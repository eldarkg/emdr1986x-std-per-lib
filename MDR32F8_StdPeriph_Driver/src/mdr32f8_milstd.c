/**
  ******************************************************************************
  * @file	 MDR32F9Qx_mil_std_1553.c
  * @author	 sidorov.a
  * @version V1.4.0
  * @date    28.03.2013
  * @brief   This file contains all the MIL_STD_1553 firmware functions.
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
  * FILE MDR32F9Qx_mil_std_1553.c
  */

/* Includes ------------------------------------------------------------------*/
#include "mdr32f8_milstd.h"
#include "mdr32f8_clkctrl.h"
#include "MDR1986VE8T.h"

#define ASSERT_INFO_FILE_ID FILEID__MDR32F9X_MIL_STD1553_C

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @defgroup MIL_STD_1553 MIL_STD_1553
 *  @warning This module can be used only for microcontrollers MDR1986VE1T and MDR1986VE3.
  * @{
  */


/** @defgroup MIL_STD_1553_Private_Defines MIL_STD_1553 Private Defines
  * @{
  */

#define MR_EN_Set			((uint32_t)0x00000001)	/*!< MIL_STD_1553 Enable mask */
#define MR_EN_Reset			((uint32_t)0x0000FFFE)	/*!< MIL_STD_1553 Disable mask */

#define IS_MIL_STD_1553_SUBADDRES(SUBADDRES)		( ((SUBADDRES) != 0) &&\
													  ((SUBADDRES) <= 0x1F) )

#define IS_MIL_STD_1553_NUMBER_DATA_WORDS(NUMBER_DATA_WORDS)	(((NUMBER_DATA_WORDS) != 0 ) &&\
																 ((NUMBER_DATA_WORDS) <=32))

/** @} */ /* End of group MIL_STD_1553_Private_Defines */

/** @defgroup MIL_STD_1553_Private_Functions MIL_STD_1553 Private Functions
  * @{
  */

/**
  * @brief  Initializes the UARTx peripheral Clock according to the
  *         specified parameters.
  * @param  UARTx: Select the UART peripheral.
  *         This parameter can be one of the following values:
  *         UART0.
  * @param  UART_BRG: specifies the HCLK division factor.
  *         This parameter can be one of the following values:
  *           @arg UART_CLKdiv1
  *           @arg UART_CLKdiv2
  *           @arg UART_CLKdiv4
  *           @arg UART_CLKdiv8
  * @retval None
  */
void MIL_STD_1553_CLK_en(MIL1553Control * MILx, uint32_t MIL_STD_1553_CLK_DIV)
{
  uint32_t tmpreg;
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
	assert_param(IS_UART_CLKSRC(UART_CLKSRC));
	
	if (MILx==MIL_STD_15531){

  tmpreg = CLK_CNTR->MIL0_CLK;

  tmpreg |=  MIL_STD_1553_CLK_EN;
  tmpreg &= ~MIL_STD_1553_DIV_Msk;
  tmpreg |=  MIL_STD_1553_CLK_DIV;

  CLK_CNTR->MIL0_CLK = tmpreg;
	}
	else if (MILx==MIL_STD_15532){

  tmpreg = CLK_CNTR->MIL1_CLK;

  tmpreg |=  MIL_STD_1553_CLK_EN;
  tmpreg &= ~MIL_STD_1553_DIV_Msk;
  tmpreg |=  MIL_STD_1553_CLK_DIV;

  CLK_CNTR->MIL1_CLK = tmpreg;
	}
	
}

/**
  * @brief	Reset the MIL_STD_1553x peripheral registers to their default reset values.
  * @param	MIL_STD_1553x: Slect the MIL_STD_1553 peripheral.
  *         This parameter can be one of the following values:
  *         MIL_STD_15531, MIL_STD_15532.
  * @retval	None
  */
void MIL_STD_1553_DeInit(MIL1553Control * MIL_STD_1553x)
{
	MIL_STD_1553x->CONTROL = 1;
	MIL_STD_1553x->INTEN = 0;
	MIL_STD_1553x->CommandWord1 = 0;
	MIL_STD_1553x->CommandWord2 = 0;
	MIL_STD_1553x->ModeData = 0;
	MIL_STD_1553x->StatusWord1 = 0;
	MIL_STD_1553x->StatusWord2 = 0;
}

