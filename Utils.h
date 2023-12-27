#ifndef UTILS_H_
#define UTILS_H_


#define SET_BIT(reg, bit)	(reg|=1<<bit)
#define CLR_BIT(reg, bit)	(reg&=~(1<<bit))
#define Tog_BIT(reg, bit)	(reg^=1<<bit)
#define GET_BIT(reg, bit)	(1& (reg>>bit))



#define F_CPU	8000000
#include <util/delay.h>


#endif /* UTILS_H_ */