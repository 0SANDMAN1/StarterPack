/*
* SPI_Types.h
*
* Created: 10/27/2023 2:57:29 PM
*  Author: user
*/


#ifndef SPI_TYPES_H_
#define SPI_TYPES_H_

#include "STD_Types.h"

typedef struct{
	u8 SPR_Bit:2;
	u8 CPHA_Bit:1;
	u8 CPOL_Bit:1;
	u8 MSTR_Bit:1;
	u8 DORD_Bit:1;
	u8 SPE_Bit:1;
	u8 SPIE_Bit:1;
}SPCR_BitsType;

typedef struct{
	u8 SPI2X_Bit:1;
	u8 RESERVED_Bit:5;
	u8 WCOL_Bit:1;
	u8 SPIF_Bit:1;
}SPSR_BitsType;

typedef union{
	u8 AllRegister;
	SPCR_BitsType Bits;
}SPCR_RegisterType;

typedef union{
	u8 AllRegister;
	SPSR_BitsType Bits;
}SPSR_RegisterType;

typedef struct{
	SPCR_RegisterType SPCR_Reg;
	SPSR_RegisterType SPSR_Reg;
	u8 SPDR_Reg;
}SPI_Registers;

typedef enum{
	Slave=0,
	Master
}SPIModeTypes;

typedef enum{
	MSB=0,
	LSB
}SPIDORDTypes;

typedef enum{
	SPIClock_4=0,
	SPIClock_16,
	SPIClock_64,
	SPIClock_128
}SPIClockTypes;

typedef enum{
	SPIDoupleSpeedDisable=0,
	SPIDoupleSpeedEnable
}SPIDoupleSpeedTypes;

typedef struct{
	SPIModeTypes spiMode;
	SPIDORDTypes spiDord;
	SPIClockTypes spiClock;
	SPIDoupleSpeedTypes spiDoupleSpeedMode;
}SPI_ConfigTypes;


#endif /* SPI_TYPES_H_ */