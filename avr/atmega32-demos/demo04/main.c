#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define PRESCALAR 1024
#define BV(n) (1<<(n))

uint8_t data = 0x0F;

void timer1_init(uint16_t ms);


// PORTA --> LEDs
int main(void)
{
	// enable AVR interrupt
	sei();

	// make PA as output & write init value
	DDRA = 0xFF;
	PORTA = data;

	// init timer
	timer1_init(1000);

	while(1);
	return 0;	
}

void timer1_init(uint16_t ms)
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
	// enable timer1 interrupt
	TIMSK |= BV(OCIE1A);
}

// ISR macro ensure that JMP instruction is added in the corresponding vector table slot.
ISR(TIMER1_COMPA_vect)
{
	data = ~data;
	PORTA = data;
}







