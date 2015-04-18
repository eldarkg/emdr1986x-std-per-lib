/**
  ******************************************************************************
  * @file    MDR32F9Qx_power.c
  * @author  Phyton Application Team
  * @version V1.4.0
  * @date    21/07/2011
  * @brief   This file contains all the POWER firmware functions.
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
  * FILE MDR32F9Qx_power.c
  */
/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_config.h"
#include "MDR32F9Qx_power.h"
#include "MDR32F9Qx_rst_clk.h"


#define ASSERT_INFO_FILE_ID FILEID__MDR32F9X_POWER_C

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @defgroup POWER POWER
  * @{
  */

/** @defgroup POWER_Private_TypesDefinitions POWER Private Types Definitions
  * @{
  */

/** @} */ /* End of group POWER_Private_TypesDefinitions */

/** @defgroup POWER_Private_Defines POWER Private Defines
  * @{
  */

#if defined (USE_MDR1986VE9x) /* For Cortex M3 */
/* POWER registers bit address in the alias region */
#define PERIPH_BASE                 0x40000000
#define PERIPH_BB_BASE              0x42000000
#define POWER_OFFSET                (MDR_POWER_BASE - PERIPH_BASE)
#define BKP_OFFSET                  (MDR_BKP_BASE - PERIPH_BASE)

#define SFR_OFFSET(TP, MOD, SFR)    ((uint32_t)&((TP*)MOD)->SFR)
#define BB_ADDR(TP, MOD, SFR, BIT)  (PERIPH_BB_BASE + SFR_OFFSET(TP, MOD, SFR)*32 + BIT*4)
#define POWER_BB(SFR, BIT)          BB_ADDR(MDR_POWER_TypeDef, POWER_OFFSET, SFR, BIT)
#define BKP_BB(SFR, BIT)            BB_ADDR(MDR_BKP_TypeDef, BKP_OFFSET, SFR, BIT)

#define POWER_PVDEN_BB              POWER_BB(PVDCS, POWER_PVDCS_PVDEN_Pos)

#define BKP_FPOR_BB                 BKP_BB(REG_0E, BKP_REG_0E_FPOR_Pos)
#define BKP_STANDBY_BB              BKP_BB(REG_0F, BKP_REG_0F_STANDBY_Pos)

#endif //  #if defined (USE_MDR1986VE9x) /* For Cortex M3 */

/* --------------------- POWER registers bit mask ------------------------ */

/* BKP_REG0E register bit mask */
#define DUcc_Mask         ((uint32_t)(BKP_REG_0E_LOW_Msk | BKP_REG_0E_SELECTRI_Msk))
#define DUccTrim_Mask     ((uint32_t)BKP_REG_0E_TRIM_Msk)

/* PVDCS register bit mask */

/** @} */ /* End of group POWER_Private_Defines */

/** @defgroup POWER_Private_Macros POWER Private Macros
  * @{
  */

/** @} */ /* End of group POWER_Private_Macros */

/** @defgroup POWER_Private_Variables POWER Private Variables
  * @{
  */

/** @} */ /* End of group POWER_Private_Variables */

/** @defgroup POWER_Private_Function_Prototypes POWER Private Function Prototypes
  * @{
  */

/** @} */ /* End of group POWER_Private_FunctionPrototypes */

/** @defgroup POWER_Private_Functions POWER Private Functions
  * @{
  */

/**
  * @brief  Deinitializes the POWER peripheral registers to their default reset values.
  * @param  None
  * @retval None
  */
void POWER_DeInit(void)
{
  MDR_POWER -> PVDCS = (uint32_t) 0x00000000;
}

/**
  * @brief  POWER_SET_DUCC_MODE - Select the internal voltage regulator mode
  * @param  DUccMode: specifies the DUcc mode.
  *   This parameter can be one of the following values:
  *     @arg POWER_DUcc_upto_10MHz:  system clock is up to 10 MHz
  *     @arg POWER_DUcc_upto_200kHz: system clock is up to 200 kHz
  *     @arg POWER_DUcc_upto_500kHz: system clock is up to 500 kHz
  *     @arg POWER_DUcc_clk_off:   all clocks are switnhed off
  *     @arg POWER_DUcc_upto_1MHz:   system clock is up to 1 MHz
  *     @arg POWER_DUcc_upto_40MHz:  system clock is up to 40 MHz
  *     @arg POWER_DUcc_upto_80MHz:  system clock is up to 80 MHz
  *     @arg POWER_DUcc_over_80MHz:  system clock is over 80 MHz
  * @retval None
  */
void POWER_DUccMode(uint32_t DUccMode)
{
  uint32_t tmpreg;
  /* Check the parameters */
  assert_param(IS_POWER_DUCC_MODE(DUccMode));
  /* Clear POWER_REG0E[5:0] bits */
  tmpreg  = MDR_BKP -> REG_0E & (uint32_t) (~DUcc_Mask);
  /* Set POWER_REG0E[5:0] bits according to DUcc mode */
  tmpreg |= DUcc_Mask & DUccMode;
  MDR_BKP -> REG_0E = tmpreg;
}

/**
  * @brief  POWER_SET_DUCC_TRIM - Set the internal voltage regulator trim
  * @param  DUccTrim: specifies the DUcc trim.
  *   This parameter can be one of the following values:
  *     @arg POWER_DUcc_plus_100mV:  trim DUcc with + 100mV
  *     @arg POWER_DUcc_plus_060mV:  trim DUcc with + 060mV
  *     @arg POWER_DUcc_plus_040mV:  trim DUcc with + 040mV
  *     @arg POWER_DUcc_plus_010mV:  trim DUcc with + 010mV
  *     @arg POWER_DUcc_minus_010mV: trim DUcc with - 010mV
  *     @arg POWER_DUcc_minus_040mV: trim DUcc with - 040mV
  *     @arg POWER_DUcc_minus_060mV: trim DUcc with - 060mV
  *     @arg POWER_DUcc_minus_100mV: trim DUcc with - 100mV
  * @retval None
  */
void POWER_DUccTrim(uint32_t DUccTrim)
{
  uint32_t tmpreg;
  /* Check the parameters */
  assert_param(IS_POWER_DUCC_TRIM(DUccTrim));
  /* Clear POWER_REG0E[5:0] bits */
  tmpreg  = MDR_BKP -> REG_0E & (uint32_t) (~DUccTrim_Mask);
  /* Set POWER_REG0E[5:0] bits according to DUcc mode */
  tmpreg |= DUccTrim_Mask & DUccTrim;
  MDR_BKP -> REG_0E = tmpreg;
}

/**
  * @brief  POWER_DUccStandby - Enter standby mode.
  * @param  None
  * @retval None
  */
void POWER_DUccStandby ( void )
{
#if defined (USE_MDR1986VE9x)
*(__IO uint32_t *) BKP_STANDBY_BB = (uint32_t) 0x01;
#elif defined (USE_MDR1986VE3)
	MDR_BKP->REG_0F |= BKP_REG_0F_STANDBY;
#endif

}

/**
  * @brief  POWER_PVDlevelConfig - Configures the voltage threshold detected
  *         by the Power Voltage Detector(PVD).
  * @param  POWER_PVDlevel: specifies the PVD detection level
  *   This parameter can be one of the following values:
  *     @arg PWR_PVDlevel_2V0: PVD detection level set to 2.0V
  *     @arg PWR_PVDlevel_2V2: PVD detection level set to 2.2V
  *     @arg PWR_PVDlevel_2V4: PVD detection level set to 2.4V
  *     @arg PWR_PVDlevel_2V6: PVD detection level set to 2.6V
  *     @arg PWR_PVDlevel_2V8: PVD detection level set to 2.8V
  *     @arg PWR_PVDlevel_3V0: PVD detection level set to 3.0V
  *     @arg PWR_PVDlevel_3V2: PVD detection level set to 3.2V
  *     @arg PWR_PVDlevel_3V4: PVD detection level set to 3.4V
  * @retval None
  */
void POWER_PVDlevelConfig(uint32_t POWER_PVDlevel)
{
  uint32_t tmpreg;
  /* Check the parameters */
  assert_param(IS_POWER_PVD_LEVEL(POWER_PVDlevel));
  tmpreg = MDR_POWER->PVDCS;
  /* Clear PLS[5:3] bits */
  tmpreg &= (uint32_t) ~POWER_PVDCS_PLS_Msk;
  /* Set PLS[5:3] bits according to POWER_PVDlevel value */
  tmpreg |= (POWER_PVDlevel & POWER_PVDCS_PLS_Msk);
  /* Store the new value */
  MDR_POWER->PVDCS = tmpreg;
}

/**
  * @brief  POWER_PVBDlevelConfig - Configures the voltage threshold detected
  *         by the Power Battery Voltage Detector(PVBD).
  * @param  POWER_PVBDlevel: specifies the PVBD detection level
  *   This parameter can be one of the following values:
  *     @arg PWR_PVBDlevel_1V8: PVBD detection level set to 1.8V
  *     @arg PWR_PVBDlevel_2V2: PVBD detection level set to 2.2V
  *     @arg PWR_PVBDlevel_2V6: PVBD detection level set to 2.6V
  *     @arg PWR_PVBDlevel_3V0: PVBD detection level set to 3.0V
  * @retval None
  */
void POWER_PVBDlevelConfig(uint32_t POWER_PVBDlevel)
{
  uint32_t tmpreg;
  /* Check the parameters */
  assert_param(IS_POWER_PVBD_LEVEL(POWER_PVBDlevel));
  tmpreg = MDR_POWER->PVDCS;
  /* Clear PBLS[2:1] bits */
  tmpreg &= (uint32_t) ~POWER_PVDCS_PBLS_Msk;
  /* Set PBLS[2:1] bits according to POWER_PVBDlevel value */
  tmpreg |= (POWER_PVBDlevel & POWER_PVDCS_PBLS_Msk);
  /* Store the new value */
  MDR_POWER->PVDCS = tmpreg;
}

/**
  * @brief  POWER_SetFlagPOR - Set power on reset flag (FPOR).
  * @param  None
  * @retval None
  */
void POWER_SetFlagPOR ( void )
{
#if defined (USE_MDR1986VE9x)
	*(__IO uint32_t *) BKP_FPOR_BB = (uint32_t) 0x01;
#elif defined (USE_MDR1986VE3) || defined (USE_MDR1986VE1T)
	MDR_BKP->REG_0E |= BKP_REG_0E_FPOR;
#endif
}

/**
  * @brief  POWER_FlagPORstatus - power on reset flag (FPOR) status
  * @param  None
  * @retval enum ErrorStatus - SUCCESS if FPOR is zero, else ERROR
  */
ErrorStatus POWER_FlagPORstatus(void)
{
  ErrorStatus state = ERROR;
#if defined (USE_MDR1986VE9x)
  if (*(__IO uint32_t *) BKP_FPOR_BB == 0)
  {
    state = SUCCESS;
  }
#elif defined (USE_MDR1986VE3) || defined (USE_MDR1986VE1T)
  if (( MDR_BKP->REG_0E & BKP_REG_0E_FPOR ) == BKP_REG_0E_FPOR) {
	  state = SUCCESS;
  }
#endif
  return state;
}

/**
  * @brief  POWER_PVDenable - Enables or disables the Power Voltage Detectors (PVD, PVBD).
  * @param  NewState: new state of the PVDs.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void POWER_PVDenable ( FunctionalState NewState )
{
	/* Check the parameters */
	assert_param(IS_FUNCTIONAL_STATE(NewState));
#if defined (USE_MDR1986VE9x)
	*(__IO uint32_t *) POWER_PVDEN_BB = (uint32_t) NewState;
#elif defined (USE_MDR1986VE3) || defined (USE_MDR1986VE1T)
	if(NewState != DISABLE){
		MDR_POWER->PVDCS |= POWER_PVDCS_PVDEN;
	}
	else {
		MDR_POWER->PVDCS &= ~POWER_PVDCS_PVDEN;
	}
#endif
}

