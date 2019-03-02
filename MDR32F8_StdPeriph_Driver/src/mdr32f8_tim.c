/**
  ******************************************************************************
  * @file    MDR32F9Qx_timer.c
  * @author  Phyton Application Team
  * @version V1.4.0
  * @date    22/02/2011
  * @brief   This file provides all the TIMER firmware functions.
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
  * FILE MDR32F9Qx_timer.c
  */

/* Includes ------------------------------------------------------------------*/
#include "mdr32f8_tim.h"
#include "mdr32f8_clkctrl.h"
#include "MDR1986VE8T.h"

#define ASSERT_INFO_FILE_ID FILEID__MDR32F9X_TIMER_C

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @defgroup TIMER TIMER
  * @{
  */

/** @defgroup TIMER_Private_Functions TIMER Private Functions
  * @{
  */

/**
  * @brief  Deinitializes the TIMERx peripheral registers to their default reset values.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @retval None
  */
void TIMER_DeInit ( MDR_TMR_TypeDef* TIMERx ) {
	/* Check the parameters */
	assert_param(IS_TIMER_ALL_PERIPH(TIMERx));

	TIMERx->CNTRL = 0;
	TIMERx->CNT = 0;
	TIMERx->PSG = 0;
	TIMERx->ARR = 0;

	TIMERx->CH1_CNTRL = 0;
	TIMERx->CH2_CNTRL = 0;
	TIMERx->CH3_CNTRL = 0;
	TIMERx->CH4_CNTRL = 0;
	TIMERx->CH1_CNTRL1 = 0;
	TIMERx->CH2_CNTRL1 = 0;
	TIMERx->CH3_CNTRL1 = 0;
	TIMERx->CH4_CNTRL1 = 0;
	TIMERx->CH1_CNTRL2 = 0;
	TIMERx->CH2_CNTRL2 = 0;
	TIMERx->CH3_CNTRL2 = 0;
	TIMERx->CH4_CNTRL2 = 0;

	TIMERx->CCR1 = 0;
	TIMERx->CCR2 = 0;
	TIMERx->CCR3 = 0;
	TIMERx->CCR4 = 0;
	TIMERx->CCR11 = 0;
	TIMERx->CCR21 = 0;
	TIMERx->CCR31 = 0;
	TIMERx->CCR41 = 0;
	TIMERx->CH1_DTG = 0;
	TIMERx->CH2_DTG = 0;
	TIMERx->CH3_DTG = 0;
	TIMERx->CH4_DTG = 0;
	TIMERx->BRKETR_CNTRL = 0;
	TIMERx->STATUS = 0;
	TIMERx->IE = 0;
	TIMERx->DMA_RE = 0;
#if defined(USE_MDR1986VE3) || defined (USE_MDR1986VE1T) /* For Cortex M1 */
	TIMERx->DMA_REChx[0] = TIMERx->DMA_REChx[1] =
			TIMERx->DMA_REChx[2] = TIMERx->DMA_REChx[3] = 0;
#endif
}

/**
  * @brief  Initializes the TIMERx Counter peripheral according to
  *         the specified parameters in the TIMER_CntInitStruct.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  TIMER_CntInitStruct: pointer to a TIMER_CntInitTypeDef structure
  *         that contains the configuration information for the specified TIMER
  *         peripheral.
  * @retval None
  */
void TIMER_CntInit(MDR_TMR_TypeDef* TIMERx, const TIMER_CntInitTypeDef* TIMER_CntInitStruct)
{
  uint32_t tmpreg_CNTRL;
  uint32_t tmpreg_BRKETR_CNTRL;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_COUNTER_MODE(TIMER_CntInitStruct->TIMER_CounterMode));
  assert_param(IS_TIMER_COUNTER_DIR(TIMER_CntInitStruct->TIMER_CounterDirection));
  assert_param(IS_TIMER_EVENT_SOURCE(TIMER_CntInitStruct->TIMER_EventSource));
  assert_param(IS_TIMER_FILTER_SAMPLING(TIMER_CntInitStruct->TIMER_FilterSampling));
  assert_param(IS_TIMER_ARR_UPDATE_MODE(TIMER_CntInitStruct->TIMER_ARR_UpdateMode));
  assert_param(IS_TIMER_FILTER_CONF(TIMER_CntInitStruct->TIMER_ETR_FilterConf));
  assert_param(IS_TIMER_ETR_PRESCALER(TIMER_CntInitStruct->TIMER_ETR_Prescaler));
  assert_param(IS_TIMER_ETR_POLARITY(TIMER_CntInitStruct->TIMER_ETR_Polarity));
  assert_param(IS_TIMER_BRK_POLARITY(TIMER_CntInitStruct->TIMER_BRK_Polarity));

  TIMERx->CNT = TIMER_CntInitStruct->TIMER_IniCounter;
  TIMERx->PSG = TIMER_CntInitStruct->TIMER_Prescaler;
  TIMERx->ARR = TIMER_CntInitStruct->TIMER_Period;

  /* Form new value for the TIMERx_CNTRL register */
  tmpreg_CNTRL = TIMER_CntInitStruct->TIMER_CounterMode
               + TIMER_CntInitStruct->TIMER_CounterDirection
               + TIMER_CntInitStruct->TIMER_EventSource
               + TIMER_CntInitStruct->TIMER_FilterSampling
               + TIMER_CntInitStruct->TIMER_ARR_UpdateMode;

  /* Configure TIMERx_CNTRL register with new value */
  TIMERx->CNTRL = tmpreg_CNTRL;

  /* Form new value for the TIMERx_BRKETR_CNTRL register */
  tmpreg_BRKETR_CNTRL = (TIMER_CntInitStruct->TIMER_ETR_FilterConf << TIMER_BRKETR_CNTRL_ETR_FILTER_Pos)
                      + TIMER_CntInitStruct->TIMER_ETR_Prescaler
                      + TIMER_CntInitStruct->TIMER_ETR_Polarity
                      + TIMER_CntInitStruct->TIMER_BRK_Polarity;

  /* Configure TIMERx_BRKETR_CNTRL register with new value */
  TIMERx->BRKETR_CNTRL = tmpreg_BRKETR_CNTRL;
}


/**
  * @brief  Fills each TIMER_CntInitStruct member with its default value.
  * @param  TIMER_CntInitStruct: pointer to a TIMER_CntInitTypeDef structure
  *         which will be initialized.
  * @retval None
  */
void TIMER_CntStructInit(TIMER_CntInitTypeDef* TIMER_CntInitStruct)
{
  TIMER_CntInitStruct->TIMER_IniCounter = 0;
  TIMER_CntInitStruct->TIMER_Prescaler  = 0;
  TIMER_CntInitStruct->TIMER_Period     = 0;
  TIMER_CntInitStruct->TIMER_CounterMode      = TIMER_CntMode_ClkFixedDir;
  TIMER_CntInitStruct->TIMER_CounterDirection = TIMER_CntDir_Up;
  TIMER_CntInitStruct->TIMER_EventSource      = TIMER_EvSrc_None;
  TIMER_CntInitStruct->TIMER_FilterSampling   = TIMER_FDTS_TIMER_CLK_div_1;
  TIMER_CntInitStruct->TIMER_ARR_UpdateMode   = TIMER_ARR_Update_Immediately;
  TIMER_CntInitStruct->TIMER_ETR_FilterConf   = TIMER_Filter_1FF_at_TIMER_CLK;
  TIMER_CntInitStruct->TIMER_ETR_Prescaler    = TIMER_ETR_Prescaler_None;
  TIMER_CntInitStruct->TIMER_ETR_Polarity     = TIMER_ETRPolarity_NonInverted;
  TIMER_CntInitStruct->TIMER_BRK_Polarity     = TIMER_BRKPolarity_NonInverted;
}

/**
  * @brief  Enables or disables the specified TIMER peripheral.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMERx peripheral.
  * @param  NewState: new state of the TIMERx peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void TIMER_Cmd(MDR_TMR_TypeDef* TIMERx, FunctionalState NewState)
{
  uint32_t tmpreg_CNTRL;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  tmpreg_CNTRL = TIMERx->CNTRL;

  /* Form new value */
  if (NewState != DISABLE)
  {
    /* Enable TIMERx by setting the CNT_EN bit in the CNTRL register */
    tmpreg_CNTRL |= TIMER_CNTRL_CNT_EN;
  }
  else
  {
    /* Disable TIMERx by resetting the CNT_EN bit in the CNTRL register */
    tmpreg_CNTRL &= ~TIMER_CNTRL_CNT_EN;
  }

  /* Configure CNTRL register with new value */
  TIMERx->CNTRL = tmpreg_CNTRL;
}

/**
  * @brief  Sets the TIMERx Counter Register value.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  Counter: specifies the Counter register new value.
  * @retval None
  */
#if defined (USE_MDR1986VE1T) || defined (USE_MDR1986VE3)
void TIMER_SetCounter(MDR_TIMER_TypeDef* TIMERx, uint32_t Counter)
#elif defined (USE_MDR1986VE9x)
void TIMER_SetCounter(MDR_TMR_TypeDef* TIMERx, uint16_t Counter)
#endif
{
  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));

  TIMERx->CNT = Counter;
}

/**
  * @brief  Sets the TIMERx Prescaler.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  Prescaler: specifies the Prescaler Register value.
  * @retval None
  */
void TIMER_SetCntPrescaler(MDR_TMR_TypeDef* TIMERx, uint16_t Prescaler)
{
  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));

  TIMERx->PSG = Prescaler;
}

/**
  * @brief  Sets the TIMERx Autoreload Register value.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  Autoreload: specifies the Autoreload Register value.
  * @retval None
  */
#if defined (USE_MDR1986VE1T) || defined (USE_MDR1986VE3)
void TIMER_SetCntAutoreload(MDR_TIMER_TypeDef* TIMERx, uint32_t Autoreload)
#elif defined (USE_MDR1986VE9x)
void TIMER_SetCntAutoreload(MDR_TMR_TypeDef* TIMERx, uint16_t Autoreload)
#endif
{
  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));

  TIMERx->ARR = Autoreload;
}

/**
  * @brief  Sets the TIMERx Autoreload Register value.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  Autoreload: specifies the Autoreload Register value.
  * @param  UpdateMode: specifies the Autoreload Register Update mode.
  *         This parameter can be one of the following values:
  *           @arg TIMER_ARR_Update_Immediately:     the ARR register is updated immediately;
  *           @arg TIMER_ARR_Update_On_CNT_Overflow: the ARR register is updated at CNT count end.
  * @retval None
  */
#if defined (USE_MDR1986VE1T) || defined (USE_MDR1986VE3)
void TIMER_CntAutoreloadConfig(MDR_TIMER_TypeDef* TIMERx, uint32_t Autoreload, uint32_t UpdateMode)
#elif defined (USE_MDR1986VE9x)
void TIMER_CntAutoreloadConfig(MDR_TMR_TypeDef* TIMERx, uint16_t Autoreload, uint32_t UpdateMode)
#endif
{
  uint32_t tmpreg_CNTRL;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_ARR_UPDATE_MODE(UpdateMode));

  tmpreg_CNTRL = TIMERx->CNTRL;
  tmpreg_CNTRL &= ~TIMER_CNTRL_ARRB_EN;
  tmpreg_CNTRL += UpdateMode;
  TIMERx->CNTRL = tmpreg_CNTRL;

  TIMERx->ARR = Autoreload;
}

/**
  * @brief  Returns the TIMERx Counter value.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @retval Counter Register value.
  */
