/*
 * ServoMotor.h
 *
 * Created: 10/14/2023 5:06:36 PM
 *  Author: user
 */ 


#ifndef SERVOMOTOR_H_
#define SERVOMOTOR_H_

#include "Timer1.h"
#include "DIO.h"

#define miniAngle 0
#define maxAngle 180
#define miniCount 250
#define maxCount 500

void ServoMotor(float angle);
//void servo_rotate(int angle);

#endif /* SERVOMOTOR_H_ */