/**
  * @brief  POWER_GetFlagStatus - Checks whether the specified
  * POWER detection flag is set or not.
  * @param  POWER_FLAG: specifies the flag to check.
  *   This parameter can be one of the following values:
  *     @arg POWER_FLAG_PVD: PVD Output
  *     @arg POWER_FLAG_PVBD: PVBD Output
  * @retval The new state of POWER_FLAG (SET or RESET).
  */
FlagStatus POWER_GetFlagStatus(uint32_t POWER_FLAG)
{
  FlagStatus status;
  /* Check the parameters */
  assert_param(IS_POWER_FLAG(POWER_FLAG));

  if ((MDR_POWER->PVDCS & POWER_FLAG) != (uint32_t)RESET)
  {
    status = SET;
  }
  else
  {
    status = RESET;
  }
  /* Return the flag status */
  return status;
}

/**
  * @brief  POWER_ClearFlag - Clears the POWER's pending flags.
  * @param  POWER_FLAG: specifies the flag to clear.
  *   This parameter can be one of the following values:
  *     @arg POWER_FLAG_PVD: Power voltage detection flag
  *     @arg POWER_FLAG_PVBD: Battery voltage detection flag
  * @retval None
  */
void POWER_ClearFlag(uint32_t POWER_FLAG)
{
  /* Check the parameters */
  assert_param(IS_POWER_FLAG(POWER_FLAG));

  MDR_POWER->PVDCS &= (uint32_t) ~POWER_FLAG;
}

