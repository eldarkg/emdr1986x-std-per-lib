/**
  ******************************************************************************
  * @file    MDR32F9Qx_comp.h
  * @author  Phyton Application Team
  * @version V1.3.0
  * @date    21/07/2011
  * @brief   This file contains all the functions prototypes for the COMP
  *          firmware library.
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
  * <h2><center>&copy; COPYRIGHT 2011 Phyton</center></h2>
  ******************************************************************************
  * FILE MDR32F9Qx_comp.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MDR32F9QX_COMP_H
#define __MDR32F9QX_COMP_H

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_config.h"
#include "MDR32F9Qx_lib.h"

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @addtogroup COMP
  * @{
  */

/** @defgroup COMP_Exported_Types COMP Exported Types
  * @{
  */

/**
  * @brief  COMP Init structure definition
  */

typedef struct
{
  uint32_t COMP_PlusInputSource;        /*!< Specifies the Comparator non-inverting input source.
                                             This parameter can be a value of @ref COMP_Plus_Input_Source */

  uint32_t COMP_MinusInputSource;       /*!< Specifies the Comparator inverting input source.
                                             This parameter can be a value of @ref COMP_Minus_Input_Source */

  uint32_t COMP_OutInversion;           /*!< Enables or disables the Comparator output innversion.
                                             This parameter can be a value of @ref COMP_Out_Inversion */
}COMP_InitTypeDef;

/**
  * @brief  COMP CVRef Init structure definition
  */

typedef struct
{
  uint32_t COMP_CVRefSource;            /*!< Specifies the CVREF voltage source.
                                             This parameter can be a value of @ref COMP_CVRef_Source */

  uint32_t COMP_CVRefRange;             /*!< Specifies the CVREF range (Up or Down).
                                             This parameter can be a value of @ref COMP_CVRef_Range */

  uint32_t COMP_CVRefScale;             /*!< Specifies the CVREF internal voltage scale.
                                             This parameter can be a value of @ref COMP_CVRef_Scale */
}COMP_CVRefInitTypeDef;

/** @} */ /* End of group COMP_Exported_Types */

/** @defgroup COMP_Exported_Constants COMP Exported Constants
  * @{
  */

/** @defgroup COMP_Plus_Input_Source COMP non-inverting input source
  * @{
  */

#define COMP_PlusInput_IN1                    (((uint32_t)0x0) << COMP_CFG_CREF_Pos)        /*!< The non-inverting comparator input connected to IN1. */
#define COMP_PlusInput_CVREF                  (((uint32_t)0x1) << COMP_CFG_CREF_Pos)        /*!< The non-inverting comparator input connected to CVREF. */

#define IS_COMP_PLUS_INPUT_CONFIG(CONFIG) (((CONFIG) == COMP_PlusInput_IN1  ) || \
                                           ((CONFIG) == COMP_PlusInput_CVREF))

/** @} */ /* End of group COMP_Plus_Input_Source */

/** @defgroup COMP_Minus_Input_Source COMP inverting input source
  * @{
  */

#define COMP_MinusInput_IN2                   (((uint32_t)0x0) << COMP_CFG_CCH_Pos)         /*!< The inverting comparator input connected to IN2. */
#define COMP_MinusInput_IN1                   (((uint32_t)0x1) << COMP_CFG_CCH_Pos)         /*!< The inverting comparator input connected to IN1. */
#define COMP_MinusInput_IN3                   (((uint32_t)0x2) << COMP_CFG_CCH_Pos)         /*!< The inverting comparator input connected to IN3. */
#define COMP_MinusInput_IVREF                 (((uint32_t)0x3) << COMP_CFG_CCH_Pos)         /*!< The inverting comparator input connected to IVREF. */

#define IS_COMP_MINUS_INPUT_CONFIG(CONFIG) (((CONFIG) == COMP_MinusInput_IN2  ) || \
                                            ((CONFIG) == COMP_MinusInput_IN1  ) || \
                                            ((CONFIG) == COMP_MinusInput_IN3  ) || \
                                            ((CONFIG) == COMP_MinusInput_IVREF))

/** @} */ /* End of group COMP_Minus_Input_Source */

/** @defgroup COMP_Out_Inversion COMP output inversion
  * @{
  */

