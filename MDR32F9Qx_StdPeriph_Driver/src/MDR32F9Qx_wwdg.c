/**
  * FILE MDR32F9Qx_wwdg.c
  */
/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_wwdg.h"
#include "MDR32F9Qx_rst_clk.h"


#define ASSERT_INFO_FILE_ID FILEID__MDR32F9X_WWDG_C

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @defgroup WWDG WWDG
  * @{
  */

/** @defgroup WWDG_Private_TypesDefinitions WWDG Private Types Definitions
  * @{
  */

/** @} */ /* End of group WWDG_Private_TypesDefinitions */

/** @defgroup WWDG_Private_Defines WWDG Private Defines
  * @{
  */

#if defined (USE_MDR1986VE9x) || defined (USE_MDR1901VC1T)
/* WWDG registers bit address in the alias region */
#define PERIPH_BASE                 0x40000000
#define PERIPH_BB_BASE              0x42000000
#define WWDG_OFFSET                 (MDR_WWDG_BASE - PERIPH_BASE)

#define SFR_OFFSET(TP, MOD, SFR)    ((uint32_t)&((TP*)MOD)->SFR)
#define BB_ADDR(TP, MOD, SFR, BIT)  (PERIPH_BB_BASE + SFR_OFFSET(TP, MOD, SFR)*32 + BIT*4)
#define WWDG_BB(SFR, BIT)           BB_ADDR(MDR_WWDG_TypeDef, WWDG_OFFSET, SFR, BIT)

#define EWI_BB                      WWDG_BB(CFR, WWDG_CFR_EWI_Pos)
#endif

/* --------------------- WWDG registers bit mask ------------------------ */

/* CR register bit mask */
#define WDGA_Mask         ((uint32_t)0x00000080)

/* CFR register bit mask */
#define WDGTB_Mask        ((uint32_t)0xFFFFFE7F)
#define WIN_Mask          ((uint32_t)0x7F)
#define CTR_Mask          ((uint32_t)0x7F)

/** @} */ /* End of group WWDG_Private_Defines */

/** @defgroup WWDG_Private_Macros WWDG Private Macros
  * @{
  */

/** @} */ /* End of group WWDG_Private_Macros */

/** @defgroup WWDG_Private_Variables WWDG Private Variables
  * @{
  */

/** @} */ /* End of group WWDG_Private_Variables */

/** @defgroup WWDG_Private_Functions WWDG Private Functions
  * @{
  */

/**
  * @brief  WWDG_DeInit - Deinitializes the WWDG peripheral registers to their default reset values.
  * @param  None
  * @retval None
  */
void WWDG_DeInit(void)
{
  RST_CLK_PCLKcmd(RST_CLK_PCLK_WWDG, ENABLE);
  RST_CLK_PCLKcmd(RST_CLK_PCLK_WWDG, DISABLE);
}

/**
  * @brief  WWDG_SetPrescaler - Sets the WWDG Prescaler.
  * @param  WWDG_Prescaler: specifies the WWDG Prescaler.
  *   This parameter can be one of the following values:
  *     @arg WWDG_Prescaler_1: WWDG counter clock = (PCLK1/4096)/1
  *     @arg WWDG_Prescaler_2: WWDG counter clock = (PCLK1/4096)/2
  *     @arg WWDG_Prescaler_4: WWDG counter clock = (PCLK1/4096)/4
  *     @arg WWDG_Prescaler_8: WWDG counter clock = (PCLK1/4096)/8
  * @retval None
  */
void WWDG_SetPrescaler(uint32_t WWDG_Prescaler)
{
  uint32_t tmpreg;
  /* Check the parameters */
  assert_param(IS_WWDG_PRESCALER(WWDG_Prescaler));
  /* Clear WDGTB[1:0] bits */
  tmpreg = MDR_WWDG->CFR & WDGTB_Mask;
  /* Set WDGTB[1:0] bits according to WWDG_Prescaler value */
  tmpreg |= WWDG_Prescaler;
  /* Store the new value */
  MDR_WWDG->CFR = tmpreg;
}

/**
  * @brief  WWDG_SetWindowValue - Sets the WWDG window value.
  * @param  WindowValue: specifies the window value to be compared to the downcounter.
  *   This parameter value must be lower than 0x80.
  * @retval None
  */
void WWDG_SetWindowValue(uint32_t WindowValue)
{
  __IO uint32_t tmpreg = 0;

  /* Check the parameters */
  assert_param(IS_WWDG_WINDOW_VALUE(WindowValue));
  /* Clear W[6:0] bits */

  tmpreg = MDR_WWDG->CFR & (uint32_t) (~WIN_Mask);

  /* Set W[6:0] bits according to WindowValue value */
  tmpreg |= WindowValue & (uint32_t) WIN_Mask;

  /* Store the new value */
  MDR_WWDG->CFR = tmpreg;
}

/**
  * @brief  WWDG_EnableIT - Enables the WWDG Early Wakeup interrupt(EWI).
  * @param  None
  * @retval None
  */
void WWDG_EnableIT ( void )
{
#if defined (USE_MDR1986VE9x) || defined (USE_MDR1901VC1T)
	*(__IO uint32_t *) EWI_BB = (uint32_t) ENABLE;
#elif defined (USE_MDR1986VE3) || defined (USE_MDR1986VE1T)
	MDR_WWDG->CFR |= WWDG_CFR_EWI;
#endif
}

/**
  * @brief  WWDG_SetCounter - Sets the WWDG counter value.
  * @param  Counter: specifies the watchdog counter value.
  *   This parameter must be a number between 0x00 and 0x7F.
  * @retval None
  */
void WWDG_SetCounter(uint32_t Counter)
{
  /* Check the parameters */
  assert_param(IS_WWDG_COUNTER(Counter));
  /* Write to T[6:0] bits to configure the counter value, no need to do
     a read-modify-write; writing a 0 to WDGA bit does nothing */

  MDR_WWDG->CR = Counter & CTR_Mask;
}

/**
  * @brief  WWDG_Enable - Enables WWDG and load the counter value.
  * @param  Counter: specifies the watchdog counter value.
  *   This parameter must be a number between 0x00 and 0x7F.
  * @retval None
  */
void WWDG_Enable(uint32_t Counter)
{
  /* Check the parameters */
  assert_param(IS_WWDG_COUNTER(Counter));
  MDR_WWDG->CR = WDGA_Mask | Counter;
}

/**
  * @brief  WWDG_GetFlagStatus - Checks whether the Early Wakeup interrupt flag is set or not.
  * @param  None
  * @retval The new state of the Early Wakeup interrupt flag (SET or RESET)
  */
FlagStatus WWDG_GetFlagStatus(void)
{
  return (FlagStatus)(MDR_WWDG->SR);
}

/**
  * @brief  WWDG_ClearFlag - Clears Early Wakeup interrupt flag.
  * @param  None
  * @retval None
  */
void WWDG_ClearFlag(void)
{
  MDR_WWDG->SR = (uint32_t)RESET;
}

/** @} */ /* End of group WWDG_Private_Functions */

/** @} */ /* End of group WWDG */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

/*
*
* END OF FILE MDR32F9Qx_wwdg.c */

