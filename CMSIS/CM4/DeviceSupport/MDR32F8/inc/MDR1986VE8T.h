/*
 *-----------------------------------------------------------------------------
 * The confidential and proprietary information contained in this file may
 * only be used by a person authorised under and to the extent permitted
 * by a subsisting licensing agreement from ARM Limited.
 *
 *            (C) COPYRIGHT 2009-2010 ARM Limited.
 *                ALL RIGHTS RESERVED
 *
 * This entire notice must be reproduced on all copies of this file
 * and copies of this file may only be made by a person if such person is
 * permitted to do so under the terms of a subsisting license agreement
 * from ARM Limited.
 *
 *      SVN Information
 *
 *
 *      Revision            : $Revision: 142008 $
 *
 *      Release information : cortexm4_r0p1_00rel0
 *-----------------------------------------------------------------------------
 */

#ifndef __MDR1986VE8T_H__
#define __MDR1986VE8T_H__

/*
 * ==========================================================================
 * ---------- Interrupt Number Definition -----------------------------------
 * ==========================================================================
 */

typedef enum IRQn
{
/******  Cortex-M4 Processor Exceptions Numbers ***************************************************/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                             */
  HardFault_IRQn              = -13,    /*!< 3 Cortex-M4 Hard Fault Interrupt                     */
  SVCall_IRQn                 = -5,     /*!< 11 Cortex-M4 SV Call Interrupt                       */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M4 Pend SV Interrupt                       */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M4 System Tick Interrupt                   */

/******  CM4IKMCU Cortex-M4 specific Interrupt Numbers ********************************************/
                                       
  FT_IF0_IRQn             = 32,
  FT_IF1_IRQn             = 33,
  FT_IF2_IRQn             = 34,
  FT_IF3_IRQn             = 35,
  CLK_IF_IRQn             = 36,
  PVD_IF_IRQn             = 37,
  RTC_IF_IRQn             = 38,
  BKP_IF_IRQn             = 39,
  EXT_INTERROR0_IRQn      = 40,
  EXT_INTERROR1_IRQn      = 41,
  EXT_INTERROR2_IRQn      = 42,
  EXT_INTERROR3_IRQn      = 43,
  EXT_INTERROR4_IRQn      = 44,
  EXT_INTERROR5_IRQn      = 45,
  EXT_INTERROR6_IRQn      = 46,
  EXT_INTERROR7_IRQn      = 47,
  IF_ERR_SCR_IRQn         = 48,
  IF_FIN_SCR_IRQn         = 49,
  DMA_ERR_IRQn            = 50,
  
  DMA_DONE0_IRQn          = 51,
  DMA_DONE1_IRQn          = 52,
  DMA_DONE2_IRQn          = 53,
  DMA_DONE3_IRQn          = 54,
  DMA_DONE4_IRQn          = 55,
  DMA_DONE5_IRQn          = 56,
  DMA_DONE6_IRQn          = 57,
  DMA_DONE7_IRQn          = 58,
  DMA_DONE8_IRQn          = 59,
  DMA_DONE9_IRQn          = 60,
  DMA_DONE10_IRQn         = 61,
  DMA_DONE11_IRQn         = 62,
  DMA_DONE12_IRQn         = 63,
  DMA_DONE13_IRQn         = 64,
  DMA_DONE14_IRQn         = 65,
  DMA_DONE15_IRQn         = 66,  
  DMA_DONE16_IRQn         = 67,
  DMA_DONE17_IRQn         = 68,
  DMA_DONE18_IRQn         = 69,
  DMA_DONE19_IRQn         = 70,
  DMA_DONE20_IRQn         = 71,
  DMA_DONE21_IRQn         = 72,
  DMA_DONE22_IRQn         = 73,
  DMA_DONE23_IRQn         = 74,
  DMA_DONE24_IRQn         = 75,
  DMA_DONE25_IRQn         = 76,  
  DMA_DONE26_IRQn         = 77,
  DMA_DONE27_IRQn         = 78,
  DMA_DONE28_IRQn         = 79,
  DMA_DONE29_IRQn         = 80,
  DMA_DONE30_IRQn         = 81,
  DMA_DONE31_IRQn         = 82,
  
  PORTA_IRQn         		  = 83,
  PORTB_IRQn         		  = 84,
  PORTC_IRQn         		  = 85,
  PORTD_IRQn         		  = 86,
  PORTE_IRQn         		  = 87,
  PORTF_IRQn         		  = 88,	
  
  ETH0_IRQn         		  = 89,
  ETH1_IRQn         		  = 90,	
  SPW0_IRQn        			  = 91,
  SPW1_IRQn        			  = 92,
  
  TMR0_IRQn         			= 93,
  TMR1_IRQn         			= 94,
  TMR2_IRQn         			= 95,
  TMR3_IRQn         			= 96,
  TMR4_IRQn         			= 97,
  TMR5_IRQn         			= 98,
  
  CAN0_IRQn         			= 99,
  CAN1_IRQn         			= 100,
  CAN2_IRQn         			= 101,
  CAN3_IRQn         			= 102,
  CAN4_IRQn         			= 103,
  
	SSP0_IRQn         		  = 104,
  SSP1_IRQn         		  = 105,
  SSP2_IRQn         		  = 106,
  SSP3_IRQn         		  = 107,
  
  UART0_IRQn         		  = 108,	
  UART1_IRQn         		  = 109,	
  UART2_IRQn         		  = 110,	
  UART3_IRQn         		  = 111,
  
  USB_IRQn         		    = 112,
  
  ARC0_RX_IRQn         		= 113,
  ARC0_TX_IRQn        	 	= 114,	
  ARC1_RX_IRQn         		= 115,
  ARC1_TX_IRQn        	 	= 116,	  
  
  MIL0_IRQn         			= 117,
  MIL1_IRQn         			= 118,
  ADC0_IRQn         			= 119,
  ADC1_IRQn         			= 120,
  DAC0_IRQn         			= 121,
  DAC1_IRQn         			= 122,
  
  CRYPTO_IRQn       			= 123,
  CRC_IRQn       			    = 124,
  ECC_IRQn       			    = 125,
} IRQn_Type;


/*
 * ==========================================================================
 * ----------- Processor and Core Peripheral Section ------------------------
 * ==========================================================================
 */

/* Configuration of the Cortex-M4 Processor and Core Peripherals */
#define __MPU_PRESENT           1       /*!< cm4ikmcu does not provide a MPU present or not       */
#define __NVIC_PRIO_BITS        3       /*!< cm4ikmcu Supports 3 Bits for the Priority Levels     */
#define __Vendor_SysTickConfig  0       /*!< Set to 1 if different SysTick Config is used         */


#include "core_cm4.h"                   /* Cortex-M4 processor and core peripherals               */
//#include "system_cm4ikmcu.h"            /* cm4ikmcu System                                        */

/** @defgroup __Exported_types Exported types
  * @{
  */

typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus, BitStatus;

#define IS_BIT_STATUS(STATUS)	(((STATUS) == RESET) || ((STATE) == SET))

typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;
#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

typedef enum {ERROR = 0, SUCCESS = !ERROR} ErrorStatus;

/**
  * @}
  */ 	

/**
 * Initialize the system clock
 *
 * @param  none
 * @return none
 *
 * @brief  Setup the microcontroller system
 *         Initialize the PLL and update the SystemFrequency variable
 */
extern void SystemInit (void);


/******************************************************************************/
/*                Device Specific Peripheral registers structures             */
/******************************************************************************/

/*--------------------- General Purpose Input and Ouptut ---------------------*/
typedef union
{
  __IO uint32_t WORD;
  __IO uint16_t HALFWORD[2];
  __IO uint8_t  BYTE[4];
} GPIO_Data_TypeDef;

typedef struct
{
  GPIO_Data_TypeDef DATA [256];
  GPIO_Data_TypeDef DIR;
  uint32_t RESERVED[3];
  GPIO_Data_TypeDef IE;
} GPIO_TypeDef;


/***
*  DMA control
**/
typedef struct
{
  __IO	uint32_t STATUS;
  __IO	uint32_t CONFIG;
  __IO	uint32_t CTRL_BASE_PTR;
  __IO	uint32_t ALT_CTRL_BASE_PTR;
  __IO	uint32_t WAITONREG_STATUS;
  __IO	uint32_t CHNL_SW_REQUEST;
  __IO	uint32_t CHNL_USEBURST_SET;
  __IO	uint32_t CHNL_USEBURST_CLR;
  __IO	uint32_t CHNL_REQ_MASK_SET;
  __IO	uint32_t CHNL_REQ_MASK_CLR;
  __IO	uint32_t CHNL_ENABLE_SET;
  __IO	uint32_t CHNL_ENABLE_CLR;
  __IO	uint32_t CHNL_PRI_ALT_SET;
  __IO	uint32_t CHNL_PRI_ALT_CLR;
  __IO	uint32_t CHNL_PRIORITY_SET;
  __IO	uint32_t CHNL_PRIORITY_CLR;
  uint32_t RESERVED[3];
  __IO	uint32_t ERR_CLR;
  __IO	uint32_t CHMUX0;
  __IO	uint32_t CHMUX1;
  __IO	uint32_t CHMUX2;
  __IO	uint32_t CHMUX3;
  __IO	uint32_t CHMUX4;
  __IO	uint32_t CHMUX5;
  __IO	uint32_t CHMUX6;
  __IO	uint32_t CHMUX7;
} DMAControl;

#define DMA_CNTR_BASE	    (( uint32_t) 0xe0042000)

#define	MDR_DMA		    ((DMAControl *) DMA_CNTR_BASE)

/** @defgroup MDR1986VE8T_Periph_DMA_Defines Defines
  * @{
  */

/** @defgroup MDR1986VE8T_DMA_STATUS	DMA STATUS
  * @{
  */ 

/*-- DMA_STATUS: DMA Status Register -------------------------------*/
/* Bit field positions: */
#define DMA_STATUS_MASTER_ENABLE_Pos            0
#define DMA_STATUS_STATE_Pos                    4
#define DMA_STATUS_CHNLS_MINUS1_Pos             16
#define DMA_STATUS_TEST_STATUS_Pos              28

/* Bit field masks: */
#define DMA_STATUS_MASTER_ENABLE                ((uint32_t)0x00000001)
#define DMA_STATUS_STATE_Msk                    ((uint32_t)0x000000F0)
#define DMA_STATUS_CHNLS_MINUS1_Msk             ((uint32_t)0x001F0000)
#define DMA_STATUS_TEST_STATUS_Msk              ((uint32_t)0xF0000000)

/** @} */ /* End of group DMA_STATUS */

/** @defgroup MDR1986VE8T_DMA_CFG	DMA CFG
  * @{
  */ 

/*-- DMA_CFG: DMA Configuration Register ---------------------------*/
/* Bit field positions: */
#define DMA_CFG_MASTER_ENABLE_Pos               0
#define DMA_CFG_CHNL_PROT_CTRL_Pos              5

/* Bit field masks: */
#define DMA_CFG_MASTER_ENABLE                   ((uint32_t)0x00000001)
#define DMA_CFG_CHNL_PROT_CTRL_Msk              ((uint32_t)0x000000E0)

/** @} */ /* End of group DMA_CFG */

/** @} */ /* End of group MDR1986VE8T_Periph_DMA_Defines */

/***
*  DMA Primary data structure
**/

typedef struct
{
  __IO	uint32_t PRIMARY_CH0_SOURCE_END_POINTER;
  __IO	uint32_t PRIMARY_CH0_DEST_END_POINTER;
  __IO	uint32_t PRIMARY_CH0_CONTROL;
  __IO	uint32_t PRIMARY_CH0_UNUSED;
 
  __IO	uint32_t PRIMARY_CH1_SOURCE_END_POINTER;
  __IO	uint32_t PRIMARY_CH1_DEST_END_POINTER;
  __IO	uint32_t PRIMARY_CH1_CONTROL;
  __IO	uint32_t PRIMARY_CH1_UNUSED;

  __IO	uint32_t PRIMARY_CH2_SOURCE_END_POINTER;
  __IO	uint32_t PRIMARY_CH2_DEST_END_POINTER;
  __IO	uint32_t PRIMARY_CH2_CONTROL;
  __IO	uint32_t PRIMARY_CH2_UNUSED;
 
  __IO	uint32_t PRIMARY_CH3_SOURCE_END_POINTER;
  __IO	uint32_t PRIMARY_CH3_DEST_END_POINTER;
  __IO	uint32_t PRIMARY_CH3_CONTROL;
  __IO	uint32_t PRIMARY_CH3_UNUSED;

  __IO	uint32_t PRIMARY_CH4_SOURCE_END_POINTER;
  __IO	uint32_t PRIMARY_CH4_DEST_END_POINTER;
  __IO	uint32_t PRIMARY_CH4_CONTROL;
  __IO	uint32_t PRIMARY_CH4_UNUSED;
 
  __IO	uint32_t PRIMARY_CH5_SOURCE_END_POINTER;
  __IO	uint32_t PRIMARY_CH5_DEST_END_POINTER;
  __IO	uint32_t PRIMARY_CH5_CONTROL;
  __IO	uint32_t PRIMARY_CH5_UNUSED;

  __IO	uint32_t PRIMARY_CH6_SOURCE_END_POINTER;
  __IO	uint32_t PRIMARY_CH6_DEST_END_POINTER;
  __IO	uint32_t PRIMARY_CH6_CONTROL;
  __IO	uint32_t PRIMARY_CH6_UNUSED;
 
  __IO	uint32_t PRIMARY_CH7_SOURCE_END_POINTER;
  __IO	uint32_t PRIMARY_CH7_DEST_END_POINTER;
  __IO	uint32_t PRIMARY_CH7_CONTROL;
  __IO	uint32_t PRIMARY_CH7_UNUSED;

  __IO	uint32_t PRIMARY_CH8_SOURCE_END_POINTER;
  __IO	uint32_t PRIMARY_CH8_DEST_END_POINTER;
  __IO	uint32_t PRIMARY_CH8_CONTROL;
  __IO	uint32_t PRIMARY_CH8_UNUSED;
 
  __IO	uint32_t PRIMARY_CH9_SOURCE_END_POINTER;
  __IO	uint32_t PRIMARY_CH9_DEST_END_POINTER;
  __IO	uint32_t PRIMARY_CH9_CONTROL;
  __IO	uint32_t PRIMARY_CH9_UNUSED;

  __IO	uint32_t PRIMARY_CH10_SOURCE_END_POINTER;
  __IO	uint32_t PRIMARY_CH10_DEST_END_POINTER;
  __IO	uint32_t PRIMARY_CH10_CONTROL;
  __IO	uint32_t PRIMARY_CH10_UNUSED;
 
  __IO	uint32_t PRIMARY_CH11_SOURCE_END_POINTER;
  __IO	uint32_t PRIMARY_CH11_DEST_END_POINTER;
  __IO	uint32_t PRIMARY_CH11_CONTROL;
  __IO	uint32_t PRIMARY_CH11_UNUSED;

  __IO	uint32_t PRIMARY_CH12_SOURCE_END_POINTER;
  __IO	uint32_t PRIMARY_CH12_DEST_END_POINTER;
  __IO	uint32_t PRIMARY_CH12_CONTROL;
  __IO	uint32_t PRIMARY_CH12_UNUSED;
 
  __IO	uint32_t PRIMARY_CH13_SOURCE_END_POINTER;
  __IO	uint32_t PRIMARY_CH13_DEST_END_POINTER;
  __IO	uint32_t PRIMARY_CH13_CONTROL;
  __IO	uint32_t PRIMARY_CH13_UNUSED;

  __IO	uint32_t PRIMARY_CH14_SOURCE_END_POINTER;
  __IO	uint32_t PRIMARY_CH14_DEST_END_POINTER;
  __IO	uint32_t PRIMARY_CH14_CONTROL;
  __IO	uint32_t PRIMARY_CH14_UNUSED;
 
  __IO	uint32_t PRIMARY_CH15_SOURCE_END_POINTER;
  __IO	uint32_t PRIMARY_CH15_DEST_END_POINTER;
  __IO	uint32_t PRIMARY_CH15_CONTROL;
  __IO	uint32_t PRIMARY_CH15_UNUSED;

  __IO	uint32_t PRIMARY_CH16_SOURCE_END_POINTER;
  __IO	uint32_t PRIMARY_CH16_DEST_END_POINTER;
  __IO	uint32_t PRIMARY_CH16_CONTROL;
  __IO	uint32_t PRIMARY_CH16_UNUSED;
 
  __IO	uint32_t PRIMARY_CH17_SOURCE_END_POINTER;
  __IO	uint32_t PRIMARY_CH17_DEST_END_POINTER;
  __IO	uint32_t PRIMARY_CH17_CONTROL;
  __IO	uint32_t PRIMARY_CH17_UNUSED;

  __IO	uint32_t PRIMARY_CH18_SOURCE_END_POINTER;
  __IO	uint32_t PRIMARY_CH18_DEST_END_POINTER;
  __IO	uint32_t PRIMARY_CH18_CONTROL;
  __IO	uint32_t PRIMARY_CH18_UNUSED;
 
  __IO	uint32_t PRIMARY_CH19_SOURCE_END_POINTER;
  __IO	uint32_t PRIMARY_CH19_DEST_END_POINTER;
  __IO	uint32_t PRIMARY_CH19_CONTROL;
  __IO	uint32_t PRIMARY_CH19_UNUSED;

  __IO	uint32_t PRIMARY_CH20_SOURCE_END_POINTER;
  __IO	uint32_t PRIMARY_CH20_DEST_END_POINTER;
  __IO	uint32_t PRIMARY_CH20_CONTROL;
  __IO	uint32_t PRIMARY_CH20_UNUSED;
 
  __IO	uint32_t PRIMARY_CH21_SOURCE_END_POINTER;
  __IO	uint32_t PRIMARY_CH21_DEST_END_POINTER;
  __IO	uint32_t PRIMARY_CH21_CONTROL;
  __IO	uint32_t PRIMARY_CH21_UNUSED;

  __IO	uint32_t PRIMARY_CH22_SOURCE_END_POINTER;
  __IO	uint32_t PRIMARY_CH22_DEST_END_POINTER;
  __IO	uint32_t PRIMARY_CH22_CONTROL;
  __IO	uint32_t PRIMARY_CH22_UNUSED;
 
  __IO	uint32_t PRIMARY_CH23_SOURCE_END_POINTER;
  __IO	uint32_t PRIMARY_CH23_DEST_END_POINTER;
  __IO	uint32_t PRIMARY_CH23_CONTROL;
  __IO	uint32_t PRIMARY_CH23_UNUSED;

  __IO	uint32_t PRIMARY_CH24_SOURCE_END_POINTER;
  __IO	uint32_t PRIMARY_CH24_DEST_END_POINTER;
  __IO	uint32_t PRIMARY_CH24_CONTROL;
  __IO	uint32_t PRIMARY_CH24_UNUSED;
 
  __IO	uint32_t PRIMARY_CH25_SOURCE_END_POINTER;
  __IO	uint32_t PRIMARY_CH25_DEST_END_POINTER;
  __IO	uint32_t PRIMARY_CH25_CONTROL;
  __IO	uint32_t PRIMARY_CH25_UNUSED;

  __IO	uint32_t PRIMARY_CH26_SOURCE_END_POINTER;
  __IO	uint32_t PRIMARY_CH26_DEST_END_POINTER;
  __IO	uint32_t PRIMARY_CH26_CONTROL;
  __IO	uint32_t PRIMARY_CH26_UNUSED;
 
  __IO	uint32_t PRIMARY_CH27_SOURCE_END_POINTER;
  __IO	uint32_t PRIMARY_CH27_DEST_END_POINTER;
  __IO	uint32_t PRIMARY_CH27_CONTROL;
  __IO	uint32_t PRIMARY_CH27_UNUSED;

  __IO	uint32_t PRIMARY_CH28_SOURCE_END_POINTER;
  __IO	uint32_t PRIMARY_CH28_DEST_END_POINTER;
  __IO	uint32_t PRIMARY_CH28_CONTROL;
  __IO	uint32_t PRIMARY_CH28_UNUSED;
 
  __IO	uint32_t PRIMARY_CH29_SOURCE_END_POINTER;
  __IO	uint32_t PRIMARY_CH29_DEST_END_POINTER;
  __IO	uint32_t PRIMARY_CH29_CONTROL;
  __IO	uint32_t PRIMARY_CH29_UNUSED;

  __IO	uint32_t PRIMARY_CH30_SOURCE_END_POINTER;
  __IO	uint32_t PRIMARY_CH30_DEST_END_POINTER;
  __IO	uint32_t PRIMARY_CH30_CONTROL;
  __IO	uint32_t PRIMARY_CH30_UNUSED;
 
  __IO	uint32_t PRIMARY_CH31_SOURCE_END_POINTER;
  __IO	uint32_t PRIMARY_CH31_DEST_END_POINTER;
  __IO	uint32_t PRIMARY_CH31_CONTROL;
  __IO	uint32_t PRIMARY_CH31_UNUSED;
} DMA_PrimaryData_TypeDef;

/***
*  DMA Alternate data structure
**/

