#include <avr/io.h>
#include <util/delay.h>

// PORTA --> LEDs
#define LED_ON		0x00
#define LED_OFF		0xFF

#define BV(n) (1<<(n))
#define PRESCALAR 1024
void timer1_delay_ms(uint16_t ms);

int main(void)
{
	uint8_t cnt = 0;
	uint8_t on_time = 18;
	// make PA as output
	DDRA = 0xFF;
	while(1)
	{
		PORTA = LED_ON;
		timer1_delay_ms(on_time);
		PORTA = LED_OFF;
		timer1_delay_ms(20 - on_time);
		cnt++;
		if(cnt == 200)
		{
			on_time = on_time - 2;
			cnt = 0;
			if(on_time == 0)
				break;
		}
	}

	while(1);
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









