#include "DIO.h"
#ifndef H_BRIDGE_H
#define H_BRIDGE_H

#define H_PortC PortC
#define H_PortD PortD

#define H_A1 Pin3
#define H_A2 Pin4
#define H_A3 Pin5
#define H_A4 Pin6

#define H_ENA Pin4
#define H_ENB Pin5

#define Farward 1
#define Backward 2

void H_Bridge_Init();
void H_Bridge_SetPinValue(uint8 H_EN, uint8 Value);
void H_Bridge_SetENA(uint8 Direction);
void H_Bridge_SetENB(uint8 Direction);

#endif
