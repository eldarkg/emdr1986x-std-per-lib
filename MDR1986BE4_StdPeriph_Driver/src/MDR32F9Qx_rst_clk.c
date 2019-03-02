/**
  * FILE MDR32F9Qx_rst_clk.c
  */

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_config.h"
#include "MDR32F9Qx_rst_clk.h"


#define ASSERT_INFO_FILE_ID FILEID__MDR32F9X_RST_CLK_C

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @defgroup RST_CLK RST_CLK
  * @{
  */

/** @defgroup RST_CLK_Private_Constants RST_CLK Private Constants
  * @{
  */
#define FLAG_MASK                   ((uint8_t)0x1F)
#define FLAG_SFR_MASK               ((uint8_t)0xE0)

#ifndef HSI_Value
/* Typical Value of the HSI in Hz */
 #define HSI_Value                  ((uint32_t)8000000)
#endif /* HSI_Value */

#ifndef HSE_Value
/* Typical Value of the HSE in Hz */
 #define HSE_Value                  ((uint32_t)8000000)
#endif /* HSE_Value */

#ifndef LSI_Value
/* Typical Value of the LSI in Hz */
 #define LSI_Value                  ((uint32_t)40000)
#endif /* LSI_Value */

#ifndef LSE_Value
/* Typical Value of the LSE in Hz */
 #define LSE_Value                  ((uint32_t)32768)
#endif /* LSE_Value */

#ifndef HSEonTimeOut
/* Time out for HSE start up */
 #define HSEonTimeOut               ((uint16_t)0x0600)
#endif /* HSEonTimeOut */

#ifndef LSEonTimeOut
/* Time out for LSE start up */
 #define LSEonTimeOut               ((uint16_t)0x0600)
#endif /* LSEonTimeOut */

#ifndef HSIonTimeOut
/* Time out for HSI start up */
 #define HSIonTimeOut               ((uint16_t)0x0600)
#endif /* HSIonTimeOut */

#ifndef LSIonTimeOut
/* Time out for LSI start up */
 #define LSIonTimeOut               ((uint16_t)0x0600)
#endif /* LSIonTimeOut */

#ifndef PLLCPUonTimeOut
/* Time out for PLLCPU start up */
 #define PLLCPUonTimeOut            ((uint16_t)0x0600)
#endif /* PLLCPUonTimeOut */

/** @} */ /* End of group RST_CLK_Private_Constants */

/** @defgroup RST_CLK_Private_Functions RST_CLK Private Functions
  * @{
  */

/**
  * @brief  Set the RST_CLK clock configuration to the default reset state.
  * @param  None
  * @retval None
  */
void RST_CLK_DeInit(void)
{
  RST_CLK_WarmDeInit();
  /* Reset REG_0F bits to zero but HSION bit */
  RST_CLK_PCLKcmd(RST_CLK_PCLK_BKP, ENABLE);
  MDR_BKP->REG_0F |= (uint32_t)((1<<22)|(1<<15)); /* HSION & LSION */
  MDR_BKP->REG_0F &= (uint32_t)((1<<22)|(1<<15));
}

/**
  * @brief  Set the RST_CLK clock configuration to the default reset state except for
  *         the backup domain REG_0F register.
  * @param  None
  * @retval None
  */
void RST_CLK_WarmDeInit(void)
{
  /* Prepare HSI clk */
  RST_CLK_HSIcmd(ENABLE);
  RST_CLK_HSIstatus();
  RST_CLK_CPUclkSelection(RST_CLK_CPUclkHSI);

  /* Reset CPU_CLOCK bits */
  MDR_RST_CLK->CPU_CLOCK   &= (uint32_t)0x00000000;

  /* Reset PLL_CONTROL bits */
  MDR_RST_CLK->PLL_CONTROL &= (uint32_t)0x00000000;

  /* Reset HSEON and HSEBYP bits */
  MDR_RST_CLK->HS_CONTROL  &= (uint32_t)0x00000000;

  /* Reset ADC_MCO_CLOCK bits */
  MDR_RST_CLK->ADC_MCO_CLOCK   &= (uint32_t)0x00000000;

  /* Reset RTC_CLOCK bits */
  MDR_RST_CLK->RTC_CLOCK   &= (uint32_t)0x00000000;

  /* Reset all clock but RTC_CLK bit */
  MDR_RST_CLK->PER1_CLOCK   = RST_CLK_PER1_CLOCK_DMA_EN | RST_CLK_PER1_CLOCK_DEBUG_EN;

  /* Reset all periph clocks */
  MDR_RST_CLK->PER2_CLOCK	= RST_CLK_PER2_CLOCK_PCLK_EN_RST_CLK;
}

/**
  * @brief  RST_CLK_HSEconfig - HSE (High Speed External) clock mode and source selection
  * @param  RST_CLK_HSE - mode selector
  *         @arg RST_CLK_HSE_OFF    -  switch off HSE clock generator
  *         @arg RST_CLK_HSE_ON     -  switch on HSE clock generator
  *         @arg RST_CLK_HSE_Bypass -  use external clock source
  * @retval None
  */
void RST_CLK_HSEconfig(uint32_t RST_CLK_HSE)
{
  /* Check the parameters */
  assert_param(IS_RST_CLK_HSE(RST_CLK_HSE));
  /* Reset HSEON and HSEBYP bits before configuring the HSE */
  MDR_RST_CLK->HS_CONTROL &= ~((uint32_t)(RST_CLK_HSE_ON | RST_CLK_HSE_Bypass));
  /* Configure HSE (RCC_HSE_OFF is already covered by the code section above) */
  switch (RST_CLK_HSE)
  {
    case RST_CLK_HSE_ON:
      /* Set HSEON bit */
      MDR_RST_CLK->HS_CONTROL |= RST_CLK_HSE_ON;
      break;

    case RST_CLK_HSE_Bypass:
      /* Set HSEBYP and HSEON bits */
      MDR_RST_CLK->HS_CONTROL |= RST_CLK_HSE_ON | RST_CLK_HSE_Bypass;
      break;

    default:
      break;
  }
}

/**
  * @brief  RST_CLK_HSEstatus - HSE clock status
  * @param  None
  * @retval enum ErrorStatus - SUCCESS if HSE clock is ready, else ERROR
  */
ErrorStatus RST_CLK_HSEstatus(void)
{
  __IO uint32_t startCounter = 0;
  ErrorStatus state;
  FlagStatus flag;

  /* Wait until HSE is ready or time out is occure */
  do
  {
    flag = RST_CLK_GetFlagStatus(RST_CLK_FLAG_HSERDY);
    startCounter++;
  } while ((startCounter < HSEonTimeOut) && (flag == RESET));

  if (RST_CLK_GetFlagStatus(RST_CLK_FLAG_HSERDY) != RESET)
  {
    state = SUCCESS;
  }
  else
  {
    state = ERROR;
  }
  return state;
}

/**
  * @brief  RST_CLK_LSEconfig - LSE (Low Speed External) clock mode and source selection
  * @param  RST_CLK_LSE - mode selector
  *         @arg RST_CLK_LSE_OFF    -  switch off LSE clock generator
  *         @arg RST_CLK_LSE_ON     -  switch on LSE clock generator
  *         @arg RST_CLK_LSE_Bypass -  use external clock source
  * @retval None
  */
void RST_CLK_LSEconfig(uint32_t RST_CLK_LSE)
{
  /* Check the parameters */
  assert_param(IS_RST_CLK_LSE(RST_CLK_LSE));
  /* Reset LSEON and LSEBYP bits before configuring the LSE */
  MDR_BKP->REG_0F &= ~((uint32_t)(RST_CLK_LSE_ON | RST_CLK_LSE_Bypass));
  switch (RST_CLK_LSE)
  {
    case RST_CLK_LSE_ON:
      /* Set LSEON bit */
      MDR_BKP->REG_0F |= RST_CLK_LSE_ON;
      break;

    case RST_CLK_LSE_Bypass:
      /* Set LSEBYP and LSEON bits */
      MDR_BKP->REG_0F |= (RST_CLK_LSE_ON | RST_CLK_LSE_Bypass);
      break;

    default:
      break;
  }
}

/**
  * @brief  RST_CLK_LSEstatus - LSE clock status
  * @param  None
  * @retval enum ErrorStatus - SUCCESS if LSE clock is ready, else ERROR
  */
ErrorStatus RST_CLK_LSEstatus(void)
{
  __IO uint32_t startCounter = 0;
  ErrorStatus state;
  FlagStatus flag;

 /* Wait until LSE is ready or time out is occure */
 do
  {
    flag = RST_CLK_GetFlagStatus(RST_CLK_FLAG_LSERDY);
    startCounter++;
  } while ((startCounter < LSEonTimeOut) && (flag == RESET));

  if (RST_CLK_GetFlagStatus(RST_CLK_FLAG_LSERDY) != RESET)
  {
    state = SUCCESS;
  }
  else
  {
    state = ERROR;
  }
  return state;
}

/**
  * @brief  RST_CLK_HSIcmd:  HSI (High Speed Internal) clock mode selection
  * @param  NewState: mode selector - DISABLE, ENABLE
  *         @arg DISABLE:   switch off HSI clock generator
  *         @arg ENABLE:    switch on HSI clock generator
  * @retval None
  */
void RST_CLK_HSIcmd(FunctionalState NewState)
{
  uint32_t temp = 0;

  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  temp = MDR_BKP->REG_0F;
  /* Form new value */
  if (NewState != DISABLE){
    /* Enable HSI clk by setting the HSE_ON bit in the BKP_REG_0F register */
    temp |= BKP_REG_0F_HSI_ON;
  }
  else{
    /* Disable HSI clk by resetting the HSE_ON bit in the BKP_REG_0F register */
    temp &= ~BKP_REG_0F_HSI_ON;
  }
  /* Configure REG_0F register with new value */
  MDR_BKP->REG_0F = temp;
}

/**
  * @brief  RST_CLK_HSIadjust: HSI clock frequency adjustment by HSITRIM setting
  * @param  HSItrimValue
  *         This parameter must be a number between 0 and 0x3F.
  * @retval None
  */
void RST_CLK_HSIadjust(uint32_t HSItrimValue)
{
  uint32_t temp;
  /* Check the parameters */
  assert_param(IS_RCC_CLK_HSI_TRIM_VALUE(HSItrimValue));
  temp = MDR_BKP->REG_0F;
  /* Clear HSITRIM[5:0] bits */
  temp &= ~BKP_REG_0F_HSI_TRIM_Msk;
  /* Set the HSITRIM[5:0] bits according to HSItrimValue value */
  temp |= (uint32_t)HSItrimValue << BKP_REG_0F_HSI_TRIM_Pos;
  /* Store the new value */
  MDR_BKP->REG_0F = temp;
}

/**
  * @brief  RST_CLK_HSIstatus: HSI clock status
  * @param  None
  * @retval enum ErrorStatus: SUCCESS if HSI clock is ready, else ERROR
  */
ErrorStatus RST_CLK_HSIstatus(void)
{
  __IO uint32_t startCounter = 0;
  ErrorStatus state;
  FlagStatus flag;

  /* Wait until HSI is ready or time out is occure */
  do
  {
    flag = RST_CLK_GetFlagStatus(RST_CLK_FLAG_HSIRDY);
    startCounter++;
  } while ((startCounter < HSIonTimeOut) && (flag == RESET));

  if (RST_CLK_GetFlagStatus(RST_CLK_FLAG_HSIRDY) != RESET)
  {
    state = SUCCESS;
  }
  else
  {
    state = ERROR;
  }
  return state;
}

/**
  * @brief  RST_CLK_LSIcmd:  LSI (High Speed Internal) clock mode selection
  * @param  NewState: mode selector - DISABLE, ENABLE
  *         @arg DISABLE:   switch off LSI clock generator
  *         @arg ENABLE:    switch on LSI clock generator
  * @retval None
  */
void RST_CLK_LSIcmd(FunctionalState NewState)
{

  uint32_t temp = 0;

  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  temp = MDR_BKP->REG_0F;
  /* Form new value */
  if (NewState != DISABLE) {
    /* Enable LSI clk by setting the LSE_ON bit in the BKP_REG_0F register */
    temp |= BKP_REG_0F_LSI_ON;
  }
  else {
    /* Disable LSI clk by resetting the LSE_ON bit in the BKP_REG_0F register */
    temp &= ~BKP_REG_0F_LSI_ON;
  }
  /* Configure REG_0F register with new value */
  MDR_BKP->REG_0F = temp;
}

/**
  * @brief  RST_CLK_HSIadjust: LSI clock frequency adjustment by LSITRIM setting
  * @param  LSItrimValue
  *         This parameter must be a number between 0 and 0x1F.
  * @retval None
  */
void RST_CLK_LSIadjust(uint32_t LSItrimValue)
{
  uint32_t temp;
  /* Check the parameters */
  assert_param(IS_RCC_CLK_LSI_TRIM_VALUE(LSItrimValue));
  temp = MDR_BKP->REG_0F;
  /* Clear LSITRIM[4:0] bits */
  temp &= ~BKP_REG_0F_LSI_TRIM_Msk;
  /* Set the LSITRIM[4:0] bits according to LSItrimValue value */
  temp |= (uint32_t)LSItrimValue << BKP_REG_0F_LSI_TRIM_Pos;
  /* Store the new value */
  MDR_BKP->REG_0F = temp;
}

/**
  * @brief  RST_CLK_LSIstatus - LSI clock status
  * @param  None
  * @retval enum ErrorStatus - SUCCESS if LSI clock is ready, else ERROR
  */
ErrorStatus RST_CLK_LSIstatus(void)
{
  __IO uint32_t startCounter = 0;
  ErrorStatus state;
  FlagStatus flag;

  /* Wait until LSI is ready or time out is occure */
  do
  {
    flag = RST_CLK_GetFlagStatus(RST_CLK_FLAG_LSIRDY);
    startCounter++;
  } while ((startCounter < LSIonTimeOut) && (flag == RESET));

  if (RST_CLK_GetFlagStatus(RST_CLK_FLAG_LSIRDY) != RESET)
  {
    state = SUCCESS;
  }
  else
  {
    state = ERROR;
  }
  return (state);
}

/**
  * @brief  Configures the CPU_PLL clock source and multiplication factor.
  * @param  RST_CLK_CPU_PLLsource: specifies the PLL entry clock source.
  *         @arg RST_CLK_CPU_PLLsrcHSIdiv1: HSI oscillator clock is selected as CPU_PLL clock entry
  *         @arg RST_CLK_CPU_PLLsrcHSIdiv2: HSI oscillator clock divided by 2 is selected as CPU_PLL clock entry
  *         @arg RST_CLK_CPU_PLLsrcHSEdiv1: HSE oscillator clock is selected as CPU_PLL clock entry
  *         @arg RST_CLK_CPU_PLLsrcHSEdiv2: HSE oscillator clock divided by 2 is selected as CPU_PLL clock entry
  * @param  RST_CLK_CPU_PLLmul: specifies the PLL multiplication factor.
  *         This parameter must be a number between 0 and 15.
  *           @arg RST_CLK_CPU_PLLmul1
  *           @arg RST_CLK_CPU_PLLmul2
  *           @arg RST_CLK_CPU_PLLmul3
  *           @arg RST_CLK_CPU_PLLmul4
  *           @arg RST_CLK_CPU_PLLmul5
  *           @arg RST_CLK_CPU_PLLmul6
  *           @arg RST_CLK_CPU_PLLmul7
  *           @arg RST_CLK_CPU_PLLmul8
  *           @arg RST_CLK_CPU_PLLmul9
  *           @arg RST_CLK_CPU_PLLmul10
  *           @arg RST_CLK_CPU_PLLmul11
  *           @arg RST_CLK_CPU_PLLmul12
  *           @arg RST_CLK_CPU_PLLmul13
  *           @arg RST_CLK_CPU_PLLmul14
  *           @arg RST_CLK_CPU_PLLmul15
  *           @arg RST_CLK_CPU_PLLmul16
  * @retval None
  */
void RST_CLK_CPU_PLLconfig ( uint32_t RST_CLK_CPU_PLLsource,
                         uint32_t RST_CLK_CPU_PLLmul )
{
  uint32_t temp;

  /* Check the parameters */
  assert_param(IS_RST_CLK_CPU_PLL_SOURCE(RST_CLK_CPU_PLLsource));
  assert_param(IS_RST_CLK_CPU_PLL_MUL(RST_CLK_CPU_PLLmul));

  /* Select CPUPLL source */
  temp = MDR_RST_CLK->CPU_CLOCK;
  /* Clear CPU_C1_SEL bits */
  temp &= ~RST_CLK_CPU_CLOCK_CPU_C1_SEL_Msk;
  /* Set the CPU_C1_SEL bits */
  temp |= RST_CLK_CPU_PLLsource;
  /* Store the new value */MDR_RST_CLK->CPU_CLOCK = temp;

  /* Set CPUPLL multiplier */
  temp = MDR_RST_CLK->PLL_CONTROL;
  /* Clear PLLMUL[3:0] bits */
  temp &= ~RST_CLK_PLL_CONTROL_PLL_CPU_MUL_Msk;
  /* Set the PLLMUL[3:0] bits */
  temp |= (RST_CLK_CPU_PLLmul << RST_CLK_PLL_CONTROL_PLL_CPU_MUL_Pos);
  /* Store the new value */
  MDR_RST_CLK->PLL_CONTROL = temp;

  if( (MDR_RST_CLK->PLL_CONTROL & RST_CLK_PLL_CONTROL_PLL_CPU_ON) == RST_CLK_PLL_CONTROL_PLL_CPU_ON ) {
    temp = MDR_RST_CLK->PLL_CONTROL;
    temp |= RST_CLK_PLL_CONTROL_PLL_CPU_PLD;
    MDR_RST_CLK->PLL_CONTROL = temp;
    temp &= ~RST_CLK_PLL_CONTROL_PLL_CPU_PLD;
    MDR_RST_CLK->PLL_CONTROL = temp;
  }

}

/**
  * @brief  Select the CPU_PLL output as input for CPU_C3_SEL or bypass the CPU_PLL.
  * @param  UsePLL: usage state of the CPU_PLL. This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void RST_CLK_CPU_PLLuse(FunctionalState UsePLL)
{
  uint32_t temp = 0;

  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(UsePLL));

  temp = MDR_RST_CLK->CPU_CLOCK;
  /* Form new value */
  if (UsePLL != DISABLE){
    /* Use the CPU PLL output as input for CPU_C3_SEL
     * by setting the CPU_C2_SEL bit in the CPU_CLOCK register */
    temp |= (1<< RST_CLK_CPU_CLOCK_CPU_C2_SEL_Pos);
  }
  else{
    /* Use the CPU_C1 output as input for CPU_C3_SEL
     * by resetting the CPU_C2_SEL bit in the CPU_CLOCK register */
    temp &= ~(1<< RST_CLK_CPU_CLOCK_CPU_C2_SEL_Pos);
  }
  /* Configure CPU_CLOCK register with new value */
  MDR_RST_CLK->CPU_CLOCK = temp;
}

