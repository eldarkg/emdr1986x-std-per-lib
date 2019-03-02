/**
  * FILE MDR32F9Qx_comp.c
  */

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_comp.h"
#include "MDR32F9Qx_config.h"

#define ASSERT_INFO_FILE_ID FILEID__MDR32F9X_COMP_C

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @defgroup COMP COMP
  * @warning	This module can be used only for microcontroller series MDR1986VE9x.
  * @{
  */



/** @defgroup COMP_Private_Functions COMP Private Functions
  * @{
  */

/**
  * @brief  Deinitializes the COMP peripheral registers to their default reset values.
  * @param  None.
  * @retval None.
  */
void COMP_DeInit(void)
{
  MDR_COMP->CFG = 0;
  MDR_COMP->RESULT_LATCH;
}

/**
  * @brief  Initializes the COMP peripheral according to
  *         the specified parameters in the COMP_InitStruct.
  * @param  COMP_InitStruct: pointer to a COMP_InitTypeDef structure
  *         that contains the configuration information for the specified COMP
  *         peripheral.
  * @retval None
  */
void COMP_Init(const COMP_InitTypeDef* COMP_InitStruct)
{
  uint32_t tmpreg_CFG;

  /* Check the parameters */
  assert_param(IS_COMP_PLUS_INPUT_CONFIG(COMP_InitStruct->COMP_PlusInputSource));
  assert_param(IS_COMP_MINUS_INPUT_CONFIG(COMP_InitStruct->COMP_MinusInputSource));
  assert_param(IS_COMP_OUT_INV_CONFIG(COMP_InitStruct->COMP_OutInversion));

  tmpreg_CFG = MDR_COMP->CFG;
  tmpreg_CFG &= ~(COMP_CFG_CREF | COMP_CFG_CCH_Msk | COMP_CFG_INV);
  tmpreg_CFG += COMP_InitStruct->COMP_PlusInputSource
              + COMP_InitStruct->COMP_MinusInputSource
              + COMP_InitStruct->COMP_OutInversion;
  MDR_COMP->CFG = tmpreg_CFG;
}

/**
  * @brief  Fills each COMP_InitStruct member with its default value.
  * @param  COMP_InitStruct: pointer to a COMP_InitTypeDef structure
  *         which will be initialized.
  * @retval None
  */
void COMP_StructInit(COMP_InitTypeDef* COMP_InitStruct)
{
  COMP_InitStruct->COMP_PlusInputSource  = COMP_PlusInput_IN1;
  COMP_InitStruct->COMP_MinusInputSource = COMP_MinusInput_IN2;
  COMP_InitStruct->COMP_OutInversion     = COMP_OUT_INV_Disable;
}

/**
  * @brief  Enables or disables the COMP peripheral.
  * @param  NewState: new state of the COMP peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void COMP_Cmd(FunctionalState NewState)
{
  uint32_t tmpreg_CFG;

  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  tmpreg_CFG = MDR_COMP->CFG;

  /* Form new value */
  if (NewState != DISABLE)
  {
    /* Enable COMP by setting the COMP_CFG_ON bit in the COMP_CFG register */
    tmpreg_CFG |= COMP_CFG_ON;
  }
  else
  {
    /* Disable COMP by resetting the COMP_CFG_ON bit in the COMP_CFG register */
    tmpreg_CFG &= ~COMP_CFG_ON;
  }

  /* Configure COMP_CFG register with new value */
  MDR_COMP->CFG = tmpreg_CFG;
}

/**
  * @brief  Checks whether the specified COMP Status flag is set or not.
  * @param  Flag: specifies the flag to check.
  *         This parameter can be one of the following values:
  *           @arg COMP_CFG_FLAG_READY:          the Comparator is ready;
  *           @arg COMP_CFG_FLAG_IE:             the Comparator interrupt enabled.
  * @retval Current Status flag state (SET or RESET).
  */
