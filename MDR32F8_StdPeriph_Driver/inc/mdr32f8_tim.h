/**
  ******************************************************************************
  * @file    MDR32F9Qx_timer.h
  * @author  Phyton Application Team
  * @version V1.4.0
  * @date    16/02/2011
  * @brief   This file contains all the functions prototypes for the TIMER
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
  * <h2><center>&copy; COPYRIGHT 2010 Phyton</center></h2>
  ******************************************************************************
  * FILE MDR32F9Qx_timer.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MDR32F9QX_TIMER_H
#define __MDR32F9QX_TIMER_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"	
#include "mdr32f8_config.h"
#include "MDR1986VE8T.h"	

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @addtogroup TIMER
  * @{
  */

/** @defgroup TIMER_Exported_Types TIMER Exported Types
  * @{
  */

/**
  * @brief  TIMER Counter Init structure definition
  */

typedef struct {

#if defined(USE_MDR1986VE9x) /* For Cortex M3 */
	uint16_t TIMER_IniCounter; 		 /*!< Specifies the initial counter value.
	 	 	 	 	 	 	 	     	  This parameter can be a number between 0x0000 and 0xFFFF. */
#elif ((defined (USE_MDR1986VE3)) || (defined (USE_MDR1986VE1T)))
	uint32_t TIMER_IniCounter;		/*!< Specifies the initial counter value.
									 	 This parameter can be a number between 0x0000 and 0xFFFFFFFF. */
#endif // #elif ((defined (USE_MDR1986VE3)) || (defined (USE_MDR1986VE1T)))

	uint16_t TIMER_Prescaler; 		 /*!< Specifies the prescaler value used to divide the TIMER clock.
	 	 	 	 	 	 	 	   	 	  This parameter can be a number between 0x0000 and 0xFFFF.
	 	 	 	 	 	 	 	   	 	  CLK = TIMER_CLK/(TIMER_Prescaler + 1) */

#if defined(USE_MDR1986VE9x) 		 /* For Cortex M3 */
	uint16_t TIMER_Period; 			 /*!< Specifies the period value to be loaded into the
	 	 	 	 	 	 	 	 	 	  Auto-Reload Register (ARR) at the next update event.
	 	 	 	 	 	 	 	 	 	  This parameter must be a number between 0x0000 and 0xFFFF.  */
#elif ((defined (USE_MDR1986VE3)) || (defined (USE_MDR1986VE1T))) /* For Cortex M1 */
	uint32_t TIMER_Period;			/*!< Specifies the period value to be loaded into the
										 Auto-Reload Register (ARR) at the next update event.
										 This parameter must be a number between 0x0000 and 0xFFFFFFFF.  */
#endif // #elif ((defined (USE_MDR1986VE3)) || (defined (USE_MDR1986VE1T))) /* For Cortex M1 */

	uint16_t TIMER_CounterMode;		 /*!< Specifies the counter mode.
	 	 	 	 	 	 	 	 	 	  This parameter can be a value of @ref TIMER_Counter_Mode */

	uint16_t TIMER_CounterDirection; /*!< Specifies the counter direction.
	 	 	 	 	 	 	 	 	 	  This parameter can be a value of @ref TIMER_Counter_Direction */

	uint16_t TIMER_EventSource; 	/*!< Specifies the Counter Event source.
	 	 	 	 	 	 	 	 	 	 This parameter can be a value of @ref TIMER_Event_Source */

	uint16_t TIMER_FilterSampling;  /*!< Specifies the filter sampling clock (FDTS).
	 	 	 	 	 	 	 	 	 	 This parameter can be a value of @ref TIMER_Filter_Sampling */

	uint16_t TIMER_ARR_UpdateMode; 	/*!< Specifies the Auto-Reload Register (ARR) updating mode.
	 	 	 	 	 	 	 	 	 	 This parameter can be a value of @ref TIMER_ARR_Update_Mode */

	uint16_t TIMER_ETR_FilterConf; 	/*!< Specifies the ETR Filter configuration.
	 	 	 	 	 	 	 	 	 	 This parameter can be a value of @ref TIMER_FilterConfiguration */

	uint16_t TIMER_ETR_Prescaler; 	/*!< Specifies the ETR Prescaler configuration.
	 	 	 	 	 	 	 	 	 	 This parameter can be a value of @ref TIMER_ETR_Prescaler */

	uint16_t TIMER_ETR_Polarity; 	/*!< Specifies the ETR Polarity configuration.
	 	 	 	 	 	 	 	 	 	 This parameter can be a value of @ref TIMER_ETR_Polarity */

	uint16_t TIMER_BRK_Polarity; 	/*!< Specifies the BRK Polarity configuration.
	 	 	 	 	 	 	 	 	 	 This parameter can be a value of @ref TIMER_BRK_Polarity */
} TIMER_CntInitTypeDef;

/**
  * @brief  TIMER Channel Init structure definition
  */

typedef struct
{
  uint16_t TIMER_CH_Number;             /*!< Specifies the TIMER Channel number to be configured.
                                             This parameter can be a value of @ref TIMER_CH_Number */

  uint16_t TIMER_CH_Mode;               /*!< Specifies the TIMER Channel mode.
                                             This parameter can be a value of @ref TIMER_CH_Mode */

  uint16_t TIMER_CH_ETR_Ena;            /*!< Enables or disables ETR.
                                             This parameter can be a value of FunctionalState */

  uint16_t TIMER_CH_ETR_Reset;          /*!< Enables or disables ETR Reset.
                                             This parameter can be a value of @ref TIMER_CH_ETR_Reset */

  uint16_t TIMER_CH_BRK_Reset;          /*!< Enables or disables BRK Reset.
                                             This parameter can be a value of @ref TIMER_CH_BRK_Reset */

  uint16_t TIMER_CH_REF_Format;         /*!< Specifies the REF signal format.
                                             This parameter can be a value of @ref TIMER_CH_REF_Format */

  uint16_t TIMER_CH_Prescaler;          /*!< Specifies the TIMER Channel Prescaler configuration.
                                             This parameter can be a value of @ref TIMER_CH_Prescaler */

  uint16_t TIMER_CH_EventSource;        /*!< Specifies the Channel Event source.
                                             This parameter can be a value of @ref TIMER_CH_EventSource */

  uint16_t TIMER_CH_FilterConf;         /*!< Specifies the TIMER Channel Filter configuration.
                                             This parameter can be a value of @ref TIMER_FilterConfiguration */

  uint16_t TIMER_CH_CCR_UpdateMode;     /*!< Specifies the TIMER CCR, CCR1 update mode.
                                             This parameter can be a value of @ref TIMER_CH_CCR_Update_Mode */

  uint16_t TIMER_CH_CCR1_Ena;           /*!< Enables or disables the CCR1 register.
                                             This parameter can be a value of FunctionalState */

  uint16_t TIMER_CH_CCR1_EventSource;   /*!< Specifies the Channel CCR1 Event source.
                                             This parameter can be a value of @ref TIMER_CH_CCR1_EventSource */
}TIMER_ChnInitTypeDef;

/**
  * @brief  TIMER Channel Output Init structure definition
  */

