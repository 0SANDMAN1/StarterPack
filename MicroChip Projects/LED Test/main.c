/*
* LED Test.c
*
* Created: 09-Oct-23 10:02:27 PM
* Author : Eslam Ehab
*/

#include "DIO.h"
#include "Clock.h"
#include "LED.h"


int main(void)
{
	/* Replace with your application code */
	DIO_Init();
	LED_Init();
	//Buzzer_Init();
	while (1)
	{
		LED0_ON();
		_delay_ms(1000);
		LED1_ON();
		_delay_ms(1000);
		LED2_ON();
		_delay_ms(1000);
		LED0_OFF();
		_delay_ms(1000);
		LED1_OFF();
		_delay_ms(1000);
		LED2_OFF();
		_delay_ms(1000);
	}
}

