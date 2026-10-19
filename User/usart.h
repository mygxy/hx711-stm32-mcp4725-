#ifndef __USART_H
#define __USART_H

#include "stm32f10x.h"
#include <stdio.h>

/* USART1 : PA9 -> TX, PA10 -> RX, 8N1 */
void USART1_Init(uint32_t baud);

#endif
