/*
* main.c
*
* Created: 26-Oct-23 10:20:50 PM
*  Author: Eslam Ehab
*/
#include "Clock.h"
#include "DIO.h"
#include <stdlib.h>
#include "LCD.h"
#include "ADC.h"
#include "LM35.h"

int main(void)
{
	DIO_Init();
	LCD_Init();
	DIO_ConfigChannel(DIO_ChannelA1,Input);
	
	ADC_Init(ADC_InitTypes= {ADC_Vref_Internal, ADC_Prescaler128});
	LM35_Init(ADC_InitTypes);
	
	u16 adcValue =0;
	s8 adcString[10];

	
	
	while(1)
	{
		adcValue = LM35_Read(ADC_Channel1);
		itoa(adcValue,adcString,10);  //convert from string to ascii
		LCD_String(adcString);
		_delay_ms(500);
	}
}