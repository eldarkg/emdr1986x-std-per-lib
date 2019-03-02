/**
  * FILE MDR32F9Qx_dac.c
  */

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_config.h"
#include "MDR32F9Qx_dac.h"


#define ASSERT_INFO_FILE_ID FILEID__MDR32F9X_DAC_C

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @defgroup DAC DAC
  * @{
  */

/** @defgroup DAC_Private_Functions DAC Private Functions
  * @{
  */

/**
  * @brief  Deinitializes the DAC peripheral registers to their default reset values.
  * @param  None.
  * @retval None.
  */
void DAC_DeInit(void)
{
  MDR_DAC->DAC1_DATA = 0;
  MDR_DAC->CFG = 0;
}

/**
  * @brief  Initializes the DAC1 peripheral.
  * @param  DAC1_Ref: selects the DAC1 Reference Voltage source.
  *         This parameter can be one of the following values:
  *           @arg DAC1_AVCC:                   selects AVcc as Reference Voltage;
  *           @arg DAC1_REF :                   selects DAC1_REF input as Reference Voltage.
  * @retval None
  */
void DAC1_Init(uint32_t DAC1_Ref)
{
  uint32_t tmpreg_CFG;

  /* Check the parameters */
  assert_param(IS_DAC1_REF_CONFIG(DAC1_Ref));

  tmpreg_CFG = MDR_DAC->CFG;
  tmpreg_CFG &= ~DAC_CFG_M_REF0;
  tmpreg_CFG += DAC1_Ref;
  MDR_DAC->CFG = tmpreg_CFG;
}

/**
  * @brief  Enables or disables the DAC1 peripheral.
  * @param  NewState: new state of the DAC1 peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void DAC1_Cmd(FunctionalState NewState)
{
  uint32_t tmpreg_CFG;

  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  tmpreg_CFG = MDR_DAC->CFG;

  /* Form new value */
  if (NewState != DISABLE)
  {
    /* Enable DAC1 by setting the Cfg_ON_DAC0 bit in the DAC_CFG register */
    tmpreg_CFG |= DAC_CFG_ON_DAC0;
  }
  else
  {
    /* Disable DAC1 by resetting the Cfg_ON_DAC0 bit in the DAC_CFG register */
    tmpreg_CFG &= ~DAC_CFG_ON_DAC0;
  }

  /* Configure DAC_CFG register with new value */
  MDR_DAC->CFG = tmpreg_CFG;
}

/**
  * @brief  Sets the DAC1 output data.
  * @param  Data: specifies the DAC output data.
  * @retval None
  */
void DAC1_SetData(uint32_t Data)
{
  /* Check the parameters */
  assert_param(IS_DAC_DATA(Data));

  MDR_DAC->DAC1_DATA = Data;
}

/**
  * @brief  Returns the DAC1 output data.
  * @param  None.
  * @retval Counter Register value.
  */
uint32_t DAC1_GetData(void)
{
  return MDR_DAC->DAC1_DATA;
}

/** @} */ /* End of group DAC_Private_Functions */

/** @} */ /* End of group DAC */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

/*
*
* END OF FILE MDR32F9Qx_dac.c */

