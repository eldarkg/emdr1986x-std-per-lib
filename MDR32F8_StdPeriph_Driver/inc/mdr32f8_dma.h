/**
  ******************************************************************************
  * @file    MDR32F9Qx_dma.h
  * @author  Phyton Application Team
  * @version V1.4.0
  * @date    11/06/2010
  * @brief   This file contains all the functions prototypes for the DMA
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
  * <h2><center>&copy; COPYRIGHT 2010 Phyton</center></h2>
  ******************************************************************************
  * FILE MDR32F9Qx_dma.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MDR32F9Qx_DMA_H
#define __MDR32F9Qx_DMA_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"	
#include "mdr32f8_config.h"
#include "MDR1986VE8T.h"	

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @addtogroup DMA
  * @{
  */

/** @defgroup DMA_Exported_Types DMA Exported Types
  * @{
  */

/**
  * @brief  DMA Channel Primary / Alternate Control Data initialization structure definition
  */

typedef struct
{
  uint32_t DMA_SourceBaseAddr;                 /*!< Specifies the source base address for DMA Channelx. */

  uint32_t DMA_DestBaseAddr;                  /*!< Specifies the destination base address for DMA Channelx. */

  uint32_t DMA_SourceIncSize;                 /*!< Specifies the source address register increment value.
                                                 This parameter can be a value of @ref DMA_source_incremented_mode */

  uint32_t DMA_DestIncSize;                   /*!< Specifies the destination address register increment value.
                                                 This parameter can be a value of @ref DMA_dest_incremented_mode */

  uint32_t DMA_MemoryDataSize;                /*!< Specifies the Memory data width.
                                                 This parameter can be a value of @ref DMA_memory_data_size */

  uint32_t DMA_Mode;                          /*!< Specifies the operation mode of the DMA Channelx.
                                                 This parameter can be a value of @ref DMA_operating_mode. */

  uint32_t DMA_CycleSize;                     /*!< Specifies the  total number of DMA transfers that the DMA cycle contains.
                                                 This parameter can be a value of @ref DMA_cycle_size. */

  uint32_t DMA_NumContinuous;                 /*!< Specifies how many DMA transfers can occur before the DMA controller rearbitrates.
                                                 This parameter can be a value of @ref DMA_number_continuous_transfers. */

  uint32_t DMA_SourceProtCtrl;                /*!< Specifies the DMA Source protection control.
                                                 This parameter can be a value of @ref DMA_source_protection_control. */

  uint32_t DMA_DestProtCtrl;                  /*!< Specifies the DMA Destination protection control.
                                                 This parameter can be a value of @ref DMA_dest_protection_control. */
} DMA_CtrlDataInitTypeDef;

/**
  * @brief  DMA Channel Control Data structure definition
  */

typedef struct
{
  uint32_t DMA_SourceEndAddr;                 /*!< Specifies the DMA channel source end address */

  uint32_t DMA_DestEndAddr;                   /*!< Specifies the DMA channel destination end address. */

  uint32_t DMA_Control;                       /*!< Specifies the DMA channel control data configuration. */

  uint32_t DMA_Unused;                        /*!< Specifies the DMA channel unused memory. */

}DMA_CtrlDataTypeDef;

/**
  * @brief  DMA Channel Init structure definition
  */

typedef struct
{
  DMA_CtrlDataInitTypeDef *DMA_PriCtrlData;   /*!< Specifies the pointer to the primary control data structure.
                                                 This parameter should be NULL if primary data structure is not used */

  DMA_CtrlDataInitTypeDef *DMA_AltCtrlData;   /*!< Specifies the pointer to the alternate control data structure.
                                                 This parameter should be NULL if alternate data structure is not used */

  uint32_t DMA_ProtCtrl;                      /*!< Specifies the AHB-Lite protection control.
                                                 This parameter can be a value of @ref DMA_AHB_protection_control. */

  uint8_t DMA_Priority;                       /*!< Specifies the software priority for the DMA Channelx.
                                                 This parameter can be a value of @ref DMA_priority_level */

  uint8_t DMA_UseBurst;                       /*!< Disables single request to generate DMA requests for the DMA Channelx.
                                                 This parameter can be a value of @ref DMA_burst_mode */

  uint8_t DMA_SelectDataStructure;            /*!< Specifies the primary /alternate data structure to use by the DMA channel.
                                                 This parameter can be a value of @ref DMA_data_structure_selection. */

} DMA_ChannelInitTypeDef;

