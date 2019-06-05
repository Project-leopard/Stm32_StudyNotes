#include "spi.h"

void SPI_Flash_Config(void)
{
	SPI_InitTypeDef SPI_InitStruct;
	GPIO_InitTypeDef GPIO_InitStruct;
	RCC_APB2PeriphClockCmd(SPI_CS_CLK|SPI_SCK_CLK|SPI_MISO_CLK|SPI_MOSI_CLK,ENABLE);
	RCC_APB1PeriphClockCmd(SPI_CLK,ENABLE);

	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=SPI_CS_PIN;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(SPI_CS_PORT,&GPIO_InitStruct);
	GPIO_SetBits(SPI_CS_PORT,SPI_CS_PIN);

	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Pin=SPI_SCK_PIN;
	GPIO_Init(SPI_SCK_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Pin=SPI_MOSI_PIN;
	GPIO_Init(SPI_MOSI_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Pin=SPI_MISO_PIN;
	GPIO_Init(SPI_MISO_PORT,&GPIO_InitStruct);

	SPI_InitStruct.SPI_BaudRatePrescaler=SPI_BaudRatePrescaler_2;
	SPI_InitStruct.SPI_CPHA=SPI_CPHA_2Edge;
	SPI_InitStruct.SPI_CPOL=SPI_CPOL_High;
	SPI_InitStruct.SPI_CRCPolynomial=0;
	SPI_InitStruct.SPI_DataSize=SPI_DataSize_8b;
	SPI_InitStruct.SPI_Direction=SPI_Direction_2Lines_FullDuplex;
	SPI_InitStruct.SPI_FirstBit=SPI_FirstBit_MSB;
	SPI_InitStruct.SPI_Mode=SPI_Mode_Master;
	SPI_InitStruct.SPI_NSS=SPI_NSS_Soft;
	SPI_Init(SPI_PORT,&SPI_InitStruct);
	SPI_Cmd(SPI_PORT,ENABLE);
}