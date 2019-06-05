#ifndef __EEPROM_H
#define __EEPROM_H

#include <stdio.h>
#include "usersystem.h"
#include "stm32f10x.h"
#include "soft_iic.h"
#include "iic.h"

#define EEPROM_ADDR           		0xA0           //地址(设备地址)
#define EEPROM_WR                 	0x00           //写
#define EEPROM_RD                 	0x01           //读

uint8_t EEPROM_WriteData(volatile uint8_t data,volatile uint8_t addr);				//I2C向EEPROM写入一字节
uint8_t EEPROM_ReadData(volatile uint8_t addr);										//I2C向EEPROM读取一字节

#endif /* __EEPROM_H */