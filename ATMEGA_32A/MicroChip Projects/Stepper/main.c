/*
 * Stepper.c
 *
 * Created: 16-Sep-23 7:37:34 PM
 * Author : Eslam Ehab
 */ 

#include "Include/DIO.h"
#include "Include/Stepper.h"


int main(void)
{
	Stepper_Init(PortC, Pin0, PortC, Pin1, PortC, Pin2, PortC, Pin3);
    while (1)
    {
		Stepper_Rotate_CW(360);
		_delay_ms(10000);
		Stepper_Rotate_CCW(360);
    }
}

