#include "DIO_Interface.h"
#include "DIO_Private.h"

static void DIO_InitPin(DIO_Pin_type pin, DIO_PinStatus status)
{
	DIO_Port port;
	u8 pinNum;
	
	port = pin/8;
	pinNum = pin-(port*8);
	
	switch (status)
	{
		case OUTPUT: 
			switch (port)
			{
				case PA:
					SET_BIT(DDRA, pinNum);
					CLR_BIT(PORTA, pinNum);
					break;
					
				case PB:
					SET_BIT(DDRB, pinNum);
					CLR_BIT(PORTB, pinNum);
					break;
				
				case PC:
					SET_BIT(DDRC, pinNum);
					CLR_BIT(PORTC, pinNum);
					break;
				
				case PD:
					SET_BIT(DDRD, pinNum);
					CLR_BIT(PORTD, pinNum);
					break;
			}	
			break;
			
		case INPULL:
			switch (port)
			{
				case PA:
					CLR_BIT(DDRA, pinNum);
					SET_BIT(PORTA, pinNum);
					break;
				
				case PB:
					CLR_BIT(DDRB, pinNum);
					SET_BIT(PORTB, pinNum);
					break;
				
				case PC:
					CLR_BIT(DDRC, pinNum);
					SET_BIT(PORTC, pinNum);
					break;
				
				case PD:
					CLR_BIT(DDRD, pinNum);
					SET_BIT(PORTD, pinNum);
					break;
			}
			break;
		
		case INFREE:
			switch (port)
			{
				case PA:
					CLR_BIT(DDRA, pinNum);
					CLR_BIT(PORTA, pinNum);
					break;
				
				case PB:
					CLR_BIT(DDRB, pinNum);
					CLR_BIT(PORTB, pinNum);
					break;
				
				case PC:
					CLR_BIT(DDRC, pinNum);
					CLR_BIT(PORTC, pinNum);
					break;
				
				case PD:
					CLR_BIT(DDRD, pinNum);
					CLR_BIT(PORTD, pinNum);
					break;
			}
			break;
	}
}



void DIO_WritePin(DIO_Pin_type pin, DIO_PinVolt volt)
{
	DIO_Port port;
	u8 pinNum;
	
	port = pin/8;
	pinNum = pin-(port*8);
	
	switch (volt)	
	{
		case LOW:
			switch(port)
			{
				case PA:
					CLR_BIT(PORTA, pinNum);
					break;
					
				case PB:
					CLR_BIT(PORTB, pinNum);
					break;
				
				case PC:
					CLR_BIT(PORTC, pinNum);
					break;
				
				case PD:
					CLR_BIT(PORTD, pinNum);
					break;
			}
			break;
			
		case HIGH:
			switch(port)
			{
				case PA:
					SET_BIT(PORTA, pinNum);
					break;
				
				case PB:
					SET_BIT(PORTB, pinNum);
					break;
				
				case PC:
					SET_BIT(PORTC, pinNum);
					break;
				
				case PD:
					SET_BIT(PORTD, pinNum);
					break;
			}
			break;
	}
}


DIO_PinVolt DIO_ReadPin(DIO_Pin_type pin)
{
		DIO_PinVolt volt;
		
		DIO_Port port;
		u8 pinNum;
		
		port = pin/8;
		pinNum = pin-(port*8);
		
		switch(port)
		{
			case PA:
				if (GET_BIT(PINA, pinNum) == 1)
				{
					volt = HIGH;
				}
				else
				{
					volt = LOW;
				}
				break;
			
			case PB:
				if (GET_BIT(PINB, pinNum) == 1)
				{
					volt = HIGH;
				}
				else
				{
					volt = LOW;
				}
				break;
			
			case PC:
				if (GET_BIT(PINC, pinNum) == 1)
				{
					volt = HIGH;
				}
				else
				{
					volt = LOW;
				}
				break;
			
			case PD:
				if (GET_BIT(PIND, pinNum) == 1)
				{
					volt = HIGH;
				}
				else
				{
					volt = LOW;
				}
				break;
		}
		
		return volt;
}



void DIO_TogglePin(DIO_Pin_type pin)
{
	DIO_Port port;
	u8 pinNum;
	
	port = pin/8;
	pinNum = pin-(port*8);
	
	switch(port)
	{
		case PA:
			Tog_BIT(PORTA, pinNum);
			break;
		
		case PB:
			Tog_BIT(PORTA, pinNum);
			break;
		
		case PC:
			Tog_BIT(PORTA, pinNum);
			break;
		
		case PD:
			Tog_BIT(PORTA, pinNum);
			break;
	}
}


void DIO_WritePort(DIO_Port port, u8 value)
{
	switch(port)	
	{
		case PA:
			PORTA = value;
			break;
			
		case PB:
			PORTB = value;
			break;
		
		case PC:
			PORTC = value;
			break;
		
		case PD:
			PORTD = value;
			break;
	}
}



u8 DIO_ReadPort(DIO_Port port)
{
	u8 value;
	
	switch(port)
	{
		case PA:
			value = PORTA;
			break;
		
		case PB:
			value = PORTB;
			break;
		
		case PC:
			value = PORTC;
			break;
		
		case PD:
			value = PORTD;
			break;
	}
	
	return value;
}

void DIO_Init(void)
{
	DIO_Pin_type pin = PINA0;
	for(pin; pin<TOTAL_PINS; pin++)
	{
		DIO_InitPin(pin, PinsStatusArray[pin]);
	}
}
