#include "nt35510.h"
/**
 * @brief 	NT35510写入命令函数
 * @param 	cmd：要写入的命令
 * @retval 	无
*/
void NT35510_WR_CMD(vu16 cmd)
{
	NT35510->NT35510_Cmd=cmd;
}
/**
 * @brief 	NT35510写入数据函数
 * @param 	cmd：要写入的数据
 * @retval 	无
*/
void NT35510_WR_DATA(vu16 data)
{
	NT35510->NT35510_Data=data;
}
/**
 * @brief 	NT35510读取数据令函数
 * @param 	无
 * @retval 	读取的数据
*/
u16 NT35510_READ_DATA(void)
{
	vu16 data;
	data=NT35510->NT35510_Data;
	return data;
}
/**
 * @brief 	NT35510写入命令&数据函数
 * @param 	cmd：要写入的命令
 * @param	data：要写入的数据
 * @retval 	无
*/
void NT35510_WriteCmd(vu16 cmd,vu16 data)
{
	NT35510->NT35510_Cmd=cmd;
	NT35510->NT35510_Data=data;
}
/**
 * @brief 	NT35510清屏函数
 * @param 	color：清屏颜色
 * @retval 	无
*/
void NT35510_Clear(vu16 color)
{
	vu32 count;
	NT35510_WR_CMD(NT35510_SetX);
	NT35510_WR_DATA(0);
	NT35510_WR_CMD(NT35510_SetX+1);
	NT35510_WR_DATA(0);
	NT35510_WR_CMD(NT35510_SetY);
	NT35510_WR_DATA(0);
	NT35510_WR_CMD(NT35510_SetY+1);
	NT35510_WR_DATA(0);
	NT35510_WR_CMD(NT35510_WRAM);
	for(count=0;count<(480*800);count++){
		NT35510->NT35510_Data=color;
	}
}
/**
 * @brief 	NT35510开窗函数
 * @param 	xstart：x起始坐标
 * @param 	ystart：y起始坐标
 * @param 	width：窗口宽度
 * @param 	height：窗口宽度
 * @retval 	无
*/
void NT35510_OpenWindow(vu16 xstart,vu16 ystart,vu16 width,vu16 height)
{
	vu32 x;
	NT35510_WR_CMD(NT35510_SetX);
	NT35510_WR_DATA(xstart>>8);
	NT35510_WR_CMD(NT35510_SetX+1);
	NT35510_WR_DATA(xstart&0xFF);
	NT35510_WR_CMD(NT35510_SetX+2);
	NT35510_WR_DATA((xstart+height-1)>>8);
	NT35510_WR_CMD(NT35510_SetX+3);
	NT35510_WR_DATA((xstart+height-1)&0xFF);

	NT35510_WR_CMD(NT35510_SetX);
	NT35510_WR_DATA(ystart>>8);
	NT35510_WR_CMD(NT35510_SetX+1);
	NT35510_WR_DATA(ystart&0xFF);
	NT35510_WR_CMD(NT35510_SetX+2);
	NT35510_WR_DATA((ystart+width-1)>>8);
	NT35510_WR_CMD(NT35510_SetX+3);
	NT35510_WR_DATA((ystart+width-1)&0xFF);
	NT35510_WR_CMD(NT35510_WRAM);
	for(x=0;x<width*height;x++){
		NT35510->NT35510_Data=0xFFFF;
	}
}
/**
 * @brief 	NT35510显示ASCII函数
 * @param 	xstart：x起始坐标
 * @param 	ystart：y起始坐标
 * @param 	width：窗口宽度
 * @param 	height：窗口宽度
 * @param 	str：要显示的ASCII
 * @retval 	无
*/
void NT35510_ShowStr(vu16 xstart,vu16 ystart,vu16 width,vu16 height,const unsigned char str)
{
	vu8 i,x,y,z;
	NT35510_WR_CMD(NT35510_SetX);
	NT35510_WR_DATA(xstart>>8);
	NT35510_WR_CMD(NT35510_SetX+1);
	NT35510_WR_DATA(xstart&0xFF);
	NT35510_WR_CMD(NT35510_SetX+2);
	NT35510_WR_DATA((xstart+width-1)>>8);
	NT35510_WR_CMD(NT35510_SetX+3);
	NT35510_WR_DATA((xstart+width-1)&0xFF);

	NT35510_WR_CMD(NT35510_SetY);
	NT35510_WR_DATA(ystart>>8);
	NT35510_WR_CMD(NT35510_SetY+1);
	NT35510_WR_DATA(ystart&0xFF);
	NT35510_WR_CMD(NT35510_SetY+2);
	NT35510_WR_DATA((ystart+height-1)>>8);
	NT35510_WR_CMD(NT35510_SetY+3);
	NT35510_WR_DATA((ystart+height-1)&0xFF);
	NT35510_WR_CMD(NT35510_WRAM);
	for(x=0;x<3;x++){
		for(y=0;y<8;y++){
			for(z=x,i=0;i<12;i++,z+=3){
				if(((*((asc2_2412+(36*(str-32)))+z))&(0x80>>y))){
					NT35510->NT35510_Data=0xFFFF;
				}else{
					NT35510->NT35510_Data=0x0000;
				}
			}
		}
	}
}
/**
 * @brief 	NT35510显示字符串函数ASCII
 * @param	str：要显示的字符串指针
 * @param	size：字符串长度
 * @retval 	无
*/
void NT35510_ShowString(u8* str,vu16 len)
{
	static u16 x=0,y=0;
	vu16 i;
	for(i=0;i<len;i++){
		NT35510_ShowStr(x,y,12,24,*str);
		str++;
		y+=12;
	}
}