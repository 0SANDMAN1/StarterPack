#include "STD.h"
#ifndef DIO_H
#define DIO_H

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
#define PinD_Reg *((volatile uint8*) 0x10)
#define DDRD_Reg *((volatile uint8*) 0x11)
#define PortD_Reg *((volatile uint8*) 0x12)

/*GroupC*/
#define PinC_Reg *((volatile uint8*) 0x13)
#define DDRC_Reg *((volatile uint8*) 0x14)
#define PortC_Reg *((volatile uint8*) 0x15)

/*GroupB*/
#define PinB_Reg *((volatile uint8*) 0x16)
#define DDRB_Reg *((volatile uint8*) 0x17)
#define PortB_Reg *((volatile uint8*) 0x18)

/*GroupA*/
#define PinA_Reg *((volatile uint8*) 0x19)
#define DDRA_Reg *((volatile uint8*) 0x1A)
#define PortA_Reg *((volatile uint8*) 0x1B)

#define Output  1
#define Input  0

#define High 1
#define Low 0

void DIO_voidSetPinDirection(uint8 Port, uint8 Pin, uint8 Direction);
void DIO_voidSetPinValue(uint8 Port, uint8 Pin, uint8 Value);
uint8 DIO_uint8GetPinValue(uint8 Port, uint8 Pin);

#endif