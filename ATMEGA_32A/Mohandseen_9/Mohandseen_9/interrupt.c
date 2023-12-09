/*
* Mohandseen_9.c
*
* Created: 9/22/2023 2:05:01 PM
* Author : user
*/

//#include <avr/io.h>
#include "Clock.h"
#include "BitMath.h"
#include "DIO.h"
#include "LCD.h"
#include "Keypad.h"
#include "SSD.h"
#include "GINT.h"
#include "Ext_Int.h"

void ExtInt0Fun(void){
	DIO_ToggleChannel(DIO_ChannelC2);
	_delay_ms(500);
}

int main(void)
{
	
	DIO_Init();
	DIO_ConfigChannel(DIO_ChannelD2,Input);
	DIO_ConfigChannel(DIO_ChannelC2,Output);
	DIO_ConfigChannel(DIO_ChannelC7,Output);
	
	Ext_Interrupt_SetCallBack(Ext_INT0,ExtInt0Fun);
	Ext_Interrupt_Sncontrol(Ext_INT0,Falling_Edge);
	Ext_Interrupt_Enable(Ext_INT0);
	EnableAllInterrupts();
	
	while (1)
	{

		DIO_ToggleChannel(DIO_ChannelC7);
		_delay_ms(500);
	}
}


