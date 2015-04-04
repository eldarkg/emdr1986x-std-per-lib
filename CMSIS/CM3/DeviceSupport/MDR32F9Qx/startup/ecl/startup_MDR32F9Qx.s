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


        MODULE  ?cstartup

        ;; Forward declaration of sections.
        SECTION CSTACK:DATA:NOROOT(3)

        SECTION .intvec:CODE:NOROOT(2)

        EXTERN  __iar_program_start
        EXTERN  SystemInit
        PUBLIC  __vector_table

        DATA
__vector_table
        DCD     sfe(CSTACK)
        DCD     Reset_Handler             ; Reset Handler
        DCD     NMI_Handler               ; NMI Handler
        DCD     HardFault_Handler         ; Hard Fault Handler
        DCD     MemManage_Handler         ; MPU Fault Handler
        DCD     BusFault_Handler          ; Bus Fault Handler
        DCD     UsageFault_Handler        ; Usage Fault Handler
        DCD     0                         ; Reserved
        DCD     0                         ; Reserved
        DCD     0                         ; Reserved
        DCD     0                         ; Reserved
        DCD     SVC_Handler               ; SVCall Handler
        DCD     DebugMon_Handler          ; Debug Monitor Handler
        DCD     0                         ; Reserved
        DCD     PendSV_Handler            ; PendSV Handler
        DCD     SysTick_Handler           ; SysTick Handler

         ; External Interrupts
        DCD     CAN1_IRQHandler           ; IRQ0
        DCD     CAN2_IRQHandler           ; IRQ1
        DCD     USB_IRQHandler            ; IRQ2
        DCD     0                         ; IRQ3  reserved
        DCD     0                         ; IRQ4  reserved
        DCD     DMA_IRQHandler            ; IRQ5
        DCD     UART1_IRQHandler          ; IRQ6
        DCD     UART2_IRQHandler          ; IRQ7
        DCD     SSP1_IRQHandler           ; IRQ8
        DCD     0                         ; IRQ9  reserved
        DCD     I2C_IRQHandler            ; IRQ10
        DCD     POWER_IRQHandler          ; IRQ11
        DCD     WWDG_IRQHandler           ; IRQ12
        DCD     0                         ; IRQ13 reserved
        DCD     Timer1_IRQHandler         ; IRQ14
        DCD     Timer2_IRQHandler         ; IRQ15
        DCD     Timer3_IRQHandler         ; IRQ16
        DCD     ADC_IRQHandler            ; IRQ17
        DCD     0                         ; IRQ18 reserved
        DCD     COMPARATOR_IRQHandler     ; IRQ19
        DCD     SSP2_IRQHandler           ; IRQ20
        DCD     0                         ; IRQ21 reserved
        DCD     0                         ; IRQ22 reserved
        DCD     0                         ; IRQ23 reserved
        DCD     0                         ; IRQ24 reserved
        DCD     0                         ; IRQ25 reserved
        DCD     0                         ; IRQ26 reserved
        DCD     BACKUP_IRQHandler         ; IRQ27
        DCD     EXT_INT1_IRQHandler       ; IRQ28
        DCD     EXT_INT2_IRQHandler       ; IRQ29
        DCD     EXT_INT3_IRQHandler       ; IRQ30
        DCD     EXT_INT4_IRQHandler       ; IRQ31

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Default interrupt handlers.
;;
        THUMB

        PUBWEAK Reset_Handler
        SECTION .text:CODE:REORDER(2)
Reset_Handler
        LDR     R0, =SystemInit
        BLX     R0
        LDR     R0, =__iar_program_start
        BX      R0

        PUBWEAK NMI_Handler
        SECTION .text:CODE:REORDER(1)
NMI_Handler
        B NMI_Handler

        PUBWEAK HardFault_Handler
        SECTION .text:CODE:REORDER(1)
HardFault_Handler
        B HardFault_Handler

        PUBWEAK MemManage_Handler
        SECTION .text:CODE:REORDER(1)
MemManage_Handler
        B MemManage_Handler

        PUBWEAK BusFault_Handler
        SECTION .text:CODE:REORDER(1)
BusFault_Handler
        B BusFault_Handler

        PUBWEAK UsageFault_Handler
        SECTION .text:CODE:REORDER(1)
