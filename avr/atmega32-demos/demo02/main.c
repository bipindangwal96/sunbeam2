#include <avr/io.h>
#include <util/delay.h>

#define PRESCALAR 1024
#define BV(n) (1<<(n))

void timer1_delay_ms(uint16_t ms);


// PORTA --> LEDs
int main(void)
{
	uint8_t data = 0x33;
	// make PA as output
	DDRA = 0xFF;

	while(1)
	{
		// write LED data on PORTA
		PORTA = data;
		// Change LED data
		data = ~data;
		// delay of 1 sec
		timer1_delay_ms(1000);
	}
	return 0;	
}

void timer1_delay_ms(uint16_t ms)
{
	uint16_t cnt;
	// calculate the count
	cnt = (F_CPU / 1000) * ms / PRESCALAR;
	// set TCNT1
	TCNT1 = 65535 - cnt;
	// config timer: mode=Normal, Prescalar=1024.
	TCCR1A = 0x00;
	TCCR1B = BV(CS12) | BV(CS10);
	// wait for TOV1 flag
	while( (TIFR & BV(TOV1)) == 0 )
		;
	// clear TOV1 flag
	TIFR |= BV(TOV1);
	// stop timer
	TCCR1B = 0x00;
}









