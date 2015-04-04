/**
  ******************************************************************************
  * @file    MDR32F9Qx_iwdg.h
  * @author  Phyton Application Team
  * @version V1.3.0
  * @date    27/01/2011
  * @brief   This file contains all the functions prototypes for the IWDG
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
  * <h2><center>&copy; COPYRIGHT 2010 Phyton</center></h2>
  ******************************************************************************
  * FILE MDR32F9Qx_iwdg.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MDR32F9Qx_IWDG_H
#define __MDR32F9Qx_IWDG_H

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_lib.h"

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @addtogroup IWDG
  * @{
  */

/** @defgroup IWDG_Exported_Types IWDG Exported Types
  * @{
  */

/** @} */ /* End of group IWDG_Exported_Types */

/** @defgroup IWDG_Exported_Constants IWDG Exported Constants
  * @{
  */

/** @defgroup IWDG_prescaler  IWDG prescaler
  * @{
  */

#define IWDG_Prescaler_4            ((uint32_t)0x00)
#define IWDG_Prescaler_8            ((uint32_t)0x01)
#define IWDG_Prescaler_16           ((uint32_t)0x02)
#define IWDG_Prescaler_32           ((uint32_t)0x03)
#define IWDG_Prescaler_64           ((uint32_t)0x04)
#define IWDG_Prescaler_128          ((uint32_t)0x05)
#define IWDG_Prescaler_256          ((uint32_t)0x06)
#define IS_IWDG_PRESCALER(PRESCALER) (((PRESCALER) == IWDG_Prescaler_4)  || \
                                      ((PRESCALER) == IWDG_Prescaler_8)  || \
                                      ((PRESCALER) == IWDG_Prescaler_16) || \
                                      ((PRESCALER) == IWDG_Prescaler_32) || \
                                      ((PRESCALER) == IWDG_Prescaler_64) || \
                                      ((PRESCALER) == IWDG_Prescaler_128)|| \
                                      ((PRESCALER) == IWDG_Prescaler_256))

/** @} */ /* End of group IWDG_prescaler */

/** @defgroup IWDG_Flag  IWDG Flags
  * @{
  */

#define IWDG_FLAG_PVU               IWDG_SR_PVU
#define IWDG_FLAG_RVU               IWDG_SR_RVU
#define IS_IWDG_FLAG(FLAG) (((FLAG) == IWDG_FLAG_PVU) || ((FLAG) == IWDG_FLAG_RVU))

/** @} */ /* End of group IWDG_Flag */

/** @defgroup IWDG_Reload  IWDG Reload
  * @{
  */

#define IS_IWDG_RELOAD(RELOAD) ((RELOAD) <= 0xFFF)

/** @} */ /* End of group IWDG_Reload */

/** @} */ /* End of group IWDG_Exported_Constants */

/** @defgroup IWDG_Exported_Macros IWDG Exported Macros
  * @{
  */

/** @} */ /* End of group IWDG_Exported_Macros */

/** @defgroup IWDG_Exported_Functions IWDG Exported Functions
  * @{
  */

void IWDG_WriteAccessEnable(void);
void IWDG_WriteAccessDisable(void);
void IWDG_SetPrescaler(uint32_t IWDG_Prescaler);
void IWDG_SetReload(uint32_t Reload);
void IWDG_ReloadCounter(void);
void IWDG_Enable(void);
FlagStatus IWDG_GetFlagStatus(uint32_t IWDG_FLAG);

/** @} */ /* End of group IWDG_Exported_Functions */

/** @} */ /* End of group IWDG */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

#endif /* __MDR32F9Qx_IWDG_H */

/******************* (C) COPYRIGHT 2010 Phyton *********************************
*
* END OF FILE MDR32F9Qx_iwdg.h */

