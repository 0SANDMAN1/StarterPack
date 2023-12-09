/*
* main.c
*
* Created: 17-Oct-23 10:31:00 PM
*  Author: Eslam Ehab
*/
#include "LCD.h"


int main(void)
{
	LCD_Init();
	LCD_SetPos(1, 1);
	LCD_String("Eslam Ehab");
	
	while (1)
	{
		
	}
}