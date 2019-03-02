/**
  * FILE MDR32F9Qx_arinc429r.c
  */

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_config.h"
#include "MDR32F9Qx_arinc429r.h"

#define ASSERT_INFO_FILE_ID FILEID__MDR32F9X_ARINC429R_C

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @defgroup ARINC429R ARINC429R
 *  @warning This module can be used only for microcontrollers MDR1986VE1T and MDR1986VE3.
  * @{
  */

#if defined (USE_MDR1986VE1T) || defined (USE_MDR1986VE3)

/** @defgroup ARINC429R_Private_Defines ARINC429R Private Defines
  * @{
  */

#define IS_ARINC429R_BRG(BRG)		((BRG) <= 0x7F)
#define IS_ARINC429R_DIV(DIV)		((DIV) <= 0xFF)
#define IS_ARINC429R_LABLE(LABLE)	((LABLE & 0xFF) == 0)

/** @} */ /* End of group ARINC429R_Private_Defines */

/** @defgroup ARINC429R_Private_Functions ARINC429R Private Functions
  * @{
  */

/**
  * @brief	Initializes the ARINC429R peripheral Clock according to the
  *         specified parameters.
  * @param	ARINC429R_BRG: specifies the HCLK division factor.
  * 		This parameter is number from 0 to 0x7F.
  * @retval	None
  */
void ARINC429R_BRG_Init(uint32_t ARINC429R_BRG)
{
	uint32_t tmpreg_CONTROL1;
	uint32_t tmpreg_CONTROL2;
	MDR_ARINC429R_TypeDef * ARINC429Rx;

	/* Check the parameters */
	assert_param(IS_ARINC429R_BRG(ARINC429R_BRG));

	ARINC429Rx = MDR_ARINC429R;

	/* Read the control1 and control2 ARINC register */
	tmpreg_CONTROL1 = ARINC429Rx->CONTROL1;
	tmpreg_CONTROL2 = ARINC429Rx->CONTROL2;

	/* Clear the previous value of the divisor */
	tmpreg_CONTROL1 &= ~ARINC429R_CONTROL1_DIV_Msk;
	tmpreg_CONTROL2 &= ~ARINC429R_CONTROL2_DIV_6_4_Msk;

	/* Set the new value of the divisor */
	tmpreg_CONTROL1 |= ((ARINC429R_BRG & 0x0F )<< ARINC429R_CONTROL1_DIV_Pos);
	tmpreg_CONTROL2 |= (((ARINC429R_BRG & 0x70)>>4) << ARINC429R_CONTROL2_DIV_6_4_Pos);

	/* Write the control1 and control2 ARINC register */
	ARINC429Rx->CONTROL1 = tmpreg_CONTROL1;
	ARINC429Rx->CONTROL2 = tmpreg_CONTROL2;
}

/**
  * @brief	Reset the ARINC429R peripheral registers to their default reset values.
  * @param	None.
  * @retval	None.
  */
void ARINC429R_DeInit()
{
	MDR_ARINC429R_TypeDef * ARINC429Rx;
	ARINC429Rx = MDR_ARINC429R;

	ARINC429Rx->CONTROL1 = 0;
	ARINC429Rx->CONTROL2 = 0;
	ARINC429Rx->CONTROL3 = 0;
	ARINC429Rx->STATUS1  = 0;
	ARINC429Rx->STATUS2	 = 0;
	ARINC429Rx->CONTROL4 = 0;
	ARINC429Rx->CONTROL5 = 0;
	ARINC429Rx->CHANNEL  = 0;
	ARINC429Rx->LABEL	 = 0;
#if defined (USE_MDR1986VE3)
	ARINC429Rx->CONTROL6 = 0;
	ARINC429Rx->CONTROL7 = 0;
#endif
}

/**
  * @brief	Initializes the ARINC429R channelx peripheral according to the specified
  *         sparameters in the ARINC429R_InitChannelStruct.
  * @param	ARINC429R_CHANNELx: Select the ARINC429R channel.
  *         This parameter can be one of the following values:
  *         	@arg ARINC429R_CHANNEL1
  *         	@arg ARINC429R_CHANNEL2
  *         	@arg ARINC429R_CHANNEL3
  *         	@arg ARINC429R_CHANNEL4
  *         	@arg ARINC429R_CHANNEL5
  *         	@arg ARINC429R_CHANNEL6
  *         	@arg ARINC429R_CHANNEL7
  *         	@arg ARINC429R_CHANNEL8
  *         	@note Available only for MC MDR1986BE3
  *         	@arg ARINC429R_CHANNEL9
  *         	@arg ARINC429R_CHANNEL10
  *         	@arg ARINC429R_CHANNEL11
  *         	@arg ARINC429R_CHANNEL12
  *         	@arg ARINC429R_CHANNEL13
  *         	@arg ARINC429R_CHANNEL14
  * @param	ARINC429R_InitChannelStruct: pointer to a ARINC429R_InitChannelTypeDef structure
  *         that contains the configuration information for the specified ARINC429R channel.
  * @retval	None
  */
void ARINC429R_ChannelInit(uint32_t ARINC429R_CHANNELx, ARINC429R_InitChannelTypeDef * ARINC429R_InitChannelStruct)
{
	MDR_ARINC429R_TypeDef * ARINC429Rx;
	uint32_t tmpreg_CONTROL1;
	uint32_t tmpreg_CONTROL2;
	uint32_t tmpreg_CONTROL3;
	uint32_t tmpreg_CONTROL4;
	uint32_t tmpreg_CONTROL5;
#if defined (USE_MDR1986VE3)
	uint32_t tmpreg_CONTROL6;
	uint32_t tmpreg_CONTROL7;
#endif

	/* Check the parameters */
	assert_param(IS_ARINC429R_CHANNEL(ARINC429R_CHANNELx));
	assert_param(IS_ARINC429R_CLK(ARINC429R_InitChannelStruct->ARINC429R_CLK));
	assert_param(IS_FUNCTIONAL_STATE(ARINC429R_InitChannelStruct->ARINC429R_LB));
	assert_param(IS_FUNCTIONAL_STATE(ARINC429R_InitChannelStruct->ARINC429R_SD));
	assert_param(IS_BIT_STATUS(ARINC429R_InitChannelStruct->ARINC429R_SDI1));
	assert_param(IS_BIT_STATUS(ARINC429R_InitChannelStruct->ARINC429R_SDI2));
	assert_param(IS_ARINC429R_DIV(ARINC429R_InitChannelStruct->ARINC429R_DIV));

	ARINC429Rx = MDR_ARINC429R;

	/* Set the speed of receiving data for specified ARINC429R_CHANNELx */
	tmpreg_CONTROL1 = ARINC429Rx->CONTROL1;
	tmpreg_CONTROL1 &= ~(1<<(ARINC429R_CONTROL1_CLK1_Pos + ARINC429R_CHANNELx));
	tmpreg_CONTROL1 |= ARINC429R_InitChannelStruct->ARINC429R_CLK << (ARINC429R_CONTROL1_CLK1_Pos + ARINC429R_CHANNELx);
	ARINC429Rx->CONTROL1 = tmpreg_CONTROL1;

	/* Set resolution tag detection and resolution decoding 9 and 10 data bits */
	tmpreg_CONTROL2 = ARINC429Rx->CONTROL2;
	tmpreg_CONTROL2 &= ~( (1<<(ARINC429R_CONTROL2_LB_EN1_Pos + ARINC429R_CHANNELx))\
						 |(1<<(ARINC429R_CONTROL2_SD_EN1_Pos + ARINC429R_CHANNELx)));
	tmpreg_CONTROL2 |= ( (ARINC429R_InitChannelStruct->ARINC429R_LB << (ARINC429R_CONTROL2_LB_EN1_Pos + ARINC429R_CHANNELx))\
					    |(ARINC429R_InitChannelStruct->ARINC429R_SD << (ARINC429R_CONTROL2_SD_EN1_Pos + ARINC429R_CHANNELx)));
	ARINC429Rx->CONTROL2 = tmpreg_CONTROL2;

	/* Set bit comparison SDI1 and bit comparison SDI2 */
	tmpreg_CONTROL3 = ARINC429Rx->CONTROL3;
	tmpreg_CONTROL3 &= ~( (1<<(ARINC429R_CONTROL3_SDI1_1_Pos +ARINC429R_CHANNELx))\
						 |(1<<(ARINC429R_CONTROL3_SDI2_1_Pos +ARINC429R_CHANNELx)));
	tmpreg_CONTROL3 |= ( (ARINC429R_InitChannelStruct->ARINC429R_SDI1 << (ARINC429R_CONTROL3_SDI1_1_Pos +ARINC429R_CHANNELx))\
						|(ARINC429R_InitChannelStruct->ARINC429R_SDI2 << (ARINC429R_CONTROL3_SDI2_1_Pos +ARINC429R_CHANNELx)));
	ARINC429Rx->CONTROL3 = tmpreg_CONTROL3;

	/* Set core frequency divider for frequency reference channel ARINC429R_CHANNELx */
	switch (ARINC429R_CHANNELx){
		case ARINC429R_CHANNEL1:
		case ARINC429R_CHANNEL2:
		case ARINC429R_CHANNEL3:
		case ARINC429R_CHANNEL4:
			tmpreg_CONTROL4 = ARINC429Rx->CONTROL4;
			tmpreg_CONTROL4 &= ~(0xFF<<(ARINC429R_CHANNELx*8));
			tmpreg_CONTROL4 |= ARINC429R_InitChannelStruct->ARINC429R_DIV << (ARINC429R_CHANNELx*8);
			ARINC429Rx->CONTROL4 = tmpreg_CONTROL4;
			break;
		case ARINC429R_CHANNEL5:
		case ARINC429R_CHANNEL6:
		case ARINC429R_CHANNEL7:
		case ARINC429R_CHANNEL8:
			tmpreg_CONTROL5 = ARINC429Rx->CONTROL5;
			tmpreg_CONTROL5 &= ~(0xFF<<((ARINC429R_CHANNELx - ARINC429R_CHANNEL5)*8));
			tmpreg_CONTROL5 |= ARINC429R_InitChannelStruct->ARINC429R_DIV << ((ARINC429R_CHANNELx - ARINC429R_CHANNEL5)*8);
			ARINC429Rx->CONTROL5 = tmpreg_CONTROL5;
			break;
#if defined (USE_MDR1986VE3)
		case ARINC429R_CHANNEL9:
		case ARINC429R_CHANNEL10:
		case ARINC429R_CHANNEL11:
		case ARINC429R_CHANNEL12:
			tmpreg_CONTROL6 = ARINC429Rx->CONTROL6;
			tmpreg_CONTROL6 &= ~(0xFF<<((ARINC429R_CHANNELx - ARINC429R_CHANNEL9)*8));
			tmpreg_CONTROL6 |= ARINC429R_InitChannelStruct->ARINC429R_DIV << ((ARINC429R_CHANNELx - ARINC429R_CHANNEL9)*8);
			ARINC429Rx->CONTROL6 = tmpreg_CONTROL6;
			break;
		case ARINC429R_CHANNEL13:
		case ARINC429R_CHANNEL14:
			tmpreg_CONTROL7 = ARINC429Rx->CONTROL7;
			tmpreg_CONTROL7 &= ~(0xFF<<((ARINC429R_CHANNELx - ARINC429R_CHANNEL13)*8));
			tmpreg_CONTROL7 |= ARINC429R_InitChannelStruct->ARINC429R_DIV << ((ARINC429R_CHANNELx - ARINC429R_CHANNEL13)*8);
			ARINC429Rx->CONTROL7 = tmpreg_CONTROL7;
			break;
#endif
	}
}

/**
  * @brief	Enables or disables the specified ARINC429R channel.
  * @param	ARINC429R_CHANNELx: Select the ARINC429R channel.
  *         This parameter can be one of the following values:
  *         	@arg ARINC429R_CHANNEL1
  *         	@arg ARINC429R_CHANNEL2
  *         	@arg ARINC429R_CHANNEL3
  *         	@arg ARINC429R_CHANNEL4
  *         	@arg ARINC429R_CHANNEL5
  *         	@arg ARINC429R_CHANNEL6
  *         	@arg ARINC429R_CHANNEL7
  *         	@arg ARINC429R_CHANNEL8
  *         	@note Available only for MC MDR1986BE3
  *         	@arg ARINC429R_CHANNEL9
  *         	@arg ARINC429R_CHANNEL10
  *         	@arg ARINC429R_CHANNEL11
  *         	@arg ARINC429R_CHANNEL12
  *         	@arg ARINC429R_CHANNEL13
  *         	@arg ARINC429R_CHANNEL14
  * @param	NewState: new state of the ARINC429R channel.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void ARINC429R_ChannelCmd(uint32_t ARINC429R_CHANNELx, FunctionalState NewState)
{
	MDR_ARINC429R_TypeDef * ARINC429Rx;

	/* Check the parameters */
	assert_param(IS_ARINC429R_CHANNEL(ARINC429R_CHANNELx));
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	ARINC429Rx = MDR_ARINC429R;

	if(NewState != DISABLE){
		/* Enable the selected ARINC429R channel by setting the CH_ENx bit in the CONTROL1 register */
		ARINC429Rx->CONTROL1 |= 1<<(ARINC429R_CONTROL1_CH_EN1_Pos + ARINC429R_CHANNELx);
	}
	else{
		/* Disable the selected ARINC429R channel by clearing the CH_ENx bit in the CONTROL1 register */
		ARINC429Rx->CONTROL1 &= ~(1<<(ARINC429R_CONTROL1_CH_EN1_Pos + ARINC429R_CHANNELx));
	}
}

