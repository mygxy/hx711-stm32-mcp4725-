#ifndef _MY_GPIO_H
#define _MY_GPIO_H

#include "stm32f10x.h"

// 推挽输出初始化
void GPIO_Out_Init(GPIO_TypeDef* GPIOx, uint16_t Pin);
// 引脚置高
void GPIO_High(GPIO_TypeDef* GPIOx, uint16_t Pin);
// 引脚置低
void GPIO_Low(GPIO_TypeDef* GPIOx, uint16_t Pin);


// 输入（上拉输入，最常用：按键）
void GPIO_In_Init(GPIO_TypeDef* GPIOx, uint16_t Pin);
// 读取引脚电平
uint8_t GPIO_Read(GPIO_TypeDef* GPIOx, uint16_t Pin);

#endif


