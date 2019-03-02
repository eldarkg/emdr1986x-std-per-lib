/**
  * FILE system_MDR1986VE3.h
  */

/** @addtogroup __CMSIS CMSIS
  * @{
  */

/** @addtogroup MDR1986VE3
 *  @{
 */

/** @addtogroup MDR1986VE3_System_ARM MDR1986VE3 System ARM
  * @{
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SYSTEM_MDR1986VE3_H
#define __SYSTEM_MDR1986VE3_H

#ifdef __cplusplus
extern "C" {
#endif

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

#ifdef __cplusplus
}
#endif

#endif /* #define __SYSTEM_MDR1986VE3_H */

/** @} */ /* End of group MDR1986VE3_System_ARM */

/** @} */ /* End of goup MDR1986VE3 */

/** @} */ /* End of group __CMSIS */

/*
*
* END OF FILE system_1986VE3.h */
