/**
  * FILE MDR32F9Qx_rst_clk.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MDR32F9Qx_RST_CLK_H
#define __MDR32F9Qx_RST_CLK_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_lib.h"

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @addtogroup RST_CLK
  * @{
  */

/** @defgroup RST_CLK_Exported_Types RST_CLK Exported Types
  * @{
  */

/**
  * @brief Structure type for modules clocks frequencies expressed in Hz
  */

typedef struct
{
  uint32_t CPU_CLK_Frequency;
  uint32_t ADC_CLK_Frequency;
  uint32_t ADCIU_CLK_Frequency;
  uint32_t RTCHSI_Frequency;
  uint32_t RTCHSE_Frequency;
}RST_CLK_FreqTypeDef;

/**
  * @brief RST_CLK unit non-volatile settings init structure
  */

typedef struct {
     uint32_t REG_0F;
} Init_NonVolatile_RST_CLK_TypeDef;

/** @} */ /* End of group RST_CLK_Exported_Types */

/** @defgroup RST_CLK_Exported_Constants RST_CLK Exported Constants
  * @{
  */

/** @defgroup HSE_configuration HSE configuration
  * @{
  */

/**
  * @brief RST_CLK HSE (High Speed External) clock mode and source selection constants
  */

#define RST_CLK_HSE_OFF                      ((uint32_t)0x00000000)
#define RST_CLK_HSE_ON                       ((uint32_t)0x00000001)
#define RST_CLK_HSE_Bypass                   ((uint32_t)0x00000002)

#define IS_RST_CLK_HSE(HSE)                  (((HSE) == RST_CLK_HSE_OFF) || \
                                              ((HSE) == RST_CLK_HSE_ON)  || \
                                              ((HSE) == RST_CLK_HSE_Bypass))

/** @} */ /* End of group HSE_configuration */

/** @defgroup LSE_configuration LSE configuration
  * @{
  */

/**
  * @brief RST_CLK LSE (Low Speed External) clock mode and source selection constants
  */

#define RST_CLK_LSE_OFF                      ((uint32_t)0x00000000)
#define RST_CLK_LSE_ON                       ((uint32_t)0x00000001)
#define RST_CLK_LSE_Bypass                   ((uint32_t)0x00000002)

#define IS_RST_CLK_LSE(LSE)                  (((LSE) == RST_CLK_LSE_OFF) || \
                                              ((LSE) == RST_CLK_LSE_ON)  || \
                                              ((LSE) == RST_CLK_LSE_Bypass))

/** @} */ /* End of group LSE_configuration */

/** @defgroup CPU_PLL_entry_clock_source CPU PLL entry clock source
  * @{
  */

/**
  * @brief RST_CLK CPU_PLL clock mode and source selection constants
  */

#define RST_CLK_CPU_PLLsrcHSIdiv1           ((uint32_t)0x00000000)
#define RST_CLK_CPU_PLLsrcHSIdiv2           ((uint32_t)0x00000001)
#define RST_CLK_CPU_PLLsrcHSEdiv1           ((uint32_t)0x00000002)
#define RST_CLK_CPU_PLLsrcHSEdiv2           ((uint32_t)0x00000003)

#define IS_RST_CLK_CPU_PLL_SOURCE(SRC)      (((SRC) == RST_CLK_CPU_PLLsrcHSIdiv1) || \
                                             ((SRC) == RST_CLK_CPU_PLLsrcHSIdiv2) || \
                                             ((SRC) == RST_CLK_CPU_PLLsrcHSEdiv1) || \
                                             ((SRC) == RST_CLK_CPU_PLLsrcHSEdiv2))

/** @} */ /* End of group CPU_PLL_entry_clock_source */

/** @defgroup CPU_PLL_clock_multiplier CPU_PLL clock multiplier
  * @{
  */

/**
  * @brief RST_CLK PLL_CPU_MUL multiplier of the CPU_C1 clock constants
  */

