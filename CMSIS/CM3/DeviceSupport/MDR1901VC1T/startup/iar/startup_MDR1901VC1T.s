;/**
; * FILE startup_MDR1901VC1T.s
; */

	
        MODULE  ?cstartup

        ;; Forward declaration of sections.
        SECTION CSTACK:DATA:NOROOT(3)

        SECTION .intvec:CODE:NOROOT(2)

        EXTERN  __iar_program_start
        EXTERN  SystemInit
        PUBLIC  __vector_table

        DATA
__vector_table
                 DCD     sfe(CSTACK)                  ; Top of Stack
                 DCD     Reset_Handler                ; Reset Handler
                 DCD     NonMaskableInt_Handler       ; 2 Non Maskable Handeler
                 DCD     HardFault_Handler            ; 3 Hard Fault Handeler
                 DCD     MemoryManagement_Handler     ; 4 Memory Management Handeler
                 DCD     BusFault_Handler             ; 5 Bus Fault Handeler
                 DCD     UsageFault_Handler           ; 6 Usage Fault Handeler
                 DCD     0                            ; Reserved
                 DCD     0                            ; Reserved
                 DCD     0                            ; Reserved
                 DCD     0                            ; Reserved
                 DCD     SVCall_Handler               ; 11 SV Call Handeler
                 DCD     0                            ; Reserved
                 DCD     0                            ; Reserved
                 DCD     PendSV_Handler               ; 14 Pend SV Handeler
                 DCD     SysTick_Handler              ; 15 System Tick Timer Handeler

                 ; External Interrupts
                 DCD     SSP3_IRQHandler              ; SSP3 Handeler
                 DCD     SSP4_IRQHandler              ; SSP4  Handeler
                 DCD     USB_IRQHandler               ; USB Host  Handeler
                 DCD     MCBSP1_IRQHandler            ; MCBSP1  Handeler
                 DCD     MCBSP2_IRQHandler            ; MCBSP2  Handeler
                 DCD     DMA_IRQHandler               ; DMA  Handeler
                 DCD     UART1_IRQHandler             ; UART1  Handeler
                 DCD     UART2_IRQHandler             ; UART2  Handeler
                 DCD     SSP1_IRQHandler              ; SSP1  Handeler
                 DCD     MCBSP3_IRQHandler            ; MCBSP3  Handeler
                 DCD     I2C_IRQHandler               ; I2C  Handeler
                 DCD     POWER_IRQHandler             ; POWER Detecor  Handeler
                 DCD     WWDG_IRQHandler              ; Window Watchdog  Handeler
                 DCD     DMA_DSP_IRQHandler           ; DMA DSP  Handeler
                 DCD     Timer1_IRQHandler            ; Timer1  Handeler
                 DCD     Timer2_IRQHandler            ; Timer2  Handeler
                 DCD     Timer3_IRQHandler            ; Timer3  Handeler
                 DCD     ADC_IRQHandler               ; ADC  Handeler
                 DCD     SDIO_IRQHandler              ; SDIO  Handeler
                 DCD     COMPARATOR_IRQHandler        ; COMPARATOR  Handeler
                 DCD     SSP2_IRQHandler              ; SSP2  Handeler
                 DCD     AUDIO_IP_IRQHandler          ; Audio IP  Handeler
                 DCD     DSP_CRPT_IRQHandler          ; DSP CRPT  Handeler
                 DCD     DSP_TIMER_IRQHandler         ; DSP TIMER  Handeler
                 DCD     DSP_CORE_IRQHandler          ; DSP CORE  Handeler
                 DCD     DSP_STATE_IRQHandler         ; DSP STATE  Handeler
                 DCD     UART3_IRQHandler             ; UART3  Handeler
                 DCD     BACKUP_IRQHandler            ; BACKUP  Handeler
                 DCD     EXT_INT1_IRQHandler          ; EXT_INT1  Handeler
                 DCD     EXT_INT2_IRQHandler          ; EXT_INT2  Handeler
                 DCD     EXT_INT3_IRQHandler          ; EXT_INT3  Handeler
                 DCD     EXT_INT4_IRQHandler          ; EXT_INT4  Handeler
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Default interrupt handlers.
;;
        THUMB

; Reset Handler
		PUBWEAK Reset_Handler
		SECTION .text:CODE:REORDER(2)
Reset_Handler
        LDR     R0, =SystemInit
        BLX     R0
        LDR     R0, =__iar_program_start
        BX      R0


; Dummy Exception Handlers (infinite loops which can be modified)
        PUBWEAK NonMaskableInt_Handler
        SECTION .text:CODE:REORDER(1)
NonMaskableInt_Handler
		   BL NonMaskableInt_Handler

        PUBWEAK HardFault_Handler
        SECTION .text:CODE:REORDER(1)
HardFault_Handler
		   BL HardFault_Handler

        PUBWEAK MemoryManagement_Handler
        SECTION .text:CODE:REORDER(1)
MemoryManagement_Handler
		   BL MemoryManagement_Handler

        PUBWEAK BusFault_Handler
        SECTION .text:CODE:REORDER(1)
BusFault_Handler
		   BL BusFault_Handler

        PUBWEAK UsageFault_Handler
        SECTION .text:CODE:REORDER(1)
UsageFault_Handler
		   BL UsageFault_Handler

        PUBWEAK SVCall_Handler
        SECTION .text:CODE:REORDER(1)
SVCall_Handler
		   BL SVCall_Handler

        PUBWEAK PendSV_Handler
        SECTION .text:CODE:REORDER(1)
PendSV_Handler
		   BL PendSV_Handler

        PUBWEAK SysTick_Handler
        SECTION .text:CODE:REORDER(1)
SysTick_Handler
		   BL SysTick_Handler


