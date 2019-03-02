/**
  * FILE MDR32F9Qx_adc.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MDR32F9QX_ADC_H
#define __MDR32F9QX_ADC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_config.h"
#include "MDR32F9Qx_lib.h"

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
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

	uint32_t ADC_StartDelay; 			/*!< Specifies the ADC1 conversion start delay.
	 	 	 	 	 	 	 	 	 	 	 This parameter can be a number between 0 and 15. */

	uint32_t ADC_TempSensor; 			/*!< Enables or disables the temperature sensor and internal voltage reference.
	 	 	 	 	 	 	 	 	 	 	 This parameter can be a value of @ref ADC_Temp_Sensor */

	uint32_t ADC_TempSensorAmplifier; 	/*!< Enables or disables the temperature sensor.
	 	 	 	 	 	 	 	 	 	 	 This parameter can be a value of @ref ADC_Temp_Sensor_Amplifier */

	uint32_t ADC_TempSensorConversion; 	/*!< Enables or disables the temperature sensor conversion.
	 	 	 	 	 	 	 	 	 	 	 This parameter can be a value of @ref ADC_Temp_Sensor_Conversion */

	uint32_t ADC_IntVRefConversion; 	/*!< Enables or disables the internal voltage reference conversion.
	 	 	 	 	 	 	 	 	 	 	 This parameter can be a value of @ref ADC_Int_VRef_Conversion */

	uint32_t ADC_IntVRefTrimming; 		/*!< Configures the internal voltage reference trimming.
	 	 	 	 	 	 	 	 	 	 	 This parameter can be a number between 0 and 7. */

	uint32_t ADC_IntVRefAmplifier;		/*!< Enable or disable the internal voltage reference amplifier.
											 This parameter can be a value of @ref ADC_Int_VRef_Amlifier */

} ADC_InitTypeDef;

/**
  * @brief  ADC1, ADC2 Init structure definition
  */

typedef struct
{
  uint32_t ADC_ClockSource;             /*!< Specifies the ADCx clock source.
                                             This parameter can be a value of @ref ADCx_Clock_Source */

  uint32_t ADC_SamplingMode;            /*!< Specifies the ADCx sampling mode.
                                             This parameter can be a value of @ref ADCx_Sampling_Mode */

  uint32_t ADC_ChannelSwitching;        /*!< Enables or disables the ADCx channel switching.
                                             This parameter can be a value of @ref ADCx_Channel_Switching */

  uint32_t ADC_ChannelNumber;           /*!< Specifies the ADCx channel number.
                                             This parameter can be a value of @ref ADCx_Channel_Number */

  uint32_t ADC_Channels;                /*!< Specifies the ADCx channels mask.
                                             This parameter can be a value of @ref ADCx_Channels */

  uint32_t ADC_LevelControl;            /*!< Enables or disables the ADCx level control.
                                             This parameter can be a value of @ref ADCx_Level_Control */

  uint16_t ADC_LowLevel;                /*!< Specifies the ADCx value low level.
                                             This parameter can be a number between 0x0000 and 0x07FF. */

  uint16_t ADC_HighLevel;                /*!< Specifies the ADCx value high level.
                                             This parameter can be a number between 0x0000 and 0x07FF. */

  uint32_t ADC_VRefSource;              /*!< Specifies the ADCx voltage reference source (internal or external).
                                             This parameter can be a value of @ref ADCx_VRef_Source */

  uint32_t ADC_IntVRefSource;           /*!< Specifies the ADCx internal voltage reference source (inexact or exact).
                                             This parameter can be a value of @ref ADCx_Int_VRef_Source */

  uint32_t ADC_Prescaler;               /*!< Specifies the ADCx Prescaler configuration.
                                             This parameter can be a value of @ref ADCx_Prescaler */

  uint32_t ADC_DelayGo;                 /*!< Specifies the ADCx start conversion delay at sequential conversion mode.
                                             This parameter can be a number between 0 and 7. */
}ADCx_InitTypeDef;

