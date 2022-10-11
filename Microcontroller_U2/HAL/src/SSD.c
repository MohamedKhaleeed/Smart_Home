/*
 * SSD.c
 *
 *  Created on: Aug 25, 2022
 *      Author: ahmad
 */


#include "std_types.h"
#include "macros.h"
#include "DIO_interface.h"
#include "SSD_interface.h"
#include "SSD_cfg.h"
#include "SSD_priv.h"


void SSD_Init(void) {
	#if SSD_CONNECTION_TYPE	== WITHOUT_DECODER
    DIO_SetPinMode(SSD_PIN_A, DIO_OUTPUT);
    DIO_SetPinMode(SSD_PIN_B, DIO_OUTPUT);
    DIO_SetPinMode(SSD_PIN_C, DIO_OUTPUT);
    DIO_SetPinMode(SSD_PIN_D, DIO_OUTPUT);
    DIO_SetPinMode(SSD_PIN_E, DIO_OUTPUT);
    DIO_SetPinMode(SSD_PIN_F, DIO_OUTPUT);
    DIO_SetPinMode(SSD_PIN_G, DIO_OUTPUT);

	#elif SSD_CONNECTION_TYPE	== WITH_DECODER
    DIO_SetPinMode(SSD_DEC_PIN_A,DIO_OUTPUT);
    DIO_SetPinMode(SSD_DEC_PIN_B,DIO_OUTPUT);
    DIO_SetPinMode(SSD_DEC_PIN_C,DIO_OUTPUT);
    DIO_SetPinMode(SSD_DEC_PIN_D,DIO_OUTPUT);
	#endif

}

