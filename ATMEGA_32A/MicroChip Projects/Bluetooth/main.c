/*
* Bluetooth.c
*
* Created: 06-Dec-23 12:10:07 AM
* Author : Eslam Ehab
*/
#include "Clock.h"
#include "BitMath.h"
#include "DIO.h"
#include "Bluetooth.h"



int main(void)
{
	DIO_ConfigChannel(DIO_ChannelB3,Output);
	UART_ConfigTypes options = {BaudRate_9600,DoupleSpeed_Disable,CharacterSize_8,Stop_1Bit,Parity_Disable,TX_Enable,RX_Enable};
	Bluetooth_Init(&options);
	Bluetooth_TransmaitString("Test");
	u8 rxdata = 0;
	/* Replace with your application code */
	while (1)
	{
		rxdata = Bluetooth_Receive();
		if(rxdata == '1')
		{
			DIO_ToggleChannel(DIO_ChannelB3);
		}
	}
}

