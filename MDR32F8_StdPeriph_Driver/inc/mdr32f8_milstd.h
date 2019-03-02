/**
  ******************************************************************************
  * @file	 MDR32F9Qx_mil_std_1553.h
  * @author	 sidorov.a
  * @version V1.4.0
  * @date    28.03.2013
  * @brief   This file contains all the functions prototypes for the
  * 		 MIL_STD_1553 firmware library.
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
  * FILE MDR32F9Qx_mil_std_1553.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef MDR32F9QX_MIL_STD_1553_H_
#define MDR32F9QX_MIL_STD_1553_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"	
#include "mdr32f8_config.h"
#include "MDR1986VE8T.h"	

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @addtogroup MIL_STD_1553
  * @{
  */

/** @defgroup MIL_STD_1553_Exported_Types MIL_STD_1553 Exported Types
  * @{
  */

/**
  * @brief	MIL_STD_1553 Init Structure definition
  */

typedef struct {
	uint32_t MIL_STD_1553_Mode; 					/*!< This member configures the MIL_STD_1553 mode.
										 	 	 	 	 This parameter is one of @ref MIL_STD_1553_Mode values. */
	uint32_t MIL_STD_1553_RERR;						/*!< This member configures the resetting of errors in TD mode.
	 	 	 	 	 	 	 	 	     	 	 	 	 This parameter can be: ENABLE or DISABLE. */
	uint32_t MIL_STD_1553_DIV;						/*!< This member configures the MIL_STD_1553 clock divider.
	 	 	 	 	 	 	 	 	 	 	 	 	 	 This parameter is number from 0 to 127.
	 	 	 	 	 	 	 	 	 	 	 	 	 	 If MAN_CLK not a multiple of 8 then DIV[6:3]=(MAN_CLK/8)+1, DIV[2:0]=0,
	 	 	 	 	 	 	 	 	 	 	 	 	 	 but the stability of reception is not guaranteed.*/
	uint32_t MIL_STD_1553_RTA; 						/*!< This member configures the address of the terminal device.
	 	 	 	 	 	 	 	 	 	 	 	 	 	 This parameter is value from 0 to 0x1E */
	uint32_t MIL_STD_1553_TRB;						/*!< This member configures the Transmission block the backup channel.
	 	 	 	 	 	 	 	 	 	 	 	 	 	 This parameter can be: ENABLE or DISABLE. */
	uint32_t MIL_STD_1553_TRA;						/*!< This member configures the Transmission block the main channel.
	 	 	 	 	 	 	 	 	 	 	 	 	 	 This parameter can be: ENABLE or DISABLE. */
#if defined (USE_MDR1986VE1T)
	/**
	 * @note This member may be used only for MDR1986VE1T microcontroller the third revision.
	 */
	FunctionalState	MIL_STD_1553_Inversion_Signals;		/*!< This member enables or disables the inversion signals
														 	 PRD_PRMA, PRD_PRMB, PRD_PRMC, PRD_PRMD.
														 	 This parameter can be: ENABLE or DISABLE. */
	FunctionalState MIL_STD_1553_Filtration_Flow;		/*!< This option enables or disables the filtering flow NRZ, in the case
	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 of drivers with nekkorektno duty cycle and pulse width of NRZ code.
	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 This parameter can be: ENABLE or DISABLE. */
	FunctionalState MIL_STD_1553_Automatic_Adjustment;	/*!< This member enables or disables the automatic adjustment of the mid bit intervals.
														 	 This parameter can be: ENABLE or DISABLE. */

#endif /* #if defined (USE_MDR1986VE1T) */
} MIL_STD_1553_InitTypeDef;

/**
  * @brief	Data Fields Union definition
  */

typedef union {
	uint32_t NumberDataWords	:5;		/*!< Specifies the number of data word in a message. */
	uint32_t Cmd				:5;		/*!< Specifies the command type.*/
} Data_FieldsTypeDef;

/**
  * @brief	MIL_STD_1553 CommandWord Bit Fields definition
  */
typedef struct {
	/*Data_FieldsTypeDef Data;*/			/*!< Specifies the number of data word in a message or command type.
											 This parameter is number from 0 to 0x1F. */
	uint32_t Data					:5;
	uint32_t Subaddress				:5;	/*!< Specifies the code subaddress OU or code attribute control mode 00000 or 11111.
											 This parameter is number from 0 to 0x1F. */
	uint32_t ReadWriteBit			:1;	/*!< Specifies the action to execute TD (receive or transmit DW).
											 This parameter is one of @ref MIL_STD_READ_WRITE_BIT values. */
	uint32_t TerminalDeviceAddress	:5;	/*!< Specifies the address of TD, which is intended CW.
											 This parameter is number from 0 to 0x1F. */
} MIL_STD_1553_CommandWordBitFields;

