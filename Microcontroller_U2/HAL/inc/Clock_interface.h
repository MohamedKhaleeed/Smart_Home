/*
 * Clock_interface.h
 *
 *  Created on: Sep 23, 2022
 *      Author: Dell
 */

#ifndef HAL_INC_CLOCK_INTERFACE_H_
#define HAL_INC_CLOCK_INTERFACE_H_

#include "std_types.h"

#define CLK_DEC_PIN_A		DIO_PORTC,DIO_PIN2
#define CLK_DEC_PIN_B		DIO_PORTC,DIO_PIN3
#define CLK_DEC_PIN_C		DIO_PORTC,DIO_PIN4
#define CLK_DEC_PIN_D		DIO_PORTC,DIO_PIN5

#define CLK_E1				DIO_PORTB,DIO_PIN4
#define CLK_E2				DIO_PORTC,DIO_PIN6
#define CLK_E3				DIO_PORTC,DIO_PIN7
#define CLK_E4				DIO_PORTD,DIO_PIN3
#define CLK_E5				DIO_PORTD,DIO_PIN4
#define CLK_E6				DIO_PORTD,DIO_PIN6

void Clk_Init(void);
void Clk_Display(u8 num);


#endif /* HAL_INC_CLOCK_INTERFACE_H_ */
