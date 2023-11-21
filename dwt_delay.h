/*
 * Simple microseconds delay routine, utilizing ARM's DWT
 * (Data Watchpoint and Trace Unit) and HAL library.
 * Intended to use with gcc compiler, but I hope it can be used
 * with any other C compiler across the Universe (provided that
 * ARM and CMSIS already invented) :)
 * Max K
 *
 *
 * This file is part of DWT_Delay package.
 * DWT_Delay is free software: you can redistribute it and/or modify it
 * under the terms of the MIT License.
 */

#if defined(__CORTEX_M) && __CORTEX_M < 3U
#warning DWT_Delay in useless in this project since DWT unit is not accessible \
         by processor on Cortex-M0/0+/1 cores. You may want to implement microdelays \
         with hardware timer.
#endif

#ifndef INC_DWT_DELAY_H_
#define INC_DWT_DELAY_H_

#include <stdint.h>

#define DWT_DELAY_NEWBIE 0

void DWT_Init(void);
void DWT_Delay(uint32_t us);

#endif /* INC_DWT_DELAY_H_ */
