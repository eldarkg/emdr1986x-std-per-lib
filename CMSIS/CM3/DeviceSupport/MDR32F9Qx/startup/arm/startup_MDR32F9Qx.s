;/*****************************************************************************
; * @file:    startup_MDR32F9Qx.s
; * @purpose: CMSIS Cortex-M3 Core Device Startup File for the
; *           Milandr MDR32F9Qx device series
; * @version: V1.0
; * @date:    09/07/2010
; *****************************************************************************
; * @copy
; *
; * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
; * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
; * TIME. AS A RESULT, PHYTON SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT
; * OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
; * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
; * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
; *
; * <h2><center>&copy; COPYRIGHT 2010 Phyton</center></h2>
; ******************************************************************************
; * FILE startup_MDR32F9Qx.s
; */

; Amount of memory (in bytes) allocated for Stack
; Tailor this value to your application needs
; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Stack_Size      EQU     0x00000400

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Heap_Size       EQU     0x00000200

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit

                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset
                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size

__Vectors       DCD     __initial_sp               ; Top of Stack
                DCD     Reset_Handler              ; Reset Handler
                DCD     NMI_Handler                ; NMI Handler
                DCD     HardFault_Handler          ; Hard Fault Handler
                DCD     MemManage_Handler          ; MPU Fault Handler
                DCD     BusFault_Handler           ; Bus Fault Handler
                DCD     UsageFault_Handler         ; Usage Fault Handler
                DCD     0                          ; Reserved
                DCD     0                          ; Reserved
                DCD     0                          ; Reserved
                DCD     0                          ; Reserved
                DCD     SVC_Handler                ; SVCall Handler
                DCD     DebugMon_Handler           ; Debug Monitor Handler
                DCD     0                          ; Reserved
                DCD     PendSV_Handler             ; PendSV Handler
                DCD     SysTick_Handler            ; SysTick Handler

                ; External Interrupts
                DCD     CAN1_IRQHandler            ; IRQ0
                DCD     CAN2_IRQHandler            ; IRQ1
                DCD     USB_IRQHandler             ; IRQ2
                DCD     0                          ; IRQ3  reserved
                DCD     0                          ; IRQ4  reserved
                DCD     DMA_IRQHandler             ; IRQ5
                DCD     UART1_IRQHandler           ; IRQ6
                DCD     UART2_IRQHandler           ; IRQ7
                DCD     SSP1_IRQHandler            ; IRQ8
                DCD     0                          ; IRQ9  reserved
                DCD     I2C_IRQHandler             ; IRQ10
                DCD     POWER_IRQHandler           ; IRQ11
                DCD     WWDG_IRQHandler            ; IRQ12
                DCD     0                          ; IRQ13 reserved
                DCD     Timer1_IRQHandler          ; IRQ14
                DCD     Timer2_IRQHandler          ; IRQ15
                DCD     Timer3_IRQHandler          ; IRQ16
                DCD     ADC_IRQHandler             ; IRQ17
                DCD     0                          ; IRQ18 reserved
                DCD     COMPARATOR_IRQHandler      ; IRQ19
                DCD     SSP2_IRQHandler            ; IRQ20
                DCD     0                          ; IRQ21 reserved
                DCD     0                          ; IRQ22 reserved
                DCD     0                          ; IRQ23 reserved
                DCD     0                          ; IRQ24 reserved
                DCD     0                          ; IRQ25 reserved
                DCD     0                          ; IRQ26 reserved
                DCD     BACKUP_IRQHandler          ; IRQ27
                DCD     EXT_INT1_IRQHandler        ; IRQ28
                DCD     EXT_INT2_IRQHandler        ; IRQ29
                DCD     EXT_INT3_IRQHandler        ; IRQ30
                DCD     EXT_INT4_IRQHandler        ; IRQ31
__Vectors_End

__Vectors_Size  EQU  __Vectors_End - __Vectors

                AREA    |.text|, CODE, READONLY

