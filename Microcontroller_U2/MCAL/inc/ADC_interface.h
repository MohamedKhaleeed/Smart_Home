/*
 * ADC_interface.h
 *
 *  Created on: Sep 17, 2022
 *      Author: Dell
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_
#include "std_types.h"

typedef enum {
	ADC_CHANNEL_0,
	ADC_CHANNEL_1,
	ADC_CHANNEL_2,
	ADC_CHANNEL_3,
	ADC_CHANNEL_4,
	ADC_CHANNEL_5,
	ADC_CHANNEL_6,
	ADC_CHANNEL_7
}ADC_CHANNEL_TYPE;

typedef enum {
	ADC_CONVERSION_FINISHED ,
	ADC_CONVERSION_NOT_FINISHED
}ADC_CONVERSION_STATE_TYPE ;

void ADC_voidInit(void);
void ADC_voidStart_Conversion(ADC_CHANNEL_TYPE);
u16  ADC_u16Get_Result();
void ADC_SetCallBackFunction(ptrf ptrToFunc);
ADC_CONVERSION_STATE_TYPE ADC_Get_Conv_State(void);
#endif /* ADC_INTERFACE_H_ */