typedef struct
{
  uint16_t TIMER_CH_Number;             /*!< Specifies the TIMER Channel number to be configured.
                                             This parameter can be a value of @ref TIMER_CH_Number */

  uint16_t TIMER_CH_DirOut_Polarity;    /*!< Specifies the TIMER CHx output polarity.
                                             This parameter can be a value of @ref TIMER_CH_OUT_Polarity */

  uint16_t TIMER_CH_DirOut_Source;      /*!< Specifies the TIMER CHx output source.
                                             This parameter can be a value of @ref TIMER_CH_OUT_Source */

  uint16_t TIMER_CH_DirOut_Mode;        /*!< Specifies the TIMER CHx output enable source.
                                             This parameter can be a value of @ref TIMER_CH_OUT_Mode */

  uint16_t TIMER_CH_NegOut_Polarity;    /*!< Enables or disables the TIMER CHxN output inversion.
                                             This parameter can be a value of @ref TIMER_CH_OUT_Polarity */

  uint16_t TIMER_CH_NegOut_Source;      /*!< Specifies the TIMER CHxN output source.
                                             This parameter can be a value of @ref TIMER_CH_OUT_Source */

  uint16_t TIMER_CH_NegOut_Mode;        /*!< Specifies the TIMER CHxN output enable source.
                                             This parameter can be a value of @ref TIMER_CH_OUT_Mode */

  uint16_t TIMER_CH_DTG_MainPrescaler;  /*!< Specifies the main prescaler of TIMER DTG.
                                             This parameter can be a number between 0x0000 and 0x00FF.
                                             Delay DTGdel = TIMER_CH_DTG_MainPrescaler*(TIMER_CH_DTG_AuxPrescaler + 1) clocks. */

  uint16_t TIMER_CH_DTG_AuxPrescaler;   /*!< Specifies the auxiliary prescaler of TIMER DTG.
                                             This parameter can be a number between 0x0000 and 0x000F.
                                             Delay DTGdel = TIMER_CH_DTG_MainPrescaler*(TIMER_CH_DTG_AuxPrescaler + 1) clocks. */

  uint16_t TIMER_CH_DTG_ClockSource;    /*!< Specifies the TIMER DTG clock source.
                                             This parameter can be a value of @ref TIMER_CH_DTG_Clock_Source */
}TIMER_ChnOutInitTypeDef;

/** @} */ /* End of group TIMER_Exported_Types */

/** @defgroup TIMER_Exported_Constants TIMER Exported Constants
  * @{
  */

#if defined (USE_MDR1986VE9x)
#define IS_TIMER_ALL_PERIPH(PERIPH) (((PERIPH) == MDR_TIMER1) || \
                                     ((PERIPH) == MDR_TIMER2) || \
                                     ((PERIPH) == MDR_TIMER3)))
#elif ((defined (USE_MDR1986VE3)) || (defined (USE_MDR1986VE1T)))
#define IS_TIMER_ALL_PERIPH(PERIPH) (((PERIPH) == MDR_TIMER1) || \
                                     ((PERIPH) == MDR_TIMER2) || \
                                     ((PERIPH) == MDR_TIMER3) || \
                                     ((PERIPH) == MDR_TIMER4))
#endif

/** @defgroup TIMER_Counter_Mode TIMER Counter Mode
  * @{
  */

#define TIMER_CntMode_ClkFixedDir             (((uint32_t)0x0) << TIMER_CNTRL_CNT_MODE_Pos) /*!< The Timer clock changes the TIMERx_CNT value. The count direction is not changed. */
#define TIMER_CntMode_ClkChangeDir            (((uint32_t)0x1) << TIMER_CNTRL_CNT_MODE_Pos) /*!< The Timer clock changes the TIMERx_CNT value. The count direction changes. */
#define TIMER_CntMode_EvtFixedDir             (((uint32_t)0x2) << TIMER_CNTRL_CNT_MODE_Pos) /*!< The event changes the TIMERx_CNT value. The count direction is not changed. */
#define TIMER_CntMode_EvtChangeDir            (((uint32_t)0x3) << TIMER_CNTRL_CNT_MODE_Pos) /*!< The event changes the TIMERx_CNT value. The count direction changes. */

#define IS_TIMER_COUNTER_MODE(MODE) (((MODE) == TIMER_CntMode_ClkFixedDir ) || \
                                     ((MODE) == TIMER_CntMode_ClkChangeDir) || \
                                     ((MODE) == TIMER_CntMode_EvtFixedDir ) || \
                                     ((MODE) == TIMER_CntMode_EvtChangeDir))

/** @} */ /* End of group TIMER_Counter_Mode */

/** @defgroup TIMER_Counter_Direction TIMER Counter Direction
  * @{
  */

#define TIMER_CntDir_Up                       (((uint32_t)0x0) << TIMER_CNTRL_DIR_Pos)  /*!< Increments the Timer TIMERx_CNT counter value. */
#define TIMER_CntDir_Dn                       (((uint32_t)0x1) << TIMER_CNTRL_DIR_Pos)  /*!< Decrements the Timer TIMERx_CNT counter value. */

#define IS_TIMER_COUNTER_DIR(DIR) (((DIR) == TIMER_CntDir_Up) || \
                                   ((DIR) == TIMER_CntDir_Dn))

/** @} */ /* End of group TIMER_Counter_Direction */

/** @defgroup TIMER_Event_Source TIMER Event Source
  * @{
  */

#define TIMER_EvSrc_None                      (((uint32_t)0x0) << TIMER_CNTRL_EVENT_SEL_Pos)  /*!< No events. */
#define TIMER_EvSrc_TM1                       (((uint32_t)0x1) << TIMER_CNTRL_EVENT_SEL_Pos)  /*!< Selects TIMER1 (CNT == ARR) event. */
#define TIMER_EvSrc_TM2                       (((uint32_t)0x2) << TIMER_CNTRL_EVENT_SEL_Pos)  /*!< Selects TIMER2 (CNT == ARR) event. */
#define TIMER_EvSrc_TM3                       (((uint32_t)0x3) << TIMER_CNTRL_EVENT_SEL_Pos)  /*!< Selects TIMER3 (CNT == ARR) event. */
#define TIMER_EvSrc_CH1                       (((uint32_t)0x4) << TIMER_CNTRL_EVENT_SEL_Pos)  /*!< Selects Channel 1 event. */
#define TIMER_EvSrc_CH2                       (((uint32_t)0x5) << TIMER_CNTRL_EVENT_SEL_Pos)  /*!< Selects Channel 2 event. */
#define TIMER_EvSrc_CH3                       (((uint32_t)0x6) << TIMER_CNTRL_EVENT_SEL_Pos)  /*!< Selects Channel 3 event. */
#define TIMER_EvSrc_CH4                       (((uint32_t)0x7) << TIMER_CNTRL_EVENT_SEL_Pos)  /*!< Selects Channel 4 event. */
#define TIMER_EvSrc_ETR                       (((uint32_t)0x8) << TIMER_CNTRL_EVENT_SEL_Pos)  /*!< Selects ETR event. */

#define IS_TIMER_EVENT_SOURCE(SOURCE) (((SOURCE) == TIMER_EvSrc_None) || \
                                       ((SOURCE) == TIMER_EvSrc_TM1 ) || \
                                       ((SOURCE) == TIMER_EvSrc_TM2 ) || \
                                       ((SOURCE) == TIMER_EvSrc_TM3 ) || \
                                       ((SOURCE) == TIMER_EvSrc_CH1 ) || \
                                       ((SOURCE) == TIMER_EvSrc_CH2 ) || \
                                       ((SOURCE) == TIMER_EvSrc_CH3 ) || \
                                       ((SOURCE) == TIMER_EvSrc_CH4 ) || \
                                       ((SOURCE) == TIMER_EvSrc_ETR ))

/** @} */ /* End of group TIMER_Event_Source */

/** @defgroup TIMER_Filter_Sampling TIMER Filter Sampling Clock
  * @{
  */

