#ifndef __NT35510_H
#define __NT35510_H

#include "fsmc.h"
#include "stm32f10x.h"
#include "usersystem.h"

#define LCD_BL_CLK				RCC_APB2Periph_GPIOB
#define LCD_BL_PORT				GPIOB
#define LCD_BL_PIN				GPIO_Pin_0
#define LCD_BL					PBout(0)
typedef struct
{
	vu16 NT35510_Cmd;
	vu16 NT35510_Data;
}NT35510_TypeDef;			    
#define NT35510_BASE        ((u32)(0x6C000000|0x000007FE))
#define NT35510             ((NT35510_TypeDef*)NT35510_BASE)
#define NT35510_SetX		0x2A00
#define NT35510_SetY		0x2B00
#define NT35510_WRAM		0x2C00


void NT35510_WR_CMD(u16 cmd);
void NT35510_WR_DATA(u16 data);
u16 NT35510_READ_DATA(void);
void NT35510_WriteCmd(vu16 cmd,vu16 data);
void NT35510_Clear(vu16 color);
void NT35510_OpenWindow(vu16 xstart,vu16 ystart,vu16 width,vu16 height);

#endif /* __NT35510_H */