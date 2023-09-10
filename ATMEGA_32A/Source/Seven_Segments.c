#include "../Include/Segments.h"

void Seg_Init()
{
    DIO_voidSetPinDirection(Seg_PortA, Seg_Pin, OutputPinDirection);
    DIO_voidSetPinDirection(Seg_PortB, Seg_Pin, OutputPinDirection);
    DIO_voidSetPinDirection(Seg_PortC, Seg_Pin, OutputPinDirection);
    DIO_voidSetPinDirection(Seg_PortD, Seg_Pin, OutputPinDirection);
    DIO_voidSetPinDirection(ENB1, Seg_Pin, OutputPinDirection);
    DIO_voidSetPinDirection(ENB2, Seg_Pin, OutputPinDirection);
}

void Seg_Display(uint8 number, uint8 Seg_Number)
{
    switch (number)
    {
        case 0: DIO_voidSetPinValue(Seg_PortA, uint8 Seg_Pin, Low); DIO_voidSetPinValue(Seg_PortB, uint8 Seg_Pin, Low); DIO_voidSetPinValue(Seg_PortC, uint8 Seg_Pin, Low); DIO_voidSetPinValue(Seg_PortD, uint8 Seg_Pin, Low); break;
        case 1: DIO_voidSetPinValue(Seg_PortA, uint8 Seg_Pin, Low); DIO_voidSetPinValue(Seg_PortB, uint8 Seg_Pin, Low); DIO_voidSetPinValue(Seg_PortC, uint8 Seg_Pin, Low); DIO_voidSetPinValue(Seg_PortD, uint8 Seg_Pin, Low); break;
        case 2: DIO_voidSetPinValue(Seg_PortA, uint8 Seg_Pin, Low); DIO_voidSetPinValue(Seg_PortB, uint8 Seg_Pin, Low); DIO_voidSetPinValue(Seg_PortC, uint8 Seg_Pin, Low); DIO_voidSetPinValue(Seg_PortD, uint8 Seg_Pin, Low); break;
        case 3: DIO_voidSetPinValue(Seg_PortA, uint8 Seg_Pin, Low); DIO_voidSetPinValue(Seg_PortB, uint8 Seg_Pin, Low); DIO_voidSetPinValue(Seg_PortC, uint8 Seg_Pin, Low); DIO_voidSetPinValue(Seg_PortD, uint8 Seg_Pin, Low); break;
        case 4: DIO_voidSetPinValue(Seg_PortA, uint8 Seg_Pin, Low); DIO_voidSetPinValue(Seg_PortB, uint8 Seg_Pin, Low); DIO_voidSetPinValue(Seg_PortC, uint8 Seg_Pin, Low); DIO_voidSetPinValue(Seg_PortD, uint8 Seg_Pin, Low); break;
        case 5: DIO_voidSetPinValue(Seg_PortA, uint8 Seg_Pin, Low); DIO_voidSetPinValue(Seg_PortB, uint8 Seg_Pin, Low); DIO_voidSetPinValue(Seg_PortC, uint8 Seg_Pin, Low); DIO_voidSetPinValue(Seg_PortD, uint8 Seg_Pin, Low); break;
        case 6: DIO_voidSetPinValue(Seg_PortA, uint8 Seg_Pin, Low); DIO_voidSetPinValue(Seg_PortB, uint8 Seg_Pin, Low); DIO_voidSetPinValue(Seg_PortC, uint8 Seg_Pin, Low); DIO_voidSetPinValue(Seg_PortD, uint8 Seg_Pin, Low); break;
        case 7: DIO_voidSetPinValue(Seg_PortA, uint8 Seg_Pin, Low); DIO_voidSetPinValue(Seg_PortB, uint8 Seg_Pin, Low); DIO_voidSetPinValue(Seg_PortC, uint8 Seg_Pin, Low); DIO_voidSetPinValue(Seg_PortD, uint8 Seg_Pin, Low); break;
        case 8: DIO_voidSetPinValue(Seg_PortA, uint8 Seg_Pin, Low); DIO_voidSetPinValue(Seg_PortB, uint8 Seg_Pin, Low); DIO_voidSetPinValue(Seg_PortC, uint8 Seg_Pin, Low); DIO_voidSetPinValue(Seg_PortD, uint8 Seg_Pin, Low); break;
        case 9: DIO_voidSetPinValue(Seg_PortA, uint8 Seg_Pin, Low); DIO_voidSetPinValue(Seg_PortB, uint8 Seg_Pin, Low); DIO_voidSetPinValue(Seg_PortC, uint8 Seg_Pin, Low); DIO_voidSetPinValue(Seg_PortD, uint8 Seg_Pin, Low); break;
    }
    switch (number)
    {
    DIO_voidSetPinValue(uint8 Seg_Port, uint8 Seg_Pin, (number >> 0) & 0x01);
    DIO_voidSetPinValue(uint8 Seg_Port, uint8 Seg_Pin, (number >> 1) & 0x01);
    DIO_voidSetPinValue(uint8 Seg_Port, uint8 Seg_Pin, (number >> 2) & 0x01);
    DIO_voidSetPinValue(uint8 Seg_Port, uint8 Seg_Pin, (number >> 3) & 0x01);
    }
}

void DIO_SetSegNumber(uint8 Seg_EN)
{
    if (Seg_EN == 1)
    {
        DIO_voidSetPinDirection(PortB, Pin2, Output);
        DIO_voidSetPinValue(PortB, Pin2, High);
    }
    else if (Seg_EN == 2)
    {
        DIO_voidSetPinDirection(PortB, Pin1, Output);
        DIO_voidSetPinValue(PortB, Pin1, High);
    }
}