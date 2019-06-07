#ifndef __NT35510_H
#define __NT35510_H

#include "fsmc.h"
#include "stm32f10x.h"
#include "usersystem.h"
#include "sram.h"

#define LCD_BL_CLK				RCC_APB2Periph_GPIOB			//LCD背光
#define LCD_BL_PORT				GPIOB
#define LCD_BL_PIN				GPIO_Pin_0
#define LCD_BL					PBout(0)
typedef struct													//NT35510结构体
{
	vu16 NT35510_Cmd;
	vu16 NT35510_Data;
}NT35510_TypeDef;			    
#define NT35510_BASE        ((u32)(0x6C000000|0x000007FE))		//NT35510基址
#define NT35510             ((NT35510_TypeDef*)NT35510_BASE)	//NT35510结构体
#define NT35510_SetX		0x2A00								//设置X坐标命令
#define NT35510_SetY		0x2B00								//设置Y坐标命令
#define NT35510_WRAM		0x2C00								//写NT35510 GRAM命令

void NT35510_WR_CMD(vu16 cmd);									//NT35510写命令函数
void NT35510_WR_DATA(vu16 data);								//NT35510写数据函数
u16 NT35510_READ_DATA(void);									//NT35510读数据函数
void NT35510_WriteCmd(vu16 cmd,vu16 data);						//NT35510写数据函数
void NT35510_Clear(vu16 color);									//NT35510清屏函数
void NT35510_OpenWindow(vu16 xstart,vu16 ystart,vu16 width,vu16 height);						//NT35510开窗函数
void NT35510_ShowStr(vu16 xstart,vu16 ystart,vu16 width,vu16 height,const unsigned char str);	//NT35510显示ASCII函数
void NT35510_ShowString(u8* str,vu16 len);														//NT35510显示字符串函数

#endif /* __NT35510_H */