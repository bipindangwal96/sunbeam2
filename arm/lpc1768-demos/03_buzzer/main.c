#include "LPC17xx.h"
#include "buzzer.h"

int main()
{	
	int i;
	buzzer_init();
	for(i=1; i<=4; i++)
	{
		buzzer_beep(2000);
		delay_ms(2000);
	}
	return 0;
}

