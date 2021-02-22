################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../rt-thread/components/net/lwip-2.0.2/src/netif/ethernet.c \
../rt-thread/components/net/lwip-2.0.2/src/netif/ethernetif.c \
../rt-thread/components/net/lwip-2.0.2/src/netif/lowpan6.c 

OBJS += \
./rt-thread/components/net/lwip-2.0.2/src/netif/ethernet.o \
./rt-thread/components/net/lwip-2.0.2/src/netif/ethernetif.o \
./rt-thread/components/net/lwip-2.0.2/src/netif/lowpan6.o 

C_DEPS += \
./rt-thread/components/net/lwip-2.0.2/src/netif/ethernet.d \
./rt-thread/components/net/lwip-2.0.2/src/netif/ethernetif.d \
./rt-thread/components/net/lwip-2.0.2/src/netif/lowpan6.d 


# Each subdirectory must supply rules for building sources it contributes
rt-thread/components/net/lwip-2.0.2/src/netif/%.o: ../rt-thread/components/net/lwip-2.0.2/src/netif/%.c
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -ffunction-sections -fdata-sections -Wall  -g -gdwarf-2 -DDEBUG -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\applications" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\board\CubeMX_Config\Core\Inc" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\board\port" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\board" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\libraries\STM32H7xx_HAL\CMSIS\Device\ST\STM32H7xx\Include" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\libraries\STM32H7xx_HAL\CMSIS\Include" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\libraries\STM32H7xx_HAL\STM32H7xx_HAL_Driver\Inc" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\libraries\drivers\include\config" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\libraries\drivers\include" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\libraries\drivers" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\libraries\rt_ota_lib\inc" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\libraries\touchgfx_lib\Middlewares\ST\touchgfx\framework\include" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\libraries\touchgfx_lib\TouchGFX\generated\fonts\include" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\libraries\touchgfx_lib\TouchGFX\generated\gui_generated\include" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\libraries\touchgfx_lib\TouchGFX\generated\images\include" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\libraries\touchgfx_lib\TouchGFX\generated\texts\include" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\libraries\touchgfx_lib\TouchGFX\gui\include" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\libraries\touchgfx_lib\TouchGFX\target\generated" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\libraries\touchgfx_lib\TouchGFX\target" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\libraries\touchgfx_lib\TouchGFX" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\libraries\wlan_wiced_lib" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\packages\EasyFlash-v4.1.0\inc" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\packages\fal-v0.5.0\inc" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\packages\gt9147-latest\inc" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\packages\netutils-v1.2.0\iperf" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\packages\rt_printf-latest" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\packages\sys_load_monitor-v1.0.0" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\rt-thread\components\cplusplus" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\rt-thread\components\dfs\filesystems\devfs" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\rt-thread\components\dfs\filesystems\elmfat" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\rt-thread\components\dfs\include" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\rt-thread\components\drivers\include" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\rt-thread\components\drivers\spi\sfud\inc" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\rt-thread\components\drivers\spi" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\rt-thread\components\drivers\touch" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\rt-thread\components\drivers\wlan" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\rt-thread\components\finsh" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\rt-thread\components\libc\compilers\newlib" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\rt-thread\components\libc\pthreads" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\rt-thread\components\libc\termios" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\rt-thread\components\libc\time" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\rt-thread\components\net\lwip-2.0.2\src\arch\include" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\rt-thread\components\net\lwip-2.0.2\src\include\netif" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\rt-thread\components\net\lwip-2.0.2\src\include" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\rt-thread\components\net\lwip-2.0.2\src" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\rt-thread\components\net\netdev\include" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\rt-thread\components\net\sal_socket\impl" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\rt-thread\components\net\sal_socket\include\dfs_net" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\rt-thread\components\net\sal_socket\include\socket\sys_socket" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\rt-thread\components\net\sal_socket\include\socket" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\rt-thread\components\net\sal_socket\include" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\rt-thread\components\utilities\ymodem" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\rt-thread\include" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\rt-thread\libcpu\arm\common" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\rt-thread\libcpu\arm\cortex-m7" -I"C:\RT-ThreadStudio\workspace\H750_TouchGFX\model\net" -include"C:\RT-ThreadStudio\workspace\H750_TouchGFX\rtconfig_preinc.h" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

