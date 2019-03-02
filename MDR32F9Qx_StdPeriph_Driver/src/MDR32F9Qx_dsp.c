/**
  * FILE MDR32F9Qx_dsp.c
  */

/* Includes ------------------------------------------------------------------*/

#include "MDR32F9Qx_config.h"
#include "MDR32F9Qx_dsp.h"

#define ASSERT_INFO_FILE_ID FILEID__MDR32F9Qx_DSP_C

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

#if defined (USE_MDR1901VC1T)

/** @deftogroup DSP DSP
  * @{
  */

/** @defgroup DSP_Private_Constant DSP Private Constant
  * @{
  */

/* RCC_CLK registers bit address in the alias region */
#define PERIPH_BASE                 0x40000000
#define PERIPH_BB_BASE              0x42000000
#define RST_CLK_OFFSET              (MDR_RST_CLK_BASE - PERIPH_BASE)

#define SFR_OFFSET(TP, MOD, SFR)    ((uint32_t)&((TP*)MOD)->SFR)
#define BB_ADDR(TP, MOD, SFR, BIT)  (PERIPH_BB_BASE + SFR_OFFSET(TP, MOD, SFR)*32 + BIT*4)
#define RST_CLK_BB(SFR, BIT)        BB_ADDR(MDR_RST_CLK_TypeDef, RST_CLK_OFFSET, SFR, BIT)

#define RST_DSP_BB					RST_CLK_BB(DSP_CONTROL_STATUS, RST_CLK_DSP_CONTROL_STATUS_RST_DSP_Pos)
#define RST_DSP_CPU_BB				RST_CLK_BB(DSP_CONTROL_STATUS, RST_CLK_DSP_CONTROL_STATUS_RST_DSP_CPU_Pos)
#define RST_DSP_MEM_BB				RST_CLK_BB(DSP_CONTROL_STATUS, RST_CLK_DSP_CONTROL_STATUS_RST_DSP_MEM_Pos)
#define RST_DSP_PER_BB				RST_CLK_BB(DSP_CONTROL_STATUS, RST_CLK_DSP_CONTROL_STATUS_RST_DSP_PER_Pos)
#define RST_DSP_HOLD_BB				RST_CLK_BB(DSP_CONTROL_STATUS, RST_CLK_DSP_CONTROL_STATUS_HOLD_Pos)
#define RST_DSP_BIO_BB				RST_CLK_BB(DSP_CONTROL_STATUS, RST_CLK_DSP_CONTROL_STATUS_BIO_Pos)
#define RST_DSP_XF_BB				RST_CLK_BB(DSP_CONTROL_STATUS, RST_CLK_DSP_CONTROL_STATUS_XF_Pos)
#define RST_DSP_HOLDA_BB			RST_CLK_BB(DSP_CONTROL_STATUS, RST_CLK_DSP_CONTROL_STATUS_HOLDA_Pos)
#define RST_DSP_BRTRD_BB			RST_CLK_BB(DSP_CONTROL_STATUS, RST_CLK_DSP_CONTROL_STATUS_BRTRD_Pos)
#define RST_DSP_RD_BUF_EN_BB		RST_CLK_BB(DSP_CONTROL_STATUS, RST_CLK_DSP_CONTROL_STATUS_RD_BUFF_EN_Pos)

/** @} */ /* End of group DSP_Private_Constant */

/** @defgroup DSP_Private_Functions DSP Private Functions
  * @{
  */

/**
  * @brief  Disable all clock of the DSP core.
  * @param	None
  * @retval	None
  */
void DSP_DeInit(void)
{
	*(__IO uint32_t *)RST_DSP_RD_BUF_EN_BB 	= (uint32_t)DISABLE;
	*(__IO uint32_t *)RST_DSP_PER_BB 		= (uint32_t)ENABLE;
	*(__IO uint32_t *)RST_DSP_MEM_BB 		= (uint32_t)ENABLE;
	*(__IO uint32_t *)RST_DSP_CPU_BB 		= (uint32_t)ENABLE;
	*(__IO uint32_t *)RST_DSP_BB 			= (uint32_t)ENABLE;
}

