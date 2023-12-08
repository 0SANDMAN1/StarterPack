/*
 * IncFile1.h
 *
 * Created: 04/12/2023 11:42:04 pm
 *  Author: amost
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_
#include <avr/io.h>
#include "Cinfig home.h"
#include "STD_MESSAGES.h"
#include "STD_Types.h"
#include "Keypad.h"
#include "SPI.h"
#include "LCD.h"
#include "Bluetooth.h"

u8 ui8ComparePass(const u8* pass1,const u8* pass2,const u8 size);
void vMenuOption(const u8 u8SelectedRoom,const u8 u8LoginMode);
u8 u8GetKeyPressed(const u8 u8LoginMode);
u8 ui8ComparePass2(const u8* pass1, const u8* pass2, const u8 size);
u8 u8GetKeyPressed(const u8 u8LoginMode);
u8 u8GetTX (const u8 TX);
u8 Power_on_off(u8 statues);
#endif /* INCFILE1_H_ */