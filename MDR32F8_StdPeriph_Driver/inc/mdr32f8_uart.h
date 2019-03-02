/**
  ******************************************************************************
  * @file    mdr32f8_uart.h
  * @author  Milandr
  * @version V1.0.0
  * @date    20/07/2015
  * @brief   This file contains all the functions prototypes for the UART
  *          firmware library.
  ******************************************************************************
  * <br><br>
  *
  *
  * <h2><center>&copy; COPYRIGHT 2015 Milandr</center></h2>
  ******************************************************************************
  * FILE mdr32f8_uart.h
  */
	
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MDR32F8_UART_H
#define __MDR32F8_UART_H


#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"	
#include "mdr32f8_config.h"
#include "MDR1986VE8T.h"	


/** @addtogroup __MDR32F8_StdPeriph_Driver
  * @{
  */

/** @addtogroup UART
  * @{
  */

/** @defgroup UART_Exported_Types
  * @{
  */
typedef enum {BaudRateInvalid = 0, BaudRateValid = !BaudRateInvalid} BaudRateStatus;

/**
  * @brief  UART init structure definition
  */

typedef struct
{
  uint32_t UART_BaudRate;            /*!< This member configures the UART communication baud rate.
                                          The baud rate is computed using the following formula:
                                           - IntegerDivider = ((UARTCLK) / (16 * (UART_InitStruct->UART_BaudRate)))
                                           - FractionalDivider = ((IntegerDivider - ((u32) IntegerDivider)) * 64) + 0.5 */
  uint16_t UART_WordLength;          /*!< Specifies the number of data bits transmitted or received in a frame.
                                          This parameter is one of @ref UART_Word_Length values. */
  uint16_t UART_StopBits;            /*!< Specifies the number of stop bits transmitted.
                                          This parameter is one of @ref UART_Stop_Bits values. */
  uint16_t UART_Parity;              /*!< Specifies the parity mode.
                                          This parameter is one of @ref UART_Parity values. */
  uint16_t UART_FIFOMode;            /*!< Specifies the FIFO mode.
                                          This parameter is one of @ref UART_FIFO_Mode values. */
  uint16_t UART_HardwareFlowControl; /*!< Specifies whether the hardware flow control mode is enabled or disabled.
                                          This parameter is one of @ref UART_Hardware_Flow_Control values. */
}UART_InitTypeDef;


#define IS_UART_ALL_PERIPH(PERIPH)          (((PERIPH) == MDR_UART0) || \
                                             ((PERIPH) == MDR_UART1))
	
/** @defgroup UART_Word_Length
  * @{
  */

#define UART_WordLength5b                   ((uint16_t)0x0000)
#define UART_WordLength6b                   ((uint16_t)0x0020)
#define UART_WordLength7b                   ((uint16_t)0x0040)
#define UART_WordLength8b                   ((uint16_t)0x0060)

#define IS_UART_WORD_LENGTH(LENGTH)         (((LENGTH) == UART_WordLength5b) || \
                                             ((LENGTH) == UART_WordLength6b) || \
                                             ((LENGTH) == UART_WordLength7b) || \
                                             ((LENGTH) == UART_WordLength8b))
/**
  * @}
  */ 

/** @defgroup UART_Stop_Bits
  * @{
  */
#define UART_StopBits1                      ((uint16_t)0x0000)
#define UART_StopBits2                      ((uint16_t)0x0008)

#define IS_UART_STOPBITS(STOPBITS)          (((STOPBITS) == UART_StopBits1) || \
                                             ((STOPBITS) == UART_StopBits2))
/**
  * @}
  */ 
	
/** @defgroup UART_Parity
  * @{
  */
#define UART_Parity_No                      ((uint16_t)0x0000)
#define UART_Parity_Even                    ((uint16_t)0x0006)
#define UART_Parity_Odd                     ((uint16_t)0x0002)
#define UART_Parity_1                       ((uint16_t)0x0082)
#define UART_Parity_0                       ((uint16_t)0x0086)

