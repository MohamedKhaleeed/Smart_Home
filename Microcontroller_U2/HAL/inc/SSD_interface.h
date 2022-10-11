/*
 * SSD.h
 *
 *  Created on: Aug 25, 2022
 *      Author: ahmad
 */

#ifndef INC_SSD_H_
#define INC_SSD_H_
#include "SSD_cfg.h"
#include "SSD_priv.h"


/*	WITHOUT DECODER CONFIGURATION */


#define SSD_PIN_A   DIO_PORTD,DIO_PIN0
#define SSD_PIN_B   DIO_PORTD,DIO_PIN1
#define SSD_PIN_C   DIO_PORTD,DIO_PIN2
#define SSD_PIN_D   DIO_PORTD,DIO_PIN3
#define SSD_PIN_E   DIO_PORTD,DIO_PIN4
#define SSD_PIN_F   DIO_PORTD,DIO_PIN5
#define SSD_PIN_G   DIO_PORTD,DIO_PIN6



#define SSD_DEC_PIN_A		DIO_PORTA,DIO_PIN1
#define SSD_DEC_PIN_B		DIO_PORTA,DIO_PIN2
#define SSD_DEC_PIN_C		DIO_PORTA,DIO_PIN3
#define SSD_DEC_PIN_D		DIO_PORTA,DIO_PIN4






typedef enum {
    SSD_NUMBER_0,
    SSD_NUMBER_1,
    SSD_NUMBER_2,
    SSD_NUMBER_3,
    SSD_NUMBER_4,
    SSD_NUMBER_5,
    SSD_NUMBER_6,
    SSD_NUMBER_7,
    SSD_NUMBER_8,
    SSD_NUMBER_9,
    SSD_OFF
} SSD_NumberType;

void SSD_Init(void);
void SSD_Write (SSD_NumberType number);


#endif /* INC_SSD_H_ */
