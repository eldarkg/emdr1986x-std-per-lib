/**
  ******************************************************************************
  * @file	 MDR32F9Qx_audio.h
  * @author	 sidorov.a
  * @version V1.4.0
  * @date    11.10.2013
  * @brief   This file contains all the functions prototypes for the AUDIO_IP
  * 		 firmware library.
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
  * FILE MDR32F9Qx_audio.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef MDR32F9QX_AUDIO_H_
#define MDR32F9QX_AUDIO_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @addtogroup AUDIO_IP
  * @{
  */

/** @defgroup AUDIO_IP_Exported_Types AUDIO_IP Exported Types
  * @{
  */

/**
 * @brief	AUDIO IP Structure defintion
 * @note	The user should not configure all the AUDIO_IP_InitTypeDef structure's fields.
 *   		By calling the AUDIO_IP_StructInit function the structure’s fields are set to their default values.
 *   		Only the parameters that will be set to a non-default value should be configured.
 */

typedef struct {
	/**
	 * @brief POWCTL 	The general codec control.
	 */
	uint32_t			FilterMode;					/*!< Defines the used filter for inderpolation/decimation.
														 This parameter can be a value of@ref AUDIO_IP_FILTER_MODE. */
	FunctionalState		AnalogLoopBackMode;			/*!< Enable or disable addition the analog loop back.
														 This parameter can be: ENABLE or DISABLE. */
	FunctionalState		DigitalLoopBackMode;		/*!< Enable or disable addition the digital loop back.
														 This parameter can be: ENABLE or DISABLE. */
	/**
	 * @brief ADCCTL	The ADC control.
	 */

	uint32_t			ADGain;						/*!< Defines recording level of the input signal.
														 This parameter can be of a value from 0 to 0x3F. */
	uint32_t 			ADCInputAmplifier;			/*!< Defines the level of input preamplifier.
														 This parameter can be value of the@ref AUDIO_IP_ADC_INPUT_APLIFIER_LEVEL. */
	uint32_t			ADCAnalogInput;				/*!< Select the ADC source of the input signal.
	  	  	  	  	  	  	  	  	  	  	  	  	  	 This parameter can be a value of the@ref AUDIO_IP_ANALOG_INPUT_SOURCE. */
	FunctionalState		ADCInputControl;			/*!< Control of analog filter and ADC.
														 This parameter can be: ENABLE or DISABLE. */
	/**
	 * @brief DACCTL	The DAC control.
	 */

	uint32_t			DAGain;						/*!< Defines the level of playback output signal.
	 	 	 	 	 	 	 	 	 	 	 	 	 	 This parameter can be of a value from 0 to 0x3F. */
	FunctionalState		DACMute;					/*!< Enable or disable the DAC output mute.
	 	 	 	 	 	 	 	 	 	 	 	 	 	 This parameter can be: ENABLE or DISABLE. */
	FunctionalState		DACOutputAmplifier;			/*!< Enable or disable DAC analog output amplifier.
														 This parameter can be: ENABLE or DISABLE. */
	FunctionalState		DACBIASOffsetSchemeState;	/*!< Enable or disable offset scheme BIAS.
	 	 	 	 	 	 	 	 	 	 	 	 	 	 This parameter can be ENABLE or DISABLE. */
	FunctionalState		DACAnalogState;				/*!< Enable or disable analogue DAC and filters.
														 This parameter can be ENABLE or DISABLE. */
	FunctionalState		DACOverCurrentBufferDet;	/*!< Determines the resolution of a short-circuit detection circuit output buffer.
														 This parameter can be: ENABLE or DISABLE. */
	FunctionalState		DACOverCurrentNetOffsetDet; /*!< Determines the resolution of a short-circuit detection circuit bias circuitry.
														 This parameter can be: ENABLE or DISABLE. */
	uint32_t 			DACSideToneLoopBack;		/*!< Set the value of the side tone loob back.
														 This parameter can be a value if the@ref AUDIO_IP_DAC_SIDE_TONE_LOOP_BACK. */
	FunctionalState		DACState;					/*!< Determines the work mode of the AUDIO DAC.
														 This parameter can be: ENABLE or DISABLE. */
}AUDIO_IP_InitTypeDef;

/** @} */ /* End of group AUDIO_IP_Exported_Types */

/** @defgroup AUDIO_IP_Exported_Macros AUDIO_IP Exported Macros
  * @{
  */

