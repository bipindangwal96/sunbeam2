#include "LPC17xx.h"
#include "buzzer.h"
#include "eint.h"

int main()
{
	buzzer_init();
	eint2_init();
	while(1)
	{
		while(eint2_flag==0)
			;
		eint2_flag = 0;
		buzzer_beep(2000);
	}
}

