/**
  ******************************************************************************
  * @file	 MDR32F9Qx_audio.c
  * @author	 sidorov.a
  * @version V1.3.0
  * @date    11.10.2013
  * @brief   This file contains all the AUDIO_IP firmware functions.
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
  * FILE MDR32F9Qx_audio.c
  */

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_config.h"
#include "MDR32F9Qx_audio.h"

#define ASSERT_INFO_FILE_ID FILEID__MDR32F9Qx_AUDIO_C

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @defgroup AUDIO_IP AUDIO_IP
  * @warning This module can be used only for MDR1986VE3 microcontroller's.
  * @{
  */
#if defined (USE_MDR1986VE3)

/** @defgroup AUDIO_IP_Private_Defines AUDIO_IP Private Defines
  * @{
  */

/** @} */ /* End of group AUDIO_IP_Private_Defines */

/** @defgroup AUDIO_IP_Private_Macros AUDIO_IP Private Macros
  * @{
  */

#define IS_AUDIO_IP_AD_GAIN(AD_GAIN)					((AD_GAIN & (~0x0000003F)) == 0)
#define IS_AUDIO_IP_DA_GAIN(DA_GAIN)					((DA_GAIN & (~0x0000003F)) == 0)
#define IS_AUDIO_IP_CLEAR_IT(IT)						(IT & (~0x00000003) == 0)
#define SHORT_CIRCUIT_DETECTION(SC)						((SC == AUDIO_IP_DACCTL_OVECBA) ||\
														 (SC == AUDIO_IP_DACCTL_OVECBS))

/** @} */ /* End of group AUDIO_IP_Private_Macros */

/** @defgroup AUDIO_IP_Private_Variables AUDIO_IP Private Variables
  * @{
  */

/** @} */ /* End of group AUDIO_IP_Private_Variables */

/** @defgroup AUDIO_IP_Private_FunctionPrototypes AUDIO_IP Private FunctionPrototypes
  * @{
  */

/** @} */ /* End of group AUDIO_IP_Private_FunctionPrototypes */

/** @defgroup AUDIO_IP_Private_Functions AUDIO_IP Private Functions
  * @{
  */

/**
  * @brief	Reset the AUDIO_IP registers to their default reset values.
  * @param	None.
  * @retval	None.
  */
void AUDIO_IP_DeInit(void)
{
	MDR_AUDIO_IP->POWCTL	= 0x000001C0;
	MDR_AUDIO_IP->ADCCTL	= 0x0000002A;
	MDR_AUDIO_IP->DACCTL	= 0x0000002A;
	MDR_AUDIO_IP->MASKCTL	= 0x0000000F;
	MDR_AUDIO_IP->IRQFLAG	= 0x00000000;
}

/**
  * @brief	Fills each AUDIO_IP_InitStuct member with its default value.
  * @param	AUDIO_IP_InitStuct: pointer to a AUDIO_IP_InitTypeDef structure which will be initialized.
  * @retval	None.
  */
void AUDIO_IP_StructInit(AUDIO_IP_InitTypeDef * AUDIO_IP_InitStruct)
{
	AUDIO_IP_InitStruct->FilterMode					= AUDIO_IP_FILTER_MODE_FIR_FILTER;
	AUDIO_IP_InitStruct->AnalogLoopBackMode			= DISABLE;
	AUDIO_IP_InitStruct->DigitalLoopBackMode		= DISABLE;


	AUDIO_IP_InitStruct->ADGain						= 0x2A;
	AUDIO_IP_InitStruct->ADCInputAmplifier			= AUDIO_IP_ADC_INPUT_AMPLIFIER_LEVEL_0_DB;
	AUDIO_IP_InitStruct->ADCAnalogInput				= AUDIO_IP_ANALOG_INPUT_SOURCE_INP1;
	AUDIO_IP_InitStruct->ADCInputControl			= DISABLE;

	AUDIO_IP_InitStruct->DAGain						= 0x2A;
	AUDIO_IP_InitStruct->DACMute					= DISABLE;
	AUDIO_IP_InitStruct->DACOutputAmplifier			= DISABLE;
	AUDIO_IP_InitStruct->DACBIASOffsetSchemeState	= DISABLE;
	AUDIO_IP_InitStruct->DACAnalogState				= DISABLE;
	AUDIO_IP_InitStruct->DACOverCurrentBufferDet	= DISABLE;
	AUDIO_IP_InitStruct->DACOverCurrentNetOffsetDet	= DISABLE;
	AUDIO_IP_InitStruct->DACSideToneLoopBack		= AUDIO_IP_DAC_SIDE_TONE_LOOP_BACK_3dB;
	AUDIO_IP_InitStruct->DACState					= DISABLE;
}

