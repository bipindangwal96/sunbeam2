#include <avr/io.h>
#include <util/delay.h>

#define BV(n) (1<<(n))

void timer2_pwm_init(void);

int main(void)
{
	uint16_t val = 0;
	DDRD = 0xFF;
	OCR2 = 0;
	timer2_pwm_init();

	while(1)
	{
		for(val=0; val<256; val++)
		{
			OCR2 = val;
			_delay_ms(20);
		}
		for(val=255; val>0; val--)
		{
			OCR2 = val;
			_delay_ms(20);
		}
	}
	return 0;	
}

void timer2_pwm_init(void)
{
	// set TCCR2: prescalar=1, wgm mode=Phase corrected PWM, output compare=inverted mode
	TCCR2 = BV(WGM21) | BV(WGM20) | BV(COM21) | BV(CS20);
}


