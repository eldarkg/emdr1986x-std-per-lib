/**
  ******************************************************************************
  * @file    system_1986ve8t.h
  * @author  Milandr Application Team
  * @version V1.3.0
  * @date    11/04/2018
  * @brief   CMSIS Cortex-M4F Device Peripheral Access Layer System Header File.
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
  * <h2><center>&copy; COPYRIGHT Milandr</center></h2>
  ******************************************************************************
  * FILE system_1986ve8t.h
  */

/** @addtogroup __CMSIS CMSIS
  * @{
  */

/** @defgroup MDR1986VE8
 *  @{
 */

/** @defgroup __MDR1986VE8 MDR1986VE8 System
  * @{
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SYSTEM_1986VE8_H
#define __SYSTEM_1986VE8_H

/** @addtogroup __MDR1986VE8_System_Exported_Variables MDR1986VE8 System Exported Variables
  * @{
  */

extern uint32_t SystemCoreClock;          /*!< System Clock Frequency (Core Clock)
                                           *   default value */

/** @} */ /* End of group __MDR1986VE8_System_Exported_Variables */

/** @addtogroup __MDR1986VE8_System_Exported_Functions MDR1986VE8 System Exported Functions
  * @{
  */

extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);

/** @} */ /* End of group __MDR1986VE8_System_Exported_Functions */

#endif /*__SYSTEM_1986VE8_H */

/** @} */ /* End of group __MDR1986VE8 */

/** @} */ /* End of group MDR1986VE8 */

/** @} */ /* End of group __CMSIS */

/******************* (C) COPYRIGHT Milandr *********************************
*
* END OF FILE system_1986ve8t.h