void SSD_Write (SSD_NumberType number) {
#if SSD_TYPE == SSD_COMM_CATHODE
	#if SSD_CONNECTION_TYPE	== WITHOUT_DECODER
		switch(number){
	case SSD_NUMBER_0 :		DIO_SetPinLevel(SSD_PIN_A, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_B, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_C, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_D, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_E, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_F, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_G, DIO_LOW);
							break ;

	case SSD_NUMBER_1 :		DIO_SetPinLevel(SSD_PIN_A, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_B, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_C, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_D, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_E, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_F, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_G, DIO_LOW);
							break ;

	case SSD_NUMBER_2 : 	DIO_SetPinLevel(SSD_PIN_A, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_B, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_C, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_D, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_E, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_F, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_G, DIO_HIGH);
							break ;

	case SSD_NUMBER_3 : 	DIO_SetPinLevel(SSD_PIN_A, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_B, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_C, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_D, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_E, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_F, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_G, DIO_HIGH);
							break ;

	case SSD_NUMBER_4 : 	DIO_SetPinLevel(SSD_PIN_A, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_B, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_C, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_D, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_E, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_F, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_G, DIO_HIGH);
							break ;

	case SSD_NUMBER_5 : 	DIO_SetPinLevel(SSD_PIN_A, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_B, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_C, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_D, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_E, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_F, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_G, DIO_HIGH);
							break ;

	case SSD_NUMBER_6 : 	DIO_SetPinLevel(SSD_PIN_A, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_B, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_C, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_D, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_E, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_F, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_G, DIO_HIGH);
							break ;

	case SSD_NUMBER_7 : 	DIO_SetPinLevel(SSD_PIN_A, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_B, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_C, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_D, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_E, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_F, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_G, DIO_LOW);
							break ;

	case SSD_NUMBER_8 : 	DIO_SetPinLevel(SSD_PIN_A, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_B, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_C, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_D, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_E, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_F, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_G, DIO_HIGH);
							break ;

	case SSD_NUMBER_9 : 	DIO_SetPinLevel(SSD_PIN_A, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_B, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_C, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_D, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_E, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_F, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_G, DIO_HIGH);
							break ;

	default  		   :	DIO_SetPinLevel(SSD_PIN_A, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_B, DIO_LOW);
						 	DIO_SetPinLevel(SSD_PIN_C, DIO_LOW);
						 	DIO_SetPinLevel(SSD_PIN_D, DIO_LOW);
						 	DIO_SetPinLevel(SSD_PIN_E, DIO_LOW);
						 	DIO_SetPinLevel(SSD_PIN_F, DIO_LOW);
						 	DIO_SetPinLevel(SSD_PIN_G, DIO_LOW);
		}


	#elif (SSD_CONNECTION_TYPE	== WITH_DECODER)

		switch(number)
	{
		case SSD_NUMBER_0 :		DIO_SetPinLevel(SSD_DEC_PIN_A, DIO_LOW);
								DIO_SetPinLevel(SSD_DEC_PIN_B, DIO_LOW);
								DIO_SetPinLevel(SSD_DEC_PIN_C, DIO_LOW);
								DIO_SetPinLevel(SSD_DEC_PIN_D, DIO_LOW);
								break ;

		case SSD_NUMBER_1 :		DIO_SetPinLevel(SSD_DEC_PIN_A, DIO_HIGH);
								DIO_SetPinLevel(SSD_DEC_PIN_B, DIO_LOW);
								DIO_SetPinLevel(SSD_DEC_PIN_C, DIO_LOW);
								DIO_SetPinLevel(SSD_DEC_PIN_D, DIO_LOW);


								break ;

		case SSD_NUMBER_2 : 	DIO_SetPinLevel(SSD_DEC_PIN_A, DIO_LOW);
								DIO_SetPinLevel(SSD_DEC_PIN_B, DIO_HIGH);
								DIO_SetPinLevel(SSD_DEC_PIN_C, DIO_LOW);
								DIO_SetPinLevel(SSD_DEC_PIN_D, DIO_LOW);
								break ;

		case SSD_NUMBER_3 : 	DIO_SetPinLevel(SSD_DEC_PIN_A, DIO_HIGH);
								DIO_SetPinLevel(SSD_DEC_PIN_B, DIO_HIGH);
								DIO_SetPinLevel(SSD_DEC_PIN_C, DIO_LOW);
								DIO_SetPinLevel(SSD_DEC_PIN_D, DIO_LOW);

								break ;

		case SSD_NUMBER_4 : 	DIO_SetPinLevel(SSD_DEC_PIN_A, DIO_LOW);
								DIO_SetPinLevel(SSD_DEC_PIN_B, DIO_LOW);
								DIO_SetPinLevel(SSD_DEC_PIN_C, DIO_HIGH);
								DIO_SetPinLevel(SSD_DEC_PIN_D, DIO_LOW);
								break ;

		case SSD_NUMBER_5 : 	DIO_SetPinLevel(SSD_DEC_PIN_A, DIO_HIGH);
								DIO_SetPinLevel(SSD_DEC_PIN_B, DIO_LOW);
								DIO_SetPinLevel(SSD_DEC_PIN_C, DIO_HIGH);
								DIO_SetPinLevel(SSD_DEC_PIN_D, DIO_LOW);
								break ;

		case SSD_NUMBER_6 : 	DIO_SetPinLevel(SSD_DEC_PIN_A, DIO_LOW);
								DIO_SetPinLevel(SSD_DEC_PIN_B, DIO_HIGH);
								DIO_SetPinLevel(SSD_DEC_PIN_C, DIO_HIGH);
								DIO_SetPinLevel(SSD_DEC_PIN_D, DIO_LOW);
								break ;

		case SSD_NUMBER_7 : 	DIO_SetPinLevel(SSD_DEC_PIN_A, DIO_HIGH);
								DIO_SetPinLevel(SSD_DEC_PIN_B, DIO_HIGH);
								DIO_SetPinLevel(SSD_DEC_PIN_C, DIO_HIGH);
								DIO_SetPinLevel(SSD_DEC_PIN_D, DIO_LOW);
								break ;

		case SSD_NUMBER_8 : 	DIO_SetPinLevel(SSD_DEC_PIN_A, DIO_LOW);
								DIO_SetPinLevel(SSD_DEC_PIN_B, DIO_LOW);
								DIO_SetPinLevel(SSD_DEC_PIN_C, DIO_LOW);
								DIO_SetPinLevel(SSD_DEC_PIN_D, DIO_HIGH);
								break ;

		case SSD_NUMBER_9 : 	DIO_SetPinLevel(SSD_DEC_PIN_A, DIO_HIGH);
								DIO_SetPinLevel(SSD_DEC_PIN_B, DIO_LOW);
								DIO_SetPinLevel(SSD_DEC_PIN_C, DIO_LOW);
								DIO_SetPinLevel(SSD_DEC_PIN_D, DIO_HIGH);
								break ;

		default  		   :	DIO_SetPinLevel(SSD_DEC_PIN_A, DIO_LOW);
								DIO_SetPinLevel(SSD_DEC_PIN_B, DIO_LOW);
								DIO_SetPinLevel(SSD_DEC_PIN_C, DIO_LOW);
								DIO_SetPinLevel(SSD_DEC_PIN_D, DIO_LOW);
			}
#else
#error "Invalid SSD Connection Type"
#endif


	#elif SSD_TYPE == SSD_COMM_ANODE
		#if SSD_CONNECTION_TYPE	== WITHOUT_DECODER
		switch(number){
	case SSD_NUMBER_0 :		DIO_SetPinLevel(SSD_PIN_A,DIO_LOW );
							DIO_SetPinLevel(SSD_PIN_B, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_C, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_D, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_E, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_F, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_G, DIO_HIGH);
							break ;

	case SSD_NUMBER_1 :		DIO_SetPinLevel(SSD_PIN_A, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_B, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_C, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_D, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_E, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_F, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_G, DIO_HIGH);
							break ;

	case SSD_NUMBER_2 : 	DIO_SetPinLevel(SSD_PIN_A, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_B, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_C, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_D, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_E, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_F, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_G, DIO_LOW);
							break ;

	case SSD_NUMBER_3 : 	DIO_SetPinLevel(SSD_PIN_A, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_B, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_C, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_D, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_E, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_F, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_G, DIO_LOW);
							break ;

	case SSD_NUMBER_4 : 	DIO_SetPinLevel(SSD_PIN_A, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_B, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_C, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_D, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_E, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_F, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_G, DIO_LOW);
							break ;

	case SSD_NUMBER_5 : 	DIO_SetPinLevel(SSD_PIN_A, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_B, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_C, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_D, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_E, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_F, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_G, DIO_LOW);
							break ;

	case SSD_NUMBER_6 : 	DIO_SetPinLevel(SSD_PIN_A,DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_B, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_C, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_D, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_E, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_F, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_G, DIO_LOW);
							break ;

	case SSD_NUMBER_7 :     DIO_SetPinLevel(SSD_PIN_A, DIO_LOW);
						    DIO_SetPinLevel(SSD_PIN_B, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_C, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_D, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_E, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_F, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_G, DIO_HIGH);
							break ;

	case SSD_NUMBER_8 : 	DIO_SetPinLevel(SSD_PIN_A, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_B, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_C, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_D, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_E, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_F, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_G, DIO_LOW);
							break ;

	case SSD_NUMBER_9 : 	DIO_SetPinLevel(SSD_PIN_A, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_B, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_C, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_D, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_E, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_F, DIO_LOW);
							DIO_SetPinLevel(SSD_PIN_G, DIO_LOW);
							break ;

	default  		   : 	DIO_SetPinLevel(SSD_PIN_A, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_B, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_C, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_D, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_E, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_F, DIO_HIGH);
							DIO_SetPinLevel(SSD_PIN_G, DIO_HIGH);
		}

	#elif SSD_CONNECTION_TYPE	== WITH_DECODER

		switch(number)
	{
		case SSD_NUMBER_0 :		DIO_SetPinLevel(SSD_DEC_PIN_A, DIO_LOW);
								DIO_SetPinLevel(SSD_DEC_PIN_B, DIO_LOW);
								DIO_SetPinLevel(SSD_DEC_PIN_C, DIO_LOW);
								DIO_SetPinLevel(SSD_DEC_PIN_D, DIO_LOW);
								break ;

		case SSD_NUMBER_1 :		DIO_SetPinLevel(SSD_DEC_PIN_A, DIO_HIGH);
								DIO_SetPinLevel(SSD_DEC_PIN_B, DIO_LOW);
								DIO_SetPinLevel(SSD_DEC_PIN_C, DIO_LOW);
								DIO_SetPinLevel(SSD_DEC_PIN_D, DIO_LOW);

								break ;

		case SSD_NUMBER_2 : 	DIO_SetPinLevel(SSD_DEC_PIN_A, DIO_LOW);
								DIO_SetPinLevel(SSD_DEC_PIN_B, DIO_HIGH);
								DIO_SetPinLevel(SSD_DEC_PIN_C, DIO_LOW);
								DIO_SetPinLevel(SSD_DEC_PIN_D, DIO_LOW);
								break ;

		case SSD_NUMBER_3 : 	DIO_SetPinLevel(SSD_DEC_PIN_A, DIO_HIGH);
								DIO_SetPinLevel(SSD_DEC_PIN_B, DIO_HIGH);
								DIO_SetPinLevel(SSD_DEC_PIN_C, DIO_LOW);
								DIO_SetPinLevel(SSD_DEC_PIN_D, DIO_LOW);
								break ;

		case SSD_NUMBER_4 : 	DIO_SetPinLevel(SSD_DEC_PIN_A, DIO_LOW);
								DIO_SetPinLevel(SSD_DEC_PIN_B, DIO_LOW);
								DIO_SetPinLevel(SSD_DEC_PIN_C, DIO_HIGH);
								DIO_SetPinLevel(SSD_DEC_PIN_D, DIO_LOW);
								break ;

		case SSD_NUMBER_5 : 	DIO_SetPinLevel(SSD_DEC_PIN_A, DIO_HIGH);
								DIO_SetPinLevel(SSD_DEC_PIN_B, DIO_LOW);
								DIO_SetPinLevel(SSD_DEC_PIN_C, DIO_HIGH);
								DIO_SetPinLevel(SSD_DEC_PIN_D, DIO_LOW);
								break ;

		case SSD_NUMBER_6 : 	DIO_SetPinLevel(SSD_DEC_PIN_A, DIO_LOW);
								DIO_SetPinLevel(SSD_DEC_PIN_B, DIO_HIGH);
								DIO_SetPinLevel(SSD_DEC_PIN_C, DIO_HIGH);
								DIO_SetPinLevel(SSD_DEC_PIN_D, DIO_LOW);
								break ;

		case SSD_NUMBER_7 : 	DIO_SetPinLevel(SSD_DEC_PIN_A, DIO_HIGH);
								DIO_SetPinLevel(SSD_DEC_PIN_B, DIO_HIGH);
								DIO_SetPinLevel(SSD_DEC_PIN_C, DIO_HIGH);
								DIO_SetPinLevel(SSD_DEC_PIN_D, DIO_LOW);
								break ;

		case SSD_NUMBER_8 : 	DIO_SetPinLevel(SSD_DEC_PIN_A, DIO_LOW);
								DIO_SetPinLevel(SSD_DEC_PIN_B, DIO_LOW);
								DIO_SetPinLevel(SSD_DEC_PIN_C, DIO_LOW);
								DIO_SetPinLevel(SSD_DEC_PIN_D, DIO_HIGH);
								break ;

		case SSD_NUMBER_9 : 	DIO_SetPinLevel(SSD_DEC_PIN_A, DIO_HIGH);
								DIO_SetPinLevel(SSD_DEC_PIN_B, DIO_LOW);
								DIO_SetPinLevel(SSD_DEC_PIN_C, DIO_LOW);
								DIO_SetPinLevel(SSD_DEC_PIN_D, DIO_HIGH);
								break ;

		default  		   :	DIO_SetPinLevel(SSD_DEC_PIN_A, DIO_LOW);
								DIO_SetPinLevel(SSD_DEC_PIN_B, DIO_LOW);
								DIO_SetPinLevel(SSD_DEC_PIN_C, DIO_LOW);
								DIO_SetPinLevel(SSD_DEC_PIN_D, DIO_LOW);
			}
#else
#error "Invalid SSD Connection Type"
#endif

#else
#error "Invalid SSD Type"
#endif
}



