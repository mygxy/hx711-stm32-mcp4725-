#include "my_gpio.h"
void GPIO_Out_Init(GPIO_TypeDef* GPIOx, uint16_t Pin)
{
    GPIO_InitTypeDef GPIO_InitStruct;

    // ����ʱ��
    if(GPIOx == GPIOA) RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    if(GPIOx == GPIOB) RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    if(GPIOx == GPIOC) RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    GPIO_InitStruct.GPIO_Pin = Pin;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOx, &GPIO_InitStruct);
}

void GPIO_High(GPIO_TypeDef* GPIOx, uint16_t Pin)
{
    GPIO_SetBits(GPIOx, Pin);
}

void GPIO_Low(GPIO_TypeDef* GPIOx, uint16_t Pin)
{
    GPIO_ResetBits(GPIOx, Pin);
}


//GPIO_Out_Init(GPIOB, GPIO_Pin_5); sample

// ====================== ����ģʽ���¼ӣ� ======================
void GPIO_In_Init(GPIO_TypeDef* GPIOx, uint16_t Pin)
{
    GPIO_InitTypeDef GPIO_InitStruct;

    // ��ʱ��
    if(GPIOx == GPIOA) RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    if(GPIOx == GPIOB) RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    if(GPIOx == GPIOC) RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    // �������루������ã�
    GPIO_InitStruct.GPIO_Pin = Pin;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(GPIOx, &GPIO_InitStruct);
}

// ��ȡ���ŵ�ƽ
uint8_t GPIO_Read(GPIO_TypeDef* GPIOx, uint16_t Pin)
{
    return GPIO_ReadInputDataBit(GPIOx, Pin);
}
