/*
 * Timer0.c
 *
 *  Created on: Sep 21, 2022
 *      Author: Dell
 */
#include "Timer0_priv.h"
#include "Timer0_cfg.h"
#include "Timer0_interface.h"
#include "macros.h"
#include "std_types.h"

static ptrf ISR_J ;


void Timer0_voidInit(void){

#if	  TIMER0_OPERATION_MODE == TIMER0_NORMAL_OPERATION_MODE
	{
	  SET_BIT(TCCR0,FOC0);
	  CLR_BIT(TCCR0,WGM01);
	  CLR_BIT(TCCR0,WGM00);

#if TIMER0_INTERTUPT_MODE == TIMER0_INTERRUPT_ENABLE_MODE
	  	  SET_BIT(TIMSK,TOIE0);
	#elif TIMER0_INTERTUPT_MODE == TIMER0_INTERRUPT_DISABLE_MODE
	  	  CLR_BIT(TIMSK,TOIE0);
	#error "Error in TIMER0_INTERTUPT_MODE configuration "

	#endif

	}

#elif TIMER0_OPERATION_MODE == TIMER0_CTC_OPERATION_MODE
	{
	  SET_BIT(TCCR0,FOC0);
	  SET_BIT(TCCR0,WGM01);
	  CLR_BIT(TCCR0,WGM00);

#if TIMER0_INTERTUPT_MODE == TIMER0_INTERRUPT_ENABLE_MODE
	  	  SET_BIT(TIMSK,OCIE0);
	#elif TIMER0_INTERTUPT_MODE == TIMER0_INTERRUPT_DISABLE_MODE
	  	  CLR_BIT(TIMSK,OCIE0);
	#else #error "Error in TIMER0_INTERTUPT_MODE configuration "

	#endif
	}

#elif TIMER0_OPERATION_MODE == TIMER0_PWM_OPERATION_MODE
	  SET_BIT(TCCR0,WGM01);
	  SET_BIT(TCCR0,WGM00);

#else #error "Error in TIMER0_OPERATION_MODE configuration"

#endif


#if	TIMER0_CMP_MATCH_OUT_MODE == TIMER0_NORMAL_PORT_OPERATION_MODE
	  	  CLR_BIT(TCCR0,COM01);
	  	  CLR_BIT(TCCR0,COM00);

#elif	TIMER0_CMP_MATCH_OUT_MODE == TIMER0_TGL_PORT_OPERATION_MODE
	  	  CLR_BIT(TCCR0,COM01);
	  	  SET_BIT(TCCR0,COM00);

#elif	TIMER0_CMP_MATCH_OUT_MODE == TIMER0_CLR_PORT_OPERATION_MODE
	  	  SET_BIT(TCCR0,COM01);
	  	  CLR_BIT(TCCR0,COM00);

#elif	TIMER0_CMP_MATCH_OUT_MODE == TIMER0_SET_PORT_OPERATION_MODE
	  	 SET_BIT(TCCR0,COM01);
	  	 SET_BIT(TCCR0,COM00);

#else #error "Error in TIMER0_OPERATION_MODE configuration "

#endif



 }

void Timer0_void_Polling(){

#if	  TIMER0_OPERATION_MODE == TIMER0_NORMAL_OPERATION_MODE
	while ( GET_BIT(TIFR,TOV0)==0 );
	SET_BIT(TIFR,TOV0) ;

#elif TIMER0_INTERTUPT_MODE == TIMER0_CTC_OPERATION_MODE
	while ( GET_BIT(TIFR,OCF0)==0 );
	SET_BIT(TIFR,OCF0) ;

	#endif



}

void Timer0_voidSetTicks(u8 ticks){

#if	TIMER0_OPERATION_MODE == TIMER0_NORMAL_OPERATION_MODE
	TCNT0 = 256-ticks ;

#elif TIMER0_OPERATION_MODE == TIMER0_CTC_OPERATION_MODE
	TCNT0 = 0 ;
	OCR0 = ticks ;
#endif


}

void Timer0_voidEnable(){
#if TIMER0_PRESCALER_MODE == TIMER0_PRESCALER_1_MODE
	  	CLR_BIT(TCCR0,CS02);
	  	CLR_BIT(TCCR0,CS01);
	  	SET_BIT(TCCR0,CS00);

#elif  TIMER0_PRESCALER_MODE == TIMER0_PRESCALER_8_MODE
	  	CLR_BIT(TCCR0,CS02);
	  	SET_BIT(TCCR0,CS01);
	  	CLR_BIT(TCCR0,CS00);

#elif  TIMER0_PRESCALER_MODE == TIMER0_PRESCALER_64_MODE
	  	CLR_BIT(TCCR0,CS02);
	  	SET_BIT(TCCR0,CS01);
	  	SET_BIT(TCCR0,CS00);

#elif  TIMER0_PRESCALER_MODE == TIMER0_PRESCALER_256_MODE
	  	SET_BIT(TCCR0,CS02);
	  	CLR_BIT(TCCR0,CS01);
	  	CLR_BIT(TCCR0,CS00);

#elif  TIMER0_PRESCALER_MODE == TIMER0_PRESCALER_1024_MODE

	  	SET_BIT(TCCR0,CS02);
	  	CLR_BIT(TCCR0,CS01);
	  	SET_BIT(TCCR0,CS00);

#elif  TIMER0_PRESCALER_MODE == TIMER0_PRESCALER_EXT_CLK_FE_MODE
	  	SET_BIT(TCCR0,CS02);
	  	SET_BIT(TCCR0,CS01);
	  	CLR_BIT(TCCR0,CS00);

#elif  TIMER0_PRESCALER_MODE == TIMER0_PRESCALER_EXT_CLK_RE_MODE
	  	SET_BIT(TCCR0,CS02);
	  	SET_BIT(TCCR0,CS01);
	  	SET_BIT(TCCR0,CS00);

#else #error "Error in TIMER0_PRESCALER_MODE configuration "

#endif

}

void Timer0_voidDisable(){

	CLR_BIT(TCCR0,CS02);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS00);

}



void Timer0_SetCallBackFunction(ptrf ptrToFunc){
	ISR_J = ptrToFunc ;
}


void __vector_10 (void)__attribute__((signal,used));
void __vector_10 (void){
	ISR_J();
}

void __vector_11 (void)__attribute__((signal,used));
void __vector_11 (void){
	ISR_J();
}

