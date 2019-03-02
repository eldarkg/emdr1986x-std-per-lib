/**
  * FILE MDR32F9Qx_ssp.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MDR32F9Qx_SSP_H
#define __MDR32F9Qx_SSP_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_config.h"
#include "MDR32F9Qx_lib.h"

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @addtogroup SSP
  * @{
  */

/** @defgroup SSP_Exported_Types SSP Exported Types
  * @{
  */

/**
  * @brief  SSP Init Structure definition
  */

typedef struct
{
  uint16_t SSP_SCR;                        /*!< This member configures the SSP communication speed.
                                                This parameter is number from 0 to 255.
                                                The information rate is computed using the following formula:
                                                F_SSPCLK / ( CPSDVR * (1 + SCR) ) */
  uint16_t SSP_CPSDVSR;                    /*!< This member configures the SSP clock divider.
                                                This parameter is an even number from 2 to 254 */
  uint16_t SSP_Mode;                       /*!< Specifies the number of stop bits transmitted.
                                                This parameter is one of @ref SSP_Mode values. */
  uint16_t SSP_WordLength;                 /*!< Specifies the number of data bits transmitted or received in a frame.
                                                This parameter is one of @ref SSP_Word_Length values. */
  uint16_t SSP_SPH;                        /*!< Specifies the number of stop bits transmitted.
                                                This parameter is one of @ref SSP_Clock_Phase values. */
  uint16_t SSP_SPO;                        /*!< Specifies the number of stop bits transmitted.
                                                This parameter is one of @ref SSP_Clock_Polarity values. */
  uint16_t SSP_FRF;                        /*!< Specifies the number of stop bits transmitted.
                                                This parameter is one of @ref SSP_Frame_Format values. */
  uint16_t SSP_HardwareFlowControl;        /*!< Specifies whether the hardware flow control mode is enabled or disabled.
                                                This parameter is one of @ref SSP_Hardware_Flow_Control values. */
}SSP_InitTypeDef;

/** @} */ /* End of group SSP_Exported_Types */


/** @defgroup SSP_Exported_Constants SSP Exported Constants
  * @{
  */

#ifdef USE_MDR1986VE9x /* For Cortex M3 */
#define IS_SSP_ALL_PERIPH(PERIPH)          (((PERIPH) == MDR_SSP1) || \
                                            ((PERIPH) == MDR_SSP2))
#endif // #ifdef USE_MDR1986VE9x /* For Cortex M3 */

#ifdef USE_MDR1986VE1T /* For Cortex M1 */
#define IS_SSP_ALL_PERIPH(PERIPH)          (((PERIPH) == MDR_SSP1) || \
                                            ((PERIPH) == MDR_SSP2) || \
                                            ((PERIPH) == MDR_SSP3))
#endif // #ifdef USE_MDR1986VE1T /* For Cortex M1 */

#ifdef USE_MDR1986VE3 /* For Cortex M1 */
#define IS_SSP_ALL_PERIPH(PERIPH)          (((PERIPH) == MDR_SSP1) || \
                                            ((PERIPH) == MDR_SSP2) || \
                                            ((PERIPH) == MDR_SSP3) || \
                                            ((PERIPH) == MDR_SSP4))
#endif // #ifdef USE_MDR1986VE3 /* For Cortex M1 */



#define IS_SSP_SPEED_FACTOR(DIVIDER)       ((DIVIDER) <= 0xFF)

#define IS_SSP_SPEED_DIVIDER(DIVIDER)      (((DIVIDER) <= 0xFE) && \
                                            ((DIVIDER) >= 0x02) && \
                                            (((DIVIDER) & 0x01) == 0))

/** @defgroup SSP_Mode SSP Mode
  * @{
  */

#define SSP_ModeMaster                     ((uint32_t)0x0000)
#define SSP_ModeSlave                      ((uint32_t)0x0004)

#define IS_SSP_MODE(MODE)                  (((MODE) == SSP_ModeMaster) || \
                                            ((MODE) == SSP_ModeSlave))

/** @} */ /* End of group SSP_Mode */

/** @defgroup SSP_Word_Length SSP Word Length
  * @{
  */

#define SSP_WordLength4b                   ((uint16_t)0x0003)
#define SSP_WordLength5b                   ((uint16_t)0x0004)
#define SSP_WordLength6b                   ((uint16_t)0x0005)
#define SSP_WordLength7b                   ((uint16_t)0x0006)
#define SSP_WordLength8b                   ((uint16_t)0x0007)
#define SSP_WordLength9b                   ((uint16_t)0x0008)
#define SSP_WordLength10b                  ((uint16_t)0x0009)
#define SSP_WordLength11b                  ((uint16_t)0x000A)
#define SSP_WordLength12b                  ((uint16_t)0x000B)
#define SSP_WordLength13b                  ((uint16_t)0x000C)
#define SSP_WordLength14b                  ((uint16_t)0x000D)
#define SSP_WordLength15b                  ((uint16_t)0x000E)
#define SSP_WordLength16b                  ((uint16_t)0x000F)

