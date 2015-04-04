;/*****************************************************************************/
;/* 1986VE3.s: Startup file for ARM Cortex-M1 Device Family                   */
;/*****************************************************************************/
;/* <<< Use Configuration Wizard in Context Menu >>>                          */
;/*****************************************************************************/
;/* This file is part of the uVision/ARM development tools.                   */
;/* Copyright (c) 2005-2008 Keil Software. All rights reserved.               */
;/* This software may only be used under the terms of a valid, current,       */
;/* end user licence from KEIL for a compatible version of KEIL software      */
;/* development tools. Nothing else gives you the right to use this software. */
;/*****************************************************************************/


;// <h> Stack Configuration
;//   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
;// </h>

Stack_Size      EQU     0x00001000

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


;// <h> Heap Configuration
;//   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
;// </h>

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

__Vectors       DCD     __initial_sp              ; Top of Stack
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
							DCD     USB_IRQHandler							;IRQ2
							DCD     CAN1_IRQHandler							;IRQ3
							DCD     CAN2_IRQHandler							;IRQ4
							DCD     DMA_IRQHandler							;IRQ5
							DCD     UART1_IRQHandler						;IRQ6
							DCD     UART2_IRQHandler						;IRQ7
							DCD     SSP1_IRQHandler							;IRQ8
							DCD     BUSY_IRQHandler							;IRQ9
							DCD     ARINC429R_IRQHandler				;IRQ10
							DCD     POWER_IRQHandler						;IRQ11
							DCD     WWDG_IRQHandler							;IRQ12
							DCD     Timer4_IRQHandler						;IRQ13
							DCD     Timer1_IRQHandler						;IRQ14
							DCD     Timer2_IRQHandler						;IRQ15
							DCD     Timer3_IRQHandler						;IRQ16
							DCD     ADC_IRQHandler							;IRQ17
							DCD     ETHERNET_IRQHandler					;IRQ18
							DCD     SSP3_IRQHandler							;IRQ19
							DCD     SSP2_IRQHandler							;IRQ20
							DCD     ARINC429T_IRQHandler				;IRQ21
							DCD     KEYPAD_IRQHandler						;IRQ22
							DCD     LED_IRQHandler							;IRQ23
							DCD     UART3_UART4_IRQHandler			;IRQ24
							DCD     AudioCodec_IRQHandler				;IRQ25
							DCD     ETHERNET2_IRQHandler				;IRQ26
							DCD     BKP_IRQHandler							;IRQ27
							DCD     EXT_INT1_IRQHandler					;IRQ28
							DCD     EXT_INT2_IRQHandler					;IRQ29
							DCD     EXT_INT3_IRQHandler					;IRQ30
							DCD     EXT_INT4_IRQHandler					;IRQ31

                AREA    |.text|, CODE, READONLY


; Reset Handler

Reset_Handler   PROC
                EXPORT  Reset_Handler			[WEAK]
                IMPORT  __main
                LDR     R0,=__main
				BX      R0
                ENDP


; Dummy Exception Handlers (infinite loops which can be modified)                

NMI_Handler     PROC
                EXPORT  NMI_Handler				[WEAK]
                B       .
                ENDP

HardFault_Handler PROC
                EXPORT  HardFault_Handler		[WEAK]
                B       .
                ENDP

SVC_Handler     PROC
                EXPORT  SVC_Handler				[WEAK]
                B       .
                ENDP

PendSV_Handler  PROC
                EXPORT  PendSV_Handler			[WEAK]
                B       .
                ENDP

SysTick_Handler PROC
                EXPORT  SysTick_Handler			[WEAK]
				B       .
                ENDP

; External Interrupts

MIL_STD_1553B2_IRQHandler	PROC
                EXPORT  MIL_STD_1553B2_IRQHandler	[WEAK]
				B       .
                ENDP

MIL_STD_1553B1_IRQHandler	PROC
                EXPORT  MIL_STD_1553B1_IRQHandler	[WEAK]
				B       .
                ENDP

