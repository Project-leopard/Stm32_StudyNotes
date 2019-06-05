#include "led.h"
/**
 * @brief 	战舰V3 LED初始化
 * @param 	无
 * @retval 	无
*/
void LED_Config(void)
{
	/* 定义结构体 */
	GPIO_InitTypeDef GPIO_InitStruct;					//GPIO结构体
	/* 使能LED引脚时钟 */
	RCC_APB2PeriphClockCmd(RED_CLK|GREEN_CLK,ENABLE);	//使能GPIOB与GPIOE
	/* 配置LED引脚工作模式 */
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;			//通用推挽输出
	GPIO_InitStruct.GPIO_Pin=RED_PIN;					//红色LED引脚
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;		//速率50MHz
	GPIO_Init(RED_PORT,&GPIO_InitStruct);				//初始化红色LED引脚
	GPIO_InitStruct.GPIO_Pin=GREEN_PIN;					//绿色LED引脚
	GPIO_Init(GREEN_PORT,&GPIO_InitStruct);				//初始化绿色LED引脚
	RED=LED_OFF;										//红色LED关
	GREEN=LED_OFF;										//绿色LED关
}