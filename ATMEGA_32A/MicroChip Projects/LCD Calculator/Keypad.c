/*
* Keypad.c
*
* Created: 9/30/2023 2:03:55 PM
*  Author: user
*/
#include "Keypad.h"
#include "Keypad_Config.h"

void Keypad_Init(){
	//cols Input
	for (u8 j=0;j<colsCount;j++)
	{
		DIO_ConfigChannel(KeypadCols[j],Input);
		DIO_WriteChannel(KeypadCols[j],STD_High);//connect pullup res.
	}
	//rows Output
	for(u8 i=0;i<rowsCount;i++){
		DIO_ConfigChannel(KeypadRows[i],Output);
		DIO_WriteChannel(KeypadRows[i],STD_High);
	}
}
u8 GetKey(){
	for (u8 i=0;i<rowsCount;i++)
	{
		DIO_WriteChannel(KeypadRows[i],STD_Low);
		for (u8 j=0;j<colsCount;j++)
		{
			if (DIO_ReadChannel(KeypadCols[j]) == STD_Low)
			{
				while(DIO_ReadChannel(KeypadCols[j]) == STD_Low);
				return Keypad[i][j];
			}
		}
		DIO_WriteChannel(KeypadRows[i],STD_High);
	}
	return STD_Low;
}