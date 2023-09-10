#ifndef LED_H
#define LED_H

#include "STD.h"
#include "DIO.h"

#define LED0 Pin0
#define LED1 Pin1
#define LED2 Pin2
#define LED3 Pin3
#define LED4 Pin4
#define LED5 Pin5
#define LED6 Pin6
#define LED7 Pin7

#define LED_PortA PortA
#define LED_PortB PortB
#define LED_PortC PortC
#define LED_PortD PortD

void LED_Init( uint8 LED_Port, uint8 LED_Pin);
void LED_On( uint8 LED_Port, uint8 LED_Pin);
void LED_Off( uint8 LED_Port, uint8 LED_Pin);


#endif