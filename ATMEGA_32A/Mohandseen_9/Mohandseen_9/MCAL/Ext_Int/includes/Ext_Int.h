/*
 * Ext_Int.h
 *
 * Created: 10/6/2023 3:56:30 PM
 *  Author: user
 */ 


#ifndef EXT_INT_H_
#define EXT_INT_H_

#include "Ext_Int_Reg.h"
#include "Ext_Int_Types.h"
#include "BitMath.h"
#include <avr/interrupt.h>

void Ext_Interrupt_Enable(Ext_Int_Types extIntId);
void Ext_Interrupt_Disable(Ext_Int_Types extIntId);
void Ext_Interrupt_Sncontrol(Ext_Int_Types extIntId,Ext_Int_Sncontrol mode);
void Ext_Interrupt_SetCallBack(Ext_Int_Types extIntId,void (*ExtIntCopyPtr)(void));

#endif /* EXT_INT_H_ */