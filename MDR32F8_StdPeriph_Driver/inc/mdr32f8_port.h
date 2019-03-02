/**
  ******************************************************************************
  * @file    mdr32f8_port.h
  * @author  Milandr
  * @version V1.0.0
  * @date    20/07/2015
  * @brief   This file contains all the functions prototypes for the PORTs
  *          firmware library.
  ******************************************************************************
  * <br><br>
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, PHYTON SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT
  * OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2015 Milandr</center></h2>
  ******************************************************************************
  * FILE mdr32f8_port.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MDR32F8_PORT_H
#define __MDR32F8_PORT_H

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"
#include "MDR1986VE8T.h"
#include "mdr32f8_config.h"

/** @addtogroup __MDR32F8_StdPeriph_Driver MDR32F8 Standard Peripherial Driver
  * @{
  */

/** @addtogroup PORT
  * @{
  */

/** @defgroup PORT_Exported_Types PORT Exported Types
  * @{
  */

#define IS_PORT_ALL_PERIPH(PERIPH) (((PERIPH) == PORTA) || \
                                    ((PERIPH) == PORTB) || \
                                    ((PERIPH) == PORTC) || \
                                    ((PERIPH) == PORTD) || \
                                    ((PERIPH) == PORTE) || \
																		((PERIPH) == PORTF))
	
/**
  * @brief  Configuration OE enumeration
  */
	
typedef enum
{
  PORT_SOE_IN            = 0x0,
  PORT_SOE_OUT           = 0x1
}PORT_SOE_TypeDef;

typedef enum
{
  PORT_COE_IN            = 0x0,
  PORT_COE_OUT           = 0x1
}PORT_COE_TypeDef;

#define IS_PORT_SOE(SOE) (((SOE) == PORT_SOE_IN) || ((SOE) == PORT_SOE_OUT))
#define IS_PORT_COE(COE) (((COE) == PORT_COE_IN) || ((COE) == PORT_COE_OUT))

/**
  * @brief  Configuration Function enumeration
  */

typedef enum
{
  PORT_SFUNC_USER        = 0x0,
  PORT_SFUNC_1           = 0x1,
	PORT_SFUNC_2           = 0x2,
	PORT_SFUNC_3           = 0x3,
	PORT_SFUNC_4           = 0x4,
	PORT_SFUNC_5           = 0x5,
	PORT_SFUNC_6           = 0x6,
	PORT_SFUNC_7           = 0x7,
	PORT_SFUNC_8           = 0x8,
	PORT_SFUNC_9           = 0x9,
	PORT_SFUNC_10          = 0xA,
	PORT_SFUNC_11          = 0xB,
	PORT_SFUNC_12          = 0xC,
	PORT_SFUNC_13          = 0xD,
	PORT_SFUNC_14          = 0xE,
	PORT_SFUNC_15          = 0xF	
}PORT_SFUNC_TypeDef;

typedef enum
{
  PORT_CFUNC_USER        = 0x0,
  PORT_CFUNC_1           = 0x1,
	PORT_CFUNC_2           = 0x2,
	PORT_CFUNC_3           = 0x3,
	PORT_CFUNC_4           = 0x4,
	PORT_CFUNC_5           = 0x5,
	PORT_CFUNC_6           = 0x6,
	PORT_CFUNC_7           = 0x7,
	PORT_CFUNC_8           = 0x8,
	PORT_CFUNC_9           = 0x9,
	PORT_CFUNC_10          = 0xA,
	PORT_CFUNC_11          = 0xB,
	PORT_CFUNC_12          = 0xC,
	PORT_CFUNC_13          = 0xD,
	PORT_CFUNC_14          = 0xE,
	PORT_CFUNC_15          = 0xF	
}PORT_CFUNC_TypeDef;

