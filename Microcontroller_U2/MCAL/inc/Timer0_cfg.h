/*
 * Timer0_cfg.h
 *
 *  Created on: Sep 21, 2022
 *      Author: Dell
 */

#ifndef TIMER0_DRIVER_TIMER0_CFG_H_
#define TIMER0_DRIVER_TIMER0_CFG_H_

/*
  TIMER0_OPERATION_MODE ->  TIMER0_NORMAL_OPERATION_MODE
 	 	 	 	 	 	->  TIMER0_CTC_OPERATION_MODE
 	 	 	 	 	    ->	TIMER0_PWM_OPERATION_MODE
 */
#define TIMER0_OPERATION_MODE 	 TIMER0_CTC_OPERATION_MODE


/*
TIMER0_CMP_MATCH_OUT_MODE -> TIMER0_NORMAL_PORT_OPERATION_MODE
 	 	 	 	   	      -> TIMER0_TGL_PORT_OPERATION_MODE
 	 	 	 	   	   	  -> TIMER0_CLR_PORT_OPERATION_MODE
 	 	 	 	   	   	  -> TIMER0_SET_PORT_OPERATION_MODE
 */
#define TIMER0_CMP_MATCH_OUT_MODE	TIMER0_NORMAL_PORT_OPERATION_MODE


/*
 TIMER0_PRESCALER_MODE -> 	TIMER0_PRESCALER_1_MODE
					   ->	TIMER0_PRESCALER_8_MODE
 	 	 	 	 	   ->	TIMER0_PRESCALER_64_MODE
 	 	 	 	 	   ->	TIMER0_PRESCALER_256_MODE
 	 	 	 	 	   -> 	TIMER0_PRESCALER_1024_MODE
 	 	 	 	 	   ->	TIMER0_PRESCALER_EXT_CLK_FE_MODE
 	 	 	 	 	   ->	TIMER0_PRESCALER_EXT_CLK_RE_MODE
 */
#define TIMER0_PRESCALER_MODE	TIMER0_PRESCALER_1024_MODE

/*
TIMER0_INTERTUPT_MODE-> TIMER0_INTERRUPT_ENABLE_MODE
 	 	 	 	 	 -> TIMER0_INTERRUPT_DISABLE_MODE
 */
#define TIMER0_INTERTUPT_MODE	TIMER0_INTERRUPT_ENABLE_MODE

#endif /* TIMER0_DRIVER_TIMER0_CFG_H_ */
