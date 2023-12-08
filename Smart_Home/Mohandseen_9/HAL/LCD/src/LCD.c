/*
* LCD.c
*
* Created: 9/29/2023 2:24:23 PM
*  Author: user
*/
#include "LCD.h"

void LCD_Init(){
	DIO_WriteChannel(LCD_RW,STD_Low);
	DIO_WriteChannel(LCD_E,STD_High);
	_delay_ms(20);
	LCD_Cmd(0x33);
	LCD_Cmd(0x32);
	LCD_Cmd(0x28);//function Set 4Bit & 2Line & 5*8
	LCD_Cmd(0x06);//Entry Mode shift to right
	LCD_Cmd(0x0F);//Display ON & Cursor & Blinking
	_delay_ms(2);
}
void LCD_Cmd(u8 cmd){
	u8 portValue = STD_Low;
	DIO_WriteChannel(LCD_RS,STD_Low);
	portValue = DIO_ReadPort(LCD_DataPort);
	portValue = (portValue & 0x0F) | (cmd & 0xF0);
	DIO_WritePort(LCD_DataPort,portValue);
	DIO_WriteChannel(LCD_E,STD_Low);
	_delay_us(100);
	DIO_WriteChannel(LCD_E,STD_High);
	
	_delay_ms(5);
	
	portValue = DIO_ReadPort(LCD_DataPort);
	portValue = (portValue & 0x0F) | (cmd<<4);
	DIO_WritePort(LCD_DataPort,portValue);
	DIO_WriteChannel(LCD_E,STD_Low);
	_delay_us(100);
	DIO_WriteChannel(LCD_E,STD_High);
	_delay_ms(2);
}
void LCD_Char(u8 data){
	u8 portValue = STD_Low;
	DIO_WriteChannel(LCD_RS,STD_High);
	portValue = DIO_ReadPort(LCD_DataPort);
	portValue = (portValue & 0x0F) | (data & 0xF0);
	DIO_WritePort(LCD_DataPort,portValue);
	DIO_WriteChannel(LCD_E,STD_Low);
	_delay_us(100);
	DIO_WriteChannel(LCD_E,STD_High);
	
	_delay_ms(5);
	
	portValue = DIO_ReadPort(LCD_DataPort);
	portValue = (portValue & 0x0F) | (data<<4);
	DIO_WritePort(LCD_DataPort,portValue);
	DIO_WriteChannel(LCD_E,STD_Low);
	_delay_us(100);
	DIO_WriteChannel(LCD_E,STD_High);
	_delay_ms(2);
}
void LCD_String(s8 * string){
	u8 i = 0;
	while(string[i] != '\0'){
		LCD_Char(string[i]);
		i++;
	}
}
void LCD_Clear(){
	LCD_Cmd(0x01);
}
void LCD_SetPos(u8 line,u8 pos){
	switch(line){
		case 1:
		LCD_Cmd(0x80 | (pos & 0x0F));
		break;
		case 2:
		LCD_Cmd(0xC0 | (pos & 0x0F));
		break;
	}
}
void LCD_CustomChar(u8 loc,s8 * msg){
	if (loc<8)
	{
		LCD_Cmd(0x40 + (loc*8));
		for (u8 i=0;i<8;i++)
		{
			LCD_Char(msg[i]);
		}
	}
}

void LCD_movecursor(u8 row,u8 coloumn)
{
	u8 data ; // the command which will set the position of the cursor
	/* in case of wrong input set the cursor to the first position of the LCD*/
	if(row>2||row<1||coloumn>16||coloumn<1)
	{
		data=0x80;
	}
	/********************************************/
	/*set the postion of cursor depend on the selected row and coloumn*/
	if(row==1)
	{
		data=0x80+coloumn-1 ;
	}
	else if (row==2)
	{
		data=0xc0+coloumn-1;
	}
	/**************************************/
	
	LCD_Cmd(data); //set the position  of the cursor
}