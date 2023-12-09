/*
 * LED LINE.c
 *
 * Created: 06-Sep-23 12:33:57 AM
 * Author : Eslam Ehab
 */

#include "DIO.h"
#include "DIO.c"
#include <delay.h>


int main(void)
{
    /* Replace with your application code */
	void DIO_voidSetPinDirection(PortC, Pin0, Output);
	void DIO_voidSetPinDirection(PortC, Pin7, Output);
    while (1)
    {
		void DIO_voidSetPinValue(PORTC, Pin0, High);
		_delay_ms(1000);
		void DIO_voidSetPinValue(PORTC, Pin7, High);
    }
}

