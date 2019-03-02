/**
  * FILE system_MDR32F9Qx.h
  */

/** @addtogroup __CMSIS CMSIS
  * @{
  */

/** @defgroup MDR1986VE9x
 *  @{
 */

/** @defgroup __MDR32F9QX MDR32F9QX System
  * @{
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SYSTEM_MDR32F9Qx_H
#define __SYSTEM_MDR32F9Qx_H

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup __MDR32F9QX_System_Exported_Variables MDR32F9QX System Exported Variables
  * @{
  */

extern uint32_t SystemCoreClock;          /*!< System Clock Frequency (Core Clock)
                                           *   default value */

/** @} */ /* End of group __MDR32F9QX_System_Exported_Variables */

/** @addtogroup __MDR32F9QX_System_Exported_Functions MDR32F9QX System Exported Functions
  * @{
  */

extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);

/** @} */ /* End of group __MDR32F9QX_System_Exported_Functions */

#ifdef __cplusplus
}
#endif

#endif /*__SYSTEM_MDR32F9Qx_H */

/** @} */ /* End of group __MDR32F9QX */

/** @} */ /* End of group MDR1986VE9x */

/** @} */ /* End of group __CMSIS */

/*
*
* END OF FILE system_MDR32F9Qx.h */
