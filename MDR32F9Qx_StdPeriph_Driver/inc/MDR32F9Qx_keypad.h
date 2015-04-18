/**
  ******************************************************************************
  * @file	 MDR32F9Qx_keypad.h
  * @author	 sidorov.a
  * @version V1.4.0
  * @date    22.10.2013
  * @brief   This file contains all the functions prototypes for the KEYPAD
  * 		 firmware library.
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
  * FILE MDR32F9Qx_keypad.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef MDR32F9QX_KEYPAD_H_
#define MDR32F9QX_KEYPAD_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @addtogroup KEYPAD
  * @{
  */

/** @defgroup KEYPAD_Exported_Types KEYPAD Exported Types
  * @{
  */

/**
  * @brief	KEYPAD Init Structure definition
  */

typedef struct {
	uint32_t 		KeyRow;							/*!< Number of keys in a row matrix keyboard.
														 Specifies the number of pins of the controller involved readers.
														 This parameter can be a value of@ref KEY_ROW. */
	uint32_t 		KeyColumn;						/*!< Number of columns of the matrix keyboard shortcuts.
														 Specifies the number of involved scanning terminals of the controller.
														 This parameter can be a value of@ref KEY_COLUMN. */
	FunctionalState	InterruptState;					/*!< Enable or disable interrupt for any change in the registers KEYPAD_SWR1-KEYPAD_SWR14.
														 This parameter can be: ENABLE or DISABLE. */
	FunctionalState	ContactChatteringState;				/*!< Enable or disable contact chattering.
	 	 	 	 	 	 	 	 	 	 	 	 	 	 This parameter can be: ENABLE or DISABLE. */
	uint32_t		ContactChatteringTimer;			/*!< Config timer protection chattering. Specifies the number
														 of clock cycles of the keyboard controller, during which
														 will be blocked scanning and interrupt.
														 This parameter can be a value of@ref CONTACT_CHATTERING_TIMER. */
	FunctionalState SwitchesFieldScanState;			/*!< Enable or disable scan field switches.
														 Scan Mode field switches. */
	uint32_t		FirstColumnNumberSwitches;		/*!< Specifies the column number from which the scan mode is
														 activated scanning field switches.
														 This parameter can be a value of@ref FIRST_COLUMN_NUMBER_SWITCHES. */
	FunctionalState	DelayBetweenScansState;			/*!< Enable or disable delay between the scans.
														 This parametr can be: ENABLE or DISABLE. */
	uint32_t		DelayBetweenScansConfig;		/*!< Specifies the number of clock cycles of the keyboard controller,
														 for which there is a delay between scans.
														 This parameter can be a value of the@ref DELAY_BETWEEN_SCANS. */

} KEYPAD_InitTypeDef;

/** @} */ /* End of group KEYPAD_Exported_Types */

/** @defgroup KEYPAD_Exported_Macros KEYPAD Exported Macros
  * @{
  */

/** @defgroup KEYPAD_BRG KEYPAD BRG
  * @{
  */

#define KEYPAD_BRG_4						((uint32_t)0x00000000)
#define KEYPAD_BRG_8						((uint32_t)0x00000001)
#define KEYPAD_BRG_16						((uint32_t)0x00000002)
#define KEYPAD_BRG_64						((uint32_t)0x00000003)
#define KEYPAD_BRG_128						((uint32_t)0x00000004)
#define KEYPAD_BRG_256						((uint32_t)0x00000005)
#define KEYPAD_BRG_512						((uint32_t)0x00000006)
#define KEYPAD_BRG_1024						((uint32_t)0x00000007)

#define IS_KEYPAD_BRG(BRG)					(((BRG << KEYPAD_CR_KEY_PRE_Pos) &\
											 (~KEYPAD_CR_KEY_PRE_Msk)) == 0)


/** @} */ /* End of group KEYPAD_BRG */

/** @defgroup KEYPAD_KEY_ROW KEYPAD KEY_ROW
  * @{
  */

#define KEYPAD_KEY_ROW_1					((uint32_t)0x00000000)
#define KEYPAD_KEY_ROW_2					((uint32_t)0x00000001)
#define KEYPAD_KEY_ROW_3					((uint32_t)0x00000002)
#define KEYPAD_KEY_ROW_4					((uint32_t)0x00000003)
#define KEYPAD_KEY_ROW_5					((uint32_t)0x00000004)
#define KEYPAD_KEY_ROW_6					((uint32_t)0x00000005)
#define KEYPAD_KEY_ROW_7					((uint32_t)0x00000006)
#define KEYPAD_KEY_ROW_8					((uint32_t)0x00000007)

#define IS_KEYPAD_KEY_ROW(KEY_ROW)			(((KEY_ROW << KEYPAD_CR_KEY_ROW_Pos) &\
		   	   	   	   	   	   	   	   	     (~KEYPAD_CR_KEY_ROW_Msk)) == 0)

/** @} */ /* End of group KEYPAD_KEY_ROW */

/** @defgroup KEYPAD_KEY_COLUMN KEYPAD KEY_COLUMN
  * @{
  */

