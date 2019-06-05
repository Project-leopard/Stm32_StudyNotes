#include "usersystem.h"
/**
 * @brief 	SysTick延时毫秒
 * @param 	ms 毫秒数 1=1毫秒
 * @retval 	无
*/
void Systick_DelayMs(volatile uint32_t ms)
{
	SysTick_Config(72000);
	while(ms--){
		while(!((SysTick->CTRL)&(1<<16)));
	}
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;
}
/**
 * @brief 	SysTick延时微秒
 * @param 	us 微秒数 1=1微秒
 * @retval 	无
*/
void Systick_DelayUs(volatile uint32_t us)
{
	SysTick_Config(72);
	while(us--){
		while(!((SysTick->CTRL)&(1<<16)));
	}
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;
}

u8 SPI_ErrorFun(vu8 code)
{
	if(code==0){
		printf("\r\nSPI_TXE Error\r\n");
		return 1;
	}
	if(code==1){
		printf("\r\nSPI_RXNE Error\r\n");
		return 2;
	}
	return 10;
}