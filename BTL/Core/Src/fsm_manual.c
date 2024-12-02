/*
 * fsm_manual.c
 *
 *  Created on: Nov 19, 2024
 *      Author: phanh
 */

#include "fsm_manual.h"

void fsm_manual() {
	switch (status) {
	case MAN_RED_GREEN:
		Light1(SET, SET);
		Light2(SET, RESET);
		Light3(SET, SET);
		Light4(SET, RESET);
		if (isButtonPressed(0) == 1) {
			status = AUTO_RED_GREEN;
			lcd_clear_display();
			setTimer(1, 1000);
		}
		lcd_goto_XY(1, 0);
		lcd_send_string("RED");
		lcd_goto_XY(2, 0);
		lcd_send_string("GREEN");
		if (isButtonPressed(1) == 1) {
			status = MAN_RED_YELLOW;
			lcd_clear_display();
		}
		break;

	case MAN_RED_YELLOW:
		Light1(SET, SET);
		Light2(RESET, SET);
		Light3(SET, SET);
		Light4(RESET, SET);
		lcd_goto_XY(1, 0);
		lcd_send_string("RED");
		lcd_goto_XY(2, 0);
		lcd_send_string("YELLOW");
		if (isButtonPressed(1) == 1) {
			status = MAN_GREEN_RED;
			lcd_clear_display();

		}
		if (isButtonPressed(0) == 1) {
			status = AUTO_RED_YELLOW;
			lcd_clear_display();
			setTimer(1, 1000);
		}

		break;

	case MAN_GREEN_RED:
		Light1(SET, RESET);
		Light2(SET, SET);
		Light3(SET, RESET);
		Light4(SET, SET);
		lcd_goto_XY(1, 0);
		lcd_send_string("GREEN");
		lcd_goto_XY(2, 0);
		lcd_send_string("RED");
		if (isButtonPressed(0) == 1) {
			status = AUTO_GREEN_RED;
			lcd_clear_display();
			setTimer(1, 1000);
		}
		if (isButtonPressed(1) == 1) {
			status = MAN_YELLOW_RED;
			lcd_clear_display();
		}

		break;
	case MAN_YELLOW_RED:
		Light1(RESET, SET);
		Light2(SET, SET);
		Light3(RESET, SET);
		Light4(SET, SET);
		lcd_goto_XY(1, 0);
		lcd_send_string("YELLOW");
		lcd_goto_XY(2, 0);
		lcd_send_string("RED");
		if (isButtonPressed(0) == 1) {
			status = AUTO_YELLOW_RED;
			lcd_clear_display();
			setTimer(1, 1000);
		}
		if (isButtonPressed(1) == 1) {
			status = MAN_RED_GREEN;
			lcd_clear_display();
		}

	default:
		break;
	}
}