typedef struct
{
  __IO	uint32_t ALTER_CH0_SOURCE_END_POINTER;
  __IO	uint32_t ALTER_CH0_DEST_END_POINTER;
  __IO	uint32_t ALTER_CH0_CONTROL;
  __IO	uint32_t ALTER_CH0_UNUSED;
 
  __IO	uint32_t ALTER_CH1_SOURCE_END_POINTER;
  __IO	uint32_t ALTER_CH1_DEST_END_POINTER;
  __IO	uint32_t ALTER_CH1_CONTROL;
  __IO	uint32_t ALTER_CH1_UNUSED;

  __IO	uint32_t ALTER_CH2_SOURCE_END_POINTER;
  __IO	uint32_t ALTER_CH2_DEST_END_POINTER;
  __IO	uint32_t ALTER_CH2_CONTROL;
  __IO	uint32_t ALTER_CH2_UNUSED;
 
  __IO	uint32_t ALTER_CH3_SOURCE_END_POINTER;
  __IO	uint32_t ALTER_CH3_DEST_END_POINTER;
  __IO	uint32_t ALTER_CH3_CONTROL;
  __IO	uint32_t ALTER_CH3_UNUSED;

  __IO	uint32_t ALTER_CH4_SOURCE_END_POINTER;
  __IO	uint32_t ALTER_CH4_DEST_END_POINTER;
  __IO	uint32_t ALTER_CH4_CONTROL;
  __IO	uint32_t ALTER_CH4_UNUSED;
 
  __IO	uint32_t ALTER_CH5_SOURCE_END_POINTER;
  __IO	uint32_t ALTER_CH5_DEST_END_POINTER;
  __IO	uint32_t ALTER_CH5_CONTROL;
  __IO	uint32_t ALTER_CH5_UNUSED;

  __IO	uint32_t ALTER_CH6_SOURCE_END_POINTER;
  __IO	uint32_t ALTER_CH6_DEST_END_POINTER;
  __IO	uint32_t ALTER_CH6_CONTROL;
  __IO	uint32_t ALTER_CH6_UNUSED;
 
  __IO	uint32_t ALTER_CH7_SOURCE_END_POINTER;
  __IO	uint32_t ALTER_CH7_DEST_END_POINTER;
  __IO	uint32_t ALTER_CH7_CONTROL;
  __IO	uint32_t ALTER_CH7_UNUSED;

  __IO	uint32_t ALTER_CH8_SOURCE_END_POINTER;
  __IO	uint32_t ALTER_CH8_DEST_END_POINTER;
  __IO	uint32_t ALTER_CH8_CONTROL;
  __IO	uint32_t ALTER_CH8_UNUSED;
 
  __IO	uint32_t ALTER_CH9_SOURCE_END_POINTER;
  __IO	uint32_t ALTER_CH9_DEST_END_POINTER;
  __IO	uint32_t ALTER_CH9_CONTROL;
  __IO	uint32_t ALTER_CH9_UNUSED;

  __IO	uint32_t ALTER_CH10_SOURCE_END_POINTER;
  __IO	uint32_t ALTER_CH10_DEST_END_POINTER;
  __IO	uint32_t ALTER_CH10_CONTROL;
  __IO	uint32_t ALTER_CH10_UNUSED;
 
  __IO	uint32_t ALTER_CH11_SOURCE_END_POINTER;
  __IO	uint32_t ALTER_CH11_DEST_END_POINTER;
  __IO	uint32_t ALTER_CH11_CONTROL;
  __IO	uint32_t ALTER_CH11_UNUSED;

  __IO	uint32_t ALTER_CH12_SOURCE_END_POINTER;
  __IO	uint32_t ALTER_CH12_DEST_END_POINTER;
  __IO	uint32_t ALTER_CH12_CONTROL;
  __IO	uint32_t ALTER_CH12_UNUSED;
 
  __IO	uint32_t ALTER_CH13_SOURCE_END_POINTER;
  __IO	uint32_t ALTER_CH13_DEST_END_POINTER;
  __IO	uint32_t ALTER_CH13_CONTROL;
  __IO	uint32_t ALTER_CH13_UNUSED;

  __IO	uint32_t ALTER_CH14_SOURCE_END_POINTER;
  __IO	uint32_t ALTER_CH14_DEST_END_POINTER;
  __IO	uint32_t ALTER_CH14_CONTROL;
  __IO	uint32_t ALTER_CH14_UNUSED;
 
  __IO	uint32_t ALTER_CH15_SOURCE_END_POINTER;
  __IO	uint32_t ALTER_CH15_DEST_END_POINTER;
  __IO	uint32_t ALTER_CH15_CONTROL;
  __IO	uint32_t ALTER_CH15_UNUSED;

  __IO	uint32_t ALTER_CH16_SOURCE_END_POINTER;
  __IO	uint32_t ALTER_CH16_DEST_END_POINTER;
  __IO	uint32_t ALTER_CH16_CONTROL;
  __IO	uint32_t ALTER_CH16_UNUSED;
 
  __IO	uint32_t ALTER_CH17_SOURCE_END_POINTER;
  __IO	uint32_t ALTER_CH17_DEST_END_POINTER;
  __IO	uint32_t ALTER_CH17_CONTROL;
  __IO	uint32_t ALTER_CH17_UNUSED;

  __IO	uint32_t ALTER_CH18_SOURCE_END_POINTER;
  __IO	uint32_t ALTER_CH18_DEST_END_POINTER;
  __IO	uint32_t ALTER_CH18_CONTROL;
  __IO	uint32_t ALTER_CH18_UNUSED;
 
  __IO	uint32_t ALTER_CH19_SOURCE_END_POINTER;
  __IO	uint32_t ALTER_CH19_DEST_END_POINTER;
  __IO	uint32_t ALTER_CH19_CONTROL;
  __IO	uint32_t ALTER_CH19_UNUSED;

  __IO	uint32_t ALTER_CH20_SOURCE_END_POINTER;
  __IO	uint32_t ALTER_CH20_DEST_END_POINTER;
  __IO	uint32_t ALTER_CH20_CONTROL;
  __IO	uint32_t ALTER_CH20_UNUSED;
 
  __IO	uint32_t ALTER_CH21_SOURCE_END_POINTER;
  __IO	uint32_t ALTER_CH21_DEST_END_POINTER;
  __IO	uint32_t ALTER_CH21_CONTROL;
  __IO	uint32_t ALTER_CH21_UNUSED;

  __IO	uint32_t ALTER_CH22_SOURCE_END_POINTER;
  __IO	uint32_t ALTER_CH22_DEST_END_POINTER;
  __IO	uint32_t ALTER_CH22_CONTROL;
  __IO	uint32_t ALTER_CH22_UNUSED;
 
  __IO	uint32_t ALTER_CH23_SOURCE_END_POINTER;
  __IO	uint32_t ALTER_CH23_DEST_END_POINTER;
  __IO	uint32_t ALTER_CH23_CONTROL;
  __IO	uint32_t ALTER_CH23_UNUSED;

  __IO	uint32_t ALTER_CH24_SOURCE_END_POINTER;
  __IO	uint32_t ALTER_CH24_DEST_END_POINTER;
  __IO	uint32_t ALTER_CH24_CONTROL;
  __IO	uint32_t ALTER_CH24_UNUSED;
 
  __IO	uint32_t ALTER_CH25_SOURCE_END_POINTER;
  __IO	uint32_t ALTER_CH25_DEST_END_POINTER;
  __IO	uint32_t ALTER_CH25_CONTROL;
  __IO	uint32_t ALTER_CH25_UNUSED;

  __IO	uint32_t ALTER_CH26_SOURCE_END_POINTER;
  __IO	uint32_t ALTER_CH26_DEST_END_POINTER;
  __IO	uint32_t ALTER_CH26_CONTROL;
  __IO	uint32_t ALTER_CH26_UNUSED;
 
  __IO	uint32_t ALTER_CH27_SOURCE_END_POINTER;
  __IO	uint32_t ALTER_CH27_DEST_END_POINTER;
  __IO	uint32_t ALTER_CH27_CONTROL;
  __IO	uint32_t ALTER_CH27_UNUSED;

  __IO	uint32_t ALTER_CH28_SOURCE_END_POINTER;
  __IO	uint32_t ALTER_CH28_DEST_END_POINTER;
  __IO	uint32_t ALTER_CH28_CONTROL;
  __IO	uint32_t ALTER_CH28_UNUSED;
 
  __IO	uint32_t ALTER_CH29_SOURCE_END_POINTER;
  __IO	uint32_t ALTER_CH29_DEST_END_POINTER;
  __IO	uint32_t ALTER_CH29_CONTROL;
  __IO	uint32_t ALTER_CH29_UNUSED;

  __IO	uint32_t ALTER_CH30_SOURCE_END_POINTER;
  __IO	uint32_t ALTER_CH30_DEST_END_POINTER;
  __IO	uint32_t ALTER_CH30_CONTROL;
  __IO	uint32_t ALTER_CH30_UNUSED;
 
  __IO	uint32_t ALTER_CH31_SOURCE_END_POINTER;
  __IO	uint32_t ALTER_CH31_DEST_END_POINTER;
  __IO	uint32_t ALTER_CH31_CONTROL;
  __IO	uint32_t ALTER_CH31_UNUSED;
} DMA_AlterData_TypeDef;
/***

*  Cache control
**/
typedef struct
{
  __IO	uint32_t KEY;
  __IO	uint32_t CNTL;
  __I	uint32_t HIT_CNT;
  __I	uint32_t MISS_CNT;
  uint32_t RESERVED[4];
  __IO	uint32_t ECC_CNTL;
  __IO	uint32_t ECC_ADDR;
  __IO	uint32_t ECC_DATA;
  __IO	uint32_t ECC_ECC;
} CacheControl;

#define ICACHE_BASE	    (( uint32_t) 0xe0044000)
#define DCACHE_BASE	    (( uint32_t) 0xe0045000)

#define	ICACHE		    ((CacheControl *) ICACHE_BASE)
#define DCACHE		    ((CacheControl *) DCACHE_BASE)

#define CC_CACHE_ENABLE ((uint32_t) 0x1)
#define CC_CACHE_CLR	((uint32_t) (1<<1))
#define CC_OTP_ENABLE	((uint32_t) (1<<2))
#define CC_EXTB_ENABLE	((uint32_t) (1<<3))
#define CC_HIT_CLR	((uint32_t) (1<<4))
#define CC_MISS_CLR	((uint32_t) (1<<5))

#define CC_KEY			((uint32_t) 0x8555aaa1)

/***
*  SCRABER control
**/
typedef struct
{
  __IO	uint32_t CNTRL;
  __IO	uint32_t S_ADDR;
  __IO	uint32_t F_ADDR;
  __IO	uint32_t DATA;
  __IO	uint32_t SECC;
} SCRControl;

#define SCR_CNTR_BASE	    (( uint32_t) 0xe0043000)

#define	SCR_CNTR	    ((SCRControl *) SCR_CNTR_BASE)

/***
*  FT control
**/
typedef struct
{
  __IO	uint32_t KEY;
  __IO	uint32_t CONTROL;
  __IO	uint32_t STATUS;
  __IO	uint32_t TIMEOUT;
  __IO	uint32_t TICKCNT;
  __IO	uint32_t FIRSTEVENT;
  __IO	uint32_t LASTEVENT;
  __IO	uint32_t TIMEOUTCNT;
  __IO	uint32_t EVENT[13];
  __IO	uint32_t RESET_EVENT0;
  __IO	uint32_t RESET_EVENT1;
  __IO	uint32_t RESET_EVENT2;
  __IO	uint32_t RESET_EVENT3;
  __IO	uint32_t RESET_EVENT4;
  __IO	uint32_t IE_EVENT5;
  __IO	uint32_t IE_EVENT6;
  __IO	uint32_t IE_EVENT7;
  __IO	uint32_t IE_EVENT8;
  __IO	uint32_t IE_EVENT9;
  __IO	uint32_t IE_EVENT10;
  __IO	uint32_t IE_EVENT11;
  __IO	uint32_t IE_EVENT12;
  __IO	uint32_t FT_STAT0;
  __IO	uint32_t FT_STAT1;
} FTControl;

#define FT_CNTR_BASE	    (( uint32_t) 0x40003000)

#define	FT_CNTR		    ((FTControl *) FT_CNTR_BASE)


/***
*  OTP control
**/

typedef struct
{
  __IO	uint32_t KEY;
  __IO	uint32_t CNTR;
  __IO	uint32_t ADR;
  __IO	uint32_t WDATA;
  __IO	uint32_t RDATA;
  __IO	uint32_t ECCCS;
  __IO	uint32_t ECCADR;
  __IO	uint32_t ECCDATA;
  __IO	uint32_t ECCECC;
  __IO	uint32_t TEST_TUNING;
} OTPControl;


#define OTP_CNTR_BASE	    (( uint32_t) 0x40006000)

#define	OTP_CNTR	    ((OTPControl *) OTP_CNTR_BASE)
#define OTP_CNTR_WS	    ((uint32_t) 0x7)

/***
*  ROM,RAMC,RAMD control
**/

typedef struct
{
  __IO	uint32_t KEY;
  __IO	uint32_t ECCCS;
  __IO	uint32_t ECCADR;
  __IO	uint32_t ECCDATA;
  __IO	uint32_t ECCECC;
  __IO	uint32_t TEST_TUNING;
} MEMControl;


#define ROM_CNTR_BASE	    (( uint32_t) 0x40009000)
#define RAMC_CNTR_BASE	    (( uint32_t) 0x40007000)
#define RAMD_CNTR_BASE	    (( uint32_t) 0x40008000)

#define	ROM_CNTR	    ((MEMControl *) ROM_CNTR_BASE)
#define	RAMC_CNTR	    ((MEMControl *) RAMC_CNTR_BASE)
#define	RAMD_CNTR	    ((MEMControl *) RAMD_CNTR_BASE)

#define RCACHE_BASE	    (( uint32_t) 0x4000b000)
#define RCACHE		    ((CacheControl *) RCACHE_BASE)
/***
*  EXTBUS control
**/
typedef struct
{
  __IO	uint32_t KEY;
  __IO	uint32_t RGN0_CNTRL;
  __IO	uint32_t RGN1_CNTRL;
  __IO	uint32_t RGN2_CNTRL;
  __IO	uint32_t RGN3_CNTRL;
  __IO	uint32_t RGN4_CNTRL;
  __IO	uint32_t RGN5_CNTRL;
  __IO	uint32_t RGN6_CNTRL;
  __IO	uint32_t RGN7_CNTRL;
  
  __IO	uint32_t RGN0_ECCBASE;
  __IO	uint32_t RGN1_ECCBASE;
  __IO	uint32_t RGN2_ECCBASE;
  __IO	uint32_t RGN3_ECCBASE;
  __IO	uint32_t RGN4_ECCBASE;
  __IO	uint32_t RGN5_ECCBASE;
  __IO	uint32_t RGN6_ECCBASE;
  __IO	uint32_t RGN7_ECCBASE;
  
  __IO	uint32_t RGN0_ECCS;
  __IO	uint32_t RGN1_ECCS;
  __IO	uint32_t RGN2_ECCS;
  __IO	uint32_t RGN3_ECCS;
  __IO	uint32_t RGN4_ECCS;
  __IO	uint32_t RGN5_ECCS;
  __IO	uint32_t RGN6_ECCS;
  __IO	uint32_t RGN7_ECCS;
  

  __IO	uint32_t SPORT_PWR0;
  __IO	uint32_t SPORT_PWR1;
  __IO	uint32_t SPORT_PWR2;
  __IO	uint32_t SPORT_PWR3;
  
  __IO	uint32_t SPORT_PD0;
  __IO	uint32_t SPORT_PD1;
  __IO	uint32_t SPORT_PD2;
  __IO	uint32_t SPORT_PD3;

  __IO	uint32_t SPORT_CL0;
  __IO	uint32_t SPORT_CL1;
  __IO	uint32_t SPORT_CL2;
  __IO	uint32_t SPORT_CL3;
  
  __IO	uint32_t ECC_ADDR;
  __IO	uint32_t ECC_DATA;
  __IO	uint32_t ECC_ECC;
  
} EXTBUSControl;

#define EXT_BUS_CNTR_BASE	    (( uint32_t) 0x40005000)

#define	EXT_BUS_CNTR		    ((EXTBUSControl *) EXT_BUS_CNTR_BASE)

#define EB_CNTR_MODE(mode)  ((mode & 3) << 4)
#define EB_CNTR_ECCMODE	    4
#define EB_CNTR_ECCEN	    2
#define EB_CNTR_EN	    1
#define EB_CNTR_WS_HOLD(hold)  ((hold & 0xf) << 20)
#define EB_CNTR_WS_ACTIVE(act) ((act & 0xf) << 16)
#define EB_CNTR_WS_SETUP(setup) ((setup & 0xff) << 8)

#define EBC_ECCEN_pos							1
#define EBC_ECCMODE_pos						2
#define EBC_RDYWAIT_pos						3
#define EBC_MODE_pos							4
#define EBC_ROM_pos								6
#define EBC_CPOL_pos							7
#define EBC_WS_ACTIVE_pos					8
#define EBC_WS_SETUP_pos					16
#define EBC_WS_HOLD_pos						20
#define EBC_USESEPAR_pos					24
#define EBC_CACHEBLE_pos					25
#define EBC_READ32_pos						26
#define EBC_ENOCLK_pos						27
#define EBC_DIVOCLK_pos						28

#define EBC_ECCEN_MSK							((uint32_t) 0x00000002)
#define EBC_ECCMODE_MSK						((uint32_t) 0x00000004)
#define EBC_RDYWAIT_MSK						((uint32_t) 0x00000008)
#define EBC_MODE_MSK							((uint32_t) 0x00000030)
#define EBC_ROM_MSK								((uint32_t) 0x00000040)
#define EBC_CPOL_MSK							((uint32_t) 0x00000080)
#define EBC_WS_ACTIVE_MSK					((uint32_t) 0x0000FF00)
#define EBC_WS_SETUP_MSK					((uint32_t) 0x000F0000)
#define EBC_WS_HOLD_MSK						((uint32_t) 0x00F00000)
#define EBC_USESEPAR_MSK					((uint32_t) 0x01000000)
#define EBC_CACHEBLE_MSK					((uint32_t) 0x02000000)
#define EBC_READ32_MSK						((uint32_t) 0x04000000)
#define EBC_ENOCLK_MSK						((uint32_t) 0x08000000)
#define EBC_DIVOCLK_MSK						((uint32_t) 0xF0000000)

/***
*  PWR control
**/

typedef struct
{
  __IO	uint32_t KEY;
  
  __IO	uint32_t CNTR0;
  __IO	uint32_t CNTR1;
  __IO	uint32_t CNTR2;
  
  __IO	uint32_t STAT;

  __IO	uint32_t ULIMIT;
  __IO	uint32_t CLIMIT;
 
} PWRControl;


#define PWR_BASE	    (( uint32_t) 0x40002000)
#define	PWR	 	    ((PWRControl *) PWR_BASE)

/***
*  WDT control
**/


typedef struct
{
  __IO	uint32_t KEY;
  __IO	uint32_t PRL;
  __IO	uint32_t EN;
  __IO	uint32_t CNT;
 
} WDTControl;


#define WDT_BASE	    (( uint32_t) 0x40004000)
#define	WDT	 	    ((WDTControl *) WDT_BASE)

/***
*  ADCx control
**/

typedef struct
{
  __IO	uint32_t KEY;
  
  __IO	uint32_t CONFIG0;
  __IO	uint32_t CONFIG1;
  __IO	uint32_t CONFIG2;
  __IO	uint32_t CONTROL;
  __IO	uint32_t STATUS;

  __IO	uint32_t RESULT;
  __IO	uint32_t RESULTCH_xx[64];

  __IO	uint32_t MAX_LEVEL;
  __IO	uint32_t MIN_LEVEL;

  __IO	uint32_t CHSEL0;
  __IO	uint32_t CHSEL1;

  __IO	uint32_t DMAREQ;
  __IO	uint32_t STATRCH0;
  __IO	uint32_t STATRCH1;
  
  __IO	uint32_t FIFOEN0;
  __IO	uint32_t FIFOEN1;
 
} ADCxControl;


#define ADC0_BASE	    (( uint32_t) 0x400AA000)

#define	ADC0	 	    ((ADCxControl *) ADC0_BASE)

#define ADC1_BASE	    (( uint32_t) 0x400AB000)

#define	ADC1	 	    ((ADCxControl *) ADC1_BASE)

/** @defgroup MDR1986VE8T_ADC_Defines Defines
  * @{
  */

/** @defgroup MDR1986VE8T_ADC1_CFG	ADC1 CFG
  * @{
  */ 

/*-- CONFIG0: ADCx Configuration Register -------------------------*/
/* Bit field positions: */
#define ADCx_CONFIG0_ADCEN_Pos                  0
#define ADCx_CONFIG0_WORKMODE_Pos               1
#define ADCx_CONFIG0_REFMODE_Pos               	3
#define ADCx_CONFIG0_RH_MODE_Pos               	4
#define ADCx_CONFIG0_SELMODE_Pos                5
#define ADCx_CONFIG0_EXT_GO_INV_Pos             7
#define ADCx_CONFIG0_EXT_GO_SEL_Pos             8

/* Bit field masks: */
#define ADCx_CONFIG0_ADCEN               		((uint32_t)0x00000001)
#define ADCx_CONFIG0_WORKMODE               ((uint32_t)0x00000006)
#define ADCx_CONFIG0_REFMODE               	((uint32_t)0x00000008)
#define ADCx_CONFIG0_RH_MODE               	((uint32_t)0x00000010)
#define ADCx_CONFIG0_SELMODE                ((uint32_t)0x00000020)
#define ADCx_CONFIG0_EXT_GO_INV             ((uint32_t)0x00000080)
#define ADCx_CONFIG0_EXT_GO_SEL             ((uint32_t)0xFFFFFF00)

/** @} */ /* End of group CONFIG0 */

/*-- CONFIG1: ADCx Configuration Register -------------------------*/
/* Bit field positions: */
#define ADCx_CONFIG1_REFTRIM_Pos               0
#define ADCx_CONFIG1_SETUP_Pos               	 3
#define ADCx_CONFIG1_PAUSE_Pos               	 12
#define ADCx_CONFIG1_ADCTRIM_Pos               20

/* Bit field masks: */
#define ADCx_CONFIG1_REFTRIM               ((uint32_t)0x00000007)
#define ADCx_CONFIG1_SETUP               	 ((uint32_t)0x00000FF8)
#define ADCx_CONFIG1_PAUSE               	 ((uint32_t)0x000FF000)
#define ADCx_CONFIG1_ADCTRIM               ((uint32_t)0xFFF00000)

