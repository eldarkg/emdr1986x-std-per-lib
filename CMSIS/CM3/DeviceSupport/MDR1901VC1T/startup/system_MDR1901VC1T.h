/**
  ******************************************************************************
  * @file    system_MDR1901VC1T.h
  * @author  Phyton Application Team
  * @version V1.3.0
  * @date    11/06/2010
  * @brief   CMSIS Cortex-M3 Device Peripheral Access Layer System Header File.
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
  * FILE system_MDR1901VC1T.h
  */

/** @addtogroup __CMSIS CMSIS
  * @{
  */

/** @defgroup MDR1901VC1T
 *  @{
 */

/** @defgroup __MDR1901VC1T MDR1901VC1T System
  * @{
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SYSTEM_MDR1901VC1T_H
#define __SYSTEM_MDR1901VC1T_H

/** @addtogroup __MDR1901VC1T_System_Exported_Variables MDR1901VC1T System Exported Variables
  * @{
  */

extern uint32_t SystemCoreClock;          /*!< System Clock Frequency (Core Clock)
                                           *   default value */

/** @} */ /* End of group __MDR1901VC1T_System_Exported_Variables */

/** @addtogroup __MDR1901VC1T_System_Exported_Functions MDR1901VC1T System Exported Functions
  * @{
  */

extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);

/** @} */ /* End of group __MDR1901VC1T_System_Exported_Functions */

#endif /*__SYSTEM_MDR1901VC1T_H */

/** @} */ /* End of group __MDR1901VC1T */

/** @} */ /* End of group MDR1901VC1T */

/** @} */ /* End of group __CMSIS */

/******************* (C) COPYRIGHT 2010 Phyton *********************************
*
* END OF FILE system_MDR1901VC1T.h */
