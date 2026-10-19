#include "delay.h"

/* Microsecond delay, SysTick clocked by HCLK (72MHz) */
void delay_us(uint32_t us)
{
    SysTick->LOAD = 72 * us;      /* reload value */
    SysTick->VAL  = 0x00;         /* clear current counter */
    SysTick->CTRL = 0x00000005;   /* enable, HCLK source, no interrupt */
    while (!(SysTick->CTRL & 0x00010000)); /* wait COUNTFLAG */
    SysTick->CTRL = 0x00000004;   /* disable */
}

/* Millisecond delay */
void delay_ms(uint32_t ms)
{
    while (ms--)
    {
        delay_us(1000);
    }
}