#if defined (USE_MDR1986VE1T) || defined (USE_MDR1986VE3)
uint32_t TIMER_GetCounter(MDR_TIMER_TypeDef* TIMERx)
#elif defined (USE_MDR1986VE9x)
uint16_t TIMER_GetCounter(MDR_TMR_TypeDef* TIMERx)
#endif
{
  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));

  return TIMERx->CNT;
}

/**
  * @brief  Configures the TIMERx Counter Event source.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  EventSource: specifies the Event source.
  *         This parameter can be one of the following values:
  *           @arg TIMER_EvSrc_None: no events;
  *           @arg TIMER_EvSrc_TM1:  selects TIMER1 (CNT == ARR) event;
  *           @arg TIMER_EvSrc_TM2:  selects TIMER2 (CNT == ARR) event;
  *           @arg TIMER_EvSrc_TM3:  selects TIMER3 (CNT == ARR) event;
  *           @arg TIMER_EvSrc_CH1:  selects Channel 1 event;
  *           @arg TIMER_EvSrc_CH2:  selects Channel 2 event;
  *           @arg TIMER_EvSrc_CH3:  selects Channel 3 event;
  *           @arg TIMER_EvSrc_CH4:  selects Channel 4 event;
  *           @arg TIMER_EvSrc_ETR:  selects ETR event.
  * @retval None
  */
void TIMER_CntEventSourceConfig(MDR_TMR_TypeDef* TIMERx, uint32_t EventSource)
{
  uint32_t tmpreg_CNTRL;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_EVENT_SOURCE(EventSource));

  tmpreg_CNTRL = TIMERx->CNTRL;
  tmpreg_CNTRL &= ~TIMER_CNTRL_EVENT_SEL_Msk;
  tmpreg_CNTRL += EventSource;
  TIMERx->CNTRL = tmpreg_CNTRL;
}

/**
  * @brief  Configures the TIMERx Filter Sampling clock.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  Prescaler: specifies the Filter Sampling clock.
  *         This parameter can be one of the following values:
  *           @arg TIMER_FDTS_TIMER_CLK_div_1: the FDTS clock occures each TIMER_CLK clock;
  *           @arg TIMER_FDTS_TIMER_CLK_div_2: the FDTS clock occures each 2-nd TIMER_CLK clock;
  *           @arg TIMER_FDTS_TIMER_CLK_div_3: the FDTS clock occures each 3-rd TIMER_CLK clock;
  *           @arg TIMER_FDTS_TIMER_CLK_div_4: the FDTS clock occures each 4-th TIMER_CLK clock.
  * @retval None
  */
void TIMER_FilterSamplingConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Prescaler)
{
  uint32_t tmpreg_CNTRL;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_FILTER_SAMPLING(Prescaler));

  tmpreg_CNTRL = TIMERx->CNTRL;
  tmpreg_CNTRL &= ~TIMER_CNTRL_FDTS_Msk;
  tmpreg_CNTRL += Prescaler;
  TIMERx->CNTRL = tmpreg_CNTRL;
}

/**
  * @brief  Configures the TIMERx count mode.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  Mode: specifies the Timer count mode.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CntMode_ClkFixedDir:  The Timer clock changes the TIMERx_CNT value. The count direction is not changed.
  *           @arg TIMER_CntMode_ClkChangeDir: The Timer clock changes the TIMERx_CNT value. The count direction changes.
  *           @arg TIMER_CntMode_EvtFixedDir:  The event changes the TIMERx_CNT value. The count direction is not changed.
  *           @arg TIMER_CntMode_EvtChangeDir: The event changes the TIMERx_CNT value. The count direction changes.
  * @retval None
  */
void TIMER_CounterModeConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Mode)
{
  uint32_t tmpreg_CNTRL;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_COUNTER_MODE(Mode));

  tmpreg_CNTRL = TIMERx->CNTRL;
  tmpreg_CNTRL &= ~TIMER_CNTRL_CNT_MODE_Msk;
  tmpreg_CNTRL += Mode;
  TIMERx->CNTRL = tmpreg_CNTRL;
}

/**
  * @brief  Configures the TIMERx count direction.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  Direction: specifies the Timer count direction.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CntDir_Up: increments the Timer TIMERx_CNT counter value;
  *           @arg TIMER_CntDir_Dn: decrements the Timer TIMERx_CNT counter value.
  * @retval None
  */
void TIMER_SetCounterDirection(MDR_TMR_TypeDef* TIMERx, uint32_t Direction)
{
  uint32_t tmpreg_CNTRL;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_COUNTER_DIR(Direction));

  tmpreg_CNTRL = TIMERx->CNTRL;
  tmpreg_CNTRL &= ~TIMER_CNTRL_DIR;
  tmpreg_CNTRL += Direction;
  TIMERx->CNTRL = tmpreg_CNTRL;
}

/**
  * @brief  Configures the TIMERx count direction.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  Prescaler: specifies the ETR signal prescaler value.
  *         This parameter can be one of the following values:
  *           @arg TIMER_ETR_Prescaler_None : no division of input frequency;
  *           @arg TIMER_ETR_Prescaler_div_2: selects input frequency divider by 2;
  *           @arg TIMER_ETR_Prescaler_div_4: selects input frequency divider by 4;
  *           @arg TIMER_ETR_Prescaler_div_8: selects input frequency divider by 8.
  * @param  Polarity: enables or disables inversion on ETR input.
  *         This parameter can be one of the following values:
  *           @arg TIMER_ETRPolarity_NonInverted: no inversion of the ETR input;
  *           @arg TIMER_ETRPolarity_Inverted:    the ETR input is inverted.
  * @param  Filter: specifies the ETR Filter configuration.
  *         This parameter can be one of the following values:
  *           @arg TIMER_Filter_1FF_at_TIMER_CLK:   signal is latched by 1 trigger  at TIMER_CLK clock frequency;
  *           @arg TIMER_Filter_2FF_at_TIMER_CLK:   signal is latched by 2 triggers at TIMER_CLK clock frequency;
  *           @arg TIMER_Filter_4FF_at_TIMER_CLK:   signal is latched by 4 triggers at TIMER_CLK clock frequency;
  *           @arg TIMER_Filter_8FF_at_TIMER_CLK:   signal is latched by 8 triggers at TIMER_CLK clock frequency;
  *           @arg TIMER_Filter_6FF_at_FTDS_div_2:  signal is latched by 6 triggers at FDTS/2  clock frequency;
  *           @arg TIMER_Filter_8FF_at_FTDS_div_2:  signal is latched by 8 triggers at FDTS/2  clock frequency;
  *           @arg TIMER_Filter_6FF_at_FTDS_div_4:  signal is latched by 6 triggers at FDTS/4  clock frequency;
  *           @arg TIMER_Filter_8FF_at_FTDS_div_4:  signal is latched by 8 triggers at FDTS/4  clock frequency;
  *           @arg TIMER_Filter_6FF_at_FTDS_div_8:  signal is latched by 6 triggers at FDTS/8  clock frequency;
  *           @arg TIMER_Filter_8FF_at_FTDS_div_8:  signal is latched by 8 triggers at FDTS/8  clock frequency;
  *           @arg TIMER_Filter_5FF_at_FTDS_div_16: signal is latched by 5 triggers at FDTS/16 clock frequency;
  *           @arg TIMER_Filter_6FF_at_FTDS_div_16: signal is latched by 6 triggers at FDTS/16 clock frequency;
  *           @arg TIMER_Filter_8FF_at_FTDS_div_16: signal is latched by 8 triggers at FDTS/16 clock frequency;
  *           @arg TIMER_Filter_5FF_at_FTDS_div_32: signal is latched by 5 triggers at FDTS/32 clock frequency;
  *           @arg TIMER_Filter_6FF_at_FTDS_div_32: signal is latched by 6 triggers at FDTS/32 clock frequency;
  *           @arg TIMER_Filter_8FF_at_FTDS_div_32: signal is latched by 8 triggers at FDTS/32 clock frequency.
  * @retval None
  */
void TIMER_ETRInputConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Prescaler, uint32_t Polarity, uint32_t Filter)
{
  uint32_t tmpreg_BRKETR_CNTRL;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_ETR_PRESCALER(Prescaler));
  assert_param(IS_TIMER_ETR_POLARITY(Polarity));
  assert_param(IS_TIMER_FILTER_CONF(Filter));

  tmpreg_BRKETR_CNTRL = TIMERx->BRKETR_CNTRL;
  tmpreg_BRKETR_CNTRL &= ~(TIMER_BRKETR_CNTRL_ETR_PSC_Msk + TIMER_BRKETR_CNTRL_ETR_INV + TIMER_BRKETR_CNTRL_ETR_FILTER_Msk);
  tmpreg_BRKETR_CNTRL += Prescaler + Polarity + (Filter << TIMER_BRKETR_CNTRL_ETR_FILTER_Pos);
  TIMERx->BRKETR_CNTRL = tmpreg_BRKETR_CNTRL;
}

/**
  * @brief  Configures the TIMERx ETR Filter peripheral.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  Filter: specifies the ETR Filter configuration.
  *         This parameter can be one of the following values:
  *           @arg TIMER_Filter_1FF_at_TIMER_CLK:   signal is latched by 1 trigger  at TIMER_CLK clock frequency;
  *           @arg TIMER_Filter_2FF_at_TIMER_CLK:   signal is latched by 2 triggers at TIMER_CLK clock frequency;
  *           @arg TIMER_Filter_4FF_at_TIMER_CLK:   signal is latched by 4 triggers at TIMER_CLK clock frequency;
  *           @arg TIMER_Filter_8FF_at_TIMER_CLK:   signal is latched by 8 triggers at TIMER_CLK clock frequency;
  *           @arg TIMER_Filter_6FF_at_FTDS_div_2:  signal is latched by 6 triggers at FDTS/2  clock frequency;
  *           @arg TIMER_Filter_8FF_at_FTDS_div_2:  signal is latched by 8 triggers at FDTS/2  clock frequency;
  *           @arg TIMER_Filter_6FF_at_FTDS_div_4:  signal is latched by 6 triggers at FDTS/4  clock frequency;
  *           @arg TIMER_Filter_8FF_at_FTDS_div_4:  signal is latched by 8 triggers at FDTS/4  clock frequency;
  *           @arg TIMER_Filter_6FF_at_FTDS_div_8:  signal is latched by 6 triggers at FDTS/8  clock frequency;
  *           @arg TIMER_Filter_8FF_at_FTDS_div_8:  signal is latched by 8 triggers at FDTS/8  clock frequency;
  *           @arg TIMER_Filter_5FF_at_FTDS_div_16: signal is latched by 5 triggers at FDTS/16 clock frequency;
  *           @arg TIMER_Filter_6FF_at_FTDS_div_16: signal is latched by 6 triggers at FDTS/16 clock frequency;
  *           @arg TIMER_Filter_8FF_at_FTDS_div_16: signal is latched by 8 triggers at FDTS/16 clock frequency;
  *           @arg TIMER_Filter_5FF_at_FTDS_div_32: signal is latched by 5 triggers at FDTS/32 clock frequency;
  *           @arg TIMER_Filter_6FF_at_FTDS_div_32: signal is latched by 6 triggers at FDTS/32 clock frequency;
  *           @arg TIMER_Filter_8FF_at_FTDS_div_32: signal is latched by 8 triggers at FDTS/32 clock frequency.
  * @retval None
  */
