#include "timer.h"
#include "led.h"

void timer_init(uint32_t ms)
{
	uint32_t cnt;
	// enable timer and reset it.
	LPC_TIM0->TCR = BV(TCR_RESET) | BV(TCR_EN);
	// timer mode
	LPC_TIM0->CTCR = CTCR_TIMER_MODE;
	// set prescalar
	LPC_TIM0->PR = PR_VAL - 1;

	// calculate count based on delay needed.
	cnt = (PCLK / 1000) * ms / PR_VAL;
	// Set value in MR0.
	LPC_TIM0->MR0 = cnt - 1;
	// Set MCR -- reset timer and generate interrupt.
	LPC_TIM0->MCR = BV(MCR_MR0I) | BV(MCR_MR0R);
	// start the timer
	LPC_TIM0->TCR = BV(TCR_EN);

	// Enable Interrupt in NVIC
	NVIC_EnableIRQ(TIMER0_IRQn);
}

void TIMER0_IRQHandler(void)
{
	// toggle led
	led_toggle();
	// clear the timer interrupt
	LPC_TIM0->IR |= BV(IR_MR0);
}






