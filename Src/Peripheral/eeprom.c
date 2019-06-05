#include "eeprom.h"
/**
 * @brief 	向EEPROM写入一字节数据
 * @param 	data 要写入的数据
 * @param	addr 要写入的地址(EEPROM低地址)
 * @retval 	写入成功返回1 失败返回0
*/
uint8_t EEPROM_WriteData(volatile uint8_t data,volatile uint8_t addr)
{
	/* I2C写EEPROM流程，起始信号-发送EEPROM写地址-发送EEPROM低地址-发送写入数据 */
	/* 产生起始信号 */
	SOFT_IIC_Start();
	/* 发送EEPROM写地址 */
	SOFT_IIC_SendData(EEPROM_ADDR|EEPROM_WR);
	/* 等待EEPROM应答信号 */
	if(!SOFT_IIC_GetAck()){
		printf("SendADDR Error!\r\n");
		/* 产生停止信号 */
		SOFT_IIC_Stop();
		/* 返回0 */
		return DISABLE;
	}
	/* 发送EEPROM低地址 */
	SOFT_IIC_SendData(addr);
	/* 等待EEPROM应答信号 */
	if(!SOFT_IIC_GetAck()){
		printf("SendEEPROMADDR Error!\r\n");
		/* 产生停止信号 */
		SOFT_IIC_Stop();
		/* 返回0 */
		return DISABLE;
	}
	/* 发送写入数据 */
	SOFT_IIC_SendData(data);
	/* 等待EEPROM应答信号 */
	if(!SOFT_IIC_GetAck()){
		printf("SendData Error!\r\n");
		/* 产生停止信号 */
		SOFT_IIC_Stop();
		/* 返回0 */
		return DISABLE;
	}
	/* 产生停止信号 */
	SOFT_IIC_Stop();
	/* 延时等待数据写入完成 */
	Systick_DelayMs(10);
	/* 返回1 */
	return ENABLE;
}
/**
 * @brief 	从EEPROM读取一字节数据
 * @param 	addr 要读取数据的低地址
 * @retval 	成功返回读取到的数据 失败返回0
*/
uint8_t EEPROM_ReadData(volatile uint8_t addr)
{
	/* I2C读取EEPROM数据流程，起始信号-发送EEPROM写地址-发送EEPROM低地址-再次产生起始信号-发送EEPROM读地址-接收读取数据 */
	uint8_t data=0;
	/* 产生起始信号 */
	SOFT_IIC_Start();
	/* 发送EEPROM写地址 */
	SOFT_IIC_SendData(EEPROM_ADDR|EEPROM_WR);
	/* 等待EEPROM应答信号 */
	if(!SOFT_IIC_GetAck()){
		printf("SendADDR Error!\r\n");
		/* 产生停止信号 */
		SOFT_IIC_Stop();
		/* 返回0 */
		return DISABLE;

	}
	/* 发送EEPROM低地址 */
	SOFT_IIC_SendData(addr);
	/* 再次产生起始信号 */
	SOFT_IIC_Start();
	/* 发送EEPROM读地址 */
	SOFT_IIC_SendData(EEPROM_ADDR|EEPROM_RD);
	/* 等待EEPROM应答信号 */
	if(!SOFT_IIC_GetAck()){
		printf("ReadData Error!\r\n");
		/* 产生停止信号 */
		SOFT_IIC_Stop();
		/* 返回0 */
		return DISABLE;

	}
	/* 接收读取数据 */
	data=SOFT_IIC_ReadData(1);
	/* 产生停止信号 */
	SOFT_IIC_Stop();
	/* 返回读取数据 */
	return data;
}