#define IS_SSP_WORD_LENGTH(LENGTH)         (((LENGTH) == SSP_WordLength4b)  || \
                                            ((LENGTH) == SSP_WordLength5b)  || \
                                            ((LENGTH) == SSP_WordLength6b)  || \
                                            ((LENGTH) == SSP_WordLength7b)  || \
                                            ((LENGTH) == SSP_WordLength8b)  || \
                                            ((LENGTH) == SSP_WordLength9b)  || \
                                            ((LENGTH) == SSP_WordLength10b) || \
                                            ((LENGTH) == SSP_WordLength11b) || \
                                            ((LENGTH) == SSP_WordLength12b) || \
                                            ((LENGTH) == SSP_WordLength13b) || \
                                            ((LENGTH) == SSP_WordLength14b) || \
                                            ((LENGTH) == SSP_WordLength15b) || \
                                            ((LENGTH) == SSP_WordLength16b))

/** @} */ /* End of group SSP_Word_Length */

/** @defgroup SSP_Clock_Phase SSP Clock Phase
  * @{
  */

#define SSP_SPH_1Edge                       ((uint16_t)0x0000)
#define SSP_SPH_2Edge                       ((uint16_t)0x0080)

#define IS_SSP_SPH(PHASE)                   (((PHASE) == SSP_SPH_1Edge) || \
                                             ((PHASE) == SSP_SPH_2Edge))

/** @} */ /* End of group SSP_Clock_Phase */

/** @defgroup SSP_Clock_Polarity SSP Clock Polarity
  * @{
  */

#define SSP_SPO_Low                         ((uint16_t)0x0000)
#define SSP_SPO_High                        ((uint16_t)0x0040)

#define IS_SSP_SPO(LEVEL)                   (((LEVEL) == SSP_SPO_Low) || \
                                             ((LEVEL) == SSP_SPO_High))

/** @} */ /* End of group SSP_Clock_Polarity */

/** @defgroup SSP_Frame_Format SSP Frame Format
  * @{
  */

#define SSP_FRF_SPI_Motorola                ((uint16_t)0x0000)
#define SSP_FRF_SSI_TI                      ((uint16_t)0x0010)
#define SSP_FRF_Microwire                   ((uint16_t)0x0020)

#define IS_SSP_FRF(FORMAT)                  (((FORMAT) == SSP_FRF_SPI_Motorola) || \
                                             ((FORMAT) == SSP_FRF_SSI_TI)       || \
                                             ((FORMAT) == SSP_FRF_Microwire))

/** @} */ /* End of group SSP_Frame_Format */

/** @defgroup SSP_Hardware_Flow_Control SSP Hardware Flow Control
  * @{
  */
#define SSP_HardwareFlowControl_None        ((uint16_t)0x0000)
#define SSP_HardwareFlowControl_SOD         ((uint16_t)0x0008)
#define SSP_HardwareFlowControl_SSE         ((uint16_t)0x0002)
#define SSP_HardwareFlowControl_LBM         ((uint16_t)0x0001)

#define SSP_HardwareFlowControl_MASK		((uint16_t)(SSP_HardwareFlowControl_None |\
													  SSP_HardwareFlowControl_SSE |\
													  SSP_HardwareFlowControl_LBM |\
													  SSP_HardwareFlowControl_SOD))

#define IS_SSP_HARDWARE_FLOW_CONTROL(CONTROL) \
                              ((CONTROL & (~SSP_HardwareFlowControl_MASK)) == 0)
/** @} */ /* End of group SSP_Hardware_Flow_Control */

/** @defgroup SSP_Flags SSP Flags
  * @{
  */

#define SSP_FLAG_BSY                        ((uint16_t)0x0010)
#define SSP_FLAG_RFF                        ((uint16_t)0x0008)
#define SSP_FLAG_RNE                        ((uint16_t)0x0004)
#define SSP_FLAG_TNF                        ((uint16_t)0x0002)
#define SSP_FLAG_TFE                        ((uint16_t)0x0001)