/**
  * @brief  DMA Channel Scatter-Gather Init structure definition
  */

typedef struct
{
  DMA_CtrlDataTypeDef *DMA_SG_TaskArray;      /*!< Specifies the pointer to the Scatter-Gather task structures array. The size
                                                 of the array should be equal to DMA_SG_TaskNumber.
                                                 Every structure of the array should contain the copy of the alternate control
                                                 data for the related task. It will be used by DMA to configure
                                                 the alternate control data while operating in the
                                                 scatter-gather mode */

  uint32_t DMA_SG_TaskNumber;                 /*!< Specifies the number of scatter-gather tasks to be executed by DMA */


  uint32_t DMA_SourceProtCtrl;                /*!< Specifies the Primary Control Data DMA Source protection control.
                                                 This parameter can be a value of @ref DMA_source_protection_control. */

  uint32_t DMA_DestProtCtrl;                  /*!< Specifies the Primary Control Data DMA Destination protection control.
                                                 This parameter can be a value of @ref DMA_dest_protection_control. */

  uint32_t DMA_ProtCtrl;                      /*!< Specifies the AHB-Lite protection control.
                                                 This parameter can be a value of @ref DMA_AHB_protection_control. */

  uint8_t DMA_Priority;                       /*!< Specifies the software priority for the DMA Channelx.
                                                 This parameter can be a value of @ref DMA_priority_level */

  uint8_t DMA_UseBurst;                       /*!< Disables single request to generate DMA requests for the DMA Channelx.
                                                 This parameter can be a value of @ref DMA_burst_mode */

} DMA_Channel_SG_InitTypeDef;


/** @} */ /* End of group DMA_Exported_Types */

/** @defgroup DMA_Exported_Constants DMA Exported Constants
  * @{
  */

/** @defgroup DMA_channels_number DMA channels number
  * @{
  */

#define IS_DMA_CHANNELS(NUMBER) ((NUMBER >= 1) && (NUMBER <= 32))

/** @} */ /* End of group DMA_channels_number */

/** @defgroup DMA_alternate_data_usage DMA alternate data usage
  * @{
  */

#define DMA_ALternateDataDisabled           ((uint16_t)(0x00))
#define DMA_ALternateDataEnabled            ((uint16_t)(0x01))

#define IS_DMA_ALTERNATE_DATA(STATE)        (((STATE) == DMA_ALternateDataDisabled) || \
                                            ((STATE)  == DMA_ALternateDataEnabled))

/** @} */ /* End of group DMA_alternate_data_usage */

/** @defgroup DMA_valid_channels DMA valid channels
  * @{
  */
#if defined (USE_MDR1986VE9x)

#define DMA_Channel_UART1_TX    ((uint8_t)(0))
#define DMA_Channel_UART1_RX    ((uint8_t)(1))
#define DMA_Channel_UART2_TX    ((uint8_t)(2))
#define DMA_Channel_UART2_RX    ((uint8_t)(3))
#define DMA_Channel_SSP1_TX     ((uint8_t)(4))
#define DMA_Channel_SSP1_RX     ((uint8_t)(5))
#define DMA_Channel_SSP2_TX     ((uint8_t)(6))
#define DMA_Channel_SSP2_RX     ((uint8_t)(7))
#define DMA_Channel_ADC1        ((uint8_t)(8))
#define DMA_Channel_ADC2        ((uint8_t)(9))
#define DMA_Channel_TIM1        ((uint8_t)(0))//10
#define DMA_Channel_TIM2        ((uint8_t)(11))
#define DMA_Channel_TIM3        ((uint8_t)(12))
#define DMA_Channel_SW1         ((uint8_t)(13))
#define DMA_Channel_SW2         ((uint8_t)(14))
#define DMA_Channel_SW3         ((uint8_t)(15))
#define DMA_Channel_SW4         ((uint8_t)(16))
#define DMA_Channel_SW5         ((uint8_t)(17))
#define DMA_Channel_SW6         ((uint8_t)(18))
#define DMA_Channel_SW7         ((uint8_t)(19))
#define DMA_Channel_SW8         ((uint8_t)(20))
#define DMA_Channel_SW9         ((uint8_t)(21))
#define DMA_Channel_SW10        ((uint8_t)(22))
#define DMA_Channel_SW11        ((uint8_t)(23))
#define DMA_Channel_SW12        ((uint8_t)(24))
#define DMA_Channel_SW13        ((uint8_t)(25))
#define DMA_Channel_SW14        ((uint8_t)(26))
#define DMA_Channel_SW15        ((uint8_t)(27))
#define DMA_Channel_SW16        ((uint8_t)(28))
#define DMA_Channel_SW17        ((uint8_t)(29))
#define DMA_Channel_SW18        ((uint8_t)(30))
#define DMA_Channel_SW19        ((uint8_t)(31))

