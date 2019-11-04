#include "rtc.h"

void rtc_init(rtc_time_t *rt)
{
	// reset and disable rtc
	LPC_RTC->CCR = BV(CCR_RESET) | BV(CCR_CALIB);
	// set the time from "rt" into the RTC registers
	LPC_RTC->SEC = rt->sec;
	LPC_RTC->MIN = rt->min;
	LPC_RTC->HOUR = rt->hr;
	LPC_RTC->DOM = rt->dom;
	LPC_RTC->MONTH = rt->month;
	LPC_RTC->YEAR = rt->year;
	LPC_RTC->DOW = rt->dow;
	LPC_RTC->DOY = rt->doy;
	// enable rtc
	LPC_RTC->CCR = BV(CCR_EN) | BV(CCR_CALIB);
}

void rtc_get(rtc_time_t *rt)
{
	// get the time from the RTC registers into "rt"
	rt->sec = LPC_RTC->SEC;
	rt->min = LPC_RTC->MIN;
	rt->hr = LPC_RTC->HOUR;
 	rt->dom = LPC_RTC->DOM;
	rt->month = LPC_RTC->MONTH;
	rt->year = LPC_RTC->YEAR;
	rt->dow = LPC_RTC->DOW;
	rt->doy = LPC_RTC->DOY;
}

