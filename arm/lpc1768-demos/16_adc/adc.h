#ifndef __ADC_H
#define __ADC_H

#include "LPC17xx.h"

#define	ADCR_CHN2			2
#define	ADCR_CLKDIV			8
#define	ADCR_PDN			21
#define	ADCR_START			24

#define ADDR_DONE			31
#define ADDR_RESULT			4
#define ADDR_RESULT_MASK	0x0FFF

#define	ADCR_CLKDIV_VAL		2

#define	PCADC		12

void adc_init(void);
uint32_t adc_read(void);

#endif