#define IS_PORT_SFUNC(SFUNC) 	(((SFUNC) == PORT_SFUNC_USER)  || ((SFUNC) == PORT_SFUNC_1) || \
															((SFUNC) == PORT_SFUNC_2) 	|| ((SFUNC) == PORT_SFUNC_3)) 	|| \
															((SFUNC) == PORT_SFUNC_4) 	|| ((SFUNC) == PORT_SFUNC_5)) 	|| \
															((SFUNC) == PORT_SFUNC_6) 	|| ((SFUNC) == PORT_SFUNC_7)) 	|| \
															((SFUNC) == PORT_SFUNC_8) 	|| ((SFUNC) == PORT_SFUNC_9)) 	|| \
															((SFUNC) == PORT_SFUNC_10) 	|| ((SFUNC) == PORT_SFUNC_11)) 	|| \
															((SFUNC) == PORT_SFUNC_12) 	|| ((SFUNC) == PORT_SFUNC_13)) 	|| \
															((SFUNC) == PORT_SFUNC_14) 	|| ((SFUNC) == PORT_SFUNC_15)))
#define IS_PORT_CFUNC(CFUNC) 	(((CFUNC) == PORT_CFUNC_USER)  || ((CFUNC) == PORT_CFUNC_1) || \
															((CFUNC) == PORT_CFUNC_2) 	|| ((CFUNC) == PORT_CFUNC_3)) 	|| \
															((CFUNC) == PORT_CFUNC_4) 	|| ((CFUNC) == PORT_CFUNC_5)) 	|| \
															((CFUNC) == PORT_CFUNC_6) 	|| ((CFUNC) == PORT_CFUNC_7)) 	|| \
															((CFUNC) == PORT_CFUNC_8) 	|| ((CFUNC) == PORT_CFUNC_9)) 	|| \
															((CFUNC) == PORT_CFUNC_10) 	|| ((CFUNC) == PORT_CFUNC_11)) 	|| \
															((CFUNC) == PORT_CFUNC_12) 	|| ((CFUNC) == PORT_CFUNC_13)) 	|| \
															((CFUNC) == PORT_CFUNC_14) 	|| ((CFUNC) == PORT_CFUNC_15)))

/**
  * @brief  Configuration Mode enumeration
  */
	
typedef enum
{
  PORT_SANALOG_ANALOG      = 0x0,
  PORT_SANALOG_DIGITAL     = 0x1
}PORT_SANALOG_TypeDef;

typedef enum
{
  PORT_CANALOG_ANALOG      = 0x0,
  PORT_CANALOG_DIGITAL     = 0x1
}PORT_CANALOG_TypeDef;

#define IS_PORT_SANALOG(SANALOG) (((SANALOG) == PORT_SANALOG_ANALOG) || ((SANALOG) == PORT_SANALOG_DIGITAL))
#define IS_PORT_CANALOG(CANALOG) (((CANALOG) == PORT_CANALOG_ANALOG) || ((CANALOG) == PORT_CANALOG_DIGITAL))

/**
  * @brief  Configuration PULLUP enumeration
  */

typedef enum
{
  PORT_SPULLUP_OFF      = 0x0,
  PORT_SPULLUP_ON       = 0x1
}PORT_SPULLUP_TypeDef;

typedef enum
{
  PORT_CPULLUP_OFF      = 0x0,
  PORT_CPULLUP_ON       = 0x1
}PORT_CPULLUP_TypeDef;

#define IS_PORT_SPULLUP(SPULLUP) (((SPULLUP) == PORT_SPULLUP_OFF) || ((SPULLUP) == PORT_SPULLUP_ON))
#define IS_PORT_CPULLUP(CPULLUP) (((CPULLUP) == PORT_CPULLUP_OFF) || ((CPULLUP) == PORT_CPULLUP_ON))

/**
  * @brief  Configuration PULLDOWN enumeration
  */

typedef enum
{
  PORT_SPULLDOWN_OFF    = 0x0,
  PORT_SPULLDOWN_ON     = 0x1
}PORT_SPULLDOWN_TypeDef;

typedef enum
{
  PORT_CPULLDOWN_OFF    = 0x0,
  PORT_CPULLDOWN_ON     = 0x1
}PORT_CPULLDOWN_TypeDef;

