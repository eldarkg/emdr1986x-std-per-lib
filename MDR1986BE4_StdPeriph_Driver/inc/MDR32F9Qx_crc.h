/**
  * FILE MDR32F9Qx_crc.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef MDR32F9QX_CRC_H_
#define MDR32F9QX_CRC_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @addtogroup CRC CRC
  * @{
  */

/** @defgroup CRC_Exported_Types CRC Exported Types
  * @{
  */

/**
 * @brief CRC Init struct defintion
 */

typedef struct {

	uint32_t			CRC_DataSize;			/*!< Size of the data in the calculation of CRC.
	 	 	 	 	 	 	 	 	 	 	 	 	 This parameter can be a value of @ref CRC_Data_Size.*/

	uint32_t			CRC_DataLoadSize;		/*!< Size of loding data in the register DATAI.
	 	 	 	 	 	 	 	 	 	 	 	 	 This parameter can be a value of @ref CRC_DATA_LOAD_SIZE. */

	FunctionalState		CRC_DMARequestState;	/*!< Status for DMA request generation.
													This parameter can be a value of FunctionalState. */

	uint32_t 			CRC_EndianMode;			/*!< Order of computation of CRC.
													 This parameter can be a value of @ref CRC_Endian_Mode. */

	uint32_t 			CRC_Polynom;			/*!< Polynomial for CRC calculation.
													 This parameter can be a number between 0x10001 and 0x1FFFF. */

	uint32_t			CRC_StartValue;			/*!< Start value of the CRC calculation.
													 This parameter can be a number between 0x0000 and 0x1FFFF. */

}CRC_InitTypeDef;

/** @} */ /* End of group CRC_Exported_Types */

/** @defgroup CRC_Exported_Constants CRC Exported Constants
  * @{
  */

/** @defgroup CRC_Data_Size CRC Data Size
  * @{
  */

#define CRC_DATA_SIZE_8BIT					(uint32_t)(0x00000000)
#define CRC_DATA_SIZE_16BIT					(uint32_t)(0x00000020)
#define CRC_DATA_SIZE_32BIT					(uint32_t)(0x00000040)

#define IS_CRC_DATA_SIZE(DS)				((DS == CRC_DATA_SIZE_8BIT)  ||\
											 (DS == CRC_DATA_SIZE_16BIT) ||\
											 (DS == CRC_DATA_SIZE_32BIT))

/** @} */ /* End of group CRC_Data_Size */

/** @defgroup CRC_DATA_LOAD_SIZE CRC DATA LOAD SIZE
  * @{
  */

#define CRC_DATA_LOAD_SIZE_8BIT				(uint32_t)(0x00000000)
#define CRC_DATA_LOAD_SIZE_16BIT			(uint32_t)(0x00000008)
#define CRC_DATA_LOAD_SIZE_32BIT			(uint32_t)(0x00000010)

#define IS_CRC_DATA_LOAD_SIZE(DLS)			((DLS == CRC_DATA_LOAD_SIZE_8BIT)  ||\
											 (DLS == CRC_DATA_LOAD_SIZE_16BIT) ||\
											 (DLS == CRC_DATA_LOAD_SIZE_32BIT))

/** @} */ /* End of group CRC_DATA_LOAD_SIZE */

/** @defgroup CRC_Endian_Mode CRC Endian Mode
  * @{
  */

#define CRC_BIG_ENDIAN_MODE				(uint32_t)(0x000000002)
#define CRC_LITTLE_ENDIAN_MODE			(uint32_t)(0x000000000)

#define IS_CRC_ENDIAN_MODE(EM)			((EM == CRC_BIG_ENDIAN_MODE) ||\
										 (EM == CRC_LITTLE_ENDIAN_MODE))

/** @} */ /* End of group CRC_Endian_Mode */

/** @defgroup CRC_STATUS_FLAG CRC STATUS FLAG
  * @{
  */

#define CRC_FIFO_OVER					(uint32_t)(0x00000008)
#define CRC_FIFO_EMPTY					(uint32_t)(0x00000004)
#define CRC_FIFO_FULL					(uint32_t)(0x00000002)
#define CRC_CONV_COMP					(uint32_t)(0x00000001)

#define IS_CRC_STATUS_FLAG(SF)			((SF == CRC_FIFO_OVER)  ||\
										 (SF == CRC_FIFO_EMPTY) ||\
										 (SF == CRC_FIFO_FULL)  ||\
										 (SF == CRC_CONV_COMP))

/** @} */ /* End of group CRC_STATUS_FLAG */

/** @} */ /* End of group CRC_Exported_Constants */

/** @defgroup CRC_Exported_Functions CRC Exported Functions
  * @{
  */

void CRC_DeInit(void);
void CRC_Init(CRC_InitTypeDef * CRC_InitStruct);
void CRC_StructInit(CRC_InitTypeDef * CRC_InitStruct);
void CRC_Cmd(FunctionalState NewState);
void CRC_SetDataSize(uint32_t data_size);
void CRC_SetDataLoadSize(uint32_t data_load_size);
void CRC_DMARequestCmd(FunctionalState NewState);
void CRC_SetEndianMode(uint32_t endian_mode);
void CRC_SetPolynom(uint16_t polynom);
void CRC_SetStartValue(uint16_t start_value);
FlagStatus CRC_GetFlagStatus(uint32_t crc_flag);
void CRC_ClearFIFOOverFlag(void);
void CRC_WriteData(uint32_t data);
uint16_t CRC_GetCRC(void);

/** @} */ /* End of group CRC_Exported_Functions */

/** @} */ /* End of group CRC */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

#ifdef __cplusplus
} // extern "C" block end
#endif

#endif /* MDR32F9QX_CRC_H_ */

/*
*
* END OF FILE MDR32F9Qx_crc.h */
