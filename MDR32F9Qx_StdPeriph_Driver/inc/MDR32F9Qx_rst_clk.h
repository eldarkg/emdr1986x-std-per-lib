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
#include "MDR32F9Qx_config.h"
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
  uint32_t USB_CLK_Frequency;
  uint32_t ADC_CLK_Frequency;
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


#if defined  (USE_MDR1986VE3) || defined (USE_MDR1986VE1T)
/** @defgroup HSE2_configuration HSE2 configuration
 *  @{
 */

/**
  * @brief RST_CLK HSE2 (High Speed External 2 ) clock mode and source selection constants
  */

#define RST_CLK_HSE2_OFF						((uint32_t)0x00000000)
#define RST_CLK_HSE2_ON							((uint32_t)0x00000004)
#define RST_CLK_HSE2_Bypass						((uint32_t)0x00000008)

#define IS_RST_CLK_HSE2(HSE2)                  	(((HSE2) == RST_CLK_HSE2_OFF) || \
                                              	 ((HSE2) == RST_CLK_HSE2_ON)  || \
                                              	 ((HSE2) == RST_CLK_HSE2_Bypass))

/** @} */ /* End of group HSE2_configuration */

#endif /* #if defined  (USE_MDR1986VE3) || defined (USE_MDR1986VE1T) */

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

#define IS_RST_CLK_CPU_PLL_MUL(SRC)             ((SRC) < 16)

/** @} */ /* End of group CPU_PLL_clock_multiplier */


/** @defgroup USB_PLL_entry_clock_source USB PLL entry clock source
  * @{
  */

/**
  * @brief RST_CLK USB_PLL clock mode and source selection constants
  */

#define RST_CLK_USB_PLLsrcHSIdiv1           ((uint32_t)0x00000000)
#define RST_CLK_USB_PLLsrcHSIdiv2           ((uint32_t)0x00000001)
#define RST_CLK_USB_PLLsrcHSEdiv1           ((uint32_t)0x00000002)
#define RST_CLK_USB_PLLsrcHSEdiv2           ((uint32_t)0x00000003)

#define IS_RST_CLK_USB_PLL_SOURCE(SRC)      (((SRC) == RST_CLK_USB_PLLsrcHSIdiv1) ||\
                                             ((SRC) == RST_CLK_USB_PLLsrcHSIdiv2) ||\
                                             ((SRC) == RST_CLK_USB_PLLsrcHSEdiv1) ||\
                                             ((SRC) == RST_CLK_USB_PLLsrcHSEdiv2))

/** @} */ /* End of group USB_PLL_entry_clock_source */

/** @defgroup USB_PLL_clock_multiplier USB_PLL clock multiplier
  * @{
  */

/**
  * @brief RST_CLK USB_C1 clock PLL_USB_MUL multiplier constants
  */

#define RST_CLK_USB_PLLmul1                     ((uint32_t)0x00000000)
#define RST_CLK_USB_PLLmul2                     ((uint32_t)0x00000001)
#define RST_CLK_USB_PLLmul3                     ((uint32_t)0x00000002)
#define RST_CLK_USB_PLLmul4                     ((uint32_t)0x00000003)
#define RST_CLK_USB_PLLmul5                     ((uint32_t)0x00000004)
#define RST_CLK_USB_PLLmul6                     ((uint32_t)0x00000005)
#define RST_CLK_USB_PLLmul7                     ((uint32_t)0x00000006)
#define RST_CLK_USB_PLLmul8                     ((uint32_t)0x00000007)
#define RST_CLK_USB_PLLmul9                     ((uint32_t)0x00000008)
#define RST_CLK_USB_PLLmul10                    ((uint32_t)0x00000009)
#define RST_CLK_USB_PLLmul11                    ((uint32_t)0x0000000A)
#define RST_CLK_USB_PLLmul12                    ((uint32_t)0x0000000B)
#define RST_CLK_USB_PLLmul13                    ((uint32_t)0x0000000C)
#define RST_CLK_USB_PLLmul14                    ((uint32_t)0x0000000D)
#define RST_CLK_USB_PLLmul15                    ((uint32_t)0x0000000E)
#define RST_CLK_USB_PLLmul16                    ((uint32_t)0x0000000F)