#define RST_CLK_CPU_PLLmul1                     ((uint32_t)0x00000000)
#define RST_CLK_CPU_PLLmul2                     ((uint32_t)0x00000001)
#define RST_CLK_CPU_PLLmul3                     ((uint32_t)0x00000002)
#define RST_CLK_CPU_PLLmul4                     ((uint32_t)0x00000003)
#define RST_CLK_CPU_PLLmul5                     ((uint32_t)0x00000004)
#define RST_CLK_CPU_PLLmul6                     ((uint32_t)0x00000005)
#define RST_CLK_CPU_PLLmul7                     ((uint32_t)0x00000006)
#define RST_CLK_CPU_PLLmul8                     ((uint32_t)0x00000007)
#define RST_CLK_CPU_PLLmul9                     ((uint32_t)0x00000008)
#define RST_CLK_CPU_PLLmul10                    ((uint32_t)0x00000009)
#define RST_CLK_CPU_PLLmul11                    ((uint32_t)0x0000000A)
#define RST_CLK_CPU_PLLmul12                    ((uint32_t)0x0000000B)
#define RST_CLK_CPU_PLLmul13                    ((uint32_t)0x0000000C)
#define RST_CLK_CPU_PLLmul14                    ((uint32_t)0x0000000D)
#define RST_CLK_CPU_PLLmul15                    ((uint32_t)0x0000000E)
#define RST_CLK_CPU_PLLmul16                    ((uint32_t)0x0000000F)

#define IS_RST_CLK_CPU_PLL_MUL(SRC)             (SRC < 16)


/** @} */ /* End of group CPU_PLL_clock_multiplier */

/** @defgroup CPU_CLK_divider CPU CLK divider
  * @{
  */

/**
  * @brief RST_CLK CPU_PLL output clock CPU_CLK_DIV divider constants
  */

#define RST_CLK_CPUclkDIV1                    ((uint32_t)0x00000000)
#define RST_CLK_CPUclkDIV2                    ((uint32_t)0x00000008)
#define RST_CLK_CPUclkDIV4                    ((uint32_t)0x00000009)
#define RST_CLK_CPUclkDIV8                    ((uint32_t)0x0000000A)
#define RST_CLK_CPUclkDIV16                   ((uint32_t)0x0000000B)
#define RST_CLK_CPUclkDIV32                   ((uint32_t)0x0000000C)
#define RST_CLK_CPUclkDIV64                   ((uint32_t)0x0000000D)
#define RST_CLK_CPUclkDIV128                  ((uint32_t)0x0000000E)
#define RST_CLK_CPUclkDIV256                  ((uint32_t)0x0000000F)

#define IS_RST_CLK_CPUclkDIV(DIV)             (((DIV) == RST_CLK_CPUclkDIV1)   || \
                                               ((DIV) == RST_CLK_CPUclkDIV2)   || \
                                               ((DIV) == RST_CLK_CPUclkDIV4)   || \
                                               ((DIV) == RST_CLK_CPUclkDIV8)   || \
                                               ((DIV) == RST_CLK_CPUclkDIV16)  || \
                                               ((DIV) == RST_CLK_CPUclkDIV32)  || \
                                               ((DIV) == RST_CLK_CPUclkDIV64)  || \
                                               ((DIV) == RST_CLK_CPUclkDIV128) || \
                                               ((DIV) == RST_CLK_CPUclkDIV256))

/** @} */ /* End of group CPU_CLK_divider */

/** @defgroup CPU_CLK_selector CPU CLK selector
  * @{
  */

/**
  * @brief RST_CLK CPU_CLK source CPU_CLK selector constants
  */

#define RST_CLK_CPUclkHSI                     ((uint32_t)0x00000000)
#define RST_CLK_CPUclkCPU_C3                  ((uint32_t)0x00000100)
#define RST_CLK_CPUclkLSE                     ((uint32_t)0x00000200)
#define RST_CLK_CPUclkLSI                     ((uint32_t)0x00000300)

#define IS_RST_CPU_CLK(SRC)                   (((SRC) == RST_CLK_CPUclkHSI)    || \
                                               ((SRC) == RST_CLK_CPUclkCPU_C3) || \
                                               ((SRC) == RST_CLK_CPUclkLSE)    || \
                                               ((SRC) == RST_CLK_CPUclkLSI))

