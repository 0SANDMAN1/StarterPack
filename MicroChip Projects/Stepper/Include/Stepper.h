#include "DIO.h"
#include "delay.h"
#ifndef STEPPER_H
#define STEPPER_H

uint8 IN1;
uint8 IN2;
uint8 IN3;
uint8 IN4;

uint8 Port_IN1;
uint8 Port_IN2;
uint8 Port_IN3;
uint8 Port_IN4;

void Stepper_Init(uint8 Port_A, uint8 Pin_A, uint8 Port_B, uint8 Pin_B, uint8 Port_C, uint8 Pin_C, uint8 Port_D, uint8 Pin_D)
void Stepper_A();
void Stepper_B();
void Stepper_C();
void Stepper_D();
void Stepper_Rotate_CW(uint16 Angle);
void Stepper_Rotate_CCW(uint16 Angle);

#endif