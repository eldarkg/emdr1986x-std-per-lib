/**
  ******************************************************************************
  * @file	 MDR32F9Qx_arinc429t.c
  * @author	 sidorov.a
  * @version V1.4.0
  * @date    15.04.2013
  * @brief   This file contains all the ARINC429T firmware functions.
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
  * FILE MDR32F9Qx_arinc429t.c
  */

/* Includes ------------------------------------------------------------------*/
#include "mdr32f8_arinc_tx.h"
#include "MDR1986VE8T.h"

#define ASSERT_INFO_FILE_ID FILEID__MDR32F9X_ARINC429T_C

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @defgroup ARINC429T ARINC429T
 * 	@warning This module can be used only for microcontrollers
 * 	MDR1986VE1T and MDR1986VE3.
  * @{
  */



/** @defgroup ARINC429T_Private_Defines ARINC429T Private Defines
  * @{
  */

#define IS_ARINC429T_DIV_CH(DIV_CH)			((DIV_CH) <=0xFF )

/** @} */ /* End of group ARINC429T_Private_Defines */

/** @defgroup ARINC429T_Private_Functions ARINC429T Private Functions
  * @{
  */

/**
  * @brief	Initializes the ARINC429T peripheral Clock according to the
  *         specified parameters.
  * @param	ARINC429T_BRG: specifies the HCLK division factor.
  * 		This parameter is number from 0 to 0x7F.
  * @retval None
  */
void ARINC429T_BRG_Init(uint32_t ARINC429T_BRG)
{
	ARINC429TControl * ARINC429Tx;
	uint32_t tmpreg_CONTROL1;

	/* Check the parameters */
	assert_param(IS_ARINC429T_HCLKdiv(ARINC429T_BRG));

	ARINC429Tx = ARINC429T1;

	tmpreg_CONTROL1 = ARINC429Tx->CONTROL1;
	tmpreg_CONTROL1 &= ~ARINC429T_HCLKdiv_MASK;
	tmpreg_CONTROL1 |= (ARINC429T_BRG << ARINC429T_CONTROL1_DIV_Pos);

	ARINC429Tx->CONTROL1 = tmpreg_CONTROL1;
}

/**
  * @brief	Reset the ARINC429T peripheral registers to their default reset values.
  * @param	None
  * @retval	None
  */
void ARINC429T_DeInit(void)
{
	ARINC429TControl * ARINC429Tx;

	ARINC429Tx = ARINC429T1;

	ARINC429Tx->CONTROL1 = 0;
	ARINC429Tx->CONTROL2 = 0;
	ARINC429Tx->CONTROL3 = 0;
    ARINC429Tx->CONTROL4 = 0;
	ARINC429Tx->STATUS = 0;
}

/**
  * @brief	Initializes the ARINC429T channelx peripheral according to the specified
  *         sparameters in the ARINC429T_InitChannelStruct.
  * @param	ARINC429T_CHANNELx: Slect the ARINC429T channel.
  * 		This parameter can be one of the following values:
  * 			@arg ARINC429T_CHANNEL1
  * 			@arg ARINC429T_CHANNEL2
  * 			@arg ARINC429T_CHANNEL3
  * 			@arg ARINC429T_CHANNEL4
  * @param	ARINC429T_InitChanelStruct: pointer to a ARINC429T_InitChannelTypeDef structure
  *         that contains the configuration information for the specified ARINC429T channel.
  * @retval	None
  */
void ARINC429T_ChannelInit(uint32_t ARINC429T_CHANNELx, ARINC429T_InitChannelTypeDef * ARINC429T_InitChanelStruct)
{
	ARINC429TControl * ARINC429Tx;
	uint32_t tmpreg_CONTROL1;
	uint32_t tmpreg_CONTROL2;
	uint32_t tmpreg_CONTROL3;
    uint32_t tmpreg_CONTROL4;

	/* Check the parameters */
	assert_param(IS_ARINC429T_CHANNEL(ARINC429T_CHANNELx));
	assert_param(IS_ARINC429T_CLK(ARINC429T_InitChanelStruct->ARINC429T_CLK));
	assert_param(IS_ARINC429T_DIV_CH(ARINC429T_InitChanelStruct->ARINC429T_DIV));
	assert_param(IS_FUNCTIONAL_STATE(ARINC429T_InitChanelStruct->ARINC429T_EN_PAR));
	assert_param(IS_ARINC429T_ODD(ARINC429T_InitChanelStruct->ARINC429T_ODD));
    assert_param(IS_FUNCTIONAL_STATE(ARINC429T_InitChanelStruct->ARINC429T_EN_SYNC));
	
    ARINC429Tx = ARINC429T1;

	tmpreg_CONTROL3 = ARINC429Tx->CONTROL3;
	tmpreg_CONTROL3 &= ~(0xFF << (ARINC429T_CHANNELx*8));
	tmpreg_CONTROL3 |= (ARINC429T_InitChanelStruct->ARINC429T_DIV << (ARINC429T_CHANNELx*8));
	ARINC429Tx->CONTROL3 = tmpreg_CONTROL3;

	tmpreg_CONTROL4 = ARINC429Tx->CONTROL4;
	tmpreg_CONTROL4 &= ~(0x01 << (ARINC429T_CHANNELx));
	tmpreg_CONTROL4 |= (ARINC429T_InitChanelStruct->ARINC429T_ENSYNC << (ARINC429T_CHANNELx));
	ARINC429Tx->CONTROL4 = tmpreg_CONTROL4;


	switch(ARINC429T_CHANNELx){
		case ARINC429T_CHANNEL1:
		case ARINC429T_CHANNEL2:
			tmpreg_CONTROL1 = ARINC429Tx->CONTROL1;
			tmpreg_CONTROL1 &= ~( (1 << (ARINC429T_CONTROL1_CLK1_Pos + ARINC429T_CHANNELx*4))\
							     |(1 << (ARINC429T_CONTROL1_EN_PAR1_Pos + ARINC429T_CHANNELx*4))\
							     |(1 << (ARINC429T_CONTROL1_ODD1_Pos + ARINC429T_CHANNELx*4)));
			tmpreg_CONTROL1 |= ((ARINC429T_InitChanelStruct->ARINC429T_CLK << (ARINC429T_CONTROL1_CLK1_Pos + ARINC429T_CHANNELx*4))\
							     |(ARINC429T_InitChanelStruct->ARINC429T_EN_PAR << (ARINC429T_CONTROL1_EN_PAR1_Pos + ARINC429T_CHANNELx*4))\
							     |(ARINC429T_InitChanelStruct->ARINC429T_ODD << (ARINC429T_CONTROL1_ODD1_Pos + ARINC429T_CHANNELx*4)));
			ARINC429Tx->CONTROL1 = tmpreg_CONTROL1;
			break;
		case ARINC429T_CHANNEL3:
		case ARINC429T_CHANNEL4:
			tmpreg_CONTROL2 = ARINC429Tx->CONTROL2;
			tmpreg_CONTROL2 &= ~( (1 << (ARINC429T_CONTROL2_CLK3_Pos + (ARINC429T_CHANNELx - ARINC429T_CHANNEL3)*4))\
							     |(1 << (ARINC429T_CONTROL1_EN_PAR1_Pos + (ARINC429T_CHANNELx - ARINC429T_CHANNEL3)*4))\
							     |(1 << (ARINC429T_CONTROL1_ODD1_Pos + (ARINC429T_CHANNELx - ARINC429T_CHANNEL3)*4)));
			tmpreg_CONTROL2 |= ((ARINC429T_InitChanelStruct->ARINC429T_CLK << (ARINC429T_CONTROL1_CLK1_Pos + (ARINC429T_CHANNELx - ARINC429T_CHANNEL3)*4))\
							     |(ARINC429T_InitChanelStruct->ARINC429T_EN_PAR << (ARINC429T_CONTROL1_EN_PAR1_Pos + (ARINC429T_CHANNELx - ARINC429T_CHANNEL3)*4))\
							     |(ARINC429T_InitChanelStruct->ARINC429T_ODD << (ARINC429T_CONTROL1_ODD1_Pos + (ARINC429T_CHANNELx - ARINC429T_CHANNEL3)*4)));
			ARINC429Tx->CONTROL2 = tmpreg_CONTROL2;
			break;
	}
}

/**
  * @brief	Enables or disables the specified ARINC429T channel.
  * @param	ARINC429T_CHANNELx: Slect the ARINC429T channel.
  * 		This parameter can be one of the following values:
  * 			@arg ARINC429T_CHANNEL1
  * 			@arg ARINC429T_CHANNEL2
  * 			@arg ARINC429T_CHANNEL3
  * 			@arg ARINC429T_CHANNEL4
  * @param	NewState: new state of the ARINC429T channel.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void ARINC429T_ChannelCmd(uint32_t ARINC429T_CHANNELx, FunctionalState NewState)
{
	ARINC429TControl * ARINC429Tx;

	/* Check the parameters */
	assert_param(IS_ARINC429T_CHANNEL(ARINC429T_CHANNELx));
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	ARINC429Tx = ARINC429T1;

	if(NewState != DISABLE){
		if(ARINC429T_CHANNELx <= ARINC429T_CHANNEL2)
			ARINC429Tx->CONTROL1 |= 1 << (ARINC429T_CONTROL1_CH_EN1_Pos + ARINC429T_CHANNELx*4);
		else
			ARINC429Tx->CONTROL2 |= 1 << (ARINC429T_CONTROL2_CH_EN3_Pos +(ARINC429T_CHANNELx - ARINC429T_CHANNEL3)*4);
	}
	else{
		if(ARINC429T_CHANNELx <= ARINC429T_CHANNEL2)
			ARINC429Tx->CONTROL1 &= ~(1 << (ARINC429T_CONTROL1_CH_EN1_Pos + ARINC429T_CHANNELx*4));
		else
			ARINC429Tx->CONTROL2 &= ~(1 << (ARINC429T_CONTROL2_CH_EN3_Pos +(ARINC429T_CHANNELx - ARINC429T_CHANNEL3)*4));
	}
}