/**
  * @brief	Initializes the AUDIO_IP peripheral according to the specified
  *   		parameters in the AUDIO_IP_InitStuct.
  * @param	AUDIO_IP_InitStuct: pointer to a AUDIO_IP_InitTypeDef structure which will be initialized.
  * @retval	None.
  */
void AUDIO_IP_Init(AUDIO_IP_InitTypeDef * AUDIO_IP_InitStruct)
{
	uint32_t tmpreg;

	/* Check the parameters */
	assert_param(IS_AUDIO_IP_FILTER_MODE(AUDIO_IP_InitStruct->FilterMode));
	assert_param(IS_FUNCTIONAL_STATE(AUDIO_IP_InitStruct->AnalogLoopBackMode));
	assert_param(IS_FUNCTIONAL_STATE(AUDIO_IP_InitStruct->DigitalLoopBackMode));
	assert_param(IS_AUDIO_IP_AD_GAIN(AUDIO_IP_InitStruct->ADGain));
	assert_param(IS_AUDIO_IP_INPUT_AMPLIFIER_LEVEL(AUDIO_IP_InitStruct->ADCInputAmplifier));
	assert_param(IS_AUDIO_IP_DA_GAIN(AUDIO_IP_InitStruct->DAGain));
	assert_param(IS_FUNCTIONAL_STATE(AUDIO_IP_InitStruct->DACMute));
	assert_param(IS_FUNCTIONAL_STATE(AUDIO_IP_InitStruct->DACOutputAmplifier));
	assert_param(IS_FUNCTIONAL_STATE(AUDIO_IP_InitStruct->DACBIASOffsetSchemeState));
	assert_param(IS_FUNCTIONAL_STATE(AUDIO_IP_InitStruct->DACAnalogState));
	assert_param(IS_FUNCTIONAL_STATE(AUDIO_IP_InitStruct->DACOverCurrentBufferDet));
	assert_param(IS_FUNCTIONAL_STATE(AUDIO_IP_InitStruct->DACOverCurrentNetOffsetDet));
	assert_param(IS_AUDIO_IP_DAC_SIDE_TONE_LOOP_BACK(AUDIO_IP_InitStruct->DACSideToneLoopBack));
	assert_param(IS_FUNCTIONAL_STATE(AUDIO_IP_InitStruct->DACState));

	/* Configure POWCTL register */
	tmpreg = (AUDIO_IP_InitStruct->FilterMode 			<< AUDIO_IP_POWCTL_IIREN_Pos) |
			 (AUDIO_IP_InitStruct->AnalogLoopBackMode 	<< AUDIO_IP_POWCTL_ALB_Pos  ) |
			 (AUDIO_IP_InitStruct->DigitalLoopBackMode 	<< AUDIO_IP_POWCTL_DLB_Pos  );

	MDR_AUDIO_IP->POWCTL = tmpreg;

	/* Configure ADCCTL register */
	tmpreg = (AUDIO_IP_InitStruct->ADGain) 											|
			 (AUDIO_IP_InitStruct->ADCInputAmplifier << AUDIO_IP_ADCCTL_INBG_Pos) 	|
			 (AUDIO_IP_InitStruct->ADCAnalogInput 	<< AUDIO_IP_ADCCTL_AINSEL_Pos) 	|
			 (AUDIO_IP_InitStruct->ADCInputControl 	<<AUDIO_IP_ADCCTL_ICONT_Pos);

	MDR_AUDIO_IP->ADCCTL = tmpreg;

	/* Configure DACCTL register */
	tmpreg = (AUDIO_IP_InitStruct->DAGain) 													 |
			 (AUDIO_IP_InitStruct->DACMute 					 << AUDIO_IP_DACCTL_MUTE1_Pos)   |
			 (AUDIO_IP_InitStruct->DACOutputAmplifier		 << AUDIO_IP_DACCTL_ODAMP_Pos)   |
			 (AUDIO_IP_InitStruct->DACBIASOffsetSchemeState	 << AUDIO_IP_DACCTL_BIAS_Pos)	 |
			 (AUDIO_IP_InitStruct->DACAnalogState			 << AUDIO_IP_DACCTL_ODDAC_Pos)   |
			 (AUDIO_IP_InitStruct->DACOverCurrentBufferDet 	 << AUDIO_IP_DACCTL_OVECBA_Pos)  |
			 (AUDIO_IP_InitStruct->DACOverCurrentNetOffsetDet << AUDIO_IP_DACCTL_OVECBS_Pos)  |
			 (AUDIO_IP_InitStruct->DACSideToneLoopBack		 << AUDIO_IP_DACCTL_SIDETONE_Pos)|
			 (AUDIO_IP_InitStruct->DACState					 << AUDIO_IP_DACCTL_DACRES_Pos);

	MDR_AUDIO_IP->DACCTL = tmpreg;
}

