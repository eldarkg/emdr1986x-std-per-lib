/**
  * FILE MDR32F9Qx_crc.c
  */

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_config.h"
#include "MDR32F9Qx_crc.h"

#define ASSERT_INFO_FILE_ID FILEID__MDR32F9Qx_CRC_C

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @addtogroup CRC CRC
  * @{
  */

/** @defgroup CRC_Private_Defines CRC Private Defines
  * @{
  */

#define IS_CRC_START_VALUE(SV)					((SV & (~CRC_VAL_CRCOUT_Msk)) == 0)
#define IS_CRC_POLYNOM(POL)						((POL & (~CRC_POL_CRC_POL_Msk)) == 0)

/** @} */ /* End of group CRC_Private_Defines */

/** @defgroup CRC_Private_Functions CRC Private Functions
  * @{
  */

/**
 * @brief	Resets the CRC peripheral registers to their default reset values.
 */
void CRC_DeInit(void)
{
	MDR_CRC->CTRL 	= 0;
	MDR_CRC->STAT 	= 4;
	MDR_CRC->VAL	= 0;
	MDR_CRC->POL	= 0;
}

/**
 * @brief	Initializes the CRC peripheral according to the specified
 *         parameters in the CRC_InitStruct.
 * @param 	CRC_InitStruct: pointer to a CRC_InitTypeDef structure
 *         that contains the configuration information for the specified CRC peripheral.
 */
void CRC_Init(CRC_InitTypeDef * CRC_InitStruct)
{
	/* Check the parameters */
	assert_param(IS_CRC_DATA_SIZE(CRC_InitStruct->CRC_DataSize));
	assert_param(IS_CRC_DATA_LOAD_SIZE(CRC_InitStruct->CRC_DataLoadSize));
	assert_param(IS_FUNCTIONAL_STATE(CRC_InitStruct->CRC_DMARequestState));
	assert_param(IS_CRC_ENDIAN_MODE(CRC_InitStruct->CRC_EndianMode));
	assert_param(IS_CRC_POLYNOM(CRC_InitStruct->CRC_Polynom));
	assert_param(IS_CRC_START_VALUE(CRC_InitStruct->CRC_StartValue));

	/* Set CRC CTRL register */
	MDR_CRC->CTRL = CRC_InitStruct->CRC_DataSize
				  | CRC_InitStruct->CRC_DataLoadSize
				  | (CRC_InitStruct->CRC_DMARequestState << CRC_CTRL_DMAEN_Pos)
				  | CRC_InitStruct->CRC_EndianMode;

	/* Set initial polynom */
	MDR_CRC->POL = CRC_InitStruct->CRC_Polynom | 0x10001;

	/* Set initial value */
	MDR_CRC->VAL = CRC_InitStruct->CRC_StartValue;
}

/**
 * @brief	Fills each CRC_InitStruct member with its default value.
 * @param 	CRC_InitStruct: pointer to a CRC_InitTypeDef structure
 *          that is to be initialized.
 */
void CRC_StructInit(CRC_InitTypeDef * CRC_InitStruct)
{
	CRC_InitStruct->CRC_DataSize 		= CRC_DATA_SIZE_8BIT;
	CRC_InitStruct->CRC_DataLoadSize 	= CRC_DATA_LOAD_SIZE_8BIT;
	CRC_InitStruct->CRC_DMARequestState = DISABLE;
	CRC_InitStruct->CRC_EndianMode 		= CRC_LITTLE_ENDIAN_MODE;
	CRC_InitStruct->CRC_Polynom			= 0;
	CRC_InitStruct->CRC_StartValue 		= 0;
}

/**
 * @brief	Enables or disables the specified CRC peripheral.
 * @param 	NewState: new state of the CRC peripheral.
 *          This parameter can be: ENABLE or DISABLE.
 */
void CRC_Cmd(FunctionalState NewState)
{
	/* Check the parameters */
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(NewState == ENABLE){
		MDR_CRC->CTRL |= CRC_CTRL_CRCEN;
	}
	else{
		MDR_CRC->CTRL &= ~CRC_CTRL_CRCEN;
	}
}

/**
 * @brief	Set the input data size.
 * @param 	data_size: the size of input data.
 * 			This parameter can be one of the following values:
 * 				@arg CRC_DATA_SIZE_8BIT
 * 				@arg CRC_DATA_SIZE_16BIT
 * 				@arg CRC_DATA_SIZE_32BIT
 */
void CRC_SetDataSize(uint32_t data_size)
{
	uint32_t tmpreg;

	/* Check the parameters */
	assert_param(IS_CRC_DATA_SIZE(data_size));

	/* Set data size */
	tmpreg = MDR_CRC->CTRL & (~CRC_CTRL_DCSIZE_Msk);
	tmpreg |= data_size;
	MDR_CRC->CTRL = tmpreg;
}

/**
 * @brief 	Set the load data size.
 * @param 	data_load_size: the size of loading data.
 *			This parameter can be one of the following values:
 *				@arg CRC_DATA_LOAD_SIZE_8BIT
 *				@arg CRC_DATA_LOAD_SIZE_16BI
 *				@arg CRC_DATA_LOAD_SIZE_32BI
 */
void CRC_SetDataLoadSize(uint32_t data_load_size)
{
	uint32_t tmpreg;

	/* Check the parameters */
	assert_param(IS_CRC_DATA_LOAD_SIZE(data_load_size));

	/* Set data load size */
	tmpreg = MDR_CRC->CTRL & (~CRC_CTRL_DLSIZE_Msk);
	tmpreg |= data_load_size;
	MDR_CRC->CTRL = tmpreg;
}

/**
 * @brief	Enables or disables the CRC DMA request.
 * @param 	NewState: new state of the CRC DMA request.
 *          This parameter can be: ENABLE or DISABLE.
 */
void CRC_DMARequestCmd(FunctionalState NewState)
{
	/* Check the parameters */
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(NewState == ENABLE){
		MDR_CRC->CTRL |= CRC_CTRL_DMAEN;
	}
	else{
		MDR_CRC->CTRL &= ~CRC_CTRL_DMAEN;
	}
}

/**
 * @brief	Set the endian mode.
 * @param 	endian_mode: new value of the CRC endian mode.
 */
void CRC_SetEndianMode(uint32_t endian_mode)
{
	/* Check the parameters */
	assert_param(IS_CRC_ENDIAN_MODE(endian_mode));

	if(endian_mode ==  CRC_BIG_ENDIAN_MODE){
		MDR_CRC->CTRL |= CRC_CTRL_DATAINV;
	}
	else{
		MDR_CRC->CTRL &= ~CRC_CTRL_DATAINV;
	}
}

/**
 * @brief	Set the CRC polynom.
 * @param 	polynom: new value of the CRC polynom.
 */
void CRC_SetPolynom(uint16_t polynom)
{
	/* Check the parameters */
	assert_param(IS_CRC_POLYNOM(polynom));

	MDR_CRC->POL = polynom | 0x10001;
}

/**
 * @brief	The initial value for CRC calculation.
 * @param 	start_value: the start CRC value.
 */
void CRC_SetStartValue(uint16_t start_value)
{
	/* Check the parameters */
	assert_param(IS_CRC_START_VALUE(start_value));

	MDR_CRC->VAL = start_value;
}

/**
 * @brief	Checks whether the specified CRC Status flag is set or not.
 * @param 	crc_flag: specifies the flag to check.
 * 			This parameter can be one of the following values:
 * 				@arg  CRC_FIFO_OVER
 * 				@arg  CRC_FIFO_EMPTY
 * 				@arg  CRC_FIFO_FULL
 * 				@arg  CRC_CONV_COMP
 * @return	Current Status flag state (SET or RESET).
 */
FlagStatus CRC_GetFlagStatus(uint32_t crc_flag)
{
	FlagStatus flag = RESET;

	/* Check the parameters */
	assert_param(IS_CRC_STATUS_FLAG(crc_flag));

	if(MDR_CRC->STAT & crc_flag){
		flag = SET;
	}
	return (flag);
}

/**
 * @brief	Clear the FIFO overloaded flag.
 */
void CRC_ClearFIFOOverFlag(void)
{
	MDR_CRC->STAT |= CRC_STAT_FIFOOVER;
}

/**
 * @brief	Write new data to CRC FIFO.
 * @param 	data: data value loaded into FIFO.
 */
void CRC_WriteData(uint32_t data)
{
	MDR_CRC->DATAI = data;
}

/**
 * @brief 	Returns the CRC result.
 * @return	CRC result register value.
 */
uint16_t CRC_GetCRC(void)
{
	return (MDR_CRC->VAL & 0xFFFF);
}

/** @} */ /* End of group CRC_Private_Functions */

/** @} */ /* End of group CRC */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

/*
*
* END OF FILE MDR32F9Qx_crc.c */
