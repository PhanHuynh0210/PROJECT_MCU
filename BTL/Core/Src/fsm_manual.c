/*
 * fsm_manual.c
 *
 *  Created on: Nov 19, 2024
 *      Author: phanh
 */

#include "fsm_manual.h"

void fsm_manual() {
	switch (status) {
	case MAN_RED:
		Light1(SET, SET);
		Light2(SET, SET);
		Light3(SET, SET);
		Light4(SET, SET);
		lcd_goto_XY(1, 0);
		lcd_send_string("SET RED TIME");
		lcd_goto_XY(2, 0);
		lcd_send_string(" RED TIME: ");
		lcd_display_value(2, 12, set_red);
		if (isButtonPressed(0) == 1) {
			status = MAN_GREEN;
		}
		if (isButtonPressed(1) == 1) {
			set_red++;
			status = SET_RED;
			lcd_goto_XY(1, 0);
			lcd_send_string("SET RED TIME");
			lcd_goto_XY(2, 0);
			lcd_send_string(" RED TIME: ");
			lcd_display_value(2, 12, set_red);
		}
		break;

	case MAN_GREEN:
		Light1(SET, RESET);
		Light2(SET, RESET);
		Light3(SET, RESET);
		Light4(SET, RESET);
		lcd_goto_XY(1, 0);
		lcd_send_string("SET GREEN TIME");
		lcd_goto_XY(2, 0);
		lcd_send_string(" GREEN TIME: ");
		lcd_display_value(2, 13, set_green);
		if (isButtonPressed(0) == 1) {
			status = MAN_YELLOW;
		}
		if (isButtonPressed(1) == 1) {
			set_green++;
			status = SET_GREEN;
			lcd_goto_XY(1, 0);
			lcd_send_string("SET GREEN TIME");
			lcd_goto_XY(2, 0);
			lcd_send_string(" GREEN TIME: ");
			lcd_display_value(2, 13, set_green);
		}
		break;

	case MAN_YELLOW:
		Light1(RESET, SET);
		Light2(RESET, SET);
		Light3(RESET, SET);
		Light4(RESET, SET);
		lcd_goto_XY(1, 0);
		lcd_send_string("SET YELLOW TIME");
		lcd_goto_XY(2, 0);
		lcd_send_string(" YELLOW TIME: ");
		lcd_display_value(2, 14, set_yellow);
		if (isButtonPressed(0) == 1) {
			status = AUTO_RED_GREEN;
		}
		if (isButtonPressed(1) == 1) {
			set_yellow++;
			status = SET_YELLOW;
			lcd_goto_XY(1, 0);
			lcd_send_string("SET YELLOW TIME");
			lcd_goto_XY(2, 0);
			lcd_send_string(" YELLOW TIME: ");
			lcd_display_value(2, 14, set_yellow);
		}
		break;

	default:
		break;
	}
}
