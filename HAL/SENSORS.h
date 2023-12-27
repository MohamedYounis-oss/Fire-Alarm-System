#ifndef SENSORS_H_
#define SENSORS_H_

#include "ADC.h"

#define LM35_CH			CH_3
#define POT_CH			CH_2
#define PRESSURE_CH		CH_2	

u16 LM35_GetTemp(void);
u8 POT_GetPercent(void);
u16 PRESSURE_Read(void);

#endif /* SENSORS_H_ */