#include "systick.h"

static volatile uint32_t jiffies;

void SysTick_Handler(void)
{
	jiffies++;	
}

void systick_delay_ms(uint32_t ms)
{
	uint32_t cur = jiffies;	
	while(jiffies < cur + ms)
		;
}


