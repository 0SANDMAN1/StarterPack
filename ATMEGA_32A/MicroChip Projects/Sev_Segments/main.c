/*
 * Sev_Segments.c
 *
 * Created: 10-Sep-23 11:46:54 PM
 * Author : Eslam Ehab
 */ 

#include "Segments.h"
#include <util/delay.h>


int main(void)
{
	Seg_Init(3);
    while (1) 
    {
		uint8 i;
		for (i = 0; i < 10; i++)
		{
			_delay_ms(3000);
			Seg_Display(i);
		}
    }
}

