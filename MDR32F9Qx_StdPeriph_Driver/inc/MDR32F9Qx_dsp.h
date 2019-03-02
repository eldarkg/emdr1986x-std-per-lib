/**
  * FILE MDR32F9Qx_dsp.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef MDR32F9QX_DSP_H_
#define MDR32F9QX_DSP_H_

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_config.h"


/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @defgroup DSP_FLAG DSP_FLAG
  * @{
  */

#define DSP_FLAG_BIO				RST_CLK_DSP_CONTROL_STATUS_BIO
#define DSP_FLAG_XF					RST_CLK_DSP_CONTROL_STATUS_XF
#define DSP_FLAG_HOLDA				RST_CLK_DSP_CONTROL_STATUS_HOLDA
#define DSP_FLAG_BRTRD				RST_CLK_DSP_CONTROL_STATUS_RD_BUFF_EN

#define IS_DSP_FLAG(FLAG)			((FLAG == DSP_FLAG_BIO) 	|| \
									 (FLAG == DSP_FLAG_XF)		|| \
									 (FLAG == DSP_FLAG_HOLDA)	|| \
									 (FLAG == DSP_FLAG_BRTRD))

/** @} */ /* End of group DSP_FLAG */

/** @defgroup DSP_CLK_PCLK peripheral modules clock constants
  * @{
  */
#define DSP_CLK_PCLK_CRP 			DSP_CORE_CLKCMD_CRP
#define DSP_CLK_PCLK_CDC 			DSP_CORE_CLKCMD_CDC
#define DSP_CLK_PCLK_TMR 			DSP_CORE_CLKCMD_TMR
#define DSP_CLK_PCLK_DMA 			DSP_CORE_CLKCMD_DMA
#define DSP_CLK_PCLK_MC3 			DSP_CORE_CLKCMD_MC3
#define DSP_CLK_PCLK_PC3 			DSP_CORE_CLKCMD_PC3
#define DSP_CLK_PCLK_MC2 			DSP_CORE_CLKCMD_MC2
#define DSP_CLK_PCLK_PC2 			DSP_CORE_CLKCMD_PC2
#define DSP_CLK_PCLK_MC1 			DSP_CORE_CLKCMD_MC1
#define DSP_CLK_PCLK_PC1 			DSP_CORE_CLKCMD_PC1
#define DSP_CLK_PCLK_CDM 			DSP_CORE_CLKCMD_CDM
#define DSP_CLK_PCLK_CPM 			DSP_CORE_CLKCMD_CPM
#define DSP_CLK_PCLK_CPU 			DSP_CORE_CLKCMD_CPU

#define DSP_CLK_PCLK_Msk			(DSP_CLK_PCLK_CRP| \
 									 DSP_CLK_PCLK_CDC| \
 									 DSP_CLK_PCLK_TMR| \
 									 DSP_CLK_PCLK_DMA| \
									 DSP_CLK_PCLK_MC3| \
									 DSP_CLK_PCLK_PC3| \
									 DSP_CLK_PCLK_MC2| \
									 DSP_CLK_PCLK_PC2| \
									 DSP_CLK_PCLK_MC1| \
									 DSP_CLK_PCLK_PC1| \
									 DSP_CLK_PCLK_CDM| \
									 DSP_CLK_PCLK_CPM| \
									 DSP_CLK_PCLK_CPU)

#define IS_DSP_CLK_PCLK(PCLK)		((PCLK & (~DSP_CLK_PCLK_Msk)) == 0)
/** @} */ /* End of group DSP_CLK_PCLK */

/** @defgroup DSP_AIRQ DSP_AIRQ
  * @{
  */

#define DSP_AIRQ0 					DSP_CORE_AIR_AIRQ0
#define DSP_AIRQ1 					DSP_CORE_AIR_AIRQ1
#define DSP_AIRQ2 					DSP_CORE_AIR_AIRQ2
#define DSP_AIRQ3 					DSP_CORE_AIR_AIRQ3
#define DSP_ANMI 					DSP_CORE_AIR_ANMI

#define DSP_AIRQ_Msk				(DSP_AIRQ0 |\
									 DSP_AIRQ1 |\
									 DSP_AIRQ2 |\
									 DSP_AIRQ3 |\
									 DSP_ANMI)


#define IS_DSP_AIRQ(AIRQ)			((AIRQ & (~DSP_AIRQ_Msk)) == 0)