/** @} */ /* End of group CONFIG1 */

/*-- CONFIG2: ADCx Configuration Register -------------------------*/
/* Bit field positions: */
#define ADCx_CONFIG2_IE_NE_Pos               0
#define ADCx_CONFIG2_IE_OF_Pos               1
#define ADCx_CONFIG2_IE_NAE_Pos              2
#define ADCx_CONFIG2_IE_AF_Pos               3
#define ADCx_CONFIG2_IE_ERFIN_Pos            4
#define ADCx_CONFIG2_LEVLCNTRL_Pos           6
#define ADCx_CONFIG2_REFSEL_Pos              8
#define ADCx_CONFIG2_REFTRIMR_Pos            16
#define ADCx_CONFIG2_DT_MODE_Pos             24

/* Bit field masks: */
#define ADCx_CONFIG2_IE_NE               ((uint32_t)0x00000001)
#define ADCx_CONFIG2_IE_OF               ((uint32_t)0x00000002)
#define ADCx_CONFIG2_IE_NAE              ((uint32_t)0x00000004)
#define ADCx_CONFIG2_IE_AF               ((uint32_t)0x00000008)
#define ADCx_CONFIG2_IE_ERFIN            ((uint32_t)0x00000010)
#define ADCx_CONFIG2_LEVLCNTRL           ((uint32_t)0x000000C0)
#define ADCx_CONFIG2_REFSEL              ((uint32_t)0x0000FF00)
#define ADCx_CONFIG2_REFTRIMR            ((uint32_t)0x00FF0000)
#define ADCx_CONFIG2_DT_MODE             ((uint32_t)0x01000000)

/** @} */ /* End of group CONFIG2 */

/** @} */ /* End of group Periph_ADC_Defines */

/** @} */ /* End of group Periph_ADC */

/***
*  DACx control
**/

typedef struct
{
  __IO	uint32_t KEY;
  
  __IO	uint32_t CONFIG0;
  __IO	uint32_t CONFIG1;

  __IO	uint32_t DATA;

  __IO	uint32_t STATUS;
  __IO	uint32_t IMSK;
  __IO	uint32_t DMAREQ;
 
} DACxControl;


#define DAC0_BASE	    (( uint32_t) 0x400AC000)

#define	DAC0	 	    ((DACxControl *) DAC0_BASE)

#define DAC1_BASE	    (( uint32_t) 0x400AD000)

#define	DAC1	 	    ((DACxControl *) DAC1_BASE)

/** @defgroup MDR1986VE8T_Periph_DAC_Defines Defines
  * @{
  */

/** @defgroup Periph_DAC_CFG	DAC CFG
  * @{
  */ 

/*-- DAC_CFG: DAC Configuration Register ---------------------------*/
/* Bit field positions: */
#define DAC_CONFIG0_M_REF_Pos                   2
#define DAC_CONFIG0_SYNC_A_Pos                  1
#define DAC_CONFIG0_ON_DAC_Pos                  0


/* Bit field masks: */
#define DAC_CONFIG0_M_REF                   ((uint32_t) 0x0000000C)
#define DAC_CONFIG0_SYNC_A                  ((uint32_t) 0x00000002)
#define DAC_CONFIG0_ON_DAC                  ((uint32_t) 0x00000001)

/** @} */ /* End of group DAC_CFG */

/** @defgroup Periph_DAC_DATA	DAC DATA
  * @{
  */ 

/*-- DAC1_DATA: DAC1 Data Register ---------------------------------*/
/* Bit field masks: */
#define DAC_DATA_Msk                  			 ((uint32_t)0x00000FFF)

/** @} */ /* End of group DAC_DATA */

/** @} */ /* End of group MDR1986VE8T_Periph_DAC_Defines */

/***
*  CRC control
**/

typedef struct
{
  __IO	uint32_t KEY;
  __IO	uint32_t CTRL;
  __IO	uint32_t STAT;
  __IO	uint32_t DIN;
  __IO	uint32_t VALL;
  __IO	uint32_t VALH;
  __IO	uint32_t POLL;
  __IO	uint32_t POLH;
  __IO	uint32_t FINXORL;
  __IO	uint32_t FINXORH;
  __IO	uint32_t CNTFLOW;
} CRC_Control;

#define CRC_BASE	    (( uint32_t) 0x400AF000)

#define	CRC	 	    ((CRC_Control *) CRC_BASE)


/***
*  ECC control
**/

typedef struct
{
  __IO	uint32_t KEY;
  __IO	uint32_t CTRL;
  __IO	uint32_t STAT;
  __IO	uint32_t DATIL;
  __IO	uint32_t DATIH;
  __IO	uint32_t ECCI;
  __IO	uint32_t DLER;
  __IO	uint32_t DHER;
  __IO	uint32_t ECER;
  __IO	uint32_t DATOL;
  __IO	uint32_t DATOH;
  __IO	uint32_t ECCO;
  __IO	uint32_t H000;
  __IO	uint32_t H032;
  __IO	uint32_t H100;
  __IO	uint32_t H132;
  __IO	uint32_t H200;
  __IO	uint32_t H232;
  __IO	uint32_t H300;
  __IO	uint32_t H332;
  __IO	uint32_t H400;
  __IO	uint32_t H432;
  __IO	uint32_t H500;
  __IO	uint32_t H532;
  __IO	uint32_t H600;
  __IO	uint32_t H632;
  __IO	uint32_t H700;
  __IO	uint32_t H732;
  
} ECC_Control;

#define ECC_BASE	    (( uint32_t) 0x400B0000)

#define	ECC 	    ((ECC_Control *) ECC_BASE)


/***
*  BKP control
**/

typedef struct
{
  __IO	uint32_t REG_xx[60];
  __IO	uint32_t KEY;
  __IO	uint32_t RESERV_0[3];
  
  __IO	uint32_t REG_60_TMR0;
  __IO	uint32_t REG_61_TMR0;
  __IO	uint32_t REG_62_TMR0;
  __IO	uint32_t REG_63_TMR0
  ;
  __IO	uint32_t REG_60_TMR1;
  __IO	uint32_t REG_61_TMR1;
  __IO	uint32_t REG_62_TMR1;
  __IO	uint32_t REG_63_TMR1;
  
  __IO	uint32_t REG_60_TMR2;
  __IO	uint32_t REG_61_TMR2;
  __IO	uint32_t REG_62_TMR2;
  __IO	uint32_t REG_63_TMR2;
  
  __IO	uint32_t RTC_CNT_TMR0;
  __IO	uint32_t RTC_DIV_TMR0;
  __IO	uint32_t RTC_PRL_TMR0;
  __IO	uint32_t RTC_ALRM_TMR0;
  __IO	uint32_t RTC_CS_TMR0;
  
  __IO	uint32_t RESERV_1[3];

  __IO	uint32_t RTC_CNT_TMR1;
  __IO	uint32_t RTC_DIV_TMR1;
  __IO	uint32_t RTC_PRL_TMR1;
  __IO	uint32_t RTC_ALRM_TMR1;
  __IO	uint32_t RTC_CS_TMR1;
  
  __IO	uint32_t RESERV_2[3];

  __IO	uint32_t RTC_CNT_TMR2;
  __IO	uint32_t RTC_DIV_TMR2;
  __IO	uint32_t RTC_PRL_TMR2;
  __IO	uint32_t RTC_ALRM_TMR2;
  __IO	uint32_t RTC_CS_TMR2;
  
  
} BKPControl;


#define BKP_BASE	    (( uint32_t) 0x40001000)

#define	BKP		    ((BKPControl *) BKP_BASE)
#define BKP_KEY 	    ((uint32_t)	0x8555aaa1)

/***
*  CRYPTO control
**/

typedef struct
{
  __IO	uint32_t CRPT_CWR;
  __IO	uint32_t CRPT_SR;
  __IO	uint32_t CRPT_DATA;
  __IO	uint32_t CRPT_KR;
  __IO	uint32_t CRPT_CR;
  __IO	uint32_t CRPT_SYNR;
  __IO	uint32_t CRPT_IMIT;
  __IO	uint32_t CRPT_ITER;
} CRPTControl;


#define CRPT_BASE	    (( uint32_t) 0x400AE000)

#define	CRPT		    ((CRPTControl *) CRPT_BASE)

/***
*   MIL1553 Control 
**/

typedef struct
{
  __IO	uint32_t DATA[1024];
  __IO	uint32_t CONTROL;
  __IO	uint32_t STATUS;
  __IO	uint32_t ERROR;
  __IO	uint32_t CommandWord1;
  __IO	uint32_t CommandWord2;
  __IO	uint32_t ModeData;
  __IO	uint32_t StatusWord1;
  __IO	uint32_t StatusWord2;
  __IO	uint32_t INTEN;
  __IO	uint32_t MSG;
} MIL1553Control;


#define MIL15531_BASE	    (( uint32_t) 0x400A6000)
#define MIL15532_BASE	    (( uint32_t) 0x400A8000)

#define	MIL_STD_15531	    ((MIL1553Control *) MIL15531_BASE)
#define	MIL_STD_15532	    ((MIL1553Control *) MIL15532_BASE)

/** @defgroup MDR1986VE8T_Periph_MIL_STD_1553_Defines Defines
  * @{
  */
/** @defgroup MDR1986VE8T_Periph_MIL_STD_1553_CONTROL	MIL STD 1553 CONTROL
  * @{
  */ 

/*-- MIL_STD_1553_CONTROL: MIL_STD_1553 Control Register -----*/
/* Bit field positions: */
#define MIL_STD_1553_CONTROL_MR_Pos            0
#define MIL_STD_1553_CONTROL_BCSTART_Pos       1
#define MIL_STD_1553_CONTROL_BCMODE_Pos        2
#define MIL_STD_1553_CONTROL_RTMODE_Pos        3
#define MIL_STD_1553_CONTROL_TRA_Pos           4
#define MIL_STD_1553_CONTROL_TRB_Pos           5
#define MIL_STD_1553_CONTROL_RTA_Pos           6
#define MIL_STD_1553_CONTROL_DIV_Pos           11
#define MIL_STD_1553_CONTROL_RERR_Pos          18
#define MIL_STD_1553_CONTROL_INVTR_Pos		   19
#define MIL_STD_1553_CONTROL_ENFILTER_Pos	   20
#define MIL_STD_1553_CONTROL_AUTOTUNE_Pos	   21

/* Bit field masks: */
#define MIL_STD_1553_CONTROL_MR                 ((uint32_t)0x00000001)
#define MIL_STD_1553_CONTROL_BCSTART            ((uint32_t)0x00000002)
#define MIL_STD_1553_CONTROL_BCMODE			    ((uint32_t)0x00000004)
#define MIL_STD_1553_CONTROL_RTMODE             ((uint32_t)0x00000008)
#define MIL_STD_1553_CONTROL_TRA                ((uint32_t)0x00000010)
#define MIL_STD_1553_CONTROL_TRB                ((uint32_t)0x00000020)
#define MIL_STD_1553_CONTROL_RTA_Msk            ((uint32_t)0x000007C0)
#define MIL_STD_1553_CONTROL_DIV_Msk            ((uint32_t)0x0003F800)
#define MIL_STD_1553_CONTROL_RERR               ((uint32_t)0x00040000)
#define MIL_STD_1553_CONTROL_INVTR				((uint32_t)0x00080000)
#define MIL_STD_1553_CONTROL_ENFILTER		    ((uint32_t)0x00100000)
#define MIL_STD_1553_CONTROL_AUTOTUNE		    ((uint32_t)0x00200000)

/** @} */ /* End of group MIL_STD_1553_CONTROL */


/** @defgroup MDR1986VE8T_Periph_MIL_STD_1553_STATUS	MIL STD 1553 STATUS
  * @{
  */ 

/*-- MIL_STD_1553_STATUS: MIL_STD_1553 Status Register -----*/
/* Bit field positions: */
#define MIL_STD_1553_STATUS_IDLE_Pos            	 0
#define MIL_STD_1553_STATUS_RFLAGN_Pos            	 1
#define MIL_STD_1553_STATUS_VALMESS_Pos            	 2
#define MIL_STD_1553_STATUS_ERR_Pos	            	 3
#define MIL_STD_1553_STATUS_RCVA_Pos            	 4
#define MIL_STD_1553_STATUS_RCVB_Pos            	 5

/* Bit field masks: */
#define MIL_STD_1553_STATUS_IDLE            		 ((uint32_t)0x00000001)
#define MIL_STD_1553_STATUS_RFLAGN          	  	 ((uint32_t)0x00000002)
#define MIL_STD_1553_STATUS_VALMESS     	       	 ((uint32_t)0x00000004)
#define MIL_STD_1553_STATUS_ERR	     	   	    	 ((uint32_t)0x00000008)
#define MIL_STD_1553_STATUS_RCVA	            	 ((uint32_t)0x00000010)
#define MIL_STD_1553_STATUS_RCVB 	  	         	 ((uint32_t)0x00000020)

/** @} */ /* End of group MIL_STD_1553_STATUS */

/** @defgroup MDR1986VE8T_Periph_MIL_STD_1553_ERROR	MIL STD 1553 ERROR
  * @{
  */ 

/*-- MIL_STD_1553_ERROR: MIL_STD_1553 ERROR Register -----*/
/* Bit field positions: */
#define MIL_STD_1553_ERROR_NORCV_Pos           0
#define MIL_STD_1553_ERROR_MANERR_Pos          1
#define MIL_STD_1553_ERROR_SYNCERR_Pos         2
#define MIL_STD_1553_ERROR_SEQERR_Pos          3
#define MIL_STD_1553_ERROR_GAPERR_Pos          4
#define MIL_STD_1553_ERROR_CONERR_Pos          5
#define MIL_STD_1553_ERROR_PROERR_Pos          6

/* Bit field masks: */
#define MIL_STD_1553_ERROR_NORCV                ((uint32_t)0x00000001)
#define MIL_STD_1553_ERROR_MANERR               ((uint32_t)0x00000002)
#define MIL_STD_1553_ERROR_SYNCERR              ((uint32_t)0x00000004)
#define MIL_STD_1553_ERROR_SEQERR               ((uint32_t)0x00000008)
#define MIL_STD_1553_ERROR_GAPERR               ((uint32_t)0x00000010)
#define MIL_STD_1553_ERROR_CONERR               ((uint32_t)0x00000020)
#define MIL_STD_1553_ERROR_PROERR               ((uint32_t)0x00000040)

/** @} */ /* End of group MIL_STD_1553_ERROR */

/** @defgroup MDR1986VE8T_Periph_MIL_STD_1553_ITEEN	MIL STD 1553 ITEEN
  * @{
  */ 

/*-- MIL_STD_1553_ITEEN: MIL_STD_1553 ITEEN Register -----*/
/* Bit field positions: */
#define MIL_STD_1553_INTEN_IDLEIE_Pos          0
#define MIL_STD_1553_INTEN_RFLAGNIE_Pos        1
#define MIL_STD_1553_INTEN_VALMESSIE_Pos       2
#define MIL_STD_1553_INTEN_ERRIE_Pos           3

/* Bit field masks: */
#define MIL_STD_1553_INTEN_IDLEIE               ((uint32_t)0x00000001)
#define MIL_STD_1553_INTEN_RFLAGNIE             ((uint32_t)0x00000002)
#define MIL_STD_1553_INTEN_VALMESSIE            ((uint32_t)0x00000004)
#define MIL_STD_1553_INTEN_ERRIE                ((uint32_t)0x00000008)

/** @} */ /* End of group MIL_STD_1553_ITEEN */

/** @} */ /* End of group Periph_MIL_STD_1553_Defines */

/***
*  ARINC429R Control 
**/

typedef struct
{
  __IO	uint32_t CONTROL1;
  __IO	uint32_t CONTROL2;
  __IO	uint32_t CONTROL3;
  __IO	uint32_t STATUS1;
  __IO	uint32_t STATUS2;
  __IO	uint32_t CONTROL4;
  __IO	uint32_t CONTROL5;
  __IO	uint32_t CHANNEL;
  __IO	uint32_t LABEL;
  __IO	uint32_t DATA_R;
 	uint32_t RESERVED0[2];
  __IO	uint32_t DATA_R1;
  __IO	uint32_t DATA_R2;
  __IO	uint32_t DATA_R3;
  __IO	uint32_t DATA_R4;
  __IO	uint32_t DATA_R5;
  __IO	uint32_t DATA_R6;
  __IO	uint32_t DATA_R7;
  __IO	uint32_t DATA_R8;
 	uint32_t RESERVED1[6];
  __IO	uint32_t INTMASK;
 	uint32_t RESERVED2;
  __IO	uint32_t CONTROL8;
  __IO	uint32_t CONTROL9;
} ARINC429RControl;

typedef struct
{
  __IO	uint32_t DATA_R[1024];
} ARINC429RData;

#define ARINC429R1_BASE	    (( uint32_t) 0x4009E000)
#define ARINC429R2_BASE	    (( uint32_t) 0x400A2000)
#define ARINC429RD1_BASE    (( uint32_t) 0x4009F000)
#define ARINC429RD2_BASE    (( uint32_t) 0x400A3000)

#define	ARINC429R1	    ((ARINC429RControl *) ARINC429R1_BASE)
#define	ARINC429R2	    ((ARINC429RControl *) ARINC429R2_BASE)
#define	ARINC429RD1	    ((ARINC429RData *) ARINC429RD1_BASE)
#define	ARINC429RD2	    ((ARINC429RData *) ARINC429RD2_BASE)

/** @defgroup MDR1986VE8T_Periph_ARINC429R_Defines Defines
  * @{
  */

/** @defgroup MDR1986VE8T_Periph_ARINC429R_CONTROL1	ARINC429R CONTROL1
  * @{
  */ 

/*-- ARINC429R_CONTROL1: ARINC429R CONTROL1 Register -----*/
/* Bit field positions: */
#define ARINC429R_CONTROL1_CH_EN1_Pos          0
#define ARINC429R_CONTROL1_CH_EN2_Pos          1
#define ARINC429R_CONTROL1_CH_EN3_Pos          2
#define ARINC429R_CONTROL1_CH_EN4_Pos          3
#define ARINC429R_CONTROL1_CH_EN5_Pos          4
#define ARINC429R_CONTROL1_CH_EN6_Pos          5
#define ARINC429R_CONTROL1_CH_EN7_Pos          6
#define ARINC429R_CONTROL1_CH_EN8_Pos          7
#define ARINC429R_CONTROL1_CLK1_Pos            14
#define ARINC429R_CONTROL1_CLK2_Pos            15
#define ARINC429R_CONTROL1_CLK3_Pos            16
#define ARINC429R_CONTROL1_CLK4_Pos            17
#define ARINC429R_CONTROL1_CLK5_Pos            18
#define ARINC429R_CONTROL1_CLK6_Pos            19
#define ARINC429R_CONTROL1_CLK7_Pos            20
#define ARINC429R_CONTROL1_CLK8_Pos            21
#define ARINC429R_CONTROL1_DIV_Pos             28

/* Bit field masks: */
#define ARINC429R_CONTROL1_CH_EN1               ((uint32_t)0x00000001)
#define ARINC429R_CONTROL1_CH_EN2               ((uint32_t)0x00000002)
#define ARINC429R_CONTROL1_CH_EN3               ((uint32_t)0x00000004)
#define ARINC429R_CONTROL1_CH_EN4               ((uint32_t)0x00000008)
#define ARINC429R_CONTROL1_CH_EN5               ((uint32_t)0x00000010)
#define ARINC429R_CONTROL1_CH_EN6               ((uint32_t)0x00000020)
#define ARINC429R_CONTROL1_CH_EN7               ((uint32_t)0x00000040)
#define ARINC429R_CONTROL1_CH_EN8               ((uint32_t)0x00000080)
#define ARINC429R_CONTROL1_CLK1                 ((uint32_t)0x00004000)
#define ARINC429R_CONTROL1_CLK2                 ((uint32_t)0x00008000)
#define ARINC429R_CONTROL1_CLK3                 ((uint32_t)0x00010000)
#define ARINC429R_CONTROL1_CLK4                 ((uint32_t)0x00020000)
#define ARINC429R_CONTROL1_CLK5                 ((uint32_t)0x00040000)
#define ARINC429R_CONTROL1_CLK6                 ((uint32_t)0x00080000)
#define ARINC429R_CONTROL1_CLK7                 ((uint32_t)0x00100000)
#define ARINC429R_CONTROL1_DIV_Msk	            ((uint32_t)0xF0000000)

/** @} */ /* End of group ARINC429R_CONTROL1 */

/** @defgroup MDR1986VE8T_Periph_ARICN429R_CONTROL2	ARICN429R CONTROL2
  * @{
  */ 

/*-- ARICN429R_CONTROL2: ARICN429R CONTROL2 Register -----*/
/* Bit field positions: */
#define ARINC429R_CONTROL2_DIV_6_4_Pos         0
#define ARINC429R_CONTROL2_LB_EN1_Pos          3
#define ARINC429R_CONTROL2_LB_EN2_Pos          4
#define ARINC429R_CONTROL2_LB_EN3_Pos          5
#define ARINC429R_CONTROL2_LB_EN4_Pos          6
#define ARINC429R_CONTROL2_LB_EN5_Pos          7
#define ARINC429R_CONTROL2_LB_EN6_Pos          8
#define ARINC429R_CONTROL2_LB_EN7_Pos          9
#define ARINC429R_CONTROL2_LB_EN8_Pos          10
#define ARINC429R_CONTROL2_SD_EN1_Pos          17
#define ARINC429R_CONTROL2_SD_EN2_Pos          18
#define ARINC429R_CONTROL2_SD_EN3_Pos          19
#define ARINC429R_CONTROL2_SD_EN4_Pos          20
#define ARINC429R_CONTROL2_SD_EN5_Pos          21
#define ARINC429R_CONTROL2_SD_EN6_Pos          22
#define ARINC429R_CONTROL2_SD_EN7_Pos          23
#define ARINC429R_CONTROL2_SD_EN8_Pos          24
#define ARINC429R_CONTROL2_DA_Pos			   31

