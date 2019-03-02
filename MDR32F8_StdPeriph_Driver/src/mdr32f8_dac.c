/**
  ******************************************************************************
  * @file    MDR32F9Qx_dac.c
  * @author  Phyton Application Team
  * @version V1.4.0
  * @date    22/07/2011
  * @brief   This file provides all the DAC firmware functions.
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
  * FILE MDR32F9Qx_dac.c
  */

/* Includes ------------------------------------------------------------------*/
#include "mdr32f8_config.h"
#include "mdr32f8_dac.h"


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
void DAC_DeInit(DACxControl* DACx)
{
  DACx->DATA = 0;
  DACx->CONFIG0 = 0;
	DACx->CONFIG1 = 0;
}

/**
  * @brief  Initializes the DAC peripheral.
  * @param  SyncMode: specifies the DAC1, DAC2 operation mode - synchronous or independent.
  *         This parameter can be one of the following values:
  *           @arg DAC_SYNC_MODE_Independent:   the independent DAC1, DAC2 operation mode;
  *           @arg DAC_SYNC_MODE_Synchronous:   the synchronous DAC1, DAC2 operation mode.
  * @param  DAC1_Ref: selects the DAC1 Reference Voltage source.
  *         This parameter can be one of the following values:
  *           @arg DAC1_AVCC:                   selects AVcc as Reference Voltage;
  *           @arg DAC1_REF :                   selects DAC1_REF input as Reference Voltage.
  * @param  DAC2_Ref: selects the DAC2 Reference Voltage source.
  *         This parameter can be one of the following values:
  *           @arg DAC2_AVCC:                   selects AVcc as Reference Voltage;
  *           @arg DAC2_REF :                   selects DAC2_REF input as Reference Voltage.
  * @retval None
  */
void DAC_Init(DACxControl* DACx, uint32_t SyncMode, uint32_t DAC_Ref)
{
  uint32_t tmpreg_CFG;

  /* Check the parameters */
  assert_param(IS_DAC_SYNC_MODE(SyncMode));
  assert_param(IS_DAC1_REF_CONFIG(DAC1_Ref));
  assert_param(IS_DAC2_REF_CONFIG(DAC2_Ref));

  tmpreg_CFG = DACx->CONFIG0;
  tmpreg_CFG &= ~(DAC_CONFIG0_M_REF | DAC_CONFIG0_SYNC_A);
  tmpreg_CFG |= (SyncMode<<1) | (DAC_Ref<<2);
  DACx->CONFIG0 = tmpreg_CFG;
}


/**
  * @brief  Enables or disables the DAC1 peripheral.
  * @param  NewState: new state of the DAC1 peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void DAC_Cmd(DACxControl* DACx, FunctionalState NewState)
{
  uint32_t tmpreg_CFG;

  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  tmpreg_CFG = DACx->CONFIG0;

  /* Form new value */
  if (NewState != DISABLE)
  {
    /* Enable DAC1 by setting the Cfg_ON_DAC0 bit in the DAC_CFG register */
    tmpreg_CFG |= DAC_CONFIG0_ON_DAC;
  }
  else
  {
    /* Disable DAC1 by resetting the Cfg_ON_DAC0 bit in the DAC_CFG register */
    tmpreg_CFG &= ~DAC_CONFIG0_ON_DAC;
  }

  /* Configure DAC_CFG register with new value */
  DACx->CONFIG0 = tmpreg_CFG;
}


/**
  * @brief  Sets the DAC1 (and DAC2 in Synchronous mode) output data.
  * @param  Data: specifies the DAC output data.
  * @retval None
  */
void DAC_SetData(DACxControl* DACx, uint32_t Data)
{
  /* Check the parameters */
  assert_param(IS_DAC_DATA(Data));

  DACx->DATA = Data;
}


/**
  * @brief  Returns the DAC1 output data.
  * @param  None.
  * @retval Counter Register value.
  */
uint32_t DAC_GetData(DACxControl* DACx)
{
  return DACx->DATA;
}

void DAC_CLK_en(DACxControl* DACx, uint32_t DAC_CLKSRC, uint32_t DAC_CLK_DIV)
{
  uint32_t tmpreg;
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
	assert_param(IS_UART_CLKSRC(UART_CLKSRC));

	if(DACx==DAC0){
  tmpreg = CLK_CNTR->DAC0_CLK;

  tmpreg |=  DAC_CLK_EN;
  tmpreg &= ~DAC_DIV_Msk;
  tmpreg |=  DAC_CLK_DIV;
	tmpreg &= ~DAC_CLKSRC_msk;
	tmpreg |=  DAC_CLKSRC<<DAC_CLKSRC_offs;

  CLK_CNTR->DAC0_CLK = tmpreg;
	}
	else if(DACx==DAC1){
  tmpreg = CLK_CNTR->DAC1_CLK;

  tmpreg |=  DAC_CLK_EN;
  tmpreg &= ~DAC_DIV_Msk;
  tmpreg |=  DAC_CLK_DIV;
	tmpreg &= ~DAC_CLKSRC_msk;
	tmpreg |=  DAC_CLKSRC<<DAC_CLKSRC_offs;

  CLK_CNTR->DAC1_CLK = tmpreg;
	}
}

/** @} */ /* End of group DAC_Private_Functions */

/** @} */ /* End of group DAC */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

/******************* (C) COPYRIGHT 2011 Phyton *********************************
*
* END OF FILE MDR32F9Qx_dac.c */

