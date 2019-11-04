#ifndef __SYSTICK_H
#define __SYSTICK_H

#include "LPC17xx.h"

void SysTick_Handler(void);

void systick_delay_ms(uint32_t ms);

#endif


