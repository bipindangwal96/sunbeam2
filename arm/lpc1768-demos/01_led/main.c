#include "LPC17xx.h"

// LED -- P1.29

void led_init(void);
void led_on(void);
void led_off(void);

int main()
{
	led_init();
	while(1)
	{
		led_on();
		delay_ms(1000);
		led_off();
		delay_ms(1000);
	}
}

void led_init(void)
{
	// make port as output port
	LPC_GPIO1->FIODIR |= BV(29);
	// off the led
	led_off();
}

void led_on(void)
{
	// P1.29 = 1
	LPC_GPIO1->FIOSET |= BV(29);
}

void led_off(void)
{
	// P1.29 = 0	
	LPC_GPIO1->FIOCLR = BV(29);
}


