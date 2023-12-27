#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "DIO_Interface.h"

/************************************************ Pin Config **************************************/

#define KEYPAD_1ST_OUT	PINB0
#define KEYPAD_1ST_IN	PINB4
#define KEYPAD_ROWS		4
#define KEYPAD_COLS		4
#define NO_KEY			'N'

static u8 KeysArr[KEYPAD_ROWS][KEYPAD_COLS] = {{'7', '8', '9', '/'},
											{'4', '5', '6', '*'},
											{'1', '2', '3', '-'},
											{'C', '0', '=', '+'}};

/**************************************************************************************************/


u8 KEYPAD_GetKey(void);
s16 KEYPAD_GetNumber(void);



#endif /* KEYPAD_H_ */