#define KEYPAD_KEY_COLUMN_1					((uint32_t)0x00000000)
#define KEYPAD_KEY_COLUMN_2					((uint32_t)0x00000001)
#define KEYPAD_KEY_COLUMN_3					((uint32_t)0x00000002)
#define KEYPAD_KEY_COLUMN_4					((uint32_t)0x00000003)
#define KEYPAD_KEY_COLUMN_5					((uint32_t)0x00000004)
#define KEYPAD_KEY_COLUMN_6					((uint32_t)0x00000005)
#define KEYPAD_KEY_COLUMN_7					((uint32_t)0x00000006)
#define KEYPAD_KEY_COLUMN_8					((uint32_t)0x00000007)
#define KEYPAD_KEY_COLUMN_9					((uint32_t)0x00000008)
#define KEYPAD_KEY_COLUMN_10				((uint32_t)0x00000009)
#define KEYPAD_KEY_COLUMN_11				((uint32_t)0x0000000A)
#define KEYPAD_KEY_COLUMN_12				((uint32_t)0x0000000B)
#define KEYPAD_KEY_COLUMN_13				((uint32_t)0x0000000C)
#define KEYPAD_KEY_COLUMN_14				((uint32_t)0x0000000D)
#define KEYPAD_KEY_COLUMN_15				((uint32_t)0x0000000E)
#define KEYPAD_KEY_COLUMN_16				((uint32_t)0x0000000F)

#define IS_KEYPAD_KEY_COLUMN(KEY_COLUMN)	(((KEY_COLUMN << KEYPAD_CR_KEY_COL_Pos) & \
											 (~KEYPAD_CR_KEY_COL_Msk)) == 0)

/** @} */ /* End of group KEYPAD_KEY_COLUMN */

/** @defgroup KEYPAD_CONTACT_CHATTERING_TIMER KEYPAD CONTACT_CHATTERING_TIMER
  * @{
  */

#define KEYPAD_CONTACT_CHATTERING_TIMER_8_CYCLES		((uint32_t)0x00000000)
#define KEYPAD_CONTACT_CHATTERING_TIMER_16_CYCLES		((uint32_t)0x00000001)
#define KEYPAD_CONTACT_CHATTERING_TIMER_32_CYCLES		((uint32_t)0x00000002)
#define KEYPAD_CONTACT_CHATTERING_TIMER_64_CYCLES		((uint32_t)0x00000003)
#define KEYPAD_CONTACT_CHATTERING_TIMER_256_CYCLES		((uint32_t)0x00000004)
#define KEYPAD_CONTACT_CHATTERING_TIMER_512_CYCLES		((uint32_t)0x00000005)
#define KEYPAD_CONTACT_CHATTERING_TIMER_1024_CYCLES		((uint32_t)0x00000006)
#define KEYPAD_CONTACT_CHATTERING_TIMER_2048_CYCLES		((uint32_t)0x00000007)

#define IS_KEYPAD_CONTACT_CHATTERING_TIMER_CYCLES(CYCLES) (((CYCLES << KEYPAD_CR_KEY_LTIM_Pos) &\
														   (~KEYPAD_CR_KEY_LTIM_Msk)) == 0)

/** @} */ /* End of group KEYPAD_CONTACT_CHATTERING_TIMER */

/** @defgroup KEYPAD_FIRST_COLUMN_NUMBER_SWITCHES KEYPAD FIRST_COLUMN_NUMBER_SWITCHES
  * @{
  */

#define KEYPAD_FIRST_COLUMN_NUMBER_SWITCHES_1			((uint32_t)0x00000000)
#define KEYPAD_FIRST_COLUMN_NUMBER_SWITCHES_2			((uint32_t)0x00000001)
#define KEYPAD_FIRST_COLUMN_NUMBER_SWITCHES_3			((uint32_t)0x00000002)
#define KEYPAD_FIRST_COLUMN_NUMBER_SWITCHES_4			((uint32_t)0x00000003)
#define KEYPAD_FIRST_COLUMN_NUMBER_SWITCHES_5			((uint32_t)0x00000004)
#define KEYPAD_FIRST_COLUMN_NUMBER_SWITCHES_6			((uint32_t)0x00000005)
#define KEYPAD_FIRST_COLUMN_NUMBER_SWITCHES_7			((uint32_t)0x00000006)
#define KEYPAD_FIRST_COLUMN_NUMBER_SWITCHES_8			((uint32_t)0x00000007)
#define KEYPAD_FIRST_COLUMN_NUMBER_SWITCHES_9			((uint32_t)0x00000008)
#define KEYPAD_FIRST_COLUMN_NUMBER_SWITCHES_10			((uint32_t)0x00000009)
#define KEYPAD_FIRST_COLUMN_NUMBER_SWITCHES_11			((uint32_t)0x0000000A)
#define KEYPAD_FIRST_COLUMN_NUMBER_SWITCHES_12			((uint32_t)0x0000000B)
#define KEYPAD_FIRST_COLUMN_NUMBER_SWITCHES_13			((uint32_t)0x0000000C)
#define KEYPAD_FIRST_COLUMN_NUMBER_SWITCHES_14			((uint32_t)0x0000000D)
#define KEYPAD_FIRST_COLUMN_NUMBER_SWITCHES_15			((uint32_t)0x0000000E)
#define KEYPAD_FIRST_COLUMN_NUMBER_SWITCHES_16			((uint32_t)0x0000000F)

