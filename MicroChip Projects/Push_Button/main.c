/*
* Push_Button.c
*
* Created: 9/22/2023 3:51:43 PM
* Author : Eslam Ehab
*/

#include "Include/DIO.h"
#include "Include/delay.h"
#include "Include/bit_math.h"


int main(void)
{
	/* Replace with your application code */
	DIO_voidSetPinDirection(PortB, Pin0, Input); //PB0
	DIO_voidSetPinDirection(PortD, Pin6, Input); //PB1
	DIO_voidSetPinDirection(PortD, Pin2, Input); //PB2
	DIO_voidSetPinDirection(PortC, Pin2, Output); //LED 0
	DIO_voidSetPinDirection(PortC, Pin7, Output); //LED 1
	DIO_voidSetPinDirection(PortD, Pin3, Output); //LED 2
	//uint8 x;
	while (1)
	{
		if (DIO_uint8GetPinValue(PortB, Pin0) == 1)
		{
			_delay_ms(100);
			Toggle(PortC_Reg, Pin2);
		} else if (DIO_uint8GetPinValue(PortD, Pin6) == 1)
		{
			_delay_ms(100);
			Toggle(PortC_Reg, Pin7);
		} else if (DIO_uint8GetPinValue(PortD, Pin2) == 1)
		{
			_delay_ms(100);
			Toggle(PortD_Reg, Pin3);
		}
		/*if (DIO_uint8GetPinValue(PortB, Pin0) == 1)
		{
		x = 0;
		}
		else if (DIO_uint8GetPinValue(PortD, Pin6) == 1)
		{
		x = 1;
		}
		else if (DIO_uint8GetPinValue(PortD, Pin2) == 1)
		{
		x = 2;
		}
		
		switch (x)
		{
		case 0: _delay_ms(100); DIO_voidSetPinValue(PortC, Pin2, High); while (DIO_uint8GetPinValue(PortB, Pin0) == 0){ DIO_voidSetPinValue(PortC, Pin2, Low);} break;
		case 1: _delay_ms(100); DIO_voidSetPinValue(PortC, Pin7, High); while (DIO_uint8GetPinValue(PortD, Pin2) == 0){ DIO_voidSetPinValue(PortC, Pin7, Low);} break;
		case 2: _delay_ms(100); DIO_voidSetPinValue(PortD, Pin3, High); while (DIO_uint8GetPinValue(PortD, Pin2) == 0){ DIO_voidSetPinValue(PortD, Pin3, Low);} break;
		}*/
	}
}