/** @} */ /* End of group CPU_CLK_selector */

/** @defgroup ADC_MCO_CLOCK_source ADC clock source
  * @{
  */

/**
  * @brief RST_CLK ADC_CLK selector constants
  */
#define RST_CLK_ADCclkCPU_C1                  ((uint32_t)0x00000000)
#define RST_CLK_ADCclkPER1_C1                 ((uint32_t)0x00000001)
#define RST_CLK_ADCclkPLLCPU                  ((uint32_t)0x00000002)
#define RST_CLK_ADCclkHSI_CLK                 ((uint32_t)0x00000003)


#define IS_RST_CLK_ADCclk(SRC)                (((SRC) == RST_CLK_ADCclkCPU_C1)  || \
                                               ((SRC) == RST_CLK_ADCclkPER1_C1) || \
                                               ((SRC) == RST_CLK_ADCclkPLLCPU)  || \
                                               ((SRC) == RST_CLK_ADCclkHSI_CLK))
/** @} */ /* End of group ADC_MCO_CLOCK_source */

/** @defgroup ADC_MCO_CS3_SEL ADC clock divider
  * @{
  */

/**
  * @brief RST_CLK ADC_CS2_SEL output clock ADC_CS3_SEL divider constants
  */

#define RST_CLK_ADCclkDIV1                    ((uint32_t)0x00000000)
#define RST_CLK_ADCclkDIV2                    ((uint32_t)0x00000008)
#define RST_CLK_ADCclkDIV4                    ((uint32_t)0x00000009)
#define RST_CLK_ADCclkDIV8                    ((uint32_t)0x0000000A)
#define RST_CLK_ADCclkDIV16                   ((uint32_t)0x0000000B)
#define RST_CLK_ADCclkDIV32                   ((uint32_t)0x0000000C)
#define RST_CLK_ADCclkDIV64                   ((uint32_t)0x0000000D)
#define RST_CLK_ADCclkDIV128                  ((uint32_t)0x0000000E)
#define RST_CLK_ADCclkDIV256                  ((uint32_t)0x0000000F)

#define IS_RST_CLK_ADCclkDivValue(SRC)        (((SRC) == RST_CLK_ADCclkDIV1)    || \
                                               ((SRC) == RST_CLK_ADCclkDIV2)    || \
                                               ((SRC) == RST_CLK_ADCclkDIV4)    || \
                                               ((SRC) == RST_CLK_ADCclkDIV8)    || \
                                               ((SRC) == RST_CLK_ADCclkDIV16)   || \
                                               ((SRC) == RST_CLK_ADCclkDIV32)   || \
                                               ((SRC) == RST_CLK_ADCclkDIV64)   || \
                                               ((SRC) == RST_CLK_ADCclkDIV128)  || \
                                               ((SRC) == RST_CLK_ADCclkDIV256))

/** @} */ /* End of group ADC_MCO_CS3_SEL */

/** @defgroup ADCIU_MCO_CLOCK_source ADCIU clock source
 *  @{
 */

/**
 * @brief RST_CLK ADCIU_CLK selector constants
 */
#define RST_CLK_ADCIUclkCPU_C1						((uint32_t)0x00000000)
#define RST_CLK_ADCIUclkPER1_C1						((uint32_t)0x00000004)
#define RST_CLK_ADCIUclkPLLCPU						((uint32_t)0x00000008)
#define RST_CLK_ADCIUclkHSI_CLK						((uint32_t)0x0000000C)

#define IS_RST_CLK_ADCIUclk(SRC)					 (((SRC) == RST_CLK_ADCIUclkCPU_C1) || \
													  ((SRC) == RST_CLK_ADCIUclkPER1_C1) || \
													  ((SRC) == RST_CLK_ADCIUclkPLLCPU)  || \
													  ((SRC) == RST_CLK_ADCIUclkHSI_CLK))
/** @} */ /* End of group ADCIU_MCO_CLOCK_source */

/** @defgroup ADCIUclkDIV_divider ADCIU MCO divider
 *	@{
 */

 /**
  * @brief ADCIU_MCO_CLK ADCIU_CLK output clock ADCIU_CLK_DIV divider
  */
