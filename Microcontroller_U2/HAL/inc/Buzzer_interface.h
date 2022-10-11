/*
 * Buzzer_interface.h
 *
 *  Created on: Sep 21, 2022
 *      Author: Dell
 */

#ifndef BUZZER_INTERFACE_H_
#define BUZZER_INTERFACE_H_

#define BUZZER_PIN	 DIO_PORTB,DIO_PIN7

void Buzzer_voidInit	(void);
void Buzzer_voidBeep_ON (void);
void Buzzer_voidBeep_OFF(void);

#endif /* BUZZER_INTERFACE_H_ */
