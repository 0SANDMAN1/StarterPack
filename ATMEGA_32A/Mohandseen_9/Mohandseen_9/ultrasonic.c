/*
* Mohandseen_9.c
*
* Created: 9/22/2023 2:05:01 PM
* Author : user
*/

#include <avr/io.h>
#include <stdlib.h>
#include "Clock.h"
#include "BitMath.h"
#include "DIO.h"
#include "LCD.h"
#include "Keypad.h"
#include "SSD.h"
#include "GINT.h"
#include "Ext_Int.h"
#include "ADC.h"
#include "LM35.h"
#include "PWM.h"
#include "ServoMotor.h"
#include "Ultrasonic.h"


int main(void)
{
	DIO_Init();
	LCD_Init();
	double distance = 0;
	s8 distanceString[20];
	while (1)
	{
		distance = Ultrasonic_Read();
		dtostrf(distance,2,2,distanceString);
		LCD_String(distanceString);
		_delay_ms(100);
		LCD_Clear();
	}
}
