/*
* Buzzer.c
*
* Created: 08-Oct-23 10:23:10 PM
*  Author: Eslam Ehab
*/
#include "Buzzer.h"

void Buzzer_Init()
{
	DIO_ConfigChannel(DIO_ChannelA3, Output);
}

void Buzzer_ON()
{
	DIO_WriteChannel(DIO_ChannelA3, STD_High);
}

void Buzzer_OFF()
{
	DIO_WriteChannel(DIO_ChannelA3, STD_Low);
}