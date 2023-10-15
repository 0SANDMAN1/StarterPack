#include "../Include/Buzzer.h"

void Buzzer_Init()
{
    DIO_voidSetPinDirection(Buzzer_PortA, Buzzer_Pin3, Output);
}

void Buzzer_SetHigh()
{
    DIO_voidSetPinValue(Buzzer_PortA, Buzzer_Pin3, High);
}

void Buzzer_SetLow()
{
    DIO_voidSetPinValue(Buzzer_PortA, Buzzer_Pin3, Low);
}