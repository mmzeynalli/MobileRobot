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
const double movable_obj_height = 15;
const double immovable_obj_height = 10;

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
		{
			car_stop();

		}
		else if(d == movable_obj_height)
		{

		}
		else if(d == immovable_obj_height)
		{

		}
	}
}
