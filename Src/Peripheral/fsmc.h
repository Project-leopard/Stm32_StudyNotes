#ifndef __FSMC_H
#define __FSMC_H

#include "stm32f10x.h"
#include "usersystem.h"
#include "nt35510.h"
#include "w25q128.h"

#define FSMC_CLK			RCC_AHBPeriph_FSMC				//FSMC时钟

#define FSMC_A0_CLK			RCC_APB2Periph_GPIOF
#define FSMC_A0_PORT		GPIOF
#define FSMC_A0_PIN			GPIO_Pin_0

#define FSMC_A1_CLK			RCC_APB2Periph_GPIOF
#define FSMC_A1_PORT		GPIOF
#define FSMC_A1_PIN			GPIO_Pin_1

#define FSMC_A2_CLK			RCC_APB2Periph_GPIOF
#define FSMC_A2_PORT		GPIOF
#define FSMC_A2_PIN			GPIO_Pin_2

#define FSMC_A3_CLK			RCC_APB2Periph_GPIOF
#define FSMC_A3_PORT		GPIOF
#define FSMC_A3_PIN			GPIO_Pin_3

#define FSMC_A4_CLK			RCC_APB2Periph_GPIOF
#define FSMC_A4_PORT		GPIOF
#define FSMC_A4_PIN			GPIO_Pin_4

#define FSMC_A5_CLK			RCC_APB2Periph_GPIOF
#define FSMC_A5_PORT		GPIOF
#define FSMC_A5_PIN			GPIO_Pin_5

#define FSMC_A6_CLK			RCC_APB2Periph_GPIOF
#define FSMC_A6_PORT		GPIOF
#define FSMC_A6_PIN			GPIO_Pin_12

#define FSMC_A7_CLK			RCC_APB2Periph_GPIOF
#define FSMC_A7_PORT		GPIOF
#define FSMC_A7_PIN			GPIO_Pin_13

#define FSMC_A8_CLK			RCC_APB2Periph_GPIOF
#define FSMC_A8_PORT		GPIOF
#define FSMC_A8_PIN			GPIO_Pin_14

#define FSMC_A9_CLK			RCC_APB2Periph_GPIOF
#define FSMC_A9_PORT		GPIOF
#define FSMC_A9_PIN			GPIO_Pin_15

#define FSMC_A10_CLK		RCC_APB2Periph_GPIOG
#define FSMC_A10_PORT		GPIOG
#define FSMC_A10_PIN		GPIO_Pin_0

#define FSMC_A11_CLK		RCC_APB2Periph_GPIOG
#define FSMC_A11_PORT		GPIOG
#define FSMC_A11_PIN		GPIO_Pin_1

#define FSMC_A12_CLK		RCC_APB2Periph_GPIOG
#define FSMC_A12_PORT		GPIOG
#define FSMC_A12_PIN		GPIO_Pin_2

#define FSMC_A13_CLK		RCC_APB2Periph_GPIOG
#define FSMC_A13_PORT		GPIOG
#define FSMC_A13_PIN		GPIO_Pin_3

#define FSMC_A14_CLK		RCC_APB2Periph_GPIOG
#define FSMC_A14_PORT		GPIOG
#define FSMC_A14_PIN		GPIO_Pin_4

#define FSMC_A15_CLK		RCC_APB2Periph_GPIOG
#define FSMC_A15_PORT		GPIOG
#define FSMC_A15_PIN		GPIO_Pin_5

#define FSMC_A16_CLK		RCC_APB2Periph_GPIOD
#define FSMC_A16_PORT		GPIOD
#define FSMC_A16_PIN		GPIO_Pin_11

#define FSMC_A17_CLK		RCC_APB2Periph_GPIOD
#define FSMC_A17_PORT		GPIOD
#define FSMC_A17_PIN		GPIO_Pin_12

#define FSMC_A18_CLK		RCC_APB2Periph_GPIOD
#define FSMC_A18_PORT		GPIOD
#define FSMC_A18_PIN		GPIO_Pin_13

#define FSMC_D0_CLK			RCC_APB2Periph_GPIOD
#define FSMC_D0_PORT		GPIOD
#define FSMC_D0_PIN			GPIO_Pin_14

#define FSMC_D1_CLK			RCC_APB2Periph_GPIOD
#define FSMC_D1_PORT		GPIOD
#define FSMC_D1_PIN			GPIO_Pin_15

