#include "../Include/DIO.h"
#include "../Include/Stepper.h"

void Stepper_Init(uint8 Port_A, uint8 Pin_A, uint8 Port_B, uint8 Pin_B, uint8 Port_C, uint8 Pin_C, uint8 Port_D, uint8 Pin_D)
{
    uint8 Port_IN1 = Port_A;
    uint8 Port_IN2 = Port_B;
    uint8 Port_IN3 = Port_C;
    uint8 Port_IN4 = Port_D;
    uint8 IN1 = Pin_A;
    uint8 IN2 = Pin_B;
    uint8 IN3 = Pin_C;
    uint8 IN4 = Pin_D;
    DIO_voidSetPinDirection(Port_A, Pin_A, Output);
    DIO_voidSetPinDirection(Port_B, Pin_B, Output);
    DIO_voidSetPinDirection(Port_C, Pin_C, Output);
    DIO_voidSetPinDirection(Port_D, Pin_D, Output);
}

void Stepper_A()
{
    DIO_voidSetPinValue(Port_IN1, IN1, High);
    DIO_voidSetPinValue(Port_IN2, IN2, Low);
    DIO_voidSetPinValue(Port_IN3, IN3, Low);
    DIO_voidSetPinValue(Port_IN4, IN4, Low);
}

void Stepper_B()
{
    DIO_voidSetPinValue(Port_IN1, IN1, Low);
    DIO_voidSetPinValue(Port_IN2, IN2, High);
    DIO_voidSetPinValue(Port_IN3, IN3, Low);
    DIO_voidSetPinValue(Port_IN4, IN4, Low);
}

void Stepper_C()
{
    DIO_voidSetPinValue(Port_IN1, IN1, Low);
    DIO_voidSetPinValue(Port_IN2, IN2, Low);
    DIO_voidSetPinValue(Port_IN3, IN3, High);
    DIO_voidSetPinValue(Port_IN4, IN4, Low);
}

void Stepper_D()
{
    DIO_voidSetPinValue(Port_IN1, IN1, Low);
    DIO_voidSetPinValue(Port_IN2, IN2, Low);
    DIO_voidSetPinValue(Port_IN3, IN3, Low);
    DIO_voidSetPinValue(Port_IN4, IN4, High);
}

void Stepper_Rotate_CW(uint16 Angle)
{
    uint16 steps = (Angle * 2048)/360;
    uint16 i;
    for (i = 0; i < steps; i++)
    {
        Stepper_A();
        _delay_ms(100);
        Stepper_B();
        _delay_ms(100);
        Stepper_C();
        _delay_ms(100);
        Stepper_D();
        _delay_ms(100);
    }
    
}

void Stepper_Rotate_CCW(uint16 Angle)
{
    uint16 steps = (Angle * 2048)/360;
    uint16 i;
    for (i = 0; i < steps; i++)
    {
        Stepper_D();
        _delay_ms(100);
        Stepper_C();
        _delay_ms(100);
        Stepper_B();
        _delay_ms(100);
        Stepper_A();
        _delay_ms(100);
    }
}