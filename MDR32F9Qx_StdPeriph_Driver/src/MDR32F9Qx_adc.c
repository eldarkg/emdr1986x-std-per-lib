/**
  ******************************************************************************
  * @file    MDR32F9Qx_adc.c
  * @author  Phyton Application Team
  * @version V1.4.0
  * @date    22/07/2011
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
  * <h2><center>&copy; COPYRIGHT 2011 Phyton</center></h2>
  ******************************************************************************
  * FILE MDR32F9Qx_adc.c
  */

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_config.h"
#include "MDR32F9Qx_adc.h"

#define ASSERT_INFO_FILE_ID FILEID__MDR32F9X_ADC_C

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @defgroup ADC ADC
  * @{
  */

/** @defgroup ADC_Private_Functions ADC Private Functions
  * @{
  */

/**
  * @brief  Deinitializes the ADC peripheral registers to their default reset values.
  * @param  None.
  * @retval None.
  */
void ADC_DeInit ( void )
{
  MDR_ADC->ADC1_CFG = 0;
  MDR_ADC->ADC2_CFG = 0;
  MDR_ADC->ADC1_H_LEVEL = 0;
  MDR_ADC->ADC1_L_LEVEL = 0;
  MDR_ADC->ADC1_RESULT;
  MDR_ADC->ADC1_STATUS = 0;
  MDR_ADC->ADC1_CHSEL = 0;

#if defined ( USE_MDR1986VE9x ) /* For Cortex M3 */
  MDR_ADC->ADC2_H_LEVEL = 0;
  MDR_ADC->ADC2_L_LEVEL = 0;
  MDR_ADC->ADC2_RESULT;
  MDR_ADC->ADC2_STATUS = 0;
  MDR_ADC->ADC2_CHSEL = 0;
#endif // #if defined ( USE_MDR1986VE9x ) /* For Cortex M3 */

#if defined (USE_MDR1986VE1T) || defined (USE_MDR1986VE3)
  MDR_ADC->ADC1_TRIM = 0;
#endif
}

/**
  * @brief  Initializes the ADC peripheral according to
  *         the specified parameters in the ADC_InitStruct.
  * @param  ADC_InitStruct: pointer to a ADC_InitTypeDef structure
  *         that contains the configuration information for the specified ADC
  *         peripheral.
  * @retval None
  */
void ADC_Init(const ADC_InitTypeDef* ADC_InitStruct)
{
  uint32_t tmpreg_CFG;
  uint32_t tmpreg_MSK;
#if defined (USE_MDR1986VE1T) || defined (USE_MDR1986VE3)
  uint32_t tmpreg_TRIM;
#endif

  /* Check the parameters */
#if defined (USE_MDR1986VE9x)
  assert_param(IS_ADC_SYNC_MODE(ADC_InitStruct->ADC_SynchronousMode));
#endif
  assert_param(IS_ADC_START_DELAY_VALUE(ADC_InitStruct->ADC_StartDelay));
  assert_param(IS_ADC_TEMP_SENSOR_CONFIG(ADC_InitStruct->ADC_TempSensor));
  assert_param(IS_ADC_TEMP_SENSOR_AMP_CONFIG(ADC_InitStruct->ADC_TempSensorAmplifier));
  assert_param(IS_ADC_TEMP_SENSOR_CONVERSION_CONFIG(ADC_InitStruct->ADC_TempSensorConversion));
  assert_param(IS_ADC_VREF_CONVERSION_CONFIG(ADC_InitStruct->ADC_IntVRefConversion));
  assert_param(IS_ADC_VREF_TRIMMING_VALUE(ADC_InitStruct->ADC_IntVRefTrimming));
#if defined (USE_MDR1986VE1T) || defined (USE_MDR1986VE3)
  assert_param(IS_ADC_INT_VREF_AMPLIFIER(ADC_InitStruct->ADC_IntVRefAmplifier));
#endif

  tmpreg_CFG = (ADC_InitStruct->ADC_StartDelay << ADC1_CFG_DELAY_ADC_Pos)
             + ADC_InitStruct->ADC_TempSensor
             + ADC_InitStruct->ADC_TempSensorAmplifier
             + ADC_InitStruct->ADC_TempSensorConversion
             + ADC_InitStruct->ADC_IntVRefConversion;

#if defined( USE_MDR1986VE9x ) /* For Cortex M3*/
  tmpreg_CFG += (ADC_InitStruct->ADC_IntVRefTrimming << ADC1_CFG_TR_Pos)
             +   ADC_InitStruct->ADC_SynchronousMode;
#endif // #if defined(USE_MDR1986VE9x) /* For Cortex M3*/

  tmpreg_MSK = ADC1_CFG_DELAY_ADC_Msk
             | ADC1_CFG_TS_EN
             | ADC1_CFG_TS_BUF_EN
             | ADC1_CFG_SEL_TS
             | ADC1_CFG_SEL_VREF;
#if defined( USE_MDR1986VE9x ) /* For Cortex M3*/
  tmpreg_MSK |= ADC1_CFG_TR_Msk
             |  ADC1_CFG_SYNC_CONVER;
#elif defined (USE_MDR1986VE1T) || defined (USE_MDR1986VE3)
  tmpreg_TRIM = (ADC_InitStruct->ADC_IntVRefTrimming << ADC1_TRIM_TS_TRIM_Pos)
          | ADC_InitStruct->ADC_IntVRefAmplifier;
  MDR_ADC->ADC1_TRIM  = tmpreg_TRIM;
#endif

  MDR_ADC->ADC1_CFG = (MDR_ADC->ADC1_CFG & ~tmpreg_MSK) + tmpreg_CFG;
}

/**
  * @brief  Fills each ADC_InitStruct member with its default value.
  * @param  ADC_InitStruct: pointer to a ADC_InitTypeDef structure
  *         which will be initialized.
  * @retval None
  */
void ADC_StructInit(ADC_InitTypeDef* ADC_InitStruct)
{

#if defined( USE_MDR1986VE9x )
  ADC_InitStruct->ADC_SynchronousMode     = ADC_SyncMode_Independent;
#endif

  ADC_InitStruct->ADC_StartDelay        	= 0;
  ADC_InitStruct->ADC_TempSensor        	= ADC_TEMP_SENSOR_Disable;
  ADC_InitStruct->ADC_TempSensorAmplifier   = ADC_TEMP_SENSOR_AMPLIFIER_Disable;
  ADC_InitStruct->ADC_TempSensorConversion  = ADC_TEMP_SENSOR_CONVERSION_Disable;
  ADC_InitStruct->ADC_IntVRefConversion     = ADC_VREF_CONVERSION_Disable;
  ADC_InitStruct->ADC_IntVRefTrimming     	= 0;

#if defined ( USE_MDR1986VE3 ) || defined ( USE_MDR1986VE1T )
  ADC_InitStruct->ADC_IntVRefAmplifier    	= ADC_INT_VREF_AMPLIFIER_Disable;
#endif
}


/**
  * @brief  Sets the Internal Voltage Reference trimming.
  * @param  Trim: trimming value in range 0..7.
  * @retval None
  */
void ADC_SetTrim(uint32_t Trim)
{
  uint32_t tmpreg;

  /* Check the parameters */
  assert_param(IS_ADC_VREF_TRIMMING_VALUE(Trim));

#if defined(USE_MDR1986VE9x) /* For Cortex M3*/
  tmpreg = MDR_ADC->ADC1_CFG & ~ADC1_CFG_TR_Msk;
  MDR_ADC->ADC1_CFG = tmpreg + (Trim << ADC1_CFG_TR_Pos);

#elif defined (USE_MDR1986VE1T) || defined (USE_MDR1986VE3)
  tmpreg = MDR_ADC->ADC1_TRIM;
  tmpreg &= ~ADC1_TRIM_TS_TRIM_Msk;
  tmpreg |= Trim << ADC1_TRIM_TS_TRIM_Pos;
  MDR_ADC->ADC1_TRIM = tmpreg;
#endif
}


/**
  * @brief  Initializes the ADC1 peripheral according to
  *         the specified parameters in the ADCx_InitStruct.
  * @param  ADCx_InitStruct: pointer to a ADCx_InitTypeDef structure
  *         that contains the configuration information for the ADC1
  *         peripheral.
  * @retval None
  */
void ADC1_Init(const ADCx_InitTypeDef* ADCx_InitStruct)
{
  uint32_t tmpreg_CFG1;
  uint32_t tmpreg_CFG2;

  /* Check the parameters */
  assert_param(IS_ADC_CLOCK_SOURCE_CONFIG(ADCx_InitStruct->ADC_ClockSource));
  assert_param(IS_ADC_SAMPLING_MODE_CONFIG(ADCx_InitStruct->ADC_SamplingMode));
  assert_param(IS_ADC_CH_SWITCHING_CONFIG(ADCx_InitStruct->ADC_ChannelSwitching));
  assert_param(IS_ADC1_CH_NUM(ADCx_InitStruct->ADC_ChannelNumber));
  assert_param(IS_ADC1_CH_MASK(ADCx_InitStruct->ADC_Channels));
  assert_param(IS_ADC_LEVEL_CONTROL_CONFIG(ADCx_InitStruct->ADC_LevelControl));
  assert_param(IS_ADC_VALUE(ADCx_InitStruct->ADC_LowLevel));
  assert_param(IS_ADC_VALUE(ADCx_InitStruct->ADC_HighLevel));
  assert_param(IS_ADC_VREF_SOURCE_CONFIG(ADCx_InitStruct->ADC_VRefSource));
  assert_param(IS_ADC_INT_VREF_SOURCE_CONFIG(ADCx_InitStruct->ADC_IntVRefSource));
  assert_param(IS_ADC_CLK_div_VALUE(ADCx_InitStruct->ADC_Prescaler));
  assert_param(IS_ADC_DELAY_GO_VALUE(ADCx_InitStruct->ADC_DelayGo));

  tmpreg_CFG1 = MDR_ADC->ADC1_CFG;

  tmpreg_CFG1 &= ~(ADC1_CFG_REG_CLKS
                 | ADC1_CFG_REG_SAMPLE
                 | ADC1_CFG_REG_CHCH
                 | ADC1_CFG_REG_CHS_Msk
                 | ADC1_CFG_REG_RNGC
                 | ADC1_CFG_M_REF
                 | ADC1_CFG_REG_DIVCLK_Msk
                 | ADC1_CFG_DELAY_GO_Msk);

  tmpreg_CFG1 += ADCx_InitStruct->ADC_ClockSource
               + ADCx_InitStruct->ADC_SamplingMode
               + ADCx_InitStruct->ADC_ChannelSwitching
               + (ADCx_InitStruct->ADC_ChannelNumber << ADC1_CFG_REG_CHS_Pos)
               + ADCx_InitStruct->ADC_LevelControl
               + ADCx_InitStruct->ADC_VRefSource
               + ADCx_InitStruct->ADC_Prescaler
               + (ADCx_InitStruct->ADC_DelayGo << ADC1_CFG_DELAY_GO_Pos);

  tmpreg_CFG2 = MDR_ADC->ADC2_CFG;
  tmpreg_CFG2 &= ~ADC2_CFG_ADC1_OP;
  tmpreg_CFG2 += ADCx_InitStruct->ADC_IntVRefSource << ADC2_CFG_ADC1_OP_Pos;

  MDR_ADC->ADC1_CFG = tmpreg_CFG1;
  MDR_ADC->ADC2_CFG = tmpreg_CFG2;

  MDR_ADC->ADC1_L_LEVEL = ADCx_InitStruct->ADC_LowLevel;
  MDR_ADC->ADC1_H_LEVEL = ADCx_InitStruct->ADC_HighLevel;
  MDR_ADC->ADC1_CHSEL   = ADCx_InitStruct->ADC_Channels;
}

#if defined  (USE_MDR1986VE9x) /* For Cortex M3 */
/**
  * @brief  Initializes the ADC2 peripheral according to
  *         the specified parameters in the ADCx_InitStruct.
  * @warning 	This function can be used only for microcontroller
  * 		series MDR1986VE9x.
  * @param  ADCx_InitStruct: pointer to a ADCx_InitTypeDef structure
  *         that contains the configuration information for the ADC2
  *         peripheral.
  * @retval None
  */
void ADC2_Init(const ADCx_InitTypeDef* ADCx_InitStruct)
{
  uint32_t tmpreg_CFG2;

  /* Check the parameters */
  assert_param(IS_ADC_CLOCK_SOURCE_CONFIG(ADCx_InitStruct->ADC_ClockSource));
  assert_param(IS_ADC_SAMPLING_MODE_CONFIG(ADCx_InitStruct->ADC_SamplingMode));
  assert_param(IS_ADC_CH_SWITCHING_CONFIG(ADCx_InitStruct->ADC_ChannelSwitching));
  assert_param(IS_ADC2_CH_NUM(ADCx_InitStruct->ADC_ChannelNumber));
  assert_param(IS_ADC2_CH_MASK(ADCx_InitStruct->ADC_Channels));
  assert_param(IS_ADC_LEVEL_CONTROL_CONFIG(ADCx_InitStruct->ADC_LevelControl));
  assert_param(IS_ADC_VALUE(ADCx_InitStruct->ADC_LowLevel));
  assert_param(IS_ADC_VALUE(ADCx_InitStruct->ADC_HighLevel));
  assert_param(IS_ADC_VREF_SOURCE_CONFIG(ADCx_InitStruct->ADC_VRefSource));
  assert_param(IS_ADC_INT_VREF_SOURCE_CONFIG(ADCx_InitStruct->ADC_IntVRefSource));
  assert_param(IS_ADC_CLK_div_VALUE(ADCx_InitStruct->ADC_Prescaler));
  assert_param(IS_ADC_DELAY_GO_VALUE(ADCx_InitStruct->ADC_DelayGo));

  tmpreg_CFG2 = MDR_ADC->ADC2_CFG;

  tmpreg_CFG2 &= ~(ADC2_CFG_REG_CLKS
                 | ADC2_CFG_REG_SAMPLE
                 | ADC2_CFG_REG_CHCH
                 | ADC2_CFG_REG_CHS_Msk
                 | ADC2_CFG_REG_RNGC
                 | ADC2_CFG_M_REF
                 | ADC2_CFG_ADC2_OP
                 | ADC2_CFG_REG_DIVCLK_Msk
                 | ADC2_CFG_DELAY_GO_Msk);

  tmpreg_CFG2 += ADCx_InitStruct->ADC_ClockSource
               + ADCx_InitStruct->ADC_SamplingMode
               + ADCx_InitStruct->ADC_ChannelSwitching
               + (ADCx_InitStruct->ADC_ChannelNumber << ADC2_CFG_REG_CHS_Pos)
               + ADCx_InitStruct->ADC_LevelControl
               + ADCx_InitStruct->ADC_VRefSource
               + (ADCx_InitStruct->ADC_IntVRefSource << ADC2_CFG_ADC2_OP_Pos)
               + ADCx_InitStruct->ADC_Prescaler
               + (ADCx_InitStruct->ADC_DelayGo << ADC2_CFG_DELAY_GO_Pos);

  MDR_ADC->ADC2_CFG = tmpreg_CFG2;
  MDR_ADC->ADC2_L_LEVEL = ADCx_InitStruct->ADC_LowLevel;
  MDR_ADC->ADC2_H_LEVEL = ADCx_InitStruct->ADC_HighLevel;
  MDR_ADC->ADC2_CHSEL   = ADCx_InitStruct->ADC_Channels;
}

#endif /* #if defined  (USE_MDR1986VE9x) */

/**
  * @brief  Fills each ADCx_InitStruct member with its default value.
  * @param  ADCx_InitStruct: pointer to a ADCx_InitTypeDef structure
  *         which will be initialized.
  * @retval None
  */
void ADCx_StructInit(ADCx_InitTypeDef* ADCx_InitStruct)
{
  ADCx_InitStruct->ADC_ClockSource      = ADC_CLOCK_SOURCE_CPU;
  ADCx_InitStruct->ADC_SamplingMode     = ADC_SAMPLING_MODE_SINGLE_CONV;
  ADCx_InitStruct->ADC_ChannelSwitching = ADC_CH_SWITCHING_Disable;
  ADCx_InitStruct->ADC_ChannelNumber    = ADC_CH_ADC0;
  ADCx_InitStruct->ADC_Channels         = 0;
  ADCx_InitStruct->ADC_LevelControl     = ADC_LEVEL_CONTROL_Disable;
  ADCx_InitStruct->ADC_LowLevel         = 0;
  ADCx_InitStruct->ADC_HighLevel        = 0;
  ADCx_InitStruct->ADC_VRefSource       = ADC_VREF_SOURCE_INTERNAL;
  ADCx_InitStruct->ADC_IntVRefSource    = ADC_INT_VREF_SOURCE_INEXACT;
  ADCx_InitStruct->ADC_Prescaler        = ADC_CLK_div_None;
  ADCx_InitStruct->ADC_DelayGo          = 0;
}

/**
  * @brief  Enables or disables the ADC1 peripheral.
  * @param  NewState: new state of the ADC1 peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void ADC1_Cmd(FunctionalState NewState)
{
  uint32_t tmpreg_CFG;

  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  tmpreg_CFG = MDR_ADC->ADC1_CFG;

  /* Form new value */
  if (NewState != DISABLE)
  {
    /* Enable ADC1 by setting the Cfg_REG_ADON bit in the ADC1_CFG register */
    tmpreg_CFG |= ADC1_CFG_REG_ADON;
  }
  else
  {
    /* Disable ADC1 by resetting the Cfg_REG_ADON bit in the ADC1_CFG register */
    tmpreg_CFG &= ~ADC1_CFG_REG_ADON;
  }

  /* Configure ADC1_CFG register with new value */
  MDR_ADC->ADC1_CFG = tmpreg_CFG;
}

