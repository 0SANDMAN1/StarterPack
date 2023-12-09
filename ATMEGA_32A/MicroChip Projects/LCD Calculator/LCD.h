/*
 * LCD.h
 *
 * Created: 9/29/2023 2:24:12 PM
 *  Author: user
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "Clock.h"
#include "DIO.h"

#define LCD_RS DIO_ChannelB1
#define LCD_RW DIO_ChannelB2
#define LCD_E DIO_ChannelB3

#define LCD_DataPort DIO_PortA

void LCD_Init();
void LCD_Cmd(u8 cmd);
void LCD_Char(u8 data);
void LCD_String(s8 * string);
void LCD_Clear();
void LCD_SetPos(u8 line,u8 pos);
void LCD_CustomChar(u8 loc,s8 * msg);

#endif /* LCD_H_ */