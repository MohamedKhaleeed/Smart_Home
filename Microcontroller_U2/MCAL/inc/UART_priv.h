/*
 * UART_priv.h
 *
 *  Created on: Sep 22, 2022
 *      Author: Dell
 */

#ifndef MCAL_INC_UART_PRIV_H_
#define MCAL_INC_UART_PRIV_H_

/************ UART ************/
#define UCSRA        (*((volatile u8*)0x2B))
#define UCSRB        (*((volatile u8*)0x2A))
#define UCSRC        (*((volatile u8*)0x40))
#define UBRRL        (*((volatile u8*)0x29))
#define UBRRH        (*((volatile u8*)0x40))
#define UDR          (*((volatile u8*)0x2C))



#endif /* MCAL_INC_UART_PRIV_H_ */
