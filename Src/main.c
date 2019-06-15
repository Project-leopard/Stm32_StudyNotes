#include <stdio.h>
#include "usersystem.h"
#include "usart.h"
#include "led.h"
#include "eeprom.h"
#include "iic.h"
#include "soft_iic.h"
#include "spi.h"
#include "w25q128.h"
#include "ff.h"
#include "fsmc.h"
#include "sram.h"
#include "nt35510.h"
#include "tim.h"
#include "lcd12864.h"

int main(void)
{
	LED_Initialize();
	USART_Initialize();
	SOFT_IIC_Initialize();
	SPI_Flash_Initialize();
	FSMC_SRAM_Initialize();
	FSMC_NT35510_Initialize();
	LCD12864_Initialize();
	printf("dnf.qq.com\r\n");
	LCD12864_Display();
	while(1){
		RED=LED_ON;
		GREEN=LED_OFF;
		Systick_DelayMs(500);
		RED=LED_OFF;
		GREEN=LED_ON;
		Systick_DelayMs(500);
	}
    return 0;
}