void TIMER_ETRFilterConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Filter)
{
  uint32_t tmpreg_BRKETR_CNTRL;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_FILTER_CONF(Filter));

  tmpreg_BRKETR_CNTRL = TIMERx->BRKETR_CNTRL;
  tmpreg_BRKETR_CNTRL &= ~TIMER_BRKETR_CNTRL_ETR_FILTER_Msk;
  tmpreg_BRKETR_CNTRL += Filter << TIMER_BRKETR_CNTRL_ETR_FILTER_Pos;
  TIMERx->BRKETR_CNTRL = tmpreg_BRKETR_CNTRL;
}

/**
  * @brief  Configures the TIMERx ETR signal prescaler value.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  Prescaler: specifies the ETR signal prescaler value.
  *         This parameter can be one of the following values:
  *           @arg TIMER_ETR_Prescaler_None : no division of input frequency;
  *           @arg TIMER_ETR_Prescaler_div_2: selects input frequency divider by 2;
  *           @arg TIMER_ETR_Prescaler_div_4: selects input frequency divider by 4;
  *           @arg TIMER_ETR_Prescaler_div_8: selects input frequency divider by 8.
  * @retval None
  */
void TIMER_ETRPrescalerConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Prescaler)
{
  uint32_t tmpreg_BRKETR_CNTRL;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_ETR_PRESCALER(Prescaler));

  tmpreg_BRKETR_CNTRL = TIMERx->BRKETR_CNTRL;
  tmpreg_BRKETR_CNTRL &= ~TIMER_BRKETR_CNTRL_ETR_PSC_Msk;
  tmpreg_BRKETR_CNTRL += Prescaler;
  TIMERx->BRKETR_CNTRL = tmpreg_BRKETR_CNTRL;
}

/**
  * @brief  Configures the TIMERx ETR input inversion.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  Polarity: enables or disables inversion on ETR input.
  *         This parameter can be one of the following values:
  *           @arg TIMER_ETRPolarity_NonInverted: no inversion of the ETR input;
  *           @arg TIMER_ETRPolarity_Inverted:    the ETR input is inverted.
  * @retval None
  */
void TIMER_ETRPolarityConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Polarity)
{
  uint32_t tmpreg_BRKETR_CNTRL;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_ETR_POLARITY(Polarity));

  tmpreg_BRKETR_CNTRL = TIMERx->BRKETR_CNTRL;
  tmpreg_BRKETR_CNTRL &= ~TIMER_BRKETR_CNTRL_ETR_INV;
  tmpreg_BRKETR_CNTRL += Polarity;
  TIMERx->BRKETR_CNTRL = tmpreg_BRKETR_CNTRL;
}

/**
  * @brief  Configures the TIMERx BRK input inversion.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  Polarity: enables or disables inversion on BRK input.
  *         This parameter can be one of the following values:
  *           @arg TIMER_BRKPolarity_NonInverted: no inversion of the BRK input;
  *           @arg TIMER_BRKPolarity_Inverted:    the BRK input is inverted.
  * @retval None
  */
void TIMER_BRKPolarityConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Polarity)
{
  uint32_t tmpreg_BRKETR_CNTRL;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_BRK_POLARITY(Polarity));

  tmpreg_BRKETR_CNTRL = TIMERx->BRKETR_CNTRL;
  tmpreg_BRKETR_CNTRL &= ~TIMER_BRKETR_CNTRL_BRK_INV;
  tmpreg_BRKETR_CNTRL += Polarity;
  TIMERx->BRKETR_CNTRL = tmpreg_BRKETR_CNTRL;
}

/**
  * @brief  Returns the TIMERx count direction.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @retval The current Timer count direction (TIMER_CntDir_Up or TIMER_CntDir_Dn)
  */
uint32_t TIMER_GetCounterDirection(MDR_TMR_TypeDef* TIMERx)
{
  uint32_t bitstatus;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));

  if ((TIMERx->CNTRL & TIMER_CNTRL_DIR) == 0)
  {
    bitstatus = TIMER_CntDir_Up;
  }
  else
  {
    bitstatus = TIMER_CntDir_Dn;
  }

  return bitstatus;
}

/**
  * @brief  Checks whether the TIMERx WR_CMPL flag is set or not.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @retval The WR_CMPL flag current state (SET or RESET).
  */
FlagStatus TIMER_GetCntWriteComplete(MDR_TMR_TypeDef* TIMERx)
{
  FlagStatus bitstatus;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));

  if ((TIMERx->CNTRL & TIMER_CNTRL_WR_CMPL) == 0)
  {
    bitstatus = RESET;
  }
  else
  {
    bitstatus = SET;
  }

  return bitstatus;
}

/**
  * @brief  Initializes the TIMERx Channel peripheral according to
  *         the specified parameters in the TIMER_ChnInitStruct.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  TIMER_ChnInitStruct: pointer to a TIMER_ChnInitTypeDef structure
  *         that contains the configuration information for the specified
  *         TIMER Channel peripheral.
  * @retval None
  */
void TIMER_ChnInit(MDR_TMR_TypeDef* TIMERx, const TIMER_ChnInitTypeDef* TIMER_ChnInitStruct)
{
  uint32_t tmpreg_CH_Number;
  uint32_t tmpreg_CH_CNTRL;
  uint32_t tmpreg_CH_CNTRL2;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_CHANNEL_NUMBER(TIMER_ChnInitStruct->TIMER_CH_Number));
  assert_param(IS_TIMER_CHANNEL_MODE(TIMER_ChnInitStruct->TIMER_CH_Mode));
  assert_param(IS_FUNCTIONAL_STATE(TIMER_ChnInitStruct->TIMER_CH_ETR_Ena));
  assert_param(IS_TIMER_CHANNEL_ETR_RESET_CONFIG(TIMER_ChnInitStruct->TIMER_CH_ETR_Reset));
  assert_param(IS_TIMER_CHANNEL_BRK_RESET_CONFIG(TIMER_ChnInitStruct->TIMER_CH_BRK_Reset));
  assert_param(IS_TIMER_CHANNEL_REF_FORMAT(TIMER_ChnInitStruct->TIMER_CH_REF_Format));
  assert_param(IS_TIMER_CHANNEL_PRESCALER(TIMER_ChnInitStruct->TIMER_CH_Prescaler));
  assert_param(IS_TIMER_CHANNEL_EVENT_SOURCE(TIMER_ChnInitStruct->TIMER_CH_EventSource));
  assert_param(IS_TIMER_FILTER_CONF(TIMER_ChnInitStruct->TIMER_CH_FilterConf));
  assert_param(IS_TIMER_CHANNEL_CCR_UPDATE_MODE(TIMER_ChnInitStruct->TIMER_CH_CCR_UpdateMode));
  assert_param(IS_FUNCTIONAL_STATE(TIMER_ChnInitStruct->TIMER_CH_CCR1_Ena));
  assert_param(IS_TIMER_CHANNEL_CCR1_EVENT_SOURCE(TIMER_ChnInitStruct->TIMER_CH_CCR1_EventSource));

  tmpreg_CH_CNTRL = TIMER_ChnInitStruct->TIMER_CH_Mode
                  + TIMER_ChnInitStruct->TIMER_CH_ETR_Reset
                  + TIMER_ChnInitStruct->TIMER_CH_BRK_Reset
                  + TIMER_ChnInitStruct->TIMER_CH_REF_Format
                  + (TIMER_ChnInitStruct->TIMER_CH_Prescaler << TIMER_CH_CNTRL_CHPSC_Pos)
                  + TIMER_ChnInitStruct->TIMER_CH_EventSource
                  + (TIMER_ChnInitStruct->TIMER_CH_FilterConf << TIMER_CH_CNTRL_CHFLTR_Pos);

  if (TIMER_ChnInitStruct->TIMER_CH_ETR_Ena != DISABLE)
  {
    tmpreg_CH_CNTRL += TIMER_CH_CNTRL_ETREN;
  }

  tmpreg_CH_Number = TIMER_ChnInitStruct->TIMER_CH_Number;

  *(&TIMERx->CH1_CNTRL + tmpreg_CH_Number) = tmpreg_CH_CNTRL;

  tmpreg_CH_CNTRL2 = TIMER_ChnInitStruct->TIMER_CH_CCR_UpdateMode
                   + TIMER_ChnInitStruct->TIMER_CH_CCR1_EventSource;

  if (TIMER_ChnInitStruct->TIMER_CH_CCR1_Ena != DISABLE)
  {
    tmpreg_CH_CNTRL2 += TIMER_CH_CNTRL2_CCR1_EN;
  }

  *(&TIMERx->CH1_CNTRL2 + tmpreg_CH_Number) = tmpreg_CH_CNTRL2;
}

/**
  * @brief  Fills each TIMER_ChnInitStruct member with its default value.
  * @param  TIMER_ChnInitStruct : pointer to a TIMER_ChnInitTypeDef structure
  *         which will be initialized.
  * @retval None
  */
void TIMER_ChnStructInit(TIMER_ChnInitTypeDef* TIMER_ChnInitStruct)
{
  TIMER_ChnInitStruct->TIMER_CH_Number           = TIMER_CHANNEL1;
  TIMER_ChnInitStruct->TIMER_CH_Mode             = TIMER_CH_MODE_PWM;
  TIMER_ChnInitStruct->TIMER_CH_ETR_Ena          = DISABLE;
  TIMER_ChnInitStruct->TIMER_CH_ETR_Reset        = TIMER_CH_ETR_RESET_Disable;
  TIMER_ChnInitStruct->TIMER_CH_BRK_Reset        = TIMER_CH_BRK_RESET_Disable;
  TIMER_ChnInitStruct->TIMER_CH_REF_Format       = TIMER_CH_REF_Format0;
  TIMER_ChnInitStruct->TIMER_CH_Prescaler        = TIMER_CH_Prescaler_None;
  TIMER_ChnInitStruct->TIMER_CH_EventSource      = TIMER_CH_EvSrc_PE;
  TIMER_ChnInitStruct->TIMER_CH_FilterConf       = TIMER_Filter_1FF_at_TIMER_CLK;
  TIMER_ChnInitStruct->TIMER_CH_CCR_UpdateMode   = TIMER_CH_CCR_Update_Immediately;
  TIMER_ChnInitStruct->TIMER_CH_CCR1_Ena         = DISABLE;
  TIMER_ChnInitStruct->TIMER_CH_CCR1_EventSource = TIMER_CH_CCR1EvSrc_PE;
}

/**
  * @brief  Sets the TIMERx Channel Capture Compare Register (CCR) value.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  Channel: specifies the Timer Channel number.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CHANNEL1: specifies TIMERx Channel 1;
  *           @arg TIMER_CHANNEL2: specifies TIMERx Channel 2;
  *           @arg TIMER_CHANNEL3: specifies TIMERx Channel 3;
  *           @arg TIMER_CHANNEL4: specifies TIMERx Channel 4.
  * @param  Compare: specifies the Capture Compare Register (CCR) new value.
  * @retval None
  */
#if defined (USE_MDR1986VE1T) || defined (USE_MDR1986VE3)
void TIMER_SetChnCompare(MDR_TIMER_TypeDef* TIMERx, uint32_t Channel, uint32_t Compare)
#elif defined (USE_MDR1986VE9x)
void TIMER_SetChnCompare(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, uint16_t Compare)
#endif
{
  __IO uint32_t *tmpreg_CCRx;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_CHANNEL_NUMBER(Channel));

  tmpreg_CCRx = &TIMERx->CCR1 + Channel;
  *tmpreg_CCRx = Compare;
}