/**
  * @brief  POWER_PVD_ITconfig - Enables or disables the specified POWER interrupts.
  * @param  POWER_IT: specifies the PVD interrupts sources to be enabled or disabled.
  *   This parameter can be any combination of the following values:
  *     @arg  POWER_PVD_IT:  PVD interrupt enable
  *     @arg  POWER_PVBD_IT:  PVBD interrupt enable
  * @param  NewState: new state of the specified POWER interrupts.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void POWER_PVD_ITconfig(uint32_t POWER_IT, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_POWER_PVD_IT(POWER_IT));
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  if (NewState != DISABLE)
  {
    MDR_POWER->PVDCS |= POWER_IT;
  }
  else
  {
    MDR_POWER->PVDCS &= (uint32_t)~POWER_IT;
  }
}

/**
  * @brief  POWER_PVD_INVconfig - Enables or disables inversion of the
  * specified POWER voltage detection flags
  * @param  POWER_INV: specifies the PVD interrupts sources to be enabled or disabled.
  *   This parameter can be any combination of the following values:
  *     @arg  POWER_PVD_INV: PVD inversion enable
  *     @arg  POWER_PVBD_INV: PVBD inversion enable
  * @param  NewState: new state of the specified POWER voltage flag inversion.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void POWER_PVD_INVconfig(uint32_t POWER_INV, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_POWER_PVD_INV(POWER_INV));
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  if (NewState != DISABLE)
  {
    MDR_POWER->PVDCS |= POWER_INV;
  }
  else
  {
    MDR_POWER->PVDCS &= (uint32_t)~POWER_INV;
  }
}
#if defined (USE_MDR1986VE9x)
/**
  * @brief  Enters STOP mode.
  * @param  POWER_Regulator_state: specifies the regulator state in STOP mode.
  *   This parameter can be: ENABLE or DISABLE.
  *     @arg ENABLE: STOP mode with regulator ON
  *     @arg DISABLE: STOP mode with regulator in low power mode
  * @param  POWER_STOPentry: specifies if STOP mode in entered with WFI or WFE instruction.
  *   This parameter can be one of the following values:
  *     @arg POWER_STOPentry_WFI: enter STOP mode with WFI instruction
  *     @arg POWER_STOPentry_WFE: enter STOP mode with WFE instruction
  * @retval None
  */