#define IS_RST_CLK_USB_PLL_MUL(SRC)             ((SRC) < 16)

/** @} */ /* End of group USB_PLL_clock_multiplier */

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
#define RST_CLK_ADCclkCPU_C1                  ((uint32_t)0x00000020)
#define RST_CLK_ADCclkUSB_C1                  ((uint32_t)0x00000021)
#define RST_CLK_ADCclkCPU_C2                  ((uint32_t)0x00000022)
#define RST_CLK_ADCclkUSB_C2                  ((uint32_t)0x00000023)
#define RST_CLK_ADCclkLSE                     ((uint32_t)0x00000000)
#define RST_CLK_ADCclkLSI                     ((uint32_t)0x00000010)
#define RST_CLK_ADCclkHSI_C1                  ((uint32_t)0x00000030)

#define IS_RST_CLK_ADCclk(SRC)                (((SRC) == RST_CLK_ADCclkCPU_C1) || \
                                               ((SRC) == RST_CLK_ADCclkUSB_C1) || \
                                               ((SRC) == RST_CLK_ADCclkCPU_C2) || \
                                               ((SRC) == RST_CLK_ADCclkUSB_C2) || \
                                               ((SRC) == RST_CLK_ADCclkLSE)    || \
                                               ((SRC) == RST_CLK_ADCclkLSI)    || \
                                               ((SRC) == RST_CLK_ADCclkHSI_C1))
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

/** @defgroup AUC_MCO_CLOCK_source AUC clock source
 *  @{
 */

/**
 * @brief RST_CLK AUC_CLK selector constants
 */
#define RST_CLK_AUCclkHSI_C1						((uint32_t)0x00000000)
#define RST_CLK_AUCclkHSI_2_C1						((uint32_t)0x00010000)
#define RST_CLK_AUCclkHSE_C1						((uint32_t)0x00020000)
#define RST_CLK_AUCclkHSE_2_C1						((uint32_t)0x00030000)
#define RST_CLK_AUCclkPLLCPU						((uint32_t)0x00100000)
#define RST_CLK_AUCclkPLLUSB						((uint32_t)0x00200000)

#define IS_RST_CLK_AUCclk(SRC)						(((SRC) == RST_CLK_AUCclkHSI_C1)   || \
													 ((SRC) == RST_CLK_AUCclkHSI_2_C1) || \
													 ((SRC) == RST_CLK_AUCclkHSE_C1)   || \
													 ((SRC) == RST_CLK_AUCclkHSE_2_C1) || \
													 ((SRC) == RST_CLK_AUCclkPLLCPU)   || \
													 ((SRC) == RST_CLK_AUCclkPLLUSB))
/** @} */ /* End of group AUC_MCO_CLOCK_source */

/** @defgroup AUCclkDIV_divider AUC MCO divider
 *	@{
 */

 /**
  * @brief AUC_MCO_CLK AUC_CLK output clock AUC_CLK_DIV divider
  */
#define RST_CLK_AUCclkDIV1							((uint32_t)0x00000000)
#define RST_CLK_AUCclkDIV2							((uint32_t)0x08000000 | 0x00000000)
#define RST_CLK_AUCclkDIV4							((uint32_t)0x08000000 | 0x01000000)
#define RST_CLK_AUCclkDIV8							((uint32_t)0x08000000 | 0x02000000)
#define RST_CLK_AUCclkDIV16							((uint32_t)0x08000000 | 0x03000000)
#define RST_CLK_AUCclkDIV32							((uint32_t)0x08000000 | 0x04000000)
#define RST_CLK_AUCclkDIV64							((uint32_t)0x08000000 | 0x05000000)
#define RST_CLK_AUCclkDIV128						((uint32_t)0x08000000 | 0x06000000)
#define RST_CLK_AUCclkDIV256						((uint32_t)0x08000000 | 0x07000000)

