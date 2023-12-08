/*
 * DIO.h
 *
 * Created: 9/23/2023 1:48:22 PM
 *  Author: user
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "BitMath.h"
#include "DIO_Reg.h"
#include "DIO_Types.h"
#include "DIO_CFG.h"

void DIO_WriteChannel(DIO_ChannelTypes ChannelId,STD_LevelTypes Level);
STD_LevelTypes DIO_ReadChannel(DIO_ChannelTypes ChannelId);
void DIO_ConfigChannel(DIO_ChannelTypes ChannelId,DIO_DirTypes direction);
void DIO_ToggleChannel(DIO_ChannelTypes ChannelId);
u8 DIO_ReadPort(DIO_PortTypes portId);
void DIO_WritePort(DIO_PortTypes portId,u8 portValue);
void DIO_WriteChannelGroup(DIO_PortTypes portId,u8 portValue,u8 mask);

#endif /* DIO_H_ */