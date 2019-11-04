#include "LPC17xx.h"
#include "led.h"
#include "timer.h"

int main()
{
	led_init();
	timer_init(1000);
}

