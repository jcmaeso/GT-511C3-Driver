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
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F303x8 -I"C:/Users/jcala/Documents/STM32/Touch/Inc" -I"C:/Users/jcala/Documents/STM32/Touch/Drivers/STM32F3xx_HAL_Driver/Inc" -I"C:/Users/jcala/Documents/STM32/Touch/Drivers/STM32F3xx_HAL_Driver/Inc/Legacy" -I"C:/Users/jcala/Documents/STM32/Touch/Drivers/CMSIS/Device/ST/STM32F3xx/Include" -I"C:/Users/jcala/Documents/STM32/Touch/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


