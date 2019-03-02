/**
  * FILE system_MDR1986VE3.c
  */


/** @addtogroup __CMSIS CMSIS
  * @{
  */

/** @addtogroup MDR1986VE3 MDR1986VE3
 *  @{
 */

/** @defgroup MDR1986VE3_System_ARM MDR1986VE3 System ARM
  * @{
  */

/** @addtogroup System_Private_Includes System Private Includes
  * @{
  */

#include "MDR1986VE3.h"
#include "MDR32F9Qx_config.h"

/** @} */ /* End of group System_Private_Includes */

/** @defgroup __MDR1986VE3_System_Private_Variables MDR1986VE3 System Private Variables
  * @{
  */

/*******************************************************************************
*  Clock Definitions
*******************************************************************************/
  uint32_t SystemCoreClock = (uint32_t)8000000;         /*!< System Clock Frequency (Core Clock)
                                                         *   default value */

/** @} */ /* End of group __MDR1986VE3_System_Private_Variables */

/** @defgroup __MDR1986VE3_System_Private_Functions MDR1986VE3 System Private Functions
  * @{
  */

/**
  * @brief  Update SystemCoreClock according to Clock Register Values
  * @note   None
  * @param  None
  * @retval None
  */
void SystemCoreClockUpdate (void)
{
  uint32_t cpu_c1_freq, cpu_c2_freq, cpu_c3_freq;
  uint32_t pll_mul;

  /* Compute CPU_CLK frequency */

  /* Determine CPU_C1 frequency */
  if ((MDR_RST_CLK->CPU_CLOCK & (uint32_t)0x00000002) == (uint32_t)0x00000002)
  {
    cpu_c1_freq = HSE_Value;
  }
  else
  {
    cpu_c1_freq = HSI_Value;
  }

  if ((MDR_RST_CLK->CPU_CLOCK & (uint32_t)0x00000001) == (uint32_t)0x00000001)
  {
    cpu_c1_freq >>= 1;
  }

  /* Determine CPU_C2 frequency */
  cpu_c2_freq = cpu_c1_freq;

  if ((MDR_RST_CLK->CPU_CLOCK & (uint32_t)0x00000004) == (uint32_t)0x00000004)
  {
    /* Determine CPU PLL output frequency */
    pll_mul = ((MDR_RST_CLK->PLL_CONTROL >> 8) & (uint32_t)0x0F) + 1;
    cpu_c2_freq *= pll_mul;
  }

  /*Select CPU_CLK from HSI, CPU_C3, LSE, LSI cases */
  switch ((MDR_RST_CLK->CPU_CLOCK >> 8) & (uint32_t)0x03)
  {
    uint32_t tmp;
    case 0 :
      /* HSI */
      SystemCoreClock = HSI_Value;
      break;
    case 1 :
      /* CPU_C3 */
      /* Determine CPU_C3 frequency */
      tmp = MDR_RST_CLK->CPU_CLOCK >> 4 & (uint32_t)0x0F;
      if (tmp & (uint32_t)0x8)
      {
        tmp &= (uint32_t)0x7;
        cpu_c3_freq = cpu_c2_freq >> (tmp + 1);
      }
      else
      {
        cpu_c3_freq = cpu_c2_freq;
      }
      SystemCoreClock = cpu_c3_freq;
      break;
    case 2 :
      /* LSE */
      SystemCoreClock = LSE_Value;
      break;
    default : /* case 3 */
      /* LSI */
      SystemCoreClock = LSI_Value;
      break;
  }
}

/**
  * @brief  Setup the microcontroller system
  *         RST clock configuration to the default reset state
  *         Setup SystemCoreClock variable.
  * @note   This function should be used only after reset.
  * @param  None
  * @retval None
  */
void SystemInit (void)
{
	/* Reset the RST clock configuration to the default reset state */

  /* Reset all clock but RST_CLK & BKP_CLK bits */
  MDR_RST_CLK->PER_CLOCK   = (uint32_t)0x8000010;
  MDR_RST_CLK->PER2_CLOCK &= (uint32_t)0x00000000;

  /* Reset CPU_CLOCK bits */
  MDR_RST_CLK->CPU_CLOCK   &= (uint32_t)0x00000000;

  /* Reset PLL_CONTROL bits */
  MDR_RST_CLK->PLL_CONTROL &= (uint32_t)0x00000000;

  /* Reset HSEON and HSEBYP bits */
  MDR_RST_CLK->HS_CONTROL  &= (uint32_t)0x00000000;

  /* Reset USB_CLOCK bits */
  MDR_RST_CLK->USB_CLOCK   &= (uint32_t)0x00000000;

  /* Reset ADC_MCO_CLOCK bits */
  MDR_RST_CLK->ADC_MCO_CLOCK   &= (uint32_t)0x00000000;

  SystemCoreClockUpdate();
}

/** @} */ /* End of group __MDR1986VE3_System_Private_Functions */

/** @} */ /* End of group MDR1986VE3_System_ARM MDR1986VE3 System ARM */

/** @} */ /* End of group MDR1986VE3 MDR1986VE3 */

/** @} */ /* End of group __CMSIS */

/*
*
* END OF FILE system_MDR1986VE3.c */
