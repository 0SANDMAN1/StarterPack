/*
 * LCD.c
 *
 * Created: 9/29/2023 4:45:19 PM
 * Author : Eslam Ehab
 */ 
#include "Include/LCD.h"


int main(void)
{
    /* Replace with your application code */
	LCD_Init();
	LCD_Setpos(1, 5);
	LCD_String("Eslam");
	LCD_Setpos(0, 1);
	LCD_String("FantaBlack");
    while (1) 
    {
    }
}