#define TIMER_FDTS_TIMER_CLK_div_1              (((uint32_t)0x0) << TIMER_CNTRL_FDTS_Pos) /*!< The FDTS clock occures each TIMER_CLK clock. */
#define TIMER_FDTS_TIMER_CLK_div_2              (((uint32_t)0x1) << TIMER_CNTRL_FDTS_Pos) /*!< The FDTS clock occures each 2-nd TIMER_CLK clock. */
#define TIMER_FDTS_TIMER_CLK_div_3              (((uint32_t)0x2) << TIMER_CNTRL_FDTS_Pos) /*!< The FDTS clock occures each 3-rd TIMER_CLK clock. */
#define TIMER_FDTS_TIMER_CLK_div_4              (((uint32_t)0x3) << TIMER_CNTRL_FDTS_Pos) /*!< The FDTS clock occures each 4-th TIMER_CLK clock. */

#define IS_TIMER_FILTER_SAMPLING(CONFIG) (((CONFIG) == TIMER_FDTS_TIMER_CLK_div_1) || \
                                          ((CONFIG) == TIMER_FDTS_TIMER_CLK_div_2) || \
                                          ((CONFIG) == TIMER_FDTS_TIMER_CLK_div_3) || \
                                          ((CONFIG) == TIMER_FDTS_TIMER_CLK_div_4))

/** @} */ /* End of group TIMER_Filter_Sampling */

/** @defgroup TIMER_ARR_Update_Mode TIMER ARR Update Mode
  * @{
  */

#define TIMER_ARR_Update_Immediately          (((uint32_t)0x0) << TIMER_CNTRL_ARRB_EN_Pos)  /*!< The ARR register is updated immediately. */
#define TIMER_ARR_Update_On_CNT_Overflow      (((uint32_t)0x1) << TIMER_CNTRL_ARRB_EN_Pos)  /*!< The ARR register is updated at CNT count end. */

#define IS_TIMER_ARR_UPDATE_MODE(MODE) (((MODE) == TIMER_ARR_Update_Immediately    ) || \
                                        ((MODE) == TIMER_ARR_Update_On_CNT_Overflow))

/** @} */ /* End of group TIMER_ARR_UpdateMode */

/** @defgroup TIMER_FilterConfiguration TIMER Filter configuration
  * @{
  */

#define TIMER_Filter_1FF_at_TIMER_CLK         ((uint32_t)0x0)  /*!< Signal is latched by 1 trigger  at TIMER_CLK clock frequency. */
#define TIMER_Filter_2FF_at_TIMER_CLK         ((uint32_t)0x1)  /*!< Signal is latched by 2 triggers at TIMER_CLK clock frequency. */
#define TIMER_Filter_4FF_at_TIMER_CLK         ((uint32_t)0x2)  /*!< Signal is latched by 4 triggers at TIMER_CLK clock frequency. */
#define TIMER_Filter_8FF_at_TIMER_CLK         ((uint32_t)0x3)  /*!< Signal is latched by 8 triggers at TIMER_CLK clock frequency. */
#define TIMER_Filter_6FF_at_FTDS_div_2        ((uint32_t)0x4)  /*!< Signal is latched by 6 triggers at FDTS/2  clock frequency. */
#define TIMER_Filter_8FF_at_FTDS_div_2        ((uint32_t)0x5)  /*!< Signal is latched by 8 triggers at FDTS/2  clock frequency. */
#define TIMER_Filter_6FF_at_FTDS_div_4        ((uint32_t)0x6)  /*!< Signal is latched by 6 triggers at FDTS/4  clock frequency. */
#define TIMER_Filter_8FF_at_FTDS_div_4        ((uint32_t)0x7)  /*!< Signal is latched by 8 triggers at FDTS/4  clock frequency. */
#define TIMER_Filter_6FF_at_FTDS_div_8        ((uint32_t)0x8)  /*!< Signal is latched by 6 triggers at FDTS/8  clock frequency. */
#define TIMER_Filter_8FF_at_FTDS_div_8        ((uint32_t)0x9)  /*!< Signal is latched by 8 triggers at FDTS/8  clock frequency. */
#define TIMER_Filter_5FF_at_FTDS_div_16       ((uint32_t)0xA)  /*!< Signal is latched by 5 triggers at FDTS/16 clock frequency. */
#define TIMER_Filter_6FF_at_FTDS_div_16       ((uint32_t)0xB)  /*!< Signal is latched by 6 triggers at FDTS/16 clock frequency. */
#define TIMER_Filter_8FF_at_FTDS_div_16       ((uint32_t)0xC)  /*!< Signal is latched by 8 triggers at FDTS/16 clock frequency. */
#define TIMER_Filter_5FF_at_FTDS_div_32       ((uint32_t)0xD)  /*!< Signal is latched by 5 triggers at FDTS/32 clock frequency. */
#define TIMER_Filter_6FF_at_FTDS_div_32       ((uint32_t)0xE)  /*!< Signal is latched by 6 triggers at FDTS/32 clock frequency. */
#define TIMER_Filter_8FF_at_FTDS_div_32       ((uint32_t)0xF)  /*!< Signal is latched by 8 triggers at FDTS/32 clock frequency. */

#define IS_TIMER_FILTER_CONF(CONF) (((CONF) == TIMER_Filter_1FF_at_TIMER_CLK  ) || \
                                    ((CONF) == TIMER_Filter_2FF_at_TIMER_CLK  ) || \
                                    ((CONF) == TIMER_Filter_4FF_at_TIMER_CLK  ) || \
                                    ((CONF) == TIMER_Filter_8FF_at_TIMER_CLK  ) || \
                                    ((CONF) == TIMER_Filter_6FF_at_FTDS_div_2 ) || \
                                    ((CONF) == TIMER_Filter_8FF_at_FTDS_div_2 ) || \
                                    ((CONF) == TIMER_Filter_6FF_at_FTDS_div_4 ) || \
                                    ((CONF) == TIMER_Filter_8FF_at_FTDS_div_4 ) || \
                                    ((CONF) == TIMER_Filter_6FF_at_FTDS_div_8 ) || \
                                    ((CONF) == TIMER_Filter_8FF_at_FTDS_div_8 ) || \
                                    ((CONF) == TIMER_Filter_5FF_at_FTDS_div_16) || \
                                    ((CONF) == TIMER_Filter_6FF_at_FTDS_div_16) || \
                                    ((CONF) == TIMER_Filter_8FF_at_FTDS_div_16) || \
                                    ((CONF) == TIMER_Filter_5FF_at_FTDS_div_32) || \
                                    ((CONF) == TIMER_Filter_6FF_at_FTDS_div_32) || \
                                    ((CONF) == TIMER_Filter_8FF_at_FTDS_div_32))

/** @} */ /* End of group TIMER_FilterConfiguration */

/** @defgroup TIMER_ETR_Prescaler TIMER ETR Prescaler
  * @{
  */

#define TIMER_ETR_Prescaler_None              (((uint32_t)0x0) << TIMER_BRKETR_CNTRL_ETR_PSC_Pos)  /*!< No division of input frequency. */
#define TIMER_ETR_Prescaler_div_2             (((uint32_t)0x1) << TIMER_BRKETR_CNTRL_ETR_PSC_Pos)  /*!< Selects input frequency divider by 2. */
#define TIMER_ETR_Prescaler_div_4             (((uint32_t)0x2) << TIMER_BRKETR_CNTRL_ETR_PSC_Pos)  /*!< Selects input frequency divider by 4. */
#define TIMER_ETR_Prescaler_div_8             (((uint32_t)0x3) << TIMER_BRKETR_CNTRL_ETR_PSC_Pos)  /*!< Selects input frequency divider by 8. */

