/*
 * Dimmer.c
 *
 * Created: 06-Dec-23 3:50:29 PM
 *  Author: Eslam Ehab
 */ 
#include "DIO.h"
#include "Dimmer.h"

void InitPWM()
{
	TCCR0 |= 1 << WGM00 | 1 << WGM01 | 1 << CS00 | 1 << COM01;
	DIO_ConfigChannel(DIO_ChannelB3, Output);
}

void SetPWMOutPut (u8 duty)
{
	OCR0 = duty;
}