/**
  * @brief	Enables or disables the specified ARINC429R interrupts.
  * @param	ARINC429R_IT: specifies the ARINC429R interrupt sources to be
  * 		enabled or disabled.
  * 		This parameter can be one of the following values:
  * 			@arg	ARINC429R_IT_INTEHF
  * 			@arg	ARINC429R_IT_INTEFF
  * 			@arg	ARINC429R_IT_INTEER
  * 			@arg	ARINC429R_IT_INTEDR
  * @param	NewState: new state of the specified ARINC429R interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void ARINC429R_ITConfig(uint32_t ARINC429R_IT, FunctionalState NewState)
{
	MDR_ARINC429R_TypeDef * ARINC429Rx;

	/* Check the parameters */
	assert_param(IS_ARINC429R_IT(ARINC429R_IT));
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	ARINC429Rx = MDR_ARINC429R;

	if(NewState != DISABLE){
		ARINC429Rx->CONTROL3 |= ARINC429R_IT;
	}
	else{
		ARINC429Rx->CONTROL3 &= ~(ARINC429R_IT);
	}
}

#if defined (USE_MDR1986VE1T)
/**
  * @brief	Enables or disables the specified ARINC429R interrupt mask.
  * @warning May be ususe only for MC MDR1986BE1T.
  * @param	ARINC429R_CHANNELx: Select the ARINC429R channel.
  *         This parameter can be one of the following values:
  *         	@arg ARINC429R_CHANNEL1
  *         	@arg ARINC429R_CHANNEL2
  *         	@arg ARINC429R_CHANNEL3
  *         	@arg ARINC429R_CHANNEL4
  *         	@arg ARINC429R_CHANNEL5
  *         	@arg ARINC429R_CHANNEL6
  *         	@arg ARINC429R_CHANNEL7
  *         	@arg ARINC429R_CHANNEL8
  * @param	ARINC429R_ITMask: pecifies the ARINC429R interrupt mask sources to be
  * 		enabled or disabled.
  * 		This parameter can be one of the following values:
  * 			@arg ARINC429R_ITMask_HF
  * 			@arg ARINC429R_ITMask_FF
  * 			@arg ARINC429R_ITMask_ER
  * 			@arg ARINC429R_ITMask_DR
  * @retval	None.
  */