#define IS_KEYPAD_FIRST_COLUMN_NUMBER_SWITCHES(SWITCHES) (((SWITCHES << KEYPAD_CR_KEY_SWCOL_Pos) &\
														   (~KEYPAD_CR_KEY_SWCOL_Msk)) == 0)

/** @} */ /* End of group KEYPAD_FIRST_COLUMN_NUMBER_SWITCHES */

/** @defgroup KEYPAD_DELAY_BETWEEN_SCANS KEYPAD DELAY_BETWEEN_SCANS
  * @{
  */

#define KEYPAD_DELAY_BETWEEN_SCANS_8_CYCLES				((uint32_t)0x00000000)
#define KEYPAD_DELAY_BETWEEN_SCANS_16_CYCLES			((uint32_t)0x00000001)
#define KEYPAD_DELAY_BETWEEN_SCANS_32_CYCLES			((uint32_t)0x00000002)
#define KEYPAD_DELAY_BETWEEN_SCANS_64_CYCLES			((uint32_t)0x00000003)
#define KEYPAD_DELAY_BETWEEN_SCANS_256_CYCLES			((uint32_t)0x00000004)
#define KEYPAD_DELAY_BETWEEN_SCANS_512_CYCLES			((uint32_t)0x00000005)
#define KEYPAD_DELAY_BETWEEN_SCANS_1024_CYCLES			((uint32_t)0x00000006)
#define KEYPAD_DELAY_BETWEEN_SCANS_2048_CYCLES			((uint32_t)0x00000007)

#define IS_KEYPAD_DELAY_BETWEEN_SCANS(CYCLES)			(((CYCLES << KEYPAD_CR_KEY_IVCONF_Pos) & \
														 (~KEYPAD_CR_KEY_IVCONF_Msk)) == 0)

/** @} */ /* End of group KEYPAD_DELAY_BETWEEN_SCANS */

/** @defgroup KEYPAD_FLAG KEYPAD FLAG
  * @{
  */

#define KEYPAD_FLAG_INTF								((uint32_t)0x00000001)
#define KEYPAD_FLAG_PT1F								((uint32_t)0x00000002)
#define KEYPAD_FLAG_PT2F								((uint32_t)0x00000004)
#define KEYPAD_FLAG_ERRF								((uint32_t)0x00000008)
#define KEYPAD_FLAG_SCF									((uint32_t)0x00000010)
#define KEYPAD_FLAG_PCHATF								((uint32_t)0x00000020)

#define IS_KEYPAD_FLAG(FLAG)							((FLAG == KEYPAD_FLAG_INTF) ||\
														 (FLAG == KEYPAD_FLAG_PT1F) ||\
														 (FLAG == KEYPAD_FLAG_PT2F) ||\
														 (FLAG == KEYPAD_FLAG_ERRF) ||\
														 (FLAG == KEYPAD_FLAG_SCF)  ||\
														 (FLAG == KEYPAD_FLAG_PCHATF))

/** @} */ /* End of group KEYPAD_FLAG */

/** @} */ /* End of group KEYPAD_Exported_Macros */

/** @defgroup KEYPAD_Exported_Constants KEYPAD Exported Constants
  * @{
  */
/** @} */ /* End of group KEYPAD_Exported_Constants */

/** @defgroup KEYPAD_Exported_Functions KEYPAD Exported Functions
  * @{
  */
void KEYPAD_DeInit(void);
void KEYPAD_BRGInit(uint32_t KEYPAD_BRG);
void KEYPAD_StructInit(KEYPAD_InitTypeDef * KEYPAD_InitStruct);
void KEYPAD_Init(KEYPAD_InitTypeDef * KEYPAD_InitStruct);
void KEYPAD_Cmd(FunctionalState NewState);
FlagStatus KEYPAD_GetFlagStatus(uint32_t KEYPAD_FLAG);
void KEYPAD_ClearFlag(uint32_t KEYPAD_FLAG);
uint32_t KEYPAD_GetPressedFirstKey(void);
uint32_t KEYPAD_GetPressedSecondKey(void);
BitStatus KEYPAD_GetSwitchStatus(uint32_t switch_number);
void KEYPAD_ITCmd(FunctionalState NewState);

/** @} */ /* End of group KEYPAD_Exported_Functions */

/** @} */ /* End of group KEYPAD */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

#ifdef __cplusplus
} // extern "C" block end
#endif

#endif /* MDR32F9QX_KEYPAD_H_ */

/******************* (C) COPYRIGHT 2013 Milandr ********************************
*
* END OF FILE MDR32F9Qx_keypad.h */
