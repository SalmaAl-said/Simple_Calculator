 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: LCD_Program.c
 *
 * Author: Salma Al-said
 *
 * created date : 16/9/2023
 *
 *******************************************************************************/

#include "STD_TYPES.h"
#include  "BIT_CALC.h"
#include <util/delay.h>
#include "DIO_Interface.h"
#include "LCD_Config.h"
#include "LCD_Private.h"
#include "LCD_Interface.h"


/******************************************************************************
*                             FUNCTIONS IMPLEMENTATION                        *
******************************************************************************/

void LCD_Void_Init (void)
{
	DIO_U8_Set_Pin_Dir( LCD_U8_CTRL_PORT  , LCD_U8_RS_PIN , DIO_U8_OUTPUT  ) ;
	DIO_U8_Set_Pin_Dir( LCD_U8_CTRL_PORT  , LCD_U8_RW_PIN , DIO_U8_OUTPUT  ) ;
	DIO_U8_Set_Pin_Dir( LCD_U8_CTRL_PORT  , LCD_U8_E_PIN , DIO_U8_OUTPUT  ) ;
	DIO_U8_Set_Port_Dir( LCD_U8_DATA_PORT , 0xff ) ;
	_delay_ms(40);
	LCD_Void_Write_CMD (0b00111000);
	_delay_us(50);
	LCD_Void_Write_CMD (0b00001100);
	_delay_us(50);
	LCD_Void_Write_CMD (0b00000001);
	_delay_ms(2);

}

void LCD_Void_Write_CMD ( u8 Copy_u8_cmd )
{
	DIO_U8_Set_Pin_Val( LCD_U8_CTRL_PORT , LCD_U8_RS_PIN  , DIO_U8_LOW  ) ;
	LCD_Void_Write( Copy_u8_cmd ) ;
}


void LCD_Void_Write_Data ( u8 Copy_u8_data )
{
	DIO_U8_Set_Pin_Val( LCD_U8_CTRL_PORT , LCD_U8_RS_PIN  , DIO_U8_HIGH  ) ;
	LCD_Void_Write( Copy_u8_data ) ;
}

void LCD_Void_Write ( u8 Copy_u8_Val )
{
	DIO_U8_Set_Pin_Val( LCD_U8_CTRL_PORT , LCD_U8_RW_PIN   , DIO_U8_LOW   ) ;

	DIO_U8_Set_Pin_Val( LCD_U8_DATA_PORT  , LCD_U8_DATA_PIN0   , GET_BIT(Copy_u8_Val,0)  ) ;
	DIO_U8_Set_Pin_Val( LCD_U8_DATA_PORT  , LCD_U8_DATA_PIN1   , GET_BIT(Copy_u8_Val,1)  ) ;
	DIO_U8_Set_Pin_Val( LCD_U8_DATA_PORT  , LCD_U8_DATA_PIN2   , GET_BIT(Copy_u8_Val,2)  ) ;
	DIO_U8_Set_Pin_Val( LCD_U8_DATA_PORT  , LCD_U8_DATA_PIN3   , GET_BIT(Copy_u8_Val,3)  ) ;
	DIO_U8_Set_Pin_Val( LCD_U8_DATA_PORT  , LCD_U8_DATA_PIN4   , GET_BIT(Copy_u8_Val,4)  ) ;
	DIO_U8_Set_Pin_Val( LCD_U8_DATA_PORT  , LCD_U8_DATA_PIN5   , GET_BIT(Copy_u8_Val,5)  ) ;
	DIO_U8_Set_Pin_Val( LCD_U8_DATA_PORT  , LCD_U8_DATA_PIN6   , GET_BIT(Copy_u8_Val,6)  ) ;
	DIO_U8_Set_Pin_Val( LCD_U8_DATA_PORT  , LCD_U8_DATA_PIN7   , GET_BIT(Copy_u8_Val,7)  ) ;

	DIO_U8_Set_Pin_Val( LCD_U8_CTRL_PORT  , LCD_U8_E_PIN   , DIO_U8_HIGH   ) ;
	_delay_ms(1);
	DIO_U8_Set_Pin_Val( LCD_U8_CTRL_PORT  , LCD_U8_E_PIN   , DIO_U8_LOW   ) ;


}

void LCD_Write_Str ( u8 * str ,u8 x_pos , u8 y_pos )
{
	LCD_MoveCursor (  x_pos ,  y_pos ) ;
	while ( *str != '\0')
	{
		if ( (x_pos == 16 ) && ( y_pos == 0 ))
		{
			LCD_MoveCursor ( 0 , 1 ) ;
		}
		if ( (x_pos == 16 ) && ( y_pos == 1 ) )
		{
			LCD_MoveCursor ( 0 , 0 ) ;
		}
		LCD_Void_Write_Data( *str ) ;
		str ++ ;
		x_pos++ ;

	}

}

void LCD_MoveCursor ( u8 x_pos , u8 y_pos )
{
	u8 DDRAM_Adress = x_pos + ( 64*y_pos) ;
	DDRAM_Adress = DDRAM_Adress | 0b10000000;
	LCD_Void_Write_CMD( DDRAM_Adress );
}



void LCD_Write_Num ( u32 Num ,u8 x_pos , u8 y_pos )
{
	u8 Rem , index = 0 ;
	u8 arr[20];

	if (Num==0)
	{
		arr[index]='0';
		index++;
	}


	while (Num!=0)
	{
		Rem = Num % 10 ;
		arr[index]= Rem + '0' ;
		index++;
		Num /= 10 ;
	}
	arr[index]='\0';
	reverse (arr , index );
	LCD_Write_Str ( arr , x_pos ,  y_pos ) ;

}

void reverse (u8 * ptr , u8 element )
{
	u8 start =0 ;
	u8 end = element - 1 ;

	while (start < end)
	{

		//Swap
		 u32 temp = ptr[start];
		 ptr[start] = ptr[end];
		 ptr[end] = temp;

	start++;
	end--;
	}
}

void LCD_SET_CGRAM ( u8 address )
{
	u8 CGRAM_Address = ( 0b01000000 | address ) ;
	LCD_Void_Write_CMD( CGRAM_Address );
}

void LCD_Disdlay_Clear ()
{
	LCD_Void_Write_CMD( 0b00000001 );
}




