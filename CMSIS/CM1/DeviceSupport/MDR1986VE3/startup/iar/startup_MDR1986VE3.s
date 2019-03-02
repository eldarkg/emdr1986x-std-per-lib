;/*
; * startup_MDR1986VE3.s
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
        DCD     sfe(CSTACK)               ; Top of Stack
        DCD     Reset_Handler             ; Reset Handler
        DCD     NMI_Handler               ; NMI Handler
        DCD     HardFault_Handler         ; Hard Fault Handler
        DCD     0                         ; Reserved
        DCD     0                         ; Reserved
        DCD     0                         ; Reserved
        DCD     0                         ; Reserved
        DCD     0                         ; Reserved
        DCD     0                         ; Reserved
        DCD     0                         ; Reserved
        DCD     SVC_Handler               ; SVCall Handler
        DCD     0                         ; Reserved
        DCD     0                         ; Reserved
        DCD     PendSV_Handler            ; PendSV Handler
        DCD     SysTick_Handler           ; SysTick Handler

        ; External Interrupts

		DCD     MIL_STD_1553B2_IRQHandler		;IRQ0
		DCD     MIL_STD_1553B1_IRQHandler		;IRQ1
		DCD     USB_IRQHandler					;IRQ2
		DCD     CAN1_IRQHandler					;IRQ3
		DCD     CAN2_IRQHandler					;IRQ4
		DCD     DMA_IRQHandler					;IRQ5
		DCD     UART1_IRQHandler				;IRQ6
		DCD     UART2_IRQHandler				;IRQ7
		DCD     SSP1_IRQHandler					;IRQ8
		DCD     BUSY_IRQHandler					;IRQ9
		DCD     ARINC429R_IRQHandler			;IRQ10
		DCD     POWER_IRQHandler				;IRQ11
		DCD     WWDG_IRQHandler					;IRQ12
		DCD     Timer4_IRQHandler				;IRQ13
		DCD     Timer1_IRQHandler				;IRQ14
		DCD     Timer2_IRQHandler				;IRQ15
		DCD     Timer3_IRQHandler				;IRQ16
		DCD     ADC_IRQHandler					;IRQ17
		DCD     ETHERNET_IRQHandler				;IRQ18
		DCD     SSP3_IRQHandler					;IRQ19
		DCD     SSP2_IRQHandler					;IRQ20
		DCD     ARINC429T_IRQHandler			;IRQ21
		DCD     KEYPAD_IRQHandler				;IRQ22
		DCD     LED_IRQHandler					;IRQ23
		DCD     UART3_UART4_IRQHandler			;IRQ24
		DCD     AudioCodec_IRQHandler			;IRQ25
		DCD     ETHERNET2_IRQHandler			;IRQ26
		DCD     BKP_IRQHandler					;IRQ27
		DCD     EXT_INT1_IRQHandler				;IRQ28
		DCD     EXT_INT2_IRQHandler				;IRQ29
		DCD     EXT_INT3_IRQHandler				;IRQ30
		DCD     EXT_INT4_IRQHandler				;IRQ31

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
        PUBWEAK NMI_Handler
        SECTION .text:CODE:REORDER(1)
NMI_Handler
		BL NMI_Handler

        PUBWEAK HardFault_Handler
        SECTION .text:CODE:REORDER(1)
HardFault_Handler
        BL  HardFault_Handler


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
        PUBWEAK MIL_STD_1553B2_IRQHandler
        SECTION .text:CODE:REORDER(1)
MIL_STD_1553B2_IRQHandler
		BL MIL_STD_1553B2_IRQHandler

        PUBWEAK MIL_STD_1553B1_IRQHandler
        SECTION .text:CODE:REORDER(1)
MIL_STD_1553B1_IRQHandler
		BL MIL_STD_1553B1_IRQHandler

        PUBWEAK USB_IRQHandler
        SECTION .text:CODE:REORDER(1)
USB_IRQHandler
		BL  USB_IRQHandler

        PUBWEAK CAN1_IRQHandler
        SECTION .text:CODE:REORDER(1)
CAN1_IRQHandler
		BL  CAN1_IRQHandler

        PUBWEAK CAN2_IRQHandler
        SECTION .text:CODE:REORDER(1)
CAN2_IRQHandler
		BL  CAN2_IRQHandler

        PUBWEAK DMA_IRQHandler
        SECTION .text:CODE:REORDER(1)
DMA_IRQHandler
		BL  DMA_IRQHandler

        PUBWEAK UART1_IRQHandler
        SECTION .text:CODE:REORDER(1)
UART1_IRQHandler
		BL  UART1_IRQHandler

        PUBWEAK UART2_IRQHandler
        SECTION .text:CODE:REORDER(1)
UART2_IRQHandler
		BL  UART2_IRQHandler

        PUBWEAK SSP1_IRQHandler
        SECTION .text:CODE:REORDER(1)
SSP1_IRQHandler
		BL  SSP1_IRQHandler

        PUBWEAK BUSY_IRQHandler
        SECTION .text:CODE:REORDER(1)
BUSY_IRQHandler
		BL  BUSY_IRQHandler

        PUBWEAK ARINC429R_IRQHandler
        SECTION .text:CODE:REORDER(1)
ARINC429R_IRQHandler
        BL  ARINC429R_IRQHandler

        PUBWEAK POWER_IRQHandler
        SECTION .text:CODE:REORDER(1)
POWER_IRQHandler
		BL  POWER_IRQHandler

        PUBWEAK WWDG_IRQHandler
        SECTION .text:CODE:REORDER(1)
WWDG_IRQHandler
		BL  WWDG_IRQHandler

        PUBWEAK Timer4_IRQHandler
        SECTION .text:CODE:REORDER(1)
Timer4_IRQHandler
		BL  Timer4_IRQHandler

        PUBWEAK Timer1_IRQHandler
        SECTION .text:CODE:REORDER(1)
Timer1_IRQHandler
		BL  Timer1_IRQHandler

        PUBWEAK Timer2_IRQHandler
        SECTION .text:CODE:REORDER(1)
Timer2_IRQHandler
		BL  Timer2_IRQHandler

        PUBWEAK Timer3_IRQHandler
        SECTION .text:CODE:REORDER(1)
Timer3_IRQHandler
		BL  Timer3_IRQHandler

        PUBWEAK ADC_IRQHandler
        SECTION .text:CODE:REORDER(1)
ADC_IRQHandler
		BL  ADC_IRQHandler

        PUBWEAK ETHERNET_IRQHandler
        SECTION .text:CODE:REORDER(1)
ETHERNET_IRQHandler
		BL  ETHERNET_IRQHandler

        PUBWEAK SSP3_IRQHandler
        SECTION .text:CODE:REORDER(1)
SSP3_IRQHandler
		BL  SSP3_IRQHandler

        PUBWEAK SSP2_IRQHandler
        SECTION .text:CODE:REORDER(1)
SSP2_IRQHandler
		BL  SSP2_IRQHandler

        PUBWEAK ARINC429T_IRQHandler
        SECTION .text:CODE:REORDER(1)
ARINC429T_IRQHandler
		BL  ARINC429T_IRQHandler

        PUBWEAK KEYPAD_IRQHandler
        SECTION .text:CODE:REORDER(1)
KEYPAD_IRQHandler
		BL  KEYPAD_IRQHandler

        PUBWEAK LED_IRQHandler
        SECTION .text:CODE:REORDER(1)
LED_IRQHandler
		BL  LED_IRQHandler

        PUBWEAK UART3_UART4_IRQHandler
        SECTION .text:CODE:REORDER(1)
UART3_UART4_IRQHandler
		BL  UART3_UART4_IRQHandler

		PUBWEAK AudioCodec_IRQHandler
		SECTION .text:CODE:REORDER(1)
AudioCodec_IRQHandler
		BL AudioCodec_IRQHandler

		PUBWEAK ETHERNET2_IRQHandler
		SECTION .text:CODE:REORDER
ETHERNET2_IRQHandler
		BL ETHERNET2_IRQHandler

        PUBWEAK BKP_IRQHandler
        SECTION .text:CODE:REORDER(1)
BKP_IRQHandler
		BL  BKP_IRQHandler

        PUBWEAK EXT_INT1_IRQHandler
        SECTION .text:CODE:REORDER(1)
EXT_INT1_IRQHandler
		BL  EXT_INT1_IRQHandler

        PUBWEAK EXT_INT2_IRQHandler
        SECTION .text:CODE:REORDER(1)
EXT_INT2_IRQHandler
		BL  EXT_INT2_IRQHandler

        PUBWEAK EXT_INT3_IRQHandler
        SECTION .text:CODE:REORDER(1)
EXT_INT3_IRQHandler
		BL  EXT_INT3_IRQHandler

        PUBWEAK EXT_INT4_IRQHandler
        SECTION .text:CODE:REORDER(1)
EXT_INT4_IRQHandler
		BL  EXT_INT4_IRQHandler

        END
