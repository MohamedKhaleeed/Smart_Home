/*
 * STPM_interface.h
 *
 *  Created on: Sep 17, 2022
 *      Author: Dell
 */

#ifndef STPM_INTERFACE_H_
#define STPM_INTERFACE_H_
#include "std_types.h"

#define STPM_PIN1   DIO_PORTC,DIO_PIN2
#define STPM_PIN2 	DIO_PORTC,DIO_PIN3
#define STPM_PIN3	DIO_PORTC,DIO_PIN4
#define STPM_PIN4	DIO_PORTC,DIO_PIN5

void STPM_voidInit(void);
void STPM_voidRotate_Clk_Wise(u16 angle);
void STPM_voidRotate_Anti_Clk_Wise(u16 angle);


#endif /* STPM_INTERFACE_H_ */
