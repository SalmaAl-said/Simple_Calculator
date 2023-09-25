/*
 * main.c
 *
 *  Created on: Sep 8, 2023
 *      Author: spider
 */

#include"STD_TYPES.h"
#include"BIT_CALC.h"
#include"DIO_Interface.h"
#include"DIO_Private.h"
#include"DIO_Config.h"


u8 DIO_U8_Set_Pin_Dir( u8 Copy_U8_Port_ID , u8 Copy_U8_Pin_ID , u8 Copy_U8_Dir_ID )
{
	if( ( Copy_U8_Port_ID >= DIO_MIN_U8_PORT_ID  ) && ( Copy_U8_Port_ID <= DIO_MAX_U8_PORT_ID  ) )
	{
		if ( ( Copy_U8_Pin_ID >= DIO_MIN_U8_PIN_ID ) && ( Copy_U8_Pin_ID <= DIO_MAX_U8_PIN_ID  ) )
		{
			if ( ( Copy_U8_Dir_ID == DIO_U8_INPUT ) || ( Copy_U8_Dir_ID == DIO_U8_OUTPUT ))
			{
				switch ( Copy_U8_Port_ID )
				{
				case PORT_A :
					Assign_BIT( DIO_U8_DDRA , Copy_U8_Pin_ID , Copy_U8_Dir_ID  ) ;
					break ;
				case PORT_B :
					Assign_BIT( DIO_U8_DDRB , Copy_U8_Pin_ID , Copy_U8_Dir_ID  ) ;
					break ;
				case PORT_C :
					Assign_BIT( DIO_U8_DDRC , Copy_U8_Pin_ID , Copy_U8_Dir_ID  ) ;
					break ;
				case PORT_D :
					Assign_BIT( DIO_U8_DDRD , Copy_U8_Pin_ID , Copy_U8_Dir_ID  ) ;
					break ;
				}
			}
			else
			{
				return Wrong_dir_ID ;
			}
		}
		else
		{
			return Wrong_pin_ID ;
		}
	}
	else
	{
		return Wrong_port_ID ;
	}

	return NO_Wrong ;
}




u8 DIO_U8_Set_Pin_Val( u8 Copy_U8_Port_ID , u8 Copy_U8_Pin_ID , u8 Copy_U8_Val_ID )
{
	if( ( Copy_U8_Port_ID >= DIO_MIN_U8_PORT_ID  ) && ( Copy_U8_Port_ID <= DIO_MAX_U8_PORT_ID  ) )
	{
		if ( ( Copy_U8_Pin_ID >= DIO_MIN_U8_PIN_ID ) && ( Copy_U8_Pin_ID <= DIO_MAX_U8_PIN_ID  ) )
		{
			if ( ( Copy_U8_Val_ID == DIO_U8_LOW ) || ( Copy_U8_Val_ID == DIO_U8_HIGH ))
			{
				switch ( Copy_U8_Port_ID )
				{
				case PORT_A :
					Assign_BIT( DIO_U8_PORTA , Copy_U8_Pin_ID , Copy_U8_Val_ID  ) ;
					break ;
				case PORT_B :
					Assign_BIT( DIO_U8_PORTB , Copy_U8_Pin_ID , Copy_U8_Val_ID  ) ;
					break ;
				case PORT_C :
					Assign_BIT( DIO_U8_PORTC , Copy_U8_Pin_ID , Copy_U8_Val_ID  ) ;
					break ;
				case PORT_D :
					Assign_BIT( DIO_U8_PORTD , Copy_U8_Pin_ID , Copy_U8_Val_ID  ) ;
					break ;
				}
			}
			else
			{
				return Wrong_Val_ID  ;
			}
		}
		else
		{
			return Wrong_pin_ID ;
		}
	}
	else
	{
		return Wrong_port_ID ;
	}

	return NO_Wrong ;
}




u8 DIO_U8_Set_Port_Dir( u8 Copy_U8_Port_ID ,  u8 Copy_U8_Dir_ID )
{
	if ( ( Copy_U8_Port_ID >= DIO_MIN_U8_PORT_ID  ) && ( Copy_U8_Port_ID <= DIO_MAX_U8_PORT_ID  ))
	{
			switch ( Copy_U8_Port_ID )
				{
				case PORT_A :
					DIO_U8_DDRA = Copy_U8_Dir_ID ;
					break ;
				case PORT_B :
					DIO_U8_DDRB = Copy_U8_Dir_ID ;
					break ;
				case PORT_C :
					DIO_U8_DDRC = Copy_U8_Dir_ID ;
					break ;
				case PORT_D :
					DIO_U8_DDRD = Copy_U8_Dir_ID ;
					break ;
				}

	}
	else
	{
		return Wrong_port_ID ;
	}
	return NO_Wrong ;
}



u8 DIO_U8_Set_Port_Val( u8 Copy_U8_Port_ID ,  u8 Copy_U8_Val_ID )
{
	if ( ( Copy_U8_Port_ID >= DIO_MIN_U8_PORT_ID  ) && ( Copy_U8_Port_ID <= DIO_MAX_U8_PORT_ID  ))
	{
			switch ( Copy_U8_Port_ID )
				{
				case PORT_A :
					DIO_U8_PORTA = Copy_U8_Val_ID ;
					break ;
				case PORT_B :
					DIO_U8_PORTB = Copy_U8_Val_ID ;
					break ;
				case PORT_C :
					DIO_U8_PORTC = Copy_U8_Val_ID ;
					break ;
				case PORT_D :
					DIO_U8_PORTD = Copy_U8_Val_ID ;
					break ;
				}

	}
	else
	{
		return Wrong_port_ID ;
	}
	return NO_Wrong ;
}


u8 DIO_U8_Get_Pin_Value ( u8 Copy_U8_Port_ID , u8 Copy_U8_Pin_ID , u8 *Copy_U8_Pin_Val )
{
	if ( ( Copy_U8_Port_ID >= DIO_MIN_U8_PORT_ID  ) && ( Copy_U8_Port_ID <= DIO_MAX_U8_PORT_ID  ) )
	{
		if ( ( Copy_U8_Pin_ID >= DIO_MIN_U8_PIN_ID ) && ( Copy_U8_Pin_ID <= DIO_MAX_U8_PIN_ID  ) )
		{
			switch ( Copy_U8_Port_ID )
					{
					case PORT_A :
						*Copy_U8_Pin_Val = GET_BIT( DIO_U8_PINA  , Copy_U8_Pin_ID ) ;
						break ;
					case PORT_B :
						*Copy_U8_Pin_Val = GET_BIT( DIO_U8_PINA , Copy_U8_Pin_ID ) ;
						break ;
					case PORT_C :
						*Copy_U8_Pin_Val = GET_BIT( DIO_U8_PINA , Copy_U8_Pin_ID ) ;
						break ;
					case PORT_D :
						*Copy_U8_Pin_Val = GET_BIT( DIO_U8_PINA , Copy_U8_Pin_ID ) ;
						break ;
					}
		}
		else
		{
			return Wrong_pin_ID ;
		}
	}
	else
	{
		return Wrong_port_ID ;
	}
	return NO_Wrong ;
}
