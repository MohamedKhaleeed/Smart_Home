/*
 * Timer2.c
 *
 *  Created on: Sep 23, 2022
 *      Author: Dell
 */
#include "Timer2_interface.h"
#include "Timer2_cfg.h"
#include "Timer2_priv.h"
#include "macros.h"
#include "std_types.h"

static ptrf ISR_J ;

void Timer2_voidInit(){

	SET_BIT(TCCR2,FOC2);

	SET_BIT(TCCR2,WGM21);
	CLR_BIT(TCCR2,WGM20);



	CLR_BIT(TCCR2,COM21);
	CLR_BIT(TCCR2,COM20);


	OCR2 = 250 ;

	SET_BIT(TCCR2,CS22);
	SET_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS20);

	SET_BIT(TIMSK,OCIE2);


}

void Timer2_SetCallBackFunction(ptrf ptrToFunc){
	ISR_J = ptrToFunc ;
}
void __vector_4 (void)__attribute__((signal,used));
void __vector_4 (void){
	ISR_J();
}
