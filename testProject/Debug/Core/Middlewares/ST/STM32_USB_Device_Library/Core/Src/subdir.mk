################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_conf_template.c \
../Core/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.c \
../Core/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.c \
../Core/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.c 

OBJS += \
./Core/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_conf_template.o \
./Core/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.o \
./Core/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.o \
./Core/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.o 

C_DEPS += \
./Core/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_conf_template.d \
./Core/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.d \
./Core/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.d \
./Core/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_conf_template.o: ../Core/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_conf_template.c Core/Middlewares/ST/STM32_USB_Device_Library/Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xC -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_conf_template.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.o: ../Core/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.c Core/Middlewares/ST/STM32_USB_Device_Library/Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xC -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.o: ../Core/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.c Core/Middlewares/ST/STM32_USB_Device_Library/Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xC -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.o: ../Core/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.c Core/Middlewares/ST/STM32_USB_Device_Library/Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xC -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

