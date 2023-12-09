/*
 * File:   main.c
 * Author: Eslam Ehab
 *
 * Created on December 3, 2023, 9:41 PM
 */

#include "Config.h"
#include <pic.h>

#define _XTAL_FREQ 40000000
void Seg_Counter(unsigned char Number, float Timer);



void main() {
    TRISB = 0x00;
    TRISC = 0x00;
    PORTB = 0x00;
    PORTC = 0x00;
    unsigned char i;
    while(1){
        for(i = 0;i < 100;i++)
        {
        Seg_Counter(i, 5);
        }
        /*
        for (i = 0;i < 10;i++)
        {
            PORTB = 0x00;
            PORTC = 0x00;
            PORTB = Number[i];
            PORTC = Number[i];
            __delay_ms(750);
        }*/
    }
}

void Seg_Counter(unsigned char Number, float Timer)
{
    unsigned char segments[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
	float Time_ms = Timer * 1000;
	if(Number < 100)
	{
		unsigned char Ones = Number % 10;
		unsigned char Tens = Number / 10;
		for (unsigned short i = 0; i < Time_ms / 20; i++)
		{
            PORTB = 0x00;
            PORTC = 0x00;
			PORTB = segments[Tens];
			PORTC = segments[Ones];
            __delay_us(10);
		}
	}
}