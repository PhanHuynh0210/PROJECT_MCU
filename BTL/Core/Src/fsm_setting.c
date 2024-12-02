/*
 * fsm_setting.c
 *
 *  Created on: Nov 19, 2024
 *      Author: phanh
 */

#include "fsm_setting.h"
#include "fsm_automatic.h"

void fsm_setting() {
	switch (status) {
	case SET_RED:
		Light1(SET, SET);
		Light2(SET, SET);
		Light3(SET, SET);
		Light4(SET, SET);
		lcd_goto_XY(1, 0);
		lcd_send_string("SET RED TIME");
		lcd_goto_XY(2, 0);
		lcd_send_string(" RED TIME: ");
		lcd_display_value(2, 11, set_red);
		if (isButtonPressed(1) == 1) {
			set_red++;
			if (set_red > 99) {
				set_red = 0;
				lcd_clear_display();
			}
		}
		if (isButtonPressed(2) == 1) {
			status = SET_GREEN;
			red_value = set_red;
		}
		if (isButtonPressed(0) == 1) {
			status = SET_GREEN;
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
				lcd_clear_display();
			}
		}
		lcd_goto_XY(1, 0);
		lcd_send_string("SET GREEN TIME");
		lcd_goto_XY(2, 0);
		lcd_send_string(" GREEN TIME: ");
		lcd_display_value(2, 13, set_green);
		if (isButtonPressed(2) == 1) {
			status = SET_YELLOW;
			green_value = set_green;
		}
		if (isButtonPressed(0) == 1) {
			status = SET_YELLOW;
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
				lcd_clear_display();
			}
		}
		lcd_goto_XY(1, 0);
		lcd_send_string("SET YELLOW TIME");
		lcd_goto_XY(2, 0);
		lcd_send_string(" YELLOW TIME: ");
		lcd_display_value(2, 14, set_yellow);
		if (isButtonPressed(2) == 1) {
		    if (set_green + set_yellow != set_red) {
		        status = FIX;
		    } else {
		        status = DONE;
		        yellow_value = set_yellow;
		    }
		}
		if (isButtonPressed(0) == 1) {
			status = SET_RED;
			lcd_clear_display();

		}
		break;
	case FIX:
		Light1(RESET, RESET);
		Light2(RESET, RESET);
		Light3(RESET, RESET);
		Light4(RESET, RESET);
		lcd_goto_XY(1, 0);
		lcd_send_string("CAI MON CHO MA");
		lcd_goto_XY(2, 0);
		lcd_send_string("THANG HY CHO");
		updateCountSet();
		if (count_set >= 3) {
			count_set = 0;
			status = SET_RED;
		}
		break;
	case DONE:
		Light1(RESET, RESET);
		Light2(RESET, RESET);
		Light3(RESET, RESET);
		Light4(RESET, RESET);
		lcd_goto_XY(1, 0);
		lcd_send_string("DONE!!!");
		lcd_goto_XY(2, 0);
		lcd_send_string("THANG HY CHO");
		updateCountSet();
		if (count_set >= 3) {
			count_set = 0;
			status = AUTO_RED_GREEN;
			setTimer(1, 1000);
			lcd_clear_display();
		}
		break;
	default:
		break;
	}
}