#elif defined (USE_MDR1986VE1T)

/*-- req DMA request ---------------------------------------------------------*/
#define DMA_Channel_REQ_UART1_TX    ((uint8_t)(0))
#define DMA_Channel_REQ_UART1_RX    ((uint8_t)(1))
#define DMA_Channel_REQ_UART2_TX    ((uint8_t)(2))
#define DMA_Channel_REQ_UART2_RX    ((uint8_t)(3))
#define DMA_Channel_REQ_SSP1_TX     ((uint8_t)(4))
#define DMA_Channel_REQ_SSP1_RX     ((uint8_t)(5))
#define DMA_Channel_REQ_SSP2_TX     ((uint8_t)(6))
#define DMA_Channel_REQ_SSP2_RX     ((uint8_t)(7))
#define DMA_Channel_REQ_SSP3_TX     ((uint8_t)(8))
#define DMA_Channel_REQ_SSP3_RX     ((uint8_t)(9))
#define DMA_Channel_REQ_TIM1        ((uint8_t)(10))
#define DMA_Channel_REQ_TIM2        ((uint8_t)(11))
#define DMA_Channel_REQ_TIM3        ((uint8_t)(12))
#define DMA_Channel_REQ_TIM4        ((uint8_t)(13))
#define DMA_Channel_SW1           ((uint8_t)(14))
#define DMA_Channel_SW2           ((uint8_t)(15))
#define DMA_Channel_SW3             ((uint8_t)(16))
#define DMA_Channel_SW4           ((uint8_t)(17))
#define DMA_Channel_SW5           ((uint8_t)(18))
#define DMA_Channel_SW6           ((uint8_t)(19))
#define DMA_Channel_SW7           ((uint8_t)(20))
#define DMA_Channel_SW8           ((uint8_t)(21))
#define DMA_Channel_SW9           ((uint8_t)(22))
#define DMA_Channel_SW10      ((uint8_t)(23))
#define DMA_Channel_SW11      ((uint8_t)(24))
#define DMA_Channel_SW12      ((uint8_t)(25))
#define DMA_Channel_SW13      ((uint8_t)(26))
#define DMA_Channel_SW14      ((uint8_t)(27))
#define DMA_Channel_SW15      ((uint8_t)(28))
#define DMA_Channel_SW16      ((uint8_t)(29))
#define DMA_Channel_SW17      ((uint8_t)(30))
#define DMA_Channel_SW18      ((uint8_t)(31))

