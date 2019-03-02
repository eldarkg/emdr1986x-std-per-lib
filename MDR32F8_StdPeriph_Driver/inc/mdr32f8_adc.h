/**
  ******************************************************************************
  * @file    mdr32f8_adc.h
  * @author  Milandr Application Team
  * @version V1.4.0
  * @date    20/07/2015
  * @brief   This file contains all the functions prototypes for the ADC
  *          firmware library.
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
  * FILE mdr32f8_adc.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MDR32F8_ADC_H
#define __MDR32F8_ADC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"	
#include "mdr32f8_config.h"
#include "MDR1986VE8T.h"	

/** @addtogroup __MDR32F8_StdPeriph_Driver MDR32F8 Standard Peripherial Driver
  * @{
  */

/** @addtogroup  ADC ADC
  * @{
  */

/** @defgroup ADC_Exported_Types ADC Exported Types
  * @{
  */

/**
  * @brief  ADC Init structure definition
  */

typedef struct {

/* CONFIG0 */
	//uint32_t ADC_ADCEN;
	
	uint32_t ADC_WORKMODE;

	uint32_t ADC_REFMODE; 

	uint32_t ADC_RH_MODE;

	uint32_t ADC_SELMODE; 
	
	//uint32_t ADC_FIFOCLR;	

	uint32_t ADC_EXT_GO_INV;

	uint32_t ADC_EXT_GO_SEL;
	
/* CONFIG1 */
	uint32_t ADC_REFTRIM;

	uint32_t ADC_SETUP; 

	uint32_t ADC_PAUSE;

	uint32_t ADC_ADCTRIM;
 	
/* CONFIG2 */	
	FunctionalState ADC_IE_NE;

	FunctionalState ADC_IE_OF; 

	FunctionalState ADC_IE_NAE;

	FunctionalState ADC_IE_AF;
	
	FunctionalState ADC_IE_ERFIN;

	uint32_t ADC_LEVLCNTRL; 

	uint32_t ADC_REFSEL;

	uint32_t ADC_REF_TRIMR;

	uint32_t ADC_DT_MODE;
	
	uint32_t ADC_FIFOEN_0_31;
	
	uint32_t ADC_FIFOEN_32_63;
	
//	uint32_t ADC_FIFOEN;

} ADCx_InitTypeDef;


#define ADCx_CONFIG0_WORKMODE_GO_CONV					(uint32_t)(0x00 << ADCx_CONFIG0_WORKMODE_Pos)
#define ADCx_CONFIG0_WORKMODE_EXT_GO					(uint32_t)(0x01 << ADCx_CONFIG0_WORKMODE_Pos)
#define ADCx_CONFIG0_WORKMODE_CONT						(uint32_t)(0x02 << ADCx_CONFIG0_WORKMODE_Pos)

#define ADCx_CONFIG0_REFMODE_ADC_POW				  (uint32_t)(0x00 << ADCx_CONFIG0_REFMODE_Pos)
#define ADCx_CONFIG0_REFMODE_REFSEL						(uint32_t)(0x01 << ADCx_CONFIG0_REFMODE_Pos)

#define ADCx_CONFIG0_RH_MODE_REF25						(uint32_t)(0x00 << ADCx_CONFIG0_RH_MODE_Pos)
#define ADCx_CONFIG0_RH_MODE_ADC_POW				  (uint32_t)(0x01 << ADCx_CONFIG0_RH_MODE_Pos)

#define ADCx_CONFIG0_SELMODE_NOSW							(uint32_t)(0x00 << ADCx_CONFIG0_SELMODE_Pos)
#define ADCx_CONFIG0_SELMODE_CHSEL					  (uint32_t)(0x01 << ADCx_CONFIG0_SELMODE_Pos)

#define ADCx_CONFIG0_EXT_GO_INV_NOINV					(uint32_t)(0x00 << ADCx_CONFIG0_EXT_GO_INV_Pos)
#define ADCx_CONFIG0_EXT_GO_INV_INV						(uint32_t)(0x01 << ADCx_CONFIG0_EXT_GO_INV_Pos)

#define ADCx_CONFIG0_EXT_GO_SEL_NO_SRC				(uint32_t)(0x00 << ADCx_CONFIG0_EXT_GO_SEL_Pos)
#define ADCx_CONFIG0_EXT_GO_SEL_ADC_GO				(uint32_t)(0x00 << ADCx_CONFIG0_EXT_GO_SEL_Pos)

