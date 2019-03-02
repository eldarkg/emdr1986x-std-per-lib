/**
  ******************************************************************************
  * @file    mdr32f8_ebc.c
  * @author  Milandr Application Team
  * @version V1.4.0
  * @date    20/07/2015
  * @brief   This file provides all the ADC firmware functions.
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
  * <h2><center>&copy; COPYRIGHT 2015 Milandr</center></h2>
  ******************************************************************************
  * FILE mdr32f8_ebc.c
  */

/* Includes ------------------------------------------------------------------*/
#include "mdr32f8_config.h"
#include "mdr32f8_ebc.h"

#define ASSERT_INFO_FILE_ID FILEID__MDR32F8_EBC_C

/** @addtogroup __MDR32F8_StdPeriph_Driver MDR32F8 Standard Peripherial Driver
  * @{
  */

/** @defgroup EBC EBC
  * @{
  */

/** @defgroup EBC_Private_Functions EBC Private Functions
  * @{
  */


/**
  * @brief  Initializes the EBC peripheral according to
  *         the specified parameters in the EBC_RGN_InitStruct.
  * @param  EBC_RGN_InitStruct: pointer to a EBC_RGN_InitTypeDef structure
  *         that contains the configuration information for the specified EBC_RGN.
  * @retval None
  */
void EBC_RGNx_Init(uint32_t RGNx, const EBC_RGN_InitTypeDef* EBC_RGN_InitStruct)
{
  uint32_t tmpreg_RGNx_CNTRL;

	tmpreg_RGNx_CNTRL = (EBC_RGN_InitStruct->RGN_ECCEN 		<< EBC_ECCEN_pos)
									| (EBC_RGN_InitStruct->RGN_ECCMODE 		<< EBC_ECCMODE_pos)
									| (EBC_RGN_InitStruct->RGN_RDYWAIT 		<< EBC_RDYWAIT_pos)
									| (EBC_RGN_InitStruct->RGN_MODE 	 		<< EBC_MODE_pos)
									| (EBC_RGN_InitStruct->RGN_ROM 		 		<< EBC_ROM_pos)
									| (EBC_RGN_InitStruct->RGN_CPOL 	 		<< EBC_CPOL_pos)
									| (EBC_RGN_InitStruct->RGN_WS_ACTIVE 	<< EBC_WS_ACTIVE_pos)
									| (EBC_RGN_InitStruct->RGN_WS_SETUP 	<< EBC_WS_SETUP_pos)
									| (EBC_RGN_InitStruct->RGN_WS_HOLD 		<< EBC_WS_HOLD_pos)
									| (EBC_RGN_InitStruct->RGN_USESEPAR 	<< EBC_USESEPAR_pos)
									| (EBC_RGN_InitStruct->RGN_CACHEBLE 	<< EBC_CACHEBLE_pos)
									| (EBC_RGN_InitStruct->RGN_READ32 		<< EBC_READ32_pos)
									| (EBC_RGN_InitStruct->RGN_ENOCLK 		<< EBC_ENOCLK_pos)
									| (EBC_RGN_InitStruct->RGN_DIVOCLK 		<< EBC_DIVOCLK_pos);									
	switch (RGNx)
	{
		case RGN0: EXT_BUS_CNTR->RGN0_CNTRL = tmpreg_RGNx_CNTRL;break;
		case RGN1: EXT_BUS_CNTR->RGN1_CNTRL = tmpreg_RGNx_CNTRL;break;
		case RGN2: EXT_BUS_CNTR->RGN2_CNTRL = tmpreg_RGNx_CNTRL;break;
		case RGN3: EXT_BUS_CNTR->RGN3_CNTRL = tmpreg_RGNx_CNTRL;break;
		case RGN4: EXT_BUS_CNTR->RGN4_CNTRL = tmpreg_RGNx_CNTRL;break;
		case RGN5: EXT_BUS_CNTR->RGN5_CNTRL = tmpreg_RGNx_CNTRL;break;
		case RGN6: EXT_BUS_CNTR->RGN6_CNTRL = tmpreg_RGNx_CNTRL;break;
		case RGN7: EXT_BUS_CNTR->RGN7_CNTRL = tmpreg_RGNx_CNTRL;break;			
	}

	
}

/**
  * @brief  Fills each EBC_RGN_InitStruct member with its default value.
  * @param  EBC_RGN_InitStruct: pointer to a EBC_RGN_InitTypeDef structure
  *         which will be initialized.
  * @retval None
  */
