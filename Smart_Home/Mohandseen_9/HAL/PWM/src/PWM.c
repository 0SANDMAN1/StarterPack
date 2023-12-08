/*
* PWM.c
*
* Created: 10/14/2023 3:34:32 PM
*  Author: user
*/
#include "PWM.h"

void PWM_Generate_COM1A(u8 Duty){
	DIO_ConfigChannel(DIO_ChannelD5,Output);
	u16 ICR1Value = 0xFFFF;
	Timer1_SetValue(ICR1DataReg,ICR1Value);
	u16 OCR1AValue = (u16)((((float)Duty/100)*((u32)ICR1Value+1))-1);
	Timer1_SetValue(OCR1ADataReg,OCR1AValue);
	Timer1_InitTypes options = {PWM_Fast,Clock_8,COM1A_Non_Inverting_PWM,COM1B_No_PWM,TOVInt_Disable,OC1AInt_Disable,OC1BInt_Disable,ICInt_Disable};
	Timer1_Init(&options);
}