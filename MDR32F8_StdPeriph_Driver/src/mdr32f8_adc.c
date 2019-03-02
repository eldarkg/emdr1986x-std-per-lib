/**
  ******************************************************************************
  * @file    mdr32f8_adc.c
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
  * FILE mdr32f8_adc.c
  */

/* Includes ------------------------------------------------------------------*/
#include "mdr32f8_config.h"
#include "mdr32f8_adc.h"

#define ASSERT_INFO_FILE_ID FILEID__MDR32F8_ADC_C

/** @addtogroup __MDR32F8_StdPeriph_Driver MDR32F8 Standard Peripherial Driver
  * @{
  */

/** @defgroup ADC ADC
  * @{
  */

/** @defgroup ADC_Private_Functions ADC Private Functions
  * @{
  */

void ADC_StructInit(ADCx_InitTypeDef* ADC_InitStruct)
{
  //  reg CONFIG0
  ADC_InitStruct->ADC_WORKMODE   = 0;   // Run by GO bit
	ADC_InitStruct->ADC_REFMODE    = 0;   // Ref by ADUcc and ADGND
	ADC_InitStruct->ADC_RH_MODE    = 0;   // Iref from REF25 
	ADC_InitStruct->ADC_SELMODE    = 0;   // Channel's switching Off
	ADC_InitStruct->ADC_EXT_GO_INV = 0;   // EXT_GO Invertion Off
	ADC_InitStruct->ADC_EXT_GO_SEL = 0;   // EXT_GO Disabled
  
  //  reg CONFIG1
  ADC_InitStruct->ADC_ADCTRIM    = 0;   // No correction  
	ADC_InitStruct->ADC_SETUP      = 5;   // ADCCLK ticks
	ADC_InitStruct->ADC_PAUSE      = 5;   // ADCCLK ticks 
  ADC_InitStruct->ADC_REFTRIM    = 0;   // Trim by Default

  //  reg CONFIG2
	ADC_InitStruct->ADC_IE_NE    = DISABLE;  
	ADC_InitStruct->ADC_IE_OF    = DISABLE;
	ADC_InitStruct->ADC_IE_NAE   = DISABLE;
	ADC_InitStruct->ADC_IE_AF    = DISABLE;
	ADC_InitStruct->ADC_IE_ERFIN = DISABLE;
  
	ADC_InitStruct->ADC_LEVLCNTRL    = 0;    //  Min_Level / Max_Level disabled
	ADC_InitStruct->ADC_REFSEL       = 0;    //  unused with ADC_REFMODE = 0
	ADC_InitStruct->ADC_REF_TRIMR    = 0x7F; //  Middle value
	ADC_InitStruct->ADC_DT_MODE      = 0;    //  Temperature sensor 
	ADC_InitStruct->ADC_FIFOEN_0_31  = 0;    //  FIFO no channel selected
	ADC_InitStruct->ADC_FIFOEN_32_63 = 0;    //  FIFO no channel selected
  
	//ADC_InitStruct->ADC_FIFOEN = 0;
}  


/**
  * @brief  Initializes the ADC peripheral according to
  *         the specified parameters in the ADC_InitStruct.
  * @param  ADC_InitStruct: pointer to a ADC_InitTypeDef structure
  *         that contains the configuration information for the specified ADC
  *         peripheral.
  * @retval None
  */
