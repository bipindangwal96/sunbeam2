#include "LPC17xx.h"

#define SRAM_BB_BASE	0x20000000
#define SRAM_BBALS_BASE	0x22000000
#define SRAM_ALS_ADDR(regr,bit) (SRAM_BBALS_BASE + ((uint32_t)&regr-SRAM_BB_BASE)*32 + bit*4)
#define SRAM_ALS_VAL(regr,bit) (*(uint32_t*)SRAM_ALS_ADDR(regr, bit))

#define PERI_BB_BASE	0x40000000
#define PERI_BBALS_BASE	0x42000000
#define PERI_ALS_ADDR(regr,bit) (PERI_BBALS_BASE + ((uint32_t)&regr-PERI_BB_BASE)*32 + bit*4)
#define PERI_ALS_VAL(regr,bit) (*(uint32_t*)PERI_ALS_ADDR(regr, bit))

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
		delay_ms(500);
		led_off();
		delay_ms(500);
	}
}

void led_init(void)
{
	// make port as output port
	//LPC_GPIO1->FIODIR |= BV(29);
	SRAM_ALS_VAL(LPC_GPIO1->FIODIR, 29) = 1;
	// off the led
	led_off();
}

void led_on(void)
{
	// P1.29 = 1
	//LPC_GPIO1->FIOSET |= BV(29);
	SRAM_ALS_VAL(LPC_GPIO1->FIOSET, 29) = 1;
}

void led_off(void)
{
	// P1.29 = 0	
	//LPC_GPIO1->FIOCLR = BV(29);
	SRAM_ALS_VAL(LPC_GPIO1->FIOCLR, 29) = 1;
}


