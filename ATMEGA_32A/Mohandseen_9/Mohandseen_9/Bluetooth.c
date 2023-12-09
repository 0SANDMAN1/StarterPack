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


int main(void)
{
	//DIO_Init();
	DIO_ConfigChannel(DIO_ChannelC7,Output);
	//LCD_Init();
	UART_ConfigTypes options = {BaudRate_9600,DoupleSpeed_Disable,CharacterSize_8,Stop_1Bit,Parity_Disable,TX_Enable,RX_Enable};
	Bluetooth_Init(&options);
	Bluetooth_TransmaitString("Test");
	u8 rxdata = 0;
	while (1)
	{
		rxdata = Bluetooth_Receive();
		if(rxdata == '1'){
			DIO_ToggleChannel(DIO_ChannelC7);
		}
	}
}