/**
  * @brief  Enables or disables the CPU_PLL.
  * @param  NewState: new state of the CPU_PLL. This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void RST_CLK_CPU_PLLcmd ( FunctionalState NewState )
{
  uint32_t temp;

  assert_param(IS_FUNCTIONAL_STATE(NewState));

  temp = MDR_RST_CLK->PLL_CONTROL;

  if(NewState == ENABLE){
    temp |= RST_CLK_PLL_CONTROL_PLL_CPU_ON;
  }
  else{
    temp &= ~RST_CLK_PLL_CONTROL_PLL_CPU_ON;
  }
  MDR_RST_CLK->PLL_CONTROL = temp;
}

/**
  * @brief  RST_CLK_CPU_PLLstatus: CPU_PLL status
  * @param  None
  * @retval enum ErrorStatus: SUCCESS if CPU_PLL output clock is ready, else ERROR
  */
ErrorStatus RST_CLK_CPU_PLLstatus(void)
{
  __IO uint32_t startCounter = 0;
  ErrorStatus state;
  FlagStatus flag;

  /* Wait until CPUPLL is ready or time out is occure */
  do
  {
    flag = RST_CLK_GetFlagStatus(RST_CLK_FLAG_PLLCPURDY);
    startCounter++;
  } while ((startCounter < PLLCPUonTimeOut) && (flag == RESET));

  if (RST_CLK_GetFlagStatus(RST_CLK_FLAG_PLLCPURDY) != RESET)
  {
    state = SUCCESS;
  }
  else
  {
    state = ERROR;
  }
  return state;
}

