/*
 * ADC_cfg.h
 *
 *  Created on: Sep 17, 2022
 *      Author: Dell
 */

#ifndef ADC_CFG_H_
#define ADC_CFG_H_

/*
 ADC_REFERENCE_MODE -> 	 ADC_AREF_REF_MODE
 	 	 	 	 	-> 	 ADC_AVCC_REF_MODE
 	 	 	 	 	->	 ADC_INTERNAL_REF_MODE
  */
#define ADC_REFERENCE_MODE		ADC_AREF_REF_MODE

/*
 ADC_ADJUST_MODE	-> 	ADC_LEFT_ADJUST_MODE
 	 	 	 	 	->	ADC_RIGHT_ADJUST_MODE
 */
#define ADC_ADJUST_MODE			ADC_RIGHT_ADJUST_MODE
/*
  ADC_PRESCALER_MODE  -> ADC_PRESCALER_2_MODE
 	 	 	 	 	  -> ADC_PRESCALER_4_MODE
 	 	 	 	 	  -> ADC_PRESCALER_8_MODE
 	 	 	 	 	  -> ADC_PRESCALER_16_MODE
 	 	 	 	 	  -> ADC_PRESCALER_32_MODE
 	 	 	 	 	  -> ADC_PRESCALER_64_MODE
 	 	 	 	 	  -> ADC_PRESCALER_128_MODE
 */
#define ADC_PRESCALER_MODE 		ADC_PRESCALER_128_MODE
#endif /* ADC_CFG_H_ */
