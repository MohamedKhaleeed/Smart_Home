/*
 * Timer0_interface.h
 *
 *  Created on: Sep 21, 2022
 *      Author: Dell
 */

#ifndef TIMER0_DRIVER_TIMER0_INTERFACE_H_
#define TIMER0_DRIVER_TIMER0_INTERFACE_H_
#include "std_types.h"

void Timer0_voidInit(void);
void Timer0_voidSetTicks(u8 ticks);
void Timer0_voidEnable();
void Timer0_voidSDisable();
void Timer0_SetCallBackFunction(ptrf ptrToFunc);
void Timer0_void_Polling();

#endif /* TIMER0_DRIVER_TIMER0_INTERFACE_H_ */
