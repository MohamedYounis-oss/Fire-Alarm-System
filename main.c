#include "MemMap.h"
#include "Utils.h"
#include "StdTypes.h"
#include "DIO_Interface.h"
#include "SEGMENT.h"
#include "DC_MOTOR.h"
#include "LCD.h"
#include "KeyPad.h"
#include "ADC.h"
#include "SENSORS.h"
#include "FireSystem.h"


int main(void)
{
	DIO_Init();
	LCD_Init();
	ADC_Init(ADC_VCC, ADC_SCALER_64);
	
	
	u16 temp, smoke;
	u8 password = 1555;
	u8 key, num;
	TEMP_CASE_type tempCase = DEFAULT;
	
	
    while (1) 
    {
		temp = LM35_GetTemp();
		smoke = POT_GetPercent();
		
		
		
		if (temp >= 450 && smoke <50 && tempCase != FIRE)
		{
			tempCase = HEAT;
			Its_Heat(temp, smoke);
		}
		
		else if ((temp >= 450 && smoke >= 50) | tempCase == FIRE)
		{
			tempCase = FIRE;
			Its_Fire(temp, smoke);
		}
		
		else if (temp < 400 && tempCase != FIRE)
		{
			tempCase = FINE;
			Its_Fine(temp);
		}
		else if (temp <450 && temp >=400)
		{
			if (tempCase == FINE || tempCase == DEFAULT)
			{
				Its_Fine(temp);
			} 
			else if (tempCase == HEAT)
			{
				Its_Heat(temp, smoke);
			}
		}
		
		if (tempCase == FIRE)
		{
			key = KEYPAD_GetKey();
			if (key != NO_KEY)
			{
				LCD_ClearScreen();
				LCD_WriteString("Password: ");
				
				num = KEYPAD_GetNumber();
				if (num == password)
				{
					tempCase = DEFAULT;
					
				}
				else
				{
					LCD_GotoWriteString(1, 0, "Wrong Password");
					_delay_ms(1000);
					LCD_ClearScreen();
				}
			}
		}
		
		
    }
}

