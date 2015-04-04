/**
  ******************************************************************************
  * @file    system_MDR1986VE3.h
  * @author  Phyton Application Team
  * @version V1.3.0
  * @date    27/02/2013
  * @brief   CMSIS Cortex-M1 Device Peripheral Access Layer System Header File.
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
  * <h2><center>&copy; COPYRIGHT 2013 Milandr</center></h2>
  ******************************************************************************
  * FILE system_MDR1986VE3.h
  */

/** @addtogroup __CMSIS CMSIS
  * @{
  */

/** @addtogroup MDR1986VE3
 *  @{
 */

/** @addtogroup __MDR1986VE3_System_Eclipse MDR1986VE3 System Eclipse
  * @{
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SYSTEM_MDR1986VE3_H
#define __SYSTEM_MDR1986VE3_H

/** @addtogroup __MDR1986VE3_System_Exported_Variables MDR1986VE3 System Exported Variables
  * @{
  */

extern uint32_t SystemCoreClock;          /*!< System Clock Frequency (Core Clock)
                                           *   default value */

/** @} */ /* End of group __MDR1986VE3_System_Exported_Variables */

/** @addtogroup __MDR1986VE3_System_Exported_Functions MDR1986VE3 System Exported Functions
  * @{
  */

extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);

/** @} */ /* End of group __MDR1986VE3_System_Exported_Functions */

#endif /* #define __SYSTEM_MDR1986VE3_H */

/** @} */ /* End of group __MDR1986VE3_System_Eclipse */

/** @} */ /* End of group MDR1986VE3 */

/** @} */ /* End of group __CMSIS */

/******************* (C) COPYRIGHT 2013 Milandr *********************************
*
* END OF FILE system_1986VE3.h */