void EBC_RGNx_StructInit(EBC_RGN_InitTypeDef* EBC_RGN_InitStruct)
{
  EBC_RGN_InitStruct->RGN_ECCEN = DISABLE;
  EBC_RGN_InitStruct->RGN_ECCMODE = 0;
  EBC_RGN_InitStruct->RGN_RDYWAIT = 0;
  EBC_RGN_InitStruct->RGN_MODE = 0;
  EBC_RGN_InitStruct->RGN_ROM = 0;
  EBC_RGN_InitStruct->RGN_CPOL = 0;
  EBC_RGN_InitStruct->RGN_WS_ACTIVE = 0;
  EBC_RGN_InitStruct->RGN_WS_SETUP = 0;
  EBC_RGN_InitStruct->RGN_WS_HOLD = 0;
  EBC_RGN_InitStruct->RGN_USESEPAR = 0;
  EBC_RGN_InitStruct->RGN_CACHEBLE = DISABLE;
  EBC_RGN_InitStruct->RGN_READ32 = 0;
  EBC_RGN_InitStruct->RGN_ENOCLK = DISABLE;
  EBC_RGN_InitStruct->RGN_DIVOCLK = 0;		
}

/**
  * @brief  Enables or disables the EBC_RGNx.
  * @param  NewState: new state of the EBC_RGNx.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void EBC_RGNx_Cmd(uint32_t RGNx, FunctionalState NewState)
{
  uint32_t tmpreg_CNTRL;

  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));

	switch (RGNx)
	{
		case RGN0: tmpreg_CNTRL = EXT_BUS_CNTR->RGN0_CNTRL;break;
		case RGN1: tmpreg_CNTRL = EXT_BUS_CNTR->RGN1_CNTRL;break;
		case RGN2: tmpreg_CNTRL = EXT_BUS_CNTR->RGN2_CNTRL;break;
		case RGN3: tmpreg_CNTRL = EXT_BUS_CNTR->RGN3_CNTRL;break;
		case RGN4: tmpreg_CNTRL = EXT_BUS_CNTR->RGN4_CNTRL;break;
		case RGN5: tmpreg_CNTRL = EXT_BUS_CNTR->RGN5_CNTRL;break;
		case RGN6: tmpreg_CNTRL = EXT_BUS_CNTR->RGN6_CNTRL;break;
		case RGN7: tmpreg_CNTRL = EXT_BUS_CNTR->RGN7_CNTRL;break;			
	}

  /* Form new value */
  if (NewState != DISABLE)
  {
    /* Enable EBC_RGNx by setting the EBC_RGNx_CNTRL_EN bit in the CNTRL register */
    tmpreg_CNTRL |= EBC_RGNx_EN;
  }
  else
  {
    /* Disable EBC_RGNx by resetting the EBC_RGNx_CNTRL_EN bit in the CNTRL register */
    tmpreg_CNTRL &= ~EBC_RGNx_EN;
  }

  /* Configure CNTRL register with new value */
	switch (RGNx)
	{
		case RGN0: EXT_BUS_CNTR->RGN0_CNTRL |= tmpreg_CNTRL;break;
		case RGN1: EXT_BUS_CNTR->RGN1_CNTRL |= tmpreg_CNTRL;break;
		case RGN2: EXT_BUS_CNTR->RGN2_CNTRL |= tmpreg_CNTRL;break;
		case RGN3: EXT_BUS_CNTR->RGN3_CNTRL |= tmpreg_CNTRL;break;
		case RGN4: EXT_BUS_CNTR->RGN4_CNTRL |= tmpreg_CNTRL;break;
		case RGN5: EXT_BUS_CNTR->RGN5_CNTRL |= tmpreg_CNTRL;break;
		case RGN6: EXT_BUS_CNTR->RGN6_CNTRL |= tmpreg_CNTRL;break;
		case RGN7: EXT_BUS_CNTR->RGN7_CNTRL |= tmpreg_CNTRL;break;			
	}
}

/** @} */ /* End of group EBC_Private_Functions */

/** @} */ /* End of group EBC */

/** @} */ /* End of group __MDR32F8_StdPeriph_Driver */

/******************* (C) COPYRIGHT 2015 Milandr *********************************
*
* END OF FILE mdr32f8_ebc.c */

