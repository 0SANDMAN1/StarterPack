/*
* ADC.c
*
* Created: 06-Dec-23 3:04:38 PM
* Author : Eslam Ehab
*/
#include "Clock.h"
#include "DIO.h"
#include "Dimmer.h"


int main(void)
{
	u8 BR = 0;
	InitPWM();
	while (1)
	{
		for (BR = 0; BR < 255; BR++)
		{
			SetPWMOutPut(BR);
			_delay_ms(5);
		}
		
		for (BR = 255; BR > 0; BR--)
		{
			SetPWMOutPut(BR);
			_delay_ms(5);
		}
	}
}

