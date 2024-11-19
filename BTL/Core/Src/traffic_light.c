/*
 * traffic_light.c
 *
 *  Created on: Nov 19, 2024
 *      Author: phanh
 */

#include "traffic_light.h"

void Light1(GPIO_PinState D3, GPIO_PinState D4) {
	HAL_GPIO_WritePin(GPIOB, D3_Pin, D3);
	HAL_GPIO_WritePin(GPIOB, D4_Pin, D4);
}

void Light2(GPIO_PinState D5, GPIO_PinState D6) {
	HAL_GPIO_WritePin(GPIOB, D5_Pin, D5);
	HAL_GPIO_WritePin(GPIOB, D6_Pin, D6);
}
void Light3(GPIO_PinState D7, GPIO_PinState D8) {
	HAL_GPIO_WritePin(GPIOA, D7_Pin, D7);
	HAL_GPIO_WritePin(GPIOA, D8_Pin, D8);
}

void Light4(GPIO_PinState D9, GPIO_PinState D10) {
	HAL_GPIO_WritePin(GPIOC, D9_Pin, D9);
	HAL_GPIO_WritePin(GPIOB, D10_Pin, D10);
}
