/*
 * Heater.c
 *
 *  Created on: Sep 21, 2022
 *      Author: Dell
 */
#include "DIO_interface.h"
#include "Heater_interface.h"

void Heater_voidInit (void){
	DIO_SetPinMode(HEATER_PIN,DIO_OUTPUT);
}
void Heater_voidON 	(void){
	DIO_SetPinLevel(HEATER_PIN,DIO_HIGH);
}
void Heater_voidOFF (void){
	DIO_SetPinLevel(HEATER_PIN,DIO_LOW);

}
