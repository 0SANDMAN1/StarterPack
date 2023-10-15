#include "../Include/LED.h"

void LED_ON( uint8 Port, uint8 Pin)
{
    switch (Port)
    {
        case PortA: DIO_voidSetPinDirection(Port, Pin, Output); DIO_voidSetPinValue(Port, Pin, High); break;
        case PortB: DIO_voidSetPinDirection(Port, Pin, Output); DIO_voidSetPinValue(Port, Pin, High); break;
        case PortC: DIO_voidSetPinDirection(Port, Pin, Output); DIO_voidSetPinValue(Port, Pin, High); break;
        case PortD: DIO_voidSetPinDirection(Port, Pin, Output); DIO_voidSetPinValue(Port, Pin, High); break;
    }
}

void LED_OFF( uint8 Port, uint8 Pin)
{
    switch (Port)
    {
        case PortA: DIO_voidSetPinDirection(Port, Pin, Output); DIO_voidSetPinValue(Port, Pin, Low); break;
        case PortB: DIO_voidSetPinDirection(Port, Pin, Output); DIO_voidSetPinValue(Port, Pin, Low); break;
        case PortC: DIO_voidSetPinDirection(Port, Pin, Output); DIO_voidSetPinValue(Port, Pin, Low); break;
        case PortD: DIO_voidSetPinDirection(Port, Pin, Output); DIO_voidSetPinValue(Port, Pin, Low); break;
    }
}