/**
  * @brief	Initializes the MIL_STD_1553x peripheral according to the specified
  *         sparameters in the MIL_STD_1553_InitStruct.
  * @param	MIL_STD_1553x: Select the MIL_STD_1553 peripheral.
  *         This parameter can be one of the following values:
  *         MIL_STD_15531, MIL_STD_15532.
  * @param	MIL_STD_1553_InitStruct: pointer to a MIL_STD_1553_InitTypeDef structure
  *         that contains the configuration information for the specified MIL_STD_1553 peripheral.
  * @retval None
  */
void MIL_STD_1553_Init(MIL1553Control * MIL_STD_1553x, MIL_STD_1553_InitTypeDef * MIL_STD_1553_InitStruct)
{
	uint32_t tmpreg;

	/* Check the parameters */
	assert_param(IS_MIL_STD_1553_ALL_PERIPH(MIL_STD_1553x));
	assert_param(IS_MIL_STD_1553_MODE(MIL_STD_1553_InitStruct->MIL_STD_1553_Mode));
	assert_param(IS_MIL_STD_1553_DEVIDER(MIL_STD_1553_InitStruct->MIL_STD_1553_DIV));
	assert_param(IS_MIL_STD_1553_RTA(MIL_STD_1553_InitStruct->MIL_STD_1553_RTA));
	assert_param(IS_FUNCTIONAL_STATE(MIL_STD_1553_InitStruct->MIL_STD_1553_RERR));
	assert_param(IS_FUNCTIONAL_STATE(MIL_STD_1553_InitStruct->MIL_STD_1553_TRA));
	assert_param(IS_FUNCTIONAL_STATE(MIL_STD_1553_InitStruct->MIL_STD_1553_TRB));
#if defined (USE_MDR1986VE1T)
	assert_param(IS_FUNCTIONAL_STATE(MIL_STD_1553_InitStruct->MIL_STD_1553_Inversion_Signals));
	assert_param(IS_FUNCTIONAL_STATE(MIL_STD_1553_InitStruct->MIL_STD_1553_Filtration_Flow));
	assert_param(IS_FUNCTIONAL_STATE(MIL_STD_1553_InitStruct->MIL_STD_1553_Automatic_Adjustment));
#endif /* #if defined (USE_MDR1986VE1T) */

	/* MIL_STD_1553x CONTROL Configuration */
	tmpreg = (MIL_STD_1553_InitStruct->MIL_STD_1553_RERR << MIL_STD_1553_CONTROL_RERR_Pos)
		   | (MIL_STD_1553_InitStruct->MIL_STD_1553_Mode << MIL_STD_1553_CONTROL_BCMODE_Pos)
		   | (MIL_STD_1553_InitStruct->MIL_STD_1553_DIV << MIL_STD_1553_CONTROL_DIV_Pos)
		   | (MIL_STD_1553_InitStruct->MIL_STD_1553_RTA << MIL_STD_1553_CONTROL_RTA_Pos)
		   | (MIL_STD_1553_InitStruct->MIL_STD_1553_TRA << MIL_STD_1553_CONTROL_TRA_Pos)
		   | (MIL_STD_1553_InitStruct->MIL_STD_1553_TRB << MIL_STD_1553_CONTROL_TRB_Pos);

#if defined (USE_MDR1986VE1T)
	tmpreg |= MIL_STD_1553_InitStruct->MIL_STD_1553_Automatic_Adjustment << MIL_STD_1553_CONTROL_AUTOTUNE_Pos
		   |  MIL_STD_1553_InitStruct->MIL_STD_1553_Filtration_Flow << MIL_STD_1553_CONTROL_ENFILTER_Pos
		   |  MIL_STD_1553_InitStruct->MIL_STD_1553_Inversion_Signals << MIL_STD_1553_CONTROL_INVTR_Pos;
#endif /* #if defined (USE_MDR1986VE1T) */

	tmpreg |= MIL_STD_1553_CONTROL_MR;

	MIL_STD_1553x->CONTROL = tmpreg;
}

