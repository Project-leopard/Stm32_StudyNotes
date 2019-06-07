#include "soft_iic.h"
/**
 * @brief 	模拟I2C产生应答信号
 * @param 	无
 * @retval 	无
*/
static void SOFT_IIC_Ack(void)
{
	/* 	
	在第九个时钟，数据发送端会释放SDA的控制权,由数据接
	收端控制SDA,若SDA为高电平,表示非应答信号(NACK),低电平表示应答信号(ACK)
	*/
	/* SCL拉低 */
	SCL_LOW;
	/* SDA初始化为通用推挽输出 */
	SDA_IO_OUT();
	/* SDA拉低 */
	SDA_LOW;
	/* 延时 */
	SOFT_IIC_Delay();
	/* SCL拉高 */
	SCL_HIGH;
	/* 延时 */
	SOFT_IIC_Delay();
	/* SCL拉低 */
	SCL_LOW;
}
/**
 * @brief 	模拟I2C产生非应答信号
 * @param 	无
 * @retval 	无
*/
static void SOFT_IIC_NoAck(void)
{
	/* 	
	在第九个时钟，数据发送端会释放SDA的控制权,由数据接
	收端控制SDA,若SDA为高电平,表示非应答信号(NACK),低电平表示应答信号(ACK)
	*/
	/* SCL拉低 */
	SCL_LOW;
	/* SDA初始化为通用推挽输出 */
	SDA_IO_OUT();
	/* 延时 */
	SOFT_IIC_Delay();
	/* SDA拉高 */
	SDA_HIGH;
	/* 延时 */
	SOFT_IIC_Delay();
	/* SCL拉高 */
	SCL_HIGH;
	/* 延时 */
	SOFT_IIC_Delay();
	/* SCL拉低 */
	SCL_LOW;
}
/**
 * @brief 	模拟I2C引脚初始化、置位
 * @param 	无
 * @retval 	无
*/
void SOFT_IIC_Initialize(void)
{
	/* 定义结构体 */
	GPIO_InitTypeDef GPIO_InitStruct;						//GPIO结构体
	RCC_APB2PeriphClockCmd(SOFT_IIC_CLK,ENABLE);			//使能SDA、SCL引脚时钟
	/* 配置模拟I2C引脚工作模式 */
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;				//通用推挽输出
	GPIO_InitStruct.GPIO_Pin=SOFT_IIC_SCL|SOFT_IIC_SDA;		//SDA、SCL引脚
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;			//速率50MHz
	GPIO_Init(SOFT_IIC_PORT,&GPIO_InitStruct);				//初始化I2C引脚
	/* 模拟I2C高阻态 */
	SDA_HIGH;												//SDA拉高
	SCL_HIGH;												//SCL拉高
}
/**
 * @brief 	模拟I2C_SDA引脚配置为上拉输入
 * @param 	无
 * @retval 	无
*/
void SDA_IO_IN(void)
{
	/* 定义结构体 */
	GPIO_InitTypeDef GPIO_InitStruct;						//GPIO结构体
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IPU;				//上拉输入
	GPIO_InitStruct.GPIO_Pin=SOFT_IIC_SDA;					//SDA引脚
	GPIO_Init(SOFT_IIC_PORT,&GPIO_InitStruct);				//初始化SDA引脚为输入
}
/**
 * @brief 	模拟I2C_SDA引脚配置为通用推挽输出
 * @param 	无
 * @retval 	无
*/
void SDA_IO_OUT(void)
{
	/* 定义结构体 */
	GPIO_InitTypeDef GPIO_InitStruct;						//GPIO结构体
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;				//通用推挽输出
	GPIO_InitStruct.GPIO_Pin=SOFT_IIC_SDA;					//SDA引脚
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;			//速率50MHz
	GPIO_Init(SOFT_IIC_PORT,&GPIO_InitStruct);				//初始化SDA引脚为输出
}
/**
 * @brief 	模拟I2C延时
 * @param 	无
 * @retval 	无
*/
void SOFT_IIC_Delay(void)
{
	/* 调用系统滴嗒定时器延时函数，延时两微秒 */
	Systick_DelayUs(2);
}
/**
 * @brief 	模拟I2C产生起始信号
 * @param 	无
 * @retval 	成功返回1 失败返回0
*/
uint8_t SOFT_IIC_Start(void)
{
	/*
	当SCL线是高电
	平时SDA线从高电平向低电平切换,这个情况表示通讯的起始。当SCL是高电平时SDA
	线由低电平向高电平切换,表示通讯的停止。起始和停止信号一般由主机产生
	*/
	/* 配置SDA引脚为输出 */
	SDA_IO_OUT();
	/* SDA拉高 */
	SDA_HIGH;
	/* SCL拉高 */
	SCL_HIGH;
	/* 延时 */
	SOFT_IIC_Delay();
	/* 判断SDA是否准备就绪 SDA高电平*/
	if(!SDA_READ){
		/* SDA没有就绪，产生起始信号失败，返回0 */
		return DISABLE;
	}
	/* SDA拉高 */
	SDA_LOW;
	/* 延时 */
	SOFT_IIC_Delay();
	/* 判断SDA是否成功拉低 */
	if(SDA_READ){
		/* SDA没有被拉低，产生起始信号失败，返回0 */
		return DISABLE;
	}
	/* SCL拉低 */
	SCL_LOW;
	/* 起始信号产生成功，返回1 */
	return ENABLE;
}
/**
 * @brief 	模拟I2C产生停止信号
 * @param 	无
 * @retval 	无
*/
void SOFT_IIC_Stop(void)
{
	/*
	当SCL线是高电
	平时SDA线从高电平向低电平切换,这个情况表示通讯的起始。当SCL是高电平时SDA
	线由低电平向高电平切换,表示通讯的停止。起始和停止信号一般由主机产生
	*/
	/* 配置SDA引脚为输出 */
	SDA_IO_OUT();
	/* SCL拉低 */
	SCL_LOW;
	/* SDA拉低 */
	SDA_LOW;
	/* SCL拉高 */
	SCL_HIGH;
	/* 延时 */
	SOFT_IIC_Delay();
	/* SDA拉高 */
	SDA_HIGH;
	/* 延时 */
	SOFT_IIC_Delay();
}
/**
 * @brief 	模拟I2C接收应答信号
 * @param 	无
 * @retval  成功返回1 失败返回0
*/
uint8_t SOFT_IIC_GetAck(void)
{
	uint8_t count=0;
	/* SDA配置为输入 */
	SDA_IO_IN();
	/* SDA拉高 */
	SDA_HIGH;
	/* 延时 */
	SOFT_IIC_Delay();
	/* SCL拉高 */
	SCL_HIGH;
	/* 延时 */
	SOFT_IIC_Delay();
	/* 等待应答信号 */
	while(SDA_READ){
		count++;
		if(count>250){
			/* 没有收到应答信号，函数失败，返回0 */
			SCL_LOW;
			return DISABLE;
		}
	}
	/* 成功受到应答信号，返回1 */
	SCL_LOW;
	return ENABLE;
}
/**
 * @brief 	模拟I2C发送一字节数据
 * @param 	data要发送的数据
 * @retval 	无
*/
void SOFT_IIC_SendData(uint8_t data)
{
	uint8_t x;
	/* SDA配置为输出 */
	SDA_IO_OUT();
	/* 埃位发送数据 */
	for(x=0;x<8;x++){
		/* SCL拉低 */
		SCL_LOW;
		/* 延时 */
		SOFT_IIC_Delay();
		/* 判断数据Bit位为0还是1 */
		if(data&0x80){
			/* 为1，SDA拉高，发送1 */
			SDA_HIGH;
		}else{
			/* 为1，SDA拉低，发送0 */
			SDA_LOW;
		}
		/* 数据左移一位 */
		data<<=1;
		/* SDA拉高 */
		SCL_HIGH;
		/* 延时 */
		SOFT_IIC_Delay();
	}
	/* SCL拉低 */
	SCL_LOW;
	/* 延时 */
	SOFT_IIC_Delay();
}
/**
 * @brief 	模拟I2C读取一字节数据
 * @param 	ack 产生应答还是非应答信号 非应答1 应答0
 * @retval 	返回读取数据
*/
uint8_t SOFT_IIC_ReadData(uint8_t ack)
{
	uint8_t x,data=0;
	/* SDA配置为输入 */
	SDA_IO_IN();
	for(x=0;x<8;x++){
		/* SCL拉低 */
		SCL_LOW;
		/* 延时 */
		SOFT_IIC_Delay();
		/* SCL拉高 */
		SCL_HIGH;
		/* 数据左移一位 */
		data<<=1;
		/* 读取SDA引脚 */
		if(SDA_READ){
			/* 高电平，数据或1 */
			data|=0x01;
		}
		/* 延时 */
		SOFT_IIC_Delay();
	}
	/* 判断是否应答 */
	if(ack==1){
		/* 非应答 */
		SOFT_IIC_NoAck();
	}else{
		/* 应答 */
		SOFT_IIC_Ack();
	}
	/* 返回接收数据 */
	return data;
}