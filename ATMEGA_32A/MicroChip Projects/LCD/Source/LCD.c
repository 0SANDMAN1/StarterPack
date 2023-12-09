#include "../Include/LCD.h"

void LCD_Init(void)
{
	DIO_voidSetPinDirection(PortB, LCD_RW, Output);
	DIO_voidSetPinDirection(PortB, LCD_E, Output);
	DIO_voidSetPinDirection(PortB, LCD_RS, Output);
	DIO_voidSetPinValue(PortB, LCD_RW, LCD_OFF);
	DIO_voidSetPinValue(PortB, LCD_E, LCD_ON);
	_delay_ms(20);
	LCD_CMD(0x33);
	LCD_CMD(0x32);
	LCD_CMD(0X28);
	LCD_CMD(0x06);
	LCD_CMD(0x0F);
	_delay_ms(2);
}

void LCD_CMD(uint8 cmd)
{
	uint8 portvalue = 0;
	DIO_voidSetPinDirection(PortB, LCD_RS, Low);
	portvalue = DIO_ReadPort(LCD_DATAPORT);
	portvalue = (portvalue & 0x0F) | (cmd & 0xF0);
	DIO_WritePort(LCD_DATAPORT, portvalue);
	DIO_voidSetPinValue(PortB, LCD_E, Low);
	_delay_us(100);
	DIO_voidSetPinValue(PortB, LCD_E, High);

	_delay_ms(5);

	portvalue = DIO_ReadPort(LCD_DATAPORT);
	portvalue = (portvalue & 0x0F) | (cmd << 4);
	DIO_WritePort(LCD_DATAPORT, portvalue);
	DIO_voidSetPinValue(PortB, LCD_E, Low);
	_delay_us(100);
	DIO_voidSetPinValue(PortB, LCD_E, High);
	_delay_ms(2);
}

void LCD_Char(uint8 data)
{
	uint8 portvalue = 0;
	DIO_voidSetPinDirection(PortB, LCD_RS, High);
	portvalue = DIO_ReadPort(LCD_DATAPORT);
	portvalue = (portvalue & 0x0F) | (data & 0xF0);
	DIO_WritePort(LCD_DATAPORT, portvalue);
	DIO_voidSetPinValue(PortB, LCD_E, Low);
	_delay_us(100);
	DIO_voidSetPinValue(PortB, LCD_E, High);

	_delay_ms(5);

	portvalue = DIO_ReadPort(LCD_DATAPORT);
	portvalue = (portvalue & 0x0F) | (data << 4);
	DIO_WritePort(LCD_DATAPORT, portvalue);
	DIO_voidSetPinValue(PortB, LCD_E, Low);
	_delay_us(100);
	DIO_voidSetPinValue(PortB, LCD_E, High);
	_delay_ms(2);
}

void LCD_String(Int8 * string)
{
	uint8 i = 0;
	while(string[i] != '\0')
	{
		LCD_Char(string[i]);
		i++;
	}
}

void LCD_Clear()
{
	LCD_CMD(0x01);
}

void LCD_Setpos(uint8 line, uint8 pos)
{
	switch(line)
	{
		case 1:
		LCD_CMD(0x80 | (pos & 0x0F));
		break;
		case 2:
		LCD_CMD(0xC0 | (pos & 0x0F));
		break;
	}
}

void LCD_CustomeChar(uint8 Loc, Int8 * txt)
{
	if(Loc < 8)
	{
		LCD_CMD(0x40 + (Loc * 8));
		for (uint8 i = 0; i < 8; i++)
		{
			LCD_Char(txt[i]);
		}
	}
}