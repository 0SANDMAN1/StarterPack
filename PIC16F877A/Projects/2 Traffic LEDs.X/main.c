/*
 * File:   main.c
 * Author: Eslam Ehab
 *
 * Created on November 13, 2023, 9:40 PM
 */


#include "Config.h"
#include <pic.h>

#define _XTAL_FREQ 40000000

void main() {
    TRISB = 0x00; //Set all ports to output
    PORTB = 0x00;

    /* Replace with your application code */
    while (1) {
        RB1 = 0;
        RB2 = 0;
        RB5 = 0;
        RB6 = 0;
        RB3 = 1;
        RB4 = 1;
        __delay_ms(5000);
        RB2 = 1;
        RB5 = 1;
        __delay_ms(3000);
        RB3 = 0;
        RB2 = 0;
        RB5 = 0;
        RB4 = 0;
        RB1 = 1;
        RB6 = 1;
        __delay_ms(5000);
        RB2 = 1;
        RB5 = 1;
        __delay_ms(3000); 
    }
}
