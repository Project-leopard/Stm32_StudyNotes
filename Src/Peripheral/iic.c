#include "iic.h"
/**
 * @brief 	硬件I2C初始化
 * @param 	无
 * @retval 	无
 * 由于SMT32硬件I2C存在缺陷，不推荐使用硬件I2C，推荐使用模拟I2C。
 * 硬件I2C只做驱动，不实现任何功能
*/
void IIC_Config(void)
{
	/* 定义结构体 */
	GPIO_InitTypeDef GPIO_InitStruct;											//GPIO结构体
	I2C_InitTypeDef I2C_InitStruct;												//I2C结构体
	RCC_APB2PeriphClockCmd(IIC_IO_CLK,ENABLE);									//使能I2C引脚时钟
	RCC_APB1PeriphClockCmd(IIC_CLK,ENABLE);										//使能I2C时钟
	/* 配置I2C引脚工作模式 */
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AF_OD;									//复用开漏输出
	GPIO_InitStruct.GPIO_Pin=IIC_SCL|IIC_SDA;									//SCL/SDA引脚
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;								//速率50MHz
	GPIO_Init(IIC_IO_PORT,&GPIO_InitStruct);									//初始化I2C引脚
	/* 配置I2C工作模式 */
	I2C_InitStruct.I2C_Ack=I2C_Ack_Disable;										//使能I2C应答
	I2C_InitStruct.I2C_AcknowledgedAddress=I2C_AcknowledgedAddress_7bit;		//使用7位地址
	I2C_InitStruct.I2C_ClockSpeed=IIC_SPEED;									//配置I2C工作速度
	I2C_InitStruct.I2C_DutyCycle=I2C_DutyCycle_2;								//配置时钟占空比
	I2C_InitStruct.I2C_Mode=I2C_Mode_I2C;										//配置I2C工作模式
	I2C_InitStruct.I2C_OwnAddress1=IIC_ADDR;									//设置I2C自身地址
	I2C_Init(IIC_PORT,&I2C_InitStruct);											//初始化I2C
	I2C_Cmd(IIC_PORT,ENABLE);													//使能I2C
}