UsageFault_Handler
        B UsageFault_Handler

        PUBWEAK SVC_Handler
        SECTION .text:CODE:REORDER(1)
SVC_Handler
        B SVC_Handler

        PUBWEAK DebugMon_Handler
        SECTION .text:CODE:REORDER(1)
DebugMon_Handler
        B DebugMon_Handler

        PUBWEAK PendSV_Handler
        SECTION .text:CODE:REORDER(1)
PendSV_Handler
        B PendSV_Handler

        PUBWEAK SysTick_Handler
        SECTION .text:CODE:REORDER(1)
SysTick_Handler
        B SysTick_Handler


        PUBWEAK CAN1_IRQHandler
        SECTION .text:CODE:REORDER(1)
CAN1_IRQHandler
        B CAN1_IRQHandler

        PUBWEAK CAN2_IRQHandler
        SECTION .text:CODE:REORDER(1)
CAN2_IRQHandler
        B CAN2_IRQHandler

        PUBWEAK USB_IRQHandler
        SECTION .text:CODE:REORDER(1)
USB_IRQHandler
        B USB_IRQHandler

        PUBWEAK DMA_IRQHandler
        SECTION .text:CODE:REORDER(1)
DMA_IRQHandler
        B DMA_IRQHandler

        PUBWEAK UART1_IRQHandler
        SECTION .text:CODE:REORDER(1)
UART1_IRQHandler
        B UART1_IRQHandler

        PUBWEAK UART2_IRQHandler
        SECTION .text:CODE:REORDER(1)
UART2_IRQHandler
        B UART2_IRQHandler

        PUBWEAK SSP1_IRQHandler
        SECTION .text:CODE:REORDER(1)
SSP1_IRQHandler
        B SSP1_IRQHandler

        PUBWEAK I2C_IRQHandler
        SECTION .text:CODE:REORDER(1)
I2C_IRQHandler
        B I2C_IRQHandler

        PUBWEAK POWER_IRQHandler
        SECTION .text:CODE:REORDER(1)
POWER_IRQHandler
        B POWER_IRQHandler

        PUBWEAK WWDG_IRQHandler
        SECTION .text:CODE:REORDER(1)
WWDG_IRQHandler
        B WWDG_IRQHandler

        PUBWEAK Timer1_IRQHandler
        SECTION .text:CODE:REORDER(1)
Timer1_IRQHandler
        B Timer1_IRQHandler

        PUBWEAK Timer2_IRQHandler
        SECTION .text:CODE:REORDER(1)
Timer2_IRQHandler
        B Timer2_IRQHandler

        PUBWEAK Timer3_IRQHandler
        SECTION .text:CODE:REORDER(1)
Timer3_IRQHandler
        B Timer3_IRQHandler

        PUBWEAK ADC_IRQHandler
        SECTION .text:CODE:REORDER(1)
ADC_IRQHandler
        B ADC_IRQHandler

        PUBWEAK COMPARATOR_IRQHandler
        SECTION .text:CODE:REORDER(1)
COMPARATOR_IRQHandler
        B COMPARATOR_IRQHandler

        PUBWEAK SSP2_IRQHandler
        SECTION .text:CODE:REORDER(1)
SSP2_IRQHandler
        B SSP2_IRQHandler

        PUBWEAK BACKUP_IRQHandler
        SECTION .text:CODE:REORDER(1)
BACKUP_IRQHandler
        B BACKUP_IRQHandler

        PUBWEAK EXT_INT1_IRQHandler
        SECTION .text:CODE:REORDER(1)
EXT_INT1_IRQHandler
        B EXT_INT1_IRQHandler

        PUBWEAK EXT_INT2_IRQHandler
        SECTION .text:CODE:REORDER(1)
EXT_INT2_IRQHandler
        B EXT_INT2_IRQHandler

        PUBWEAK EXT_INT3_IRQHandler
        SECTION .text:CODE:REORDER(1)
EXT_INT3_IRQHandler
        B EXT_INT3_IRQHandler

        PUBWEAK EXT_INT4_IRQHandler
        SECTION .text:CODE:REORDER(1)
EXT_INT4_IRQHandler
        B EXT_INT4_IRQHandler

        END
;/******************* (C) COPYRIGHT 2010 Phyton *********************************
;*
;* END OF FILE startup_MDR32F9Qx.s */
