#ifndef __W25Q128_H
#define __W25Q128_H

#include "usersystem.h"
#include "stm32f10x.h"
#include "spi.h"

#define SPI_CS						PBout(12)
#define W25Q128_PageSize			0x100
#define Dummy						0xFF
#define W25Q128_WriteEnable			0x06 
#define W25Q128_WriteDisable		0x04 
#define W25Q128_ReadStatusReg		0x05 
#define W25Q128_WriteStatusReg		0x01 
#define W25Q128_ReadData			0x03 
#define W25Q128_FastReadData		0x0B 
#define W25Q128_FastReadDual		0x3B 
#define W25Q128_PageProgram			0x02 
#define W25Q128_BlockErase			0xD8 
#define W25Q128_SectorErase			0x20 
#define W25Q128_ChipErase			0xC7 
#define W25Q128_PowerDown			0xB9 
#define W25Q128_ReleasePowerDown	0xAB 
#define W25Q128_DeviceID			0xAB 
#define W25Q128_ManufactDeviceID	0x90 
#define W25Q128_JedecDeviceID		0x9F
#define HIGH						1
#define LOW							0
#define FLASH_ID					0xEF4018

u8 SPI_Flash_SendData(vu8 data);
u8 SPI_Flash_ReadData(void);
u32 SPI_Flash_ReadID(void);
void SPI_Flash_WriteEnable(void);
void SPI_Flash_WaitForWriteEnd(void);
void SPI_Flash_SectorErase(vu32 SectorNum);
void SPI_Flash_EraseAll(void);
void SPI_Flash_PageWrite(u8* data,vu32 addr,vu16 size);
void SPI_Flash_BufferRead(u8* data,vu32 addr,vu32 size);
u32 SPI_Flash_BufferWrite(u8* data,vu32 addr,vu32 size);

#endif /* __WQ25128 */