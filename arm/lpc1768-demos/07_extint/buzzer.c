#include "buzzer.h"

void buzzer_init(void)
{
	// make P2.11 as output
	LPC_GPIO2->FIODIR |= BV(BUZZER);
	// off the buzzer
	buzzer_off();
}

void buzzer_on(void)
{
	// make P2.11 = 0	
	LPC_GPIO2->FIOCLR = BV(BUZZER);
}

void buzzer_off(void)
{
	// make P2.11 = 1
	LPC_GPIO2->FIOSET |= BV(BUZZER);	
}

void buzzer_beep(uint32_t delay)
{
	// buzzer on
	buzzer_on();
	// delay
	delay_ms(delay);
	// buzzer off
	buzzer_off();
}

