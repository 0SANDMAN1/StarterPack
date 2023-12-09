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

volatile unsigned long TOV_Count = 0;

int main(void)
{
	DIO_Init();
	//LCD_Init();
	/*
	DIO_ConfigChannel(DIO_ChannelC7,Output);
	
	
	//TIMSK |= (1<<TOIE0)|(1<<OCIE0);
	TCCR0 &=~ (1<<WGM00);
	TCCR0 |= (1<<CS00)|(1<<CS01)|(1<<COM00)|(1<<WGM01);//N=64
	
	EnableAllInterrupts();
	
	//TCNT0 = 111;
	OCR0 = 200;
	*/
	DIO_WriteChannel(DIO_ChannelC5,STD_High);
	DIO_WriteChannel(DIO_ChannelC6,STD_Low);
	//PWM_Generate_COM1A(25);
	
	
	
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
/*
ISR(TIMER0_OVF_vect){
TOV_Count++;
if (TOV_Count == 977)
{
TCNT0 = 111;
DIO_ToggleChannel(DIO_ChannelC7);
TOV_Count = 0;
}
}
*/

/*
ISR(TIMER0_OVF_vect){
TOV_Count++;
}

ISR(TIMER0_COMP_vect){
if (TOV_Count == 976)
{
//TCNT0 = 0;
TOV_Count = 0;
DIO_ToggleChannel(DIO_ChannelC7);
}
}
*/