# dwt_delay
Microseconds delay lib for STM32 (or whatever ARM) based on DWT.

Just include it in your project, call `DWT_Init()` and then use delays as needed.

Functions are named as DWT_* to be HAL-alike.
If you dont use STM32 MCU, or dont like naming, change names to whatever you like.


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
        DWT_delay(42);
    }

}
```

## Changelog
- **2018-01-06**
This lib emerged.

- **2019-02-19**
Overflow check added.
