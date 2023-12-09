/*
* ADC_Types.h
*
* Created: 10/7/2023 3:04:03 PM
*  Author: user
*/


#ifndef ADC_TYPES_H_
#define ADC_TYPES_H_

#include "STD_Types.h"

typedef enum{
	ADC_Channel0=0,
	ADC_Channel1,
	ADC_Channel2,
	ADC_Channel3,
	ADC_Channel4,
	ADC_Channel5,
	ADC_Channel6,
	ADC_Channel7
}ADC_ChannelTypes;

typedef enum{
	ADC_Prescaler2=1,
	ADC_Prescaler4,
	ADC_Prescaler8,
	ADC_Prescaler16,
	ADC_Prescaler32,
	ADC_Prescaler64,
	ADC_Prescaler128
}ADC_PrescalerTypes;

typedef enum{
	ADC_Vref_AREF=0,
	ADC_Vref_AVCC,
	ADC_Vref_Reserved,
	ADC_Vref_Internal
}ADC_VrefTypes;

typedef struct{
	ADC_VrefTypes adcVref;
	ADC_PrescalerTypes adcClock;
}ADC_InitTypes;

typedef struct{
	u8 ADC_ADPS_Bit:3;
	u8 ADC_ADIE_Bit:1;
	u8 ADC_ADIF_Bit:1;
	u8 ADC_ADATE_Bit:1;
	u8 ADC_ADSC_Bit:1;
	u8 ADC_ADEN_Bit:1;
}ADC_ADCSRA_Bits;

typedef union{
	u8 AllRegister;
	ADC_ADCSRA_Bits Bits;
}ADC_ADCSRA_Register;

typedef struct{
	u8 ADC_ADCL_Reg;
	u8 ADC_ADCH_Reg;
	ADC_ADCSRA_Register ADC_ADCSRA_Reg;
	u8 ADC_ADMUX_Reg;
}ADC_Registers;

#endif /* ADC_TYPES_H_ */