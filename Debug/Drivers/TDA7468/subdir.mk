################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/TDA7468/TDA7468.c 

OBJS += \
./Drivers/TDA7468/TDA7468.o 

C_DEPS += \
./Drivers/TDA7468/TDA7468.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/TDA7468/TDA7468.o: ../Drivers/TDA7468/TDA7468.c Drivers/TDA7468/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F030x6 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I"D:/Home projects/Audio/TDA7468_Prog/TDA7468_Prog/Drivers/TDA7468" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/TDA7468/TDA7468.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

