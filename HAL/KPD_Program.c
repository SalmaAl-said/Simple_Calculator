 /******************************************************************************
 *
 * Module: keypad
 *
 * File Name: KPD_Program.c
 *
 * Author: Salma Al-said
 *
 * created date : 23/9/2023
 *
 *******************************************************************************/


#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "DIO_Interface.h"
#include "KPD_Config.h"
#include "KPD_Private.h"
#include "KPD_Interface.h"


static u8 KPD_AU8_ROWS_PINS [KPD_ROWS]= { ROW_PIN0 , ROW_PIN1 , ROW_PIN2 , ROW_PIN3 } ;
static u8 KPD_AU8_COLS_PINS [KPD_COLS]= { COL_PIN0 , COL_PIN1 , COL_PIN2 , COL_PIN3 } ;


/******************************************************************************
*                             FUNCTIONS IMPLEMENTATION                        *
******************************************************************************/

void KPD_Init()
{
	u8 COL_Index , ROW_Index ;

	for( COL_Index = 0 ; COL_Index < KPD_COLS ; COL_Index ++ )
	{
		DIO_U8_Set_Pin_Dir( COL_PORT  , KPD_AU8_COLS_PINS[COL_Index] , DIO_U8_OUTPUT  ) ;
	}

	for ( ROW_Index = 0 ; ROW_Index < KPD_ROWS ; ROW_Index ++ )
	{
		DIO_U8_Set_Pin_Dir( ROW_PORT  , KPD_AU8_ROWS_PINS[ROW_Index] , DIO_U8_INPUT ) ;
		DIO_U8_Set_Pin_Val( ROW_PORT  , KPD_AU8_ROWS_PINS[ROW_Index] , DIO_U8_HIGH ) ;
	}
}


u8 KPD_Void_GET_Status (  )
{
	u8 COL_Index , ROW_Index ;
	u8  KPD_Status , Presskey = KPD_Key_NotPressed ;
	static u8 KPD_ARR [KPD_ROWS][KPD_COLS] = KPD_ARR_VAL ;

	for( COL_Index = 0 ; COL_Index < KPD_COLS ; COL_Index ++ )
	{
		DIO_U8_Set_Pin_Val( COL_PORT , KPD_AU8_COLS_PINS[COL_Index] , DIO_U8_LOW  ) ;

		for ( ROW_Index = 0 ; ROW_Index < KPD_ROWS ; ROW_Index ++ )
		{
			// Key_Num = COL_Index + ( ROW_Index * KPD_ROWS ) ;
			DIO_U8_Get_Pin_Value ( ROW_PORT , KPD_AU8_ROWS_PINS[ROW_Index] , &KPD_Status ) ;

			if ( KPD_Status == KPD_Key_Pressed )
			{
				Presskey = KPD_ARR[ROW_Index][COL_Index] ;

			while (KPD_Status == KPD_Key_Pressed)
			{
				DIO_U8_Get_Pin_Value ( ROW_PORT , KPD_AU8_ROWS_PINS[ROW_Index] , &KPD_Status ) ;
			}
			return Presskey ;
			}

		}

		DIO_U8_Set_Pin_Val( COL_PORT , KPD_AU8_COLS_PINS[COL_Index] , DIO_U8_HIGH ) ;
	}
	return Presskey ;
}
