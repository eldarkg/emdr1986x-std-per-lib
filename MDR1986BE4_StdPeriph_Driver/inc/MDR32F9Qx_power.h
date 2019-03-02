/**
  * FILE MDR32F9Qx_power.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MDR32F9Qx_POWER_H
#define __MDR32F9Qx_POWER_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_lib.h"

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @addtogroup POWER
  * @{
  */

/** @defgroup POWER_Exported_Types POWER Exported Types
  * @{
  */

/** @} */ /* End of group POWER_Exported_Types */

/** @defgroup POWER_Exported_Constants POWER Exported Constants
  * @{
  */

/** @defgroup POWER_DUcc_Mode POWER DUcc Mode
  * @{
  */
#define POWER_DUCC_MODE(par) ((uint32_t)((par<<3 )|(par)))

#define POWER_DUcc_upto_10MHz  POWER_DUCC_MODE(0)
#define POWER_DUcc_upto_200kHz POWER_DUCC_MODE(1)
#define POWER_DUcc_upto_500kHz POWER_DUCC_MODE(2)
#define POWER_DUcc_clk_off     POWER_DUCC_MODE(3)
#define POWER_DUcc_upto_1MHz   POWER_DUCC_MODE(4)
#define POWER_DUcc_upto_40MHz  POWER_DUCC_MODE(5)
#define POWER_DUcc_upto_80MHz  POWER_DUCC_MODE(6)
#define POWER_DUcc_over_80MHz  POWER_DUCC_MODE(7)

#define IS_POWER_DUCC_MODE(MODE) (((MODE) == POWER_DUcc_upto_10MHz) || \
                                ((MODE) == POWER_DUcc_upto_200kHz)|| \
                                ((MODE) == POWER_DUcc_upto_500kHz)|| \
                                ((MODE) == POWER_DUcc_clk_off)    || \
                                ((MODE) == POWER_DUcc_upto_1MHz)  || \
                                ((MODE) == POWER_DUcc_upto_40MHz) || \
                                ((MODE) == POWER_DUcc_upto_80MHz) || \
                                ((MODE) == POWER_DUcc_over_80MHz))

/** @} */ /* End of group POWER_DUcc_Mode */

/** @defgroup POWER_DUcc_Trim POWER DUcc Trim
  * @{
  */
#define POWER_DUcc_plus_100mV  ((uint32_t)(0x0000 << 8))
#define POWER_DUcc_plus_060mV  ((uint32_t)(0x0001 << 8))
#define POWER_DUcc_plus_040mV  ((uint32_t)(0x0002 << 8))
#define POWER_DUcc_plus_010mV  ((uint32_t)(0x0003 << 8))
#define POWER_DUcc_minus_010mV ((uint32_t)(0x0004 << 8))
#define POWER_DUcc_minus_040mV ((uint32_t)(0x0005 << 8))
#define POWER_DUcc_minus_060mV ((uint32_t)(0x0006 << 8))
#define POWER_DUcc_minus_100mV ((uint32_t)(0x0007 << 8))

#define IS_POWER_DUCC_TRIM(TRIM) (((TRIM) == POWER_DUcc_plus_100mV) || \
                                  ((TRIM) == POWER_DUcc_plus_060mV) || \
                                  ((TRIM) == POWER_DUcc_plus_040mV) || \
                                  ((TRIM) == POWER_DUcc_plus_010mV) || \
                                  ((TRIM) == POWER_DUcc_minus_010mV)|| \
                                  ((TRIM) == POWER_DUcc_minus_040mV)|| \
                                  ((TRIM) == POWER_DUcc_minus_060mV)|| \
                                  ((TRIM) == POWER_DUcc_minus_100mV))

/** @} */ /* End of group POWER_DUcc_Trim */



/** @defgroup POWER_Voltage_Detector_Level POWER Voltage Detector Level
  * @{
  */

#define PWR_PVDlevel_2V0 ((uint32_t)(0x00000000 << 3)) /* PVD detection level set to 2.0V  */
#define PWR_PVDlevel_2V2 ((uint32_t)(0x00000001 << 3)) /* PVD detection level set to 2.2V  */
#define PWR_PVDlevel_2V4 ((uint32_t)(0x00000002 << 3)) /* PVD detection level set to 2.4V  */
#define PWR_PVDlevel_2V6 ((uint32_t)(0x00000003 << 3)) /* PVD detection level set to 2.6V  */
#define PWR_PVDlevel_2V8 ((uint32_t)(0x00000004 << 3)) /* PVD detection level set to 2.8V  */
#define PWR_PVDlevel_3V0 ((uint32_t)(0x00000005 << 3)) /* PVD detection level set to 3.0V  */
#define PWR_PVDlevel_3V2 ((uint32_t)(0x00000006 << 3)) /* PVD detection level set to 3.2V  */
#define PWR_PVDlevel_3V4 ((uint32_t)(0x00000007 << 3)) /* PVD detection level set to 3.4V  */

#define IS_POWER_PVD_LEVEL(LVL) (((LVL) == PWR_PVDlevel_2V0) || \
                                 ((LVL) == PWR_PVDlevel_2V2) || \
                                 ((LVL) == PWR_PVDlevel_2V4) || \
                                 ((LVL) == PWR_PVDlevel_2V6) || \
                                 ((LVL) == PWR_PVDlevel_2V8) || \
                                 ((LVL) == PWR_PVDlevel_3V0) || \
                                 ((LVL) == PWR_PVDlevel_3V2) || \
                                 ((LVL) == PWR_PVDlevel_3V4))

