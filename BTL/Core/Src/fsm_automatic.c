/*
 * fsm_automatic.c
 *
 *  Created on: Nov 19, 2024
 *      Author: phanh
 */

#include "fsm_automatic.h"

int count_set;
int toggle_en;
int seg1;
int seg2;

void set() {
	count_set = 0;
	toggle_en = 0;
	seg1 = 0;
	seg2 = 0;
}

void updateCountSet() {
	if (timer_flag[1] == 1) {
		count_set++;
		setTimer(1, 100);
	}
}


void fsm_auto_run() {
	switch (status) {
	case INIT:
		Light1(SET, SET);
		Light2(SET, SET);
		Light3(SET, SET);
		Light4(SET, SET);
		setTimer(1, 100);
		setTimer(6, 25);
		set();
        lcd_clear_display();
		status = AUTO_RED_GREEN;
		break;

	case AUTO_RED_GREEN:
		Light1(RESET, RESET);
		Light2(RESET, SET);
		Light3(RESET, RESET);
		Light4(RESET, SET);

		seg1 = red_value - count_set;
		seg2 = green_value - count_set;
		lcd_display_value(0, 0, seg1);
		lcd_display_value(1, 0, seg2);

		updateCountSet();
		if (count_set >= red_value - yellow_value) {
			count_set = 0;
			status = AUTO_RED_YELLOW;
		}
		if (isButtonPressed(0) == 1) {
			set();
			status = MAN_RED;
			Light1(SET, SET);
			Light2(SET, SET);
			Light3(SET, SET);
			Light4(SET, SET);
		}
		break;

	case AUTO_RED_YELLOW:
		Light1(RESET, RESET);
		Light2(SET, RESET);
		Light3(RESET, RESET);
		Light4(SET, RESET);

		seg1 = yellow_value - count_set;
		seg2 = yellow_value - count_set;
		lcd_display_value(0, 0, seg1);
		lcd_display_value(1, 0, seg2);

		updateCountSet();
		if (count_set >= red_value - green_value) {
			count_set = 0;
			status = AUTO_GREEN_RED;
		}
		if (isButtonPressed(0) == 1) {
			set();
			status = MAN_RED;
			Light1(SET, SET);
			Light2(SET, SET);
			Light3(SET, SET);
			Light4(SET, SET);
		}
		break;

	case AUTO_GREEN_RED:
		Light1(RESET, SET);
		Light2(RESET, RESET);
		Light3(RESET, SET);
		Light4(RESET, RESET);
		seg1 = green_value - count_set;
		seg2 = red_value - count_set;
		lcd_display_value(0, 0, seg1);
		lcd_display_value(1, 0, seg2);

		updateCountSet();
		if (count_set >= red_value - yellow_value) {
			count_set = 0;
			status = AUTO_YELLOW_RED;
		}
		if (isButtonPressed(0) == 1) {
			set();
			status = MAN_RED;
			Light1(SET, SET);
			Light2(SET, SET);
			Light3(SET, SET);
			Light4(SET, SET);
		}
		break;

	case AUTO_YELLOW_RED:
		Light1(SET, RESET);
		Light2(RESET, RESET);
		Light3(SET, RESET);
		Light4(RESET, RESET);
		seg1 = yellow_value - count_set;
		seg2 = yellow_value - count_set;
		lcd_display_value(0, 0, seg1);
		lcd_display_value(1, 0, seg2);

		updateCountSet();
		if (count_set >= red_value - green_value) {
			count_set = 0;
			status = AUTO_RED_GREEN;
		}
		if (isButtonPressed(0) == 1) {
			set();
			status = MAN_RED;
			Light1(SET, SET);
			Light2(SET, SET);
			Light3(SET, SET);
			Light4(SET, SET);
		}
		break;

	default:
		break;
	}
}