FlagStatus COMP_GetCfgFlagStatus(uint32_t Flag)
{
  FlagStatus bitstatus;

  /* Check the parameters */
  assert_param(IS_COMP_CFG_FLAG(Flag));

  if ((MDR_COMP->CFG & Flag) == 0)
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
  * @brief  Configures non-inverting comparator input.
  * @param  Source: specifies the non-inverting comparator input source.
  *         This parameter can be one of the following values:
  *           @arg COMP_PlusInput_IN1:           the non-inverting comparator input connected to IN1;
  *           @arg COMP_PlusInput_CVREF:         the non-inverting comparator input connected to CVREF.
  * @retval None.
  */
void COMP_PInpSourceConfig(uint32_t Source)
{
  uint32_t tmpreg_CFG;

  /* Check the parameters */
  assert_param(IS_COMP_PLUS_INPUT_CONFIG(Source));

  tmpreg_CFG = MDR_COMP->CFG;
  tmpreg_CFG &= ~COMP_CFG_CREF;
  tmpreg_CFG += Source;
  MDR_COMP->CFG = tmpreg_CFG;
}

/**
  * @brief  Configures inverting comparator input.
  * @param  Source: specifies the inverting comparator input source.
  *         This parameter can be one of the following values:
  *           @arg COMP_MinusInput_IN2:          the inverting comparator input connected to IN2;
  *           @arg COMP_MinusInput_IN1:          the inverting comparator input connected to IN1;
  *           @arg COMP_MinusInput_IN3:          the inverting comparator input connected to IN3;
  *           @arg COMP_MinusInput_IVREF:        the inverting comparator input connected to IVREF.
  * @retval None.
  */
void COMP_MInpSourceConfig(uint32_t Source)
{
  uint32_t tmpreg_CFG;

  /* Check the parameters */
  assert_param(IS_COMP_MINUS_INPUT_CONFIG(Source));

  tmpreg_CFG = MDR_COMP->CFG;
  tmpreg_CFG &= ~COMP_CFG_CCH_Msk;
  tmpreg_CFG += Source;
  MDR_COMP->CFG = tmpreg_CFG;
}

/**
  * @brief  Configures comparator output inversion.
  * @param  Inversion: enables or disables inversion on the comparator output.
  *         This parameter can be one of the following values:
  *           @arg COMP_OUT_INV_Disable:         disables the comparator output inversion;
  *           @arg COMP_OUT_INV_Enable:          enables the comparator output inversion.
  * @retval None.
  */
void COMP_OutInversionConfig(uint32_t Inversion)
{
  uint32_t tmpreg_CFG;

  /* Check the parameters */
  assert_param(IS_COMP_OUT_INV_CONFIG(Inversion));

  tmpreg_CFG = MDR_COMP->CFG;
  tmpreg_CFG &= ~COMP_CFG_INV;
  tmpreg_CFG += Inversion;
  MDR_COMP->CFG = tmpreg_CFG;
}

/**
  * @brief  Initializes the COMP reference voltage source according to
  *         the specified parameters in the COMP_CVRefInitStruct.
  * @param  COMP_CVRefInitStruct: pointer to a COMP_CVRefInitTypeDef structure
  *         that contains the configuration information for the COMP
  *         reference voltage source.
  * @retval None
  */
void COMP_CVRefInit(const COMP_CVRefInitTypeDef* COMP_CVRefInitStruct)
{
  uint32_t tmpreg_CFG;

  /* Check the parameters */
  assert_param(IS_COMP_CVREF_SOURCE_CONFIG(COMP_CVRefInitStruct->COMP_CVRefSource));
  assert_param(IS_COMP_CVREF_RANGE_CONFIG(COMP_CVRefInitStruct->COMP_CVRefRange));
  assert_param(IS_COMP_CVREF_SCALE_CONFIG(COMP_CVRefInitStruct->COMP_CVRefScale));

  tmpreg_CFG = MDR_COMP->CFG;
  tmpreg_CFG &= ~(COMP_CFG_CVRSS | COMP_CFG_CVRR | COMP_CFG_CVR_Msk);
  tmpreg_CFG += COMP_CVRefInitStruct->COMP_CVRefSource
              + COMP_CVRefInitStruct->COMP_CVRefRange
              + COMP_CVRefInitStruct->COMP_CVRefScale;
  MDR_COMP->CFG = tmpreg_CFG;
}

/**
  * @brief  Fills each COMP_CVRefInitStruct member with its default value.
  * @param  COMP_CVRefInitStruct: pointer to a COMP_CVRefInitTypeDef structure
  *         which will be initialized.
  * @retval None
  */
void COMP_CVRefStructInit(COMP_CVRefInitTypeDef* COMP_CVRefInitStruct)
{
  COMP_CVRefInitStruct->COMP_CVRefSource = COMP_CVREF_SOURCE_AVdd;
  COMP_CVRefInitStruct->COMP_CVRefRange  = COMP_CVREF_RANGE_Up;
  COMP_CVRefInitStruct->COMP_CVRefScale  = COMP_CVREF_SCALE_0_div_24;
}

/**
  * @brief  Enables or disables the COMP reference voltage source.
  * @param  NewState: new state of the COMP reference voltage source.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void COMP_CVRefCmd(FunctionalState NewState)
{
  uint32_t tmpreg_CFG;

  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  tmpreg_CFG = MDR_COMP->CFG;

  /* Form new value */
  if (NewState != DISABLE)
  {
    /* Enable COMP reference by setting the COMP_CFG_CVREN bit in the COMP_CFG register */
    tmpreg_CFG |= COMP_CFG_CVREN;
  }
  else
  {
    /* Disable COMP reference by resetting the COMP_CFG_CVREN bit in the COMP_CFG register */
    tmpreg_CFG &= ~COMP_CFG_CVREN;
  }

  /* Configure COMP_CFG register with new value */
  MDR_COMP->CFG = tmpreg_CFG;
}

