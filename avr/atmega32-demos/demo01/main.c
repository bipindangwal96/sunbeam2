#include <avr/io.h>
#include <util/delay.h>

// PORTA --> LEDs

int main(void)
{
	uint8_t data = ~(0x01);
	// make PA as output
	DDRA = 0xFF;

	while(1)
	{
		// write LED data on PORTA
		PORTA = data;

		// delay of 1 sec
		_delay_ms(1000);

		// Change LED data
		data = data << 1;
		if(data == 0)
			data = ~(0x01);
	}
	return 0;	
}