/* Bit field masks: */
#define ARINC429R_CONTROL2_DIV_6_4_Msk			((uint32_t)0x00000007)
#define ARINC429R_CONTROL2_LB_EN1               ((uint32_t)0x00000008)
#define ARINC429R_CONTROL2_LB_EN2               ((uint32_t)0x00000010)
#define ARINC429R_CONTROL2_LB_EN3               ((uint32_t)0x00000020)
#define ARINC429R_CONTROL2_LB_EN4               ((uint32_t)0x00000040)
#define ARINC429R_CONTROL2_LB_EN5               ((uint32_t)0x00000080)
#define ARINC429R_CONTROL2_LB_EN6               ((uint32_t)0x00000100)
#define ARINC429R_CONTROL2_LB_EN7               ((uint32_t)0x00000200)
#define ARINC429R_CONTROL2_LB_EN8               ((uint32_t)0x00000400)
#define ARINC429R_CONTROL2_SD_EN1               ((uint32_t)0x00020000)
#define ARINC429R_CONTROL2_SD_EN2               ((uint32_t)0x00040000)
#define ARINC429R_CONTROL2_SD_EN3               ((uint32_t)0x00080000)
#define ARINC429R_CONTROL2_SD_EN4               ((uint32_t)0x00100000)
#define ARINC429R_CONTROL2_SD_EN5               ((uint32_t)0x00200000)
#define ARINC429R_CONTROL2_SD_EN6               ((uint32_t)0x00400000)
#define ARINC429R_CONTROL2_SD_EN7               ((uint32_t)0x00800000)
#define ARINC429R_CONTROL2_SD_EN8               ((uint32_t)0x01000000)
#define ARINC429R_CONTROL2_DA			   		((uint32_t)0x80000000)

/** @} */ /* End of group ARICN429R_CONTROL2 */

/** @defgroup MDR1986VE8T_Periph_ARINC429R_CONTROL3	ARINC429R CONTROL3
  * @{
  */ 

/*-- ARINC429R_CONTROL3: ARINC429R CONTROL3 Register -----*/
/* Bit field positions: */
#define ARINC429R_CONTROL3_SDI1_1_Pos          0
#define ARINC429R_CONTROL3_SDI1_2_Pos          1
#define ARINC429R_CONTROL3_SDI1_3_Pos          2
#define ARINC429R_CONTROL3_SDI1_4_Pos          3
#define ARINC429R_CONTROL3_SDI1_5_Pos          4
#define ARINC429R_CONTROL3_SDI1_6_Pos          5
#define ARINC429R_CONTROL3_SDI1_7_Pos          6
#define ARINC429R_CONTROL3_SDI1_8_Pos          7
#define ARINC429R_CONTROL3_SDI2_1_Pos          14
#define ARINC429R_CONTROL3_SDI2_2_Pos          15
#define ARINC429R_CONTROL3_SDI2_3_Pos          16
#define ARINC429R_CONTROL3_SDI2_4_Pos          17
#define ARINC429R_CONTROL3_SDI2_5_Pos          18
#define ARINC429R_CONTROL3_SDI2_6_Pos          19
#define ARINC429R_CONTROL3_SDI2_7_Pos          20
#define ARINC429R_CONTROL3_SDI2_8_Pos          21
#define ARINC429R_CONTROL3_INTEDR_Pos          28
#define ARINC429R_CONTROL3_INTEER_Pos          29
#define ARINC429R_CONTROL3_INTEFF_Pos          30
#define ARINC429R_CONTROL3_INTEHF_Pos          31

/* Bit field masks: */
#define ARINC429R_CONTROL3_SDI1_1               ((uint32_t)0x00000001)
#define ARINC429R_CONTROL3_SDI1_2               ((uint32_t)0x00000002)
#define ARINC429R_CONTROL3_SDI1_3               ((uint32_t)0x00000004)
#define ARINC429R_CONTROL3_SDI1_4               ((uint32_t)0x00000008)
#define ARINC429R_CONTROL3_SDI1_5               ((uint32_t)0x00000010)
#define ARINC429R_CONTROL3_SDI1_6               ((uint32_t)0x00000020)
#define ARINC429R_CONTROL3_SDI1_7               ((uint32_t)0x00000040)
#define ARINC429R_CONTROL3_SDI1_8               ((uint32_t)0x00000080)
#define ARINC429R_CONTROL3_SDI2_1               ((uint32_t)0x00004000)
#define ARINC429R_CONTROL3_SDI2_2               ((uint32_t)0x00008000)
#define ARINC429R_CONTROL3_SDI2_3               ((uint32_t)0x00010000)
#define ARINC429R_CONTROL3_SDI2_4               ((uint32_t)0x00020000)
#define ARINC429R_CONTROL3_SDI2_5               ((uint32_t)0x00040000)
#define ARINC429R_CONTROL3_SDI2_6               ((uint32_t)0x00080000)
#define ARINC429R_CONTROL3_SDI2_7               ((uint32_t)0x00100000)
#define ARINC429R_CONTROL3_SDI2_8               ((uint32_t)0x00200000)
#define ARINC429R_CONTROL3_INTEDR               ((uint32_t)0x10000000)
#define ARINC429R_CONTROL3_INTEER               ((uint32_t)0x20000000)
#define ARINC429R_CONTROL3_INTEFF               ((uint32_t)0x40000000)
#define ARINC429R_CONTROL3_INTEHF               ((uint32_t)0x80000000)

/** @} */ /* End of group ARINC429R_CONTROL3 */

/** @defgroup MDR1986VE8T_Periph_ARINC429R_CONTROL4	ARINC429R CONTROL4
  * @{
  */ 

/*-- ARINC429R_CONTROL4: ARINC429R CONTROL4 Register -----*/
/* Bit field positions: */
#define ARINC429R_CONTROL4_DIV_CH1_Pos            	 0
#define ARINC429R_CONTROL4_DIV_CH2_Pos            	 8
#define ARINC429R_CONTROL4_DIV_CH3_Pos            	 16
#define ARINC429R_CONTROL4_DIV_CH4_Pos            	 24

/* Bit field masks: */
#define ARINC429R_CONTROL4_DIV_CH1_Msk               ((uint32_t)0x000000FF)
#define ARINC429R_CONTROL4_DIV_CH2_Msk               ((uint32_t)0x0000FF00)
#define ARINC429R_CONTROL4_DIV_CH3_Msk               ((uint32_t)0x00FF0000)
#define ARINC429R_CONTROL4_DIV_CH4_Msk               ((uint32_t)0xFF000000)

/** @} */ /* End of group ARINC429R_CONTROL4 */

/** @defgroup MDR1986VE8T_Periph_ARINC492_CONTROL5	ARINC492 CONTROL5
  * @{
  */ 

/*-- ARINC492_CONTROL5: ARINC492 CONTROL5 Register -----*/
/* Bit field positions: */
#define ARINC429R_CONTROL5_DIV_CH5_Pos            	 0
#define ARINC429R_CONTROL5_DIV_CH6_Pos            	 8
#define ARINC429R_CONTROL5_DIV_CH7_Pos            	 16
#define ARINC429R_CONTROL5_DIV_CH8_Pos            	 24

/* Bit field masks: */
#define ARINC429R_CONTROL5_DIV_CH5_Msk               ((uint32_t)0x000000FF)
#define ARINC429R_CONTROL5_DIV_CH6_Msk               ((uint32_t)0x0000FF00)
#define ARINC429R_CONTROL5_DIV_CH7_Msk               ((uint32_t)0x00FF0000)
#define ARINC429R_CONTROL5_DIV_CH8_Msk				 ((uint32_t)0xFF000000)

/** @} */ /* End of group ARINC492_CONTROL5 */

/** @defgroup MDR1986VE8T_Periph_ARINC429R_INTMASK	ARINC429R INTMASK
  * @{
  */ 

/*-- ARINC429R_INTMASK: ARINC429R INTMASK register -----*/
/* Bit field positions: */
#define ARINC429R_INTMASK_IEHF1_Pos					0
#define ARINC429R_INTMASK_IEFF1_Pos					1
#define ARINC429R_INTMASK_IEER1_Pos					2
#define ARINC429R_INTMASK_IEDR1_Pos					3
#define ARINC429R_INTMASK_IEHF2_Pos					4
#define ARINC429R_INTMASK_IEFF2_Pos					5
#define ARINC429R_INTMASK_IEER2_Pos					6
#define ARINC429R_INTMASK_IEDR2_Pos					7
#define ARINC429R_INTMASK_IEHF3_Pos					8
#define ARINC429R_INTMASK_IEFF3_Pos					9
#define ARINC429R_INTMASK_IEER3_Pos					10
#define ARINC429R_INTMASK_IEDR3_Pos					11
#define ARINC429R_INTMASK_IEHF4_Pos					12
#define ARINC429R_INTMASK_IEFF4_Pos					13
#define ARINC429R_INTMASK_IEER4_Pos					14
#define ARINC429R_INTMASK_IEDR4_Pos					15
#define ARINC429R_INTMASK_IEHF5_Pos					16
#define ARINC429R_INTMASK_IEFF5_Pos					17
#define ARINC429R_INTMASK_IEER5_Pos					18
#define ARINC429R_INTMASK_IEDR5_Pos					19
#define ARINC429R_INTMASK_IEHF6_Pos					20
#define ARINC429R_INTMASK_IEFF6_Pos					21
#define ARINC429R_INTMASK_IEER6_Pos					22
#define ARINC429R_INTMASK_IEDR6_Pos					23
#define ARINC429R_INTMASK_IEHF7_Pos					24
#define ARINC429R_INTMASK_IEFF7_Pos					25
#define ARINC429R_INTMASK_IEER7_Pos					26
#define ARINC429R_INTMASK_IEDR7_Pos					27
#define ARINC429R_INTMASK_IEHF8_Pos					28
#define ARINC429R_INTMASK_IEFF8_Pos					29
#define ARINC429R_INTMASK_IEER8_Pos					30
#define ARINC429R_INTMASK_IEDR8_Pos					31

/* Bit field masks: */
#define ARINC429R_INTMASK_IEHF1						((uint32_t)0x00000001))
#define ARINC429R_INTMASK_IEFF1						((uint32_t)0x00000002))
#define ARINC429R_INTMASK_IEER1						((uint32_t)0x00000004))
#define ARINC429R_INTMASK_IEDR1						((uint32_t)0x00000008))
#define ARINC429R_INTMASK_IEHF2						((uint32_t)0x00000010))
#define ARINC429R_INTMASK_IEFF2						((uint32_t)0x00000020))
#define ARINC429R_INTMASK_IEER2						((uint32_t)0x00000040))
#define ARINC429R_INTMASK_IEDR2						((uint32_t)0x00000080))
#define ARINC429R_INTMASK_IEHF3						((uint32_t)0x00000100))
#define ARINC429R_INTMASK_IEFF3						((uint32_t)0x00000200))
#define ARINC429R_INTMASK_IEER3						((uint32_t)0x00000400))
#define ARINC429R_INTMASK_IEDR3						((uint32_t)0x00000800))
#define ARINC429R_INTMASK_IEHF4						((uint32_t)0x00001000))
#define ARINC429R_INTMASK_IEFF4						((uint32_t)0x00002000))
#define ARINC429R_INTMASK_IEER4						((uint32_t)0x00004000))
#define ARINC429R_INTMASK_IEDR4						((uint32_t)0x00008000))
#define ARINC429R_INTMASK_IEHF5						((uint32_t)0x00010000))
#define ARINC429R_INTMASK_IEFF5						((uint32_t)0x00020000))
#define ARINC429R_INTMASK_IEER5						((uint32_t)0x00040000))
#define ARINC429R_INTMASK_IEDR5						((uint32_t)0x00080000))
#define ARINC429R_INTMASK_IEHF6						((uint32_t)0x00100000))
#define ARINC429R_INTMASK_IEFF6						((uint32_t)0x00200000))
#define ARINC429R_INTMASK_IEER6						((uint32_t)0x00400000))
#define ARINC429R_INTMASK_IEDR6						((uint32_t)0x00800000))
#define ARINC429R_INTMASK_IEHF7						((uint32_t)0x01000000))
#define ARINC429R_INTMASK_IEFF7						((uint32_t)0x02000000))
#define ARINC429R_INTMASK_IEER7						((uint32_t)0x04000000))
#define ARINC429R_INTMASK_IEDR7						((uint32_t)0x08000000))
#define ARINC429R_INTMASK_IEHF8						((uint32_t)0x10000000))
#define ARINC429R_INTMASK_IEFF8						((uint32_t)0x20000000))
#define ARINC429R_INTMASK_IEER8						((uint32_t)0x40000000))
#define ARINC429R_INTMASK_IEDR8						((uint32_t)0x80000000))

/** @} */ /* End of group ARINC429R_INTMASK */

/** @defgroup MDR1986VE8T_Periph_ARINC429R_STATUS1	ARINC429R STATUS1
  * @{
  */ 

/*-- ARINC429R_STATUS1: ARINC429R STATUS1 Register -----*/
/* Bit field positions: */
#define ARINC429R_STATUS1_DR1_Pos              0
#define ARINC429R_STATUS1_DR2_Pos              1
#define ARINC429R_STATUS1_DR3_Pos              2
#define ARINC429R_STATUS1_DR4_Pos              3
#define ARINC429R_STATUS1_DR5_Pos              4
#define ARINC429R_STATUS1_DR6_Pos              5
#define ARINC429R_STATUS1_DR7_Pos              6
#define ARINC429R_STATUS1_DR8_Pos              7
#define ARINC429R_STATUS1_ERR1_Pos             14
#define ARINC429R_STATUS1_ERR2_Pos             15
#define ARINC429R_STATUS1_ERR3_Pos             16
#define ARINC429R_STATUS1_ERR4_Pos             17
#define ARINC429R_STATUS1_ERR5_Pos             18
#define ARINC429R_STATUS1_ERR6_Pos             19
#define ARINC429R_STATUS1_ERR7_Pos             20
#define ARINC429R_STATUS1_ERR8_Pos             21

/* Bit field masks: */
#define ARINC429R_STATUS1_DR1                   ((uint32_t)0x00000001)
#define ARINC429R_STATUS1_DR2                   ((uint32_t)0x00000002)
#define ARINC429R_STATUS1_DR3                   ((uint32_t)0x00000004)
#define ARINC429R_STATUS1_DR4                   ((uint32_t)0x00000008)
#define ARINC429R_STATUS1_DR5                   ((uint32_t)0x00000010)
#define ARINC429R_STATUS1_DR6                   ((uint32_t)0x00000020)
#define ARINC429R_STATUS1_DR7                   ((uint32_t)0x00000040)
#define ARINC429R_STATUS1_DR8                   ((uint32_t)0x00000080)
#define ARINC429R_STATUS1_ERR1                  ((uint32_t)0x00004000)
#define ARINC429R_STATUS1_ERR2                  ((uint32_t)0x00008000)
#define ARINC429R_STATUS1_ERR3                  ((uint32_t)0x00010000)
#define ARINC429R_STATUS1_ERR4                  ((uint32_t)0x00020000)
#define ARINC429R_STATUS1_ERR5                  ((uint32_t)0x00040000)
#define ARINC429R_STATUS1_ERR6                  ((uint32_t)0x00080000)
#define ARINC429R_STATUS1_ERR7                  ((uint32_t)0x00100000)
#define ARINC429R_STATUS1_ERR8                  ((uint32_t)0x00200000)

/** @} */ /* End of group ARINC429R_STATUS1 */

/** @defgroup MDR1986VE8T_Periph_ARINC429R_STATUS2	ARINC429R STATUS2
  * @{
  */ 

/*-- ARINC429R_STATUS2: ARINC429R STATUS2 Register -----*/
/* Bit field positions: */
#define ARINC429R_STATUS2_FF1_Pos              0
#define ARINC429R_STATUS2_FF2_Pos              1
#define ARINC429R_STATUS2_FF3_Pos              2
#define ARINC429R_STATUS2_FF4_Pos              3
#define ARINC429R_STATUS2_FF5_Pos              4
#define ARINC429R_STATUS2_FF6_Pos              5
#define ARINC429R_STATUS2_FF7_Pos              6
#define ARINC429R_STATUS2_FF8_Pos              7
#define ARINC429R_STATUS2_HF1_Pos              14
#define ARINC429R_STATUS2_HF2_Pos              15
#define ARINC429R_STATUS2_HF3_Pos              16
#define ARINC429R_STATUS2_HF4_Pos              17
#define ARINC429R_STATUS2_HF5_Pos              18
#define ARINC429R_STATUS2_HF6_Pos              19
#define ARINC429R_STATUS2_HF7_Pos              20
#define ARINC429R_STATUS2_HF8_Pos              21

/* Bit field masks: */
#define ARINC429R_STATUS2_FF1                   ((uint32_t)0x00000001)
#define ARINC429R_STATUS2_FF2                   ((uint32_t)0x00000002)
#define ARINC429R_STATUS2_FF3                   ((uint32_t)0x00000004)
#define ARINC429R_STATUS2_FF4                   ((uint32_t)0x00000008)
#define ARINC429R_STATUS2_FF5                   ((uint32_t)0x00000010)
#define ARINC429R_STATUS2_FF6                   ((uint32_t)0x00000020)
#define ARINC429R_STATUS2_FF7                   ((uint32_t)0x00000040)
#define ARINC429R_STATUS2_FF8                   ((uint32_t)0x00000080)
#define ARINC429R_STATUS2_HF1                   ((uint32_t)0x00004000)
#define ARINC429R_STATUS2_HF2                   ((uint32_t)0x00008000)
#define ARINC429R_STATUS2_HF3                   ((uint32_t)0x00010000)
#define ARINC429R_STATUS2_HF4                   ((uint32_t)0x00020000)
#define ARINC429R_STATUS2_HF5                   ((uint32_t)0x00040000)
#define ARINC429R_STATUS2_HF6                   ((uint32_t)0x00080000)
#define ARINC429R_STATUS2_HF7                   ((uint32_t)0x00100000)
#define ARINC429R_STATUS2_HF8                   ((uint32_t)0x00200000)

/** @} */ /* End of group ARINC429R_STATUS2 */

/** @} */ /* End of group MDR1986VE8T_Periph_ARINC429R_Defines */

/***
*   ARINC429T Control 
**/

typedef struct
{
  __IO	uint32_t CONTROL1;
  __IO	uint32_t CONTROL2;
  __IO	uint32_t STATUS;
  __IO	uint32_t DATA1_T;
  __IO	uint32_t DATA2_T;
  __IO	uint32_t DATA3_T;
  __IO	uint32_t DATA4_T;
  __IO	uint32_t CONTROL3;
  __IO	uint32_t CONTROL4;
} ARINC429TControl;

typedef struct
{
  __IO	uint32_t DATA_T[1024];
} ARINC429TData;

#define ARINC429T1_BASE	    (( uint32_t) 0x400A0000)
#define ARINC429T2_BASE	    (( uint32_t) 0x400A4000)
#define ARINC429TD1_BASE    (( uint32_t) 0x400A1000)
#define ARINC429TD2_BASE    (( uint32_t) 0x400A5000)

#define	ARINC429T1	    ((ARINC429TControl *) ARINC429T1_BASE)
#define	ARINC429T2	    ((ARINC429TControl *) ARINC429T2_BASE)
#define	ARINC429TD1	    ((ARINC429TData *) ARINC429TD1_BASE)
#define	ARINC429TD2	    ((ARINC429TData *) ARINC429TD2_BASE)

/** @defgroup MDR1986VE8T_Periph_ARINC429T_Defines Defines
  * @{
  */

/** @defgroup MDR1986VE8T_Periph_ARINC429T_CONTROL1	ARINC429T CONTROL1
  * @{
  */ 

/*-- ARINC429T_CONTROL1: ARINC429T CONTROL1 Register -----*/
/* Bit field positions: */
#define ARINC429T_CONTROL1_CH_EN1_Pos          0
#define ARINC429T_CONTROL1_CLK1_Pos            1
#define ARINC429T_CONTROL1_EN_PAR1_Pos         2
#define ARINC429T_CONTROL1_ODD1_Pos            3
#define ARINC429T_CONTROL1_CH_EN2_Pos          4
#define ARINC429T_CONTROL1_CLK2_Pos            5
#define ARINC429T_CONTROL1_EN_PAR2_Pos         6
#define ARINC429T_CONTROL1_ODD2_Pos            7
#define ARINC429T_CONTROL1_DIV_Pos             8
#define ARINC429T_CONTROL1_INTE_FFT1_Pos       15
#define ARINC429T_CONTROL1_INTE_TXR1_Pos       16
#define ARINC429T_CONTROL1_INTE_HFT1_Pos       17
#define ARINC429T_CONTROL1_INTE_FFT2_Pos       18
#define ARINC429T_CONTROL1_INTE_TXR2_Pos       19
#define ARINC429T_CONTROL1_INTE_HFT2_Pos       20

