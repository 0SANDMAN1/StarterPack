/*
 * ServoMotor.c
 *
 * Created: 10/14/2023 5:06:48 PM
 *  Author: user
 */ 
#include "ServoMotor.h"
#include "Clock.h"

void ServoMotor(float angle){
	
	DIO_ConfigChannel(DIO_ChannelD5,Output);
	float OCR1AValue = (float)((angle-miniAngle) * ((float)(maxCount-miniCount)/(maxAngle-miniAngle)))+miniCount-1;
	float ICR1Value = 4999;
	Timer1_SetValue(ICR1DataReg,ICR1Value);
	Timer1_SetValue(OCR1ADataReg,OCR1AValue);
	
	Timer1_InitTypes options = {PWM_Fast,Clock_1024,COM1A_Non_Inverting_PWM,COM1B_No_PWM,TOVInt_Disable,OC1AInt_Disable,OC1BInt_Disable,ICInt_Disable};
	Timer1_Init(&options);
}
// void initializeServo() {
// 	// Set the appropriate pin as output
// 	DDRD |= (1 << PD5); // Assuming PD5 is used for PWM output (you may need to change this)
// 
// 	// Configure Timer1 for Fast PWM mode
// 	TCCR1A |= (1 << COM1A1) | (1 << WGM11) | (1 << WGM10);
// 	TCCR1B |= (1 << WGM13) | (1 << WGM12);
// 
// 	// Set prescaler to 8 for a good range of angles
// 	TCCR1B |= (1 << CS12) | (1 << CS10);
// 	// Set ICR1 for 20ms period (typical for servo motors)
// 	ICR1 = 39999; // Assuming 16MHz clock, adjust if needed
// }
// 
// void setServoAngle(int angle) {
// 	// Convert angle to a value between 0 and 180 to match PWM range
// 	int pulseWidth = 1000 + (angle * 11); // Adjust this scaling if needed
// 
// 	// Set OCR1A with the calculated pulse width
// 	OCR1A = pulseWidth;
// 
// 	// Wait for the servo to reach the desired position
// 	_delay_ms(500); // Adjust delay based on servo speed and mechanics
// }
// void servo_rotate(int angle) {
// 	// Convert angle to the corresponding delay
// 	int delay_time = 1000 + (angle * 10); // Adjust this scaling factor if needed
// 
// 	// Send a pulse to the servo
// 	PORTD |= (1 << DIO_ChannelD5);
// 	for (u16 i = 0; i < delay_time; i++) {
// 		_delay_us(1);
// 	}
// 	PORTD &= ~(1 << DIO_ChannelD5);
// 	_delay_ms((int)(20 - delay_time / 1000));  // Remaining time in 20ms (50 Hz) period
// }