/*-- sreq DMA request --------------------------------------------------------*/
#define DMA_Channel_SREQ_UART1_TX    ((uint8_t)(0))
#define DMA_Channel_SREQ_UART1_RX    ((uint8_t)(1))
#define DMA_Channel_SREQ_UART2_TX    ((uint8_t)(2))
#define DMA_Channel_SREQ_UART2_RX    ((uint8_t)(3))
#define DMA_Channel_SREQ_SSP1_TX     ((uint8_t)(4))
#define DMA_Channel_SREQ_SSP1_RX     ((uint8_t)(5))
#define DMA_Channel_SREQ_SSP2_TX     ((uint8_t)(6))
#define DMA_Channel_SREQ_SSP2_RX     ((uint8_t)(7))
#define DMA_Channel_SREQ_SSP3_TX     ((uint8_t)(8))
#define DMA_Channel_SREQ_SSP3_RX     ((uint8_t)(9))
#define DMA_Channel_SREQ_TIM1        ((uint8_t)(10))
#define DMA_Channel_SREQ_TIM2        ((uint8_t)(11))
#define DMA_Channel_SREQ_TIM3        ((uint8_t)(12))
#define DMA_Channel_SREQ_TIM4        ((uint8_t)(13))
#define DMA_Channel_SREQ_TIM1_REQ1   ((uint8_t)(14))
#define DMA_Channel_SREQ_TIM1_REQ2   ((uint8_t)(15))
#define DMA_Channel_SREQ_TIM1_REQ3   ((uint8_t)(16))
#define DMA_Channel_SREQ_TIM1_REQ4   ((uint8_t)(17))
#define DMA_Channel_SREQ_TIM2_REQ1   ((uint8_t)(18))
#define DMA_Channel_SREQ_TIM2_REQ2   ((uint8_t)(19))
#define DMA_Channel_SREQ_TIM2_REQ3   ((uint8_t)(20))
#define DMA_Channel_SREQ_TIM2_REQ4   ((uint8_t)(21))
#define DMA_Channel_SREQ_TIM3_REQ1   ((uint8_t)(22))
#define DMA_Channel_SREQ_TIM3_REQ2   ((uint8_t)(23))
#define DMA_Channel_SREQ_TIM3_REQ3   ((uint8_t)(24))
#define DMA_Channel_SREQ_TIM3_REQ4   ((uint8_t)(25))
#define DMA_Channel_SREQ_TIM4_REQ1   ((uint8_t)(26))
#define DMA_Channel_SREQ_TIM4_REQ2   ((uint8_t)(27))
#define DMA_Channel_SREQ_TIM4_REQ3   ((uint8_t)(28))
#define DMA_Channel_SREQ_TIM4_REQ4   ((uint8_t)(29))
#define DMA_Channel_SREQ_ADCDMA    ((uint8_t)(30))
#define DMA_Channel_SREQ_SW1         ((uint8_t)(31))

#elif defined (USE_MDR1986VE3)

/*-- req DMA request ---------------------------------------------------------*/
#define DMA_Channel_REQ_UART1_TX    ((uint8_t)(0))
#define DMA_Channel_REQ_UART1_RX    ((uint8_t)(1))
#define DMA_Channel_REQ_UART2_TX    ((uint8_t)(2))
#define DMA_Channel_REQ_UART2_RX    ((uint8_t)(3))
#define DMA_Channel_REQ_SSP1_TX     ((uint8_t)(4))
#define DMA_Channel_REQ_SSP1_RX     ((uint8_t)(5))
#define DMA_Channel_REQ_SSP2_TX     ((uint8_t)(6))
#define DMA_Channel_REQ_SSP2_RX     ((uint8_t)(7))
#define DMA_Channel_REQ_SSP3_TX     ((uint8_t)(8))
#define DMA_Channel_REQ_SSP3_RX     ((uint8_t)(9))
#define DMA_Channel_REQ_TIM1        ((uint8_t)(10))
#define DMA_Channel_REQ_TIM2        ((uint8_t)(11))
#define DMA_Channel_REQ_TIM3        ((uint8_t)(12))
#define DMA_Channel_REQ_TIM4        ((uint8_t)(13))
#define DMA_Channel_SW1           ((uint8_t)(14))
#define DMA_Channel_SW2           ((uint8_t)(15))
#define DMA_Channel_SW3             ((uint8_t)(16))
#define DMA_Channel_SW4           ((uint8_t)(17))
#define DMA_Channel_SW5           ((uint8_t)(18))
#define DMA_Channel_SW6           ((uint8_t)(19))
#define DMA_Channel_SW7           ((uint8_t)(20))
#define DMA_Channel_SW8           ((uint8_t)(21))
#define DMA_Channel_SW9           ((uint8_t)(22))
#define DMA_Channel_REQ_SSP4_RX     ((uint8_t)(23))
#define DMA_Channel_REQ_UART3_TX    ((uint8_t)(24))
#define DMA_Channel_REQ_UART3_RX    ((uint8_t)(25))
#define DMA_Channel_REQ_UART4_TX    ((uint8_t)(26))
#define DMA_Channel_REQ_UART4_RX    ((uint8_t)(27))
#define DMA_Channel_REQ_SSP4_TX     ((uint8_t)(28))
#define DMA_Channel_REQ_AUDIO_TX  ((uint8_t)(29))
#define DMA_Channel_SW10          ((uint8_t)(30))
#define DMA_Channel_REQ_AUDIO_RX    ((uint8_t)(31))