/** @} */ /* End of group ADC_Exported_Types */

/** @defgroup ADC_Exported_Constants ADC Exported Constants
  * @{
  */

/** @defgroup ADC_Start_Delay ADC Start Delay
  * @{
  */

#define IS_ADC_START_DELAY_VALUE(VALUE) ((VALUE) <= 15)

/** @} */ /* End of group ADC_Start_Delay */

/** @defgroup ADC_Temp_Sensor ADC Temperature Sensor configuration
  * @{
  */

#define ADC_TEMP_SENSOR_Disable               (((uint32_t)0x0) << ADC1_CFG_TS_EN_Pos)       /*!< Disables Temperature Sensor. */
#define ADC_TEMP_SENSOR_Enable                (((uint32_t)0x1) << ADC1_CFG_TS_EN_Pos)       /*!< Enables Temperature Sensor. */

#define IS_ADC_TEMP_SENSOR_CONFIG(CONFIG) (((CONFIG) == ADC_TEMP_SENSOR_Disable) || \
                                           ((CONFIG) == ADC_TEMP_SENSOR_Enable ))

/** @} */ /* End of group ADC_Temp_Sensor */

/** @defgroup ADC_Temp_Sensor_Amplifier ADC Temperature Sensor Amplifier configuration
  * @{
  */

#define ADC_TEMP_SENSOR_AMPLIFIER_Disable     (((uint32_t)0x0) << ADC1_CFG_TS_BUF_EN_Pos)   /*!< Disables Temperature Sensor Amplifier. */
#define ADC_TEMP_SENSOR_AMPLIFIER_Enable      (((uint32_t)0x1) << ADC1_CFG_TS_BUF_EN_Pos)   /*!< Enables Temperature Sensor Amplifier. */

#define IS_ADC_TEMP_SENSOR_AMP_CONFIG(CONFIG) (((CONFIG) == ADC_TEMP_SENSOR_AMPLIFIER_Disable) || \
                                               ((CONFIG) == ADC_TEMP_SENSOR_AMPLIFIER_Enable ))

/** @} */ /* End of group ADC_Temp_Sensor_Amplifier */

/** @defgroup ADC_Temp_Sensor_Conversion ADC Temperature Sensor Conversion configuration
  * @{
  */

#define ADC_TEMP_SENSOR_CONVERSION_Disable    (((uint32_t)0x0) << ADC1_CFG_SEL_TS_Pos)      /*!< Disables Temperature Sensor Conversion. */
#define ADC_TEMP_SENSOR_CONVERSION_Enable     (((uint32_t)0x1) << ADC1_CFG_SEL_TS_Pos)      /*!< Enables Temperature Sensor Conversion. */

#define IS_ADC_TEMP_SENSOR_CONVERSION_CONFIG(CONFIG) (((CONFIG) == ADC_TEMP_SENSOR_CONVERSION_Disable) || \
                                                      ((CONFIG) == ADC_TEMP_SENSOR_CONVERSION_Enable ))

/** @} */ /* End of group ADC_Temp_Sensor_Conversion */

/** @defgroup ADC_Int_VRef_Conversion ADC Internal Voltage Reference Conversion configuration
  * @{
  */

#define ADC_VREF_CONVERSION_Disable           (((uint32_t)0x0) << ADC1_CFG_SEL_VREF_Pos)    /*!< Disables Internal Voltage Reference Conversion. */
#define ADC_VREF_CONVERSION_Enable            (((uint32_t)0x1) << ADC1_CFG_SEL_VREF_Pos)    /*!< Enables Internal Voltage Reference Conversion. */

#define IS_ADC_VREF_CONVERSION_CONFIG(CONFIG) (((CONFIG) == ADC_VREF_CONVERSION_Disable) || \
                                               ((CONFIG) == ADC_VREF_CONVERSION_Enable ))