/**
  * @brief	MIL_STD_1553 CommandWord Unioun definition
  */
typedef union {
	uint32_t 							CommandWord;	/*!< Specifies the fully Command Word. */
	MIL_STD_1553_CommandWordBitFields	Fields;			/*!< Specifies the particular field of the Command Word.*/

} MIL_STD_1553_CommandWordTypeDef;

/**
  * @brief	MIL_STD_1553 StatusWord Bit Fields definition
  */
typedef struct {
	uint32_t	FaultTDBit					:1;	/*!< Specifies the fault terminal device.
													 This parameter can be: SET or RESET. */
	uint32_t	AdoptionControlInterfaceBit	:1;	/*!< Specifies the adoption control interface.
	 	 	 	 	 	 	 	 	 	 	 	     This parameter can be: SET or RESET. */
	uint32_t	AbonentFaultBit				:1;	/*!< Specifies the fault abonent.
													 This parameter can be: SET or RESET. */
	uint32_t	BusyBit						:1;	/*!< Specifies the busy abonent.
													 This parameter can be: SET or RESET. */
	uint32_t	GroupCommandBit				:1;	/*!< Specifies the group command.
													 This parameter can be: SET or RESET. */
	uint32_t	Reserved					:3;	/*!< Reserved */
	uint32_t	ServiceRequestBit			:1;	/*!< Specifies the service request.
													 This parameter can be: SET or RESET. */
	uint32_t	TransferReplyWordBit		:1;	/*!< Specifies the transfer replay word.
													 This parameter can be: SET or RESET. */
	uint32_t	ErrorBit					:1;	/*!< Specifies the error in the message.
													 This parameter can be: SET or RESET. */
	uint32_t 	TerminalDeviceAddress		:5;	/*!< Specifies the termnal device address.
													 This parameter is number from 0x00 to 0x1F. */
} MIL_STD_1553_StatusWordBitFields;

/**
  * @brief	MIL_STD_1553 StatusWord Structure definition
  */
typedef union {
	uint32_t	 						StatusWord;	/*!< Specifies the fully Status Word. */
	MIL_STD_1553_StatusWordBitFields	Fields;		/*!< Specifies the particular field of the Status Word. */
} MIL_STD_1553_StatusWordTypeDef;

/**
  * @brief	Bool Structure definition
  */

typedef enum {
	FALSE = 0,
	TRUE = !DISABLE
} Bool;

/** @} */ /* End of group MIL_STD_1553_Exported_Types */

/** @defgroup MIL_STD_1553_Exported_Macros MIL_STD_1553 Exported Macros
  * @{
  */

#define IS_MIL_STD_1553_ALL_PERIPH(PERIPH)		(((PERIPH) == MDR_MIL_STD_15531) ||\
												 ((PERIPH) == MDR_MIL_STD_15532))

#define IS_MIL_STD_1553_DEVIDER(DIVIDER)		((DIVIDER) <= 0x7F)

#define IS_MIL_STD_1553_RTA(RTA)				((RTA) <= 0x1F)

/** @defgroup MIL_STD_1553_Mode MIL_STD_1553 Mode
  * @{
  */

#define MIL_STD_1553_ModeBusController			((uint32_t)0x01)
#define MIL_STD_1553_ModeTerminal				((uint32_t)0x02)
#define MIL_STD_1553_ModeMonitor				((uint32_t)0x03)

#define IS_MIL_STD_1553_MODE(MODE)				(((MODE) == MIL_STD_1553_ModeBusController) ||\
												 ((MODE) == MIL_STD_1553_ModeMonitor)       ||\
												 ((MODE) == MIL_STD_1553_ModeTerminal))

/** @} */ /* End of group MIL_STD_1553_Mode */

/** @defgroup MIL_STD_READ_WRITE_BIT MIL_STD_READ_WRITE BIT
  * @{
  */

#define MIL_STD_1553_TD_TO_BC						((uint32_t)0x00000001)
#define MIL_STD_1553_BC_TO_TD						((uint32_t)0x00000000)

#define IS_MIL_STD_READ_WRITE_BIT(BIT)			(((BIT) == MIL_STD_1553_TD_TO_BC) || \
												 ((BIT) == MIL_STD_1553_BC_TO_TD))

/** @} */ /* End of group MIL_STD_READ_WRITE_BIT */



/** @defgroup MIL_STD_1553_Flags MIL_STD_1553 Flags
  * @{
  */

#define MIL_STD_1553_FLAG_IDLE					((uint32_t)0x00000001)
#define MIL_STD_1553_FLAG_RFLAGN				((uint32_t)0x00000002)
#define MIL_STD_1553_FLAG_VALMESS				((uint32_t)0x00000004)
#define MIL_STD_1553_FLAG_ERR					((uint32_t)0x00000008)
#define MIL_STD_1553_FLAG_RCVA					((uint32_t)0x00000010)
#define MIL_STD_1553_FLAG_RCVB					((uint32_t)0x00000020)