#define IS_PORT_SPULLDOWN(SPULLDOWN) (((SPULLDOWN) == PORT_SPULLDOWN_OFF) || ((SPULLDOWN) == PORT_SPULLDOWN_ON))
#define IS_PORT_CPULLDOWN(CPULLDOWN) (((CPULLDOWN) == PORT_CPULLDOWN_OFF) || ((CPULLDOWN) == PORT_CPULLDOWN_ON))

/**
  * @brief  Configuration PD enumeration
  */

typedef enum
{
  PORT_SPD_OFF       = 0x0,
  PORT_SPD_ON        = 0x1
}PORT_SPD_TypeDef;

typedef enum
{
  PORT_CPD_OFF       = 0x0,
  PORT_CPD_ON        = 0x1
}PORT_CPD_TypeDef;

#define IS_PORT_SPD(SPD) (((SPD) == PORT_SPD_OFF) || ((SPD) == PORT_SPD_ON))
#define IS_PORT_CPD(CPD) (((CPD) == PORT_CPD_OFF) || ((CPD) == PORT_CPD_ON))

/**
  * @brief  Configuration Speed enumeration
  */

typedef enum
{
  PORT_SPWR_DROFF       	= 0x0,
  PORT_SPWR_300        		= 0x1,
	PORT_SPWR_100        		= 0x2,
	PORT_SPWR_10        		= 0x3
}PORT_SPWR_TypeDef;

typedef enum
{
  PORT_CPWR_DROFF       	= 0x0,
  PORT_CPWR_300        		= 0x1,
	PORT_CPWR_100        		= 0x2,
	PORT_CPWR_10        		= 0x3
}PORT_CPWR_TypeDef;

#define IS_PORT_SPWR(SPWR) (((SPWR) == PORT_SPWR_DROFF) || ((SPWR) == PORT_SPWR_300) || \
                              ((SPWR) == PORT_SPWR_100) || ((SPWR) == PORT_SPWR_10))
#define IS_PORT_CPWR(CPWR) (((CPWR) == PORT_CPWR_DROFF) || ((CPWR) == PORT_CPWR_300) || \
                              ((CPWR) == PORT_CPWR_100) || ((CPWR) == PORT_CPWR_10))

/**
  * @brief  Configuration CL enumeration
  */

typedef enum
{
  PORT_SCL_OFF       = 0x0,
  PORT_SCL_ON        = 0x1
}PORT_SCL_TypeDef;

typedef enum
{
  PORT_CCL_OFF       = 0x0,
  PORT_CCL_ON        = 0x1
}PORT_CCL_TypeDef;

#define IS_PORT_SCL(SCL) (((SCL) == PORT_SCL_OFF) || ((SCL) == PORT_SCL_ON))
#define IS_PORT_CCL(CCL) (((CCL) == PORT_CCL_OFF) || ((CCL) == PORT_CCL_ON))

/**
  * @brief  Configuration IE enumeration
  */

typedef enum
{
  PORT_SIE_OFF       = 0x0,
  PORT_SIE_ON        = 0x1
}PORT_SIE_TypeDef;

typedef enum
{
  PORT_CIE_OFF       = 0x0,
  PORT_CIE_ON        = 0x1
}PORT_CIE_TypeDef;

#define IS_PORT_SIE(SIE) (((SIE) == PORT_SIE_OFF) || ((SIE) == PORT_SIE_ON))
#define IS_PORT_CIE(CIE) (((CIE) == PORT_CIE_OFF) || ((CIE) == PORT_CIE_ON))

/**
  * @brief  Configuration IT enumeration
  */

typedef enum
{
  PORT_SIT_LOW       		= 0x0,
  PORT_SIT_HIGH        	= 0x1
}PORT_SIT_TypeDef;

typedef enum
{
  PORT_CIT_LOW       		= 0x0,
  PORT_CIT_HIGH        	= 0x1
}PORT_CIT_TypeDef;

#define IS_PORT_SIT(SIT) (((SIT) == PORT_SIT_LOW) || ((SIE) == PORT_SIT_HIGH))
#define IS_PORT_CIT(CIT) (((CIT) == PORT_CIT_LOW) || ((CIT) == PORT_CIT_HIGH))