void ADC_Init(ADCxControl* ADCx, const ADCx_InitTypeDef* ADC_InitStruct)
{
  uint32_t tmpreg_CONFIG0;
  uint32_t tmpreg_CONFIG1;
  uint32_t tmpreg_CONFIG2;
  uint32_t tmpreg_CONFIG0_MSK;	
  uint32_t tmpreg_CONFIG1_MSK;	
  uint32_t tmpreg_CONFIG2_MSK;		
  //uint32_t tmpreg_MSK;

  assert_param(IS_ADC_START_DELAY_VALUE(ADC_InitStruct->ADC_StartDelay));
  assert_param(IS_ADC_TEMP_SENSOR_CONFIG(ADC_InitStruct->ADC_TempSensor));
  assert_param(IS_ADC_TEMP_SENSOR_AMP_CONFIG(ADC_InitStruct->ADC_TempSensorAmplifier));
  assert_param(IS_ADC_TEMP_SENSOR_CONVERSION_CONFIG(ADC_InitStruct->ADC_TempSensorConversion));
  assert_param(IS_ADC_VREF_CONVERSION_CONFIG(ADC_InitStruct->ADC_IntVRefConversion));
  assert_param(IS_ADC_VREF_TRIMMING_VALUE(ADC_InitStruct->ADC_IntVRefTrimming));

/* CONFIG0 */	
  tmpreg_CONFIG0 = (ADC_InitStruct->ADC_WORKMODE << ADCx_CONFIG0_WORKMODE_Pos)
             | (ADC_InitStruct->ADC_REFMODE << ADCx_CONFIG0_REFMODE_Pos)
             | (ADC_InitStruct->ADC_RH_MODE << ADCx_CONFIG0_RH_MODE_Pos)
             | (ADC_InitStruct->ADC_SELMODE << ADCx_CONFIG0_SELMODE_Pos)
	           | (ADC_InitStruct->ADC_EXT_GO_INV << ADCx_CONFIG0_EXT_GO_INV_Pos)
             | (ADC_InitStruct->ADC_EXT_GO_SEL << ADCx_CONFIG0_EXT_GO_SEL_Pos);

  tmpreg_CONFIG0_MSK = ADCx_CONFIG0_WORKMODE
             | ADCx_CONFIG0_REFMODE
             | ADCx_CONFIG0_RH_MODE
             | ADCx_CONFIG0_SELMODE
             | ADCx_CONFIG0_EXT_GO_INV
             | ADCx_CONFIG0_EXT_GO_SEL;

/* CONFIG1 */
	tmpreg_CONFIG1 = (ADC_InitStruct->ADC_REFTRIM << ADCx_CONFIG1_REFTRIM_Pos)
             | (ADC_InitStruct->ADC_SETUP << ADCx_CONFIG1_SETUP_Pos)
	           | (ADC_InitStruct->ADC_PAUSE << ADCx_CONFIG1_PAUSE_Pos)
             | (ADC_InitStruct->ADC_ADCTRIM << ADCx_CONFIG1_ADCTRIM_Pos);

  tmpreg_CONFIG1_MSK = ADCx_CONFIG1_REFTRIM
             | ADCx_CONFIG1_SETUP
             | ADCx_CONFIG1_PAUSE
             | ADCx_CONFIG1_ADCTRIM;
	
/* CONFIG2 */	
  tmpreg_CONFIG2 = (ADC_InitStruct->ADC_IE_NE << ADCx_CONFIG2_IE_NE_Pos)
             | (ADC_InitStruct->ADC_IE_OF << ADCx_CONFIG2_IE_OF_Pos)
             | (ADC_InitStruct->ADC_IE_NAE << ADCx_CONFIG2_IE_NAE_Pos)
             | (ADC_InitStruct->ADC_IE_AF << ADCx_CONFIG2_IE_AF_Pos)
	           | (ADC_InitStruct->ADC_IE_ERFIN << ADCx_CONFIG2_IE_ERFIN_Pos)
             | (ADC_InitStruct->ADC_LEVLCNTRL << ADCx_CONFIG2_LEVLCNTRL_Pos)
             | (ADC_InitStruct->ADC_REFSEL << ADCx_CONFIG2_REFSEL_Pos)
             | (ADC_InitStruct->ADC_REF_TRIMR << ADCx_CONFIG2_REFTRIMR_Pos)
             | (ADC_InitStruct->ADC_DT_MODE << ADCx_CONFIG2_DT_MODE_Pos);						 
					
   tmpreg_CONFIG2_MSK = ADCx_CONFIG2_IE_NE
             | ADCx_CONFIG2_IE_OF
             | ADCx_CONFIG2_IE_NAE
             | ADCx_CONFIG2_IE_AF
             | ADCx_CONFIG2_IE_ERFIN
             | ADCx_CONFIG2_LEVLCNTRL
             | ADCx_CONFIG2_REFSEL
             | ADCx_CONFIG2_REFTRIMR
             | ADCx_CONFIG2_DT_MODE;		
		
	ADCx->CONFIG0 = (ADCx->CONFIG0 & ~tmpreg_CONFIG0_MSK) | tmpreg_CONFIG0;
	ADCx->CONFIG1 = (ADCx->CONFIG1 & ~tmpreg_CONFIG1_MSK) | tmpreg_CONFIG1;
	ADCx->CONFIG2 = (ADCx->CONFIG2 & ~tmpreg_CONFIG2_MSK) | tmpreg_CONFIG2;	
	
//	if((ADC_InitStruct->ADC_FIFOEN)<32)
//	ADCx->FIFOEN0 = (1 << (ADC_InitStruct->ADC_FIFOEN));
//	else
//	ADCx->FIFOEN1 = (1 << ((ADC_InitStruct->ADC_FIFOEN)-32));			


	ADCx->FIFOEN0 = ADC_InitStruct->ADC_FIFOEN_0_31;

	ADCx->FIFOEN1 = ADC_InitStruct->ADC_FIFOEN_32_63;		
		
}

