/*
 * Buzzer.c
 *
 * Created: 12-Sep-23 5:13:25 PM
 * Author : Eslam Ehab
 */ 

#include "Include/Buzzer.h"
#include <util/delay.h>


int main(void)
{
    /* Replace with your application code */
	Buzzer_Init();
    while (1) 
    {
		Buzzer_SetHigh();
		_delay_ms(10000);
		Buzzer_SetLow();
		_delay_ms(10000);
    }
}