#define COMP_OUT_INV_Disable                   (((uint32_t)0x0) << COMP_CFG_INV_Pos)        /*!< Disables the Comparator output inversion. */
#define COMP_OUT_INV_Enable                    (((uint32_t)0x1) << COMP_CFG_INV_Pos)        /*!< Enables the Comparator output inversion. */

#define IS_COMP_OUT_INV_CONFIG(CONFIG) (((CONFIG) == COMP_OUT_INV_Disable) || \
                                        ((CONFIG) == COMP_OUT_INV_Enable ))

/** @} */ /* End of group COMP_Out_Inversion */

/** @defgroup COMP_CVRef_Source COMP CVRef source
  * @{
  */

#define COMP_CVREF_SOURCE_AVdd                (((uint32_t)0x0) << COMP_CFG_CVRSS_Pos)       /*!< The CVREF source is (AVdd, AGND). */
#define COMP_CVREF_SOURCE_VRef                (((uint32_t)0x1) << COMP_CFG_CVRSS_Pos)       /*!< The CVREF source is (VRef+, VRef-). */

#define IS_COMP_CVREF_SOURCE_CONFIG(CONFIG) (((CONFIG) == COMP_CVREF_SOURCE_AVdd) || \
                                             ((CONFIG) == COMP_CVREF_SOURCE_VRef))

/** @} */ /* End of group COMP_CVRef_Source */

/** @defgroup COMP_CVRef_Range COMP CVRef range
  * @{
  */

#define COMP_CVREF_RANGE_Up                   (((uint32_t)0x0) << COMP_CFG_CVRR_Pos)        /*!< CVREF works in Up Range. */
#define COMP_CVREF_RANGE_Dn                   (((uint32_t)0x1) << COMP_CFG_CVRR_Pos)        /*!< CVREF works in Down Range. */

#define IS_COMP_CVREF_RANGE_CONFIG(CONFIG) (((CONFIG) == COMP_CVREF_RANGE_Up) || \
                                            ((CONFIG) == COMP_CVREF_RANGE_Dn))

/** @} */ /* End of group COMP_CVRef_Range */

/** @defgroup COMP_CVRef_Scale COMP CVRef scale
  * @{
  */

#define COMP_CVREF_SCALE_0_div_24             (((uint32_t)0x0) << COMP_CFG_CVR_Pos)         /*!< Selects the COMP CVRef down range scale 0/24.  */
#define COMP_CVREF_SCALE_1_div_24             (((uint32_t)0x1) << COMP_CFG_CVR_Pos)         /*!< Selects the COMP CVRef down range scale 1/24.  */
#define COMP_CVREF_SCALE_2_div_24             (((uint32_t)0x2) << COMP_CFG_CVR_Pos)         /*!< Selects the COMP CVRef down range scale 2/24.  */
#define COMP_CVREF_SCALE_3_div_24             (((uint32_t)0x3) << COMP_CFG_CVR_Pos)         /*!< Selects the COMP CVRef down range scale 3/24.  */
#define COMP_CVREF_SCALE_4_div_24             (((uint32_t)0x4) << COMP_CFG_CVR_Pos)         /*!< Selects the COMP CVRef down range scale 4/24.  */
#define COMP_CVREF_SCALE_5_div_24             (((uint32_t)0x5) << COMP_CFG_CVR_Pos)         /*!< Selects the COMP CVRef down range scale 5/24.  */
#define COMP_CVREF_SCALE_6_div_24             (((uint32_t)0x6) << COMP_CFG_CVR_Pos)         /*!< Selects the COMP CVRef down range scale 6/24.  */
#define COMP_CVREF_SCALE_7_div_24             (((uint32_t)0x7) << COMP_CFG_CVR_Pos)         /*!< Selects the COMP CVRef down range scale 7/24.  */
#define COMP_CVREF_SCALE_8_div_24             (((uint32_t)0x8) << COMP_CFG_CVR_Pos)         /*!< Selects the COMP CVRef down range scale 8/24.  */
#define COMP_CVREF_SCALE_9_div_24             (((uint32_t)0x9) << COMP_CFG_CVR_Pos)         /*!< Selects the COMP CVRef down range scale 9/24.  */
#define COMP_CVREF_SCALE_10_div_24            (((uint32_t)0xA) << COMP_CFG_CVR_Pos)         /*!< Selects the COMP CVRef down range scale 10/24. */
#define COMP_CVREF_SCALE_11_div_24            (((uint32_t)0xB) << COMP_CFG_CVR_Pos)         /*!< Selects the COMP CVRef down range scale 11/24. */
#define COMP_CVREF_SCALE_12_div_24            (((uint32_t)0xC) << COMP_CFG_CVR_Pos)         /*!< Selects the COMP CVRef down range scale 12/24. */
#define COMP_CVREF_SCALE_13_div_24            (((uint32_t)0xD) << COMP_CFG_CVR_Pos)         /*!< Selects the COMP CVRef down range scale 13/24. */
#define COMP_CVREF_SCALE_14_div_24            (((uint32_t)0xE) << COMP_CFG_CVR_Pos)         /*!< Selects the COMP CVRef down range scale 14/24. */
#define COMP_CVREF_SCALE_15_div_24            (((uint32_t)0xF) << COMP_CFG_CVR_Pos)         /*!< Selects the COMP CVRef down range scale 15/24. */