/**
  * @brief	Config the DSP core state.
  * @param	NewState: the new state of the DSP core clock.
  * 		This parameter can be: ENABLE or DISABLE.
  * @retval	None
  */
void DSP_RST_Cmd(FunctionalState NewState)
{
	/* Check the parameters */
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	*(__IO uint32_t *) RST_DSP_BB = (uint32_t) !NewState;
}

/**
  * @brief	Enable or Disable the DSP core.
  * @param	NewState: the new state of the DSP CPU core.
  * @retval	None.
  */
void DSP_CPU_Cmd(FunctionalState NewState)
{
	/* Check the parameters */
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	*(__IO uint32_t *) RST_DSP_CPU_BB = (uint32_t) !NewState;
}

/**
  * @brief	Enable or disable the DSP memory block.
  * @param	NewState: the new state of the DSP memory block.
  * @retval	None.
  */
void DSP_MEM_Cmd(FunctionalState NewState)
{
	/* Check the parameters */
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	*(__IO uint32_t *) RST_DSP_MEM_BB = (uint32_t) !NewState;
}

/**
  * @brief	Config the peripheral DSP block.
  * @param	NewState: the new state of the peripheral DSP block.
  * @retval	None.
  */
void DSP_PER_Cmd(FunctionalState NewState)
{
	/* Check the parameters */
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	*(__IO uint32_t *) RST_DSP_PER_BB = (uint32_t) !NewState;
}

/**
  * @brief	Config read prefetch address space DSP.
  * @param	NewState: the new state of the RD_Buff_EN bit.
  * @retval	None.
  */
void DSP_ReadBufferCmd(FunctionalState NewState)
{
	/* Check the parameters */
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	*(__IO uint32_t *) RST_DSP_RD_BUF_EN_BB = (uint32_t) NewState;
}

/**
  * @brief	Get DSP flag status.
  * @param	flag: specifies the flag to check.
  *			This parameter can be one of the following values:
  *				@arg DSP_FLAG_BIO
  *				@arg DSP_FLAG_XF
  *				@arg DSP_FLAG_HOLDA
  *				@arg DSP_FLAG_BRTRD
  * @retval	The state of the DSP checked flag (SET or RESET).
  */
FlagStatus DSP_GetStatus(uint32_t flag)
{
	FlagStatus state;
	/* Check the parameters */
	assert_param(IS_DSP_FLAG(flag));

	switch (flag){
		case DSP_FLAG_BIO:
			state = (FlagStatus) *(__IO uint32_t * )RST_DSP_BIO_BB;
		break;
		case DSP_FLAG_XF:
			state = (FlagStatus) *(__IO uint32_t * )RST_DSP_XF_BB;
		break;
		case DSP_FLAG_HOLDA:
			state = (FlagStatus) *(__IO uint32_t * )RST_DSP_HOLDA_BB;
		break;
		case DSP_FLAG_BRTRD:
			state = (FlagStatus) *(__IO uint32_t * )RST_DSP_BRTRD_BB;
		break;
		default:
			state = RESET;
			break;
	}
	return(state);
}

/**
  * @brief	Enables or disables the DSP peripheral modules clock.
  * @param	DSP_CLK_PCLK: specifies the peripheral to gates its clock.
  * 		This parameter can be any combination of the following values:
  * 			@arg DSP_CLK_PCLK_CRP, DSP_CLK_PCLK_CDC, DSP_CLK_PCLK_TMR,
  * 			     DSP_CLK_PCLK_DMA, DSP_CLK_PCLK_MC3, DSP_CLK_PCLK_PC3,
  * 			     DSP_CLK_PCLK_MC2, DSP_CLK_PCLK_PC2, DSP_CLK_PCLK_MC1,
  * 			     DSP_CLK_PCLK_PC1, DSP_CLK_PCLK_CDM, DSP_CLK_PCLK_CPM,
  * 			     DSP_CLK_PCLK_CPU.
  * @param	NewSate:  new state of the specified peripheral clock.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval	None.
  */
