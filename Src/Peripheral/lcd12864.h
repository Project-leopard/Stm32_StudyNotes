#ifndef __LCD12864_H
#define __LCD12864_H

#include "stm32f10x.h"
#include "usersystem.h"

#define LCD12864_DB0_CLK				RCC_APB2Periph_GPIOC
#define LCD12864_DB0_PORT				GPIOC
#define LCD12864_DB0_PIN				GPIO_Pin_0

#define LCD12864_DB1_CLK				RCC_APB2Periph_GPIOC
#define LCD12864_DB1_PORT				GPIOC
#define LCD12864_DB1_PIN				GPIO_Pin_1

#define LCD12864_DB2_CLK				RCC_APB2Periph_GPIOC
#define LCD12864_DB2_PORT				GPIOC
#define LCD12864_DB2_PIN				GPIO_Pin_2

#define LCD12864_DB3_CLK				RCC_APB2Periph_GPIOC
#define LCD12864_DB3_PORT				GPIOC
#define LCD12864_DB3_PIN				GPIO_Pin_3

#define LCD12864_DB4_CLK				RCC_APB2Periph_GPIOC
#define LCD12864_DB4_PORT				GPIOC
#define LCD12864_DB4_PIN				GPIO_Pin_4

#define LCD12864_DB5_CLK				RCC_APB2Periph_GPIOC
#define LCD12864_DB5_PORT				GPIOC
#define LCD12864_DB5_PIN				GPIO_Pin_5

#define LCD12864_DB6_CLK				RCC_APB2Periph_GPIOC
#define LCD12864_DB6_PORT				GPIOC
#define LCD12864_DB6_PIN				GPIO_Pin_6

#define LCD12864_DB7_CLK				RCC_APB2Periph_GPIOC
#define LCD12864_DB7_PORT				GPIOC
#define LCD12864_DB7_PIN				GPIO_Pin_7

#define LCD12864_RS_CLK					RCC_APB2Periph_GPIOG
#define LCD12864_RS_PORT				GPIOG
#define LCD12864_RS_PIN					GPIO_Pin_13
#define RS								PGout(13)

#define LCD12864_RW_CLK					RCC_APB2Periph_GPIOG
#define LCD12864_RW_PORT				GPIOG
#define LCD12864_RW_PIN					GPIO_Pin_14
#define RW								PGout(14)

#define LCD12864_EN_CLK					RCC_APB2Periph_GPIOG
#define LCD12864_EN_PORT				GPIOG
#define LCD12864_EN_PIN					GPIO_Pin_15
#define EN								PGout(15)

#define LCD12864_PSB_CLK				RCC_APB2Periph_GPIOB
#define LCD12864_PSB_PORT				GPIOB
#define LCD12864_PSB_PIN				GPIO_Pin_3
#define PSB								PBout(3)

#define LCD12864_RST_CLK				RCC_APB2Periph_GPIOB
#define LCD12864_RST_PORT				GPIOB
#define LCD12864_RST_PIN				GPIO_Pin_4
#define RST								PBout(4)

#define HIGH							1
#define LOW								0

#define DataPORT(x)						GPIOC->ODR=(GPIOC->ODR&0xFF00)|(x&0x00FF)

void LCD12864_WriteCmd(vu8 cmd);
void LCD12864_WriteData(vu8 Data);
void LCD12864_Initialize(void);
void LCD12864_SetXY(vu8 x,vu8 y);
void LCD12864_Display(void);

#endif /* __LCD12864_H */