#ifndef TWI_Reg
#define TWI_Reg

#include "../../Library/STD_Types.h"

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
    u8 TWBR;
    u8 TWSR;
    u8 TWARTWDR;
    u8 RESERVED[50];
    TWCRRegisterType TWCR_Reg;

}TWIRegistersType;


#endif