/**
  * FILE MDR32F9Qx_adciu.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef MDR32F9QX_ADCIU_H_
#define MDR32F9QX_ADCIU_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_config.h"

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @addtogroup ADCIU ADCIU
  * @{
  */

/** @defgroup ADCIU_Exported_Types ADCIU Exported Types
  * @{
  */

/**
 * @brief ADCIU Init structure defintion
 */
typedef struct {

	uint32_t ADCIU_VoltageReference;		/*!< Select the reference voltage source.
	 	 	 	 	 	 	 	 	 	 	 	 This parameter can be a value of @ref ADCIU_Reference_Voltage_Configuration. */

	uint32_t ADCIU_ChopperFrequencyDivider;	/*!< Choosing scaler mode eliminate the constant component.
	 	 	 	 	 	 	 	 	 	 	 	 This parameter can be a value of @ref ADCIU_Chopper_Frequency_Divider. */

	uint32_t ADCIU_BypassBufferReference;	/*!< Enable or disable bypass buffers reference.
	 	 	 	 	 	 	 	 	 	 	 	 This parameter can be a value of  @ref ADCIU_Bypass_buffer_reference_configuration*/

	uint32_t ADCIU_DigitalGain;				/*!< Determines the level of digital amplification.
												 This parameter can be a number between 0x0000 and 0x3F. */

	uint32_t ADCIU_SFCDivider;				/*!< Set the SFC divider.
												 This parameter can be a value of @ref ADCIU_SFC_divider. */

	uint32_t ADCIU_SFFDivider;				/*!< Set the SFF divider.
											   	 This parameter can be a number between 0x0000 and 0x7F. */

} ADCIU_InitTypeDef;

/**
 * @brief ADCIU Channel init structure
 */
typedef struct {

	FunctionalState ADCIU_ChopperState;				/*!< Enable or disable mode eliminate of the constant component.
														 This parameter can be a value of FunctionalState */

	uint32_t	 	ADCIU_AnalogGain;				/*!< Specifies the level of analog gain.
														 This parameter can be a value of @ref ADCIU_AGAIN */

	FunctionalState ADCIU_DMARequest;				/*!< Enable or disable dma request when there is data in the FIFO.
														 This parameter can be a value of FunctionalState */

	FunctionalState ADCIU_IT_FIFO_OverflowState;	/*!< Enable or disable FIFO overflow interrupt.
														 This parameter can be a value of FunctionalState */

	FunctionalState ADCIU_IT_FIFO_NotEmptyState;	/*!< Enable or disable FIFO data present interrupt.
														 This parameter can be a value of FunctionalState */

}ADCIU_ChannelInitTypeDef;

/** @} */ /* End of group ADCIU_Exported_Types */

/** @defgroup ADCIU_Exported_Macros ADCIU Exported Macros
  * @{
  */

/** @} */ /* End of group ADCIU_Exported_Macros */

/** @defgroup ADCIU_Exported_Constants ADCIU Exported Constants
  * @{
  */

/** @defgroup ADCIU_Reference_Voltage_Configuration ADCIU Reference Voltage Configuration
  * @{
  */

#define ADCIU_REFEREVCE_VOLTAGE_INTERNAL			(uint32_t)(0 << ADCIU_CTRL1_REF_EX_Pos)
#define ADCIU_REFEREVCE_VOLTAGE_EXTERNAL			(uint32_t)(1 << ADCIU_CTRL1_REF_EX_Pos)

#define IS_ADCIU_REFEREVCE_VOLTAGE(RV)				((RV == ADCIU_REFEREVCE_VOLTAGE_INTERNAL) ||\
													 (RV == ADCIU_REFEREVCE_VOLTAGE_EXTERNAL))

/** @} */ /* End of group ADCIU_Reference_Voltage_Configuration */

/** @defgroup ADCIU_Chopper_Frequency_Divider ADCIU Chopper Frequency Divider
  * @{
  */

