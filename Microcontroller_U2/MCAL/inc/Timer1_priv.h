/*
 * Timer1_priv.h
 *
 *  Created on: Sep 22, 2022
 *      Author: Dell
 */

#ifndef MCAL_INC_TIMER1_PRIV_H_
#define MCAL_INC_TIMER1_PRIV_H_

#define TCCR1A	 *((volatile u8*)0x4F)
#define TCCR1B	 *((volatile u8*)0x4E)
#define TIFR	 *((volatile u8*)0x58)
#define TIMSK 	 *((volatile u8*)0x59)
#define OCR1AL	 *((volatile u8*)0x4A)
#define OCR1AH	 *((volatile u8*)0x4B)
#define ICR1H	 *((volatile u8*)0x47)
#define ICR1L	 *((volatile u8*)0x46)

#define OCR1A	 *((volatile u16*)0x46)



/*TTCR1A Register bits*/
#define COM1A1	7
#define COM1A0	6
#define COM1B1	5
#define COM1B0	4
#define FOC1A	3
#define FOC1B	2
#define WGM11	1
#define WGM10	0
/*TCCR1B Register bits*/
#define ICNC1	7
#define ICES1	6
#define WGM13	4
#define WGM12	3
#define CS12	2
#define CS11 	1
#define CS10    0

/*TIMSK Register bits*/

#define TICIE1	5
#define OCIE1A	4
#define OCIE1B	3
#define TOIE1	2


#endif /* MCAL_INC_TIMER1_PRIV_H_ */
