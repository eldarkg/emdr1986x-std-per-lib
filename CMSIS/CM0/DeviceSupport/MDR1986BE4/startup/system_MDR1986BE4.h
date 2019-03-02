/**
  * FILE system_MDR1986BE4.h
  */

/** @addtogroup __CMSIS CMSIS
  * @{
  */

/** @defgroup MDR1986BE4
 *  @{
 */

/** @defgroup __MDR1986BE4 MDR1986BE4 System
  * @{
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SYSTEM_MDR1986BE4_H
#define __SYSTEM_MDR1986BE4_H

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup __MDR1986BE4_System_Exported_Variables MDR1986BE4 System Exported Variables
  * @{
  */

extern uint32_t SystemCoreClock;          /*!< System Clock Frequency (Core Clock)
                                           *   default value */

/** @} */ /* End of group __MDR1986BE4_System_Exported_Variables */

/** @addtogroup __MDR1986BE4_System_Exported_Functions MDR1986BE4 System Exported Functions
  * @{
  */

extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);

/** @} */ /* End of group __MDR1986BE4_System_Exported_Functions */

#ifdef __cplusplus
}
#endif

#endif /*__SYSTEM_MDR1986BE4_H */

/** @} */ /* End of group __MDR1986BE4 */

/** @} */ /* End of group MDR1986BE4 */

/** @} */ /* End of group __CMSIS */

/*
*
* END OF FILE system_MDR1986BE4.h */
