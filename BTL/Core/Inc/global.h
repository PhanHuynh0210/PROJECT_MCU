/*
 * global.h
 *
 *  Created on: Nov 19, 2024
 *      Author: phanh
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "sw_timer.h"
#include "button.h"
#include "fsm_automatic.h"
#include "lcd.h"
#include <stdio.h>


#define MAN_RED 		12
#define MAN_GREEN 		13
#define MAN_YELLOW 		14

#define INIT				1
#define AUTO_RED_GREEN		2
#define AUTO_RED_YELLOW		3
#define AUTO_GREEN_RED		4
#define AUTO_YELLOW_RED		5

#define count_R		5
#define count_G		3
#define count_Y		2

#define IDLE			6
#define DEBOUNCE		7
#define PRESSED			8
#define LONG_PRESSED	9

#define SET_RED			15
#define SET_GREEN		16
#define SET_YELLOW		17

extern int status;

extern int red_value;
extern int green_value;
extern int yellow_value;

extern int set_red;
extern int set_yellow;
extern int set_green;

void  setvalue();
void upvalue();

#endif /* INC_GLOBAL_H_ */
