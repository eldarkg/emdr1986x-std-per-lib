/**
  * FILE MDR32F9Qx_adciu.c
  */

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_config.h"
#include "MDR32F9Qx_adciu.h"

#define ASSERT_INFO_FILE_ID FILEID__MDR32F9x_ADCIU_C

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @addtogroup ADCIU ADCIU
  * @{
  */

/** @defgroup ADIUC_Private_Functions ADCIU Private Functions
  * @{
  */

/**
 *	@brief	Deinitializes the ADCIU peripheral registers to their default reset values.
 */
void ADCIU_DeInit(void)
{
	MDR_ADCIU->CTRL2	= ADCIU_CTRL2_RESET;
	MDR_ADCIU->CTRL2	&= ~ADCIU_CTRL2_RESET;

	MDR_ADCIU->CTRL1 	= 0x00;
	MDR_ADCIU->ANGAIN 	= 0x00;
	MDR_ADCIU->DIGGAIN 	= 0x2A;
	MDR_ADCIU->DMAEN	= 0x00;
	MDR_ADCIU->CTRL2	= 0x00;
	MDR_ADCIU->INTEN	= 0x00;
	MDR_ADCIU->STAT		= 0x00;
}

/**
 * @brief	Initializes the ADCIU peripheral according to
 *          the specified parameters in the ADCIU_InitStruct.
 * @param 	ADCIU_InitStruct: pointer to a ADCIU_InitTypeDef structure
 *          that contains the configuration information for the specified ADCIU
 *          peripheral.
 */
void ADCIU_Init(ADCIU_InitTypeDef * ADCIU_InitStruct)
{
	/* Check the parameters */
	assert_param(IS_ADCIU_REFEREVCE_VOLTAGE(ADCIU_InitStruct->ADCIU_VoltageReference));
	assert_param(IS_ADCIU_CHOPPER_FREQUENCY_DIVIDER(ADCIU_InitStruct->ADCIU_ChopperFrequencyDivider));
	assert_param(IS_ADCIU_BYPASS_BUFFER_REFERNCE_CONF(ADCIU_InitStruct->ADCIU_BypassBufferReference));
	assert_param(IS_ADCIU_DGAIN(ADCIU_InitStruct->ADCIU_DigitalGain));
	assert_param(IS_ADCIU_SFC(ADCIU_InitStruct->ADCIU_SFCDivider));
	assert_param(IS_ADCIU_SFF(ADCIU_InitStruct->ADCIU_SFFDivider));

	/* Set reference voltage sorcse */
	MDR_ADCIU->CTRL1 = ADCIU_InitStruct->ADCIU_VoltageReference;

	/* Set ADCIU CTRL2 */
	MDR_ADCIU->CTRL2 = ADCIU_InitStruct->ADCIU_ChopperFrequencyDivider
					 | ADCIU_InitStruct->ADCIU_BypassBufferReference
					 | ADCIU_InitStruct->ADCIU_SFCDivider
					 | ADCIU_InitStruct->ADCIU_SFFDivider;

	/* Set ADCIU DIGGAIN */
	MDR_ADCIU->DIGGAIN = ADCIU_InitStruct->ADCIU_DigitalGain;

}

/**
 * @brief	Initializes the ADCIU channel peripheral according to
 *          the specified parameters in the ADCIU_ChannelInitStruct.
 * @param 	ChannelNumber: the number of the initialized channel.
 * @param 	ADCIU_ChannelInitStruct: pointer to a ADCIU_ChannelInitTypeDef
 * 			structure that contains the configuration information.
 */
void ADCIU_InitChannel(uint32_t ChannelNumber, ADCIU_ChannelInitTypeDef * ADCIU_ChannelInitStruct)
{
	uint32_t tmpreg;
	/* Check the parameters */
	assert_param(IS_ADCIU_CHANNEL_NUMBER(ChannelNumber));
	assert_param(IS_FUNCTIONAL_STATE(ADCIU_ChannelInitStruct->ADCIU_ChopperState));
	assert_param(IS_ADCIU_AGAIN(ADCIU_ChannelInitStruct->ADCIU_AnalogGain));
	assert_param(IS_FUNCTIONAL_STATE(ADCIU_ChannelInitStruct->ADCIU_DMARequest));
	assert_param(IS_FUNCTIONAL_STATE(ADCIU_ChannelInitStruct->ADCIU_IT_FIFO_OverflowState));
	assert_param(IS_FUNCTIONAL_STATE(ADCIU_ChannelInitStruct->ADCIU_IT_FIFO_OverflowState));

	/* Set mode to eliminate the constant component  */
	if(ADCIU_ChannelInitStruct->ADCIU_ChopperState == ENABLE){
		MDR_ADCIU->CTRL1 |= 1 << (ChannelNumber + ADCIU_CTRL1_CHP1EN_Pos);
	}
	else{
		MDR_ADCIU->CTRL1 &= ~(1 << (ChannelNumber + ADCIU_CTRL1_CHP1EN_Pos));
	}

	 /* Set new analog gain value */
	 tmpreg = MDR_ADCIU->ANGAIN & ~(ADCIU_ANGAIN_ADC1PGA_Msk << (2*ChannelNumber + ADCIU_ANGAIN_ADC1PGA_Pos));
	 tmpreg |= ADCIU_ChannelInitStruct->ADCIU_AnalogGain << (2*ChannelNumber + ADCIU_ANGAIN_ADC1PGA_Pos);
	 MDR_ADCIU->ANGAIN = tmpreg;

	 /* Set dma request when there is data in the FIFO */
	 if(ADCIU_ChannelInitStruct->ADCIU_DMARequest == ENABLE){
		 MDR_ADCIU->DMAEN |= 1 << ChannelNumber;
	 }
	 else{
		 MDR_ADCIU->DMAEN &= ~(1 << ChannelNumber);
	 }

	 /* Config interrupt config */
	 if(ADCIU_ChannelInitStruct->ADCIU_IT_FIFO_NotEmptyState == ENABLE){
		 MDR_ADCIU->INTEN |= 1 << ChannelNumber;
	 }
	 else{
		 MDR_ADCIU->INTEN &= ~(1 << ChannelNumber);
	 }

	 /* Config interrupt config */
	 if(ADCIU_ChannelInitStruct->ADCIU_IT_FIFO_OverflowState == ENABLE){
		 MDR_ADCIU->INTEN |= 1 << (ChannelNumber + ADCIU_INTEN_OV1M_Pos);
	 }
	 else{
		 MDR_ADCIU->INTEN &= ~(1 << (ChannelNumber + ADCIU_INTEN_OV1M_Pos));
	 }

}

/**
 * @brief	Fills each ADCIU_InitStruct member with its default value.
 * @param	ADCIU_InitStruct:  pointer to a ADCIU_InitStruct structure
 *          which will be initialized.
 */
void ADCIU_StructInit(ADCIU_InitTypeDef * ADCIU_InitStruct)
{
	ADCIU_InitStruct->ADCIU_VoltageReference		= ADCIU_REFEREVCE_VOLTAGE_INTERNAL;
	ADCIU_InitStruct->ADCIU_ChopperFrequencyDivider = ADCIU_CHOPPER_FREQUENCY_DIVIDER4;
	ADCIU_InitStruct->ADCIU_BypassBufferReference	= ADCIU_BYPASS_BUFFER_REFERNCE_DISABLE;
	ADCIU_InitStruct->ADCIU_DigitalGain				= 0x2A;
	ADCIU_InitStruct->ADCIU_SFCDivider				= ADCIU_SFC0;
	ADCIU_InitStruct->ADCIU_SFFDivider				= 0;
}

/**
 * @brief	Fills each ADCIU_ChannelInitStruct member with its default value.
 * @param 	ADCIU_ChannelInitStruct: pointer to a ADCIU_ChannelInitTypeDef
 * 			structure which will be initialized.
 */
void ADCIU_ChannelStructInit(ADCIU_ChannelInitTypeDef * ADCIU_ChannelInitStruct)
{
	ADCIU_ChannelInitStruct->ADCIU_ChopperState				= DISABLE;
	ADCIU_ChannelInitStruct->ADCIU_AnalogGain				= ADCIU_AGAIN0dB;
	ADCIU_ChannelInitStruct->ADCIU_DMARequest				= DISABLE;
	ADCIU_ChannelInitStruct->ADCIU_IT_FIFO_OverflowState	= DISABLE;
	ADCIU_ChannelInitStruct->ADCIU_IT_FIFO_NotEmptyState	= DISABLE;
}

/**
 * @brief	Enables or disables the ADCIUx channel.
 * @param 	ChannelNumber: the number of channel.
 * 			This parameter can be one of the following values:
 * 				@arg ADCIU_CHANNEL_NUMBER1
 * 				@arg ADCIU_CHANNEL_NUMBER2
 * 				@arg ADCIU_CHANNEL_NUMBER3
 * 				@arg ADCIU_CHANNEL_NUMBER4
 * 				@arg ADCIU_CHANNEL_NUMBER5
 * 				@arg ADCIU_CHANNEL_NUMBER6
 * 				@arg ADCIU_CHANNEL_NUMBER7
 * 				@arg ADCIU_CHANNEL_NUMBER8
 * @param 	NewState: new state of the ADCIUx channel.
 *          This parameter can be: ENABLE or DISABLE.
 */
void ADCIU_ChannelCmd(uint32_t ChannelNumber, FunctionalState NewState)
{
	/* Check the parameters */
	assert_param(IS_ADCIU_CHANNEL_NUMBER(ChannelNumber));
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(NewState == ENABLE){
		MDR_ADCIU->CTRL1 |= 1 << ChannelNumber;
	}
	else{
		MDR_ADCIU->CTRL1 &= ~(1 << ChannelNumber);
	}
}

/**
 * @brief	Enables or disables the ADCIUx channel chopper.
 * @param 	ChannelNumber: the number of channel.
 * 			This parameter can be one of the following values:
 * 				@arg ADCIU_CHANNEL_NUMBER1
 * 				@arg ADCIU_CHANNEL_NUMBER2
 * 				@arg ADCIU_CHANNEL_NUMBER3
 * 				@arg ADCIU_CHANNEL_NUMBER4
 * 				@arg ADCIU_CHANNEL_NUMBER5
 * 				@arg ADCIU_CHANNEL_NUMBER6
 * 				@arg ADCIU_CHANNEL_NUMBER7
 * 				@arg ADCIU_CHANNEL_NUMBER8
 * @param 	NewState: new state of the ADCIUx channel.
 *          This parameter can be: ENABLE or DISABLE.
 */
void ADCIU_ChopperCmd(uint32_t ChannelNumber, FunctionalState NewState)
{
	/* Check the parameters */
	assert_param(IS_ADCIU_CHANNEL_NUMBER(ChannelNumber));
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	/* Set mode to eliminate the constant component */
	if(NewState == ENABLE){
		MDR_ADCIU->CTRL1 |= 1 << (ADCIU_CTRL1_CHP1EN_Pos + ChannelNumber);
	}
	else{
		MDR_ADCIU->CTRL1 &= ~(1 << (ADCIU_CTRL1_CHP1EN_Pos + ChannelNumber));
	}
}

/**
 * @brief	Set the analog gain for the specified channel.
 * @param 	ChannelNumber: the number of channel.
 * 			This parameter can be one of the following values:
 * 				@arg ADCIU_CHANNEL_NUMBER1
 * 				@arg ADCIU_CHANNEL_NUMBER2
 * 				@arg ADCIU_CHANNEL_NUMBER3
 * 				@arg ADCIU_CHANNEL_NUMBER4
 * 				@arg ADCIU_CHANNEL_NUMBER5
 * 				@arg ADCIU_CHANNEL_NUMBER6
 * 				@arg ADCIU_CHANNEL_NUMBER7
 * 				@arg ADCIU_CHANNEL_NUMBER8
 * @param 	gain: the new value of the analog gain.
 * 			This parameter can be one of the following values:
 * 				@arg ADCIU_AGAIN0dB
 * 				@arg ADCIU_AGAIN6dB
 * 				@arg ADCIU_AGAIN12dB
 * 				@arg ADCIU_AGAIN24dB
 */
void ADCIU_AGain(uint32_t ChannelNumber, uint32_t gain)
{
	uint32_t tmpreg;

	/* Check the parameters */
	assert_param(IS_ADCIU_CHANNEL_NUMBER(ChannelNumber));
	assert_param(IS_ADCIU_AGAIN(gain));

	/*  Set analog gain */
	tmpreg = MDR_ADCIU->ANGAIN;
	tmpreg &= ~(ADCIU_ANGAIN_ADC1PGA_Msk << ChannelNumber*2);
	tmpreg |= gain << ChannelNumber*2;

	/* */
	MDR_ADCIU->ANGAIN = tmpreg;
}

/**
 * @brief	Enables or disables the ADCIU interrupts.
 * @param 	ChannelNumber: the channel number.
 * 			This parameter can be one of the following values:
 * 				@arg ADCIU_CHANNEL_NUMBER1
 * 				@arg ADCIU_CHANNEL_NUMBER2
 * 				@arg ADCIU_CHANNEL_NUMBER3
 * 				@arg ADCIU_CHANNEL_NUMBER4
 * 				@arg ADCIU_CHANNEL_NUMBER5
 * 				@arg ADCIU_CHANNEL_NUMBER6
 * 				@arg ADCIU_CHANNEL_NUMBER7
 * 				@arg ADCIU_CHANNEL_NUMBER8
 * @param 	ADCIU_IT: specifies the ADCIU interrupts sources to be enabled or disabled.
 * 			This parameter can be one of the following values:
 * 				@arg ADCIU_IT_FIFO_OVERFLOW
 * 				@arg ADCIU_IT_FITO_NOT_EMPTY
 * @param 	NewState: new state of the ADCIU interrupts.
 *         This parameter can be: ENABLE or DISABLE.
 */
void ADCIU_ITConfig(uint32_t ChannelNumber, uint32_t ADCIU_IT, FunctionalState NewState)
{
	/* Check the parameters */
	assert_param(IS_ADCIU_CHANNEL_NUMBER(ChannelNumber));
	assert_param(IS_ADCIU_IT(ADCIU_IT));
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	/* Config IT state */
	if(NewState == ENABLE){
		MDR_ADCIU->INTEN |= (ADCIU_IT << ChannelNumber);
	}
	else{
		MDR_ADCIU->INTEN &= ~(ADCIU_IT << ChannelNumber);
	}

}

/**
 * @brief	Clears the ADCIU specified interupt flag.
 * @param 	ChannelNumber: the number of channel.
 * 			This parameter can be one of the following values:
 * 				@arg ADCIU_CHANNEL_NUMBER1
 * 				@arg ADCIU_CHANNEL_NUMBER2
 * 				@arg ADCIU_CHANNEL_NUMBER3
 * 				@arg ADCIU_CHANNEL_NUMBER4
 * 				@arg ADCIU_CHANNEL_NUMBER5
 * 				@arg ADCIU_CHANNEL_NUMBER6
 * 				@arg ADCIU_CHANNEL_NUMBER7
 * 				@arg ADCIU_CHANNEL_NUMBER8
 * 			This parameter can be one of the following values:
 * 				@arg ADCIU_IT_FIFO_OVERFLOW
 * @param 	ADCIU_IT: IT tha could be sleared.
 */
void ADCIU_ClearIT_OVERFLOW(uint32_t ChannelNumber)
{
	/* Check the parameters */
	assert_param(IS_ADCIU_CHANNEL_NUMBER(ChannelNumber));

	MDR_ADCIU->STAT |= ADCIU_IT_FIFO_OVERFLOW << ChannelNumber;
}

/**
 * @brief	Enables or disables the ADCIUx channel DMA request.
 * @param 	ChannelNumber: the number of channel.
 * 			This parameter can be one of the following values:
 * 				@arg ADCIU_CHANNEL_NUMBER1
 * 				@arg ADCIU_CHANNEL_NUMBER2
 * 				@arg ADCIU_CHANNEL_NUMBER3
 * 				@arg ADCIU_CHANNEL_NUMBER4
 * 				@arg ADCIU_CHANNEL_NUMBER5
 * 				@arg ADCIU_CHANNEL_NUMBER6
 * 				@arg ADCIU_CHANNEL_NUMBER7
 * 				@arg ADCIU_CHANNEL_NUMBER8
 * @param 	NewState: new state of the ADCIUx channel.
 *          This parameter can be: ENABLE or DISABLE.
 */
void ADCIU_DMARequestCmd(uint32_t ChannelNumber, FunctionalState NewState)
{
	/* Check the parameters */
	assert_param(IS_ADCIU_CHANNEL_NUMBER(ChannelNumber));
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(NewState == ENABLE){
		MDR_ADCIU->DMAEN |= 1 << ChannelNumber;
	}
	else{
		MDR_ADCIU->DMAEN &= ~(1 << ChannelNumber);
	}
}

/**
 * @brief	Checks whether the specified ADCIU Status flag is set or not.
 * @param 	ChannelNumber: the number of channel.
 * 			This parameter can be one of the following values:
 * 				@arg ADCIU_CHANNEL_NUMBER1
 * 				@arg ADCIU_CHANNEL_NUMBER2
 * 				@arg ADCIU_CHANNEL_NUMBER3
 * 				@arg ADCIU_CHANNEL_NUMBER4
 * 				@arg ADCIU_CHANNEL_NUMBER5
 * 				@arg ADCIU_CHANNEL_NUMBER6
 * 				@arg ADCIU_CHANNEL_NUMBER7
 * 				@arg ADCIU_CHANNEL_NUMBER8
 * @param 	ADCIU_STATUS_FLAG: specifies the flag to check.
 *          This parameter can be one of the following values:
 *          	@arg ADCIU_FLAG_FIFO_OVERFLOW
 *          	@arg ADCIU_FLAG_FITO_NOT_EMPTY
 * @return	Current Status flag state (SET or RESET).
 */
FlagStatus ADCIU_GetStatusFlag(uint32_t ChannelNumber, uint32_t ADCIU_STATUS_FLAG)
{
	FlagStatus flag = RESET;
	/* Check the parameters */
	assert_param(IS_ADCIU_CHANNEL_NUMBER(ChannelNumber));
	assert_param(IS_ADCIU_FLAG(ADCIU_STATUS_FLAG));

	if(MDR_ADCIU->STAT & (ADCIU_STATUS_FLAG << ChannelNumber)){
		flag = SET;
	}

	return (flag);
}

/**
 * @brief	Returns the ADCIU result.
 * @param 	ChannelNumber: the number of channel.
 * 			This parameter can be one of the following values:
 * 				@arg ADCIU_CHANNEL_NUMBER1
 * 				@arg ADCIU_CHANNEL_NUMBER2
 * 				@arg ADCIU_CHANNEL_NUMBER3
 * 				@arg ADCIU_CHANNEL_NUMBER4
 * 				@arg ADCIU_CHANNEL_NUMBER5
 * 				@arg ADCIU_CHANNEL_NUMBER6
 * 				@arg ADCIU_CHANNEL_NUMBER7
 * 				@arg ADCIU_CHANNEL_NUMBER8
 * @return	ADCIU Result Register value for the specified channel.
 */
uint32_t ADCIU_GetResult(uint32_t ChannelNumber)
{
	/* Check the parameters */
	assert_param(IS_ADCIU_CHANNEL_NUMBER(ChannelNumber));

	return (MDR_ADCIU->F_DAT[ChannelNumber]);
}

/** @} */ /* End of group ADCIU_Private_Functions */

/** @} */ /* End of group ADCIU */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

/*
*
* END OF FILE MDR32F9Qx_adciu.c */
