#include "LCD.h"

/***************************************************************************************/
#if LCD_MODE == _8_BIT

static void LCD_WriteCommand(u8 command)
{
	
	DIO_WritePin(RS, LOW);
	DIO_WritePort(LCD_PORT, command);
	
	//*** Triggering **
	DIO_WritePin(EN, HIGH);
	_delay_ms(1);
	DIO_WritePin(EN, LOW);
	//*****************
}

static void LCD_WriteData(u8 data)
{
	
	DIO_WritePin(RS, HIGH);
	DIO_WritePort(LCD_PORT, data);
	
	//*** Triggering **
	DIO_WritePin(EN, HIGH);
	_delay_ms(1);
	DIO_WritePin(EN, LOW);
	//*****************
}

void LCD_Init()
{

	_delay_ms(50);
	LCD_WriteCommand(0x38); // 8-Bit data length / 1 line display / 5*7 font
	LCD_WriteCommand(0x0C);	// entire display on , with a blinking cursor
	LCD_WriteCommand(0x01);
	_delay_ms(1);
	LCD_WriteCommand(0x06); // increases DDram address by 1, no shifting		
}

#elif LCD_MODE == _4_BIT

static void LCD_WriteCommand(u8 command)
{
	
	DIO_WritePin(RS, LOW);
	DIO_WritePin(D7, GET_BIT(command, 7));
	DIO_WritePin(D6, GET_BIT(command, 6));
	DIO_WritePin(D5, GET_BIT(command, 5));
	DIO_WritePin(D4, GET_BIT(command, 4));
	//*** Triggering **
	DIO_WritePin(EN, HIGH);
	_delay_ms(1);
	DIO_WritePin(EN, LOW);
	//*****************
	
	DIO_WritePin(D7, GET_BIT(command, 3));
	DIO_WritePin(D6, GET_BIT(command, 2));
	DIO_WritePin(D5, GET_BIT(command, 1));
	DIO_WritePin(D4, GET_BIT(command, 0));
	//*** Triggering **
	DIO_WritePin(EN, HIGH);
	_delay_ms(1);
	DIO_WritePin(EN, LOW);
	//*****************
}

static void LCD_WriteData(u8 data)
{
	
	DIO_WritePin(RS, HIGH);
	DIO_WritePin(D7, GET_BIT(data, 7));
	DIO_WritePin(D6, GET_BIT(data, 6));
	DIO_WritePin(D5, GET_BIT(data, 5));
	DIO_WritePin(D4, GET_BIT(data, 4));
	//*** Triggering **
	DIO_WritePin(EN, HIGH);
	_delay_ms(1);
	DIO_WritePin(EN, LOW);
	//*****************
	
	DIO_WritePin(D7, GET_BIT(data, 3));
	DIO_WritePin(D6, GET_BIT(data, 2));
	DIO_WritePin(D5, GET_BIT(data, 1));
	DIO_WritePin(D4, GET_BIT(data, 0));
	//*** Triggering **
	DIO_WritePin(EN, HIGH);
	_delay_ms(1);
	DIO_WritePin(EN, LOW);
	//*****************
}

void LCD_Init()
{

	_delay_ms(50);
	LCD_WriteCommand(0x02);
	LCD_WriteCommand(0x28); // 8-Bit data length / 1 line display / 5*7 font
	LCD_WriteCommand(0x0C);	// entire display on , with a blinking cursor
	LCD_WriteCommand(0x01);
	_delay_ms(1);
	LCD_WriteCommand(0x06); // increases DDram address by 1, no shifting		
}

#endif

/****************************************************************************************************/

void LCD_WriteChar(u8 ch)
{
	LCD_WriteData(ch);
}

void LCD_WriteString(u8* str)
{
	for (int i=0; str[i]; i++)
	{
		LCD_WriteChar(str[i]);
	}
}



void LCD_WriteNumber(u16 num)
{
	if (num == 0)
	{
		LCD_WriteChar('0');
		return;
	}
	
	if (num <0)
	{
		LCD_WriteChar('-');
		num = num*-1;
		
	}
	
	u16 temp = num;
	u8 str[20];
	u8 i = 0;
	
	while (temp)
	{
		str[i] = (temp%10) + '0';
		temp = temp/10;	
		i++;
	}
	
	for (s8 j=i-1; j>=0; j--)
	{
		LCD_WriteChar(str[j]);
	}
}


void LCD_WriteBinary(u8 num)
{
	
	for (s8 i=7; i>=0; i--)
	{
		if ((num>>i)&1) LCD_WriteChar('1');
		else LCD_WriteChar('0');
	}
}


void LCD_Goto(u8 line, u8 cell)
{
	u8 data;
	if (line == 0)
	{
		LCD_WriteCommand(0x80 + cell);
	}
	else if (line == 1)
	{
		LCD_WriteCommand(0x80 + 0x40 + cell);
	}
}


void LCD_writeNumber_In4digits(u16 num)
{
	
	LCD_WriteChar(((num%10000)/1000)+'0');
	LCD_WriteChar(((num%1000)/100)+'0');
	LCD_WriteChar(((num%100)/10)+'0');
	LCD_WriteChar(((num%10)/1)+'0');
}

void LCD_GotoClear(u8 line, u8 cell, u8 cellsNum)
{
	LCD_Goto(line, cell);
	for (int i=0; i<cellsNum; i++)
	{
		LCD_WriteChar(' ');
	}
}


void LCD_GotoWriteString(u8 line, u8 cell, u8* str)
{
	LCD_Goto(line, cell);
	LCD_WriteString(str);
}

void LCD_GotoWriteNum(u8 line, u8 cell, u16 num)
{
	LCD_Goto(line, cell);
	LCD_WriteNumber(num);
}


void LCD_ClearScreen()
{
	LCD_WriteCommand(0x01);
}

void LCD_ClearLine(u8 line)
{
	LCD_GotoClear(line, 0, 15);
	LCD_Goto(line, 0);
}