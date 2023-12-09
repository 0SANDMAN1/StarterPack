#include "../include/TWI.h"

void TWI_Init(u8 address)
{
    TWI->TWAR_Reg = address;
    TWI->TWBR_Reg = address;
}
u8 TWI_Status(void)
u8 TWI_Start(void)
u8 TWI_Send(u8 data)
u8 TWI_Read_Ack(u8 * data)
u8 TWI_Read_NAck(u8 * data)