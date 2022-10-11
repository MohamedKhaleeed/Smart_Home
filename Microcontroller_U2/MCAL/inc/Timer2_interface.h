/*
 * Timer2_interface.h
 *
 *  Created on: Sep 23, 2022
 *      Author: Dell
 */

#ifndef MCAL_INC_TIMER2_INTERFACE_H_
#define MCAL_INC_TIMER2_INTERFACE_H_

#include "std_types.h"

void Timer2_voidInit(void);
void Timer2_SetCallBackFunction(ptrf ptrToFunc);

#endif /* MCAL_INC_TIMER2_INTERFACE_H_ */
