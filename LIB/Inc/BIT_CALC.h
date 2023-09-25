/*
 * BIT_CALC.h
 *
 *  Created on: Sep 7, 2023
 *      Author: spider
 */

#ifndef BIT_CALC_H_
#define BIT_CALC_H_

#define SET_BIT(var,bit_no) (var)|=(1<<(bit_no))

#define CLEAR_BIT(var,bit_no) (var)&=(~(1<<(bit_no)))

#define TOGGLE_BIT(var,bit_no) (var)^=(1<<(bit_no))

#define GET_BIT(var,bit_no) (((var)>>(bit_no))&(1))

#define Assign_BIT(var,bit_no,val) do{if(val==1)\
								   SET_BIT(var,bit_no);\
								   else\
								   CLEAR_BIT(var,bit_no);\
								     }while(0)



#endif /* LIB_BIT_CALC_H_ */
