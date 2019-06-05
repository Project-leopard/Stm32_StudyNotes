#ifndef __SRAM_H
#define __SRAM_H

#include "stm32f10x.h"
#include "usersystem.h"

#define Bank1_SRAM3ADDR				((u8*)0x68000000)

void SRAM_Test(void);

#endif /* __SRAM_H */