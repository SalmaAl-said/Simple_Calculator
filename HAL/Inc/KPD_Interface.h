 /******************************************************************************
 *
 * Module: keypad
 *
 * File Name: KPD_Interface.h
 *
 * Author: Salma Al-said
 *
 * created date : 23/9/2023
 *
 *******************************************************************************/

#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_

#define KPD_ROWS     4
#define KPD_COLS     4

#define KPD_Key_Pressed       0
#define KPD_Key_NotPressed    1

#define KPD_Keys     KPD_ROWS*KPD_COLS


/******************************************************************************
*                             FUNCTIONS PROTOTYPES                            *
******************************************************************************/

void KPD_Init() ;
u8 KPD_Void_GET_Status (  ) ;

#endif /* KPD_INTERFACE_H_ */
