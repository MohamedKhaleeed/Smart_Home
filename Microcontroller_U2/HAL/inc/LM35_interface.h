/*
 * LM35_interface.h
 *
 *  Created on: Sep 21, 2022
 *      Author: Dell
 */

#ifndef LM35_INTERFACE_H_
#define LM35_INTERFACE_H_
#include "std_types.h"

#define LM35_ADC_Channel 	DIO_PIN0

void LM35_voidInit(void);
void LM35_voidStart_Reading  (void);
void LM35_voidGet_Reading(void);
#endif /* LM35_INTERFACE_H_ */
