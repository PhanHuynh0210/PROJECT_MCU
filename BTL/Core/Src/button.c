/*
 * button.c
 *
 *  Created on: Nov 19, 2024
 *      Author: phanh
 */

#include "button.h"
#include "global.h"
int buttonState[3] = { IDLE, IDLE, IDLE };
int TimeOutForKeyPress[3] = { 0, 0, 0 };
int button_flag[3] = { 0, 0, 0 };
int KeyReg0[3] = { NORMAL_STATE, NORMAL_STATE, NORMAL_STATE };
int KeyReg1[3] = { NORMAL_STATE, NORMAL_STATE, NORMAL_STATE };
int KeyReg2[3] = { NORMAL_STATE, NORMAL_STATE, NORMAL_STATE };
int KeyRegb[3];

int isButtonPressed(int index) {
    if (button_flag[index] == 1) {
        button_flag[index] = 0;
        return 1;
    }
    return 0;
}

int isButtonLongPressed(int index) {
    if (button_flag[index] == 2) {
        button_flag[index] = 0;
        return 1;
    }
    return 0;
}

void subKeyProcess(int index) {
	if (buttonState[index] == PRESSED) {
		button_flag[index] = 1;
	} else if (buttonState[index] == LONG_PRESSED) {
		button_flag[index] = 2;
	}
}

//void subKeyProcess(int index) {
//	button_flag[index] = 1;
//}

void getKeyInput() {
	KeyRegb[0] = HAL_GPIO_ReadPin(A0_GPIO_Port, A0_Pin);
	KeyRegb[1] = HAL_GPIO_ReadPin(A1_GPIO_Port, A1_Pin);
	KeyRegb[2] = HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin);

//    int anyButtonPressed = 0;

	for (int i = 0; i < 3; i++) {
		KeyReg2[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg0[i];
		KeyReg0[i] = KeyRegb[i];
		switch (buttonState[i]) {
		case IDLE:
			if (KeyReg0[i] == PRESSED_STATE && KeyReg1[i] == KeyReg0[i]
					&& KeyReg2[i] == KeyReg1[i]) {
				buttonState[i] = DEBOUNCE;
				TimeOutForKeyPress[i] = DEBOUNCE_DURATION;
			}
			break;
		case DEBOUNCE:
			if (TimeOutForKeyPress[i] > 0) {
				TimeOutForKeyPress[i]--;
			} else {
				if (KeyReg0[i] == PRESSED_STATE) {
					buttonState[i] = PRESSED;
					TimeOutForKeyPress[i] = LONG_PRESS_DURATION;
					subKeyProcess(i);
				} else {
					buttonState[i] = IDLE;
				}
			}
			break;
		case PRESSED:
			if (KeyReg0[i] == NORMAL_STATE) {
				buttonState[i] = IDLE;
			} else {
				if (TimeOutForKeyPress[i] > 0) {
					TimeOutForKeyPress[i]--;
				} else {
					buttonState[i] = LONG_PRESSED;
					subKeyProcess(i);
				}
			}
			break;
		case LONG_PRESSED:
			if (KeyReg0[i] == NORMAL_STATE) {
				buttonState[i] = IDLE;
			} else {
				subKeyProcess(i);
				TimeOutForKeyPress[i] = LONG_PRESS_DURATION;
			}
			break;
		default:
			buttonState[i] = IDLE;
			break;
		}
	}
}
//        if (buttonState[i] == PRESSED || buttonState[i] == LONG_PRESSED) {
//            anyButtonPressed = 1;
//        }
//    }
//
//    if (anyButtonPressed) {
//        HAL_GPIO_WritePin(LED_BUT_GPIO_Port, LED_BUT_Pin, GPIO_PIN_RESET);
//    } else {
//        HAL_GPIO_WritePin(LED_BUT_GPIO_Port, LED_BUT_Pin, GPIO_PIN_SET);
//    }
//}
