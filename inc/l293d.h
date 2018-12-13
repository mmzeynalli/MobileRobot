/*
 * l293d.h
 *
 *  Created on: Dec 13, 2018
 *      Author: User
 */

#ifndef L293D_H_
#define L293D_H_

#include "stm32f10x.h"

#define PERIPH RCC_APB2Periph_GPIOA
#define PORT GPIOA

#define PIN_MOTOR1_FWD GPIO_Pin_1
#define PIN_MOTOR1_BACK GPIO_Pin_2

#define PIN_MOTOR2_FWD GPIO_Pin_3
#define PIN_MOTOR2_BACK GPIO_Pin_4

void init_motors(void);
void car_move_forward(void);
void car_move_backward(void);
void car_turn_right(void);
void car_turn_left(void);
void car_stop(void);


#endif /* L293D_H_ */