/**
  * @brief	Enables or disables the specified ARINC429T interrupts
  * 		for the specifies channel.
  * @param	ARINC429T_CHANNELx: Slect the ARINC429T channel.
  * 		This parameter can be one of the following values:
  * 			@arg ARINC429T_CHANNEL1
  * 			@arg ARINC429T_CHANNEL2
  * 			@arg ARINC429T_CHANNEL3
  * 			@arg ARINC429T_CHANNEL4
  * @param	ARINC429T_IT: specifies the ARINC429T interrupt sources to be
  * 		enabled or disabled.
  * 		This parameter can be one of the following values:
  * 			@arg ARINC429T_IT_INTE_HTF
  * 			@arg ARINC429T_IT_INTE_TXR
  * 			@arg ARINC429T_IT_INTE_FFT
  * @param	NewState: new state of the specified ARINC429T interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval	None
  */
void ARINC429T_ITConfig(uint32_t ARINC429T_CHANNELx, uint32_t ARINC429T_IT, FunctionalState NewState)
{
	ARINC429TControl * ARINC429Tx;

	/* Check the parameters */
	assert_param(IS_ARINC429T_CHANNEL(ARINC429T_CHANNELx));
	assert_param(IS_ARINC429T_IT(ARINC429T_IT));
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	ARINC429Tx = ARINC429T1;

	if(NewState != DISABLE){
		if(ARINC429T_CHANNELx < ARINC429T_CHANNEL3)
			ARINC429Tx->CONTROL1 |= ARINC429T_IT << (ARINC429T_CONTROL1_INTE_FFT1_Pos + (ARINC429T_CHANNELx * 3));
		else
			ARINC429Tx->CONTROL2 |= ARINC429T_IT << (ARINC429T_CONTROL2_INTE_FFT3_Pos + ((ARINC429T_CHANNELx - ARINC429T_CHANNEL3) * 3));
	}else{
		if(ARINC429T_CHANNELx < ARINC429T_CHANNEL3)
			ARINC429Tx->CONTROL1 &= ~(ARINC429T_IT << (ARINC429T_CONTROL1_INTE_FFT1_Pos + (ARINC429T_CHANNELx * 3)));
		else
			ARINC429Tx->CONTROL2 &= ~(ARINC429T_IT << (ARINC429T_CONTROL2_INTE_FFT3_Pos + ((ARINC429T_CHANNELx - ARINC429T_CHANNEL3) * 3)));
	}
}

