#include "adc.h"

void adc_init(void)
{
	// Make P0.25 as input
	LPC_GPIO0->FIODIR &= ~BV(25);

	// enable ADC AD0.2 in PINSEL
	LPC_PINCON->PINSEL1 &= ~(BV(18) | BV(19));
	LPC_PINCON->PINSEL1 |= BV(18);
	
	// Enable Power for ADC peri.
	LPC_SC->PCONP |= BV(PCADC);

	// Config ADC -- ADCR	- Select Channel 2, CLKDIV = (2-1), Enable Power
	LPC_ADC->ADCR = BV(ADCR_PDN) | ((ADCR_CLKDIV_VAL-1)<<ADCR_CLKDIV) | BV(ADCR_CHN2);
}

uint32_t adc_read(void)
{
	uint32_t result;
	// start conversion (ADCR -- START bit)
	LPC_ADC->ADCR |= BV(ADCR_START);

	// wait for conversion (ADGDR -- DONE bit)
	do {
		result = LPC_ADC->ADGDR;
	} while((result & BV(ADDR_DONE)) == 0);

	// read the result (ADGDR)	
	return (result >> ADDR_RESULT) & ADDR_RESULT_MASK;
}