/**
  * @brief  Sets the TIMERx Channel Capture Compare Register1 (CCR1) value.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  Channel: specifies the Timer Channel number.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CHANNEL1: specifies TIMERx Channel 1;
  *           @arg TIMER_CHANNEL2: specifies TIMERx Channel 2;
  *           @arg TIMER_CHANNEL3: specifies TIMERx Channel 3;
  *           @arg TIMER_CHANNEL4: specifies TIMERx Channel 4.
  * @param  Compare: specifies the Capture Compare Register1 (CCR1) new value.
  * @retval None
  */
#if defined (USE_MDR1986VE1T) || defined (USE_MDR1986VE3)
void TIMER_SetChnCompare1(MDR_TIMER_TypeDef* TIMERx, uint32_t Channel, uint32_t Compare)
#elif defined (USE_MDR1986VE9x)
void TIMER_SetChnCompare1(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, uint16_t Compare)
#endif
{
  __IO uint32_t *tmpreg_CCR1x;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_CHANNEL_NUMBER(Channel));

  tmpreg_CCR1x = &TIMERx->CCR11 + Channel;
  *tmpreg_CCR1x = Compare;
}

/**
  * @brief  Sets the TIMERx Channel Capture Compare Register (CCR) value.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  Channel: specifies the Timer Channel number.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CHANNEL1: specifies TIMERx Channel 1;
  *           @arg TIMER_CHANNEL2: specifies TIMERx Channel 2;
  *           @arg TIMER_CHANNEL3: specifies TIMERx Channel 3;
  *           @arg TIMER_CHANNEL4: specifies TIMERx Channel 4.
  * @param  Compare: specifies the Capture Compare Register (CCR) new value.
  * @param  UpdateMode: specifies the Capture Compare Register Update mode.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CH_CCR_Update_Immediately: the CCR register is updated immediately;
  *           @arg TIMER_CH_CCR_Update_On_CNT_eq_0: the CCR register is updated at (CNT == 0) condition.
  * @retval None
  */
#if defined (USE_MDR1986VE1T) || defined (USE_MDR1986VE3)
void TIMER_ChnCompareConfig(MDR_TIMER_TypeDef* TIMERx, uint32_t Channel, uint32_t Compare, uint32_t UpdateMode)
#elif defined (USE_MDR1986VE9x)
void TIMER_ChnCompareConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, uint16_t Compare, uint32_t UpdateMode)
#endif
{
  __IO uint32_t *tmpreg_CNTRL2x;
  __IO uint32_t *tmpreg_CCRx;
  uint32_t tmpreg_CNTRL2;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_CHANNEL_NUMBER(Channel));
  assert_param(IS_TIMER_ARR_UPDATE_MODE(UpdateMode));

  tmpreg_CNTRL2x = &TIMERx->CH1_CNTRL2 + Channel;

  tmpreg_CNTRL2 = *tmpreg_CNTRL2x;
  tmpreg_CNTRL2 &= ~TIMER_CH_CNTRL2_CCRRLD;
  tmpreg_CNTRL2 += UpdateMode;
  *tmpreg_CNTRL2x = tmpreg_CNTRL2;

  tmpreg_CCRx = &TIMERx->CCR1 + Channel;

  *tmpreg_CCRx = Compare;
}

/**
  * @brief  Sets the TIMERx Channel Capture Compare Register1 (CCR1) value.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  Channel: specifies the Timer Channel number.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CHANNEL1: specifies TIMERx Channel 1;
  *           @arg TIMER_CHANNEL2: specifies TIMERx Channel 2;
  *           @arg TIMER_CHANNEL3: specifies TIMERx Channel 3;
  *           @arg TIMER_CHANNEL4: specifies TIMERx Channel 4.
  * @param  Compare: specifies the Capture Compare Register1 (CCR1) new value.
  * @param  UpdateMode: specifies the Capture Compare Register1 Update mode.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CH_CCR_Update_Immediately: the CCR1 register is updated immediately;
  *           @arg TIMER_CH_CCR_Update_On_CNT_eq_0: the CCR1 register is updated at (CNT == 0) condition.
  * @retval None
  */
#if defined (USE_MDR1986VE1T) || defined (USE_MDR1986VE3)
void TIMER_ChnCompare1Config(MDR_TIMER_TypeDef* TIMERx, uint32_t Channel, uint32_t Compare, uint32_t UpdateMode)
#elif defined (USE_MDR1986VE9x)
void TIMER_ChnCompare1Config(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, uint16_t Compare, uint32_t UpdateMode)
#endif
{
  __IO uint32_t *tmpreg_CNTRL2x;
  __IO uint32_t *tmpreg_CCR1x;
  uint32_t tmpreg_CNTRL2;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_CHANNEL_NUMBER(Channel));
  assert_param(IS_TIMER_ARR_UPDATE_MODE(UpdateMode));

  tmpreg_CNTRL2x = &TIMERx->CH1_CNTRL2 + Channel;

  tmpreg_CNTRL2 = *tmpreg_CNTRL2x;
  tmpreg_CNTRL2 &= ~TIMER_CH_CNTRL2_CCRRLD;
  tmpreg_CNTRL2 += UpdateMode;
  *tmpreg_CNTRL2x = tmpreg_CNTRL2;

  tmpreg_CCR1x = &TIMERx->CCR11 + Channel;

  *tmpreg_CCR1x = Compare;
}

/**
  * @brief  Returns the TIMERx Channel Capture Compare Register (CCR) value.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  Channel: specifies the Timer Channel number.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CHANNEL1: specifies TIMERx Channel 1;
  *           @arg TIMER_CHANNEL2: specifies TIMERx Channel 2;
  *           @arg TIMER_CHANNEL3: specifies TIMERx Channel 3;
  *           @arg TIMER_CHANNEL4: specifies TIMERx Channel 4.
  * @retval Capture Compare Register (CCR) value.
  */
#if defined (USE_MDR1986VE1T) || defined (USE_MDR1986VE3)
uint32_t TIMER_GetChnCapture(MDR_TIMER_TypeDef* TIMERx, uint32_t Channel)
#elif defined (USE_MDR1986VE9x)
uint16_t TIMER_GetChnCapture(MDR_TMR_TypeDef* TIMERx, uint32_t Channel)
#endif
{
  __IO uint32_t *tmpreg_CCRx;
  uint32_t tmpreg;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_CHANNEL_NUMBER(Channel));

  tmpreg_CCRx = &TIMERx->CCR1 + Channel;
  tmpreg = *tmpreg_CCRx;

  return tmpreg;
}

/**
  * @brief  Returns the TIMERx Channel Capture Compare Register1 (CCR1) value.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  Channel: specifies the Timer Channel number.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CHANNEL1: specifies TIMERx Channel 1;
  *           @arg TIMER_CHANNEL2: specifies TIMERx Channel 2;
  *           @arg TIMER_CHANNEL3: specifies TIMERx Channel 3;
  *           @arg TIMER_CHANNEL4: specifies TIMERx Channel 4.
  * @retval Capture Compare Register1 (CCR1) value.
  */
#if defined (USE_MDR1986VE1T) || defined (USE_MDR1986VE3)
uint32_t TIMER_GetChnCapture1(MDR_TIMER_TypeDef* TIMERx, uint32_t Channel)
#elif defined (USE_MDR1986VE9x)
uint16_t TIMER_GetChnCapture1(MDR_TMR_TypeDef* TIMERx, uint32_t Channel)
#endif
{
  __IO uint32_t *tmpreg_CCR1x;
  uint32_t tmpreg;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_CHANNEL_NUMBER(Channel));

  tmpreg_CCR1x = &TIMERx->CCR11 + Channel;
  tmpreg = *tmpreg_CCR1x;

  return tmpreg;
}

/**
  * @brief  Enables or disables the TIMERx Channel ETR input.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  Channel: specifies the Timer Channel number.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CHANNEL1: specifies TIMERx Channel 1;
  *           @arg TIMER_CHANNEL2: specifies TIMERx Channel 2;
  *           @arg TIMER_CHANNEL3: specifies TIMERx Channel 3;
  *           @arg TIMER_CHANNEL4: specifies TIMERx Channel 4.
  * @param  NewState: new state of the ETR enable (OCCE) bit.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void TIMER_ChnETR_Cmd(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, FunctionalState NewState)
{
  __IO uint32_t *tmpreg_CH_CNTRLx;
  uint32_t tmpreg_CH_CNTRL;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_CHANNEL_NUMBER(Channel));
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  tmpreg_CH_CNTRLx = &TIMERx->CH1_CNTRL + Channel;

  tmpreg_CH_CNTRL = *tmpreg_CH_CNTRLx;

  /* Form new value */
  if (NewState != DISABLE)
  {
    /* Enable TIMERx by setting the CNT_EN bit in the CNTRL register */
    tmpreg_CH_CNTRL |= TIMER_CH_CNTRL_OCCE;
  }
  else
  {
    /* Disable TIMERx by resetting the CNT_EN bit in the CNTRL register */
    tmpreg_CH_CNTRL &= ~TIMER_CH_CNTRL_OCCE;
  }

  /* Configure CNTRL register with new value */
  *tmpreg_CH_CNTRLx = tmpreg_CH_CNTRL;
}

/**
  * @brief  Enables or disables TIMERx Channel ETR Reset.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  Channel: specifies the Timer Channel number.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CHANNEL1: specifies TIMERx Channel 1;
  *           @arg TIMER_CHANNEL2: specifies TIMERx Channel 2;
  *           @arg TIMER_CHANNEL3: specifies TIMERx Channel 3;
  *           @arg TIMER_CHANNEL4: specifies TIMERx Channel 4.
  * @param  NewState: new state of the ETR Reset enable.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CH_ETR_RESET_Disable: disables ETR Reset;
  *           @arg TIMER_CH_ETR_RESET_Enable:  enables ETR Reset.
  * @retval None
  */
void TIMER_ChnETRResetConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, uint32_t NewState)
{
  __IO uint32_t *tmpreg_CH_CNTRLx;
  uint32_t tmpreg_CH_CNTRL;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_CHANNEL_NUMBER(Channel));
  assert_param(IS_TIMER_CHANNEL_ETR_RESET_CONFIG(NewState));

  tmpreg_CH_CNTRLx = &TIMERx->CH1_CNTRL + Channel;

  tmpreg_CH_CNTRL = *tmpreg_CH_CNTRLx;
  tmpreg_CH_CNTRL &= ~TIMER_CH_CNTRL_ETREN;
  tmpreg_CH_CNTRL += NewState;
  *tmpreg_CH_CNTRLx = tmpreg_CH_CNTRL;
}

/**
  * @brief  Enables or disables TIMERx Channel BRK Reset.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  Channel: specifies the Timer Channel number.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CHANNEL1: specifies TIMERx Channel 1;
  *           @arg TIMER_CHANNEL2: specifies TIMERx Channel 2;
  *           @arg TIMER_CHANNEL3: specifies TIMERx Channel 3;
  *           @arg TIMER_CHANNEL4: specifies TIMERx Channel 4.
  * @param  NewState: new state of the BRK Reset enable.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CH_BRK_RESET_Disable: disables BRK Reset;
  *           @arg TIMER_CH_BRK_RESET_Enable:  enables BRK Reset.
  * @retval None
  */
void TIMER_ChnBRKResetConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, uint32_t NewState)
{
  __IO uint32_t *tmpreg_CH_CNTRLx;
  uint32_t tmpreg_CH_CNTRL;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_CHANNEL_NUMBER(Channel));
  assert_param(IS_TIMER_CHANNEL_BRK_RESET_CONFIG(NewState));

  tmpreg_CH_CNTRLx = &TIMERx->CH1_CNTRL + Channel;

  tmpreg_CH_CNTRL = *tmpreg_CH_CNTRLx;
  tmpreg_CH_CNTRL &= ~TIMER_CH_CNTRL_BRKEN;
  tmpreg_CH_CNTRL += NewState;
  *tmpreg_CH_CNTRLx = tmpreg_CH_CNTRL;
}