#define COMP_CVREF_SCALE_8_div_32             (((uint32_t)0x0) << COMP_CFG_CVR_Pos)         /*!< Selects the COMP CVRef up range scale 8/32.  */
#define COMP_CVREF_SCALE_9_div_32             (((uint32_t)0x1) << COMP_CFG_CVR_Pos)         /*!< Selects the COMP CVRef up range scale 9/32.  */
#define COMP_CVREF_SCALE_10_div_32            (((uint32_t)0x2) << COMP_CFG_CVR_Pos)         /*!< Selects the COMP CVRef up range scale 10/32. */
#define COMP_CVREF_SCALE_11_div_32            (((uint32_t)0x3) << COMP_CFG_CVR_Pos)         /*!< Selects the COMP CVRef up range scale 11/32. */
#define COMP_CVREF_SCALE_12_div_32            (((uint32_t)0x4) << COMP_CFG_CVR_Pos)         /*!< Selects the COMP CVRef up range scale 12/32. */
#define COMP_CVREF_SCALE_13_div_32            (((uint32_t)0x5) << COMP_CFG_CVR_Pos)         /*!< Selects the COMP CVRef up range scale 13/32. */
#define COMP_CVREF_SCALE_14_div_32            (((uint32_t)0x6) << COMP_CFG_CVR_Pos)         /*!< Selects the COMP CVRef up range scale 14/32. */
#define COMP_CVREF_SCALE_15_div_32            (((uint32_t)0x7) << COMP_CFG_CVR_Pos)         /*!< Selects the COMP CVRef up range scale 15/32. */
#define COMP_CVREF_SCALE_16_div_32            (((uint32_t)0x8) << COMP_CFG_CVR_Pos)         /*!< Selects the COMP CVRef up range scale 16/32. */
#define COMP_CVREF_SCALE_17_div_32            (((uint32_t)0x9) << COMP_CFG_CVR_Pos)         /*!< Selects the COMP CVRef up range scale 17/32. */
#define COMP_CVREF_SCALE_18_div_32            (((uint32_t)0xA) << COMP_CFG_CVR_Pos)         /*!< Selects the COMP CVRef up range scale 18/32. */
#define COMP_CVREF_SCALE_19_div_32            (((uint32_t)0xB) << COMP_CFG_CVR_Pos)         /*!< Selects the COMP CVRef up range scale 19/32. */
#define COMP_CVREF_SCALE_20_div_32            (((uint32_t)0xC) << COMP_CFG_CVR_Pos)         /*!< Selects the COMP CVRef up range scale 20/32. */
#define COMP_CVREF_SCALE_21_div_32            (((uint32_t)0xD) << COMP_CFG_CVR_Pos)         /*!< Selects the COMP CVRef up range scale 21/32. */
#define COMP_CVREF_SCALE_22_div_32            (((uint32_t)0xE) << COMP_CFG_CVR_Pos)         /*!< Selects the COMP CVRef up range scale 22/32. */
#define COMP_CVREF_SCALE_23_div_32            (((uint32_t)0xF) << COMP_CFG_CVR_Pos)         /*!< Selects the COMP CVRef up range scale 23/32. */

