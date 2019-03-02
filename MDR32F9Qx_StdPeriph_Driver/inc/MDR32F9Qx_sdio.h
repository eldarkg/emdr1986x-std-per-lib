/**
  * FILE MDR32F9Qx_sdio.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef MDR32F9QX_SDIO_H_
#define MDR32F9QX_SDIO_H_

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_config.h"

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @addtogroup SDIO
  * @{
  */

/** @defgroup SDIO_Exported_Types SDIO Exported Types
  * @{
  */
typedef struct
{
  FunctionalState WaitStartBitCmd;   	/*!< Specifies waiting or the formation of a start bit in the command line.
                                               This parameter can be: ENABLE or DISABLE. */

  FunctionalState WaitStartBitData;  	/*!< Specifies waiting or the formation of a start bit in the data lines.
                                           	   This parameter can be: ENABLE or DISABLE. */

  FunctionalState CRCCmd;  			/*!< Hardware CRC calculation on line CMD.
                                           	   This parameter can be: ENABLE or DISABLE. */

  FunctionalState CRCData; 			/*!< Hardware CRC calculation lines DAT3-DAT0.
                                           	   This parameter can be: ENABLE or DISABLE. */

  FunctionalState WriteCmd;       		/*!< Send a response to a write command 101b.
                                           	   This parameter can be: ENABLE or DISABLE. */

  FunctionalState EndBusy ;       		/*!< Puts BUSY on the line DAT0.
                                           	   This parameter can be: ENABLE or DISABLE. */

  uint32_t BusWide;              		/*!< Specifies the SDIO bus width.
                                           	   This parameter can be a value of @ref SDIO_BUS_WIDE */

  FunctionalState ClockOutput;			/*!< Enable or disable output clock signal.
                                           	    This parameter can be: ENABLE or DISABLE. */

  uint32_t ClockDiv;              		/*!< Specifies the clock frequency of the SDIO controller.
                                           	   This parameter can be a value of @ref SDIO_CLOCK_DIV */

} SDIO_InitTypeDef;

/** @} */ /* End of group SDIO_Exported_Types */

/** @defgroup SDIO_Exported_Macros SDIO Exported Macros
  * @{
  */

/** @defgroup SDIO_BUS_WIDE SDIO_BUS_WIDE
  * @{
  */

#define SDIO_BusWide_1b                     ((uint32_t)0x00000000)
#define SDIO_BusWide_4b                     ((uint32_t)0x00020000)

#define IS_SDIO_BUS_WIDE(WIDE) 				(((WIDE) == SDIO_BusWide_1b) ||\
 	 	 	 	 	 	 	 	 	 	 	 ((WIDE) == SDIO_BusWide_4b))

/** @} */ /* End of group SDIO_BUS_WIDE */

/** @defgroup SDIO_CLOCK_DIV SDIO_CLOCK_DIV
  * @{
  */

#define SDIO_CLOCK_DIV_1					((uint32_t)0 << SDIO_CR_BR_Pos)
#define SDIO_CLOCK_DIV_2					((uint32_t)1 << SDIO_CR_BR_Pos)
#define SDIO_CLOCK_DIV_4					((uint32_t)2 << SDIO_CR_BR_Pos)
#define SDIO_CLOCK_DIV_8					((uint32_t)3 << SDIO_CR_BR_Pos)
#define SDIO_CLOCK_DIV_16					((uint32_t)4 << SDIO_CR_BR_Pos)
#define SDIO_CLOCK_DIV_32					((uint32_t)5 << SDIO_CR_BR_Pos)
#define SDIO_CLOCK_DIV_64					((uint32_t)6 << SDIO_CR_BR_Pos)
#define SDIO_CLOCK_DIV_128					((uint32_t)7 << SDIO_CR_BR_Pos)

#define IS_SDIO_CLOCK_DIV(DIV)				(((DIV) & ~SDIO_CR_BR_Msk) == 0)

/** @} */ /* End of group SDIO_CLOCK_DIV */

/** @defgroup SDIO_IT SDIO_IT
  * @{
  */

#define SDIO_IT_TX_FIFO_DATA_EMPTY 			((uint32_t)SDIO_CR_TXEIE_DAT )
#define SDIO_IT_RX_FIFO_DATA_NOT_EMPTY		((uint32_t)SDIO_CR_RXNEIE_DAT)
#define SDIO_IT_RX_FIFO_DATA_FULL			((uint32_t)SDIO_CR_RXFIE_DAT )
#define SDIO_IT_TX_FIFO_CMD_EMPTY			((uint32_t)SDIO_CR_TXEIE_DAT )
#define SDIO_IT_RX_FIFO_CMD_EMPTY			((uint32_t)SDIO_CR_RXNEIE_CMD)
#define SDIO_IT_RX_FIFO_CMD_FULL			((uint32_t)SDIO_CR_RXFEIE_CMD)

#define SDIO_IT_MSK							(SDIO_IT_TX_FIFO_DATA_EMPTY		|\
                                             SDIO_IT_RX_FIFO_DATA_NOT_EMPTY	|\
                                             SDIO_IT_RX_FIFO_DATA_FULL		|\
                                             SDIO_IT_TX_FIFO_CMD_EMPTY		|\
                                             SDIO_IT_RX_FIFO_CMD_EMPTY		|\
                                             SDIO_IT_RX_FIFO_CMD_FULL)

#define IS_SDIO_IT(IT)						((IT&(~SDIO_IT_MSK) == 0) && (IT != 0))

