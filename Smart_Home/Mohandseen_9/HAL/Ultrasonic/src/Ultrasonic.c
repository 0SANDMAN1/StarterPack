/*
* Ultrasonic.c
*
* Created: 10/20/2023 4:29:38 PM
*  Author: user
*/
#include "Ultrasonic.h"

volatile u32 Timer1_OVCount = 0;

double Ultrasonic_Read(){
	DIO_ConfigChannel(UltrasonicTriggerPin,Output);
	DIO_ConfigChannel(UltrasonicEchoPin,Input);
	
	EnableAllInterrupts();
	
	Timer1_InitTypes options = {Normal,Clock_64,COM1A_No_PWM,COM1B_No_PWM,TOVInt_Enable,OC1AInt_Disable,OC1BInt_Disable,ICInt_Disable};
	Timer1_Init(&options);
	
	Timer1->TCCR1B_Reg.Bits.ICES1_Bit = 1;//ICU Rising Edge
	
	DIO_WriteChannel(UltrasonicTriggerPin,STD_High);
	_delay_us(10);
	DIO_WriteChannel(UltrasonicTriggerPin,STD_Low);
	
	while(Timer1->TIFR_Reg.Bits.ICF1_Bit == STD_Low);//waiting for the Rising Edge
	Timer1->TCNT1_Reg = 0;
	Timer1->ICR1_Reg = 0;
	Timer1_OVCount = 0;
	Timer1->TCCR1B_Reg.Bits.ICES1_Bit = 0;//ICU Falling Edge
	Timer1->TIFR_Reg.Bits.ICF1_Bit = 1;
	
	while(Timer1->TIFR_Reg.Bits.ICF1_Bit == STD_Low);//waiting for the Falling Edge
	u32 Timer_Value = (Timer1_OVCount*65535) + (u32)Timer1->ICR1_Reg;
	double distance = (double)0.0686*Timer_Value;
	return distance;
}
void Timer1_TOVHandler(void){
	Timer1_OVCount++;
}