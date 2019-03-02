/**
  * FILE MDR32F9Qx_sdio.c
  */

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_config.h"
#include "MDR32F9Qx_sdio.h"

#define ASSERT_INFO_FILE_ID FILEID__MDR32F9Qx_SDIO_C

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

#if defined (USE_MDR1901VC1T)

#define IS_SDIO_CMD_TRANSFER_NUMBER_BIT(NUMBER_BIT) 			((NUMBER_BIT & 0xFFFF) == 0)
#define IS_SDIO_DATA_TRANSFER_NUMBER_BIT(NUMBER_BIT) 			((NUMBER_BIT & 0xFFFF) == 0)
/**
 * @brief Resets the SDIO peripheral registers to their default reset values.
 */
void SDIO_DeInit(void)
{
	MDR_SDIO->CR           = 0;
	MDR_SDIO->SR           = 0;
	MDR_SDIO->CMDDR        = 0;
	MDR_SDIO->DATDR        = 0;
	MDR_SDIO->CMDCRC       = 0;
	MDR_SDIO->DAT0CRC      = 0;
	MDR_SDIO->DAT1CRC      = 0;
	MDR_SDIO->DAT2CRC      = 0;
	MDR_SDIO->DAT3CRC      = 0;
	MDR_SDIO->CMD_TRANSFER = 0;
	MDR_SDIO->DAT_TRANSFER = 0;
}


/**
 * @brief Fills each SDIO_InitStruct member with its default value.
 * @param SDIO_InitStruct: pointer to a SDIO_InitTypeDef structure
 *        that is to be initialized.
 */
void SDIO_StructInit(SDIO_InitTypeDef * SDIO_InitStruct)
{
	SDIO_InitStruct->WaitStartBitCmd 	= DISABLE;
	SDIO_InitStruct->WaitStartBitData 	= DISABLE;
	SDIO_InitStruct->CRCCmd 			= DISABLE;
	SDIO_InitStruct->CRCData 			= DISABLE;
	SDIO_InitStruct->WriteCmd 			= DISABLE;
	SDIO_InitStruct->EndBusy 			= DISABLE;
	SDIO_InitStruct->BusWide 			= SDIO_BusWide_1b;
	SDIO_InitStruct->ClockOutput 		= DISABLE;
	SDIO_InitStruct->ClockDiv 			= SDIO_CLOCK_DIV_1;
}

/**
 * @brief Initializes the SDIO peripheral according to the specified
 *        parameters in the SDIO_InitStruct.
 * @param SDIO_InitStruct: pointer to a SDIO_InitTypeDef structure
 *        that contains the configuration information for the specified SDIO peripheral.
 */
void SDIO_Init(SDIO_InitTypeDef * SDIO_InitStruct)
{
	/* Check the parameters */
	assert_param(IS_FUNCTIONAL_STATE(SDIO_InitStruct->WaitStartBitCmd));
	assert_param(IS_FUNCTIONAL_STATE(SDIO_InitStruct->WaitStartBitData));
	assert_param(IS_FUNCTIONAL_STATE(SDIO_InitStruct->CRCCmd));
	assert_param(IS_FUNCTIONAL_STATE(SDIO_InitStruct->CRCData));
	assert_param(IS_FUNCTIONAL_STATE(SDIO_InitStruct->WriteCmd));
	assert_param(IS_FUNCTIONAL_STATE(SDIO_InitStruct->EndBusy));
	assert_param(IS_SDIO_BUS_WIDE(SDIO_InitStruct->BusWide));
	assert_param(IS_FUNCTIONAL_STATE(SDIO_InitStruct->ClockOutput));
	assert_param(IS_SDIO_CLOCK_DIV(SDIO_InitStruct->ClockDiv));

	MDR_SDIO->CR = (SDIO_InitStruct->WaitStartBitCmd << SDIO_CR_SBITCMD_Pos  )|\
				   (SDIO_InitStruct->WaitStartBitData << SDIO_CR_SBITDAT_Pos )|\
				   (SDIO_InitStruct->CRCCmd << SDIO_CR_CRC_EN_CMD_Pos        )|\
				   (SDIO_InitStruct->CRCData << SDIO_CR_CRC_EN_DATA_Pos      )|\
				   (SDIO_InitStruct->WriteCmd << SDIO_CR_WRITECMD_Pos        )|\
				   (SDIO_InitStruct->EndBusy << SDIO_CR_ENDBUSY_Pos          )|\
				   (SDIO_InitStruct->BusWide << SDIO_CR_WIDTHDAT_Pos         )|\
				   (SDIO_InitStruct->ClockOutput << SDIO_CR_CLKOE_Pos        )|\
				   (SDIO_InitStruct->ClockDiv              					 );

}

