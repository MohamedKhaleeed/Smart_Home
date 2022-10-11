/*
 * LM35.c

 *
 *  Created on: Sep 21, 2022
 *      Author: Dell
 */
#include "DIO_interface.h"
#include "LM35_priv.h"
#include "LM35_cfg.h"
#include "LM35_interface.h"
#include "std_types.h"
#include "ADC_interface.h"

u16 temprature = 24 ;


void LM35_voidStart_Reading(void){

	ADC_voidStart_Conversion(LM35_ADC_Channel);
}

void  LM35_voidGet_Reading(void){

		u16 reading = ADC_u16Get_Result();
		temprature = (reading * (5000.0/1024))/10.0;
}


void LM35_voidInit(void){
	DIO_SetPinMode (DIO_PORTA,LM35_ADC_Channel,DIO_INPUT_FLOATING);
	ADC_voidInit();
}