/**
  * @brief  Configures the TIMERx REF signal format.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  Channel: specifies the Timer Channel number.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CHANNEL1: specifies TIMERx Channel 1;
  *           @arg TIMER_CHANNEL2: specifies TIMERx Channel 2;
  *           @arg TIMER_CHANNEL3: specifies TIMERx Channel 3;
  *           @arg TIMER_CHANNEL4: specifies TIMERx Channel 4.
  * @param  Format: new value of the TIMERx REF format.
  *         This parameter can be one of @ref TIMER_CH_REF_Format values.
  * @retval None
  */
void TIMER_ChnREFFormatConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, uint32_t Format)
{
  __IO uint32_t *tmpreg_CH_CNTRLx;
  uint32_t tmpreg_CH_CNTRL;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_CHANNEL_NUMBER(Channel));
  assert_param(IS_TIMER_CHANNEL_REF_FORMAT(Format));

  tmpreg_CH_CNTRLx = &TIMERx->CH1_CNTRL + Channel;

  tmpreg_CH_CNTRL = *tmpreg_CH_CNTRLx;
  tmpreg_CH_CNTRL &= ~TIMER_CH_CNTRL_OCCM_Msk;
  tmpreg_CH_CNTRL += Format;
  *tmpreg_CH_CNTRLx = tmpreg_CH_CNTRL;
}

/**
  * @brief  Configures the TIMERx Capture prescaler value.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  Channel: specifies the Timer Channel number.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CHANNEL1: specifies TIMERx Channel 1;
  *           @arg TIMER_CHANNEL2: specifies TIMERx Channel 2;
  *           @arg TIMER_CHANNEL3: specifies TIMERx Channel 3;
  *           @arg TIMER_CHANNEL4: specifies TIMERx Channel 4.
  * @param  Prescaler: specifies the Capture signal prescaler value.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CH_Prescaler_None : no division of input frequency;
  *           @arg TIMER_CH_Prescaler_div_2: selects input frequency divider by 2;
  *           @arg TIMER_CH_Prescaler_div_4: selects input frequency divider by 4;
  *           @arg TIMER_CH_Prescaler_div_8: selects input frequency divider by 8.
  * @retval None
  */
void TIMER_ChnCapturePrescalerConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, uint32_t Prescaler)
{
  __IO uint32_t *tmpreg_CH_CNTRLx;
  uint32_t tmpreg_CH_CNTRL;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_CHANNEL_NUMBER(Channel));
  assert_param(IS_TIMER_CHANNEL_PRESCALER(Prescaler));

  tmpreg_CH_CNTRLx = &TIMERx->CH1_CNTRL + Channel;

  tmpreg_CH_CNTRL = *tmpreg_CH_CNTRLx;
  tmpreg_CH_CNTRL &= ~TIMER_CH_CNTRL_CHPSC_Msk;
  tmpreg_CH_CNTRL += Prescaler << TIMER_CH_CNTRL_CHPSC_Pos;
  *tmpreg_CH_CNTRLx = tmpreg_CH_CNTRL;
}

/**
  * @brief  Configures the TIMERx Channel Capture Event source.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  Channel: specifies the Timer Channel number.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CHANNEL1: specifies TIMERx Channel 1;
  *           @arg TIMER_CHANNEL2: specifies TIMERx Channel 2;
  *           @arg TIMER_CHANNEL3: specifies TIMERx Channel 3;
  *           @arg TIMER_CHANNEL4: specifies TIMERx Channel 4.
  * @param  EventSource: specifies the Event source.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CH_EvSrc_PE:     selects positive edge from current TIMER channel;
  *           @arg TIMER_CH_EvSrc_NE:     selects negative edge from current TIMER channel;
  *           @arg TIMER_CH_EvSrc_PE_OC1: selects positive edge from other TIMER channel (variant 1);
  *           @arg TIMER_CH_EvSrc_PE_OC2: selects positive edge from other TIMER channel (variant 2).
  * @retval None
  */
void TIMER_ChnEventSourceConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, uint32_t EventSource)
{
  __IO uint32_t *tmpreg_CH_CNTRLx;
  uint32_t tmpreg_CH_CNTRL;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_CHANNEL_NUMBER(Channel));
  assert_param(IS_TIMER_CHANNEL_EVENT_SOURCE(EventSource));

  tmpreg_CH_CNTRLx = &TIMERx->CH1_CNTRL + Channel;

  tmpreg_CH_CNTRL = *tmpreg_CH_CNTRLx;
  tmpreg_CH_CNTRL &= ~TIMER_CH_CNTRL_CHSEL_Msk;
  tmpreg_CH_CNTRL += EventSource;
  *tmpreg_CH_CNTRLx = tmpreg_CH_CNTRL;
}

/**
  * @brief  Configures the TIMERx Channel Filter peripheral.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  Channel: specifies the Timer Channel number.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CHANNEL1: specifies TIMERx Channel 1;
  *           @arg TIMER_CHANNEL2: specifies TIMERx Channel 2;
  *           @arg TIMER_CHANNEL3: specifies TIMERx Channel 3;
  *           @arg TIMER_CHANNEL4: specifies TIMERx Channel 4.
  * @param  Filter: specifies the Channel Filter configuration.
  *         This parameter can be one of the following values:
  *           @arg TIMER_Filter_1FF_at_TIMER_CLK:   signal is latched by 1 trigger  at TIMER_CLK clock frequency;
  *           @arg TIMER_Filter_2FF_at_TIMER_CLK:   signal is latched by 2 triggers at TIMER_CLK clock frequency;
  *           @arg TIMER_Filter_4FF_at_TIMER_CLK:   signal is latched by 4 triggers at TIMER_CLK clock frequency;
  *           @arg TIMER_Filter_8FF_at_TIMER_CLK:   signal is latched by 8 triggers at TIMER_CLK clock frequency;
  *           @arg TIMER_Filter_6FF_at_FTDS_div_2:  signal is latched by 6 triggers at FDTS/2  clock frequency;
  *           @arg TIMER_Filter_8FF_at_FTDS_div_2:  signal is latched by 8 triggers at FDTS/2  clock frequency;
  *           @arg TIMER_Filter_6FF_at_FTDS_div_4:  signal is latched by 6 triggers at FDTS/4  clock frequency;
  *           @arg TIMER_Filter_8FF_at_FTDS_div_4:  signal is latched by 8 triggers at FDTS/4  clock frequency;
  *           @arg TIMER_Filter_6FF_at_FTDS_div_8:  signal is latched by 6 triggers at FDTS/8  clock frequency;
  *           @arg TIMER_Filter_8FF_at_FTDS_div_8:  signal is latched by 8 triggers at FDTS/8  clock frequency;
  *           @arg TIMER_Filter_5FF_at_FTDS_div_16: signal is latched by 5 triggers at FDTS/16 clock frequency;
  *           @arg TIMER_Filter_6FF_at_FTDS_div_16: signal is latched by 6 triggers at FDTS/16 clock frequency;
  *           @arg TIMER_Filter_8FF_at_FTDS_div_16: signal is latched by 8 triggers at FDTS/16 clock frequency;
  *           @arg TIMER_Filter_5FF_at_FTDS_div_32: signal is latched by 5 triggers at FDTS/32 clock frequency;
  *           @arg TIMER_Filter_6FF_at_FTDS_div_32: signal is latched by 6 triggers at FDTS/32 clock frequency;
  *           @arg TIMER_Filter_8FF_at_FTDS_div_32: signal is latched by 8 triggers at FDTS/32 clock frequency.
  * @retval None
  */
void TIMER_ChnFilterConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, uint32_t Filter)
{
  __IO uint32_t *tmpreg_CH_CNTRLx;
  uint32_t tmpreg_CH_CNTRL;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_CHANNEL_NUMBER(Channel));
  assert_param(IS_TIMER_FILTER_CONF(Filter));

  tmpreg_CH_CNTRLx = &TIMERx->CH1_CNTRL + Channel;

  tmpreg_CH_CNTRL = *tmpreg_CH_CNTRLx;
  tmpreg_CH_CNTRL &= ~TIMER_CH_CNTRL_CHFLTR_Msk;
  tmpreg_CH_CNTRL += Filter << TIMER_CH_CNTRL_CHFLTR_Pos;
  *tmpreg_CH_CNTRLx = tmpreg_CH_CNTRL;
}

/**
  * @brief  Checks whether the TIMERx CCR (CCR1) writ operation is complete or not.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  Channel: specifies the Timer Channel number.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CHANNEL1: specifies TIMERx Channel 1;
  *           @arg TIMER_CHANNEL2: specifies TIMERx Channel 2;
  *           @arg TIMER_CHANNEL3: specifies TIMERx Channel 3;
  *           @arg TIMER_CHANNEL4: specifies TIMERx Channel 4.
  * @retval The TIMERx_CHy_CNTRL.WR_CMPL flag current state (SET or RESET).
  */
FlagStatus TIMER_GetChnWriteComplete(MDR_TMR_TypeDef* TIMERx, uint32_t Channel)
{
  __IO uint32_t *tmpreg_CH_CNTRLx;
  FlagStatus bitstatus;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_CHANNEL_NUMBER(Channel));

  tmpreg_CH_CNTRLx = &TIMERx->CH1_CNTRL + Channel;

  if ((*tmpreg_CH_CNTRLx & TIMER_CH_CNTRL_WR_CMPL) == 0)
  {
    bitstatus = RESET;
  }
  else
  {
    bitstatus = SET;
  }

  return bitstatus;
}

/**
  * @brief  Configures the TIMERx Channel Capture1 Event source.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  Channel: specifies the Timer Channel number.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CHANNEL1: specifies TIMERx Channel 1;
  *           @arg TIMER_CHANNEL2: specifies TIMERx Channel 2;
  *           @arg TIMER_CHANNEL3: specifies TIMERx Channel 3;
  *           @arg TIMER_CHANNEL4: specifies TIMERx Channel 4.
  * @param  EventSource: specifies the Event source.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CH_CCR1EvSrc_PE    : selects positive edge from current TIMER channel.
  *           @arg TIMER_CH_CCR1EvSrc_NE    : selects negative edge from current TIMER channel.
  *           @arg TIMER_CH_CCR1EvSrc_NE_OC1: selects negative edge from other TIMER channel (variant 1).
  *           @arg TIMER_CH_CCR1EvSrc_NE_OC2: selects negative edge from other TIMER channel (variant 2).
  * @retval None
  */
void TIMER_ChnCCR1_EventSourceConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, uint32_t EventSource)
{
  __IO uint32_t *tmpreg_CH_CNTRL2x;
  uint32_t tmpreg_CH_CNTRL2;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_CHANNEL_NUMBER(Channel));
  assert_param(IS_TIMER_CHANNEL_CCR1_EVENT_SOURCE(EventSource));

  tmpreg_CH_CNTRL2x = &TIMERx->CH1_CNTRL2 + Channel;

  tmpreg_CH_CNTRL2 = *tmpreg_CH_CNTRL2x;
  tmpreg_CH_CNTRL2 &= ~TIMER_CH_CNTRL2_CHSEL1_Msk;
  tmpreg_CH_CNTRL2 += EventSource;
  *tmpreg_CH_CNTRL2x = tmpreg_CH_CNTRL2;
}

