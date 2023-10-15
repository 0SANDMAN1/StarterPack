/*
* DIO_CFG.h
*
* Created: 9/23/2023 4:33:29 PM
*  Author: user
*/


#ifndef DIO_CFG_H_
#define DIO_CFG_H_

#include "DIO.h"

typedef struct{
	DIO_DirTypes direction;
	STD_LevelTypes Level;
}DIO_PinCfg;

#define PINCOUNT 32

void DIO_Init();

#endif /* DIO_CFG_H_ */