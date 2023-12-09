/*
 * GINT.c
 *
 * Created: 10/6/2023 3:43:42 PM
 *  Author: user
 */ 
#include "GINT.h"

void EnableAllInterrupts(){
	SetBit(GINT_SREG_Reg,GINT_SREG_IBit);
}
void DisableAllInterrupts(){
	ClearBit(GINT_SREG_Reg,GINT_SREG_IBit);
}