#include "LPC17xx.h"
#include "lcd.h"

int main()
{
	lcd_init();
	lcd_puts(LCD_LINE1, "DESD @ SUNBEAM");
	lcd_puts(LCD_LINE2, "LCD Demo");
	return 0;
}