#if defined  (USE_MDR1986VE9x)
/**
  * @brief  Enables or disables the ADC1 peripheral.
  * @warning 	This function can be used only for microcontroller
  * 		series MDR1986VE9x.
  * @param  NewState: new state of the ADC1 peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void ADC2_Cmd(FunctionalState NewState)
{
  uint32_t tmpreg_CFG;

  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  tmpreg_CFG = MDR_ADC->ADC2_CFG;

  /* Form new value */
  if (NewState != DISABLE)
  {
    /* Enable ADC2 by setting the Cfg_REG_ADON bit in the ADC2_CFG register */
    tmpreg_CFG |= ADC2_CFG_REG_ADON;
  }
  else
  {
    /* Disable ADC2 by resetting the Cfg_REG_ADON bit in the ADC2_CFG register */
    tmpreg_CFG &= ~ADC2_CFG_REG_ADON;
  }

  /* Configure ADC2_CFG register with new value */
  MDR_ADC->ADC2_CFG = tmpreg_CFG;
}
#endif /* #if defined  (USE_MDR1986VE9x) */

/**
  * @brief  Selects the ADC1 Channel number for Single Channel Mode conversion.
  * @param  Channel: specifies the ADC Channel number.
  * @retval None
  */
void ADC1_SetChannel(uint32_t Channel)
{
  uint32_t tmpreg_CFG;

  /* Check the parameters */
  assert_param(IS_ADC1_CH_NUM(Channel));

  tmpreg_CFG = MDR_ADC->ADC1_CFG;
  tmpreg_CFG &= ~ADC1_CFG_REG_CHS_Msk;
  tmpreg_CFG += Channel << ADC1_CFG_REG_CHS_Pos;
  MDR_ADC->ADC1_CFG = tmpreg_CFG;
}

