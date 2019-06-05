#ifndef __USART_H
#define __USART_H

#include "stm32f10x.h"

#define USART_CLK			RCC_APB2Periph_USART1				//串口时钟
#define USART_PORT			USART1								//USART1

#define USART_TX_CLK		RCC_APB2Periph_GPIOA				//串口发送引脚时钟
#define USART_TX_PORT		GPIOA								//GPIOA
#define USART_TX_PIN		GPIO_Pin_9							//串口发送引脚

#define USART_RX_CLK		RCC_APB2Periph_GPIOA				//串口接收引脚时钟
#define USART_RX_PORT		GPIOA								//GPIOA
#define USART_RX_PIN		GPIO_Pin_10							//串口接收引脚

#define USART_IRQN			USART1_IRQn							//串口中断源
#define USART_BAUD			115200								//串口波特率

void USART_Config(void);

#endif /* __USART_H */