/**
  * @brief  Configuration IR enumeration
  */

typedef enum
{
  PORT_SIR_OFF         = 0x0,
  PORT_SIR_ON          = 0x1
}PORT_SIR_TypeDef;

typedef enum
{
  PORT_CIR_OFF         = 0x0,
  PORT_CIR_ON          = 0x1
}PORT_CIR_TypeDef;

#define IS_PORT_SIR(SIR) (((SIR) == PORT_SIR_OFF) || ((SIR) == PORT_SIR_ON))
#define IS_PORT_CIR(CIR) (((CIR) == PORT_CIR_OFF) || ((CIR) == PORT_CIR_ON))

typedef struct
{
  uint32_t PORT_Pin;    										/*!< Specifies PORT pins to be configured.
                                              This parameter is a mask of @ref PORT_pins_define values. */
  PORT_SOE_TypeDef PORT_SOE; 								/*!< Specifies in/out mode for the selected pins.
                                              This parameter is a mask of @ref PORT_SOE_TypeDef values. */
 	PORT_SFUNC_TypeDef PORT_SFUNC;						/*!< Specifies operating function for the selected pins.
                                              This parameter is a mask of @ref PORT_pins_define values. */
	PORT_SANALOG_TypeDef PORT_SANALOG;				/*!< Specifies the operating mode for the selected pins.
                                              This parameter is a mask of @ref PORT_SANALOG_TypeDef values. */
  PORT_SPULLUP_TypeDef PORT_SPULLUP;				/*!< Specifies pull up state for the selected pins.
                                              This parameter is a mask of @ref PORT_SPULLUP_TypeDef values. */     
  PORT_SPULLDOWN_TypeDef PORT_SPULLDOWN;		/*!< Specifies pull down state for the selected pins.
                                              This parameter is a mask of @ref PORT_SPULLDOWN_TypeDef values. */       
  PORT_SPD_TypeDef PORT_SPD; 								/*!< Specifies PD state for the selected pins.
                                              This parameter is a mask of @ref PORT_SPD_TypeDef values. */          
  PORT_SPWR_TypeDef PORT_SPWR;         			/*!< Specifies the speed for the selected pins.
                                              This parameter is a mask of @ref PORT_SPWR_TypeDef values. */
  PORT_SCL_TypeDef PORT_SCL;     						/*!< Specifies CL state for the selected pins.
                                              This parameter is a mask of @ref PORT_SCL_TypeDef values. */    
	PORT_SIE_TypeDef PORT_SIE;        				/*!< Specifies IE state for the selected pins.
                                              This parameter is a mask of @ref PORT_SIE_TypeDef values. */ 
	PORT_SIT_TypeDef PORT_SIT;    						/*!< Specifies IT state for the selected pins.
                                              This parameter is a mask of @ref PORT_SIT_TypeDef values. */     
	PORT_SIR_TypeDef PORT_SIR;         				/*!< Specifies IR state for the selected pins.
                                              This parameter is a mask of @ref PORT_SIR_TypeDef values. */

	PORT_COE_TypeDef PORT_COE; 								/*!< Specifies PORT pins to be configured.
                                              This parameter is a mask of @ref PORT_pins_define values. */
	PORT_CFUNC_TypeDef PORT_CFUNC;						/*!< Specifies in/out mode for the selected pins.
                                              This parameter is a mask of @ref PORT_COE_TypeDef values. */
	PORT_CANALOG_TypeDef PORT_CANALOG;				/*!< Specifies the operating mode for the selected pins.
                                              This parameter is a mask of @ref PORT_CANALOG_TypeDef values. */
	PORT_CPULLUP_TypeDef PORT_CPULLUP; 				/*!< Specifies pull up state for the selected pins.
                                              This parameter is a mask of @ref PORT_CPULLUP_TypeDef values. */
	PORT_CPULLDOWN_TypeDef PORT_CPULLDOWN;		/*!< Specifies pull down state for the selected pins.
                                              This parameter is a mask of @ref PORT_CPULLDOWN_TypeDef values. */ 		
	PORT_CPD_TypeDef PORT_CPD;  							/*!< Specifies PD state for the selected pins.
                                              This parameter is a mask of @ref PORT_CPD_TypeDef values. */ 
	PORT_CPWR_TypeDef PORT_CPWR;							/*!< Specifies the speed for the selected pins.
                                              This parameter is a mask of @ref PORT_CPWR_TypeDef values. */
	PORT_CCL_TypeDef PORT_CCL; 								/*!< Specifies CL state for the selected pins.
                                              This parameter is a mask of @ref PORT_CCL_TypeDef values. */ 
	PORT_CIE_TypeDef PORT_CIE;								/*!< Specifies IE state for the selected pins.
                                              This parameter is a mask of @ref PORT_CIE_TypeDef values. */
	PORT_CIT_TypeDef PORT_CIT; 								/*!< Specifies IT state for the selected pins.
                                              This parameter is a mask of @ref PORT_CIT_TypeDef values. */
	PORT_CIR_TypeDef PORT_CIR; 								/*!< Specifies IR state for the selected pins.
                                              This parameter is a mask of @ref PORT_CIR_TypeDef values. */	
}PORT_InitTypeDef;