/* Bit field masks: */
#define ARINC429T_CONTROL1_CH_EN1               ((uint32_t)0x00000001)
#define ARINC429T_CONTROL1_CLK1                 ((uint32_t)0x00000002)
#define ARINC429T_CONTROL1_EN_PAR1              ((uint32_t)0x00000004)
#define ARINC429T_CONTROL1_ODD1                 ((uint32_t)0x00000008)
#define ARINC429T_CONTROL1_CH_EN2               ((uint32_t)0x00000010)
#define ARINC429T_CONTROL1_CLK2                 ((uint32_t)0x00000020)
#define ARINC429T_CONTROL1_EN_PAR2              ((uint32_t)0x00000040)
#define ARINC429T_CONTROL1_ODD2                 ((uint32_t)0x00000080)
#define ARINC429T_CONTROL1_DIV_MASK             ((uint32_t)0x00007F00)
#define ARINC429T_CONTROL1_INTE_FFT1            ((uint32_t)0x00008000)
#define ARINC429T_CONTROL1_INTE_TXR1            ((uint32_t)0x00010000)
#define ARINC429T_CONTROL1_INTE_HFT1            ((uint32_t)0x00020000)
#define ARINC429T_CONTROL1_INTE_FFT2            ((uint32_t)0x00040000)
#define ARINC429T_CONTROL1_INTE_TXR2            ((uint32_t)0x00080000)
#define ARINC429T_CONTROL1_INTE_HFT2            ((uint32_t)0x00100000)

/** @} */ /* End of group ARINC429T_CONTROL1 */

/** @defgroup MDR1986VE8T_Periph_ARINC429T_CONTROL2	ARINC429T CONTROL2
  * @{
  */ 

/*-- ARINC429T_CONTROL2: ARINC429T CONTROL2 Register -----*/
/* Bit field positions: */
#define ARINC429T_CONTROL2_CH_EN3_Pos          0
#define ARINC429T_CONTROL2_CLK3_Pos            1
#define ARINC429T_CONTROL2_EN_PAR3_Pos         2
#define ARINC429T_CONTROL2_ODD3_Pos            3
#define ARINC429T_CONTROL2_CH_EN4_Pos          4
#define ARINC429T_CONTROL2_CLK4_Pos            5
#define ARINC429T_CONTROL2_EN_PAR4_Pos         6
#define ARINC429T_CONTROL2_ODD4_Pos            7
#define ARINC429T_CONTROL2_INTE_FFT3_Pos       15
#define ARINC429T_CONTROL2_INTE_TXR3_Pos       16
#define ARINC429T_CONTROL2_INTE_HFT3_Pos       17
#define ARINC429T_CONTROL2_INTE_FFT4_Pos       18
#define ARINC429T_CONTROL2_INTE_TXR4_Pos       19
#define ARINC429T_CONTROL2_INTE_HFT4_Pos       20

/* Bit field masks: */
#define ARINC429T_CONTROL2_CH_EN3               ((uint32_t)0x00000001)
#define ARINC429T_CONTROL2_CLK3                 ((uint32_t)0x00000002)
#define ARINC429T_CONTROL2_EN_PAR3              ((uint32_t)0x00000004)
#define ARINC429T_CONTROL2_ODD3                 ((uint32_t)0x00000008)
#define ARINC429T_CONTROL2_CH_EN4               ((uint32_t)0x00000010)
#define ARINC429T_CONTROL2_CLK4                 ((uint32_t)0x00000020)
#define ARINC429T_CONTROL2_EN_PAR4              ((uint32_t)0x00000040)
#define ARINC429T_CONTROL2_ODD4                 ((uint32_t)0x00000080)
#define ARINC429T_CONTROL2_INTE_FFT3            ((uint32_t)0x00008000)
#define ARINC429T_CONTROL2_INTE_TXR3            ((uint32_t)0x00010000)
#define ARINC429T_CONTROL2_INTE_HFT3            ((uint32_t)0x00020000)
#define ARINC429T_CONTROL2_INTE_FFT4            ((uint32_t)0x00040000)
#define ARINC429T_CONTROL2_INTE_TXR4            ((uint32_t)0x00080000)
#define ARINC429T_CONTROL2_INTE_HFT4            ((uint32_t)0x00100000)

/** @} */ /* End of group ARINC429T_CONTROL2 */

/** @defgroup MDR1986VE8T_Periph_ARINC429T_CONTROL3	ARINC429T CONTROL3
  * @{
  */ 

/*-- ARINC429T_CONTROL3: ARINC429T CONTROL3 Register -----*/
/* Bit field positions: */
#define ARINC429T_CONTROL3_DIV_CH1_Pos            	 0
#define ARINC429T_CONTROL3_DIV_CH2_Pos            	 8
#define ARINC429T_CONTROL3_DIV_CH3_Pos            	 16
#define ARINC429T_CONTROL3_DIV_CH4_Pos            	 24

/* Bit field masks: */
#define ARINC429T_CONTROL3_DIV_CH1_Msk               ((uint32_t)0x000000FF)
#define ARINC429T_CONTROL3_DIV_CH2_Msk               ((uint32_t)0x0000FF00)
#define ARINC429T_CONTROL3_DIV_CH3_Msk               ((uint32_t)0x00FF0000)
#define ARINC429T_CONTROL3_DIV_CH4_Msk               ((uint32_t)0xFF000000)

/** @} */ /* End of group ARINC429T_CONTROL3 */

/** @defgroup MDR1986VE8T_Periph_ARIN?429T_STATUS	ARIN?429T STATUS
  * @{
  */ 

/*-- ARIN?429T_STATUS: ARIN?429T STATUS Register -----*/
/* Bit field positions: */
#define ARINC429T_STATUS_TX_R1_Pos             0
#define ARINC429T_STATUS_FFT1_Pos              1
#define ARINC429T_STATUS_HFT1_Pos              2
#define ARINC429T_STATUS_TX_R2_Pos             3
#define ARINC429T_STATUS_FFT2_Pos              4
#define ARINC429T_STATUS_HFT2_Pos              5
#define ARINC429T_STATUS_TX_R3_Pos             8
#define ARINC429T_STATUS_FFT3_Pos              9
#define ARINC429T_STATUS_HFT3_Pos              10
#define ARINC429T_STATUS_TX_R4_Pos             11
#define ARINC429T_STATUS_FFT4_Pos              12
#define ARINC429T_STATUS_HFT4_Pos              13

/* Bit field masks: */
#define ARINC429T_STATUS_TX_R1                  ((uint32_t)0x00000001)
#define ARINC429T_STATUS_FFT1                   ((uint32_t)0x00000002)
#define ARINC429T_STATUS_HFT1                   ((uint32_t)0x00000004)
#define ARINC429T_STATUS_TX_R2                  ((uint32_t)0x00000008)
#define ARINC429T_STATUS_FFT2                   ((uint32_t)0x00000010)
#define ARINC429T_STATUS_HFT2                   ((uint32_t)0x00000020)
#define ARINC429T_STATUS_TX_R3                  ((uint32_t)0x00000100)
#define ARINC429T_STATUS_FFT3                   ((uint32_t)0x00000200)
#define ARINC429T_STATUS_HFT3                   ((uint32_t)0x00000400)
#define ARINC429T_STATUS_TX_R4                  ((uint32_t)0x00000800)
#define ARINC429T_STATUS_FFT4                   ((uint32_t)0x00001000)
#define ARINC429T_STATUS_HFT4                   ((uint32_t)0x00002000)

/** @} */ /* End of group ARIN?429T_STATUS */

/** @} */ /* End of group MDR1986VE8T_Periph_ARINC429T_Defines */

/***
*   CLOCK Control 
**/
typedef struct
{
  __IO	uint32_t KEY;
  __IO	uint32_t MAX_CLK;
  __IO	uint32_t CPU_CLK;
  __IO	uint32_t PER0_CLK;
  __IO	uint32_t PER1_CLK;
  
  __IO	uint32_t CPU_CHK0;
  __IO	uint32_t CPU_CHK1;
  __IO	uint32_t CPU_CHK2;
  __IO	uint32_t CPU_STAT;
  
  __IO	uint32_t LSI_CLK;
  __IO	uint32_t LSI_CHK0;
  __IO	uint32_t LSI_CHK1;
  __IO	uint32_t LSI_CHK2;
  __IO	uint32_t LSI_STAT;
  
  __IO	uint32_t HSI_STAT;
  
  __IO	uint32_t LSE_CLK;
  __IO	uint32_t LSE_CHK0;
  __IO	uint32_t LSE_CHK1;
  __IO	uint32_t LSE_CHK2;
  __IO	uint32_t LSE_STAT;
  
  __IO	uint32_t HSE0_CLK;
  __IO	uint32_t HSE0_CHK0;
  __IO	uint32_t HSE0_CHK1;
  __IO	uint32_t HSE0_CHK2;
  __IO	uint32_t HSE0_STAT;

  __IO	uint32_t HSE1_CLK;
  __IO	uint32_t HSE1_CHK0;
  __IO	uint32_t HSE1_CHK1;
  __IO	uint32_t HSE1_CHK2;
  __IO	uint32_t HSE1_STAT;
  
  __IO	uint32_t PLL0_CLK;
  __IO	uint32_t PLL0_CHK0;
  __IO	uint32_t PLL0_CHK1;
  __IO	uint32_t PLL0_CHK2;
  __IO	uint32_t PLL0_STAT;
  
  __IO	uint32_t PLL1_CLK;
  __IO	uint32_t PLL1_CHK0;
  __IO	uint32_t PLL1_CHK1;
  __IO	uint32_t PLL1_CHK2;
  __IO	uint32_t PLL1_STAT;
  
  __IO	uint32_t PLL2_CLK;
  __IO	uint32_t PLL2_CHK0;
  __IO	uint32_t PLL2_CHK1;
  __IO	uint32_t PLL2_CHK2;
  __IO	uint32_t PLL2_STAT;
  
  __IO	uint32_t PLL3_CLK;
  __IO	uint32_t PLL3_CHK0;
  __IO	uint32_t PLL3_CHK1;
  __IO	uint32_t PLL3_CHK2;
  __IO	uint32_t PLL3_STAT;
  
  __IO	uint32_t PLL4_CLK;
  __IO	uint32_t PLL4_CHK0;
  __IO	uint32_t PLL4_CHK1;
  __IO	uint32_t PLL4_CHK2;
  __IO	uint32_t PLL4_STAT;
  
  __IO	uint32_t PLL5_CLK;
  __IO	uint32_t PLL5_CHK0;
  __IO	uint32_t PLL5_CHK1;
  __IO	uint32_t PLL5_CHK2;
  __IO	uint32_t PLL5_STAT;
  
  __IO	uint32_t PLL6_CLK;
  __IO	uint32_t PLL6_CHK0;
  __IO	uint32_t PLL6_CHK1;
  __IO	uint32_t PLL6_CHK2;
  __IO	uint32_t PLL6_STAT;
  
  __IO	uint32_t PLL7_CLK;
  __IO	uint32_t PLL7_CHK0;
  __IO	uint32_t PLL7_CHK1;
  __IO	uint32_t PLL7_CHK2;
  __IO	uint32_t PLL7_STAT;
  
  __IO	uint32_t CAN0_CLK;
  __IO	uint32_t CAN1_CLK;
  __IO	uint32_t CAN2_CLK;
  __IO	uint32_t CAN3_CLK;
  __IO	uint32_t CAN4_CLK;
  __IO	uint32_t CAN5_CLK;

  __IO	uint32_t TIM0_CLK;
  __IO	uint32_t TIM1_CLK;
  __IO	uint32_t TIM2_CLK;
  __IO	uint32_t TIM3_CLK;
  __IO	uint32_t TIM4_CLK;
  __IO	uint32_t TIM5_CLK;


  __IO	uint32_t MIL0_CLK;
  __IO	uint32_t MIL1_CLK;
  __IO	uint32_t MIL2_CLK;
  __IO	uint32_t MIL3_CLK;
  
  __IO	uint32_t ARC0_CLK;
  __IO	uint32_t ARC1_CLK;
  __IO	uint32_t ARC2_CLK;
  __IO	uint32_t ARC3_CLK;
  
  __IO	uint32_t EMAC0_CLK;
  __IO	uint32_t EMAC1_CLK;
  __IO	uint32_t EPHY0_CLK;
  __IO	uint32_t EPHY1_CLK;
  
  __IO	uint32_t SPW0_CLK;
  __IO	uint32_t SPW1_CLK;
  __IO	uint32_t SPHY0_CLK;
  __IO	uint32_t SPHY1_CLK;
  
  __IO	uint32_t UART0_CLK;
  __IO	uint32_t UART1_CLK;
  __IO	uint32_t UART2_CLK;
  __IO	uint32_t UART3_CLK;
  __IO	uint32_t UART4_CLK;
  __IO	uint32_t UART5_CLK;
  
  __IO	uint32_t SSP0_CLK;
  __IO	uint32_t SSP1_CLK;
  __IO	uint32_t SSP2_CLK;
  __IO	uint32_t SSP3_CLK;
  __IO	uint32_t SSP4_CLK;
  __IO	uint32_t SSP5_CLK;
  
  __IO	uint32_t USB_CLK;
  
  __IO	uint32_t ADC0_CLK;
  __IO	uint32_t ADC1_CLK;
  
  __IO	uint32_t DAC0_CLK;
  __IO	uint32_t DAC1_CLK;
  
  __IO	uint32_t RTC_CLK;
  
} CLKControl;

#define CLK_CNTR_BASE	    (( uint32_t) 0x40000000)

#define	CLK_CNTR	    ((CLKControl *) CLK_CNTR_BASE)

/*
#define	BKP_BASE	    (( uint32_t) 0x040001000)
#define BKP_KEY 	    ((uint32_t)	0x8555aaa1)

*/

/** @defgroup Periph_RST_CLK_CAN_CLOCK	RST CLK CAN CLOCK
  * @{
  */ 

/*-- RST_CLK_CAN_CLOCK: CAN Clock Register -------------------------*/
/* Bit field positions: */
#define RST_CLK_CAN_CLOCK_CAN0_BRG_Pos          0
#define RST_CLK_CAN_CLOCK_CAN1_BRG_Pos          0
#define RST_CLK_CAN_CLOCK_CAN0_CLK_EN_Pos       16
#define RST_CLK_CAN_CLOCK_CAN1_CLK_EN_Pos       16

/* Bit field masks: */
#define RST_CLK_CAN_CLOCK_CAN0_BRG_Msk          ((uint32_t)0x0000FFFF)
#define RST_CLK_CAN_CLOCK_CAN1_BRG_Msk          ((uint32_t)0x0000FFFF)
#define RST_CLK_CAN_CLOCK_CAN0_CLK_EN           ((uint32_t)0x00010000)
#define RST_CLK_CAN_CLOCK_CAN1_CLK_EN           ((uint32_t)0x00010000)

/** @} */ /* End of group RST_CLK_CAN_CLOCK */

/** @defgroup Periph_RST_CLK_SSP_CLOCK	RST CLK SSP CLOCK
  * @{
  */ 

/*-- RST_CLK_SSP_CLOCK: SSP Clock Register -------------------------*/
/* Bit field positions: */
#define RST_CLK_SSP_CLOCK_SSP0_BRG_Pos          0
#define RST_CLK_SSP_CLOCK_SSP1_BRG_Pos          0
#define RST_CLK_SSP_CLOCK_SSP0_CLK_EN_Pos       16
#define RST_CLK_SSP_CLOCK_SSP1_CLK_EN_Pos       16

/* Bit field masks: */
#define RST_CLK_SSP_CLOCK_SSP0_BRG_Msk          ((uint32_t)0x0000FFFF)
#define RST_CLK_SSP_CLOCK_SSP1_BRG_Msk          ((uint32_t)0x0000FFFF)
#define RST_CLK_SSP_CLOCK_SSP0_CLK_EN           ((uint32_t)0x00010000)
#define RST_CLK_SSP_CLOCK_SSP1_CLK_EN           ((uint32_t)0x00010000)

/** @} */ /* End of group RST_CLK_SSP_CLOCK */

/** @defgroup Periph_RST_CLK_TIM_CLOCK	RST CLK TIM CLOCK
  * @{
  */ 

/*-- RST_CLK_TIM_CLOCK: Timer Clock Register -----------------------*/
/* Bit field positions: */
#define RST_CLK_TIM_CLOCK_TIM0_BRG_Pos          0
#define RST_CLK_TIM_CLOCK_TIM1_BRG_Pos          0
#define RST_CLK_TIM_CLOCK_TIM2_BRG_Pos          0
#define RST_CLK_TIM_CLOCK_TIM3_BRG_Pos          0
#define RST_CLK_TIM_CLOCK_TIM0_CLK_EN_Pos       16
#define RST_CLK_TIM_CLOCK_TIM1_CLK_EN_Pos       16
#define RST_CLK_TIM_CLOCK_TIM2_CLK_EN_Pos       16
#define RST_CLK_TIM_CLOCK_TIM3_CLK_EN_Pos       16

/* Bit field masks: */
#define RST_CLK_TIM_CLOCK_TIM0_BRG_Msk          ((uint32_t)0x0000FFFF)
#define RST_CLK_TIM_CLOCK_TIM1_BRG_Msk          ((uint32_t)0x0000FFFF)
#define RST_CLK_TIM_CLOCK_TIM2_BRG_Msk          ((uint32_t)0x0000FFFF)
#define RST_CLK_TIM_CLOCK_TIM3_BRG_Msk          ((uint32_t)0x0000FFFF)
#define RST_CLK_TIM_CLOCK_TIM0_CLK_EN           ((uint32_t)0x00010000)
#define RST_CLK_TIM_CLOCK_TIM1_CLK_EN           ((uint32_t)0x00010000)
#define RST_CLK_TIM_CLOCK_TIM2_CLK_EN           ((uint32_t)0x00010000)
#define RST_CLK_TIM_CLOCK_TIM3_CLK_EN           ((uint32_t)0x00010000)

/** @} */ /* End of group RST_CLK_TIM_CLOCK */

/** @defgroup MDR1986VE8T_Periph_RST_CLK_ETR_CLOCK	RST CLK ETR CLOCK
  * @{
  */ 

/*-- RST_CLK_ETR_CLOCK: ETR Clock Register -----------------------*/
/* Bit field positions: */
#define RST_CLK_ETH_CLOCK_ETH_BRG_Pos				0
#define RST_CLK_ETH_CLOCK_MAN_BRG_Pos				0	 //notused
#define RST_CLK_ETH_CLOCK_PHY_BRG_Pos				0
#define RST_CLK_ETH_CLOCK_ETH_CLK_EN_Pos		16
#define RST_CLK_ETH_CLOCK_MAN_CLK_EN_Pos		0	 //notused
#define RST_CLK_ETH_CLOCK_SLEEP_Pos					0  //notused
#define RST_CLK_ETH_CLOCK_PHY_CLK_EN_Pos		16
#define RST_CLK_ETH_CLOCK_PHY_CLK_SEL_Pos		0  //notused
#define RST_CLK_ETH_CLOCK_ETH2_CLK_EN_Pos		0  //notused

/* Bit field masks: */

#define RST_CLK_ETH_CLOCK_MAN_BRG_Msk			((uint32_t)0x00000000)//notused
#define RST_CLK_ETH_CLOCK_MAN_CLK_EN			((uint32_t)0x00000000)//notused
#define RST_CLK_ETH_CLOCK_SLEEP					  ((uint32_t)0x00000000)//notused

#define RST_CLK_ETH_CLOCK_ETH_BRG_Msk			((uint32_t)0x0000FFFF)
#define RST_CLK_ETH_CLOCK_ETH_CLK_EN			((uint32_t)0x00010000)

#define RST_CLK_ETH_CLOCK_PHY_CLK_EN			((uint32_t)0x00010000)
#define RST_CLK_ETH_CLOCK_PHY_CLK_SEL_Msk	((uint32_t)0x00000000)//notused
#define RST_CLK_ETH_CLOCK_PHY_BRG_Msk			((uint32_t)0x0000FFFF)

#define RST_CLK_ETH_CLOCK_ETH2_CLK_EN			((uint32_t)0x00000000)//notused

/** @} */ /* End of group RST_CLK_ETR_CLOCK */

/***
*  PORT control
**/

typedef struct
{
  __IO	uint32_t KEY;
  __IO	uint32_t RXTX;
  __IO	uint32_t SRXTX;
  __IO	uint32_t CRXTX;
  
  __IO	uint32_t SOE;
  __IO	uint32_t COE;

  __IO	uint32_t SFUNC[4];

  __IO	uint32_t CFUNC[4];
  
  __IO	uint32_t SANALOG;
  __IO	uint32_t CANALOG;
  
  __IO	uint32_t SPULLUP;
  __IO	uint32_t CPULLUP;
  
  __IO	uint32_t SPULLDOWN;
  __IO	uint32_t CPULLDOWN;

  __IO	uint32_t SPD;
  __IO	uint32_t CPD;

  __IO	uint32_t SPWR[2];
  __IO	uint32_t CPWR[2];

  __IO	uint32_t SCL;
  __IO	uint32_t CCL;

  __IO	uint32_t SIE;
  __IO	uint32_t CIE;

  __IO	uint32_t SIT;
  __IO	uint32_t CIT;
  
  __IO	uint32_t SIR;
  __IO	uint32_t CIR; 

  __IO	uint32_t HCUR; 
 
} PortControl;



#define PORTA_BASE	    (( uint32_t) 0x40080000)
#define PORTB_BASE	    (( uint32_t) 0x40081000)
#define PORTC_BASE	    (( uint32_t) 0x40082000)
#define PORTD_BASE	    (( uint32_t) 0x40083000)
#define PORTE_BASE	    (( uint32_t) 0x40084000)
#define PORTF_BASE	    (( uint32_t) 0x40085000)

#define	PORTA	    	    ((PortControl *) PORTA_BASE)
#define	PORTB	    	    ((PortControl *) PORTB_BASE)
#define	PORTC	    	    ((PortControl *) PORTC_BASE)
#define	PORTD	    	    ((PortControl *) PORTD_BASE)
#define	PORTE	    	    ((PortControl *) PORTE_BASE)
#define	PORTF	    	    ((PortControl *) PORTF_BASE)

#define FUNC_MASK 0x0f
#define FUNCREGNUM(pin)	(pin >> 3)
#define _FUNCPIN(TYPE) TYPE ## FUNC
#define FUNCPIN(pin,TYPE) _FUNCPIN(TYPE)[FUNCREGNUM(pin)]
#define SFUNCPIN(pin) FUNCPIN(pin,S)
#define CFUNCPIN(pin) FUNCPIN(pin,C)
#define FUNCVAL(pin,func) ((func & FUNC_MASK) << ((pin % 8)<<2))