/**
  * @brief	Fills each MIL_STD_1553_InitStruct member with its default value.
  * @param	MIL_STD_1553_InitStruct: pointer to a MIL_STD_1553_InitTypeDef structure
  *         that is to be initialized.
  * @retval	None
  */
void MIL_STD_1553xStructInit(MIL_STD_1553_InitTypeDef * MIL_STD_1553_InitStruct)
{
	/* MIL_STD_1553_InitStruct members default value */
	/* Initialize the MIL_STD_1553_DIV member */
	MIL_STD_1553_InitStruct->MIL_STD_1553_DIV = 0;
	/* Initialize the MIL_STD_1553_Mode member */
	MIL_STD_1553_InitStruct->MIL_STD_1553_Mode = MIL_STD_1553_ModeTerminal;
	/* Initialize the MIL_STD_1553_RERR member */
	MIL_STD_1553_InitStruct->MIL_STD_1553_RERR = DISABLE;
	/* Initialize the MIL_STD_1553_RTA member */
	MIL_STD_1553_InitStruct->MIL_STD_1553_RTA = 0;
	/* Initialize the MIL_STD_1553_TRA member */
	MIL_STD_1553_InitStruct->MIL_STD_1553_TRA = DISABLE;
	/* Initialize the MIL_STD_1553_TRB member */
	MIL_STD_1553_InitStruct->MIL_STD_1553_TRB = DISABLE;
#if defined (USE_MDR1986VE1T)
	/* Initialize the MIL_STD_1553_Inversion_Signals member */
	MIL_STD_1553_InitStruct->MIL_STD_1553_Inversion_Signals = DISABLE;
	/* Initialize the MIL_STD_1553_Filtration_Flow member */
	MIL_STD_1553_InitStruct->MIL_STD_1553_Filtration_Flow = DISABLE;
	/* Initialize the MIL_STD_1553_Automatic_Adjustment member */
	MIL_STD_1553_InitStruct->MIL_STD_1553_Automatic_Adjustment = DISABLE;
#endif /* #if defined (USE_MDR1986VE1T) */
}

/**
  * @brief	Enables or disables the specified MIL_STD_1553 peripheral.
  * @param	MIL_STD_1553x: Select the MIL_STD_1553 peripheral.
  *         This parameter can be one of the following values:
  *         MIL_STD_15531, MIL_STD_15532.
  * @param  NewState: new state of the MIL_STD_1553x peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void MIL_STD_1553_Cmd(MIL1553Control * MIL_STD_1553x, FunctionalState NewState)
{
	/* Check the parameters */
	assert_param(IS_MIL_STD_1553_ALL_PERIPH(MIL_STD_1553x));
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(NewState == ENABLE){
		/* Enable the selected MIL_STD_1553 by clearingsetting the MR bit in the CONTROL register */
		MIL_STD_1553x->CONTROL &= ~MR_EN_Set;
	}
	else{
		/* Disable the selected MIL_STD_1553 by setting the MR bit in the CONTROL register */
		MIL_STD_1553x->CONTROL |= ~MR_EN_Reset;
	}
}

/**
  * @brief	Return the CommandWordX received by the MIL_STD_1553x peripher.
  * @param	MIL_STD_1553x: Select the MIL_STD_1553 peripheral.
  *         This parameter can be one of the following values:
  *         MIL_STD_15531, MIL_STD_15532.
  * @param	COMMAND_WORDx: Number of received the CommandWord.
  * 		This parameter can be one of the following values:
  * 			@arg MIL_STD_1553_COMMAND_WORD1
  * 			@arg MIL_STD_1553_COMMAND_WORD2
  * @retval	The received command word.
  */
