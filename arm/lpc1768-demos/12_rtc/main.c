#include <stdio.h>
#include "LPC17xx.h"
#include "lcd.h"
#include "rtc.h"

int main()
{
	rtc_time_t rt;
	char str[20];
	rt.sec = 00;
	rt.min = 59;
	rt.hr = 23;
 	rt.dom = 31;
	rt.month = 12;
	rt.year = 2019;
	rt.dow = 2;
	rt.doy = 365;

	rtc_init(&rt);
	lcd_init();
	while(1)
	{
		rtc_get(&rt);
		sprintf(str, "%02d/%02d/%04d", rt.dom, rt.month, rt.year);
		lcd_puts(LCD_LINE1, str);
		sprintf(str, "%02d:%02d:%02d", rt.hr, rt.min, rt.sec);
		lcd_puts(LCD_LINE2, str);
		delay_ms(1000);
	}
	return 0;
}