/** @} */ /* End of group DSP_AIRQ */

/** @defgroup DSP_ADMA DSP_ADMA
  * @{
  */

#define DSP_ADMARQ0	 				DSP_CORE_AIR_ADMARQ0
#define DSP_ADMARQ1 				DSP_CORE_AIR_ADMARQ1
#define DSP_ADMARQ2 				DSP_CORE_AIR_ADMARQ2
#define DSP_ADMARQ3					DSP_CORE_AIR_ADMARQ3
#define DSP_ADMADONE0 				DSP_CORE_AIR_ADMADONE0
#define DSP_ADMADONE1				DSP_CORE_AIR_ADMADONE1
#define DSP_ADMADONE2				DSP_CORE_AIR_ADMADONE2
#define DSP_ADMADONE3				DSP_CORE_AIR_ADMADONE3

#define DSP_ADMA_Msk				(DSP_ADMARQ0 	| DSP_ADMARQ1  	| \
								 	 DSP_ADMARQ2 	| DSP_ADMARQ3	| \
								 	 DSP_ADMADONE0 	| DSP_ADMADONE1 | \
								 	 DSP_ADMADONE2 	| DSP_ADMADONE3 )

#define IS_DSP_ADMA(ADMA)			((ADMA & (~DSP_ADMA_Msk)) == 0)


/** @} */ /* End of group DSP_ADMA */

/** @defgroup DSP_DIR DSP_DIR
  * @{
  */

#define DSP_DIRQ0 					DSP_CORE_DIR_DIRQ0
#define DSP_DIRQ1 					DSP_CORE_DIR_DIRQ1
#define DSP_DIRQ2	 				DSP_CORE_DIR_DIRQ2
#define DSP_DIRQ3 					DSP_CORE_DIR_DIRQ3
#define DSP_TIRQ 					DSP_CORE_DIR_TIR
#define DSP_RIRQ1	 				DSP_CORE_DIR_RIRQ1
#define DSP_XIRQ1					DSP_CORE_DIR_XIRQ1
#define DSP_RIRQ2 					DSP_CORE_DIR_RIRQ2
#define DSP_XIRQ2 					DSP_CORE_DIR_XIRQ2
#define DSP_RIRQ3 					DSP_CORE_DIR_RIRQ3
#define DSP_XIRQ3 					DSP_CORE_DIR_XIRQ3
#define DSP_CDIRQ 					DSP_CORE_DIR_CDIRQ
#define DSP_CRIRQ 					DSP_CORE_DIR_CRIRQ
#define DSP_DMAIRQ					DSP_CORE_DIR_DMAIRQ

#define DSP_DIR_Msk					(DSP_DIRQ0 | DSP_DIRQ1 | DSP_DIRQ2 |\
									 DSP_DIRQ3 | DSP_TIRQ  | DSP_RIRQ1 |\
									 DSP_XIRQ1 | DSP_RIRQ2 | DSP_XIRQ2 |\
									 DSP_RIRQ3 | DSP_XIRQ3 | DSP_CDIRQ |\
									 DSP_CRIRQ | DSP_DMAIRQ)

#define IS_DSP_DIR(DIR)				((DIR & (~DSP_DIR_Msk)) == 0)

/** @} */ /* End of group DSP_DIR */

/** @defgroup DSP_Exported_Functions DSP Exported Functions
  * @{
  */

void DSP_DeInit(void);
void DSP_RST_Cmd(FunctionalState NewState);
void DSP_CPU_Cmd(FunctionalState NewState);
void DSP_MEM_Cmd(FunctionalState NewState);
void DSP_PER_Cmd(FunctionalState NewState);
void DSP_ReadBufferCmd(FunctionalState NewState);
FlagStatus DSP_GetStatus(uint32_t flag);
void DSP_CLKPCLKCmd(uint32_t DSP_CLK_PCLK, FunctionalState NewSate);
void DSP_RISCToDSPInterruptCmd(uint32_t Interrupt, FlagStatus NewStatus);
void DSP_DMA_RISC_Cmd(uint32_t ADMA, FlagStatus NewStatus);
void DSP_DSPToRISCInterruptCmd(uint32_t Interrupt, FlagStatus NewStatus);


/** @} */ /* End of group DSP_Exported_Functions */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

#endif /* MDR32F9QX_DSP_H_ */

/*
*
* END OF FILE MDR32F9Qx_dsp.h */