#define IS_TIMER_ETR_PRESCALER(VALUE) (((VALUE) == TIMER_ETR_Prescaler_None ) || \
                                       ((VALUE) == TIMER_ETR_Prescaler_div_2) || \
                                       ((VALUE) == TIMER_ETR_Prescaler_div_4) || \
                                       ((VALUE) == TIMER_ETR_Prescaler_div_8))

/** @} */ /* End of group TIMER_ETR_Prescaler */

/** @defgroup TIMER_ETR_Polarity TIMER ETR Polarity
  * @{
  */

#define TIMER_ETRPolarity_NonInverted         (((uint32_t)0x0) << TIMER_BRKETR_CNTRL_ETR_INV_Pos)  /*!< No inversion of the ETR input. */
#define TIMER_ETRPolarity_Inverted            (((uint32_t)0x1) << TIMER_BRKETR_CNTRL_ETR_INV_Pos)  /*!< The ETR input is inverted. */

#define IS_TIMER_ETR_POLARITY(STATE) (((STATE) == TIMER_ETRPolarity_NonInverted) || \
                                      ((STATE) == TIMER_ETRPolarity_Inverted   ))

/** @} */ /* End of group TIMER_ETR_Polarity */

/** @defgroup TIMER_BRK_Polarity TIMER BRK Polarity
  * @{
  */

#define TIMER_BRKPolarity_NonInverted         (((uint32_t)0x0) << TIMER_BRKETR_CNTRL_BRK_INV_Pos)  /*!< No inversion of the BRK input. */
#define TIMER_BRKPolarity_Inverted            (((uint32_t)0x1) << TIMER_BRKETR_CNTRL_BRK_INV_Pos)  /*!< The BRK input is inverted. */

#define IS_TIMER_BRK_POLARITY(STATE) (((STATE) == TIMER_BRKPolarity_NonInverted) || \
                                      ((STATE) == TIMER_BRKPolarity_Inverted   ))

/** @} */ /* End of group TIMER_BRK_Polarity */

/** @defgroup TIMER_CH_Number TIMER Channel Number
  * @{
  */

#define TIMER_CHANNEL1                        ((uint32_t)0x0)  /*!< Specifies the TIMER channel 1. */
#define TIMER_CHANNEL2                        ((uint32_t)0x1)  /*!< Specifies the TIMER channel 2. */
#define TIMER_CHANNEL3                        ((uint32_t)0x2)  /*!< Specifies the TIMER channel 3. */
#define TIMER_CHANNEL4                        ((uint32_t)0x3)  /*!< Specifies the TIMER channel 4. */

#define IS_TIMER_CHANNEL_NUMBER(NUMBER) (((NUMBER) == TIMER_CHANNEL1) || \
                                         ((NUMBER) == TIMER_CHANNEL2) || \
                                         ((NUMBER) == TIMER_CHANNEL3) || \
                                         ((NUMBER) == TIMER_CHANNEL4))

/** @} */ /* End of group TIMER_CH_Number */

/** @defgroup TIMER_CH_ETR_Reset TIMER Channel ETR Reset configuration
  * @{
  */

#define TIMER_CH_ETR_RESET_Disable            (((uint32_t)0x0) << TIMER_CH_CNTRL_ETREN_Pos)   /*!< Disables ETR Reset. */
#define TIMER_CH_ETR_RESET_Enable             (((uint32_t)0x1) << TIMER_CH_CNTRL_ETREN_Pos)   /*!< Enables ETR Reset. */

#define IS_TIMER_CHANNEL_ETR_RESET_CONFIG(CONFIG) (((CONFIG) == TIMER_CH_ETR_RESET_Disable) || \
                                                   ((CONFIG) == TIMER_CH_ETR_RESET_Enable ))

/** @} */ /* End of group TIMER_CH_ETR_Reset */

/** @defgroup TIMER_CH_BRK_Reset TIMER Channel BRK Reset configuration
  * @{
  */

#define TIMER_CH_BRK_RESET_Disable            (((uint32_t)0x0) << TIMER_CH_CNTRL_BRKEN_Pos)   /*!< Disables BRK Reset. */
#define TIMER_CH_BRK_RESET_Enable             (((uint32_t)0x1) << TIMER_CH_CNTRL_BRKEN_Pos)   /*!< Enables BRK Reset. */

#define IS_TIMER_CHANNEL_BRK_RESET_CONFIG(CONFIG) (((CONFIG) == TIMER_CH_BRK_RESET_Disable) || \
                                                   ((CONFIG) == TIMER_CH_BRK_RESET_Enable ))

/** @} */ /* End of group TIMER_CH_BRK_Reset */

/** @defgroup TIMER_CH_Mode TIMER Channel Mode
  * @{
  */

#define TIMER_CH_MODE_PWM                     (((uint32_t)0x0) << TIMER_CH_CNTRL_CAP_NPWM_Pos)  /*!< Specifies the PWM channel mode. */
#define TIMER_CH_MODE_CAPTURE                 (((uint32_t)0x1) << TIMER_CH_CNTRL_CAP_NPWM_Pos)  /*!< Specifies the Capture channel mode. */

#define IS_TIMER_CHANNEL_MODE(MODE) (((MODE) == TIMER_CH_MODE_PWM    ) || \
                                     ((MODE) == TIMER_CH_MODE_CAPTURE))

/** @} */ /* End of group TIMER_CH_Mode */

/** @defgroup TIMER_CH_REF_Format TIMER Channel REF Format
  * @{
  */

#define TIMER_CH_REF_Format0                  (((uint32_t)0x0) << TIMER_CH_CNTRL_OCCM_Pos)  /*!< REF is equal to 0 */
#define TIMER_CH_REF_Format1                  (((uint32_t)0x1) << TIMER_CH_CNTRL_OCCM_Pos)  /*!< REF is equal to 1 if:
                                                                                                   (CNT == CCR) or
                                                                                                   ((CNT == CCR1) and CCR1 enabled),
                                                                                                 else REF is equal to 0. */
#define TIMER_CH_REF_Format2                  (((uint32_t)0x2) << TIMER_CH_CNTRL_OCCM_Pos)  /*!< REF is equal to 0 if:
                                                                                                   (CNT == CCR) or
                                                                                                   ((CNT == CCR1) and CCR1 enabled),
                                                                                                 else REF is equal to 1. */
#define TIMER_CH_REF_Format3                  (((uint32_t)0x3) << TIMER_CH_CNTRL_OCCM_Pos)  /*!< Toggle REF state if:
                                                                                                   (CNT == CCR) or
                                                                                                   ((CNT == CCR1) and CCR1 enabled). */
#define TIMER_CH_REF_Format4                  (((uint32_t)0x4) << TIMER_CH_CNTRL_OCCM_Pos)  /*!< REF is equal to 0. */
#define TIMER_CH_REF_Format5                  (((uint32_t)0x5) << TIMER_CH_CNTRL_OCCM_Pos)  /*!< REF is equal to 1. */
#define TIMER_CH_REF_Format6                  (((uint32_t)0x6) << TIMER_CH_CNTRL_OCCM_Pos)  /*!< REF is equal to inverted DIR state if:
                                                                                                   (CCR1 disabled and (CNT < CCR)) or
                                                                                                   (CCR1 enabled  and (CCR1 < CNT < CCR)),
                                                                                                 else REF is equal to DIR state. */
#define TIMER_CH_REF_Format7                  (((uint32_t)0x7) << TIMER_CH_CNTRL_OCCM_Pos)  /*!< REF is equal to DIR state if:
                                                                                                   (CCR1 disabled and (CNT < CCR)) or
                                                                                                   (CCR1 enabled  and (CCR1 < CNT < CCR)),
                                                                                                 else REF is equal to inverted DIR state. */

