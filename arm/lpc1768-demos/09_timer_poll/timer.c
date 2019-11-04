#include "timer.h"

void timer_init(void)
{
	// enable timer and reset it.
	LPC_TIM0->TCR = BV(TCR_RESET) | BV(TCR_EN);
	// timer mode
	LPC_TIM0->CTCR = CTCR_TIMER_MODE;
	// set prescalar
	LPC_TIM0->PR = PR_VAL - 1;
}

void timer_delay_ms(uint32_t ms)
{
	uint32_t cnt;
	// reset the timer
	LPC_TIM0->TCR |= BV(TCR_RESET);
	// calculate count based on timer.
	cnt = (PCLK / 1000) * ms / PR_VAL;
	// Set value in MR0.
	LPC_TIM0->MR0 = cnt - 1;
	// Set MCR -- stop timer and generate interrupt.
	LPC_TIM0->MCR = BV(MCR_MR0I) | BV(MCR_MR0S);
	// start the timer
	LPC_TIM0->TCR = BV(TCR_EN);
	// wait for interrupt flag in IR
	while( (LPC_TIM0->IR & BV(IR_MR0)) == 0 )
		;
	// clear the timer interrupt
	LPC_TIM0->IR |= BV(IR_MR0);
}