; Reset handler
Reset_Handler    PROC
                 EXPORT  Reset_Handler             [WEAK]
        IMPORT  SystemInit
        IMPORT  __main
                 LDR     R0, =SystemInit
                 BLX     R0
                 LDR     R0, =__main
                 BX      R0
                 ENDP

; Dummy Exception Handlers (infinite loops which can be modified)

NMI_Handler     PROC
                EXPORT  NMI_Handler                [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler          [WEAK]
                B       .
                ENDP
MemManage_Handler\
                PROC
                EXPORT  MemManage_Handler          [WEAK]
                B       .
                ENDP
BusFault_Handler\
                PROC
                EXPORT  BusFault_Handler           [WEAK]
                B       .
                ENDP
UsageFault_Handler\
                PROC
                EXPORT  UsageFault_Handler         [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler                [WEAK]
                B       .
                ENDP
DebugMon_Handler\
                PROC
                EXPORT  DebugMon_Handler           [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler             [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler            [WEAK]
                B       .
                ENDP

Default_Handler PROC


                EXPORT  CAN1_IRQHandler            [WEAK]
                EXPORT  CAN2_IRQHandler            [WEAK]
                EXPORT  USB_IRQHandler             [WEAK]
                EXPORT  DMA_IRQHandler             [WEAK]
                EXPORT  UART1_IRQHandler           [WEAK]
                EXPORT  UART2_IRQHandler           [WEAK]
                EXPORT  SSP1_IRQHandler            [WEAK]
                EXPORT  I2C_IRQHandler             [WEAK]
                EXPORT  POWER_IRQHandler           [WEAK]
                EXPORT  WWDG_IRQHandler            [WEAK]
                EXPORT  Timer1_IRQHandler          [WEAK]
                EXPORT  Timer2_IRQHandler          [WEAK]
                EXPORT  Timer3_IRQHandler          [WEAK]
                EXPORT  ADC_IRQHandler             [WEAK]
                EXPORT  COMPARATOR_IRQHandler      [WEAK]
                EXPORT  SSP2_IRQHandler            [WEAK]
                EXPORT  BACKUP_IRQHandler          [WEAK]
                EXPORT  EXT_INT1_IRQHandler        [WEAK]
                EXPORT  EXT_INT2_IRQHandler        [WEAK]
                EXPORT  EXT_INT3_IRQHandler        [WEAK]
                EXPORT  EXT_INT4_IRQHandler        [WEAK]

CAN1_IRQHandler
CAN2_IRQHandler
USB_IRQHandler
DMA_IRQHandler
UART1_IRQHandler
UART2_IRQHandler
SSP1_IRQHandler
I2C_IRQHandler
POWER_IRQHandler
WWDG_IRQHandler
Timer1_IRQHandler
Timer2_IRQHandler
Timer3_IRQHandler
ADC_IRQHandler
COMPARATOR_IRQHandler
SSP2_IRQHandler
BACKUP_IRQHandler
EXT_INT1_IRQHandler
EXT_INT2_IRQHandler
EXT_INT3_IRQHandler
EXT_INT4_IRQHandler

                B       .

                ENDP

                ALIGN

;*******************************************************************************
; User Stack and Heap initialization
;*******************************************************************************
                 IF      :DEF:__MICROLIB

                 EXPORT  __initial_sp
                 EXPORT  __heap_base
                 EXPORT  __heap_limit

                 ELSE

                 IMPORT  __use_two_region_memory
                 EXPORT  __user_initial_stackheap

__user_initial_stackheap

                 LDR     R0, =  Heap_Mem
                 LDR     R1, =(Stack_Mem + Stack_Size)
                 LDR     R2, = (Heap_Mem +  Heap_Size)
                 LDR     R3, = Stack_Mem
                 BX      LR

                 ALIGN

                 ENDIF

                 END

;/******************* (C) COPYRIGHT 2010 Phyton *********************************
;*
;* END OF FILE startup_MDR32F9Qx.s */
