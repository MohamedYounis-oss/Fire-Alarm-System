#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "DIO_Interface.h"

/*********************** PIN CONFIG ****************/
#define MOTOR_IN1 PINC3
#define MOTOR_IN2 PINC4

/***************************************************/


void motor_cw();
void motor_ccw();
void motor_stop();


#endif /* DC_MOTOR_H_ */