/** @} */ /* End of group ADC_Int_VRef_Conversion */

/** @defgroup ADC_Int_VRef_Trimming ADC Internal Voltage Reference Trimming
  * @{
  */

#define IS_ADC_VREF_TRIMMING_VALUE(VALUE) ((VALUE) <= 0x1F)

/** @} */ /* End of group ADC_Int_VRef_Trimming */

/** @defgroup ADCx_Clock_Source ADCx Clock Source configuration
  * @{
  */

#define ADC_CLOCK_SOURCE_CPU                  (((uint32_t)0x0) << ADC1_CFG_REG_CLKS_Pos)    /*!< Selects CPU_CLK as ADC clock. */
#define ADC_CLOCK_SOURCE_ADC                  (((uint32_t)0x1) << ADC1_CFG_REG_CLKS_Pos)    /*!< Selects ADC_CLK as ADC clock. */

#define IS_ADC_CLOCK_SOURCE_CONFIG(CONFIG) (((CONFIG) == ADC_CLOCK_SOURCE_ADC) || \
                                            ((CONFIG) == ADC_CLOCK_SOURCE_CPU))

/** @} */ /* End of group ADCx_Clock_Source */

/** @defgroup ADCx_Sampling_Mode ADC Sampling Mode configuration
  * @{
  */

#define ADC_SAMPLING_MODE_SINGLE_CONV         (((uint32_t)0x0) << ADC1_CFG_REG_SAMPLE_Pos)  /*!< Selects ADC single mode operation. */
#define ADC_SAMPLING_MODE_CICLIC_CONV         (((uint32_t)0x1) << ADC1_CFG_REG_SAMPLE_Pos)  /*!< Selects ADC ciclic mode operation. */

#define IS_ADC_SAMPLING_MODE_CONFIG(CONFIG) (((CONFIG) == ADC_SAMPLING_MODE_SINGLE_CONV) || \
                                             ((CONFIG) == ADC_SAMPLING_MODE_CICLIC_CONV))

/** @} */ /* End of group ADCx_Sampling_Mode */

/** @defgroup ADCx_Channel_Switching ADC Channel Switching configuration
  * @{
  */

#define ADC_CH_SWITCHING_Disable              (((uint32_t)0x0) << ADC1_CFG_REG_CHCH_Pos)    /*!< Disables Channel Switching. */
#define ADC_CH_SWITCHING_Enable               (((uint32_t)0x1) << ADC1_CFG_REG_CHCH_Pos)    /*!< Enables Channel Switching. */

#define IS_ADC_CH_SWITCHING_CONFIG(CONFIG) (((CONFIG) == ADC_CH_SWITCHING_Disable) || \
                                            ((CONFIG) == ADC_CH_SWITCHING_Enable ))

/** @} */ /* End of group ADCx_Channel_Switching */


/** @defgroup ADCx_Channel_Number ADC Channel Number
  * @{
  */