#define IS_COMP_CVREF_SCALE_CONFIG(CONFIG) (((CONFIG) == COMP_CVREF_SCALE_0_div_24 ) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_1_div_24 ) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_2_div_24 ) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_3_div_24 ) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_4_div_24 ) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_5_div_24 ) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_6_div_24 ) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_7_div_24 ) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_8_div_24 ) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_9_div_24 ) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_10_div_24) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_11_div_24) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_12_div_24) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_13_div_24) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_14_div_24) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_15_div_24) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_8_div_32 ) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_9_div_32 ) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_10_div_32) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_11_div_32) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_12_div_32) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_13_div_32) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_14_div_32) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_15_div_32) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_16_div_32) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_17_div_32) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_18_div_32) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_19_div_32) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_20_div_32) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_21_div_32) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_22_div_32) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_23_div_32))

/** @} */ /* End of group COMP_CVRef_Scale */

/** @defgroup COMP_Flags COMP Flags
  * @{
  */

#define COMP_CFG_FLAG_READY                    (((uint32_t)0x1) << COMP_CFG_READY_Pos)      /*!< Comparator is ready. */
#define COMP_CFG_FLAG_IE                       (((uint32_t)0x1) << COMP_CFG_CMPIE_Pos)      /*!< The Comparator interrupt enabled. */

#define IS_COMP_CFG_FLAG(FLAG) (((FLAG) == COMP_CFG_FLAG_READY) || \
                                ((FLAG) == COMP_CFG_FLAG_IE   ))

#define COMP_STATUS_FLAG_SY                    (((uint32_t)0x1) << COMP_RESULT_RSLT_SY_Pos) /*!< The latched Comparator output value. */
#define COMP_STATUS_FLAG_AS                    (((uint32_t)0x1) << COMP_RESULT_RSLT_AS_Pos) /*!< The Comparator output value. */
#define COMP_STATUS_FLAG_LCH                   (((uint32_t)0x1) << COMP_RESULT_RST_LCH_Pos) /*!< The clocked Comparator output value. */

#define IS_COMP_STATUS_FLAG(FLAG) (((FLAG) == COMP_STATUS_FLAG_SY ) || \
                                   ((FLAG) == COMP_STATUS_FLAG_AS ) || \
                                   ((FLAG) == COMP_STATUS_FLAG_LCH))

/** @} */ /* End of group COMP_Flags */

/** @defgroup COMP_Interrupt_definition COMP Interrupt definition
  * @{
  */

#define COMP_IT_LCH                         (((uint32_t)0x1) << COMP_RESULT_RST_LCH_Pos)

#define IS_COMP_CONFIG_IT(IT)               ((IT) == COMP_IT_LCH)

/** @} */ /* End of group COMP_Interrupt_definition */

/** @} */ /* End of group COMP_Exported_Constants */

/** @defgroup COMP_Exported_Macros COMP Exported Macros
  * @{
  */

/** @} */ /* End of group COMP_Exported_Macros */

/** @defgroup COMP_Exported_Functions COMP Exported Functions
  * @{
  */

void COMP_DeInit(void);

void COMP_Init(const COMP_InitTypeDef* COMP_InitStruct);
void COMP_StructInit(COMP_InitTypeDef* COMP_InitStruct);

void COMP_Cmd(FunctionalState NewState);

FlagStatus COMP_GetCfgFlagStatus(uint32_t Flag);

void COMP_PInpSourceConfig(uint32_t Source);
void COMP_MInpSourceConfig(uint32_t Source);
void COMP_OutInversionConfig(uint32_t Inversion);

void COMP_CVRefInit(const COMP_CVRefInitTypeDef* COMP_CVRefInitStruct);
void COMP_CVRefStructInit(COMP_CVRefInitTypeDef* COMP_CVRefInitStruct);

void COMP_CVRefCmd(FunctionalState NewState);

void COMP_CVRefSourceConfig(uint32_t Source);
void COMP_CVRefRangeConfig(uint32_t Range);
void COMP_CVRefScaleConfig(uint32_t Scale);

uint32_t COMP_GetResultLatch(void);
uint32_t COMP_GetStatus(void);

FlagStatus COMP_GetFlagStatus(uint32_t Flag);

void COMP_ITConfig(FunctionalState NewState);

/** @} */ /* End of group COMP_Exported_Functions */

/** @} */ /* End of group COMP */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

#endif /* __MDR32F9QX_COMP_H */

/******************* (C) COPYRIGHT 2011 Phyton *********************************
*
* END OF FILE MDR32F9Qx_comp.h */