/**
  * @brief	Enables or disables the AUDIO_IP ADC channel.
  * @param	NewState: new state of the AUDIO_IP ADC channel.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval	None.
  */
void AUDIO_IP_ADCCmd(FunctionalState NewState)
{
	/* Check the parameters */
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(NewState != DISABLE){
		MDR_AUDIO_IP->POWCTL |= AUDIO_IP_POWCTL_ADCEN;
	}
	else{
		MDR_AUDIO_IP->POWCTL &= ~AUDIO_IP_POWCTL_ADCEN;
	}
}

/**
  * @brief	Enables or disables the AUDIO_IP DAC channel.
  * @param	NewState: new state of the AUDIO_IP DAC channel.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval	None.
  */
void AUDIO_IP_DACCmd(FunctionalState NewState)
{
	/* Check the parameters */
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(NewState != DISABLE){
		MDR_AUDIO_IP->POWCTL |= AUDIO_IP_POWCTL_DACEN;
	}
	else{
		MDR_AUDIO_IP->POWCTL &= ~AUDIO_IP_POWCTL_DACEN;
	}
}

/**
  * @brief	Set the new value of the ADC gain.
  * @param	GainValue: new vale of of the ADC gain.
  * @retval	None.
  */
void AUDIO_IP_SetADGain(uint32_t GainValue)
{
	uint32_t tmpreg;

	/* Check the parameters */
	assert_param(IS_AUDIO_IP_AD_GAIN(GainValue));

	tmpreg = MDR_AUDIO_IP->ADCCTL & (~AUDIO_IP_ADCCTL_ADGAIN_Msk);
	tmpreg |= GainValue & AUDIO_IP_ADCCTL_ADGAIN_Msk;
	MDR_AUDIO_IP->ADCCTL = tmpreg;
}

/**
  * @brief	Set the new value of the DAC gain.
  * @param	GainValue: new vale of of the DAC gain.
  * @retval None.
  */
void AUDIO_IP_SetDAGain(uint32_t GainValue)
{
	uint32_t tmpreg;

	/* Check the parameters */
	assert_param(IS_AUDIO_IP_DA_GAIN(GainValue));

	tmpreg = MDR_AUDIO_IP->ADCCTL & (~AUDIO_IP_DACCTL_DAGAIN_Msk);
	tmpreg |= GainValue & AUDIO_IP_DACCTL_DAGAIN_Msk;
	MDR_AUDIO_IP->DACCTL = tmpreg;
}