#if defined  (USE_MDR1986VE9x)
/**
  * @brief  Selects the ADC2 Channel number for Single Channel Mode conversion.
  * @warning 	This function can be used only for microcontroller
  * 		series MDR1986VE9x.
  * @param  Channel: specifies the ADC Channel number.
  * @retval None
  */
void ADC2_SetChannel(uint32_t Channel)
{
  uint32_t tmpreg_CFG;

  /* Check the parameters */
  assert_param(IS_ADC2_CH_NUM(Channel));

  tmpreg_CFG = MDR_ADC->ADC2_CFG;
  tmpreg_CFG &= ~ADC2_CFG_REG_CHS_Msk;
  tmpreg_CFG += Channel << ADC2_CFG_REG_CHS_Pos;
  MDR_ADC->ADC2_CFG = tmpreg_CFG;
}
#endif /* #if defined  (USE_MDR1986VE9x) */

/**
  * @brief  Selects the ADC1 Channels for conversion with Channels switching.
  * @param  ChannelMask: specifies the ADC Channels Mask.
  * @retval None
  */
void ADC1_SetChannels(uint32_t ChannelMask)
{
  /* Check the parameters */
  assert_param(IS_ADC1_CH_MASK(ChannelMask));

  MDR_ADC->ADC1_CHSEL = ChannelMask;
}

