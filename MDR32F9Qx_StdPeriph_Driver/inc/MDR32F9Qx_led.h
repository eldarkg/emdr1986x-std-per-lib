/**
  * FILE MDR32F9Qx_led.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef MDR32F9QX_LED_H_
#define MDR32F9QX_LED_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_config.h"

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @addtogroup LED
  * @{
  */

/** @defgroup LED_Exported_Types LED Exported Types
  * @{
  */

/**
 * @brief LED Init Structure definition
 */
typedef struct{
	FunctionalState TwinkleState;						/*!< Enable or disable flickering.
															 This parameter can be: ENABLE or DISABLE. */
	uint32_t 		TwinkleDIV;							/*!< Division ratio of the frequency of blinking display controller.
	 														 This parameter can be a value from 0 to 0xFF. */

	uint32_t 		FrameNumber;						/*!< Number of used frame if the flicker off FlickeringState=DISABLE.
															 This parameter can be a value of@ref LED_FRAME. */

	uint32_t 		RowLen;								/*!< String length indicators IPV72A-4/5h7L - 1.
															 Specifies the length of consistent data on circuits DO.
															 This parameter can be a value of@ref LED_ROW_LEN. */
	uint32_t		ColumnLen;							/*!< Number of lines DO [7:0] - 1, connected to the indicators.
															 This parameter can be a value of@ref LED_COLUMN_LEN. */

	FunctionalState	RAMState;							/*!< Enable or disable access to TextBuf and DecodeBbuf, when LED off.
															 This parameter can be: ENABLE or DISABLE. */

	FunctionalState	EN_InversionState;					/*!< Enable or disable inversion on output EN.
	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 This parameter can be: ENABLE or DISABLE. */

	FunctionalState Y_InversionState;					/*!< Enable or disable inversion on output Y.
	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 This parameter can be: ENABLE or DISABLE. */

	FunctionalState C_InversionState;					/*!< Enable or disable inversion on output C.
	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 This parameter can be: ENABLE or DISABLE. */

	FunctionalState DO_InversionState;					/*!< Enable or disable inversion on output DO.
	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 This parameter can be: ENABLE or DISABLE. */
}LED_InitTypeDef;

/** @} */ /* End of group LED_Exported_Types */

/** @defgroup LED_Exported_Macros LED Exported Macros
  * @{
  */

/** @defgroup LED_FRAME LED FRAME
  * @{
  */

#define LED_FRAME0						((uint32_t)0x00000000)
#define LED_FRAME1						((uint32_t)0x00000001)//((uint32_t)0x00000008)

#define IS_LED_FRAME(LED_FRMAME)		((LED_FRMAME == LED_FRAME0) ||\
										 (LED_FRMAME == LED_FRAME1))

/** @} */ /* End of group LED_FRAME */

/** @defgroup LED_ROW_LEN LED ROW_LEN
  * @{
  */

#define LED_ROW1						((uint32_t)0x00000000)
#define LED_ROW2						((uint32_t)0x00000010)
#define LED_ROW3						((uint32_t)0x00000020)
#define LED_ROW4						((uint32_t)0x00000030)
#define LED_ROW5						((uint32_t)0x00000040)
#define LED_ROW6						((uint32_t)0x00000050)
#define LED_ROW7						((uint32_t)0x00000060)
#define LED_ROW8						((uint32_t)0x00000070)

#define IS_LED_ROW_LEN(ROW_LEN)			((ROW_LEN & (~LED_CR_LEN_STR_Msk)) == 0 )

/** @} */ /* End of group LED_ROW_LEN */

/** @defgroup LED_COLUMN_LEN LED COLUMN_LEN
  * @{
  */

#define LED_COLUMN1						((uint32_t)0x00000000)
#define LED_COLUMN2						((uint32_t)0x00000100)
#define LED_COLUMN3						((uint32_t)0x00000200)
#define LED_COLUMN4						((uint32_t)0x00000300)
#define LED_COLUMN5						((uint32_t)0x00000400)
#define LED_COLUMN6						((uint32_t)0x00000500)
#define LED_COLUMN7						((uint32_t)0x00000600)
#define LED_COLUMN8						((uint32_t)0x00000700)

#define IS_LED_COLUMN_LEN(COLUMN_LEN)	((COLUMN_LEN & ~ LED_CR_LEN_STOLB_Msk) == 0)

/** @} */ /* End of group LED_COLUMN_LEN */

/** @defgroup LED_BRG LED BRG
  * @{
  */

#define LED_BRG4						((uint32_t)0x00000003)
#define LED_BRG5						((uint32_t)0x00000004)
#define LED_BRG6						((uint32_t)0x00000005)
#define LED_BRG7						((uint32_t)0x00000006)
#define LED_BRG8						((uint32_t)0x00000007)

#define IS_LED_BRG(BRG)					((BRG >= LED_BRG4) && (BRG <= LED_BRG8))

/** @} */ /* End of group LED_BRG */

/** @defgroup LED_INVERSION LED INVERSION
  * @{
  */
#define LED_INVERSION_Y					((uint32_t)0x00001000)
#define LED_INVERSION_EN				((uint32_t)0x00002000)
#define LED_INVERSION_C 				((uint32_t)0x00004000)
#define LED_INVERSION_DO				((uint32_t)0x00008000)

#define IS_LED_INVERSION_OUTPUT(OUTPUT)	((OUTPUT == LED_INVERSION_Y)  ||\
										 (OUTPUT == LED_INVERSION_EN) ||\
										 (OUTPUT == LED_INVERSION_C)  ||\
										 (OUTPUT == LED_INVERSION_DO))

/** @} */ /* End of group LED_INVERSION */

/** @} */ /* End of group LED_Exported_Macros */

/** @defgroup LED_Exported_Constants LED Exported Constants
  * @{
  */
/** @} */ /* End of group LED_Exported_Constants */

/** @defgroup LED_Exported_Functions LED Exported Functions
  * @{
  */
void LED_DeInit(void);
void LED_BRGInit(uint32_t LED_BRG);
void LED_StructInit(LED_InitTypeDef * LED_InitStruct);
void LED_Init(LED_InitTypeDef * LED_InitStruct);
void LED_CMD(FunctionalState NewState);
void LED_InversionOutputCMD(uint32_t output, FunctionalState NewState);
void LED_ITCMD(FunctionalState NewState);
void LED_TwinkleCMD(FunctionalState NewState);
FlagStatus LED_GetReadyFlag(void);
void LED_InitDecodeBuf(void);
void LED_ClearFrame(uint32_t led_frame);
void LED_PutString(uint32_t position, const char * ptr_char);

/** @} */ /* End of group LED_Exported_Functions */

/** @} */ /* End of group LED */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

#ifdef __cplusplus
} // extern "C" block end
#endif

#endif /* MDR32F9QX_LED_H_ */

/*
*
* END OF FILE MDR32F9Qx_led.h */
