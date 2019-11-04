#ifndef __RTC_H
#define __RTC_H

#include "LPC17xx.h"

typedef struct rtc_time
{
	int hr, min, sec;
	int dom, dow, doy, month, year;
}rtc_time_t;

#define		CCR_EN		0
#define		CCR_RESET	1
#define		CCR_CALIB	4

void rtc_init(rtc_time_t *rt);
void rtc_get(rtc_time_t *rt);

#endif