uint32_t MIL_STD_1553_GetCommandWord(MIL1553Control * MIL_STD_1553x, uint32_t COMMAND_WORDx)
{
	/* Check the parameters */
	assert_param(IS_MIL_STD_1553_ALL_PERIPH(MIL_STD_1553x));
	assert_param(IS_MIL_STD_1553_COMMAND_WORD(COMMAND_WORDx));

	if (COMMAND_WORDx == MIL_STD_1553_COMMAND_WORD1) {
		return (MIL_STD_1553x->CommandWord1);
	}
	else {
		return (MIL_STD_1553x->CommandWord2);
	}
}

/**
  * @brief	Set the CommandWordX register for the specified MIL_STD_1553 peripheral.
  * @param	MIL_STD_1553x: Select the MIL_STD_1553 peripheral.
  *         This parameter can be one of the following values:
  *         MIL_STD_15531, MIL_STD_15532.
  * @param	COMMAND_WORDx: Number of the CommandWord.
  * 		This parameter can be one of the following values:
  * 			@arg MIL_STD_1553_COMMAND_WORD1
  * 			@arg MIL_STD_1553_COMMAND_WORD2
  * @param	CommandWord: pointer to a MIL_STD_1553_CommandWordTypeDef structure
  *         that contains the command information for the specified MIL_STD_1553 command register.
  * @retval	None
  */
void MIL_STD_1553_SetCommandWord(MIL1553Control * MIL_STD_1553x, uint32_t COMMAND_WORDx, MIL_STD_1553_CommandWordTypeDef * CommandWord)
{
	/* Check the parameters */
	assert_param(IS_MIL_STD_1553_ALL_PERIPH(MIL_STD_1553x));
	assert_param(IS_MIL_STD_1553_COMMAND_WORD(COMMAND_WORDx));

	if(COMMAND_WORDx == MIL_STD_1553_COMMAND_WORD1){
		MIL_STD_1553x->CommandWord1 = CommandWord->CommandWord;
	}
	else{
		MIL_STD_1553x->CommandWord2 = CommandWord->CommandWord;
	}
}

/**
  * @brief	Return the data word of management commands received by
  * 		the MIL_STD_1553x peripher.
	@param	MIL_STD_1553x: Select the MIL_STD_1553 peripheral.
  *         This parameter can be one of the following values:
  *         MIL_STD_15531, MIL_STD_15532.
  * @retval	The received ModeData.
  */
uint32_t MIL_STD_1553_GetModeData(MIL1553Control * MIL_STD_1553x)
{
	/* Check the parameters */
	assert_param(IS_MIL_STD_1553_ALL_PERIPH(MIL_STD_1553x));

	return (MIL_STD_1553x->ModeData);
}

/**
  * @brief	Returns the MSG register value of the specified MIL_STD_1553x peripheral.
  * @param	MIL_STD_1553x: Select the MIL_STD_1553 peripheral.
  *         This parameter can be one of the following values:
  *         MIL_STD_15531, MIL_STD_15532.
  * @retval	Returns code message received in the mode of the TD and M.
  */
uint32_t MIL_STD_1553_GetMSG(MIL1553Control * MIL_STD_1553x)
{
	/* Check the parameters */
	assert_param(IS_MIL_STD_1553_ALL_PERIPH(MIL_STD_1553x));

	return (MIL_STD_1553x->MSG);
}

/**
  * @brief	Set the StatusWordX register for the specified MIL_STD_1553 peripheral.
  * @param	MIL_STD_1553x: Select the MIL_STD_1553 peripheral.
  *         This parameter can be one of the following values:
  *         MIL_STD_15531, MIL_STD_15532.
  * @param	STATUS_WORDx: Number of the StatusWord.
  * 		This parameter can be one of the following values:
  * 			@arg MIL_STD_1553_STATUS_WORD1
  * 			@arg MIL_STD_1553_STATUS_WORD2
  * @param	StatusWord: pointer to a MIL_STD_1553_StatusWordTypeDef structure
  *         that contains the status information for the specified MIL_STD_1553 status register.
  * @retval	None
  */
