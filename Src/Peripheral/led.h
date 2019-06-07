#ifndef __LED_H
#define __LED_H

#include "stm32f10x.h"
#include "usersystem.h"

#define RED_CLK			RCC_APB2Periph_GPIOB					//红色LED时钟
#define RED_PORT		GPIOB									//GPIOB
#define RED_PIN			GPIO_Pin_5								//红色LED引脚
#define GREEN_CLK		RCC_APB2Periph_GPIOE					//绿色LED时钟
#define GREEN_PORT		GPIOE									//GPIOE
#define GREEN_PIN		GPIO_Pin_5								//绿色LED引脚
#define RED				PBout(5)								//红色LED位带操作
#define GREEN			PEout(5)								//绿色LED位带操作
#define LED_ON			0										//LED开
#define LED_OFF			1										//LED关

void LED_Initialize(void);										//战舰V3LED初始化函数

#endif /* __LED_H */