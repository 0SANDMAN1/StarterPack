#ifndef TWI_TYPES 
#define TWI_TYPES

#include "Clock.h"
#include "TWI_Reg.h"

#define F_TWI 100000UL
#define MyTWPS 1
#define MYTWBR (((F_CPU/F_TWI)-16)/(2*(4^MyTWPS)))

void TWI_Init(u8 address);
u8 TWI_Status(void);
u8 TWI_Start(void);
u8 TWI_Send(u8 data);
u8 TWI_Read_Ack(u8 * data);
u8 TWI_Read_NAck(u8 * data);

#endif