/** @defgroup AUDIO_IP_AUC_C1 AUDIO_IP AUC_C1
  * @{
  */

#define AUDIO_IP_AUC_C1_HSI					0x00
#define AUDIO_IP_AUC_C1_HSI_2				0x01
#define AUDIO_IP_AUC_C1_HSE					0x02
#define AUDIO_IP_AUC_C1_HSE_2				0x03

#define IS_AUDIO_IP_AUC_C1(AUC_C1)			((AUC_C1 == AUDIO_IP_AUC_C1_HSI)   ||\
											 (AUC_C1 == AUDIO_IP_AUC_C1_HSI_2) ||\
											 (AUC_C1 == AUDIO_IP_AUC_C1_HSE)   ||\
											 (AUC_C1 == AUDIO_IP_AUC_C1_HSE_2))

/** @} */ /* End of group AUDIO_IP_AUC_C1 */

/** @defgroup AUDIO_IP_AUC_C2 AUDIO_IP AUC_C2
  * @{
  */

#define AUDIO_IP_AUC_C2_AUC_C1				0x00
#define AUDIO_IP_AUC_C2_AUC_PLLCPU0			0x01
#define AUDIO_IP_AUC_C2_AUC_PLLUSB0			0x02

#define IS_AUDIO_IP_AUC_C2(AUC_C2)			((AUC_C2 == AUDIO_IP_C2_AUC_C1)      ||\
											 (AUC_C2 == AUDIO_IP_C2_AUC_PLLCPU0) ||\
											 (AUC_C2 == AUDIO_IP_C2_AUC_PLLUSB0))

/** @} */ /* End of group AUDIO_IP_AUC_C2 */

/** @defgroup AUDIO_IP_AUDIO_C3 AUDIO_IP AUDIO_C3
  * @{
  */

#define AUDIO_IP_AUDIO_CLK_DIV1				((uint32_t)0x00000000)
#define AUDIO_IP_AUDIO_CLK_DIV2				((uint32_t)0x00000008)
#define AUDIO_IP_AUDIO_CLK_DIV4				((uint32_t)0x00000009)
#define AUDIO_IP_AUDIO_CLK_DIV8				((uint32_t)0x0000000A)
#define AUDIO_IP_AUDIO_CLK_DIV16			((uint32_t)0x0000000B)
#define AUDIO_IP_AUDIO_CLK_DIV32			((uint32_t)0x0000000V)
#define AUDIO_IP_AUDIO_CLK_DIV64			((uint32_t)0x0000000D)
#define AUDIO_IP_AUDIO_CLK_DIV128			((uint32_t)0x0000000E)
#define AUDIO_IP_AUDIO_CLK_DIV256			((uint32_t)0x0000000F)

#define IS_AUDIO_IP_AUDIO_CLK_DIV(CLK_DIV)	((CLK_DIV >= AUDIO_IP_AUDIO_CLK_DIV1) &&\
										     (CLK_DIV <= AUDIO_IP_AUDIO_CLK_DIV256)

/** @} */ /* End of group AUDIO_IP_AUDIO_C3 */

/** @defgroup AUDIO_IP_FILTER_MODE AUDIO_IP FILTER_MODE
  * @{
  */

#define AUDIO_IP_FILTER_MODE_FIR_FILTER		((uint32_t)0x00000000)
#define AUDIO_IP_FILTER_MODE_IIR_FILTER		((uint32_t)0x00000004)

#define IS_AUDIO_IP_FILTER_MODE(FILTER_MODE)				((FILTER_MODE == AUDIO_IP_FILTER_MODE_FIR_FILTER) ||\
															 (FILTER_MODE == AUDIO_IP_FILTER_MODE_IIR_FILTER))

/** @} */ /* End of group AUDIO_IP_FILTER_MODE */

/** @defgroup AUDIO_IP_ADC_INPUT_ADMPLIFIER_LEVEL AUDIO_IP ADC_INPUT_ADMPLIFIER_LEVEL
  * @{
  */

#define AUDIO_IP_ADC_INPUT_AMPLIFIER_LEVEL_0_DB				((uint32_t)0x00000000)
#define AUDIO_IP_ADC_INPUT_AMPLIFIER_LEVEL_6_DB				((uint32_t)0x00000001)
#define AUDIO_IP_ADC_INPUT_AMPLIFIER_LEVEL_12_DB			((uint32_t)0x00000002)
#define AUDIO_IP_ADC_INPUT_AMPLIFIER_LEVEL_24_DB			((uint32_t)0x00000003)

