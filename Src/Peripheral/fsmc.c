#include "fsmc.h"

void FSMC_SRAM_Initialize(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	FSMC_NORSRAMTimingInitTypeDef FSMC_SramWriteInitTimingStruct;
	FSMC_NORSRAMInitTypeDef FSMC_SramInitStruct;

	RCC_AHBPeriphClockCmd(FSMC_CLK,ENABLE);
	RCC_APB2PeriphClockCmd(FSMC_A0_CLK|FSMC_A1_CLK|FSMC_A2_CLK|FSMC_A3_CLK|FSMC_A4_CLK|FSMC_A5_CLK|FSMC_A6_CLK|FSMC_A7_CLK
							|FSMC_A8_CLK|FSMC_A9_CLK|FSMC_A10_CLK|FSMC_A11_CLK|FSMC_A12_CLK|FSMC_A13_CLK|FSMC_A14_CLK|FSMC_A15_CLK
							|FSMC_A16_CLK|FSMC_A17_CLK|FSMC_A18_CLK|FSMC_D0_CLK|FSMC_D1_CLK|FSMC_D2_CLK|FSMC_D3_CLK|FSMC_D4_CLK
							|FSMC_D5_CLK|FSMC_D6_CLK|FSMC_D7_CLK|FSMC_D8_CLK|FSMC_D9_CLK|FSMC_D10_CLK|FSMC_D11_CLK|FSMC_D12_CLK
							|FSMC_D13_CLK|FSMC_D14_CLK|FSMC_D15_CLK|FSMC_NOE_CLK|FSMC_NWE_CLK|FSMC_NE2_CLK|FSMC_NE3_CLK|FSMC_NE4_CLK
							|FSMC_NBL0_CLK|FSMC_NBL1_CLK,ENABLE);
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;

	GPIO_InitStruct.GPIO_Pin=FSMC_A0_PIN;
	GPIO_Init(FSMC_A0_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_A1_PIN;
	GPIO_Init(FSMC_A1_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_A2_PIN;
	GPIO_Init(FSMC_A2_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_A3_PIN;
	GPIO_Init(FSMC_A3_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_A4_PIN;
	GPIO_Init(FSMC_A4_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_A5_PIN;
	GPIO_Init(FSMC_A5_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_A6_PIN;
	GPIO_Init(FSMC_A6_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_A7_PIN;
	GPIO_Init(FSMC_A7_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_A8_PIN;
	GPIO_Init(FSMC_A8_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_A9_PIN;
	GPIO_Init(FSMC_A9_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_A10_PIN;
	GPIO_Init(FSMC_A10_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_A11_PIN;
	GPIO_Init(FSMC_A11_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_A12_PIN;
	GPIO_Init(FSMC_A12_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_A13_PIN;
	GPIO_Init(FSMC_A13_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_A14_PIN;
	GPIO_Init(FSMC_A14_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_A15_PIN;
	GPIO_Init(FSMC_A15_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_A16_PIN;
	GPIO_Init(FSMC_A16_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_A17_PIN;
	GPIO_Init(FSMC_A17_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_A18_PIN;
	GPIO_Init(FSMC_A18_PORT,&GPIO_InitStruct);
	/* FSMC_D0~FSMC_D15 */
	GPIO_InitStruct.GPIO_Pin=FSMC_D0_PIN;
	GPIO_Init(FSMC_D0_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_D1_PIN;
	GPIO_Init(FSMC_D1_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_D2_PIN;
	GPIO_Init(FSMC_D2_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_D3_PIN;
	GPIO_Init(FSMC_D3_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_D4_PIN;
	GPIO_Init(FSMC_D4_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_D5_PIN;
	GPIO_Init(FSMC_D5_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_D6_PIN;
	GPIO_Init(FSMC_D6_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_D7_PIN;
	GPIO_Init(FSMC_D7_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_D8_PIN;
	GPIO_Init(FSMC_D8_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_D9_PIN;
	GPIO_Init(FSMC_D9_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_D10_PIN;
	GPIO_Init(FSMC_D10_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_D11_PIN;
	GPIO_Init(FSMC_D11_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_D12_PIN;
	GPIO_Init(FSMC_D12_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_D13_PIN;
	GPIO_Init(FSMC_D13_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_D14_PIN;
	GPIO_Init(FSMC_D14_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_D15_PIN;
	GPIO_Init(FSMC_D15_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_NBL0_PIN;
	GPIO_Init(FSMC_NBL0_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_NBL1_PIN;
	GPIO_Init(FSMC_NBL1_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_NOE_PIN;
	GPIO_Init(FSMC_NOE_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_NWE_PIN;
	GPIO_Init(FSMC_NWE_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_NE3_PIN;
	GPIO_Init(FSMC_NE3_PORT,&GPIO_InitStruct);

	FSMC_SramWriteInitTimingStruct.FSMC_AccessMode=FSMC_AccessMode_A;
	FSMC_SramWriteInitTimingStruct.FSMC_AddressHoldTime=0x00;
	FSMC_SramWriteInitTimingStruct.FSMC_AddressSetupTime=0x00;
	FSMC_SramWriteInitTimingStruct.FSMC_BusTurnAroundDuration=0x00;
	FSMC_SramWriteInitTimingStruct.FSMC_CLKDivision=0x00;
	FSMC_SramWriteInitTimingStruct.FSMC_DataLatency=0x00;
	FSMC_SramWriteInitTimingStruct.FSMC_DataSetupTime=0x02;

	FSMC_SramInitStruct.FSMC_AsynchronousWait=FSMC_AsynchronousWait_Disable;
	FSMC_SramInitStruct.FSMC_Bank=FSMC_Bank1_NORSRAM3;
	FSMC_SramInitStruct.FSMC_BurstAccessMode=FSMC_BurstAccessMode_Disable;
	FSMC_SramInitStruct.FSMC_DataAddressMux=FSMC_DataAddressMux_Disable;
	FSMC_SramInitStruct.FSMC_ExtendedMode=FSMC_ExtendedMode_Disable;
	FSMC_SramInitStruct.FSMC_MemoryDataWidth=FSMC_MemoryDataWidth_16b;
	FSMC_SramInitStruct.FSMC_MemoryType=FSMC_MemoryType_SRAM;
	FSMC_SramInitStruct.FSMC_ReadWriteTimingStruct=&FSMC_SramWriteInitTimingStruct;
	FSMC_SramInitStruct.FSMC_WaitSignal=FSMC_WaitSignal_Disable;
	FSMC_SramInitStruct.FSMC_WaitSignalActive=FSMC_WaitSignalActive_BeforeWaitState;
	FSMC_SramInitStruct.FSMC_WaitSignalPolarity=FSMC_WaitSignalPolarity_Low;
	FSMC_SramInitStruct.FSMC_WrapMode=FSMC_WrapMode_Disable;
	FSMC_SramInitStruct.FSMC_WriteBurst=FSMC_WriteBurst_Disable;
	FSMC_SramInitStruct.FSMC_WriteOperation=FSMC_WriteOperation_Enable;
	FSMC_SramInitStruct.FSMC_WriteTimingStruct=&FSMC_SramWriteInitTimingStruct;
	FSMC_NORSRAMInit(&FSMC_SramInitStruct);
	FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM3,ENABLE);
}

void FSMC_NT35510_Initialize(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	FSMC_NORSRAMTimingInitTypeDef FSMC_LCDWriteTimeInitstruct;
	FSMC_NORSRAMInitTypeDef FSMC_LCDInitStruct;
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_FSMC,ENABLE);
	RCC_APB2PeriphClockCmd(FSMC_D0_CLK|FSMC_D1_CLK|FSMC_D2_CLK|FSMC_D3_CLK|FSMC_D4_CLK
							|FSMC_D5_CLK|FSMC_D6_CLK|FSMC_D7_CLK|FSMC_D8_CLK|FSMC_D9_CLK
							|FSMC_D10_CLK|FSMC_D11_CLK|FSMC_D12_CLK|FSMC_D13_CLK|FSMC_D14_CLK
							|FSMC_D15_CLK|FSMC_NE4_CLK|FSMC_A10_CLK|FSMC_NWE_CLK|FSMC_NOE_CLK|LCD_BL_CLK,ENABLE);
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;

	GPIO_InitStruct.GPIO_Pin=FSMC_D0_PIN;
	GPIO_Init(FSMC_D0_PORT,&GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin=FSMC_D1_PIN;
	GPIO_Init(FSMC_D1_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_D2_PIN;
	GPIO_Init(FSMC_D2_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_D3_PIN;
	GPIO_Init(FSMC_D3_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_D4_PIN;
	GPIO_Init(FSMC_D4_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_D5_PIN;
	GPIO_Init(FSMC_D5_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_D6_PIN;
	GPIO_Init(FSMC_D6_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_D7_PIN;
	GPIO_Init(FSMC_D7_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_D8_PIN;
	GPIO_Init(FSMC_D8_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_D9_PIN;
	GPIO_Init(FSMC_D9_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_D10_PIN;
	GPIO_Init(FSMC_D10_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_D11_PIN;
	GPIO_Init(FSMC_D11_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_D12_PIN;
	GPIO_Init(FSMC_D12_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_D13_PIN;
	GPIO_Init(FSMC_D13_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_D14_PIN;
	GPIO_Init(FSMC_D14_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_D15_PIN;
	GPIO_Init(FSMC_D15_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_A10_PIN;
	GPIO_Init(FSMC_A10_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_NE4_PIN;
	GPIO_Init(FSMC_NE4_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_NWE_PIN;
	GPIO_Init(FSMC_NWE_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=FSMC_NOE_PIN;
	GPIO_Init(FSMC_NOE_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=LCD_BL_PIN;
	GPIO_Init(LCD_BL_PORT,&GPIO_InitStruct);

	FSMC_LCDWriteTimeInitstruct.FSMC_AccessMode=FSMC_AccessMode_B;
	FSMC_LCDWriteTimeInitstruct.FSMC_AddressHoldTime=0x00;
	FSMC_LCDWriteTimeInitstruct.FSMC_AddressSetupTime=0x01;
	FSMC_LCDWriteTimeInitstruct.FSMC_BusTurnAroundDuration=0x00;
	FSMC_LCDWriteTimeInitstruct.FSMC_CLKDivision=0x00;
	FSMC_LCDWriteTimeInitstruct.FSMC_DataLatency=0x00;
	FSMC_LCDWriteTimeInitstruct.FSMC_DataSetupTime=0x04;

	FSMC_LCDInitStruct.FSMC_AsynchronousWait=FSMC_AsynchronousWait_Disable;
	FSMC_LCDInitStruct.FSMC_Bank=FSMC_Bank1_NORSRAM4;
	FSMC_LCDInitStruct.FSMC_BurstAccessMode=FSMC_BurstAccessMode_Disable;
	FSMC_LCDInitStruct.FSMC_DataAddressMux=FSMC_DataAddressMux_Disable;
	FSMC_LCDInitStruct.FSMC_ExtendedMode=FSMC_ExtendedMode_Disable;
	FSMC_LCDInitStruct.FSMC_MemoryDataWidth=FSMC_MemoryDataWidth_16b;
	FSMC_LCDInitStruct.FSMC_MemoryType=FSMC_MemoryType_NOR;
	FSMC_LCDInitStruct.FSMC_ReadWriteTimingStruct=&FSMC_LCDWriteTimeInitstruct;
	FSMC_LCDInitStruct.FSMC_WaitSignal=FSMC_WaitSignal_Disable;
	FSMC_LCDInitStruct.FSMC_WaitSignalActive=FSMC_WaitSignalActive_BeforeWaitState;
	FSMC_LCDInitStruct.FSMC_WaitSignalPolarity=FSMC_WaitSignalPolarity_Low;
	FSMC_LCDInitStruct.FSMC_WrapMode=FSMC_WrapMode_Disable;
	FSMC_LCDInitStruct.FSMC_WriteBurst=FSMC_WriteBurst_Disable;
	FSMC_LCDInitStruct.FSMC_WriteOperation=FSMC_WriteOperation_Enable;
	FSMC_LCDInitStruct.FSMC_WriteTimingStruct=&FSMC_LCDWriteTimeInitstruct;
	FSMC_NORSRAMInit(&FSMC_LCDInitStruct);
	FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM4,ENABLE);

	Systick_DelayMs(45);
	NT35510_WriteCmd(0xF000,0x55);
	NT35510_WriteCmd(0xF001,0xAA);
	NT35510_WriteCmd(0xF002,0x52);
	NT35510_WriteCmd(0xF003,0x08);
	NT35510_WriteCmd(0xF004,0x01);
	//AVDD Set AVDD 5.2V
	NT35510_WriteCmd(0xB000,0x0D);
	NT35510_WriteCmd(0xB001,0x0D);
	NT35510_WriteCmd(0xB002,0x0D);
	//AVDD ratio
	NT35510_WriteCmd(0xB600,0x34);
	NT35510_WriteCmd(0xB601,0x34);
	NT35510_WriteCmd(0xB602,0x34);
	//AVEE -5.2V
	NT35510_WriteCmd(0xB100,0x0D);
	NT35510_WriteCmd(0xB101,0x0D);
	NT35510_WriteCmd(0xB102,0x0D);
	//AVEE ratio
	NT35510_WriteCmd(0xB700,0x34);
	NT35510_WriteCmd(0xB701,0x34);
	NT35510_WriteCmd(0xB702,0x34);
	//VCL -2.5V
	NT35510_WriteCmd(0xB200,0x00);
	NT35510_WriteCmd(0xB201,0x00);
	NT35510_WriteCmd(0xB202,0x00);
	//VCL ratio
	NT35510_WriteCmd(0xB800,0x24);
	NT35510_WriteCmd(0xB801,0x24);
	NT35510_WriteCmd(0xB802,0x24);
	//VGH 15V (Free pump)
	NT35510_WriteCmd(0xBF00,0x01);
	NT35510_WriteCmd(0xB300,0x0F);
	NT35510_WriteCmd(0xB301,0x0F);
	NT35510_WriteCmd(0xB302,0x0F);
	//VGH ratio
	NT35510_WriteCmd(0xB900,0x34);
	NT35510_WriteCmd(0xB901,0x34);
	NT35510_WriteCmd(0xB902,0x34);
	//VGL_REG -10V
	NT35510_WriteCmd(0xB500,0x08);
	NT35510_WriteCmd(0xB501,0x08);
	NT35510_WriteCmd(0xB502,0x08);
	NT35510_WriteCmd(0xC200,0x03);
	//VGLX ratio
	NT35510_WriteCmd(0xBA00,0x24);
	NT35510_WriteCmd(0xBA01,0x24);
	NT35510_WriteCmd(0xBA02,0x24);
	//VGMP/VGSP 4.5V/0V
	NT35510_WriteCmd(0xBC00,0x00);
	NT35510_WriteCmd(0xBC01,0x78);
	NT35510_WriteCmd(0xBC02,0x00);
	//VGMN/VGSN -4.5V/0V
	NT35510_WriteCmd(0xBD00,0x00);
	NT35510_WriteCmd(0xBD01,0x78);
	NT35510_WriteCmd(0xBD02,0x00);
	//VCOM
	NT35510_WriteCmd(0xBE00,0x00);
	NT35510_WriteCmd(0xBE01,0x64);
	//Gamma Setting
	NT35510_WriteCmd(0xD100,0x00);
	NT35510_WriteCmd(0xD101,0x33);
	NT35510_WriteCmd(0xD102,0x00);
	NT35510_WriteCmd(0xD103,0x34);
	NT35510_WriteCmd(0xD104,0x00);
	NT35510_WriteCmd(0xD105,0x3A);
	NT35510_WriteCmd(0xD106,0x00);
	NT35510_WriteCmd(0xD107,0x4A);
	NT35510_WriteCmd(0xD108,0x00);
	NT35510_WriteCmd(0xD109,0x5C);
	NT35510_WriteCmd(0xD10A,0x00);
	NT35510_WriteCmd(0xD10B,0x81);
	NT35510_WriteCmd(0xD10C,0x00);
	NT35510_WriteCmd(0xD10D,0xA6);
	NT35510_WriteCmd(0xD10E,0x00);
	NT35510_WriteCmd(0xD10F,0xE5);
	NT35510_WriteCmd(0xD110,0x01);
	NT35510_WriteCmd(0xD111,0x13);
	NT35510_WriteCmd(0xD112,0x01);
	NT35510_WriteCmd(0xD113,0x54);
	NT35510_WriteCmd(0xD114,0x01);
	NT35510_WriteCmd(0xD115,0x82);
	NT35510_WriteCmd(0xD116,0x01);
	NT35510_WriteCmd(0xD117,0xCA);
	NT35510_WriteCmd(0xD118,0x02);
	NT35510_WriteCmd(0xD119,0x00);
	NT35510_WriteCmd(0xD11A,0x02);
	NT35510_WriteCmd(0xD11B,0x01);
	NT35510_WriteCmd(0xD11C,0x02);
	NT35510_WriteCmd(0xD11D,0x34);
	NT35510_WriteCmd(0xD11E,0x02);
	NT35510_WriteCmd(0xD11F,0x67);
	NT35510_WriteCmd(0xD120,0x02);
	NT35510_WriteCmd(0xD121,0x84);
	NT35510_WriteCmd(0xD122,0x02);
	NT35510_WriteCmd(0xD123,0xA4);
	NT35510_WriteCmd(0xD124,0x02);
	NT35510_WriteCmd(0xD125,0xB7);
	NT35510_WriteCmd(0xD126,0x02);
	NT35510_WriteCmd(0xD127,0xCF);
	NT35510_WriteCmd(0xD128,0x02);
	NT35510_WriteCmd(0xD129,0xDE);
	NT35510_WriteCmd(0xD12A,0x02);
	NT35510_WriteCmd(0xD12B,0xF2);
	NT35510_WriteCmd(0xD12C,0x02);
	NT35510_WriteCmd(0xD12D,0xFE);
	NT35510_WriteCmd(0xD12E,0x03);
	NT35510_WriteCmd(0xD12F,0x10);
	NT35510_WriteCmd(0xD130,0x03);
	NT35510_WriteCmd(0xD131,0x33);
	NT35510_WriteCmd(0xD132,0x03);
	NT35510_WriteCmd(0xD133,0x6D);
	NT35510_WriteCmd(0xD200,0x00);
	NT35510_WriteCmd(0xD201,0x33);
	NT35510_WriteCmd(0xD202,0x00);
	NT35510_WriteCmd(0xD203,0x34);
	NT35510_WriteCmd(0xD204,0x00);
	NT35510_WriteCmd(0xD205,0x3A);
	NT35510_WriteCmd(0xD206,0x00);
	NT35510_WriteCmd(0xD207,0x4A);
	NT35510_WriteCmd(0xD208,0x00);
	NT35510_WriteCmd(0xD209,0x5C);
	NT35510_WriteCmd(0xD20A,0x00);

	NT35510_WriteCmd(0xD20B,0x81);
	NT35510_WriteCmd(0xD20C,0x00);
	NT35510_WriteCmd(0xD20D,0xA6);
	NT35510_WriteCmd(0xD20E,0x00);
	NT35510_WriteCmd(0xD20F,0xE5);
	NT35510_WriteCmd(0xD210,0x01);
	NT35510_WriteCmd(0xD211,0x13);
	NT35510_WriteCmd(0xD212,0x01);
	NT35510_WriteCmd(0xD213,0x54);
	NT35510_WriteCmd(0xD214,0x01);
	NT35510_WriteCmd(0xD215,0x82);
	NT35510_WriteCmd(0xD216,0x01);
	NT35510_WriteCmd(0xD217,0xCA);
	NT35510_WriteCmd(0xD218,0x02);
	NT35510_WriteCmd(0xD219,0x00);
	NT35510_WriteCmd(0xD21A,0x02);
	NT35510_WriteCmd(0xD21B,0x01);
	NT35510_WriteCmd(0xD21C,0x02);
	NT35510_WriteCmd(0xD21D,0x34);
	NT35510_WriteCmd(0xD21E,0x02);
	NT35510_WriteCmd(0xD21F,0x67);
	NT35510_WriteCmd(0xD220,0x02);
	NT35510_WriteCmd(0xD221,0x84);
	NT35510_WriteCmd(0xD222,0x02);
	NT35510_WriteCmd(0xD223,0xA4);
	NT35510_WriteCmd(0xD224,0x02);
	NT35510_WriteCmd(0xD225,0xB7);
	NT35510_WriteCmd(0xD226,0x02);
	NT35510_WriteCmd(0xD227,0xCF);
	NT35510_WriteCmd(0xD228,0x02);
	NT35510_WriteCmd(0xD229,0xDE);
	NT35510_WriteCmd(0xD22A,0x02);
	NT35510_WriteCmd(0xD22B,0xF2);
	NT35510_WriteCmd(0xD22C,0x02);
	NT35510_WriteCmd(0xD22D,0xFE);
	NT35510_WriteCmd(0xD22E,0x03);
	NT35510_WriteCmd(0xD22F,0x10);
	NT35510_WriteCmd(0xD230,0x03);
	NT35510_WriteCmd(0xD231,0x33);
	NT35510_WriteCmd(0xD232,0x03);
	NT35510_WriteCmd(0xD233,0x6D);
	NT35510_WriteCmd(0xD300,0x00);
	NT35510_WriteCmd(0xD301,0x33);
	NT35510_WriteCmd(0xD302,0x00);
	NT35510_WriteCmd(0xD303,0x34);
	NT35510_WriteCmd(0xD304,0x00);
	NT35510_WriteCmd(0xD305,0x3A);
	NT35510_WriteCmd(0xD306,0x00);
	NT35510_WriteCmd(0xD307,0x4A);
	NT35510_WriteCmd(0xD308,0x00);
	NT35510_WriteCmd(0xD309,0x5C);
	NT35510_WriteCmd(0xD30A,0x00);

	NT35510_WriteCmd(0xD30B,0x81);
	NT35510_WriteCmd(0xD30C,0x00);
	NT35510_WriteCmd(0xD30D,0xA6);
	NT35510_WriteCmd(0xD30E,0x00);
	NT35510_WriteCmd(0xD30F,0xE5);
	NT35510_WriteCmd(0xD310,0x01);
	NT35510_WriteCmd(0xD311,0x13);
	NT35510_WriteCmd(0xD312,0x01);
	NT35510_WriteCmd(0xD313,0x54);
	NT35510_WriteCmd(0xD314,0x01);
	NT35510_WriteCmd(0xD315,0x82);
	NT35510_WriteCmd(0xD316,0x01);
	NT35510_WriteCmd(0xD317,0xCA);
	NT35510_WriteCmd(0xD318,0x02);
	NT35510_WriteCmd(0xD319,0x00);
	NT35510_WriteCmd(0xD31A,0x02);
	NT35510_WriteCmd(0xD31B,0x01);
	NT35510_WriteCmd(0xD31C,0x02);
	NT35510_WriteCmd(0xD31D,0x34);
	NT35510_WriteCmd(0xD31E,0x02);
	NT35510_WriteCmd(0xD31F,0x67);
	NT35510_WriteCmd(0xD320,0x02);
	NT35510_WriteCmd(0xD321,0x84);
	NT35510_WriteCmd(0xD322,0x02);
	NT35510_WriteCmd(0xD323,0xA4);
	NT35510_WriteCmd(0xD324,0x02);
	NT35510_WriteCmd(0xD325,0xB7);
	NT35510_WriteCmd(0xD326,0x02);
	NT35510_WriteCmd(0xD327,0xCF);
	NT35510_WriteCmd(0xD328,0x02);
	NT35510_WriteCmd(0xD329,0xDE);
	NT35510_WriteCmd(0xD32A,0x02);
	NT35510_WriteCmd(0xD32B,0xF2);
	NT35510_WriteCmd(0xD32C,0x02);
	NT35510_WriteCmd(0xD32D,0xFE);
	NT35510_WriteCmd(0xD32E,0x03);
	NT35510_WriteCmd(0xD32F,0x10);
	NT35510_WriteCmd(0xD330,0x03);
	NT35510_WriteCmd(0xD331,0x33);
	NT35510_WriteCmd(0xD332,0x03);
	NT35510_WriteCmd(0xD333,0x6D);
	NT35510_WriteCmd(0xD400,0x00);
	NT35510_WriteCmd(0xD401,0x33);
	NT35510_WriteCmd(0xD402,0x00);
	NT35510_WriteCmd(0xD403,0x34);
	NT35510_WriteCmd(0xD404,0x00);
	NT35510_WriteCmd(0xD405,0x3A);
	NT35510_WriteCmd(0xD406,0x00);
	NT35510_WriteCmd(0xD407,0x4A);
	NT35510_WriteCmd(0xD408,0x00);
	NT35510_WriteCmd(0xD409,0x5C);
	NT35510_WriteCmd(0xD40A,0x00);
	NT35510_WriteCmd(0xD40B,0x81);

	NT35510_WriteCmd(0xD40C,0x00);
	NT35510_WriteCmd(0xD40D,0xA6);
	NT35510_WriteCmd(0xD40E,0x00);
	NT35510_WriteCmd(0xD40F,0xE5);
	NT35510_WriteCmd(0xD410,0x01);
	NT35510_WriteCmd(0xD411,0x13);
	NT35510_WriteCmd(0xD412,0x01);
	NT35510_WriteCmd(0xD413,0x54);
	NT35510_WriteCmd(0xD414,0x01);
	NT35510_WriteCmd(0xD415,0x82);
	NT35510_WriteCmd(0xD416,0x01);
	NT35510_WriteCmd(0xD417,0xCA);
	NT35510_WriteCmd(0xD418,0x02);
	NT35510_WriteCmd(0xD419,0x00);
	NT35510_WriteCmd(0xD41A,0x02);
	NT35510_WriteCmd(0xD41B,0x01);
	NT35510_WriteCmd(0xD41C,0x02);
	NT35510_WriteCmd(0xD41D,0x34);
	NT35510_WriteCmd(0xD41E,0x02);
	NT35510_WriteCmd(0xD41F,0x67);
	NT35510_WriteCmd(0xD420,0x02);
	NT35510_WriteCmd(0xD421,0x84);
	NT35510_WriteCmd(0xD422,0x02);
	NT35510_WriteCmd(0xD423,0xA4);
	NT35510_WriteCmd(0xD424,0x02);
	NT35510_WriteCmd(0xD425,0xB7);
	NT35510_WriteCmd(0xD426,0x02);
	NT35510_WriteCmd(0xD427,0xCF);
	NT35510_WriteCmd(0xD428,0x02);
	NT35510_WriteCmd(0xD429,0xDE);
	NT35510_WriteCmd(0xD42A,0x02);
	NT35510_WriteCmd(0xD42B,0xF2);
	NT35510_WriteCmd(0xD42C,0x02);
	NT35510_WriteCmd(0xD42D,0xFE);
	NT35510_WriteCmd(0xD42E,0x03);
	NT35510_WriteCmd(0xD42F,0x10);
	NT35510_WriteCmd(0xD430,0x03);
	NT35510_WriteCmd(0xD431,0x33);
	NT35510_WriteCmd(0xD432,0x03);
	NT35510_WriteCmd(0xD433,0x6D);
	NT35510_WriteCmd(0xD500,0x00);
	NT35510_WriteCmd(0xD501,0x33);
	NT35510_WriteCmd(0xD502,0x00);
	NT35510_WriteCmd(0xD503,0x34);
	NT35510_WriteCmd(0xD504,0x00);
	NT35510_WriteCmd(0xD505,0x3A);
	NT35510_WriteCmd(0xD506,0x00);
	NT35510_WriteCmd(0xD507,0x4A);
	NT35510_WriteCmd(0xD508,0x00);
	NT35510_WriteCmd(0xD509,0x5C);
	NT35510_WriteCmd(0xD50A,0x00);
	NT35510_WriteCmd(0xD50B,0x81);

	NT35510_WriteCmd(0xD50C,0x00);
	NT35510_WriteCmd(0xD50D,0xA6);
	NT35510_WriteCmd(0xD50E,0x00);
	NT35510_WriteCmd(0xD50F,0xE5);
	NT35510_WriteCmd(0xD510,0x01);
	NT35510_WriteCmd(0xD511,0x13);
	NT35510_WriteCmd(0xD512,0x01);
	NT35510_WriteCmd(0xD513,0x54);
	NT35510_WriteCmd(0xD514,0x01);
	NT35510_WriteCmd(0xD515,0x82);
	NT35510_WriteCmd(0xD516,0x01);
	NT35510_WriteCmd(0xD517,0xCA);
	NT35510_WriteCmd(0xD518,0x02);
	NT35510_WriteCmd(0xD519,0x00);
	NT35510_WriteCmd(0xD51A,0x02);
	NT35510_WriteCmd(0xD51B,0x01);
	NT35510_WriteCmd(0xD51C,0x02);
	NT35510_WriteCmd(0xD51D,0x34);
	NT35510_WriteCmd(0xD51E,0x02);
	NT35510_WriteCmd(0xD51F,0x67);
	NT35510_WriteCmd(0xD520,0x02);
	NT35510_WriteCmd(0xD521,0x84);
	NT35510_WriteCmd(0xD522,0x02);
	NT35510_WriteCmd(0xD523,0xA4);
	NT35510_WriteCmd(0xD524,0x02);
	NT35510_WriteCmd(0xD525,0xB7);
	NT35510_WriteCmd(0xD526,0x02);
	NT35510_WriteCmd(0xD527,0xCF);
	NT35510_WriteCmd(0xD528,0x02);
	NT35510_WriteCmd(0xD529,0xDE);
	NT35510_WriteCmd(0xD52A,0x02);
	NT35510_WriteCmd(0xD52B,0xF2);
	NT35510_WriteCmd(0xD52C,0x02);
	NT35510_WriteCmd(0xD52D,0xFE);
	NT35510_WriteCmd(0xD52E,0x03);
	NT35510_WriteCmd(0xD52F,0x10);
	NT35510_WriteCmd(0xD530,0x03);
	NT35510_WriteCmd(0xD531,0x33);
	NT35510_WriteCmd(0xD532,0x03);
	NT35510_WriteCmd(0xD533,0x6D);
	NT35510_WriteCmd(0xD600,0x00);
	NT35510_WriteCmd(0xD601,0x33);
	NT35510_WriteCmd(0xD602,0x00);
	NT35510_WriteCmd(0xD603,0x34);
	NT35510_WriteCmd(0xD604,0x00);
	NT35510_WriteCmd(0xD605,0x3A);
	NT35510_WriteCmd(0xD606,0x00);
	NT35510_WriteCmd(0xD607,0x4A);
	NT35510_WriteCmd(0xD608,0x00);
	NT35510_WriteCmd(0xD609,0x5C);
	NT35510_WriteCmd(0xD60A,0x00);
	NT35510_WriteCmd(0xD60B,0x81);

	NT35510_WriteCmd(0xD60C,0x00);
	NT35510_WriteCmd(0xD60D,0xA6);
	NT35510_WriteCmd(0xD60E,0x00);
	NT35510_WriteCmd(0xD60F,0xE5);
	NT35510_WriteCmd(0xD610,0x01);
	NT35510_WriteCmd(0xD611,0x13);
	NT35510_WriteCmd(0xD612,0x01);
	NT35510_WriteCmd(0xD613,0x54);
	NT35510_WriteCmd(0xD614,0x01);
	NT35510_WriteCmd(0xD615,0x82);
	NT35510_WriteCmd(0xD616,0x01);
	NT35510_WriteCmd(0xD617,0xCA);
	NT35510_WriteCmd(0xD618,0x02);
	NT35510_WriteCmd(0xD619,0x00);
	NT35510_WriteCmd(0xD61A,0x02);
	NT35510_WriteCmd(0xD61B,0x01);
	NT35510_WriteCmd(0xD61C,0x02);
	NT35510_WriteCmd(0xD61D,0x34);
	NT35510_WriteCmd(0xD61E,0x02);
	NT35510_WriteCmd(0xD61F,0x67);
	NT35510_WriteCmd(0xD620,0x02);
	NT35510_WriteCmd(0xD621,0x84);
	NT35510_WriteCmd(0xD622,0x02);
	NT35510_WriteCmd(0xD623,0xA4);
	NT35510_WriteCmd(0xD624,0x02);
	NT35510_WriteCmd(0xD625,0xB7);
	NT35510_WriteCmd(0xD626,0x02);
	NT35510_WriteCmd(0xD627,0xCF);
	NT35510_WriteCmd(0xD628,0x02);
	NT35510_WriteCmd(0xD629,0xDE);
	NT35510_WriteCmd(0xD62A,0x02);
	NT35510_WriteCmd(0xD62B,0xF2);
	NT35510_WriteCmd(0xD62C,0x02);
	NT35510_WriteCmd(0xD62D,0xFE);
	NT35510_WriteCmd(0xD62E,0x03);
	NT35510_WriteCmd(0xD62F,0x10);
	NT35510_WriteCmd(0xD630,0x03);
	NT35510_WriteCmd(0xD631,0x33);
	NT35510_WriteCmd(0xD632,0x03);
	NT35510_WriteCmd(0xD633,0x6D);
	//LV2 Page 0 enable
	NT35510_WriteCmd(0xF000,0x55);
	NT35510_WriteCmd(0xF001,0xAA);
	NT35510_WriteCmd(0xF002,0x52);
	NT35510_WriteCmd(0xF003,0x08);
	NT35510_WriteCmd(0xF004,0x00);
	//Display control
	NT35510_WriteCmd(0xB100, 0xCC);
	NT35510_WriteCmd(0xB101, 0x00);
	//Source hold time
	NT35510_WriteCmd(0xB600,0x05);
	//Gate EQ control
	NT35510_WriteCmd(0xB700,0x70);
	NT35510_WriteCmd(0xB701,0x70);
	//Source EQ control (Mode 2)
	NT35510_WriteCmd(0xB800,0x01);
	NT35510_WriteCmd(0xB801,0x03);
	NT35510_WriteCmd(0xB802,0x03);
	NT35510_WriteCmd(0xB803,0x03);
	//Inversion mode (2-dot)
	NT35510_WriteCmd(0xBC00,0x02);
	NT35510_WriteCmd(0xBC01,0x00);
	NT35510_WriteCmd(0xBC02,0x00);
	//Timing control 4H w/ 4-delay
	NT35510_WriteCmd(0xC900,0xD0);
	NT35510_WriteCmd(0xC901,0x02);
	NT35510_WriteCmd(0xC902,0x50);
	NT35510_WriteCmd(0xC903,0x50);
	NT35510_WriteCmd(0xC904,0x50);
	NT35510_WriteCmd(0x3500,0x00);
	NT35510_WriteCmd(0x3A00,0x55);  //16-bit/pixel
	NT35510_WR_CMD(0x1100);
	Systick_DelayUs(110);
	NT35510_WR_CMD(0x2900);
	NT35510_Clear(0xF800);
	Systick_DelayMs(30);
	LCD_BL=1;
}