/**
  * @brief  RST_CLK_CPUclkPrescaler: configures the CPU_C3_SEL division factor switch.
  * @param  CPUclkDivValue: specifies the CPU_PLL clock division factor.
  *         @arg RST_CLK_CPUclkDIV1
  *         @arg RST_CLK_CPUclkDIV2
  *         @arg RST_CLK_CPUclkDIV4
  *         @arg RST_CLK_CPUclkDIV8
  *         @arg RST_CLK_CPUclkDIV16
  *         @arg RST_CLK_CPUclkDIV32
  *         @arg RST_CLK_CPUclkDIV64
  *         @arg RST_CLK_CPUclkDIV128
  *         @arg RST_CLK_CPUclkDIV256
  * @retval None
  */
void RST_CLK_CPUclkPrescaler(uint32_t CPUclkDivValue)
{
  uint32_t temp;

  /* Check the parameters */
  assert_param(IS_RST_CLK_CPUclkDIV(CPUclkDivValue));

  temp = MDR_RST_CLK->CPU_CLOCK;
  /* Clear CPU_C3_SEL bits */
  temp &= ~RST_CLK_CPU_CLOCK_CPU_C3_SEL_Msk;
  /* Set the CPU_C3_SEL bits */
  temp |= (CPUclkDivValue << RST_CLK_CPU_CLOCK_CPU_C3_SEL_Pos);
  /* Store the new value */
  MDR_RST_CLK->CPU_CLOCK = temp;
}

