/*
 * Sev_SegmentsV2.c
 *
 * Created: 11-Sep-23 2:56:26 AM
 * Author : Eslam Ehab
 */ 

#include "Include/Segments.h"
#include <util/delay.h>


int main(void)
{
    /* Replace with your application code */
	Seg_Init(1);
	Seg_Init(2);
    while (1)
	{
		for (uint8 i = 0; i < 100; i++)
		{
			Seg_Counter(i, 5);
		}
	}
}