#define ADC_CH_ADC0                           ((uint32_t)0x00) /*!< Specifies the ADC channel 0.  */
#define ADC_CH_ADC1                           ((uint32_t)0x01) /*!< Specifies the ADC channel 1.  */
#define ADC_CH_ADC2                           ((uint32_t)0x02) /*!< Specifies the ADC channel 2.  */
#define ADC_CH_ADC3                           ((uint32_t)0x03) /*!< Specifies the ADC channel 3.  */
#define ADC_CH_ADC4                           ((uint32_t)0x04) /*!< Specifies the ADC channel 4.  */
#define ADC_CH_ADC5                           ((uint32_t)0x05) /*!< Specifies the ADC channel 5.  */
#define ADC_CH_ADC6                           ((uint32_t)0x06) /*!< Specifies the ADC channel 6.  */
#define ADC_CH_ADC7                           ((uint32_t)0x07) /*!< Specifies the ADC channel 7.  */
#define ADC_CH_ADC8                           ((uint32_t)0x08) /*!< Specifies the ADC channel 8.  */
#define ADC_CH_ADC9                           ((uint32_t)0x09) /*!< Specifies the ADC channel 9.  */
#define ADC_CH_ADC10                          ((uint32_t)0x0A) /*!< Specifies the ADC channel 10. */
#define ADC_CH_ADC11                          ((uint32_t)0x0B) /*!< Specifies the ADC channel 11. */
#define ADC_CH_ADC12                          ((uint32_t)0x0C) /*!< Specifies the ADC channel 12. */
#define ADC_CH_ADC13                          ((uint32_t)0x0D) /*!< Specifies the ADC channel 13. */
#define ADC_CH_ADC14                          ((uint32_t)0x0E) /*!< Specifies the ADC channel 14. */
#define ADC_CH_ADC15                          ((uint32_t)0x0F) /*!< Specifies the ADC channel 15. */
#define ADC_CH_INT_VREF                       ((uint32_t)0x1E) /*!< Specifies the ADC channel 30 (Internal VRef). */
#define ADC_CH_TEMP_SENSOR                    ((uint32_t)0x1F) /*!< Specifies the ADC channel 31 (Temperature Sensor). */

#define IS_ADC_CH_NUM(NUM)  (((NUM) == ADC_CH_ADC0       ) || \
                             ((NUM) == ADC_CH_ADC1       ) || \
                             ((NUM) == ADC_CH_ADC2       ) || \
                             ((NUM) == ADC_CH_ADC3       ) || \
                             ((NUM) == ADC_CH_ADC4       ) || \
                             ((NUM) == ADC_CH_ADC5       ) || \
                             ((NUM) == ADC_CH_ADC6       ) || \
                             ((NUM) == ADC_CH_ADC7       ) || \
                             ((NUM) == ADC_CH_ADC8       ) || \
                             ((NUM) == ADC_CH_ADC9       ) || \
                             ((NUM) == ADC_CH_ADC10      ) || \
                             ((NUM) == ADC_CH_ADC11      ) || \
                             ((NUM) == ADC_CH_ADC12      ) || \
                             ((NUM) == ADC_CH_ADC13      ) || \
                             ((NUM) == ADC_CH_ADC14      ) || \
                             ((NUM) == ADC_CH_ADC15      ))

#define IS_ADC1_CH_NUM(NUM)  ((IS_ADC_CH_NUM(NUM))        || \
                             ((NUM) == ADC_CH_INT_VREF   ) || \
                             ((NUM) == ADC_CH_TEMP_SENSOR))

/** @} */ /* End of group ADCx_Channel_Number */

/** @defgroup ADCx_Channels ADC Channels
  * @{
  */

