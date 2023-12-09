/*
 * Dimmer.h
 *
 * Created: 06-Dec-23 3:49:28 PM
 *  Author: Eslam Ehab
 */ 


#ifndef DIMMER_H_
#define DIMMER_H_
#include <avr/io.h>
#include <util/delay.h>

void InitPWM();
void SetPWMOutPut (u8 duty);



#endif /* DIMMER_H_ */