#define IS_TIMER_CHANNEL_REF_FORMAT(FORMAT) (((FORMAT) == TIMER_CH_REF_Format0) || \
                                             ((FORMAT) == TIMER_CH_REF_Format1) || \
                                             ((FORMAT) == TIMER_CH_REF_Format2) || \
                                             ((FORMAT) == TIMER_CH_REF_Format3) || \
                                             ((FORMAT) == TIMER_CH_REF_Format4) || \
                                             ((FORMAT) == TIMER_CH_REF_Format5) || \
                                             ((FORMAT) == TIMER_CH_REF_Format6) || \
                                             ((FORMAT) == TIMER_CH_REF_Format7))

/** @} */ /* End of group TIMER_CH_REF_Format */

/** @defgroup TIMER_CH_Prescaler TIMER Channel Prescaler
  * @{
  */

#define TIMER_CH_Prescaler_None               ((uint32_t)0x0)  /*!< No division of input frequency. */
#define TIMER_CH_Prescaler_div_2              ((uint32_t)0x1)  /*!< Selects input frequency divider by 2. */
#define TIMER_CH_Prescaler_div_4              ((uint32_t)0x2)  /*!< Selects input frequency divider by 4. */
#define TIMER_CH_Prescaler_div_8              ((uint32_t)0x3)  /*!< Selects input frequency divider by 8. */

#define IS_TIMER_CHANNEL_PRESCALER(VALUE) (((VALUE) == TIMER_CH_Prescaler_None ) || \
                                           ((VALUE) == TIMER_CH_Prescaler_div_2) || \
                                           ((VALUE) == TIMER_CH_Prescaler_div_4) || \
                                           ((VALUE) == TIMER_CH_Prescaler_div_8))

/** @} */ /* End of group TIMER_CH_Prescaler */

/** @defgroup TIMER_CH_EventSource TIMER Channel Event Source
  * @{
  */

#define TIMER_CH_EvSrc_PE                     (((uint32_t)0x0) << TIMER_CH_CNTRL_CHSEL_Pos)  /*!< Selects positive edge from current TIMER channel. */
#define TIMER_CH_EvSrc_NE                     (((uint32_t)0x1) << TIMER_CH_CNTRL_CHSEL_Pos)  /*!< Selects negative edge from current TIMER channel. */
#define TIMER_CH_EvSrc_PE_OC1                 (((uint32_t)0x2) << TIMER_CH_CNTRL_CHSEL_Pos)  /*!< Selects positive edge from other TIMER channel (variant 1). */
#define TIMER_CH_EvSrc_PE_OC2                 (((uint32_t)0x3) << TIMER_CH_CNTRL_CHSEL_Pos)  /*!< Selects positive edge from other TIMER channel (variant 2). */

#define IS_TIMER_CHANNEL_EVENT_SOURCE(SOURCE) (((SOURCE) == TIMER_CH_EvSrc_PE    ) || \
                                               ((SOURCE) == TIMER_CH_EvSrc_NE    ) || \
                                               ((SOURCE) == TIMER_CH_EvSrc_PE_OC1) || \
                                               ((SOURCE) == TIMER_CH_EvSrc_PE_OC2))

/** @} */ /* End of group TIMER_CH_EventSource */

/** @defgroup TIMER_CH_CCR1_EventSource TIMER Channel CCR1 Event Source
  * @{
  */

#define TIMER_CH_CCR1EvSrc_PE                 (((uint32_t)0x0) << TIMER_CH_CNTRL2_CHSEL1_Pos)  /*!< Selects positive edge from current TIMER channel. */
#define TIMER_CH_CCR1EvSrc_NE                 (((uint32_t)0x1) << TIMER_CH_CNTRL2_CHSEL1_Pos)  /*!< Selects negative edge from current TIMER channel. */
#define TIMER_CH_CCR1EvSrc_NE_OC1             (((uint32_t)0x2) << TIMER_CH_CNTRL2_CHSEL1_Pos)  /*!< Selects negative edge from other TIMER channel (variant 1). */
#define TIMER_CH_CCR1EvSrc_NE_OC2             (((uint32_t)0x3) << TIMER_CH_CNTRL2_CHSEL1_Pos)  /*!< Selects negative edge from other TIMER channel (variant 2). */

#define IS_TIMER_CHANNEL_CCR1_EVENT_SOURCE(SOURCE) (((SOURCE) == TIMER_CH_CCR1EvSrc_PE    ) || \
                                                    ((SOURCE) == TIMER_CH_CCR1EvSrc_NE    ) || \
                                                    ((SOURCE) == TIMER_CH_CCR1EvSrc_NE_OC1) || \
                                                    ((SOURCE) == TIMER_CH_CCR1EvSrc_NE_OC2))

/** @} */ /* End of group TIMER_CH_CCR1_EventSource */

/** @defgroup TIMER_CH_CCR_Update_Mode TIMER CCR, CCR1 Update mode
  * @{
  */

#define TIMER_CH_CCR_Update_Immediately       (((uint32_t)0x0) << TIMER_CH_CNTRL2_CCRRLD_Pos)  /*!< The CCR, CCR1 registers is updated immediately. */
#define TIMER_CH_CCR_Update_On_CNT_eq_0       (((uint32_t)0x1) << TIMER_CH_CNTRL2_CCRRLD_Pos)  /*!< The CCR, CCR1 registers is updated at (CNT == 0) condition. */

#define IS_TIMER_CHANNEL_CCR_UPDATE_MODE(MODE) (((MODE) == TIMER_CH_CCR_Update_Immediately) || \
                                                ((MODE) == TIMER_CH_CCR_Update_On_CNT_eq_0))

/** @} */ /* End of group TIMER_CH_CCR_UpdateMode */

/** @defgroup TIMER_CH_OUT_Polarity TIMER Channel Output Polarity
  * @{
  */

#define TIMER_CHOPolarity_NonInverted         ((uint32_t)0x0)   /*!< No inversion on the Channel output. */
#define TIMER_CHOPolarity_Inverted            ((uint32_t)0x1)   /*!< The Channel output is inverted. */

#define IS_TIMER_CHO_POLARITY(STATE) (((STATE) == TIMER_CHOPolarity_NonInverted) || \
                                      ((STATE) == TIMER_CHOPolarity_Inverted   ))

/** @} */ /* End of group TIMER_CH_OUT_Polarity */

/** @defgroup TIMER_CH_OUT_Source TIMER Channel Output Source
  * @{
  */

#define TIMER_CH_OutSrc_Only_0                ((uint32_t)0x0)   /*!< Selects the '0' state on the CHx (or CHxN) line. */
#define TIMER_CH_OutSrc_Only_1                ((uint32_t)0x1)   /*!< Selects the '1' state on the CHx (or CHxN) line. */
#define TIMER_CH_OutSrc_REF                   ((uint32_t)0x2)   /*!< Selects the REF state on the CHx (or CHxN) line. */
#define TIMER_CH_OutSrc_DTG                   ((uint32_t)0x3)   /*!< Selects the DTG output state on the CHx (or CHxN) line. */

#define IS_TIMER_CHO_SOURCE(SOURCE) (((SOURCE) == TIMER_CH_OutSrc_Only_0) || \
                                     ((SOURCE) == TIMER_CH_OutSrc_Only_1) || \
                                     ((SOURCE) == TIMER_CH_OutSrc_REF   ) || \
                                     ((SOURCE) == TIMER_CH_OutSrc_DTG   ))

/** @} */ /* End of group TIMER_CH_OUT_Source */

/** @defgroup TIMER_CH_OUT_Mode TIMER Channel Output Enable Source
  * @{
  */