void POWER_EnterSTOPMode(FunctionalState POWER_Regulator_state, uint8_t POWER_STOPentry)
{
  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(POWER_Regulator_state));
  assert_param(IS_POWER_STOP_ENTRY(POWER_STOPentry));

  /* Set UDcc stanby status */

   *(__IO uint32_t *) BKP_STANDBY_BB = (uint32_t) (!POWER_Regulator_state);
   /* Set SLEEPDEEP bit of Cortex System Control Register */
   *(__IO uint32_t *) SCB -> SCR |= SCB_SCR_SLEEPDEEP_Msk;

   if(POWER_Regulator_state == ENABLE){
	   MDR_BKP->REG_0F &= ~BKP_REG_0F_STANDBY;
   }
   else{
	   MDR_BKP->REG_0F |= BKP_REG_0F_STANDBY;
   }
  /* Select STOP mode entry --------------------------------------------------*/
  if(POWER_STOPentry == POWER_STOPentry_WFI)
  {
    /* Request Wait For Interrupt */
    __WFI();
  }
  else
  {
    /* Request Wait For Event */
    __WFE();
  }
}
#elif defined (USE_MDR1986VE1T) || defined (USE_MDR1986VE3)

/**
  * @brief	Shifting core controller into a low power consumption. In this mode,
  * 		the clock frequency is applied only to the selected peripheral
  * 		blocks, which interrupt the supply resumes clock on the core.
  * @param	None
  * @retval None
  */