#define PWR_MASK 0x3
#define PWRREGNUM(pin) (pin >> 4)
#define _PWRPIN(type) type ## PWR
#define PWRPIN(pin, type) _PWRPIN(type)[PWRREGNUM(pin)]
#define SPWRPIN(pin) PWRPIN(pin, S)
#define CPWRPIN(pin) PWRPIN(pin, C)
#define PWRVAL(pin, pwr) ((pwr & PWR_MASK) << ((pin % 16) << 1))

/****
/ USB controller interface
**/
typedef struct
{
  __IO uint32_t HTXC;
  __IO uint32_t HTXT;
  __IO uint32_t HTXLC;
  __IO uint32_t HTXSE;
  __IO uint32_t HTXA;
  __IO uint32_t HTXE;
  __IO uint32_t HFN_L;
  __IO uint32_t HFN_H;
  __IO uint32_t HIS;
  __IO uint32_t HIM;
  __IO uint32_t HRXS;
  __IO uint32_t HRXP;
  __IO uint32_t HRXA;
  __IO uint32_t HRXE;
  __IO uint32_t HRXCS;
  __IO uint32_t HSTM;
  __IO uint32_t RESERVED1[16];
  __IO uint32_t HRXFD;
  __IO uint32_t RESERVED2;
  __IO uint32_t HRXFDC_L;
  __IO uint32_t HRXFDC_H;
  __IO uint32_t HRXFC;
  __IO uint32_t RESERVED3[11];
  __IO uint32_t HTXFD;
  __IO uint32_t RESERVED4[3];
  __IO uint32_t HTXFDC;
  __IO uint32_t RESERVED5[11];

  __IO uint32_t SEP0_CTRL;
  __IO uint32_t SEP0_STS;
  __IO uint32_t SEP0_TS;
  __IO uint32_t SEP0_NTS;
  __IO uint32_t SEP1_CTRL;
  __IO uint32_t SEP1_STS;
  __IO uint32_t SEP1_TS;
  __IO uint32_t SEP1_NTS;
  __IO uint32_t SEP2_CTRL;
  __IO uint32_t SEP2_STS;
  __IO uint32_t SEP2_TS;
  __IO uint32_t SEP2_NTS;
  __IO uint32_t SEP3_CTRL;
  __IO uint32_t SEP3_STS;
  __IO uint32_t SEP3_TS;
  __IO uint32_t SEP3_NTS;
  __IO uint32_t SC;
  __IO uint32_t SLS;
  __IO uint32_t SIS;
  __IO uint32_t SIM;
  __IO uint32_t SA;
  __IO uint32_t SFN_L;
  __IO uint32_t SFN_H;
  __IO uint32_t RESERVED6[9];
 
  __IO uint32_t SEP0_RXFD;
  __IO uint32_t RESERVED7;
  __IO uint32_t SEP0_RXFDC_L;
  __IO uint32_t SEP0_RXFDC_H;
  __IO uint32_t SEP0_RXFC;
  __IO uint32_t RESERVED8[11];
  __IO uint32_t SEP0_TXFD;
  __IO uint32_t RESERVED9[3];
  __IO uint32_t SEP0_TXFDC;
  __IO uint32_t RESERVED10[11];
  __IO uint32_t SEP1_RXFD;
  __IO uint32_t RESERVED11;
  __IO uint32_t SEP1_RXFDC_L;
  __IO uint32_t SEP1_RXFDC_H;
  __IO uint32_t SEP1_RXFC;
  __IO uint32_t RESERVED12[11];
  __IO uint32_t SEP1_TXFD;
  __IO uint32_t RESERVED13[3];
  __IO uint32_t SEP1_TXFDC;
  __IO uint32_t RESERVED14[11];
  __IO uint32_t SEP2_RXFD;
  __IO uint32_t RESERVED15;
  __IO uint32_t SEP2_RXFDC_L;
  __IO uint32_t SEP2_RXFDC_H;
  __IO uint32_t SEP2_RXFC;
  __IO uint32_t RESERVED16[11];
  __IO uint32_t SEP2_TXFD;
  __IO uint32_t RESERVED17[3];
  __IO uint32_t SEP2_TXFDC;
  __IO uint32_t RESERVED18[11];
  __IO uint32_t SEP3_RXFD;
  __IO uint32_t RESERVED19;
  __IO uint32_t SEP3_RXFDC_L;
  __IO uint32_t SEP3_RXFDC_H;
  __IO uint32_t SEP3_RXFC;
  __IO uint32_t RESERVED20[11];
  __IO uint32_t SEP3_TXFD;
  __IO uint32_t RESERVED21[3];
  __IO uint32_t SEP3_TXFDC;
  __IO uint32_t RESERVED22[11];
  
  __IO uint32_t HSCR;
  __IO uint32_t HSVR;
}
USB_Typedef;

#define USB_BASE	0x4009D000
#define USB		((USB_Typedef *) USB_BASE)

/***
*  TIMER32 control
**/
typedef struct
{
  __IO	uint32_t CNT;
  __IO	uint32_t PSG;
  __IO	uint32_t ARR;
  __IO	uint32_t CNTRL;
  __IO	uint32_t CCR1;
  __IO	uint32_t CCR2;
  __IO	uint32_t CCR3;
  __IO	uint32_t CCR4;
  __IO	uint32_t CH1_CNTRL;
  __IO	uint32_t CH2_CNTRL;
  __IO	uint32_t CH3_CNTRL;
  __IO	uint32_t CH4_CNTRL;
  __IO	uint32_t CH1_CNTRL1;
  __IO	uint32_t CH2_CNTRL1;
  __IO	uint32_t CH3_CNTRL1;
  __IO	uint32_t CH4_CNTRL1;
  __IO	uint32_t CH1_DTG;
  __IO	uint32_t CH2_DTG;
  __IO	uint32_t CH3_DTG;
  __IO	uint32_t CH4_DTG;
  __IO	uint32_t BRKETR_CNTRL;
  __IO	uint32_t STATUS;
  __IO	uint32_t IE;
  __IO	uint32_t DMA_RE;
  __IO	uint32_t CH1_CNTRL2;
  __IO	uint32_t CH2_CNTRL2;
  __IO	uint32_t CH3_CNTRL2;
  __IO	uint32_t CH4_CNTRL2;
  __IO	uint32_t CCR11;
  __IO	uint32_t CCR21;
  __IO	uint32_t CCR31;
  __IO	uint32_t CCR41;
  __IO	uint32_t DMA_RECh1;
  __IO	uint32_t DMA_RECh2;
  __IO	uint32_t DMA_RECh3;
  __IO	uint32_t DMA_RECh4;
  
  
}MDR_TMR_TypeDef;

#define MDR_TMR_BASE                 (PERIPH_BASE + 0x80000)

#define MDR_TMR0_BASE		  (MDR_TMR_BASE + 0xA000)
#define MDR_TMR1_BASE		  (MDR_TMR_BASE + 0xB000)
#define MDR_TMR2_BASE		  (MDR_TMR_BASE + 0xC000)
#define MDR_TMR3_BASE		  (MDR_TMR_BASE + 0xD000)
#define MDR_TMR4_BASE		  (MDR_TMR_BASE + 0xE000)
#define MDR_TMR5_BASE		  (MDR_TMR_BASE + 0xF000)

#define MDR_TMR0                     ((MDR_TMR_TypeDef *) MDR_TMR0_BASE)
#define MDR_TMR1                     ((MDR_TMR_TypeDef *) MDR_TMR1_BASE)
#define MDR_TMR2                     ((MDR_TMR_TypeDef *) MDR_TMR2_BASE)
#define MDR_TMR3                     ((MDR_TMR_TypeDef *) MDR_TMR3_BASE)
#define MDR_TMR4                     ((MDR_TMR_TypeDef *) MDR_TMR4_BASE)
#define MDR_TMR5                     ((MDR_TMR_TypeDef *) MDR_TMR5_BASE)

/** @defgroup MDR1986VE8T_Periph_TIMER_Defines Defines
  * @{
  */

/** @defgroup Periph_TIMER_CNTRL	TIMER CNTRL
  * @{
  */ 

/*-- TIMER_CNTRL: Timer Control Register ---------------------------*/
/* Bit field positions: */
#define TIMER_CNTRL_CNT_EN_Pos                  0
#define TIMER_CNTRL_ARRB_EN_Pos                 1
#define TIMER_CNTRL_WR_CMPL_Pos                 2
#define TIMER_CNTRL_DIR_Pos                     3
#define TIMER_CNTRL_FDTS_Pos                    4
#define TIMER_CNTRL_CNT_MODE_Pos                6
#define TIMER_CNTRL_EVENT_SEL_Pos               8

/* Bit field masks: */
#define TIMER_CNTRL_CNT_EN                      ((uint32_t)0x00000001)
#define TIMER_CNTRL_ARRB_EN                     ((uint32_t)0x00000002)
#define TIMER_CNTRL_WR_CMPL                     ((uint32_t)0x00000004)
#define TIMER_CNTRL_DIR                         ((uint32_t)0x00000008)
#define TIMER_CNTRL_FDTS_Msk                    ((uint32_t)0x00000030)
#define TIMER_CNTRL_CNT_MODE_Msk                ((uint32_t)0x000000C0)
#define TIMER_CNTRL_EVENT_SEL_Msk               ((uint32_t)0x00000F00)

/** @} */ /* End of group TIMER_CNTRL */

/** @defgroup Periph_TIMER_CH_CNTRL	TIMER CH CNTRL
  * @{
  */ 

/*-- TIMER_CH_CNTRL: Timer Channel Control Register ----------------*/
/* Bit field positions: */
#define TIMER_CH_CNTRL_CHFLTR_Pos               0
#define TIMER_CH_CNTRL_CHSEL_Pos                4
#define TIMER_CH_CNTRL_CHPSC_Pos                6
#define TIMER_CH_CNTRL_OCCE_Pos                 8
#define TIMER_CH_CNTRL_OCCM_Pos                 9
#define TIMER_CH_CNTRL_BRKEN_Pos                12
#define TIMER_CH_CNTRL_ETREN_Pos                13
#define TIMER_CH_CNTRL_WR_CMPL_Pos              14
#define TIMER_CH_CNTRL_CAP_NPWM_Pos             15

/* Bit field masks: */
#define TIMER_CH_CNTRL_CHFLTR_Msk               ((uint32_t)0x0000000F)
#define TIMER_CH_CNTRL_CHSEL_Msk                ((uint32_t)0x00000030)
#define TIMER_CH_CNTRL_CHPSC_Msk                ((uint32_t)0x000000C0)
#define TIMER_CH_CNTRL_OCCE                     ((uint32_t)0x00000100)
#define TIMER_CH_CNTRL_OCCM_Msk                 ((uint32_t)0x00000E00)
#define TIMER_CH_CNTRL_BRKEN                    ((uint32_t)0x00001000)
#define TIMER_CH_CNTRL_ETREN                    ((uint32_t)0x00002000)
#define TIMER_CH_CNTRL_WR_CMPL                  ((uint32_t)0x00004000)
#define TIMER_CH_CNTRL_CAP_NPWM                 ((uint32_t)0x00008000)

/** @} */ /* End of group TIMER_CH_CNTRL */

/** @defgroup Periph_TIMER_CH_CNTRL1	TIMER CH CNTRL1
  * @{
  */ 

/*-- TIMER_CH_CNTRL1: Timer Channel Control1 Register --------------*/
/* Bit field positions: */
#define TIMER_CH_CNTRL1_SELOE_Pos               0
#define TIMER_CH_CNTRL1_SELO_Pos                2
#define TIMER_CH_CNTRL1_INV_Pos                 4
#define TIMER_CH_CNTRL1_NSELOE_Pos              8
#define TIMER_CH_CNTRL1_NSELO_Pos               10
#define TIMER_CH_CNTRL1_NINV_Pos                12

/* Bit field masks: */
#define TIMER_CH_CNTRL1_SELOE_Msk               ((uint32_t)0x00000003)
#define TIMER_CH_CNTRL1_SELO_Msk                ((uint32_t)0x0000000C)
#define TIMER_CH_CNTRL1_INV                     ((uint32_t)0x00000010)
#define TIMER_CH_CNTRL1_NSELOE_Msk              ((uint32_t)0x00000300)
#define TIMER_CH_CNTRL1_NSELO_Msk               ((uint32_t)0x00000C00)
#define TIMER_CH_CNTRL1_NINV                    ((uint32_t)0x00001000)

/** @} */ /* End of group TIMER_CH_CNTRL1 */

/** @defgroup Periph_TIMER_CH_DTG	TIMER CH DTG
  * @{
  */ 

/*-- TIMER_CH_DTG: Timer Channel DTG Register ----------------------*/
/* Bit field positions: */
#define TIMER_CH_DTGX_Pos                       0
#define TIMER_CH_DTG_EDTS_Pos                   4
#define TIMER_CH_DTG_Pos                        8

/* Bit field masks: */
#define TIMER_CH_DTGX_Msk                       ((uint32_t)0x0000000F)
#define TIMER_CH_DTG_EDTS                       ((uint32_t)0x00000010)
#define TIMER_CH_DTG_Msk                        ((uint32_t)0x0000FF00)

/** @} */ /* End of group TIMER_CH_DTG */

/** @defgroup Periph_TIMER_BRKETR_CNTRL	TIMER BRKETR CNTRL
  * @{
  */ 

/*-- TIMER_BRKETR_CNTRL: Timer BRK/ETR Control Register ------------*/
/* Bit field positions: */
#define TIMER_BRKETR_CNTRL_BRK_INV_Pos          0
#define TIMER_BRKETR_CNTRL_ETR_INV_Pos          1
#define TIMER_BRKETR_CNTRL_ETR_PSC_Pos          2
#define TIMER_BRKETR_CNTRL_ETR_FILTER_Pos       4

/* Bit field masks: */
#define TIMER_BRKETR_CNTRL_BRK_INV              ((uint32_t)0x00000001)
#define TIMER_BRKETR_CNTRL_ETR_INV              ((uint32_t)0x00000002)
#define TIMER_BRKETR_CNTRL_ETR_PSC_Msk          ((uint32_t)0x0000000C)
#define TIMER_BRKETR_CNTRL_ETR_FILTER_Msk       ((uint32_t)0x000000F0)

/** @} */ /* End of group TIMER_BRKETR_CNTRL */

/** @defgroup Periph_TIMER_STATUS	TIMER STATUS
  * @{
  */ 

/*-- TIMER_STATUS: Timer Status Register ---------------------------*/
/* Bit field positions: */
#define TIMER_STATUS_CNT_ZERO_EVENT_Pos         0
#define TIMER_STATUS_CNT_ARR_EVENT_Pos          1
#define TIMER_STATUS_ETR_RE_EVENT_Pos           2
#define TIMER_STATUS_ETR_FE_EVENT_Pos           3
#define TIMER_STATUS_BRK_EVENT_Pos              4
#define TIMER_STATUS_CCR_CAP_EVENT_Pos          5
#define TIMER_STATUS_CCR_REF_EVENT_Pos          9
#define TIMER_STATUS_CCR1_CAP_EVENT_Pos         13

/* Bit field masks: */
#define TIMER_STATUS_CNT_ZERO_EVENT             ((uint32_t)0x00000001)
#define TIMER_STATUS_CNT_ARR_EVENT              ((uint32_t)0x00000002)
#define TIMER_STATUS_ETR_RE_EVENT               ((uint32_t)0x00000004)
#define TIMER_STATUS_ETR_FE_EVENT               ((uint32_t)0x00000008)
#define TIMER_STATUS_BRK_EVENT                  ((uint32_t)0x00000010)
#define TIMER_STATUS_CCR_CAP_EVENT_Msk          ((uint32_t)0x000001E0)
#define TIMER_STATUS_CCR_REF_EVENT_Msk          ((uint32_t)0x00001E00)
#define TIMER_STATUS_CCR1_CAP_EVENT_Msk         ((uint32_t)0x0001E000)

/** @} */ /* End of group TIMER_STATUS */

/** @defgroup Periph_TIMER_IE	TIMER IE
  * @{
  */ 

/*-- TIMER_IE: Timer Interrupt Enable Register ---------------------*/
/* Bit field positions: */
#define TIMER_IE_CNT_ZERO_EVENT_IE_Pos          0
#define TIMER_IE_CNT_ARR_EVENT_IE_Pos           1
#define TIMER_IE_ETR_RE_EVENT_IE_Pos            2
#define TIMER_IE_ETR_FE_EVENT_IE_Pos            3
#define TIMER_IE_BRK_EVENT_IE_Pos               4
#define TIMER_IE_CCR_CAP_EVENT_IE_Pos           5
#define TIMER_IE_CCR_REF_EVENT_IE_Pos           9
#define TIMER_IE_CCR1_CAP_EVENT_IE_Pos          13

/* Bit field masks: */
#define TIMER_IE_CNT_ZERO_EVENT_IE              ((uint32_t)0x00000001)
#define TIMER_IE_CNT_ARR_EVENT_IE               ((uint32_t)0x00000002)
#define TIMER_IE_ETR_RE_EVENT_IE                ((uint32_t)0x00000004)
#define TIMER_IE_ETR_FE_EVENT_IE                ((uint32_t)0x00000008)
#define TIMER_IE_BRK_EVENT_IE                   ((uint32_t)0x00000010)
#define TIMER_IE_CCR_CAP_EVENT_IE_Msk           ((uint32_t)0x000001E0)
#define TIMER_IE_CCR_REF_EVENT_IE_Msk           ((uint32_t)0x00001E00)
#define TIMER_IE_CCR1_CAP_EVENT_IE_Msk          ((uint32_t)0x0001E000)

/** @} */ /* End of group TIMER_IE */

/** @defgroup Periph_TIMER_DMA_RE	TIMER DMA RE
  * @{
  */ 

/*-- TIMER_DMA_RE: Timer DMA Request Enable Register ---------------*/
/* Bit field positions: */
#define TIMER_DMA_RE_CNT_ZERO_EVENT_RE_Pos      0
#define TIMER_DMA_RE_CNT_ARR_EVENT_RE_Pos       1
#define TIMER_DMA_RE_ETR_RE_EVENT_RE_Pos        2
#define TIMER_DMA_RE_ETR_FE_EVENT_RE_Pos        3
#define TIMER_DMA_RE_BRK_EVENT_RE_Pos           4
#define TIMER_DMA_RE_CCR_CAP_EVENT_RE_Pos       5
#define TIMER_DMA_RE_CCR_REF_EVENT_RE_Pos       9
#define TIMER_DMA_RE_CCR1_CAP_EVENT_RE_Pos      13

/* Bit field masks: */
#define TIMER_DMA_RE_CNT_ZERO_EVENT_RE          ((uint32_t)0x00000001)
#define TIMER_DMA_RE_CNT_ARR_EVENT_RE           ((uint32_t)0x00000002)
#define TIMER_DMA_RE_ETR_RE_EVENT_RE            ((uint32_t)0x00000004)
#define TIMER_DMA_RE_ETR_FE_EVENT_RE            ((uint32_t)0x00000008)
#define TIMER_DMA_RE_BRK_EVENT_RE               ((uint32_t)0x00000010)
#define TIMER_DMA_RE_CCR_CAP_EVENT_RE_Msk       ((uint32_t)0x000001E0)
#define TIMER_DMA_RE_CCR_REF_EVENT_RE_Msk       ((uint32_t)0x00001E00)
#define TIMER_DMA_RE_CCR1_CAP_EVENT_RE_Msk      ((uint32_t)0x0001E000)

/** @} */ /* End of group TIMER_DMA_RE */

/** @defgroup Periph_TIMER_CH_CNTRL2	TIMER CH CNTRL2
  * @{
  */ 

/*-- TIMER_CH_CNTRL2: Timer Channel Control2 Register --------------*/
/* Bit field positions: */
#define TIMER_CH_CNTRL2_CHSEL1_Pos              0
#define TIMER_CH_CNTRL2_CCR1_EN_Pos             2
#define TIMER_CH_CNTRL2_CCRRLD_Pos              3

/* Bit field masks: */
#define TIMER_CH_CNTRL2_CHSEL1_Msk              ((uint32_t)0x00000003)
#define TIMER_CH_CNTRL2_CCR1_EN                 ((uint32_t)0x00000004)
#define TIMER_CH_CNTRL2_CCRRLD                  ((uint32_t)0x00000008)

/** @} */ /* End of group TIMER_CH_CNTRL2 */

/** @} */ /* End of group MDR1986VE8T_Periph_TIMER_Defines */


/***
*  MDR_CAN control
**/
typedef struct
{
__IO	uint32_t ID;
__IO	uint32_t DLC;
__IO	uint32_t DATAL;
__IO	uint32_t DATAH;
}MDR_CAN_BUF_TypeDef;

typedef struct
{
__IO	uint32_t MASK;
__IO	uint32_t FILTER;
}MDR_CAN_BUF_FILTER_TypeDef;

typedef struct
{
  __IO	uint32_t CONTROL;  
  __IO	uint32_t STATUS;
  __IO	uint32_t BITTMNG;
  __IO	uint32_t Reserved0;
  __IO	uint32_t INT_EN;
  __IO	uint32_t Reserved1[2];
  __IO	uint32_t OVER;
  __IO	uint32_t RXID;
  __IO	uint32_t RXDLC;
  __IO	uint32_t RXDATAL;
  __IO	uint32_t RXDATAH;
  __IO	uint32_t TXID;
  __IO	uint32_t TXDLC;
  __IO	uint32_t DATAL;
  __IO	uint32_t DATAH;
  __IO	uint32_t BUF_CON[32];
  __IO	uint32_t INT_RX;
  __IO	uint32_t RX;
  __IO	uint32_t INT_TX;
  __IO	uint32_t TX;
  __IO	uint32_t Reserved2[76];
  MDR_CAN_BUF_TypeDef BUF[32];
  __IO	uint32_t Reserved3[64];
  MDR_CAN_BUF_FILTER_TypeDef FILTER[32];

}MDR_CAN_TypeDef;

