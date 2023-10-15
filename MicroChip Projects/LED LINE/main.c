/*
 * LED LINE.c
 *
 * Created: 06-Sep-23 12:33:57 AM
 * Author : Eslam Ehab
 */ 
#include "Include/STD.h"
#include "Include/bit_math.h"
#include "Include/DIO.h"
#include <util/delay.h>


int main(void)
{
    /* Replace with your application code */
	DIO_voidSetPinDirection(PortC, Pin0, Output);
	DIO_voidSetPinDirection(PortC, Pin7, Output);
	DIO_voidSetPinDirection(PortD, Pin0, Output);
	DIO_voidSetPinDirection(PortD, Pin7, Output);
	DIO_voidSetPinDirection(PortB, Pin0, Output);
	DIO_voidSetPinDirection(PortB, Pin7, Output);
	DIO_voidSetPinDirection(PortA, Pin0, Output);
	DIO_voidSetPinDirection(PortA, Pin7, Output);
    while (1) 
    {
		DIO_voidSetPinValue(PortC, Pin0, High);
		_delay_ms(1000);
		DIO_voidSetPinValue(PortC, Pin7, High);
		_delay_ms(1000);
		DIO_voidSetPinValue(PortD, Pin0, High);
		_delay_ms(1000);
		DIO_voidSetPinValue(PortD, Pin7, High);
		_delay_ms(1000);
		DIO_voidSetPinValue(PortB, Pin7, High);
		_delay_ms(1000);
		DIO_voidSetPinValue(PortB, Pin0, High);
		_delay_ms(1000);
		DIO_voidSetPinValue(PortA, Pin7, High);
		_delay_ms(1000);
		DIO_voidSetPinValue(PortA, Pin0, High);
		_delay_ms(100);
		DIO_voidSetPinValue(PortA, Pin7, Low);
		DIO_voidSetPinValue(PortB, Pin0, Low);
		DIO_voidSetPinValue(PortB, Pin7, Low);
		DIO_voidSetPinValue(PortD, Pin7, Low);
		DIO_voidSetPinValue(PortD, Pin0, Low);
		DIO_voidSetPinValue(PortC, Pin7, Low);
		DIO_voidSetPinValue(PortC, Pin0, Low);
		_delay_ms(900);
		DIO_voidSetPinValue(PortA, Pin7, High);
		_delay_ms(1000);
		DIO_voidSetPinValue(PortB, Pin0, High);
		_delay_ms(1000);
		DIO_voidSetPinValue(PortB, Pin7, High);
		_delay_ms(1000);
		DIO_voidSetPinValue(PortD, Pin7, High);
		_delay_ms(1000);
		DIO_voidSetPinValue(PortD, Pin0, High);
		_delay_ms(1000);
		DIO_voidSetPinValue(PortC, Pin7, High);
		_delay_ms(1000);
		DIO_voidSetPinValue(PortC, Pin0, High);
    }
}

