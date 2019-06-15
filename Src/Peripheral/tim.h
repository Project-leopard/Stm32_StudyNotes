#ifndef __TIM_H
#define __TIM_H

#include "stm32f10x.h"
#include "usersystem.h"

#define TIM6_CLK			RCC_APB1Periph_TIM6
#define TIM6_PORT			TIM6
#define TIM6_IRQ			TIM6_IRQn

#define TIM7_CLK			RCC_APB1Periph_TIM7
#define TIM7_PORT			TIM7
#define TIM7_IRQ			TIM7_IRQn

void BASIC_TIM_Initialize(void);

#endif /* __TIM_H */