void DSP_CLKPCLKCmd(uint32_t DSP_CLK_PCLK, FunctionalState NewSate)
{
	/* Check the parameters */
	assert_param(IS_FUNCTIONAL_STATE(NewSate));
	assert_param(IS_DSP_CLK_PCLK(DSP_CLK_PCLK));

	if(NewSate == ENABLE){
		MDR_DSP_CORE->CLKCMD |= DSP_CLK_PCLK;
	}
	else{
		MDR_DSP_CORE->CLKCMD &= ~(DSP_CLK_PCLK);
	}
}

/**
  * @brief	Config the intterupt from RISC to DSP.
  * @param	Interrupt: specifies the peripheral interrupt, that should be set or reset.
  * 			@arg DSP_AIRQ0, DSP_AIRQ1, DSP_AIRQ2, DSP_AIRQ3, DSP_ANMI
  * @param	NewStatus: new state of the specified peripheral clock.
  *         This parameter can be: SET or RESET.
  * @retval	None.
  */
void DSP_RISCToDSPInterruptCmd(uint32_t Interrupt, FlagStatus NewStatus)
{
	/* Check the parameters */
	assert_param(IS_FLAG_STATUS(NewStatus));
	assert_param(IS_DSP_AIRQ(Interrupt));

	MDR_DSP_CORE->AIR = Interrupt | ((NewStatus == SET) << DSP_CORE_AIR_SNR_Pos);
}

/**
  * @brief	Config the DMA ivents form RISC to DSP.
  * @param	ADMA: specifies the DMA ivents, that should be ste or reset.
  *			This parameter can be any combination of the following values:
  *				@arg DSP_ADMARQ0,
  *					 DSP_ADMARQ1,
  *					 DSP_ADMARQ2,
  *					 DSP_ADMARQ3,
  *					 DSP_ADMADONE0,
  *					 DSP_ADMADONE1,
  *					 DSP_ADMADONE2,
  *					 DSP_ADMADONE3.
  * @param	NewStatus: the new status of the specified event.
  * 		This parameter can be: SET or RESET.
  * @retval	None.
  */
void DSP_DMA_RISC_Cmd(uint32_t ADMA, FlagStatus NewStatus)
{
	/* Check the parameters */
	assert_param(IS_FLAG_STATUS(NewStatus));
	assert_param(IS_DSP_ADMA(ADMA));

	MDR_DSP_CORE->AIR = ADMA | ((NewStatus == SET) << DSP_CORE_AIR_SNR_Pos)
						     | DSP_CORE_AIR_SID;
}


/**
  * @brief	Config the interrupts form DSP to RISC.
  * @param	Interrupt: specifies the DSP interrupt, that should be ste or reset.
  * 		This parameter can be any combination of the following values:
  * 		@arg DSP_DIRQ0,
  *				 DSP_DIRQ1,
  *				 DSP_DIRQ2,
  *				 DSP_DIRQ3,
  *				 DSP_TIRQ,
  *				 DSP_RIRQ1,
  *				 DSP_XIRQ1,
  *				 DSP_RIRQ2,
  *				 DSP_XIRQ2,
  *				 DSP_RIRQ3,
  *				 DSP_XIRQ3,
  *				 DSP_CDIRQ,
  *				 DSP_CRIRQ,
  *				 DSP_DMAIRQ.
  *	@param	NewStatus:
  * @retval None.
  */
void DSP_DSPToRISCInterruptCmd(uint32_t Interrupt, FlagStatus NewStatus)
{
	/* Check the parameters */
	assert_param(IS_FLAG_STATUS(NewStatus));
	assert_param(IS_DSP_DIR(Interrupt));

	MDR_DSP_CORE->DIR = Interrupt | ((NewStatus == SET) << DSP_CORE_DIR_SNR_Pos);
}

/** @} */ /* End of group DSP_Private_Functions */

/** @} */ /* End of group DSP */

#endif

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

/*
*
* END OF FILE MDR32F9Qx_dsp.c */