#define MDR_CAN_BASE                 (PERIPH_BASE + 0x90000)

#define MDR_CAN0_BASE		  (MDR_CAN_BASE + 0x0000)
#define MDR_CAN1_BASE		  (MDR_CAN_BASE + 0x1000)
#define MDR_CAN2_BASE		  (MDR_CAN_BASE + 0x2000)
#define MDR_CAN3_BASE		  (MDR_CAN_BASE + 0x3000)
#define MDR_CAN4_BASE		  (MDR_CAN_BASE + 0x4000)

#define MDR_CAN0                     ((MDR_CAN_TypeDef *) MDR_CAN0_BASE)
#define MDR_CAN1                     ((MDR_CAN_TypeDef *) MDR_CAN1_BASE)
#define MDR_CAN2                     ((MDR_CAN_TypeDef *) MDR_CAN2_BASE)
#define MDR_CAN3                     ((MDR_CAN_TypeDef *) MDR_CAN3_BASE)
#define MDR_CAN4                     ((MDR_CAN_TypeDef *) MDR_CAN4_BASE)

/** @defgroup MDR1986VE8T_Periph_CAN_Defines Defines
  * @{
  */

/** @defgroup Periph_CAN_CONTROL	CAN CONTROL
  * @{
  */ 

/*-- CAN_CONTROL: CAN Control Register -----------------------------*/
/* Bit field positions: */
#define CAN_CONTROL_CAN_EN_Pos                  0
#define CAN_CONTROL_ROM_Pos                     1
#define CAN_CONTROL_STM_Pos                     2
#define CAN_CONTROL_SAP_Pos                     3
#define CAN_CONTROL_ROP_Pos                     4

/* Bit field masks: */
#define CAN_CONTROL_CAN_EN                      ((uint32_t)0x00000001)
#define CAN_CONTROL_ROM                         ((uint32_t)0x00000002)
#define CAN_CONTROL_STM                         ((uint32_t)0x00000004)
#define CAN_CONTROL_SAP                         ((uint32_t)0x00000008)
#define CAN_CONTROL_ROP                         ((uint32_t)0x00000010)

/** @} */ /* End of group CAN_CONTROL */

/** @defgroup Periph_CAN_STATUS	CAN STATUS
  * @{
  */ 

/*-- CAN_STATUS: CAN Status Register -------------------------------*/
/* Bit field positions: */
#define CAN_STATUS_RX_READY_Pos                 0
#define CAN_STATUS_TX_READY_Pos                 1
#define CAN_STATUS_ERROR_OVER_Pos               2
#define CAN_STATUS_BIT_ERR_Pos                  3
#define CAN_STATUS_BIT_STUFF_ERR_Pos            4
#define CAN_STATUS_CRC_ERR_Pos                  5
#define CAN_STATUS_FRAME_ERR_Pos                6
#define CAN_STATUS_ACK_ERR_Pos                  7
#define CAN_STATUS_IDLOWER_Pos                  8
#define CAN_STATUS_ERR_STATUS_Pos               9
#define CAN_STATUS_RX_ERR_CNT8_Pos              11
#define CAN_STATUS_TX_ERR_CNT8_Pos              12
#define CAN_STATUS_RX_ERR_CNT_Pos               16
#define CAN_STATUS_TX_ERR_CNT_Pos               24

/* Bit field masks: */
#define CAN_STATUS_RX_READY                     ((uint32_t)0x00000001)
#define CAN_STATUS_TX_READY                     ((uint32_t)0x00000002)
#define CAN_STATUS_ERROR_OVER                   ((uint32_t)0x00000004)
#define CAN_STATUS_BIT_ERR                      ((uint32_t)0x00000008)
#define CAN_STATUS_BIT_STUFF_ERR                ((uint32_t)0x00000010)
#define CAN_STATUS_CRC_ERR                      ((uint32_t)0x00000020)
#define CAN_STATUS_FRAME_ERR                    ((uint32_t)0x00000040)
#define CAN_STATUS_ACK_ERR                      ((uint32_t)0x00000080)
#define CAN_STATUS_IDLOWER                      ((uint32_t)0x00000100)
#define CAN_STATUS_ERR_STATUS_Msk               ((uint32_t)0x00000600)
#define CAN_STATUS_RX_ERR_CNT8                  ((uint32_t)0x00000800)
#define CAN_STATUS_TX_ERR_CNT8                  ((uint32_t)0x00001000)
#define CAN_STATUS_RX_ERR_CNT_Msk               ((uint32_t)0x00FF0000)
#define CAN_STATUS_TX_ERR_CNT_Msk               ((uint32_t)0xFF000000)

/** @} */ /* End of group CAN_STATUS */

/** @defgroup Periph_CAN_BITTMNG	CAN BITTMNG
  * @{
  */ 

/*-- CAN_BITTMNG: CAN Bittiming Register ---------------------------*/
/* Bit field positions: */
#define CAN_BITTMNG_BRP_Pos                     0
#define CAN_BITTMNG_PSEG_Pos                    16
#define CAN_BITTMNG_SEG1_Pos                    19
#define CAN_BITTMNG_SEG2_Pos                    22
#define CAN_BITTMNG_SJW_Pos                     25
#define CAN_BITTMNG_SB_Pos                      27

/* Bit field masks: */
#define CAN_BITTMNG_BRP_Msk                     ((uint32_t)0x0000FFFF)
#define CAN_BITTMNG_PSEG_Msk                    ((uint32_t)0x00070000)
#define CAN_BITTMNG_SEG1_Msk                    ((uint32_t)0x00380000)
#define CAN_BITTMNG_SEG2_Msk                    ((uint32_t)0x01C00000)
#define CAN_BITTMNG_SJW_Msk                     ((uint32_t)0x06000000)
#define CAN_BITTMNG_SB                          ((uint32_t)0x08000000)

/** @} */ /* End of group CAN_BITTMNG */

/** @defgroup Periph_CAN_INT_EN	CAN INT EN
  * @{
  */ 

/*-- CAN_INT_EN: CAN Interrupt enable Register ---------------------*/
/* Bit field positions: */
#define CAN_INT_EN_GLB_INT_EN_Pos               0
#define CAN_INT_EN_RX_INT_EN_Pos                1
#define CAN_INT_EN_TX_INT_EN_Pos                2
#define CAN_INT_EN_ERR_INT_EN_Pos               3
#define CAN_INT_EN_ERR_OVER_INT_EN_Pos          4

/* Bit field masks: */
#define CAN_INT_EN_GLB_INT_EN                   ((uint32_t)0x00000001)
#define CAN_INT_EN_RX_INT_EN                    ((uint32_t)0x00000002)
#define CAN_INT_EN_TX_INT_EN                    ((uint32_t)0x00000004)
#define CAN_INT_EN_ERR_INT_EN                   ((uint32_t)0x00000008)
#define CAN_INT_EN_ERR_OVER_INT_EN              ((uint32_t)0x00000010)

/** @} */ /* End of group CAN_INT_EN */

/** @defgroup Periph_CAN_RXID	CAN RXID
  * @{
  */ 

/*-- CAN_RXID:   CAN Receive ID Register ---------------------------*/
/*-- CAN_TXID:   CAN Transmit ID Register --------------------------*/
/*-- CAN_BUF_ID: CAN Buffer ID Register ----------------------------*/
/* Bit field positions: */
#define CAN_ID_EID_Pos                          0
#define CAN_ID_SID_Pos                          18

/* Bit field masks: */
#define CAN_ID_EID_Msk                          ((uint32_t)0x0003FFFF)
#define CAN_ID_SID_Msk                          ((uint32_t)0x1FFC0000)

/** @} */ /* End of group CAN_RXID */

/** @defgroup Periph_CAN_RXDLC	CAN RXDLC
  * @{
  */ 

/*-- CAN_RXDLC:   CAN Receive DLC Register -------------------------*/
/*-- CAN_TXDLC:   CAN Transmit DLC Register ------------------------*/
/*-- CAN_BUF_DLC: CAN Buffer DLC Register --------------------------*/
/* Bit field positions: */
#define CAN_DLC_Pos                             0
#define CAN_DLC_RTR_Pos                         8
#define CAN_DLC_R1_Pos                          9
#define CAN_DLC_R0_Pos                          10
#define CAN_DLC_SSR_Pos                         11
#define CAN_DLC_IDE_Pos                         12

/* Bit field masks: */
#define CAN_DLC_Msk                             ((uint32_t)0x0000000F)
#define CAN_DLC_RTR                             ((uint32_t)0x00000100)
#define CAN_DLC_R1                              ((uint32_t)0x00000200)
#define CAN_DLC_R0                              ((uint32_t)0x00000400)
#define CAN_DLC_SSR                             ((uint32_t)0x00000800)
#define CAN_DLC_IDE                             ((uint32_t)0x00001000)

/** @} */ /* End of group CAN_RXDLC */

/** @defgroup Periph_CAN_RXDATAL	CAN RXDATAL
  * @{
  */ 

/*-- CAN_RXDATAL:   CAN Receive Data low Register ------------------*/
/*-- CAN_DATAL:     CAN Transmit Data low Register -----------------*/
/*-- CAN_BUF_DATAL: CAN Buffer Data low Register -------------------*/
/* Bit field positions: */
#define CAN_DATAL_DB0_Pos                       0
#define CAN_DATAL_DB1_Pos                       8
#define CAN_DATAL_DB2_Pos                       16
#define CAN_DATAL_DB3_Pos                       24

/* Bit field masks: */
#define CAN_DATAL_DB0_Msk                       ((uint32_t)0x000000FF)
#define CAN_DATAL_DB1_Msk                       ((uint32_t)0x0000FF00)
#define CAN_DATAL_DB2_Msk                       ((uint32_t)0x00FF0000)
#define CAN_DATAL_DB3_Msk                       ((uint32_t)0xFF000000)

/** @} */ /* End of group CAN_RXDATAL */

/** @defgroup Periph_CAN_RXDATAH	CAN RXDATAH
  * @{
  */ 

/*-- CAN_RXDATAH:   CAN Receive Data high Register -----------------*/
/*-- CAN_DATAH:     CAN Transmit Data high Register ----------------*/
/*-- CAN_BUF_DATAH: CAN Buffer Data high Register ------------------*/
/* Bit field positions: */
#define CAN_DATAH_DB4_Pos                       0
#define CAN_DATAH_DB5_Pos                       8
#define CAN_DATAH_DB6_Pos                       16
#define CAN_DATAH_DB7_Pos                       24

/* Bit field masks: */
#define CAN_DATAH_DB4_Msk                       ((uint32_t)0x000000FF)
#define CAN_DATAH_DB5_Msk                       ((uint32_t)0x0000FF00)
#define CAN_DATAH_DB6_Msk                       ((uint32_t)0x00FF0000)
#define CAN_DATAH_DB7_Msk                       ((uint32_t)0xFF000000)

/** @} */ /* End of group CAN_RXDATAH */

/** @defgroup Periph_CAN_BUF_CON	CAN BUF CON
  * @{
  */ 

/*-- CAN_BUF_CON: CAN Buffer Connection Register -------------------*/
/* Bit field positions: */
#define CAN_BUF_CON_EN_Pos                      0
#define CAN_BUF_CON_RX_TXN_Pos                  1
#define CAN_BUF_CON_OVER_EN_Pos                 2
#define CAN_BUF_CON_RTR_EN_Pos                  3
#define CAN_BUF_CON_PRIOR_0_Pos                 4
#define CAN_BUF_CON_TX_REQ_Pos                  5
#define CAN_BUF_CON_RX_FULL_Pos                 6
#define CAN_BUF_CON_OVER_WR_Pos                 7

/* Bit field masks: */
#define CAN_BUF_CON_EN                          ((uint32_t)0x00000001)
#define CAN_BUF_CON_RX_TXN                      ((uint32_t)0x00000002)
#define CAN_BUF_CON_OVER_EN                     ((uint32_t)0x00000004)
#define CAN_BUF_CON_RTR_EN                      ((uint32_t)0x00000008)
#define CAN_BUF_CON_PRIOR_0                     ((uint32_t)0x00000010)
#define CAN_BUF_CON_TX_REQ                      ((uint32_t)0x00000020)
#define CAN_BUF_CON_RX_FULL                     ((uint32_t)0x00000040)
#define CAN_BUF_CON_OVER_WR                     ((uint32_t)0x00000080)

/** @} */ /* End of group CAN_BUF_CON */

/** @} */ /* End of group MDR1986VE8T_Periph_CAN_Defines */


/***
*  MDR_SSP control
**/
typedef struct
{
  __IO	uint32_t CR0;
  __IO	uint32_t CR1;
  __IO	uint32_t DR;
  __IO	uint32_t SR;
  __IO	uint32_t CPSR;
  __IO	uint32_t IMSC;
  __IO	uint32_t RIS;
  __IO	uint32_t MIS;
  __IO	uint32_t ICR;
  __IO	uint32_t DMACR;
}MDR_SSP_TypeDef;

#define MDR_SSP_BASE                 (PERIPH_BASE + 0x90000)

#define MDR_SSP0_BASE		  (MDR_SSP_BASE + 0x5000)
#define MDR_SSP1_BASE		  (MDR_SSP_BASE + 0x6000)
#define MDR_SSP2_BASE		  (MDR_SSP_BASE + 0x7000)
#define MDR_SSP3_BASE		  (MDR_SSP_BASE + 0x8000)

#define MDR_SSP0                     ((MDR_SSP_TypeDef *) MDR_SSP0_BASE)
#define MDR_SSP1                     ((MDR_SSP_TypeDef *) MDR_SSP1_BASE)
#define MDR_SSP2                     ((MDR_SSP_TypeDef *) MDR_SSP2_BASE)
#define MDR_SSP3                     ((MDR_SSP_TypeDef *) MDR_SSP3_BASE)

/** @defgroup MDR1986VE8T_Periph_SSP_Defines Defines
  * @{
  */

/** @defgroup Periph_SSP_CR0	SSP CR0
  * @{
  */ 

/*-- SSP_CR0: SSP Control0 Register --------------------------------*/
/* Bit field positions: */
#define SSP_CR0_DSS_Pos                         0
#define SSP_CR0_FRF_Pos                         4
#define SSP_CR0_SPO_Pos                         6
#define SSP_CR0_SPH_Pos                         7
#define SSP_CR0_SCR_Pos                         8

/* Bit field masks: */
#define SSP_CR0_DSS_Msk                         ((uint32_t)0x0000000F)
#define SSP_CR0_FRF_Msk                         ((uint32_t)0x00000030)
#define SSP_CR0_SPO                             ((uint32_t)0x00000040)
#define SSP_CR0_SPH                             ((uint32_t)0x00000080)
#define SSP_CR0_SCR_Msk                         ((uint32_t)0x0000FF00)

/** @} */ /* End of group SSP_CR0 */

/** @defgroup Periph_SSP_CR1	SSP CR1
  * @{
  */ 

/*-- SSP_CR1: SSP Control1 Register --------------------------------*/
/* Bit field positions: */
#define SSP_CR1_LBM_Pos                         0
#define SSP_CR1_SSE_Pos                         1
#define SSP_CR1_MS_Pos                          2
#define SSP_CR1_SOD_Pos                         3

/* Bit field masks: */
#define SSP_CR1_LBM                             ((uint32_t)0x00000001)
#define SSP_CR1_SSE                             ((uint32_t)0x00000002)
#define SSP_CR1_MS                              ((uint32_t)0x00000004)
#define SSP_CR1_SOD                             ((uint32_t)0x00000008)

/** @} */ /* End of group SSP_CR1 */

/** @defgroup Periph_SSP_SR	SSP SR
  * @{
  */ 

/*-- SSP_SR: SSP Status Register -----------------------------------*/
/* Bit field positions: */
#define SSP_SR_TFE_Pos                          0
#define SSP_SR_TNF_Pos                          1
#define SSP_SR_RNE_Pos                          2
#define SSP_SR_RFF_Pos                          3
#define SSP_SR_BSY_Pos                          4

/* Bit field masks: */
#define SSP_SR_TFE                              ((uint32_t)0x00000001)
#define SSP_SR_TNF                              ((uint32_t)0x00000002)
#define SSP_SR_RNE                              ((uint32_t)0x00000004)
#define SSP_SR_RFF                              ((uint32_t)0x00000008)
#define SSP_SR_BSY                              ((uint32_t)0x00000010)

/** @} */ /* End of group SSP_SR */

/** @defgroup Periph_SSP_IMSC	SSP IMSC
  * @{
  */ 

/*-- SSP_IMSC: SSP Interrupt Mask Register -------------------------*/
/* Bit field positions: */
#define SSP_IMSC_RORIM_Pos                      0
#define SSP_IMSC_RTIM_Pos                       1
#define SSP_IMSC_RXIM_Pos                       2
#define SSP_IMSC_TXIM_Pos                       3

/* Bit field masks: */
#define SSP_IMSC_RORIM                          ((uint32_t)0x00000001)
#define SSP_IMSC_RTIM                           ((uint32_t)0x00000002)
#define SSP_IMSC_RXIM                           ((uint32_t)0x00000004)
#define SSP_IMSC_TXIM                           ((uint32_t)0x00000008)

/** @} */ /* End of group SSP_IMSC */

/** @defgroup Periph_SSP_RIS	SSP RIS
  * @{
  */ 

/*-- SSP_RIS: SSP Interrupt Pending Register -----------------------*/
/* Bit field positions: */
#define SSP_RIS_RORRIS_Pos                      0
#define SSP_RIS_RTRIS_Pos                       1
#define SSP_RIS_RXRIS_Pos                       2
#define SSP_RIS_TXRIS_Pos                       3

/* Bit field masks: */
#define SSP_RIS_RORRIS                          ((uint32_t)0x00000001)
#define SSP_RIS_RTRIS                           ((uint32_t)0x00000002)
#define SSP_RIS_RXRIS                           ((uint32_t)0x00000004)
#define SSP_RIS_TXRIS                           ((uint32_t)0x00000008)

/** @} */ /* End of group SSP_RIS */

/** @defgroup Periph_SSP_MIS	SSP MIS
  * @{
  */ 

/*-- SSP_MIS: SSP Masked Interrupt Pending Register ----------------*/
/* Bit field positions: */
#define SSP_MIS_RORMIS_Pos                      0
#define SSP_MIS_RTMIS_Pos                       1
#define SSP_MIS_RXMIS_Pos                       2
#define SSP_MIS_TXMIS_Pos                       3

/* Bit field masks: */
#define SSP_MIS_RORMIS                          ((uint32_t)0x00000001)
#define SSP_MIS_RTMIS                           ((uint32_t)0x00000002)
#define SSP_MIS_RXMIS                           ((uint32_t)0x00000004)
#define SSP_MIS_TXMIS                           ((uint32_t)0x00000008)

/** @} */ /* End of group SSP_MIS */

/** @defgroup Periph_SSP_ICR	SSP ICR
  * @{
  */ 

/*-- SSP_ICR: SSP Interrupt Clear Register -------------------------*/
/* Bit field positions: */
#define SSP_ICR_RORIC_Pos                       0
#define SSP_ICR_RTIC_Pos                        1

/* Bit field masks: */
#define SSP_ICR_RORIC                           ((uint32_t)0x00000001)
#define SSP_ICR_RTIC                            ((uint32_t)0x00000002)

/** @} */ /* End of group SSP_ICR */

/** @defgroup Periph_SSP_DMACR	SSP DMACR
  * @{
  */ 

/*-- SSP_DMACR: SSP DMA Control Register ---------------------------*/
/* Bit field positions: */
#define SSP_DMACR_RXDMAE_Pos                    0
#define SSP_DMACR_TXDMAE_Pos                    1

/* Bit field masks: */
#define SSP_DMACR_RXDMAE                        ((uint32_t)0x00000001)
#define SSP_DMACR_TXDMAE                        ((uint32_t)0x00000002)

/** @} */ /* End of group SSP_DMACR */

/** @} */ /* End of group MDR1986VE8T_Periph_SSP_Defines */


/***
*  MDR_UART control
**/
typedef struct
{
  __IO	uint32_t DR;
  __IO	uint32_t RSR_ECR;
  __IO	uint32_t Reserved1[4];
  __IO	uint32_t FR;
  __IO	uint32_t Reserved2;
  __IO	uint32_t ILPR;
  __IO	uint32_t IBRD;
  __IO	uint32_t FBRD;
  __IO	uint32_t LCR_H;
  __IO	uint32_t CR;
  __IO	uint32_t IFLS;
  __IO	uint32_t IMSC;
  __IO	uint32_t RIS;
  __IO	uint32_t MIS;
  __IO	uint32_t ICR;
  __IO	uint32_t DMACR;
}MDR_UART_TypeDef;

#define MDR_UART_BASE                 (PERIPH_BASE + 0x90000)

#define MDR_UART0_BASE		  (MDR_UART_BASE + 0x9000)//0x9000
#define MDR_UART1_BASE		  (MDR_UART_BASE + 0xA000)
#define MDR_UART2_BASE		  (MDR_UART_BASE + 0xB000)
#define MDR_UART3_BASE		  (MDR_UART_BASE + 0xC000)

#define MDR_UART0                     ((MDR_UART_TypeDef *) MDR_UART0_BASE)
#define MDR_UART1                     ((MDR_UART_TypeDef *) MDR_UART1_BASE)
#define MDR_UART2                     ((MDR_UART_TypeDef *) MDR_UART2_BASE)
#define MDR_UART3                     ((MDR_UART_TypeDef *) MDR_UART3_BASE)


