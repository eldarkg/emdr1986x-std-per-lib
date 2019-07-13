;/**
; * FILE startup_MDR1986BE4.s
; */

; <<< Use Configuration Wizard in Context Menu >>>

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

Heap_Size       EQU     0x00001000

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
__Vectors       DCD     __initial_sp             ; Top of Stack
                 DCD     Reset_Handler           ; Reset Handler
                 DCD     NonMaskableInt_Handler  ; 2 Non Maskable Handeler
                 DCD     HardFault_Handler       ; 3 Hard Fault Handeler
                 DCD     0                       ; Reserved
                 DCD     0                       ; Reserved
                 DCD     0                       ; Reserved
                 DCD     0                       ; Reserved
                 DCD     0                       ; Reserved
                 DCD     0                       ; Reserved
                 DCD     0                       ; Reserved
                 DCD     SVC_Handler             ; 10 SV Call Handeler
                 DCD     0                       ; Reserved
                 DCD     0                       ; Reserved
                 DCD     PendSV_Handler          ; 14 Pend SV Handeler
                 DCD     SysTick_Handler         ; 15 System Tick Timer Handeler

                 ; External Interrupts
                 DCD     DMA_IRQHandler          ; DMA Handeler
                 DCD     UART1_IRQHandler        ; UART1  Handeler
                 DCD     UART2_IRQHandler        ; UART2  Handeler
                 DCD     SSP1_IRQHandler         ; SSP1  Handeler
                 DCD     POWER_IRQHandler        ; POWER Handeler
                 DCD     WWDG_IRQHandler         ; WWDG Handeler
                 DCD     Timer1_IRQHandler       ; Timer1  Handeler
                 DCD     Timer2_IRQHandler       ; Timer2  Handeler
                 DCD     ADC_IRQHandler          ; ADC  Handeler
                 DCD     COMPARATOR_IRQHandler   ; COMPARATOR  Handeler
                 DCD     BACKUP_IRQHandler       ; BACKUP  Handeler
                 DCD     EXT_INT0_IRQHandler     ; EXT_INT0  Handeler
                 DCD     EXT_INT1_IRQHandler     ; EXT_INT1  Handeler
                 DCD     EXT_INT2_IRQHandler     ; EXT_INT2  Handeler
                 DCD     ADCIU_CH1_IRQHandler    ; ADCIU_CH1 Handeler
                 DCD     ADCIU_CH2_IRQHandler    ; ADCIU_CH2 Handeler
                 DCD     ADCIU_CH3_IRQHandler    ; ADCIU_CH3 Handeler
                 DCD     ADCIU_CH4_IRQHandler    ; ADCIU_CH4 Handeler
                 DCD     ADCIU_CH5_IRQHandler    ; ADCIU_CH5 Handeler
                 DCD     ADCIU_CH6_IRQHandler    ; ADCIU_CH6 Handeler
                 DCD     ADCIU_CH7_IRQHandler    ; ADCIU_CH7 Handeler
                 DCD     ADCIU_CH8_IRQHandler    ; ADCIU_CH8 Handeler
                 DCD     ADCIU_IRQHandler        ; ADCIU Handeler
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
NonMaskableInt_Handler       PROC
                EXPORT  NonMaskableInt_Handler        [WEAK]
                B       .
		                ENDP

HardFault_Handler            PROC
                EXPORT  HardFault_Handler             [WEAK]
                B       .
		                ENDP

SVC_Handler               PROC
                EXPORT  SVC_Handler                [WEAK]
                B       .
		                ENDP

PendSV_Handler               PROC
                EXPORT  PendSV_Handler                [WEAK]
                B       .
		                ENDP

SysTick_Handler              PROC
                EXPORT  SysTick_Handler               [WEAK]
                B       .
		                ENDP


; External Interrupts

DMA_IRQHandler          PROC
                EXPORT  DMA_IRQHandler                [WEAK]
                B       .
                     ENDP

UART1_IRQHandler        PROC
                EXPORT  UART1_IRQHandler              [WEAK]
                B       .
                     ENDP

UART2_IRQHandler        PROC
                EXPORT  UART2_IRQHandler              [WEAK]
                B       .
                     ENDP

SSP1_IRQHandler         PROC
                EXPORT  SSP1_IRQHandler               [WEAK]
                B       .
                     ENDP

POWER_IRQHandler        PROC
                EXPORT  POWER_IRQHandler              [WEAK]
                B       .
                     ENDP

WWDG_IRQHandler         PROC
                EXPORT  WWDG_IRQHandler               [WEAK]
                B       .
                     ENDP

Timer1_IRQHandler       PROC
                EXPORT  Timer1_IRQHandler             [WEAK]
                B       .
                     ENDP

Timer2_IRQHandler       PROC
                EXPORT  Timer2_IRQHandler             [WEAK]
                B       .
                     ENDP

ADC_IRQHandler          PROC
                EXPORT  ADC_IRQHandler                [WEAK]
                B       .
                     ENDP

COMPARATOR_IRQHandler   PROC
                EXPORT  COMPARATOR_IRQHandler         [WEAK]
                B       .
                     ENDP

BACKUP_IRQHandler       PROC
                EXPORT  BACKUP_IRQHandler             [WEAK]
                B       .
                     ENDP

EXT_INT0_IRQHandler     PROC
                EXPORT  EXT_INT0_IRQHandler           [WEAK]
                B       .
                     ENDP

EXT_INT1_IRQHandler     PROC
                EXPORT  EXT_INT1_IRQHandler           [WEAK]
                B       .
                     ENDP

EXT_INT2_IRQHandler     PROC
                EXPORT  EXT_INT2_IRQHandler           [WEAK]
                B       .
                     ENDP

ADCIU_CH1_IRQHandler    PROC
                EXPORT  ADCIU_CH1_IRQHandler          [WEAK]
                B       .
                     ENDP

ADCIU_CH2_IRQHandler    PROC
                EXPORT  ADCIU_CH2_IRQHandler          [WEAK]
                B       .
                     ENDP

ADCIU_CH3_IRQHandler    PROC
                EXPORT  ADCIU_CH3_IRQHandler          [WEAK]
                B       .
                     ENDP

ADCIU_CH4_IRQHandler    PROC
                EXPORT  ADCIU_CH4_IRQHandler          [WEAK]
                B       .
                     ENDP

ADCIU_CH5_IRQHandler    PROC
                EXPORT  ADCIU_CH5_IRQHandler          [WEAK]
                B       .
                     ENDP

ADCIU_CH6_IRQHandler    PROC
                EXPORT  ADCIU_CH6_IRQHandler          [WEAK]
                B       .
                     ENDP

ADCIU_CH7_IRQHandler    PROC
                EXPORT  ADCIU_CH7_IRQHandler          [WEAK]
                B       .
                     ENDP

ADCIU_CH8_IRQHandler    PROC
                EXPORT  ADCIU_CH8_IRQHandler          [WEAK]
                B       .
                     ENDP

ADCIU_IRQHandler        PROC
                EXPORT  ADCIU_IRQHandler              [WEAK]
                B       .
                     ENDP


                 ALIGN



; User Initial Stack & Heap

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