#define ADCIU_CHOPPER_FREQUENCY_DIVIDER4			(0 << ADCIU_CTRL2_CHOP_FREQ_Pos)
#define ADCIU_CHOPPER_FREQUENCY_DIVIDER8			(1 << ADCIU_CTRL2_CHOP_FREQ_Pos)
#define ADCIU_CHOPPER_FREQUENCY_DIVIDER16			(2 << ADCIU_CTRL2_CHOP_FREQ_Pos)
#define ADCIU_CHOPPER_FREQUENCY_DIVIDER32			(3 << ADCIU_CTRL2_CHOP_FREQ_Pos)

#define IS_ADCIU_CHOPPER_FREQUENCY_DIVIDER(FD)		((FD & (~ADCIU_CTRL2_CHOP_FREQ_Msk)) == 0)

/** @} */ /* End of group ADCIU_Chopper_Frequency_Divider */

/** @defgroup ADCIU_Bypass_buffer_reference_configuration ADCIU Bypass buffer reference configuration
  * @{
  */

#define ADCIU_BYPASS_BUFFER_REFERNCE_ENABLE			(1 << ADCIU_CTRL2_BF_BP_Pos)
#define ADCIU_BYPASS_BUFFER_REFERNCE_DISABLE		(0 << ADCIU_CTRL2_BF_BP_Pos)

#define IS_ADCIU_BYPASS_BUFFER_REFERNCE_CONF(BBRF)	((BBRF == ADCIU_BYPASS_BUFFER_REFERNCE_ENABLE) ||\
													 (BBRF == ADCIU_BYPASS_BUFFER_REFERNCE_DISABLE))

/** @} */ /* End of group ADCIU_Bypass_buffer_support_configuration */

/** @defgroup ADCIU_DGAIN_ ADCIU DGAIN
  * @{
  */

#define IS_ADCIU_DGAIN(DGAIN)						((DGAIN & (~ADCIU_DIGGAN_ADCPGA_Msk)) == 0)

/** @} */ /* End of group ADCIU_DGAIN */

/** @defgroup ADCIU_SFC_divider ADCIU SFC divider
  * @{
  */

#define ADCIU_SFC0									(0 << ADCIU_CTRL2_SFC_Pos)
#define ADCIU_SFC1									(1 << ADCIU_CTRL2_SFC_Pos)
#define ADCIU_SFC2									(2 << ADCIU_CTRL2_SFC_Pos)
#define ADCIU_SFC3									(3 << ADCIU_CTRL2_SFC_Pos)
#define ADCIU_SFC4									(4 << ADCIU_CTRL2_SFC_Pos)

#define IS_ADCIU_SFC(SFC)							((SFC == ADCIU_SFC0) ||\
													 (SFC == ADCIU_SFC1) ||\
													 (SFC == ADCIU_SFC2) ||\
													 (SFC == ADCIU_SFC3) ||\
													 (SFC == ADCIU_SFC4))

/** @} */ /* End of group ADCIU_SFC_divider */

/** @defgroup ADCIU_SFF_divider ADCIU SFF divider
  * @{
  */

#define IS_ADCIU_SFF(SFF)							((SFF & (~ADCIU_CTRL2_SFF_Msk)) == 0)

/** @} */ /* End of group ADCIU_SFF_divider */

/** @defgroup ADCIU_CHANNEL_NUMBER ADCIU CHANNEL NUMBER
  * @{
  */

#define ADCIU_CHANNEL_NUMBER1						(uint32_t)(0x000000000)
#define ADCIU_CHANNEL_NUMBER2						(uint32_t)(0x000000001)
#define ADCIU_CHANNEL_NUMBER3						(uint32_t)(0x000000002)
#define ADCIU_CHANNEL_NUMBER4						(uint32_t)(0x000000003)
#define ADCIU_CHANNEL_NUMBER5						(uint32_t)(0x000000004)
#define ADCIU_CHANNEL_NUMBER6						(uint32_t)(0x000000005)
#define ADCIU_CHANNEL_NUMBER7						(uint32_t)(0x000000006)
#define ADCIU_CHANNEL_NUMBER8						(uint32_t)(0x000000007)

