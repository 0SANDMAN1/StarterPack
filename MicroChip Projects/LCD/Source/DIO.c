#include "../Include/STD.h"
#include "../Include/bit_math.h"
#include "../Include/DIO.h"
 
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
    case PortA: Loc_uint8Result = Get( PinA_Reg,  Pin); break;
    case PortB: Loc_uint8Result = Get( PinB_Reg,  Pin); break;
    case PortC: Loc_uint8Result = Get( PinC_Reg,  Pin); break;
    case PortD: Loc_uint8Result = Get( PinD_Reg,  Pin); break;
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

uint8 DIO_ReadPort(uint8 Port)
{
	uint8 portValue = 0;
	switch(Port)
	{
		case PortA:
		portValue = PortA_Reg;
		break;
		
		case PortB:
		portValue = PortB_Reg;
		break;
		
		case PortC:
		portValue = PortC_Reg;
		break;
		
		case PortD:
		portValue = PortD_Reg;
		break;
	}
	
	return portValue;
}

void DIO_WritePort(uint8 Port, uint8 portValue)
{
	switch(Port)
	{
		case PortA:
		PortA_Reg = portValue ;
		break;
		case PortB:
		PortB_Reg = portValue;
		break;
		case PortC:
		PortC_Reg  = portValue;
		break;
		case PortD:
		PortD_Reg = portValue;
		break;
	}
}