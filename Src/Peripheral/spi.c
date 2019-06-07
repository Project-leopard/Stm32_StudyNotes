#include "spi.h"
/**
 * @brief 	SPI读写FLASH初始化函数
 * @param 	无
 * @retval 	无
*/
void SPI_Flash_Initialize(void)
{
	/* 定义结构体 */
	SPI_InitTypeDef SPI_InitStruct;				//SPI初始化结构体
	GPIO_InitTypeDef GPIO_InitStruct;			//GPIO初始化结构体
	/* 使能SPI_FLASH相关引脚时钟 */
	RCC_APB2PeriphClockCmd(SPI_CS_CLK|SPI_SCK_CLK|SPI_MISO_CLK|SPI_MOSI_CLK,ENABLE);
	/* 使能SPI时钟 */
	RCC_APB1PeriphClockCmd(SPI_CLK,ENABLE);
	/* 配置SPI_FLASH相关引脚工作模式 */
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;			//通用推挽输出
	GPIO_InitStruct.GPIO_Pin=SPI_CS_PIN;				//SPI片选引脚
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;		//速率50MHz
	GPIO_Init(SPI_CS_PORT,&GPIO_InitStruct);			//初始化片选引脚
	GPIO_SetBits(SPI_CS_PORT,SPI_CS_PIN);				//引脚拉高，通讯停止

	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AF_PP;			//复用推挽输出
	GPIO_InitStruct.GPIO_Pin=SPI_SCK_PIN;				//SPI_SCK时钟引脚
	GPIO_Init(SPI_SCK_PORT,&GPIO_InitStruct);			//初始化SPI_SCK引脚

	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AF_PP;			//复用推挽输出
	GPIO_InitStruct.GPIO_Pin=SPI_MOSI_PIN;				//SPI_MOSI引脚
	GPIO_Init(SPI_MOSI_PORT,&GPIO_InitStruct);			//初始化SPI_MOSI引脚

	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;	//浮空输入
	GPIO_InitStruct.GPIO_Pin=SPI_MISO_PIN;				//SPI_MISO引脚
	GPIO_Init(SPI_MISO_PORT,&GPIO_InitStruct);			//初始化SPI_MISO引脚

	SPI_InitStruct.SPI_BaudRatePrescaler=SPI_BaudRatePrescaler_2;			//PCLK2 2分频
	SPI_InitStruct.SPI_CPHA=SPI_CPHA_2Edge;									//偶数边沿采样
	SPI_InitStruct.SPI_CPOL=SPI_CPOL_High;									//时钟极性 高电平
	SPI_InitStruct.SPI_CRCPolynomial=0;										//不使用校检表达式
	SPI_InitStruct.SPI_DataSize=SPI_DataSize_8b;							//SPI数据帧长度
	SPI_InitStruct.SPI_Direction=SPI_Direction_2Lines_FullDuplex;			//双线全双工模式
	SPI_InitStruct.SPI_FirstBit=SPI_FirstBit_MSB;							//数据高位先行
	SPI_InitStruct.SPI_Mode=SPI_Mode_Master;								//主机模式
	SPI_InitStruct.SPI_NSS=SPI_NSS_Soft;									//软件控制片选引脚
	/* 初始化SPI_FLASH */
	SPI_Init(SPI_PORT,&SPI_InitStruct);
	/* 使能SPI_FLASH */
	SPI_Cmd(SPI_PORT,ENABLE);
}