#define MIL_STD_1553_BCSTART					((uint32_t)0x00000002)

#define IS_MIL_STD_1553_FLAG(FLAG)				(((FLAG) == MIL_STD_1553_FLAG_IDLE) ||\
												 ((FLAG) == MIL_STD_1553_FLAG_RFLAGN) ||\
												 ((FLAG) == MIL_STD_1553_FLAG_VALMESS) ||\
												 ((FLAG) == MIL_STD_1553_FLAG_ERR) ||\
												 ((FLAG) == MIL_STD_1553_FLAG_RCVA) ||\
												 ((FLAG) == MIL_STD_1553_FLAG_RCVB))

/** @} */ /* End of group MIL_STD_1553_Flags */

/** @defgroup MIL_STD_1553_Interrupt_defintion MIL_STD_1553 Interrupt defintion
  * @{
  */

#define MIL_STD_1553_IT_IDLEIE          		((uint32_t)0x00000001)
#define MIL_STD_1553_IT_RFLAGNIE        		((uint32_t)0x00000002)
#define MIL_STD_1553_IT_VALMESSIE       		((uint32_t)0x00000004)
#define MIL_STD_1553_IT_ERRIE           		((uint32_t)0x00000008)

#define MIL_STD_1553_IT_MASK					(MIL_STD_1553_IT_IDLEIE |\
												 MIL_STD_1553_IT_RFLAGNIE |\
												 MIL_STD_1553_IT_VALMESSIE |\
												 MIL_STD_1553_IT_ERRIE)

#define IS_MIL_STD_1553_IT(IT)					((IT) & (~MIL_STD_1553_IT_MASK) == 0)

/*
#define IS_MIL_STD_1553_IT(IT)					(((IT) == MIL_STD_1553_IT_IDLEIE) ||\
												 ((IT) == MIL_STD_1553_IT_RFLAGNIE) ||\
												 ((IT) == MIL_STD_1553_IT_VALMESSIE) ||\
												 ((IT) == MIL_STD_1553_IT_ERRIE))
*/

/** @} */ /* End of group MIL_STD_1553_Interrupt_defintion */

/** @defgroup MIL_STD_1553_Number_CommandWord MIL_STD_1553 Number CommandWord
  * @{
  */

#define MIL_STD_1553_COMMAND_WORD1					((uint32_t)0x00000000)
#define MIL_STD_1553_COMMAND_WORD2					((uint32_t)0x00000001)

#define IS_MIL_STD_1553_COMMAND_WORD(COMMAND_WORD) 	((COMMAND_WORD) < 0x02)

/** @} */ /* End of group MIL_STD_1553_Number_CommandWord */

/** @defgroup MIL_STD_1553_Number_StatusWord MIL_STD_1553 Number StatusWord
  * @{
  */

#define MIL_STD_1553_STATUS_WORD1					((uint32_t)0x00000000)
#define MIL_STD_1553_STATUS_WORD2					((uint32_t)0x00000001)

#define IS_MIL_STD_1553_STATUS_WORD(STATUS_WORD) 	((STATUS_WORD) < 0x02)

/** @} */ /* End of group MIL_STD_1553_Number_StatusWord */

/** @defgroup MIL_STD_1553_Number_Transmitter MIL_STD_1553 Number Transmitter
  * @{
  */

#define MIL_STD_1553_TRANSMITTER_MAIN					((uint32_t)0x0000010)
#define MIL_STD_1553_TRANSMITTER_RESERVE				((uint32_t)0x0000020)

#define IS_MIL_STD_1553_TRANSMITTER_CHANNEL(CHANNEL)	(((CHANNEL) == MIL_STD_1553_TRANSMITTER_MAIN) ||\
													     ((CHANNEL) == MIL_STD_1553_TRANSMITTER_RESERVE))

/** @} */ /* End of group MIL_STD_1553_Number_Transmitter */

/** @defgroup MIL_STD_1553_Clock_BRG MIL_STD_1553 Clock BRG
  * @{
  */

#define MIL_STD_1553_HCLKdiv1					((uint32_t)0x00000000)
#define MIL_STD_1553_HCLKdiv2					((uint32_t)0x00000001)
#define MIL_STD_1553_HCLKdiv4					((uint32_t)0x00000002)
#define MIL_STD_1553_HCLKdiv8					((uint32_t)0x00000003)
#define MIL_STD_1553_HCLKdiv16					((uint32_t)0x00000004)
#define MIL_STD_1553_HCLKdiv32					((uint32_t)0x00000005)
#define MIL_STD_1553_HCLKdiv64					((uint32_t)0x00000006)
#define MIL_STD_1553_HCLKdiv128					((uint32_t)0x00000007)

