#ifndef __HX711_H
#define __HX711_H

#include "stm32f10x.h"

/* ---- HX711 pin mapping (change here if wiring changes) ---- */
#define HX711_DT_PORT   GPIOA
#define HX711_DT_PIN    GPIO_Pin_0    /* DOUT, input  */
#define HX711_SCK_PORT  GPIOA
#define HX711_SCK_PIN   GPIO_Pin_1    /* PD_SCK, output */

void    HX711_Init(void);
int32_t HX711_Read(void);                /* one sample, channel A gain 128 */
int32_t HX711_ReadAverage(uint8_t n);    /* average of n samples */

#endif
