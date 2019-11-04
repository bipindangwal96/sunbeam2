#include "spi.h"

void spi_init(void)
{
	// enable SPI pins except SS
	LPC_PINCON->PINSEL0 &= ~(BV(31) | BV(30));
	LPC_PINCON->PINSEL0 |= BV(31);
	LPC_PINCON->PINSEL1 &= ~(BV(5) | BV(4) | BV(3) | BV(2) | BV(1) | BV(0));
	LPC_PINCON->PINSEL1 |= BV(5) | BV(3);
	LPC_GPIO0->FIODIR |= BV(SSEL);

	// configure SPI - 8-bit transfer, CPOL=1, CPHA=1, Enable SSP, Master mode.
	LPC_SSP0->CR0 = BV(CR0_CPOL) | BV(CR0_CPHA) | CR0_DL_VAL;
	LPC_SSP0->CR1 = BV(CR1_SSPEN);

	// set CPSR
	LPC_SSP0->CPSR = CPSR_VAL;
}

uint16_t spi_transfer(uint16_t data)
{
	uint16_t val;
	// enable slave (SS=0)
	LPC_GPIO0->FIOCLR = BV(SSEL);

	// write data into DR
	LPC_SSP0->DR = data;

	// wait for transfer
	while( (LPC_SSP0->SR & BV(SPSR_RXFNE)) == 0 )
		;
	val = LPC_SSP0->DR;
	// read SPSR to clear the flag (& discard the value)
	(void) LPC_SSP0->SR;

	// disable slave (SS=1)
	LPC_GPIO0->FIOSET |= BV(SSEL);

	return val;
}