/**
  * @brief  Fills each ADCx_InitStruct member with its default value.
  * @param  ADCx_InitStruct: pointer to a ADCx_InitTypeDef structure
  *         which will be initialized.
  * @retval None
  */
void ADCx_StructInit(ADCx_InitTypeDef* ADCx_InitStruct)
{
/* CONFIG0 */	
ADCx_InitStruct->ADC_WORKMODE = 0;
ADCx_InitStruct->ADC_REFMODE = 0; 
ADCx_InitStruct->ADC_RH_MODE = 0;
ADCx_InitStruct->ADC_SELMODE = 0; 	
ADCx_InitStruct->ADC_EXT_GO_INV = 0;
ADCx_InitStruct->ADC_EXT_GO_SEL = 0;
/* CONFIG1 */
ADCx_InitStruct->ADC_REFTRIM = 0;
ADCx_InitStruct->ADC_SETUP = 0; 
ADCx_InitStruct->ADC_PAUSE = 0;
ADCx_InitStruct->ADC_ADCTRIM = 0;
/* CONFIG2 */	
ADCx_InitStruct->ADC_IE_NE = DISABLE;
ADCx_InitStruct->ADC_IE_OF = DISABLE; 
ADCx_InitStruct->ADC_IE_NAE = DISABLE;
ADCx_InitStruct->ADC_IE_AF = DISABLE;
ADCx_InitStruct->ADC_IE_ERFIN = DISABLE;
ADCx_InitStruct->ADC_LEVLCNTRL = 0; 
ADCx_InitStruct->ADC_REFSEL = 0;
ADCx_InitStruct->ADC_REF_TRIMR = 0;
ADCx_InitStruct->ADC_DT_MODE = 0;
}

/**
  * @brief  Enables or disables the ADC1 peripheral.
  * @param  NewState: new state of the ADC1 peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void ADCx_Cmd(ADCxControl* ADCx, FunctionalState NewState)
{
  uint32_t tmpreg_CFG;

  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  tmpreg_CFG = ADCx->CONFIG0;

  /* Form new value */
  if (NewState != DISABLE)
  {
    /* Enable ADCx by setting the ADCx_CONFIG0_ADCEN bit in the CONFIG0 register */
    tmpreg_CFG |= ADCx_CONFIG0_ADCEN;
  }
  else
  {
    /* Disable ADCx by resetting the ADCx_CONFIG0_ADCEN bit in the CONFIG0 register */
    tmpreg_CFG &= ~ADCx_CONFIG0_ADCEN;
  }

  /* Configure CONFIG0 register with new value */
  ADCx->CONFIG0 = tmpreg_CFG;
}

/**
  * @brief  Selects the ADCx Channel number for Single Channel Mode conversion.
  * @param  Channel: specifies the ADC Channel number.
  * @retval None
  */
void ADCx_SetChannel(ADCxControl* ADCx, uint32_t Channel)
{
  uint32_t tmpreg_CTRL;

  /* Check the parameters */
  assert_param(IS_ADC1_CH_NUM(Channel));

  tmpreg_CTRL = ADCx->CONTROL;
  tmpreg_CTRL &= ~ADCx_CONTROL_CHANNEL_Mask;
  tmpreg_CTRL |= Channel << ADCx_CONTROL_CHANNEL_Pos;
  ADCx->CONTROL = tmpreg_CTRL;
}

/**
  * @brief  Selects the ADCx Channels for conversion with Channels switching.
  * @param  ChannelMask: specifies the ADC Channels Mask.
  * @retval None
  */
void ADCx_SetChannels0(ADCxControl* ADCx, uint32_t ChannelMask)
{
  /* Check the parameters */
  assert_param(IS_ADC1_CH_MASK(ChannelMask));

  ADCx->CHSEL0 = ChannelMask;
}

/**
  * @brief  Selects the ADCx Channels for conversion with Channels switching.
  * @param  ChannelMask: specifies the ADC Channels Mask.
  * @retval None
  */
void ADCx_SetChannels1(ADCxControl* ADCx, uint32_t ChannelMask)
{
  /* Check the parameters */
  assert_param(IS_ADC1_CH_MASK(ChannelMask));

  ADCx->CHSEL1 = ChannelMask;
}

