/*
* SPI.c
*
* Created: 10/27/2023 2:57:40 PM
*  Author: user
*/
#include "SPI.h"

void SPI_Init(SPI_ConfigTypes * options){
	switch(options->spiMode){
		case Master:
		DIO_ConfigChannel(SPI_SSPin,Output);
		DIO_ConfigChannel(SPI_MOSIPin,Output);
		DIO_ConfigChannel(SPI_MISOPin,Input);
		DIO_ConfigChannel(SPI_SCKPin,Output);
		SPI->SPCR_Reg.Bits.MSTR_Bit = 1;
		SPI->SPCR_Reg.Bits.SPE_Bit = 1;
		break;
		case Slave:
		DIO_ConfigChannel(SPI_SSPin,Input);
		DIO_ConfigChannel(SPI_MOSIPin,Input);
		DIO_ConfigChannel(SPI_MISOPin,Output);
		DIO_ConfigChannel(SPI_SCKPin,Input);
		SPI->SPCR_Reg.Bits.MSTR_Bit = 0;
		SPI->SPCR_Reg.Bits.SPE_Bit = 1;
		break;
	}
	SPI->SPCR_Reg.AllRegister |= options->spiDord<<5;
	SPI->SPCR_Reg.AllRegister |= options->spiClock;
	SPI->SPSR_Reg.AllRegister |= options->spiDoupleSpeedMode;
}
u8 SPI_TxRx(u8 data){
	SPI->SPDR_Reg = data;
	while(SPI->SPSR_Reg.Bits.SPIF_Bit == 0);
	return SPI->SPDR_Reg;
}
void SPISlaveEnable(DIO_ChannelTypes channelID){
	DIO_ConfigChannel(channelID,Output);
	DIO_WriteChannel(channelID,STD_Low);
}
void SPISlaveDisable(DIO_ChannelTypes channelID){
	DIO_ConfigChannel(channelID,Output);
	DIO_WriteChannel(channelID,STD_High);
}