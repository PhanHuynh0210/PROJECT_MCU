/*
 * fsm_automatic.h
 *
 *  Created on: Nov 19, 2024
 *      Author: phanh
 */

#ifndef INC_FSM_AUTOMATIC_H_
#define INC_FSM_AUTOMATIC_H_

#include "traffic_light.h"

extern int count_set;

void init_fsm_auto();
void fsm_auto_run();
void set();
void  updateCountSet();

#endif /* INC_FSM_AUTOMATIC_H_ */
