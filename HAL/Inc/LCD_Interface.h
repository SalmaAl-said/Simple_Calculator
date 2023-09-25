 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: LCD_Interface.h
 *
 * Author: Salma Al-said
 *
 * created date : 16/9/2023
 *
 *******************************************************************************/

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_



/******************************************************************************
*                             FUNCTIONS PROTOTYPES                            *
******************************************************************************/

void LCD_Void_Init (void) ;

void LCD_Void_Write_CMD ( u8 Copy_u8_cmd ) ;

void LCD_Void_Write_Data ( u8 Copy_u8_data ) ;

void LCD_Void_Write ( u8 Copy_u8_Val ) ;

void LCD_Write_Str ( u8 * str ,u8 x_pos , u8 y_pos ) ;

void LCD_MoveCursor ( u8 x_pos , u8 y_pos ) ;

void LCD_Write_Num ( u32 Num ,u8 x_pos , u8 y_pos ) ;

void reverse (u8 * ptr , u8 element );

void LCD_SET_CGRAM ( u8 address ) ;

void LCD_Disdlay_Clear () ;

void LCD_char( u8 * arr ) ;


#endif /* LCD_INTERFACE_H_ */