#define RST_CLK_ADCIUclkDIV1						((uint32_t)0x00000000)
#define RST_CLK_ADCIUclkDIV2						((uint32_t)0x00000080)
#define RST_CLK_ADCIUclkDIV4						((uint32_t)0x00000090)
#define RST_CLK_ADCIUclkDIV8						((uint32_t)0x000000A0)
#define RST_CLK_ADCIUclkDIV16						((uint32_t)0x000000B0)
#define RST_CLK_ADCIUclkDIV32						((uint32_t)0x000000C0)
#define RST_CLK_ADCIUclkDIV64						((uint32_t)0x000000D0)
#define RST_CLK_ADCIUclkDIV128						((uint32_t)0x000000E0)
#define RST_CLK_ADCIUclkDIV256						((uint32_t)0x000000F0)

#define IS_RST_CLK_ADCIUclkDIV(DIV)					(((DIV) == RST_CLK_ADCIUclkDIV1)   || \
													 ((DIV) == RST_CLK_ADCIUclkDIV2)   || \
													 ((DIV) == RST_CLK_ADCIUclkDIV4)   || \
													 ((DIV) == RST_CLK_ADCIUclkDIV8)   || \
													 ((DIV) == RST_CLK_ADCIUclkDIV16)  || \
													 ((DIV) == RST_CLK_ADCIUclkDIV32)  || \
													 ((DIV) == RST_CLK_ADCIUclkDIV64)  || \
													 ((DIV) == RST_CLK_ADCIUclkDIV128) || \
													 ((DIV) == RST_CLK_ADCIUclkDIV256))
/** @} */ /* End of group ADCIUclkDIV_divider */


/** @defgroup CLK_peripheral CLK peripheral
  * @{
  */

/**
  * @brief RST_CLK peripheral modules clock constants
  */

#define PCLK_BIT(BASE)              ((uint32_t)(1 << ((((uint32_t)BASE) >> 15) & 0x1F)))

#define RST_CLK_PCLK_SSP1			PCLK_BIT(MDR_SSP1_BASE)
#define RST_CLK_PCLK_UART1			PCLK_BIT(MDR_UART1_BASE)
#define RST_CLK_PCLK_UART2			PCLK_BIT(MDR_UART2_BASE)
#define RST_CLK_PCLK_EEPROM			PCLK_BIT(MDR_EEPROM_BASE)
#define RST_CLK_PCLK_RST_CLK		PCLK_BIT(MDR_RST_CLK_BASE)
#define RST_CLK_PCLK_DMA			PCLK_BIT(MDR_DMA_BASE)
#define RST_CLK_PCLK_COMP			PCLK_BIT(MDR_COMP_BASE)
#define RST_CLK_PCLK_DAC			PCLK_BIT(MDR_DAC_BASE)
#define RST_CLK_PCLK_ADC			PCLK_BIT(MDR_ADC_BASE)
#define RST_CLK_PCLK_WWDG			PCLK_BIT(MDR_WWDG_BASE)
#define RST_CLK_PCLK_IWDG			PCLK_BIT(MDR_IWDG_BASE)
#define RST_CLK_PCLK_POWER			PCLK_BIT(MDR_POWER_BASE)
#define RST_CLK_PCLK_BKP			PCLK_BIT(MDR_BKP_BASE)
#define RST_CLK_PCLK_ADCUI			PCLK_BIT(MDR_ADCIU_BASE)
#define RST_CLK_PCLK_TIMER1			PCLK_BIT(MDR_TIMER1_BASE)
#define RST_CLK_PCLK_TIMER2			PCLK_BIT(MDR_TIMER2_BASE)
#define RST_CLK_PCLK_PORTA			PCLK_BIT(MDR_PORTA_BASE)
#define RST_CLK_PCLK_PORTB			PCLK_BIT(MDR_PORTB_BASE)
#define RST_CLK_PCLK_PORTC			PCLK_BIT(MDR_PORTC_BASE)
#define RST_CLK_PCLK_CRC			PCLK_BIT(MDR_CRC_BASE)

