#include <stdio.h>
#include "LPC17xx.h"
#include "uart.h"
#include "adc.h"

int main()
{
	char str[32];
	uint32_t res;
	uart_init(9600);
	uart_puts("ADC Demo \r\n");
	adc_init();
	while(1)
	{
		res = adc_read();
		sprintf(str, "Result: %lu\r\n", res);
		uart_puts(str);
		delay_ms(1000);
	}
}

