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
#include "Bluetooth.h"
#include "SPI.h"
#include "EEPROM.h"


int main(void)
{
	//DIO_Init();
	DIO_ConfigChannel(DIO_ChannelC7,Output);
	//LCD_Init();
	
	TWI_Init(0b00001111);

	u8 rxData = 0;
	u8 txData = 0;
	while (1)
	{
		txData = (u8)rand();
		EEPROM_WriteByte(0b10100000,0b00000011,txData);
		_delay_ms(200);
		rxData = EEPROM_ReadByte(0b10100000,0b00000011);
		if (rxData == txData)
		{
			DIO_ToggleChannel(DIO_ChannelC7);
		}
		_delay_ms(200);
	}
}
