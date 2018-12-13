/*
 * servo.h
 *
 *  Created on: Dec 13, 2018
 *      Author: User
 */

#ifndef SERVO_H_
#define SERVO_H_

#include "stm32f10x.h"

#define PERIPH RCC_APB2Periph_GPIOB
#define PORT GPIOB
#define PIN GPIO_Pin_6

#define PERIOD 1999
#define CLOCK_DIV 100000

void init_servo(void);
void servo_catch(void);

#endif /* SERVO_H_ */