/**
  * @brief	Sets the new value of the preamplifier ADC.
  * @param	InputAdmplifierLevel: the new value of the preamplifier.
  * @retval	None.
  */
void AUDIO_IP_SetADCInputAdmplifierLevel(uint32_t InputAdmplifierLevel)
{
	uint32_t tmpreg;
	/* Check the parameters */
	assert_param(IS_AUDIO_IP_INPUT_AMPLIFIER_LEVEL(InputAdmplifierLevel));

	tmpreg = MDR_AUDIO_IP->ADCCTL & (~AUDIO_IP_ADCCTL_INBG_Msk);
	tmpreg |= InputAdmplifierLevel << AUDIO_IP_ADCCTL_INBG_Pos;
	MDR_AUDIO_IP->ADCCTL = tmpreg;
}

/**
  * @brief	Selects the source of the analog input signal.
  * @param	ADCInputSource: the new value of the analog input signal source.
  * @retval	None.
  */
void AUDIO_IP_SetADCInputSource(uint32_t ADCInputSource)
{
	uint32_t tmpreg;
	/* Check the parameters */
	assert_param(IS_AUDIO_IP_ANALOG_INPUT_SOURCE(ADCInputSource));

	tmpreg = MDR_AUDIO_IP->ADCCTL & (~AUDIO_IP_ADCCTL_AINSEL_Msk);
	tmpreg |= ADCInputSource << AUDIO_IP_ADCCTL_AINSEL_Pos;
	MDR_AUDIO_IP->ADCCTL = tmpreg;
}

/**
  * @brief	Enable or disable mute on the DAC output.
  * @param	NewState: new state of the DAC mute output.
  * 		This parameter can be: ENABLE or DISABLE.
  * @retval	None.
  */
void AUDIO_IP_DACMuteCmd(FunctionalState NewState)
{
	/* Check the parameters */
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(NewState != DISABLE){
		MDR_AUDIO_IP->DACCTL |= AUDIO_IP_DACCTL_MUTE1;
	}
	else{
		MDR_AUDIO_IP->DACCTL &= ~AUDIO_IP_DACCTL_MUTE1;
	}
}

/**
  * @brief	Enalbe or disable DAC output amplifier.
  * @param	NewState: new state of the DAC output.
  * 		This parameter can be: ENABLE or DISABLE.
  * @retval	None.
  */
void AUDIO_IP_DACOutputAmplifierCmd(FunctionalState NewState)
{
	/* Check the parameters */
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(NewState != DISABLE ){
		MDR_AUDIO_IP->DACCTL |= AUDIO_IP_DACCTL_ODAMP;
	}
	else{
		MDR_AUDIO_IP->DACCTL &= ~AUDIO_IP_DACCTL_ODAMP;
	}
}

/**
  * @brief	Enables or disables the detection circuit short circuit.
  * @param	ShortCircuitDetection: type of circuit a short circuit.
  * 		This parameter can be one following values:
  * 			@arg	SHORT_CIRCUIT_DETECTION_OUTPUT_BUFFER
  * 			@arg	SHORT_CIRCUIT_DETECTION_BIAS_CIRCUIT
  * @param	NewState: new state of the circuit.
  * @retval None.
  */
void AUDIO_IP_OverCurCmd(uint32_t ShortCircuitDetection, FunctionalState NewState)
{
	/* Check the parameters */
	assert_param(IS_FUNCTIONAL_STATE(NewState));
	assert_param(AUDIO_IP_SHORT_CIRCUIT_DETECTION(ShortCircuitDetection));

	if(NewState != DISABLE ){
		MDR_AUDIO_IP->DACCTL |= ShortCircuitDetection;
	}
	else{
		MDR_AUDIO_IP->DACCTL &= ~ShortCircuitDetection;
	}
}

