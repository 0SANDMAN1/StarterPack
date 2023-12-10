/*
* Cinfig_home.h
*
* Created: 04/12/2023 3:00:44 pm
*  Author: amost
*/


#ifndef CINFIG HOME_H_
#define CINFIG HOME_H_

#include "STD_Types.h"

#define NOT_STORED   0xFF
#define NOT_SELECTED 0xFF
#define NOT_PRESSED 0


#define AIR_CONDTIONING_ON          (u8)0x01
#define AIR_CONDTIONING_OFF			(u8)0x00


#define BLOCK_MODE_TIME  (u32)20000
#define CHARACTER_PREVIEW_TIME (u16)300
#define DEGREES_SYMBOL		   (u8)0xDF

/*********************************** PIN Configuration ***********************************/
#define PASS_SIZE       (u8)4
#define TRIES_ALLOWED   (u8)3
#define PASSWORD_SYMBOL (u8)'*'
#define ASCII_ZERO      (u8)'0'

#define PASS_NOT_SET (u8)0xFF
#define PASS_SET     (u8)0x01

#define ADMIN_PASS_STATUS_ADDRESS (u16)0X050
#define GUEST_PASS_STATUS_ADDRESS (u16)0X064
#define EEPROM_ADMIN_ADDRESS      (u16)0X014
#define EEPROM_GUEST_ADDRESS      (u16)0X028
#define LOGIN_BLOCKED_ADDRESS     (u16)0X10A
/*****************************************************************************************/

/************************************   Login configurations *****************************/
#define NO_MODE (u8)0
#define ADMIN   (u8)1
#define GUEST   (u8)2
/*****************************************************************************************/

/************************************   Logic values *************************************/
#define FALSE   (u8)0
#define TRUE    (u8)1
/*****************************************************************************************/

#define CHECK_ADMIN_MODE        (u8)'0'
#define CHECK_GUEST_MODE        (u8)'1'

#define SELECT_ROOM1            (u8)'1'
#define SELECT_ROOM2            (u8)'2'
#define SELECT_ROOM3            (u8)'3'
#define SELECT_ROOM4            (u8)'4'
#define ADMIN_MORE_OPTION       (u8)'4'

#define SELECT_ROOM4_ADMIN      (u8)'1'
#define SELECT_TV               (u8)'2'
#define SELECT_AIR_CONDITIONING (u8)'3'
#define ADMIN_LAST_OPTION        (u8)'4'

#define SELECT_DIMMERLED		(u8)'1'
#define ADMIN_RET_OPTION        (u8)'2'
#define SELECT_SET_TEMPERATURE  (u8)'1'
#define SELECT_AIR_COND_CTRL    (u8)'2'
#define SELECT_AIR_COND_RET     (u8)'3'
#define DOOR_OPT                (u8)'3'


/****************************   Show menu codes  *****************************************/
#define MAIN_MENU            (u8)1
#define MORE_MENU            (u8)2
#define ROOM1_MENU           (u8)3
#define ROOM2_MENU           (u8)4
#define ROOM3_MENU           (u8)5
#define ROOM4_MENU           (u8)6
#define TV_MENU              (u8)7
#define AIRCONDITIONING_MENU (u8)8
#define AIRCOND_CTRL_MENU    (u8)9
#define TEMPERATURE_MENU     (u8)10
#define DimmerLED_MENU       (u8)11
#define LAST_MENU			 (u8)12
#define DOOR_MENU			 (u8)13
/*****************************************************************************************/

/*****************************  Ports and pins of input and output pins ******************/
#define ADMIN_LED_PORT (u8)'C'
#define GUEST_LED_PORT (u8)'C'
#define BLOCK_LED_PORT (u8)'C'

#define ADMIN_LED_PIN  (u8)0
#define GUEST_LED_PIN  (u8)1
#define BLOCK_LED_PIN  (u8)2
/*****************************************************************************************/



#endif /* CINFIG HOME_H_ */