/***
*  MDR_SPW control
**/
typedef struct
{
  __IO	uint32_t CONTROL;
  __IO	uint32_t STATUS;
  __IO	uint32_t DIV;
  __IO	uint32_t TIME;
  __IO	uint32_t PAUSE;
  __IO	uint32_t FIFORX;
  __IO	uint32_t FIFOTX;
  __IO	uint32_t CNTRX_PACK;
  __IO	uint32_t CNTRX0_PACK;
  __IO	uint32_t NUM_TXDESC;
  __IO	uint32_t NUM_RXDESC;
  __IO	uint32_t PHY_CNTR;
  __IO	uint32_t RESERV[4];
  __IO	uint32_t RXDESC[16];
  __IO	uint32_t TXDESC[16];
}MDR_SPW_TypeDef;

#define MDR_SPW_BASE                 (PERIPH_BASE + 0x80000)

#define MDR_SPW0_BASE		  (MDR_SPW_BASE + 0x8000)
#define MDR_SPW1_BASE		  (MDR_SPW_BASE + 0x9000)

#define MDR_SPW0                     ((MDR_SPW_TypeDef *) MDR_SPW0_BASE)
#define MDR_SPW1                     ((MDR_SPW_TypeDef *) MDR_SPW1_BASE)

/***
*  MDR_ETH control
**/

typedef struct
{
  __IO	uint16_t DILIMETR;
  __IO	uint16_t MAC_T;
  __IO	uint16_t MAC_M;
  __IO	uint16_t MAC_H;
  __IO	uint16_t HASH0;
  __IO	uint16_t HASH1;
  __IO	uint16_t HASH2;
  __IO	uint16_t HASH3;
  __IO	uint16_t IPG;
  __IO	uint16_t PSC;
  __IO	uint16_t BAG;
  __IO	uint16_t JITTERWND;
  __IO	uint16_t R_CFG;
  __IO	uint16_t X_CFG;
//  __IO	uint32_t G_CFG;
	__IO	uint16_t G_CFGl;
	__IO	uint16_t G_CFGh;
  __IO	uint16_t IMR;
  __IO	uint16_t IFR;
  __IO	uint16_t MDIO_CTRL;
  __IO	uint16_t MDIO_DATA;
  __IO	uint16_t R_HEAD;
  __IO	uint16_t X_TAIL;
  __IO	uint16_t R_TAIL;
  __IO	uint16_t X_HEAD;
  __IO	uint16_t STAT;
  __IO	uint16_t RCOUNTER;
  __IO	uint16_t PHY_CONTROL;
  __IO	uint16_t PHY_STATUS;
  __IO	uint16_t PHY_CNTR_A;
}MDR_ETH_TypeDef;


#define MDR_ETH_BASE                 (SRAM_BASE + 0x1000000)

#define MDR_ETH0_BASE		  (MDR_ETH_BASE + 0x00000)
#define MDR_ETH1_BASE		  (MDR_ETH_BASE + 0x10000)

#define MDR_ETH0                     ((MDR_ETH_TypeDef *) MDR_ETH0_BASE)
#define MDR_ETH1                     ((MDR_ETH_TypeDef *) MDR_ETH1_BASE)


/** @defgroup MDR1986VE8T_Periph_ETHERNET_Defines Defines
  * @{
  */

/** @defgroup MDR1986VE8T_Periph_ETH_G_CFGl	ETH G CFGl
  * @{
  */ 

/*-- ETH_G_CFGl: ETH G_CFGl Register -----*/
/* Bit field positions: */
#define ETH_G_CFGl_ColWnd_Pos          		0
#define ETH_G_CFGl_PAUSE_EN_Pos       		8
#define ETH_G_CFGl_DTRM_EN_Pos         		9
#define ETH_G_CFGl_HD_EN_Pos          		10
#define ETH_G_CFGl_EXT_EN_Pos          		11
#define ETH_G_CFGl_BUFF_MODE_Pos       		12
#define ETH_G_CFGl_RCLR_EN_Pos         		14

/* Bit field masks: */
#define ETH_G_CFGl_ColWnd_Msk           	((uint32_t)0x000000FF)
#define ETH_G_CFGl_PAUSE_EN             	((uint32_t)0x00000100)
#define ETH_G_CFGl_DTRM_EN              	((uint32_t)0x00000200)
#define ETH_G_CFGl_HD_EN 	         	 	((uint32_t)0x00000400)
#define ETH_G_CFGl_EXT_EN               	((uint32_t)0x00000800)
#define ETH_G_CFGl_BUFF_MODE_Msk        	((uint32_t)0x00003000)
#define ETH_G_CFGl_EN_RCLR             	 	((uint32_t)0x00004000)

/** @} */ /* End of group ETH_G_CFGl */

/** @defgroup MDR1986VE8T_Periph_ETH_G_CFGh	ETH G CFGh
  * @{
  */ 

/*-- ETH_G_CFGh: ETH G_CFGh Register -----*/
/* Bit field positions: */
#define ETH_G_CFGh_XRST_Pos					0
#define ETH_G_CFGh_RRST_Pos            	 	1
#define ETH_G_CFGh_DLB_Pos					2
#define ETH_G_CFGh_DBG_RF_EN_Pos			12
#define ETH_G_CFGh_DBG_XF_EN_Pos			13
#define ETH_G_CFGh_DBG_MODE_Pos				14

/* Bit field masks: */
#define ETH_G_CFGh_XRST     				((uint32_t)0x00000001)
#define ETH_G_CFGh_RRST                	 	((uint32_t)0x00000002)
#define ETH_G_CFGh_DLB    					((uint32_t)0x00000004)
#define ETH_G_CFGh_DBG_RF_EN    			((uint32_t)0x00001000)
#define ETH_G_CFGh_DBG_XF_EN   		  		((uint32_t)0x00002000)
#define ETH_G_CFGh_DBG_MODE_Msk				((uint32_t)0x0000C000)

/** @} */ /* End of group ETH_G_CFGh */

/** @defgroup MDR1986VE8T_Periph_ETH_X_CFG	ETH X CFG
  * @{
  */ 

/*-- ETH_X_CFG: ETH X_CFG Register -----*/
/* Bit field positions: */
#define ETH_X_CFG_RtryCnt_Pos         		0
#define ETH_X_CFG_IPG_EN_Pos          		4
#define ETH_X_CFG_CRC_EN_Pos          		5
#define ETH_X_CFG_PRE_EN_Pos          		6
#define ETH_X_CFG_PAD_EN_Pos          		7
#define ETH_X_CFG_EVNT_MODE_Pos       		8
#define ETH_X_CFG_MSB1st_Pos          		12
#define ETH_X_CFG_BE_Pos              		13
#define ETH_X_CFG_EN_Pos             		15

/* Bit field masks: */
#define ETH_X_CFG_RtryCnt_Msk         		((uint32_t)0x0000000F)
#define ETH_X_CFG_IPG_EN               		((uint32_t)0x00000010)
#define ETH_X_CFG_CRC_EN               		((uint32_t)0x00000020)
#define ETH_X_CFG_PRE_EN               		((uint32_t)0x00000040)
#define ETH_X_CFG_PAD_EN               		((uint32_t)0x00000080)
#define ETH_X_CFG_EVNT_MODE_Msk       		((uint32_t)0x00000700)
#define ETH_X_CFG_MSB1st               		((uint32_t)0x00001000)
#define ETH_X_CFG_BE                   		((uint32_t)0x00002000)
#define ETH_X_CFG_EN                  		((uint32_t)0x00008000)

/** @} */ /* End of group ETH_X_CFG */

/** @defgroup MDR1986VE8T_Periph_ETH_R_CFG	ETH R CFG
  * @{
  */ 

/*-- ETH_R_CFG: ETH R_CFG Register -----*/
/* Bit field positions: */
#define ETH_R_CFG_MCA_EN_Pos          0
#define ETH_R_CFG_BCA_EN_Pos          1
#define ETH_R_CFG_UCA_EN_Pos          2
#define ETH_R_CFG_AC_EN_Pos           3
#define ETH_R_CFG_EF_EN_Pos           4
#define ETH_R_CFG_CF_EN_Pos           5
#define ETH_R_CFG_LF_EN_Pos           6
#define ETH_R_CFG_SF_EN_Pos           7
#define ETH_R_CFG_EVNT_MODE_Pos       8
#define ETH_R_CFG_MSB1st_Pos          12
#define ETH_R_CFG_BE_Pos              13
#define ETH_R_CFG_EN_Pos              15

/* Bit field masks: */
#define ETH_R_CFG_MCA_EN               ((uint32_t)0x00000001)
#define ETH_R_CFG_BCA_EN               ((uint32_t)0x00000002)
#define ETH_R_CFG_UCA_EN               ((uint32_t)0x00000004)
#define ETH_R_CFG_AC_EN                ((uint32_t)0x00000008)
#define ETH_R_CFG_EF_EN                ((uint32_t)0x00000010)
#define ETH_R_CFG_CF_EN                ((uint32_t)0x00000020)
#define ETH_R_CFG_LF_EN                ((uint32_t)0x00000040)
#define ETH_R_CFG_SF_EN                ((uint32_t)0x00000080)
#define ETH_R_CFG_EVNT_MODE_Msk        ((uint32_t)0x00000700)
#define ETH_R_CFG_MSB1st               ((uint32_t)0x00001000)
#define ETH_R_CFG_BE                   ((uint32_t)0x00002000)
#define ETH_R_CFG_EN                   ((uint32_t)0x00008000)

/** @} */ /* End of group ETH_R_CFG */

/** @defgroup MDR1986VE8T_Periph_ETH_IMR	ETH IMR
  * @{
  */ 

/*-- ETH_IMR: ETH IMR Register -----*/
/* Bit field positions: */
#define ETH_IMR_RF_OK_Pos             0
#define ETH_IMR_MISSED_F_Pos          1
#define ETH_IMR_OVF_Pos               2
#define ETH_IMR_SMB_ERR_Pos           3
#define ETH_IMR_CRC_ERR_Pos           4
#define ETH_IMR_CF_Pos                5
#define ETH_IMR_LF_Pos                6
#define ETH_IMR_SF_Pos                7
#define ETH_IMR_XF_OK_Pos             8
#define ETH_IMR_XF_ERR_Pos            9
#define ETH_IMR_UNDF_Pos              10
#define ETH_IMR_LC_Pos                11
#define ETH_IMR_CRS_LOST_Pos          12
#define ETH_IMR_MDIO_INT_Pos          14
#define ETH_IMR_MII_RDY_Pos           15

/* Bit field masks: */
#define ETH_IMR_RF_OK                  ((uint32_t)0x00000001)
#define ETH_IMR_MISSED_F               ((uint32_t)0x00000002)
#define ETH_IMR_OVF                    ((uint32_t)0x00000004)
#define ETH_IMR_SMB_ERR                ((uint32_t)0x00000008)
#define ETH_IMR_CRC_ERR                ((uint32_t)0x00000010)
#define ETH_IMR_CF                     ((uint32_t)0x00000020)
#define ETH_IMR_LF                     ((uint32_t)0x00000040)
#define ETH_IMR_SF                     ((uint32_t)0x00000080)
#define ETH_IMR_XF_OK                  ((uint32_t)0x00000100)
#define ETH_IMR_XF_ERR                 ((uint32_t)0x00000200)
#define ETH_IMR_UNDF                   ((uint32_t)0x00000400)
#define ETH_IMR_LC                     ((uint32_t)0x00000800)
#define ETH_IMR_CRS_LOST               ((uint32_t)0x00001000)
#define ETH_IMR_MDIO_INT			   ((uint32_t)0x00004000)
#define ETH_IMR_MII_RDY                ((uint32_t)0x00008000)

/** @} */ /* End of group ETH_IMR */

/** @defgroup MDR1986VE8T_Periph_ETH_IFR	ETH IFR
  * @{
  */ 

/*-- ETH_IFR: ETH IFR Register -----*/
/* Bit field positions: */
#define ETH_IFR_RF_OK_Pos             0
#define ETH_IFR_MISSED_F_Pos          1
#define ETH_IFR_OVF_Pos               2
#define ETH_IFR_SMB_ERR_Pos           3
#define ETH_IFR_CRC_ERR_Pos           4
#define ETH_IFR_CF_Pos                5
#define ETH_IFR_LF_Pos                6
#define ETH_IFR_SF_Pos                7
#define ETH_IFR_XF_OK_Pos             8
#define ETH_IFR_XF_ERR_Pos            9
#define ETH_IFR_UNDF_Pos              10
#define ETH_IFR_LC_Pos                11
#define ETH_IFR_CRS_LOST_Pos          12
#define ETH_IFR_MDIO_INT_Pos          14
#define ETH_IFR_MII_RDY_Pos           15

/* Bit field masks: */
#define ETH_IFR_RF_OK                  ((uint32_t)0x00000001)
#define ETH_IFR_MISSED_F               ((uint32_t)0x00000002)
#define ETH_IFR_OVF                    ((uint32_t)0x00000004)
#define ETH_IFR_SMB_ERR                ((uint32_t)0x00000008)
#define ETH_IFR_CRC_ERR                ((uint32_t)0x00000010)
#define ETH_IFR_CF                     ((uint32_t)0x00000020)
#define ETH_IFR_LF                     ((uint32_t)0x00000040)
#define ETH_IFR_SF                     ((uint32_t)0x00000080)
#define ETH_IFR_XF_OK                  ((uint32_t)0x00000100)
#define ETH_IFR_XF_ERR                 ((uint32_t)0x00000200)
#define ETH_IFR_UNDF                   ((uint32_t)0x00000400)
#define ETH_IFR_LC                     ((uint32_t)0x00000800)
#define ETH_IFR_CRS_LOST               ((uint32_t)0x00001000)
#define ETH_IFR_MDIO_INT			   ((uint32_t)0x00004000)
#define ETH_IFR_MII_RDY                ((uint32_t)0x00008000)

/** @} */ /* End of group ETH_IFR */

/** @defgroup MDR1986VE8T_Periph_ETH_STAT	ETH STAT
  * @{
  */ 

/*-- ETH_STAT: ETH STAT Register -----*/
/* Bit field positions: */
#define ETH_STAT_R_EMPTY_Pos			0
#define ETH_STAT_R_AEMPTY_Pos			1
#define ETH_STAT_R_HALF_Pos				2
#define ETH_STAT_R_AFULL_Pos			3
#define ETH_STAT_R_FULL_Pos				4
#define ETH_STAT_R_COUNT_Pos			5
#define ETH_STAT_X_EMPTY_Pos			8
#define ETH_STAT_X_AEMPTY_Pos			9
#define ETH_STAT_X_HALF_Pos				10
#define ETH_STAT_X_AFULL_Pos			11
#define ETH_STAT_X_FULL_Pos				12

/* Bit field masks: */
#define ETH_STAT_R_EMPTY				((uint32_t)0x00000001)
#define ETH_STAT_R_AEMPTY				((uint32_t)0x00000002)
#define ETH_STAT_R_HALF					((uint32_t)0x00000004)
#define ETH_STAT_R_AFULL				((uint32_t)0x00000008)
#define ETH_STAT_R_FULL					((uint32_t)0x00000010)
#define ETH_STAT_R_COUNT_Msk			((uint32_t)0x000000E0)
#define ETH_STAT_X_EMPTY				((uint32_t)0x00000100)
#define ETH_STAT_X_AEMPTY				((uint32_t)0x00000200)
#define ETH_STAT_X_HALF					((uint32_t)0x00000400)
#define ETH_STAT_X_AFULL				((uint32_t)0x00000800)
#define ETH_STAT_X_FULL					((uint32_t)0x00001000)

/** @} */ /* End of group ETH_STAT */

/** @defgroup MDR1986VE8T_Periph_ETH_MDIO_CTRL	ETH MDIO CTRL
  * @{
  */ 

/*-- ETH_MDIO_CTRL: ETH MDIO_CTRL Register -----*/
/* Bit field positions: */
#define ETH_MDIO_CTRL_RG_A_Pos			0
#define ETH_MDIO_CTRL_DIV_Pos			5
#define ETH_MDIO_CTRL_PHY_A_Pos			8
#define ETH_MDIO_CTRL_OP_Pos			13
#define ETH_MDIO_CTRL_PRE_EN_Pos		14
#define ETH_MDIO_CTRL_RDY_Pos			15

/* Bit field masks: */
#define ETH_MDIO_CTRL_RG_A_Msk			((uint32_t)0x0000001F)
#define ETH_MDIO_CTRL_DIV_Msk			((uint32_t)0x000000E0)
#define ETH_MDIO_CTRL_PHY_A_Msk			((uint32_t)0x00001F00)
#define ETH_MDIO_CTRL_OP				((uint32_t)0x00002000)
#define ETH_MDIO_CTRL_PRE_EN			((uint32_t)0x00004000)
#define ETH_MDIO_CTRL_RDY				((uint32_t)0x00008000)

/** @} */ /* End of group ETH_MDIO_CTRL */

/** @defgroup MDR1986VE8T_Periph_ETH_PHY_CONTROL	ETH PHY CONTROL
  * @{
  */ 

/*-- ETH_PHY_CONTROL: ETH PHY_CONTROL Register -----*/
/* Bit field positions: */
#define ETH_PHY_CONTROL_LB_pos						0
#define ETH_PHY_CONTROL_DLB_pos						1
#define ETH_PHY_CONTROL_HALFD_pos					2
#define ETH_PHY_CONTROL_EARLY_DV_pos			3
#define ETH_PHY_CONTROL_DIR_pos						4
#define ETH_PHY_CONTROL_BASE_2_pos				5
#define ETH_PHY_CONTROL_LINK_PERIOD_pos		6
#define ETH_PHY_CONTROL_EXT_EN_pos				14
#define ETH_PHY_CONTROL_RST_pos						15

/* Bit field masks: */
#define ETH_PHY_CONTROL_LB						((uint32_t)0x00000001)
#define ETH_PHY_CONTROL_DLB						((uint32_t)0x00000002)
#define ETH_PHY_CONTROL_HALFD					((uint32_t)0x00000004)
#define ETH_PHY_CONTROL_EARLY_DV			((uint32_t)0x00000008)
#define ETH_PHY_CONTROL_DIR						((uint32_t)0x00000010)
#define ETH_PHY_CONTROL_BASE_2				((uint32_t)0x00000020)
#define ETH_PHY_CONTROL_LINK_PERIOD		((uint32_t)0x00000FC0)
#define ETH_PHY_CONTROL_EXT_EN				((uint32_t)0x00004000)
#define ETH_PHY_CONTROL_RST						((uint32_t)0x00008000)

/** @} */ /* End of group ETH_PHY_CONTROL */

/** @defgroup MDR1986VE8T_Periph_ETH_PHY_STATUS	ETH PHY STATUS
  * @{
  */ 

/*-- ETH_PHY_STATUS: ETH PHY_STATUS Register -----*/
/* Bit field positions: */
#define ETH_PHY_STATUS_LED_LINK_pos			8
#define ETH_PHY_STATUS_LED_STAT_pos			9
#define ETH_PHY_STATUS_INT_LOSS_pos			10
#define ETH_PHY_STATUS_INT_POL_pos			11
#define ETH_PHY_STATUS_INT_JAB_pos			12
#define ETH_PHY_STATUS_INT_JAM_pos			13

/* Bit field masks: */
#define ETH_PHY_STATUS_LED_LINK			((uint32_t)0x00000100)
#define ETH_PHY_STATUS_LED_STAT			((uint32_t)0x00000200)
#define ETH_PHY_STATUS_INT_LOSS			((uint32_t)0x00000400)
#define ETH_PHY_STATUS_INT_POL			((uint32_t)0x00000800)
#define ETH_PHY_STATUS_INT_JAB			((uint32_t)0x00001000)
#define ETH_PHY_STATUS_INT_JAM			((uint32_t)0x00002000)

/** @} */ /* End of group ETH_PHY_STATUS */

/*-- ETH_PHY_STATUS: ETH PHY_CONTROL_A Register -----*/
/* Bit field positions: */
#define ETH_PHY_CONTROL_A_SELR_pos			0
#define ETH_PHY_CONTROL_A_TRIM_pos			1
#define ETH_PHY_CONTROL_A_TRIMR_pos			4
#define ETH_PHY_CONTROL_A_EN_PHY_pos		15

/* Bit field masks: */
#define ETH_PHY_CONTROL_A_SELR					((uint32_t)0x00000001)
#define ETH_PHY_CONTROL_A_TRIM					((uint32_t)0x0000000E)
#define ETH_PHY_CONTROL_A_TRIMR					((uint32_t)0x00000FF0)
#define ETH_PHY_CONTROL_A_EN_PHY				((uint32_t)0x00008000)

/** @} */ /* End of group ETH_PHY_STATUS */

/** @} */ /* End of group MDR1986VE8T_Periph_ETHERNET Defines */

/******************************************************************************/
/*                         Peripheral memory map                              */
/******************************************************************************/
/* Peripheral and SRAM base address */
#define SRAM_BASE             ((     uint32_t)0x20000000)
#define PERIPH_BASE           ((     uint32_t)0x40000000)
#define PERIPH_BB_BASE        ((     uint32_t)0x42000000)

/* Peripheral memory map */
#define GPIO_BASE                 (PERIPH_BASE + 0x0e000)

#define GPIO0_BASE                (GPIO_BASE)
#define GPIO1_BASE                (GPIO_BASE       + 0x0800)
#define GPIO2_BASE                (GPIO_BASE       + 0x1000)

#define SMPID		  ((volatile uint32_t) *((uint32_t *)0xe00fe000))
#define SMPID_BASE	      ((uint32_t) 0xe00fe000)
/******************************************************************************/
/*                         Peripheral declaration                             */
/******************************************************************************/
#define GPIO0                     ((GPIO_TypeDef *) GPIO0_BASE)
#define GPIO1                     ((GPIO_TypeDef *) GPIO1_BASE)
#define GPIO2                     ((GPIO_TypeDef *) GPIO2_BASE)


#endif