void ARINC429R_ITMaskConfig(uint32_t ARINC429R_CHANNELx, uint32_t ARINC429R_ITMask, FunctionalState NewState)
{
	MDR_ARINC429R_TypeDef * ARINC429Rx;

	/* Check the parameters */
	assert_param(IS_ARINC429R_CHANNEL(ARINC429R_CHANNELx));
	assert_param(IS_ARINC429R_ITMask(ARINC429R_ITMask));
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	ARINC429Rx = MDR_ARINC429R;

	if(NewState != DISABLE){
		ARINC429Rx->INTMASK |= ARINC429R_ITMask << (4 * ARINC429R_CHANNELx);
	}
	else{
		ARINC429Rx->INTMASK &= ~(ARINC429R_ITMask << (4 * ARINC429R_CHANNELx));
	}
}
#endif

/**
  * @brief	Checks whether the specified ARINC429R flag is set or not.
  * @param	ARINC429R_CHANNELx: Select the ARINC429R channel.
  *         This parameter can be one of the following values:
  *         	@arg ARINC429R_CHANNEL1
  *         	@arg ARINC429R_CHANNEL2
  *         	@arg ARINC429R_CHANNEL3
  *         	@arg ARINC429R_CHANNEL4
  *         	@arg ARINC429R_CHANNEL5
  *         	@arg ARINC429R_CHANNEL6
  *         	@arg ARINC429R_CHANNEL7
  *         	@arg ARINC429R_CHANNEL8
  *         	@note Available only for MC MDR1986BE3
  *         	@arg ARINC429R_CHANNEL9
  *         	@arg ARINC429R_CHANNEL10
  *         	@arg ARINC429R_CHANNEL11
  *         	@arg ARINC429R_CHANNEL12
  *         	@arg ARINC429R_CHANNEL13
  *         	@arg ARINC429R_CHANNEL14
  * @param	ARINC429R_FLAG: specifies the flag to check.
  *         This parameter can be one of the following values:
  *         	@arg ARINC429R_FLAG_ERR
  *         	@arg ARINC429R_FLAG_DR
  *         	@arg ARINC429R_FLAG_HF
  *         	@arg ARINC429R_FLAG_FF
  * @retval	The state of ARINC429R_FLAG (SET or RESET).
  */
