#include "lcd12864.h"

void LCD12864_Initialize(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	RCC_APB2PeriphClockCmd(LCD12864_DB0_CLK|LCD12864_DB1_CLK|LCD12864_DB2_CLK|LCD12864_DB3_CLK
						|LCD12864_DB4_CLK|LCD12864_DB5_CLK|LCD12864_DB6_CLK|LCD12864_DB7_CLK
						|LCD12864_RS_CLK|LCD12864_RW_CLK|LCD12864_EN_CLK|LCD12864_PSB_CLK|LCD12864_RST_CLK,ENABLE);
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;

	GPIO_InitStruct.GPIO_Pin=LCD12864_DB0_PIN|LCD12864_DB1_PIN|LCD12864_DB2_PIN|LCD12864_DB3_PIN|LCD12864_DB4_PIN|LCD12864_DB5_PIN \
							|LCD12864_DB6_PIN|LCD12864_DB7_PIN;
	GPIO_Init(LCD12864_DB0_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=LCD12864_RS_PIN|LCD12864_RW_PIN|LCD12864_EN_PIN;
	GPIO_Init(LCD12864_RS_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=LCD12864_PSB_PIN|LCD12864_RST_PIN;
	GPIO_Init(LCD12864_PSB_PORT,&GPIO_InitStruct);
	RST=HIGH;
	PSB=HIGH;
	LCD12864_WriteCmd(0x30);
	Systick_DelayMs(5);
	LCD12864_WriteCmd(0x0C);
	Systick_DelayMs(5);
	LCD12864_WriteCmd(0x01);
	Systick_DelayMs(5);
}
void LCD12864_WriteCmd(vu8 cmd)
{
	RS=LOW;
	RW=LOW;
	EN=LOW;
	DataPORT(cmd);
	Systick_DelayMs(5);
	EN=HIGH;
	Systick_DelayMs(5);
	EN=LOW;
}

void LCD12864_WriteData(vu8 Data)
{
	RS=HIGH;
	RW=LOW;
	EN=LOW;
	DataPORT(Data);
	Systick_DelayUs(1000);
	EN=HIGH;
	Systick_DelayUs(1000);
	EN=LOW;
}

void LCD12864_SetXY(vu8 x,vu8 y)
{
	vu8 set;
   	if(x==0){
		x=0x80;
	}else if(x==1){
		x=0x90;
	}else if(x==2){
		x=0x88;
	}else if(x==3){
		x=0x98;
	}
   set =x+y;  
   LCD12864_WriteCmd(set);
}

void LCD12864_Display(void)
{
	vu8 x;
	vu8 str[]={'L','C','D','1','2','8','6','4',0xB2,0xE2,0xCA,0xD4};
	vu8 str1[]={0xCA,0xB1,0xBC,0xE4,':','2','0','1','9','-','6','-','1','4'};
	vu8 str2[]={'B','y',':',' ',0xD2,0xB0,0xC2,0xED,0xB3,0xAF};
	LCD12864_SetXY(0,1);
	for(x=0;x<12;x++){
		LCD12864_WriteData(str[x]);
	}
	LCD12864_SetXY(1,0);
	for(x=0;x<14;x++){
		LCD12864_WriteData(str1[x]);
	}
	LCD12864_SetXY(2,0);
	for(x=0;x<10;x++){
		LCD12864_WriteData(str2[x]);
	}
}