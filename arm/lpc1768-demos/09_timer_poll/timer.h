#ifndef __TIMER_H
#define __TIMER_H

#include "LPC17xx.h"

#define		TCR_EN		0
#define		TCR_RESET	1

#define		CTCR_TIMER_MODE		0x00

#define		MCR_MR0I	0
#define		MCR_MR0R	1
#define		MCR_MR0S	2

#define		IR_MR0		0

#define		PR_VAL		18

void timer_init(void);
void timer_delay_ms(uint32_t ms);

#endif

