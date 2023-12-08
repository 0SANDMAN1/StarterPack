/*
 * LM35.c
 *
 * Created: 10/7/2023 4:50:00 PM
 *  Author: user
 */ 
#include "LM35.h"

void LM35_Init(ADC_InitTypes * options){
	ADC_Init(options);
}
u16 LM35_Read(ADC_ChannelTypes channelId){
	u16 adcValue = 0;
	u16 Temp = 0;
	adcValue = ADC_Read(channelId);
	Temp = (adcValue/4);
	return Temp;
}