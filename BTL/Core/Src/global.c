/*
 * global.c
 *
 *  Created on: Nov 19, 2024
 *      Author: phanh
 */

#include"global.h"

int status = 0;

int red_value;
int green_value;
int yellow_value;

int set_red;
int set_yellow;
int set_green;

void setvalue() {
	red_value = count_R;
	green_value = count_G;
	yellow_value = count_Y;

	set_red = count_R;
	set_yellow = count_Y;
	set_green = count_G;

}

void upvalue() {
	red_value = set_red;
	green_value = set_green;
	yellow_value = set_yellow;
}
