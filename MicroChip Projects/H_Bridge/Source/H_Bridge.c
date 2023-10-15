#include "../Include/H_Bridge.h"
#include "../Include/DIO.h"

void H_Bridge_Init()
{
    DIO_voidSetPinDirection(H_PortC, H_A1, Output);
    DIO_voidSetPinDirection(H_PortC, H_A2, Output);
    DIO_voidSetPinDirection(H_PortC, H_A3, Output);
    DIO_voidSetPinDirection(H_PortC, H_A4, Output);
    DIO_voidSetPinDirection(H_PortD, H_ENA, Output);
    DIO_voidSetPinDirection(H_PortD, H_ENB, Output);
}

void H_Bridge_SetPinValue(uint8 H_EN, uint8 Value)
{
    if (Value == High)
    {
        DIO_voidSetPinValue(H_PortD, H_EN, High);
    }
    else
    {
        DIO_voidSetPinValue(H_PortD, H_EN, Low);
    }
}

void H_Bridge_SetENA(uint8 Direction)
{
    DIO_voidSetPinValue(H_PortD, H_ENA, High);
    switch (Direction)
    {
        case (1): DIO_voidSetPinValue(H_PortC, H_A1, High); DIO_voidSetPinValue(H_PortC, H_A2, Low); break;
        case (2): DIO_voidSetPinValue(H_PortC, H_A2, High); DIO_voidSetPinValue(H_PortC, H_A1, Low); break;
    }
    
}

void H_Bridge_SetENB(uint8 Direction)
{
    DIO_voidSetPinValue(H_PortD, H_ENB, High);
    switch (Direction)
    {
        case (1): DIO_voidSetPinValue(H_PortC, H_A1, High); DIO_voidSetPinValue(H_PortC, H_A2, Low); break;
        case (2): DIO_voidSetPinValue(H_PortC, H_A2, High); DIO_voidSetPinValue(H_PortC, H_A1, Low); break;
    }
    
}