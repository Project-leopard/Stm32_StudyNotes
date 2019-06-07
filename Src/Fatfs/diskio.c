/*-----------------------------------------------------------------------*/
/* Low level disk I/O module skeleton for FatFs     (C)ChaN, 2016        */
/*-----------------------------------------------------------------------*/
/* If a working storage control module is available, it should be        */
/* attached to the FatFs via a glue function rather than modifying it.   */
/* This is an example of glue functions to attach various exsisting      */
/* storage control modules to the FatFs module with a defined API.       */
/*-----------------------------------------------------------------------*/

#include <stdio.h>
#include "ff.h"			/* Obtains integer types */
#include "diskio.h"		/* Declarations of disk functions */
#include "spi.h"
#include "w25q128.h"

/* Definitions of physical drive number for each drive */
#define DEV_W25Q128		0
#define DEV_SDCARD		1


/*-----------------------------------------------------------------------*/
/* Get Drive Status                                                      */
/*-----------------------------------------------------------------------*/

DSTATUS disk_status (
	BYTE pdrv		/* Physical drive nmuber to identify the drive */
)
{
	switch (pdrv) {
	case DEV_W25Q128 :
		if(SPI_Flash_ReadID()==FLASH_ID){
			//状态正常
			return 0;
		}else{
			//状态异常
			return STA_NOINIT;
		}
	case DEV_SDCARD :
		/* 在这里添加获取SD卡状态代码，并返回状态 */
		break;
	}
	return STA_NOINIT;
}



/*-----------------------------------------------------------------------*/
/* Inidialize a Drive                                                    */
/*-----------------------------------------------------------------------*/

DSTATUS disk_initialize (
	BYTE pdrv				/* Physical drive nmuber to identify the drive */
)
{
	switch (pdrv) {
	case DEV_W25Q128 :
		/* 调用SPI_Flash初始化函数 */
		SPI_Flash_Initialize();
		/* 读取FlashID，确认初始化正常，并返回Flash状态 */
		return disk_status(DEV_W25Q128);
	case DEV_SDCARD :
		/* 在这里添加SD卡初始化代码，并返回状态 */
		break;
	}
	return STA_NOINIT;
}



/*-----------------------------------------------------------------------*/
/* Read Sector(s)                                                        */
/*-----------------------------------------------------------------------*/

DRESULT disk_read (
	BYTE pdrv,		/* Physical drive nmuber to identify the drive */
	BYTE *buff,		/* Data buffer to store read data */
	DWORD sector,	/* Start sector in LBA */
	UINT count		/* Number of sectors to read */
)
{
	switch (pdrv) {
	case DEV_W25Q128 :
		/* 调用SPI_Flash写入读取数据函数 */
		SPI_Flash_BufferRead((u8*)buff,sector*4096,count*4096);
		return RES_OK;
	case DEV_SDCARD :
		/* 在这里添加SD卡读取数据代码，并返回状态 */
		break;
	}
	return RES_PARERR;
}



/*-----------------------------------------------------------------------*/
/* Write Sector(s)                                                       */
/*-----------------------------------------------------------------------*/

#if FF_FS_READONLY == 0

DRESULT disk_write (
	BYTE pdrv,			/* Physical drive nmuber to identify the drive */
	const BYTE *buff,	/* Data to be written */
	DWORD sector,		/* Start sector in LBA */
	UINT count			/* Number of sectors to write */
)
{
	switch (pdrv) {
	case DEV_W25Q128 :
		/* 写入数据之前先擦除扇区 */
		SPI_Flash_SectorErase(sector);
		/* 调用SPI_Flash写入数据函数 */
		SPI_Flash_BufferWrite((u8*)buff,sector*4096,count*4096);
		return RES_OK;
	case DEV_SDCARD :
		/* 在这里添加SD卡写入数据代码，并返回状态 */
		break;
	}
	return RES_PARERR;
}

#endif


/*-----------------------------------------------------------------------*/
/* Miscellaneous Functions                                               */
/*-----------------------------------------------------------------------*/

DRESULT disk_ioctl (
	BYTE pdrv,		/* Physical drive nmuber (0..) */
	BYTE cmd,		/* Control code */
	void *buff		/* Buffer to send/receive control data */
)
{
	switch (pdrv) {
	case DEV_W25Q128 :
		switch(cmd){
			/* 返回扇区个数 */
			case GET_SECTOR_COUNT :
			*((DWORD*)buff)=3840;
			break;
			/* 返回扇区大小 */
			case GET_SECTOR_SIZE :
			*((WORD*)buff)=4096;
			break;
			/* 返回擦除扇区最小个数 */
			case GET_BLOCK_SIZE :
			*((WORD*)buff)=1;
			break;
		}
	case DEV_SDCARD :
		/* 在这里添加SD卡信息代码，并返回状态 */
		break;
	}
	return RES_OK;
}

DWORD get_fattime(void)
{
	return 0;
}