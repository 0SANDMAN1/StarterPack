#include "../Include/KeyPad.h"

static const uint8 KeyPad[Rows][Columns] = Keypad_Keys;
const uint8  KPD_RowsPins[4] ={ R0, R1, R2, R3};
const  uint8 KPD_ColsPins[4] ={ C0, C1, C2, C3};
uint8 Key_Port;

void Keypad_Init_ALL(uint8 Key_Port)
{
    DIO_voidSetPinDirection(Key_Port, R0, Output); /*Rows*/
    DIO_voidSetPinDirection(Key_Port, R1, Output);
    DIO_voidSetPinDirection(Key_Port, R2, Output);
    DIO_voidSetPinDirection(Key_Port, R3, Output);
    DIO_voidSetPinValue(Key_Port, R0, High);
    DIO_voidSetPinValue(Key_Port, R1, High);
    DIO_voidSetPinValue(Key_Port, R2, High);
    DIO_voidSetPinValue(Key_Port, R3, High);

    DIO_voidSetPinDirection(Key_Port, C0, Input); /*Columns*/
    DIO_voidSetPinDirection(Key_Port, C1, Input);
    DIO_voidSetPinDirection(Key_Port, C2, Input);
    DIO_voidSetPinDirection(Key_Port, C3, Input);
    DIO_voidSetPinValue(Key_Port, C0, High);
    DIO_voidSetPinValue(Key_Port, C1, High);
    DIO_voidSetPinValue(Key_Port, C2, High);
    DIO_voidSetPinValue(Key_Port, C3, High);
}

uint8 Keypad_GetKeyPressed(void)
{
    uint8 Local_Row, Local_Col;
    uint8 Local_SW = Key_NotPressed;
    for(Local_Row = 1 ; Local_Row <= 4 ; Local_Row++)
	{
		DIO_voidSetPinValue(Key_Port,KPD_RowsPins[Local_Row],Low);
		
		for(Local_Col = 1 ;Local_Col <= 4 ; Local_Col++)
		{
			if(DIO_uint8GetPinValue(Key_Port , KPD_ColsPins[Local_Col]) == Low) /* switch is pressed */
			{
				//for bouncing
			    _delay_ms(20);
				while(DIO_uint8GetPinValue(Key_Port , KPD_ColsPins[Local_Col])== 0);//for the delay of pressing
				Local_SW = KeyPad[Local_Row][Local_Col];
			}
			
		}
		DIO_voidSetPinValue(Key_Port, KPD_RowsPins[Local_Row], High);
    }
    return Local_SW;
}