/**
  * @brief  RST_CLK_CPUclkSelection: select the CPU clock source.
  * @param  CPU_CLK: specifies the CPU clock source.
  *         @arg RST_CLK_CPUclkHSI
  *         @arg RST_CLK_CPUclkCPU_C3
  *         @arg RST_CLK_CPUclkLSE
  *         @arg RST_CLK_CPUclkLSI
  * @retval None
  */
void RST_CLK_CPUclkSelection(uint32_t CPU_CLK)
{
  uint32_t temp;

  /* Check the parameters */
  assert_param(IS_RST_CPU_CLK(CPU_CLK));

  temp = MDR_RST_CLK->CPU_CLOCK;
  /* Clear CPU_C3_SEL bits */
  temp &= ~RST_CLK_CPU_CLOCK_HCLK_SEL_Msk;
  /* Set the CPU_C3_SEL bits */
  temp |= CPU_CLK;
  /* Store the new value */
  MDR_RST_CLK->CPU_CLOCK = temp;
}



/**
  * @brief  RST_CLK_ADCclkSelection: select the ADC clock source.
  * @param  ADC_CLK: specifies the ADC_C2 clock source.
  *         @arg  RST_CLK_ADCclkCPU_C1
  *         @arg  RST_CLK_ADCclkPER1_C1
  *         @arg  RST_CLK_ADCclkPLLCPU
  *         @arg  RST_CLK_ADCclkHSI_CLK
  * @retval None
  */
void RST_CLK_ADCclkSelection(uint32_t ADC_CLK)
{
  uint32_t temp;

  /* Check the parameters */
  assert_param(IS_RST_CLK_ADCclk(ADC_CLK));

  /* Select ADC_CLK source */
  temp = MDR_RST_CLK->ADC_MCO_CLOCK;
  /* Clear ADC_C1,C2 SEL bits */
  temp &= ~(RST_CLK_ADC_MCO_CLOCK_ADC_C1_SEL_Msk);
  /* Set the ADC_C1, SEL bits */
  temp |= ADC_CLK;
  /* Store the new value */
  MDR_RST_CLK->ADC_MCO_CLOCK = temp;
}

/**
  * @brief  RST_CLK_ADCclkPrescaler: configures the ADC_C3_SEL division factor switch.
  * @param  ADCclkDivValue: specifies the ADC_C2 clock division factor.
  *         This parameter must be a number between 0 and 15.
  *           @arg RST_CLK_ADCclkDIV1
  *           @arg RST_CLK_ADCclkDIV2
  *           @arg RST_CLK_ADCclkDIV4
  *           @arg RST_CLK_ADCclkDIV8
  *           @arg RST_CLK_ADCclkDIV16
  *           @arg RST_CLK_ADCclkDIV32
  *           @arg RST_CLK_ADCclkDIV64
  *           @arg RST_CLK_ADCclkDIV128
  *           @arg RST_CLK_ADCclkDIV256
  * @retval None
  */
