/*
 * Clock.c
 *
 *  Created on: Sep 23, 2022
 *      Author: Dell
 */
#include <util/delay.h>
#include "std_types.h"
#include "macros.h"
#include "DIO_interface.h"
#include "Clock_interface.h"
#include "Clock_cfg.h"
#include "Clock_priv.h"
#include "Timer0_interface.h"

u64 Ticks = 45400 ;
u8 counter = 0 ;
void Clk_Tick(void){
	counter++ ;
	if (counter >= 32 )
	{
		counter = 0 ;
		Ticks++ ;
	}
}

void Clk_Init(void){

	DIO_SetPinMode(CLK_DEC_PIN_A,DIO_OUTPUT);
    DIO_SetPinMode(CLK_DEC_PIN_B,DIO_OUTPUT);
    DIO_SetPinMode(CLK_DEC_PIN_C,DIO_OUTPUT);
    DIO_SetPinMode(CLK_DEC_PIN_D,DIO_OUTPUT);

	DIO_SetPinMode(CLK_E1,DIO_OUTPUT);
    DIO_SetPinMode(CLK_E2,DIO_OUTPUT);
    DIO_SetPinMode(CLK_E3,DIO_OUTPUT);
    DIO_SetPinMode(CLK_E4,DIO_OUTPUT);
    DIO_SetPinMode(CLK_E5,DIO_OUTPUT);
    DIO_SetPinMode(CLK_E6,DIO_OUTPUT);
	Timer0_voidInit();
	Timer0_voidSetTicks(250);
	Timer0_SetCallBackFunction(Clk_Tick);
	Timer0_voidEnable();

}

void Clk_Display(u8 num){


switch(num)
{
	case 0 :				DIO_SetPinLevel(CLK_DEC_PIN_A, DIO_LOW);
							DIO_SetPinLevel(CLK_DEC_PIN_B, DIO_LOW);
							DIO_SetPinLevel(CLK_DEC_PIN_C, DIO_LOW);
							DIO_SetPinLevel(CLK_DEC_PIN_D, DIO_LOW);
							break ;

	case 1 :				DIO_SetPinLevel(CLK_DEC_PIN_A, DIO_HIGH);
							DIO_SetPinLevel(CLK_DEC_PIN_B, DIO_LOW);
							DIO_SetPinLevel(CLK_DEC_PIN_C, DIO_LOW);
							DIO_SetPinLevel(CLK_DEC_PIN_D, DIO_LOW);


							break ;

	case 2 : 				DIO_SetPinLevel(CLK_DEC_PIN_A, DIO_LOW);
							DIO_SetPinLevel(CLK_DEC_PIN_B, DIO_HIGH);
							DIO_SetPinLevel(CLK_DEC_PIN_C, DIO_LOW);
							DIO_SetPinLevel(CLK_DEC_PIN_D, DIO_LOW);
							break ;

	case 3 : 				DIO_SetPinLevel(CLK_DEC_PIN_A, DIO_HIGH);
							DIO_SetPinLevel(CLK_DEC_PIN_B, DIO_HIGH);
							DIO_SetPinLevel(CLK_DEC_PIN_C, DIO_LOW);
							DIO_SetPinLevel(CLK_DEC_PIN_D, DIO_LOW);

							break ;

	case 4 : 				DIO_SetPinLevel(CLK_DEC_PIN_A, DIO_LOW);
							DIO_SetPinLevel(CLK_DEC_PIN_B, DIO_LOW);
							DIO_SetPinLevel(CLK_DEC_PIN_C, DIO_HIGH);
							DIO_SetPinLevel(CLK_DEC_PIN_D, DIO_LOW);
							break ;

	case 5 : 				DIO_SetPinLevel(CLK_DEC_PIN_A, DIO_HIGH);
							DIO_SetPinLevel(CLK_DEC_PIN_B, DIO_LOW);
							DIO_SetPinLevel(CLK_DEC_PIN_C, DIO_HIGH);
							DIO_SetPinLevel(CLK_DEC_PIN_D, DIO_LOW);
							break ;

	case 6 : 				DIO_SetPinLevel(CLK_DEC_PIN_A, DIO_LOW);
							DIO_SetPinLevel(CLK_DEC_PIN_B, DIO_HIGH);
							DIO_SetPinLevel(CLK_DEC_PIN_C, DIO_HIGH);
							DIO_SetPinLevel(CLK_DEC_PIN_D, DIO_LOW);
							break ;

	case 7 : 				DIO_SetPinLevel(CLK_DEC_PIN_A, DIO_HIGH);
							DIO_SetPinLevel(CLK_DEC_PIN_B, DIO_HIGH);
							DIO_SetPinLevel(CLK_DEC_PIN_C, DIO_HIGH);
							DIO_SetPinLevel(CLK_DEC_PIN_D, DIO_LOW);
							break ;

	case 8 : 				DIO_SetPinLevel(CLK_DEC_PIN_A, DIO_LOW);
							DIO_SetPinLevel(CLK_DEC_PIN_B, DIO_LOW);
							DIO_SetPinLevel(CLK_DEC_PIN_C, DIO_LOW);
							DIO_SetPinLevel(CLK_DEC_PIN_D, DIO_HIGH);
							break ;

	case 9 : 				DIO_SetPinLevel(CLK_DEC_PIN_A, DIO_HIGH);
							DIO_SetPinLevel(CLK_DEC_PIN_B, DIO_LOW);
							DIO_SetPinLevel(CLK_DEC_PIN_C, DIO_LOW);
							DIO_SetPinLevel(CLK_DEC_PIN_D, DIO_HIGH);
							break ;

	default  		   :	DIO_SetPinLevel(CLK_DEC_PIN_A, DIO_LOW);
							DIO_SetPinLevel(CLK_DEC_PIN_B, DIO_LOW);
							DIO_SetPinLevel(CLK_DEC_PIN_C, DIO_LOW);
							DIO_SetPinLevel(CLK_DEC_PIN_D, DIO_LOW);
		}
}
