/**
  * FILE MDR32F9Qx_bkp.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MDR32F9Qx_BKP_H
#define __MDR32F9Qx_BKP_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_config.h"
#include "MDR32F9Qx_lib.h"

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @addtogroup BKP
  * @{
  */

/** @defgroup BKP_Exported_Types BKP Exported Types
  * @{
  */

/** @} */ /* End of group BKP_Exported_Types */

/** @defgroup BKP_Exported_Macros BKP Exported Macros
  * @{
  */

/** @} */ /* End of group BKP Exported Macros */

/** @defgroup BKP_Exported_Constants BKP Exported Constants
  * @{
  */

/** @defgroup Data_Backup_Registers Data Backup Registers
  * @{
  */

#define BKP_REG00                          ((uint32_t)0x0000)
#define BKP_REG01                          ((uint32_t)0x0004)
#define BKP_REG02                          ((uint32_t)0x0008)
#define BKP_REG03                          ((uint32_t)0x000C)
#define BKP_REG04                          ((uint32_t)0x0010)
#define BKP_REG05                          ((uint32_t)0x0014)
#define BKP_REG06                          ((uint32_t)0x0018)
#define BKP_REG07                          ((uint32_t)0x001C)
#define BKP_REG08                          ((uint32_t)0x0020)
#define BKP_REG09                          ((uint32_t)0x0024)
#define BKP_REG0A                          ((uint32_t)0x0028)
#define BKP_REG0B                          ((uint32_t)0x002C)
#define BKP_REG0C                          ((uint32_t)0x0030)
#define BKP_REG0D                          ((uint32_t)0x0034)
#define BKP_REG0E                          ((uint32_t)0x0038)
#define BKP_REG0F                          ((uint32_t)0x003C)

#define IS_BKP_REG(REG) \
                        (((REG) == BKP_REG00) || ((REG) == BKP_REG01) || \
                         ((REG) == BKP_REG02) || ((REG) == BKP_REG03) || \
                         ((REG) == BKP_REG04) || ((REG) == BKP_REG05) || \
                         ((REG) == BKP_REG06) || ((REG) == BKP_REG07) || \
                         ((REG) == BKP_REG08) || ((REG) == BKP_REG09) || \
                         ((REG) == BKP_REG0A) || ((REG) == BKP_REG0B) || \
                         ((REG) == BKP_REG0C) || ((REG) == BKP_REG0D) || \
                         ((REG) == BKP_REG0E) || ((REG) == BKP_REG0F))

#define IS_USER_BKP_REG(REG) \
                        (((REG) == BKP_REG00) || ((REG) == BKP_REG01) || \
                         ((REG) == BKP_REG02) || ((REG) == BKP_REG03) || \
                         ((REG) == BKP_REG04) || ((REG) == BKP_REG05) || \
                         ((REG) == BKP_REG06) || ((REG) == BKP_REG07) || \
                         ((REG) == BKP_REG08) || ((REG) == BKP_REG09) || \
                         ((REG) == BKP_REG0A) || ((REG) == BKP_REG0B) || \
                         ((REG) == BKP_REG0C) || ((REG) == BKP_REG0D))

/** @} */ /* End of group Data_Backup_Registers */

/** @defgroup BKP_RTC_CLK BKP RTC CLK
  * @{
  */

#define BKP_RTC_LSIclk ((uint32_t)0x0000)
#define BKP_RTC_LSEclk ((uint32_t)0x0004)
#define BKP_RTC_HSIclk ((uint32_t)0x0008)
#define BKP_RTC_HSEclk ((uint32_t)0x000C)

#define IS_RTC_CLK_SOURCE(CLK) (((CLK) == BKP_RTC_LSIclk) || \
                                ((CLK) == BKP_RTC_LSEclk) || \
                                ((CLK) == BKP_RTC_HSIclk) || \
                                ((CLK) == BKP_RTC_HSEclk))

