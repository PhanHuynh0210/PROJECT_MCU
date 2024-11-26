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
		lcd_goto_XY(1, 0);
		lcd_send_string("SET RED TIME");
		lcd_goto_XY(2, 0);
		lcd_send_string(" RED TIME: ");
		lcd_display_value(2, 12, set_red);
		if (isButtonPressed(2) == 1) {
			Light1(RESET, RESET);
			Light2(RESET, RESET);
			Light3(RESET, RESET);
			Light4(RESET, RESET);
			status = MAN_GREEN;
		}

		break;
	case SET_GREEN:
		Light1(SET, RESET);
		Light2(SET, RESET);
		Light3(SET, RESET);
		Light4(SET, RESET);
		if (isButtonPressed(1) == 1) {
			set_green++;
			if (set_green > 99) {
				set_green = 0;
			}
		}
		lcd_goto_XY(1, 0);
		lcd_send_string("SET GREEN TIME");
		lcd_goto_XY(2, 0);
		lcd_send_string(" GREEN TIME: ");
		lcd_display_value(2, 13, set_green);
		if (isButtonPressed(2) == 1) {
			Light1(RESET, RESET);
			Light2(RESET, RESET);
			Light3(RESET, RESET);
			Light4(RESET, RESET);
			status = MAN_YELLOW;
		}
		break;
	case SET_YELLOW:
		Light1(RESET, SET);
		Light2(RESET, SET);
		Light3(RESET, SET);
		Light4(RESET, SET);
		if (isButtonPressed(1) == 1) {
			set_yellow++;
			if (set_yellow > 99) {
				set_yellow = 0;
			}
		}
		lcd_goto_XY(1, 0);
		lcd_send_string("SET YELLOW TIME");
		lcd_goto_XY(2, 0);
		lcd_send_string(" YELLOW TIME: ");
		lcd_display_value(2, 14, set_yellow);

		if (isButtonPressed(2) == 1) {
			Light1(RESET, RESET);
			Light2(RESET, RESET);
			Light3(RESET, RESET);
			Light4(RESET, RESET);
			if (set_green + set_yellow != set_red) {
				lcd_clear_display();
				lcd_goto_XY(1, 0);
				lcd_send_string("cai mon cho ma");
				lcd_goto_XY(2, 0);
				lcd_send_string("d hoc nua ");
				if (timer_flag[2] == 1) {
					status = SET_RED;
					setTimer(2,3000);
				}
			} else {
				status = AUTO_RED_GREEN;
				setTimer(1, 1000);
				lcd_clear_display();
				Light1(RESET, RESET);
				Light2(RESET, RESET);
				Light3(RESET, RESET);
				Light4(RESET, RESET);
				upvalue();
			}
		}
		break;
	default:
		break;
	}
}

