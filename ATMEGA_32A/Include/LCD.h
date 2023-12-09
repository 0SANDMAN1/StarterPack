#ifndef LCD_H
#define LCD_H

#include "DIO.h"

#define LCD_RS Pin1
#define LCD_RW Pin2
#define LCD_E Pin3

#define LCD_D4 Pin4
#define LCD_D5 Pin5
#define LCD_D6 Pin6
#define LCD_D7 Pin7

#define LCD_DATAPORT PortA

#define LCD_ON 1
#define LCD_OFF 0

void LCD_Init(void);
void LCD_CMD(uint8 cmd);
void LCD_Char(uint8 data);
void LCD_String(Int8 * string);
void LCD_Clear();
void LCD_Setpos(uint8 line, uint8 pos);
void LCD_CustomeChar(uint8 Loc, Int8 * txt);

#endif