#define IS_AUDIO_IP_INPUT_AMPLIFIER_LEVEL(AMPLIFIER_LEVEL)	((AMPLIFIER_LEVEL == AUDIO_IP_ADC_INPUT_AMPLIFIER_LEVEL_0_DB)  ||\
															 (AMPLIFIER_LEVEL == AUDIO_IP_ADC_INPUT_AMPLIFIER_LEVEL_6_DB)  ||\
															 (AMPLIFIER_LEVEL == AUDIO_IP_ADC_INPUT_AMPLIFIER_LEVEL_12_DB) ||\
															 (AMPLIFIER_LEVEL == AUDIO_IP_ADC_INPUT_AMPLIFIER_LEVEL_24_DB))

/** @} */ /* End of group AUDIO_IP_ADC_INPUT_ADMPLIFIER_LEVEL */

/** @defgroup AUDIO_IP_ANALOG_INPUT_SOURCE AUDIO_IP ANALOG_INPUT_SOURCE
  * @{
  */

#define AUDIO_IP_ANALOG_INPUT_SOURCE_INP1					((uint32_t)0x00000000)
#define AUDIO_IP_ANALOG_INPUT_SOURCE_MICIN_INT				((uint32_t)0x00000001)
#define AUDIO_IP_ANALOG_INPUT_SOURCE_MICIN_EXT				((uint32_t)0x00000002)
#define AUDIO_IP_ANALOG_INPUT_SOURCE_INP2					((uint32_t)0x00000003)

#define IS_AUDIO_IP_ANALOG_INPUT_SOURCE(INPUT_SOURCE)		((INPUT_SOURCE == AUDIO_IP_ANALOG_INPUT_SOURCE_INP1)      ||\
															 (INPUT_SOURCE == AUDIO_IP_ANALOG_INPUT_SOURCE_MICIN_INT) ||\
															 (INPUT_SOURCE == AUDIO_IP_ANALOG_INPUT_SOURCE_MICIN_EXT) ||\
															 (INPUT_SOURCE == AUDIO_IP_ANALOG_INPUT_SOURCE_INP2))

/** @} */ /* End of group AUDIO_IP_ANALOG_INPUT_SOURCE */

/** @defgroup AUDIO_IP_DAC_SIDE_TONE_LOOP_BACK AUDIO_IP DAC_SIDE_TONE_LOOP_BACK
  * @{
  */

#define AUDIO_IP_DAC_SIDE_TONE_LOOP_BACK_MUTE						((uint32_t)0x00000007)
#define AUDIO_IP_DAC_SIDE_TONE_LOOP_BACK_21dB						((uint32_t)0x00000006)
#define AUDIO_IP_DAC_SIDE_TONE_LOOP_BACK_18dB						((uint32_t)0x00000005)
#define AUDIO_IP_DAC_SIDE_TONE_LOOP_BACK_15dB						((uint32_t)0x00000004)
#define AUDIO_IP_DAC_SIDE_TONE_LOOP_BACK_12dB						((uint32_t)0x00000003)
#define AUDIO_IP_DAC_SIDE_TONE_LOOP_BACK_9dB						((uint32_t)0x00000002)
#define AUDIO_IP_DAC_SIDE_TONE_LOOP_BACK_6dB						((uint32_t)0x00000001)
#define AUDIO_IP_DAC_SIDE_TONE_LOOP_BACK_3dB						((uint32_t)0x00000000)

#define IS_AUDIO_IP_DAC_SIDE_TONE_LOOP_BACK(SIDE_TONE_LOOP_BACK)	(SIDE_TONE_LOOP_BACK <= AUDIO_IP_DAC_SIDE_TONE_LOOP_BACK_MUTE)

/** @} */ /* End of group AUDIO_IP_SIDE_TONE_LOOP_BACK */

/** @defgroup AUDIO_IP_IT AUDIO_IP IT
  * @{
  */

#define AUDIO_IP_IT_DAOVFM									((uint32_t)0x00000001)
#define AUDIO_IP_IT_ADCVFM									((uint32_t)0x00000002)
#define AUDIO_IP_IT_ADCNSM									((uint32_t)0x00000004)
#define AUDIO_IP_IT_DACNSM									((uint32_t)0x00000008)
#define AUDIO_IP_IT_OVERCURM								((uint32_t)0x00000010)

