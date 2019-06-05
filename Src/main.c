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

int main(void)
{
	LED_Config();
	USART_Config();
	SOFT_IIC_Config();
	FSMC_NT35510_Initialize();
	NT35510_OpenWindow(0,0,100,100);
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