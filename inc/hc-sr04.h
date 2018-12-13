/*
 * hc-sr04.h
 *
 *  Created on: Dec 13, 2018
 *      Author: User
 */

#ifndef HC_SR04_H_
#define HC_SR04_H_

#include "stm32f10x.h"

#define PERIPH RCC_APB2Periph_GPIOB
#define PORT GPIOB
#define PIN_TRIG GPIO_Pin_8
#define PIN_ECHO GPIO_Pin_9

void void init_distSensor(void);
double read_distance(void);


#endif /* HC_SR04_H_ */
