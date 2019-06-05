#include "nt35510.h"

void NT35510_WR_CMD(u16 cmd)
{
	NT35510->NT35510_Cmd=cmd;
}

void NT35510_WR_DATA(u16 data)
{
	NT35510->NT35510_Data=data;
}

u16 NT35510_READ_DATA(void)
{
	vu16 data;
	data=NT35510->NT35510_Data;
	return data;
}

void NT35510_WriteCmd(vu16 cmd,vu16 data)
{
	NT35510->NT35510_Cmd=cmd;
	NT35510->NT35510_Data=data;
}

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

void NT35510_OpenWindow(vu16 xstart,vu16 ystart,vu16 width,vu16 height)
{
	vu32 x;
	NT35510_WR_CMD(NT35510_SetX);
	NT35510_WR_DATA(xstart>>8);
	NT35510_WR_CMD(NT35510_SetX+1);
	NT35510_WR_DATA(xstart&0xFF);
	NT35510_WR_CMD(NT35510_SetX+2);
	NT35510_WR_DATA((xstart+width-1)>>8);
	NT35510_WR_CMD(NT35510_SetX+3);
	NT35510_WR_DATA((xstart+width-1)&0xFF);

	NT35510_WR_CMD(NT35510_SetX);
	NT35510_WR_DATA(ystart>>8);
	NT35510_WR_CMD(NT35510_SetX+1);
	NT35510_WR_DATA(ystart&0xFF);
	NT35510_WR_CMD(NT35510_SetX+2);
	NT35510_WR_DATA((ystart+height-1)>>8);
	NT35510_WR_CMD(NT35510_SetX+3);
	NT35510_WR_DATA((ystart+height-1)&0xFF);
	NT35510_WR_CMD(NT35510_WRAM);
	for(x=0;x<width*height;x++){
		NT35510->NT35510_Data=0xFFFF;
	}
}