; External Interrupts

        PUBWEAK SSP3_IRQHandler
        SECTION .text:CODE:REORDER(1)
SSP3_IRQHandler
		   BL SSP3_IRQHandler

        PUBWEAK SSP4_IRQHandler
        SECTION .text:CODE:REORDER(1)
SSP4_IRQHandler
		   BL SSP4_IRQHandler

        PUBWEAK USB_IRQHandler
        SECTION .text:CODE:REORDER(1)
USB_IRQHandler
		   BL USB_IRQHandler

        PUBWEAK MCBSP1_IRQHandler
        SECTION .text:CODE:REORDER(1)
MCBSP1_IRQHandler
		   BL MCBSP1_IRQHandler

        PUBWEAK MCBSP2_IRQHandler
        SECTION .text:CODE:REORDER(1)
MCBSP2_IRQHandler
		   BL MCBSP2_IRQHandler

        PUBWEAK DMA_IRQHandler
        SECTION .text:CODE:REORDER(1)
DMA_IRQHandler
		   BL DMA_IRQHandler

        PUBWEAK UART1_IRQHandler
        SECTION .text:CODE:REORDER(1)
UART1_IRQHandler
		   BL UART1_IRQHandler

        PUBWEAK UART2_IRQHandler
        SECTION .text:CODE:REORDER(1)
UART2_IRQHandler
		   BL UART2_IRQHandler

        PUBWEAK SSP1_IRQHandler
        SECTION .text:CODE:REORDER(1)
SSP1_IRQHandler
		   BL SSP1_IRQHandler

        PUBWEAK MCBSP3_IRQHandler
        SECTION .text:CODE:REORDER(1)
MCBSP3_IRQHandler
		   BL MCBSP3_IRQHandler

        PUBWEAK I2C_IRQHandler
        SECTION .text:CODE:REORDER(1)
I2C_IRQHandler
		   BL I2C_IRQHandler

        PUBWEAK POWER_IRQHandler
        SECTION .text:CODE:REORDER(1)
POWER_IRQHandler
		   BL POWER_IRQHandler

        PUBWEAK WWDG_IRQHandler
        SECTION .text:CODE:REORDER(1)
WWDG_IRQHandler
		   BL WWDG_IRQHandler

        PUBWEAK DMA_DSP_IRQHandler
        SECTION .text:CODE:REORDER(1)
DMA_DSP_IRQHandler
		   BL DMA_DSP_IRQHandler

        PUBWEAK Timer1_IRQHandler
        SECTION .text:CODE:REORDER(1)
Timer1_IRQHandler
		   BL Timer1_IRQHandler

        PUBWEAK Timer2_IRQHandler
        SECTION .text:CODE:REORDER(1)
Timer2_IRQHandler
		   BL Timer2_IRQHandler

        PUBWEAK Timer3_IRQHandler
        SECTION .text:CODE:REORDER(1)
Timer3_IRQHandler
		   BL Timer3_IRQHandler

        PUBWEAK ADC_IRQHandler
        SECTION .text:CODE:REORDER(1)
ADC_IRQHandler
		   BL ADC_IRQHandler

        PUBWEAK SDIO_IRQHandler
        SECTION .text:CODE:REORDER(1)
SDIO_IRQHandler
		   BL SDIO_IRQHandler

        PUBWEAK COMPARATOR_IRQHandler
        SECTION .text:CODE:REORDER(1)
COMPARATOR_IRQHandler
		   BL COMPARATOR_IRQHandler

        PUBWEAK SSP2_IRQHandler
        SECTION .text:CODE:REORDER(1)
SSP2_IRQHandler
		   BL SSP2_IRQHandler

        PUBWEAK AUDIO_IP_IRQHandler
        SECTION .text:CODE:REORDER(1)
AUDIO_IP_IRQHandler
		   BL AUDIO_IP_IRQHandler

        PUBWEAK DSP_CRPT_IRQHandler
        SECTION .text:CODE:REORDER(1)
DSP_CRPT_IRQHandler
		   BL DSP_CRPT_IRQHandler

        PUBWEAK DSP_TIMER_IRQHandler
        SECTION .text:CODE:REORDER(1)
DSP_TIMER_IRQHandler
		   BL DSP_TIMER_IRQHandler

        PUBWEAK DSP_CORE_IRQHandler
        SECTION .text:CODE:REORDER(1)
DSP_CORE_IRQHandler
		   BL DSP_CORE_IRQHandler

        PUBWEAK DSP_STATE_IRQHandler
        SECTION .text:CODE:REORDER(1)
DSP_STATE_IRQHandler
		   BL DSP_STATE_IRQHandler

        PUBWEAK UART3_IRQHandler
        SECTION .text:CODE:REORDER(1)
UART3_IRQHandler
		   BL UART3_IRQHandler

        PUBWEAK BACKUP_IRQHandler
        SECTION .text:CODE:REORDER(1)
BACKUP_IRQHandler
		   BL BACKUP_IRQHandler

        PUBWEAK EXT_INT1_IRQHandler
        SECTION .text:CODE:REORDER(1)
EXT_INT1_IRQHandler
		   BL EXT_INT1_IRQHandler

        PUBWEAK EXT_INT2_IRQHandler
        SECTION .text:CODE:REORDER(1)
EXT_INT2_IRQHandler
		   BL EXT_INT2_IRQHandler

        PUBWEAK EXT_INT3_IRQHandler
        SECTION .text:CODE:REORDER(1)
EXT_INT3_IRQHandler
		   BL EXT_INT3_IRQHandler

        PUBWEAK EXT_INT4_IRQHandler
        SECTION .text:CODE:REORDER(1)
EXT_INT4_IRQHandler
		   BL EXT_INT4_IRQHandler

	END
