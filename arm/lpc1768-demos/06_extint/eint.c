#include "eint.h"
#include "buzzer.h"

void eint2_init(void)
{
	// Enable EINT2 for P2.12.
	LPC_PINCON->PINSEL4 &= ~(BV(25) | BV(24));
	LPC_PINCON->PINSEL4 |= BV(24);
	
	// Enable EINT2 interrupt.
	NVIC_EnableIRQ(EINT2_IRQn);
	
	// Configure EINT2 as Rising edge.
	LPC_SC->EXTMODE |= BV(EINT2);
	LPC_SC->EXTPOLAR |= BV(EINT2);
	LPC_SC->EXTINT |= BV(EINT2);		
}

void EINT2_IRQHandler(void)
{
	// Beep the buzzer.
	buzzer_beep(2000);
	// Clear the interrupt.
	LPC_SC->EXTINT |= BV(EINT2);	
}

