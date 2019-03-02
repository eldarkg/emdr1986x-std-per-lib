/**
  ******************************************************************************
  * @file	 MDR32F9Qx_arinc429t.h
  * @author	 sidorov.a
  * @version V1.4.0
  * @date    15.04.2013
  * @brief    This file contains all the functions prototypes for the ARINC429T
  *          firmware library.
  ******************************************************************************
  ******************************************************************************
  * <br><br>
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, MILANDR SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT
  * OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2013 Milandr </center></h2>
  ******************************************************************************
  * FILE MDR32F9Qx_arinc429t.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef MDR32F9QX_ARINC429T_H_
#define MDR32F9QX_ARINC429T_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"
#include "MDR1986VE8T.h"
#include "mdr32f8_config.h"

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @addtogroup ARINC429T ARINC429T
  * @{
  */

/** @defgroup ARINC429T_Exported_Types ARINC429T Exported Types
  * @{
  */

/**
  * @brief	ARINC429T Init Channel Structure definition
  */

typedef struct {
	uint32_t 		ARINC429T_ODD;			/*!< This member specifies bits even or odd parity for the channel.
												 This parameter is one of @ref ARINC429T_ODD values. */
	FunctionalState ARINC429T_EN_PAR;		/*!< This member enables or disables the 32-bit parity for a given channel.
												 This parameter can be: ENABLE or DISABLE. */
	uint32_t 		ARINC429T_CLK;			/*!< This member specifies the data sending speed.
	 	 	 	 	 	 	 	 	 	 	 	 This parameter is one of @ref ARINC429T_CLK values. */
	uint32_t 		ARINC429T_DIV;			/*!< This member specifies the individual core
											 	 frequency divider for channel reference frequency.
											 	 This parameter is number from 0 to 0xFF. */
    FunctionalState ARINC429T_ENSYNC;      /*!< This member enables or disables the ENSYNC  interface mode for a given channel.
												 This parameter can be: ENABLE or DISABLE. */

} ARINC429T_InitChannelTypeDef;

/** @} */ /* End of group ARINC429T_Exported_Types */

/** @defgroup ARINC429T_CLK ARINC429T CLK
  * @{
  */

#define ARINC429T_CLK_12_5_KHz		((uint32_t)0x00000001)
#define ARINC429T_CLK_100_KHz		((uint32_t)0x00000000)

#define IS_ARINC429T_CLK(CLK)		(((CLK) == ARINC429T_CLK_12_5_KHz) ||\
								     ((CLK) == ARINC429T_CLK_100_KHz))

/** @} */ /* End of group ARINC429T_CLK */

/** @defgroup ARINC429T_ODD ARINC429T ODD
  * @{
  */

#define ARINC429T_ODD_ADD_TO_ODD			((uint32_t)0x00000001)
#define ARINC429T_ODD_ADD_TO_PARITY			((uint32_t)0x00000000)

#define IS_ARINC429T_ODD(ODD)				(((ODD) == ARINC429T_ODD_ADD_TO_ODD) || \
											 ((ODD) == ARINC429T_ODD_ADD_TO_PARITY))
/** @} */ /* End of group ARINC429T_ODD */

/** @defgroup ARINC429T_Channel ARINC429T Channel
  * @{
  */
#define ARINC429T_CHANNEL1			((uint32_t)0x00000000)
#define ARINC429T_CHANNEL2			((uint32_t)0x00000001)
#define ARINC429T_CHANNEL3			((uint32_t)0x00000002)
#define ARINC429T_CHANNEL4			((uint32_t)0x00000003)

#define IS_ARINC429T_CHANNEL(CHANNELx)		(((CHANNELx) >= ARINC429T_CHANNEL1 ) &&\
									         ((CHANNELx) <= ARINC429T_CHANNEL4 ))

/** @} */ /* End of group ARINC429T_Channel */

/** @defgroup ARINC429T_Interrupt_Defintion ARINC429T Interrupt Defintion
  * @{
  */

#define ARINC429T_IT_INTE_HTF		((uint32_t)0x00000004)
#define ARINC429T_IT_INTE_TXR		((uint32_t)0x00000002)
#define ARINC429T_IT_INTE_FFT		((uint32_t)0x00000001)

#define IS_ARINC429T_IT(IT)			(((IT) == ARINC429T_IT_INTE_HTF) ||\
									 ((IT) == ARINC429T_IT_INTE_TXR) ||\
									 ((IT) == ARINC429T_IT_INTE_FFT))

/** @} */ /* End of group ARINC429T_Interrupt_Defintion */

/** @defgroup ARINC429T_Flags ARINC429T Flags
  * @{
  */

#define ARINC429T_FLAG_TX_R				((uint32_t)0x00000001)
#define ARINC429T_FLAG_FFT				((uint32_t)0x00000002)
#define ARINC429T_FLAG_HFT				((uint32_t)0x00000004)

#define IS_ARINC429T_FLAG(FLAG)			( ((FLAG) == ARINC429T_FLAG_TX_R) ||\
										  ((FLAG) == ARINC429T_FLAG_FFT)  ||\
										  ((FLAG) == ARINC429T_FLAG_HFT))

/** @} */ /* End of group ARINC429T_Flags */

/** @defgroup ARINC429T_Clock_BRG ARINC429T Clock BRG
  * @{
  */

#define ARINC429T_HCLKdiv_MASK			((uint32_t)0x00007F00)
#define IS_ARINC429T_HCLKdiv(HCLKdiv)	(((HCLKdiv) & ~(ARINC429T_HCLKdiv_MASK)) == 0)

/** @} */ /* End of group ARINC429T_Clock_BRG */

/** @defgroup ARINC429T_Exported_Funstions ARINC429T Exported Funstions
  * @{
  */

void ARINC429T_BRG_Init(uint32_t ARINC429T_BRG);
void ARINC429T_DeInit(void);
void ARINC429T_ChannelInit(uint32_t ARINC429T_CHANNELx, ARINC429T_InitChannelTypeDef * ARINC429T_InitChanelStruct);
void ARINC429T_ChannelCmd(uint32_t ARINC429T_CHANNELx, FunctionalState NewState);
void ARINC429T_ITConfig(uint32_t ARINC429T_CHANNELx, uint32_t ARINC429T_IT, FunctionalState NewState);
FlagStatus ARINC429T_GetFlagStatus(uint32_t ARINC429T_CHANNELx, uint32_t ARINC429T_FLAG);
void ARINC429T_SendData(uint32_t ARINC429T_CHANNELx, uint32_t Data );

/** @} */ /* End of group ARINC429T_Exported_Funstions */

/** @} */ /* End of group ARINC429T */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

#ifdef __cplusplus
} // extern "C" block end
#endif

#endif /* MDR32F9QX_ARINC429T_H_ */

/******************* (C) COPYRIGHT 2013 Milandr ********************************
*
* END OF FILE MDR32F9Qx_arinc429t.h */
