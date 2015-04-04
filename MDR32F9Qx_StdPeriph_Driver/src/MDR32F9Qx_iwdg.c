/**
  ******************************************************************************
  * @file    MDR32F9Qx_iwdg.c
  * @author  Phyton Application Team
  * @version V1.3.0
  * @date    27/01/2011
  * @brief   This file contains all the IWDG firmware functions.
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
  * FILE MDR32F9Qx_iwdg.c
  */
/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_config.h"
#include "MDR32F9Qx_iwdg.h"

#define ASSERT_INFO_FILE_ID FILEID__MDR32F9X_IWDG_C

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @defgroup IWDG IWDG
  * @{
  */

/** @defgroup IWDG_Private_TypesDefinitions IWDG Private Types Definitions
  * @{
  */

/** @} */ /* End of group IWDG_Private_TypesDefinitions */

/** @defgroup IWDG_Private_Defines IWDG Private Defines
  * @{
  */

/* ---------------------- IWDG registers bit mask ----------------------------*/

/* KR register bit mask */
#define KR_KEY_Reload       ((uint32_t)0xAAAA)
#define KR_KEY_Enable       ((uint32_t)0xCCCC)
#define KR_KEY_WriteEnable  ((uint32_t)0x5555)
#define KR_KEY_WriteDisable ((uint32_t)0x0000)

/** @} */ /* End of group IWDG_Private_Defines */

/** @defgroup IWDG_Private_Macros  IWDG Private Macros
  * @{
  */

/** @} */ /* End of group IWDG_Private_Macros */

/** @defgroup IWDG_Private_Variables  IWDG Private Variables
  * @{
  */

/** @} */ /* End of group IWDG_Private_Variables */

/** @defgroup IWDG_Private_FunctionPrototypes  IWDG Private Functions Prototypes
  * @{
  */

/** @} */ /* End of group IWDG_Private_FunctionPrototypes */

/** @defgroup IWDG_Private_Functions  IWDG Private Functions
  * @{
  */

/**
  * @brief  IWDG_WriteAccessEnable - Enables write access to IWDG_PR and IWDG_RLR registers.
  * @param  None
  * @retval None
  */
void IWDG_WriteAccessEnable(void)
{
  MDR_IWDG->KR = KR_KEY_WriteEnable;
}

/**
  * @brief  IWDG_WriteAccessDisable - Disables write access to IWDG_PR and IWDG_RLR registers.
  * @param  None
  * @retval None
  */
void IWDG_WriteAccessDisable(void)
{
  MDR_IWDG->KR = KR_KEY_WriteDisable;
}

/**
  * @brief  IWDG_SetPrescaler - Sets IWDG Prescaler value.
  * @param  IWDG_Prescaler: specifies the IWDG Prescaler value.
  *   This parameter can be one of the following values:
  *     @arg IWDG_Prescaler_4: IWDG prescaler set to 4
  *     @arg IWDG_Prescaler_8: IWDG prescaler set to 8
  *     @arg IWDG_Prescaler_16: IWDG prescaler set to 16
  *     @arg IWDG_Prescaler_32: IWDG prescaler set to 32
  *     @arg IWDG_Prescaler_64: IWDG prescaler set to 64
  *     @arg IWDG_Prescaler_128: IWDG prescaler set to 128
  *     @arg IWDG_Prescaler_256: IWDG prescaler set to 256
  * @retval None
  */
void IWDG_SetPrescaler(uint32_t IWDG_Prescaler)
{
  /* Check the parameters */
  assert_param(IS_IWDG_PRESCALER(IWDG_Prescaler));

  MDR_IWDG->PR = IWDG_Prescaler;
}

/**
  * @brief  IWDG_SetReload - Sets IWDG Reload value.
  * @param  Reload: specifies the IWDG Reload value.
  *   This parameter must be a number between 0 and 0x0FFF.
  * @retval None
  */
void IWDG_SetReload(uint32_t Reload)
{
  /* Check the parameters */
  assert_param(IS_IWDG_RELOAD(Reload));

  MDR_IWDG->RLR = Reload;
}

/**
  * @brief  IWDG_ReloadCounter - Reloads IWDG counter with value defined in the reload register
  *   (write access to IWDG_PR and IWDG_RLR registers disabled).
  * @param  None
  * @retval None
  */
void IWDG_ReloadCounter(void)
{
  MDR_IWDG->KR = KR_KEY_Reload;
}

/**
  * @brief  IWDG_Enable - Enables IWDG (write access to IWDG_PR and IWDG_RLR registers disabled).
  * @param  None
  * @retval None
  */
void IWDG_Enable(void)
{
  MDR_IWDG->KR = KR_KEY_Enable;
}

/**
  * @brief  IWDG_GetFlagStatus - Checks whether the specified IWDG flag is set or not.
  * @param  IWDG_FLAG: specifies the flag to check.
  *   This parameter can be one of the following values:
  *     @arg IWDG_FLAG_PVU: Prescaler Value Update on going
  *     @arg IWDG_FLAG_RVU: Reload Value Update on going
  * @retval The new state of IWDG_FLAG (SET or RESET).
  */
FlagStatus IWDG_GetFlagStatus(uint32_t IWDG_FLAG)
{
  FlagStatus bitstatus;
  /* Check the parameters */
  assert_param(IS_IWDG_FLAG(IWDG_FLAG));
  if ((MDR_IWDG->SR & IWDG_FLAG) != (uint32_t)RESET)
  {
    bitstatus = SET;
  }
  else
  {
    bitstatus = RESET;
  }
  /* Return the flag status */
  return bitstatus;
}

/** @} */ /* End of group IWDG_Private_Functions */

/** @} */ /* End of group IWDG */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

/******************* (C) COPYRIGHT 2010 Phyton *********************************
*
* END OF FILE MDR32F9Qx_iwdg.c */

