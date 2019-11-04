#include "LPC17xx.h"
#include "spi.h"

int main()
{
	uint8_t val = 0x55;

	spi_init();
	while(1)
	{
		spi_transfer(val);
		delay_ms(1000);
		val = ~val;
	}
}

