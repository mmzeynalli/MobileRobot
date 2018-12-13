/*
 * l293d.c
 *
 *  Created on: Dec 13, 2018
 *      Author: User
 */

#include "l293d.h"

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

void car_move_forward()
{
	GPIO_SetBits(PORT, PIN_MOTOR1_FWD);
	GPIO_SetBits(PORT, PIN_MOTOR2_FWD);
	GPIO_ResetBits(PORT, PIN_MOTOR1_BACK);
	GPIO_ResetBits(PORT, PIN_MOTOR2_BACK);
}

void car_move_backward()
{
	GPIO_SetBits(PORT, PIN_MOTOR1_BACK);
	GPIO_SetBits(PORT, PIN_MOTOR2_BACK);
	GPIO_ResetBits(PORT, PIN_MOTOR1_FWD);
	GPIO_ResetBits(PORT, PIN_MOTOR2_FWD);
}

void car_turn_right()
{
	GPIO_SetBits(PORT, PIN_MOTOR1_FWD);
	GPIO_SetBits(PORT, PIN_MOTOR2_BACK);
	GPIO_ResetBits(PORT, PIN_MOTOR1_BACK);
	GPIO_ResetBits(PORT, PIN_MOTOR2_FWD);
}

void car_turn_left()
{
	GPIO_SetBits(PORT, PIN_MOTOR1_BACK);
	GPIO_SetBits(PORT, PIN_MOTOR2_FWD);
	GPIO_ResetBits(PORT, PIN_MOTOR1_FWD);
	GPIO_ResetBits(PORT, PIN_MOTOR2_BACK);
}

void car_stop()
{
	GPIO_ResetBits(PORT, PIN_MOTOR1_FWD);
	GPIO_ResetBits(PORT, PIN_MOTOR2_FWD);
	GPIO_ResetBits(PORT, PIN_MOTOR1_BACK);
	GPIO_ResetBits(PORT, PIN_MOTOR2_BACK);
}
