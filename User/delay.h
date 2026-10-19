#ifndef __DELAY_H
#define __DELAY_H

#include "stm32f10x.h"

/* SysTick based blocking delay (system clock = 72MHz) */
void delay_us(uint32_t us);   /* 0 ~ 233015 us */
void delay_ms(uint32_t ms);

#endif
