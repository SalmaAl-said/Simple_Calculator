/******************************************************************************
 *
 * Module: application
 *
 * File Name: main.c
 *
 * Author: Salma Al-said
 *
 * created date : 24/9/2023
 *
 *******************************************************************************/


#include"STD_TYPES.h"
#include"BIT_CALC.h"
#include"DIO_Interface.h"
#include"KPD_Interface.h"
#include"LCD_Interface.h"
#include "util/delay.h"

int main (void)
{


	LCD_Void_Init () ;
	KPD_Init() ;

	LCD_Write_Str ( "Welcome" , 4 , 0 ) ;
	LCD_Write_Str ( "Calculator" , 3 , 1 ) ;
	_delay_ms(2000);
	LCD_Disdlay_Clear () ;

	u8 PressKey = KPD_Key_NotPressed , operator = 0 ;
	u32 Num1=0 ,Num2=0 , Res=0 ;
	u8 Counter_n1 = 0 , counter_n2 = 0 ;

	while(1)
	{
		PressKey = KPD_Void_GET_Status ( ) ;

		if ( PressKey >= '0' && PressKey <= '9')
		{
			LCD_Void_Write_Data ( PressKey ) ;
			if ( operator == 0 )
			{
				Num1= Num1*10 + ( PressKey - '0') ;
				Counter_n1++ ;
			}
			else
			{
				Num2= Num2*10 + ( PressKey - '0') ;
				counter_n2++;
			}
		}
		else if ( PressKey=='+' || PressKey=='-' || PressKey=='*' || PressKey=='/' )
		{
			LCD_Void_Write_Data ( PressKey ) ;
			operator = PressKey ;
		}
		else if ( PressKey == '=')
		{
			LCD_Void_Write_Data ( PressKey ) ;
			switch ( operator )
			{
			case '+' :
				Res = Num1 + Num2 ;
				break;

			case '-' :
				Res = Num1 - Num2 ;
				break;

			case '*' :
				Res = Num1 * Num2 ;
				break;

			case '/' :
				if ( Num2 == 0)
				{
					LCD_Disdlay_Clear () ;
					LCD_Write_Str ( "Math Error" , 3 , 0 ) ;
					continue;
				}
				else
				{
					Res = Num1 / Num2 ;
				}
				break;

			default :
				LCD_Disdlay_Clear () ;
				LCD_Write_Str ( "Invalid Operator" ,0 , 0 ) ;
				continue;
			}
			LCD_Write_Num ( Res ,0 , 1 ) ;
			Num1 = 0;
			Num2 = 0;
			operator = 0;
		}
		else if ( PressKey == 'c')
		{
			LCD_Disdlay_Clear () ;
			Num1 = 0;
			Num2 = 0;
			operator = 0;
		}

	}
}
