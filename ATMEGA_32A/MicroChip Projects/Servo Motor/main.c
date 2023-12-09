/*
* Servo Motor.c
*
* Created: 09-Dec-23 10:04:37 PM
* Author : Eslam Ehab
*/

#include <util/delay.h>
#include "DIO.h"
#include "ServoMotor.h"


int main(void)
{
	DIO_Init();
	/* Replace with your application code */
	while (1)
	{
		ServoMotor(0);
		_delay_ms(500);
		ServoMotor(45);
		_delay_ms(500);
		ServoMotor(90);
		_delay_ms(500);
		ServoMotor(135);
		_delay_ms(500);
		ServoMotor(180);
		_delay_ms(1000);
	}
}

