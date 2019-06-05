#include "sram.h"

void SRAM_Test(void)
{
	u8 x;
	u8 *str=Bank1_SRAM3ADDR;
	u8 str1[]="WWW.SOUGOU.COM";
	for(x=0;x<15;x++){
		*(str+x)=str1[x];
	}
	printf("SRAM Test: %s\r\n",str);
	printf("Addr is: %p\r\n",str);
}