void MIL_STD_1553_SetStatusWord(MIL1553Control * MIL_STD_1553x, uint32_t STATUS_WORDx, MIL_STD_1553_StatusWordTypeDef * StatusWord)
{
	/* Check the parameters */
	assert_param(IS_MIL_STD_1553_ALL_PERIPH(MIL_STD_1553x));
	assert_param(IS_MIL_STD_1553_STATUS_WORD(STATUS_WORDx));

	if(STATUS_WORDx == MIL_STD_1553_STATUS_WORD1){
		MIL_STD_1553x->StatusWord1 = StatusWord->StatusWord;
	}
	else{
		MIL_STD_1553x->StatusWord2 = StatusWord->StatusWord;
	}
}

/**
  * @brief	Returns th StatusWordx register value of the specified MIL_STD_1553x peripheral.
  * @param	MIL_STD_1553x: Select the MIL_STD_1553 peripheral.
  *         This parameter can be one of the following values:
  *         MIL_STD_15531, MIL_STD_15532.
  * @param	STATUS_WORDx: Number of the StatusWord.
  * 		This parameter can be one of the following values:
  * 			@arg MIL_STD_1553_STATUS_WORD1
  * 			@arg MIL_STD_1553_STATUS_WORD2
  * @retval	Return the StatusWordx register value.
  */
uint32_t MIL_STD_1553_GetStatusWord(MIL1553Control * MIL_STD_1553x, uint32_t STATUS_WORDx)
{
	/* Check the parameters */
	assert_param(IS_MIL_STD_1553_ALL_PERIPH(MIL_STD_1553x));
	assert_param(IS_MIL_STD_1553_STATUS_WORD(STATUS_WORDx));

	if(STATUS_WORDx == MIL_STD_1553_STATUS_WORD1){
		return (MIL_STD_1553x->StatusWord1);
	}
	else{
		return (MIL_STD_1553x->StatusWord2);
	}
}

/**
  * @brief	Return the Status register value of the specified MIL_STD_1553x peripheral.
  * @param	MIL_STD_1553x: Select the MIL_STD_1553 peripheral.
  *         This parameter can be one of the following values:
  *         MIL_STD_15531, MIL_STD_15532.
  * @retval STATUS.
  */
uint32_t MIL_STD_1553_GetStatus(MIL1553Control * MIL_STD_1553x)
{
	/* Check the parameters */
	assert_param(IS_MIL_STD_1553_ALL_PERIPH(MIL_STD_1553x));

	return (MIL_STD_1553x->STATUS);
}

/**
  * @brief	Checks whether the specified MIL_STD_1553 flag is set or not.
  * @param	MIL_STD_1553x: Select the MIL_STD_1553 peripheral.
  *         This parameter can be one of the following values:
  *         MIL_STD_15531, MIL_STD_15532.
  * @param	MIL_STD_1553_FLAG: specifies the flag to check.
  *         This parameter can be one of the following values:
  *         	@arg MIL_STD_1553_FLAG_IDLE
  *         	@arg MIL_STD_1553_FLAG_RFLAGN
  *         	@arg MIL_STD_1553_FLAG_VALMESS
  *         	@arg MIL_STD_1553_FLAG_ERR
  *         	@arg MIL_STD_1553_FLAG_RCVA
  *         	@arg MIL_STD_1553_FLAG_RCVB
  * @retval	The state of MIL_STD_1553_FLAG (SET or RESET).
  */
FlagStatus MIL_STD_1553_GetFlagStatus(MIL1553Control * MIL_STD_1553x, uint32_t MIL_STD_1553_FLAG)
{
	FlagStatus bitstatus;

	/* Check the parameters */
	assert_param(IS_MIL_STD_1553_ALL_PERIPH(MIL_STD_1553x));
	assert_param(IS_MIL_STD_1553_FLAG(MIL_STD_1553_FLAG));

	if (MIL_STD_1553x->STATUS & MIL_STD_1553_FLAG) {
		bitstatus = SET;
	}
	else {
		bitstatus = RESET;
	}

	return (bitstatus);
}