void POWER_EnterSLEEPMode(void)
{
	/* Enter in SLEEP mode */
	MDR_RST_CLK->ETH_CLOCK |= 1 << RST_CLK_ETH_CLOCK_SLEEP_Pos;
}

#endif

/**
  * @brief  Enters STANDBY mode.
  * @param  None
  * @retval None
  */
void POWER_EnterSTANDBYMode ( void )
{
	/* Select STANDBY mode */
#if defined (USE_MDR1986VE9x)
	*(__IO uint32_t *) BKP_STANDBY_BB = (uint32_t) 0x01;
	/* Set SLEEPDEEP bit of Cortex System Control Register */
	*(__IO uint32_t *) SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
#elif defined (USE_MDR1986VE3) || defined (USE_MDR1986VE1T)
	MDR_BKP->REG_0F |= BKP_REG_0F_STANDBY;
#endif
	/* Request Wait For Interrupt */
	__WFI();
}

#if defined (USE_MDR1986VE1T) || defined (USE_MDR1986VE3)

/**
 * @brief	POWER_SetTrim - Adjustment coefficient of the reference voltage
 * 			integrated voltage regulator DUcc roughly.
 * @param 	trim: coefficient of the reference voltage.
 * 			This parameter can be one the following values:
 * 				@arg POWER_TRIM_1_8_V
 * 				@arg POWER_TRIM_1_6_V
 * 				@arg POWER_TRIM_1_4_V
 * @return	None.
 */
void POWER_SetTrim(uint32_t trim)
{
	uint32_t tmpreg;
	/* Check the parameters */
	assert_param(IS_POWER_TRIM(trim));

	tmpreg = MDR_BKP->REG_0E & (~(3 << BKP_REG_0E_TRIM_34_Pos));
	tmpreg = tmpreg | trim;
	MDR_BKP->REG_0E = tmpreg;
}

#endif

/** @} */ /* End of group POWER_Private_Functions */

/** @} */ /* End of group POWER */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

/******************* (C) COPYRIGHT 2011 Phyton *********************************
*
* END OF FILE MDR32F9Qx_power.c */
