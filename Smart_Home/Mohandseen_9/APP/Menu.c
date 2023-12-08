/*
* Menu.c
*
* Created: 04/12/2023 11:43:32 pm
*  Author: amost
*/
#include "menu.h"
extern UART_ConfigTypes option;
void InitPWM();
void SetPWMOutPut (u8 duty);
volatile u16 temp_sensor_reading=0;
volatile u8 last_air_conditioning_value=AIR_CONDTIONING_OFF;
extern u8 temperature;
//extern s8 adcstring;
extern u8 advvalue;
extern u16 required_temperature;
extern u8 login_mode;
extern u8 rxdata;

u8 ui8ComparePass(const u8* pass1, const u8* pass2, const u8 size)
{
	u8 pin_counter = 0; // the offset of the character of the pin
	u8 ret_value = TRUE; // assume the passwords are equal initially

	while (pin_counter < size) // loop till the pin is fully entered
	{
		if (*(pass1 + pin_counter) != *(pass2 + pin_counter))
		{
			ret_value = FALSE; // set to FALSE if characters are not equal
			break;             // break the loop
		}
		pin_counter++; // increase the offset by one
	}

	return ret_value; // returns TRUE if the two PINs are equal, FALSE otherwise
}

u8 ui8ComparePass2(const u8* pass1, const u8* pass2, const u8 size)
{
	return (memcmp(pass1, pass2, size) == 0) ? TRUE : FALSE;
}

u8 u8GetKeyPressed(const u8 u8LoginMode)
{
	u8 key_pressed = NOT_PRESSED;
	while (key_pressed == NOT_PRESSED)//repeat till the user press any key
	{
		key_pressed = GetKey();
		_delay_ms(20);//if the user pressed any button in keypad save the value in key_pressed
	}
	return key_pressed;
}

u8 u8GetTX (const u8 TX)
{
	u8 data = NOT_PRESSED;
	while (data == 0)
	{
		data = Bluetooth_Receive();
		_delay_ms(20);
	}
	return data;
}

