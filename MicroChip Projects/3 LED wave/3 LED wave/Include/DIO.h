#include "STD.h"
#ifndef DIO_H
#define DIO_H
#define F_CPU 16000000UL

/*PinNumbers*/
#define Pin0 0
#define Pin1 1
#define Pin2 2
#define Pin3 3
#define Pin4 4
#define Pin5 5
#define Pin6 6
#define Pin7 7


/*Port*/
#define PortA 0
#define PortB 1
#define PortC 2
#define PortD 3

/*GroupD*/
#define PinD_Reg *((volatile uint8*) 0x30)
#define DDRD_Reg *((volatile uint8*) 0x31)
#define PortD_Reg *((volatile uint8*) 0x32)

/*GroupC*/
#define PinC_Reg *((volatile uint8*) 0x13)
#define DDRC_Reg *((volatile uint8*) 0x34)
#define PortC_Reg *((volatile uint8*) 0x35)

/*GroupB*/
#define PinB_Reg *((volatile uint8*) 0x36)
#define DDRB_Reg *((volatile uint8*) 0x37)
#define PortB_Reg *((volatile uint8*) 0x38)

/*GroupA*/
#define PinA_Reg *((volatile uint8*) 0x39)
#define DDRA_Reg *((volatile uint8*) 0x3A)
#define PortA_Reg *((volatile uint8*) 0x3B)

#define Output  1
#define Input  0

#define High 1
#define Low 0

void DIO_voidSetPinDirection(uint8 Port, uint8 Pin, uint8 Direction);
void DIO_voidSetPinValue(uint8 Port, uint8 Pin, uint8 Value);
uint8 DIO_uint8GetPinValue(uint8 Port, uint8 Pin);

#endif