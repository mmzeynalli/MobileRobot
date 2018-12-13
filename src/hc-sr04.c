/*
 * hc-sr04.c
 *
 *  Created on: Dec 13, 2018
 *      Author: User
 */

#include "hc-sr04.h"

const double knot = 4 * 0.0171821;

void init_distSensor()
{
	RCC_APB2PeriphClockCmd(PERIPH, ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;

	//trig pin
	GPIO_InitStruct.GPIO_Pin = PIN_TRIG;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP; // push pull mode of alterntv func.
	GPIO_Init(PORT, &GPIO_InitStruct);

	//echo pin
	GPIO_InitStruct.GPIO_Pin = PIN_ECHO;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD; // input pull down
	GPIO_Init(PORT, &GPIO_InitStruct);
}

double read_distance()
{
	uint32_t time;

	// Trigger Pin
	PORT->BRR = PIN_TRIG;
	delay_us(2);

	PORT->BSRR = PIN_TRIG;
	delay_us(10);

	GPIOB->BRR = PIN_TRIG;
	delay_us(2);


	while((PORT->IDR & PIN_ECHO) == 0x00);

	time = 0;

	while((PORT->IDR & PIN_ECHO) != 0x00)
	{
		time++; //calculate echo time
		delay_us(2);
	}

 	 double res = knot * time; //find distance

 	 return res;
}