/**
  * @brief  Enables or disables the TIMERx Channel CCR1 register.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  Channel: specifies the Timer Channel number.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CHANNEL1: specifies TIMERx Channel 1;
  *           @arg TIMER_CHANNEL2: specifies TIMERx Channel 2;
  *           @arg TIMER_CHANNEL3: specifies TIMERx Channel 3;
  *           @arg TIMER_CHANNEL4: specifies TIMERx Channel 4.
  * @param  NewState: new state of the CCR1_EN bit.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void TIMER_ChnCCR1_Cmd(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, FunctionalState NewState)
{
  __IO uint32_t *tmpreg_CH_CNTRL2x;
  uint32_t tmpreg_CH_CNTRL2;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_CHANNEL_NUMBER(Channel));
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  tmpreg_CH_CNTRL2x = &TIMERx->CH1_CNTRL2 + Channel;

  tmpreg_CH_CNTRL2 = *tmpreg_CH_CNTRL2x;

  /* Form new value */
  if (NewState != DISABLE)
  {
    /* Enable TIMERx by setting the CCR1_EN bit in the CNTRL2 register */
    tmpreg_CH_CNTRL2 |= TIMER_CH_CNTRL2_CCR1_EN;
  }
  else
  {
    /* Disable TIMERx by resetting the CCR1_EN bit in the CNTRL2 register */
    tmpreg_CH_CNTRL2 &= ~TIMER_CH_CNTRL2_CCR1_EN;
  }

  /* Configure CNTRL register with new value */
  *tmpreg_CH_CNTRL2x = tmpreg_CH_CNTRL2;
}

/**
  * @brief  Initializes the TIMERx Channel Output peripheral according to
  *         the specified parameters in the TIMER_ChnOutInitStruct.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  TIMER_ChnOutInitStruct: pointer to a TIMER_ChnOutInitTypeDef structure
  *         that contains the configuration information for the specified
  *         TIMER Channel peripheral.
  * @retval None
  */
void TIMER_ChnOutInit(MDR_TMR_TypeDef* TIMERx, const TIMER_ChnOutInitTypeDef* TIMER_ChnOutInitStruct)
{
  uint32_t tmpreg_CH_Number;
  uint32_t tmpreg_CH_CNTRL1;
  uint32_t tmpreg_CH_DTG;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_CHANNEL_NUMBER(TIMER_ChnOutInitStruct->TIMER_CH_Number));
  assert_param(IS_TIMER_CHO_POLARITY(TIMER_ChnOutInitStruct->TIMER_CH_DirOut_Polarity));
  assert_param(IS_TIMER_CHO_SOURCE(TIMER_ChnOutInitStruct->TIMER_CH_DirOut_Source));
  assert_param(IS_TIMER_CHO_MODE(TIMER_ChnOutInitStruct->TIMER_CH_DirOut_Mode));
  assert_param(IS_TIMER_CHO_POLARITY(TIMER_ChnOutInitStruct->TIMER_CH_NegOut_Polarity));
  assert_param(IS_TIMER_CHO_SOURCE(TIMER_ChnOutInitStruct->TIMER_CH_NegOut_Source));
  assert_param(IS_TIMER_CHO_MODE(TIMER_ChnOutInitStruct->TIMER_CH_NegOut_Mode));
  assert_param(IS_TIMER_CHANNEL_DTG_MAIN_PRESCALER(TIMER_ChnOutInitStruct->TIMER_CH_DTG_MainPrescaler));
  assert_param(IS_TIMER_CHANNEL_DTG_AUX_PRESCALER(TIMER_ChnOutInitStruct->TIMER_CH_DTG_AuxPrescaler));
  assert_param(IS_TIMER_CHANNEL_DTG_CLK_SOURCE(TIMER_ChnOutInitStruct->TIMER_CH_DTG_ClockSource));

  tmpreg_CH_CNTRL1 = (TIMER_ChnOutInitStruct->TIMER_CH_DirOut_Polarity << TIMER_CH_CNTRL1_INV_Pos)
                   + (TIMER_ChnOutInitStruct->TIMER_CH_DirOut_Source   << TIMER_CH_CNTRL1_SELO_Pos)
                   + (TIMER_ChnOutInitStruct->TIMER_CH_DirOut_Mode     << TIMER_CH_CNTRL1_SELOE_Pos)
                   + (TIMER_ChnOutInitStruct->TIMER_CH_NegOut_Polarity << TIMER_CH_CNTRL1_NINV_Pos)
                   + (TIMER_ChnOutInitStruct->TIMER_CH_NegOut_Source   << TIMER_CH_CNTRL1_NSELO_Pos)
                   + (TIMER_ChnOutInitStruct->TIMER_CH_NegOut_Mode     << TIMER_CH_CNTRL1_NSELOE_Pos);

  tmpreg_CH_Number = TIMER_ChnOutInitStruct->TIMER_CH_Number;

  *(&TIMERx->CH1_CNTRL1 + tmpreg_CH_Number) = tmpreg_CH_CNTRL1;

  tmpreg_CH_DTG = (TIMER_ChnOutInitStruct->TIMER_CH_DTG_MainPrescaler << TIMER_CH_DTG_Pos)
                + (TIMER_ChnOutInitStruct->TIMER_CH_DTG_AuxPrescaler  << TIMER_CH_DTGX_Pos)
                + TIMER_ChnOutInitStruct->TIMER_CH_DTG_ClockSource;

  *(&TIMERx->CH1_DTG + tmpreg_CH_Number) = tmpreg_CH_DTG;
}

/**
  * @brief  Fills each TIMER_ChnOutInitStruct member with its default value.
  * @param  TIMER_ChnOutInitStruct: pointer to a TIMER_ChnOutInitTypeDef structure
  *         which will be initialized.
  * @retval None
  */
void TIMER_ChnOutStructInit(TIMER_ChnOutInitTypeDef* TIMER_ChnOutInitStruct)
{
  TIMER_ChnOutInitStruct->TIMER_CH_DirOut_Polarity   = TIMER_CHOPolarity_NonInverted;
  TIMER_ChnOutInitStruct->TIMER_CH_DirOut_Source     = TIMER_CH_OutSrc_Only_0;
  TIMER_ChnOutInitStruct->TIMER_CH_DirOut_Mode       = TIMER_CH_OutMode_Input;
  TIMER_ChnOutInitStruct->TIMER_CH_NegOut_Polarity   = TIMER_CHOPolarity_NonInverted;
  TIMER_ChnOutInitStruct->TIMER_CH_NegOut_Source     = TIMER_CH_OutSrc_Only_0;
  TIMER_ChnOutInitStruct->TIMER_CH_NegOut_Mode       = TIMER_CH_OutMode_Input;
  TIMER_ChnOutInitStruct->TIMER_CH_DTG_MainPrescaler = 0;
  TIMER_ChnOutInitStruct->TIMER_CH_DTG_AuxPrescaler  = 0;
  TIMER_ChnOutInitStruct->TIMER_CH_DTG_ClockSource   = TIMER_CH_DTG_ClkSrc_TIMER_CLK;
}

/**
  * @brief  Configures the TIMERx Channel output.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  Channel: specifies the Timer Channel number.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CHANNEL1: specifies TIMERx Channel 1;
  *           @arg TIMER_CHANNEL2: specifies TIMERx Channel 2;
  *           @arg TIMER_CHANNEL3: specifies TIMERx Channel 3;
  *           @arg TIMER_CHANNEL4: specifies TIMERx Channel 4.
  * @param  OutSource: specifies the Channel Output source.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CH_OutSrc_Only_0: selects the '0' state on the CHx line;
  *           @arg TIMER_CH_OutSrc_Only_1: selects the '1' state on the CHx line;
  *           @arg TIMER_CH_OutSrc_REF:    selects the REF state on the CHx line;
  *           @arg TIMER_CH_OutSrc_DTG:    selects the DTG output state on the CHx line.
  * @param  Mode: specifies the Channel Output Enable source.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CH_OutMode_Input:     selects the Input mode on the CHx line;
  *           @arg TIMER_CH_OutMode_Output:    selects the Output mode on the CHx line;
  *           @arg TIMER_CH_OutMode_REF_as_OE: the REF signal specifies the CHx line mode;
  *           @arg TIMER_CH_OutMode_DTG_as_OE: the DTG output specifies the CHx line mode.
  * @param  Polarity: enables or disables the Channel Output inversion.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CHOPolarity_NonInverted: no inversion on the Channel output;
  *           @arg TIMER_CHOPolarity_Inverted:    the Channel output is inverted.
  * @retval None
  */
void TIMER_ChnOutConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, uint32_t OutSource, uint32_t Mode, uint32_t Polarity)
{
  __IO uint32_t *tmpreg_CH_CNTRL1x;
  uint32_t tmpreg_CH_CNTRL1;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_CHANNEL_NUMBER(Channel));
  assert_param(IS_TIMER_CHO_SOURCE(OutSource));
  assert_param(IS_TIMER_CHO_MODE(Mode));
  assert_param(IS_TIMER_CHO_POLARITY(Polarity));

  tmpreg_CH_CNTRL1x = &TIMERx->CH1_CNTRL1 + Channel;

  tmpreg_CH_CNTRL1 = *tmpreg_CH_CNTRL1x;
  tmpreg_CH_CNTRL1 &= ~(TIMER_CH_CNTRL1_INV + TIMER_CH_CNTRL1_SELO_Msk + TIMER_CH_CNTRL1_SELOE_Msk);
  tmpreg_CH_CNTRL1 += (Polarity  << TIMER_CH_CNTRL1_INV_Pos)
                    + (OutSource << TIMER_CH_CNTRL1_SELO_Pos)
                    + (Mode      << TIMER_CH_CNTRL1_SELOE_Pos);
  *tmpreg_CH_CNTRL1x = tmpreg_CH_CNTRL1;
}

/**
  * @brief  Configures the TIMERx Channel Output source.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  Channel: specifies the Timer Channel number.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CHANNEL1: specifies TIMERx Channel 1;
  *           @arg TIMER_CHANNEL2: specifies TIMERx Channel 2;
  *           @arg TIMER_CHANNEL3: specifies TIMERx Channel 3;
  *           @arg TIMER_CHANNEL4: specifies TIMERx Channel 4.
  * @param  OutSource: specifies the Channel Output source.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CH_OutSrc_Only_0: selects the '0' state on the CHx line;
  *           @arg TIMER_CH_OutSrc_Only_1: selects the '1' state on the CHx line;
  *           @arg TIMER_CH_OutSrc_REF:    selects the REF state on the CHx line;
  *           @arg TIMER_CH_OutSrc_DTG:    selects the DTG output state on the CHx line.
  * @retval None
  */
void TIMER_ChnOutSourceConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, uint32_t OutSource)
{
  __IO uint32_t *tmpreg_CH_CNTRL1x;
  uint32_t tmpreg_CH_CNTRL1;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_CHANNEL_NUMBER(Channel));
  assert_param(IS_TIMER_CHO_SOURCE(OutSource));

  tmpreg_CH_CNTRL1x = &TIMERx->CH1_CNTRL1 + Channel;

  tmpreg_CH_CNTRL1 = *tmpreg_CH_CNTRL1x;
  tmpreg_CH_CNTRL1 &= ~TIMER_CH_CNTRL1_SELO_Msk;
  tmpreg_CH_CNTRL1 += OutSource << TIMER_CH_CNTRL1_SELO_Pos;
  *tmpreg_CH_CNTRL1x = tmpreg_CH_CNTRL1;
}

