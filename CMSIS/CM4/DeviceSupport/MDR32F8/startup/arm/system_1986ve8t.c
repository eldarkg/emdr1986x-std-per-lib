/**
  ******************************************************************************
  * @file    system_1986dt8t.c
  * @author  Milandr Application Team
  * @version V1.3.0
  * @date    11/04/2018
  * @brief   CMSIS Cortex-M4F Device Peripheral Access Layer System Source File.
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
  * <h2><center>&copy; COPYRIGHT 2018 Milandr</center></h2>
  ******************************************************************************
  * FILE system_1986dt8t.c
  */


/** @addtogroup __CMSIS CMSIS
  * @{
  */

/** @defgroup MDR1986VE8
 *  @{
 */

/** @addtogroup __MDR1986VE8 MDR1986VE8 System
  * @{
  */

/** @addtogroup System_Private_Includes System Private Includes
  * @{
  */

#include "MDR1986VE8T.h"
#include "mdr32f8_config.h"

/** @} */ /* End of group System_Private_Includes */

/** @addtogroup __MDR1986VE8_System_Private_Variables __MDR1986VE8 System Private Variables
  * @{
  */

/*******************************************************************************
*  Clock Definitions
*******************************************************************************/
  uint32_t SystemCoreClock = (uint32_t)8000000;         /*!< System Clock Frequency (Core Clock)
                                                         *   default value */

/** @} */ /* End of group __MDR1986VE8_System_Private_Variables */

/** @addtogroup __MDR1986VE8_System_Private_Functions __MDR1986VE8 System Private Functions
  * @{
  */

/**
  * @brief  Update SystemCoreClock according to Clock Register Values
  * @note   None
  * @param  None
  * @retval None
  */
void SystemCoreClockUpdate (void)
{
 
}

/**
  * @brief  Setup the microcontroller system
  *         RST clock configuration to the default reset state
  *         Setup SystemCoreClock variable.
  * @note   This function should be used only after reset.
  * @param  None
  * @retval None
  */
void SystemInit (void)
{
	
}

/** @} */ /* End of group __MDR1986VE8_System_Private_Functions */

/** @} */ /* End of group __MDR1986VE8 */

/** @} */ /* End of group MDR1986VE8 */

/** @} */ /* End of group __CMSIS */

/******************* (C) COPYRIGHT 2018 Milandr *********************************
*
* END OF FILE system_1986dt8t.c */
