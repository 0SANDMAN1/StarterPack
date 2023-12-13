/*
* Mohandseen_9.c
*
* Created: 9/22/2023 2:05:01 PM
* Author : user
*/


#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include "Clock.h"
#include "BitMath.h"
#include "DIO.h"
#include "LCD.h"
#include "Keypad.h"
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
#include "Cinfig home.h"


void ExtInt0Fun(void);
//void ExtInt1Fun(void);

UART_ConfigTypes option = {BaudRate_9600,DoupleSpeed_Disable,CharacterSize_8,Stop_1Bit,Parity_Disable,TX_Enable,RX_Enable};
ADC_InitTypes options={ADC_Vref_Internal,ADC_Prescaler128};

u8 pass_tries_count;
u8 login_mode = NO_MODE; //Store the current user mode admin or guest or not logged in
u8 rxdata = 0;
extern u8 last_air_conditioning_value;

//u8 overflowFlag=0;
s8 adcstring [10];
u8 temperature = 0;
u16 advvalue =0;
u16 required_temperature=24;



int main(void)
{
	

	//The average temperature of the room
	u8 brightness =0;
	u8 temp_ones = NOT_SELECTED;
	u8 temp_tens = NOT_SELECTED;
	u8 Dimmer_ones = NOT_SELECTED;
	u8 Dimmer_tens = NOT_SELECTED;
	u8 Dimmer_hundreds = NOT_SELECTED;
	u8 block_mode_flag = FALSE;
	u8 key_pressed  = NOT_PRESSED;
	u8 rxdata = 0;
	
	/*****************  INITIALIZE  **********************************************/
	Bluetooth_Init(&option);
	DIO_ConfigChannel(DIO_ChannelB3,Output);
	DIO_ConfigChannel(DIO_ChannelD2,Input);
	LM35_Init(&options);
	DIO_Init();
	Keypad_Init();
	LCD_Init();
	
	Ext_Interrupt_SetCallBack(Ext_INT0,ExtInt0Fun);
	Ext_Interrupt_Sncontrol(Ext_INT0,Rising_Edge);
	Ext_Interrupt_Enable(Ext_INT0);
	
	// 	Ext_Interrupt_SetCallBack(Ext_INT1,ExtInt1Fun);
	// 	Ext_Interrupt_Sncontrol(Ext_INT1,Rising_Edge);
	// 	Ext_Interrupt_Enable(Ext_INT1);
	
	
	EnableAllInterrupts();
	//Timer0_Init();
	/*****************************************************************************/
	/* Printing Welcome screen */
	LCD_SetPos(1, 0);
	LCD_String("Welcome to smart");
	Bluetooth_TransmaitString("Welcome to smart\n\r");
	LCD_SetPos(2, 0);
	LCD_String("home system");
	Bluetooth_TransmaitString("home system\n\r");
	_delay_ms(1000);
	LCD_Clear();
	
	/***************************/
	/*Setting Admin and Guest passwords if not set */
	//read the state of the the passwords of the admin and guest if both are set or not set
	advvalue = LM35_Read(ADC_Channel0);
	if (advvalue >required_temperature)
	{
		DIO_WriteChannel(DIO_ChannelB7,STD_High);
	}
	
	if ( (EEPROM_ui8ReadByteFromAddress(ADMIN_PASS_STATUS_ADDRESS)!=PASS_SET) || (EEPROM_ui8ReadByteFromAddress(GUEST_PASS_STATUS_ADDRESS)!=PASS_SET) )
	{
		LCD_String("Login for");//printing login menu
		LCD_SetPos(2,1);//move the cursor to the second line
		LCD_String("first time");
		_delay_ms(1000);//Halt the system for the given time in (ms)
		LCD_Clear();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
		LCD_String("Set Admin pass");//printing the set admin password menu
		LCD_SetPos(2,1);
		LCD_String("Admin pass:");
		
		/********************************* setting Admin password **********************************************/
		u8 pass_counter = 0;  // the counter of the characters of the password
		u8 pass[PASS_SIZE] = {NOT_STORED, NOT_STORED, NOT_STORED, NOT_STORED};  // the array where it stored the password
		while (pass_counter < PASS_SIZE) {  // loop till the user finishes inserting the pass
			key_pressed = 0;  // return the variable that holds the pressed key from keypad to its initial value
			while (key_pressed == 0) {  // repeat till the user presses any key
				key_pressed = GetKey();  // if the user pressed any button on the keypad, save the value in GetKey
				_delay_ms(20);
			}

			pass[pass_counter] = key_pressed;  // add the entered character to the pass array
			LCD_Char(key_pressed);  // print the entered character
			_delay_ms(CHARACTER_PREVIEW_TIME);  // Halt the system for the given time in (ms)
			LCD_SetPos(2, 12 + pass_counter);  // move the LCD cursor to the previous location to write the password symbol over the character
			LCD_Char(PASSWORD_SYMBOL);  // to display (Password sign *)
			_delay_ms(100);  // Halt the system for the given time in (ms)
			pass_counter++;  // increase the characters count
		}

		EEPROM_vWriteBlockToAddress(EEPROM_ADMIN_ADDRESS,pass,PASS_SIZE);//save the entire password as a block to the EEPROM
		EEPROM_vWriteByteToAddress(ADMIN_PASS_STATUS_ADDRESS,PASS_SET);//write the status of pass as it is set
		
		LCD_Clear();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
		LCD_String("Pass Saved");// show pass saved message
		_delay_ms(500);//Halt the system for the given time in (ms)
		LCD_Clear();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
		
		/********************************* setting guest password **********************************************/
		pass_counter=0;//reset password counter which count the characters of the pass
		LCD_String("Set Guest Pass");//printing the set admin password menu
		LCD_SetPos(2,1);
		LCD_String("Guest Pass:");
		while (pass_counter<PASS_SIZE)//loop till the user finish inserting the pass
		{
			key_pressed = 0;//return the variable that holds the pressed key from keypad to its initial value
			while (key_pressed == 0)//repeat till the user press any key
			{
				key_pressed = GetKey();//if the user pressed any button in keypad save the value in key_pressed
				_delay_ms(20);
			}

			pass[pass_counter]=key_pressed;//add the entered character to the pass array
			LCD_Char(key_pressed);//print the entered character
			_delay_ms(CHARACTER_PREVIEW_TIME);//Halt the system for the given time in (ms)
			LCD_SetPos(2,12+pass_counter);//move the lcd cursor to the previous location to write the password symbol over the character
			LCD_Char(PASSWORD_SYMBOL); // to display (Password sign *)
			_delay_ms(100);//Halt the system for the given time in (ms)
			pass_counter++;//increase the characters count
		}
		EEPROM_vWriteBlockToAddress(EEPROM_GUEST_ADDRESS,pass,PASS_SIZE);//save the entire password as a block to the EEPROM
		EEPROM_vWriteByteToAddress(GUEST_PASS_STATUS_ADDRESS,PASS_SET);//write the status of pass as it is set
		LCD_Clear();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
		LCD_String("Pass Saved");//move the lcd cursor to the previous location
		_delay_ms(500);//Halt the system for the given time in (ms)
		LCD_Clear();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
		EEPROM_vWriteByteToAddress(LOGIN_BLOCKED_ADDRESS,FALSE);
		
	}//The end of if admin and guest password is set
	else//this code of else run only if the system is not running for the first time (ADMIN and GUEST passwords are set)
	{
		block_mode_flag = EEPROM_ui8ReadByteFromAddress(LOGIN_BLOCKED_ADDRESS); //read the blocked location from EEPROM
		
	}
	
	while (1)//The start of the periodic code
	{
		
		key_pressed = 0;//return the variable that holds the pressed key from keypad to its initial value
		u8 pass_tries_count=0;//stores how many times the user tried to log in to the system and failed
		if ( pass_tries_count!=3 ){
			login_mode=NO_MODE;//log the user out
			key_pressed = 0;//clear the key_pressed to avoid unwanted selection in the menu switch
			DIO_WriteChannel(DIO_ChannelD6,STD_Low);//turnoff the led of the admin
			DIO_WriteChannel(DIO_ChannelD3,STD_Low);//turnoff the led of the guest
			//LCD_Clear();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
			_delay_ms(1000);//Halt the system for the given time in (ms)
		}
		
		
		
		while (login_mode==NO_MODE)//The user can only leave the loop only in case of he was logged in as guest or admin
		{
			if(block_mode_flag==TRUE)//if the login process was blocked wait till the end of the block period
			{
				LCD_Clear();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
				LCD_String("Login blocked");
				Bluetooth_TransmaitString("Login blocked\n\r");
				LCD_SetPos(2,1);
				LCD_String("wait 20 seconds");
				Bluetooth_TransmaitString("wait 20 seconds\n\r");
				DIO_WriteChannel(DIO_ChannelD4,STD_High);//Turn on the led of Blocked
				DIO_WriteChannel(DIO_ChannelA3,STD_High);//turn on alarm 
				_delay_ms(BLOCK_MODE_TIME);//Halt the system for the given time in (ms)
				DIO_WriteChannel(DIO_ChannelA3,STD_Low);//turn off alarm 
				pass_tries_count = 0; //Clear the count on number of wrong tries
				block_mode_flag = FALSE;//Disable block of runtime
				DIO_WriteChannel(DIO_ChannelD4,STD_Low);//Turn off the led of Blocked
				EEPROM_vWriteByteToAddress(LOGIN_BLOCKED_ADDRESS,FALSE);//write false at blocked location in EEPROM
			}
			
			
			
			L:LCD_Clear();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
			LCD_String("Select mode :\n\r");
			LCD_SetPos(2,1);
			LCD_String("0:Admin 1:Guest\n\r");
			/*Bluetooth_TransmaitString("Select mode : 0:Admin 1:Guest");*/
			while(key_pressed==NOT_PRESSED)//wait for the selection of the mode
			{
				key_pressed = GetKey();
				_delay_ms(20);//if the user pressed any button in keypad save the value in key_pressed
			}
			if ( key_pressed!=CHECK_ADMIN_MODE && key_pressed!=CHECK_GUEST_MODE )
			{
				LCD_Clear();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
				LCD_String("Wrong input.");//Prints error message on the LCD
				key_pressed = NOT_PRESSED;//return the variable that holds the pressed key from keypad to its initial value
				_delay_ms(1000);//Halt the system for the given time in (ms)
				continue;//return to the loop of login #while (login_mode==NO_MODE) 
			}

			u8 pass_counter=0;//counts the entered key of the password from the keypad
			u8 pass[PASS_SIZE]={NOT_STORED,NOT_STORED,NOT_STORED,NOT_STORED};//temporarily hold the entire password that will be entered by the user to be check
			u8 stored_pass[PASS_SIZE]={NOT_STORED,NOT_STORED,NOT_STORED,NOT_STORED};//temporarily hold the entire stored password that is written by the user for the first time
			
			switch(key_pressed)
			{
				/********************************* Admin login **********************************************/
				case CHECK_ADMIN_MODE:
				while(login_mode!=ADMIN)//this loop is to repeat the login for admin in case of wrong password
				{
					key_pressed = NOT_PRESSED;//return the variable that holds the pressed key from keypad to its initial value
					LCD_Clear();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
					LCD_String("Admin mode");
					Bluetooth_TransmaitString("Admin mode\n\r");//print meesage in terminal for login
					LCD_SetPos(2,1);
					LCD_String("Enter Pass:");
					Bluetooth_TransmaitString("Enter Pass:\n\r");
					_delay_ms(200);//Halt the system for the given time in (ms)
					pass_counter=0;//counts the number of entered characters
					while(pass_counter<PASS_SIZE)
					{
						while (rxdata == NOT_PRESSED)//repeat till the user press any key
						{
							rxdata = u8GetTX();//if the user pressed any button in keypad save the value in key_pressed
							_delay_ms(20);
						}
						pass[pass_counter]=rxdata;//add the entered character to the pass array
						LCD_Char(rxdata);//print the entered character
						_delay_ms(CHARACTER_PREVIEW_TIME);//Halt the system for the given time in (ms)
						LCD_SetPos(2,12+pass_counter);//move the cursor of the lcd screen to the previous location
						LCD_Char(PASSWORD_SYMBOL);// to display (Password sign *)
						_delay_ms(100);//Halt the system for the given time in (ms)
						pass_counter++;//increase the password counter that count the characters of the pass
						rxdata = NOT_PRESSED;//return the variable that holds the pressed key from keypad to its initial value
					}
					EEPROM_vReadBlockFromAddress(EEPROM_ADMIN_ADDRESS,stored_pass,PASS_SIZE);//read the stored pass from the EEPROM

					/*compare passwords*/
					if ((ui8ComparePass2(pass,stored_pass,PASS_SIZE)) == TRUE)//in case of right password
					{
						login_mode = ADMIN;//set the login mode to admin mode
						pass_tries_count=0;//clear the counter of wrong tries
						LCD_Clear();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
						LCD_String("Right pass");
						Bluetooth_TransmaitString("Right pass\n\r");
						LCD_SetPos(2,1);
						LCD_String("Admin mode");
						Bluetooth_TransmaitString("Admin mode\n\r");
						_delay_ms(500);//Halt the system for the given time in (ms)
						DIO_WriteChannel(DIO_ChannelD6,STD_High);//turn on the led of admin
						LCD_SetPos(1,0);
						LCD_String("Door opening");
						Bluetooth_TransmaitString("Door opening\n\r");
						
						ServoMotor(90);//door open 			
						_delay_ms(500);
						
						LCD_Clear();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
						
					}
					else//in case of wrong password
					{
						pass_tries_count++;//increase the number of wrong tries to block login if it exceeds the allowed tries
						login_mode = NO_MODE;//set the mode as not logged in
						LCD_Clear();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
						LCD_String("Wrong Pass");
						Bluetooth_TransmaitString("Wrong Pass\n\r");
						LCD_SetPos(2,1);
						LCD_String("Tries left:");
						Bluetooth_TransmaitString("Tries left:\n\r");
						LCD_Char(TRIES_ALLOWED-pass_tries_count+ASCII_ZERO);//print the number of tries left before block mode to be activated
						_delay_ms(1000);//Halt the system for the given time in (ms)
						LCD_Clear();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
						if (pass_tries_count>=TRIES_ALLOWED)//if the condition of the block mode is true
						{
							EEPROM_vWriteByteToAddress(LOGIN_BLOCKED_ADDRESS,TRUE);//write to the EEPROM TRUE to the the block mode address
							block_mode_flag = TRUE;//turn on block mode
							break;//break the loop of admin login #while(login_mode!=ADMIN)# at line 169
						}
					}
				}
				break;//bREAK SWITCH case
				
				
				
				/********************************* Guest login **********************************************/
				case  CHECK_GUEST_MODE:
				while(login_mode != GUEST)
				{
					key_pressed = NOT_PRESSED;//return the variable that holds the pressed key from keypad to its initial value
					LCD_Clear();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
					LCD_String("Guest mode");
					LCD_SetPos(2,1);
					LCD_String("Enter pass:");
					_delay_ms(200);//Halt the system for the given time in (ms)
					pass_counter=0;//counts the number of entered characters
					while(pass_counter<PASS_SIZE)
					{
						while (key_pressed == NOT_PRESSED)//repeat till the user press any key
						{
							key_pressed = GetKey();
							_delay_ms(20);//if the user pressed any button in keypad save the value in key_pressed
						}
						pass[pass_counter]=key_pressed;//add the pressed key to the password string
						LCD_Char(key_pressed);//print the entered character
						_delay_ms(CHARACTER_PREVIEW_TIME);//Halt the system for the given time in (ms)
						LCD_SetPos(2,12+pass_counter);//return the cursor to the location of the previous character to replace it with the password sign
						LCD_Char(PASSWORD_SYMBOL); // to display (Password sign *)
						_delay_ms(100);//Halt the system for the given time in (ms)
						pass_counter++;//increase the password counter that count the characters of the pass
						key_pressed = NOT_PRESSED;//return the variable that holds the pressed key from keypad to its initial value
					}
					EEPROM_vReadBlockFromAddress(EEPROM_GUEST_ADDRESS,stored_pass,PASS_SIZE);//Save the entire password in the EEPROM
					/*compare passwords*/
					if (ui8ComparePass2(pass,stored_pass,PASS_SIZE)==TRUE)//in case of right password
					{
						login_mode = GUEST;
						LCD_Clear();
						LCD_String("Wait for approve");//wait for approve from admin 
						LCD_SetPos(1,0);
						Bluetooth_TransmaitString("Req from guest: 1.OPEN 2.CLOSED\n\r");
						_delay_ms(200);
						
						rxdata = u8GetTX();//wait untill admin approv or reject 
						if (rxdata == '1')
						{
							pass_tries_count=0;//clear the counter of wrong tries
						LCD_Clear();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
						LCD_String("Right pass");
						LCD_SetPos(2,1);
						LCD_String("Guest mode");
						ServoMotor(90);//door open
						
						
						_delay_ms(500);//Halt the system for the given time in (ms)
						DIO_WriteChannel(DIO_ChannelD3,STD_High);//turn the led of gust mode that is connected to the master micro controller on
						LCD_Clear();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
						}else if (rxdata =='2')
						{
							LCD_String("req has been rejected");
							_delay_ms(500);
							pass[pass_counter]=0;//reast all inputs to try again 
							pass_counter=0;
							rxdata = NOT_PRESSED;
							key_pressed = NOT_PRESSED;
							login_mode =NO_MODE;//reset login mode flag 
							goto L;
						}
					}
					else//in case of wrong password
					{
						pass_tries_count++;//increase the number of wrong tries to block login if it exceeds the allowed tries
						login_mode = NO_MODE;//set the mode as not logged in
						LCD_Clear();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
						LCD_String("Wrong pass");
						LCD_SetPos(2,1);
						LCD_String("Tries left:");
						LCD_Char(TRIES_ALLOWED-pass_tries_count+ASCII_ZERO);//print the number of tries left before block mode to be activated
						_delay_ms(1000);//Halt the system for the given time in (ms)
						LCD_Clear();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
						if (pass_tries_count>=TRIES_ALLOWED)//if the condition of the block mode is true
						{
							EEPROM_vWriteByteToAddress(LOGIN_BLOCKED_ADDRESS,TRUE);//write to the EEPROM TRUE to the the block mode address
							block_mode_flag = TRUE;//turn on block mode
							break;//breaks the loop of insert guest password #while(login_mode != GUEST)# line 228
						}//end of if that check if the number of tries exceeds the maximum tries allowed
					}//end of the case of wrong password
				}//end of loop of guest login
				break;//break for CHECK_GUEST_MODE switch case
			}//end of switch
			
		}
		
		/******************************************************************************************************************************************************************/
		u8 show_menu = MAIN_MENU;
		
		while(block_mode_flag!=TRUE)
		{
			key_pressed = 0;//Set the key pressed by the user to its default value
			u8 Value = 0;//save value on another value to connect admin and guest mode together
			switch (show_menu)
			{
				case MAIN_MENU:
				do
				{
					/******************** print main Menu ******************/
					LCD_Clear();
					LCD_String("1:Room1 2:Room2");
					if(login_mode==ADMIN)//check login mode
					{
						Bluetooth_TransmaitString("1:Room1 2:Room2\n\r");
						_delay_ms(100);
						Bluetooth_TransmaitString("3:Room3 4:More\n\r");
						LCD_SetPos(2,1);
						LCD_String("3:Room3 4:More");//this menu options only printed if the logged in user is an admin
					}
					else if(login_mode==GUEST)//check login mode
					{
						LCD_SetPos(2,1);
						LCD_String("3:Room3 4:Room4");//this menu options only printed if the logged in user is a guest
					}
					/*******************************************************/
					
					if (login_mode == GUEST)
					{
						key_pressed = u8GetKeyPressed(login_mode);//wait for the user till key is pressed
						_delay_ms(100);//to avoid the duplication of the pressed key(deboncy)
						if (key_pressed == SELECT_ROOM1)//If key pressed is 1
						{
							show_menu = ROOM1_MENU;//Set the next menu to be shown to room1 menu
							Value = key_pressed;
						}
						else if (key_pressed == SELECT_ROOM2)//If key pressed is 2
						{
							show_menu = ROOM2_MENU;//Set the next menu to be shown to room2 menu
							Value = key_pressed;
						}
						else if (key_pressed == SELECT_ROOM3)//If key pressed is 3
						{
							show_menu = ROOM3_MENU;//Set the next menu to be shown to room3 menu
							Value = key_pressed;
						}
						else if (key_pressed == SELECT_ROOM4)//If key pressed is 4 and the logged in user is guest
						{
							show_menu = ROOM4_MENU;//Set the next menu to be shown to room4 menu
							Value = key_pressed;
						}
						else if(key_pressed != NOT_PRESSED)//show wrong input message if the user pressed wrong key
						{
							LCD_Clear();//remove all previously printed characters on the LCD 
							LCD_String("Wrong input");//print error message
							_delay_ms(500);//Halt the system for the given time in (ms)
							Value = 0;
						}
					}
					else if (login_mode == ADMIN)
					{
						rxdata = u8GetTX(login_mode);//wait till receive value from bluetooth 
						_delay_ms(20);
						if (rxdata == SELECT_ROOM1)//If key pressed is 1
						{
							show_menu = ROOM1_MENU;//Set the next menu to be shown to room1 menu
							Value = rxdata;
						}
						else if (rxdata == SELECT_ROOM2)//If key pressed is 2
						{
							show_menu = ROOM2_MENU;//Set the next menu to be shown to room2 menu
							Value = rxdata;
						}
						else if (rxdata == SELECT_ROOM3)//If key pressed is 3
						{
							show_menu = ROOM3_MENU;//Set the next menu to be shown to room3 menu
							Value = rxdata;
						}
						else if (rxdata == ADMIN_MORE_OPTION)//If key pressed is 4 and the logged in user is admin
						{
							show_menu = MORE_MENU;//Set the next menu to be shown to more menu
							Value = rxdata;
						}
						else if(rxdata != NOT_PRESSED)//show wrong input message if the user pressed wrong key
						{
							LCD_Clear();//remove all previously printed characters on the LCD 
							LCD_String("Wrong input");//print error message
							_delay_ms(500);//Halt the system for the given time in (ms)
							Value = 0;
						}
					}
					
				} while ( ((Value < '1') || (Value > '4')) );//break the loop in case of valid key
				
				break;//End of main menu case
				
				case MORE_MENU:
				do
				{
					/******************** print more Menu ******************/
					LCD_Clear();//remove all previously printed characters on the LCD 
					Bluetooth_TransmaitString("1:Room4    2:TV\n\r");
					_delay_ms(20);
					Bluetooth_TransmaitString("3:AirCond 4:MORE\n\r");
					LCD_String("1:Room4    2:TV ");
					LCD_SetPos(2,1);
					LCD_String("3:AirCond.4:MORE");
					/*******************************************************/
					rxdata = u8GetTX(login_mode);
					
					if (rxdata == SELECT_ROOM4_ADMIN)//If key pressed is 1
					{
						show_menu = ROOM4_MENU;//Set the next menu to be shown to room4 menu
					}
					else if (rxdata == SELECT_TV)//If key pressed is 2
					{
						show_menu = TV_MENU;//Set the next menu to be shown to TV menu
					}
					else if (rxdata == SELECT_AIR_CONDITIONING)//If key pressed is 3
					{
						show_menu = AIRCONDITIONING_MENU;//Set the next menu to be shown to Air conditioning menu
					}
					else if (rxdata == ADMIN_LAST_OPTION)//If key pressed is 4 (RET)
					{
						show_menu = LAST_MENU;//Set the next menu to be shown to main menu
					}

					else if(rxdata != NOT_PRESSED)//show wrong input message if the user pressed wrong key
					{
						LCD_Clear();//remove all previously printed characters on the LCD 
						LCD_String("Wrong input");//print error message
						_delay_ms(500);//Halt the system for the given time in (ms)
					}
				} while (( (rxdata < '1') || (rxdata > '4') ));//break the loop in case of valid key or time is out
				
				break;//End of more menu case
				
				case LAST_MENU:
				do
				{
					/******************** print more Menu ******************/
					Bluetooth_TransmaitString("1:DimLED 2:RET\n\r");
					Bluetooth_TransmaitString("3:DOOR\n\r");
					LCD_Clear();//remove all previously printed characters on the LCD 
					LCD_String("1:DimLED 2:RET");
					LCD_SetPos(2,1);
					LCD_String("3:DOOR ");
					rxdata = u8GetTX(login_mode);
					
					if (rxdata == SELECT_DIMMERLED)//If key pressed is 1
					{
						show_menu = DimmerLED_MENU;//Set the next menu to be shown to Air conditioning menu
					}
					else if (rxdata == DOOR_OPT)//If key pressed is 3
					{
						show_menu=DOOR_MENU;//Set the next menu to be shown to DOOR_MENU
					}
					else if (rxdata == ADMIN_RET_OPTION)//If key pressed is 2(RET)
					{
						show_menu = MAIN_MENU;//Set the next menu to be shown to main menu
					}
					else if(rxdata != NOT_PRESSED)//show wrong input message if the user pressed wrong key
					{
						LCD_Clear();//remove all previously printed characters on the LCD 
						LCD_String("Wrong input");//print error message
						_delay_ms(500);//Halt the system for the given time in (ms)
					}
				} while (( (rxdata < '1') || (rxdata > '3') ));//break the loop in case of valid key
				break; //End of Last Menu case
				
				case AIRCONDITIONING_MENU:
				do
				{
					/******************** print more Menu ******************/
					LCD_Clear();//remove all previously printed characters on the LCD 
					Bluetooth_TransmaitString("1:Set temperature\n\r");
					Bluetooth_TransmaitString("2:Control  3:RET\n\r");
					LCD_String("1:Set temperature ");
					LCD_SetPos(2,1);
					LCD_String("2:Control  3:RET");
					/*******************************************************/
					rxdata = u8GetTX(login_mode);
					
					if (rxdata == SELECT_SET_TEMPERATURE)//If key pressed is 1
					{
						show_menu = TEMPERATURE_MENU;//Set the next menu to be shown to set temperature menu
					}
					else if (rxdata == SELECT_AIR_COND_CTRL)//If key pressed is 2
					{
						show_menu = AIRCOND_CTRL_MENU;//Set the next menu to be shown to air conditioning control menu
					}
					else if (rxdata == SELECT_AIR_COND_RET)//If key pressed is 0
					{
						show_menu = MORE_MENU;//Set the next menu to be shown to more menu
					}
					else if(rxdata != NOT_PRESSED)//show wrong input message if the user pressed wrong key
					{
						LCD_Clear();//remove all previously printed characters on the LCD 
						LCD_String("Wrong input");//print error message
						_delay_ms(500);//Halt the system for the given time in (ms)
					}
				} while (( (rxdata < '1') || (rxdata > '3') ));//break the loop in case of valid key 
				break;//End of air conditioning menu case
				
				case ROOM1_MENU:
				vMenuOption(ROOM1_MENU,login_mode);//call the function that show the menu of room 1
				show_menu = MAIN_MENU;//Set the next menu to be shown to main menu
				break;//End of room1 menu case
				
				case ROOM2_MENU:
				vMenuOption(ROOM2_MENU,login_mode);//call the function that show the menu of room 2
				show_menu = MAIN_MENU;//Set the next menu to be shown to main menu
				break;//End of room2 menu case
				
				case ROOM3_MENU:
				vMenuOption(ROOM3_MENU,login_mode);//call the function that show the menu of room 3
				show_menu = MAIN_MENU;//Set the next menu to be shown to main menu
				break;//End of room3 menu case
				
				case ROOM4_MENU:
				vMenuOption(ROOM4_MENU,login_mode);//call the function that show the menu of room 4
				if (login_mode == GUEST)//in case of guest is logged in
				{
					show_menu = MAIN_MENU;//Set the next menu to be shown to main menu
				}
				else//in case of admin is logged in
				{
					show_menu = MORE_MENU;//Set the next menu to be shown to more menu
				}
				break;//End of room4 menu case
				
				case DimmerLED_MENU:
				brightness = 0;
				while (brightness==0 )//start the loop that asks for the temperature from the user
				{
					InitPWM();//Iint pwm 
					rxdata = NOT_PRESSED;//set the key pressed to the default value
					LCD_Clear();//remove all previously printed characters on the LCD 
					Bluetooth_TransmaitString("Set Brightness:%\n\r");
					LCD_String("Set Brightness:%");//print the format of inserting temperature
					LCD_SetPos(2,0);//move the cursor to the place to write the entered temperature
					
					/*******************************************************************************/
					rxdata = u8GetTX(login_mode);

					if (rxdata > '9')//show wrong input message if the user entered non numeric value
					{
						LCD_Clear();//remove all previously printed characters on the LCD 
						LCD_String("Wrong input");//print error message
						_delay_ms(500);//Halt the system for the given time in (ms)
						continue;//return to #while (temperature==0)
					}
					else//if the value is valid
					{
						LCD_Char(rxdata);//print the value on the lcd
						Dimmer_hundreds = rxdata;//save the entered value
						rxdata = NOT_PRESSED;//set the key pressed to the default value
					}
					/*******************************************************************************/
					rxdata = u8GetTX(login_mode);
					

					if ((rxdata <'0' || rxdata >'9'))//show wrong input message if the user entered non numeric value
					{
						LCD_Clear();//remove all previously printed characters on the LCD 
						LCD_String("Wrong input");//print error message
						_delay_ms(500);//Halt the system for the given time in (ms)
						continue;//repeat the loop that ask for the temperature
					}
					else//if the value is valid
					{
						LCD_Char(rxdata);//print the value on the lcd
						Dimmer_tens = rxdata;//save the entered value
						rxdata = NOT_PRESSED;//set the key pressed to the default value
					}
					
					rxdata = u8GetTX(login_mode);//wait for the user till key is pressed 
					
					if ((rxdata <'0' || rxdata >'9'))//show wrong input message if the user entered non numeric value
					{
						LCD_Clear();//remove all previously printed characters on the LCD 
						LCD_String("Wrong input");//print error message
						_delay_ms(500);//Halt the system for the given time in (ms)
						continue;//repeat the loop that ask for the temperature
					}
					else//if the value is valid
					{
						LCD_Char(rxdata);//print the value on the lcd
						Dimmer_ones = rxdata;//save the entered value
						rxdata = NOT_PRESSED;//set the key pressed to the default value
					}


					brightness = ((Dimmer_hundreds*100) + (Dimmer_tens*10) + (Dimmer_ones));//set the value of the temperature from the given separated values
					
					if (brightness >255){//where 255 max value of 8 bit
						LCD_Clear();
						LCD_String("Invalid Input");
						_delay_ms(500);
						show_menu = DimmerLED_MENU;//set next menu to DimmerLED_MENU

					}else
					{
						InitPWM();
						SetPWMOutPut(brightness);
						LCD_Clear();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
						//show the message
						LCD_String("Brightness Set");
						_delay_ms(500);//Halt the system for the given time in (ms)
						show_menu = LAST_MENU;
						
					}

				}break;
				
				case DOOR_MENU:
				
				do{
					//rxdata = NOT_PRESSED;//set the key pressed to the default value
					key_pressed =NOT_PRESSED;
					LCD_Clear();//remove all previously printed characters on the LCD 
					Bluetooth_TransmaitString("1:open 2:colse\n\r");
					LCD_String("1:open 2:colse");//print the format of inserting temperature
					LCD_SetPos(2,0);//move the cursor to the place to write the entered temperature
					
					/*******************************************************************************/
					rxdata = u8GetTX(login_mode);
					
					/*u8 data = rxdata;*/
					if (rxdata > '2')//show wrong input message if the user entered non numeric value
					{
						LCD_Clear();//remove all previously printed characters on the LCD
						LCD_String("Wrong input");//print error message
						_delay_ms(500);//Halt the system for the given time in (ms)
						continue;//return to #while (temperature==0)
					}
					else if (rxdata == '1')//if the value is valid
					{
						
						LCD_Char(rxdata);
						ServoMotor(0);
						_delay_ms(500);
						ServoMotor(180);
						/*ServoMotor(90);*/
						//LCD_Char("door opened");//print the  on the lcd
						//Bluetooth_TransmaitString("door opened");
						_delay_ms(500);
						rxdata = NOT_PRESSED;//set the key pressed to the default value
						show_menu = LAST_MENU;
						
					}else if(rxdata == '2')
					{
						LCD_Char(rxdata);
						ServoMotor(0);
						_delay_ms(500);
						ServoMotor(180);
						//LCD_Char("door closed");//print the value on the lcd
						//Bluetooth_TransmaitString("door closed");
						_delay_ms(500);
						rxdata = NOT_PRESSED;//set the key pressed to the default value
						show_menu = LAST_MENU;
						
					}
				}while (rxdata >0 && rxdata<3);
				break;
				
				
				
				case TV_MENU:
				vMenuOption(TV_MENU,login_mode);//call the function that show the menu of tv
				show_menu = MORE_MENU;//Set the next menu to be shown to more menu
				break;//End of TV menu case
				
				
				case AIRCOND_CTRL_MENU:
				vMenuOption(AIRCOND_CTRL_MENU,login_mode);//call the function that show the menu of Air conditioning control
				show_menu = AIRCONDITIONING_MENU;//Set the next menu to be shown to air conditioning menu
				break;//End of air conditioning control menu case
				
				
				case TEMPERATURE_MENU:
				temperature = 0;//clear the value of temperature
				while (temperature==0 )//start the loop that asks for the temperature from the user
				{
					key_pressed = NOT_PRESSED;//set the key pressed to the default value
					LCD_Clear();//remove all previously printed characters on the LCD 
					LCD_String("Set temp.:__");//print the format of inserting temperature
					LCD_Char(DEGREES_SYMBOL); // print the symbol of degree
					LCD_Char('C'); // print the C character
					LCD_SetPos(1,11);//move the cursor to the place to write the entered temperature
					_delay_ms(200);//Halt the system for the given time in (ms)
					LCD_SetPos(1,10);
					
					/*******************************************************************************/
					rxdata = u8GetTX();//wait for the user till key is pressed 
					_delay_ms(20);//to avoid the duplication of the pressed key
					

					if (rxdata <'0' || rxdata >'9')//show wrong input message if the user entered non numeric value
					{
						LCD_Clear();//remove all previously printed characters on the LCD 
						LCD_String("Wrong input");//print error message
						Bluetooth_TransmaitString("Wrong input\n\r");
						_delay_ms(500);//Halt the system for the given time in (ms)
						continue;//return to #while (temperature==0)
					}
					else//if the value is valid
					{
						LCD_Char(rxdata);//print the value on the lcd
						temp_tens = rxdata-ASCII_ZERO;//save the entered value
						rxdata = NOT_PRESSED;//set the key pressed to the default value
					}
					/*******************************************************************************/
					rxdata = u8GetTX();//wait for the user till key is pressed 
					_delay_ms(20);//to avoid the duplication of the pressed key
					
					

					if ((rxdata <'0' || rxdata >'9'))//show wrong input message if the user entered non numeric value
					{
						LCD_Clear();//remove all previously printed characters on the LCD 
						LCD_String("Wrong input");//print error message
						Bluetooth_TransmaitString("Wrong input\n\r");
						_delay_ms(500);//Halt the system for the given time in (ms)
						continue;//repeat the loop that ask for the temperature
					}
					else//if the value is valid
					{
						LCD_Char(rxdata);//print the value on the lcd
						temp_ones = rxdata-ASCII_ZERO;//save the entered value
						rxdata = NOT_PRESSED;//set the key pressed to the default value
					}
					temperature = temp_tens*10 + temp_ones;//set the value of the temperature from the given separated values
					_delay_ms(200);
					LCD_Clear();//remove all previously printed characters on the LCD 
					LCD_String("Temperature Set");//show the message
					Bluetooth_TransmaitString("Temperature Set\n\r");
					_delay_ms(500);//Halt the system for the given time in (ms)
					if (advvalue >temperature)//check for req temp and current temp to take action
					{
						DIO_WriteChannel(DIO_ChannelB7,STD_High);//turn on air cond
					}else
					{
						DIO_WriteChannel(DIO_ChannelB7,STD_Low);//turn off air cond
					}
					advvalue=LM35_Read(ADC_Channel0);//init lm35 to display current temp 
					itoa (advvalue,adcstring,10);//fun to convert int to array to display on lcd
					LCD_SetPos(2,0);
					LCD_String("TEMP NOW");
					LCD_SetPos(2,9);
					LCD_String(adcstring);
					_delay_ms(500);
				}
				show_menu = AIRCONDITIONING_MENU;//Set the next menu to be shown to air conditioning menu
				break;//break from switch
			}//End of the switch
		}//End of while that repeats the menu after each successful action till session timeout
	}// end of the main while(1)
}//end of main function