/*-- sreq DMA request --------------------------------------------------------*/
#define DMA_Channel_SREQ_UART1_TX    ((uint8_t)(0))
#define DMA_Channel_SREQ_UART1_RX    ((uint8_t)(1))
#define DMA_Channel_SREQ_UART2_TX    ((uint8_t)(2))
#define DMA_Channel_SREQ_UART2_RX    ((uint8_t)(3))
#define DMA_Channel_SREQ_SSP1_TX     ((uint8_t)(4))
#define DMA_Channel_SREQ_SSP1_RX     ((uint8_t)(5))
#define DMA_Channel_SREQ_SSP2_TX     ((uint8_t)(6))
#define DMA_Channel_SREQ_SSP2_RX     ((uint8_t)(7))
#define DMA_Channel_SREQ_SSP3_TX     ((uint8_t)(8))
#define DMA_Channel_SREQ_SSP3_RX     ((uint8_t)(9))
#define DMA_Channel_SREQ_TIM1        ((uint8_t)(10))
#define DMA_Channel_SREQ_TIM2        ((uint8_t)(11))
#define DMA_Channel_SREQ_TIM3        ((uint8_t)(12))
#define DMA_Channel_SREQ_TIM4        ((uint8_t)(13))
#define DMA_Channel_SREQ_TIM1_REQ1   ((uint8_t)(14))
#define DMA_Channel_SREQ_TIM1_REQ2   ((uint8_t)(15))
#define DMA_Channel_SREQ_TIM1_REQ3   ((uint8_t)(16))
#define DMA_Channel_SREQ_TIM1_REQ4   ((uint8_t)(17))
#define DMA_Channel_SREQ_TIM2_REQ1   ((uint8_t)(18))
#define DMA_Channel_SREQ_TIM2_REQ2   ((uint8_t)(19))
#define DMA_Channel_SREQ_TIM2_REQ3   ((uint8_t)(20))
#define DMA_Channel_SREQ_TIM2_REQ4   ((uint8_t)(21))
#define DMA_Channel_SREQ_TIM3_REQ1   ((uint8_t)(22))
#define DMA_Channel_SREQ_TIM3_REQ2   ((uint8_t)(23))
#define DMA_Channel_SREQ_TIM3_REQ3   ((uint8_t)(24))
#define DMA_Channel_SREQ_TIM3_REQ4   ((uint8_t)(25))
#define DMA_Channel_SREQ_TIM4_REQ1   ((uint8_t)(26))
#define DMA_Channel_SREQ_TIM4_REQ2   ((uint8_t)(27))
#define DMA_Channel_SREQ_TIM4_REQ3   ((uint8_t)(28))
#define DMA_Channel_SREQ_TIM4_REQ4   ((uint8_t)(29))
#define DMA_Channel_SREQ_ADCDMA    ((uint8_t)(30))
#define DMA_Channel_SREQ_SW1         ((uint8_t)(31))

#endif

#define IS_DMA_CHANNEL(CHANNEL) (CHANNEL <= (DMA_Channels_Number - 1))

/** @} */ /* End of group DMA_valid_channels */

/** @defgroup DMA_source_incremented_mode DMA source incremented mode
  * @{
  */

#define DMA_SourceIncByte                   ((uint32_t)(0 << 26))
#define DMA_SourceIncHalfword               ((uint32_t)(1 << 26))
#define DMA_SourceIncWord                   ((uint32_t)(2 << 26))
#define DMA_SourceIncNo                     ((uint32_t)(3 << 26))
#define IS_DMA_SOURCE_INC_STATE(STATE)      (((STATE) == DMA_SourceIncByte)     || \
                                            ((STATE)  == DMA_SourceIncHalfword) || \
                                            ((STATE)  == DMA_SourceIncWord)     || \
                                            ((STATE)  == DMA_SourceIncNo))

