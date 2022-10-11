/*
 * Timer2_priv.h
 *
 *  Created on: Sep 23, 2022
 *      Author: Dell
 */

#ifndef MCAL_INC_TIMER2_PRIV_H_
#define MCAL_INC_TIMER2_PRIV_H_


/************ TIMER 2 ************/
#define TCCR2 *((volatile u8 *)0x45)
#define TCNT2 *((volatile u8 *)0x44)
#define OCR2 *((volatile u8 *)0x43)
#define TIMSK 	 *((volatile u8*)0x59)

/*TCCR2 Register bits*/
#define FOC2	0
#define WGM20	1
#define COM21	2
#define COM20	3
#define WGM21	4
#define CS22	5
#define CS21	6
#define CS20	7

/*TIMSK Register bits*/
#define OCIE2	7
#define TOIE2   6

#endif /* MCAL_INC_TIMER2_PRIV_H_ */
