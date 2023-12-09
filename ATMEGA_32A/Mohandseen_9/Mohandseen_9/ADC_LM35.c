/*
* Mohandseen_9.c
*
* Created: 9/22/2023 2:05:01 PM
* Author : user
*/

//#include <avr/io.h>
#include <stdlib.h>
#include "Clock.h"
#include "BitMath.h"
#include "DIO.h"
#include "LCD.h"
#include "Keypad.h"
#include "SSD.h"
#include "GINT.h"
#include "Ext_Int.h"
#include "ADC.h"
#include "LM35.h"

int main(void)
{
	
	DIO_Init();
	LCD_Init();
	
	DIO_ConfigChannel(DIO_ChannelA1,Input);
	
	ADC_InitTypes options = {ADC_Vref_Internal,ADC_Prescaler128};
	LM35_Init(&options);
	
	u16 adcValue = 0;
	s8 adcString[10];
	while (1)
	{
		adcValue = LM35_Read(ADC_Channel1);
		itoa(adcValue,adcString,10);
		LCD_String(adcString);
		_delay_ms(500);
		LCD_Clear();
	}
}