/** @} */ /* End of group SDIO_IT */

/** @defgroup DATA_LINE_DIR DATA_LINE_DIR
  * @{
  */

#define SDIO_DATA_LINE_OUT					((uint32_t)SDIO_CR_DIRDATA)
#define SDIO_DATA_LINE_IN					((uint32_t)0x00000000)

#define IS_DATA_LINE_DIR(DIR)				((DIR == SDIO_DATA_LINE_OUT) ||\
											 (DIR == SDIO_DATA_LINE_IN))

/** @} */ /* End of group DATA_LINE_DIR */

/** @defgroup CMD_LINE_DIR CMD_LINE_DIR
  * @{
  */

#define SDIO_CMD_LINE_OUT					((uint32_t)SDIO_CR_DIRCMD)
#define SDIO_CMD_LINE_IN					((uint32_t)0x00000000)

#define IS_CMD_LINE_DIR(DIR)				((DIR == SDIO_CMD_LINE_OUT) ||\
											 (DIR == SDIO_CMD_LINE_IN))

/** @} */ /* End of group CMD_LINE_DIR */

/** @defgroup SDIO_FLAG SDIO_FLAG
  * @{
  */

#define SDIO_FLAG_CMD_TRANSFER_ACIVE		((uint32_t)SDIO_CR_WORK2)
#define SDIO_FLAG_DATA_TRANSFER_ACIVE       ((uint32_t)SDIO_CR_WORK1)
#define SDIO_FLAG_FIFO_CMD_EMPTY            ((uint32_t)SDIO_SR_FIFOCMD_EMPTY | 0x80000000)
#define SDIO_FLAG_FIFO_DAT_EMPTY            ((uint32_t)SDIO_SR_FIFODAT_EMPTY | 0x80000000)
#define SDIO_FLAG_FIFO_CMD_FULL             ((uint32_t)SDIO_SR_FIFOCMD_FULL  | 0x80000000)
#define SDIO_FLAG_FIFO_DAT_FULL             ((uint32_t)SDIO_SR_FIFODAT_FULL  | 0x80000000)

#define IS_SDIO_FLAG(FLAG)					((FLAG == SDIO_FLAG_CMD_TRANSFER_ACIVE  ) ||\
											 (FLAG == SDIO_FLAG_DATA_TRANSFER_ACIVE ) ||\
											 (FLAG == SDIO_FLAG_FIFO_CMD_EMPTY      ) ||\
											 (FLAG == SDIO_FLAG_FIFO_DAT_EMPTY      ) ||\
											 (FLAG == SDIO_FLAG_FIFO_CMD_FULL       ) ||\
											 (FLAG == SDIO_FLAG_FIFO_DAT_FULL       ))

/** @} */ /* End of group SDIO_FLAG */

/** @defgroup SDIO_DATA_LINE SDIO_DATA_LINE
  * @{
  */

#define SDIO_DATA_LINE_0					(0x00000000)
#define SDIO_DATA_LINE_1					(0x00000004)
#define SDIO_DATA_LINE_2					(0x00000008)
#define SDIO_DATA_LINE_3					(0x0000000C)

#define IS_SDIO_DATA_LINE(data_line)		((data_line == SDIO_DATA_LINE_0) ||\
											 (data_line == SDIO_DATA_LINE_1) ||\
											 (data_line == SDIO_DATA_LINE_2) ||\
											 (data_line == SDIO_DATA_LINE_3))

/** @} */ /* End of group SDIO_DATA_LINE */

/** @} */ /* End of group SDIO_Exported_Macros */

/** @defgroup SDIO_Exported_Functions SDIO Exported Functions
  * @{
  */

void SDIO_DeInit(void);
void SDIO_StructInit(SDIO_InitTypeDef * SDIO_InitStruct);
void SDIO_Init(SDIO_InitTypeDef * SDIO_InitStruct);
void SDIO_Cmd(FunctionalState NewState);
void SDIO_ItConfig(uint32_t SDIO_IT, FunctionalState NewState);
void SDIO_CMDTxCmd(FunctionalState NewSate);
void SDIO_DATATxCmd(FunctionalState NewSate);
void SDIO_SetDataLinesDirection(uint32_t data_direction);
void SDIO_SetCMDLineDirection(uint32_t cmd_direction);
void SDIO_SetBaudRatePrescaler(uint32_t prescaler);
FlagStatus SDIO_GetFlagStatus(uint32_t SDIO_FLAG);
void SDIO_SendCMD(uint32_t cmd);
void SDIO_SendData(uint32_t data);
uint32_t SDIO_ReceiveCMD(void);
uint32_t SDIO_ReceiveData(void);
void SDIO_ClearCMD_CRC(void);
void SDIO_ClearDataCRC(uint32_t data_bus_wide);
uint8_t SDIO_GetCRC_CMD(void);
uint16_t SDIO_GetDataCRC(uint32_t data_line);
void SDIO_SetCMDTransferNumberBit(uint32_t number_bit);
void SDIO_SetDATATransferNumberBit(uint32_t number_bit);
uint16_t SDIO_GetCMDTransferNumberBit(void);
uint16_t SDIO_GetDATATransferNumberBit(void);

/** @} */ /* End of group SDIO_Exported_Functions */

/** @} */ /* End of group SDIO */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

#endif /* MDR32F9QX_SDIO_H_ */

/*
*
* END OF FILE MDR32F9Qx_sdio.h */
