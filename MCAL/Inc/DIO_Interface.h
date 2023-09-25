/*
 * DIO_Interface.h
 *
 *  Created on: Sep 8, 2023
 *      Author: spider
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define PORT_A      0
#define PORT_B      1
#define PORT_C      2
#define PORT_D      3

#define PIN_0       0
#define PIN_1       1
#define PIN_2       2
#define PIN_3       3
#define PIN_4       4
#define PIN_5       5
#define PIN_6       6
#define PIN_7       7

#define DIO_U8_LOW    0
#define DIO_U8_HIGH   1

#define DIO_U8_INPUT    0
#define DIO_U8_OUTPUT   1



#define NO_Wrong          0
#define Wrong_port_ID     1
#define Wrong_pin_ID      2
#define Wrong_dir_ID      3
#define Wrong_Val_ID      4



u8 DIO_U8_Set_Pin_Dir( u8 Copy_U8_Port_ID , u8 Copy_U8_Pin_ID , u8 Copy_U8_Dir_ID ) ;
u8 DIO_U8_Set_Pin_Val( u8 Copy_U8_Port_ID , u8 Copy_U8_Pin_ID , u8 Copy_U8_Val_ID ) ;
u8 DIO_U8_Set_Port_Dir( u8 Copy_U8_Port_ID ,  u8 Copy_U8_Dir_ID ) ;
u8 DIO_U8_Set_Port_Val( u8 Copy_U8_Port_ID ,  u8 Copy_U8_Val_ID ) ;
u8 DIO_U8_Get_Pin_Value ( u8 Copy_U8_Port_ID , u8 Copy_U8_Pin_ID , u8 *Copy_U8_Pin_Val );


#endif /* DIO_INTERFACE_H_ */
