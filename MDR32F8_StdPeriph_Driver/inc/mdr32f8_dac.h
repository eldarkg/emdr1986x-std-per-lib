/**
  ******************************************************************************
  * @file    MDR32F9Qx_dac.h
  * @author  Phyton Application Team
  * @version V1.4.0
  * @date    21/07/2011
  * @brief   This file contains all the functions prototypes for the DAC
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
  * <h2><center>&copy; COPYRIGHT 2011 Phyton</center></h2>
  ******************************************************************************
  * FILE MDR32F9Qx_dac.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MDR32F9QX_DAC_H
#define __MDR32F9QX_DAC_H

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

/** @addtogroup DAC
  * @{
  */

/** @defgroup DAC_Exported_Types DAC Exported Types
  * @{
  */

/** @} */ /* End of group DAC_Exported_Types */

/** @defgroup DAC_Exported_Constants DAC Exported Constants
  * @{
  */

/** @defgroup DAC_Synchronous_Mode DAC Synchronous Mode
  * @{
  */

#define DAC_SYNC_MODE_Independent             (((uint32_t)0x0) << DAC_CFG_SYNC_A_Pos)       /*!< The independent DAC1, DAC2 operation mode. */
#define DAC_SYNC_MODE_Synchronous             (((uint32_t)0x1) << DAC_CFG_SYNC_A_Pos)       /*!< The synchronous DAC1, DAC2 operation mode. */

#define IS_DAC_SYNC_MODE(MODE) (((MODE) == DAC_SYNC_MODE_Independent) || \
                                ((MODE) == DAC_SYNC_MODE_Synchronous))

/** @} */ /* End of group DAC_Synchronous_Mode */

/** @defgroup DAC1_Ref_Source DAC1 Reference Voltage source
  * @{
  */

#define DAC1_AVCC                             (((uint32_t)0x0) << DAC_CFG_M_REF0_Pos)       /*!< Selects AVcc as Reference Voltage. */
#define DAC1_REF                              (((uint32_t)0x1) << DAC_CFG_M_REF0_Pos)       /*!< Selects DAC1_REF input as Reference Voltage. */

#define IS_DAC1_REF_CONFIG(CONFIG) (((CONFIG) == DAC1_AVCC) || \
                                    ((CONFIG) == DAC1_REF ))

/** @} */ /* End of group DAC1_Ref_Source */

/** @defgroup DAC2_Ref_Source DAC2 Reference Voltage source
  * @{
  */

#define DAC2_AVCC                             (((uint32_t)0x0) << DAC_CFG_M_REF1_Pos)       /*!< Selects AVcc as Reference Voltage. */
#define DAC2_REF                              (((uint32_t)0x1) << DAC_CFG_M_REF1_Pos)       /*!< Selects DAC2_REF input as Reference Voltage. */

#define IS_DAC2_REF_CONFIG(CONFIG) (((CONFIG) == DAC2_AVCC) || \
                                    ((CONFIG) == DAC2_REF ))

/** @} */ /* End of group DAC2_Ref_Source */

/** @defgroup DAC_Data DAC Data
  * @{
  */

#define DAC_LO_DATA_MSK                       ((uint32_t)0x0FFF)
#define DAC_HI_DATA_MSK                       (DAC_LO_DATA_MSK << 16)

#define IS_DAC_DATA(DATA) (((DATA) & ~(DAC_LO_DATA_MSK | DAC_HI_DATA_MSK)) == 0 )

/** @} */ /* End of group DAC_Data */

#define DAC_DIV_Msk        								 ((uint32_t)0x0000FFFF)
#define DAC_CLK_EN         								 (1<<16)
#define DAC_CLKSRC_msk                     ((uint32_t)0xF0000000) 
#define DAC_CLKSRC_offs                    28

#define DAC_CLKSRC_HSI                     ((uint32_t)0x00000000)
#define DAC_CLKSRC_HSE0                    ((uint32_t)0x00000001)
#define DAC_CLKSRC_HSE1                    ((uint32_t)0x00000002)
#define DAC_CLKSRC_LSI                     ((uint32_t)0x00000003)
#define DAC_CLKSRC_LSE                     ((uint32_t)0x00000004)
#define DAC_CLKSRC_PLL0                    ((uint32_t)0x00000005)
#define DAC_CLKSRC_PLL1                    ((uint32_t)0x00000006)
#define DAC_CLKSRC_PLL2                    ((uint32_t)0x00000007)
#define DAC_CLKSRC_MAX_CLK                 ((uint32_t)0x0000000C)

#define IS_DAC_CLKSRC(CLKSRC)  					(((CLKSRC) == DAC_CLKSRC_HSI)  || \
																					 ((CLKSRC) == DAC_CLKSRC_HSE0) || \
																					 ((CLKSRC) == DAC_CLKSRC_HSE1) || \
																					 ((CLKSRC) == DAC_CLKSRC_LSI)  || \
																					 ((CLKSRC) == DAC_CLKSRC_LSE)  || \
																					 ((CLKSRC) == DAC_CLKSRC_PLL0) || \
																					 ((CLKSRC) == DAC_CLKSRC_PLL1) || \
																					 ((CLKSRC) == DAC_CLKSRC_PLL2) || \
																					 ((CLKSRC) == DAC_CLKSRC_MAX_CLK))																				 

#define DAC_CLKdiv1                        ((uint32_t)0x00000000)
#define DAC_CLKdiv2                        ((uint32_t)0x00000001)
#define DAC_CLKdiv4                        ((uint32_t)0x00000002)
#define DAC_CLKdiv8                        ((uint32_t)0x00000003)

/** @} */ /* End of group DAC_Exported_Constants */

/** @defgroup DAC_Exported_Macros DAC Exported Macros
  * @{
  */

/** @} */ /* End of group DAC_Exported_Macros */

/** @defgroup DAC_Exported_Functions DAC Exported Functions
  * @{
  */

void DAC_DeInit(DACxControl* DACx);

void DAC_Init(DACxControl* DACx, uint32_t SyncMode, uint32_t DACx_Ref);

void DAC_Cmd(DACxControl* DACx, FunctionalState NewState);

void DAC_SetData(DACxControl* DACx, uint32_t Data);

uint32_t DAC_GetData(DACxControl* DACx);

void DAC_CLK_en(DACxControl* DACx, uint32_t DAC_CLKSRC, uint32_t DAC_CLK_DIV);

/** @} */ /* End of group DAC_Exported_Functions */

/** @} */ /* End of group DAC */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

#ifdef __cplusplus
} // extern "C" block end
#endif

#endif /* __MDR32F9QX_DAC_H */

/******************* (C) COPYRIGHT 2011 Phyton *********************************
*
* END OF FILE MDR32F9Qx_dac.h */

