#include "LPC17xx.h"
#include "led.h"
#include "timer.h"

int main()
{
	led_init();
	timer_init();
	while(1)
	{
		led_on();
		timer_delay_ms(1000);
		led_off();
		timer_delay_ms(1000);
	}
}

