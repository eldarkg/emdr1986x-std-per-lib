/**
  * FILE MDR32F9Qx_wwdg.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MDR32F9Qx_WWDG_H
#define __MDR32F9Qx_WWDG_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_config.h"
#include "MDR32F9Qx_lib.h"

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @addtogroup WWDG
  * @{
  */

/** @defgroup WWDG_Exported_Types WWDG Exported Types
  * @{
  */

/** @} */ /* End of group WWDG_Exported_Types */

/** @defgroup WWDG_Exported_Constants WWDG Exported Constants
  * @{
  */

/** @defgroup WWDG_prescaler  WWDG prescaler
  * @{
  */

#define WWDG_Prescaler_1    ((uint32_t)0x00000000)
#define WWDG_Prescaler_2    ((uint32_t)0x00000080)
#define WWDG_Prescaler_4    ((uint32_t)0x00000100)
#define WWDG_Prescaler_8    ((uint32_t)0x00000180)
#define IS_WWDG_PRESCALER(PRESCALER) (((PRESCALER) == WWDG_Prescaler_1) || \
                                      ((PRESCALER) == WWDG_Prescaler_2) || \
                                      ((PRESCALER) == WWDG_Prescaler_4) || \
                                      ((PRESCALER) == WWDG_Prescaler_8))
#define IS_WWDG_WINDOW_VALUE(VALUE) ((VALUE) <= 0x7F)
#define IS_WWDG_COUNTER(COUNTER) (((COUNTER) >= 0x40) && ((COUNTER) <= 0x7F))

/** @} */ /* End of group WWDG_prescaler */

/** @} */ /* End of group WWDG_Exported_Constants */

/** @defgroup WWDG_Exported_Macros WWDG Exported Macros
  * @{
  */

/** @} */ /* End of group WWDG_Exported_Macros */

/** @defgroup WWDG_Exported_Functions WWDG Exported Functions
  * @{
  */

void WWDG_DeInit(void);
void WWDG_SetPrescaler(uint32_t WWDG_Prescaler);
void WWDG_SetWindowValue(uint32_t WindowValue);
void WWDG_EnableIT(void);
void WWDG_SetCounter(uint32_t Counter);
void WWDG_Enable(uint32_t Counter);
FlagStatus WWDG_GetFlagStatus(void);
void WWDG_ClearFlag(void);

/** @} */ /* End of group WWDG_Exported_Functions */

/** @} */ /* End of group WWDG */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

#ifdef __cplusplus
} // extern "C" block end
#endif

#endif /* __MDR32F9Qx_WWDG_H */

/*
*
* END OF FILE MDR32F9Qx_wwdg.h */