#define IS_RST_CLK_AUCclkDIV(DIV)					(((DIV) == RST_CLK_AUCclkDIV1)   || \
													 ((DIV) == RST_CLK_AUCclkDIV2)   || \
													 ((DIV) == RST_CLK_AUCclkDIV4)   || \
													 ((DIV) == RST_CLK_AUCclkDIV8)   || \
													 ((DIV) == RST_CLK_AUCclkDIV16)  || \
													 ((DIV) == RST_CLK_AUCclkDIV32)  || \
													 ((DIV) == RST_CLK_AUCclkDIV64)  || \
													 ((DIV) == RST_CLK_AUCclkDIV128) || \
													 ((DIV) == RST_CLK_AUCclkDIV256))
/** @} */ /* End of group AUCclkDIV_divider */


/** @defgroup CLK_peripheral CLK peripheral
  * @{
  */

/**
  * @brief RST_CLK peripheral modules clock constants
  */

#define PCLK_BIT(BASE)              ((uint32_t)(1u << ((((uint32_t)BASE) >> 15) & 0x1F)))
#if defined USE_MDR1986VE3
	#define PCLK_BIT2(BASE)				((uint32_t)(1 << ((((uint32_t)BASE) >> 15) & 0x0F)))
#endif

#if defined ( USE_MDR1986VE9x )

	#define RST_CLK_PCLK_CAN1           PCLK_BIT(MDR_CAN1_BASE)
	#define RST_CLK_PCLK_CAN2           PCLK_BIT(MDR_CAN2_BASE)
	#define RST_CLK_PCLK_USB            PCLK_BIT(MDR_USB_BASE)
	#define RST_CLK_PCLK_EEPROM         PCLK_BIT(MDR_EEPROM_BASE)
	#define RST_CLK_PCLK_RST_CLK        PCLK_BIT(MDR_RST_CLK_BASE)
	#define RST_CLK_PCLK_DMA            PCLK_BIT(MDR_DMA_BASE)
	#define RST_CLK_PCLK_UART1          PCLK_BIT(MDR_UART1_BASE)
	#define RST_CLK_PCLK_UART2          PCLK_BIT(MDR_UART2_BASE)
	#define RST_CLK_PCLK_SSP1           PCLK_BIT(MDR_SSP1_BASE)
	#define RST_CLK_PCLK_09             PCLK_BIT(0x40048000)
	#define RST_CLK_PCLK_I2C            PCLK_BIT(MDR_I2C_BASE)
	#define RST_CLK_PCLK_POWER          PCLK_BIT(MDR_POWER_BASE)
	#define RST_CLK_PCLK_WWDG           PCLK_BIT(MDR_WWDG_BASE)
	#define RST_CLK_PCLK_IWDG           PCLK_BIT(MDR_IWDG_BASE)
	#define RST_CLK_PCLK_TIMER1         PCLK_BIT(MDR_TIMER1_BASE)
	#define RST_CLK_PCLK_TIMER2         PCLK_BIT(MDR_TIMER2_BASE)
	#define RST_CLK_PCLK_TIMER3         PCLK_BIT(MDR_TIMER3_BASE)
	#define RST_CLK_PCLK_ADC            PCLK_BIT(MDR_ADC_BASE)
	#define RST_CLK_PCLK_DAC            PCLK_BIT(MDR_DAC_BASE)
	#define RST_CLK_PCLK_COMP           PCLK_BIT(MDR_COMP_BASE)
	#define RST_CLK_PCLK_SSP2           PCLK_BIT(MDR_SSP2_BASE)
	#define RST_CLK_PCLK_PORTA          PCLK_BIT(MDR_PORTA_BASE)
	#define RST_CLK_PCLK_PORTB          PCLK_BIT(MDR_PORTB_BASE)
	#define RST_CLK_PCLK_PORTC          PCLK_BIT(MDR_PORTC_BASE)
	#define RST_CLK_PCLK_PORTD          PCLK_BIT(MDR_PORTD_BASE)
	#define RST_CLK_PCLK_PORTE          PCLK_BIT(MDR_PORTE_BASE)
	#define RST_CLK_PCLK_26             PCLK_BIT(0x400D0000)
	#define RST_CLK_PCLK_BKP            PCLK_BIT(MDR_BKP_BASE)
	#define RST_CLK_PCLK_28             PCLK_BIT(0x400E0000)
	#define RST_CLK_PCLK_PORTF          PCLK_BIT(MDR_PORTF_BASE)
	#define RST_CLK_PCLK_EBC            PCLK_BIT(MDR_EBC_BASE)
	#define RST_CLK_PCLK_31             PCLK_BIT(0x400F8000)

	#define IS_RST_CLK_PCLK(PCLK)       ((((PCLK) & RST_CLK_PCLK_09) == 0x00) && \
										 (((PCLK) & RST_CLK_PCLK_26) == 0x00) && \
										 (((PCLK) & RST_CLK_PCLK_28) == 0x00) && \
										 (((PCLK) & RST_CLK_PCLK_31) == 0x00))
