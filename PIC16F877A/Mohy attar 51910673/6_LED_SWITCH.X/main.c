/* 
 * File:   main.c
 * Author: Eslam Ehab
 *
 * Created on November 13, 2023, 11:45 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Config.h"
#include <pic.h>
#define _XTAL_FREQ 40000000

/*
 * 
 */
void main() {
    TRISB = 0x00;
    PORTB = 0X00;
    RB0 = 1;
    
    while(1){
        if (RB0 == 0)
        {
            __delay_ms(50);
            while (RB0 == 0);
            
            int button = rand() % 7 + 1;
            
            switch (button){
            case 1: PORTB = 0x01; RB1 = 1; __delay_ms(3000); PORTB = 0x01; button = 0; break;
            case 2: PORTB = 0x01; RB3 = 1; RB6 = 1; __delay_ms(3000); PORTB = 0x01; button = 0; break;
            case 3: PORTB = 0x01; RB3 = 1; RB6 = 1; RB1 = 1; __delay_ms(3000); PORTB = 0x01; button = 0; break;
            case 4: PORTB = 0x01; RB2 = 1; RB5 = 1; RB4 = 1; RB7 = 1; __delay_ms(3000); PORTB = 0x01; button = 0; break;
            case 5: PORTB = 0x01; RB2 = 1; RB5 = 1; RB4 = 1; RB7 = 1; RB1 = 1; __delay_ms(3000); PORTB = 0x01; button = 0; break;
            case 6: PORTB = 0x01; RB2 = 1; RB3 = 1; RB4 = 1; RB5 = 1; RB6 = 1; RB7 = 1; __delay_ms(3000); PORTB = 0x01; button = 0; break;
        }
        }
    }
}