/**
  * @brief  Configures the COMP reference voltage source.
  * @param  Source: specifies the COMP reference voltage source.
  *         This parameter can be one of the following values:
  *           @arg COMP_CVREF_SOURCE_AVdd:       the CVREF source is (AVdd, AGND);
  *           @arg COMP_CVREF_SOURCE_VRef:       the CVREF source is (VRef+, VRef-).
  * @retval None.
  */
void COMP_CVRefSourceConfig(uint32_t Source)
{
  uint32_t tmpreg_CFG;

  /* Check the parameters */
  assert_param(IS_COMP_CVREF_SOURCE_CONFIG(Source));

  tmpreg_CFG = MDR_COMP->CFG;
  tmpreg_CFG &= ~COMP_CFG_CVRSS;
  tmpreg_CFG += Source;
  MDR_COMP->CFG = tmpreg_CFG;
}

/**
  * @brief  Configures the COMP reference voltage range.
  * @param  Range: specifies the COMP reference voltage range.
  *         This parameter can be one of the following values:
  *           @arg COMP_CVREF_RANGE_Up:          CVREF works in Up Range;
  *           @arg COMP_CVREF_RANGE_Dn:          CVREF works in Down Range.
  * @retval None.
  */
void COMP_CVRefRangeConfig(uint32_t Range)
{
  uint32_t tmpreg_CFG;

  /* Check the parameters */
  assert_param(IS_COMP_CVREF_RANGE_CONFIG(Range));

  tmpreg_CFG = MDR_COMP->CFG;
  tmpreg_CFG &= ~COMP_CFG_CVRR;
  tmpreg_CFG += Range;
  MDR_COMP->CFG = tmpreg_CFG;
}

/**
  * @brief  Configures the COMP reference voltage scale.
  * @param  Scale: specifies the COMP reference voltage scale.
  *         If CVREF Up Range selected This parameter can be one of the following values:
  *           @arg COMP_CVREF_SCALE_8_div_32:    the COMP CVRef up range scale 8/32;
  *           @arg COMP_CVREF_SCALE_9_div_32:    the COMP CVRef up range scale 9/32;
  *           @arg COMP_CVREF_SCALE_10_div_32:   the COMP CVRef up range scale 10/32;
  *           @arg COMP_CVREF_SCALE_11_div_32:   the COMP CVRef up range scale 11/32;
  *           @arg COMP_CVREF_SCALE_12_div_32:   the COMP CVRef up range scale 12/32;
  *           @arg COMP_CVREF_SCALE_13_div_32:   the COMP CVRef up range scale 13/32;
  *           @arg COMP_CVREF_SCALE_14_div_32:   the COMP CVRef up range scale 14/32;
  *           @arg COMP_CVREF_SCALE_15_div_32:   the COMP CVRef up range scale 15/32;
  *           @arg COMP_CVREF_SCALE_16_div_32:   the COMP CVRef up range scale 16/32;
  *           @arg COMP_CVREF_SCALE_17_div_32:   the COMP CVRef up range scale 17/32;
  *           @arg COMP_CVREF_SCALE_18_div_32:   the COMP CVRef up range scale 18/32;
  *           @arg COMP_CVREF_SCALE_19_div_32:   the COMP CVRef up range scale 19/32;
  *           @arg COMP_CVREF_SCALE_20_div_32:   the COMP CVRef up range scale 20/32;
  *           @arg COMP_CVREF_SCALE_21_div_32:   the COMP CVRef up range scale 21/32;
  *           @arg COMP_CVREF_SCALE_22_div_32:   the COMP CVRef up range scale 22/32;
  *           @arg COMP_CVREF_SCALE_23_div_32:   the COMP CVRef up range scale 23/32.
  *         If CVREF Down Range selected This parameter can be one of the following values:
  *           @arg COMP_CVREF_SCALE_0_div_24:    the COMP CVRef down range scale 0/24;
  *           @arg COMP_CVREF_SCALE_1_div_24:    the COMP CVRef down range scale 1/24;
  *           @arg COMP_CVREF_SCALE_2_div_24:    the COMP CVRef down range scale 2/24;
  *           @arg COMP_CVREF_SCALE_3_div_24:    the COMP CVRef down range scale 3/24;
  *           @arg COMP_CVREF_SCALE_4_div_24:    the COMP CVRef down range scale 4/24;
  *           @arg COMP_CVREF_SCALE_5_div_24:    the COMP CVRef down range scale 5/24;
  *           @arg COMP_CVREF_SCALE_6_div_24:    the COMP CVRef down range scale 6/24;
  *           @arg COMP_CVREF_SCALE_7_div_24:    the COMP CVRef down range scale 7/24;
  *           @arg COMP_CVREF_SCALE_8_div_24:    the COMP CVRef down range scale 8/24;
  *           @arg COMP_CVREF_SCALE_9_div_24:    the COMP CVRef down range scale 9/24;
  *           @arg COMP_CVREF_SCALE_10_div_24:   the COMP CVRef down range scale 10/24;
  *           @arg COMP_CVREF_SCALE_11_div_24:   the COMP CVRef down range scale 11/24;
  *           @arg COMP_CVREF_SCALE_12_div_24:   the COMP CVRef down range scale 12/24;
  *           @arg COMP_CVREF_SCALE_13_div_24:   the COMP CVRef down range scale 13/24;
  *           @arg COMP_CVREF_SCALE_14_div_24:   the COMP CVRef down range scale 14/24;
  *           @arg COMP_CVREF_SCALE_15_div_24:   the COMP CVRef down range scale 15/24.
  * @retval None.
  */
