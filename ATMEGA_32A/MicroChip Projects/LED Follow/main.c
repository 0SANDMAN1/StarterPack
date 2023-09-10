/*
 * LED.c
 *
 * Created: 06-Sep-23 6:09:47 PM
 * Author : Eslam Ehab
 */ 

#include "STD.h"
#include "bit_math.h"
#include "DIO.h"
#include <util/delay.h>


int main(void)
{
    /* Replace with your application code */
	DIO_voidSetPinDirection(PortC, Pin0, Output);
	DIO_voidSetPinDirection(PortC, Pin1, Output);
	DIO_voidSetPinDirection(PortC, Pin2, Output);
	DIO_voidSetPinDirection(PortC, Pin3, Output);
	DIO_voidSetPinDirection(PortA, Pin0, Output);
	DIO_voidSetPinDirection(PortA, Pin1, Output);
	DIO_voidSetPinDirection(PortA, Pin2, Output);
	DIO_voidSetPinDirection(PortA, Pin3, Output);
    while (1) 
    {
		uint8 i; //PortC
		//uint8 j; //PortA
		uint8 x = 8;
		for (i = Pin0; i < x; i++)
		{
			DIO_voidSetPinValue(PortC, i, High);
			_delay_ms(1000);
			DIO_voidSetPinValue(PortA, i, High);
			_delay_ms(1000);
			DIO_voidSetPinValue(PortC, i, Low);
			_delay_ms(1000);
			DIO_voidSetPinValue(PortC, i+1, High);
			_delay_ms(1000);
			DIO_voidSetPinValue(PortA, i, Low);
		}
		
	}
}

