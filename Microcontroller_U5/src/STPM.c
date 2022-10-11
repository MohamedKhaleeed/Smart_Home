/*
 * STPM.c
 *
 *  Created on: Sep 16, 2022
 *      Author: Dell
 */
#include "DIO.h"
#include "STPM_priv.h"
#include "STPM_cfg.h"
#include "STPM_interface.h"
#include "std_types.h"
#include "macros.h"
#include <util/delay.h>

void STPM_voidInit(void){
	DIO_SetPinMode(STPM_PIN1,DIO_OUTPUT);
	DIO_SetPinMode(STPM_PIN2,DIO_OUTPUT);
	DIO_SetPinMode(STPM_PIN3,DIO_OUTPUT);
	DIO_SetPinMode(STPM_PIN4,DIO_OUTPUT);
}


void STPM_voidRotate_Clk_Wise(u16 angle){
u16 itterations = (angle /STPM_STEP_ANGLE) / 4 ;

for (u16 i = 0  ; i < itterations ; i++ )
	{
		DIO_SetPinLevel(STPM_PIN1,DIO_LOW);
		DIO_SetPinLevel(STPM_PIN2,DIO_LOW);
		DIO_SetPinLevel(STPM_PIN3,DIO_LOW);
		DIO_SetPinLevel(STPM_PIN4,DIO_HIGH);
		_delay_ms(10);

		DIO_SetPinLevel(STPM_PIN1,DIO_LOW);
		DIO_SetPinLevel(STPM_PIN2,DIO_LOW);
		DIO_SetPinLevel(STPM_PIN3,DIO_HIGH);
		DIO_SetPinLevel(STPM_PIN4,DIO_LOW);
		_delay_ms(10);

		DIO_SetPinLevel(STPM_PIN1,DIO_LOW);
		DIO_SetPinLevel(STPM_PIN2,DIO_HIGH);
		DIO_SetPinLevel(STPM_PIN3,DIO_LOW);
		DIO_SetPinLevel(STPM_PIN4,DIO_LOW);
		_delay_ms(10);

		DIO_SetPinLevel(STPM_PIN1,DIO_HIGH);
		DIO_SetPinLevel(STPM_PIN2,DIO_LOW);
		DIO_SetPinLevel(STPM_PIN3,DIO_LOW);
		DIO_SetPinLevel(STPM_PIN4,DIO_LOW);
		_delay_ms(10);
	}
}

void STPM_voidRotate_Anti_Clk_Wise(u16 angle){

u16 itterations = (angle /STPM_STEP_ANGLE) / 4 ;

for (u16 i = 0  ; i < itterations ; i++ )
	{
		DIO_SetPinLevel(STPM_PIN1,DIO_HIGH);
		DIO_SetPinLevel(STPM_PIN2,DIO_LOW);
		DIO_SetPinLevel(STPM_PIN3,DIO_LOW);
		DIO_SetPinLevel(STPM_PIN4,DIO_LOW);
		_delay_ms(10);

		DIO_SetPinLevel(STPM_PIN1,DIO_LOW);
		DIO_SetPinLevel(STPM_PIN2,DIO_HIGH);
		DIO_SetPinLevel(STPM_PIN3,DIO_LOW);
		DIO_SetPinLevel(STPM_PIN4,DIO_LOW);
		_delay_ms(10);

		DIO_SetPinLevel(STPM_PIN1,DIO_LOW);
		DIO_SetPinLevel(STPM_PIN2,DIO_LOW);
		DIO_SetPinLevel(STPM_PIN3,DIO_HIGH);
		DIO_SetPinLevel(STPM_PIN4,DIO_LOW);
		_delay_ms(10);

		DIO_SetPinLevel(STPM_PIN1,DIO_LOW);
		DIO_SetPinLevel(STPM_PIN2,DIO_LOW);
		DIO_SetPinLevel(STPM_PIN3,DIO_LOW);
		DIO_SetPinLevel(STPM_PIN4,DIO_HIGH);
		_delay_ms(10);
	}
}