/** @} */ /* End of group POWER_Voltage_Detector_Level */

/** @defgroup POWER_Battery_Voltage_Detector_Level POWER Battery Voltage Detector Level
  * @{
  */

#define PWR_PVBDlevel_1V8 ((uint32_t)(0x00000000 << 1)) /* PVBD detection level set to 1.8V  */
#define PWR_PVBDlevel_2V2 ((uint32_t)(0x00000001 << 1)) /* PVBD detection level set to 2.2V  */
#define PWR_PVBDlevel_2V6 ((uint32_t)(0x00000002 << 1)) /* PVBD detection level set to 2.6V  */
#define PWR_PVBDlevel_3V0 ((uint32_t)(0x00000003 << 1)) /* PVBD detection level set to 3.0V  */

#define IS_POWER_PVBD_LEVEL(LVL) (((LVL) == PWR_PVBDlevel_1V8) || \
                                  ((LVL) == PWR_PVBDlevel_2V2) || \
                                  ((LVL) == PWR_PVBDlevel_2V6) || \
                                  ((LVL) == PWR_PVBDlevel_3V0))

/** @} */ /* End of group POWER_Battery_Voltage_Detector_Level */


/** @defgroup POWER_Voltage_Detector_Output_Flags POWER Voltage Detector Output Flags
  * @{
  */

#define POWER_FLAG_PVD  ((uint32_t)POWER_PVDCS_PVD)     /* PVD Output  */
#define POWER_FLAG_PVBD ((uint32_t)POWER_PVDCS_PVBD)    /* PVBD Output */

#define IS_POWER_FLAG(F) (((F) == POWER_FLAG_PVD) || ((F) == POWER_FLAG_PVBD))

/** @} */ /* End of group POWER_Voltage_Detector_Output_Flags */

/** @defgroup POWER_Voltage_Detector_Interrupt_Enable POWER Voltage Detector Interrupt Enable
  * @{
  */

#define POWER_PVD_IT  ((uint32_t)POWER_PVDCS_IEPVD)     /* PVD interrupt enable  */
#define POWER_PVBD_IT ((uint32_t)POWER_PVDCS_IEPVBD)    /* PVBD interrupt enable */

#define IS_POWER_PVD_IT(F) (((F) == POWER_PVD_IT) || ((F) == POWER_PVBD_IT))

/** @} */ /* End of group POWER_Voltage_Detector_Interrupt_Enable */

/** @defgroup POWER_Voltage_Detector_Interrupt_Inversion POWER Voltage Detector Interrupt Inversion
  * @{
  */
#define POWER_PVD_INV  ((uint32_t)POWER_PVDCS_INV)      /* PVD inversion enable  */
#define POWER_PVBD_INV ((uint32_t)POWER_PVDCS_INVB)     /* PVBD inversion enable */

#define IS_POWER_PVD_INV(F) (((F) == POWER_PVD_INV) || ((F) == POWER_PVBD_INV))

/** @} */ /* End of group POWER_Voltage_Detector_Interrupt_Inversion */

/** @defgroup POWER_Stop_Entry_Mode POWER Stop Entry Mode
  * @{
  */
#define POWER_STOPentry_WFI  ((uint32_t)0x01)
#define POWER_STOPentry_WFE ((uint32_t)0x00)

#define IS_POWER_STOP_ENTRY(F) (((F) == POWER_STOPentry_WFI) || ((F) == POWER_STOPentry_WFE))

/** @} */ /* End of group POWER_Stop_Entry_Mode */


/** @} */ /* End of group POWER_Exported_Constants */

/** @defgroup POWER_Exported_Macros POWER Exported Macros
  * @{
  */

/** @} */ /* End of group POWER_Exported_Macros */

/** @defgroup POWER_Exported_Functions POWER Exported Functions
  * @{
  */

void POWER_DeInit(void);

void POWER_DUccMode(uint32_t DUccMode);
void POWER_DUccTrim(uint32_t DUccTrim);
void POWER_DUccStandby(void);
void POWER_SetFlagPOR(void);
ErrorStatus POWER_FlagPORstatus(void);

void POWER_PVDenable(FunctionalState NewState);
void POWER_PVDlevelConfig(uint32_t POWER_PVDlevel);
void POWER_PVBDlevelConfig(uint32_t POWER_PVBDlevel);
FlagStatus POWER_GetFlagStatus(uint32_t POWER_FLAG);
void POWER_ClearFlag(uint32_t POWER_FLAG);
void POWER_PVD_ITconfig(uint32_t POWER_IT, FunctionalState NewState);
void POWER_PVD_INVconfig(uint32_t POWER_INV, FunctionalState NewState);
void POWER_EnterSTANDBYMode(void);

/** @} */ /* End of group POWER_Exported_Functions */

/** @} */ /* End of group POWER */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

#ifdef __cplusplus
} // extern "C" block end
#endif

#endif /* __MDR32F9Qx_POWER_H */

/*
*
* END OF FILE MDR32F9Qx_power.h */