void ExtInt0Fun(void) {//INterupt function to handle Temp when system on 
	advvalue = LM35_Read(ADC_Channel0);
	if (advvalue >= required_temperature ) {
		DIO_WriteChannel(DIO_ChannelB7, STD_High);
		last_air_conditioning_value = AIR_CONDTIONING_ON;
	} else if(advvalue <= required_temperature)
	{
		DIO_WriteChannel(DIO_ChannelB7, STD_Low);
		last_air_conditioning_value = AIR_CONDTIONING_OFF;
	}else if (advvalue <= required_temperature)
	{
		if (last_air_conditioning_value==AIR_CONDTIONING_ON)//in the case of the last saved status of the air conditioning was on
		{
			DIO_WriteChannel(DIO_ChannelB7, STD_High);//turn on the led of the air conditioning
		}
		else if (last_air_conditioning_value==AIR_CONDTIONING_OFF)//in the case of the last saved status of the air conditioning was off
		{
			DIO_WriteChannel(DIO_ChannelB7, STD_Low);//turn off the led of the air conditioning
		}
	}
}

// void ExtInt1Fun(void) //interrupt Function to handle overflow of dimmer led
// {
// 	overflowFlag = 1;
// }

/*ISR(TIMER0_COMP_vect) {
DIO_WriteChannel(DIO_ChannelD2,STD_High);
_delay_ms(500);
DIO_WriteChannel(DIO_ChannelD2,STD_Low);
}*/











