/*
 * EEPROM.h
 *
 * Created: 10/30/2023 8:32:14 PM
 *  Author: user
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "TWI.h"

//void EEPROM_WriteByte(u8 DeviceAdd,u8 LocAdd,u8 data);
//u8 EEPROM_ReadByte(u8 DeviceAdd,u8 LocAdd);
void EEPROM_vReadBlockFromAddress(const u16 u16Address, u8* dist,const u16 size);
void EEPROM_vWriteBlockToAddress(const u16 u16Address, const u8* u8Data,const u16 size);
u8 EEPROM_ui8ReadByteFromAddress(const u16 u16Address);
void EEPROM_vWriteByteToAddress(const u16 u16Address, const u8 u8Data);

#endif /* EEPROM_H_ */