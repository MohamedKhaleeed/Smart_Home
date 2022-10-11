/*
 * UART_priv.h
 *
 *  Created on: Sep 23, 2022
 *      Author: pc
 */

#ifndef INC_UART_PRIV_H_
#define INC_UART_PRIV_H_

#define UCSRA        (*((volatile u8*)0x2B))
#define UCSRB        (*((volatile u8*)0x2A))
#define UCSRC        (*((volatile u8*)0x40))
#define UBRRL        (*((volatile u8*)0x29))
#define UBRRH        (*((volatile u8*)0x40))
#define UDR          (*((volatile u8*)0x2C))

#endif /* INC_UART_PRIV_H_ */
