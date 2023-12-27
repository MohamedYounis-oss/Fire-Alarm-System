#include "KeyPad.h"
#include "LCD.h"

u8 KEYPAD_GetKey()
{
	u8 r, c, key = NO_KEY;
	DIO_WritePin(KEYPAD_1ST_OUT, HIGH);
	DIO_WritePin(KEYPAD_1ST_OUT+1, HIGH);
	DIO_WritePin(KEYPAD_1ST_OUT+2, HIGH);
	DIO_WritePin(KEYPAD_1ST_OUT+3, HIGH);
	
	for (r=0; r<KEYPAD_ROWS; r++)
	{
		DIO_WritePin(KEYPAD_1ST_OUT+r, LOW);
		for (c=0; c<KEYPAD_COLS; c++)
		{
			if (DIO_ReadPin(KEYPAD_1ST_IN+c)  == LOW)
			{
				key = KeysArr[r][c];
				while(DIO_ReadPin(KEYPAD_1ST_IN+c)  == LOW);
			}
		}
		DIO_WritePin(KEYPAD_1ST_OUT+r, HIGH);
	}
	return key;
}


void KEYPAD_application_getNumber()
{
	u8 k = NO_KEY;
	u16 num = 0;
	u8 flag = 0;
	 
	k = KEYPAD_GetKey();
	if (k != NO_KEY)
	{
		if (k >='0' && k <='9')
		{
			if (flag)
			{
				LCD_ClearLine(0);
				flag = 0;
			}
			LCD_WriteChar(k);
			num = num*10 + (k-'0');
		}
		else if (k == '=')
		{
			LCD_WriteChar(k);
			LCD_Goto(1, 0);
			LCD_WriteBinary(num);
			LCD_WriteString("              ");
			num = 0;
			LCD_Goto(0, 0);
			flag = 1;
		}
		else if (k == 'C')
		{
			num = 0;
			LCD_ClearScreen();
		}
	}
}


s16 KEYPAD_GetNumber()
{
	u8 key = NO_KEY, negativeFlag=0;
	s16 num = 0;
	
	while (1)
	{
		key = KEYPAD_GetKey();
		if (key >= '0' && key<='9')
		{
			LCD_WriteChar(key);
			num = num*10;
			num = num+(key-'0');
		}
		else if (key == '-')
		{
			LCD_WriteChar('-');
			negativeFlag = 1;
		}
		else if (key == '=')
		{
			if (negativeFlag == 0) return num;
			else return num*-1;
		}
	}
}
