/*
 * Heating_System_interface.h
 *
 *  Created on: Sep 22, 2022
 *      Author: Dell
 */

#ifndef HEATING__SYSTEM_APP_LAYER_INC_HEATING_SYSTEM_INTERFACE_H_
#define HEATING__SYSTEM_APP_LAYER_INC_HEATING_SYSTEM_INTERFACE_H_

typedef enum {
	LOGIN_SUCCESS = 56,
	LOGIN_FAILED,
	LOGIN_NOTYET
}login_state;

void Heating_System_Handle(void);
void Heating_System_Init(void);
void Clock_Handle(void);
login_state Login_Verfiy(void);

#endif /* HEATING__SYSTEM_APP_LAYER_INC_HEATING_SYSTEM_INTERFACE_H_ */
