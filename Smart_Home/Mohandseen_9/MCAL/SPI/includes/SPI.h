/*
 * SPI.h
 *
 * Created: 10/27/2023 2:56:33 PM
 *  Author: user
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "SPI_Reg.h"

void SPI_Init(SPI_ConfigTypes * options);
u8 SPI_TxRx(u8 data);
void SPISlaveEnable(DIO_ChannelTypes channelID);
void SPISlaveDisable(DIO_ChannelTypes channelID);

#endif /* SPI_H_ */