/**
 * @brief Enables or disables the specified SDIO peripheral.
 * @param NewState: new state of the SDIO peripheral.
 *        This parameter can be: ENABLE or DISABLE.
 */
void SDIO_Cmd(FunctionalState NewState)
{
	/* Check the parameters */
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(NewState == ENABLE){
		MDR_SDIO->CR |= SDIO_CR_SDE;
	}
	else{
		MDR_SDIO->CR &= ~SDIO_CR_SDE;
	}
}

/**
 * @brief Enables or disables the specified SDIO interrupts.
 * @param SDIO_IT: specifies the SDIO interrupt sources to be enabled or disabled.
 *       	This parameter can be one of the following values:
 *       		@arg	SDIO_IT_TX_FIFO_DATA_EMPTY
 *       		@arg    SDIO_IT_RX_FIFO_DATA_NOT_EMPTY
 *       		@arg    SDIO_IT_RX_FIFO_DATA_FULL
 *       		@arg    SDIO_IT_TX_FIFO_CMD_EMPTY
 *       		@arg    SDIO_IT_RX_FIFO_CMD_EMPTY
 *       		@arg    SDIO_IT_RX_FIFO_CMD_FULL
 * @param NewState: new state of the specified SDIO interrupts.
 *       This parameter can be: ENABLE or DISABLE.
 */
void SDIO_ItConfig(uint32_t SDIO_IT, FunctionalState NewState)
{
	/* Check the parameters */
	assert_param(IS_SDIO_IT(SDIO_IT));
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(NewState == ENABLE){
		MDR_SDIO->CR |= SDIO_IT;
	}
	else{
		MDR_SDIO->CR &= ~SDIO_IT;
	}
}

/**
 * @brief Start or stop command transaction.
 * @param New state: new status of command transaction.
 *        This parameter can be: ENABLE or DISABLE.
 */
void SDIO_CMDTxCmd(FunctionalState NewSate)
{
	/* Check the parameters */
	assert_param(IS_FUNCTIONAL_STATE(NewSate));

	if(NewSate){
		MDR_SDIO->CR |= SDIO_CR_WORK2;
	}
	else{
		MDR_SDIO->CR &= ~SDIO_CR_WORK2;
	}
}

/**
 * @brief Start or stop data transaction.
 * @param New state: new status of data transaction.
 *        This parameter can be: ENABLE or DISABLE.
 */
void SDIO_DATATxCmd(FunctionalState NewSate)
{
	/* Check the parameters */
	assert_param(IS_FUNCTIONAL_STATE(NewSate));

	if(NewSate){
		MDR_SDIO->CR |= SDIO_CR_WORK1;
	}
	else{
		MDR_SDIO->CR &= ~SDIO_CR_WORK1;
	}
}

/**
 * @brief Set the data D0-D3 line direction.
 * @param data_direction: specifies the D0-D3 line direction.
 * 		  This paramet can be: DIO_DATA_LINE_OUT or DIO_DATA_LINE_IN.
 */