/**
  * @brief  Bit_SET and Bit_RESET enumeration
  */

typedef enum
{
  Bit_RESET = 0,
  Bit_SET
}BitAction;

#define IS_PORT_BIT_ACTION(ACTION) (((ACTION) == Bit_RESET) || ((ACTION) == Bit_SET))

/** @} */ /* End of group PORT_Exported_Types */

/** @defgroup PORT_Exported_Constants PORT Exported Constants
  * @{
  */

/** @defgroup PORT_pins_define PORT pins define
  * @{
  */

#define PORT_Pin_0                  0x0001U  /*!< Pin 0 selected */
#define PORT_Pin_1                  0x0002U  /*!< Pin 1 selected */
#define PORT_Pin_2                  0x0004U  /*!< Pin 2 selected */
#define PORT_Pin_3                  0x0008U  /*!< Pin 3 selected */
#define PORT_Pin_4                  0x0010U  /*!< Pin 4 selected */
#define PORT_Pin_5                  0x0020U  /*!< Pin 5 selected */
#define PORT_Pin_6                  0x0040U  /*!< Pin 6 selected */
#define PORT_Pin_7                  0x0080U  /*!< Pin 7 selected */
#define PORT_Pin_8                  0x0100U  /*!< Pin 8 selected */
#define PORT_Pin_9                  0x0200U  /*!< Pin 9 selected */
#define PORT_Pin_10                 0x0400U  /*!< Pin 10 selected */
#define PORT_Pin_11                 0x0800U  /*!< Pin 11 selected */
#define PORT_Pin_12                 0x1000U  /*!< Pin 12 selected */
#define PORT_Pin_13                 0x2000U  /*!< Pin 13 selected */
#define PORT_Pin_14                 0x4000U  /*!< Pin 14 selected */
#define PORT_Pin_15                 0x8000U  /*!< Pin 15 selected */

#define PORT_Pin_16                 0x0001U<<16  /*!< Pin 16 selected */
#define PORT_Pin_17                 0x0002U<<16  /*!< Pin 17 selected */
#define PORT_Pin_18                 0x0004U<<16  /*!< Pin 18 selected */
#define PORT_Pin_19                 0x0008U<<16  /*!< Pin 19 selected */
#define PORT_Pin_20                 0x0010U<<16  /*!< Pin 20 selected */
#define PORT_Pin_21                 0x0020U<<16  /*!< Pin 21 selected */
#define PORT_Pin_22                 0x0040U<<16  /*!< Pin 22 selected */
#define PORT_Pin_23                 0x0080U<<16  /*!< Pin 23 selected */
#define PORT_Pin_24                 0x0100U<<16  /*!< Pin 24 selected */
#define PORT_Pin_25                 0x0200U<<16  /*!< Pin 25 selected */
#define PORT_Pin_26                 0x0400U<<16  /*!< Pin 26 selected */
#define PORT_Pin_27                 0x0800U<<16  /*!< Pin 27 selected */
#define PORT_Pin_28                 0x1000U<<16  /*!< Pin 28 selected */
#define PORT_Pin_29                 0x2000U<<16  /*!< Pin 29 selected */
#define PORT_Pin_30                 0x4000U<<16  /*!< Pin 30 selected */
#define PORT_Pin_31                 0x8000U<<16  /*!< Pin 31 selected */