void RST_CLK_ADCclkPrescaler(uint32_t ADCclkDivValue)
{
  uint32_t temp;

  /* Check the parameters */
  assert_param(IS_RST_CLK_ADCclkDivValue(ADCclkDivValue));

  temp = MDR_RST_CLK->ADC_MCO_CLOCK;
  /* Clear ADC_C3_SEL bits */
  temp &= ~RST_CLK_ADC_MCO_CLOCK_ADC_C3_SEL_Msk;
  /* Set the ADC_C3_SEL bits */
  temp |= ADCclkDivValue << RST_CLK_ADC_MCO_CLOCK_ADC_C3_SEL_Pos;
  /* Store the new value */
  MDR_RST_CLK->ADC_MCO_CLOCK = temp;
}

/**
  * @brief  Enables or disables the ADC_CLK clock.
  * @param  NewState: new state of the ADC_CLK.
  *         @arg ENABLE
  *         @arg DISABLE
  * @retval None
  */
void RST_CLK_ADCclkEnable ( FunctionalState NewState )
{
  uint32_t temp = 0;
  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  temp = MDR_RST_CLK->ADC_MCO_CLOCK;
  /* Form new value */
  if (NewState != DISABLE){
    /* Enable the ADC CLK by setting the ADC_CLK_EN bit in the ADC_MCO_CLOCK register */
    temp |= RST_CLK_ADC_MCO_CLOCK_ADC_CLK_EN;
  }
  else{
    /* Disable the ADC CLK by resetting the ADC_CLK_EN bit in the ADC_MCO_CLOCK register */
    temp &= ~RST_CLK_ADC_MCO_CLOCK_ADC_CLK_EN;
  }
  /* Configure CPU_CLOCK register with new value */
  MDR_RST_CLK->ADC_MCO_CLOCK = temp;
}


/**
  * @brief  Set the RST_CLK_ADCIU clock configuration to the default reset state.
  * @param  None.
  * @retval None.
  */
void RST_CLK_ADCIUclkDeInit(void)
{

  MDR_RST_CLK->ADC_MCO_CLOCK &= ~(RST_CLK_ADC_MCO_CLOCK_ADCIU_C1_SEL_Msk |
                              	  RST_CLK_ADC_MCO_CLOCK_ADCIU_C3_SEL_Msk |
                              	  RST_CLK_ADC_MCO_CLOCK_ADCIU_CLK_EN);

}
/**
  * @brief  RST_CLK_ADCIUclkSelection: select the ADCIU clock source.
  * @warning This function can be used only for microcontroller MDR1986VE3.
  * @param  ADCIU_CLK_C1: specifies the ADCIU_C1 clock source.
  *         @arg  RST_CLK_ADCIUclkCPU_C1
  *         @arg  RST_CLK_ADCIUclkPER1_C1
  *         @arg  RST_CLK_ADCIUclkPLLCPU
  *         @arg  RST_CLK_ADCIUclkHSI_CLK
  * @retval None
  */
void RST_CLK_ADCIUclkSelection(uint32_t ADCIU_CLK_C1)
{
  uint32_t temp = 0;

  /* Check the parameters */
  assert_param(IS_RST_CLK_ADCIUclk(ADCIU_CLK_C1));

  /* Select ADC_CLK source */
  temp = MDR_RST_CLK->ADC_MCO_CLOCK;
  /* Clear ADCIU_C1,C2 SEL bits */
  temp &= ~RST_CLK_ADC_MCO_CLOCK_ADCIU_C1_SEL_Msk;
  /* Set the ADCIU_C1 SEL bits */
  temp |= ADCIU_CLK_C1;
  /* Store the new value */
  MDR_RST_CLK->ADC_MCO_CLOCK = temp;
}

/**
 * @brief RST_CLK_ADCIUclkPrescaler: configures the ADCIU_C3_SEL division factor switch.
 * @param ADCIUclkDIVValue: specifies the ADCIU_VIV clock division factor.
 *    @arg RST_CLK_ADCIUclkDIV1
 *    @arg RST_CLK_ADCIUclkDIV2
 *    @arg RST_CLK_ADCIUclkDIV4
 *    @arg RST_CLK_ADCIUclkDIV8
 *    @arg RST_CLK_ADCIUclkDIV16
 *    @arg RST_CLK_ADCIUclkDIV32
 *    @arg RST_CLK_ADCIUclkDIV64
 *    @arg RST_CLK_ADCIUclkDIV128
 *    @arg RST_CLK_ADCIUclkDIV256
 * @retval None
 */
void RST_CLK_ADCIUclkPrescaler(uint32_t ADCIUclkDIVValue)
{
  uint32_t temp = 0;

  /* Check the parameters */
  assert_param(IS_RST_CLK_ADCIUclkDIV(ADCIUclkDIVValue));

  temp = MDR_RST_CLK->ADC_MCO_CLOCK;
  /* Clear ADCIU_C3_SEL bits */
  temp &= ~RST_CLK_ADC_MCO_CLOCK_ADCIU_C3_SEL_Msk;
  /* Set the ADCIU_C3_SEL bits */
  temp |= ADCIUclkDIVValue;
  /* Store the new value */
  MDR_RST_CLK->ADC_MCO_CLOCK = temp;
}

/**
 * @brief  Enables or disables the ADCIU clk.
 * @param  NewState: new state of the ADCIU clk.
 *         This parameter can be: ENABLE or DISABLE.
 * @retval None
 */
void RST_CLK_ADCIUclkCMD(FunctionalState NewState)
{
  uint32_t temp = 0;

  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  temp = MDR_RST_CLK->ADC_MCO_CLOCK;

  /* Form new value */
  if (NewState != DISABLE){
    /* Enable ADCIU clk by setting the ADCIU_CLK_EN bit in the ADC_MCO_CLOCK register */
    temp |= RST_CLK_ADC_MCO_CLOCK_ADCIU_CLK_EN;
  }
  else{
    /* Disable ADCIU clk by resetting the ADCIU_CLK_EN bit in the ADC_MCO_CLOCK register */
    temp &= ~RST_CLK_ADC_MCO_CLOCK_ADCIU_CLK_EN;
  }
  /* Configure ADC_MCO_CLOCK register with new value */
  MDR_RST_CLK->ADC_MCO_CLOCK = temp;
}