/**
  * @brief	Enables or disables the specified MIL_STD_1553x interrupts.
  * @param	MIL_STD_1553x: Select the MIL_STD_1553 peripheral.
  *         This parameter can be one of the following values:
  *         MIL_STD_15531, MIL_STD_15532.
  * @param	MIL_STD_1553_IT: specifies the MIL_STD_1553x interrupt sources to be
  * 		enabled or disabled.
  *         This parameter can be one of the following values:
  *         	@arg MIL_STD_1553_IT_IDLEIE
  *         	@arg MIL_STD_1553_IT_RFLAGNIE
  *         	@arg MIL_STD_1553_IT_VALMESSIE
  *         	@arg MIL_STD_1553_IT_ERRIE
  * @param  NewState: new state of the specified MIL_STD_1553x interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval	None
  */
void MIL_STD_1553_ITConfig(MIL1553Control * MIL_STD_1553x, uint32_t MIL_STD_1553_IT, FunctionalState NewState)
{
	/* Check the parameters */
	assert_param(IS_MIL_STD_1553_ALL_PERIPH(MIL_STD_1553x));
	assert_param(IS_MIL_STD_1553_IT(MIL_STD_1553_IT));
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(NewState != DISABLE){
		MIL_STD_1553x->INTEN |= MIL_STD_1553_IT;
	}
	else{
		MIL_STD_1553x->INTEN &= (~MIL_STD_1553_IT);
	}
}

/**
  * @brief	Reads the received data from buffer.
  * @param	MIL_STD_1553x: Select the MIL_STD_1553 peripheral.
  *         This parameter can be one of the following values:
  *         MIL_STD_15531, MIL_STD_15532.
  * @param	Subaddress: the number of the subaddress that is used for reception.
  * @param	NumberDataWords: the number of the data word to read.
  * @param	ptr_Dest: pointer to array to place received data to.
  * @retval None
  */
void MIL_STD_1553_ReceiveData(MIL1553Control * MIL_STD_1553x, uint32_t Subaddress, uint32_t NumberDataWords, uint32_t * ptr_Dest)
{
	uint32_t i;
	uint32_t *ptr_data;

	/* Check the parameters */
	assert_param(IS_MIL_STD_1553_ALL_PERIPH(MIL_STD_1553x));
	assert_param(IS_MIL_STD_1553_SUBADDRES(Subaddress));
	assert_param(IS_MIL_STD_1553_NUMBER_DATA_WORDS(NumberDataWords));

	ptr_data = (uint32_t *)((uint32_t)MIL_STD_1553x + sizeof(uint32_t)*Subaddress*32);

	if(NumberDataWords == 0)
		NumberDataWords = 32;

	for(i = 0; i < NumberDataWords; i++ ){
		ptr_Dest[i] = (uint16_t)ptr_data[i];
	}
}

/**
  * @brief	Writes data to the transmit buffer.
  * @param	MIL_STD_1553x: Select the MIL_STD_1553 peripheral.
  *         This parameter can be one of the following values:
  *         MIL_STD_15531, MIL_STD_15532.
  * @param	Subaddress: the number of the subaddress that is used for transmiting.
  * @param	NumberDataWords: the number of the data word to write.
  * @param	ptr_Src: pointer to the array from which the data is read.
  * @retval	None
  */
void MIL_STD_1553_WiteDataToSendBuffer(MIL1553Control * MIL_STD_1553x, uint32_t Subaddress, uint32_t NumberDataWords, uint32_t * ptr_Src)
{
	uint32_t i;
	uint32_t * ptr_data;

	/* Check the parameters */
	assert_param(IS_MIL_STD_1553_ALL_PERIPH(MIL_STD_1553x));
	assert_param(IS_MIL_STD_1553_SUBADDRES(Subaddress));
	assert_param(IS_MIL_STD_1553_NUMBER_DATA_WORDS(NumberDataWords));

	ptr_data = (uint32_t*)((uint32_t)MIL_STD_1553x + sizeof(uint32_t)*Subaddress*32);

	if(NumberDataWords == 0)
		NumberDataWords = 32;

	for(i = 0; i < NumberDataWords; i++){
		ptr_data[i] = (uint32_t)ptr_Src[i];
	}
}