void vMenuOption(const u8 u8SelectedRoom,const u8 u8LoginMode)
{
	u8 u8StatusCode  = 0;//demand status code
	u8 u8TurnOnCode  = 0;//turn on the room or the device code
	u8 u8TurnOffCode = 0;//turn off the device or room
	u8 key_pressed   = NOT_PRESSED;//the key that is entered by the user
	u8 Statues=0;
	u8 value = 0;
	do
	{
		LCD_Clear();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
		

		switch(u8SelectedRoom)
		{
			case ROOM1_MENU:
			u8StatusCode = ROOM1_STATUS;
			u8TurnOnCode = ROOM1_TURN_ON;
			u8TurnOffCode = ROOM1_TURN_OFF;
			LCD_String("Room1 S:");
			break;
			
			case ROOM2_MENU:
			u8StatusCode = ROOM2_STATUS;
			u8TurnOnCode = ROOM2_TURN_ON;
			u8TurnOffCode = ROOM2_TURN_OFF;
			LCD_String("Room2 S:");
			break;
			
			case ROOM3_MENU:
			u8StatusCode = ROOM3_STATUS;
			u8TurnOnCode = ROOM3_TURN_ON;
			u8TurnOffCode = ROOM3_TURN_OFF;
			LCD_String("Room3 S:");
			break;
			
			case ROOM4_MENU:
			u8StatusCode = ROOM4_STATUS;
			u8TurnOnCode = ROOM4_TURN_ON;
			u8TurnOffCode = ROOM4_TURN_OFF;
			LCD_String("Room4 S:");
			break;
			
			case TV_MENU:
			u8StatusCode = TV_STATUS;
			u8TurnOnCode = TV_TURN_ON;
			u8TurnOffCode = TV_TURN_OFF;
			LCD_String("TV S:");
			break;
			
			case AIRCOND_CTRL_MENU:
			u8StatusCode = AIR_COND_STATUS;
			u8TurnOnCode = AIR_COND_TURN_ON;
			u8TurnOffCode = AIR_COND_TURN_OFF;
			LCD_String("Air Cond. S:");
			break;
		}
		/************************************************************************************************************/
		
		switch(u8SelectedRoom)
		{
			case ROOM1_MENU:
			if(DIO_ReadChannel(DIO_ChannelA1) == 1)//if the response from the slave was on status
			{
				LCD_String("ON");//print the status on
				Statues = 1;
			}
			else//if the response from the slave was off status
			{
				LCD_String("OFF");//print the status off
				Statues= 1;
			}break;
			
			case ROOM2_MENU:
			if(DIO_ReadChannel(DIO_ChannelB4) == 1)//if the response from the slave was on status
			{
				LCD_String("ON");//print the status on
				Statues = 12;
			}
			else//if the response from the slave was off status
			{
				LCD_String("OFF");//print the status off
				Statues= 12;
			}break;
			
			case ROOM3_MENU:
			if(DIO_ReadChannel(DIO_ChannelB5) == 1)//if the response from the slave was on status
			{
				LCD_String("ON");//print the status on
				Statues = 13;
			}
			else//if the response from the slave was off status
			{
				LCD_String("OFF");//print the status off
				Statues= 13;
			}break;
			
			case ROOM4_MENU:
			if(DIO_ReadChannel(DIO_ChannelB6) == 1)//if the response from the slave was on status
			{
				LCD_String("ON");//print the status on
				Statues = 14;
			}
			else//if the response from the slave was off status
			{
				LCD_String("OFF");//print the status off
				Statues= 14;
			}break;
			
			case TV_MENU:
			if(DIO_ReadChannel(DIO_ChannelD7) == 1)//if the response from the slave was on status
			{
				LCD_String("ON");//print the status on
				Statues = 31;
			}
			else//if the response from the slave was off status
			{
				LCD_String("OFF");//print the status off
				Statues= 31;
			}break;
			
			case AIRCOND_CTRL_MENU:
			if(DIO_ReadChannel(DIO_ChannelB7) == 1)//if the response from the slave was on status
			{
				LCD_String("ON");//print the status on
				Statues = 15;
			}
			else//if the response from the slave was off status
			{
				LCD_String("OFF");//print the status off
				Statues= 15;
			}break;
			
			case SET_TEMPERATURE:
			required_temperature = temperature;//store the temperature in required temperature
			break;//break the switch case

		}
		
		LCD_SetPos(2,1);//move the cursor to the start of the second line
		
		LCD_String("1-On 2-Off 0-RET");//print the sub menu

		/*******************************************************************************/
		if (login_mode == GUEST)
		{
			key_pressed = u8GetKeyPressed(u8LoginMode);//wait for the user till key is pressed
			_delay_ms(100);//to avoid the duplication of the pressed key

			/*there is no need to take any action in case of the user pressed 0(RET) key
			breaking the loop will be enough since it will be handled in the main*/

			if (key_pressed == '1')
			{
				
				DIO_WriteChannel(Statues,STD_High);//turn on the led of room 1
				value = key_pressed;
			}
			else if (key_pressed == '2')
			{
				DIO_WriteChannel(Statues,STD_Low);
				value = key_pressed;
			}
			else if (key_pressed == '0')
			{
				value = key_pressed;
			}
			
			else if( (key_pressed != NOT_PRESSED) && (key_pressed != '0') )//show wrong input message if the user entered non numeric value
			{
				LCD_Clear();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
				LCD_String("Wrong input");//print error message
				_delay_ms(500);//Halt the system for the given time in (ms)
				//value = 0;
			}
		}
		else if (login_mode == ADMIN)
		{
			Bluetooth_TransmaitString("1-On 2-Off 0-RET");
			rxdata = u8GetTX(login_mode);

			if (rxdata == '1')
			{
				
				DIO_WriteChannel(Statues,STD_High);//turn on the led of room 1
				value = rxdata;
			}
			else if (rxdata == '2')
			{
				DIO_WriteChannel(Statues,STD_Low);
				value = rxdata;
			}else if (rxdata == '2')
			{
				DIO_WriteChannel(Statues,STD_Low);
				value = rxdata;
			}
			else if (rxdata == '0')
			{
				value = rxdata;
			}
			
			else if( (rxdata != NOT_PRESSED) && (rxdata != '0') )//show wrong input message if the user entered non numeric value
			{
				LCD_Clear();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
				LCD_String("Wrong input");//print error message
				_delay_ms(500);//Halt the system for the given time in (ms)
				//value = 0;
			}
		}
	}while ( ( (value < '0') || (value > '2') ));
}

void InitPWM()
{
	DIO_ConfigChannel(DIO_ChannelB3, Output);
	// Set PWM mode and configure clock source
	TCCR0 |= 1 << WGM00 | 1 << WGM01 | 1 << CS00 | 1 << COM01;
}

void SetPWMOutPut (u8 duty)
{
	OCR0 = duty;
}


