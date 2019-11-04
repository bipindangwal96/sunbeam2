#include <string.h>
#include "LPC17xx.h"
#include "uart.h"

int main()
{
	char str[32];
	uart_init(9600);
	uart_puts("Enter strings: \r\n");
	while(1)
	{
		uart_gets(str);
		strupr(str);
		uart_puts(str);
	}
}

