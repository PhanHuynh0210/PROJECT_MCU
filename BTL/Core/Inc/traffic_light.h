/*
 * traffic_light.h
 *
 *  Created on: Nov 19, 2024
 *      Author: phanh
 */

#ifndef INC_TRAFFIC_LIGHT_H_
#define INC_TRAFFIC_LIGHT_H_

#include "global.h"

void Light1(GPIO_PinState D3, GPIO_PinState D4);
void Light2(GPIO_PinState D5, GPIO_PinState D6);
void Light3(GPIO_PinState D7, GPIO_PinState D8);
void Light4(GPIO_PinState D9, GPIO_PinState D10);

#endif /* INC_TRAFFIC_LIGHT_H_ */
