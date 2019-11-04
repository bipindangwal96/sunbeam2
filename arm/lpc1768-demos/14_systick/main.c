#include "LPC17xx.h"
#include "systick.h"
#include "led.h"

int main()
{
	SysTick_Config(SystemCoreClock/1000); // for intr after every 1ms	
	led_init();
	while(1)
	{
		led_on();
		systick_delay_ms(1000);
		led_off();
		systick_delay_ms(1000);
	}
}