/** @} */ /* End of group BKP_RTC_CLK */

/** @defgroup BKP_RTC_IT BKP RTC IT
  * @{
  */

#define BKP_RTC_IT_ALRF  ((uint32_t)BKP_RTC_CS_ALRF_IE)
#define BKP_RTC_IT_SECF  ((uint32_t)BKP_RTC_CS_SECF_IE)
#define BKP_RTC_IT_OWF   ((uint32_t)BKP_RTC_CS_OWF_IE)

#define IS_RTC_CLK_IT(IE) (((IE) & ~(BKP_RTC_IT_ALRF | BKP_RTC_IT_SECF | BKP_RTC_IT_OWF)) == 0)

/** @} */ /* End of group BKP_RTC_IT */

/** @defgroup BKP_RTC_CALIBRATION BKP RTC CALIBRATION
  * @{
  */

#define IS_RTC_CALIBRATION(CAL) ((CAL) <= 255)

/** @} */ /* End of group BKP_RTC_CALIBRATION */

/** @defgroup BKP_PRESCALER_VALUE BKP PRESCALER VALUE
  * @{
  */

#define IS_BKP_PRESCALER_VALUE(VAL) ((uint32_t)(VAL) <= 0x000FFFFF)

/** @} */ /* End of group BKP_PRESCALER_VALUE */

/** @defgroup BKP_RTC_FLAG BKP RTC FLAG
  * @{
  */

#define BKP_RTC_FLAG_WEC  ((uint32_t)BKP_RTC_CS_WEC)  /* RTC Write operation ended flag */
#define BKP_RTC_FLAG_OWF  ((uint32_t)BKP_RTC_CS_OWF)  /* Overflow flag                  */
#define BKP_RTC_FLAG_ALRF ((uint32_t)BKP_RTC_CS_ALRF) /* Alarm flag                     */
#define BKP_RTC_FLAG_SECF ((uint32_t)BKP_RTC_CS_SECF) /* Second flag                    */

#define IS_BKP_RTC_GET_FLAG(F) (((F) == BKP_RTC_CS_WEC)  || \
                                ((F) == BKP_RTC_CS_OWF)  || \
                                ((F) == BKP_RTC_CS_ALRF) || \
                                ((F) == BKP_RTC_CS_SECF))

/** @} */ /* End of group BKP_RTC_FLAG */

/** @} */ /* End of group BKP_Exported_Constants */

/** @defgroup BKP_Exported_Functions BKP Exported Functions
  * @{
  */
void BKP_DeInit(void);
#if defined (USE_MDR1986VE9x)
void BKP_JTAGA_CMD(FunctionalState NewState);
void BKP_JTAGB_CMD(FunctionalState NewState);
#endif // #if defined (MDR1986VE9x)
void BKP_RTCclkSource(uint32_t RTC_CLK);
void BKP_RTC_Enable(FunctionalState NewState);
void BKP_RTC_Calibration(uint32_t RTC_Calibration);
void BKP_RTC_Reset(FunctionalState NewState);
void BKP_RTC_ITConfig(uint32_t RTC_IT, FunctionalState NewState);
uint32_t  BKP_RTC_GetCounter(void);
void BKP_RTC_SetCounter(uint32_t CounterValue);
void BKP_RTC_SetAlarm(uint32_t AlarmValue);
uint32_t  BKP_RTC_GetDivider(void);
void BKP_RTC_SetPrescaler(uint32_t PrescalerValue);
void BKP_RTC_WaitForUpdate(void);
FlagStatus BKP_RTC_GetFlagStatus(uint32_t RTC_FLAG);

/** @} */ /* End of group BKP_Exported_Functions */

/** @} */ /* End of group BKP */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

#ifdef __cplusplus
} // extern "C" block end
#endif

#endif /* __MDR32F9Qx_BKP_H */

/*
*
* END OF FILE MDR32F9Qx_bkp.h */

