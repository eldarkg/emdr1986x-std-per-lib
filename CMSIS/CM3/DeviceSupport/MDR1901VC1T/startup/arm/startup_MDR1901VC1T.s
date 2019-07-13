;/**
; * FILE startup_MDR1901VC1T.s
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
                 DCD     MemoryManagement_Handler; 4 Memory Management Handeler
                 DCD     BusFault_Handler        ; 5 Bus Fault Handeler
                 DCD     UsageFault_Handler      ; 6 Usage Fault Handeler
                 DCD     0                       ; Reserved
                 DCD     0                       ; Reserved
                 DCD     0                       ; Reserved
                 DCD     0                       ; Reserved
                 DCD     SVCall_Handler          ; 10 SV Call Handeler
                 DCD     0                       ; Reserved
                 DCD     0                       ; Reserved
                 DCD     PendSV_Handler          ; 14 Pend SV Handeler
                 DCD     SysTick_Handler         ; 15 System Tick Timer Handeler

                 ; External Interrupts
                 DCD     SSP3_IRQHandler         ; SSP3 Handeler
                 DCD     SSP4_IRQHandler         ; SSP4  Handeler
                 DCD     USB_IRQHandler          ; USB Host  Handeler
                 DCD     MCBSP1_IRQHandler       ; MCBSP1  Handeler
                 DCD     MCBSP2_IRQHandler       ; MCBSP2  Handeler
                 DCD     DMA_IRQHandler          ; DMA  Handeler
                 DCD     UART1_IRQHandler        ; UART1  Handeler
                 DCD     UART2_IRQHandler        ; UART2  Handeler
                 DCD     SSP1_IRQHandler         ; SSP1  Handeler
                 DCD     MCBSP3_IRQHandler       ; MCBSP3  Handeler
                 DCD     I2C_IRQHandler          ; I2C  Handeler
                 DCD     POWER_IRQHandler        ; POWER Detecor  Handeler
                 DCD     WWDG_IRQHandler         ; Window Watchdog  Handeler
                 DCD     DMA_DSP_IRQHandler      ; DMA DSP  Handeler
                 DCD     Timer1_IRQHandler       ; Timer1  Handeler
                 DCD     Timer2_IRQHandler       ; Timer2  Handeler
                 DCD     Timer3_IRQHandler       ; Timer3  Handeler
                 DCD     ADC_IRQHandler          ; ADC  Handeler
                 DCD     SDIO_IRQHandler         ; SDIO  Handeler
                 DCD     COMPARATOR_IRQHandler   ; COMPARATOR  Handeler
                 DCD     SSP2_IRQHandler         ; SSP2  Handeler
                 DCD     AUDIO_IP_IRQHandler     ; Audio IP  Handeler
                 DCD     DSP_CRPT_IRQHandler     ; DSP CRPT  Handeler
                 DCD     DSP_TIMER_IRQHandler    ; DSP TIMER  Handeler
                 DCD     DSP_CORE_IRQHandler     ; DSP CORE  Handeler
                 DCD     DSP_STATE_IRQHandler    ; DSP STATE  Handeler
                 DCD     UART3_IRQHandler        ; UART3  Handeler
                 DCD     BACKUP_IRQHandler       ; BACKUP  Handeler
                 DCD     EXT_INT1_IRQHandler     ; EXT_INT1  Handeler
                 DCD     EXT_INT2_IRQHandler     ; EXT_INT2  Handeler
                 DCD     EXT_INT3_IRQHandler     ; EXT_INT3  Handeler
                 DCD     EXT_INT4_IRQHandler     ; EXT_INT4  Handeler
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

MemoryManagement_Handler     PROC
                EXPORT  MemoryManagement_Handler      [WEAK]
                B       .
		                ENDP

BusFault_Handler             PROC
                EXPORT  BusFault_Handler              [WEAK]
                B       .
		                ENDP

UsageFault_Handler           PROC
                EXPORT  UsageFault_Handler            [WEAK]
                B       .
		                ENDP

SVCall_Handler               PROC
                EXPORT  SVCall_Handler                [WEAK]
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

SSP3_IRQHandler         PROC
                EXPORT  SSP3_IRQHandler               [WEAK]
                B       .
                     ENDP

SSP4_IRQHandler         PROC
                EXPORT  SSP4_IRQHandler               [WEAK]
                B       .
                     ENDP

USB_IRQHandler          PROC
                EXPORT  USB_IRQHandler                [WEAK]
                B       .
                     ENDP

MCBSP1_IRQHandler       PROC
                EXPORT  MCBSP1_IRQHandler             [WEAK]
                B       .
                     ENDP

MCBSP2_IRQHandler       PROC
                EXPORT  MCBSP2_IRQHandler             [WEAK]
                B       .
                     ENDP

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

MCBSP3_IRQHandler       PROC
                EXPORT  MCBSP3_IRQHandler             [WEAK]
                B       .
                     ENDP

I2C_IRQHandler          PROC
                EXPORT  I2C_IRQHandler                [WEAK]
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

DMA_DSP_IRQHandler      PROC
                EXPORT  DMA_DSP_IRQHandler            [WEAK]
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

Timer3_IRQHandler       PROC
                EXPORT  Timer3_IRQHandler             [WEAK]
                B       .
                     ENDP

ADC_IRQHandler          PROC
                EXPORT  ADC_IRQHandler                [WEAK]
                B       .
                     ENDP

SDIO_IRQHandler         PROC
                EXPORT  SDIO_IRQHandler               [WEAK]
                B       .
                     ENDP

COMPARATOR_IRQHandler   PROC
                EXPORT  COMPARATOR_IRQHandler         [WEAK]
                B       .
                     ENDP

SSP2_IRQHandler         PROC
                EXPORT  SSP2_IRQHandler               [WEAK]
                B       .
                     ENDP

AUDIO_IP_IRQHandler     PROC
                EXPORT  AUDIO_IP_IRQHandler           [WEAK]
                B       .
                     ENDP

DSP_CRPT_IRQHandler     PROC
                EXPORT  DSP_CRPT_IRQHandler           [WEAK]
                B       .
                     ENDP

DSP_TIMER_IRQHandler    PROC
                EXPORT  DSP_TIMER_IRQHandler          [WEAK]
                B       .
                     ENDP

DSP_CORE_IRQHandler     PROC
                EXPORT  DSP_CORE_IRQHandler           [WEAK]
                B       .
                     ENDP

DSP_STATE_IRQHandler    PROC
                EXPORT  DSP_STATE_IRQHandler          [WEAK]
                B       .
                     ENDP

UART3_IRQHandler        PROC
                EXPORT  UART3_IRQHandler              [WEAK]
                B       .
                     ENDP

BACKUP_IRQHandler       PROC
                EXPORT  BACKUP_IRQHandler             [WEAK]
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

EXT_INT3_IRQHandler     PROC
                EXPORT  EXT_INT3_IRQHandler           [WEAK]
                B       .
                     ENDP

EXT_INT4_IRQHandler     PROC
                EXPORT  EXT_INT4_IRQHandler           [WEAK]
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