#define ADCx_CONFIG1_REFTRIM_TYP							(uint32_t)(0x00 << ADCx_CONFIG1_REFTRIM_Pos)

#define ADCx_CONFIG1_SETUP_NOPAUSE						(uint32_t)(0x00 << ADCx_CONFIG1_SETUP_Pos)

#define ADCx_CONFIG1_PAUSE_NOPAUSE						(uint32_t)(0x80 << ADCx_CONFIG1_PAUSE_Pos)

//#define ADCx_CONFIG1_ADCTRIM_NOTR						(uint32_t)(0x00 << ADCx_CONFIG1_ADCTRIM_Pos)

//#define ADCx_CONFIG2_IE_NE_									(uint32_t)(0x80 << ADCx_CONFIG2_IE_NE_Pos)
//#define ADCx_CONFIG2_IE_NE_									(uint32_t)(0x00 << ADCx_CONFIG2_IE_NE_Pos)

//#define ADCx_CONFIG2_IE_OF_									(uint32_t)(0x80 << ADCx_CONFIG2_IE_OF_Pos)
//#define ADCx_CONFIG2_IE_OF_									(uint32_t)(0x00 << ADCx_CONFIG2_IE_OF_Pos)

//#define ADCx_CONFIG2_IE_NAE_								(uint32_t)(0x80 << ADCx_CONFIG2_IE_NAE_Pos)
//#define ADCx_CONFIG2_IE_NAE_								(uint32_t)(0x00 << ADCx_CONFIG2_IE_NAE_Pos)

//#define ADCx_CONFIG2_IE_AF_									(uint32_t)(0x80 << ADCx_CONFIG2_IE_AF_Pos)
//#define ADCx_CONFIG2_IE_AF_									(uint32_t)(0x00 << ADCx_CONFIG2_IE_AF_Pos)

//#define ADCx_CONFIG2_IE_ERFIN_								(uint32_t)(0x80 << ADCx_CONFIG2_IE_ERFIN_Pos)
//#define ADCx_CONFIG2_IE_ERFIN_								(uint32_t)(0x00 << ADCx_CONFIG2_IE_ERFIN_Pos)

#define ADCx_CONFIG2_LEVLCNTRL_NOCTRL						(uint32_t)(0x00 << ADCx_CONFIG2_LEVLCNTRL_Pos)
#define ADCx_CONFIG2_LEVLCNTRL_INCMINMAX				(uint32_t)(0x01 << ADCx_CONFIG2_LEVLCNTRL_Pos)
#define ADCx_CONFIG2_LEVLCNTRL_NOINCMINMAX			(uint32_t)(0x02 << ADCx_CONFIG2_LEVLCNTRL_Pos)
//#define ADCx_CONFIG2_LEVLCNTRL_								(uint32_t)(0x03 << ADCx_CONFIG2_LEVLCNTRL_Pos)

//#define ADCx_CONFIG2_REFSEL_									(uint32_t)(0x80 << ADCx_CONFIG2_REFSEL_Pos)
//#define ADCx_CONFIG2_REFSEL_									(uint32_t)(0x00 << ADCx_CONFIG2_REFSEL_Pos)

//#define ADCx_CONFIG2_REFTRIMR_								(uint32_t)(0x80 << ADCx_CONFIG2_REFTRIMR_Pos)
//#define ADCx_CONFIG2_REFTRIMR_								(uint32_t)(0x00 << ADCx_CONFIG2_REFTRIMR_Pos)

//#define ADCx_CONFIG2_DT_MODE_									(uint32_t)(0x80 << ADCx_CONFIG2_DT_MODE_Pos)
//#define ADCx_CONFIG2_DT_MODE_									(uint32_t)(0x00 << ADCx_CONFIG2_DT_MODE_Pos)



#define ADCx_CONTROL_CHANNEL_Pos         		8
#define ADCx_CONTROL_CHANNEL_Mask						((uint32_t)0x00003F00)
#define ADCx_CONTROL_GO											((uint32_t)0x00000001)

#define ADCx_DIV_Msk        								((uint32_t)0x0000FFFF)
#define ADCx_CLK_EN         								((uint32_t)(1<<16))
#define ADCx_CLKSRC_msk                     ((uint32_t)0xF0000000) 
#define ADCx_CLKSRC_offs                    28