#define RST_CLK_PCLK_MASK			(RST_CLK_PCLK_SSP1 		| RST_CLK_PCLK_UART1 	|\
									 RST_CLK_PCLK_UART2 	| RST_CLK_PCLK_EEPROM 	|\
									 RST_CLK_PCLK_RST_CLK 	| RST_CLK_PCLK_DMA	 	|\
									 RST_CLK_PCLK_COMP 		| RST_CLK_PCLK_DAC 		|\
									 RST_CLK_PCLK_ADC 		| RST_CLK_PCLK_WWDG 	|\
									 RST_CLK_PCLK_IWDG 		| RST_CLK_PCLK_POWER 	|\
									 RST_CLK_PCLK_BKP 		| RST_CLK_PCLK_ADCUI 	|\
									 RST_CLK_PCLK_TIMER1 	| RST_CLK_PCLK_TIMER2 	|\
									 RST_CLK_PCLK_PORTA 	| RST_CLK_PCLK_PORTB 	|\
									 RST_CLK_PCLK_PORTC 	| RST_CLK_PCLK_CRC	)


#define IS_RST_CLK_PCLK(PCLK)       ((PCLK & RST_CLK_PCLK_MASK) == PCLK)

/** @} */ /* End of group CLK_peripheral */

/** @defgroup RST_CLK_PER1_CLK1_CLK_SRC RST_CLK_PER1_CLK1 CLK_SRC
  * @{
  */

#define RST_CLK_PER1_C1_CLK_SRC_LSI				((uint32_t)0x00000000)
#define RST_CLK_PER1_C1_CLK_SRC_LSI_2			((uint32_t)0x00000001)
#define RST_CLK_PER1_C1_CLK_SRC_LSE				((uint32_t)0x00000002)
#define RST_CLK_PER1_C1_CLK_SRC_LSE_2			((uint32_t)0x00000003)

#define IS_RST_CLK_PER1_C1_CLK_SRC(CLK_SRC)		((CLK_SRC == RST_CLK_PER1_C1_CLK_SRC_LSI) ||\
												 (CLK_SRC == RST_CLK_PER1_C1_CLK_SRC_LSI_2)||\
												 (CLK_SRC == RST_CLK_PER1_C1_CLK_SRC_LSE)	||\
												 (CLK_SRC == RST_CLK_PER1_C1_CLK_SRC_LSE_2))

/** @} */ /* End of group RST_CLK_PER1_CLK1_CLK_SRC */

/** @defgroup RST_CLK_PER1_C2_CLK_SRC RST_CLK_PER1_C2 CLK_SRC
  * @{
  */

#define RST_CLK_PER1_C2_CLK_SRC_CPU_C1				((uint32_t)0x00000000)
#define RST_CLK_PER1_C2_CLK_SRC_PER1_C1				((uint32_t)0x00000004)
#define RST_CLK_PER1_C2_CLK_SRC_PLLCPU				((uint32_t)0x00000008)
#define RST_CLK_PER1_C2_CLK_SRC_HSI_CLK				((uint32_t)0x0000000C)

#define IS_RST_CLK_PER1_C2_CLK_SRC(CLK_SRC)			((CLK_SRC == RST_CLK_PER1_C2_CLK_SRC_CPU_C1) ||\
													 (CLK_SRC == RST_CLK_PER1_C2_CLK_SRC_PER1_C1)||\
													 (CLK_SRC == RST_CLK_PER1_C2_CLK_SRC_PLLCPU) ||\
													 (CLK_SRC == RST_CLK_PER1_C2_CLK_SRC_HSI_CLK))

/** @} */ /* End of group RST_CLK_PER1_C2_CLK_SRC */

/** @defgroup RST_CLK_Flag RST_CLK Flag
  * @{
  */

/**
  * @brief RST_CLK flag identifiers
  */

#define RST_CLK_FLAG_HSIRDY                   ((uint32_t)(0x00 | 23))
#define RST_CLK_FLAG_LSIRDY                   ((uint32_t)(0x00 | 21))
#define RST_CLK_FLAG_HSERDY                   ((uint32_t)(0x20 |  2))
#define RST_CLK_FLAG_HSE2RDY	           	  ((uint32_t)(0x20 |  3))
#define RST_CLK_FLAG_LSERDY                   ((uint32_t)(0x00 | 13))
#define RST_CLK_FLAG_PLLCPURDY                ((uint32_t)(0x20 |  1))