#define IS_UART_PARITY(PARITY)              (((PARITY) == UART_Parity_No)   || \
                                             ((PARITY) == UART_Parity_Even) || \
                                             ((PARITY) == UART_Parity_Odd)  || \
                                             ((PARITY) == UART_Parity_1)    || \
                                             ((PARITY) == UART_Parity_0))	
/**
  * @}
  */ 
/** @defgroup UART_FIFO_Mode
  * @{
  */

#define UART_FIFO_OFF                       ((uint16_t)0x0000)
#define UART_FIFO_ON                        ((uint16_t)0x0010)

#define IS_UART_FIFOMODE(FIFOMODE)          (((FIFOMODE) == UART_FIFO_ON) || \
                                             ((FIFOMODE) == UART_FIFO_OFF))	
	
/**
  * @}
  */ 
/** @defgroup UART_Hardware_Flow_Control
  * @{
  */
#define UART_HardwareFlowControl_None       ((uint16_t)0x0000)
#define UART_HardwareFlowControl_CTSEn      ((uint16_t)0x8000)
#define UART_HardwareFlowControl_RTSEn      ((uint16_t)0x4000)
#define UART_HardwareFlowControl_Out2       ((uint16_t)0x2000)
#define UART_HardwareFlowControl_Out1       ((uint16_t)0x1000)
#define UART_HardwareFlowControl_RTS        ((uint16_t)0x0800)
#define UART_HardwareFlowControl_DTR        ((uint16_t)0x0400)
#define UART_HardwareFlowControl_RXE        ((uint16_t)0x0200)
#define UART_HardwareFlowControl_TXE        ((uint16_t)0x0100)
#define UART_HardwareFlowControl_LBE        ((uint16_t)0x0080)

#define UART_HARDWARE_FLOW_CONTROL_MASK		((uint16_t)0xFF80)

#define IS_UART_HARDWARE_FLOW_CONTROL(CONTROL) 		((CONTROL&(~(UART_HARDWARE_FLOW_CONTROL_MASK))) == 0)	
/**
  * @}
  */ 
/** @defgroup UART_Flags
  * @{
  */

#define UART_FLAG_RI                        ((uint32_t)0x00000100)
#define UART_FLAG_TXFE                      ((uint32_t)0x00000080)
#define UART_FLAG_RXFF                      ((uint32_t)0x00000040)
#define UART_FLAG_TXFF                      ((uint32_t)0x00000020)
#define UART_FLAG_RXFE                      ((uint32_t)0x00000010)
#define UART_FLAG_BUSY                      ((uint32_t)0x00000008)
#define UART_FLAG_DCD                       ((uint32_t)0x00000004)
#define UART_FLAG_DSR                       ((uint32_t)0x00000002)
#define UART_FLAG_CTS                       ((uint32_t)0x00000001)

#define IS_UART_FLAG(FLAG)                  (((FLAG) == UART_FLAG_RI)   || ((FLAG) == UART_FLAG_TXFE) || \
                                             ((FLAG) == UART_FLAG_RXFF) || ((FLAG) == UART_FLAG_TXFF) || \
                                             ((FLAG) == UART_FLAG_RXFE) || ((FLAG) == UART_FLAG_BUSY) || \
                                             ((FLAG) == UART_FLAG_DCD)  || ((FLAG) == UART_FLAG_DSR)  || \
                                             ((FLAG) == UART_FLAG_CTS))

#define IS_UART_BAUDRATE(BAUDRATE) (((BAUDRATE) > 0) && ((BAUDRATE) <= 921600))
/**
  * @}
  */ 

#define UART_DIV_Msk        								((uint32_t)0x0000FFFF)
#define UART_CLK_EN         								(1<<16)
#define UART_CLKSRC_msk                     ((uint32_t)0xF0000000) 
#define UART_CLKSRC_offs                    28

#define UART_CLKSRC_HSI                     ((uint32_t)0x00000000)
#define UART_CLKSRC_HSE0                    ((uint32_t)0x00000001)
#define UART_CLKSRC_HSE1                    ((uint32_t)0x00000002)
#define UART_CLKSRC_LSI                     ((uint32_t)0x00000003)
#define UART_CLKSRC_LSE                     ((uint32_t)0x00000004)
#define UART_CLKSRC_PLL0                    ((uint32_t)0x00000005)
#define UART_CLKSRC_PLL1                    ((uint32_t)0x00000006)
#define UART_CLKSRC_PLL2                    ((uint32_t)0x00000007)
#define UART_CLKSRC_MAX_CLK                 ((uint32_t)0x0000000C)