/**
  * @brief  Starts the ADC1 conversion.
  * @param  None.
  * @retval None.
  */
void ADCx_Start(ADCxControl* ADCx)
{
  ADCx->CONTROL |= ADCx_CONTROL_GO;
}

/**
  * @brief  Returns the ADC1 result.
  * @param  None.
  * @retval ADC1 Result Register value.
  */
uint32_t ADCx_GetResult(ADCxControl* ADCx)
{
  return ADCx->RESULT;
}

/**
  * @brief  Returns the ADC1, ADC2 Status Registers combined value.
  * @param  None.
  * @retval The ADC1_STATUS, ADC2_STATUS Registers combined value.
  */
uint32_t ADCx_GetStatus (ADCxControl* ADCx)
{
  return ADCx->STATUS;
}

/**
  * @brief  Checks whether the specified ADC1, ADC2 Status flag is set or not.
  * @param  Flag: specifies the flag to check.
  *         This parameter can be one of the following values:
  *           @arg ADC1_FLAG_OVERWRITE:         the previous ADC1 measured value was overwritten;
  *           @arg ADC1_FLAG_OUT_OF_RANGE:      the ADC1 measured value is out of range;
  *           @arg ADC1_FLAG_END_OF_CONVERSION: the ADC1 conversion finished;
  *           @arg ADC2_FLAG_OVERWRITE:         the previous ADC2 measured value was overwritten;
  *           @arg ADC2_FLAG_OUT_OF_RANGE:      the ADC2 measured value is out of range;
  *           @arg ADC2_FLAG_END_OF_CONVERSION: the ADC2 conversion finished.
  * @retval Current Status flag state (SET or RESET).
  */
FlagStatus ADC_GetFlagStatus(ADCxControl* ADCx, uint32_t Flag)
{
  FlagStatus bitstatus;

  /* Check the parameters */
  assert_param(IS_ADC_STATUS_FLAG(Flag));

  if ((ADCx_GetStatus(ADCx) & Flag) == 0)
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
  * @brief  Initializes the ADCx peripheral Clock according to the
  *         specified parameters.
  * @param  ADCx: Select the ADC.
  *         This parameter can be one of the following values:
  *         ADC0, ADC1.
  * @param  UART_BRG: specifies the HCLK division factor.
  *         This parameter can be one of the following values:
  *           @arg UART_CLKdiv1
  *           @arg UART_CLKdiv2
  *           @arg UART_CLKdiv4
  *           @arg UART_CLKdiv8
  * @retval None
  */
//void ADC_CLK_en(uint32_t ADC_CLKSRC, uint32_t ADC_CLK_DIV)
//{
//  uint32_t tmpreg;
//  /* Check the parameters */
//  assert_param(IS_UART_ALL_PERIPH(UARTx));
//	assert_param(IS_UART_CLKSRC(UART_CLKSRC));
//     
//  tmpreg = CLK_CNTR->ADC0_CLK;

//  tmpreg &= ~(ADCx_DIV_Msk | ADCx_CLKSRC_msk);
//  tmpreg |= (ADC_CLKSRC << ADCx_CLKSRC_offs) | ADCx_CLK_EN | ADC_CLK_DIV;
//  
//  CLK_CNTR->ADC0_CLK = tmpreg;
//}

void ADCx_CLK_en(ADCxControl* ADCx, uint32_t ADC_CLKSRC, uint32_t ADC_CLK_DIV)
{
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
	assert_param(IS_UART_CLKSRC(UART_CLKSRC));
   
  if (ADCx == ADC0)
  {  
    CLK_CNTR->ADC0_CLK = 0;
    CLK_CNTR->ADC0_CLK = (ADC_CLKSRC<< ADCx_CLKSRC_offs) | ADCx_CLK_EN | ADC_CLK_DIV;    
  }  
  else
  {  
    CLK_CNTR->ADC1_CLK = 0;
    CLK_CNTR->ADC1_CLK = (ADC_CLKSRC<< ADCx_CLKSRC_offs) | ADCx_CLK_EN | ADC_CLK_DIV;
  }  
}


/** @} */ /* End of group ADC_Private_Functions */

/** @} */ /* End of group ADC */

/** @} */ /* End of group __MDR32F8_StdPeriph_Driver */

/******************* (C) COPYRIGHT 2015 Milandr *********************************
*
* END OF FILE mdr32f8_adc.c */

