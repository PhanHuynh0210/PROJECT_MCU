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
		lcd_goto_XY(0, 0);
		lcd_send_string("SET RED TIME");
		lcd_goto_XY(1, 0);
		lcd_send_string(" RED TIME: ");
		lcd_display_value(1, 12, set_red);
		if (isButtonPressed(2) == 1) {
			Light1(SET, SET);
			Light2(SET, SET);
			Light3(SET, SET);
			Light4(SET, SET);
			status = MAN_GREEN;
		}

		break;
	case SET_GREEN:
		if (isButtonPressed(1) == 1) {
			set_green++;
			if (set_green > 99) {
				set_green = 0;
			}
		}
		lcd_goto_XY(0, 0);
		lcd_send_string("SET GREEN TIME");
		lcd_goto_XY(1, 0);
		lcd_send_string(" GREEN TIME: ");
		lcd_display_value(1, 13, set_green);
		if (isButtonPressed(2) == 1) {
			Light1(SET, SET);
			Light2(SET, SET);
			Light3(SET, SET);
			Light4(SET, SET);
			status = MAN_YELLOW;
		}

		break;
	case SET_YELLOW:
		if (isButtonPressed(2) == 1) {
			Light1(SET, SET);
			Light2(SET, SET);
			Light3(SET, SET);
			Light4(SET, SET);
			if (set_green + set_yellow != set_red) {
				status = SET_RED;
			} else {
				upvalue();
				setTimer(1, 100);
				status = AUTO_RED_GREEN;
			}
		}
		if (isButtonPressed(1) == 1) {
			set_yellow++;
			if (set_yellow > 99) {
				set_yellow = 0;
			}
		}
		lcd_goto_XY(0, 0);
		lcd_send_string("SET YELLOW TIME");
		lcd_goto_XY(1, 0);
		lcd_send_string(" YELLOW TIME: ");
		lcd_display_value(1, 14, set_yellow);
		break;
	default:
		break;
	}
}

