# emdr1986x-std-per-lib
<b>Milandr MCU 1986x Standard Peripherals Library</b>

This isn't official library that compatible with GCC compiler.

<b>Now next MCU support gcc compiler:</b>
- MDR1986VE9x
- MDR1986VE1T
- MDR1986VE3 (not tested)
- MDR1986BE4 (not tested)

<b>Documentation:</b>

https://github.com/eldarkg/emdr1986x-std-per-lib-doc

<b>Usage (pseudocode):</b>

INC = inc \
      std-per-lib/CMSIS/CM3/CoreSupport \
      std-per-lib/CMSIS/CM3/DeviceSupport/MDR32F9Qx/inc \
      std-per-lib/CMSIS/CM3/DeviceSupport/MDR32F9Qx/startup \
      std-per-lib/MDR32F9Qx_StdPeriph_Driver/inc \
      std-per-lib/MDR32F9Qx_StdPeriph_Driver/inc/USB_Library

SRC = example.c \
      std-per-lib/CMSIS/CM3/DeviceSupport/MDR32F9Qx/startup/gcc/startup_MDR32F9Qx.S \
      std-per-lib/CMSIS/CM3/DeviceSupport/MDR32F9Qx/startup/system_MDR32F9Qx.c \
      std-per-lib/MDR32F9Qx_StdPeriph_Driver/src/MDR32F9Qx_port.c \
      # another peripheral modules

<i>Release</i>
CFLAGS = -mcpu=cortex-m3 -mthumb -O2 -ffunction-sections -fdata-sections -Wall -Wextra -Wshadow -Wredundant-decls -Wno-missing-field-initializers -pipe
For each src in SRC list call:
arm-none-eabi-gcc ${CFLAGS} -DUSE_MDR1986VE9x -D__STARTUP_CLEAR_BSS -D__START=main -I${INC} ${src} -o ${src}.o
Link:
arm-none-eabi-gcc ${CFLAGS} -T std-per-lib/CMSIS/CM3/DeviceSupport/MDR32F9Qx/startup/gcc/MDR32F9Qx.ld --specs=nosys.specs -Wl,--gc-sections -ffreestanding -nostartfiles -Wl,-Map=example.map ${SRC} -o example.elf
Hex:
arm-none-eabi-objcopy -O ihex example.elf example.hex
<i>Debug</i>
Instead cflag -O2 set -O0 -ggdb3.
<i>Select MCU architecture</i>
Instead cflag -mcpu=cortex-m3 set:
-mcpu=cortex-m0     # MDR1986BE4
-mcpu=cortex-m1     # MDR1986VE1T, MDR1986VE3
-mcpu=cortex-m3     # MDR1986VE9x

Comment for pseudocode:
- instead ${VAR} paste relevant VAR list
- INC and SRC list change in accordance selected MCU.
