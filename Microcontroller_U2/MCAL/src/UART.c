/*
 * UART.c
 *
 *  Created on: Sep 7, 2022
 *      Author: X1-CB
 */
#include "std_types.h"
#include "macros.h"
#include "UART_interface.h"
#include "UART_priv.h"
#include "UART_cfg.h"
#include "DIO_interface.h"

void UART_init()
{
	SET_BIT(UCSRC, UCSRC_URSEL);
	DIO_SetPinMode(DIO_PORTD, DIO_PIN0, DIO_INPUT_FLOATING);
	DIO_SetPinMode(DIO_PORTD, DIO_PIN1, DIO_OUTPUT);

#if (STOP_BIT == STOP_BIT_ONE)
	CLR_BIT(UCSRC, UCSRC_USBS);
#elif (STOP_BIT == STOP_BIT_TWO)
	SET_BIT(UCSRC, UCSRC_USBS);
#endif

#if (Parity_Mode == Parity_Mode_Disabled)
	CLR_BIT(UCSRC, UCSRC_UPM0);
	CLR_BIT(UCSRC, UCSRC_UPM1);
#elif (Parity_Mode == Parity_Mode_Even)
	CLR_BIT(UCSRC, UCSRC_UPM0);
	SET_BIT(UCSRC, UCSRC_UPM1);
#elif (Parity_Mode == Parity_Mode_Odd)
	SET_BIT(UCSRC, UCSRC_UPM0);
	SET_BIT(UCSRC, UCSRC_UPM1);
#endif
	/****************Asynchronous********************/

	CLR_BIT(UCSRC, UCSRC_UMSEL);

	/****************Baud Rate = 9600 bps********************/

	UBRRL = 103;

	/**************** CHARACTER_SIZE 8 Bit ********************/
	SET_BIT(UCSRC, UCSRC_UCSZ0);
	SET_BIT(UCSRC, UCSRC_UCSZ1);
	CLR_BIT(UCSRB, UCSRB_UCSZ2);

	SET_BIT(UCSRB, UCSRB_RXEN);    // ENABLE RCV
	SET_BIT(UCSRB, UCSRB_TXEN);    // ENABLE TRAS
}
void UART_Send_Data(u8 data)
{
	UDR = data;
	while (GET_BIT(UCSRA,UCSRA_TXC) == 0 );
}
u8 UART_Receive_Data(void)
{
	while (GET_BIT(UCSRA,UCSRA_RXC) == 0 );
	return UDR;
}

