/*
 * EEPROM.c
 *
 * Created: 10/30/2023 8:32:27 PM
 *  Author: user
 */ 
#include "EEPROM.h"
#include <avr/io.h>
// void EEPROM_WriteByte(u8 DeviceAdd,u8 LocAdd,u8 data){
// 	u8 wDeviceAdd = DeviceAdd & 0xFE;//to clear the fist bit.
// 	if (TWI_Start() == 0x08)
// 	{
// 		if (TWI_Send(wDeviceAdd) == 0x18)
// 		{
// 			if (TWI_Send(LocAdd) == 0x28)
// 			{
// 				if (TWI_Send(data) == 0x28)
// 				{
// 					TWI_Stop();
// 				}
// 			}
// 		}
// 	}
// }
// u8 EEPROM_ReadByte(u8 DeviceAdd,u8 LocAdd){
// 	u8 wDeviceAdd = DeviceAdd & 0xFE;//to clear the first bit.
// 	u8 rDeviceAdd = DeviceAdd | (1<<0);//to set the first bit
// 	u8 data = 0;
// 	if (TWI_Start() == 0x08)
// 	{
// 		if (TWI_Send(wDeviceAdd) == 0x18)
// 		{
// 			if (TWI_Send(LocAdd) == 0x28)
// 			{
// 				if (TWI_Start() == 0x10)
// 				{
// 					if (TWI_Send(rDeviceAdd) == 0x40)
// 					{
// 						if (TWI_Read_NAck(&data) == 0x58)
// 						{
// 							TWI_Stop();
// 						}
// 					}
// 				}
// 			}
// 		}
// 	}
// 	return data;
// }

void EEPROM_vReadBlockFromAddress(const u16 uiAddress, u8* dist,const u16 size)
{
	/* Wait for completion of previous write */
	while (((EECR & (1 << EEWE))>>EEWE)==1)
	;

	u16 counter = 0;//the counter of bytes that are read

	while (counter < size) //loop until move all bytes to the given array
	{
		/* Set up address register */
		EEAR = uiAddress + counter;
		/* Start EEPROM read by writing EERE */
		EECR |= (1 << EERE);
		/* move data from data register to the array */
		*(dist + counter) = EEDR;

		counter++;//increase the bytes counter
	}
}
void EEPROM_vWriteBlockToAddress(const u16 uiAddress, const u8* uiData,const u16 size)
{
	u16 counter = 0;//Bytes write counter
	while (counter < size)
	{
		/* Wait for completion of previous write process*/
		while (( (EECR & (1 << EEWE) ) >>EEWE ) == 1)
		;
		/* Set up address register */
		EEAR = uiAddress + counter;

		/* Read the byte in the address of EEAR */
		EECR |= (1 << EERE);
		if (EEDR != (*(uiData + counter)))//compare the value read to the value to be written
		{//if they are not equal then write the data
			EEDR = *(uiData + counter);//move the data to EEDR

			/* Write logical one to EEMWE */
			EECR |= (1 << EEMWE);
			/* Start EEPROM write by setting EEWE */
			EECR |= (1 << EEWE);
		}
		else
		{

		}
		counter++;//increase bytes counter
	}
}

u8 EEPROM_ui8ReadByteFromAddress(const u16 u16Address)
{
	/* Wait for completion of previous write */
	while (((EECR & (1 << EEWE))>>EEWE)==1)
	;
	/* Set up address register */
	EEAR = u16Address;
	/* Start EEPROM read by writing EERE */
	EECR |= (1 << EERE);
	/* Return data from data register */
	return EEDR;
}

void EEPROM_vWriteByteToAddress(const u16 uiAddress, const u8 uiData)
{

	/* Wait for completion of previous write process*/
	while ( ( (EECR & (1 << EEWE) ) >>EEWE ) == 1)
	;
	/* Set up address register */
	EEAR = uiAddress;

	/* Read the byte in the address of EEAR */
	EECR |= (1 << EERE);
	if (EEDR != uiData)//compare the value read to the value to be written
	{//if they are not equal then write the data
		EEDR = uiData;//move the data to EEDR

		/* Write logical one to EEMWE */
		EECR |= (1 << EEMWE);
		/* Start EEPROM write by setting EEWE */
		EECR |= (1 << EEWE);
	}
	else
	{

	}

}