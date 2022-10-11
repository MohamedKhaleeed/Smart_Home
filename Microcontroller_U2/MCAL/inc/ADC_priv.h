/*
 * ADC_priv.h
 *
 *  Created on: Sep 17, 2022
 *      Author: Dell
 */

#ifndef ADC_PRIV_H_
#define ADC_PRIV_H_

/*ADC Registers*/
#define ADMUX 	 *((volatile u8*)0x27)
#define ADCSRA	 *((volatile u8*)0x26)
#define ADCH	 *((volatile u8*)0x25)
#define ADCL	 *((volatile u8*)0x24)
#define SFIOR	 *((volatile u8*)0x50)

/*ADMUX Register bits*/
#define REFS1 	7
#define REFS0 	6
#define ADLAR	5
#define MUX4	4
#define MUX3	3
#define MUX2	2
#define MUX1	1
#define MUX0	0

/*ADCSRA Register bits*/
#define ADEN	7
#define ADSC	6
#define ADATE	5
#define ADIF	4
#define ADIE	3
#define ADPS2	2
#define ADPS1	1
#define ADPS0	0

/*SFIOR Register bits*/
#define ADTS2 7
#define ADTS1 6
#define ADTS0 5


/*ADC Reference Modes*/
#define ADC_AREF_REF_MODE 		1
#define ADC_AVCC_REF_MODE 		2
#define ADC_INTERNAL_REF_MODE 	3

/*ADC Left Adjust Modes*/
#define ADC_LEFT_ADJUST_MODE 	1
#define ADC_RIGHT_ADJUST_MODE 	2

/*ADC Prescaler Modes*/
#define ADC_PRESCALER_2_MODE	1
#define ADC_PRESCALER_4_MODE	2
#define ADC_PRESCALER_8_MODE	3
#define ADC_PRESCALER_16_MODE	4
#define ADC_PRESCALER_32_MODE	5
#define ADC_PRESCALER_64_MODE	6
#define ADC_PRESCALER_128_MODE	7


#endif /* ADC_PRIV_H_ */