#endif // #ifdef USE_MDR1986VE9x /* For cortex M3 */

#if  defined (USE_MDR1901VC1T) /* MDR1901VCT */

	#define RST_CLK_PCLK_SSP3           PCLK_BIT(MDR_SSP3_BASE)
	#define RST_CLK_PCLK_SSP4           PCLK_BIT(MDR_SSP4_BASE)
	#define RST_CLK_PCLK_USB            PCLK_BIT(MDR_USB_BASE)
	#define RST_CLK_PCLK_EEPROM         PCLK_BIT(MDR_EEPROM_BASE)
	#define RST_CLK_PCLK_RST_CLK        PCLK_BIT(MDR_RST_CLK_BASE)
	#define RST_CLK_PCLK_DMA            PCLK_BIT(MDR_DMA_BASE)
	#define RST_CLK_PCLK_UART1          PCLK_BIT(MDR_UART1_BASE)
	#define RST_CLK_PCLK_UART2          PCLK_BIT(MDR_UART2_BASE)
	#define RST_CLK_PCLK_SSP1           PCLK_BIT(MDR_SSP1_BASE)
	#define RST_CLK_PCLK_SDIO           PCLK_BIT(MDR_SDIO_BASE)
	#define RST_CLK_PCLK_I2C            PCLK_BIT(MDR_I2C_BASE)
	#define RST_CLK_PCLK_POWER          PCLK_BIT(MDR_POWER_BASE)
	#define RST_CLK_PCLK_WWDG           PCLK_BIT(MDR_WWDG_BASE)
	#define RST_CLK_PCLK_IWDG           PCLK_BIT(MDR_IWDG_BASE)
	#define RST_CLK_PCLK_TIMER1         PCLK_BIT(MDR_TIMER1_BASE)
	#define RST_CLK_PCLK_TIMER2         PCLK_BIT(MDR_TIMER2_BASE)
	#define RST_CLK_PCLK_TIMER3         PCLK_BIT(MDR_TIMER3_BASE)
	#define RST_CLK_PCLK_ADC            PCLK_BIT(MDR_ADC_BASE)
	#define RST_CLK_PCLK_DAC            PCLK_BIT(MDR_DAC_BASE)
	#define RST_CLK_PCLK_COMP           PCLK_BIT(MDR_COMP_BASE)
	#define RST_CLK_PCLK_SSP2           PCLK_BIT(MDR_SSP2_BASE)
	#define RST_CLK_PCLK_PORTA          PCLK_BIT(MDR_PORTA_BASE)
	#define RST_CLK_PCLK_PORTB          PCLK_BIT(MDR_PORTB_BASE)
	#define RST_CLK_PCLK_PORTC          PCLK_BIT(MDR_PORTC_BASE)
	#define RST_CLK_PCLK_PORTD          PCLK_BIT(MDR_PORTD_BASE)
	#define RST_CLK_PCLK_PORTE          PCLK_BIT(MDR_PORTE_BASE)
	#define RST_CLK_PCLK_UART3          PCLK_BIT(MDR_UART3_BASE)
	#define RST_CLK_PCLK_BKP            PCLK_BIT(MDR_BKP_BASE)
	#define RST_CLK_PCLK_AUDIO_IP       ((uint32_t)0x10000000)
	#define RST_CLK_PCLK_PORTF          PCLK_BIT(MDR_PORTF_BASE)
	#define RST_CLK_PCLK_EBC            PCLK_BIT(MDR_EBC_BASE)
	#define RST_CLK_PCLK_31             PCLK_BIT(0x400F8000)

	#define IS_RST_CLK_PCLK(PCLK)       (((PCLK) & RST_CLK_PCLK_31) == 0x00)