#define IS_RST_CLK_FLAG(FLAG)                 (((FLAG) == RST_CLK_FLAG_HSIRDY)    || \
                                               ((FLAG) == RST_CLK_FLAG_LSIRDY)    || \
                                               ((FLAG) == RST_CLK_FLAG_HSERDY)    || \
                                               ((FLAG) == RST_CLK_FLAG_HSE2RDY)	  || \
                                               ((FLAG) == RST_CLK_FLAG_LSERDY)    || \
                                               ((FLAG) == RST_CLK_FLAG_PLLCPURDY))

/** @} */ /* End of group RST_CLK_Flag */

#define IS_RCC_CLK_HSI_TRIM_VALUE(TRIM)       ((TRIM) <= 0x3F)
#define IS_RCC_CLK_LSI_TRIM_VALUE(TRIM)       ((TRIM) <= 0x1F)

/** @defgroup RST_CLK_HSI_C1_SEL HSI clock divider
  * @{
  */

/**
  * @brief RST_CLK HSI clock HSI_C1_SEL divider constants
  */

#define RST_CLK_HSIclkDIV1                    ((uint32_t)0x00000000)
#define RST_CLK_HSIclkDIV2                    ((uint32_t)0x00000008)
#define RST_CLK_HSIclkDIV4                    ((uint32_t)0x00000009)
#define RST_CLK_HSIclkDIV8                    ((uint32_t)0x0000000A)
#define RST_CLK_HSIclkDIV16                   ((uint32_t)0x0000000B)
#define RST_CLK_HSIclkDIV32                   ((uint32_t)0x0000000C)
#define RST_CLK_HSIclkDIV64                   ((uint32_t)0x0000000D)
#define RST_CLK_HSIclkDIV128                  ((uint32_t)0x0000000E)
#define RST_CLK_HSIclkDIV256                  ((uint32_t)0x0000000F)

#define IS_RST_CLK_HSIclkDivValue(SRC)        (((SRC) == RST_CLK_HSIclkDIV1)    || \
                                               ((SRC) == RST_CLK_HSIclkDIV2)    || \
                                               ((SRC) == RST_CLK_HSIclkDIV4)    || \
                                               ((SRC) == RST_CLK_HSIclkDIV8)    || \
                                               ((SRC) == RST_CLK_HSIclkDIV16)   || \
                                               ((SRC) == RST_CLK_HSIclkDIV32)   || \
                                               ((SRC) == RST_CLK_HSIclkDIV64)   || \
                                               ((SRC) == RST_CLK_HSIclkDIV128)  || \
                                               ((SRC) == RST_CLK_HSIclkDIV256))

/** @} */ /* End of group RST_CLK_HSI_C1_SEL */

/** @defgroup RST_CLK_HSE_C1_SEL HSE clock divider
  * @{
  */

/**
  * @brief RST_CLK HSE clock HSE_C1_SEL divider constants
  */
#define RST_CLK_HSEclkDIV1                    ((uint32_t)0x00000000)
#define RST_CLK_HSEclkDIV2                    ((uint32_t)0x00000008)
#define RST_CLK_HSEclkDIV4                    ((uint32_t)0x00000009)
#define RST_CLK_HSEclkDIV8                    ((uint32_t)0x0000000A)
#define RST_CLK_HSEclkDIV16                   ((uint32_t)0x0000000B)
#define RST_CLK_HSEclkDIV32                   ((uint32_t)0x0000000C)
#define RST_CLK_HSEclkDIV64                   ((uint32_t)0x0000000D)
#define RST_CLK_HSEclkDIV128                  ((uint32_t)0x0000000E)
#define RST_CLK_HSEclkDIV256                  ((uint32_t)0x0000000F)