/**
  * @brief	Enables or disables the specified AUDIO_IP interrupts.
  * @param	AUDIO_IT: specifies the AUDIO_IP interrupt sources to be enabled or disabled.
  * 		This parameter can be one of the following values:
  * 			@arg AUDIO_IP_IT_DAOVFM:	mask of overflow interrupt DAC.
  * 			@arg AUDIO_IP_IT_ADCVFM:	mask of overflow interrupt ADC.
  * 			@arg AUDIO_IP_IT_ADCNSM:	mask of ADC FIFO interrupt.
  * 			@arg AUDIO_IP_IT_DACNSM:	mask of DAC FIFO interrupt
  * 			@arg AUDIO_IP_IT_OVERCURM:	mask of interrupt output short circuit DAC.
  * @retval	None.
  */
void AUDIO_IP_ITConfig(uint32_t AUDIO_IT, FunctionalState NewState)
{
	/* Check the parameters */
	assert_param(IS_AUDIO_IP_IT(AUDIO_IT));
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(NewState != DISABLE){
		MDR_AUDIO_IP->MASKCTL |= AUDIO_IT;
	}
	else{
		MDR_AUDIO_IP->MASKCTL &= ~(AUDIO_IT);
	}
}

/**
  * @brief	Checks whether the specified AUDIO_IP interrupt has occurred or not.
  * @param	AUDIO_IT: specifies the AUDIO_IP interrupt source to check.
  * 		This parameter can be one of the following values:
  * 			@arg AUDIO_IP_FLAG_DAOVF:	flag of overflow interrupt DAC.
  * 			@arg AUDIO_IP_FLAG_ADCVF:	flag of overflow interrupt ADC.
  * 			@arg AUDIO_IP_FLAG_ADCNS:	flag of ADC FIFO interrupt.
  * 			@arg AUDIO_IP_FLAG_DACNS:	flag of DAC FIFO interrupt.
  * 			@arg AUDIO_IP_FLAG_OVERCUR:	flag of interrupt output short circuit DAC.
  * @retval
  */
ITStatus AUDIO_IP_GetITStatus(uint32_t AUDIO_IP_FLAG)
{
	ITStatus bitstatus;

	/* Check the parameters */
	assert_param(IS_AUDIO_IP_FLAG(AUDIO_IP_FLAG));

	if(MDR_AUDIO_IP->IRQFLAG & AUDIO_IP_FLAG){
		bitstatus = SET;
	}
	else{
		bitstatus = RESET;
	}
	return (bitstatus);
}

/**
  * @brief	Clears the AUDIO_IP's interrupt pending bits.
  * @param	AUDIO_IT: specifies the interrupt pending bit to clear.
  * 		This parameter can be one of the following values:
  * 			@arg AUDIO_IP_IT_DAOVFM
  * 			@arg AUDIO_IP_IT_ADCVFM
  * @retval	None.
  */
void AUDIO_IP_ClearITFlag(uint32_t AUDIO_IT)
{
	/* Check the parameters */
	assert_param(IS_AUDIO_IP_CLEAR_IT(AUDIO_IT));
	MDR_AUDIO_IP->IRQFLAG |= AUDIO_IT;
}


/**
  * @brief	Returns the new sample of the ADC AUDIO_IP.
  * @param	None.
  * @retval New sample of the ADC AUDIO_IP.
  */
uint16_t AUDIO_IP_ReceiveData(void)
{
	return (MDR_AUDIO_IP->ADCREG & 0x0000FFFF);
}

/**
  * @brief	Sets the AUDIO_IP DAC output data.
  * @param	audio_data: specifies the DAC output data.
  * @retval None.
  */
void AUDIO_IP_SendData(uint16_t audio_data)
{
	MDR_AUDIO_IP->DACREG = audio_data & 0x0000FFFF;
}

/** @} */ /* End of group AUDIO_IP_Private_Functions */

#endif /* #if defined (USE_MDR1986VE3) */

/** @} */ /* End of group AUDIO_IP */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

/******************* (C) COPYRIGHT 2013 Milandr ********************************
*
* END OF FILE MDR32F9Qx_audio.c */
