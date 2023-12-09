/*
 * LM35.h
 *
 * Created: 10/7/2023 4:49:39 PM
 *  Author: user
 */ 


#ifndef LM35_H_
#define LM35_H_

#include "ADC.h"

void LM35_Init(ADC_InitTypes * options);
u16 LM35_Read(ADC_ChannelTypes channelId);

#endif /* LM35_H_ */