#if defined  (USE_MDR1986VE9x)
/**
  * @brief  Selects the ADC2 Channels for conversion with Channels switching.
  * @param  ChannelMask: specifies the ADC Channels Mask.
  * @retval None
  */
void ADC2_SetChannels(uint32_t ChannelMask)
{
  /* Check the parameters */
  assert_param(IS_ADC2_CH_MASK(ChannelMask));

  MDR_ADC->ADC2_CHSEL = ChannelMask;
}
#endif /* #if defined  (USE_MDR1986VE9x) */

/**
  * @brief  Sets the ADC1 operation mode.
  * @param  SamplingMode: specifies the ADC1 sampling.
  * @param  SwitchingMode: specifies the ADC1 channel switching.
  * @retval None
  */
void ADC1_OperationModeConfig(uint32_t SamplingMode, uint32_t SwitchingMode)
{
  uint32_t tmpreg_CFG;

  /* Check the parameters */
  assert_param(IS_ADC_SAMPLING_MODE_CONFIG(SamplingMode));
  assert_param(IS_ADC_CH_SWITCHING_CONFIG(SwitchingMode));

  tmpreg_CFG = MDR_ADC->ADC1_CFG;
  tmpreg_CFG &= ~(ADC1_CFG_REG_SAMPLE | ADC1_CFG_REG_CHCH);
  tmpreg_CFG += SamplingMode + SwitchingMode;
  MDR_ADC->ADC1_CFG = tmpreg_CFG;
}

#if defined  (USE_MDR1986VE9x)
/**
  * @brief  Sets the ADC2 operation mode.
  * @warning 	This function can be used only for microcontroller
  * 		series MDR1986VE9x.
  * @param  SamplingMode: specifies the ADC2 sampling.
  * @param  SwitchingMode: specifies the ADC2 channel switching.
  * @retval None
  */
void ADC2_OperationModeConfig(uint32_t SamplingMode, uint32_t SwitchingMode)
{
  uint32_t tmpreg_CFG;

  /* Check the parameters */
  assert_param(IS_ADC_SAMPLING_MODE_CONFIG(SamplingMode));
  assert_param(IS_ADC_CH_SWITCHING_CONFIG(SwitchingMode));

  tmpreg_CFG = MDR_ADC->ADC2_CFG;
  tmpreg_CFG &= ~(ADC2_CFG_REG_SAMPLE | ADC2_CFG_REG_CHCH);
  tmpreg_CFG += SamplingMode + SwitchingMode;
  MDR_ADC->ADC2_CFG = tmpreg_CFG;
}
#endif /* #if defined  (USE_MDR1986VE9x) */