#endif // #ifdef USE_MDR1986VE9x /* For cortex MDR1901VC1T */


#if defined (USE_MDR1986VE1T)
	#define RST_CLK_PCLK_CAN1           PCLK_BIT(MDR_CAN1_BASE)
	#define RST_CLK_PCLK_CAN2           PCLK_BIT(MDR_CAN2_BASE)
	#define RST_CLK_PCLK_USB            PCLK_BIT(MDR_USB_BASE)
	#define RST_CLK_PCLK_EEPROM         PCLK_BIT(MDR_EEPROM_BASE)
	#define RST_CLK_PCLK_RST_CLK        PCLK_BIT(MDR_RST_CLK_BASE)
	#define RST_CLK_PCLK_DMA            PCLK_BIT(MDR_DMA_BASE)
	#define RST_CLK_PCLK_UART1          PCLK_BIT(MDR_UART1_BASE)
	#define RST_CLK_PCLK_UART2          PCLK_BIT(MDR_UART2_BASE)
	#define RST_CLK_PCLK_SSP1           PCLK_BIT(MDR_SSP1_BASE)
	#define RST_CLK_PCLK_MIL_STD_15531  PCLK_BIT(MDR_MIL_STD_15531_BASE)
	#define RST_CLK_PCLK_MIL_STD_15532  PCLK_BIT(MDR_MIL_STD_15532_BASE)
	#define RST_CLK_PCLK_POWER          PCLK_BIT(MDR_POWER_BASE)
	#define RST_CLK_PCLK_WWDG           PCLK_BIT(MDR_WWDG_BASE)
	#define RST_CLK_PCLK_IWDG           PCLK_BIT(MDR_IWDG_BASE)
	#define RST_CLK_PCLK_TIMER1         PCLK_BIT(MDR_TIMER1_BASE)
	#define RST_CLK_PCLK_TIMER2         PCLK_BIT(MDR_TIMER2_BASE)
	#define RST_CLK_PCLK_TIMER3         PCLK_BIT(MDR_TIMER3_BASE)
	#define RST_CLK_PCLK_ADC            PCLK_BIT(MDR_ADC_BASE)
	#define RST_CLK_PCLK_DAC            PCLK_BIT(MDR_DAC_BASE)
	#define RST_CLK_PCLK_TIMER4         PCLK_BIT(MDR_TIMER4_BASE)
	#define RST_CLK_PCLK_SSP2           PCLK_BIT(MDR_SSP2_BASE)
	#define RST_CLK_PCLK_PORTA          PCLK_BIT(MDR_PORTA_BASE)
	#define RST_CLK_PCLK_PORTB          PCLK_BIT(MDR_PORTB_BASE)
	#define RST_CLK_PCLK_PORTC          PCLK_BIT(MDR_PORTC_BASE)
	#define RST_CLK_PCLK_PORTD          PCLK_BIT(MDR_PORTD_BASE)
	#define RST_CLK_PCLK_PORTE          PCLK_BIT(MDR_PORTE_BASE)
	#define RST_CLK_PCLK_ARINC429R      PCLK_BIT(MDR_ARINC429R_BASE)
	#define RST_CLK_PCLK_BKP            PCLK_BIT(MDR_BKP_BASE)
	#define RST_CLK_PCLK_ARINC429T      PCLK_BIT(MDR_ARINC429T_BASE)
	#define RST_CLK_PCLK_PORTF          PCLK_BIT(MDR_PORTF_BASE)
	#define RST_CLK_PCLK_EBC            PCLK_BIT(MDR_EBC_BASE)
	#define RST_CLK_PCLK_SSP3           PCLK_BIT(MDR_SSP3_BASE)

