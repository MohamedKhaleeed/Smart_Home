/*
 * Timer1.c
 *
 *  Created on: Sep 22, 2022
 *      Author: Dell
 */


#include "Timer1_priv.h"
#include "Timer1_cfg.h"
#include "Timer1_interface.h"
#include "macros.h"
#include "std_types.h"
#include "DIO_priv.h"
#include "Avr/io.h"

void Timer1_voidGeneratePWM(u8 speed){

	TCCR1A=(1<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (1<<WGM11) | (1<<WGM10);
	TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (1<<WGM12) | (0<<CS12) | (1<<CS11) | (1<<CS10);
	TCNT1H=0x00;
switch (speed)
{
case 'H' :

		TCNT1L=0x00;
		ICR1H=0x00;
		ICR1L=0x00;
		OCR1AH=0xF2;
		OCR1AL=0xFF;
		OCR1BH=0x00;
		OCR1BL=0x00;
		break ;
case 'M' :
	TCNT1L=0x00;
			ICR1H=0x00;
			ICR1L=0x00;
			OCR1AH=0x02;
			OCR1AL=0x02;
			OCR1BH=0x00;
			OCR1BL=0x00;
		break ;
case 'L' :
		TCNT1L=0x00;
		ICR1H=0x00;
		ICR1L=0x00;
		OCR1AH=0x00;
		OCR1AL=0xF0;
		OCR1BH=0x00;
		OCR1BL=0x00;
		break ;

};

}

void Timer1_voidDisablePWM(void){
	TCCR1A = 0 ;
	TCCR1B=0  ;
	TCNT1H = 0 ;
}

