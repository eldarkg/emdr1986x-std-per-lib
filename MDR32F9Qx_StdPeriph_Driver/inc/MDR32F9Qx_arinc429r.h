/**
  * FILE MDR32F9Qx_arinc429r.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef MDR32F9QX_ARINC429R_H_
#define MDR32F9QX_ARINC429R_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_config.h"
#include "MDR32F9Qx_lib.h"

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @addtogroup ARINC429R ARINC429R
  * @{
  */

/** @defgroup ARINC429R_Exported_Types ARINC429R Exported Types
  * @{
  */

/**
  * @brief	ARINC429 Init Channel Structure definition
  */

typedef struct {
	uint32_t 		ARINC429R_CLK;		/*!< This member specifies the data reception speed.
	 	 	 	 	 	 	 	 	 	 	 This parameter is one of @ref ARINC429R_CLK values.*/
	FunctionalState ARINC429R_SD;		/*!< This member allows decoding 9 and 10 data bits.
	 	 	 	 	 	 	 	 	 	 	 This parameter can be: ENABLE or DISABLE. */
	FunctionalState ARINC429R_LB;		/*!< This member allows tag detection.
	 	 	 	 	 	 	 	 	 	 	 This parameter can be: ENABLE or DISABLE. */
	BitStatus 		ARINC429R_SDI1;		/*!< This member specifies the bit comparison SDI1.
	 	 	 	 	 	 	 	 	 	 	 This parameter can be: SET or RESET. */
	BitStatus 		ARINC429R_SDI2;		/*!< This member specifies the bit comparison SDI2.
	 	 	 	 	 	 	 	 	 	     This parameter can be: SET or RESET. */
	uint32_t 		ARINC429R_DIV;		/*!< This member specifies the individual core
											 frequency divider for channel reference frequency.
											 This parameter is number from 0 to 0xFF. */
} ARINC429R_InitChannelTypeDef;

/** @} */ /* End of group ARINC429R_Exported_Types */

/** @defgroup ARINC429R_CLK ARINC429R CLK
  * @{
  */

#define ARINC429R_CLK_12_5_KHz		((uint32_t)0x00000001)
#define ARINC429R_CLK_100_KHz		((uint32_t)0x00000000)

#define IS_ARINC429R_CLK(CLK)		(((CLK) == ARINC429R_CLK_12_5_KHz) ||\
								     ((CLK) == ARINC429R_CLK_100_KHz))

/** @} */ /* End of group ARINC429R_CLK */

/** @defgroup ARINC429R_Channel ARINC429R Channel
  * @{
  */
#define ARINC429R_CHANNEL1		((uint32_t)0x00000000)
#define ARINC429R_CHANNEL2		((uint32_t)0x00000001)
#define ARINC429R_CHANNEL3		((uint32_t)0x00000002)
#define ARINC429R_CHANNEL4		((uint32_t)0x00000003)
#define ARINC429R_CHANNEL5		((uint32_t)0x00000004)
#define ARINC429R_CHANNEL6		((uint32_t)0x00000005)
#define ARINC429R_CHANNEL7		((uint32_t)0x00000006)
#define ARINC429R_CHANNEL8		((uint32_t)0x00000007)
#if defined (USE_MDR1986VE3)
#define ARINC429R_CHANNEL9		((uint32_t)0x00000008)
#define ARINC429R_CHANNEL10		((uint32_t)0x00000009)
#define ARINC429R_CHANNEL11		((uint32_t)0x0000000A)
#define ARINC429R_CHANNEL12		((uint32_t)0x0000000B)
#define ARINC429R_CHANNEL13		((uint32_t)0x0000000C)
#define ARINC429R_CHANNEL14		((uint32_t)0x0000000D)

#define IS_ARINC429R_CHANNEL(CHANNEL)		((CHANNEL) <= ARINC429R_CHANNEL14)
#endif

#if defined (USE_MDR1986VE1T)
#define IS_ARINC429R_CHANNEL(CHANNEL)		((CHANNEL) <= ARINC429R_CHANNEL8)
#endif


/** @} */ /* End of group ARINC429R_Channel */

/** @defgroup ARINC429R_Interrupt_Defintion ARINC429R Interrupt Defintion
  * @{
  */

