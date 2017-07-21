# emdr1986x-std-per-lib
## Milandr MCU 1986x Standard Peripherals Library

This isn't official library that compatible with GCC compiler.

**The following MCU's are now supported by gcc:**
- MDR1901VC1T (not tested)
- MDR1986VE1T
- MDR1986VE3 (not tested)
- MDR1986BE4 (not tested)
- MDR1986VE9x

[**>>>Link to documentation<<<**](https://github.com/eldarkg/emdr1986x-std-per-lib-doc)

[**>>>Link to a recomended GCC compiler version<<<**](https://developer.arm.com/open-source/gnu-toolchain/gnu-rm)

[**>>>Link to newest CMSIS<<<**](https://github.com/ARM-software/CMSIS_5) (The current package contain an old version of CMSIS)

To see examples for using gcc toolchain look at ```/usr/share/gcc-arm-embedded/samples``` (on Linux).

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
#### Release

```
CFLAGS = -mcpu=cortex-m3 -mthumb -O2 -ffunction-sections -fdata-sections -Wall -Wextra -Wshadow -Wredundant-decls -Wno-missing-field-initializers -Wconversion -Wno-packed-bitfield-compat -pipe
```

##### C

For each `src` in `SRC` list call:
```
arm-none-eabi-gcc ${CFLAGS} -DUSE_MDR1986VE9x -D__STARTUP_CLEAR_BSS -D__START=main -I${INC} -c ${src} -o ${src}.o
```
Link (`OBJ` it is a list of all `${src}.o`):
```
arm-none-eabi-gcc ${CFLAGS} -T std-per-lib/CMSIS/CM3/DeviceSupport/MDR32F9Qx/startup/gcc/MDR32F9Qx.ld --specs=nosys.specs -Wl,--gc-sections -ffreestanding -nostartfiles -Wl,-Map=example.map ${OBJ} -o example.elf
```

##### C++

For each `src` in `SRC` call:
```
arm-none-eabi-g++ ${CFLAGS} -fno-rtti -fno-exceptions -fno-threadsafe-statics -DUSE_MDR1986VE9x -D__STARTUP_CLEAR_BSS -I${INC} -c ${src} -o ${src}.o
```
Link:
```
arm-none-eabi-g++ ${CFLAGS} -T std-per-lib/CMSIS/CM3/DeviceSupport/MDR32F9Qx/startup/gcc/MDR32F9Qx.ld --specs=nosys.specs --specs=nano.specs -Wl,--gc-sections -ffreestanding  -Wl,-Map=example.map ${OBJ} -o example.elf
```

Selection a type of C/C++ standard library:

`--specs=nano.specs` - use newlib-nano library (recomended for embedded systems). Without this flag - used the common library.

With semihosting: `--specs=rdimon.specs`

Without semihosting: `--specs=nosys.specs`

[**>>>What is semihosting?<<<**](http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0471g/Bgbjjgij.html)

Show compiled file sections size after building (additional linker flag): `-Wl,--print-memory-usage`.

Example:
```
Memory region         Used Size  Region Size  %age Used
           FLASH:     29760 B       128 KB     22.71%
           RAM:        2312 B        32 KB      7.06%
```

Get a hex file:
```
arm-none-eabi-objcopy -O ihex example.elf example.hex
```

Get a bin file:
```
arm-none-eabi-objcopy -O binary example.elf example.bin
```

#### Debug

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