/**
  * @brief  Configures the TIMERx Channel Output mode.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  Channel: specifies the Timer Channel number.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CHANNEL1: specifies TIMERx Channel 1;
  *           @arg TIMER_CHANNEL2: specifies TIMERx Channel 2;
  *           @arg TIMER_CHANNEL3: specifies TIMERx Channel 3;
  *           @arg TIMER_CHANNEL4: specifies TIMERx Channel 4.
  * @param  Mode: specifies the Channel Output Enable source.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CH_OutMode_Input:     selects the Input mode on the CHx line;
  *           @arg TIMER_CH_OutMode_Output:    selects the Output mode on the CHx line;
  *           @arg TIMER_CH_OutMode_REF_as_OE: the REF signal specifies the CHx line mode;
  *           @arg TIMER_CH_OutMode_DTG_as_OE: the DTG output specifies the CHx line mode.
  * @retval None
  */
void TIMER_ChnOutModeConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, uint32_t Mode)
{
  __IO uint32_t *tmpreg_CH_CNTRL1x;
  uint32_t tmpreg_CH_CNTRL1;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_CHANNEL_NUMBER(Channel));
  assert_param(IS_TIMER_CHO_MODE(Mode));

  tmpreg_CH_CNTRL1x = &TIMERx->CH1_CNTRL1 + Channel;

  tmpreg_CH_CNTRL1 = *tmpreg_CH_CNTRL1x;
  tmpreg_CH_CNTRL1 &= ~TIMER_CH_CNTRL1_SELOE_Msk;
  tmpreg_CH_CNTRL1 += Mode << TIMER_CH_CNTRL1_SELOE_Pos;
  *tmpreg_CH_CNTRL1x = tmpreg_CH_CNTRL1;
}

/**
  * @brief  Configures the TIMERx Channel Output polarity.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  Channel: specifies the Timer Channel number.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CHANNEL1: specifies TIMERx Channel 1;
  *           @arg TIMER_CHANNEL2: specifies TIMERx Channel 2;
  *           @arg TIMER_CHANNEL3: specifies TIMERx Channel 3;
  *           @arg TIMER_CHANNEL4: specifies TIMERx Channel 4.
  * @param  Polarity: enables or disables the Channel Output inversion.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CHOPolarity_NonInverted: no inversion on the Channel output;
  *           @arg TIMER_CHOPolarity_Inverted:    the Channel output is inverted.
  * @retval None
  */
void TIMER_ChnOutPolarityConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, uint32_t Polarity)
{
  __IO uint32_t *tmpreg_CH_CNTRL1x;
  uint32_t tmpreg_CH_CNTRL1;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_CHANNEL_NUMBER(Channel));
  assert_param(IS_TIMER_CHO_POLARITY(Polarity));

  tmpreg_CH_CNTRL1x = &TIMERx->CH1_CNTRL1 + Channel;

  tmpreg_CH_CNTRL1 = *tmpreg_CH_CNTRL1x;
  tmpreg_CH_CNTRL1 &= ~TIMER_CH_CNTRL1_INV;
  tmpreg_CH_CNTRL1 += Polarity << TIMER_CH_CNTRL1_INV_Pos;
  *tmpreg_CH_CNTRL1x = tmpreg_CH_CNTRL1;
}

/**
  * @brief  Configures the TIMERx NChannel output.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  Channel: specifies the Timer Channel number.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CHANNEL1: specifies TIMERx Channel 1;
  *           @arg TIMER_CHANNEL2: specifies TIMERx Channel 2;
  *           @arg TIMER_CHANNEL3: specifies TIMERx Channel 3;
  *           @arg TIMER_CHANNEL4: specifies TIMERx Channel 4.
  * @param  OutSource: specifies the NChannel Output source.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CH_OutSrc_Only_0: selects the '0' state on the CHxN line;
  *           @arg TIMER_CH_OutSrc_Only_1: selects the '1' state on the CHxN line;
  *           @arg TIMER_CH_OutSrc_REF:    selects the REF state on the CHxN line;
  *           @arg TIMER_CH_OutSrc_DTG:    selects the DTG output state on the CHxN line.
  * @param  Mode: specifies the NChannel Output Enable source.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CH_OutMode_Input:     selects the Input mode on the CHxN line;
  *           @arg TIMER_CH_OutMode_Output:    selects the Output mode on the CHxN line;
  *           @arg TIMER_CH_OutMode_REF_as_OE: the REF signal specifies the CHxN line mode;
  *           @arg TIMER_CH_OutMode_DTG_as_OE: the DTG output specifies the CHxN line mode.
  * @param  Polarity: enables or disables the NChannel Output inversion.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CHOPolarity_NonInverted: no inversion on the NChannel output;
  *           @arg TIMER_CHOPolarity_Inverted:    the NChannel output is inverted.
  * @retval None
  */
void TIMER_ChnNOutConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, uint32_t OutSource, uint32_t Mode, uint32_t Polarity)
{
  __IO uint32_t *tmpreg_CH_CNTRL1x;
  uint32_t tmpreg_CH_CNTRL1;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_CHANNEL_NUMBER(Channel));
  assert_param(IS_TIMER_CHO_SOURCE(OutSource));
  assert_param(IS_TIMER_CHO_MODE(Mode));
  assert_param(IS_TIMER_CHO_POLARITY(Polarity));

  tmpreg_CH_CNTRL1x = &TIMERx->CH1_CNTRL1 + Channel;

  tmpreg_CH_CNTRL1 = *tmpreg_CH_CNTRL1x;
  tmpreg_CH_CNTRL1 &= ~(TIMER_CH_CNTRL1_NINV + TIMER_CH_CNTRL1_NSELO_Msk + TIMER_CH_CNTRL1_NSELOE_Msk);
  tmpreg_CH_CNTRL1 += (Polarity  << TIMER_CH_CNTRL1_NINV_Pos)
                    + (OutSource << TIMER_CH_CNTRL1_NSELO_Pos)
                    + (Mode      << TIMER_CH_CNTRL1_NSELOE_Pos);
  *tmpreg_CH_CNTRL1x = tmpreg_CH_CNTRL1;
}

/**
  * @brief  Configures the TIMERx NChannel Output source.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  Channel: specifies the Timer Channel number.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CHANNEL1: specifies TIMERx Channel 1;
  *           @arg TIMER_CHANNEL2: specifies TIMERx Channel 2;
  *           @arg TIMER_CHANNEL3: specifies TIMERx Channel 3;
  *           @arg TIMER_CHANNEL4: specifies TIMERx Channel 4.
  * @param  OutSource: specifies the NChannel Output source.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CH_OutSrc_Only_0: selects the '0' state on the CHxN line;
  *           @arg TIMER_CH_OutSrc_Only_1: selects the '1' state on the CHxN line;
  *           @arg TIMER_CH_OutSrc_REF:    selects the REF state on the CHxN line;
  *           @arg TIMER_CH_OutSrc_DTG:    selects the DTG output state on the CHxN line.
  * @retval None
  */
void TIMER_ChnNOutSourceConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, uint32_t OutSource)
{
  __IO uint32_t *tmpreg_CH_CNTRL1x;
  uint32_t tmpreg_CH_CNTRL1;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_CHANNEL_NUMBER(Channel));
  assert_param(IS_TIMER_CHO_SOURCE(OutSource));

  tmpreg_CH_CNTRL1x = &TIMERx->CH1_CNTRL1 + Channel;

  tmpreg_CH_CNTRL1 = *tmpreg_CH_CNTRL1x;
  tmpreg_CH_CNTRL1 &= ~TIMER_CH_CNTRL1_NSELO_Msk;
  tmpreg_CH_CNTRL1 += OutSource << TIMER_CH_CNTRL1_NSELO_Pos;
  *tmpreg_CH_CNTRL1x = tmpreg_CH_CNTRL1;
}

/**
  * @brief  Configures the TIMERx NChannel Output mode.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  Channel: specifies the Timer Channel number.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CHANNEL1: specifies TIMERx Channel 1;
  *           @arg TIMER_CHANNEL2: specifies TIMERx Channel 2;
  *           @arg TIMER_CHANNEL3: specifies TIMERx Channel 3;
  *           @arg TIMER_CHANNEL4: specifies TIMERx Channel 4.
  * @param  Mode: specifies the NChannel Output Enable source.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CH_OutMode_Input:     selects the Input mode on the CHxN line;
  *           @arg TIMER_CH_OutMode_Output:    selects the Output mode on the CHxN line;
  *           @arg TIMER_CH_OutMode_REF_as_OE: the REF signal specifies the CHxN line mode;
  *           @arg TIMER_CH_OutMode_DTG_as_OE: the DTG output specifies the CHxN line mode.
  * @retval None
  */
void TIMER_ChnNOutModeConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, uint32_t Mode)
{
  __IO uint32_t *tmpreg_CH_CNTRL1x;
  uint32_t tmpreg_CH_CNTRL1;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_CHANNEL_NUMBER(Channel));
  assert_param(IS_TIMER_CHO_MODE(Mode));

  tmpreg_CH_CNTRL1x = &TIMERx->CH1_CNTRL1 + Channel;

  tmpreg_CH_CNTRL1 = *tmpreg_CH_CNTRL1x;
  tmpreg_CH_CNTRL1 &= ~TIMER_CH_CNTRL1_NSELOE_Msk;
  tmpreg_CH_CNTRL1 += Mode << TIMER_CH_CNTRL1_NSELOE_Pos;
  *tmpreg_CH_CNTRL1x = tmpreg_CH_CNTRL1;
}

/**
  * @brief  Configures the TIMERx NChannel Output polarity.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  Channel: specifies the Timer Channel number.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CHANNEL1: specifies TIMERx Channel 1;
  *           @arg TIMER_CHANNEL2: specifies TIMERx Channel 2;
  *           @arg TIMER_CHANNEL3: specifies TIMERx Channel 3;
  *           @arg TIMER_CHANNEL4: specifies TIMERx Channel 4.
  * @param  Polarity: enables or disables the NChannel Output inversion.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CHOPolarity_NonInverted: no inversion on the NChannel output;
  *           @arg TIMER_CHOPolarity_Inverted:    the NChannel output is inverted.
  * @retval None
  */
void TIMER_ChnNOutPolarityConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Channel, uint32_t Polarity)
{
  __IO uint32_t *tmpreg_CH_CNTRL1x;
  uint32_t tmpreg_CH_CNTRL1;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_CHANNEL_NUMBER(Channel));
  assert_param(IS_TIMER_CHO_POLARITY(Polarity));

  tmpreg_CH_CNTRL1x = &TIMERx->CH1_CNTRL1 + Channel;

  tmpreg_CH_CNTRL1 = *tmpreg_CH_CNTRL1x;
  tmpreg_CH_CNTRL1 &= ~TIMER_CH_CNTRL1_NINV;
  tmpreg_CH_CNTRL1 += Polarity << TIMER_CH_CNTRL1_NINV_Pos;
  *tmpreg_CH_CNTRL1x = tmpreg_CH_CNTRL1;
}

/**
  * @brief  Configures the TIMERx Dead Time Generator (DTG) peripheral.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  Channel: specifies the Timer Channel number.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CHANNEL1: specifies TIMERx Channel 1;
  *           @arg TIMER_CHANNEL2: specifies TIMERx Channel 2;
  *           @arg TIMER_CHANNEL3: specifies TIMERx Channel 3;
  *           @arg TIMER_CHANNEL4: specifies TIMERx Channel 4.
  * @param  MainPrescaler: specifies the Main Prescaler value.
  *         This parameter can be a number between 0x0000 and 0x00FF.
  * @param  AuxPrescaler: specifies the Auxiliary Prescaler value.
  *         This parameter can be a number between 0x0000 and 0x000F.
  * @param  ClockSource: specifies the DTG clock source.
  *         This parameter can be one of the following values:
  *           @arg TIMER_CH_DTG_ClkSrc_TIMER_CLK: specifies the TIMER_CLK signal as DTG clock source;
  *           @arg TIMER_CH_DTG_ClkSrc_FDTS:      specifies the FDTS signal as DTG clock source.
  * @retval None
  */