/**
  * @brief  Sets the ADC1 sampling mode.
  * @param  SamplingMode: specifies the ADC1 sampling.
  * @retval None
  */
void ADC1_SamplingModeConfig(uint32_t SamplingMode)
{
  uint32_t tmpreg_CFG;

  /* Check the parameters */
  assert_param(IS_ADC_SAMPLING_MODE_CONFIG(SamplingMode));

  tmpreg_CFG = MDR_ADC->ADC1_CFG;
  tmpreg_CFG &= ~ADC1_CFG_REG_SAMPLE;
  tmpreg_CFG += SamplingMode;
  MDR_ADC->ADC1_CFG = tmpreg_CFG;
}

#if defined  (USE_MDR1986VE9x)
/**
  * @brief  Sets the ADC2 sampling mode.
  * @warning 	This function can be used only for microcontroller
  * 		series MDR1986VE9x.
  * @param  SamplingMode: specifies the ADC2 sampling.
  * @retval None
  */
void ADC2_SamplingModeConfig(uint32_t SamplingMode)
{
  uint32_t tmpreg_CFG;

  /* Check the parameters */
  assert_param(IS_ADC_SAMPLING_MODE_CONFIG(SamplingMode));

  tmpreg_CFG = MDR_ADC->ADC2_CFG;
  tmpreg_CFG &= ~ADC2_CFG_REG_SAMPLE;
  tmpreg_CFG += SamplingMode;
  MDR_ADC->ADC2_CFG = tmpreg_CFG;
}
#endif /* #if defined  (USE_MDR1986VE9x) */

/**
  * @brief  Sets the ADC1 channel switching mode.
  * @param  SwitchingMode: specifies the ADC1 channel switching.
  * @retval None
  */
void ADC1_ChannelSwithingConfig(uint32_t SwitchingMode)
{
  uint32_t tmpreg_CFG;

  /* Check the parameters */
  assert_param(IS_ADC_CH_SWITCHING_CONFIG(SwitchingMode));

  tmpreg_CFG = MDR_ADC->ADC1_CFG;
  tmpreg_CFG &= ~ADC1_CFG_REG_CHCH;
  tmpreg_CFG += SwitchingMode;
  MDR_ADC->ADC1_CFG = tmpreg_CFG;
}

#if defined  (USE_MDR1986VE9x)
/**
  * @brief  Sets the ADC2 channel switching mode.
  * @warning 	This function can be used only for microcontroller
  * 		series MDR1986VE9x.
  * @param  SwitchingMode: specifies the ADC2 channel switching.
  * @retval None
  */
void ADC2_ChannelSwithingConfig(uint32_t SwitchingMode)
{
  uint32_t tmpreg_CFG;

  /* Check the parameters */
  assert_param(IS_ADC_CH_SWITCHING_CONFIG(SwitchingMode));

  tmpreg_CFG = MDR_ADC->ADC2_CFG;
  tmpreg_CFG &= ~ADC2_CFG_REG_CHCH;
  tmpreg_CFG += SwitchingMode;
  MDR_ADC->ADC2_CFG = tmpreg_CFG;
}
#endif /* #if defined  (USE_MDR1986VE9x) */

/**
  * @brief  Configures the ADC1 threshould levels.
  * @param  LowLevel: specifies the ADC1 low level value.
  * @param  HighLevel: specifies the ADC1 high level value.
  * @param  NewState: enables or disables levels control.
  * @retval None
  */
void ADC1_LevelsConfig(uint32_t LowLevel, uint32_t HighLevel, uint32_t NewState)
{
  uint32_t tmpreg_CFG;

  /* Check the parameters */
  assert_param(IS_ADC_LEVEL_CONTROL_CONFIG(NewState));
  assert_param(IS_ADC_VALUE(LowLevel));
  assert_param(IS_ADC_VALUE(HighLevel));

  tmpreg_CFG = MDR_ADC->ADC1_CFG;
  tmpreg_CFG &= ~ADC1_CFG_REG_RNGC;
  tmpreg_CFG += NewState;
  MDR_ADC->ADC1_CFG = tmpreg_CFG;

  MDR_ADC->ADC1_L_LEVEL = LowLevel;
  MDR_ADC->ADC1_H_LEVEL = HighLevel;
}

#if defined  (USE_MDR1986VE9x)
/**
  * @brief  Configures the ADC2 threshould levels.
  * @warning 	This function can be used only for microcontroller
  * 		series MDR1986VE9x.
  * @param  LowLevel: specifies the ADC2 low level value.
  * @param  HighLevel: specifies the ADC2 high level value.
  * @param  NewState: enables or disables levels control.
  * @retval None
  */
void ADC2_LevelsConfig(uint32_t LowLevel, uint32_t HighLevel, uint32_t NewState)
{
  uint32_t tmpreg_CFG;

  /* Check the parameters */
  assert_param(IS_ADC_LEVEL_CONTROL_CONFIG(NewState));
  assert_param(IS_ADC_VALUE(LowLevel));
  assert_param(IS_ADC_VALUE(HighLevel));

  tmpreg_CFG = MDR_ADC->ADC2_CFG;
  tmpreg_CFG &= ~ADC2_CFG_REG_RNGC;
  tmpreg_CFG += NewState;
  MDR_ADC->ADC2_CFG = tmpreg_CFG;

  MDR_ADC->ADC2_L_LEVEL = LowLevel;
  MDR_ADC->ADC2_H_LEVEL = HighLevel;
}
#endif /* #if defined  (USE_MDR1986VE9x) */