#define IS_RST_CLK_HSEclkDivValue(SRC)        (((SRC) == RST_CLK_HSEclkDIV1)    || \
                                               ((SRC) == RST_CLK_HSEclkDIV2)    || \
                                               ((SRC) == RST_CLK_HSEclkDIV4)    || \
                                               ((SRC) == RST_CLK_HSEclkDIV8)    || \
                                               ((SRC) == RST_CLK_HSEclkDIV16)   || \
                                               ((SRC) == RST_CLK_HSEclkDIV32)   || \
                                               ((SRC) == RST_CLK_HSEclkDIV64)   || \
                                               ((SRC) == RST_CLK_HSEclkDIV128)  || \
                                               ((SRC) == RST_CLK_HSEclkDIV256))

/** @} */ /* End of group RST_CLK_HSE_C1_SEL */

/** @} */ /* End of group RST_CLK_Exported_Constants */

/** @defgroup RST_CLK_Exported_Macros RST_CLK Exported Macros
  * @{
  */

/** @} */ /* End of group RST_CLK_Exported_Macros */

/** @defgroup RST_CLK_Exported_Functions RST_CLK Exported Functions
  * @{
  */

void RST_CLK_DeInit(void);
void RST_CLK_WarmDeInit(void);

void RST_CLK_HSEconfig(uint32_t RST_CLK_HSE);
ErrorStatus RST_CLK_HSEstatus(void);

void RST_CLK_LSEconfig(uint32_t RST_CLK_LSE);
ErrorStatus RST_CLK_LSEstatus(void);

void RST_CLK_HSIcmd(FunctionalState NewState);
void RST_CLK_HSIadjust(uint32_t HSItrimValue);
ErrorStatus RST_CLK_HSIstatus(void);

void RST_CLK_LSIcmd(FunctionalState NewState);
void RST_CLK_LSIadjust(uint32_t LSItrimValue);
ErrorStatus RST_CLK_LSIstatus(void);

void RST_CLK_CPU_PLLconfig(uint32_t RST_CLK_CPU_PLLsource, uint32_t RST_CLK_CPU_PLLmul);
void RST_CLK_CPU_PLLuse(FunctionalState UsePLL);
void RST_CLK_CPU_PLLcmd(FunctionalState NewState);
ErrorStatus RST_CLK_CPU_PLLstatus(void);

void RST_CLK_CPUclkPrescaler(uint32_t CPUclkDivValue);
void RST_CLK_CPUclkSelection(uint32_t CPU_CLK);

void RST_CLK_PCLKPer1_C1_CLKSelection(uint32_t CLK_SRC);
void RST_CLK_PCLKPer1_C2_CLKSelection(uint32_t CLK_SRC);

void RST_CLK_ADCclkSelection(uint32_t ADC_CLK);
void RST_CLK_ADCclkPrescaler(uint32_t ADCclkDivValue);
void RST_CLK_ADCclkEnable(FunctionalState NewState);

void RST_CLK_HSIclkPrescaler(uint32_t HSIclkDivValue);
void RST_CLK_RTC_HSIclkEnable(FunctionalState NewState);

void RST_CLK_HSEclkPrescaler(uint32_t HSEclkDivValue);
void RST_CLK_RTC_HSEclkEnable(FunctionalState NewState);

void RST_CLK_PCLKcmd(uint32_t RST_CLK_PCLK, FunctionalState NewState);

void RST_CLK_ADCIUclkDeInit(void);
void RST_CLK_ADCIUclkSelection(uint32_t ADCIU_CLK_C1);
void RST_CLK_ADCIUclkPrescaler(uint32_t ADCIUclkDIVValue);
void RST_CLK_ADCIUclkCMD(FunctionalState NewState);

void RST_CLK_GetClocksFreq(RST_CLK_FreqTypeDef* RST_CLK_Clocks);

FlagStatus RST_CLK_GetFlagStatus(uint32_t RST_CLK_FLAG);

/** @} */ /* End of group RST_CLK_Exported_Functions */

/** @} */ /* End of group RST_CLK */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

#ifdef __cplusplus
} // extern "C" block end
#endif

#endif /* __MDR32F9Qx_RST_CLK_H */

/*
*
* END OF FILE MDR32F9Qx_rst_clk.h */

