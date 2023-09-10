#include "../Include/LED.h"

void LED_Init( uint8 LED_Port, uint8 LED_Pin)
{
    DIO_voidSetPinDirection(uint8 LED_Port, uint8 LED_Pin, Output);
}

void LED_On( uint8 LED_Port, uint8 LED_Pin)
{
    DIO_voidSetPinValue(uint8 LED_Port, uint8 LED_Pin, High);
}

void LED_Off( uint8 LED_Port, uint8 LED_Pin)
{
    DIO_voidSetPinValue(uint8 LED_Port, uint8 LED_Pin, Low);
}