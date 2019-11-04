#ifndef __SPI_H
#define __SPI_H

#include "LPC17xx.h"

#define		SSEL			16

#define		CPSR_VAL		2

#define		CR0_DL_VAL		(8-1)
#define		CR0_CPOL		6
#define		CR0_CPHA		7

#define		CR1_SSPEN		1
#define		CR1_MASTER		2

#define		SPSR_TXFE		0
#define		SPSR_RXFNE		2

void spi_init(void);
uint16_t spi_transfer(uint16_t data);

#endif


