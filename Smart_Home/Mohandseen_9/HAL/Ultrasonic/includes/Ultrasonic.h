/*
 * Ultrasonic.h
 *
 * Created: 10/20/2023 4:29:23 PM
 *  Author: user
 */ 


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "DIO.h"
#include "Timer1.h"
#include "Clock.h"
#include "GINT.h"

#define UltrasonicTriggerPin DIO_ChannelA0
#define UltrasonicEchoPin DIO_ChannelD6

double Ultrasonic_Read();
void Timer1_TOVHandler(void);


#endif /* ULTRASONIC_H_ */