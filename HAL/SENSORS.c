#include "SENSORS.h"


u16 LM35_GetTemp()
{
	u16 temp;
	u16 volt = ADC_GetVolt(LM35_CH);
	temp = volt;
	return temp;
}


u8 POT_GetPercent()
{
	u16 adcValue = ADC_Read(POT_CH);
	u8 percent = ((u32)adcValue*100)/1023;
	return percent;
}


u16 PRESSURE_Read()
{
	u16 adcValue = ADC_Read(PRESSURE_CH	);
	u16 pressure = (((u32)(adcValue-40)*1000)/942)+150;
	return pressure;
}