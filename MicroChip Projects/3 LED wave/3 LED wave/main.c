/*
 * 3 LED wave.c
 *
 * Created: 9/22/2023 3:18:49 PM
 * Author : Eslam Ehab
 */ 

#include "Include/DIO.h"
#include "Include/delay.h"


int main(void)
{
    /* Replace with your application code */
	DIO_voidSetPinDirection(PortD, Pin3, Output); //LED 2
	DIO_voidSetPinDirection(PortC, Pin7, Output); //LED 1
	DIO_voidSetPinDirection(PortC, Pin2, Output); //LED 0
    while (1) 
    {
		DIO_voidSetPinValue(PortC, Pin2, Low);
		DIO_voidSetPinValue(PortD, Pin3, High);
		_delay_ms(1000);
		DIO_voidSetPinValue(PortD, Pin3, Low);
		DIO_voidSetPinValue(PortC, Pin7, High);
		_delay_ms(1000);
		DIO_voidSetPinValue(PortC, Pin7, Low);
		DIO_voidSetPinValue(PortC, Pin2, High);
		_delay_ms(1000);
    }
}