void COMP_CVRefScaleConfig(uint32_t Scale)
{
  uint32_t tmpreg_CFG;

  /* Check the parameters */
  assert_param(IS_COMP_CVREF_SCALE_CONFIG(Scale));

  tmpreg_CFG = MDR_COMP->CFG;
  tmpreg_CFG &= ~COMP_CFG_CVR_Msk;
  tmpreg_CFG += Scale;
  MDR_COMP->CFG = tmpreg_CFG;
}

/**
  * @brief  Returns and clears the COMP Result Latch register value.
  * @param  None.
  * @retval The Result Latch register value.
  */
uint32_t COMP_GetResultLatch(void)
{
  return MDR_COMP->RESULT_LATCH;
}

/**
  * @brief  Returns the COMP Result register value.
  * @param  None.
  * @retval The Result register value.
  */
uint32_t COMP_GetStatus(void)
{
  return MDR_COMP->RESULT;
}

/**
  * @brief  Checks whether the specified COMP Status flag is set or not.
  * @param  Flag: specifies the flag to check.
  *         This parameter can be one of the following values:
  *           @arg COMP_STATUS_FLAG_SY:          the latched Comparator output value;
  *           @arg COMP_STATUS_FLAG_AS:          the Comparator output value;
  *           @arg COMP_STATUS_FLAG_LCH:         the clocked Comparator output value.
  * @retval Current Status flag state (SET or RESET).
  */
FlagStatus COMP_GetFlagStatus(uint32_t Flag)
{
  FlagStatus bitstatus;

  /* Check the parameters */
  assert_param(IS_COMP_STATUS_FLAG(Flag));

  if ((COMP_GetStatus() & Flag) == 0)
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
  * @brief  Enables or disables the COMP interrupt.
  * @param  NewState: new state of the COMP interrupt.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void COMP_ITConfig(FunctionalState NewState)
{
  uint32_t tmpreg_CFG;

  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  tmpreg_CFG = MDR_COMP->CFG;

  /* Form new value */
  if (NewState != DISABLE)
  {
    /* Enable the COMP Interrupt requests by setting bits in the CFG registers */
    tmpreg_CFG |= COMP_CFG_CMPIE;
  }
  else
  {
    /* Disable the COMP Interrupt requests by clearing bits in the CFG registers */
    tmpreg_CFG &= ~COMP_CFG_CMPIE;
  }

  /* Configure CFG registers with new value */
  MDR_COMP->CFG = tmpreg_CFG;
}

/** @} */ /* End of group COMP_Private_Functions */

/** @} */ /* End of group COMP */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

/*
*
* END OF FILE MDR32F9Qx_comp.c */

