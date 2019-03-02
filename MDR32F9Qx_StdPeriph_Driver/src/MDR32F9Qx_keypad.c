/**
  * FILE MDR32F9Qx_keypad.c
  */

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_config.h"
#include "MDR32F9Qx_keypad.h"

#define ASSERT_INFO_FILE_ID FILEID__MDR32F9Qx_KEYPAD_C

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @defgroup KEYPAD KEYPAD
  * @warning This module can be used only for MDR1986VE3 microcontrollers's.
  * @{
  */

/** @defgroup KEYPAD_Private_Constants KEYPAD Private Constants
  * @{
  */

/** @} */ /* End of group KEYPAD_Private_Constants */

/** @defgroup KEYPAD_Private_Defines KEYPAD Private Defines
  * @{
  */

/** @} */ /* End of group KEYPAD_Private_Defines */

/** @defgroup KEYPAD_Privat_Macros KEYPAD Privat Macros
  * @{
  */

/** @} */ /* End of group KEYPAD_Privat_Macros */

/** @defgroup KEYPAD_Private_Variables KEYPAD Private Variables
  * @{
  */

/** @} */ /* End of group KEYPAD_Private_Variables */

/** @defgroup KEYPAD_Private_FunctionPrototypes KEYPAD Private FunctionPrototypes
  * @{
  */

/** @} */ /* End of group KEYPAD_Private_FunctionPrototypes */

#if defined (USE_MDR1986VE3)

/** @defgroup KEYPAD_Private_Functions KEYPAD Private Functions
  * @{
  */

/**
  * @brief	Resets the MDR_KEYPAD peripheral registers to their default reset values.
  * @param	None.
  * @retval	None.
  */
void KEYPAD_DeInit(void)
{
	MDR_KEYPAD->KEYPAD_CR 		= 0;
	MDR_KEYPAD->KEYPAD_DR 		= 0;
	MDR_KEYPAD->KEYPAD_SWR[0] 	= 0;
	MDR_KEYPAD->KEYPAD_SWR[1] 	= 0;
	MDR_KEYPAD->KEYPAD_SWR[2] 	= 0;
	MDR_KEYPAD->KEYPAD_SWR[3] 	= 0;
}

/**
  * @brief	Initializes the KEYPAD peripheral clock according to the
  *         specified parameters.
  * @param	KEYPAD_BRG: specifies the HCLK division factor.
  *         This parameter can be one of the following values:
  *         	@arg: KEYPAD_BRG_4
  *         	@arg: KEYPAD_BRG_8
  *         	@arg: KEYPAD_BRG_16
  *         	@arg: KEYPAD_BRG_64
  *         	@arg: KEYPAD_BRG_128
  *         	@arg: KEYPAD_BRG_256
  *         	@arg: KEYPAD_BRG_512
  *         	@arg: KEYPAD_BRG_1024
  * @retval	None.
  */
void KEYPAD_BRGInit(uint32_t KEYPAD_BRG)
{
	uint32_t tmpreg;
	/* Check the parameters */
	assert_param(IS_KEYPAD_BRG(KEYPAD_BRG));

	tmpreg = MDR_KEYPAD->KEYPAD_CR;
	tmpreg &= ~KEYPAD_CR_KEY_PRE_Msk;
	tmpreg |= KEYPAD_BRG << KEYPAD_CR_KEY_PRE_Pos;

	MDR_KEYPAD->KEYPAD_CR = tmpreg;
}

/**
  * @brief	Fills each KEYPAD member with its default value.
  * @param  KEYPAD_InitStruct: pointer to a KEYPAD_InitTypeDef structure
  *         that is to be initialized.
  * @retval None.
  */
void KEYPAD_StructInit(KEYPAD_InitTypeDef * KEYPAD_InitStruct)
{
	KEYPAD_InitStruct->KeyRow 						= KEYPAD_KEY_ROW_1;
	KEYPAD_InitStruct->KeyColumn 					= KEYPAD_KEY_COLUMN_1;
	KEYPAD_InitStruct->InterruptState 				= DISABLE;
	KEYPAD_InitStruct->ContactChatteringState 		= DISABLE;
	KEYPAD_InitStruct->ContactChatteringTimer 		= KEYPAD_CONTACT_CHATTERING_TIMER_8_CYCLES;
	KEYPAD_InitStruct->SwitchesFieldScanState 		= DISABLE;
	KEYPAD_InitStruct->FirstColumnNumberSwitches	= KEYPAD_FIRST_COLUMN_NUMBER_SWITCHES_1;
	KEYPAD_InitStruct->DelayBetweenScansState 		= DISABLE;
	KEYPAD_InitStruct->DelayBetweenScansConfig 		= KEYPAD_DELAY_BETWEEN_SCANS_8_CYCLES;
}

/**
  * @brief	Initializes the KEYPAD peripheral according to the specified
  *         parameters in the KEYPAD_InitStruct.
  * @param	KEYPAD_InitStruct: pointer to a KEYPAD_InitTypeDef structure
  *         that contains the configuration information for the specified KEYPAD peripheral.
  * @retval None.
  */
void KEYPAD_Init(KEYPAD_InitTypeDef * KEYPAD_InitStruct)
{
	uint32_t tmpreg_keypad_cr;
	/* Check the parameters */
	assert_param(IS_KEYPAD_KEY_ROW(KEYPAD_InitStruct->KeyRow));
	assert_param(IS_KEYPAD_KEY_COLUMN(KEYPAD_InitStruct->KeyColumn));
	assert_param(IS_FUNCTIONAL_STATE(KEYPAD_InitStruct->InterruptState));
	assert_param(IS_FUNCTIONAL_STATE(KEYPAD_InitStruct->ContactChatteringState));
	assert_param(IS_KEYPAD_CONTACT_CHATTERING_TIMER_CYCLES(KEYPAD_InitStruct->ContactChatteringTimer));
	assert_param(IS_FUNCTIONAL_STATE(KEYPAD_InitStruct->SwitchesFieldScanState));
	assert_param(IS_KEYPAD_FIRST_COLUMN_NUMBER_SWITCHES(KEYPAD_InitStruct->FirstColumnNumberSwitches));
	assert_param(IS_KEYPAD_DELAY_BETWEEN_SCANS(KEYPAD_InitStruct->DelayBetweenScansConfig));

	/* */
	tmpreg_keypad_cr = MDR_KEYPAD->KEYPAD_CR & KEYPAD_CR_KEY_PRE_Msk;

	tmpreg_keypad_cr |= (KEYPAD_InitStruct->KeyRow << KEYPAD_CR_KEY_ROW_Pos)
					 | (KEYPAD_InitStruct->KeyColumn << KEYPAD_CR_KEY_COL_Pos)
					 | (KEYPAD_InitStruct->InterruptState
							 	 	 	 	 << KEYPAD_CR_KEY_IE_Pos)
					 | (KEYPAD_InitStruct->ContactChatteringState
							 	 	 	 	 << KEYPAD_CR_KEY_ENPCHAT_Pos)
					 | (KEYPAD_InitStruct->ContactChatteringTimer
							 	 	 	 	 << KEYPAD_CR_KEY_LTIM_Pos)
					 | (KEYPAD_InitStruct->SwitchesFieldScanState
							 	 	 	 	 << KEYPAD_CR_KEY_SWMEN_Pos)
					 | (KEYPAD_InitStruct->FirstColumnNumberSwitches
							 	 	 	 	 << KEYPAD_CR_KEY_SWCOL_Pos)
					 | (KEYPAD_InitStruct->DelayBetweenScansState
							 	 	 	 	 << KEYPAD_CR_KEY_IVEN_Pos)
					 | (KEYPAD_InitStruct->DelayBetweenScansConfig
							 	 	 	 	 << KEYPAD_CR_KEY_IVCONF_Pos);

	MDR_KEYPAD->KEYPAD_CR = tmpreg_keypad_cr;
}

/**
  * @brief	Enables or disables the specified KEYPAD peripheral.
  * @param	NewState: new state of the KEYPAD peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval	None.
  */
void KEYPAD_Cmd(FunctionalState NewState)
{
	/* Check the parameters */
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(NewState != DISABLE){
		MDR_KEYPAD->KEYPAD_CR |= KEYPAD_CR_KEY_EN;
	}
	else{
		MDR_KEYPAD->KEYPAD_CR &= ~KEYPAD_CR_KEY_EN;
	}
}

/**
  * @brief	Checks whether the specified KEYPAD flag is set or not.
  * @param	KEYPAD_FLAG: specifies the flag to check.
  *         This parameter can be one of the following values:
  *         	@arg: KEYPAD_FLAG_INTF
  *         	@arg: KEYPAD_FLAG_IPT1F
  *         	@arg: KEYPAD_FLAG_IPT2F
  *         	@arg: KEYPAD_FLAG_ERRF
  *         	@arg: KEYPAD_FLAG_SCF
  *         	@arg: KEYPAD_FLAG_PCHATF
  * @retval	The current state of KEYPAD_FLAG (SET or RESET).
  */
FlagStatus KEYPAD_GetFlagStatus(uint32_t KEYPAD_FLAG)
{
	FlagStatus bitstatus;

	/* Check the parameters */
	assert_param(IS_KEYPAD_FLAG(KEYPAD_FLAG));

	if(MDR_KEYPAD->KEYPAD_SR & KEYPAD_FLAG){
		bitstatus = SET;
	}
	else{
		bitstatus = RESET;
	}
	return (bitstatus);
}

/**
  * @brief	Clears the KEYPAD’s flag pending bits.
  * @param	KEYPAD_FLAG: specifies the flag pending bit to clear.
  *         This parameter can be one of the following values:
  *         	@arg: KEYPAD_FLAG_INTF
  *         	@arg: KEYPAD_FLAG_IPT1F
  *         	@arg: KEYPAD_FLAG_IPT2F
  *         	@arg: KEYPAD_FLAG_ERRF
  *         	@arg: KEYPAD_FLAG_SCF
  *         	@arg: KEYPAD_FLAG_PCHATF
  * @retval	None.
  */
void KEYPAD_ClearFlag(uint32_t KEYPAD_FLAG)
{
	/* Check the parameters */
	assert_param(IS_KEYPAD_FLAG(KEYPAD_FLAG));

	MDR_KEYPAD->KEYPAD_SR &= ~(KEYPAD_FLAG);
}

/**
  * @brief	Reads the code of the first key pressed.
  * @param	None.
  * @retval	Key of the first key pressed.
  */
uint32_t KEYPAD_GetPressedFirstKey(void)
{
	return (MDR_KEYPAD->KEYPAD_DR&0x7F);
}

/**
  * @brief	Reads the code of the second key pressed
  * @param	None.
  * @retval	Key of the second key pressed.
  */
uint32_t KEYPAD_GetPressedSecondKey(void)
{
	return ((MDR_KEYPAD->KEYPAD_DR&0x1F80)>>7);
}

/**
  * @brief	Checks the value of the specified switch.
  * @param	switch_number: the number of the switch.
  * @retval	Current state of the specified switch.
  */
BitStatus KEYPAD_GetSwitchStatus(uint32_t switch_number)
{
	FlagStatus bitstatus;
    /* FIXME unnecessary code */
	//uint32_t row, column, switch_col, bit_number;
    //
	///* Get number row in keyboard */
	//row = (MDR_KEYPAD->KEYPAD_CR & KEYPAD_CR_KEY_ROW_Msk) >> KEYPAD_CR_KEY_ROW_Pos;
	///* Get number column in keyboard */
	//column = (MDR_KEYPAD->KEYPAD_CR & KEYPAD_CR_KEY_COL_Msk) >> KEYPAD_CR_KEY_COL_Pos;
	///* Get number of the first switch in keyboard */
	//switch_col = (MDR_KEYPAD->KEYPAD_CR & KEYPAD_CR_KEY_SWCOL_Msk) >> KEYPAD_CR_KEY_SWCOL_Pos;
	///* Compute the bit posishion of the first switch */
	//bit_number = ((column - switch_col + 1)*(row + 1) - 1);

	/* Get the status of the requested switch */
	if(MDR_KEYPAD->KEYPAD_SWR[switch_number/32] & (1 << (switch_number%32))){
		bitstatus = SET;
	}
	else{
		bitstatus = RESET;
	}
	return  (bitstatus);
}

/**
  * @brief	Enables or disables the KEYPAD interrupt.
  * @param	NewState: new state of the KEYPAD interrupt.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval	None.
  */
void KEYPAD_ITCmd(FunctionalState NewState)
{
	/* Check the parameters */
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(NewState != DISABLE){
		MDR_KEYPAD->KEYPAD_CR |= KEYPAD_CR_KEY_IE;
	}
	else{
		MDR_KEYPAD->KEYPAD_CR &= ~KEYPAD_CR_KEY_IE;
	}
}

/** @} */ /* End of group KEYPAD_Private_Functions */

#endif

/** @} */ /* End of group KEYPAD */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

/*
*
* END OF FILE MDR32F9Qx_keypad.c */
