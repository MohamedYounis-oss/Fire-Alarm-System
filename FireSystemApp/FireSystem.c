#include "FireSystem.h"


void Its_Fine(u16 temp)
{
	
	LCD_GotoWriteString(0, 0, "TMP ");
	LCD_WriteNumber(temp/10);
	LCD_WriteChar('.');
	LCD_WriteNumber(temp%10);
	LCD_WriteString("               ");
	
	LCD_GotoWriteString(1, 6, "FINE");
	
	DIO_WritePin(GREEN_LED, HIGH);
	DIO_WritePin(YELLOW_LED, LOW);
	DIO_WritePin(RED_LED, LOW);
	motor_stop();
}

void Its_Heat(u16 temp, u16 smoke)
{
	LCD_GotoWriteString(0, 0, "TMP ");
	LCD_WriteNumber(temp/10);
	LCD_WriteChar('.');
	LCD_WriteNumber(temp%10);
	LCD_WriteString(" ");
	
	LCD_GotoWriteString(0, 10, "SMK ");
	LCD_WriteNumber(smoke);
	LCD_WriteString("% ");
	
	LCD_GotoWriteString(1, 6, "HEAT");
	
	DIO_WritePin(GREEN_LED, LOW);
	DIO_WritePin(YELLOW_LED, HIGH);
	DIO_WritePin(RED_LED, LOW);
	motor_stop();
}


void Its_Fire(u16 temp, u16 smoke)
{
	LCD_GotoWriteString(0, 0, "TMP ");
	LCD_WriteNumber(temp/10);
	LCD_WriteChar('.');
	LCD_WriteNumber(temp%10);
	LCD_WriteString(" ");
	
	LCD_GotoWriteString(0, 10, "SMK ");
	LCD_WriteNumber(smoke);
	LCD_WriteString("% ");
	
	LCD_GotoWriteString(1, 6, "FIRE");
	
	DIO_WritePin(GREEN_LED, LOW);
	DIO_WritePin(YELLOW_LED, LOW);
	DIO_WritePin(RED_LED, HIGH);
	motor_cw();
}