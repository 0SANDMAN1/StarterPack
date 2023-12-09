/*
* TWI_Types.h
*
* Created: 10/28/2023 4:03:44 PM
*  Author: user
*/


#ifndef TWI_TYPES_H_
#define TWI_TYPES_H_

#include "STD_Types.h"

typedef struct{
	u8 TWIE_Bit:1;
	u8 Reserved_Bit:1;
	u8 TWEN_Bit:1;
	u8 TWWC_Bit:1;
	u8 TWSTO_Bit:1;
	u8 TWSTA_Bit:1;
	u8 TWEA_Bit:1;
	u8 TWINT_Bit:1;
}TWCRBits;

typedef union{
	u8 AllRegister;
	TWCRBits Bits;
}TWCRRegisterType;

typedef struct{
	u8 TWBR_Reg;
	u8 TWSR_Reg;
	u8 TWAR_Reg;
	u8 TWDR_Reg;
	u8 RESERVED[50];
	TWCRRegisterType TWCR_Reg;
}TWIRegistersType;


#endif /* TWI_TYPES_H_ */