#define FSMC_D2_CLK			RCC_APB2Periph_GPIOD
#define FSMC_D2_PORT		GPIOD
#define FSMC_D2_PIN			GPIO_Pin_0

#define FSMC_D3_CLK			RCC_APB2Periph_GPIOD
#define FSMC_D3_PORT		GPIOD
#define FSMC_D3_PIN			GPIO_Pin_1

#define FSMC_D4_CLK			RCC_APB2Periph_GPIOE
#define FSMC_D4_PORT		GPIOE
#define FSMC_D4_PIN			GPIO_Pin_7

#define FSMC_D5_CLK			RCC_APB2Periph_GPIOE
#define FSMC_D5_PORT		GPIOE
#define FSMC_D5_PIN			GPIO_Pin_8

#define FSMC_D6_CLK			RCC_APB2Periph_GPIOE
#define FSMC_D6_PORT		GPIOE
#define FSMC_D6_PIN			GPIO_Pin_9

#define FSMC_D7_CLK			RCC_APB2Periph_GPIOE
#define FSMC_D7_PORT		GPIOE
#define FSMC_D7_PIN			GPIO_Pin_10

#define FSMC_D8_CLK			RCC_APB2Periph_GPIOE
#define FSMC_D8_PORT		GPIOE
#define FSMC_D8_PIN			GPIO_Pin_11

#define FSMC_D9_CLK			RCC_APB2Periph_GPIOE
#define FSMC_D9_PORT		GPIOE
#define FSMC_D9_PIN			GPIO_Pin_12

#define FSMC_D10_CLK		RCC_APB2Periph_GPIOE
#define FSMC_D10_PORT		GPIOE
#define FSMC_D10_PIN		GPIO_Pin_13

#define FSMC_D11_CLK		RCC_APB2Periph_GPIOE
#define FSMC_D11_PORT		GPIOE
#define FSMC_D11_PIN		GPIO_Pin_14

#define FSMC_D12_CLK		RCC_APB2Periph_GPIOE
#define FSMC_D12_PORT		GPIOE
#define FSMC_D12_PIN		GPIO_Pin_15

#define FSMC_D13_CLK		RCC_APB2Periph_GPIOD
#define FSMC_D13_PORT		GPIOD
#define FSMC_D13_PIN		GPIO_Pin_8

#define FSMC_D14_CLK		RCC_APB2Periph_GPIOD
#define FSMC_D14_PORT		GPIOD
#define FSMC_D14_PIN		GPIO_Pin_9

#define FSMC_D15_CLK		RCC_APB2Periph_GPIOD
#define FSMC_D15_PORT		GPIOD
#define FSMC_D15_PIN		GPIO_Pin_10

#define FSMC_NE2_CLK		RCC_APB2Periph_GPIOG
#define FSMC_NE2_PORT		GPIOG
#define FSMC_NE2_PIN		GPIO_Pin_9

#define FSMC_NE3_CLK		RCC_APB2Periph_GPIOG
#define FSMC_NE3_PORT		GPIOG
#define FSMC_NE3_PIN		GPIO_Pin_10

#define FSMC_NE4_CLK		RCC_APB2Periph_GPIOG
#define FSMC_NE4_PORT		GPIOG
#define FSMC_NE4_PIN		GPIO_Pin_12

#define FSMC_NOE_CLK		RCC_APB2Periph_GPIOD
#define FSMC_NOE_PORT		GPIOD
#define FSMC_NOE_PIN		GPIO_Pin_4

#define FSMC_NWE_CLK		RCC_APB2Periph_GPIOD
#define FSMC_NWE_PORT		GPIOD
#define FSMC_NWE_PIN		GPIO_Pin_5

#define FSMC_NBL0_CLK		RCC_APB2Periph_GPIOE
#define FSMC_NBL0_PORT		GPIOE
#define FSMC_NBL0_PIN		GPIO_Pin_0

#define FSMC_NBL1_CLK		RCC_APB2Periph_GPIOE
#define FSMC_NBL1_PORT		GPIOE
#define FSMC_NBL1_PIN		GPIO_Pin_1

void FSMC_SRAM_Initialize(void);				//FSMC读写外部SRAM函数
void FSMC_NT35510_Initialize(void);				//FSMC驱动NT35510 IC函数

#endif /* __FSMC_H */