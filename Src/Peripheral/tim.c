#include "tim.h"

void BASIC_TIM_Initialize(void)
{
	/* 定义结构体 */
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;			//定时器基本初始化结构体
	NVIC_InitTypeDef NVIC_InitStruct;						//中断优先级配置结构体
	/* 使能基本定时器6时钟 */
	RCC_APB1PeriphClockCmd(TIM6_CLK,ENABLE);

	/* 时钟分频因子 ,基本定时器没有,不用管 */
	// TIM_TimeBaseInitStruct.TIM_ClockDivision=0x00;
	/* 计数器计数模式,基本定时器只能向上计数,没有计数模式的设置 */
	// TIM_TimeBaseInitStruct.TIM_CounterMode=TIM_CounterMode_Up;
	/* 自动重装载寄存器周的值(计数值) */
	TIM_TimeBaseInitStruct.TIM_Period=1000;
	/* 时钟预分频数为 71,则驱动计数器的时钟 CK_CNT = CK_INT / (71+1)=1M */
	TIM_TimeBaseInitStruct.TIM_Prescaler=(72-1);
	/* 重复计数器的值,基本定时器没有,不用管 */
	// TIM_TimeBaseInitStruct.TIM_RepetitionCounter==0x00;
	TIM_TimeBaseInit(TIM6_PORT,&TIM_TimeBaseInitStruct);
	TIM_ClearFlag(TIM6_PORT,TIM_FLAG_Update);
	TIM_ITConfig(TIM6_PORT,TIM_IT_Update,ENABLE);
	TIM_Cmd(TIM6_PORT,ENABLE);

	/* 设置优先级分组 */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);									//设置优先组第0组，不设置默认组0
	/* 配置中断优先级 */
	NVIC_InitStruct.NVIC_IRQChannel=TIM6_IRQ;				//配置中断源TIM6
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;				//使能中断
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=0;	//抢占优先级
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=0;			//子优先级
	/* 初始化TIM6中断 */
	NVIC_Init(&NVIC_InitStruct);

	RCC_APB1PeriphClockCmd(TIM6_CLK,DISABLE);
}