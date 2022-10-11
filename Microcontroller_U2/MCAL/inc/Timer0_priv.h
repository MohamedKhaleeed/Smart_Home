/*
 * Timer0_priv.h
 *
 *  Created on: Sep 21, 2022
 *      Author: Dell
 */

#ifndef TIMER0_DRIVER_TIMER0_PRIV_H_
#define TIMER0_DRIVER_TIMER0_PRIV_H_

/*Timer 0 Registers */
#define TCCR0 	 *((volatile u8*)0x53)
#define TCNT0 	 *((volatile u8*)0x52)
#define OCR0 	 *((volatile u8*)0x5C)
#define TIMSK 	 *((volatile u8*)0x59)
#define TIFR 	 *((volatile u8*)0x58)


/*TCCR0 Register bits*/
#define FOC0	7
#define WGM00	6
#define COM01	5
#define COM00	4
#define WGM01	3
#define CS02	2
#define CS01	1
#define CS00	0

/*TIMSK Register bits*/
#define OCIE0	1
#define TOIE0	0

/*TIFR Register bits */
#define OCF0	1
#define TOV0	0


/*Timer0 operation modes*/
#define TIMER0_NORMAL_OPERATION_MODE	1
#define TIMER0_CTC_OPERATION_MODE		2
#define TIMER0_PWM_OPERATION_MODE		3

/*Timer0 Compare Match Output Mode*/
#define TIMER0_NOR_PORT_OPERATION_MODE	1
#define TIMER0_TGL_PORT_OPERATION_MODE	2
#define TIMER0_CLR_PORT_OPERATION_MODE	3
#define TIMER0_SET_PORT_OPERATION_MODE	4



/*Timer0 Interrupt Modes*/
#define TIMER0_INTERRUPT_ENABLE_MODE		1
#define TIMER0_INTERRUPT_DISABLE_MODE		2




/*Timer0 Prescaler Modes*/

#define TIMER0_PRESCALER_1_MODE		1
#define	TIMER0_PRESCALER_8_MODE		2
#define	TIMER0_PRESCALER_64_MODE	3
#define	TIMER0_PRESCALER_256_MODE	4
#define	TIMER0_PRESCALER_1024_MODE	5
#define	TIMER0_PRESCALER_EXT_CLK_FE_MODE	6
#define	TIMER0_PRESCALER_EXT_CLK_RE_MODE	7


#endif /* TIMER0_DRIVER_TIMER0_PRIV_H_ */
