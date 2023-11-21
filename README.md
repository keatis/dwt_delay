# dwt_delay
Microseconds delay lib based on DWT for STM32 or whatever ARM supporting it. 
Just include `dwt_delay.h` in your project, call `DWT_Init()` and then use delays as needed.

Depending on MCU used, you may need to include another header file (with MCU peripherals defines) in `dwt_delay.h`.
The `stm32f1xx.h` is included by default, allowing STM32F1xx to start out of the box.
If you don't use STM32 MCU or CubeMX, read a section at the end.  

Functions are named as DWT_* to be HAL-alike. Feel free to do whatever you like with this lib,
change names, indents, coding style, use it in LHC firmware.


## Example

```c
/* main.c */

#include "dwt_delay.h"


void main (void)
{
    // Init section of your code
    DWT_Init();


    while(1) {
        // Delay for 42us
        DWT_Delay(42);
    }

}
```

## Notes on Cortex-M0/0+/1
Unfortunately, these are not supported, since cores have no access to DWT. CMSIS library states:
```
Cortex-M0/0+/1 Core Debug Registers are only accessible over DAP and not via processor
``` 
You may want a delay function based on hardware timer instead.


## What about Cortex-M35/55/85?
I don't have any of these to check, but in theory they are supported.
Anyway you have to change `CoreDebug` to `DCB`, because `CoreDebug` is deprecated in these cores.

Hence, init sequence should be something like:
```c
DCB->DEMCR |= ‎DCB_DEMCR_TRCENA_Msk;
``` 


## I'm not with STM but need microsec delays
There's an option to try! Also suits those, who use STM32, but dont use HAL/LL libs.

Include a CMSIS header file according to your core in `dwt_delay.c` and change `SystemCoreClock`
variable to whatever you probably have in the project representing clock frequency (in Hz).

Something like this:
```c
// In dwt_delay.c

#include "dwt_delay.h"
#include "core_cm4.h"                   // CMSIS header

#define SystemCoreClock   NameOfTheGlobalVariableInYourProject_or_AnotherDefine
// or at least
#define SystemCoreClock   48000000UL    // Clock is 48Mhz
...
``` 


## Changelog
- **2018-01-06**
This lib emerged.

- **2019-02-19**
Overflow check added.

- **2019-03-26**
Typo in definition fixed. Got back to short and simpler function.

- **2023-11-21**
Now it is MIT License. Added warning for Cortex-M0/0+/1 and notes regarding other Cortex-M cores.
