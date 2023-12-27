#include "ADC.h"


void ADC_Init(ADC_Vref vref, ADC_Scaler scaler)
{
	// Vref
	switch(vref)
	{
		case ADC_AREF:
			CLR_BIT(ADMUX, REFS1);
			CLR_BIT(ADMUX, REFS0);
			break;
			
		case ADC_VCC:
			CLR_BIT(ADMUX, REFS1);
			SET_BIT(ADMUX, REFS0);
			break;
			
		case ADC_V256:
			SET_BIT(ADMUX, REFS1);
			SET_BIT(ADMUX, REFS0);
			break;
	}
	
	
	// scaler
	ADCSRA = ADCSRA & 0xf8;	
	ADCSRA = ADCSRA | scaler;	
	
	// Adjusted read to the right
	CLR_BIT(ADMUX, ADLAR);
	
	// ADC Enable
	SET_BIT(ADCSRA, ADEN); 
}


u16 ADC_Read(ADC_Channel ch)
{
	u16 adcValue;
	
	// select channel
	ADMUX = ADMUX & 0xe0;
	ADMUX = ADMUX | ch;
	
	// start conversion
	SET_BIT(ADCSRA, ADSC);
	while(GET_BIT(ADCSRA, ADSC) == 1);
	
	//Reading 
	//adcValue = ADCL | (ADCH<<8); 
	return ADC;
}


u16 ADC_GetVolt(ADC_Channel ch)
{	
	u16 adcValue = ADC_Read(ch);
	u16 volt = ((u32)adcValue*5000)/1024;
	return volt;
}