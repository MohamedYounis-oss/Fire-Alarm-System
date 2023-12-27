#ifndef MEMMAP_H_
#define MEMMAP_H_

/************************************** DIO ******************************/

#define PORTA (*(volatile unsigned char*)0x3b)
#define DDRA (*(volatile unsigned char*)0x3a)
#define PINA (*(volatile unsigned char*)0x39)

#define PORTB (*(volatile unsigned char*)0x38)
#define DDRB (*(volatile unsigned char*)0x37)
#define PINB (*(volatile unsigned char*)0x36)

#define PORTC (*(volatile unsigned char*)0x35)
#define DDRC (*(volatile unsigned char*)0x34)
#define PINC (*(volatile unsigned char*)0x33)

#define PORTD (*(volatile unsigned char*)0x32)
#define DDRD (*(volatile unsigned char*)0x31)
#define PIND (*(volatile unsigned char*)0x30)

/************************************** ADC ******************************/

#define ADMUX (*(volatile unsigned char*)0x27)
#define REFS1	7
#define REFS0	6
#define ADLAR	5


#define ADCSRA (*(volatile unsigned char*)0x26)
#define ADEN	7
#define ADSC	6
#define ADATE	5
#define	ADIF 	4
#define ADIE	3
#define ADPS2	2
#define ADPS1	1
#define ADPS0	0

#define ADCH (*(volatile unsigned char*)0x25)
#define ADCL (*(volatile unsigned char*)0x24)
#define ADC (*(volatile unsigned short*)0x24)

#endif /* MEMMAP_H_ */