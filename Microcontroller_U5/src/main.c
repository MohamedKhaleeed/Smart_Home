/*
 * main.c
 *
 *  Created on: Sep 22, 2022
 *      Author: pc
 */

#undef  F_CPU
#define F_CPU 8000000
#include"std_types.h"
#include"Login.h"
#include"UART.h"
#include"DIO.h"
#include<util/delay.h>
#include"STPM_interface.h"


int main(void){
	u8 flag = 0;
	UART_init();
	STPM_voidInit();

	DIO_SetPinMode(DIO_PORTD, DIO_PIN2, DIO_INPUT_PULLUP);
	while(DIO_ReadPinLevel(DIO_PORTD, DIO_PIN2)==DIO_HIGH);

	//ExtI0_voidInit();
	//ExtI0_voidInit();
	//ExtI0_SetCallBackFunction(func);
	//ExtI0_voidEnable();
	u8 Result = login();
	UART_Send_Data(Result);

	if (Result == 'Y'){
		STPM_voidRotate_Clk_Wise(150);

        _delay_ms(5000);

        STPM_voidRotate_Anti_Clk_Wise(150);

	}

	while(1){

		if((UART_Receive_Data() == 'E') && (flag == 0)){
			STPM_voidRotate_Clk_Wise(150);
		    flag = 1;
		}

		if((UART_Receive_Data() == 'S') &&(flag == 1)){
			STPM_voidRotate_Anti_Clk_Wise(150);
			flag = 0;
		}
	}

	//SREG|=(1<<7);
}