#define IS_RST_CLK_PCLK(PCLK)			(1)
#endif /* #if defined (USE_MDR1986VE1T) */

#ifdef USE_MDR1986VE3 /* For Coxtex M1 */
	#define RST_CLK_PCLK_CAN1           PCLK_BIT(MDR_CAN1_BASE)
	#define RST_CLK_PCLK_CAN2           PCLK_BIT(MDR_CAN2_BASE)
	#define RST_CLK_PCLK_USB            PCLK_BIT(MDR_USB_BASE)
	#define RST_CLK_PCLK_EEPROM         PCLK_BIT(MDR_EEPROM_BASE)
	#define RST_CLK_PCLK_RST_CLK        PCLK_BIT(MDR_RST_CLK_BASE)
	#define RST_CLK_PCLK_DMA            PCLK_BIT(MDR_DMA_BASE)
	#define RST_CLK_PCLK_UART1          PCLK_BIT(MDR_UART1_BASE)
	#define RST_CLK_PCLK_UART2          PCLK_BIT(MDR_UART2_BASE)
	#define RST_CLK_PCLK_SSP1           PCLK_BIT(MDR_SSP1_BASE)
	#define RST_CLK_PCLK_MIL_STD_15531  PCLK_BIT(MDR_MIL_STD_15531_BASE)
	#define RST_CLK_PCLK_MIL_STD_15532  PCLK_BIT(MDR_MIL_STD_15532_BASE)
	#define RST_CLK_PCLK_POWER          PCLK_BIT(MDR_POWER_BASE)
	#define RST_CLK_PCLK_WWDG           PCLK_BIT(MDR_WWDG_BASE)
	#define RST_CLK_PCLK_IWDG           PCLK_BIT(MDR_IWDG_BASE)
	#define RST_CLK_PCLK_TIMER1         PCLK_BIT(MDR_TIMER1_BASE)
	#define RST_CLK_PCLK_TIMER2         PCLK_BIT(MDR_TIMER2_BASE)
	#define RST_CLK_PCLK_TIMER3         PCLK_BIT(MDR_TIMER3_BASE)
	#define RST_CLK_PCLK_ADC            PCLK_BIT(MDR_ADC_BASE)
	#define RST_CLK_PCLK_DAC            PCLK_BIT(MDR_DAC_BASE)
	#define RST_CLK_PCLK_TIMER4         PCLK_BIT(MDR_TIMER4_BASE)
	#define RST_CLK_PCLK_SSP2           PCLK_BIT(MDR_SSP2_BASE)
	#define RST_CLK_PCLK_PORTA          PCLK_BIT(MDR_PORTA_BASE)
	#define RST_CLK_PCLK_PORTB          PCLK_BIT(MDR_PORTB_BASE)
	#define RST_CLK_PCLK_PORTC          PCLK_BIT(MDR_PORTC_BASE)
	#define RST_CLK_PCLK_PORTD          PCLK_BIT(MDR_PORTD_BASE)
	#define RST_CLK_PCLK_PORTE          PCLK_BIT(MDR_PORTE_BASE)
	#define RST_CLK_PCLK_ARINC429R      PCLK_BIT(MDR_ARINC429R_BASE)
	#define RST_CLK_PCLK_BKP            PCLK_BIT(MDR_BKP_BASE)
	#define RST_CLK_PCLK_ARINC429T      PCLK_BIT(MDR_ARINC429T_BASE)
	#define RST_CLK_PCLK_PORTF          PCLK_BIT(MDR_PORTF_BASE)
	#define RST_CLK_PCLK_EBC            PCLK_BIT(MDR_EBC_BASE)
	#define RST_CLK_PCLK_SSP3           PCLK_BIT(MDR_SSP3_BASE)

	#define RST_CLK_PCLK2_AUDIO_IP		PCLK_BIT2(MDR_AUDIO_IP_BASE)
	#define RST_CLK_PCLK2_LED			PCLK_BIT2(MDR_LED_BASE)
	#define RST_CLK_PCLK2_KEYBOARD		PCLK_BIT2(MDR_KEYPAD_BASE)
	#define RST_CLK_PCLK2_PORTG			PCLK_BIT2(MDR_PORTG_BASE)
	#define RST_CLK_PCLK2_UART3			PCLK_BIT2(MDR_UART3_BASE)
	#define RST_CLK_PCLK2_UART4			PCLK_BIT2(MDR_UART4_BASE)
	#define RST_CLK_PCLK2_SSP4			PCLK_BIT2(MDR_SSP4_BASE)
	#define RST_CLK_PCLK2_PORTH			PCLK_BIT2(MDR_PORTH_BASE)
	#define RST_CLK_PCLK2_PORTI			PCLK_BIT2(MDR_PORTI_BASE)

	#define RST_CLK_PCLK2_MASK			(RST_CLK_PCLK2_AUDIO_IP | RST_CLK_PCLK2_KEYBOARD |\
										 RST_CLK_PCLK2_LED 		| RST_CLK_PCLK2_UART3 	 |\
										 RST_CLK_PCLK2_UART4	| RST_CLK_PCLK2_SSP4 	 |\
										 RST_CLK_PCLK2_PORTH 	| RST_CLK_PCLK2_PORTI | RST_CLK_PCLK2_PORTG)

	#define IS_RST_CLK_PCLK(PCLK)       (1)
	#define IS_RST_CLK_PCLK2(PCLK2)		(PLCK2 & (~RST_CLK_PCLK2_MASK) == 0)


