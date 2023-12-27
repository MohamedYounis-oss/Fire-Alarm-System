#ifndef FIRESYSTEM_H_
#define FIRESYSTEM_H_


 #include "DIO_Interface.h"
 #include "ADC.h"
 #include "DC_MOTOR.h"
 #include "LCD.h"
 #include "KeyPad.h"
 #include "SENSORS.h"
 
 /************************************ PIN CONFIGURATIONS **************************************/
 
 #define GREEN_LED		PINC0
 #define YELLOW_LED		PINC1
 #define RED_LED		PINC2
 
//LCD, KEYPAD, LM35, DC_Motor and POT .. All has been defined in their own driver
/**********************************************************************************************/

typedef enum
{
	FINE,
	HEAT,
	FIRE,
	DEFAULT
	
}TEMP_CASE_type;


void Its_Fine(u16 temp);
void Its_Heat(u16 temp, u16 smoke);
void Its_Fire(u16 temp, u16 smoke);



#endif /* FIRESYSTEM_H_ */