/*
* LED.c
*
* Created: 09-Oct-23 7:54:57 PM
*  Author: Eslam Ehab
*/
#include "LED.h"

void LED_Init()
{
	DIO_ConfigChannel(DIO_ChannelD3, Output); //LED 2
	DIO_ConfigChannel(DIO_ChannelC7, Output); //LED 1
	DIO_ConfigChannel(DIO_ChannelC2, Output); //LED 0
}

void LED2_ON()
{
	DIO_WriteChannel(DIO_ChannelD3, STD_High);
}

void LED1_ON()
{
	DIO_WriteChannel(DIO_ChannelC7, STD_High);
}

void LED0_ON()
{
	DIO_WriteChannel(DIO_ChannelC2, STD_High);
}

void LED2_OFF()
{
	DIO_WriteChannel(DIO_ChannelD3, STD_Low);
}

void LED1_OFF()
{
	DIO_WriteChannel(DIO_ChannelC7, STD_Low);
}

void LED0_OFF()
{
	DIO_WriteChannel(DIO_ChannelC2, STD_Low);
}