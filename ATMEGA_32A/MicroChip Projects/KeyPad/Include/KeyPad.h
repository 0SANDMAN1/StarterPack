#include "DIO.h"
#include "delay.h"

#ifndef KEYPAD_H
#define KEYPAD_H

#define Rows 4
#define Columns 4

#define Key_NotPressed 1

#define R0 Pin0
#define R1 Pin1
#define R2 Pin2
#define R3 Pin3

#define C0 Pin4
#define C1 Pin5
#define C2 Pin6
#define C3 Pin7

#define Key_PortA 0
#define Key_PortB 1
#define Key_PortC 2
#define Key_PortD 3

#define Keypad_Keys {{'1', '2', '3', '+'}, {'4', '5', '6', '-'}, {'7', '8', '9', '*'}, {'C', '0', '=', '/'}}

void Keypad_Init_ALL(uint8 Key_Port);
uint8 Keypad_GetKeyPressed(void);
#endif