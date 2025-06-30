/*
 * DefaultDriver.c
 *
 *  Created on: 2020年2月14日
 *      Author: Administrator
 */
#include "DefaultDevice.h"
#include "string.h"
typedef struct
{
    GPIO_TypeDef *port;
    Uint16 pin;
    Uint32 rcc;
    Bool isExist;		//是否存在
    Bool isIOControl;	//是否属于IO扩展芯片控制
    Uint8 moduleIndex;	//模块序号
    Uint8 addr;			//IO地址
}Valve;

void ValveDriver_Init(Valve *valve);

void DefaultDevice_Init(void)
{
	Valve valve;
	memset(&valve, 0, sizeof(Valve));
	valve.pin = GPIO_Pin_4;
	valve.port = GPIOE;
	valve.rcc = RCC_AHB1Periph_GPIOE;
	ValveDriver_Init(&valve);

	valve.pin = GPIO_Pin_5;
	valve.port = GPIOE;
	valve.rcc = RCC_AHB1Periph_GPIOE;
	ValveDriver_Init(&valve);

	valve.pin = GPIO_Pin_6;
	valve.port = GPIOE;
	valve.rcc = RCC_AHB1Periph_GPIOE;
	ValveDriver_Init(&valve);

	valve.pin = GPIO_Pin_13;
	valve.port= GPIOC;
	valve.rcc =  RCC_AHB1Periph_GPIOC;
	ValveDriver_Init(&valve);

	valve.pin = GPIO_Pin_14;
	valve.port = GPIOC;
	valve.rcc = RCC_AHB1Periph_GPIOC;
	ValveDriver_Init(&valve);

	valve.pin = GPIO_Pin_15;
	valve.port = GPIOC;
	valve.rcc = RCC_AHB1Periph_GPIOC;
	ValveDriver_Init(&valve);
}

void ValveDriver_Init(Valve *valve)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_AHB1PeriphClockCmd(valve->rcc, ENABLE);

    GPIO_InitStructure.GPIO_Pin = valve->pin;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(valve->port, &GPIO_InitStructure);
    GPIO_ResetBits(valve->port, valve->pin);

}