/**
  * @brief	Checks whether the specified ARINC429T flag is set or not.
  * @param	ARINC429T_CHANNELx: Slect the ARINC429T channel.
  * 		This parameter can be one of the following values:
  * 			@arg ARINC429T_CHANNEL1
  * 			@arg ARINC429T_CHANNEL2
  * 			@arg ARINC429T_CHANNEL3
  * 			@arg ARINC429T_CHANNEL4
  * @param	ARINC429T_FLAG: specifies the flag to check.
  *         This parameter can be one of the following values:
  *         	@arg ARINC429T_FLAG_TX_R
  *         	@arg ARINC429T_FLAG_FFT
  *         	@arg ARINC429T_FLAG_HFT
  * @retval	The state of ARINC429T_FLAG (SET or RESET).
  */
FlagStatus ARINC429T_GetFlagStatus(uint32_t ARINC429T_CHANNELx, uint32_t ARINC429T_FLAG)
{
	ARINC429TControl * ARINC429Tx;
	FlagStatus bitstatus;

	/* Check the parameters */
	assert_param(IS_ARINC429T_CHANNEL(ARINC429T_CHANNELx));
	assert_param(IS_ARINC429T_FLAG(ARINC429T_FLAG));

	ARINC429Tx = ARINC429T1;

	switch(ARINC429T_FLAG){
		case ARINC429T_FLAG_TX_R:
			bitstatus = (ARINC429Tx->STATUS & (1 << (ARINC429T_STATUS_TX_R1_Pos + ARINC429T_CHANNELx *3 + 2*(ARINC429T_CHANNELx >= ARINC429T_CHANNEL3)))) == 0 ? RESET : SET;
			break;
		case ARINC429T_FLAG_FFT:
			bitstatus = (ARINC429Tx->STATUS & (1 << (ARINC429T_STATUS_FFT1_Pos + ARINC429T_CHANNELx *3 + 2*(ARINC429T_CHANNELx >= ARINC429T_CHANNEL3)))) == 0 ? RESET : SET;
			break;
		case ARINC429T_FLAG_HFT:
			bitstatus = (ARINC429Tx->STATUS & (1 << (ARINC429T_STATUS_HFT1_Pos + ARINC429T_CHANNELx *3 + 2*(ARINC429T_CHANNELx >= ARINC429T_CHANNEL3)))) == 0 ? RESET : SET;
			break;
	}
	return (bitstatus);
}

