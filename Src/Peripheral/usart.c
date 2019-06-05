#include "usart.h"
/**
 * @brief 	串口初始化
 * @param 	无
 * @retval 	无
*/
void USART_Config(void)
{
	/* 定义结构体 */
	GPIO_InitTypeDef GPIO_InitStruct;												//GPIO结构体
	USART_InitTypeDef USART_InitStruct;												//串口结构体
	NVIC_InitTypeDef NVIC_InitStruct;												//中断结构体
	/* 使能串口与串口IO引脚时钟 */
	RCC_APB2PeriphClockCmd(USART_TX_CLK|USART_RX_CLK|USART_CLK,ENABLE);				//使能GPIO和USART1
	/* 设置优先级分组 */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);									//设置优先组第0组，不设置默认组0
	/* 配置串口中断优先级与使能串口中断源 */
	NVIC_InitStruct.NVIC_IRQChannel=USART_IRQN;										//配置中断源
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;										//使能中断
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=0;							//主优先级
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=0;									//子优先级
	NVIC_Init(&NVIC_InitStruct);													//初始化串口中断
	/* 配置串口发送引脚工作模式 */
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AF_PP;										//复用推挽输出
	GPIO_InitStruct.GPIO_Pin=USART_TX_PIN;											//串口发送引脚
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;									//50Mhz速率
	GPIO_Init(USART_TX_PORT,&GPIO_InitStruct);										//初始化串口发送引脚
	/* 配置串口接收引脚工作模式 */
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;								//浮空输入或带上拉输入
	GPIO_InitStruct.GPIO_Pin=USART_RX_PIN;											//串口接收引脚
	GPIO_Init(USART_RX_PORT,&GPIO_InitStruct);										//初始化串口接收引脚
	/* 配置串口工作模式 */
	USART_InitStruct.USART_BaudRate=USART_BAUD;										//设置串口波特率115200
	USART_InitStruct.USART_HardwareFlowControl=USART_HardwareFlowControl_None;		//硬件控制流不使用
	USART_InitStruct.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;						//工作模式全双工
	USART_InitStruct.USART_Parity=USART_Parity_No;									//奇偶校检不使用
	USART_InitStruct.USART_StopBits=USART_StopBits_1;								//停止位1停止位
	USART_InitStruct.USART_WordLength=USART_WordLength_8b;							//数据位8位数据位
	USART_Init(USART_PORT,&USART_InitStruct);										//初始化串口
	USART_ITConfig(USART_PORT,USART_IT_RXNE,ENABLE);								//使能串口中断，接收数据寄存器非空中断
	USART_Cmd(USART_PORT,ENABLE);													//使能串口
}