#define IS_UART_CLKSRC(CLKSRC)  					(((CLKSRC) == UART_CLKSRC_HSI)  || \
																					 ((CLKSRC) == UART_CLKSRC_HSE0) || \
																					 ((CLKSRC) == UART_CLKSRC_HSE1) || \
																					 ((CLKSRC) == UART_CLKSRC_LSI)  || \
																					 ((CLKSRC) == UART_CLKSRC_LSE)  || \
																					 ((CLKSRC) == UART_CLKSRC_PLL0) || \
																					 ((CLKSRC) == UART_CLKSRC_PLL1) || \
																					 ((CLKSRC) == UART_CLKSRC_PLL2) || \
																					 ((CLKSRC) == UART_CLKSRC_MAX_CLK))																				 

#define UART_CLKdiv1                        ((uint32_t)0x00000000)
#define UART_CLKdiv2                        ((uint32_t)0x00000001)
#define UART_CLKdiv4                        ((uint32_t)0x00000002)
#define UART_CLKdiv8                        ((uint32_t)0x00000003)

/** @defgroup UART_Interrupt_definition UART Interrupt definition
  * @{
  */

#define UART_IT_OE                          ((uint32_t)0x00000400)
#define UART_IT_BE                          ((uint32_t)0x00000200)
#define UART_IT_PE                          ((uint32_t)0x00000100)
#define UART_IT_FE                          ((uint32_t)0x00000080)
#define UART_IT_RT                          ((uint32_t)0x00000040)
#define UART_IT_TX                          ((uint32_t)0x00000020)
#define UART_IT_RX                          ((uint32_t)0x00000010)
#define UART_IT_DSR                         ((uint32_t)0x00000008)
#define UART_IT_DCD                         ((uint32_t)0x00000004)
#define UART_IT_CTS                         ((uint32_t)0x00000002)
#define UART_IT_RI                          ((uint32_t)0x00000001)

#define IS_UART_CONFIG_IT(IT)               (((IT) == UART_IT_OE)  || ((IT) == UART_IT_BE)  || \
                                             ((IT) == UART_IT_PE)  || ((IT) == UART_IT_FE)  || \
                                             ((IT) == UART_IT_RT)  || ((IT) == UART_IT_TX)  || \
                                             ((IT) == UART_IT_RX)  || ((IT) == UART_IT_DSR) || \
                                             ((IT) == UART_IT_DCD) || ((IT) == UART_IT_CTS) || \
                                             ((IT) == UART_IT_RI))
/**
  * @}
  */ 																						 

/**
  * @}
  */ 
	
/**
  * @}
  */ 	
	
BaudRateStatus UART_Init ( MDR_UART_TypeDef* UARTx,
						   UART_InitTypeDef* UART_InitStruct, uint32_t CPU_FREQ);
void UART_Cmd(MDR_UART_TypeDef* UARTx, FunctionalState NewState);	
FlagStatus UART_GetFlagStatus(MDR_UART_TypeDef* UARTx, uint32_t UART_FLAG);
void UART_SendData(MDR_UART_TypeDef* UARTx, uint16_t Data);
uint16_t UART_ReceiveData(MDR_UART_TypeDef* UARTx);
void UART_CLK_en(uint32_t UART_CLKSRC, uint32_t UART_DIV);
ITStatus UART_GetITStatusMasked(MDR_UART_TypeDef* UARTx, uint32_t UART_IT);
void UART_ClearITPendingBit(MDR_UART_TypeDef* UARTx, uint32_t UART_IT);
void UART_ITConfig(MDR_UART_TypeDef* UARTx, uint32_t UART_IT, FunctionalState NewState);

#endif /* __MDR32F8_UART_H */

/******************* (C) COPYRIGHT 2015 Milandr *********************************
*
* END OF FILE mdr32f8_uart.h */	
