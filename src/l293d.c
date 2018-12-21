/*
 * l293d.c
 *
 *  Created on: Dec 13, 2018
 *      Author: User
 */

#include "l293d.h"
#include "delay.h"

void init_motors()
{
	RCC_APB2PeriphClockCmd(PERIPH, ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;

	GPIO_InitStruct.GPIO_Pin = PIN_MOTOR1_FWD;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP; // push pull mode of alterntv func.
	GPIO_Init(PORT, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin = PIN_MOTOR1_BACK;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP; // push pull mode of alterntv func.
	GPIO_Init(PORT, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin = PIN_MOTOR2_FWD;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP; // push pull mode of alterntv func.
	GPIO_Init(PORT, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin = PIN_MOTOR2_BACK;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP; // push pull mode of alterntv func.
	GPIO_Init(PORT, &GPIO_InitStruct);
}

void move_backward()
{
	GPIO_SetBits(PORT, PIN_MOTOR1_BACK);
	GPIO_SetBits(PORT, PIN_MOTOR2_BACK);
	GPIO_ResetBits(PORT, PIN_MOTOR1_FWD);
	GPIO_ResetBits(PORT, PIN_MOTOR2_FWD);
}

void turn_right()
{
	GPIO_SetBits(PORT, PIN_MOTOR1_FWD);
	GPIO_SetBits(PORT, PIN_MOTOR2_BACK);
	GPIO_ResetBits(PORT, PIN_MOTOR1_BACK);
	GPIO_ResetBits(PORT, PIN_MOTOR2_FWD);
}

void turn_left()
{
	GPIO_SetBits(PORT, PIN_MOTOR1_BACK);
	GPIO_SetBits(PORT, PIN_MOTOR2_FWD);
	GPIO_ResetBits(PORT, PIN_MOTOR1_FWD);
	GPIO_ResetBits(PORT, PIN_MOTOR2_BACK);
}


/* MAIN FUNCTIONS */
void car_move_forward()
{
	GPIO_SetBits(PORT, PIN_MOTOR1_FWD);
	GPIO_SetBits(PORT, PIN_MOTOR2_FWD);
	GPIO_ResetBits(PORT, PIN_MOTOR1_BACK);
	GPIO_ResetBits(PORT, PIN_MOTOR2_BACK);
}

void car_stop()
{
	GPIO_ResetBits(PORT, PIN_MOTOR1_FWD);
	GPIO_ResetBits(PORT, PIN_MOTOR2_FWD);
	GPIO_ResetBits(PORT, PIN_MOTOR1_BACK);
	GPIO_ResetBits(PORT, PIN_MOTOR2_BACK);
}


void car_turn_left() //turn left and stop
{
	turn_left();
	delay_ms(1000);
	car_stop();
}

/* WRITE FUNC TO TURNRIGHT and MOVEBACKWARD */

void car_turn_right()
{

}

void car_move_backwards()
{

}
