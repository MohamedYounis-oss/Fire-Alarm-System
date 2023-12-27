#ifndef LCD_H_
#define LCD_H_

#include "DIO_Interface.h"

#define _4_BIT	1
#define _8_BIT	2


/*********************************** Pin Config *******************************************/
#define LCD_MODE	_4_BIT

#define EN			PINA1
#define RS			PINA0
#define D7			PINA7
#define D6			PINA6
#define D5			PINA5
#define D4			PINA4
#define LCD_PORT	PA

/******************************************************************************************/


void LCD_Init();
void LCD_WriteChar(u8 ch);
void LCD_WriteString(u8* str);
void LCD_WriteNumber(u16 num);
void LCD_WriteBinary(u8 num);
void LCD_Goto(u8 line, u8 cell);
void LCD_writeNumber_In4digits(u16 num);
void LCD_GotoClear(u8 line, u8 cell, u8 cellsNum);
void LCD_GotoWriteString(u8 line, u8 cell, u8* str);
void LCD_GotoWriteNum(u8 line, u8 cell, u16 num);
void LCD_ClearScreen();
void LCD_ClearLine(u8 line);





#endif /* LCD_H_ */