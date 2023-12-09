/*
 * KeyPad.c
 *
 * Created: 17-Sep-23 9:20:23 PM
 * Author : Eslam Ehab
 */ 

#include "Include/DIO.h"
#include "Include/delay.h"
#include "Include/KeyPad.h"
#include "Include/Segments.h"


int main(void)
{
    /* Replace with your application code */
	Keypad_Init_ALL(PortC);
	Seg_Init(2);
	Seg_Init(1);
    while (1) 
    {
		Seg_Counter(Keypad_GetKeyPressed(), 5);
	}
}

