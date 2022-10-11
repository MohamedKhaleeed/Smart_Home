#include "std_types.h"

#define UCSRC_URSEL 	7

#define UCSRC_USBS 		3

#define UCSRC_UPM0 		4
#define UCSRC_UPM1 		5

#define UCSRC_UMSEL 	6

#define UCSRC_UCSZ0 	1
#define UCSRC_UCSZ1 	2
#define UCSRB_UCSZ2  	2

#define UCSRB_RXEN 		4
#define UCSRB_TXEN 		3


#define UCSRA_RXC 		7
#define UCSRA_TXC 		6


void UART_init();
u8 UART_Receive_Data(void);
void UART_Send_Data(u8 data);