/**
  * @brief  Sets the ADC1 low level.
  * @param  LowLevel: specifies the ADC1 low level value.
  * @retval None
  */
void ADC1_SetLowLevel(uint32_t LowLevel)
{
  /* Check the parameters */
  assert_param(IS_ADC_VALUE(LowLevel));

  MDR_ADC->ADC1_L_LEVEL = LowLevel;
}

#if defined  (USE_MDR1986VE9x)
/**
  * @brief  Sets the ADC2 low level.
  * @param  LowLevel: specifies the ADC2 low level value.
  * @retval None
  */
void ADC2_SetLowLevel(uint32_t LowLevel)
{
  /* Check the parameters */
  assert_param(IS_ADC_VALUE(LowLevel));

  MDR_ADC->ADC2_L_LEVEL = LowLevel;
}
#endif /* #if defined  (USE_MDR1986VE9x) */

/**
  * @brief  Sets the ADC1 high level.
  * @param  HighLevel: specifies the ADC1 high level value.
  * @retval None
  */
void ADC1_SetHighLevel(uint32_t HighLevel)
{
  /* Check the parameters */
  assert_param(IS_ADC_VALUE(HighLevel));

  MDR_ADC->ADC1_H_LEVEL = HighLevel;
}

#if defined  (USE_MDR1986VE9x)
/**
  * @brief  Sets the ADC2 high level.
  * @warning 	This function can be used only for microcontroller
  * 		series MDR1986VE9x.
  * @param  HighLevel: specifies the ADC2 high level value.
  * @retval None
  */
void ADC2_SetHighLevel(uint32_t HighLevel)
{
  /* Check the parameters */
  assert_param(IS_ADC_VALUE(HighLevel));

  MDR_ADC->ADC2_H_LEVEL = HighLevel;
}
#endif /* #if defined  (USE_MDR1986VE9x) */

/**
  * @brief  Starts the ADC1 conversion.
  * @param  None.
  * @retval None.
  */
void ADC1_Start(void)
{
  MDR_ADC->ADC1_CFG |= ADC1_CFG_REG_GO;
}

#if defined  (USE_MDR1986VE9x)
/**
  * @brief  Starts the ADC2 conversion.
  * @warning 	This function can be used only for microcontroller
  * 		series MDR1986VE9x.
  * @param  None.
  * @retval None.
  */
void ADC2_Start(void)
{
  MDR_ADC->ADC2_CFG |= ADC2_CFG_REG_GO;
}
#endif /* #if defined  (USE_MDR1986VE9x) */

/**
  * @brief  Returns the ADC1 result.
  * @param  None.
  * @retval ADC1 Result Register value.
  */
uint32_t ADC1_GetResult(void)
{
  return MDR_ADC->ADC1_RESULT;
}

#if defined  (USE_MDR1986VE9x)
/**
  * @brief  Returns the ADC2 result.
  * @warning 	This function can be used only for microcontroller
  * 		series MDR1986VE9x.
  * @param  None.
  * @retval ADC2 Result Register value.
  */
uint32_t ADC2_GetResult(void)
{
  return MDR_ADC->ADC2_RESULT;
}
#endif /* #if defined  (USE_MDR1986VE9x) */

/**
  * @brief  Returns the ADC1, ADC2 Status Registers combined value.
  * @param  None.
  * @retval The ADC1_STATUS, ADC2_STATUS Registers combined value.
  */
uint32_t ADC_GetStatus ( void )
{
#if defined  (USE_MDR1986VE9x) 									/* For Cortex M3 */
  return MDR_ADC->ADC1_STATUS + (MDR_ADC->ADC2_STATUS << 16);
#elif defined ( USE_MDR1986VE3 ) || defined (USE_MDR1986VE1T) 	/* For Cortex M1 */
  return MDR_ADC->ADC1_STATUS;
#endif
}

/**
  * @brief  Returns the ADC1 Status Register value.
  * @param  None.
  * @retval The ADC1_STATUS Register value.
  */
uint32_t ADC1_GetStatus(void)
{
  return MDR_ADC->ADC1_STATUS;
}

#ifdef USE_MDR1986VE9x /* For Cortex M3 */
/**
  * @brief  Returns the ADC2 Status Register value.
  * @warning 	This function can be used only for microcontroller
  * 		series MDR1986VE9x.
  * @param  None.
  * @retval The ADC2_STATUS Register value.
  */
