/*
 * servo.c
 *
 *  Created on: Dec 13, 2018
 *      Author: User
 */

#include "servo.h"

TIM_TimeBaseInitTypeDef timer;
TIM_OCInitTypeDef pwm;

void init_servo()
{
	 RCC_APB2PeriphClockCmd(PERIPH, ENABLE);
	 GPIO_InitTypeDef GPIO_InitStruct;

	 GPIO_InitStruct.GPIO_Pin = PIN;
	 GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	 GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP; // push pull mode of alterntv func.
	 GPIO_Init(PORT, &GPIO_InitStruct);

	 RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);

	 initTimer();
}

void servo_catch(int angle)
{
	 TIM_OCStructInit(&pwm);
	 pwm.TIM_OCMode = TIM_OCMode_PWM2;
	 pwm.TIM_OutputState = TIM_OutputState_Enable;
//!!!!!!!!!!!	 pwm.TIM_Pulse = bucaq;
	 pwm.TIM_OCPolarity = TIM_OCPolarity_Low;

	 TIM_OC1Init(TIM4, &pwm);
	 TIM_Cmd(TIM4, ENABLE);

}


void initTimer() {

	 TIM_TimeBaseStructInit(&timer);
	 timer.TIM_Prescaler = (SystemCoreClock / CLOCK_DIV) - 1;
	 timer.TIM_Period = PERIOD;
	 timer.TIM_ClockDivision = TIM_CKD_DIV1;
	 timer.TIM_CounterMode = TIM_CounterMode_Up;
	 TIM_TimeBaseInit(TIM4, &timer);

}