USB_IRQHandler		PROC
				EXPORT  USB_IRQHandler				[WEAK]
				B       .
                ENDP
                
CAN1_IRQHandler	PROC
				EXPORT  CAN1_IRQHandler			[WEAK]
				B       .
                ENDP

CAN2_IRQHandler	PROC
				EXPORT  CAN2_IRQHandler			[WEAK]
				B       .
                ENDP

DMA_IRQHandler		PROC
				EXPORT  DMA_IRQHandler				[WEAK]
				B       .
                ENDP

UART1_IRQHandler	PROC
				EXPORT  UART1_IRQHandler			[WEAK]
				B       .
                ENDP

UART2_IRQHandler	PROC
				EXPORT  UART2_IRQHandler			[WEAK]
				B       .
                ENDP

SSP1_IRQHandler	PROC
				EXPORT  SSP1_IRQHandler			[WEAK]
				B       .
                ENDP

BUSY_IRQHandler	PROC
				EXPORT  BUSY_IRQHandler				[WEAK]
				B       .
                ENDP

ARINC429R_IRQHandler	PROC
                EXPORT  ARINC429R_IRQHandler		[WEAK]
				B       .
                ENDP

POWER_IRQHandler	PROC
				EXPORT  POWER_IRQHandler			[WEAK]
				B       .
                ENDP

WWDG_IRQHandler	PROC
				EXPORT  WWDG_IRQHandler			[WEAK]
				B       .
                ENDP

Timer4_IRQHandler	PROC
				EXPORT  Timer4_IRQHandler			[WEAK]
				B       .
                ENDP

Timer1_IRQHandler	PROC
				EXPORT  Timer1_IRQHandler			[WEAK]
				B       .
                ENDP

Timer2_IRQHandler	PROC
				EXPORT  Timer2_IRQHandler			[WEAK]
				B       .
                ENDP

Timer3_IRQHandler	PROC
				EXPORT  Timer3_IRQHandler			[WEAK]
				B       .
                ENDP

ADC_IRQHandler		PROC
				EXPORT  ADC_IRQHandler				[WEAK]
				B       .
                ENDP

ETHERNET_IRQHandler	PROC
				EXPORT  ETHERNET_IRQHandler		[WEAK]
				B       .
                ENDP

SSP3_IRQHandler	PROC
				EXPORT  SSP3_IRQHandler			[WEAK]
				B       .
                ENDP

SSP2_IRQHandler	PROC
				EXPORT  SSP2_IRQHandler			[WEAK]
				B       .
                ENDP

ARINC429T_IRQHandler	PROC
				EXPORT  ARINC429T_IRQHandler		[WEAK]
				B       .
                ENDP
                
KEYPAD_IRQHandler	PROC
				EXPORT  KEYPAD_IRQHandler		[WEAK]
				B       .
                ENDP

LED_IRQHandler	PROC
				EXPORT  LED_IRQHandler		[WEAK]
				B       .
                ENDP

UART3_UART4_IRQHandler	PROC
				EXPORT  UART3_UART4_IRQHandler		[WEAK]
				B       .
                ENDP
AudioCodec_IRQHandler	PROC
				EXPORT  AudioCodec_IRQHandler		[WEAK]
				B       .
                ENDP
ETHERNET2_IRQHandler	PROC
				EXPORT  ETHERNET2_IRQHandler		[WEAK]
				B       .
                ENDP

BKP_IRQHandler		PROC
				EXPORT  BKP_IRQHandler				[WEAK]
				B       .
                ENDP

EXT_INT1_IRQHandler	PROC
				EXPORT  EXT_INT1_IRQHandler		[WEAK]
				B       .
                ENDP

EXT_INT2_IRQHandler	PROC
				EXPORT  EXT_INT2_IRQHandler		[WEAK]
				B       .
                ENDP

EXT_INT3_IRQHandler	PROC
				EXPORT  EXT_INT3_IRQHandler		[WEAK]
				B       .
                ENDP

EXT_INT4_IRQHandler	PROC
				EXPORT  EXT_INT4_IRQHandler		[WEAK]
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
