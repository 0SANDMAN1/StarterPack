/*
* Timer1.c
*
* Created: 10/14/2023 2:03:25 PM
*  Author: user
*/
#include "Timer1.h"
#include <avr/io.h>
#include <avr/interrupt.h>

void (*TOVIntFunPtr)(void) = 0;
void (*OC1AIntFunPtr)(void) = 0;
void (*OC1BIntFunPtr)(void) = 0;
void (*ICIntFunPtr)(void) = 0;

void Timer1_Init(Timer1_InitTypes * options){
	
	Timer1->TCCR1A_Reg.AllRegister |= (options->Mode & 0b00000011);
	Timer1->TCCR1B_Reg.AllRegister |= (options->Mode>>2)<<3;
	
	Timer1->TCCR1B_Reg.AllRegister |= options->prescaler;
	
	Timer1->TCCR1A_Reg.AllRegister |= options->COM1APWMMode<<6;
	Timer1->TCCR1A_Reg.AllRegister |= options->COM1BPWMMode<<4;
	
	Timer1->TIMSK_Reg |= options->TOVIntStatus<<2;
	Timer1->TIMSK_Reg |= options->OC1BIntStatus<<3;
	Timer1->TIMSK_Reg |= options->OC1AIntStatus<<4;
	Timer1->TIMSK_Reg |= options->ICIntStatus<<5;
	
}
void Timer1_SetCallBack(Timer1_InterruptTypes interruptId,void (*IntCopyFunPtr)(void)){
	switch(interruptId){
		case TOVInt:
		TOVIntFunPtr = IntCopyFunPtr;
		break;
		case OC1AInt:
		OC1AIntFunPtr = IntCopyFunPtr;
		break;
		case OC1BInt:
		OC1BIntFunPtr = IntCopyFunPtr;
		break;
		case ICInt:
		ICIntFunPtr = IntCopyFunPtr;
		break;
	}
}
void Timer1_SetValue(Timer1_DataRegTypes dataRegister,u16 dataValue){
	switch(dataRegister){
		case OCR1ADataReg:
		Timer1->OCR1A_Reg = dataValue;
		break;
		case OCR1BDataReg:
		Timer1->OCR1B_Reg = dataValue;
		break;
		case ICR1DataReg:
		Timer1->ICR1_Reg = dataValue;
		break;
	}
}

ISR(TIMER1_OVF_vect){
	TOVIntFunPtr();
}

//ISR(TIMER1_COMPA_vect){
//	OC1AIntFunPtr();
//}

ISR(TIMER1_COMPB_vect){
	OC1BIntFunPtr();
}

ISR(TIMER1_CAPT_vect){
	ICIntFunPtr();
}


void Timer0_Init() {
	// Set the timer mode to CTC (Clear Timer on Compare Match)
	TCCR0 |= (1 << WGM01);

	// Set the value for the compare match (15 seconds at 8 MHz clock)
	OCR0 = 0;  // (10 * 1000000) / (256 * 1) - 1

	// Enable the compare match interrupt
	TIMSK |= (1 << OCIE0);

	// Set the prescaler to 256
	TCCR0 |= (1 << CS02);
}