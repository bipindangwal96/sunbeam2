#include "led.h"

static int led_flag = 0;

void led_init(void)
{
	// make port as output port
	LPC_GPIO1->FIODIR |= BV(LED);
	// off the led
	led_off();
}

void led_on(void)
{
	// P1.29 = 1
	LPC_GPIO1->FIOSET |= BV(LED);
	led_flag = 1;
}

void led_off(void)
{
	// P1.29 = 0	
	LPC_GPIO1->FIOCLR = BV(LED);
	led_flag = 0;
}

void led_toggle(void)
{
	if(led_flag == 0)
		led_on();
	else
		led_off();
}



