/*
 * Heating_System.c
 *
 *  Created on: Sep 22, 2022
 *      Author: Dell
 */
#include <util/delay.h>
#include "GIE_interface.h"
#include "Heater_interface.h"
#include "LM35_interface.h"
#include "Buzzer_interface.h"
#include "Heater_interface.h"
#include "Timer0_interface.h"
#include "Timer1_interface.h"
#include "Timer2_interface.h"
#include "SSD_interface.h"
#include "macros.h"
#include "DIO_interface.h"
#include "UART_interface.h"
#include "std_types.h"
#include "Heating_System_interface.h"
#include "STPM_interface.h"
#include "Clock_interface.h"
#undef	F_CPU
#define F_CPU 8000000UL

#define ClK_DELAY 4
extern u16 temprature ;
extern u64 Ticks ;

static void Display_Temp(void);



void Display_Temp()
{
	GIE_voidDisable();

		u16 SSD_Temp  = temprature ;

		DIO_SetPinLevel(DIO_PORTC,DIO_PIN0,DIO_HIGH);
		DIO_SetPinLevel(DIO_PORTC,DIO_PIN1,DIO_LOW);
		SSD_Write(SSD_Temp%10);
		_delay_ms(2);
		SSD_Temp/=10 ;

		DIO_SetPinLevel(DIO_PORTC,DIO_PIN1,DIO_HIGH);
		DIO_SetPinLevel(DIO_PORTC,DIO_PIN0,DIO_LOW);
		SSD_Write(SSD_Temp);
		_delay_ms(2);
		GIE_voidEnable();

}

void Alarm_ON(void){
	Buzzer_voidBeep_ON();
 }

void ALarm_OFF(void){
	Buzzer_voidBeep_OFF();
}

void Heating_System_Handle(){

	LM35_voidGet_Reading();


	Display_Temp() ;

		if ( temprature <=	 20 )
		{

			Heater_voidON();
			ALarm_OFF();
			Timer1_voidDisablePWM();
			UART_Send_Data('S');


		}


		else if ( temprature > 20 && temprature <= 25 )
			{

					Heater_voidOFF();
					ALarm_OFF();
					Timer1_voidDisablePWM();
					UART_Send_Data('S');



			}


		else if ( temprature > 25 && temprature <= 30 )
		{

			Heater_voidOFF();
			ALarm_OFF();
			Timer1_voidGeneratePWM('L');
			UART_Send_Data('S');



		}

		else if ( temprature > 30 && temprature <= 35 )
		{

			Heater_voidOFF();
			ALarm_OFF();
			Timer1_voidGeneratePWM('M');
			UART_Send_Data('S');



		}

		else if ( temprature > 35 && temprature <= 50)
		{

			Heater_voidOFF();
			ALarm_OFF();
			Timer1_voidGeneratePWM('H');
			UART_Send_Data('S');


		}

		else
			{
				Heater_voidOFF();
				Alarm_ON();

				Timer1_voidDisablePWM();
				UART_Send_Data('E');
			}
		LM35_voidStart_Reading();


}
unsigned char H=0, M=0 , S=0 ;
unsigned char H2  , H1  , M2 , M1, S2 , S1  , T ;

void Clock_Handle(void){
		// GIE_voidDisable();
		S = Ticks%60 ;
		M = (Ticks/60)%60;
		H = (Ticks/60)/60;

		H1 = H%10 ;
		H2 = H/10 ;

		M1 = M%10 ;
		M2 = M/10 ;

		S1 = S%10 ;
		S2 = S/10 ;

		DIO_SetPinLevel(CLK_E1,DIO_LOW);
		DIO_SetPinLevel(CLK_E6,DIO_HIGH);
		DIO_SetPinLevel(CLK_E5,DIO_LOW);
		DIO_SetPinLevel(CLK_E4,DIO_LOW);
		DIO_SetPinLevel(CLK_E3,DIO_LOW);
		DIO_SetPinLevel(CLK_E2,DIO_LOW);
		DIO_SetPinLevel(CLK_E1,DIO_LOW);

		Clk_Display(S1);
		_delay_ms(ClK_DELAY);


		DIO_SetPinLevel(CLK_E6,DIO_LOW);
		DIO_SetPinLevel(CLK_E5,DIO_HIGH);
		DIO_SetPinLevel(CLK_E4,DIO_LOW);
		DIO_SetPinLevel(CLK_E3,DIO_LOW);
		DIO_SetPinLevel(CLK_E2,DIO_LOW);
		DIO_SetPinLevel(CLK_E1,DIO_LOW);

		Clk_Display(S2);
		_delay_ms(ClK_DELAY);


		DIO_SetPinLevel(CLK_E6,DIO_LOW);
		DIO_SetPinLevel(CLK_E5,DIO_LOW);
		DIO_SetPinLevel(CLK_E4,DIO_HIGH);
		DIO_SetPinLevel(CLK_E3,DIO_LOW);
		DIO_SetPinLevel(CLK_E2,DIO_LOW);
		DIO_SetPinLevel(CLK_E1,DIO_LOW);

		Clk_Display(M1);
		_delay_ms(ClK_DELAY);


		DIO_SetPinLevel(CLK_E6,DIO_LOW);
		DIO_SetPinLevel(CLK_E5,DIO_LOW);
		DIO_SetPinLevel(CLK_E4,DIO_LOW);
		DIO_SetPinLevel(CLK_E3,DIO_HIGH);
		DIO_SetPinLevel(CLK_E2,DIO_LOW);
		DIO_SetPinLevel(CLK_E1,DIO_LOW);

		Clk_Display(M2);
		_delay_ms(ClK_DELAY);

		DIO_SetPinLevel(CLK_E6,DIO_LOW);
		DIO_SetPinLevel(CLK_E5,DIO_LOW);
		DIO_SetPinLevel(CLK_E4,DIO_LOW);
		DIO_SetPinLevel(CLK_E3,DIO_LOW);
		DIO_SetPinLevel(CLK_E2,DIO_HIGH);
		DIO_SetPinLevel(CLK_E1,DIO_LOW);
		Clk_Display(H1);
		_delay_ms(ClK_DELAY);

		DIO_SetPinLevel(CLK_E6,DIO_LOW);
		DIO_SetPinLevel(CLK_E5,DIO_LOW);
		DIO_SetPinLevel(CLK_E4,DIO_LOW);
		DIO_SetPinLevel(CLK_E3,DIO_LOW);
		DIO_SetPinLevel(CLK_E2,DIO_LOW);
		DIO_SetPinLevel(CLK_E1,DIO_HIGH);
		Clk_Display(H2);
		_delay_ms(ClK_DELAY);
		// GIE_voidEnable ();




}

login_state Login_Verfiy(){

	u8 result ;
	result = UART_Receive_Data();
	if (result=='Y')
		return	LOGIN_SUCCESS ;
	else if (result=='N')
		return  LOGIN_FAILED ;
	else return LOGIN_NOTYET ;
}
void Heating_System_Init(){

	DIO_SetPinMode(DIO_PORTC,DIO_PIN0,DIO_OUTPUT);
	DIO_SetPinMode(DIO_PORTC,DIO_PIN1,DIO_OUTPUT);
	DIO_SetPinMode(DIO_PORTD,DIO_PIN5,DIO_OUTPUT);
	Clk_Init();
	UART_init();
	LM35_voidInit();
	LM35_voidStart_Reading();
	Heater_voidInit();
	Buzzer_voidInit();
	SSD_Init();
	GIE_voidEnable();

}