FlagStatus ARINC429R_GetFlagStatus(uint32_t ARINC429R_CHANNELx, uint32_t ARINC429R_FLAG)
{
	MDR_ARINC429R_TypeDef * ARINC429Rx;
	FlagStatus bitstatus;
	/* Check the parameters */
	assert_param(IS_ARINC429R_CHANNEL(ARINC429R_CHANNELx));
	assert_param(IS_ARINC429R_FLAG(ARINC429R_FLAG));

	ARINC429Rx = MDR_ARINC429R;

	switch(ARINC429R_FLAG){
		case ARINC429R_FLAG_DR:
			bitstatus = (ARINC429Rx->STATUS1 & (1 << (ARINC429R_STATUS1_DR1_Pos + ARINC429R_CHANNELx))) == 0 ? RESET : SET;
			break;
		case ARINC429R_FLAG_ERR:
			bitstatus = (ARINC429Rx->STATUS1 & (1 << (ARINC429R_STATUS1_ERR1_Pos + ARINC429R_CHANNELx))) == 0 ? RESET : SET;
			break;
		case ARINC429R_FLAG_HF:
			bitstatus = (ARINC429Rx->STATUS2 & (1 << (ARINC429R_STATUS2_HF1_Pos + ARINC429R_CHANNELx))) == 0 ? RESET : SET;
			break;
		case ARINC429R_FLAG_FF:
			bitstatus = (ARINC429Rx->STATUS2 & (1 << (ARINC429R_STATUS2_FF1_Pos + ARINC429R_CHANNELx))) == 0 ? RESET : SET;
			break;
		default:
			bitstatus = RESET;
			break;
	}
	return (bitstatus);
}