/** @} */ /* End of group DMA_source_incremented_mode */

/** @defgroup DMA_dest_incremented_mode DMA dest incremented mode
  * @{
  */

#define DMA_DestIncByte                 ((uint32_t)(0x0UL << 30))
#define DMA_DestIncHalfword             ((uint32_t)(0x1UL << 30))
#define DMA_DestIncWord                 ((uint32_t)(0x2UL << 30))
#define DMA_DestIncNo                   ((uint32_t)(0x3UL << 30))
#define IS_DMA_DEST_INC_STATE(STATE)    (((STATE) == DMA_DestIncByte)       || \
                                        ((STATE)  == DMA_DestIncHalfword)   || \
                                        ((STATE)  == DMA_DestIncWord)       || \
                                        ((STATE)  == DMA_DestIncNo))

/** @} */ /* End of group DMA_dest_incremented_mode */

/** @defgroup DMA_memory_data_size DMA memory data size
  * @{
  */

#define DMA_MemoryDataSize_Byte        ((uint32_t)(0x00 << 24))
#define DMA_MemoryDataSize_HalfWord    ((uint32_t)(0x11 << 24))
#define DMA_MemoryDataSize_Word        ((uint32_t)(0x22 << 24))
#define IS_DMA_MEMORY_DATA_SIZE(SIZE) (((SIZE) == DMA_MemoryDataSize_Byte)      || \
                                       ((SIZE) == DMA_MemoryDataSize_HalfWord)  || \
                                       ((SIZE) == DMA_MemoryDataSize_Word))

/** @} */ /* End of group DMA_memory_data_size */

/** @defgroup DMA_operating_mode DMA operating mode
  * @{
  */

#define DMA_Mode_Stop                       ((uint32_t)0x0)
#define DMA_Mode_Basic                      ((uint32_t)0x1)
#define DMA_Mode_AutoRequest                ((uint32_t)0x2)
#define DMA_Mode_PingPong                   ((uint32_t)0x3)
#define DMA_Mode_MemScatterPri              ((uint32_t)0x4)
#define DMA_Mode_MemScatterAlt              ((uint32_t)0x5)
#define DMA_Mode_PerScatterPri              ((uint32_t)0x6)
#define DMA_Mode_PerScatterAlt              ((uint32_t)0x7)
#define DMA_Mode_PerScatterAltBurst         ((uint32_t)0xF)

#define IS_DMA_MODE(MODE)          (((MODE) == DMA_Mode_Stop)           || \
                                    ((MODE) == DMA_Mode_Basic)          || \
                                    ((MODE) == DMA_Mode_AutoRequest)    || \
                                    ((MODE) == DMA_Mode_PingPong)       || \
                                    ((MODE) == DMA_Mode_MemScatterPri)  || \
                                    ((MODE) == DMA_Mode_MemScatterAlt)  || \
                                    ((MODE) == DMA_Mode_PerScatterPri)  || \
                                    ((MODE) == DMA_Mode_PerScatterAlt)  || \
                                    ((MODE) == DMA_Mode_PerScatterAltBurst))

/** @} */ /* End of group DMA_operating_mode */

/** @defgroup DMA_cycle_size DMA cycle size
  * @{
  */

#define IS_DMA_CYCLE_SIZE(SIZE)   ((SIZE >= 1) && (SIZE <= 1024))

/** @} */ /* End of group DMA_cycle_size */

/** @defgroup DMA_priority_level DMA priority level
  * @{
  */

#define DMA_Priority_Default                ((uint8_t)0x00)
#define DMA_Priority_High                   ((uint8_t)0x01)
#define IS_DMA_PRIORITY(PRIORITY)           (((PRIORITY) == DMA_Priority_Default) || \
                                            ((PRIORITY)  == DMA_Priority_High))

/** @} */ /* End of group DMA_priority_level */

/** @defgroup DMA_burst_mode DMA burst mode
  * @{
  */

