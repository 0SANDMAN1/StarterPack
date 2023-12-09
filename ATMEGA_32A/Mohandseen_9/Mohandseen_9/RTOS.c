/*
* Mohandseen_9.c
*
* Created: 9/22/2023 2:05:01 PM
* Author : user
*/

#include <avr/io.h>
#include <stdlib.h>
#include "Clock.h"
#include "BitMath.h"
#include "DIO.h"
#include "LCD.h"
#include "Keypad.h"
#include "SSD.h"
#include "GINT.h"
#include "Ext_Int.h"
#include "ADC.h"
#include "LM35.h"
#include "PWM.h"
#include "ServoMotor.h"
#include "Ultrasonic.h"
#include "Bluetooth.h"
#include "SPI.h"
#include "EEPROM.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"


void xPrint(void * string);
void ADCWriteQueue(void * string);

xQueueHandle uartQueue;

typedef struct{
	u8 iValue;
	char iMeaning[10];
}xData;

int main(void)
{
	//DIO_Init();
	UART_ConfigTypes options = {9600,DoupleSpeed_Disable,CharacterSize_8,Stop_1Bit,Parity_Disable,TX_Enable,RX_Enable};
	UART_Init(&options);

	uartQueue = xQueueCreate(3,sizeof(xData));
	
	xData txData[2] = {{100,"Oil\n\r"},{200,"Speed\n\r"}};
	
	xTaskCreate(ADCWriteQueue,"Task1",100,(void *)&txData[0],1,NULL);
	xTaskCreate(ADCWriteQueue,"Task2",100,(void *)&txData[1],1,NULL);
	xTaskCreate(xPrint,"xPrint",100,NULL,2,NULL);
	
	vTaskStartScheduler();

	while (1)
	{

	}
}

void ADCWriteQueue(void * string){
	while(1){
		xQueueSendToBack(uartQueue,string,5/portTICK_PERIOD_MS);
	}
}

void xPrint(void * string){
	char rxData[10];
	xData strData;
	while(1){
		if (xQueueReceive(uartQueue,&strData,5/portTICK_PERIOD_MS) == pdTRUE)
		{
			itoa(strData.iValue,rxData,10);
			UART_TransmaitString((char *)rxData);
			UART_TransmaitChar(' ');
			UART_TransmaitString((char*)strData.iMeaning);
		}
	}
}