uint32_t ADC2_GetStatus(void)
{
  return MDR_ADC->ADC2_STATUS;
}
#endif // #ifdef USE_MDR1986VE9x /* For Cortex M3 */

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
FlagStatus ADC_GetFlagStatus(uint32_t Flag)
{
  FlagStatus bitstatus;

  /* Check the parameters */
  assert_param(IS_ADC_STATUS_FLAG(Flag));

  if ((ADC_GetStatus() & Flag) == 0)
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
  * @brief  Checks whether the specified ADC1 Status flag is set or not.
  * @param  Flag: specifies the flag to check.
  *         This parameter can be one of the following values:
  *           @arg ADCx_FLAG_OVERWRITE:         the previous ADC1 measured value was overwritten;
  *           @arg ADCx_FLAG_OUT_OF_RANGE:      the ADC1 measured value is out of range;
  *           @arg ADCx_FLAG_END_OF_CONVERSION: the ADC1 conversion finished.
  * @retval Current Status flag state (SET or RESET).
  */
FlagStatus ADC1_GetFlagStatus(uint32_t Flag)
{
  FlagStatus bitstatus;

  /* Check the parameters */
  assert_param(IS_ADCx_STATUS_FLAG(Flag));

  if ((MDR_ADC->ADC1_STATUS & Flag) == 0)
  {
    bitstatus = RESET;
  }
  else
  {
    bitstatus = SET;
  }

  return bitstatus;
}

#if defined  (USE_MDR1986VE9x)
/**
  * @brief  Checks whether the specified ADC2 Status flag is set or not.
  * @warning 	This function can be used only for microcontroller
  * 		series MDR1986VE9x.
  * @param  Flag: specifies the flag to check.
  *         This parameter can be one of the following values:
  *           @arg ADCx_FLAG_OVERWRITE:         the previous ADC2 measured value was overwritten;
  *           @arg ADCx_FLAG_OUT_OF_RANGE:      the ADC2 measured value is out of range;
  *           @arg ADCx_FLAG_END_OF_CONVERSION: the ADC2 conversion finished.
  * @retval Current Status flag state (SET or RESET).
  */
FlagStatus ADC2_GetFlagStatus(uint32_t Flag)
{
  FlagStatus bitstatus;

  /* Check the parameters */
  assert_param(IS_ADCx_STATUS_FLAG(Flag));

  if ((MDR_ADC->ADC2_STATUS & Flag) == 0)
  {
    bitstatus = RESET;
  }
  else
  {
    bitstatus = SET;
  }

  return bitstatus;
}
#endif /* #if defined  (USE_MDR1986VE9x) */

/**
  * @brief  Clears the ADC1 Overwrite flag.
  * @param  None.
  * @retval None
  */
void ADC1_ClearOverwriteFlag(void)
{
  MDR_ADC->ADC1_STATUS &= ~ADCx_FLAG_OVERWRITE;
}

#if defined  (USE_MDR1986VE9x)
/**
  * @brief  Clears the ADC2 Overwrite flag.
  * @warning 	This function can be used only for microcontroller
  * 		series MDR1986VE9x.
  * @param  None.
  * @retval None
  */
void ADC2_ClearOverwriteFlag(void)
{
  MDR_ADC->ADC2_STATUS &= ~ADCx_FLAG_OVERWRITE;
}
#endif /* #if defined  (USE_MDR1986VE9x) */

/**
  * @brief  Clears the ADC1 AWOIFEN flag.
  * @param  None.
  * @retval None
  */
void ADC1_ClearOutOfRangeFlag(void)
{
  MDR_ADC->ADC1_STATUS &= ~ADCx_FLAG_OUT_OF_RANGE;
}

#if defined  (USE_MDR1986VE9x)
/**
  * @brief  Clears the ADC2 AWOIFEN flag.
  * @warning 	This function can be used only for microcontroller
  * 		series MDR1986VE9x.
  * @param  None.
  * @retval None
  */
void ADC2_ClearOutOfRangeFlag(void)
{
  MDR_ADC->ADC2_STATUS &= ~ADCx_FLAG_OUT_OF_RANGE;
}
#endif /* #if defined  (USE_MDR1986VE9x) */

/**
  * @brief  Enables or disables the ADC1, ADC2 interrupts.
  * @param  ADC_IT: specifies the ADC interrupts sources to be enabled or disabled.
  *         This parameter can be any combination of the following values:
  *           @arg ADC1_IT_OUT_OF_RANGE:        the ADC1 measured value is out of range;
  *           @arg ADC1_IT_END_OF_CONVERSION:   the ADC1 conversion finished;
  *           @arg ADC2_IT_OUT_OF_RANGE:        the ADC2 measured value is out of range;
  *           @arg ADC2_IT_END_OF_CONVERSION:   the ADC2 conversion finished.
  * @param  NewState: new state of the ADC interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void ADC_ITConfig(uint32_t ADC_IT, FunctionalState NewState)
{
  uint32_t tmpreg_ADC1_IE;
  uint32_t tmpreg_ADC_IT;
#if defined  (USE_MDR1986VE9x)
  uint32_t tmpreg_ADC2_IE;
#endif

  /* Check the parameters */
  assert_param(IS_ADC_CONFIG_IT(ADC_IT));
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  tmpreg_ADC1_IE = MDR_ADC->ADC1_STATUS;
  tmpreg_ADC_IT = ADC_IT << 2;

  /* Form new value */
  if (NewState != DISABLE)
  {
    /* Enable the ADC Interrupt requests by setting bits in the ADCx_STATUS registers */
    tmpreg_ADC1_IE |= tmpreg_ADC_IT & 0xFFFF;
  }
  else
  {
    /* Disable the ADC Interrupt requests by clearing bits in the ADCx_STATUS registers */
    tmpreg_ADC1_IE &= ~(tmpreg_ADC_IT & 0xFFFF);
  }

  /* Configure ADCx_STATUS registers with new value */
  MDR_ADC->ADC1_STATUS = tmpreg_ADC1_IE;

#if defined  (USE_MDR1986VE9x)

  tmpreg_ADC2_IE = MDR_ADC->ADC2_STATUS;

  /* Form new value */
  if (NewState != DISABLE)
  {
    /* Enable the ADC Interrupt requests by setting bits in the ADCx_STATUS registers */
    tmpreg_ADC2_IE |= tmpreg_ADC_IT >> 16;
  }
  else
  {
    /* Disable the ADC Interrupt requests by clearing bits in the ADCx_STATUS registers */
    tmpreg_ADC2_IE &= ~(tmpreg_ADC_IT >> 16);
  }
  /* Configure ADCx_STATUS registers with new value */
  MDR_ADC->ADC2_STATUS = tmpreg_ADC2_IE;
#endif /* #if defined  (USE_MDR1986VE9x) */
}