/**
  * @brief  RST_CLK_HSIclkPrescaler: configures the HSI_C1_SEL division factor switch.
  * @param  HSIclkDivValue: specifies the HSI clock division factor.
  *         This parameter must be a number between 0 and 15.
  *           @arg RST_CLK_HSIclkDIV1
  *           @arg RST_CLK_HSIclkDIV2
  *           @arg RST_CLK_HSIclkDIV4
  *           @arg RST_CLK_HSIclkDIV8
  *           @arg RST_CLK_HSIclkDIV16
  *           @arg RST_CLK_HSIclkDIV32
  *           @arg RST_CLK_HSIclkDIV64
  *           @arg RST_CLK_HSIclkDIV128
  *           @arg RST_CLK_HSIclkDIV256
  * @retval None
  */
void RST_CLK_HSIclkPrescaler(uint32_t HSIclkDivValue)
{
  uint32_t temp;

  /* Check the parameters */
  assert_param(IS_RST_CLK_HSIclkDivValue(HSIclkDivValue));

  temp = MDR_RST_CLK->RTC_CLOCK;
  /* Clear HSI_SEL bits */
  temp &= ~RST_CLK_RTC_CLOCK_HSI_SEL_Msk;
  /* Set the HSI_SEL bits */
  temp |= HSIclkDivValue << RST_CLK_RTC_CLOCK_HSI_SEL_Pos;
  /* Store the new value */
  MDR_RST_CLK->RTC_CLOCK = temp;
}

/**
  * @brief  RST_CLK_RTC_HSIclkEnable: enables or disables the RTCHSI clock.
  * @param  NewState: new state of the HSI_RTC_EN.
  *         @arg ENABLE
  *         @arg DISABLE
  * @retval None
  */
void RST_CLK_RTC_HSIclkEnable ( FunctionalState NewState )
{
  uint32_t temp = 0;
  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  temp = MDR_RST_CLK->RTC_CLOCK;
  /* Form new value */
  if (NewState != DISABLE){
    /* Enable HSI RTC clk by setting the HSE_RTC_EN bit in the RTC_CLOCK register */
    temp |= RST_CLK_RTC_CLOCK_HSI_RTC_EN;
  }
  else{
    /* Disable HSI RTC clk by resetting the HSE_RTC_EN bit in the RTC_CLOCK register */
    temp &= ~RST_CLK_RTC_CLOCK_HSI_RTC_EN;
  }
  /* Configure RTC_CLOCK register with new value */
  MDR_RST_CLK->RTC_CLOCK = temp;
}

/**
  * @brief  RST_CLK_HSEclkPrescaler: configures the HSE_C1_SEL division factor switch.
  * @param  HSEclkDivValue: specifies the HSE clock division factor.
  *         This parameter must be a number between 0 and 15.
  *           @arg RST_CLK_HSEclkDIV1
  *           @arg RST_CLK_HSEclkDIV2
  *           @arg RST_CLK_HSEclkDIV4
  *           @arg RST_CLK_HSEclkDIV8
  *           @arg RST_CLK_HSEclkDIV16
  *           @arg RST_CLK_HSEclkDIV32
  *           @arg RST_CLK_HSEclkDIV64
  *           @arg RST_CLK_HSEclkDIV128
  *           @arg RST_CLK_HSEclkDIV256
  * @retval None
  */
void RST_CLK_HSEclkPrescaler(uint32_t HSEclkDivValue)
{
  uint32_t temp;

  /* Check the parameters */
  assert_param(IS_RST_CLK_HSEclkDivValue(HSEclkDivValue));

  temp = MDR_RST_CLK->RTC_CLOCK;
  /* Clear HSE_SEL bits */
  temp &= ~RST_CLK_RTC_CLOCK_HSE_SEL_Msk;
  /* Set the HSE_SEL bits */
  temp |= HSEclkDivValue << RST_CLK_RTC_CLOCK_HSE_SEL_Pos;
  /* Store the new value */
  MDR_RST_CLK->RTC_CLOCK = temp;
}

/**
  * @brief  RST_CLK_RTC_HSEclkEnable: enables or disables the RTCHSE clock.
  * @param  NewState: new state of the HSE_RTC_EN.
  *         @arg ENABLE
  *         @arg DISABLE
  * @retval None
  */
void RST_CLK_RTC_HSEclkEnable(FunctionalState NewState)
{
  uint32_t temp;
  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  temp = MDR_RST_CLK->RTC_CLOCK;
  /* Form new value */
  if (NewState != DISABLE){
    /* Enable HSI RTC clk by setting the HSE_RTC_EN bit in the RTC_CLOCK register */
    temp |= RST_CLK_RTC_CLOCK_HSE_RTC_EN;
  }
  else{
    /* Disable HSI RTC clk by resetting the HSE_RTC_EN bit in the RTC_CLOCK register */
    temp &= ~RST_CLK_RTC_CLOCK_HSE_RTC_EN;
  }
  /* Configure RTC_CLOCK register with new value */
  MDR_RST_CLK->RTC_CLOCK = temp;
}

/**
 * @brief	RST_CLK_PCLKPer1_C1_CLKSelection: Select the clock source for PER1_C1
 * @param 	CLK_SRC: specifies the PER1_C1 clock source.
 * 				This parameter can be one of the following values:
 * 				@arg RST_CLK_PER1_C1_CLK_SRC_LSI
 * 				@arg RST_CLK_PER1_C1_CLK_SRC_LSI_2
 * 				@arg RST_CLK_PER1_C1_CLK_SRC_LSE
 * 				@arg RST_CLK_PER1_C1_CLK_SRC_LSE_2
 * @retval	None
 */
void RST_CLK_PCLKPer1_C1_CLKSelection(uint32_t CLK_SRC)
{
	/* Check the parameters */
	assert_param(IS_RST_CLK_PER1_C1_CLK_SRC(CLK_SRC));

	/* Cleare old clk src and set the new clk src */
	MDR_RST_CLK->PER1_CLOCK = (MDR_RST_CLK->PER1_CLOCK & (~RST_CLK_PER1_CLOCK_C1_SEL_Msk))
							| CLK_SRC;
}