#define ADC_CH_ADC0_MSK                       (((uint32_t)0x1) << ADC_CH_ADC0       ) /*!< Selects the ADC channel 0.  */
#define ADC_CH_ADC1_MSK                       (((uint32_t)0x1) << ADC_CH_ADC1       ) /*!< Selects the ADC channel 1.  */
#define ADC_CH_ADC2_MSK                       (((uint32_t)0x1) << ADC_CH_ADC2       ) /*!< Selects the ADC channel 2.  */
#define ADC_CH_ADC3_MSK                       (((uint32_t)0x1) << ADC_CH_ADC3       ) /*!< Selects the ADC channel 3.  */
#define ADC_CH_ADC4_MSK                       (((uint32_t)0x1) << ADC_CH_ADC4       ) /*!< Selects the ADC channel 4.  */
#define ADC_CH_ADC5_MSK                       (((uint32_t)0x1) << ADC_CH_ADC5       ) /*!< Selects the ADC channel 5.  */
#define ADC_CH_ADC6_MSK                       (((uint32_t)0x1) << ADC_CH_ADC6       ) /*!< Selects the ADC channel 6.  */
#define ADC_CH_ADC7_MSK                       (((uint32_t)0x1) << ADC_CH_ADC7       ) /*!< Selects the ADC channel 7.  */
#define ADC_CH_ADC8_MSK                       (((uint32_t)0x1) << ADC_CH_ADC8       ) /*!< Selects the ADC channel 8.  */
#define ADC_CH_ADC9_MSK                       (((uint32_t)0x1) << ADC_CH_ADC9       ) /*!< Selects the ADC channel 9.  */
#define ADC_CH_ADC10_MSK                      (((uint32_t)0x1) << ADC_CH_ADC10      ) /*!< Selects the ADC channel 10. */
#define ADC_CH_ADC11_MSK                      (((uint32_t)0x1) << ADC_CH_ADC11      ) /*!< Selects the ADC channel 11. */
#define ADC_CH_ADC12_MSK                      (((uint32_t)0x1) << ADC_CH_ADC12      ) /*!< Selects the ADC channel 12. */
#define ADC_CH_ADC13_MSK                      (((uint32_t)0x1) << ADC_CH_ADC13      ) /*!< Selects the ADC channel 13. */
#define ADC_CH_ADC14_MSK                      (((uint32_t)0x1) << ADC_CH_ADC14      ) /*!< Selects the ADC channel 14. */
#define ADC_CH_ADC15_MSK                      (((uint32_t)0x1) << ADC_CH_ADC15      ) /*!< Selects the ADC channel 15. */
#define ADC_CH_INT_VREF_MSK                   (((uint32_t)0x1) << ADC_CH_INT_VREF   ) /*!< Selects the ADC channel 30 (Internal VRef). */
#define ADC_CH_TEMP_SENSOR_MSK                (((uint32_t)0x1) << ADC_CH_TEMP_SENSOR) /*!< Selects the ADC channel 31 (Temperature Sensor). */

#define ADC_ALL_CH_MSK          (ADC_CH_ADC0_MSK  | \
                                 ADC_CH_ADC1_MSK  | \
                                 ADC_CH_ADC2_MSK  | \
                                 ADC_CH_ADC3_MSK  | \
                                 ADC_CH_ADC4_MSK  | \
                                 ADC_CH_ADC5_MSK  | \
                                 ADC_CH_ADC6_MSK  | \
                                 ADC_CH_ADC7_MSK  | \
                                 ADC_CH_ADC8_MSK  | \
                                 ADC_CH_ADC9_MSK  | \
                                 ADC_CH_ADC10_MSK | \
                                 ADC_CH_ADC11_MSK | \
                                 ADC_CH_ADC12_MSK | \
                                 ADC_CH_ADC13_MSK | \
                                 ADC_CH_ADC14_MSK | \
                                 ADC_CH_ADC15_MSK)

#define IS_ADC_CH_MASK(MASK)  (((MASK) & ~ADC_ALL_CH_MSK) == 0)

#define ADC1_ALL_CH_MSK          (ADC_ALL_CH_MSK    | \
                                 ADC_CH_INT_VREF_MSK | \
                                 ADC_CH_TEMP_SENSOR_MSK)

#define IS_ADC1_CH_MASK(MASK) ((((MASK) & ~ADC_ALL_CH_MSK) == 0) || \
                               ((MASK) == ADC_CH_INT_VREF_MSK)    || \
                               ((MASK) == ADC_CH_TEMP_SENSOR_MSK))

/** @} */ /* End of group ADCx_Channels */

/** @defgroup ADCx_Level_Control ADC Level Control configuration
  * @{
  */

#define ADC_LEVEL_CONTROL_Disable             (((uint32_t)0x0) << ADC1_CFG_REG_RNGC_Pos)    /*!< Disables Level Control. */
#define ADC_LEVEL_CONTROL_Enable              (((uint32_t)0x1) << ADC1_CFG_REG_RNGC_Pos)    /*!< Enables Level Control. */

