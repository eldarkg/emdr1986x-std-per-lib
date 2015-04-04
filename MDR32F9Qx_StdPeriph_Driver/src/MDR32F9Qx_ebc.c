/**
  ******************************************************************************
  * @file    MDR32F9Qx_ebc.c
  * @author  Phyton Application Team
  * @version V1.3.0
  * @date    22/02/2011
  * @brief   This file provides all the EBC firmware functions.
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
  * FILE MDR32F9Qx_ebc.c
  */

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_config.h"
#include "MDR32F9Qx_ebc.h"


#define ASSERT_INFO_FILE_ID FILEID__MDR32F9X_EBC_C

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @defgroup EBC EBC
  * @{
  */

/** @defgroup EBC_Private_Defines EBC Private Defines
  * @{
  */

#define WAIT_STATES_COEF        1000000
#define WAIT_STATES_MIN         3
#define WAIT_STATES_MAX         18

#define NAND_SYCLES_COEF        1000000
#define NAND_SYCLES_MAX         15

/** @} */ /* End of group EBC_Private_Defines */

/** @defgroup EBC_Private_Functions EBC Private Functions
  * @{
  */

/**
  * @brief  Resets the EBC peripheral registers to their default reset values.
  * @param  None
  * @retval None
  */
void EBC_DeInit(void)
{
  MDR_EBC_TypeDef *EBCx;

  EBCx = MDR_EBC;

  EBCx->CONTROL = 0;
  EBCx->NAND_CYCLES = 0;

#if defined (USE_MDR1986VE3) || defined (USE_MDR1986VE1T) || defined (USE_MDR1986VE94)

  EBCx->MEM_REGION[0] = 0;
  EBCx->MEM_REGION[1] = 0;
  EBCx->MEM_REGION[2] = 0;
  EBCx->MEM_REGION[3] = 0;

#endif /* #if defined (USE_MDR1986VE3) || defined (USE_MDR1986VE1T) */
}

/**
  * @brief  Initializes the EBC peripheral according to the specified
  *         parameters in the EBC_InitStruct.
  * @param  EBC_InitStruct: pointer to a EBC_InitTypeDef structure that
  *         contains the configuration information for the specified EBC peripheral.
  * @retval None
  */
void EBC_Init(const EBC_InitTypeDef* EBC_InitStruct)
{
  MDR_EBC_TypeDef *EBCx;
  uint32_t tmpreg_CONTROL;
  uint32_t tmpreg_CYCLES;

  /* Check the parameters */
  assert_param(IS_EBC_MODE(EBC_InitStruct->EBC_Mode));
  assert_param(IS_EBC_CPOL(EBC_InitStruct->EBC_Cpol));
  assert_param(IS_EBC_WAIT_STATE(EBC_InitStruct->EBC_WaitState));
  assert_param(IS_EBC_NAND_CYCLES(EBC_InitStruct->EBC_NandTrc));
  assert_param(IS_EBC_NAND_CYCLES(EBC_InitStruct->EBC_NandTwc));
  assert_param(IS_EBC_NAND_CYCLES(EBC_InitStruct->EBC_NandTrea));
  assert_param(IS_EBC_NAND_CYCLES(EBC_InitStruct->EBC_NandTwp));
  assert_param(IS_EBC_NAND_CYCLES(EBC_InitStruct->EBC_NandTwhr));
  assert_param(IS_EBC_NAND_CYCLES(EBC_InitStruct->EBC_NandTalea));
  assert_param(IS_EBC_NAND_CYCLES(EBC_InitStruct->EBC_NandTrr));

  /* Form new value for the EBC_CONTROL register */
  tmpreg_CONTROL = (EBC_InitStruct->EBC_Mode)
                 | (EBC_InitStruct->EBC_Cpol)
                 | (EBC_InitStruct->EBC_WaitState << EBC_CONTROL_WAIT_STATE_Pos);

#if defined (USE_MDR1986VE3) || defined (USE_MDR1986VE1T) || defined (USE_MDR1986VE94)

  /* Using the alignment data by LSB EBC */
  tmpreg_CONTROL |= EBC_InitStruct->EBC_DataAlignment;

#endif /* #if defined (USE_MDR1986VE3) || defined (USE_MDR1986VE1T) */

  /* Form new value for the EBC_NAND_CYCLES register */
  tmpreg_CYCLES  = (EBC_InitStruct->EBC_NandTrc       << EBC_NAND_CYCLES_TRC_Pos)
                 | (EBC_InitStruct->EBC_NandTwc       << EBC_NAND_CYCLES_TWC_Pos)
                 | (EBC_InitStruct->EBC_NandTrea      << EBC_NAND_CYCLES_TREA_Pos)
                 | (EBC_InitStruct->EBC_NandTwp       << EBC_NAND_CYCLES_TWP_Pos)
                 | (EBC_InitStruct->EBC_NandTwhr      << EBC_NAND_CYCLES_TWHR_Pos)
                 | (EBC_InitStruct->EBC_NandTalea 	  << EBC_NAND_CYCLES_TALEA_Pos)
                 | (EBC_InitStruct->EBC_NandTrr       << EBC_NAND_CYCLES_TRR_Pos);

  EBCx = MDR_EBC;

  /* Configure EBC registers with new values */
  EBCx->NAND_CYCLES = tmpreg_CYCLES;
  EBCx->CONTROL = tmpreg_CONTROL;
}

/**
  * @brief  Fills each EBC_InitStruct member with its default value.
  * @param  EBC_InitStruct: pointer to a EBC_InitTypeDef structure which will
  *         be initialized.
  * @retval None
  */
void EBC_StructInit(EBC_InitTypeDef* EBC_InitStruct)
{
  /* Reset EBC initialization structure parameters values */
  EBC_InitStruct->EBC_Mode          = EBC_MODE_OFF;
  EBC_InitStruct->EBC_Cpol          = EBC_CPOL_POSITIVE;
  EBC_InitStruct->EBC_WaitState 	= EBC_WAIT_STATE_3HCLK;
  EBC_InitStruct->EBC_NandTrc       = EBC_NAND_CYCLES_0HCLK;
  EBC_InitStruct->EBC_NandTwc       = EBC_NAND_CYCLES_0HCLK;
  EBC_InitStruct->EBC_NandTrea      = EBC_NAND_CYCLES_0HCLK;
  EBC_InitStruct->EBC_NandTwp       = EBC_NAND_CYCLES_0HCLK;
  EBC_InitStruct->EBC_NandTwhr      = EBC_NAND_CYCLES_0HCLK;
  EBC_InitStruct->EBC_NandTalea 	= EBC_NAND_CYCLES_0HCLK;
  EBC_InitStruct->EBC_NandTrr       = EBC_NAND_CYCLES_0HCLK;
#if defined (USE_MDR1986VE3) || defined (USE_MDR1986VE1T) || defined (USE_MDR1986VE94)
  EBC_InitStruct->EBC_DataAlignment = EBC_EBC_DATA_ALIGNMENT_OFF;
  EBC_InitStruct->EBC_UseMemRegion = DISABLE;
#endif /* #if defined (USE_MDR1986VE3) || defined (USE_MDR1986VE1T) */
}

/**
  * @brief  Calculates the Wait States number for selected HCLK frequency and
  *         time interval.
  * @param  HCLK_Frequency_KHz: specifies the HCLK frequency.
  * @param  Time_ns: specifies the time interval.
  * @retval The Wait States number in range 0..15 or 0xFFFFFFFF if result is
  *         out of range 0..15.
  */
uint32_t EBC_CalcWaitStates(uint32_t HCLK_Frequency_KHz, uint32_t Time_ns)
{
  uint32_t Cycles;

  if ( HCLK_Frequency_KHz == 0 )
  {
    Cycles = 0;
  }
  else if ( Time_ns > WAIT_STATES_MAX * WAIT_STATES_COEF / HCLK_Frequency_KHz )
  {
    Cycles = 0xFFFFFFFF;
  }
  else
  {
    Cycles = (HCLK_Frequency_KHz * Time_ns + WAIT_STATES_COEF - 1) / WAIT_STATES_COEF;
    if ( Cycles > WAIT_STATES_MAX)
    {
      Cycles = 0xFFFFFFFF;
    }
    else if ( Cycles >= WAIT_STATES_MIN)
    {
      Cycles -= WAIT_STATES_MIN;
    }
    else
    {
      Cycles = 0;
    }
  }

  return Cycles;
}

/**
  * @brief  Calculates the NAND Sycles number for selected HCLK frequency and
  *         time interval.
  * @param  HCLK_Frequency_KHz: specifies the HCLK frequency.
  * @param  Time_ns: specifies the time interval.
  * @retval The NAND Sycles number in range 0..15 or 0xFFFFFFFF if result is
  *         out of range 0..15.
  */
uint32_t EBC_CalcNandCycles(uint32_t HCLK_Frequency_KHz, uint32_t Time_ns)
{
  uint32_t Cycles;

  if ( HCLK_Frequency_KHz == 0 )
  {
    Cycles = 0;
  }
  else if ( Time_ns > NAND_SYCLES_MAX * NAND_SYCLES_COEF / HCLK_Frequency_KHz )
  {
    Cycles = 0xFFFFFFFF;
  }
  else
  {
    Cycles = (HCLK_Frequency_KHz * Time_ns + NAND_SYCLES_COEF - 1) / NAND_SYCLES_COEF;
    if ( Cycles > NAND_SYCLES_MAX)
    {
      Cycles = 0xFFFFFFFF;
    }
  }

  return Cycles;
}

/**
  * @brief  Returns the BUSY status of the NAND Flash.
  * @param  None.
  * @retval The NAND Flash BUSY status (NandFlashReady or NandFlashBusy).
  */
FlagStatus EBC_GetBusyStatus(void)
{
  MDR_EBC_TypeDef *EBCx;
  FlagStatus tmpreg_BUSY_STS;

  EBCx = MDR_EBC;

  if ((EBCx->CONTROL & EBC_CONTROL_BUSY) == 0)
  {
    tmpreg_BUSY_STS = RESET;
  }
  else
  {
    tmpreg_BUSY_STS = SET;
  }

  return tmpreg_BUSY_STS;
}

#if defined (USE_MDR1986VE3) || defined (USE_MDR1986VE1T) || defined (USE_MDR1986VE94)
/**
  * @brief  Fills each EBC_InitStruct member with its default value.
  * @warning This function can be used only for microcontrollers
  * MDR1986VE1T and MDR1986VE3.
  * @param  EBC_InitStruct: pointer to a EBC_InitTypeDef structure which will
  *         be initialized.
  * @retval None
  */
void EBC_MemRegionStructInit (EBC_MemRegionInitTypeDef * EBC_MemRegionInitStruct)
{
	/* Reset EBC initialization structure parameters values */
	EBC_MemRegionInitStruct->WS_Active 		= 0;
	EBC_MemRegionInitStruct->WS_Setup 		= EBC_WS_SETUP_CYCLE_1HCLK;
	EBC_MemRegionInitStruct->WS_Hold 		= EBC_WS_HOLD_CYCLE_1HCLK;
	EBC_MemRegionInitStruct->Use_Ready 		= DISABLE;
	EBC_MemRegionInitStruct->Enable_Tune 	= DISABLE;
}

/**
  * @brief  Initializes the EBC Memory Region according to the specified
  *         parameters in the EBC_MemRegionInitStruct.
  * @warning This function can be used only for microcontrollers
  * 		 MDR1986VE1T and MDR1986VE3.
  * @param  EBC_MemRegionInitStruct: pointer to a EBC_MemRegionInitTypeDef structure that
  *         contains the configuration information for the specified EBC Memory Region.
  * @retval None
  */
void EBC_MemRegionInit ( EBC_MemRegionInitTypeDef * EBC_MemRegionInitStruct, uint32_t EBC_MEM_REGIONx )
{
	MDR_EBC_TypeDef *EBCx;
	uint32_t tmpreg_Mem_Region;

	/* Check the parameters */
	assert_param(IS_EBC_MEM_REGION(EBC_MEM_REGIONx));
	assert_param(IS_EBC_WS_SETUP_CYCLES(EBC_MemRegionInitStruct->WS_Setup));
	assert_param(IS_EBC_WS_HOLD_CYCLES(EBC_MemRegionInitStruct->WS_Hold));
	assert_param(IS_EBC_WS_ACTIVE(EBC_MemRegionInitStruct->WS_Active));

	/* Form new value for the RAM_CYCLESx register */
	tmpreg_Mem_Region = (EBC_MemRegionInitStruct->Use_Ready << EBC_RAM_CYCLES_USE_READY_Pos)
    		          | (EBC_MemRegionInitStruct->WS_Hold << EBC_RAM_CYCLES_WS_HOLD_Pos)
    		          | (EBC_MemRegionInitStruct->WS_Setup << EBC_RAM_CYCLES_WS_SETUP_Pos)
					  | (EBC_MemRegionInitStruct->WS_Active << EBC_RAM_CYCLES_WS_ACTIVE_Pos)
					  | (EBC_MemRegionInitStruct->Enable_Tune << EBC_RAM_CYCLES_ENABLE_TUNE_Pos);

	EBCx = (MDR_EBC_TypeDef *)MDR_EBC;

	/* Configure EBC registers with new values */
	EBCx->MEM_REGION[EBC_MEM_REGIONx] = tmpreg_Mem_Region;
}

/**
  * @brief  Enables or disables the specified EBC Memory Region settigs.
  * @warning This function can be used only for microcontrollers
  * 		MDR1986VE1T and MDR1986VE3.
  * @param  EBC_MEM_REGIONx: Select the specified memory region.
  *         This parameter can be one of the following values:
  *         	@arg EBC_MEM_REGION_10000000
  *         	@arg EBC_MEM_REGION_50000000
  *         	@arg EBC_MEM_REGION_60000000
  * 			@arg EBC_MEM_REGION_70000000
  * @param  NewState: new state of the EBC Memory Region settigs.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void EBC_MemRegionCMD ( uint32_t EBC_MEM_REGIONx, uint32_t NewState )
{
	MDR_EBC_TypeDef *EBCx = (MDR_EBC_TypeDef *)MDR_EBC;

	/* Check the parameters */
	assert_param(IS_EBC_MEM_REGION(EBC_MEM_REGIONx));
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(NewState != DISABLE){
		 /* Enable the selected EBC Memory Region settigs */
		EBCx->MEM_REGION[EBC_MEM_REGIONx] |= EBC_RAM_CYCLES_ENABLE_TUNE;
	}
	else{
		/* Disable the selected EBC Memory Region settigs */
		EBCx->MEM_REGION[EBC_MEM_REGIONx] &= ~EBC_RAM_CYCLES_ENABLE_TUNE;
	}
}

#endif /* #if defined (USE_MDR1986VE3) || defined (USE_MDR1986VE1T) */

/** @} */ /* End of group EBC_Private_Functions */

/** @} */ /* End of group EBC */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

/******************* (C) COPYRIGHT 2010 Phyton *********************************
*
* END OF FILE MDR32F9Qx_ebc.c */