#define IS_ADCIU_CHANNEL_NUMBER(CHN)				(CHN <= ADCIU_CHANNEL_NUMBER8)

/** @} */ /* End of group ADCIU_CHANNEL_NUMBER */

/** @defgroup ADCIU_FLAG_STATUS ADCIU FLAG STATUS
  * @{
  */

#define ADCIU_FLAG_FIFO_OVERFLOW					(uint32_t)(1 << 8)
#define ADCIU_FLAG_FITO_NOT_EMPTY					(uint32_t)(1 << 0)

#define IS_ADCIU_FLAG(F)							((F == ADCIU_FLAG_FIFO_OVERFLOW) ||\
													 (F == ADCIU_FLAG_FITO_NOT_EMPTY))

/** @} */ /* End of group ADCIU_FLAG_STATUS */

/** @defgroup ADCIU_IT ADCIU IT
  * @{
  */

#define ADCIU_IT_FIFO_OVERFLOW						(uint32_t)(1 << 8)
#define ADCIU_IT_FITO_NOT_EMPTY						(uint32_t)(1 << 0)

#define IS_ADCIU_IT(IT)								((IT == ADCIU_IT_FIFO_OVERFLOW) ||\
													 (IT == ADCIU_IT_FITO_NOT_EMPTY))

/** @} */ /* End of group ADCIU_IT */

/** @defgroup ADCIU_AGAIN ADCIU AGAIN
  * @{
  */

#define ADCIU_AGAIN0dB								(uint32_t)(0x00000000)
#define ADCIU_AGAIN6dB								(uint32_t)(0x00000002)
#define ADCIU_AGAIN12dB								(uint32_t)(0x00000001)
#define ADCIU_AGAIN24dB								(uint32_t)(0x00000003)

#define IS_ADCIU_AGAIN(AGAIN)						((AGAIN == ADCIU_AGAIN0dB) ||\
													 (AGAIN == ADCIU_AGAIN6dB) ||\
													 (AGAIN == ADCIU_AGAIN12dB) ||\
													 (AGAIN == ADCIU_AGAIN24dB))

/** @} */ /* End of group ADCIU_AGAIN */

/** @} */ /* End of group ADCIU_Exported_Constants */

/** @defgroup ADCIU_Exported_Functions ADCIU Exported Functions
  * @{
  */

void ADCIU_DeInit(void);
void ADCIU_Init(ADCIU_InitTypeDef * ADCIU_InitStruct);
void ADCIU_InitChannel(uint32_t ChannelNumber, ADCIU_ChannelInitTypeDef * ADCIU_ChannelInitStruct);
void ADCIU_StructInit(ADCIU_InitTypeDef * ADCIU_InitStruct);
void ADCIU_ChannelStructInit(ADCIU_ChannelInitTypeDef * ADCIU_ChannelInitStruct);
void ADCIU_ChannelCmd(uint32_t ChannelNumber, FunctionalState NewState);
void ADCIU_ChopperCmd(uint32_t ChannelNumber, FunctionalState NewState);
void ADCIU_AGain(uint32_t ChannelNumber, uint32_t gain);
void ADCIU_ITConfig(uint32_t ChannelNumber, uint32_t ADCIU_IT, FunctionalState NewState);
void ADCIU_ClearIT_OVERFLOW(uint32_t ChannelNumber);
void ADCIU_DMARequestCmd(uint32_t ChannelNumber, FunctionalState NewState);
FlagStatus ADCIU_GetStatusFlag(uint32_t ChannelNumber, uint32_t ADCIU_STATUS_FLAG);
uint32_t ADCIU_GetResult(uint32_t ChannelNumber);

/** @} */ /* End of group ADCIU_Exported_Functions */

/** @} */ /* End of group ADCIU */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

#ifdef __cplusplus
} // extern "C" block end
#endif

#endif /* MDR32F9QX_ADCIU_H_ */

/*
*
* END OF FILE MDR32F9Qx_adciu.h */
