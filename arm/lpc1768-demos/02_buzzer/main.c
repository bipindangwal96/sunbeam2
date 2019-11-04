#include "LPC17xx.h"

#define FIO2DIR		(*(uint32_t*)0x2009C040)
#define FIO2SET		(*(uint32_t*)0x2009C058)
#define FIO2CLR		(*(uint32_t*)0x2009C05C)

#define BUZZER		11

void buzzer_init(void);
void buzzer_on(void);
void buzzer_off(void);
void buzzer_beep(uint32_t delay);

int main()
{	
	int i;
	buzzer_init();
	for(i=1; i<=3; i++)
	{
		buzzer_beep(2000);
		delay_ms(2000);
	}
	return 0;
}

void buzzer_init(void)
{
	// make P2.11 as output
	FIO2DIR |= BV(BUZZER);
	// off the buzzer
	buzzer_off();
}
void buzzer_on(void)
{
	// make P2.11 = 0	
	FIO2CLR = BV(BUZZER);
}
void buzzer_off(void)
{
	// make P2.11 = 1
	FIO2SET |= BV(BUZZER);	
}
void buzzer_beep(uint32_t delay)
{
	// buzzer on
	buzzer_on();
	// delay
	delay_ms(delay);
	// buzzer off
	buzzer_off();
}
	