#define IS_ADC_LEVEL_CONTROL_CONFIG(CONFIG) (((CONFIG) == ADC_LEVEL_CONTROL_Disable) || \
                                             ((CONFIG) == ADC_LEVEL_CONTROL_Enable ))

#define ADC_VALUE_MAX                        (0x0FFF)
#define IS_ADC_VALUE(VALUE)                  ((VALUE) <= ADC_VALUE_MAX)

/** @} */ /* End of group ADCx_Level_Control */

/** @defgroup ADCx_VRef_Source ADC Voltage Reference Source configuration
  * @{
  */

#define ADC_VREF_SOURCE_INTERNAL              (((uint32_t)0x0) << ADC1_CFG_M_REF_Pos)       /*!< Selects Internal Voltage Reference. */
#define ADC_VREF_SOURCE_EXTERNAL              (((uint32_t)0x1) << ADC1_CFG_M_REF_Pos)       /*!< Selects External Voltage Reference. */

#define IS_ADC_VREF_SOURCE_CONFIG(CONFIG) (((CONFIG) == ADC_VREF_SOURCE_INTERNAL) || \
                                           ((CONFIG) == ADC_VREF_SOURCE_EXTERNAL))

/** @} */ /* End of group ADCx_VRef_Source */

/** @defgroup ADCx_Int_VRef_Source ADC Internal Voltage Reference Source configuration
  * @{
  */

#define ADC_INT_VREF_SOURCE_INEXACT           ((uint32_t)0x0)   /*!< Selects inexact Internal Voltage Reference. */
#define ADC_INT_VREF_SOURCE_EXACT             ((uint32_t)0x1)   /*!< Selects exact Internal Voltage Reference (from Temperature Sensor). */

#define IS_ADC_INT_VREF_SOURCE_CONFIG(CONFIG) (((CONFIG) == ADC_INT_VREF_SOURCE_INEXACT) || \
                                               ((CONFIG) == ADC_INT_VREF_SOURCE_EXACT  ))

/** @} */ /* End of group ADCx_VRef_Source */

/** @defgroup ADCx_Prescaler ADC Clock Prescaler
  * @{
  */

#define ADC_CLK_div_None                      (((uint32_t)0x0) << ADC1_CFG_REG_DIVCLK_Pos) /*!< The input ADC clock devides by 1.     */
#define ADC_CLK_div_2                         (((uint32_t)0x1) << ADC1_CFG_REG_DIVCLK_Pos) /*!< The input ADC clock devides by 2.     */
#define ADC_CLK_div_4                         (((uint32_t)0x2) << ADC1_CFG_REG_DIVCLK_Pos) /*!< The input ADC clock devides by 4.     */
#define ADC_CLK_div_8                         (((uint32_t)0x3) << ADC1_CFG_REG_DIVCLK_Pos) /*!< The input ADC clock devides by 8.     */
#define ADC_CLK_div_16                        (((uint32_t)0x4) << ADC1_CFG_REG_DIVCLK_Pos) /*!< The input ADC clock devides by 16.    */
#define ADC_CLK_div_32                        (((uint32_t)0x5) << ADC1_CFG_REG_DIVCLK_Pos) /*!< The input ADC clock devides by 32.    */
#define ADC_CLK_div_64                        (((uint32_t)0x6) << ADC1_CFG_REG_DIVCLK_Pos) /*!< The input ADC clock devides by 64.    */
#define ADC_CLK_div_128                       (((uint32_t)0x7) << ADC1_CFG_REG_DIVCLK_Pos) /*!< The input ADC clock devides by 128.   */
#define ADC_CLK_div_256                       (((uint32_t)0x8) << ADC1_CFG_REG_DIVCLK_Pos) /*!< The input ADC clock devides by 256.   */
#define ADC_CLK_div_512                       (((uint32_t)0x9) << ADC1_CFG_REG_DIVCLK_Pos) /*!< The input ADC clock devides by 512.   */
#define ADC_CLK_div_1024                      (((uint32_t)0xA) << ADC1_CFG_REG_DIVCLK_Pos) /*!< The input ADC clock devides by 1024.  */
#define ADC_CLK_div_2048                      (((uint32_t)0xB) << ADC1_CFG_REG_DIVCLK_Pos) /*!< The input ADC clock devides by 2048.  */