/**
 * @brief	RST_CLK_PCLKPer1_C2_CLKSelection: Select the clock source for PER1_C2
 * @param 	CLK_SRC: specifies the PER1_C2 clock source.
 * 			This parameter can be one of the following values:
 * 				@arg RST_CLK_PER1_C2_CLK_SRC_CPU_C1
 * 				@arg RST_CLK_PER1_C2_CLK_SRC_PER1_C1
 * 				@arg RST_CLK_PER1_C2_CLK_SRC_PLLCPU
 * 				@arg RST_CLK_PER1_C2_CLK_SRC_HSI_CLK
 * @retval	None
 */
void RST_CLK_PCLKPer1_C2_CLKSelection(uint32_t CLK_SRC)
{
	/* Check the parameters */
	assert_param(IS_RST_CLK_PER1_C2_CLK_SRC(CLK_SRC));
	MDR_RST_CLK->PER1_CLOCK = (MDR_RST_CLK->PER1_CLOCK & (~RST_CLK_PER1_CLOCK_C2_SEL_Msk))
							| CLK_SRC;
}

/**
  * @brief  RST_CLK_RTC_HSEclkEnable: enables or disables the RTCHSE clock.
  * @param  RST_CLK_PCLK: specifies the peripheral to gates its clock.
  *         This parameter can be any combination of the following values:
  *           @arg RST_CLK_PCLK_SSP1, RST_CLK_PCLK_UART1, RST_CLK_PCLK_UART1,
  * 			   RST_CLK_PCLK_EEPROM, RST_CLK_PCLK_RST_CLK, RST_CLK_PCLK_DMA,
  * 			   RST_CLK_PCLK_COMP, RST_CLK_PCLK_DAC,	RST_CLK_PCLK_ADC,
  * 			   RST_CLK_PCLK_WWDG, RST_CLK_PCLK_IWDG, RST_CLK_PCLK_POWER,
  * 			   RST_CLK_PCLK_BKP, RST_CLK_PCLK_ADCUI, RST_CLK_PCLK_TIMER1,
  * 			   RST_CLK_PCLK_TIMER2,	RST_CLK_PCLK_PORTA,	RST_CLK_PCLK_PORTB,
  * 			   RST_CLK_PCLK_PORTC, RST_CLK_PCLK_CRC.
  * @param  NewState: new state of the specified peripheral clock.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void RST_CLK_PCLKcmd(uint32_t RST_CLK_PCLK, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  assert_param(IS_RST_CLK_PCLK(RST_CLK_PCLK));
  if (NewState != DISABLE)
  {
    MDR_RST_CLK->PER2_CLOCK |= RST_CLK_PCLK;
  }
  else
  {
    MDR_RST_CLK->PER2_CLOCK &= ~RST_CLK_PCLK;
  }
}

/**
  * @brief  RST_CLK_GetClocksFreq: Put the frequencies of different on chip clocks
  *         in *RST_CLK_Clocks structure.
  * @param  RST_CLK_Clocks: pointer to a RST_CLK_ClocksTypeDef structure that will hold
  *         the clocks frequencies.
  * @retval None
  */
