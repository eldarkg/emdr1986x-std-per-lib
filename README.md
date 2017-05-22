# emdr1986x-std-per-lib
## Milandr MCU 1986x Standard Peripherals Library

This isn't official library that compatible with GCC compiler.

**Now next MCU support gcc compiler:**
- MDR1901VC1T (not tested)
- MDR1986VE1T
- MDR1986VE3 (not tested)
- MDR1986BE4 (not tested)
- MDR1986VE9x

[**Link to documentation**](https://github.com/eldarkg/emdr1986x-std-per-lib-doc)

[**Link to a recomended GCC compiler version**](https://developer.arm.com/open-source/gnu-toolchain/gnu-rm)

### Usage (pseudocode)
```
INC = inc
      std-per-lib/CMSIS/CM3/CoreSupport
      std-per-lib/CMSIS/CM3/DeviceSupport/MDR32F9Qx/inc
      std-per-lib/CMSIS/CM3/DeviceSupport/MDR32F9Qx/startup
      std-per-lib/MDR32F9Qx_StdPeriph_Driver/inc
      std-per-lib/MDR32F9Qx_StdPeriph_Driver/inc/USB_Library
```
```
SRC = example.c
      std-per-lib/CMSIS/CM3/DeviceSupport/MDR32F9Qx/startup/gcc/startup_MDR32F9Qx.S
      std-per-lib/CMSIS/CM3/DeviceSupport/MDR32F9Qx/startup/system_MDR32F9Qx.c
      std-per-lib/MDR32F9Qx_StdPeriph_Driver/src/MDR32F9Qx_port.c
      # another peripheral modules
```
***Release***
```
CFLAGS = -mcpu=cortex-m3 -mthumb -O2 -ffunction-sections -fdata-sections -Wall -Wextra -Wshadow -Wredundant-decls -Wno-missing-field-initializers -pipe
```
For each `src` in `SRC` list call:
```
arm-none-eabi-gcc ${CFLAGS} -DUSE_MDR1986VE9x -D__STARTUP_CLEAR_BSS -D__START=main -I${INC} -c ${src} -o ${src}.o
```
Link (`OBJ` it is a list of all `${src}.o`):
```
arm-none-eabi-gcc ${CFLAGS} -T std-per-lib/CMSIS/CM3/DeviceSupport/MDR32F9Qx/startup/gcc/MDR32F9Qx.ld --specs=nosys.specs -Wl,--gc-sections -ffreestanding -nostartfiles -Wl,-Map=example.map ${OBJ} -o example.elf
```
Get a hex file:
```
arm-none-eabi-objcopy -O ihex example.elf example.hex
```
***Debug***

Instead `cflag` `-O2` set `-O0 -ggdb3`.

***Select MCU architecture***

Instead `cflag` `-mcpu=cortex-m3` use:
```
-mcpu=cortex-m0     # MDR1986BE4
-mcpu=cortex-m1     # MDR1986VE1T, MDR1986VE3
-mcpu=cortex-m3     # MDR1986VE9x, MDR1901VC1T
```
Instead compiler definition `-DUSE_MDR1986VE9x` use:
```
-DUSE_MDR1901VC1T   # MDR1901VC1T
-DUSE_MDR1986VE1T   # MDR1986VE1T
-DUSE_MDR1986VE3    # MDR1986VE3
-DUSE_MDR1986BE4    # MDR1986BE4
-DUSE_MDR1986VE9x   # MDR1986VE9x
```
`INC`, `SRC` and `ld script` change in accordance selected MCU.

***Comment for pseudocode***
- instead `${VAR}` paste relevant `VAR` list
