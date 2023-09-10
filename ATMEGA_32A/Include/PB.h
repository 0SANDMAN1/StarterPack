
#include "DIO.h"
#ifndef PB_H
#define PB_H

#define Pullup 1
#define Pulldown 0

#define Push0 Pin0
#define Push1 Pin1
#define Push2 Pin2
#define Push3 Pin3
#define Push4 Pin4
#define Push5 Pin5
#define Push6 Pin6
#define Push7 Pin7

#define PushA PortA
#define PushB PortB
#define PushC PortC
#define PushD PortD

uint8 PB_Read(uint8 Push_Port, uint8 Push_Pin);
void PB_Init( uint8 Push_Port, uint8 Push_Pin, uint8 Status);


#endif