void RST_CLK_GetClocksFreq(RST_CLK_FreqTypeDef* RST_CLK_Clocks)
{
  uint32_t cpu_c1_freq, cpu_c2_freq, cpu_c3_freq;
  uint32_t adc_c1_freq, adc_c3_freq;
  uint32_t adciu_c1_freq, adciu_c3_freq;
  uint32_t hsi_c1_freq, hse_c1_freq;
  uint32_t per_c1_freq/*, per_c2_freq*/;
  uint32_t pll_mul;
  uint32_t temp;

  /* Check the parameter */
  assert_param(RST_CLK_Clocks != 0);

  /* Compute CPU_CLK, ADC_CLK, ADCIU_CLK, RTCHSI, RTCHSE clocks frequencies */

  /* Compute CPU_CLK frequency */

  /* Determine CPU_C1 frequency */
  if( MDR_RST_CLK->CPU_CLOCK & (2 << RST_CLK_CPU_CLOCK_CPU_C1_SEL_Pos) ) {
    cpu_c1_freq = HSE_Value;
  }
  else {
    cpu_c1_freq = HSI_Value;
  }
  if( MDR_RST_CLK->CPU_CLOCK & (1 << RST_CLK_CPU_CLOCK_CPU_C1_SEL_Pos) ) {
    cpu_c1_freq /= 2;
  }

  /* Determine CPU_C2 frequency */
  cpu_c2_freq = cpu_c1_freq;

  /* Determine CPU PLL output frequency */
  pll_mul = ((MDR_RST_CLK->PLL_CONTROL >> RST_CLK_PLL_CONTROL_PLL_CPU_MUL_Pos)
		  & (uint32_t) 0x0F) + 1;
  if (MDR_RST_CLK->CPU_CLOCK & (1 << RST_CLK_CPU_CLOCK_CPU_C2_SEL_Pos)) {
    cpu_c2_freq *= pll_mul;
  }

  /*Select CPU_CLK from HSI, CPU_C3, LSE, LSI cases */
  switch ((MDR_RST_CLK->CPU_CLOCK >> RST_CLK_CPU_CLOCK_HCLK_SEL_Pos)
      & (uint32_t) 0x03) {
    case 0:
      /* HSI */
      RST_CLK_Clocks->CPU_CLK_Frequency = HSI_Value;
      break;
    case 1:
      /* CPU_C3 */
      /* Determine CPU_C3 frequency */
      if ((MDR_RST_CLK->CPU_CLOCK >> RST_CLK_CPU_CLOCK_CPU_C3_SEL_Pos
          & (uint32_t) 0x08) == 0x00) {
        cpu_c3_freq = cpu_c2_freq;
      }
      else {
        cpu_c3_freq = cpu_c2_freq
            / (1
                << ((MDR_RST_CLK->CPU_CLOCK
                    >> RST_CLK_CPU_CLOCK_CPU_C3_SEL_Pos
                    & (uint32_t) 0x07) + 1));
      }
      RST_CLK_Clocks->CPU_CLK_Frequency = cpu_c3_freq;
      break;
    case 2:
      /* LSE */
      RST_CLK_Clocks->CPU_CLK_Frequency = LSE_Value;
      break;
    default: /* case 3 */
      /* LSI */
      RST_CLK_Clocks->CPU_CLK_Frequency = LSI_Value;
      break;
  }

  /* Compute RTCHSI_CLK frequency */
  temp = MDR_RST_CLK->RTC_CLOCK >> RST_CLK_RTC_CLOCK_HSI_SEL_Pos;
  if ((temp & 0x08U) == 0) {
    hsi_c1_freq = HSI_Value;
  }
  else {
    temp = 1 << ((temp & 0x07U) + 1);
    hsi_c1_freq = HSI_Value / temp;
  }
  RST_CLK_Clocks->RTCHSI_Frequency = hsi_c1_freq;

  /* Compute RTCHSE_CLK frequency */
  temp = MDR_RST_CLK->RTC_CLOCK >> RST_CLK_RTC_CLOCK_HSE_SEL_Pos;
  if ((temp & 0x08U) == 0) {
    hse_c1_freq = HSE_Value;
  }
  else {
    temp = 1 << ((temp & 0x07U) + 1);
    hse_c1_freq = HSE_Value / temp;
  }
  RST_CLK_Clocks->RTCHSE_Frequency = hse_c1_freq;

  /* Determine clock frequency per_c1 and per_c2 */
  if(MDR_RST_CLK->PER1_CLOCK & 0x02)
	  per_c1_freq = LSE_Value;
  else
	  per_c1_freq = LSI_Value;

  if(MDR_RST_CLK->PER1_CLOCK & 0x01)
	  per_c1_freq /= 2;

  /* FIXME unnecessary code
  switch((MDR_RST_CLK->PER1_CLOCK >> 2) & 0x03){
	  case 0:
		  per_c2_freq = cpu_c1_freq;
		  break;
	  case 1:
		  per_c2_freq = per_c1_freq;
		  break;
	  case 2:
		  per_c2_freq = cpu_c1_freq * pll_mul;
		  break;
	  case 3:
		  per_c2_freq = HSI_Value;
		  break;
  }
  */

  /* Compute ADC_CLK frequency */

  /* Select ADC_C1 from cpu_c1, per_c1_freq, cpu_c2_freq, HSI_Value cases */
  switch ((MDR_RST_CLK->ADC_MCO_CLOCK >> RST_CLK_ADC_MCO_CLOCK_ADC_C1_SEL_Pos)
      & (uint32_t) 0x03) {
    case 0:
      /* ADC_C1 */
      adc_c1_freq = cpu_c1_freq;
      break;
    case 1:
      /* ADC_C1 */
      adc_c1_freq = per_c1_freq;
      break;
    case 2:
      /* ADC_C2 */
      adc_c1_freq = cpu_c2_freq;
      break;
    default: /* case 3 */
      /* ADC_C2 */
      adc_c1_freq = HSI_Value;
      break;
  }


  temp = MDR_RST_CLK->ADC_MCO_CLOCK >> RST_CLK_ADC_MCO_CLOCK_ADC_C3_SEL_Pos;
  if ((temp & 0x08U) == 0) {
    adc_c3_freq = adc_c1_freq;
  }
  else {
    temp = 1 << ((temp & 0x07U) + 1);
    adc_c3_freq = adc_c1_freq / temp;
  }

  RST_CLK_Clocks->ADC_CLK_Frequency = adc_c3_freq;

  /* Compute ADCIU_CLK frequency */

  /* Select ADCIU_C1 from cpu_c1, per_c1_freq, cpu_c2_freq, HSI_Value cases */
  switch ((MDR_RST_CLK->ADC_MCO_CLOCK >> RST_CLK_ADC_MCO_CLOCK_ADCIU_C1_SEL_Pos)
      & (uint32_t) 0x03) {
    case 0:
      /* ADCIU_C1 */
      adciu_c1_freq = cpu_c1_freq;
      break;
    case 1:
      /* ADCIU_C1 */
      adciu_c1_freq = per_c1_freq;
      break;
    case 2:
      /* ADCIU_C1 */
      adciu_c1_freq = cpu_c2_freq;
      break;
    default: /* case 3 */
      /* ADCIU_C1 */
      adciu_c1_freq = HSI_Value;
      break;
  }


  temp = MDR_RST_CLK->ADC_MCO_CLOCK >> RST_CLK_ADC_MCO_CLOCK_ADCIU_C3_SEL_Pos;
  if ((temp & 0x08U) == 0) {
    adciu_c3_freq = adciu_c1_freq;
  }
  else {
    temp = 1 << ((temp & 0x07U) + 1);
    adciu_c3_freq = adciu_c1_freq / temp;
  }

  RST_CLK_Clocks->ADCIU_CLK_Frequency = adciu_c3_freq;

}

/**
  * @brief  Checks whether the specified RCC flag is set or not.
  * @param  RST_CLK_FLAG: specifies the flag to check.
  *         This parameter can be one of the following values:
  *           @arg RST_CLK_FLAG_HSIRDY
  *                RST_CLK_FLAG_LSIRDY
  *                RST_CLK_FLAG_HSERDY
  *                RST_CLK_FLAG_LSERDY
  *                RST_CLK_FLAG_PLLCPURDY
  * @retval The new state of RCC_FLAG (SET or RESET).
  */
FlagStatus RST_CLK_GetFlagStatus(uint32_t RST_CLK_FLAG)
{
  uint32_t statusreg;
  FlagStatus bitstatus;

  /* Check the parameters */
  assert_param(IS_RST_CLK_FLAG(RST_CLK_FLAG));

  /* Get the register */
  if ((FLAG_SFR_MASK & RST_CLK_FLAG) == (uint32_t)0x20) /* The flag to check is in CLOCK_STATUS register */
  {
    statusreg = MDR_RST_CLK->CLOCK_STATUS;
  }
  else                                                  /* The flag to check is in REG_0F register */
  {
    statusreg = MDR_BKP->REG_0F;
  }

  /* Get the flag status on proper position */
  if ((statusreg & ((uint32_t)1 << (RST_CLK_FLAG & FLAG_MASK))) != (uint32_t)0x00)
  {
    bitstatus = SET;
  }
  else
  {
    bitstatus = RESET;
  }

  /* Return the flag status */
  return bitstatus;
}

/** @} */ /* End of group RST_CLK_Private_Functions */

/** @} */ /* End of group RST_CLK */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

/*
*
* END OF FILE MDR32F9Qx_rst_clk.c */