#define DMA_BurstClear                      ((uint8_t)0x00)
#define DMA_BurstSet                        ((uint8_t)0x01)
#define IS_DMA_BURST(STATE)                 (((STATE) == DMA_BurstClear) || \
                                            ((STATE)  == DMA_BurstSet))

/** @} */ /* End of group DMA_burst_mode */


/** @defgroup DMA_source_protection_control DMA source protection control
  * @{
  */

#define DMA_SourceCacheable                 ((uint32_t)(0x01 << 20))
#define DMA_SourceBufferable                ((uint32_t)(0x01 << 19))
#define DMA_SourcePrivileged                ((uint32_t)(0x01 << 18))

#define IS_DMA_SOURCE_PROT(STATE)           ((STATE & (~(0x7 << 18))) == 0)

/** @} */ /* End of group DMA_source_protection_control */

/** @defgroup DMA_dest_protection_control DMA dest protection control
  * @{
  */

#define DMA_DestCacheable                   ((uint32_t)(0x01 << 23))
#define DMA_DestBufferable                  ((uint32_t)(0x01 << 22))
#define DMA_DestPrivileged                  ((uint32_t)(0x01 << 21))

#define IS_DMA_DEST_PROT(STATE)             ((STATE & (~(0x7 << 21))) == 0)

/** @} */ /* End of group DMA_dest_protection_control */

/** @defgroup DMA_AHB_protection_control DMA AHB-Lite protection control
  * @{
  */

#define DMA_AHB_Cacheable                 ((uint32_t)(0x01 << 7))
#define DMA_AHB_Bufferable                ((uint32_t)(0x01 << 6))
#define DMA_AHB_Privileged                ((uint32_t)(0x01 << 5))

#define IS_DMA_AHB_PROT(STATE)            ((STATE & (~(0x7 << 5))) == 0)

/** @} */ /* End of group DMA_source_protection_control */

/** @defgroup DMA_number_continuous_transfers DMA number continuous transfers
  * @{
  */

#define DMA_Transfers_1                     ((uint32_t)(0x00 << 14))
#define DMA_Transfers_2                     ((uint32_t)(0x01 << 14))
#define DMA_Transfers_4                     ((uint32_t)(0x02 << 14))
#define DMA_Transfers_8                     ((uint32_t)(0x03 << 14))
#define DMA_Transfers_16                    ((uint32_t)(0x04 << 14))
#define DMA_Transfers_32                    ((uint32_t)(0x05 << 14))
#define DMA_Transfers_64                    ((uint32_t)(0x06 << 14))
#define DMA_Transfers_128                   ((uint32_t)(0x07 << 14))
#define DMA_Transfers_256                   ((uint32_t)(0x08 << 14))
#define DMA_Transfers_512                   ((uint32_t)(0x09 << 14))
#define DMA_Transfers_1024                  ((uint32_t)(0x0A << 14))

#define IS_DMA_CONTINUOUS_NUMBER(NUMBER)   (((NUMBER)  == DMA_Transfers_1)      || \
                                            ((NUMBER)  == DMA_Transfers_2)      || \
                                            ((NUMBER)  == DMA_Transfers_4)      || \
                                            ((NUMBER)  == DMA_Transfers_8)      || \
                                            ((NUMBER)  == DMA_Transfers_16)     || \
                                            ((NUMBER)  == DMA_Transfers_32)     || \
                                            ((NUMBER)  == DMA_Transfers_64)     || \
                                            ((NUMBER)  == DMA_Transfers_128)    || \
                                            ((NUMBER)  == DMA_Transfers_256)    || \
                                            ((NUMBER)  == DMA_Transfers_512)    || \
                                            ((NUMBER)  == DMA_Transfers_1024))

/** @} */ /* End of group DMA_number_continuous_transfers */

/** @defgroup DMA_data_structure_selection DMA data structure selection
  * @{
  */

#define DMA_CTRL_DATA_PRIMARY   ((uint8_t)0x00)

