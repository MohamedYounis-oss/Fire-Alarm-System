#ifndef ADC_H_
#define ADC_H_

#include "MemMap.h"
#include "StdTypes.h"
#include "Utils.h"

typedef enum
{
	ADC_AREF,
	ADC_VCC,
	ADC_V256	
}ADC_Vref;


typedef enum
{
	ADC_SCALER_2=0,
	ADC_SCALER_4=2,
	ADC_SCALER_8,
	ADC_SCALER_16,
	ADC_SCALER_32,
	ADC_SCALER_64,
	ADC_SCALER_128
}ADC_Scaler;

typedef enum
{
	CH_0,
	CH_1,
	CH_2,
	CH_3,
	CH_4,
	CH_5,
	CH_6,
	CH_7,
}ADC_Channel;



void ADC_Init(ADC_Vref vref, ADC_Scaler scaler);
u16 ADC_Read(ADC_Channel ch);
u16 ADC_GetVolt(ADC_Channel ch);


#endif /* ADC_H_ */