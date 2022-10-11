/*
 * test.c
 *
 *  Created on: Sep 22, 2022
 *      Author: Dell
 */
#include "Heating_System_interface.h"

int main (){
	Heating_System_Init();
/*	login_state result ;

	do
	{
		result = Login_Verfiy() ;

	}while(result==LOGIN_NOTYET);



	 if (result==LOGIN_FAILED)
	{
		return 0 ;
	}

*/

//else if (result==LOGIN_SUCCESS)
//		{
			while (1)
			{
				Heating_System_Handle();
				Clock_Handle();
			}
	//	}




}
