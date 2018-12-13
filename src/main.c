/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/

#include "delay.h"
#include "hc-sr04.h"
#include "l293d.h"
#include "servo.h"

const double norm_dist = 20;

int main(void)
{
	init_delay();
	init_motors();
	init_distSensor();
	init_servo();

	double d;

	while(1)
	{
		d = read_distance();

		if(d > norm_dist) //if reaches the edge
			car_stop();
		else
		{

		}
	}
}