#define IS_ADC_CLK_div_VALUE(VALUE) (((VALUE) == ADC_CLK_div_None ) || \
                                     ((VALUE) == ADC_CLK_div_2    ) || \
                                     ((VALUE) == ADC_CLK_div_4    ) || \
                                     ((VALUE) == ADC_CLK_div_8    ) || \
                                     ((VALUE) == ADC_CLK_div_16   ) || \
                                     ((VALUE) == ADC_CLK_div_32   ) || \
                                     ((VALUE) == ADC_CLK_div_64   ) || \
                                     ((VALUE) == ADC_CLK_div_128  ) || \
                                     ((VALUE) == ADC_CLK_div_256  ) || \
                                     ((VALUE) == ADC_CLK_div_512  ) || \
                                     ((VALUE) == ADC_CLK_div_1024 ) || \
                                     ((VALUE) == ADC_CLK_div_2048 ))

/** @} */ /* End of group ADCx_Prescaler */

/** @defgroup ADCx_Delay_Go ADCx start conversion delay
  * @{
  */

#define IS_ADC_DELAY_GO_VALUE(VALUE) ((VALUE) <= 7)

/** @} */ /* End of group ADCx_Level_Control */

/** @defgroup ADC_Flags ADC Flags
  * @{
  */

#define ADCx_FLAG_OVERWRITE                   (((uint32_t)0x1) << ADC1_STATUS_FLG_REG_OVERWRITE_Pos)
#define ADCx_FLAG_OUT_OF_RANGE                (((uint32_t)0x1) << ADC1_STATUS_FLG_REG_AWOIFEN_Pos)
#define ADCx_FLAG_END_OF_CONVERSION           (((uint32_t)0x1) << ADC1_STATUS_FLG_REG_EOCIF_Pos)

#define IS_ADCx_STATUS_FLAG(FLAG) (((FLAG) == ADCx_FLAG_OVERWRITE        ) || \
                                   ((FLAG) == ADCx_FLAG_OUT_OF_RANGE     ) || \
                                   ((FLAG) == ADCx_FLAG_END_OF_CONVERSION))

#define ADC1_FLAG_OVERWRITE                   (ADCx_FLAG_OVERWRITE         <<  0)
#define ADC1_FLAG_OUT_OF_RANGE                (ADCx_FLAG_OUT_OF_RANGE      <<  0)
#define ADC1_FLAG_END_OF_CONVERSION           (ADCx_FLAG_END_OF_CONVERSION <<  0)

#define IS_ADC_STATUS_FLAG(FLAG) (((FLAG) == ADC1_FLAG_OVERWRITE        ) || \
                                  ((FLAG) == ADC1_FLAG_OUT_OF_RANGE     ) || \
                                  ((FLAG) == ADC1_FLAG_END_OF_CONVERSION))

/** @} */ /* End of group ADC_Flags */

/** @defgroup ADC_Interrupt_definition ADC Interrupt definition
  * @{
  */

#define ADCx_IT_OUT_OF_RANGE               (((uint32_t)0x1) << ADC1_STATUS_FLG_REG_AWOIFEN_Pos)
#define ADCx_IT_END_OF_CONVERSION          (((uint32_t)0x1) << ADC1_STATUS_FLG_REG_EOCIF_Pos)

#define ADCx_IT_MASK						(ADCx_IT_OUT_OF_RANGE | ADCx_IT_END_OF_CONVERSION)