/**
  * @brief  Enables or disables the ADC1 interrupts.
  * @param  ADC_IT: specifies the ADC1 interrupts sources to be enabled or disabled.
  *         This parameter can be any combination of the following values:
  *           @arg ADC1_IT_OUT_OF_RANGE:        the ADC1 measured value is out of range;
  *           @arg ADC1_IT_END_OF_CONVERSION:   the ADC1 conversion finished.
  * @param  NewState: new state of the ADC1 interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void ADC1_ITConfig(uint32_t ADC_IT, FunctionalState NewState)
{
  uint32_t tmpreg_ADC1_IE;

  /* Check the parameters */
  assert_param(IS_ADCx_CONFIG_IT(ADC_IT));
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  tmpreg_ADC1_IE = MDR_ADC->ADC1_STATUS;

  /* Form new value */
  if (NewState != DISABLE)
  {
    /* Enable the ADC Interrupt requests by setting bits in the ADC1_STATUS register */
    tmpreg_ADC1_IE |= (ADC_IT << 2);
  }
  else
  {
    /* Disable the ADC Interrupt requests by clearing bits in the ADC1_STATUS register */
    tmpreg_ADC1_IE &= ~(ADC_IT << 2);
  }

  /* Configure ADC1_STATUS registers with new value */
  MDR_ADC->ADC1_STATUS = tmpreg_ADC1_IE;
}

#if defined  (USE_MDR1986VE9x)
/**
  * @brief  Enables or disables the ADC2 interrupts.
  * @warning 	This function can be used only for microcontroller
  * 		series MDR1986VE9x.
  * @param  ADC_IT: specifies the ADC2 interrupts sources to be enabled or disabled.
  *         This parameter can be any combination of the following values:
  *           @arg ADC2_IT_OUT_OF_RANGE:        the ADC2 measured value is out of range;
  *           @arg ADC2_IT_END_OF_CONVERSION:   the ADC2 conversion finished.
  * @param  NewState: new state of the ADC2 interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void ADC2_ITConfig(uint32_t ADC_IT, FunctionalState NewState)
{
  uint32_t tmpreg_ADC2_IE;

  /* Check the parameters */
  assert_param(IS_ADCx_CONFIG_IT(ADC_IT));
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  tmpreg_ADC2_IE = MDR_ADC->ADC2_STATUS;

  /* Form new value */
  if (NewState != DISABLE)
  {
    /* Enable the ADC Interrupt requests by setting bits in the ADC2_STATUS register */
    tmpreg_ADC2_IE |= (ADC_IT << 2);
  }
  else
  {
    /* Disable the ADC Interrupt requests by clearing bits in the ADC2_STATUS register */
    tmpreg_ADC2_IE &= ~(ADC_IT << 2);
  }

  /* Configure ADC2_STATUS registers with new value */
  MDR_ADC->ADC2_STATUS = tmpreg_ADC2_IE;
}
#endif /* #if defined  (USE_MDR1986VE9x) */

/**
  * @brief  Checks whether the ADC1, ADC2 interrupt has occurred or not.
  * @param  ADC_IT: specifies the ADC interrupt source to check.
  *         This parameter can be one of the following values:
  *           @arg ADC1_IT_OUT_OF_RANGE:        the ADC1 measured value is out of range;
  *           @arg ADC1_IT_END_OF_CONVERSION:   the ADC1 conversion finished;
  *           @arg ADC2_IT_OUT_OF_RANGE:        the ADC2 measured value is out of range;
  *           @arg ADC2_IT_END_OF_CONVERSION:   the ADC2 conversion finished.
  * @retval The new state of the ADC_IT (SET or RESET).
  */
ITStatus ADC_GetITStatus(uint32_t ADC_IT)
{
  ITStatus bitstatus;
  uint32_t tmpreg;

  /* Check the parameters */
  assert_param(IS_ADC_CONFIG_IT(ADC_IT));

  tmpreg = ADC_GetStatus();
  tmpreg &= (tmpreg >> 2) & ADC_IT;

  if (tmpreg == 0)
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
  * @brief  Checks whether the ADC1 interrupt has occurred or not.
  * @param  ADC_IT: specifies the ADC interrupt source to check.
  *         This parameter can be one of the following values:
  *           @arg ADC1_IT_OUT_OF_RANGE:        the ADC1 measured value is out of range;
  *           @arg ADC1_IT_END_OF_CONVERSION:   the ADC1 conversion finished.
  * @retval The new state of the ADC_IT (SET or RESET).
  */
ITStatus ADC1_GetITStatus(uint32_t ADC_IT)
{
  ITStatus bitstatus;
  uint32_t tmpreg;

  /* Check the parameters */
  assert_param(IS_ADCx_CONFIG_IT(ADC_IT));

  tmpreg = MDR_ADC->ADC1_STATUS;
  tmpreg &= (tmpreg >> 2) & ADC_IT;

  if (tmpreg == 0)
  {
    bitstatus = RESET;
  }
  else
  {
    bitstatus = SET;
  }

  return bitstatus;
}

#if defined  (USE_MDR1986VE9x)
/**
  * @brief  Checks whether the ADC2 interrupt has occurred or not.
  * @warning 	This function can be used only for microcontroller
  * 		series MDR1986VE9x.
  * @param  ADC_IT: specifies the ADC interrupt source to check.
  *         This parameter can be one of the following values:
  *           @arg ADC2_IT_OUT_OF_RANGE:        the ADC2 measured value is out of range;
  *           @arg ADC2_IT_END_OF_CONVERSION:   the ADC2 conversion finished.
  * @retval The new state of the ADC_IT (SET or RESET).
  */
ITStatus ADC2_GetITStatus(uint32_t ADC_IT)
{
  ITStatus bitstatus;
  uint32_t tmpreg;

  /* Check the parameters */
  assert_param(IS_ADCx_CONFIG_IT(ADC_IT));

  tmpreg = MDR_ADC->ADC2_STATUS;
  tmpreg &= (tmpreg >> 2) & ADC_IT;

  if (tmpreg == 0)
  {
    bitstatus = RESET;
  }
  else
  {
    bitstatus = SET;
  }

  return bitstatus;
}
#endif /* #if defined  (USE_MDR1986VE9x) */

/** @} */ /* End of group ADC_Private_Functions */

/** @} */ /* End of group ADC */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

/******************* (C) COPYRIGHT 2011 Phyton *********************************
*
* END OF FILE MDR32F9Qx_adc.c */