#define IS_AUDIO_IP_IT(IT)									((IT & (~0x000001F)) == 0)

/** @} */ /* End of group AUDIO_IP_IT */

/** @defgroup AUDIO_IP_FLAG AUDIO_IP FLAG
  * @{
  */

#define AUDIO_IP_FLAG_DAOVF									((uint32_t)0x00000001)
#define AUDIO_IP_FLAG_ADCVF									((uint32_t)0x00000002)
#define AUDIO_IP_FLAG_ADCNS									((uint32_t)0x00000004)
#define AUDIO_IP_FLAG_DACNS									((uint32_t)0x00000008)
#define AUDIO_IP_FLAG_OVERCUR								((uint32_t)0x00000010)

#define IS_AUDIO_IP_FLAG(FLAG)								((FLAG == AUDIO_IP_FLAG_DAOVF) ||\
															 (FLAG == AUDIO_IP_FLAG_ADCVF) ||\
															 (FLAG == AUDIO_IP_FLAG_ADCNS) ||\
															 (FLAG == AUDIO_IP_FLAG_DACNS) ||\
															 (FLAG == AUDIO_IP_FLAG_OVERCUR))

/** @} */ /* End of group AUDIO_IP_FLAG */

/** @defgroup AUDIO_IP_SHORT_CIRCUIT_DETECTION AUDIO_IP SHORT_CIRCUIT_DETECTION
  * @{
  */

#define AUDIO_IP_SHORT_CIRCUIT_DETECTION_OUTPUT_BUFFER				((uint32_t)0x000000100)
#define	AUDIO_IP_SHORT_CIRCUIT_DETECTION_BIAS_CIRCUIT				((uint32_t)0x000000200)

#define AUDIO_IP_SHORT_CIRCUIT_DETECTION(SC)						((SC == AUDIO_IP_SHORT_CIRCUIT_DETECTION_OUTPUT_BUFFER) ||\
														 	 	 	 (SC == AUDIO_IP_SHORT_CIRCUIT_DETECTION_BIAS_CIRCUIT))

/** @} */ /* End of group AUDIO_IP_SHORT_CIRCUIT_DETECTION */

/** @} */ /* End of group AUDIO_IP_Exported_Macros */

/** @defgroup AUDIO_IP_Exported_Constants AUDIO_IP Exported Constants
  * @{
  */

/** @} */ /* End of group AUDIO_IP_Exported_Constants */

/** @defgroup AUDIO_IP_Exported_Functions AUDIO_IP Exported Functions
  * @{
  */
void AUDIO_IP_DeInit(void);
void AUDIO_IP_StructInit(AUDIO_IP_InitTypeDef * AUDIO_IP_InitStruct);
void AUDIO_IP_Init(AUDIO_IP_InitTypeDef * AUDIO_IP_InitStruct);
void AUDIO_IP_ADCCmd(FunctionalState NewState);
void AUDIO_IP_DACCmd(FunctionalState NewState);
void AUDIO_IP_SetADGain(uint32_t GainValue);
void AUDIO_IP_SetDAGain(uint32_t GainValue);
void AUDIO_IP_SetADCInputAdmplifierLevel(uint32_t InputAdmplifierLevel);
void AUDIO_IP_SetADCInputSource(uint32_t ADCInputSource);
void AUDIO_IP_DACMuteCmd(FunctionalState NewState);
void AUDIO_IP_DACOutputAmplifierCmd(FunctionalState NewState);
void AUDIO_IP_OverCurCmd(uint32_t value, FunctionalState NewState);
void AUDIO_IP_ITConfig(uint32_t AUDIO_IT, FunctionalState NewState);
ITStatus AUDIO_IP_GetITStatus(uint32_t AUDIO_IP_FLAG);
void AUDIO_IP_ClearITFlag(uint32_t AUDIO_IT);
uint16_t AUDIO_IP_ReceiveData(void);
void AUDIO_IP_SendData(uint16_t audio_data);

/** @} */ /* End of group AUDIO_IP_Exported_Functions */

/** @} */ /* End of group AUDIO_IP */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

#ifdef __cplusplus
} // extern "C" block end
#endif

#endif /* MDR32F9QX_AUDIO_H_ */

/******************* (C) COPYRIGHT 2013 Milandr ********************************
*
* END OF FILE MDR32F9Qx_audio.h */
