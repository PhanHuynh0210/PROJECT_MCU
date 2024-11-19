/*
 * sw_timer.h
 *
 *  Created on: Nov 19, 2024
 *      Author: phanh
 */

#ifndef INC_SW_TIMER_H_
#define INC_SW_TIMER_H_

extern int timer_flag[10];
void setTimer(int index, int counter);
void timerRun();

#endif /* INC_SW_TIMER_H_ */