#define ARINC429R_IT_INT_HF		((uint32_t)0x80000000)
#define ARINC429R_IT_INT_FF		((uint32_t)0x40000000)
#define ARINC429R_IT_INT_ER		((uint32_t)0x20000000)
#define ARINC429R_IT_INT_DR		((uint32_t)0x10000000)

#define ARINC429R_IT_MASK		(ARINC429R_IT_INT_HF |\
								 ARINC429R_IT_INT_FF |\
								 ARINC429R_IT_INT_ER |\
								 ARINC429R_IT_INT_DR)

#define IS_ARINC429R_IT(IT)		(((IT) & (~ARINC429R_IT_MASK)) == 0)

/** @} */ /* End of group ARINC429R_Interrupt_Defintion */

/** @defgroup ARINC429R_Flags ARINC429R Flags
  * @{
  */

#define ARINC429R_FLAG_ERR			((uint32_t)0x0000000)
#define ARINC429R_FLAG_DR			((uint32_t)0x0000001)
#define ARINC429R_FLAG_HF			((uint32_t)0x0000002)
#define ARINC429R_FLAG_FF			((uint32_t)0x0000003)

#define IS_ARINC429R_FLAG(FLAG)		(((FLAG) == ARINC429R_FLAG_ERR) ||\
									 ((FLAG) == ARINC429R_FLAG_DR)  ||\
									 ((FLAG) == ARINC429R_FLAG_HF)  ||\
									 ((FLAG) == ARINC429R_FLAG_FF))

/** @} */ /* End of group ARINC429R_Flags */

#if defined (USE_MDR1986VE1T)

/**
 * @note This defines uses only for MC MDR1986VE1T at revision 3.
 */

/** @defgroup ARINC429R_ITMask ARINC429R ITMask
  * @{
  */

#define ARINC429R_ITMask_DR				((uint32_t)0x00000001)
#define ARINC429R_ITMask_ER				((uint32_t)0x00000002)
#define ARINC429R_ITMask_FF				((uint32_t)0x00000004)
#define ARINC429R_ITMask_HF				((uint32_t)0x00000008)

#define IS_ARINC429R_ITMask(ITMask)		((ITMask == ARINC429R_ITMask_HF) ||\
										 (ITMask == ARINC429R_ITMask_FF) ||\
										 (ITMask == ARINC429R_ITMask_ER) ||\
										 (ITMask == ARINC429R_ITMask_DR))

/** @} */ /* End of group ARINC429R_ITMask */

#endif


/** @defgroup ARINC429R_Exported_Constants ARINC429R Exported Constants
  * @{
  */

/** @} */ /* End of group ARINC429R_Exported_Constants */

/** @defgroup ARINC429R_Exported_Functions ARINC429R Exported Functions
  * @{
  */
void ARINC429R_BRG_Init(uint32_t ARINC429R_BRG);
void ARINC429R_DeInit(void);
void ARINC429R_ChannelInit(uint32_t ARINC429R_CHANNELx, ARINC429R_InitChannelTypeDef * ARINC429R_InitChannelStruct);
void ARINC429R_ChannelCmd(uint32_t ARINC429R_CHANNELx, FunctionalState NewState);
void ARINC429R_ITConfig(uint32_t ARINC429R_IT, FunctionalState NewState);
#if defined (USE_MDR1986VE1T)
	void ARINC429R_ITMaskConfig(uint32_t ARINC429R_CHANNELx, uint32_t ARINC429R_ITMask, FunctionalState NewState);
	uint32_t ARINC429R_ReceiveDataDirect(uint32_t ARINC429R_CHANNELx);
#endif
FlagStatus ARINC429R_GetFlagStatus(uint32_t ARINC429R_CHANNELx, uint32_t ARINC429R_FLAG);
void ARINC429R_SetChannel(uint32_t ARINC429R_CHANNELx);
uint32_t ARINC429R_GetLabel(void);
void ARINC429R_SetLabel(uint8_t label);
uint32_t ARINC429R_ReceiveData(void);

/** @} */ /* End of group ARINC429R_Exported_Functions */

/** @} */ /* End of group ARINC429R */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

#ifdef __cplusplus
} // extern "C" block end
#endif

#endif /* MDR32F9QX_ARINC429R_H_ */

/*
*
* END OF FILE MDR32F9Qx_arinc429r.h */
