/**
  * FILE MDR32F9Qx_uart.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MDR32F9Qx_UART_H
#define __MDR32F9Qx_UART_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_config.h"
#include "MDR32F9Qx_lib.h"

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @addtogroup UART
  * @{
  */

/** @defgroup UART_Exported_Types UART Exported Types
  * @{
  */

typedef enum {BaudRateInvalid = 0, BaudRateValid = !BaudRateInvalid} BaudRateStatus;

/**
  * @brief  UART Init Structure definition
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

/** @} */ /* End of group UART_Exported_Types */


/** @defgroup UART_Exported_Constants UART Exported Constants
  * @{
  */

#if defined (USE_MDR1986VE9x) || defined(USE_MDR1986VE1T)

#define IS_UART_ALL_PERIPH(PERIPH)          (((PERIPH) == MDR_UART1) || \
                                             ((PERIPH) == MDR_UART2))
#elif defined (USE_MDR1986VE3)

#define IS_UART_ALL_PERIPH(PERIPH)          (((PERIPH) == MDR_UART1) || \
                                            ((PERIPH) == MDR_UART2) || \
                                            ((PERIPH) == MDR_UART3) || \
                                            ((PERIPH) == MDR_UART4))

#elif defined (USE_MDR1901VC1T)

#define IS_UART_ALL_PERIPH(PERIPH)          (((PERIPH) == MDR_UART1) || \
											 ((PERIPH) == MDR_UART2) || \
											 ((PERIPH) == MDR_UART3))
#endif

/** @defgroup UART_Word_Length UART Word Length
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

/** @} */ /* End of group UART_Word_Length */

/** @defgroup UART_Stop_Bits UART Stop Bits
  * @{
  */

#define UART_StopBits1                      ((uint16_t)0x0000)
#define UART_StopBits2                      ((uint16_t)0x0008)

#define IS_UART_STOPBITS(STOPBITS)          (((STOPBITS) == UART_StopBits1) || \
                                             ((STOPBITS) == UART_StopBits2))

/** @} */ /* End of group UART_Stop_Bits */

/** @defgroup UART_Parity UART Parity
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

/** @} */ /* End of group UART_Parity */

/** @defgroup UART_FIFO_Mode UART FIFO Mode
  * @{
  */

#define UART_FIFO_OFF                       ((uint16_t)0x0000)
#define UART_FIFO_ON                        ((uint16_t)0x0010)

#define IS_UART_FIFOMODE(FIFOMODE)          (((FIFOMODE) == UART_FIFO_ON) || \
                                             ((FIFOMODE) == UART_FIFO_OFF))

/** @} */ /* End of group UART_FIFO_Mode */

/** @defgroup UART_Hardware_Flow_Control UART Hardware Flow Control
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

/** @} */ /* End of group UART_Hardware_Flow_Control */

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

/** @} */ /* End of group UART_Interrupt_definition */

/** @defgroup UART_DMA_interrupt_definition UART DMA interrupt definition
  * @{
  */

#define UART_IT_FIFO_LVL_2words             ((uint32_t)0x00000000)
#define UART_IT_FIFO_LVL_4words             ((uint32_t)0x00000001)
#define UART_IT_FIFO_LVL_8words             ((uint32_t)0x00000002)
#define UART_IT_FIFO_LVL_12words            ((uint32_t)0x00000003)
#define UART_IT_FIFO_LVL_14words            ((uint32_t)0x00000004)

#define IS_UART_IT_FIFO_LVL(IT_FIFO_LVL)    (((IT_FIFO_LVL) == UART_IT_FIFO_LVL_2words) || \
                                             ((IT_FIFO_LVL) == UART_IT_FIFO_LVL_4words) || \
                                             ((IT_FIFO_LVL) == UART_IT_FIFO_LVL_8words) || \
                                             ((IT_FIFO_LVL) == UART_IT_FIFO_LVL_12words) || \
                                             ((IT_FIFO_LVL) == UART_IT_FIFO_LVL_14words))

/** @} */ /* End of group UART_DMA_interrupt_definition */

/** @defgroup UART_DMA_request UART DMA request
  * @{
  */

#define UART_DMA_RXE                        ((uint32_t)0x00000001)
#define UART_DMA_TXE                        ((uint32_t)0x00000002)
#define UART_DMA_ONERR                      ((uint32_t)0x00000004)

#define IS_UART_DMAREQ(DMAREQ)              (((DMAREQ) == UART_DMA_RXE) || \
                                             ((DMAREQ) == UART_DMA_TXE) || \
                                             ((DMAREQ) == UART_DMA_ONERR))

/** @} */ /* End of group UART_DMA_request */

/** @defgroup UART_IrDA_Low_Power UART IrDA Low Power
  * @{
  */

