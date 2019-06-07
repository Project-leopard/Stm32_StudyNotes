#ifndef __SPI_H
#define __SPI_H

#include "stm32f10x.h"

#define SPI_CLK			RCC_APB1Periph_SPI2					//SPI时钟
#define SPI_PORT		SPI2								//SPI_PORT

#define SPI_CS_CLK		RCC_APB2Periph_GPIOB				//SPI片选引脚时钟
#define SPI_CS_PORT		GPIOB
#define SPI_CS_PIN		GPIO_Pin_12

#define SPI_SCK_CLK		RCC_APB2Periph_GPIOB				//SPI时钟引脚时钟
#define SPI_SCK_PORT	GPIOB
#define SPI_SCK_PIN		GPIO_Pin_13

#define SPI_MISO_CLK	RCC_APB2Periph_GPIOB				//SPI_MISO引脚时钟
#define SPI_MISO_PORT	GPIOB
#define SPI_MISO_PIN	GPIO_Pin_14

#define SPI_MOSI_CLK	RCC_APB2Periph_GPIOB				//SPI_MOSI引脚时钟
#define SPI_MOSI_PORT	GPIOB
#define SPI_MOSI_PIN	GPIO_Pin_15

void SPI_Flash_Initialize(void);					//SPI_FLASH初始化函数

#endif /* __SPI_H */