#工程的名称及最后生成文件的名字
TARGET = ZET6_Project

#设定临时性环境变量
export CC             = arm-atollic-eabi-gcc           
export AS             = arm-atollic-eabi-as
export LD             = arm-atollic-eabi-ld
export OBJCOPY        = arm-atollic-eabi-objcopy

#读取当前工作目录
TOP=$(shell pwd)
DEBUG=$(TOP)/Debug/
RELEASE=$(TOP)/Release/

#设定包含文件目录
INC_FLAGS=	-I $(TOP)/Libraries/STM32F10x_StdPeriph_Driver/src \
			-I $(TOP)/Libraries/STM32F10x_StdPeriph_Driver/inc \
			-I $(TOP)/Libraries/CMSIS/Device/ST/STM32F10x/Include \
			-I $(TOP)/Libraries/CMSIS/Include \
			-I $(TOP)/Src/Peripheral \
			-I $(TOP)/Src/Fatfs \
			-I $(TOP)/Src

CFLAGS =  -W -Wall -g -mcpu=cortex-m3 -mthumb -std=gnu11 -D STM32F10X_HD -D USE_STDPERIPH_DRIVER $(INC_FLAGS) -Os -ffunction-sections -fdata-sections -fstack-usage -specs=nano.specs
C_SRC=$(shell find ./ -name '*.c')  
C_OBJ=$(C_SRC:%.c=%.o)

ASM_SRC=$(shell find ./ -name '*.s')
ASM_OBJ=$(ASM_SRC:%.s=%.o)

.PHONY: all clean update      

all:$(C_OBJ) $(ASM_OBJ)
	@$(CC) $(C_OBJ) $(ASM_OBJ) -T $(TOP)/Src/stm32_flash.ld -o $(DEBUG)$(TARGET).elf   -mthumb -mcpu=cortex-m3 -Wl,--start-group -lc -lm -Wl,--end-group -specs=nano.specs -specs=nosys.specs -static -Wl,-cref,-u,Reset_Handler -Wl,-Map=$(DEBUG)$(TARGET).map -Wl,--gc-sections -Wl,--defsym=malloc_getpagesize_P=0x80 
	@$(OBJCOPY) $(DEBUG)$(TARGET).elf  $(RELEASE)$(TARGET).bin -Obinary 
	@$(OBJCOPY) $(DEBUG)$(TARGET).elf  $(RELEASE)$(TARGET).hex -Oihex
	@du -h $(RELEASE)$(TARGET).bin
	@du -h $(RELEASE)$(TARGET).hex
	@size ./Debug/$(TARGET).elf

$(C_OBJ):%.o:%.c
	@$(CC) -c $(CFLAGS) -o $@ $<
	@echo -e "\033[31m $< \033[0m \033[32m $@ \033[0m"
$(ASM_OBJ):%.o:%.s
	@$(CC) -c $(ASFLAGS) -o $@ $<
	@echo -e "\033[31m $< \033[0m \033[32m $@ \033[0m"

clean:
	@rm -f $(shell find ./ -name '*.o')
	@rm -f $(shell find ./ -name '*.d')
	@rm -f $(shell find ./ -name '*.map')
	@rm -f $(shell find ./ -name '*.su')

update:
	STM32_Programmer_CLI -c port=SWD -d $(RELEASE)$(TARGET).hex -v -s 0x08000000