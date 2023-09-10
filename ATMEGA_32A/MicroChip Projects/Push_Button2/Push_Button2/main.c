/*
 * Bush_Button_LED.c
 *
 * Created: 07-Sep-23 12:34:24 AM
 * Author : Eslam Ehab
 */ 
#include "DIO.h"
#include <util/delay.h>


int main(void)
{
    /* Replace with your application code */
	DIO_voidSetPinDirection(PortA, Pin0, Output);
	DIO_voidSetPinDirection(PortA, Pin1, Output);
	DIO_voidSetPinDirection(PortA, Pin2, Output);
	DIO_voidSetPinDirection(PortC, Pin0, Input);
	DIO_voidSetPinValue(PortC, Pin0, High);
	uint8 x = 0;
    while (1)
    {
		uint8 pinvalue = DIO_uint8GetPinValue(PortC, Pin0);
		if (pinvalue == High)
		{
			x++;
			_delay_ms(40);
		}
		switch (x)
		{
			case 0: DIO_voidSetPinValue(PortA, Pin0, High); break;
			case 1: DIO_voidSetPinValue(PortA, Pin1, High); break;
			case 2: DIO_voidSetPinValue(PortA, Pin2, High); break;
			case 3: DIO_voidSetPinValue(PortA, Pin0, Low); DIO_voidSetPinValue(PortA, Pin1, Low); DIO_voidSetPinValue(PortA, Pin2, Low); x = 0; break;
		}
    }
}