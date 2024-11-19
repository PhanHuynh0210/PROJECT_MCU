/*
 * fsm_setting.c
 *
 *  Created on: Nov 19, 2024
 *      Author: phanh
 */


#include "fsm_setting.h"

void fsm_setting() {
	switch (status) {
	case SET_RED:
		if (isButtonPressed(1) == 1) {
			set_red++;
			if (set_red > 99) {
				set_red = 0;
			}
		}
		if (timer_flag[6] == 1) {

			setTimer(6, 25);
		}
		if (isButtonPressed(2) == 1) {

			status = SET_GREEN;
		}

		break;
	case SET_GREEN:
		if (isButtonPressed(1) == 1) {
			set_green++;
			if (set_green > 99) {
				set_green = 0;
			}
		}
		if (timer_flag[6] == 1) {

			setTimer(6, 25);
		}
		if (isButtonPressed(2) == 1) {

			status = SET_YELLOW;
		}

		break;
	case SET_YELLOW:
		if (isButtonPressed(2) == 1) {

			if (set_green + set_yellow != set_red) {
				status = SET_RED;
			} else {
				upvalue();
				setTimer(1, 100);
				setTimer(6, 25);
				status = AUTO_RED_GREEN;
			}
		}
		if (isButtonPressed(1) == 1) {
			set_yellow++;
			if (set_yellow > 99) {
				set_yellow = 0;
			}
		}
		if (timer_flag[6] == 1) {

			setTimer(6, 25);
		}

		break;
	default:
		break;
	}
}