void SDIO_SetDataLinesDirection(uint32_t data_direction)
{
	/* Check the parameters */
	assert_param(IS_DATA_LINE_DIR(data_direction));

	if(data_direction == SDIO_DATA_LINE_OUT){
		MDR_SDIO->CR |= SDIO_CR_DIRDATA;
	}
	else{
		MDR_SDIO->CR &= ~SDIO_CR_DIRDATA;
	}
}

/**
 * @brief Set the CMD line direction.
 * @param cmd_direction: specifies the CMD line direction.
 * 		  This paramet can be: SDIO_CMD_LINE_OUT or SDIO_CMD_LINE_IN.
 */
void SDIO_SetCMDLineDirection(uint32_t cmd_direction)
{
	/* Check the parameters */
	assert_param(IS_CMD_LINE_DIR(cmd_direction));

	if(cmd_direction == SDIO_CMD_LINE_OUT){
		MDR_SDIO->CR |= SDIO_CR_DIRCMD ;
	}
	else{
		MDR_SDIO->CR &= ~SDIO_CR_DIRCMD;
	}
}

/**
 * @brief Initializes the SDIO peripheral clock according to the
 *        specified parameters.
 * @param prescaler: specifies the HCLK division factor.
 *        This parameter can be one of the following values:
 *        	@arg SDIO_CLOCK_DIV_1
 *        	@arg SDIO_CLOCK_DIV_2
 *        	@arg SDIO_CLOCK_DIV_4
 *        	@arg SDIO_CLOCK_DIV_8
 *        	@arg SDIO_CLOCK_DIV_16
 *        	@arg SDIO_CLOCK_DIV_32
 *        	@arg SDIO_CLOCK_DIV_64
 *        	@arg SDIO_CLOCK_DIV_128
 */
void SDIO_SetBaudRatePrescaler(uint32_t prescaler)
{
	uint32_t tmpreg;

	/* Check the parameters */
	assert_param(IS_SDIO_CLOCK_DIV(prescaler));

	/* Clear old prescaler */
	tmpreg = MDR_SDIO->CR & (~SDIO_CR_BR_Msk);

	/* Set new prescaler */
	tmpreg |= prescaler;

	/* Save new register value */
	MDR_SDIO->CR = tmpreg;
}

/**
 * @brief Checks whether the specified SDIO flag is set or not.
 * @param SDIO_FLAG: specifies the flag to check.
 *        This parameter can be one of the following values:
 *        	@arg SDIO_FLAG_CMD_TRANSFER_ACIVE
 *        	@arg SDIO_FLAG_DATA_TRANSFER_ACIVE
 *        	@arg SDIO_FLAG_FIFO_CMD_EMPTY
 *        	@arg SDIO_FLAG_FIFO_DAT_EMPTY
 *        	@arg SDIO_FLAG_FIFO_CMD_FULL
 *        	@arg SDIO_FLAG_FIFO_DAT_FULL
 * @return The new state of SDIO_FLAG (SET or RESET).
 */
FlagStatus SDIO_GetFlagStatus(uint32_t SDIO_FLAG)
{
	FlagStatus result;
	/* Check the parameters */
	assert_param(IS_SDIO_FLAG(SDIO_FLAG));

	if(SDIO_FLAG & 0x80000000){
		result = (FlagStatus)((SDIO_FLAG & MDR_SDIO->SR) != 0);
	}
	else{
		result = (FlagStatus)((SDIO_FLAG & MDR_SDIO->CR) != 0);
	}
	return (result);
}

/**
 *	@brief 	Write the command word into the SDIO CMD FIFO.
 *	@param	cmd: the transmitted command word.
 */
void SDIO_SendCMD(uint32_t cmd)
{

	/* Write cmd in SDIO FIFO CMD */
	MDR_SDIO->CMDDR = cmd;
}

/**
 *	@brief Write the data word into the SDIO DATA FIFO.
 *	@param data: the transmitted data word.
 */