/**
  * @brief	Set the specified channel for the ARINC429R peripheral.
  * @param	ARINC429R_CHANNELx: Select the ARINC429R channel.
  *         This parameter can be one of the following values:
  *         	@arg ARINC429R_CHANNEL1
  *         	@arg ARINC429R_CHANNEL2
  *         	@arg ARINC429R_CHANNEL3
  *         	@arg ARINC429R_CHANNEL4
  *         	@arg ARINC429R_CHANNEL5
  *         	@arg ARINC429R_CHANNEL6
  *         	@arg ARINC429R_CHANNEL7
  *         	@arg ARINC429R_CHANNEL8
  *         	@note Available only for MC MDR1986BE3
  *         	@arg ARINC429R_CHANNEL9
  *         	@arg ARINC429R_CHANNEL10
  *         	@arg ARINC429R_CHANNEL11
  *         	@arg ARINC429R_CHANNEL12
  *         	@arg ARINC429R_CHANNEL13
  *         	@arg ARINC429R_CHANNEL14
  * @retval	None
  */
void ARINC429R_SetChannel(uint32_t ARINC429R_CHANNELx)
{
	MDR_ARINC429R_TypeDef * ARINC429Rx;
	/* Check the parameters */
	assert_param(IS_ARINC429R_CHANNEL(ARINC429R_CHANNELx));

	ARINC429Rx = MDR_ARINC429R;

	/* Set new channel */
	ARINC429Rx->CHANNEL = ARINC429R_CHANNELx;
}

