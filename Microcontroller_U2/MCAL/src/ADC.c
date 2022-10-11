/*
 * ADC.c
 *
 *  Created on: Sep 17, 2022
 *      Author: Dell
 */

#include "ADC_priv.h"
#include "ADC_cfg.h"
#include "ADC_interface.h"
#include "macros.h"
#include "std_types.h"

static ptrf ISR_J ;

void ADC_voidInit(void){

#if ADC_REFERENCE_MODE == ADC_AREF_REF_MODE
CLR_BIT(ADMUX,REFS0);
CLR_BIT(ADMUX,REFS1);

#elif ADC_REFERENCE_MODE == ADC_AVCC_REF_MODE
SET_BIT(ADMUX,REFS0);
CLR_BIT(ADMUX,REFS1);

#elif ADC_REFERENCE_MODE == ADC_INTERNAL_REF_MODE
SET_BIT(ADMUX,REFS0);
SET_BIT(ADMUX,REFS1);

#else
	#error "Error in ADC Reference configuration"

#endif

#if ADC_ADJUST_MODE == ADC_LEFT_ADJUST_MODE
SET_BIT(ADMUX,ADLAR);

#elif ADC_ADJUST_MODE == ADC_RIGHT_ADJUST_MODE
CLR_BIT(ADMUX,ADLAR);

#else
	#error "Error in ADC Adjustment configuration"
#endif

#if	 ADC_PRESCALER_MODE == ADC_PRESCALER_2_MODE
	CLR_BIT(ADCSRA,ADPS0);
	CLR_BIT(ADCSRA,ADPS1);
	CLR_BIT(ADCSRA,ADPS2);

#elif ADC_PRESCALER_MODE == ADC_PRESCALER_4_MODE
	 CLR_BIT(ADCSRA,ADPS0);
	 SET_BIT(ADCSRA,ADPS1);
	 CLR_BIT(ADCSRA,ADPS2);

#elif ADC_PRESCALER_MODE == ADC_PRESCALER_8_MODE
	 SET_BIT(ADCSRA,ADPS0);
	 SET_BIT(ADCSRA,ADPS1);
	 CLR_BIT(ADCSRA,ADPS2);

#elif ADC_PRESCALER_MODE == ADC_PRESCALER_16_MODE
	 CLR_BIT(ADCSRA,ADPS0);
	 CLR_BIT(ADCSRA,ADPS1);
	 SET_BIT(ADCSRA,ADPS2);

#elif ADC_PRESCALER_MODE == ADC_PRESCALER_32_MODE
	 SET_BIT(ADCSRA,ADPS0);
	 CLR_BIT(ADCSRA,ADPS1);
	 SET_BIT(ADCSRA,ADPS2);

#elif ADC_PRESCALER_MODE == ADC_PRESCALER_64_MODE
	 CLR_BIT(ADCSRA,ADPS0);
	 SET_BIT(ADCSRA,ADPS1);
	 SET_BIT(ADCSRA,ADPS2);

#elif ADC_PRESCALER_MODE == ADC_PRESCALER_128_MODE
	 SET_BIT(ADCSRA,ADPS0);
	 SET_BIT(ADCSRA,ADPS1);
	 SET_BIT(ADCSRA,ADPS2);

#else
	 #error "Error in ADC Prescaler Configuration"
#endif

/*Enable ADC*/
SET_BIT(ADCSRA,ADEN);

/*Enable ADC interrupt*/
CLR_BIT(ADCSRA,ADIE);
}

void ADC_voidStart_Conversion(ADC_CHANNEL_TYPE channel ){
		 ADMUX = (ADMUX&0xE0) | (0x1F&channel);
		 SET_BIT(ADCSRA,ADSC);

}


ADC_CONVERSION_STATE_TYPE ADC_Get_Conv_State(void){

	if (GET_BIT(ADCSRA,ADIF)==0)
	  {
		return ADC_CONVERSION_NOT_FINISHED ;
	  }

	else
	  {
		return ADC_CONVERSION_FINISHED ;
	  }

}

u16  ADC_u16Get_Result(){
while (ADIF==0);
SET_BIT(ADCSRA,ADIF);
u16 result = *((s16*)(&ADCL));

#if ADC_ADJUST_MODE	== ADC_RIGHT_ADJUST_MODE
result&=0x03FF;

#elif ADC_ADJUST_MODE	== ADC_LEFT_ADJUST_MODE
result>>=6;

#endif

return result;
}


void ADC_SetCallBackFunction(ptrf ptrToFunc){
		ISR_J = ptrToFunc ;
}

void __vector_16 (void)__attribute__((signal,used));
void __vector_16 (void){
	ISR_J();
}

