#ifndef TWI_Reg
#define TWI_Reg

#include "STD_Types.h"

typedef struct
{
    u8 TWIE_Bit:1;
    u8 Reserved_Bit:1;
    u8 TWEN_Bit:1;
    u8 TWWC_Bit:1;
    u8 TWSTO_Bit:1;
    u8 TWSTA_Bit:1;
    u8 TWEA_Bit:1;
    u8 TWINT_Bit:1;
}TWCRBits;

typedef union
{
    u8 ALLRegister;
    TWCRBits Bits;
}TWCRRegisterType;

typedef struct
{
    u8 TWBR_Reg;
    u8 TWSR_Reg;
    u8 TWAR_Reg;
    u8 TWDR_Reg;
    u8 RESERVED[50];
    TWCRRegisterType TWCR_Reg;

}TWIRegistersType;


#endif