#define IS_SSP_FLAG(FLAG)                   (((FLAG) == SSP_FLAG_BSY) || \
                                             ((FLAG) == SSP_FLAG_RFF) || \
                                             ((FLAG) == SSP_FLAG_RNE) || \
                                             ((FLAG) == SSP_FLAG_TNF) || \
                                             ((FLAG) == SSP_FLAG_TFE))

/** @} */ /* End of group SSP_Flags */

/** @defgroup SSP_Interrupt_definition SSP Interrupt definition
  * @{
  */

#define SSP_IT_TX                           ((uint32_t)0x00000008)
#define SSP_IT_RX                           ((uint32_t)0x00000004)
#define SSP_IT_RT                           ((uint32_t)0x00000002)
#define SSP_IT_ROR                          ((uint32_t)0x00000001)

#define SSP_IT_MASK							(SSP_IT_TX | SSP_IT_RX |\
											 SSP_IT_RT | SSP_IT_ROR)

#define IS_SSP_CONFIG_IT(IT)				(((IT) & (~SSP_IT_MASK)) == 0)

#define IS_SSP_RESET_IT(IT)                 (((IT) == SSP_IT_RT) || \
                                             ((IT) == SSP_IT_ROR))

/** @} */ /* End of group SSP_Interrupt_definition */

/** @defgroup SSP_DMA_request SSP DMA request
  * @{
  */

#define SSP_DMA_TXE                         ((uint32_t)0x00000002)
#define SSP_DMA_RXE                         ((uint32_t)0x00000001)

#define IS_SSP_DMAREQ(DMAREQ)               (((DMAREQ) == SSP_DMA_TXE) || \
                                             ((DMAREQ) == SSP_DMA_RXE))

/** @} */ /* End of group SSP_DMA_request */

/** @defgroup SSP_Clock_BRG SSP Clock BRG
  * @{
  */

#define SSP_HCLKdiv1                        ((uint32_t)0x00000000)
#define SSP_HCLKdiv2                        ((uint32_t)0x00000001)
#define SSP_HCLKdiv4                        ((uint32_t)0x00000002)
#define SSP_HCLKdiv8                        ((uint32_t)0x00000003)
#define SSP_HCLKdiv16                       ((uint32_t)0x00000004)
#define SSP_HCLKdiv32                       ((uint32_t)0x00000005)
#define SSP_HCLKdiv64                       ((uint32_t)0x00000006)
#define SSP_HCLKdiv128                      ((uint32_t)0x00000007)

#define IS_SSP_CLOCK_BRG(BRG)               ((BRG) <= 7)

/** @} */ /* End of group SSP_Clock_BRG */

/** @} */ /* End of group SSP_Exported_Constants */

/** @defgroup SSP_Exported_Macros SSP Exported Macros
  * @{
  */

/** @} */ /* End of group SSP_Exported_Macros */

/** @defgroup SSP_Exported_Functions SSP Exported Functions
  * @{
  */

void SSP_DeInit(MDR_SSP_TypeDef* SSPx);
void SSP_Init(MDR_SSP_TypeDef* SSPx, const SSP_InitTypeDef* SSP_InitStruct);
void SSP_StructInit(SSP_InitTypeDef* SSP_InitStruct);
void SSP_Cmd(MDR_SSP_TypeDef* SSPx, FunctionalState NewState);

void SSP_ITConfig(MDR_SSP_TypeDef* SSPx, uint32_t SSP_IT, FunctionalState NewState);
ITStatus SSP_GetITStatus(MDR_SSP_TypeDef* SSPx, uint32_t SSP_IT);
ITStatus SSP_GetITStatusMasked(MDR_SSP_TypeDef* SSPx, uint32_t SSP_IT);
void SSP_ClearITPendingBit(MDR_SSP_TypeDef* SSPx, uint32_t SSP_IT);

void SSP_DMACmd(MDR_SSP_TypeDef* SSPx, uint32_t SSP_DMAReq, FunctionalState NewState);

void SSP_SendData(MDR_SSP_TypeDef* SSPx, uint16_t Data);
uint16_t SSP_ReceiveData(MDR_SSP_TypeDef* SSPx);

FlagStatus SSP_GetFlagStatus(MDR_SSP_TypeDef* SSPx, uint32_t SSP_FLAG);
void SSP_BRGInit(MDR_SSP_TypeDef* SSPx, uint32_t SSP_BRG);

/** @} */ /* End of group SSP_Exported_Functions */

/** @} */ /* End of group SSP */

/** @} */ /* End of group MDR32F9Qx_StdPeriph_Driver */

#ifdef __cplusplus
} // extern "C" block end
#endif

#endif /* __MDR32F9Qx_SSP_H */

/*
*
* END OF FILE MDR32F9Qx_ssp.h */
