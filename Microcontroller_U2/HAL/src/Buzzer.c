/*
 * Buzzer.c
 *
 *  Created on: Sep 21, 2022
 *      Author: Dell
 */

#ifndef BUZZER_C_
#define BUZZER_C_

#include "DIO_interface.h"
#include "Buzzer_priv.h"
#include "Buzzer_cfg.h"
#include "Buzzer_interface.h"

void Buzzer_voidInit(void){
	DIO_SetPinMode(BUZZER_PIN,DIO_OUTPUT);
}

void Buzzer_voidBeep_ON(void){
	DIO_SetPinLevel(BUZZER_PIN,DIO_HIGH);
}

void Buzzer_voidBeep_OFF(void){
	DIO_SetPinLevel(BUZZER_PIN,DIO_LOW);
}


#endif /* BUZZER_C_ */
