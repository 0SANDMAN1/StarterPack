/*
 * LED SIREN.c
 *
 * Created: 25-Sep-23 7:49:06 PM
 * Author : Eslam Ehab
 */ 
#include "Include/LED.h"


int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
		LED_OFF(PortB, Pin0);
		LED_OFF(PortB, Pin7);
		LED_ON(PortB, Pin3);
		LED_ON(PortB, Pin4);
		_delay_ms(500);
		LED_ON(PortB, Pin2);
		LED_ON(PortB, Pin5);
		LED_OFF(PortB, Pin3);
		LED_OFF(PortB, Pin4);
		_delay_ms(500);
		LED_OFF(PortB, Pin2);
		LED_OFF(PortB, Pin5);
		LED_ON(PortB, Pin3);
		LED_ON(PortB, Pin4);
		LED_ON(PortB, Pin1);
		LED_ON(PortB, Pin6);
		_delay_ms(500);
		LED_OFF(PortB, Pin1);
		LED_OFF(PortB, Pin6);
		LED_OFF(PortB, Pin3);
		LED_OFF(PortB, Pin4);
		LED_ON(PortB, Pin0);
		LED_ON(PortB, Pin7);
		_delay_ms(500);
    }
}

