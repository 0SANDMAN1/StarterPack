#include "../Include/DIO.h"
#include "../Include/bit_math.h"
#include "../Include/STD.h"

void DIO_voidSetPinDirection(uint8 Port, uint8 Pin, uint8 Direction);
void DIO_voidSetPinValue(uint8 Port, uint8 Pin, uint8 Value);
uint8 DIO_uint8GetPinValue(uint8 Port, uint8 Pin);
 
void DIO_voidSetPinDirection(uint8 Port, uint8 Pin, uint8 Direction)
{
    switch (Port)
    {
        case PortA: if (Direction == Output) Set(DDRA_Reg, Pin); else Clr(DDRA_Reg, Pin); break;
        case PortB: if (Direction == Output) Set(DDRB_Reg, Pin); else Clr(DDRB_Reg, Pin); break;
        case PortC: if (Direction == Output) Set(DDRC_Reg, Pin); else Clr(DDRC_Reg, Pin); break;
        case PortD: if (Direction == Output) Set(DDRD_Reg, Pin); else Clr(DDRD_Reg, Pin); break;
    }
}

uint8 DIO_uint8GetPinValue(uint8 Port, uint8 Pin)
{
    uint8 Loc_uint8Result = 0;
    switch (Port)
    {
    case PortA: Loc_uint8Result = Get( PortA_Reg,  Pin); break;
    case PortB: Loc_uint8Result = Get( PortB_Reg,  Pin); break;
    case PortC: Loc_uint8Result = Get( PortC_Reg,  Pin); break;
    case PortD: Loc_uint8Result = Get( PortD_Reg,  Pin); break;
    }
    return Loc_uint8Result;
}

void DIO_voidSetPinValue(uint8 Port, uint8 Pin, uint8 Value)
{
    switch (Port)
    {
    case PortA: if(Value == High) Set( PortA_Reg,  Pin); else Clr( PortA_Reg, Pin); break;
    case PortB: if(Value == High) Set( PortB_Reg,  Pin); else Clr( PortB_Reg, Pin); break;
    case PortC: if(Value == High) Set( PortC_Reg,  Pin); else Clr( PortC_Reg, Pin); break;
    case PortD: if(Value == High) Set( PortD_Reg,  Pin); else Clr( PortD_Reg, Pin); break;
    }
}