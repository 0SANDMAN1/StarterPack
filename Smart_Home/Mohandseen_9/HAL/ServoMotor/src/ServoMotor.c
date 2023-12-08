/*
 * ServoMotor.c
 *
 * Created: 10/14/2023 5:06:48 PM
 *  Author: user
 */ 
#include "ServoMotor.h"

void ServoMotor(u16 angle){
	
	DIO_ConfigChannel(DIO_ChannelD5,Output);
	u16 OCR1AValue = (u16)((angle-miniAngle) * ((float)(maxCount-miniCount)/(maxAngle-miniAngle)))+miniCount-1;
	u16 ICR1Value = 4999;
	Timer1_SetValue(ICR1DataReg,ICR1Value);
	Timer1_SetValue(OCR1ADataReg,OCR1AValue);
	
	Timer1_InitTypes options = {PWM_Fast,Clock_1024,COM1A_Non_Inverting_PWM,COM1B_No_PWM,TOVInt_Disable,OC1AInt_Disable,OC1BInt_Disable,ICInt_Disable};
	Timer1_Init(&options);
}