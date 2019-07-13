;/**
; * FILE startup_MDR1986BE4.s
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
                 DCD     0                            ; Reserved
                 DCD     0                            ; Reserved
                 DCD     0                            ; Reserved
                 DCD     0                            ; Reserved
                 DCD     0                            ; Reserved
                 DCD     0                            ; Reserved
                 DCD     0                            ; Reserved
                 DCD     SVC_Handler                  ; 10 SV Call Handeler
                 DCD     0                            ; Reserved
                 DCD     0                            ; Reserved
                 DCD     PendSV_Handler               ; 14 Pend SV Handeler
                 DCD     SysTick_Handler              ; 15 System Tick Timer Handeler

                 ; External Interrupts
                 DCD     DMA_IRQHandler               ; DMA Handeler
                 DCD     UART1_IRQHandler             ; UART1  Handeler
                 DCD     UART2_IRQHandler             ; UART2  Handeler
                 DCD     SSP1_IRQHandler              ; SSP1  Handeler
                 DCD     POWER_IRQHandler             ; POWER Handeler
                 DCD     WWDG_IRQHandler              ; WWDG Handeler
                 DCD     Timer1_IRQHandler            ; Timer1  Handeler
                 DCD     Timer2_IRQHandler            ; Timer2  Handeler
                 DCD     ADC_IRQHandler               ; ADC  Handeler
                 DCD     COMPARATOR_IRQHandler        ; COMPARATOR  Handeler
                 DCD     BACKUP_IRQHandler            ; BACKUP  Handeler
                 DCD     EXT_INT0_IRQHandler          ; EXT_INT0  Handeler
                 DCD     EXT_INT1_IRQHandler          ; EXT_INT1  Handeler
                 DCD     EXT_INT2_IRQHandler          ; EXT_INT2  Handeler
                 DCD     ADCIU_CH1_IRQHandler         ; ADCIU_CH1 Handeler
                 DCD     ADCIU_CH2_IRQHandler         ; ADCIU_CH2 Handeler
                 DCD     ADCIU_CH3_IRQHandler         ; ADCIU_CH3 Handeler
                 DCD     ADCIU_CH4_IRQHandler         ; ADCIU_CH4 Handeler
                 DCD     ADCIU_CH5_IRQHandler         ; ADCIU_CH5 Handeler
                 DCD     ADCIU_CH6_IRQHandler         ; ADCIU_CH6 Handeler
                 DCD     ADCIU_CH7_IRQHandler         ; ADCIU_CH7 Handeler
                 DCD     ADCIU_CH8_IRQHandler         ; ADCIU_CH8 Handeler
                 DCD     ADCIU_IRQHandler             ; ADCIU Handeler
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

        PUBWEAK SVC_Handler
        SECTION .text:CODE:REORDER(1)
SVC_Handler
		   BL SVC_Handler

        PUBWEAK PendSV_Handler
        SECTION .text:CODE:REORDER(1)
PendSV_Handler
		   BL PendSV_Handler

        PUBWEAK SysTick_Handler
        SECTION .text:CODE:REORDER(1)
SysTick_Handler
		   BL SysTick_Handler


; External Interrupts

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

        PUBWEAK POWER_IRQHandler
        SECTION .text:CODE:REORDER(1)
POWER_IRQHandler
		   BL POWER_IRQHandler

        PUBWEAK WWDG_IRQHandler
        SECTION .text:CODE:REORDER(1)
WWDG_IRQHandler
		   BL WWDG_IRQHandler

        PUBWEAK Timer1_IRQHandler
        SECTION .text:CODE:REORDER(1)
Timer1_IRQHandler
		   BL Timer1_IRQHandler

        PUBWEAK Timer2_IRQHandler
        SECTION .text:CODE:REORDER(1)
Timer2_IRQHandler
		   BL Timer2_IRQHandler

        PUBWEAK ADC_IRQHandler
        SECTION .text:CODE:REORDER(1)
ADC_IRQHandler
		   BL ADC_IRQHandler

        PUBWEAK COMPARATOR_IRQHandler
        SECTION .text:CODE:REORDER(1)
COMPARATOR_IRQHandler
		   BL COMPARATOR_IRQHandler

        PUBWEAK BACKUP_IRQHandler
        SECTION .text:CODE:REORDER(1)
BACKUP_IRQHandler
		   BL BACKUP_IRQHandler

        PUBWEAK EXT_INT0_IRQHandler
        SECTION .text:CODE:REORDER(1)
EXT_INT0_IRQHandler
		   BL EXT_INT0_IRQHandler

        PUBWEAK EXT_INT1_IRQHandler
        SECTION .text:CODE:REORDER(1)
EXT_INT1_IRQHandler
		   BL EXT_INT1_IRQHandler

        PUBWEAK EXT_INT2_IRQHandler
        SECTION .text:CODE:REORDER(1)
EXT_INT2_IRQHandler
		   BL EXT_INT2_IRQHandler

        PUBWEAK ADCIU_CH1_IRQHandler
        SECTION .text:CODE:REORDER(1)
ADCIU_CH1_IRQHandler
		   BL ADCIU_CH1_IRQHandler

        PUBWEAK ADCIU_CH2_IRQHandler
        SECTION .text:CODE:REORDER(1)
ADCIU_CH2_IRQHandler
		   BL ADCIU_CH2_IRQHandler

        PUBWEAK ADCIU_CH3_IRQHandler
        SECTION .text:CODE:REORDER(1)
ADCIU_CH3_IRQHandler
		   BL ADCIU_CH3_IRQHandler

        PUBWEAK ADCIU_CH4_IRQHandler
        SECTION .text:CODE:REORDER(1)
ADCIU_CH4_IRQHandler
		   BL ADCIU_CH4_IRQHandler

        PUBWEAK ADCIU_CH5_IRQHandler
        SECTION .text:CODE:REORDER(1)
ADCIU_CH5_IRQHandler
		   BL ADCIU_CH5_IRQHandler

        PUBWEAK ADCIU_CH6_IRQHandler
        SECTION .text:CODE:REORDER(1)
ADCIU_CH6_IRQHandler
		   BL ADCIU_CH6_IRQHandler

        PUBWEAK ADCIU_CH7_IRQHandler
        SECTION .text:CODE:REORDER(1)
ADCIU_CH7_IRQHandler
		   BL ADCIU_CH7_IRQHandler

        PUBWEAK ADCIU_CH8_IRQHandler
        SECTION .text:CODE:REORDER(1)
ADCIU_CH8_IRQHandler
		   BL ADCIU_CH8_IRQHandler

        PUBWEAK ADCIU_IRQHandler
        SECTION .text:CODE:REORDER(1)
ADCIU_IRQHandler
		   BL ADCIU_IRQHandler

	END
