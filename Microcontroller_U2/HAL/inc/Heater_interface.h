/*
 * Heater_interface.h
 *
 *  Created on: Sep 21, 2022
 *      Author: Dell
 */

#ifndef HEATER_INTERFACE_H_
#define HEATER_INTERFACE_H_

#define HEATER_PIN 		DIO_PORTB,DIO_PIN6

void Heater_voidInit (void);
void Heater_voidON 	(void);
void Heater_voidOFF (void);



#endif /* HEATER_INTERFACE_H_ */
