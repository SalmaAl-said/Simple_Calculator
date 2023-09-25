################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/KPD_Program.c \
../HAL/LCD_Program.c 

OBJS += \
./HAL/KPD_Program.o \
./HAL/LCD_Program.o 

C_DEPS += \
./HAL/KPD_Program.d \
./HAL/LCD_Program.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/%.o: ../HAL/%.c HAL/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"F:\IMT\IMT_projects\simple_calculator\APP\Inc" -I"F:\IMT\IMT_projects\simple_calculator\HAL\Inc" -I"F:\IMT\IMT_projects\simple_calculator\LIB\Inc" -I"F:\IMT\IMT_projects\simple_calculator\MCAL\Inc" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


