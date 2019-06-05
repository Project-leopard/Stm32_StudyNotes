#ifndef __IIC_H
#define __IIC_H

#include "stm32f10x.h"
#include "eeprom.h"

#define IIC_CLK				RCC_APB1Periph_I2C1				//I2C时钟
#define IIC_PORT			I2C1							//I2C
#define IIC_IO_CLK			RCC_APB2Periph_GPIOB			//SDA、SCL引脚时钟
#define IIC_IO_PORT			GPIOB							//GPIOB
#define IIC_SCL				GPIO_Pin_6						//SCL引脚
#define IIC_SDA				GPIO_Pin_7						//SDA引脚
#define IIC_SPEED			10000							//I2C速率<=400000
#define IIC_ADDR			0x0010							//I2C自身地址

void IIC_Config(void);										//硬件I2C初始化函数

#endif /* __IIC_H */