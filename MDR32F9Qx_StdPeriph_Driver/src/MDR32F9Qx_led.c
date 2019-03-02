/**
  * FILE MDR32F9Qx_led.c
  */

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_config.h"
#include "MDR32F9Qx_led.h"

#define ASSERT_INFO_FILE_ID FILEID__MDR32F9Qx_LED_C

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @defgroup LED LED
  * @warning This module can be used only for MDR1986VE3 microcontroller's.
  * @{
  */

#if defined (USE_MDR1986VE3)

const uint8_t font5x7[256 * 5] =
{
	0x0, 0x0, 0x0, 0x0, 0x0,
	0x7C, 0xDA, 0xF2, 0xDA, 0x7C,
	0x7C, 0xD6, 0xF2, 0xD6, 0x7C,
	0x38, 0x7C, 0x3E, 0x7C, 0x38,

	0x18, 0x3C, 0x7E, 0x3C, 0x18,
	0x38, 0xEA, 0xBE, 0xEA, 0x38,
	0x38, 0x7A, 0xFE, 0x7A, 0x38,
	0x0, 0x18, 0x3C, 0x18, 0x0,

	0xFF, 0xE7, 0xC3, 0xE7, 0xFF,
	0x0, 0x18, 0x24, 0x18, 0x0,
	0xFF, 0xE7, 0xDB, 0xE7, 0xFF,
	0xC, 0x12, 0x5C, 0x60, 0x70,

	0x64, 0x94, 0x9E, 0x94, 0x64,
	0x2, 0xFE, 0xA0, 0xA0, 0xE0,
	0x2, 0xFE, 0xA0, 0xA4, 0xFC,
	0x5A, 0x3C, 0xE7, 0x3C, 0x5A,

	0xFE, 0x7C, 0x38, 0x38, 0x10,		// 10
	0x10, 0x38, 0x38, 0x7C, 0xFE,
	0x28, 0x44, 0xFE, 0x44, 0x28,
	0xFA, 0xFA, 0x0, 0xFA, 0xFA,

	0x60, 0x90, 0xFE, 0x80, 0xFE,		// 14
	0x0, 0x66, 0x91, 0xA9, 0x56,
	0x6, 0x6, 0x6, 0x6, 0x6,
	0x29, 0x45, 0xFF, 0x45, 0x29,

	0x10, 0x20, 0x7E, 0x20, 0x10,		// 18
	0x8, 0x4, 0x7E, 0x4, 0x8,
	0x10, 0x10, 0x54, 0x38, 0x10,
	0x10, 0x38, 0x54, 0x10, 0x10,

	0x78, 0x8, 0x8, 0x8, 0x8,		 	// 1C
	0x30, 0x78, 0x30, 0x78, 0x30,
	0xC, 0x1C, 0x7C, 0x1C, 0xC,
	0x60, 0x70, 0x7C, 0x70, 0x60,

	0x0, 0x0, 0x0, 0x0, 0x0,			// 20
	0x0, 0x0, 0xFA, 0x0, 0x0, 			// !
	0x0, 0xE0, 0x0, 0xE0, 0x0, 			// "
	0x28, 0xFE, 0x28, 0xFE, 0x28,		// #

	0x24, 0x54, 0xFE, 0x54, 0x48,		// $	// 24
	0xC4, 0xC8, 0x10, 0x26, 0x46,		// %
	0x6C, 0x92, 0x6A, 0x4, 0xA,			// &
	0, 160, 192, 0, 0,					// '

	0x0, 0x38, 0x44, 0x82, 0x0,			// (	// 28
	0x0, 0x82, 0x44, 0x38, 0x0,			// )
	40, 16, 124, 16, 40,				// *
	0x10, 0x10, 0x7C, 0x10, 0x10,		// +

	0, 10, 12, 0, 0,					// ,	// 2C
	0x10, 0x10, 0x10, 0x10, 0x10,		// -
	0, 6, 6, 0, 0,						// .
	0x4, 0x8, 0x10, 0x20, 0x40,			// /

	0x7C, 0x82, 0x82, 0x82, 0x7C, 		// O	// 30
	0x0, 0x42, 0xFE, 0x2, 0x0,			// 1
	0x4E, 0x92, 0x92, 0x92, 0x62,		// 2
	0x84, 0x82, 0x92, 0xB2, 0xCC,		// 3

	0x18, 0x28, 0x48, 0xFE, 0x8,		// 4	// 34
	0xE4, 0xA2, 0xA2, 0xA2, 0x9C,		// 5
	0x3C, 0x52, 0x92, 0x92, 0x8C, 		// 6
	0x82, 0x84, 0x88, 0x90, 0xE0, 		// 7

	0x6C, 0x92, 0x92, 0x92, 0x6C,		// 8	// 38
	0x62, 0x92, 0x92, 0x94, 0x78, 		// 9
	0x0, 0x6C, 0x6C, 0x0, 0x0, 			// :
	0, 106, 108, 0, 0,					// ;

	0x0, 0x10, 0x28, 0x44, 0x82,		// <	// 3C
	0x28, 0x28, 0x28, 0x28, 0x28,		// =
	0x0, 0x82, 0x44, 0x28, 0x10, 		// >
	0x40, 0x80, 0x9A, 0x90, 0x60,		// ?

	124, 130, 186, 170, 120,			// @	// 40
	0x3E, 0x48, 0x88, 0x48, 0x3E, 		// A
	0xFE, 0x92, 0x92, 0x92, 0x6C, 		// B
	0x7C, 0x82, 0x82, 0x82, 0x44,		// C

	0xFE, 0x82, 0x82, 0x82, 0x7C, 		// D	// 44
	0xFE, 0x92, 0x92, 0x92, 0x82, 		// E
	0xFE, 0x90, 0x90, 0x90, 0x80, 		// F
	124, 130, 146, 146, 94,				// G

	0xFE, 0x10, 0x10, 0x10, 0xFE, 		// H	// 48
	0x0, 0x82, 0xFE, 0x82, 0x0, 		// I
	0x4, 0x2, 0x82, 0xFC, 0x80, 		// J
	0xFE, 0x10, 0x28, 0x44, 0x82, 		// K

	0xFE, 0x2, 0x2, 0x2, 0x2, 			// L	// 4C
	0xFE, 0x40, 0x38, 0x40, 0xFE, 		// M
	0xFE, 0x20, 0x10, 0x8, 0xFE, 		// N
	0x7C, 0x82, 0x82, 0x82, 0x7C, 		// O

	0xFE, 0x90, 0x90, 0x90, 0x60, 		// P	// 50
	0x7C, 0x82, 0x8A, 0x84, 0x7A, 		// Q
	0xFE, 0x90, 0x98, 0x94, 0x62, 		// R
	0x64, 0x92, 0x92, 0x92, 0x4C, 		// S

	0xC0, 0x80, 0xFE, 0x80, 0xC0, 		// T	// 54
	0xFC, 0x2, 0x2, 0x2, 0xFC, 			// U
	0xF8, 0x4, 0x2, 0x4, 0xF8, 			// V
	0xFC, 0x2, 0x1C, 0x2, 0xFC, 		// W

	0xC6, 0x28, 0x10, 0x28, 0xC6, 		// X	// 58
	0xC0, 0x20, 0x1E, 0x20, 0xC0, 		// Y
	0x86, 0x9A, 0x92, 0xB2, 0xC2, 		// Z
	0, 0xFE, 0x82, 0x82, 0, 			// [

	0x40, 0x20, 0x10, 0x8, 0x4, 		// \	// 5C
	0, 0x82, 0x82, 0xFE, 0,		 		// ]
	0x20, 0x40, 0x80, 0x40, 0x20,		// ^
	0x2, 0x2, 0x2, 0x2, 0x2, 			// _

	0x0, 0xC0, 0xE0, 0x10, 0x0, 		// `	// 60
	0x4, 0x2A, 0x2A, 0x1E, 0x2, 		// a
	0xFE, 0x14, 0x22, 0x22, 0x1C, 		// b
	0x1C, 0x22, 0x22, 0x22, 0x14, 		// c

	0x1C, 0x22, 0x22, 0x14, 0xFE, 		// d	// 64
	0x1C, 0x2A, 0x2A, 0x2A, 0x18, 		// e
	0x0, 0x10, 0x7E, 0x90, 0x40, 		// f
	0x18, 0x25, 0x25, 0x39, 0x1E, 		// g

	0xFE, 0x10, 0x20, 0x20, 0x1E, 		// h	// 68
	0x0, 0x22, 0xBE, 0x2, 0x0, 			// i
	0x4, 0x2, 0x2, 0xBC, 0x0, 			// j
	0xFE, 0x8, 0x14, 0x22, 0x0, 		// k

	0x0, 0x82, 0xFE, 0x2, 0x0, 			// l	// 6C
	0x3E, 0x20, 0x1E, 0x20, 0x1E, 		// m
	0x3E, 0x10, 0x20, 0x20, 0x1E, 		// n
	0x1C, 0x22, 0x22, 0x22, 0x1C, 		// o

	0x3F, 0x18, 0x24, 0x24, 0x18, 		// p	// 70
	0x18, 0x24, 0x24, 0x18, 0x3F, 		// q
	0x3E, 0x10, 0x20, 0x20, 0x10, 		// r
	0x12, 0x2A, 0x2A, 0x2A, 0x24, 		// s

	0x20, 0x20, 0xFC, 0x22, 0x24, 		// t	// 74
	0x3C, 0x2, 0x2, 0x4, 0x3E, 			// u
	0x38, 0x4, 0x2, 0x4, 0x38, 			// v
	0x3C, 0x2, 0xC, 0x2, 0x3C, 			// w

	0x22, 0x14, 0x8, 0x14, 0x22, 		// x	// 78
	0x32, 0x9, 0x9, 0x9, 0x3E, 			// y
	0x22, 0x26, 0x2A, 0x32, 0x22, 		// z
	0x0, 0x10, 0x6C, 0x82, 0x0, 		// {

	0x0, 0x0, 0xEE, 0x0, 0x0, 			// |	// 7C
	0x0, 0x82, 0x6C, 0x10, 0x0, 		// }
	0x40, 0x80, 0x40, 0x20, 0x40, 		// ~
	0x3C, 0x64, 0xC4, 0x64, 0x3C, 		//

	255, 0, 85, 0, 255,					//	SYM_VSCROLL_BODY
	62, 34, 34, 34, 62,					//	SYM_VSCROLL_BLOCK_UP
	124, 68, 68, 68, 124,				//	SYM_VSCROLL_BLOCK_DOWN
	14, 18, 34, 18, 14,					//	SYM_VSCROLL_ARROW_UP

	112, 72, 68, 72, 112,				//	SYM_VSCROLL_ARROW_DOWN
	85, 170, 85, 170, 85,				//	SYM_VSCROLL_BODY
	0, 0, 0, 0, 0,						//
	0, 0, 0, 0, 0,						//

	0, 0, 0, 0, 0,						// 88
	0, 0, 0, 0, 0,						//
	0, 0, 0, 0, 0,						//
	0, 0, 0, 0, 0,						//

	0, 0, 0, 0, 0,						// 8C
	0, 0, 0, 0, 0,						//
	0, 0, 0, 0, 0,						//
	0, 0, 0, 0, 0,						//

	0, 0, 0, 0, 0,						// 90
	0, 0, 0, 0, 0,						//
	0, 0, 0, 0, 0,						//
	0, 0, 0, 0, 0,						//

	0, 0, 0, 0, 0,						// 94
	0, 0, 0, 0, 0,						//
	0, 0, 0, 0, 0,						//
	0, 0, 0, 0, 0,						//

	0, 0, 0, 0, 0,						// 98
	0, 0, 0, 0, 0,						//
	0, 0, 0, 0, 0,						//
	0, 0, 0, 0, 0,						//

	0, 0, 0, 0, 0,						// 9C
	0, 0, 0, 0, 0,						//
	0, 0, 0, 0, 0,						//
	0, 0, 0, 0, 0,						//

	0, 0, 0, 0, 0,						// A0
	0, 0, 0, 0, 0,						//
	0, 0, 0, 0, 0,						//
	0, 0, 0, 0, 0,						//

	0, 0, 0, 0, 0,						// A4
	0, 0, 0, 0, 0,						//
	0, 0, 0, 0, 0,						//
	0, 0, 0, 0, 0,						//

	126, 210, 82, 210, 66,				// A8
	0, 0, 0, 0, 0,						//
	124, 146, 146, 130, 68,				// AA
	0, 0, 0, 0, 0,						//

	0, 0, 0, 0, 0,						// AC
	0, 0, 0, 0, 0,						//
	0, 0, 0, 0, 0,						//
	0, 0, 0, 0, 0,						//

	0, 0, 0, 0, 0,						// B0
	0, 0, 0, 0, 0,						//
	0, 0, 0, 0, 0,						//
	0, 0, 0, 0, 0,						//

	0, 0, 0, 0, 0,						// B4
	0, 0, 0, 0, 0,						//
	0, 0, 0, 0, 0,						//
	0, 0, 0, 0, 0,						//

	28, 170, 42, 170, 24,				// B8
	0, 0, 0, 0, 0,						//
	28, 42, 34, 20, 0,					//
	0, 0, 0, 0, 0,						//

	0, 0, 0, 0, 0,						// BC
	0, 0, 0, 0, 0,						//
	0, 0, 0, 0, 0,						//
	0, 0, 0, 0, 0,						//

	0x3E, 0x48, 0x88, 0x48, 0x3E, 		// C0
	254, 146, 146, 146, 140,			//
	0xFE, 0x92, 0x92, 0x92, 0x6C, 		//
	254, 128, 128, 128, 192,			//

	3, 126, 130, 254, 3,				// C4
	0xFE, 0x92, 0x92, 0x92, 0x82, 		//
	238, 16, 254, 16, 238,				//
	130, 146, 146, 146, 108,			//

	254, 8, 16, 32, 254,				// C8
	126, 4, 200, 16, 126,				//
	0xFE, 0x10, 0x28, 0x44, 0x82, 		//
	2, 60, 64, 128, 254,				//

	0xFE, 0x40, 0x38, 0x40, 0xFE, 		// CC
	0xFE, 0x10, 0x10, 0x10, 0xFE, 		//
	0x7C, 0x82, 0x82, 0x82, 0x7C, 		//
	254, 128, 128, 128, 254,			//

	0xFE, 0x90, 0x90, 0x90, 0x60, 		// D0
	0x7C, 0x82, 0x82, 0x82, 0x44,		//
	0xC0, 0x80, 0xFE, 0x80, 0xC0, 		//
	224, 18, 18, 18, 252,				//

	56, 68, 254, 68, 56,				// D4
	0xC6, 0x28, 0x10, 0x28, 0xC6, 		//
	254, 2, 2, 254, 3,					//
	224, 16, 16, 16, 254,				//

	254, 2, 254, 2, 254,				// D8
	254, 2, 254, 2, 255,				//
	128, 254, 18, 18, 12,				//
	254, 18, 12, 0, 254,				//

	254, 18, 18, 18, 12,				// DC
	68, 130, 146, 146, 124,				//
	254, 16, 124, 130, 124,				//
	98, 148, 152, 144, 254,				//

	0x4, 0x2A, 0x2A, 0x1E, 0x2, 		// E0
	60, 82, 82, 146, 12,				//
	62, 42, 42, 20, 0,					//
	62, 32, 32, 48, 0,					//

	3, 30, 34, 62, 3,					// E4
	0x1C, 0x2A, 0x2A, 0x2A, 0x18, 		//
	54, 8, 62, 8, 54,					//
	34, 42, 42, 20, 0,					//

	62, 4, 8, 16, 62,					// E8
	62, 132, 72, 144, 62,				//
	62, 8, 20, 34, 0,					//
	14, 16, 32, 62, 0,					//

	62, 16, 8, 16, 62,					// EC
	62, 8, 8, 62, 0,					//
	28, 34, 34, 28, 0,					//
	62, 32, 32, 62, 0,					//

	62, 40, 40, 16, 0,					// F0
	0x1C, 0x22, 0x22, 0x22, 0x14, 		//
	32, 32, 62, 32, 32,					//
	48, 10, 10, 60, 0,					//

	8, 20, 62, 20, 8,					// F4
	0x22, 0x14, 0x8, 0x14, 0x22, 		//
	62, 2, 62, 3, 0,					//
	48, 8, 8, 62, 0,					//

	62, 2, 62, 2, 62,					// F8
	62, 2, 62, 2, 63,					//
	32, 62, 10, 10, 4,					//
	62, 10, 4, 0, 62,					//

	62, 10, 10, 4, 0,					// FC
	20, 34, 42, 28, 0,					//
	62, 8, 28, 34, 28,					//
	18, 44, 40, 62, 0,					//
};


/** @defgroup LED_Private_Macros LED Private Macros
  * @{
  */

#define IS_LED_FLINKERING_DIV(DIV)			( DIV <= 0xFF )
#define IS_LED_POSITION(POS)				(POS <= 256)

/** @} */ /* End of group LED_Private_Macros */

/** @defgroup LED_Private_Functions LED Private Functions
  * @{
  */

/**
  * @brief	Resets the LED peripheral registers to their default reset values.
  * @param	None.
  * @retval None.
  */
void LED_DeInit(void)
{
	MDR_LED->CR = 0;
	MDR_LED->Jark = 0xFF;
	MDR_LED->DivR = 0;
}

/**
  * @brief	Initializes the LED peripheral clock according to the
  *         specified parameters.
  * @param	LED_BRG: specifies the HCLK division factor.
  *         This parameter can be one of the following values:
  *         	@arg: LED_BRG4
  *         	@arg: LED_BRG5
  *         	@arg: LED_BRG6
  *         	@arg: LED_BRG7
  *         	@arg: LED_BRG8
  * @retval	None.
  */
void LED_BRGInit(uint32_t LED_BRG)
{
	uint32_t tmperg;
	/* Check the parameters */
	assert_param(IS_LED_BRG(LED_BRG));

	tmperg = MDR_LED->DivR & (~LED_DIVR_DIV_Msk);
	tmperg |= LED_BRG << LED_DIVR_DIV_Pos;
	MDR_LED->DivR = tmperg;
}

/**
  * @brief	Fills each LED member with its default value.
  * @param	LED_InitStruct: pointer to a LED_InitTypeDef structure
  *         that is to be initialized.
  * @retval None.
  */
void LED_StructInit(LED_InitTypeDef * LED_InitStruct)
{
	LED_InitStruct->TwinkleState 	= DISABLE;
	LED_InitStruct->TwinkleDIV 		= 0;
	LED_InitStruct->FrameNumber 		= LED_FRAME0;
	LED_InitStruct->RowLen 				= LED_ROW1;
	LED_InitStruct->ColumnLen 			= LED_COLUMN1;
	LED_InitStruct->RAMState 			= DISABLE;
	LED_InitStruct->EN_InversionState 	= DISABLE;
	LED_InitStruct->Y_InversionState 	= DISABLE;
	LED_InitStruct->C_InversionState 	= DISABLE;
	LED_InitStruct->DO_InversionState 	= DISABLE;
}

/**
  * @brief	Initializes the LED peripheral according to the specified
  *         parameters in the LED_InitStruct.
  * @param	LED_InitStruct: pointer to a LED_InitTypeDef structure
  *         that contains the configuration information for the specified LED peripheral.
  * @retval	None.
  */
void LED_Init(LED_InitTypeDef * LED_InitStruct)
{

	uint32_t tmpreg_cr;

	/* Check the parameters */
	assert_param(IS_FUNCTIONAL_STATE(LED_InitStruct->TwinkleState));
	assert_param(IS_LED_FLINKERING_DIV(LED_InitStruct->TwinkleDIV));
	assert_param(IS_LED_FRAME(LED_InitStruct->FrameNumber));
	assert_param(IS_LED_ROW_LEN(LED_InitStruct->RowLen));
	assert_param(IS_LED_COLUMN_LEN(LED_InitStruct->ColumnLen));
	assert_param(IS_FUNCTIONAL_STATE(LED_InitStruct->RAMState));
	assert_param(IS_FUNCTIONAL_STATE(LED_InitStruct->EN_InversionState));
	assert_param(IS_FUNCTIONAL_STATE(LED_InitStruct->Y_InversionState));
	assert_param(IS_FUNCTIONAL_STATE(LED_InitStruct->C_InversionState));
	assert_param(IS_FUNCTIONAL_STATE(LED_InitStruct->DO_InversionState));

	tmpreg_cr = LED_InitStruct->TwinkleState << LED_CR_TWINK_EN_Pos 	|
				LED_InitStruct->FrameNumber << LED_CR_FRAME_Pos		   	|
				LED_InitStruct->RowLen								   	|
				LED_InitStruct->ColumnLen								|
				LED_InitStruct->RAMState << LED_CR_EN_RAM_Pos			|
				LED_InitStruct->EN_InversionState << LED_CR_INV_EN_Pos	|
				LED_InitStruct->Y_InversionState << LED_CR_INV_Y_Pos	|
				LED_InitStruct->C_InversionState << LED_CR_INV_C_Pos	|
				LED_InitStruct->DO_InversionState << LED_CR_INV_DO_Pos;

	MDR_LED->CR = tmpreg_cr;

	MDR_LED->DivR |= LED_InitStruct->TwinkleDIV << LED_DIVR_DIV_TWiNK_Pos;
}

/**
  * @brief	Enables or disables the specified LED peripheral.
  * @param	NewState: new state of the LED peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval	None.
  */
void LED_CMD(FunctionalState NewState)
{
	/* Check the parameters */
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(NewState != DISABLE){
		MDR_LED->CR |= LED_CR_DEN;
	}
	else{
		MDR_LED->CR &= ~LED_CR_DEN;
	}
}

/**
  * @brief	Enables or disables the output inversion.
  * @param	NewState: new state of the output inversion.
  *         This parameter can be: ENABLE or DISABLE.
  * @param	output: defines the specified yield.
  *         This parameter can be one of the following values:
  *         	@arg LED_INVERSION_Y
  *         	@arg LED_INVERSION_EN
  *         	@arg LED_INVERSION_C
  *         	@arg LED_INVERSION_DO
  * @retval	None.
  */
void LED_InversionOutputCMD(uint32_t output, FunctionalState NewState)
{
	/* Check the parameters */
	assert_param(IS_LED_INVERSION_OUTPUT(output));
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(NewState != DISABLE){
		MDR_LED->CR |= output;
	}
	else{
		MDR_LED->CR &= ~output;
	}
}

/**
  * @brief	Enables or disables the LED interrupt.
  * @param	NewState: new state of the LED interrupt.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval	None.
  */
void LED_ITCMD(FunctionalState NewState)
{
	/* Check the parameters */
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(NewState != DISABLE){
		MDR_LED->CR |= LED_CR_INTEN;
	}
	else{
		MDR_LED->CR &= ~LED_CR_INTEN;
	}
}

/**
  * @brief	Enables or disables the display flicker.
  * @param	NewState: new state of the display flicker.
  * @retval None.
  */
void LED_TwinkleCMD(FunctionalState NewState)
{
	/* Check the parameters */
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(NewState != DISABLE){
		MDR_LED->CR |= LED_CR_TWINK_EN;
	}
	else{
		MDR_LED->CR &= ~LED_CR_TWINK_EN;
	}
}
/**
  * @brief	Checks the value of the flag display controller ready for recording
  * 		data.
  * @param	None.
  * @retval	ready_flag: the current state of the ready flag.
  */
FlagStatus LED_GetReadyFlag(void)
{
	FlagStatus ready_flag;

	if(MDR_LED->SR & LED_SR_WR_REDY){
		ready_flag = SET;
	}
	else{
		ready_flag = RESET;
	}
	return (ready_flag);
}

/**
  * @brief	Initializes buffer graphics decoding ASCII characters symbols.
  * @param	None.
  * @retval	None.
  */
void LED_InitDecodeBuf(void)
{
	uint32_t i,j,l;
	for (i = 0, l = 0; i < 5; i++){
		for(j = 0; j < 256; j+=4){
			MDR_LED->DecodeBuf[l++] = (uint32_t)(uint32_t)((font5x7[j*5 + i]) >> 1 )
									| ((uint32_t)(font5x7[j*5 + i + 5] >> 1 ) << 8)
					                | ((uint32_t)(font5x7[j*5 + i + 10] >> 1 ) << 16)
					                | ((uint32_t)(font5x7[j*5 + i + 15] >> 1 ) << 24);
		}
	}
}

/**
  * @brief	Clear the frame of the LED text buffer.
  * @param	led_frame: the number of the cleared frame.
  * @retval	None.
  */
void LED_ClearFrame(uint32_t led_frame)
{
	uint32_t i;
	/* Check the parameters */
	assert_param(IS_LED_FRAME(led_frame));

	for(i = 0; i < 64; i++){
		MDR_LED->TextBuf[led_frame * 64 + i ] = 0;
	}
}

/**
  * @brief	Push string to the LED text buffer.
  * @param	position: the first symbol position in LED text buffer.
  * @param	ptr_char: pointer to the recording string.
  * @retval	None.
  */
void LED_PutString(uint32_t position, const char * ptr_char)
{
	uint32_t * ptr_TextBuf;
	uint8_t * ptr_input_char;
	uint32_t tmp_data;
	/* Check the parameters */
	assert_param(IS_LED_POSITION(position));

	ptr_TextBuf = (uint32_t * )MDR_LED->TextBuf;
	ptr_input_char = (uint8_t * )ptr_char;

	while((position < 256) && (*ptr_input_char != 0)){
		tmp_data = *((uint32_t *)((uint32_t)(ptr_TextBuf + (position>>2))&0xFFFFFFFC));
		tmp_data &= ~(0xFF << (position&0x03)*8);
		tmp_data |= *ptr_input_char++ << ((position&0x03)*8);

		*(ptr_TextBuf + (position++ >> 2)) = tmp_data;
	}
}

/** @} */ /* End of group LED_Private_Functions */

#endif

/** @} */ /* End of group LED */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

/*
*
* END OF FILE MDR32F9Qx_led.c */