#define UART_IrDAMode_LowPower              ((uint32_t)0x00000004)
#define UART_IrDAMode_Normal                ((uint32_t)0x00000000)

#define IS_UART_IRDA_MODE(MODE)             (((MODE) == UART_IrDAMode_LowPower) || \
                                             ((MODE) == UART_IrDAMode_Normal))

/** @} */ /* End of group UART_IrDA_Low_Power */

/** @defgroup UART_Flags UART Flags
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

/** @} */ /* End of group UART_Flags */

/** @defgroup UART_Data_Status UART Data Status
  * @{
  */

#define UART_Data_OE                        0x0B
#define UART_Data_BE                        0x0A
#define UART_Data_PE                        0x09
#define UART_Data_FE                        0x08

#define UART_Data_OE_Msk                    ((uint32_t)(1 << UART_Data_OE))
#define UART_Data_BE_Msk                    ((uint32_t)(1 << UART_Data_BE))
#define UART_Data_PE_Msk                    ((uint32_t)(1 << UART_Data_FE))
#define UART_Data_FE_Msk                    ((uint32_t)(1 << UART_Data_PE))

#define UART_Data(DATA)                     ((uint8_t)DATA)
#define UART_Flags(DATA)                    ((uint8_t)(DATA >> 8))
#define UART_CheckDataStatus(DATA, BIT)     ((((uint32_t)DATA) << (31 - BIT)) >> 31)

#define IS_UART_DATA(DATA)                  ((DATA) <= 0xFF)

/** @} */ /* End of group UART_Data_Status */

/** @defgroup UART_Clock_BRG UART Clock BRG
  * @{
  */

#define UART_HCLKdiv1                       ((uint32_t)0x00000000)
#define UART_HCLKdiv2                       ((uint32_t)0x00000001)
#define UART_HCLKdiv4                       ((uint32_t)0x00000002)
#define UART_HCLKdiv8                       ((uint32_t)0x00000003)
#define UART_HCLKdiv16                      ((uint32_t)0x00000004)
#define UART_HCLKdiv32                      ((uint32_t)0x00000005)
#define UART_HCLKdiv64                      ((uint32_t)0x00000006)
#define UART_HCLKdiv128                     ((uint32_t)0x00000007)

#define IS_UART_CLOCK_BRG(BRG)              ((BRG) <= 7)

/** @} */ /* End of group UART_Clock_BRG */

/** @} */ /* End of group UART_Exported_Constants */

/** @defgroup UART_Exported_Macros UART Exported Macros
  * @{
  */

/** @} */ /* End of group UART_Exported_Macros */

/** @defgroup UART_Exported_Functions UART Exported Functions
  * @{
  */

void UART_DeInit(MDR_UART_TypeDef* UARTx);
BaudRateStatus UART_Init(MDR_UART_TypeDef* UARTx, UART_InitTypeDef* UART_InitStruct);
void UART_StructInit(UART_InitTypeDef* UART_InitStruct);

void UART_Cmd(MDR_UART_TypeDef* UARTx, FunctionalState NewState);

void UART_ITConfig(MDR_UART_TypeDef* UARTx, uint32_t UART_IT, FunctionalState NewState);
ITStatus UART_GetITStatus(MDR_UART_TypeDef* UARTx, uint32_t UART_IT);
ITStatus UART_GetITStatusMasked(MDR_UART_TypeDef* UARTx, uint32_t UART_IT);
void UART_ClearITPendingBit(MDR_UART_TypeDef* UARTx, uint32_t UART_IT);

void UART_DMAConfig(MDR_UART_TypeDef* UARTx, uint32_t UART_IT_RB_LVL, uint32_t UART_IT_TB_LVL);
void UART_DMACmd(MDR_UART_TypeDef* UARTx, uint32_t UART_DMAReq, FunctionalState NewState);

void UART_SendData(MDR_UART_TypeDef* UARTx, uint16_t Data);
uint16_t UART_ReceiveData(MDR_UART_TypeDef* UARTx);
void UART_BreakLine(MDR_UART_TypeDef* UARTx, FunctionalState NewState);

void UART_IrDAConfig(MDR_UART_TypeDef* UARTx, uint32_t UART_IrDAMode);
void UART_IrDACmd(MDR_UART_TypeDef* UARTx, FunctionalState NewState);

FlagStatus UART_GetFlagStatus(MDR_UART_TypeDef* UARTx, uint32_t UART_FLAG);
void UART_BRGInit(MDR_UART_TypeDef* UARTx, uint32_t UART_BRG);

/** @} */ /* End of group UART_Exported_Functions */

/** @} */ /* End of group UART */

/** @} */ /* End of group MDR32F9Qx_StdPeriph_Driver */

#ifdef __cplusplus
} // extern "C" block end
#endif

#endif /* __MDR32F9Qx_UART_H */

/*
*
* END OF FILE MDR32F9Qx_uart.h */
