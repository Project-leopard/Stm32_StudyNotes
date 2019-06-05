#ifndef __SOFT_IIC_H
#define __SOFT_IIC_H

#include "stm32f10x.h"
#include "usersystem.h"

#define SOFT_IIC_CLK		RCC_APB2Periph_GPIOB				//IO模拟I2C时钟
#define SOFT_IIC_PORT		GPIOB								//GPIOB
#define SOFT_IIC_SCL		GPIO_Pin_6							//模拟I2C_SCL引脚
#define SOFT_IIC_SDA		GPIO_Pin_7							//模拟I2C_SDA引脚
#define SCL_LOW				(SOFT_IIC_PORT->BRR=0x40)			//SCL拉低实现
#define SCL_HIGH			(SOFT_IIC_PORT->BSRR=0x40)			//SCL拉高实现
#define SDA_LOW				(SOFT_IIC_PORT->BRR=0x80)			//SDA拉低实现
#define SDA_HIGH			(SOFT_IIC_PORT->BSRR=0x80)			//SDA拉高实现
#define SDA_READ			(SOFT_IIC_PORT->IDR&0x80)			//读取SDA线状态

void SOFT_IIC_Config(void);										//模拟I2C初始化、置位函数
void SDA_IO_IN(void);											//SDA配置输入函数
void SDA_IO_OUT(void);											//SDA配置输出函数
void SOFT_IIC_Delay(void);										//模拟I2CC延时函数
uint8_t SOFT_IIC_Start(void);									//模拟I2C产生起始信号函数
void SOFT_IIC_Stop(void);										//模拟I2C产生停止信号函数
uint8_t SOFT_IIC_GetAck(void);									//模拟I2C读取应答信号函数
void SOFT_IIC_SendData(uint8_t data);							//模拟I2C发送数据函数
uint8_t SOFT_IIC_ReadData(uint8_t ack);							//模拟I2C读取数据函数

#endif /* __SOFT_IIC_H */