/**
  * @brief	Transmits single data through the specified ARINC429T channel.
  * @param	ARINC429T_CHANNELx: Slect the ARINC429T channel.
  * 		This parameter can be one of the following values:
  * 			@arg ARINC429T_CHANNEL1
  * 			@arg ARINC429T_CHANNEL2
  * 			@arg ARINC429T_CHANNEL3
  * 			@arg ARINC429T_CHANNEL4
  * @param	Data: the data to transmit.
  * @retval	None
  */
void ARINC429T_SendData(uint32_t ARINC429T_CHANNELx, uint32_t Data )
{
	ARINC429TControl * ARINC429Tx;

	/* Check the parameters */
	assert_param(IS_ARINC429T_CHANNEL(ARINC429T_CHANNELx));

	ARINC429Tx = ARINC429T1;

	switch(ARINC429T_CHANNELx){
		case ARINC429T_CHANNEL1:
			ARINC429Tx->DATA1_T = Data;
			break;
		case ARINC429T_CHANNEL2:
			ARINC429Tx->DATA2_T = Data;
			break;
		case ARINC429T_CHANNEL3:
			ARINC429Tx->DATA3_T = Data;
			break;
		case ARINC429T_CHANNEL4:
			ARINC429Tx->DATA4_T = Data;
			break;
	}
}

/** @} */ /* End of group ARINC429T_Private_Functions */



/** @} */ /* End of group ARINC429T */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

/******************* (C) COPYRIGHT 2013 Milandr ********************************
*
* END OF FILE MDR32F9Qx_arinc429t.c */