#define TIMER_CH_OutMode_Input                ((uint32_t)0x0)   /*!< Selects the Input mode on the CHx (or CHxN) line. */
#define TIMER_CH_OutMode_Output               ((uint32_t)0x1)   /*!< Selects the Output mode on the CHx (or CHxN) line. */
#define TIMER_CH_OutMode_REF_as_OE            ((uint32_t)0x2)   /*!< The REF signal specifies the CHx (or CHxN) line mode. */
#define TIMER_CH_OutMode_DTG_as_OE            ((uint32_t)0x3)   /*!< The DTG output specifies the CHx (or CHxN) line mode. */

#define IS_TIMER_CHO_MODE(MODE) (((MODE) == TIMER_CH_OutMode_Input    ) || \
                                 ((MODE) == TIMER_CH_OutMode_Output   ) || \
                                 ((MODE) == TIMER_CH_OutMode_REF_as_OE) || \
                                 ((MODE) == TIMER_CH_OutMode_DTG_as_OE))

/** @} */ /* End of group TIMER_CH_OUT_Mode */

/** @defgroup TIMER_CH_DTG_Prescaler TIMER Channel DTG Prescaler
  * @{
  */

#define IS_TIMER_CHANNEL_DTG_MAIN_PRESCALER(VALUE) (((VALUE) >> 8) == 0)

#define IS_TIMER_CHANNEL_DTG_AUX_PRESCALER(VALUE) (((VALUE) >> 4) == 0)

/** @} */ /* End of group TIMER_CH_DTG_Prescaler */

/** @defgroup TIMER_CH_DTG_Clock_Source TIMER Channel DTG Clock Source
  * @{
  */

#define TIMER_CH_DTG_ClkSrc_TIMER_CLK         (((uint32_t)0x0) << TIMER_CH_DTG_EDTS_Pos)  /*!< Specifies the TIMER_CLK signal as DTG clock source. */
#define TIMER_CH_DTG_ClkSrc_FDTS              (((uint32_t)0x1) << TIMER_CH_DTG_EDTS_Pos)  /*!< Specifies the FDTS signal as DTG clock source. */

#define IS_TIMER_CHANNEL_DTG_CLK_SOURCE(SOURCE) (((SOURCE) == TIMER_CH_DTG_ClkSrc_TIMER_CLK) || \
                                                 ((SOURCE) == TIMER_CH_DTG_ClkSrc_FDTS     ))

/** @} */ /* End of group TIMER_CH_DTG_Clock_Source */

/** @defgroup TIMER_StatusFlags TIMER Status flags
  * @{
  */

#define TIMER_STATUS_CNT_ZERO                 (((uint32_t)0x1) <<  0) /*!< The (CNT == 0) condition occured. */
#define TIMER_STATUS_CNT_ARR                  (((uint32_t)0x1) <<  1) /*!< The (CNT == ARR) condition occured. */
#define TIMER_STATUS_ETR_RISING_EDGE          (((uint32_t)0x1) <<  2) /*!< The ETR rising edge occured. */
#define TIMER_STATUS_ETR_FALLING_EDGE         (((uint32_t)0x1) <<  3) /*!< The ETR falling edge occured. */
#define TIMER_STATUS_BRK                      (((uint32_t)0x1) <<  4) /*!< The (BRK == 1) condition occured. */
#define TIMER_STATUS_CCR_CAP_CH1              (((uint32_t)0x1) <<  5) /*!< The Channel 1 CCR capture condition occured. */
#define TIMER_STATUS_CCR_CAP_CH2              (((uint32_t)0x1) <<  6) /*!< The Channel 2 CCR capture condition occured. */
#define TIMER_STATUS_CCR_CAP_CH3              (((uint32_t)0x1) <<  7) /*!< The Channel 3 CCR capture condition occured. */
#define TIMER_STATUS_CCR_CAP_CH4              (((uint32_t)0x1) <<  8) /*!< The Channel 4 CCR capture condition occured. */
#define TIMER_STATUS_CCR_REF_CH1              (((uint32_t)0x1) <<  9) /*!< The Channel 1 (REF == 1) condition occured. */
#define TIMER_STATUS_CCR_REF_CH2              (((uint32_t)0x1) << 10) /*!< The Channel 2 (REF == 1) condition occured. */
#define TIMER_STATUS_CCR_REF_CH3              (((uint32_t)0x1) << 11) /*!< The Channel 3 (REF == 1) condition occured. */
#define TIMER_STATUS_CCR_REF_CH4              (((uint32_t)0x1) << 12) /*!< The Channel 4 (REF == 1) condition occured. */
#define TIMER_STATUS_CCR_CAP1_CH1             (((uint32_t)0x1) << 13) /*!< The Channel 1 CCR1 capture condition occured. */
#define TIMER_STATUS_CCR_CAP1_CH2             (((uint32_t)0x1) << 14) /*!< The Channel 2 CCR1 capture condition occured. */
#define TIMER_STATUS_CCR_CAP1_CH3             (((uint32_t)0x1) << 15) /*!< The Channel 3 CCR1 capture condition occured. */
#define TIMER_STATUS_CCR_CAP1_CH4             (((uint32_t)0x1) << 16) /*!< The Channel 4 CCR1 capture condition occured. */

#define TIMER_STATUS_Msk                      (TIMER_STATUS_CNT_ZERO         | \
                                               TIMER_STATUS_CNT_ARR          | \
                                               TIMER_STATUS_ETR_RISING_EDGE  | \
                                               TIMER_STATUS_ETR_FALLING_EDGE | \
                                               TIMER_STATUS_BRK              | \
                                               TIMER_STATUS_CCR_CAP_CH1      | \
                                               TIMER_STATUS_CCR_CAP_CH2      | \
                                               TIMER_STATUS_CCR_CAP_CH3      | \
                                               TIMER_STATUS_CCR_CAP_CH4      | \
                                               TIMER_STATUS_CCR_REF_CH1      | \
                                               TIMER_STATUS_CCR_REF_CH2      | \
                                               TIMER_STATUS_CCR_REF_CH3      | \
                                               TIMER_STATUS_CCR_REF_CH4      | \
                                               TIMER_STATUS_CCR_CAP1_CH1     | \
                                               TIMER_STATUS_CCR_CAP1_CH2     | \
                                               TIMER_STATUS_CCR_CAP1_CH3     | \
                                               TIMER_STATUS_CCR_CAP1_CH4)

#define IS_TIMER_STATUS_FLAG(FLAG) (((FLAG) == TIMER_STATUS_CNT_ZERO        ) || \
                                    ((FLAG) == TIMER_STATUS_CNT_ARR         ) || \
                                    ((FLAG) == TIMER_STATUS_ETR_RISING_EDGE ) || \
                                    ((FLAG) == TIMER_STATUS_ETR_FALLING_EDGE) || \
                                    ((FLAG) == TIMER_STATUS_BRK             ) || \
                                    ((FLAG) == TIMER_STATUS_CCR_CAP_CH1     ) || \
                                    ((FLAG) == TIMER_STATUS_CCR_CAP_CH2     ) || \
                                    ((FLAG) == TIMER_STATUS_CCR_CAP_CH3     ) || \
                                    ((FLAG) == TIMER_STATUS_CCR_CAP_CH4     ) || \
                                    ((FLAG) == TIMER_STATUS_CCR_REF_CH1     ) || \
                                    ((FLAG) == TIMER_STATUS_CCR_REF_CH2     ) || \
                                    ((FLAG) == TIMER_STATUS_CCR_REF_CH3     ) || \
                                    ((FLAG) == TIMER_STATUS_CCR_REF_CH4     ) || \
                                    ((FLAG) == TIMER_STATUS_CCR_CAP1_CH1    ) || \
                                    ((FLAG) == TIMER_STATUS_CCR_CAP1_CH2    ) || \
                                    ((FLAG) == TIMER_STATUS_CCR_CAP1_CH3    ) || \
                                    ((FLAG) == TIMER_STATUS_CCR_CAP1_CH4    ))

