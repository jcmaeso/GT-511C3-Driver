################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/touch_driver/touch.c 

OBJS += \
./Src/touch_driver/touch.o 

C_DEPS += \
./Src/touch_driver/touch.d 


# Each subdirectory must supply rules for building sources it contributes
Src/touch_driver/%.o: ../Src/touch_driver/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F051x8 -I"D:/IEEE/KK/SmartLock/Inc" -I"D:/IEEE/KK/SmartLock/Drivers/STM32F0xx_HAL_Driver/Inc" -I"D:/IEEE/KK/SmartLock/Drivers/STM32F0xx_HAL_Driver/Inc/Legacy" -I"D:/IEEE/KK/SmartLock/Drivers/CMSIS/Device/ST/STM32F0xx/Include" -I"D:/IEEE/KK/SmartLock/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