#if (DMA_AlternateData == 1)

  #define DMA_CTRL_DATA_ALTERNATE ((uint8_t)0x01)

  #define IS_DMA_SELECT_DATA_STRUCTURE(TYPE) (((TYPE)  == DMA_CTRL_DATA_PRIMARY)      || \
                                              ((TYPE)  == DMA_CTRL_DATA_ALTERNATE))
#else
  #define IS_DMA_SELECT_DATA_STRUCTURE(TYPE) (((TYPE)  == DMA_CTRL_DATA_PRIMARY))
#endif

/** @} */ /* End of group DMA_data_structure_selection */

/** @defgroup DMA_flags_definition DMA flags definition
  * @{
  */

#define DMA_FLAG_DMA_ENA        ((uint8_t)0x01)
#define DMA_FLAG_DMA_ERR        ((uint8_t)0x02)
#define DMA_FLAG_CHNL_ENA       ((uint8_t)0x03)
#define DMA_FLAG_CHNL_MASK      ((uint8_t)0x04)
#define DMA_FLAG_CHNL_WAIT      ((uint8_t)0x05)
#define DMA_FLAG_CHNL_BURST     ((uint8_t)0x06)
#define DMA_FLAG_CHNL_ALT       ((uint8_t)0x07)
#define DMA_FLAG_CHNL_PRIORITY  ((uint8_t)0x08)

#define IS_DMA_FLAG(FLAG)       (((FLAG)  == DMA_FLAG_DMA_ENA)      || \
                                 ((FLAG)  == DMA_FLAG_DMA_ERR)      || \
                                 ((FLAG)  == DMA_FLAG_CHNL_ENA)     || \
                                 ((FLAG)  == DMA_FLAG_CHNL_MASK)    || \
                                 ((FLAG)  == DMA_FLAG_CHNL_WAIT)    || \
                                 ((FLAG)  == DMA_FLAG_CHNL_BURST)   || \
                                 ((FLAG)  == DMA_FLAG_CHNL_ALT)     || \
                                 ((FLAG)  == DMA_FLAG_CHNL_PRIORITY))

/** @} */ /* End of group DMA_flags_definition */

/** @} */ /* End of group DMA_Exported_Constants */

/** @defgroup DMA_Exported_Macros DMA Exported Macros
  * @{
  */

/** @} */ /* End of group DMA_Exported_Macros */

/** @defgroup DMA_Exported_Functions DMA Exported Functions
  * @{
  */

void DMA_DeInit(void);
void DMA_Init(uint8_t DMA_Channel, DMA_ChannelInitTypeDef* DMA_InitStruct);
void DMA_SG_Init( uint8_t DMA_Channel, DMA_Channel_SG_InitTypeDef *DMA_SG_InitStruct);
void DMA_StructInit(DMA_ChannelInitTypeDef* DMA_InitStruct);
void DMA_SG_StructInit(DMA_Channel_SG_InitTypeDef* DMA_InitStruct);
void DMA_CtrlInit(uint8_t DMA_Channel, uint8_t DMA_CtrlDataType,  DMA_CtrlDataInitTypeDef* DMA_CtrlStruct);
void DMA_SG_CtrlInit(uint32_t DMA_Task, DMA_CtrlDataTypeDef *DMA_SG_TaskArray,  DMA_CtrlDataInitTypeDef* DMA_CtrlStruct);
void DMA_Cmd(uint8_t DMA_Channel, FunctionalState NewState);
void DMA_Request(uint8_t DMA_Channel);
void DMA_ClearError(void);
uint32_t DMA_GetCurrTransferCounter(uint8_t DMA_Channel, uint8_t DMA_CtrlData);
FlagStatus DMA_GetFlagStatus(uint8_t DMA_Channel, uint8_t DMA_Flag);
void DMA_CtrlDataInit(DMA_CtrlDataInitTypeDef *DMA_ctrl_data_ptr, DMA_CtrlDataTypeDef *DMA_ctrl_table_ptr);

/** @} */ /* End of group DMA_Exported_Functions */

/** @} */ /* End of group DMA */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

#ifdef __cplusplus
} // extern "C" block end
#endif

#endif /* __MDR32F9Qx_DMA_H */

/******************* (C) COPYRIGHT 2010 Phyton *********************************
*
* END OF FILE MDR32F9Qx_dma.h */