#define IS_TIMER_STATUS(STATUS) (((STATUS) & TIMER_STATUS_Msk) == (STATUS))

/** @} */ /* End of group TIMER_StatusFlags */

/** @defgroup TIMER_DMAChannels TIMER DMAChannels
  * @{
  */
/** @note Available only for MC MDR1986VE1T and MC MDR1986BE3 */

#define TIMER_DMA_Channel0					((uint32_t)0x00000004)
#define TIMER_DMA_Channel1					((uint32_t)0x00000000)
#define TIMER_DMA_Channel2					((uint32_t)0x00000001)
#define TIMER_DMA_Channel3					((uint32_t)0x00000002)
#define TIMER_DMA_Channel4					((uint32_t)0x00000003)

#define IS_TIMER_DMA_Channel(DMA_Channel)	((DMA_Channel == TIMER_DMA_Channel0) ||\
											 (DMA_CHannel == TIMER_DMA_Channel1) ||\
											 (DMA_CHannel == TIMER_DMA_Channel2) ||\
											 (DMA_CHannel == TIMER_DMA_Channel3) ||\
											 (DMA_CHannel == TIMER_DMA_Channel4))

/** @} */ /* End of group TIMER_DMAChannels */

/** @defgroup TIMER_Clock_BRG TIMER Clock BRG
  * @{
  */

#define TIMER_HCLKdiv1                        ((uint32_t)0x0)
#define TIMER_HCLKdiv2                        ((uint32_t)0x1)
#define TIMER_HCLKdiv4                        ((uint32_t)0x2)
#define TIMER_HCLKdiv8                        ((uint32_t)0x3)
#define TIMER_HCLKdiv16                       ((uint32_t)0x4)
#define TIMER_HCLKdiv32                       ((uint32_t)0x5)
#define TIMER_HCLKdiv64                       ((uint32_t)0x6)
#define TIMER_HCLKdiv128                      ((uint32_t)0x7)

#define IS_TIMER_CLOCK_BRG(BRG) (((BRG) == TIMER_HCLKdiv1  ) || \
                                 ((BRG) == TIMER_HCLKdiv2  ) || \
                                 ((BRG) == TIMER_HCLKdiv4  ) || \
                                 ((BRG) == TIMER_HCLKdiv8  ) || \
                                 ((BRG) == TIMER_HCLKdiv16 ) || \
                                 ((BRG) == TIMER_HCLKdiv32 ) || \
                                 ((BRG) == TIMER_HCLKdiv64 ) || \
                                 ((BRG) == TIMER_HCLKdiv128))
																 
#define TIM_DIV_Msk        								 ((uint32_t)0x0000FFFF)
#define TIM_CLK_EN         								 (1<<16)

#define TIM_CLKdiv1                        ((uint32_t)0x00000000)
#define TIM_CLKdiv2                        ((uint32_t)0x00000001)
#define TIM_CLKdiv4                        ((uint32_t)0x00000002)
#define TIM_CLKdiv8                        ((uint32_t)0x00000003)

#define TIM0                    0
#define TIM1                    1
#define TIM2                    2
#define TIM3                    3
#define TIM4                    4

/** @} */ /* End of group TIMER_Clock_BRG */

/** @} */ /* End of group TIMER_Exported_Constants */

/** @defgroup TIMER_Exported_Macros TIMER Exported Macros
  * @{
  */

/**
  * @brief  Clears the TIMERx's interrupt pending (TIMERx's Status) bits.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  TIMER_IT: specifies the pending bit to clear.
  *         This parameter can be any combination of the TIMER_StatusFlags:
  *           @arg TIMER_STATUS_CNT_ZERO:         the (CNT == 0) condition occured;
  *           @arg TIMER_STATUS_CNT_ARR:          the (CNT == ARR) condition occured;
  *           @arg TIMER_STATUS_ETR_RISING_EDGE:  the ETR rising edge occured;
  *           @arg TIMER_STATUS_ETR_FALLING_EDGE: the ETR falling edge occured;
  *           @arg TIMER_STATUS_BRK:              the (BRK == 1) condition occured;
  *           @arg TIMER_STATUS_CCR_CAP_CH1:      the Channel 1 CCR capture condition occured;
  *           @arg TIMER_STATUS_CCR_CAP_CH2:      the Channel 2 CCR capture condition occured;
  *           @arg TIMER_STATUS_CCR_CAP_CH3:      the Channel 3 CCR capture condition occured;
  *           @arg TIMER_STATUS_CCR_CAP_CH4:      the Channel 4 CCR capture condition occured;
  *           @arg TIMER_STATUS_CCR_REF_CH1:      the Channel 1 (REF == 1) condition occured;
  *           @arg TIMER_STATUS_CCR_REF_CH2:      the Channel 2 (REF == 1) condition occured;
  *           @arg TIMER_STATUS_CCR_REF_CH3:      the Channel 3 (REF == 1) condition occured;
  *           @arg TIMER_STATUS_CCR_REF_CH4:      the Channel 4 (REF == 1) condition occured;
  *           @arg TIMER_STATUS_CCR_CAP1_CH1:     the Channel 1 CCR1 capture condition occured;
  *           @arg TIMER_STATUS_CCR_CAP1_CH2:     the Channel 2 CCR1 capture condition occured;
  *           @arg TIMER_STATUS_CCR_CAP1_CH3:     the Channel 3 CCR1 capture condition occured;
  *           @arg TIMER_STATUS_CCR_CAP1_CH4:     the Channel 4 CCR1 capture condition occured.
  * @retval None
  */
#define TIMER_ClearITPendingBit(TIMERx, TIMER_IT) TIMER_ClearFlag(TIMERx, TIMER_IT)

/** @} */ /* End of group TIMER_Exported_Macros */

/** @defgroup TIMER_Exported_Functions TIMER Exported Functions
  * @{
  */

void TIMER_DeInit(MDR_TMR_TypeDef* TIMERx);

void TIMER_CntInit(MDR_TMR_TypeDef* TIMERx, const TIMER_CntInitTypeDef* TIMER_CntInitStruct);
void TIMER_CntStructInit(TIMER_CntInitTypeDef* TIMER_CntInitStruct);

void TIMER_Cmd(MDR_TMR_TypeDef* TIMERx, FunctionalState NewState);

#if defined (USE_MDR1986VE1T) || defined (USE_MDR1986VE3)
	void TIMER_SetCounter(MDR_TIMER_TypeDef* TIMERx, uint32_t Counter);
#elif defined (USE_MDR1986VE9x)
	void TIMER_SetCounter(MDR_TMR_TypeDef* TIMERx, uint16_t Counter);
#endif

void TIMER_SetCntPrescaler(MDR_TMR_TypeDef* TIMERx, uint16_t Prescaler);
#if defined (USE_MDR1986VE1T) || defined (USE_MDR1986VE3)
	void TIMER_SetCntAutoreload(MDR_TIMER_TypeDef* TIMERx, uint32_t Autoreload);
#elif defined (USE_MDR1986VE9x)
	void TIMER_SetCntAutoreload(MDR_TMR_TypeDef* TIMERx, uint16_t Autoreload);
#endif
#if defined (USE_MDR1986VE1T) || defined (USE_MDR1986VE3)
	void TIMER_CntAutoreloadConfig(MDR_TIMER_TypeDef* TIMERx, uint32_t Autoreload, uint32_t UpdateMode);
