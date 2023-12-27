#include "DC_MOTOR.h"

void motor_cw()
{	
	DIO_WritePin(MOTOR_IN1, HIGH);
	DIO_WritePin(MOTOR_IN2, LOW);		
}


void motor_ccw()
{	
	DIO_WritePin(MOTOR_IN1, LOW);
	DIO_WritePin(MOTOR_IN2, HIGH);	
}


void motor_stop()
{	
	DIO_WritePin(MOTOR_IN1, LOW);
	DIO_WritePin(MOTOR_IN2, LOW);		
}