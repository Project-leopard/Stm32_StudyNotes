#STM32F103ZET6
一丶开发环境：  
1.必要开发工具  
	make  
	gcc-arm-none-eabi  
	STM32CubeProgrammer  
注：建议在Linux下进行开发  
2.可选开发工具  
	VScode>=1.34（插件安装C/C++、Cortex-Debug、ARM、可调试（调试功能不完整）、可烧录、VSCode任务（tasks）已经配置好，Linux下直接安装必要开发工具、VSCode和相关插件就可直接使用）  
二丶Src一些文件和文件夹描述  
Peripheral文件夹：外设驱动与功能实现  
eeprom.h  
eeprom.c	I2C读写EEPROM实现  
/---------------------------------------------------/  
fsmc.h  
fsmc.c		FSMC读写外部SRAM、TFTLCD驱动  
/---------------------------------------------------/  
iic.h  
iic.c		硬件I2C驱动  
注：由于STM32硬件I2C存在缺陷，所以未实现任何功能，仅做驱动  
/---------------------------------------------------/  
led.h  
led.c		开发板LED实现  
/---------------------------------------------------/  
nt35510.h  
nt35510.c	基于NT35510 IC芯片的TFTLCD实现 底层由FSMC驱动 分辨率为480*800  
/---------------------------------------------------/  
soft_iic.h  
soft_iic.c	IO模拟I2C实现  
/---------------------------------------------------/  
spi.h  
spi.c		SPI读写外部FLASH驱动  
/---------------------------------------------------/  
sram.h  
sram.c		读写外部SRAM实现 底层由FSMC驱动  
/---------------------------------------------------/  
usart.h  
usart.c		串口驱动与实现  
/---------------------------------------------------/  
w25q128.h  
w25q128.c	型号为W25Q128的FLASH实现 底层由SPI驱动  
/---------------------------------------------------/  
Fatfs文件夹：FAT文件系统移植实现  
具体实现请访问:http://elm-chan.org/fsw/ff/00index_e.html  
Src文件夹：用户代码实现  
main.c		main程序入口文件  
/---------------------------------------------------/  
startup_stm32f10x_hd.s	STM32启动文件 汇编代码  
/---------------------------------------------------/  
stm32f1xx_it.h  
stm32f1xx_it.c		为了方便管理 推荐把STM32中断服务函数写到这个文件  
/---------------------------------------------------/  
stm32f10x_conf.h	STM32头文件整合  
/---------------------------------------------------/  
syscalls.c			系统I/O重定向实现文件 如：printf定向串口、LCD  
/---------------------------------------------------/  
tiny_printf.c.bak	小尺寸printf实现 可缩小程序占用空间 删除后缀.bak即可  
/---------------------------------------------------/  
system_stm32f10x.c	STM32启动函数 如时钟源配置  
/---------------------------------------------------/  
usersystem.h  
usersystem.c		位带操作、系统滴嗒定时器实现  
/---------------------------------------------------/  
stm32_flash.ld		GCC链接文件  
/---------------------------------------------------/  
Makefile文件：  
Makefile			  