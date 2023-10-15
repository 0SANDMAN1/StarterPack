#include "../Include/Segments.h"
#include "../Include/delay.h"


void Seg_Init(uint8 segment_ID)
{
    DIO_voidSetPinDirection(Seg_PortA, Seg_Pin4, Output);//A
    DIO_voidSetPinDirection(Seg_PortA, Seg_Pin5, Output);//B
    DIO_voidSetPinDirection(Seg_PortA, Seg_Pin6, Output);//C
    DIO_voidSetPinDirection(Seg_PortA, Seg_Pin7, Output);//D
	if (segment_ID == 1)//EN1
	{
		DIO_voidSetPinDirection(PortB, Pin2, Output);
		DIO_voidSetPinValue(PortB, Pin2, High);
	}
	else if (segment_ID == 2)//EN2
	{
		DIO_voidSetPinDirection(PortB, Pin1, Output);
		DIO_voidSetPinValue(PortB, Pin1, High);
	}
	else if (segment_ID == 3)//BOTH
	{
		DIO_voidSetPinDirection(PortB, Pin2, Output);
		DIO_voidSetPinValue(PortB, Pin2, High);
		DIO_voidSetPinDirection(PortB, Pin1, Output);
		DIO_voidSetPinValue(PortB, Pin1, High);
	}
}

void Seg_Display(uint8 number)//, uint8 Seg_Number)
{
	switch (number)
    {

//													1											2												4												8
		case 0: DIO_voidSetPinValue(Seg_PortA, Seg_Pin4, Low); DIO_voidSetPinValue(Seg_PortA, Seg_Pin5, Low); DIO_voidSetPinValue(Seg_PortA, Seg_Pin6, Low); DIO_voidSetPinValue(Seg_PortA, Seg_Pin7, Low); break;
        case 1: DIO_voidSetPinValue(Seg_PortA, Seg_Pin4, High); DIO_voidSetPinValue(Seg_PortA, Seg_Pin5, Low); DIO_voidSetPinValue(Seg_PortA, Seg_Pin6, Low); DIO_voidSetPinValue(Seg_PortA, Seg_Pin7, Low); break;
        case 2: DIO_voidSetPinValue(Seg_PortA, Seg_Pin4, Low); DIO_voidSetPinValue(Seg_PortA, Seg_Pin5, High); DIO_voidSetPinValue(Seg_PortA, Seg_Pin6, Low); DIO_voidSetPinValue(Seg_PortA, Seg_Pin7, Low); break;
        case 3: DIO_voidSetPinValue(Seg_PortA, Seg_Pin4, High); DIO_voidSetPinValue(Seg_PortA, Seg_Pin5, High); DIO_voidSetPinValue(Seg_PortA, Seg_Pin6, Low); DIO_voidSetPinValue(Seg_PortA, Seg_Pin7, Low); break;
        case 4: DIO_voidSetPinValue(Seg_PortA, Seg_Pin4, Low); DIO_voidSetPinValue(Seg_PortA, Seg_Pin5, Low); DIO_voidSetPinValue(Seg_PortA, Seg_Pin6, High); DIO_voidSetPinValue(Seg_PortA, Seg_Pin7, Low); break;
        case 5: DIO_voidSetPinValue(Seg_PortA, Seg_Pin4, High); DIO_voidSetPinValue(Seg_PortA, Seg_Pin5, Low); DIO_voidSetPinValue(Seg_PortA, Seg_Pin6, High); DIO_voidSetPinValue(Seg_PortA, Seg_Pin7, Low); break;
        case 6: DIO_voidSetPinValue(Seg_PortA, Seg_Pin4, Low); DIO_voidSetPinValue(Seg_PortA, Seg_Pin5, High); DIO_voidSetPinValue(Seg_PortA, Seg_Pin6, High); DIO_voidSetPinValue(Seg_PortA, Seg_Pin7, Low); break;
        case 7: DIO_voidSetPinValue(Seg_PortA, Seg_Pin4, High); DIO_voidSetPinValue(Seg_PortA, Seg_Pin5, High); DIO_voidSetPinValue(Seg_PortA, Seg_Pin6, High); DIO_voidSetPinValue(Seg_PortA, Seg_Pin7, Low); break;
        case 8: DIO_voidSetPinValue(Seg_PortA, Seg_Pin4, Low); DIO_voidSetPinValue(Seg_PortA, Seg_Pin5, Low); DIO_voidSetPinValue(Seg_PortA, Seg_Pin6, Low); DIO_voidSetPinValue(Seg_PortA, Seg_Pin7, High); break;
        case 9: DIO_voidSetPinValue(Seg_PortA, Seg_Pin4, High); DIO_voidSetPinValue(Seg_PortA, Seg_Pin5, Low); DIO_voidSetPinValue(Seg_PortA, Seg_Pin6, Low); DIO_voidSetPinValue(Seg_PortA, Seg_Pin7, High); break;

    }
/*
	switch (number)
    {
    DIO_voidSetPinValue( Seg_PortA, Seg_Pin4, (number >> 0) & 0x01);
    DIO_voidSetPinValue( Seg_PortB, Seg_Pin5, (number >> 1) & 0x01);
    DIO_voidSetPinValue( Seg_PortC, Seg_Pin6, (number >> 2) & 0x01);
    DIO_voidSetPinValue( Seg_PortD, Seg_Pin7, (number >> 3) & 0x01);
    }
*/
}

void Seg_Off(uint8 EN)
{
	if (EN == 1)
	{
		DIO_voidSetPinValue(PortB, Pin2, Low);
	}
	else if (EN == 2)
	{
		DIO_voidSetPinValue(PortB, Pin1, Low);
	}
	
}

void Seg_On(uint8 EN)
{
	if (EN == 1)
	{
		DIO_voidSetPinValue(PortB, Pin2, High);
	}
	else if (EN == 2)
	{
		DIO_voidSetPinValue(PortB, Pin1, High);
	}
	
}

void Seg_Counter(uint8 Number, float Timer)
{
	uint16 Time_ms = Timer * 1000;
	if(Number < 100)
	{
		uint8 Ones = Number % 10;
		uint8 Tens = Number / 10;
		for (uint16 i = 0; i < Time_ms / 20; i++)
		{
			Seg_Off(1);
			Seg_Off(2);
			Seg_Display(Tens);
			Seg_On(1);
			_delay_ms(10);
			Seg_Off(1);
			Seg_Display(Ones);
			Seg_On(2);
			_delay_ms(10);
		}
	}
}