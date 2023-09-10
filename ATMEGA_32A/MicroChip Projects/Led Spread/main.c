/*
 * Led Spread.c
 *
 * Created: 06-Sep-23 5:05:09 PM
 * Author : Eslam Ehab
 */ 

#include "STD.h"
#include "bit_math.h"
#include "DIO.h"
#include <util/delay.h>


int main(void)
{
    /* Replace with your application code */
	DIO_voidSetPinDirection(PortA, Pin0, Output);
	DIO_voidSetPinDirection(PortA, Pin1, Output);
	DIO_voidSetPinDirection(PortA, Pin2, Output);
	DIO_voidSetPinDirection(PortA, Pin3, Output);
	DIO_voidSetPinDirection(PortC, Pin0, Output);
	DIO_voidSetPinDirection(PortC, Pin1, Output);
	DIO_voidSetPinDirection(PortC, Pin2, Output);
	DIO_voidSetPinDirection(PortC, Pin3, Output);
    while (1) 
    {
		uint8 i;
		for(i = Pin3; i >= Pin0; i--)
		{
			DIO_voidSetPinValue(PortC, i, High);
			DIO_voidSetPinValue(PortA, i, High);
			_delay_ms(1000);
			DIO_voidSetPinValue(PortC, i, Low);
			DIO_voidSetPinValue(PortA, i, Low);
		}			
    }
}