#define ADCx_CLKSRC_HSI                     ((uint32_t)0x00000000)
#define ADCx_CLKSRC_HSE0                    ((uint32_t)0x00000001)
#define ADCx_CLKSRC_HSE1                    ((uint32_t)0x00000002)
#define ADCx_CLKSRC_LSI                     ((uint32_t)0x00000003)
#define ADCx_CLKSRC_LSE                     ((uint32_t)0x00000004)
#define ADCx_CLKSRC_PLL0                    ((uint32_t)0x00000005)
#define ADCx_CLKSRC_PLL1                    ((uint32_t)0x00000006)
#define ADCx_CLKSRC_PLL2                    ((uint32_t)0x00000007)
#define ADCx_CLKSRC_MAX_CLK                 ((uint32_t)0x0000000D)

#define IS_ADCx_CLKSRC(CLKSRC)  					(((CLKSRC) == ADCx_CLKSRC_HSI)  || \
																					 ((CLKSRC) == ADCx_CLKSRC_HSE0) || \
																					 ((CLKSRC) == ADCx_CLKSRC_HSE1) || \
																					 ((CLKSRC) == ADCx_CLKSRC_LSI)  || \
																					 ((CLKSRC) == ADCx_CLKSRC_LSE)  || \
																					 ((CLKSRC) == ADCx_CLKSRC_PLL0) || \
																					 ((CLKSRC) == ADCx_CLKSRC_PLL1) || \
																					 ((CLKSRC) == ADCx_CLKSRC_PLL2) || \
																					 ((CLKSRC) == ADCx_CLKSRC_MAX_CLK))																				 

#define ADCx_CLKdiv1                        ((uint32_t)0x00000000)
#define ADCx_CLKdiv2                        ((uint32_t)0x00000001)
#define ADCx_CLKdiv4                        ((uint32_t)0x00000002)
#define ADCx_CLKdiv8                        ((uint32_t)0x00000003)
/** @} */ /* End of group ADC_Exported_Types */

#define ADC_FLAG_NE													((uint32_t)0x00000001)
#define ADC_FLAG_OF													((uint32_t)0x00000002)
#define ADC_FLAG_NAE											  ((uint32_t)0x00000004)
#define ADC_FLAG_AF													((uint32_t)0x00000008)
#define ADC_FLAG_ERFIN										  ((uint32_t)0x00000010)

#define FIEN0  										  					((uint32_t)0x00000001)
#define FIEN1  										  					((uint32_t)0x00000002)
#define FIEN2  										  					((uint32_t)0x00000004)
#define FIEN3  										  					((uint32_t)0x00000008)
#define FIEN4  										  					((uint32_t)0x00000010)
#define FIEN5  										  					((uint32_t)0x00000020)
#define FIEN6  										  					((uint32_t)0x00000040)

/** @defgroup ADC_Exported_Macros ADC Exported Macros
  * @{
  */

/** @} */ /* End of group ADC_Exported_Macros */

/** @defgroup ADC_Exported_Functions ADC Exported Functions
  * @{
  */

void ADC_Init(ADCxControl* ADCx, const ADCx_InitTypeDef* ADC_InitStruct);
void ADC_StructInit(ADCx_InitTypeDef* ADC_InitStruct);
void ADCx_Cmd(ADCxControl* ADCx, FunctionalState NewState);
void ADCx_SetChannel(ADCxControl* ADCx, uint32_t Channel);
void ADCx_SetChannels0(ADCxControl* ADCx, uint32_t ChannelMask);
void ADCx_SetChannels1(ADCxControl* ADCx, uint32_t ChannelMask);
void ADCx_Start(ADCxControl* ADCx);
uint32_t ADCx_GetResult(ADCxControl* ADCx);
uint32_t ADCx_GetStatus (ADCxControl* ADCx);
FlagStatus ADC_GetFlagStatus(ADCxControl* ADCx, uint32_t Flag);
//void ADC_CLK_en(uint32_t ADC_CLKSRC, uint32_t ADC_CLK_DIV);
void ADCx_CLK_en(ADCxControl* ADCx, uint32_t ADC_CLKSRC, uint32_t ADC_CLK_DIV);

/** @} */ /* End of group ADC_Exported_Functions */

/** @} */ /* End of group ADC */

/** @} */ /* End of group __MDR32F8_StdPeriph_Driver */

#ifdef __cplusplus
} // extern "C" block end
#endif

#endif /* __MDR32F8_ADC_H */

/******************* (C) COPYRIGHT 2011 Phyton *********************************
*
* END OF FILE mdr32f8_adc.h */

