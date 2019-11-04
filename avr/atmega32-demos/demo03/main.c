#include <avr/io.h>
#include <util/delay.h>

#define PRESCALAR 1024
#define BV(n) (1<<(n))

void timer1_delay_ms(uint16_t ms);


// PORTA --> LEDs
int main(void)
{
	uint8_t data = 0xFF;
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
	// set OCR1A
	OCR1A = cnt-1;
	// set TCNT1
	TCNT1 = 0x0000;
	// config timer: mode=CTC, Prescalar=1024.
	TCCR1A = 0x00;
	TCCR1B = BV(WGM12) | BV(CS12) | BV(CS10);
	// wait for OCF1A flag
	while( (TIFR & BV(OCF1A)) == 0 )
		;
	// clear OCF1A flag
	TIFR |= BV(OCF1A);
	// stop timer
	TCCR1B = 0x00;
}