/**
  * @brief	Initiates transmission of a message in the channel in the BC mode.
  * @param	MIL_STD_1553x: Select the MIL_STD_1553 peripheral.
  *         This parameter can be one of the following values:
  *         MIL_STD_15531, MIL_STD_15532.
  * @retval None
  */
void MIL_STD_1553_StartTransmision(MIL1553Control * MIL_STD_1553x)
{
	/* Check the parameters */
	assert_param(IS_MIL_STD_1553_ALL_PERIPH(MIL_STD_1553x));

	MIL_STD_1553x->CONTROL |= MIL_STD_1553_CONTROL_BCSTART;
}

/**
  * @brief	Enables or disables the specified MIL_STD_1553x transmitter.
  * @param	MIL_STD_1553x: Select the MIL_STD_1553 peripheral.
  *         This parameter can be one of the following values:
  *         MIL_STD_15531, MIL_STD_15532.
  * @param	TRANSMITTERx specifies the MIL_STD_1553 number transmitter.
  * 		This parameter can be one of the following values:
  * 			@arg MIL_STD_1553_TRANSMITTER_MAIN
  * 			@arg MIL_STD_1553_TRANSMITTER_RESERVE
  * @param	NewState: new state of the specified MIL_STD_1553x transmitter.
  * @retval	None
  */
void MIL_STD_1553_Transmitter_CMD(MIL1553Control * MIL_STD_1553x, uint32_t TRANSMITTERx, FunctionalState NewState)
{
	/* Check the parameters */
	assert_param(IS_MIL_STD_1553_ALL_PERIPH(MIL_STD_1553x));
	assert_param(IS_MIL_STD_1553_TRANSMITTER_CHANNEL(TRANSMITTERx));
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(NewState != DISABLE){
		MIL_STD_1553x->CONTROL |= TRANSMITTERx;
	}
	else{
		MIL_STD_1553x->CONTROL &= ~TRANSMITTERx;
	}
}

/**
  * @brief	Return the Error register value of the specified MIL_STD_1553x peripheral.
  * @param	MIL_STD_1553x: Select the MIL_STD_1553 peripheral.
  *         This parameter can be one of the following values:
  *         MIL_STD_15531, MIL_STD_15532.
  * @retval ERROR: the register's value.
  */
uint32_t MIL_STD_1553_GetErrorStatus(MIL1553Control * MIL_STD_1553x)
{
	/* Check the parameters */
	assert_param(IS_MIL_STD_1553_ALL_PERIPH(MIL_STD_1553x));

	return (MIL_STD_1553x->ERROR);
}

/**
  * @brief	Enable or disable RERR bit in the CONTROL register of the
  * 		specified MIL_STD_1553x periphera.
  * @param	MIL_STD_1553x: Select the MIL_STD_1553 peripheral.
  *         This parameter can be one of the following values:
  *         MIL_STD_15531, MIL_STD_15532.
  * @param	NewState: new state of the specified MIL_STD_1553x interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval	None
  */
void MIL_STD_1553_RERRCmd(MIL1553Control * MIL_STD_1553x, FunctionalState NewState)
{
	/* Check the parameters */
	assert_param(IS_MIL_STD_1553_ALL_PERIPH(MIL_STD_1553x));
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(NewState != DISABLE){
		MIL_STD_1553x->CONTROL |= MIL_STD_1553_CONTROL_RERR;
	}
	else{
		MIL_STD_1553x->CONTROL &= ~MIL_STD_1553_CONTROL_RERR;
	}
}

FlagStatus MIL_STD_1553_BCSTART_bit_stat(MIL1553Control * MIL_STD_1553x)
{
	FlagStatus bitstatus;
	
	if (MIL_STD_1553x->CONTROL & MIL_STD_1553_BCSTART) {
		bitstatus = SET;
	}
	else {
		bitstatus = RESET;
	}

	return (bitstatus);
}

/** @} */ /* End of group MIL_STD_1553_Private_Functions */

/** @} */ /* End of group MIL_STD_1553 */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

/******************* (C) COPYRIGHT 2013 Milandr ********************************
*
* END OF FILE MDR32F9Qx_mil_std_1553.c */