#define PORT_Pin_All                0xFFFFFFFFU  /*!< All pins selected */

#define IS_PORT_PIN(PIN)            ((((PIN) & (uint32_t)0xFFFFFFFFUL) != 0x00) && \
                                     ((PIN) != 0x00))

#define IS_GET_PORT_PIN(PIN)        (((PIN) == PORT_Pin_0 ) || ((PIN) == PORT_Pin_16 ) || \
                                     ((PIN) == PORT_Pin_1 ) || ((PIN) == PORT_Pin_17 ) || \
                                     ((PIN) == PORT_Pin_2 ) || ((PIN) == PORT_Pin_18 ) || \
                                     ((PIN) == PORT_Pin_3 ) || ((PIN) == PORT_Pin_19 ) || \
                                     ((PIN) == PORT_Pin_4 ) || ((PIN) == PORT_Pin_20 ) || \
                                     ((PIN) == PORT_Pin_5 ) || ((PIN) == PORT_Pin_21 ) || \
                                     ((PIN) == PORT_Pin_6 ) || ((PIN) == PORT_Pin_22 ) || \
                                     ((PIN) == PORT_Pin_7 ) || ((PIN) == PORT_Pin_23 ) || \
                                     ((PIN) == PORT_Pin_8 ) || ((PIN) == PORT_Pin_24 ) || \
                                     ((PIN) == PORT_Pin_9 ) || ((PIN) == PORT_Pin_25 ) || \
                                     ((PIN) == PORT_Pin_10) || ((PIN) == PORT_Pin_26 ) || \
                                     ((PIN) == PORT_Pin_11) || ((PIN) == PORT_Pin_27 ) || \
                                     ((PIN) == PORT_Pin_12) || ((PIN) == PORT_Pin_28 ) || \
                                     ((PIN) == PORT_Pin_13) || ((PIN) == PORT_Pin_29 ) || \
                                     ((PIN) == PORT_Pin_14) || ((PIN) == PORT_Pin_30 ) || \
                                     ((PIN) == PORT_Pin_15) || ((PIN) == PORT_Pin_31 ))
																		 
/** @} */ /* End of group PORT_pins_define */

/** @} */ /* End of group PORT_Exported_Constants */

/** @defgroup PORT_Exported_Macros PORT Exported Macros
  * @{
  */

/** @} */ /* End of group PORT_Exported_Macros */

/** @defgroup PORT_Exported_Functions PORT Exported Functions
  * @{
  */

void PORT_DeInit(PortControl* PORTx);
void PORT_Init(PortControl* PORTx, const PORT_InitTypeDef* PORT_InitStruct);
void PORT_SetBits ( PortControl* PORTx, uint32_t PORT_Pin );
void PORT_ResetBits ( PortControl* PORTx, uint32_t PORT_Pin );
void PORT_StructInit(PORT_InitTypeDef* PORT_InitStruct);
void PORT_ClearStructInit(PORT_InitTypeDef* PORT_InitStruct);

uint8_t PORT_ReadInputDataBit(PortControl* PORTx, uint32_t PORT_Pin);


/** @} */ /* End of group PORT_Exported_Functions */

/** @} */ /* End of group PORT */

/** @} */ /* End of group __MDR32F8_StdPeriph_Driver */

#endif /* __MDR32F8_PORT_H */

/******************* (C) COPYRIGHT 2015 Milandr *********************************
*
* END OF FILE mdr32f8_port.h */
