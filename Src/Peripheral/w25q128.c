#include "w25q128.h"
/**
 * @brief 	使用SPI发送一字节数据 
 * @param 	data：要发送的数据
 * @retval	返回接收到的数据
 */
u8 SPI_Flash_SendData(vu8 data)
{
	/* 计数变量 */
	vu16 count=TIMEOUT;
	/* 等待发送缓冲区为空,读取TXE事件 */
	while(SPI_I2S_GetFlagStatus(SPI_PORT,SPI_I2S_FLAG_TXE)==RESET){
		if((count--)==0){
			printf("SPI TXE Error!\r\n");
			return 1;
		}
	}
	/* 写入数据寄存器,把要写入的数据写入发送缓冲区 */
	SPI_I2S_SendData(SPI_PORT,data);
	/* 初始化计数值 */
	count=TIMEOUT;
	/* 等待接收缓冲区非空,读取RXNE事件 */
	while(SPI_I2S_GetFlagStatus(SPI_PORT,SPI_I2S_FLAG_RXNE)==RESET){
		if((count--)==0){
			printf("SPI RXNE Error!\r\n");
			return 1;
		}
	}
	/* 读取数据寄存器,获取接收缓冲区数据 */
	return SPI_I2S_ReceiveData(SPI_PORT);
}
/**
 * @brief 	使用SPI接收一字节数据 
 * @param 	无
 * @retval	返回接收到的数据
 */
u8 SPI_Flash_ReadData(void)
{
	return SPI_Flash_SendData(Dummy);
}
/**
 * @brief 	SPI_FLASH读取ID函数 
 * @param 	无
 * @retval	返回FLASHID
 */
u32 SPI_Flash_ReadID(void)
{
	vu32 tmp=0;
	SPI_CS=LOW;
	SPI_Flash_SendData(W25Q128_JedecDeviceID);
	tmp=((SPI_Flash_SendData(Dummy))<<16);
	tmp|=((SPI_Flash_SendData(Dummy))<<8);
	tmp|=SPI_Flash_SendData(Dummy);
	SPI_CS=HIGH;
	return tmp;
}
/**
 * @brief 	SPI_FLASH写使能函数
 * @param 	无
 * @retval	无
 */
void SPI_Flash_WriteEnable(void)
{
	SPI_CS=LOW;
	SPI_Flash_SendData(W25Q128_WriteEnable);
	SPI_CS=HIGH;
}
/**
 * @brief 	SPI_FLASH等待状态函数
 * @param 	无
 * @retval	无
 */
void SPI_Flash_WaitForWriteEnd(void)
{
	vu8 Stat=0;
	SPI_CS=LOW;
	SPI_Flash_SendData(W25Q128_ReadStatusReg);
	do{
		Stat=SPI_Flash_SendData(Dummy);
	}while((Stat&0x01)==SET);
	SPI_CS=HIGH;
}
/**
 * @brief 	SPI_FLASH清除扇区函数
 * @param 	SectorNum：清除的扇区号
 * @retval	无
 */
void SPI_Flash_SectorErase(vu32 SectorNum)
{
	SectorNum*=4096;
	SPI_Flash_WriteEnable();
	SPI_Flash_WaitForWriteEnd();
	SPI_CS=LOW;
	SPI_Flash_SendData(W25Q128_SectorErase);
	SPI_Flash_SendData((u8)((SectorNum&0xFF0000)>>16));
	SPI_Flash_SendData((u8)((SectorNum&0xFF00)>>8));
	SPI_Flash_SendData((u8)(SectorNum&0xFF));
	SPI_CS=HIGH;
	SPI_Flash_WaitForWriteEnd();
}
/**
 * @brief 	SPI_FLASH清除全部数据函数
 * @param 	无
 * @retval	无
 */
void SPI_Flash_EraseAll(void)
{
	SPI_Flash_WriteEnable();
	SPI_Flash_WaitForWriteEnd();
	SPI_CS=LOW;
	SPI_Flash_SendData(W25Q128_ChipErase);
	SPI_CS=HIGH;
	SPI_Flash_WaitForWriteEnd();
}
/**
 * @brief 	SPI_FLASH页写入函数
 * @param 	data：写入数据指针
 * @param 	addr：写入地址
 * @param 	size：写入数据大小 应小于等于256
 * @retval	无
 */
void SPI_Flash_PageWrite(u8* data,vu32 addr,vu16 size)
{
	SPI_Flash_WriteEnable();
	SPI_Flash_WaitForWriteEnd();
	SPI_CS=LOW;
	SPI_Flash_SendData(W25Q128_PageProgram);
	SPI_Flash_SendData((u8)((addr&0xFF0000)>>16));
	SPI_Flash_SendData((u8)((addr&0xFF00)>>8));
	SPI_Flash_SendData((u8)(addr&0xFF));
	if(size>256){
		size=256;
	}
	while(size--){
		SPI_Flash_SendData(*data);
		data++;
	}
	SPI_CS=HIGH;
	SPI_Flash_WaitForWriteEnd();
}
/**
 * @brief 	SPI_FLASH读取数据函数
 * @param 	data：存放读取数据的指针
 * @param 	addr：读取数据的地址
 * @param 	size：读取数据大小
 * @retval	无
 */
void SPI_Flash_BufferRead(u8* data,vu32 addr,vu32 size)
{
	SPI_Flash_WriteEnable();
	SPI_Flash_WaitForWriteEnd();
	SPI_CS=LOW;
	SPI_Flash_SendData(W25Q128_ReadData);
	SPI_Flash_SendData((u8)((addr&0xFF0000)>>16));
	SPI_Flash_SendData((u8)((addr&0xFF00)>>8));
	SPI_Flash_SendData((u8)(addr&0xFF));
	while(size--){
		*data=SPI_Flash_SendData(Dummy);
		data++;
	}
	SPI_CS=HIGH;
}
/**
 * @brief 	SPI_FLASH不定量数据写入函数
 * @param 	data：写入数据指针
 * @param 	addr：写入地址 必须是扇区起始地址
 * @param 	size：写入数据大小
 * @retval	无
 */
u32 SPI_Flash_BufferWrite(u8* data,vu32 addr,vu32 size)
{
	u32 page=0,single=0;
	u32 x;
	page=size/W25Q128_PageSize;
	single=size%W25Q128_PageSize;
	if(size<=W25Q128_PageSize){
		SPI_Flash_PageWrite(data,addr,size);
		addr+=size;
	}else{
		for(x=0;x<page;x++){
			SPI_Flash_PageWrite(data,addr,W25Q128_PageSize);
			data+=W25Q128_PageSize;
			addr+=W25Q128_PageSize;
		}
		if(single!=0){
			SPI_Flash_PageWrite(data,addr,single);
			addr+=single;
		}
	}
	return addr;
}