#elif defined (USE_MDR1986VE9x)
	void TIMER_CntAutoreloadConfig(MDR_TMR_TypeDef* TIMERx, uint16_t Autoreload, uint32_t UpdateMode);
#endif

#if defined (USE_MDR1986VE1T) || defined (USE_MDR1986VE3)
	uint32_t TIMER_GetCounter(MDR_TIMER_TypeDef* TIMERx);
#elif defined (USE_MDR1986VE9x)
	uint16_t TIMER_GetCounter(MDR_TMR_TypeDef* TIMERx);
#endif

void TIMER_CntEventSourceConfig(MDR_TMR_TypeDef* TIMERx, uint32_t EventSource);
void TIMER_FilterSamplingConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Prescaler);
void TIMER_CounterModeConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Mode);
void TIMER_SetCounterDirection(MDR_TMR_TypeDef* TIMERx, uint32_t Direction);
void TIMER_ETRInputConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Prescaler, uint32_t Polarity, uint32_t Filter);
void TIMER_ETRFilterConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Filter);
void TIMER_ETRPrescalerConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Prescaler);
void TIMER_ETRPolarityConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Polarity);
void TIMER_BRKPolarityConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Polarity);
uint32_t TIMER_GetCounterDirection(MDR_TMR_TypeDef* TIMERx);
FlagStatus TIMER_GetCntWriteComplete(MDR_TMR_TypeDef* TIMERx);

void TIMER_ChnInit(MDR_TMR_TypeDef* TIMERx, const TIMER_ChnInitTypeDef* TIMER_ChnInitStruct);
void TIMER_ChnStructInit(TIMER_ChnInitTypeDef* TIMER_ChnInitStruct);

#if defined (USE_MDR1986VE1T) || defined (USE_MDR1986VE3)
	void TIMER_SetChnCompare(MDR_TIMER_TypeDef* TIMERx, uint32_t Channel, uint32_t Compare);
#elif defined (USE_MDR1986VE9x)
	void TIMER_SetChnCompare(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, uint16_t Compare);
#endif

#if defined (USE_MDR1986VE1T) || defined (USE_MDR1986VE3)
	void TIMER_SetChnCompare1(MDR_TIMER_TypeDef* TIMERx, uint32_t Channel, uint32_t Compare);
#elif defined (USE_MDR1986VE9x)
	void TIMER_SetChnCompare1(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, uint16_t Compare);
#endif

#if defined (USE_MDR1986VE1T) || defined (USE_MDR1986VE3)
	void TIMER_ChnCompareConfig(MDR_TIMER_TypeDef* TIMERx, uint32_t Channel, uint32_t Compare, uint32_t UpdateMode);
#elif defined (USE_MDR1986VE9x)
	void TIMER_ChnCompareConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, uint16_t Compare, uint32_t UpdateMode);
#endif

#if defined (USE_MDR1986VE1T) || defined (USE_MDR1986VE3)
	void TIMER_ChnCompare1Config(MDR_TIMER_TypeDef* TIMERx, uint32_t Channel, uint32_t Compare, uint32_t UpdateMode);
#elif defined (USE_MDR1986VE9x)
	void TIMER_ChnCompare1Config(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, uint16_t Compare, uint32_t UpdateMode);
#endif

#if defined (USE_MDR1986VE1T) || defined (USE_MDR1986VE3)
	uint32_t TIMER_GetChnCapture(MDR_TIMER_TypeDef* TIMERx, uint32_t Channel);
#elif defined (USE_MDR1986VE9x)
	uint16_t TIMER_GetChnCapture(MDR_TMR_TypeDef* TIMERx, uint32_t Channel);
#endif

#if defined (USE_MDR1986VE1T) || defined (USE_MDR1986VE3)
	uint32_t TIMER_GetChnCapture1(MDR_TIMER_TypeDef* TIMERx, uint32_t Channel);
#elif defined (USE_MDR1986VE9x)
	uint16_t TIMER_GetChnCapture1(MDR_TMR_TypeDef* TIMERx, uint32_t Channel);
#endif

void TIM_CLK_en(uint32_t TIMx, uint32_t TIM_CLK_DIV);
void  TIMER_BRGInit (MDR_TMR_TypeDef* TIMERx, uint32_t TIM_CLK_DIV);

void TIMER_ChnETR_Cmd(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, FunctionalState NewState);
void TIMER_ChnETRResetConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, uint32_t NewState);
void TIMER_ChnBRKResetConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, uint32_t NewState);
void TIMER_ChnREFFormatConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, uint32_t Format);
void TIMER_ChnCapturePrescalerConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, uint32_t Prescaler);
void TIMER_ChnEventSourceConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, uint32_t EventSource);
void TIMER_ChnFilterConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, uint32_t Filter);
FlagStatus TIMER_GetChnWriteComplete(MDR_TMR_TypeDef* TIMERx, uint32_t Channel);
void TIMER_ChnCCR1_EventSourceConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, uint32_t EventSource);
void TIMER_ChnCCR1_Cmd(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, FunctionalState NewState);

void TIMER_ChnOutInit(MDR_TMR_TypeDef* TIMERx, const TIMER_ChnOutInitTypeDef* TIMER_ChnOutInitStruct);
void TIMER_ChnOutStructInit(TIMER_ChnOutInitTypeDef* TIMER_ChnOutInitStruct);
void TIMER_ChnOutConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, uint32_t OutSource, uint32_t Mode, uint32_t Polarity);
void TIMER_ChnOutSourceConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, uint32_t OutSource);
void TIMER_ChnOutModeConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, uint32_t Mode);
void TIMER_ChnOutPolarityConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, uint32_t Polarity);
void TIMER_ChnNOutConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, uint32_t OutSource, uint32_t Mode, uint32_t Polarity);
void TIMER_ChnNOutSourceConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, uint32_t OutSource);
void TIMER_ChnNOutModeConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, uint32_t Mode);
void TIMER_ChnNOutPolarityConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, uint32_t Polarity);
void TIMER_ChnOutDTGConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Channel,
                         uint32_t MainPrescaler, uint32_t AuxPrescaler, uint32_t ClockSource);

uint32_t TIMER_GetStatus(MDR_TMR_TypeDef* TIMERx);
FlagStatus TIMER_GetFlagStatus(MDR_TMR_TypeDef* TIMERx, uint32_t Flag);
void TIMER_ClearFlag(MDR_TMR_TypeDef* TIMERx, uint32_t Flags);
#if defined (USE_MDR1986VE1T) || defined (USE_MDR1986VE3)
void TIMER_DMACmd(MDR_TIMER_TypeDef* TIMERx, uint32_t TIMER_DMASource, uint32_t TIMER_DMAChannel, FunctionalState NewState);
#endif
#if defined (USE_MDR1986VE9x)
void TIMER_DMACmd(MDR_TMR_TypeDef* TIMERx, uint32_t TIMER_DMASource, FunctionalState NewState);
#endif

void TIMER_ITConfig(MDR_TMR_TypeDef* TIMERx, uint32_t TIMER_IT, FunctionalState NewState);
ITStatus TIMER_GetITStatus(MDR_TMR_TypeDef* TIMERx, uint32_t TIMER_IT);
void TIMER_BRGInit(MDR_TMR_TypeDef* TIMERx, uint32_t TIMER_BRG);

/** @} */ /* End of group TIMER_Exported_Functions */

/** @} */ /* End of group TIMER */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

#ifdef __cplusplus
} // extern "C" block end
#endif

#endif /* __MDR32F9QX_TIMER_H */

/******************* (C) COPYRIGHT 2010 Phyton *********************************
*
* END OF FILE MDR32F9Qx_timer.h */
