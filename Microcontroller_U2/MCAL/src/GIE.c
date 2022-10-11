/*
 * GIE.c
 *
 *  Created on: Sep 13, 2022
 *      Author: Dell
 */
#include "macros.h"
#include "GIE_priv.h"
#include "GIE_interface.h"
#include "std_types.h"

void GIE_voidEnable (void){
SET_BIT(SREG,I_BIT);
}

void GIE_voidDisable(void){
CLR_BIT(SREG,I_BIT);
}


