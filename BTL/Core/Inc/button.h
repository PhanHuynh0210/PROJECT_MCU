/*
 * button.h
 *
 *  Created on: Nov 19, 2024
 *      Author: phanh
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE SET
#define PRESSED_STATE RESET

#define DEBOUNCE_DURATION 0
#define LONG_PRESS_DURATION 2500

extern int button1_flag[10];
extern int buttonState[3];

int isButtonPressed(int index);
int isButtonLongPressed(int index);
void getKeyInput();

#endif /* INC_BUTTON_H_ */
