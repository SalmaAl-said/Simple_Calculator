 /******************************************************************************
 *
 * Module: keypad
 *
 * File Name: KPD_Config.h
 *
 * Author: Salma Al-said
 *
 * created date : 23/9/2023
 *
 *******************************************************************************/

#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_


/******************************************************************************
*                                Definitions                                  *
******************************************************************************/


#define ROW_PORT     PORT_A
#define ROW_PIN0 	 PIN_0
#define ROW_PIN1 	 PIN_1
#define ROW_PIN2 	 PIN_2
#define ROW_PIN3 	 PIN_3

#define COL_PORT     PORT_A
#define COL_PIN0 	 PIN_4
#define COL_PIN1 	 PIN_5
#define COL_PIN2 	 PIN_6
#define COL_PIN3 	 PIN_7


#define KPD_ARR_VAL      {{'7', '8', '9', '/'}, {'4', '5', '6', '*'}, {'1', '2', '3', '-'}, {'c', '0', '=', '+'}}
#endif /* KPD_CONFIG_H_ */