/**
  * @brief	Get label of the specified channel ARINC429R peripheral, which
  * 		compares the first received 8 bits, if set LB_EN bit corresponding
  * 		to the specified channel.
  * @param	None
  * @retval Label of the specified channel ARINC429R peripheral.
  */
uint32_t ARINC429R_GetLabel(void)
{
	MDR_ARINC429R_TypeDef * ARINC429Rx;
	ARINC429Rx = MDR_ARINC429R;

	return (ARINC429Rx->LABEL);
}

/**
  * @brief	Set label of the specified channel ARINC429R peripheral, which
  * 		compares the first received 8 bits, if set LB_EN bit corresponding
  * 		to the specified channel.
  * @param	Label of the specified channel ARINC429R peripheral.
  * @retval None.
  */
void ARINC429R_SetLabel(uint8_t label)
{
	MDR_ARINC429R_TypeDef * ARINC429Rx;

	/* Check the parameters */
	assert_param(IS_ARINC429R_LABLE(label));


	ARINC429Rx = MDR_ARINC429R;

	ARINC429Rx->LABEL = label;
}

/**
  * @brief	Reads the received data from buffer.
  * @param	None
  * @retval The received data.
  */
uint32_t ARINC429R_ReceiveData(void)
{
	MDR_ARINC429R_TypeDef * ARINC429Rx;
	ARINC429Rx = MDR_ARINC429R;

	/* The received data */
	return (ARINC429Rx->DATA_R);
}


#if defined (USE_MDR1986VE1T)
/**
  * @brief	Reads the received data from individual buffer.
  * @note	May be ususe only for MC MDR1986BE1T.
  * @param	ARINC429R_CHANNELx: Select the ARINC429R channel.
  *         This parameter can be one of the following values:
  *         	@arg ARINC429R_CHANNEL1
  *         	@arg ARINC429R_CHANNEL2
  *         	@arg ARINC429R_CHANNEL3
  *         	@arg ARINC429R_CHANNEL4
  *         	@arg ARINC429R_CHANNEL5
  *         	@arg ARINC429R_CHANNEL6
  *         	@arg ARINC429R_CHANNEL7
  *         	@arg ARINC429R_CHANNEL8
  * @retval	The received data.
  */
uint32_t ARINC429R_ReceiveDataDirect(uint32_t ARINC429R_CHANNELx)
{
	uint32_t tmp_channel;
	uint32_t arinc_data;
	MDR_ARINC429R_TypeDef * ARINC429Rx;
	ARINC429Rx = MDR_ARINC429R;
	/* Check the parameters */
	assert_param(IS_ARINC429R_CHANNEL(ARINC429R_CHANNELx));

	/* Remember the previous value of the channel. */
	tmp_channel = ARINC429Rx->CHANNEL;
	/* Set the direct access to the FIFO for each channel. */
	ARINC429Rx->CHANNEL = 0x0E;
	/* Read the received data. */
	arinc_data = ARINC429Rx->DATA_R_Direct[ARINC429R_CHANNELx];
	/* Restore the channel value. */
	ARINC429Rx->CHANNEL = tmp_channel;

	return (arinc_data);
}
#endif

/** @} */ /* End of group ARINC429R_Private_Functions */

#endif /* #if defined (USE_MDR1986VE1T) || defined (USE_MDR1986VE3) */

/** @} */ /* End of group ARINC429R */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

/*
*
* END OF FILE MDR32F9Qx_arinc429r.c */