#endif // #ifdef USE_MDR1986VE3 /* For Coxtex M1 */

/** @} */ /* End of group CLK_peripheral */

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
#define RST_CLK_FLAG_PLLUSBRDY                ((uint32_t)(0x20 |  0))
#define RST_CLK_FLAG_PLLDSPRDY                ((uint32_t)(0x20 |  3))

#define IS_RST_CLK_FLAG(FLAG)                 (((FLAG) == RST_CLK_FLAG_HSIRDY)    || \
                                               ((FLAG) == RST_CLK_FLAG_LSIRDY)    || \
                                               ((FLAG) == RST_CLK_FLAG_HSERDY)    || \
                                               ((FLAG) == RST_CLK_FLAG_HSE2RDY)	  || \
                                               ((FLAG) == RST_CLK_FLAG_PLLDSPRDY) || \
                                               ((FLAG) == RST_CLK_FLAG_LSERDY)    || \
                                               ((FLAG) == RST_CLK_FLAG_PLLCPURDY) || \
                                               ((FLAG) == RST_CLK_FLAG_PLLUSBRDY))

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

/** @defgroup DSP_C1_CLOCK DSP_C1_CLOCK
  * @{
  */

#define DSP_C1_CLOCK_HSI					(uint32_t)(0x0000000)
#define DSP_C1_CLOCK_HSI2					(uint32_t)(0x0000001)
#define DSP_C1_CLOCK_HSE					(uint32_t)(0x0000002)
#define DSP_C1_CLOCK_HSE2					(uint32_t)(0x0000003)

#define IS_DSP_C1_CLOCK(CLOCK)				((CLOCK == DSP_C1_CLOCK_HSI)  ||\
											 (CLOCK == DSP_C1_CLOCK_HSI2) ||\
											 (CLOCK == DSP_C1_CLOCK_HSE)  ||\
											 (CLOCK == DSP_C1_CLOCK_HSE2))

/** @} */ /* End of group DSP_C1_CLOCK */

/** @defgroup DSP_PLL_MUL DSP_PLL multiplier
  * @{
  */

#define DSP_PLL_MUL1						(uint32_t)(0x00000000)
#define DSP_PLL_MUL2						(uint32_t)(0x00000001)
#define DSP_PLL_MUL3						(uint32_t)(0x00000002)
#define DSP_PLL_MUL4						(uint32_t)(0x00000003)
#define DSP_PLL_MUL5						(uint32_t)(0x00000004)
#define DSP_PLL_MUL6						(uint32_t)(0x00000005)
#define DSP_PLL_MUL7						(uint32_t)(0x00000006)
#define DSP_PLL_MUL8						(uint32_t)(0x00000007)
#define DSP_PLL_MUL9						(uint32_t)(0x00000008)
#define DSP_PLL_MUL10 						(uint32_t)(0x00000009)
#define DSP_PLL_MUL11						(uint32_t)(0x0000000A)
#define DSP_PLL_MUL12						(uint32_t)(0x0000000B)
#define DSP_PLL_MUL13						(uint32_t)(0x0000000C)
#define DSP_PLL_MUL14						(uint32_t)(0x0000000D)
#define DSP_PLL_MUL15						(uint32_t)(0x0000000E)
#define DSP_PLL_MUL16						(uint32_t)(0x0000000F)

