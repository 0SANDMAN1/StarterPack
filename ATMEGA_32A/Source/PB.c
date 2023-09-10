#include "../Include/PB.h"

void PB_Init( uint8 Push_Port, uint8 Push_Pin, uint8 Status)
{
    DIO_voidSetPinDirection(uint8 Push_Port, uint8 Push_Pin);

    if(Status == Pullup)
    {
        DIO_voidSetPinValue( uint8 Push_Port, uint8 Push_Pin, High);
    }
    else
    {
        DIO_voidSetPinValue( uint8 Push_Port, uint8 Push_Pin, Low);
    }
}

uint8 PB_Read(uint8 Push_Port, uint8 Push_Pin)
{
    return DIO_uint8GetPinValue( uint8 Push_Port, uint8 Push_Pin);
}