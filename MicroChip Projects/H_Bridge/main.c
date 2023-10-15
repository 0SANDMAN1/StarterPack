/*
 * H_Bridge.c
 *
 * Created: 11-Sep-23 7:34:55 PM
 * Author : Eslam Ehab
 */ 

#include "Include/H_Bridge.h"
#include <util/delay.h>


int main(void)
{
    /* Replace with your application code */
	H_Bridge_Init();
    while (1) 
    {
		H_Bridge_SetPinValue(H_ENA, High);
		H_Bridge_SetENA(Farward);
		_delay_ms(10000);
		H_Bridge_SetENA(Backward);
		_delay_ms(10000);
    }
}

