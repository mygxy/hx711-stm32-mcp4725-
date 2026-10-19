#include "hx711.h"
#include "my_gpio.h"
#include "delay.h"

/* Init DT as input (pull-up) and SCK as push-pull output */
void HX711_Init(void)
{
    GPIO_In_Init (HX711_DT_PORT,  HX711_DT_PIN);
    GPIO_Out_Init(HX711_SCK_PORT, HX711_SCK_PIN);
    GPIO_Low     (HX711_SCK_PORT, HX711_SCK_PIN);
}

/* Read one 24-bit sample.
 * 25 SCK pulses select channel A, gain 128.
 * Result is sign-extended to int32_t. */
int32_t HX711_Read(void)
{
    uint8_t i;
    int32_t count = 0;

    /* wait until DT goes low (data ready) */
    while (GPIO_Read(HX711_DT_PORT, HX711_DT_PIN) != 0);

    for (i = 0; i < 24; i++)
    {
        GPIO_High(HX711_SCK_PORT, HX711_SCK_PIN);
        delay_us(1);
        count = count << 1;
        GPIO_Low(HX711_SCK_PORT, HX711_SCK_PIN);
        delay_us(1);
        if (GPIO_Read(HX711_DT_PORT, HX711_DT_PIN) != 0)
        {
            count++;
        }
    }

    /* 25th pulse: channel A, gain 128 */
    GPIO_High(HX711_SCK_PORT, HX711_SCK_PIN);
    delay_us(1);
    GPIO_Low(HX711_SCK_PORT, HX711_SCK_PIN);
    delay_us(1);

    /* sign extend the 24-bit two's complement value */
    if (count & 0x800000)
    {
        count |= 0xFF000000;
    }
    else
    {
        count &= 0x00FFFFFF;
    }

    return count;
}

/* Average of n samples to reduce noise */
int32_t HX711_ReadAverage(uint8_t n)
{
    uint8_t i;
    int32_t sum = 0;

    if (n == 0)
    {
        n = 1;
    }

    for (i = 0; i < n; i++)
    {
        sum += HX711_Read();
    }

    return sum / n;
}