#define IS_MIL_STD_1553_BRG(BRG)				((BRG) <= 7)

/** @} */ /* End of group MIL_STD_1553_Clock_BRG */

#define MIL_STD_1553_DIV_Msk        								 ((uint32_t)0x0000FFFF)
#define MIL_STD_1553_CLK_EN         								 (1<<16)
#define MIL_STD_1553_CLKSRC_msk                     ((uint32_t)0xF0000000) 
#define MIL_STD_1553_CLKSRC_offs                    28

#define MIL_STD_1553_CLKdiv1                        ((uint32_t)0x00000000)
#define MIL_STD_1553_CLKdiv2                        ((uint32_t)0x00000001)
#define MIL_STD_1553_CLKdiv4                        ((uint32_t)0x00000002)
#define MIL_STD_1553_CLKdiv8                        ((uint32_t)0x00000003)

/** @} */ /* End of group MIL_STD_1553_Exported_Macros */

/** @defgroup MIL_STD_1553_Exported_Constants MIL_STD_1553 Exported Constants
  * @{
  */
/** @} */ /* End of group MIL_STD_1553_Exported_Constants */

/** @defgroup MIL_STD_1553_Exported_Functions MIL_STD_1553 Exported Functions
  * @{
  */

void MIL_STD_1553_BRGInit(uint32_t MIL_STD_1553_BRG);
void MIL_STD_1553_DeInit(MIL1553Control * MIL_STD_1553x);
void MIL_STD_1553_Init(MIL1553Control * MIL_STD_1553x, MIL_STD_1553_InitTypeDef * MIL_STD_1553_InitStruct);
void MIL_STD_1553xStructInit(MIL_STD_1553_InitTypeDef * MIL_STD_1553_InitStruct);
void MIL_STD_1553_Cmd(MIL1553Control * MIL_STD_1553x, FunctionalState NewState);
uint32_t MIL_STD_1553_GetCommandWord(MIL1553Control * MIL_STD_1553x, uint32_t COMMAND_WORDx);
void MIL_STD_1553_SetCommandWord(MIL1553Control * MIL_STD_1553x, uint32_t COMMAND_WORDx, MIL_STD_1553_CommandWordTypeDef * CommandWord);
uint32_t MIL_STD_1553_GetModeData(MIL1553Control * MIL_STD_1553x);
uint32_t MIL_STD_1553_GetMSG(MIL1553Control * MIL_STD_1553x);
void MIL_STD_1553_SetStatusWord(MIL1553Control * MIL_STD_1553x, uint32_t STATUS_WORDx, MIL_STD_1553_StatusWordTypeDef * StatusWord);
uint32_t MIL_STD_1553_GetStatusWord(MIL1553Control * MIL_STD_1553x, uint32_t STATUS_WORDx);
uint32_t MIL_STD_1553_GetStatus(MIL1553Control * MIL_STD_1553x);
FlagStatus MIL_STD_1553_GetFlagStatus(MIL1553Control * MIL_STD_1553x, uint32_t flag);
void MIL_STD_1553_ITConfig(MIL1553Control * MIL_STD_1553x, uint32_t MIL_STD_1553_IT, FunctionalState NewState);
void MIL_STD_1553_StartTransmision(MIL1553Control * MIL_STD_1553x);
void MIL_STD_1553_ReceiveData(MIL1553Control * MIL_STD_1553x, uint32_t Subaddress, uint32_t NumberDataWords, uint32_t * ptr_Dest);
void MIL_STD_1553_WiteDataToSendBuffer(MIL1553Control * MIL_STD_1553x, uint32_t Subaddress, uint32_t NumberDataWords, uint32_t * ptr_Src);
void MIL_STD_1553_Transmitter_CMD(MIL1553Control * MIL_STD_1553x, uint32_t TRANSMITTERx, FunctionalState NewState);
uint32_t MIL_STD_1553_GetErrorStatus(MIL1553Control * MIL_STD_1553x);
void MIL_STD_1553_RERRCmd(MIL1553Control * MIL_STD_1553x, FunctionalState NewState);
void MIL_STD_1553_CLK_en(MIL1553Control * MILx, uint32_t MIL_STD_1553_CLK_DIV);
FlagStatus MIL_STD_1553_BCSTART_bit_stat(MIL1553Control * MIL_STD_1553x);

/** @} */ /* End of group MIL_STD_1553_Exported_Functions */

/** @} */ /* End of group MIL_STD_1553 */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

#ifdef __cplusplus
} // extern "C" block end
#endif

#endif /* MDR32F9QX_MIL_STD_1553_H_ */

/******************* (C) COPYRIGHT 2013 Milandr ********************************
*
* END OF FILE MDR32F9Qx_mil_std_1553.h */
