#ifndef __SRAM_H
#define __SRAM_H

#include "stm32f10x.h"
#include "usersystem.h"
#include "nt35510.h"
#include "w25q128.h"

#define Bank1_SRAM3ADDR				((u8*)0x68000000)			//外部SRAM起始地址
extern u8 *asc2_2412;											//外部SRAM ASCII指针
#endif /* __SRAM_H */