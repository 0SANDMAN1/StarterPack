/*
 * Toggle LED.c
 *
 * Created: 07-Sep-23 5:48:33 PM
 * Author : Eslam Ehab
 */ 

#include "STD.h"
#include "bit_math.h"
#include "DIO.h"
#include <util/delay.h>


int main(void)
{
    /* Replace with your application code */
	DIO_voidSetPinDirection(PortA, Pin0, Output); //LED0
	DIO_voidSetPinDirection(PortA, Pin7, Input); //PUSH0
	DIO_voidSetPinValue(PortA, Pin7, High);
	/*
	DIO_voidSetPinDirection(PortC, Pin2, Output); //LED0
	DIO_voidSetPinDirection(PortC, Pin7, Output); //LED1
	DIO_voidSetPinDirection(PortD, Pin3, Output); //LED2
	DIO_voidSetPinDirection(PortB, Pin0, Input); //PUSH0
	DIO_voidSetPinDirection(PortD, Pin6, Input); //PUSH1
	DIO_voidSetPinDirection(PortD, Pin2, Input); //PUSH2
	DIO_voidSetPinValue(PortB, Pin0, High); //PUSH1
	DIO_voidSetPinValue(PortD, Pin6, High); //PUSH2
	DIO_voidSetPinValue(PortD, Pin2, High); //PUSH3
	*/
	
    while (1) 
    {
		if (DIO_uint8GetPinValue(PortA, Pin7) == Low)
		{
			_delay_ms(100);
			Toggle(PortA_Reg, Pin0);
		}
		/*
		if (DIO_uint8GetPinValue(PortB, Pin0) == Low)
		{
				_delay_ms(500);
				Toggle(PortC_Reg, Pin2);
				//DIO_voidSetPinValue(PortC, Pin7, High);
		}
		else if (DIO_uint8GetPinValue(PortD, Pin6) == Low)
		{
			_delay_ms(500);
			Toggle(PortC_Reg, Pin7);
			//DIO_voidSetPinValue(PortC, Pin6, High);
		}
		else if (DIO_uint8GetPinValue(PortD, Pin2) == Low)
		{
			_delay_ms(500);
			Toggle(PortD_Reg, Pin3);
			//DIO_voidSetPinValue(PortC, Pin5, High);
		}
		*/
    }
}

