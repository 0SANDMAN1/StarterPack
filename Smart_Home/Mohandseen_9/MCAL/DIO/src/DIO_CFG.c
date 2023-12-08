/*
* DIO_CFG.c
*
* Created: 9/23/2023 4:35:25 PM
*  Author: user
*/
#include "DIO_CFG.h"


DIO_PinCfg PinCfg[] = {
	//PORTA
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	
	//PORTB
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	
	//PORC
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	
	//PORTD
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High}
};

void DIO_Init(){
	DIO_PortTypes Portx;
	DIO_ChannelTypes BitNo;
	DIO_ChannelTypes count = DIO_ChannelA0;
	
	for (count=DIO_ChannelA0;count<PINCOUNT;count++)
	{
		Portx = count/8;
		BitNo = count%8;
		switch(Portx){
			case DIO_PortA:
			if (PinCfg[count].direction == Output)
			{
				SetBit(DDRA_Reg,BitNo);
			}
			else
			{
				ClearBit(DDRA_Reg,BitNo);
			}
			break;
			
			case DIO_PortB:
			if (PinCfg[count].direction == Output)
			{
				SetBit(DDRB_Reg,BitNo);
			}
			else
			{
				ClearBit(DDRB_Reg,BitNo);
			}
			break;
			
			case DIO_PortC:
			if (PinCfg[count].direction == Output)
			{
				SetBit(DDRC_Reg,BitNo);
			}
			else
			{
				ClearBit(DDRC_Reg,BitNo);
			}
			break;
			
			case DIO_PortD:
			if (PinCfg[count].direction == Output)
			{
				SetBit(DDRD_Reg,BitNo);
			}
			else
			{
				ClearBit(DDRD_Reg,BitNo);
			}
			break;
		}
	}
	
}