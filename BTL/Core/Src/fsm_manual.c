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
		Light1(RESET, RESET);
		Light2(RESET, RESET);
		Light3(RESET, RESET);
		Light4(RESET, RESET);
		lcd_display_value(1, 0, set_red);
		if (isButtonPressed(0) == 1) {
			status = MAN_GREEN;
		}
		if (isButtonPressed(1) == 1) {
			set_red++;
			status = SET_RED;
			lcd_display_value(1, 0, set_red);
		}
		break;

	case MAN_GREEN:
		Light1(RESET, SET);
		Light2(RESET, SET);
		Light3(RESET, SET);
		Light4(RESET, SET);
		if (isButtonPressed(0) == 1) {
			status = MAN_YELLOW;
		}
		if (isButtonPressed(1) == 1) {
			set_green++;
			status = SET_GREEN;
		}
		break;

	case MAN_YELLOW:
		Light1(SET, RESET);
		Light2(SET, RESET);
		Light3(SET, RESET);
		Light4(SET, RESET);
		if (isButtonPressed(0) == 1) {
			status = AUTO_RED_GREEN;
		}
		if (isButtonPressed(1) == 1) {
			set_yellow++;
			status = SET_YELLOW;
		}
		break;

	default:
		break;
	}
}
