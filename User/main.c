#include "stm32f10x.h"
#include <stdio.h>
#include "hx711.h"
#include "delay.h"
#include "usart.h"

/* ================= Calibration =================
 * Step 1: flash with defaults, look at "raw" on serial,
 *         write the empty-tray value into HX711_OFFSET.
 * Step 2: put 1kg weight, read raw = N1, then
 *         HX711_SCALE = (N1 - HX711_OFFSET) / 1000.0
 * Step 3: re-flash, serial shows grams.
 * =============================================== */
#define HX711_OFFSET   0          /* raw value when tray is empty */
#define HX711_SCALE    1.0f       /* counts per gram */

int main(void)
{
    int32_t raw;
    float   weight_g;

    HX711_Init();
    USART1_Init(115200);

    printf("\r\nHX711 electronic scale\r\n");
    printf("raw / weight\r\n");

    while (1)
    {
        raw = HX711_ReadAverage(10);
        weight_g = (raw - HX711_OFFSET) / HX711_SCALE;

        printf("raw=%ld  weight=%.1f g\r\n", (long)raw, weight_g);

        delay_ms(200);
    }
}