void TIMER_ChnOutDTGConfig(MDR_TMR_TypeDef* TIMERx, uint32_t Channel,
                         uint32_t MainPrescaler, uint32_t AuxPrescaler, uint32_t ClockSource)
{
  uint32_t tmpreg_CH_DTG;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_CHANNEL_NUMBER(Channel));
  assert_param(IS_TIMER_CHANNEL_DTG_MAIN_PRESCALER(MainPrescaler));
  assert_param(IS_TIMER_CHANNEL_DTG_AUX_PRESCALER(AuxPrescaler));
  assert_param(IS_TIMER_CHANNEL_DTG_CLK_SOURCE(ClockSource));

  tmpreg_CH_DTG = (MainPrescaler << TIMER_CH_DTG_Pos)
                + (AuxPrescaler  << TIMER_CH_DTGX_Pos)
                + ClockSource;

  *(&TIMERx->CH1_DTG + Channel) = tmpreg_CH_DTG;
}

/**
  * @brief  Returns the TIMERx Status Register value.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @retval The TIMERx_STATUS Register value.
  */
uint32_t TIMER_GetStatus(MDR_TMR_TypeDef* TIMERx)
{
  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));

  return (TIMERx->STATUS);
}

/**
  * @brief  Checks whether the specified TIMERx Status flag is set or not.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  Flag: specifies the flag to check.
  *         This parameter can be one of the following values:
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
  * @retval Current Status flag state (SET or RESET).
  */
FlagStatus TIMER_GetFlagStatus(MDR_TMR_TypeDef* TIMERx, uint32_t Flag)
{
  FlagStatus bitstatus;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_STATUS_FLAG(Flag));

  if ((TIMERx->STATUS & Flag) == 0)
  {
    bitstatus = RESET;
  }
  else
  {
    bitstatus = SET;
  }

  return bitstatus;
}

/**
  * @brief  Clears the TIMERx's pending flags.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  Flags: specifies the flag bit mask to clear.
  *         This parameter can be any combination of the following values:
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
void TIMER_ClearFlag(MDR_TMR_TypeDef* TIMERx, uint32_t Flags)
{
  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_STATUS(Flags));

  TIMERx->STATUS &= ~Flags;
}

/**
  * @brief  Enables or disables the TIMERx’s DMA Requests.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  TIMER_DMASource: specifies the DMA Request sources.
  *         This parameter can be any combination of the following values:
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
  * @param	TIMER_DMAChannel: specifies the DMA channel.
  * 		@note 	Available only for MC MDR1986VE1T and MC MDR1986BE3
  * 		This parameter can be any combination of the following values:
  * 			@arg TIMER_DMA_Channel0
  * 			@arg TIMER_DMA_Channel1
  * 			@arg TIMER_DMA_Channel2
  * 			@arg TIMER_DMA_Channel3
  * 			@arg TIMER_DMA_Channel4
  * @param  NewState: new state of the DMA Request sources.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
#if defined (USE_MDR1986VE1T) || defined (USE_MDR1986VE3)
void TIMER_DMACmd(MDR_TIMER_TypeDef* TIMERx, uint32_t TIMER_DMASource, uint32_t TIMER_DMAChannel, FunctionalState NewState)
#endif
#if defined (USE_MDR1986VE9x)
void TIMER_DMACmd(MDR_TMR_TypeDef* TIMERx, uint32_t TIMER_DMASource, FunctionalState NewState)
#endif
{
  uint32_t tmpreg_DMA_RE;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_STATUS(TIMER_DMASource));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
#if defined (USE_MDR1986VE1T) || defined (USE_MDR1986VE3)
  if(TIMER_DMAChannel == TIMER_DMA_Channel0){
#endif
	  tmpreg_DMA_RE = TIMERx->DMA_RE;

	  /* Form new value */
	  if (NewState != DISABLE)
	  {
		/* Enable TIMERx DMA Requests by setting bits in the DMA_RE register */
		tmpreg_DMA_RE |= TIMER_DMASource;
	  }
	  else
	  {
		/* Disable TIMERx DMA Requests by clearing bits in the DMA_RE register */
		tmpreg_DMA_RE &= ~TIMER_DMASource;
	  }

	  /* Configure CNTRL register with new value */
	  TIMERx->DMA_RE = tmpreg_DMA_RE;
#if defined (USE_MDR1986VE1T) || defined (USE_MDR1986VE3)
  }
  else{
	  tmpreg_DMA_RE = TIMERx->DMA_REChx[TIMER_DMAChannel];

	  /* Form new value */
	  if (NewState != DISABLE)
	  {
		/* Enable TIMERx DMA Requests by setting bits in the DMA_RE register */
		tmpreg_DMA_RE |= TIMER_DMASource;
	  }
	  else
	  {
		/* Disable TIMERx DMA Requests by clearing bits in the DMA_RE register */
		tmpreg_DMA_RE &= ~TIMER_DMASource;
	  }

	  /* Configure CNTRL register with new value */
	  TIMERx->DMA_REChx[TIMER_DMAChannel] = tmpreg_DMA_RE;

  }
#endif
}

/**
  * @brief  Enables or disables the specified TIMER interrupts.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  TIMER_IT: specifies the TIMER interrupts sources to be enabled or disabled.
  *         This parameter can be any combination of the following values:
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
  * @param  NewState: new state of the TIMER interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void TIMER_ITConfig(MDR_TMR_TypeDef* TIMERx, uint32_t TIMER_IT, FunctionalState NewState)
{
  uint32_t tmpreg_IE;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_STATUS(TIMER_IT));
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  tmpreg_IE = TIMERx->IE;

  /* Form new value */
  if (NewState != DISABLE)
  {
    /* Enable the TIMERx Interrupt requests by setting bits in the IE register */
    tmpreg_IE |= TIMER_IT;
  }
  else
  {
    /* Disable the TIMERx Interrupt requests by clearing bits in the IE register */
    tmpreg_IE &= ~TIMER_IT;
  }

  /* Configure CNTRL register with new value */
  TIMERx->IE = tmpreg_IE;
}

/**
  * @brief  Checks whether the TIMERx interrupt has occurred or not.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  TIMER_IT: specifies the TIMER interrupt source to check.
  *         This parameter can be one of the following values:
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
  * @retval The new state of the TIMER_IT (SET or RESET).
  */
ITStatus TIMER_GetITStatus(MDR_TMR_TypeDef* TIMERx, uint32_t TIMER_IT)
{
  ITStatus bitstatus;
  uint32_t tmpreg;

  /* Check the parameters */
  assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
  assert_param(IS_TIMER_STATUS_FLAG(TIMER_IT));

  tmpreg = TIMERx->STATUS & TIMERx->IE & TIMER_IT;

  if (tmpreg == 0)
  {
    bitstatus = RESET;
  }
  else
  {
    bitstatus = SET;
  }

  return bitstatus;
}

/**
  * @brief  Initializes the TIMERx peripheral Clock according to the
  *         specified parameters.
  * @param  TIMERx: where x can be 1 to 3 to select the TIMER peripheral.
  * @param  TIMER_BRG: specifies the HCLK division factor.
  *         This parameter can be one of the following values:
  *           @arg TIMER_HCLKdiv1:   no division of input frequency;
  *           @arg TIMER_HCLKdiv2:   selects input frequency divider by 2;
  *           @arg TIMER_HCLKdiv4:   selects input frequency divider by 4;
  *           @arg TIMER_HCLKdiv8:   selects input frequency divider by 8;
  *           @arg TIMER_HCLKdiv16:  selects input frequency divider by 16;
  *           @arg TIMER_HCLKdiv32:  selects input frequency divider by 32;
  *           @arg TIMER_HCLKdiv64:  selects input frequency divider by 64;
  *           @arg TIMER_HCLKdiv128: selects input frequency divider by 128.
  * @retval None
  */
void TIM_CLK_en(uint32_t TIMx, uint32_t TIM_CLK_DIV)
{
  uint32_t tmpreg;

	if (TIMx==TIM0){
  tmpreg = CLK_CNTR->TIM0_CLK;

  tmpreg |=  TIM_CLK_EN;
  tmpreg &= ~TIM_DIV_Msk;
  tmpreg |=  TIM_CLK_DIV;

  CLK_CNTR->TIM0_CLK = tmpreg;
	}
	
	if (TIMx==TIM1){
  tmpreg = CLK_CNTR->TIM1_CLK;

  tmpreg |=  TIM_CLK_EN;
  tmpreg &= ~TIM_DIV_Msk;
  tmpreg |=  TIM_CLK_DIV;

  CLK_CNTR->TIM1_CLK = tmpreg;
	}
	
	if (TIMx==TIM2){
  tmpreg = CLK_CNTR->TIM2_CLK;

  tmpreg |=  TIM_CLK_EN;
  tmpreg &= ~TIM_DIV_Msk;
  tmpreg |=  TIM_CLK_DIV;

  CLK_CNTR->TIM2_CLK = tmpreg;
	}
	
	if (TIMx==TIM3){
  tmpreg = CLK_CNTR->TIM3_CLK;

  tmpreg |=  TIM_CLK_EN;
  tmpreg &= ~TIM_DIV_Msk;
  tmpreg |=  TIM_CLK_DIV;

  CLK_CNTR->TIM3_CLK = tmpreg;
	}
	
}

void  TIMER_BRGInit (MDR_TMR_TypeDef* TIMERx, uint32_t TIM_CLK_DIV)
{
  uint32_t tmpreg;

	if (TIMERx == MDR_TMR0){
  tmpreg = CLK_CNTR->TIM0_CLK;

  tmpreg |=  TIM_CLK_EN;
  tmpreg &= ~TIM_DIV_Msk;
  tmpreg |=  TIM_CLK_DIV;

  CLK_CNTR->TIM0_CLK = tmpreg;
	}
	
	if (TIMERx==MDR_TMR1){
  tmpreg = CLK_CNTR->TIM1_CLK;

  tmpreg |=  TIM_CLK_EN;
  tmpreg &= ~TIM_DIV_Msk;
  tmpreg |=  TIM_CLK_DIV;

  CLK_CNTR->TIM1_CLK = tmpreg;
	}
	
	if (TIMERx==MDR_TMR2){
  tmpreg = CLK_CNTR->TIM2_CLK;

  tmpreg |=  TIM_CLK_EN;
  tmpreg &= ~TIM_DIV_Msk;
  tmpreg |=  TIM_CLK_DIV;

  CLK_CNTR->TIM2_CLK = tmpreg;
	}
	
	if (TIMERx==MDR_TMR3){
  tmpreg = CLK_CNTR->TIM3_CLK;

  tmpreg |=  TIM_CLK_EN;
  tmpreg &= ~TIM_DIV_Msk;
  tmpreg |=  TIM_CLK_DIV;

  CLK_CNTR->TIM3_CLK = tmpreg;
	}

}

/** @} */ /* End of group TIMER_Private_Functions */

/** @} */ /* End of group TIMER */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

/******************* (C) COPYRIGHT 2010 Phyton *********************************
*
* END OF FILE MDR32F9Qx_timer.c */