#define IS_ADCx_CONFIG_IT(IT)              (((IT) & ADCx_IT_MASK) == IT)

#define ADC1_IT_OUT_OF_RANGE               (ADCx_IT_OUT_OF_RANGE      <<  0)
#define ADC1_IT_END_OF_CONVERSION          (ADCx_IT_END_OF_CONVERSION <<  0)

#define IS_ADC_CONFIG_IT(IT)              (((IT) == ADC1_IT_OUT_OF_RANGE     ) || \
                                           ((IT) == ADC1_IT_END_OF_CONVERSION))
/** @} */ /* End of group ADC_Interrupt_definition */


/** @defgroup ADC_Int_VRef_Amplifier ADC Int_VRef Amplifier
  * @{
  */

#define ADC_INT_VREF_AMPLIFIER_Enable			((uint32_t)(1 << ADC1_TRIM_SEL_VREF_BUF_Pos))
#define ADC_INT_VREF_AMPLIFIER_Disable			((uint32_t)(0 << ADC1_TRIM_SEL_VREF_BUF_Pos))

#define IS_ADC_INT_VREF_AMPLIFIER(AMPLIFIER)	(((AMPLIFIER) == ADC_INT_VREF_AMPLIFIER_Enable) ||\
												 ((AMPLIFIER) == ADC_INT_VREF_AMPLIFIER_Disable))
/** @} */ /* End of group ADC_Int_VRef_Amplifier */

/** @} */ /* End of group ADC_Exported_Constants */

/** @defgroup ADC_Exported_Macros ADC Exported Macros
  * @{
  */

/** @} */ /* End of group ADC_Exported_Macros */

/** @defgroup ADC_Exported_Functions ADC Exported Functions
  * @{
  */

void ADC_DeInit(void);
void ADC_Init(const ADC_InitTypeDef* ADC_InitStruct);
void ADC_StructInit(ADC_InitTypeDef* ADC_InitStruct);
void ADC_SetTrim(uint32_t Trim);
void ADC1_Init(const ADCx_InitTypeDef* ADCx_InitStruct);
void ADCx_StructInit(ADCx_InitTypeDef* ADCx_InitStruct);
void ADC1_Cmd(FunctionalState NewState);
void ADC1_SetChannel(uint32_t Channel);
void ADC1_SetChannels(uint32_t ChannelMask);
void ADC1_OperationModeConfig(uint32_t SamplingMode, uint32_t SwitchingMode);
void ADC1_SamplingModeConfig(uint32_t SamplingMode);
void ADC1_ChannelSwitchingConfig(uint32_t SwitchingMode);
void ADC1_LevelsConfig(uint32_t LowLevel, uint32_t HighLevel, uint32_t NewState);
void ADC1_SetLowLevel(uint32_t LowLevel);
void ADC1_SetHighLevel(uint32_t HighLevel);
void ADC1_Start(void);
uint32_t ADC1_GetResult(void);
uint32_t ADC_GetStatus(void);
uint32_t ADC1_GetStatus(void);
FlagStatus ADC_GetFlagStatus(uint32_t Flag);
FlagStatus ADC1_GetFlagStatus(uint32_t Flag);
void ADC1_ClearOverwriteFlag(void);
void ADC1_ClearOutOfRangeFlag(void);
void ADC_ITConfig(uint32_t ADC_IT, FunctionalState NewState);
void ADC1_ITConfig(uint32_t ADC_IT, FunctionalState NewState);
ITStatus ADC_GetITStatus(uint32_t ADC_IT);
ITStatus ADC1_GetITStatus(uint32_t ADC_IT);

/** @} */ /* End of group ADC_Exported_Functions */

/** @} */ /* End of group ADC */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

#ifdef __cplusplus
} // extern "C" block end
#endif

#endif /* __MDR32F9QX_ADC_H */

/*
*
* END OF FILE MDR32F9Qx_adc.h */