void SDIO_SendData(uint32_t data)
{
	/* Write data iff SDIO FIFO DATA */
	MDR_SDIO->DATDR = data;
}

/**
 * @brief	Returns the most recent received command by the SDIO peripheral.
 * @brief	The received command.
 */
uint32_t SDIO_ReceiveCMD(void)
{
	return (MDR_SDIO->CMDDR);
}

/**
 * @brief	Returns the most recent received data by the SDIO peripheral.
 * @brief	The received data.
 */
uint32_t SDIO_ReceiveData(void)
{
	return (MDR_SDIO->DATDR);
}

/**
 * @brief Clear SDIO CRC command register.
 */
void SDIO_ClearCMD_CRC(void)
{
	MDR_SDIO->CMDCRC = 0;
}

/**
 * @brief Clear SDIO data register.
 * @param data_bus_wide: determines the width of the data bus.
 * 			This parameter can be one of the following values:
 * 				@arg:	SDIO_BusWide_1b
 * 				@arg:   SDIO_BusWide_4b
 */
void SDIO_ClearDataCRC(uint32_t data_bus_wide)
{
	/* Check the parameters */
	assert_param(IS_SDIO_BUS_WIDE(data_bus_wide));

	MDR_SDIO->DAT0CRC = 0;

	if(data_bus_wide == SDIO_BusWide_4b){
		MDR_SDIO->DAT1CRC = 0;
		MDR_SDIO->DAT2CRC = 0;
		MDR_SDIO->DAT3CRC = 0;
	}
}

/**
 * @brief 	Returns the calculated CRC data value.
 * @retval	CRC data value.
 */
uint8_t SDIO_GetCRC_CMD(void)
{
	return (MDR_SDIO->CMDCRC);
}

/**
 * @brief	Return the calculated CRC data for the specified number line.
 * @param 	data_line: specifies the data line number.
 * @retval	CRC value of the specified data line.
 */
uint16_t SDIO_GetDataCRC(uint32_t data_line)
{
	uint32_t * ptr_crc;
	/* Check the parameters */
	assert_param(IS_SDIO_DATA_LINE(data_line));

	/* Get pointer to the data line CRC register */
	ptr_crc = (uint32_t *)((uint32_t)&MDR_SDIO->DAT0CRC + data_line);

	return (*ptr_crc);
}

/**
 * @brief	Sets the number of bits that need to be transmitted/received
 * 			in the line of command.
 * @param	number_bit: the number bit to transfer.
 */
void SDIO_SetCMDTransferNumberBit(uint32_t number_bit)
{
	/* Check the parameters */
	assert_param(IS_SDIO_CMD_TRANSFER_NUMBER_BIT(number_bit));

	MDR_SDIO->CMD_TRANSFER = number_bit;
}

/**
 * @brief	Sets the number of bits that need to be transmitted/received
 * 			in the line of data.
 * @param	number_bit: the number bit to transfer.
 */
void SDIO_SetDATATransferNumberBit(uint32_t number_bit)
{
	/* Check the parameters */
	assert_param(IS_SDIO_DATA_TRANSFER_NUMBER_BIT(number_bit));

	MDR_SDIO->DAT_TRANSFER = number_bit;
}

/**
 * @brief	Gets the number of bits that need to be transmitted/received
 * 			in the line of command.
* @retval	Remaining number of bits that need to transmit / receive command line.
 */
uint16_t SDIO_GetCMDTransferNumberBit(void)
{
	return (MDR_SDIO->CMD_TRANSFER);
}

/**
 * @brief	Gets the number of bits that need to be transmitted/received
 * 			in the line of data.
 * @retval	Remaining number of bits that need to transmit / receive data line.
 */
uint16_t SDIO_GetDATATransferNumberBit(void)
{
	return (MDR_SDIO->DAT_TRANSFER);
}

#endif

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

/*
*
* END OF FILE MDR32F9Qx_sdio.c */