#define	IS_DSP_PLL_MULL(PLL_MUL)			((PLL_MUL >= DSP_PLL_MUL1) &&\
										    (PLL_MUL <= DSP_PLL_MUL15))

/** @} */ /* End of group DSP_PLL_MUL */

/** @defgroup DSP_Prescalere DSP_Prescalere
  * @{
  */

#define DSP_PRESCALER1						(uint32_t)(0x00000000)
#define DSP_PRESCALER2						(uint32_t)(0x00000001)

#define IS_DSP_PRESCALER(PRESCALER)			((PRESCALER == DSP_PRESCALER1) ||\
											 (PRESCALER == DSP_PRESCALER2))

/** @} */ /* End of group DSP_Prescalere */

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

void RST_CLK_USB_PLLconfig(uint32_t RST_CLK_USB_PLLsource, uint32_t RST_CLK_USB_PLLmul);
void RST_CLK_USB_PLLuse(FunctionalState UsePLL);
void RST_CLK_USB_PLLcmd(FunctionalState NewState);
ErrorStatus RST_CLK_USB_PLLstatus(void);

void RST_CLK_USBclkPrescaler(FunctionalState NewState);
void RST_CLK_USBclkEnable(FunctionalState NewState);

void RST_CLK_ADCclkSelection(uint32_t ADC_CLK);
void RST_CLK_ADCclkPrescaler(uint32_t ADCclkDivValue);
void RST_CLK_ADCclkEnable(FunctionalState NewState);

void RST_CLK_HSIclkPrescaler(uint32_t HSIclkDivValue);
void RST_CLK_RTC_HSIclkEnable(FunctionalState NewState);

void RST_CLK_HSEclkPrescaler(uint32_t HSEclkDivValue);
void RST_CLK_RTC_HSEclkEnable(FunctionalState NewState);

void RST_CLK_PCLKcmd(uint32_t RST_CLK_PCLK, FunctionalState NewState);
#if defined (USE_MDR1986VE3)
	void RST_CLK_PCLK2cmd ( uint32_t RST_CLK_PCLK2, FunctionalState NewState);
#endif
#if defined (USE_MDR1986VE3) || defined (USE_MDR1901VC1T)
	void RST_CLK_AUCclkDeInit(void);
	void RST_CLK_AUCclkSelection(uint32_t AUC_CLK);
	void RST_CLK_AUCclkPrescaler(uint32_t AUCclkDIVValue);
	void RST_CLK_AUCclkCMD(FunctionalState NewState);
#endif
void RST_CLK_GetClocksFreq(RST_CLK_FreqTypeDef* RST_CLK_Clocks);

FlagStatus RST_CLK_GetFlagStatus(uint32_t RST_CLK_FLAG);

#if defined (USE_MDR1986VE3) || defined (USE_MDR1986VE1T)
	void RST_CLK_HSE2config(uint32_t RST_CLK_HSE2);
	ErrorStatus RST_CLK_HSE2status(void);
#endif

#if defined (USE_MDR1901VC1T)
	void RST_CLK_DSP_Selection(uint32_t DSP_CLOCK);
	void RST_CLK_DSPPLLConfig(uint32_t PLLMul);
	void RST_CLK_DSPPLL_CMD(FunctionalState NewState);
	ErrorStatus RST_CLK_DSP_PLLStatus(void);
	void RST_CLK_DSP_PLLUse(FunctionalState UsePLL);
	void RST_CLK_DSPPrescaler(uint32_t DSP_Prescaler);
	void RST_CLK_DSPCmd(FunctionalState NewState);
#endif

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
