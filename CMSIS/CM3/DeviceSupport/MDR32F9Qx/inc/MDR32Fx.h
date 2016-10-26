/**
  ******************************************************************************
  * @file    MDR32Fx.h
  * @author  Phyton Application Team
  * @version V1.4.0
  * @date    22/06/2011
  * @brief   This file contains all the Special Function Registers definitions
  *          for the Milandr MDR32Fx microcontroller.
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
  * FILE MDR32Fx.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MDR32FX_H
#define __MDR32FX_H

/** @addtogroup __CMSIS CMSIS
  * @{
  */

/** @defgroup MDR1986VE9x MDR1986VE9x
 *  @{
 */

/** @defgroup __MDR32Fx_Peripheral MDR32F9Qx Peripheral
  * @{
  */

#ifdef __cplusplus
extern "C" {
#endif

#if defined ( __CC_ARM   )
  #pragma anon_unions
#endif

/* MDR32Fx Interrupt Number Definition */
typedef enum IRQn
{
/*---- Cortex-M3 Processor Exceptions Numbers --------------------------------*/
  NonMaskableInt_IRQn     = -14,  /*!<  2 Non Maskable Interrupt              *///!< NonMaskableInt_IRQn
  HardFault_IRQn          = -13,  /*!<  3 Hard Fault Interrupt                *///!< HardFault_IRQn
  MemoryManagement_IRQn   = -12,  /*!<  4 Memory Management Interrupt         *///!< MemoryManagement_IRQn
  BusFault_IRQn           = -11,  /*!<  5 Bus Fault Interrupt                 *///!< BusFault_IRQn
  UsageFault_IRQn         = -10,  /*!<  6 Usage Fault Interrupt               *///!< UsageFault_IRQn
  SVCall_IRQn             = -5,   /*!< 11 SV Call Interrupt                   *///!< SVCall_IRQn
  PendSV_IRQn             = -2,   /*!< 14 Pend SV Interrupt                   *///!< PendSV_IRQn
  SysTick_IRQn            = -1,   /*!< 15 System Tick Timer Interrupt         *///!< SysTick_IRQn

/*---- MDR32Fx specific Interrupt Numbers ------------------------------------*/
  CAN1_IRQn               =  0,   /*!< CAN1 Interrupt                         *///!< CAN1_IRQn
  CAN2_IRQn               =  1,   /*!< CAN1 Interrupt                         *///!< CAN2_IRQn
  USB_IRQn                =  2,   /*!< USB Host Interrupt                     *///!< USB_IRQn
  DMA_IRQn                =  5,   /*!< DMA Interrupt                          *///!< DMA_IRQn
  UART1_IRQn              =  6,   /*!< UART1 Interrupt                        *///!< UART1_IRQn
  UART2_IRQn              =  7,   /*!< UART2 Interrupt                        *///!< UART2_IRQn
  SSP1_IRQn               =  8,   /*!< SSP1 Interrupt                         *///!< SSP1_IRQn
  I2C_IRQn                =  10,  /*!< I2C Interrupt                          *///!< I2C_IRQn
  POWER_IRQn              =  11,  /*!< POWER Detecor Interrupt                *///!< POWER_IRQn
  WWDG_IRQn               =  12,  /*!< Window Watchdog Interrupt              *///!< WWDG_IRQn
  TIMER1_IRQn             =  14,  /*!< TIMER1 Interrupt                       *///!< TIMER1_IRQn
  TIMER2_IRQn             =  15,  /*!< TIMER2 Interrupt                       *///!< TIMER2_IRQn
  TIMER3_IRQn             =  16,  /*!< TIMER3 Interrupt                       *///!< TIMER3_IRQn
  ADC_IRQn                =  17,  /*!< ADC Interrupt                          *///!< ADC_IRQn
  COMPARATOR_IRQn         =  19,  /*!< COMPARATOR Interrupt                   *///!< COMPARATOR_IRQn
  SSP2_IRQn               =  20,  /*!< SSP2 Interrupt                         *///!< SSP2_IRQn
  BACKUP_IRQn             =  27,  /*!< BACKUP Interrupt                       *///!< BACKUP_IRQn
  EXT_INT1_IRQn           =  28,  /*!< EXT_INT1 Interrupt                     *///!< EXT_INT1_IRQn
  EXT_INT2_IRQn           =  29,  /*!< EXT_INT2 Interrupt                     *///!< EXT_INT2_IRQn
  EXT_INT3_IRQn           =  30,  /*!< EXT_INT3 Interrupt                     *///!< EXT_INT3_IRQn
  EXT_INT4_IRQn           =  31   /*!< EXT_INT4 Interrupt                     *///!< EXT_INT4_IRQn
}IRQn_Type;

/** @addtogroup __Configuration_of_CMSIS Configuration of CMSIS
  * @{
  */

/* Configuration of the Cortex-M3 Processor and Core Peripherals */
#define __CM3_REV              0x0102   /*!< Cortex-M3 Core Revision                      */
#define __MPU_PRESENT             1     /*!< MPU present or not                           */
#define __NVIC_PRIO_BITS          3     /*!< Number of Bits used for Priority Levels      */
#define __Vendor_SysTickConfig    0     /*!< Set to 1 if different SysTick Config is used */

/** @} */ /* End of group __Configuration_of_CMSIS */

/* Includes ------------------------------------------------------------------*/
#include "core_cm3.h"
#include "system_MDR32F9Qx.h"

/** @defgroup __Exported_types Exported types
  * @{
  */

typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus, BitStatus;

#define IS_BIT_STATUS(STATUS) (((STATUS) == RESET) || ((STATE) == SET))

typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;
#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

typedef enum {ERROR = 0, SUCCESS = !ERROR} ErrorStatus;

/** @} */ /* End of group __Exported_types */

/** @addtogroup __MDR32Fx_Peripheral_Units MDR32F9Qx Peripheral Units
  * @{
  */

/** @defgroup MDR32Fx_Periph_CAN CAN
  * @{
  */

/** @defgroup MDR32Fx_Periph_CAN_Data_Structures Data Structures
  * @{
  */

/* MDR_CAN_BUF_TypeDef structure */
typedef struct
{
  __IO uint32_t ID;
  __IO uint32_t DLC;
  __IO uint32_t DATAL;
  __IO uint32_t DATAH;
}MDR_CAN_BUF_TypeDef;

/* MDR_CAN_BUF_FILTER_TypeDef structure */
typedef struct
{
  __IO uint32_t MASK;
  __IO uint32_t FILTER;
}MDR_CAN_BUF_FILTER_TypeDef;

/* MDR_CAN_TypeDef structure */
typedef struct
{
  __IO uint32_t CONTROL;
  __IO uint32_t STATUS;
  __IO uint32_t BITTMNG;
       uint32_t RESERVED0;
  __IO uint32_t INT_EN;
       uint32_t RESERVED1[2];
  __IO uint32_t OVER;
  __IO uint32_t RXID;
  __IO uint32_t RXDLC;
  __IO uint32_t RXDATAL;
  __IO uint32_t RXDATAH;
  __IO uint32_t TXID;
  __IO uint32_t TXDLC;
  __IO uint32_t DATAL;
  __IO uint32_t DATAH;
  __IO uint32_t BUF_CON[32];
  __IO uint32_t INT_RX;
  __IO uint32_t RX;
  __IO uint32_t INT_TX;
  __IO uint32_t TX;
       uint32_t RESERVED2[76];
    MDR_CAN_BUF_TypeDef CAN_BUF[32];
       uint32_t RESERVED3[64];
    MDR_CAN_BUF_FILTER_TypeDef CAN_BUF_FILTER[32];
}MDR_CAN_TypeDef;

/** @} */ /* End of group MDR32Fx_Periph_CAN_Data_Structures */

/** @defgroup MDR32Fx_Periph_CAN_Defines Defines
  * @{
  */

/** @defgroup Periph_CAN_CONTROL  CAN CONTROL
  * @{
  */

/*-- CAN_CONTROL: CAN Control Register -----------------------------*/
/* Bit field positions: */
#define CAN_CONTROL_CAN_EN_Pos                  0
#define CAN_CONTROL_ROM_Pos                     1
#define CAN_CONTROL_STM_Pos                     2
#define CAN_CONTROL_SAP_Pos                     3
#define CAN_CONTROL_ROP_Pos                     4

/* Bit field masks: */
#define CAN_CONTROL_CAN_EN                      ((uint32_t)0x00000001)
#define CAN_CONTROL_ROM                         ((uint32_t)0x00000002)
#define CAN_CONTROL_STM                         ((uint32_t)0x00000004)
#define CAN_CONTROL_SAP                         ((uint32_t)0x00000008)
#define CAN_CONTROL_ROP                         ((uint32_t)0x00000010)

/** @} */ /* End of group CAN_CONTROL */

/** @defgroup Periph_CAN_STATUS CAN STATUS
  * @{
  */

/*-- CAN_STATUS: CAN Status Register -------------------------------*/
/* Bit field positions: */
#define CAN_STATUS_RX_READY_Pos                 0
#define CAN_STATUS_TX_READY_Pos                 1
#define CAN_STATUS_ERROR_OVER_Pos               2
#define CAN_STATUS_BIT_ERR_Pos                  3
#define CAN_STATUS_BIT_STUFF_ERR_Pos            4
#define CAN_STATUS_CRC_ERR_Pos                  5
#define CAN_STATUS_FRAME_ERR_Pos                6
#define CAN_STATUS_ACK_ERR_Pos                  7
#define CAN_STATUS_IDLOWER_Pos                  8
#define CAN_STATUS_ERR_STATUS_Pos               9
#define CAN_STATUS_RX_ERR_CNT8_Pos              11
#define CAN_STATUS_TX_ERR_CNT8_Pos              12
#define CAN_STATUS_RX_ERR_CNT_Pos               16
#define CAN_STATUS_TX_ERR_CNT_Pos               24

/* Bit field masks: */
#define CAN_STATUS_RX_READY                     ((uint32_t)0x00000001)
#define CAN_STATUS_TX_READY                     ((uint32_t)0x00000002)
#define CAN_STATUS_ERROR_OVER                   ((uint32_t)0x00000004)
#define CAN_STATUS_BIT_ERR                      ((uint32_t)0x00000008)
#define CAN_STATUS_BIT_STUFF_ERR                ((uint32_t)0x00000010)
#define CAN_STATUS_CRC_ERR                      ((uint32_t)0x00000020)
#define CAN_STATUS_FRAME_ERR                    ((uint32_t)0x00000040)
#define CAN_STATUS_ACK_ERR                      ((uint32_t)0x00000080)
#define CAN_STATUS_IDLOWER                      ((uint32_t)0x00000100)
#define CAN_STATUS_ERR_STATUS_Msk               ((uint32_t)0x00000600)
#define CAN_STATUS_RX_ERR_CNT8                  ((uint32_t)0x00000800)
#define CAN_STATUS_TX_ERR_CNT8                  ((uint32_t)0x00001000)
#define CAN_STATUS_RX_ERR_CNT_Msk               ((uint32_t)0x00FF0000)
#define CAN_STATUS_TX_ERR_CNT_Msk               ((uint32_t)0xFF000000)

/* ERR STATUS Modes */
#define CAN_STATUS_ERR_STATUS_ERROR_ACTIVE      0x00
#define CAN_STATUS_ERR_STATUS_ERROR_PASSIVE     0x01
#define CAN_STATUS_ERR_STATUS_ERROR_BUS_OFF_Pos 10

/** @} */ /* End of group CAN_STATUS */

/** @defgroup Periph_CAN_BITTMNG  CAN BITTMNG
  * @{
  */

/*-- CAN_BITTMNG: CAN Bittiming Register ---------------------------*/
/* Bit field positions: */
#define CAN_BITTMNG_BRP_Pos                     0
#define CAN_BITTMNG_PSEG_Pos                    16
#define CAN_BITTMNG_SEG1_Pos                    19
#define CAN_BITTMNG_SEG2_Pos                    22
#define CAN_BITTMNG_SJW_Pos                     25
#define CAN_BITTMNG_SB_Pos                      27

/* Bit field masks: */
#define CAN_BITTMNG_BRP_Msk                     ((uint32_t)0x0000FFFF)
#define CAN_BITTMNG_PSEG_Msk                    ((uint32_t)0x00070000)
#define CAN_BITTMNG_SEG1_Msk                    ((uint32_t)0x00380000)
#define CAN_BITTMNG_SEG2_Msk                    ((uint32_t)0x01C00000)
#define CAN_BITTMNG_SJW_Msk                     ((uint32_t)0x06000000)
#define CAN_BITTMNG_SB                          ((uint32_t)0x08000000)

/* PSEG Modes */
#define CAN_BITTMNG_PSEG_1_TQ                   0x00
#define CAN_BITTMNG_PSEG_2_TQ                   0x01
#define CAN_BITTMNG_PSEG_3_TQ                   0x02
#define CAN_BITTMNG_PSEG_4_TQ                   0x03
#define CAN_BITTMNG_PSEG_5_TQ                   0x04
#define CAN_BITTMNG_PSEG_6_TQ                   0x05
#define CAN_BITTMNG_PSEG_7_TQ                   0x06
#define CAN_BITTMNG_PSEG_8_TQ                   0x07

/* SEG1 Modes */
#define CAN_BITTMNG_SEG1_1_TQ                   0x00
#define CAN_BITTMNG_SEG1_2_TQ                   0x01
#define CAN_BITTMNG_SEG1_3_TQ                   0x02
#define CAN_BITTMNG_SEG1_4_TQ                   0x03
#define CAN_BITTMNG_SEG1_5_TQ                   0x04
#define CAN_BITTMNG_SEG1_6_TQ                   0x05
#define CAN_BITTMNG_SEG1_7_TQ                   0x06
#define CAN_BITTMNG_SEG1_8_TQ                   0x07

/* SEG2 Modes */
#define CAN_BITTMNG_SEG2_1_TQ                   0x00
#define CAN_BITTMNG_SEG2_2_TQ                   0x01
#define CAN_BITTMNG_SEG2_3_TQ                   0x02
#define CAN_BITTMNG_SEG2_4_TQ                   0x03
#define CAN_BITTMNG_SEG2_5_TQ                   0x04
#define CAN_BITTMNG_SEG2_6_TQ                   0x05
#define CAN_BITTMNG_SEG2_7_TQ                   0x06
#define CAN_BITTMNG_SEG2_8_TQ                   0x07

/* SJW Modes */
#define CAN_BITTMNG_SJW_1_TQ                    0x00
#define CAN_BITTMNG_SJW_2_TQ                    0x01
#define CAN_BITTMNG_SJW_3_TQ                    0x02
#define CAN_BITTMNG_SJW_4_TQ                    0x03

/** @} */ /* End of group CAN_BITTMNG */

/** @defgroup Periph_CAN_INT_EN CAN INT EN
  * @{
  */

/*-- CAN_INT_EN: CAN Interrupt enable Register ---------------------*/
/* Bit field positions: */
#define CAN_INT_EN_GLB_INT_EN_Pos               0
#define CAN_INT_EN_RX_INT_EN_Pos                1
#define CAN_INT_EN_TX_INT_EN_Pos                2
#define CAN_INT_EN_ERR_INT_EN_Pos               3
#define CAN_INT_EN_ERR_OVER_INT_EN_Pos          4

/* Bit field masks: */
#define CAN_INT_EN_GLB_INT_EN                   ((uint32_t)0x00000001)
#define CAN_INT_EN_RX_INT_EN                    ((uint32_t)0x00000002)
#define CAN_INT_EN_TX_INT_EN                    ((uint32_t)0x00000004)
#define CAN_INT_EN_ERR_INT_EN                   ((uint32_t)0x00000008)
#define CAN_INT_EN_ERR_OVER_INT_EN              ((uint32_t)0x00000010)

/** @} */ /* End of group CAN_INT_EN */

/** @defgroup Periph_CAN_RXID CAN RXID
  * @{
  */

/*-- CAN_RXID:   CAN Receive ID Register ---------------------------*/
/*-- CAN_TXID:   CAN Transmit ID Register --------------------------*/
/*-- CAN_BUF_ID: CAN Buffer ID Register ----------------------------*/
/* Bit field positions: */
#define CAN_ID_EID_Pos                          0
#define CAN_ID_SID_Pos                          18

/* Bit field masks: */
#define CAN_ID_EID_Msk                          ((uint32_t)0x0003FFFF)
#define CAN_ID_SID_Msk                          ((uint32_t)0x1FFC0000)

/** @} */ /* End of group CAN_RXID */

/** @defgroup Periph_CAN_RXDLC  CAN RXDLC
  * @{
  */

/*-- CAN_RXDLC:   CAN Receive DLC Register -------------------------*/
/*-- CAN_TXDLC:   CAN Transmit DLC Register ------------------------*/
/*-- CAN_BUF_DLC: CAN Buffer DLC Register --------------------------*/
/* Bit field positions: */
#define CAN_DLC_Pos                             0
#define CAN_DLC_RTR_Pos                         8
#define CAN_DLC_R1_Pos                          9
#define CAN_DLC_R0_Pos                          10
#define CAN_DLC_SSR_Pos                         11
#define CAN_DLC_IDE_Pos                         12

/* Bit field masks: */
#define CAN_DLC_Msk                             ((uint32_t)0x0000000F)
#define CAN_DLC_RTR                             ((uint32_t)0x00000100)
#define CAN_DLC_R1                              ((uint32_t)0x00000200)
#define CAN_DLC_R0                              ((uint32_t)0x00000400)
#define CAN_DLC_SSR                             ((uint32_t)0x00000800)
#define CAN_DLC_IDE                             ((uint32_t)0x00001000)

/* DLC Modes */
#define CAN_DLC_NO_DATA                         0x00
#define CAN_DLC_1_BYTE                          0x01
#define CAN_DLC_2_BYTES                         0x02
#define CAN_DLC_3_BYTES                         0x03
#define CAN_DLC_4_BYTES                         0x04
#define CAN_DLC_5_BYTES                         0x05
#define CAN_DLC_6_BYTES                         0x06
#define CAN_DLC_7_BYTES                         0x07
#define CAN_DLC_8_BYTES                         0x08

/** @} */ /* End of group CAN_RXDLC */

/** @defgroup Periph_CAN_RXDATAL  CAN RXDATAL
  * @{
  */

/*-- CAN_RXDATAL:   CAN Receive Data low Register ------------------*/
/*-- CAN_DATAL:     CAN Transmit Data low Register -----------------*/
/*-- CAN_BUF_DATAL: CAN Buffer Data low Register -------------------*/
/* Bit field positions: */
#define CAN_DATAL_DB0_Pos                       0
#define CAN_DATAL_DB1_Pos                       8
#define CAN_DATAL_DB2_Pos                       16
#define CAN_DATAL_DB3_Pos                       24

/* Bit field masks: */
#define CAN_DATAL_DB0_Msk                       ((uint32_t)0x000000FF)
#define CAN_DATAL_DB1_Msk                       ((uint32_t)0x0000FF00)
#define CAN_DATAL_DB2_Msk                       ((uint32_t)0x00FF0000)
#define CAN_DATAL_DB3_Msk                       ((uint32_t)0xFF000000)

/** @} */ /* End of group CAN_RXDATAL */

/** @defgroup Periph_CAN_RXDATAH  CAN RXDATAH
  * @{
  */

/*-- CAN_RXDATAH:   CAN Receive Data high Register -----------------*/
/*-- CAN_DATAH:     CAN Transmit Data high Register ----------------*/
/*-- CAN_BUF_DATAH: CAN Buffer Data high Register ------------------*/
/* Bit field positions: */
#define CAN_DATAH_DB4_Pos                       0
#define CAN_DATAH_DB5_Pos                       8
#define CAN_DATAH_DB6_Pos                       16
#define CAN_DATAH_DB7_Pos                       24

/* Bit field masks: */
#define CAN_DATAH_DB4_Msk                       ((uint32_t)0x000000FF)
#define CAN_DATAH_DB5_Msk                       ((uint32_t)0x0000FF00)
#define CAN_DATAH_DB6_Msk                       ((uint32_t)0x00FF0000)
#define CAN_DATAH_DB7_Msk                       ((uint32_t)0xFF000000)

/** @} */ /* End of group CAN_RXDATAH */

/** @defgroup Periph_CAN_BUF_CON  CAN BUF CON
  * @{
  */

/*-- CAN_BUF_CON: CAN Buffer Connection Register -------------------*/
/* Bit field positions: */
#define CAN_BUF_CON_EN_Pos                      0
#define CAN_BUF_CON_RX_TXN_Pos                  1
#define CAN_BUF_CON_OVER_EN_Pos                 2
#define CAN_BUF_CON_RTR_EN_Pos                  3
#define CAN_BUF_CON_PRIOR_0_Pos                 4
#define CAN_BUF_CON_TX_REQ_Pos                  5
#define CAN_BUF_CON_RX_FULL_Pos                 6
#define CAN_BUF_CON_OVER_WR_Pos                 7

/* Bit field masks: */
#define CAN_BUF_CON_EN                          ((uint32_t)0x00000001)
#define CAN_BUF_CON_RX_TXN                      ((uint32_t)0x00000002)
#define CAN_BUF_CON_OVER_EN                     ((uint32_t)0x00000004)
#define CAN_BUF_CON_RTR_EN                      ((uint32_t)0x00000008)
#define CAN_BUF_CON_PRIOR_0                     ((uint32_t)0x00000010)
#define CAN_BUF_CON_TX_REQ                      ((uint32_t)0x00000020)
#define CAN_BUF_CON_RX_FULL                     ((uint32_t)0x00000040)
#define CAN_BUF_CON_OVER_WR                     ((uint32_t)0x00000080)

/** @} */ /* End of group CAN_BUF_CON */

/** @} */ /* End of group MDR32Fx_Periph_CAN_Defines */

/** @} */ /* End of group MDR32Fx_Periph_CAN */

/** @defgroup MDR32Fx_Periph_USB USB
  * @{
  */

/** @defgroup MDR32Fx_Periph_USB_Data_Structures Data Structures
  * @{
  */

/* MDR_USB_SEP_TypeDef structure */
typedef struct
{
  __IO uint32_t CTRL;
  __IO uint32_t STS;
  __IO uint32_t TS;
  __IO uint32_t NTS;
}MDR_USB_SEP_TypeDef;

/* MDR_USB_SEP_FIFO_TypeDef structure */
typedef struct
{
  __IO uint32_t RXFD;
       uint32_t RESERVED0;
  __IO uint32_t RXFDC_L;
  __IO uint32_t RXFDC_H;
  __IO uint32_t RXFC;
       uint32_t RESERVED1[11];
  __IO uint32_t TXFD;
       uint32_t RESERVED2[3];
  __IO uint32_t TXFDC;
       uint32_t RESERVED3[11];
}MDR_USB_SEP_FIFO_TypeDef;

/* MDR_USB_TypeDef structure */
typedef struct
{
  __IO uint32_t HTXC;
  __IO uint32_t HTXT;
  __IO uint32_t HTXLC;
  __IO uint32_t HTXSE;
  __IO uint32_t HTXA;
  __IO uint32_t HTXE;
  __IO uint32_t HFN_L;
  __IO uint32_t HFN_H;
  __IO uint32_t HIS;
  __IO uint32_t HIM;
  __IO uint32_t HRXS;
  __IO uint32_t HRXP;
  __IO uint32_t HRXA;
  __IO uint32_t HRXE;
  __IO uint32_t HRXCS;
  __IO uint32_t HSTM;
       uint32_t RESERVED0[16];
  __IO uint32_t HRXFD;
       uint32_t RESERVED1;
  __IO uint32_t HRXFDC_L;
  __IO uint32_t HRXFDC_H;
  __IO uint32_t HRXFC;
       uint32_t RESERVED2[11];
  __IO uint32_t HTXFD;
       uint32_t RESERVED3[3];
  __IO uint32_t HTXFC;
       uint32_t RESERVED4[11];
    MDR_USB_SEP_TypeDef USB_SEP[4];
  __IO uint32_t SC;
  __IO uint32_t SLS;
  __IO uint32_t SIS;
  __IO uint32_t SIM;
  __IO uint32_t SA;
  __IO uint32_t SFN_L;
  __IO uint32_t SFN_H;
       uint32_t RESERVED5[9];
    MDR_USB_SEP_FIFO_TypeDef USB_SEP_FIFO[4];
  __IO uint32_t HSCR;
  __IO uint32_t HSVR;
}MDR_USB_TypeDef;

/** @} */ /* End of group MDR32Fx_Periph_USB_Data_Structures */

/** @defgroup MDR32Fx_Periph_USB_Defines Defines
  * @{
  */

/** @defgroup Periph_USB_HTXC USB HTXC
  * @{
  */

/*-- USB_HTXC: USB HTXC Register -----------------------------------*/
/* Bit field positions: */
#define USB_HTXC_TREQ_Pos                       0
#define USB_HTXC_SOFS_Pos                       1
#define USB_HTXC_PREEN_Pos                      2
#define USB_HTXC_ISOEN_Pos                      3

/* Bit field masks: */
#define USB_HTXC_TREQ                           ((uint32_t)0x00000001)
#define USB_HTXC_SOFS                           ((uint32_t)0x00000002)
#define USB_HTXC_PREEN                          ((uint32_t)0x00000004)
#define USB_HTXC_ISOEN                          ((uint32_t)0x00000008)

/** @} */ /* End of group USB_HTXC */

/** @defgroup Periph_USB_HTXLC  USB HTXLC
  * @{
  */

/*-- USB_HTXLC: USB HTXLC Register ---------------------------------*/
/* Bit field positions: */
#define USB_HTXLC_Pos                           0
#define USB_HTXLC_DC_Pos                        2
#define USB_HTXLC_FSPL_Pos                      3
#define USB_HTXLC_FSLR_Pos                      4

/* Bit field masks: */
#define USB_HTXLC_Msk                           ((uint32_t)0x00000003)
#define USB_HTXLC_DC                            ((uint32_t)0x00000004)
#define USB_HTXLC_FSPL                          ((uint32_t)0x00000008)
#define USB_HTXLC_FSLR                          ((uint32_t)0x00000010)

/** @} */ /* End of group USB_HTXLC */

/** @defgroup Periph_USB_HIS  USB HIS
  * @{
  */

/*-- USB_HIS: USB_HIS Register -------------------------------------*/
/* Bit field positions: */
#define USB_HIS_TDONE_Pos                       0
#define USB_HIS_RESUME_Pos                      1
#define USB_HIS_CONEV_Pos                       2
#define USB_HIS_SOFS_Pos                        3

/* Bit field masks: */
#define USB_HIS_TDONE                           ((uint32_t)0x00000001)
#define USB_HIS_RESUME                          ((uint32_t)0x00000002)
#define USB_HIS_CONEV                           ((uint32_t)0x00000004)
#define USB_HIS_SOFS                            ((uint32_t)0x00000008)

/** @} */ /* End of group USB_HIS */

/** @defgroup Periph_USB_HIM  USB HIM
  * @{
  */

/*-- USB_HIM: USB_HIM Register -------------------------------------*/
/* Bit field positions: */
#define USB_HIM_TDONEIE_Pos                     0
#define USB_HIM_RESUMEIE_Pos                    1
#define USB_HIM_CONEVIE_Pos                     2
#define USB_HIM_SOFIE_Pos                       3

/* Bit field masks: */
#define USB_HIM_TDONEIE                         ((uint32_t)0x00000001)
#define USB_HIM_RESUMEIE                        ((uint32_t)0x00000002)
#define USB_HIM_CONEVIE                         ((uint32_t)0x00000004)
#define USB_HIM_SOFIE                           ((uint32_t)0x00000008)

/** @} */ /* End of group USB_HIM */

/** @defgroup Periph_USB_HRXS USB HRXS
  * @{
  */

/*-- USB_HRXS: USB_HRXS Register -----------------------------------*/
/* Bit field positions: */
#define USB_HRXS_CRCERR_Pos                     0
#define USB_HRXS_BSERR_Pos                      1
#define USB_HRXS_RXOF_Pos                       2
#define USB_HRXS_RXTO_Pos                       3
#define USB_HRXS_NAKRXED_Pos                    4
#define USB_HRXS_STALLRXED_Pos                  5
#define USB_HRXS_ACKRXED_Pos                    6
#define USB_HRXS_DATASEQ_Pos                    7

/* Bit field masks: */
#define USB_HRXS_CRCERR                         ((uint32_t)0x00000001)
#define USB_HRXS_BSERR                          ((uint32_t)0x00000002)
#define USB_HRXS_RXOF                           ((uint32_t)0x00000004)
#define USB_HRXS_RXTO                           ((uint32_t)0x00000008)
#define USB_HRXS_NAKRXED                        ((uint32_t)0x00000010)
#define USB_HRXS_STALLRXED                      ((uint32_t)0x00000020)
#define USB_HRXS_ACKRXED                        ((uint32_t)0x00000040)
#define USB_HRXS_DATASEQ                        ((uint32_t)0x00000080)

/** @} */ /* End of group USB_HRXS */

/** @defgroup Periph_USB_SEP_CTRL USB SEP CTRL
  * @{
  */

/*-- USB_SEP_CTRL: USB_SEP Control Register ------------------------*/
/* Bit field positions: */
#define USB_SEP_CTRL_EPEN_Pos                   0
#define USB_SEP_CTRL_EPRDY_Pos                  1
#define USB_SEP_CTRL_EPDATASEQ_Pos              2
#define USB_SEP_CTRL_EPSSTALL_Pos               3
#define USB_SEP_CTRL_EPISOEN_Pos                4

/* Bit field masks: */
#define USB_SEP_CTRL_EPEN                       ((uint32_t)0x00000001)
#define USB_SEP_CTRL_EPRDY                      ((uint32_t)0x00000002)
#define USB_SEP_CTRL_EPDATASEQ                  ((uint32_t)0x00000004)
#define USB_SEP_CTRL_EPSSTALL                   ((uint32_t)0x00000008)
#define USB_SEP_CTRL_EPISOEN                    ((uint32_t)0x00000010)

/** @} */ /* End of group USB_SEP_CTRL */

/** @defgroup Periph_USB_SEP_STS  USB SEP STS
  * @{
  */

/*-- USB_SEP_STS: USB_SEP Status Register --------------------------*/
/* Bit field positions: */
#define USB_SEP_STS_SCCRCERR_Pos                0
#define USB_SEP_STS_SCBSERR_Pos                 1
#define USB_SEP_STS_SCRXOF_Pos                  2
#define USB_SEP_STS_SCRXTO_Pos                  3
#define USB_SEP_STS_SCNAKSENT_Pos               4
#define USB_SEP_STS_SCSTALLSENT_Pos             5
#define USB_SEP_STS_SCACKRXED_Pos               6
#define USB_SEP_STS_SCDATASEQ_Pos               7

/* Bit field masks: */
#define USB_SEP_STS_SCCRCERR                    ((uint32_t)0x00000001)
#define USB_SEP_STS_SCBSERR                     ((uint32_t)0x00000002)
#define USB_SEP_STS_SCRXOF                      ((uint32_t)0x00000004)
#define USB_SEP_STS_SCRXTO                      ((uint32_t)0x00000008)
#define USB_SEP_STS_SCNAKSENT                   ((uint32_t)0x00000010)
#define USB_SEP_STS_SCSTALLSENT                 ((uint32_t)0x00000020)
#define USB_SEP_STS_SCACKRXED                   ((uint32_t)0x00000040)
#define USB_SEP_STS_SCDATASEQ                   ((uint32_t)0x00000080)

/** @} */ /* End of group USB_SEP_STS */

/** @defgroup Periph_USB_SC USB SC
  * @{
  */

/*-- USB_SC: USB_SC Register ---------------------------------------*/
/* Bit field positions: */
#define USB_SCGEN_Pos                           0
#define USB_SCTXLS_Pos                          1
#define USB_SCDC_Pos                            3
#define USB_SCFSP_Pos                           4
#define USB_SCFSR_Pos                           5

/* Bit field masks: */
#define USB_SCGEN                               ((uint32_t)0x00000001)
#define USB_SCTXLS_Msk                          ((uint32_t)0x00000006)
#define USB_SCDC                                ((uint32_t)0x00000008)
#define USB_SCFSP                               ((uint32_t)0x00000010)
#define USB_SCFSR                               ((uint32_t)0x00000020)

/** @} */ /* End of group USB_SC */

/** @defgroup Periph_USB_SIS  USB SIS
  * @{
  */

/*-- USB_SIS: USB_SIS Register -------------------------------------*/
/* Bit field positions: */
#define USB_SIS_SCTDONE_Pos                     0
#define USB_SIS_SCRESUME_Pos                    1
#define USB_SIS_SCRESETEV_Pos                   2
#define USB_SIS_SCSOFREC_Pos                    3
#define USB_SIS_SCNAKSENT_Pos                   4
#define USB_SIS_SCUSBON_Pos                     5

/* Bit field masks: */
#define USB_SIS_SCTDONE                         ((uint32_t)0x00000001)
#define USB_SIS_SCRESUME                        ((uint32_t)0x00000002)
#define USB_SIS_SCRESETEV                       ((uint32_t)0x00000004)
#define USB_SIS_SCSOFREC                        ((uint32_t)0x00000008)
#define USB_SIS_SCNAKSENT                       ((uint32_t)0x00000010)
#define USB_SIS_SCUSBON                         ((uint32_t)0x00000020)

/** @} */ /* End of group USB_SIS */

/** @defgroup Periph_USB_SIM  USB SIM
  * @{
  */

/*-- USB_SIM: USB_SIM Register -------------------------------------*/
/* Bit field positions: */
#define USB_SIM_SCTDONEIE_Pos                   0
#define USB_SIM_SCRESUMEIE_Pos                  1
#define USB_SIM_SCRESETEVIE_Pos                 2
#define USB_SIM_SCSOFRECIE_Pos                  3
#define USB_SIM_SCNAKSENTIE_Pos                 4

/* Bit field masks: */
#define USB_SIM_SCTDONEIE                       ((uint32_t)0x00000001)
#define USB_SIM_SCRESUMEIE                      ((uint32_t)0x00000002)
#define USB_SIM_SCRESETEVIE                     ((uint32_t)0x00000004)
#define USB_SIM_SCSOFRECIE                      ((uint32_t)0x00000008)
#define USB_SIM_SCNAKSENTIE                     ((uint32_t)0x00000010)

/** @} */ /* End of group USB_SIM */

/** @defgroup Periph_USB_HSCR USB HSCR
  * @{
  */

/*-- USB_HSCR: USB_HSCR Register -----------------------------------*/
/* Bit field positions: */
#define USB_HSCR_HOST_MODE_Pos                  0
#define USB_HSCR_RESET_CORE_Pos                 1
#define USB_HSCR_EN_TX_Pos                      2
#define USB_HSCR_EN_RX_Pos                      3
#define USB_HSCR_DP_PULLUP_Pos                  4
#define USB_HSCR_DP_PULLDOWN_Pos                5
#define USB_HSCR_DM_PULLUP_Pos                  6
#define USB_HSCR_DM_PULLDOWN_Pos                7

/* Bit field masks: */
#define USB_HSCR_HOST_MODE                      ((uint32_t)0x00000001)
#define USB_HSCR_RESET_CORE                     ((uint32_t)0x00000002)
#define USB_HSCR_EN_TX                          ((uint32_t)0x00000004)
#define USB_HSCR_EN_RX                          ((uint32_t)0x00000008)
#define USB_HSCR_DP_PULLUP                      ((uint32_t)0x00000010)
#define USB_HSCR_DP_PULLDOWN                    ((uint32_t)0x00000020)
#define USB_HSCR_DM_PULLUP                      ((uint32_t)0x00000040)
#define USB_HSCR_DM_PULLDOWN                    ((uint32_t)0x00000080)

/** @} */ /* End of group USB_HSCR */

/** @defgroup Periph_USB_HSVR USB HSVR
  * @{
  */

/*-- USB_HSVR: USB_HSVR Register -----------------------------------*/
/* Bit field positions: */
#define USB_HSVR_VERSION_Pos                    0
#define USB_HSVR_REVISION_Pos                   4

/* Bit field masks: */
#define USB_HSVR_VERSION_Msk                    ((uint32_t)0x0000000F)
#define USB_HSVR_REVISION_Msk                   ((uint32_t)0x000000F0)

/** @} */ /* End of group USB_HSVR */

/** @} */ /* End of group MDR32Fx_Periph_USB_Defines */

/** @} */ /* End of group MDR32Fx_Periph_USB */

/** @defgroup MDR32Fx_Periph_EEPROM EEPROM
  * @{
  */

/** @defgroup MDR32Fx_Periph_EEPROM_Data_Structures Data Structures
  * @{
  */

/* MDR_EEPROM_TypeDef structure */
typedef struct
{
  __IO uint32_t CMD;
  __IO uint32_t ADR;
  __IO uint32_t DI;
  __IO uint32_t DO;
  __IO uint32_t KEY;
}MDR_EEPROM_TypeDef;

/** @} */ /* End of group MDR32Fx_Periph_EEPROM_Data_Structures */

/** @defgroup MDR32Fx_Periph_EEPROM_Defines Defines
  * @{
  */

/** @defgroup Periph_EEPROM_CMD EEPROM CMD
  * @{
  */

/*-- EEPROM_CMD: EEPROM Command Register ---------------------------*/
/* Bit field positions: */
#define EEPROM_CMD_CON_Pos                      0
#define EEPROM_CMD_WR_Pos                       1
#define EEPROM_CMD_RD_Pos                       2
#define EEPROM_CMD_DELAY_Pos                    3
#define EEPROM_CMD_XE_Pos                       6
#define EEPROM_CMD_YE_Pos                       7
#define EEPROM_CMD_SE_Pos                       8
#define EEPROM_CMD_IFREN_Pos                    9
#define EEPROM_CMD_ERASE_Pos                    10
#define EEPROM_CMD_MAS1_Pos                     11
#define EEPROM_CMD_PROG_Pos                     12
#define EEPROM_CMD_NVSTR_Pos                    13

/* Bit field masks: */
#define EEPROM_CMD_CON                          ((uint32_t)0x00000001)
#define EEPROM_CMD_WR                           ((uint32_t)0x00000002)
#define EEPROM_CMD_RD                           ((uint32_t)0x00000004)
#define EEPROM_CMD_DELAY_Msk                    ((uint32_t)0x00000038)
#define EEPROM_CMD_XE                           ((uint32_t)0x00000040)
#define EEPROM_CMD_YE                           ((uint32_t)0x00000080)
#define EEPROM_CMD_SE                           ((uint32_t)0x00000100)
#define EEPROM_CMD_IFREN                        ((uint32_t)0x00000200)
#define EEPROM_CMD_ERASE                        ((uint32_t)0x00000400)
#define EEPROM_CMD_MAS1                         ((uint32_t)0x00000800)
#define EEPROM_CMD_PROG                         ((uint32_t)0x00001000)
#define EEPROM_CMD_NVSTR                        ((uint32_t)0x00002000)

/* EEPROM Key */
#define EEPROM_KEY                              0x8AAA5551

#define EEPROM_ADDRESS                          0x08000000

#define EEPROM_SECTOR_A_SHIFT                   0x00
#define EEPROM_SECTOR_B_SHIFT                   0x04
#define EEPROM_SECTOR_C_SHIFT                   0x08
#define EEPROM_SECTOR_D_SHIFT                   0x0C

#define EEPROM_WORD_SIZE                        4
#define EEPROM_PAGE_SIZE                        4096

/** @} */ /* End of group EEPROM_CMD */

/** @} */ /* End of group MDR32Fx_Periph_EEPROM_Defines */

/** @} */ /* End of group MDR32Fx_Periph_EEPROM */

/** @defgroup MDR32Fx_Periph_RST_CLK RST_CLK
  * @{
  */

/** @defgroup MDR32Fx_Periph_RST_CLK_Data_Structures Data Structures
  * @{
  */

/* MDR_RST_CLK_TypeDef structure */
typedef struct
{
  __IO uint32_t CLOCK_STATUS;
  __IO uint32_t PLL_CONTROL;
  __IO uint32_t HS_CONTROL;
  __IO uint32_t CPU_CLOCK;
  __IO uint32_t USB_CLOCK;
  __IO uint32_t ADC_MCO_CLOCK;
  __IO uint32_t RTC_CLOCK;
  __IO uint32_t PER_CLOCK;
  __IO uint32_t CAN_CLOCK;
  __IO uint32_t TIM_CLOCK;
  __IO uint32_t UART_CLOCK;
  __IO uint32_t SSP_CLOCK;
}MDR_RST_CLK_TypeDef;

/** @} */ /* End of group MDR32Fx_Periph_RST_CLK_Data_Structures */

/** @defgroup MDR32Fx_Periph_RST_CLK_Defines Defines
  * @{
  */

/** @defgroup Periph_RST_CLK_CLOCK_STATUS RST CLK CLOCK STATUS
  * @{
  */

/*-- RST_CLK_CLOCK_STATUS: Clock Status Register -------------------*/
/* Bit field positions: */
#define RST_CLK_CLOCK_STATUS_PLL_USB_RDY_Pos    0
#define RST_CLK_CLOCK_STATUS_PLL_CPU_RDY_Pos    1
#define RST_CLK_CLOCK_STATUS_HSE_RDY_Pos        2

/* Bit field masks: */
#define RST_CLK_CLOCK_STATUS_PLL_USB_RDY        ((uint32_t)0x00000001)
#define RST_CLK_CLOCK_STATUS_PLL_CPU_RDY        ((uint32_t)0x00000002)
#define RST_CLK_CLOCK_STATUS_HSE_RDY            ((uint32_t)0x00000004)

/** @} */ /* End of group RST_CLK_CLOCK_STATUS */

/** @defgroup Periph_RST_CLK_PLL_CONTROL  RST CLK PLL CONTROL
  * @{
  */

/*-- RST_CLK_PLL_CONTROL: PLL Control Register ---------------------*/
/* Bit field positions: */
#define RST_CLK_PLL_CONTROL_PLL_USB_ON_Pos      0
#define RST_CLK_PLL_CONTROL_PLL_USB_RLD_Pos     1
#define RST_CLK_PLL_CONTROL_PLL_CPU_ON_Pos      2
#define RST_CLK_PLL_CONTROL_PLL_CPU_PLD_Pos     3
#define RST_CLK_PLL_CONTROL_PLL_USB_MUL_Pos     4
#define RST_CLK_PLL_CONTROL_PLL_CPU_MUL_Pos     8

/* Bit field masks: */
#define RST_CLK_PLL_CONTROL_PLL_USB_ON          ((uint32_t)0x00000001)
#define RST_CLK_PLL_CONTROL_PLL_USB_RLD         ((uint32_t)0x00000002)
#define RST_CLK_PLL_CONTROL_PLL_CPU_ON          ((uint32_t)0x00000004)
#define RST_CLK_PLL_CONTROL_PLL_CPU_PLD         ((uint32_t)0x00000008)
#define RST_CLK_PLL_CONTROL_PLL_USB_MUL_Msk     ((uint32_t)0x000000F0)
#define RST_CLK_PLL_CONTROL_PLL_CPU_MUL_Msk     ((uint32_t)0x00000F00)

/** @} */ /* End of group RST_CLK_PLL_CONTROL */

/** @defgroup Periph_RST_CLK_HS_CONTROL RST CLK HS CONTROL
  * @{
  */

/*-- RST_CLK_HS_CONTROL: HS Control Register -----------------------*/
/* Bit field positions: */
#define RST_CLK_HS_CONTROL_HSE_ON_Pos           0
#define RST_CLK_HS_CONTROL_HSE_BYP_Pos          1

/* Bit field masks: */
#define RST_CLK_HS_CONTROL_HSE_ON               ((uint32_t)0x00000001)
#define RST_CLK_HS_CONTROL_HSE_BYP              ((uint32_t)0x00000002)

/** @} */ /* End of group RST_CLK_HS_CONTROL */

/** @defgroup Periph_RST_CLK_CPU_CLOCK  RST CLK CPU CLOCK
  * @{
  */

/*-- RST_CLK_CPU_CLOCK: CPU Clock Register -------------------------*/
/* Bit field positions: */
#define RST_CLK_CPU_CLOCK_CPU_C1_SEL_Pos        0
#define RST_CLK_CPU_CLOCK_CPU_C2_SEL_Pos        2
#define RST_CLK_CPU_CLOCK_CPU_C3_SEL_Pos        4
#define RST_CLK_CPU_CLOCK_HCLK_SEL_Pos          8

/* Bit field masks: */
#define RST_CLK_CPU_CLOCK_CPU_C1_SEL_Msk        ((uint32_t)0x00000003)
#define RST_CLK_CPU_CLOCK_CPU_C2_SEL            ((uint32_t)0x00000004)
#define RST_CLK_CPU_CLOCK_CPU_C3_SEL_Msk        ((uint32_t)0x000000F0)
#define RST_CLK_CPU_CLOCK_HCLK_SEL_Msk          ((uint32_t)0x00000300)

/* CPU C1 SEL Modes */
#define RST_CLK_CPU_CLOCK_CPU_C1_SEL_HSI              0x00
#define RST_CLK_CPU_CLOCK_CPU_C1_SEL_HSI_DIV_2        0x01
#define RST_CLK_CPU_CLOCK_CPU_C1_SEL_HSE              0x02
#define RST_CLK_CPU_CLOCK_CPU_C1_SEL_HSE_DIV_2        0x03

/* CPU C2 SEL Modes */
#define RST_CLK_CPU_CLOCK_CPU_C2_SEL_CPU_C1           0x00
#define RST_CLK_CPU_CLOCK_CPU_C2_SEL_PLL_CPU          0x01

/* CPU C3 SEL Modes */
#define RST_CLK_CPU_CLOCK_CPU_C3_SEL_CPU_C2           0x00
#define RST_CLK_CPU_CLOCK_CPU_C3_SEL_CPU_C2_DIV_2     0x08
#define RST_CLK_CPU_CLOCK_CPU_C3_SEL_CPU_C2_DIV_4     0x09
#define RST_CLK_CPU_CLOCK_CPU_C3_SEL_CPU_C2_DIV_8     0x0A
#define RST_CLK_CPU_CLOCK_CPU_C3_SEL_CPU_C2_DIV_16    0x0B
#define RST_CLK_CPU_CLOCK_CPU_C3_SEL_CPU_C2_DIV_32    0x0C
#define RST_CLK_CPU_CLOCK_CPU_C3_SEL_CPU_C2_DIV_64    0x0D
#define RST_CLK_CPU_CLOCK_CPU_C3_SEL_CPU_C2_DIV_128   0x0E
#define RST_CLK_CPU_CLOCK_CPU_C3_SEL_CPU_C2_DIV_256   0x0F

/* HCLK SEL Modes */
#define RST_CLK_CPU_CLOCK_HCLK_SEL_HSI                0x00
#define RST_CLK_CPU_CLOCK_HCLK_SEL_CPU_C3             0x01
#define RST_CLK_CPU_CLOCK_HCLK_SEL_LSE                0x02
#define RST_CLK_CPU_CLOCK_HCLK_SEL_LSI                0x03

/** @} */ /* End of group RST_CLK_CPU_CLOCK */

/** @defgroup Periph_RST_CLK_USB_CLOCK  RST CLK USB CLOCK
  * @{
  */

/*-- RST_CLK_USB_CLOCK: USB Clock Register -------------------------*/
/* Bit field positions: */
#define RST_CLK_USB_CLOCK_USB_C1_SEL_Pos        0
#define RST_CLK_USB_CLOCK_USB_C2_SEL_Pos        2
#define RST_CLK_USB_CLOCK_USB_C3_SEL_Pos        4
#define RST_CLK_USB_CLOCK_USB_CLK_EN_Pos        8

/* Bit field masks: */
#define RST_CLK_USB_CLOCK_USB_C1_SEL_Msk        ((uint32_t)0x00000003)
#define RST_CLK_USB_CLOCK_USB_C2_SEL            ((uint32_t)0x00000004)
#define RST_CLK_USB_CLOCK_USB_C3_SEL            ((uint32_t)0x00000010)
#define RST_CLK_USB_CLOCK_USB_CLK_EN            ((uint32_t)0x00000100)

/* USB C1 SEL Modes */
#define RST_CLK_USB_CLOCK_USB_C1_SEL_HSI            0x00
#define RST_CLK_USB_CLOCK_USB_C1_SEL_HSI_DIV_2      0x01
#define RST_CLK_USB_CLOCK_USB_C1_SEL_HSE            0x02
#define RST_CLK_USB_CLOCK_USB_C1_SEL_HSE_DIV_2      0x03

/* USB C2 SEL Modes */
#define RST_CLK_USB_CLOCK_USB_C2_SEL_USB_C1         0x00
#define RST_CLK_USB_CLOCK_USB_C2_SEL_PLL_USB        0x01

/* USB C3 SEL Modes */
#define RST_CLK_USB_CLOCK_USB_C3_SEL_USB_C2         0x00
#define RST_CLK_USB_CLOCK_USB_C3_SEL_USB_C2_DIV_2   0x01

/** @} */ /* End of group RST_CLK_USB_CLOCK */

/** @defgroup Periph_RST_CLK_ADC_MCO_CLOCK  RST CLK ADC MCO CLOCK
  * @{
  */

/*-- RST_CLK_ADC_MCO_CLOCK: ADC Clock Register ---------------------*/
/* Bit field positions: */
#define RST_CLK_ADC_MCO_CLOCK_ADC_C1_SEL_Pos    0
#define RST_CLK_ADC_MCO_CLOCK_ADC_C2_SEL_Pos    4
#define RST_CLK_ADC_MCO_CLOCK_ADC_C3_SEL_Pos    8
#define RST_CLK_ADC_MCO_CLOCK_ADC_CLK_EN_Pos    13

/* Bit field masks: */
#define RST_CLK_ADC_MCO_CLOCK_ADC_C1_SEL_Msk    ((uint32_t)0x00000003)
#define RST_CLK_ADC_MCO_CLOCK_ADC_C2_SEL_Msk    ((uint32_t)0x00000030)
#define RST_CLK_ADC_MCO_CLOCK_ADC_C3_SEL_Msk    ((uint32_t)0x00000F00)
#define RST_CLK_ADC_MCO_CLOCK_ADC_CLK_EN        ((uint32_t)0x00002000)

/* ADC C1 SEL Modes */
#define RST_CLK_ADC_MCO_CLOCK_ADC_C1_SEL_CPU_C1           0x00
#define RST_CLK_ADC_MCO_CLOCK_ADC_C1_SEL_USB_C1           0x01
#define RST_CLK_ADC_MCO_CLOCK_ADC_C1_SEL_CPU_C2           0x02
#define RST_CLK_ADC_MCO_CLOCK_ADC_C1_SEL_USB_C2           0x03

/* ADC C2 SEL Modes */
#define RST_CLK_ADC_MCO_CLOCK_ADC_C2_SEL_LSE              0x00
#define RST_CLK_ADC_MCO_CLOCK_ADC_C2_SEL_LSI              0x01
#define RST_CLK_ADC_MCO_CLOCK_ADC_C2_SEL_ADC_C1           0x02
#define RST_CLK_ADC_MCO_CLOCK_ADC_C2_SEL_HSI_C1           0x03

/* ADC C3 SEL Modes */
#define RST_CLK_ADC_MCO_CLOCK_ADC_C3_SEL_ADC_C2           0x00
#define RST_CLK_ADC_MCO_CLOCK_ADC_C3_SEL_ADC_C2_DIV_2     0x08
#define RST_CLK_ADC_MCO_CLOCK_ADC_C3_SEL_ADC_C2_DIV_4     0x09
#define RST_CLK_ADC_MCO_CLOCK_ADC_C3_SEL_ADC_C2_DIV_8     0x0A
#define RST_CLK_ADC_MCO_CLOCK_ADC_C3_SEL_ADC_C2_DIV_16    0x0B
#define RST_CLK_ADC_MCO_CLOCK_ADC_C3_SEL_ADC_C2_DIV_32    0x0C
#define RST_CLK_ADC_MCO_CLOCK_ADC_C3_SEL_ADC_C2_DIV_64    0x0D
#define RST_CLK_ADC_MCO_CLOCK_ADC_C3_SEL_ADC_C2_DIV_128   0x0E
#define RST_CLK_ADC_MCO_CLOCK_ADC_C3_SEL_ADC_C2_DIV_256   0x0F

/** @} */ /* End of group RST_CLK_ADC_MCO_CLOCK */

/** @defgroup Periph_RST_CLK_RTC_CLOCK  RST CLK RTC CLOCK
  * @{
  */

/*-- RST_CLK_RTC_CLOCK: RTC Clock Register -------------------------*/
/* Bit field positions: */
#define RST_CLK_RTC_CLOCK_HSE_SEL_Pos           0
#define RST_CLK_RTC_CLOCK_HSI_SEL_Pos           4
#define RST_CLK_RTC_CLOCK_HSE_RTC_EN_Pos        8
#define RST_CLK_RTC_CLOCK_HSI_RTC_EN_Pos        9

/* Bit field masks: */
#define RST_CLK_RTC_CLOCK_HSE_SEL_Msk           ((uint32_t)0x0000000F)
#define RST_CLK_RTC_CLOCK_HSI_SEL_Msk           ((uint32_t)0x000000F0)
#define RST_CLK_RTC_CLOCK_HSE_RTC_EN            ((uint32_t)0x00000100)
#define RST_CLK_RTC_CLOCK_HSI_RTC_EN            ((uint32_t)0x00000200)

/* HSE SEL Modes */
#define RST_CLK_RTC_CLOCK_HSE_SEL_HSE           0x00
#define RST_CLK_RTC_CLOCK_HSE_SEL_HSE_DIV_2     0x08
#define RST_CLK_RTC_CLOCK_HSE_SEL_HSE_DIV_4     0x09
#define RST_CLK_RTC_CLOCK_HSE_SEL_HSE_DIV_8     0x0A
#define RST_CLK_RTC_CLOCK_HSE_SEL_HSE_DIV_16    0x0B
#define RST_CLK_RTC_CLOCK_HSE_SEL_HSE_DIV_32    0x0C
#define RST_CLK_RTC_CLOCK_HSE_SEL_HSE_DIV_64    0x0D
#define RST_CLK_RTC_CLOCK_HSE_SEL_HSE_DIV_128   0x0E
#define RST_CLK_RTC_CLOCK_HSE_SEL_HSE_DIV_256   0x0F

/* HSI SEL Modes */
#define RST_CLK_RTC_CLOCK_HSI_SEL_HSI           0x00
#define RST_CLK_RTC_CLOCK_HSI_SEL_HSI_DIV_2     0x08
#define RST_CLK_RTC_CLOCK_HSI_SEL_HSI_DIV_4     0x09
#define RST_CLK_RTC_CLOCK_HSI_SEL_HSI_DIV_8     0x0A
#define RST_CLK_RTC_CLOCK_HSI_SEL_HSI_DIV_16    0x0B
#define RST_CLK_RTC_CLOCK_HSI_SEL_HSI_DIV_32    0x0C
#define RST_CLK_RTC_CLOCK_HSI_SEL_HSI_DIV_64    0x0D
#define RST_CLK_RTC_CLOCK_HSI_SEL_HSI_DIV_128   0x0E
#define RST_CLK_RTC_CLOCK_HSI_SEL_HSI_DIV_256   0x0F

/** @} */ /* End of group RST_CLK_RTC_CLOCK */

/** @defgroup Periph_RST_CLK_CAN_CLOCK  RST CLK CAN CLOCK
  * @{
  */

/*-- RST_CLK_PER_CLOCK: PER Clock Register ---------------------*/
/* Bit field positions: */
#define RST_CLK_PER_CLOCK_PCLK_EN_CAN1_Pos            0
#define RST_CLK_PER_CLOCK_PCLK_EN_CAN2_Pos            1
#define RST_CLK_PER_CLOCK_PCLK_EN_USB_Pos             2
#define RST_CLK_PER_CLOCK_PCLK_EN_EEPROM_CNTRL_Pos    3
#define RST_CLK_PER_CLOCK_PCLK_EN_RST_CLK_Pos         4
#define RST_CLK_PER_CLOCK_PCLK_EN_DMA_Pos             5
#define RST_CLK_PER_CLOCK_PCLK_EN_UART1_Pos           6
#define RST_CLK_PER_CLOCK_PCLK_EN_UART2_Pos           7
#define RST_CLK_PER_CLOCK_PCLK_EN_SPI1_Pos            8
#define RST_CLK_PER_CLOCK_PCLK_EN_I2C_Pos             10
#define RST_CLK_PER_CLOCK_PCLK_EN_POWER_Pos           11
#define RST_CLK_PER_CLOCK_PCLK_EN_WWDT_Pos            12
#define RST_CLK_PER_CLOCK_PCLK_EN_IWDT_Pos            13
#define RST_CLK_PER_CLOCK_PCLK_EN_TIMER1_Pos          14
#define RST_CLK_PER_CLOCK_PCLK_EN_TIMER2_Pos          15
#define RST_CLK_PER_CLOCK_PCLK_EN_TIMER3_Pos          16
#define RST_CLK_PER_CLOCK_PCLK_EN_ADC_Pos             17
#define RST_CLK_PER_CLOCK_PCLK_EN_DAC_Pos             18
#define RST_CLK_PER_CLOCK_PCLK_EN_COMP_Pos            19
#define RST_CLK_PER_CLOCK_PCLK_EN_SPI2_Pos            20
#define RST_CLK_PER_CLOCK_PCLK_EN_PORTA_Pos           21
#define RST_CLK_PER_CLOCK_PCLK_EN_PORTB_Pos           22
#define RST_CLK_PER_CLOCK_PCLK_EN_PORTC_Pos           23
#define RST_CLK_PER_CLOCK_PCLK_EN_PORTD_Pos           24
#define RST_CLK_PER_CLOCK_PCLK_EN_PORTE_Pos           25
#define RST_CLK_PER_CLOCK_PCLK_EN_BKP_Pos             27
#define RST_CLK_PER_CLOCK_PCLK_EN_PORTF_Pos           29
#define RST_CLK_PER_CLOCK_PCLK_EN_EXT_BUS_CNTRL_Pos   30

/* Bit field masks: */
#define RST_CLK_PER_CLOCK_PCLK_EN_CAN1                ((uint32_t)0x00000001)
#define RST_CLK_PER_CLOCK_PCLK_EN_CAN2                ((uint32_t)0x00000002)
#define RST_CLK_PER_CLOCK_PCLK_EN_USB                 ((uint32_t)0x00000004)
#define RST_CLK_PER_CLOCK_PCLK_EN_EEPROM_CNTRL        ((uint32_t)0x00000008)
#define RST_CLK_PER_CLOCK_PCLK_EN_RST_CLK             ((uint32_t)0x00000010)
#define RST_CLK_PER_CLOCK_PCLK_EN_DMA                 ((uint32_t)0x00000020)
#define RST_CLK_PER_CLOCK_PCLK_EN_UART1               ((uint32_t)0x00000040)
#define RST_CLK_PER_CLOCK_PCLK_EN_UART2               ((uint32_t)0x00000080)
#define RST_CLK_PER_CLOCK_PCLK_EN_SPI1                ((uint32_t)0x00000100)
#define RST_CLK_PER_CLOCK_PCLK_EN_I2C                 ((uint32_t)0x00000400)
#define RST_CLK_PER_CLOCK_PCLK_EN_POWER               ((uint32_t)0x00000800)
#define RST_CLK_PER_CLOCK_PCLK_EN_WWDT                ((uint32_t)0x00001000)
#define RST_CLK_PER_CLOCK_PCLK_EN_IWDT                ((uint32_t)0x00002000)
#define RST_CLK_PER_CLOCK_PCLK_EN_TIMER1              ((uint32_t)0x00004000)
#define RST_CLK_PER_CLOCK_PCLK_EN_TIMER2              ((uint32_t)0x00008000)
#define RST_CLK_PER_CLOCK_PCLK_EN_TIMER3              ((uint32_t)0x00010000)
#define RST_CLK_PER_CLOCK_PCLK_EN_ADC                 ((uint32_t)0x00020000)
#define RST_CLK_PER_CLOCK_PCLK_EN_DAC                 ((uint32_t)0x00040000)
#define RST_CLK_PER_CLOCK_PCLK_EN_COMP                ((uint32_t)0x00080000)
#define RST_CLK_PER_CLOCK_PCLK_EN_SPI2                ((uint32_t)0x00100000)
#define RST_CLK_PER_CLOCK_PCLK_EN_PORTA               ((uint32_t)0x00200000)
#define RST_CLK_PER_CLOCK_PCLK_EN_PORTB               ((uint32_t)0x00400000)
#define RST_CLK_PER_CLOCK_PCLK_EN_PORTC               ((uint32_t)0x00800000)
#define RST_CLK_PER_CLOCK_PCLK_EN_PORTD               ((uint32_t)0x01000000)
#define RST_CLK_PER_CLOCK_PCLK_EN_PORTE               ((uint32_t)0x02000000)
#define RST_CLK_PER_CLOCK_PCLK_EN_BKP                 ((uint32_t)0x08000000)
#define RST_CLK_PER_CLOCK_PCLK_EN_PORTF               ((uint32_t)0x20000000)
#define RST_CLK_PER_CLOCK_PCLK_EN_EXT_BUS_CNTRL       ((uint32_t)0x40000000)

/** @} */ /* End of group RST_CLK_PER_CLOCK */

/** @defgroup Periph_RST_CLK_PER_CLOCK  RST CLK PER CLOCK
  * @{
  */

/*-- RST_CLK_CAN_CLOCK: CAN Clock Register -------------------------*/
/* Bit field positions: */
#define RST_CLK_CAN_CLOCK_CAN1_BRG_Pos          0
#define RST_CLK_CAN_CLOCK_CAN2_BRG_Pos          8
#define RST_CLK_CAN_CLOCK_CAN1_CLK_EN_Pos       24
#define RST_CLK_CAN_CLOCK_CAN2_CLK_EN_Pos       25

/* Bit field masks: */
#define RST_CLK_CAN_CLOCK_CAN1_BRG_Msk          ((uint32_t)0x000000FF)
#define RST_CLK_CAN_CLOCK_CAN2_BRG_Msk          ((uint32_t)0x0000FF00)
#define RST_CLK_CAN_CLOCK_CAN1_CLK_EN           ((uint32_t)0x01000000)
#define RST_CLK_CAN_CLOCK_CAN2_CLK_EN           ((uint32_t)0x02000000)

/* CAN BRG Modes */
#define RST_CLK_CAN_CLOCK_CAN_BRG_HCLK          0x00
#define RST_CLK_CAN_CLOCK_CAN_BRG_HCLK_DIV_2    0x01
#define RST_CLK_CAN_CLOCK_CAN_BRG_HCLK_DIV_4    0x02
#define RST_CLK_CAN_CLOCK_CAN_BRG_HCLK_DIV_8    0x03
#define RST_CLK_CAN_CLOCK_CAN_BRG_HCLK_DIV_16   0x04
#define RST_CLK_CAN_CLOCK_CAN_BRG_HCLK_DIV_32   0x05
#define RST_CLK_CAN_CLOCK_CAN_BRG_HCLK_DIV_64   0x06
#define RST_CLK_CAN_CLOCK_CAN_BRG_HCLK_DIV_128  0x07

/** @} */ /* End of group RST_CLK_CAN_CLOCK */

/** @defgroup Periph_RST_CLK_TIM_CLOCK  RST CLK TIM CLOCK
  * @{
  */

/*-- RST_CLK_TIM_CLOCK: Timer Clock Register -----------------------*/
/* Bit field positions: */
#define RST_CLK_TIM_CLOCK_TIM1_BRG_Pos          0
#define RST_CLK_TIM_CLOCK_TIM2_BRG_Pos          8
#define RST_CLK_TIM_CLOCK_TIM3_BRG_Pos          16
#define RST_CLK_TIM_CLOCK_TIM1_CLK_EN_Pos       24
#define RST_CLK_TIM_CLOCK_TIM2_CLK_EN_Pos       25
#define RST_CLK_TIM_CLOCK_TIM3_CLK_EN_Pos       26

/* Bit field masks: */
#define RST_CLK_TIM_CLOCK_TIM1_BRG_Msk          ((uint32_t)0x000000FF)
#define RST_CLK_TIM_CLOCK_TIM2_BRG_Msk          ((uint32_t)0x0000FF00)
#define RST_CLK_TIM_CLOCK_TIM3_BRG_Msk          ((uint32_t)0x00FF0000)
#define RST_CLK_TIM_CLOCK_TIM1_CLK_EN           ((uint32_t)0x01000000)
#define RST_CLK_TIM_CLOCK_TIM2_CLK_EN           ((uint32_t)0x02000000)
#define RST_CLK_TIM_CLOCK_TIM3_CLK_EN           ((uint32_t)0x04000000)

/* TIM BRG Modes */
#define RST_CLK_TIM_CLOCK_TIM_BRG_HCLK          0x00
#define RST_CLK_TIM_CLOCK_TIM_BRG_HCLK_DIV_2    0x01
#define RST_CLK_TIM_CLOCK_TIM_BRG_HCLK_DIV_4    0x02
#define RST_CLK_TIM_CLOCK_TIM_BRG_HCLK_DIV_8    0x03
#define RST_CLK_TIM_CLOCK_TIM_BRG_HCLK_DIV_16   0x04
#define RST_CLK_TIM_CLOCK_TIM_BRG_HCLK_DIV_32   0x05
#define RST_CLK_TIM_CLOCK_TIM_BRG_HCLK_DIV_64   0x06
#define RST_CLK_TIM_CLOCK_TIM_BRG_HCLK_DIV_128  0x07

/** @} */ /* End of group RST_CLK_TIM_CLOCK */

/** @defgroup Periph_RST_CLK_UART_CLOCK RST CLK UART CLOCK
  * @{
  */

/*-- RST_CLK_UART_CLOCK: UART Clock Register -----------------------*/
/* Bit field positions: */
#define RST_CLK_UART_CLOCK_UART1_BRG_Pos        0
#define RST_CLK_UART_CLOCK_UART2_BRG_Pos        8
#define RST_CLK_UART_CLOCK_UART1_CLK_EN_Pos     24
#define RST_CLK_UART_CLOCK_UART2_CLK_EN_Pos     25

/* Bit field masks: */
#define RST_CLK_UART_CLOCK_UART1_BRG_Msk        ((uint32_t)0x000000FF)
#define RST_CLK_UART_CLOCK_UART2_BRG_Msk        ((uint32_t)0x0000FF00)
#define RST_CLK_UART_CLOCK_UART1_CLK_EN         ((uint32_t)0x01000000)
#define RST_CLK_UART_CLOCK_UART2_CLK_EN         ((uint32_t)0x02000000)

/* UART BRG Modes */
#define RST_CLK_UART_CLOCK_UART_BRG_HCLK            0x00
#define RST_CLK_UART_CLOCK_UART_BRG_HCLK_DIV_2      0x01
#define RST_CLK_UART_CLOCK_UART_BRG_HCLK_DIV_4      0x02
#define RST_CLK_UART_CLOCK_UART_BRG_HCLK_DIV_8      0x03
#define RST_CLK_UART_CLOCK_UART_BRG_HCLK_DIV_16     0x04
#define RST_CLK_UART_CLOCK_UART_BRG_HCLK_DIV_32     0x05
#define RST_CLK_UART_CLOCK_UART_BRG_HCLK_DIV_64     0x06
#define RST_CLK_UART_CLOCK_UART_BRG_HCLK_DIV_128    0x07

/** @} */ /* End of group RST_CLK_UART_CLOCK */

/** @defgroup Periph_RST_CLK_SSP_CLOCK  RST CLK SSP CLOCK
  * @{
  */

/*-- RST_CLK_SSP_CLOCK: SSP Clock Register -------------------------*/
/* Bit field positions: */
#define RST_CLK_SSP_CLOCK_SSP1_BRG_Pos          0
#define RST_CLK_SSP_CLOCK_SSP2_BRG_Pos          8
#define RST_CLK_SSP_CLOCK_SSP1_CLK_EN_Pos       24
#define RST_CLK_SSP_CLOCK_SSP2_CLK_EN_Pos       25

/* Bit field masks: */
#define RST_CLK_SSP_CLOCK_SSP1_BRG_Msk          ((uint32_t)0x000000FF)
#define RST_CLK_SSP_CLOCK_SSP2_BRG_Msk          ((uint32_t)0x0000FF00)
#define RST_CLK_SSP_CLOCK_SSP1_CLK_EN           ((uint32_t)0x01000000)
#define RST_CLK_SSP_CLOCK_SSP2_CLK_EN           ((uint32_t)0x02000000)

/* SSP BRG Modes */
#define RST_CLK_SSP_CLOCK_SSP_BRG_HCLK          0x00
#define RST_CLK_SSP_CLOCK_SSP_BRG_HCLK_DIV_2    0x01
#define RST_CLK_SSP_CLOCK_SSP_BRG_HCLK_DIV_4    0x02
#define RST_CLK_SSP_CLOCK_SSP_BRG_HCLK_DIV_8    0x03
#define RST_CLK_SSP_CLOCK_SSP_BRG_HCLK_DIV_16   0x04
#define RST_CLK_SSP_CLOCK_SSP_BRG_HCLK_DIV_32   0x05
#define RST_CLK_SSP_CLOCK_SSP_BRG_HCLK_DIV_64   0x06
#define RST_CLK_SSP_CLOCK_SSP_BRG_HCLK_DIV_128  0x07

/** @} */ /* End of group RST_CLK_SSP_CLOCK */

/** @} */ /* End of group MDR32Fx_Periph_RST_CLK_Defines */

/** @} */ /* End of group MDR32Fx_Periph_RST_CLK */

/** @defgroup MDR32Fx_Periph_DMA DMA
  * @{
  */

/** @defgroup MDR32Fx_Periph_DMA_Data_Structures Data Structures
  * @{
  */

/* MDR_DMA_TypeDef structure */
typedef struct
{
  __IO uint32_t STATUS;
  __IO uint32_t CFG;
  __IO uint32_t CTRL_BASE_PTR;
  __IO uint32_t ALT_CTRL_BASE_PTR;
  __IO uint32_t WAITONREQ_STATUS;
  __IO uint32_t CHNL_SW_REQUEST;
  __IO uint32_t CHNL_USEBURST_SET;
  __IO uint32_t CHNL_USEBURST_CLR;
  __IO uint32_t CHNL_REQ_MASK_SET;
  __IO uint32_t CHNL_REQ_MASK_CLR;
  __IO uint32_t CHNL_ENABLE_SET;
  __IO uint32_t CHNL_ENABLE_CLR;
  __IO uint32_t CHNL_PRI_ALT_SET;
  __IO uint32_t CHNL_PRI_ALT_CLR;
  __IO uint32_t CHNL_PRIORITY_SET;
  __IO uint32_t CHNL_PRIORITY_CLR;
       uint32_t RESERVED0[3];
  __IO uint32_t ERR_CLR;
}MDR_DMA_TypeDef;

/** @} */ /* End of group MDR32Fx_Periph_DMA_Data_Structures */

/** @defgroup MDR32Fx_Periph_DMA_Defines Defines
  * @{
  */

/** @defgroup Periph_DMA_STATUS DMA STATUS
  * @{
  */

/*-- DMA_STATUS: DMA Status Register -------------------------------*/
/* Bit field positions: */
#define DMA_STATUS_MASTER_ENABLE_Pos            0
#define DMA_STATUS_STATE_Pos                    4
#define DMA_STATUS_CHNLS_MINUS1_Pos             16
#define DMA_STATUS_TEST_STATUS_Pos              28

/* Bit field masks: */
#define DMA_STATUS_MASTER_ENABLE                ((uint32_t)0x00000001)
#define DMA_STATUS_STATE_Msk                    ((uint32_t)0x000000F0)
#define DMA_STATUS_CHNLS_MINUS1_Msk             ((uint32_t)0x001F0000)
#define DMA_STATUS_TEST_STATUS_Msk              ((uint32_t)0xF0000000)

/** @} */ /* End of group DMA_STATUS */

/** @defgroup Periph_DMA_CFG  DMA CFG
  * @{
  */

/*-- DMA_CFG: DMA Configuration Register ---------------------------*/
/* Bit field positions: */
#define DMA_CFG_MASTER_ENABLE_Pos               0
#define DMA_CFG_CHNL_PROT_CTRL_Pos              5

/* Bit field masks: */
#define DMA_CFG_MASTER_ENABLE                   ((uint32_t)0x00000001)
#define DMA_CFG_CHNL_PROT_CTRL_Msk              ((uint32_t)0x000000E0)

/** @} */ /* End of group DMA_CFG */

/** @} */ /* End of group MDR32Fx_Periph_DMA_Defines */

/** @} */ /* End of group MDR32Fx_Periph_DMA */

/** @defgroup MDR32Fx_Periph_UART UART
  * @{
  */

/** @defgroup MDR32Fx_Periph_UART_Data_Structures Data Structures
  * @{
  */

/* MDR_UART_TypeDef structure */
typedef struct
{
  __IO uint32_t DR;
  __IO uint32_t RSR_ECR;
       uint32_t RESERVED0[4];
  __IO uint32_t FR;
       uint32_t RESERVED1;
  __IO uint32_t ILPR;
  __IO uint32_t IBRD;
  __IO uint32_t FBRD;
  __IO uint32_t LCR_H;
  __IO uint32_t CR;
  __IO uint32_t IFLS;
  __IO uint32_t IMSC;
  __IO uint32_t RIS;
  __IO uint32_t MIS;
  __IO uint32_t ICR;
  __IO uint32_t DMACR;
}MDR_UART_TypeDef;

/** @} */ /* End of group MDR32Fx_Periph_UART_Data_Structures */

/** @defgroup MDR32Fx_Periph_UART_Defines Defines
  * @{
  */

/** @defgroup Periph_UART_DR  UART DR
  * @{
  */

/*-- UART_DR: UART Data Register -----------------------------------*/
/* Bit field positions: */
#define UART_DR_DATA_Pos                        0
#define UART_DR_FE_Pos                          8
#define UART_DR_PE_Pos                          9
#define UART_DR_BE_Pos                          10
#define UART_DR_OE_Pos                          11

/* Bit field masks: */
#define UART_DR_DATA_Msk                        ((uint32_t)0x000000FF)
#define UART_DR_FE                              ((uint32_t)0x00000100)
#define UART_DR_PE                              ((uint32_t)0x00000200)
#define UART_DR_BE                              ((uint32_t)0x00000400)
#define UART_DR_OE                              ((uint32_t)0x00000800)

/** @} */ /* End of group UART_DR */

/** @defgroup Periph_UART_RSR_ECR UART RSR ECR
  * @{
  */

/*-- UART_RSR_ECR: UART RSR Register -------------------------------*/
/* Bit field positions: */
#define UART_RSR_ECR_FE_Pos                     0
#define UART_RSR_ECR_PE_Pos                     1
#define UART_RSR_ECR_BE_Pos                     2
#define UART_RSR_ECR_OE_Pos                     3

/* Bit field masks: */
#define UART_RSR_ECR_FE                         ((uint32_t)0x00000001)
#define UART_RSR_ECR_PE                         ((uint32_t)0x00000002)
#define UART_RSR_ECR_BE                         ((uint32_t)0x00000004)
#define UART_RSR_ECR_OE                         ((uint32_t)0x00000008)

/** @} */ /* End of group UART_RSR_ECR */

/** @defgroup Periph_UART_FR  UART FR
  * @{
  */

/*-- UART_FR: UART Flag Register -----------------------------------*/
/* Bit field positions: */
#define UART_FR_CTS_Pos                         0
#define UART_FR_DSR_Pos                         1
#define UART_FR_DCD_Pos                         2
#define UART_FR_BUSY_Pos                        3
#define UART_FR_RXFE_Pos                        4
#define UART_FR_TXFF_Pos                        5
#define UART_FR_RXFF_Pos                        6
#define UART_FR_TXFE_Pos                        7
#define UART_FR_RI_Pos                          8

/* Bit field masks: */
#define UART_FR_CTS                             ((uint32_t)0x00000001)
#define UART_FR_DSR                             ((uint32_t)0x00000002)
#define UART_FR_DCD                             ((uint32_t)0x00000004)
#define UART_FR_BUSY                            ((uint32_t)0x00000008)
#define UART_FR_RXFE                            ((uint32_t)0x00000010)
#define UART_FR_TXFF                            ((uint32_t)0x00000020)
#define UART_FR_RXFF                            ((uint32_t)0x00000040)
#define UART_FR_TXFE                            ((uint32_t)0x00000080)
#define UART_FR_RI                              ((uint32_t)0x00000100)

/** @} */ /* End of group UART_FR */

/** @defgroup Periph_UART_LCR_H UART LCR H
  * @{
  */

/*-- UART_LCR_H: UART LCR_H Register -------------------------------*/
/* Bit field positions: */
#define UART_LCR_H_BRK_Pos                      0
#define UART_LCR_H_PEN_Pos                      1
#define UART_LCR_H_EPS_Pos                      2
#define UART_LCR_H_STP2_Pos                     3
#define UART_LCR_H_FEN_Pos                      4
#define UART_LCR_H_WLEN_Pos                     5
#define UART_LCR_H_SPS_Pos                      7

/* Bit field masks: */
#define UART_LCR_H_BRK                          ((uint32_t)0x00000001)
#define UART_LCR_H_PEN                          ((uint32_t)0x00000002)
#define UART_LCR_H_EPS                          ((uint32_t)0x00000004)
#define UART_LCR_H_STP2                         ((uint32_t)0x00000008)
#define UART_LCR_H_FEN                          ((uint32_t)0x00000010)
#define UART_LCR_H_WLEN_Msk                     ((uint32_t)0x00000060)
#define UART_LCR_H_SPS                          ((uint32_t)0x00000080)

/* WLEN Modes */
#define UART_LCR_H_WLEN_5_BITS                  0x00
#define UART_LCR_H_WLEN_6_BITS                  0x01
#define UART_LCR_H_WLEN_7_BITS                  0x02
#define UART_LCR_H_WLEN_8_BITS                  0x03

/** @} */ /* End of group UART_LCR_H */

/** @defgroup Periph_UART_CR  UART CR
  * @{
  */

/*-- UART_CR: UART Command Register --------------------------------*/
/* Bit field positions: */
#define UART_CR_UARTEN_Pos                      0
#define UART_CR_SIREN_Pos                       1
#define UART_CR_SIRLP_Pos                       2
#define UART_CR_LBE_Pos                         7
#define UART_CR_TXE_Pos                         8
#define UART_CR_RXE_Pos                         9
#define UART_CR_DTR_Pos                         10
#define UART_CR_RTS_Pos                         11
#define UART_CR_OUT1_Pos                        12
#define UART_CR_OUT2_Pos                        13
#define UART_CR_RTSEN_Pos                       14
#define UART_CR_CTSEN_Pos                       15

/* Bit field masks: */
#define UART_CR_UARTEN                          ((uint32_t)0x00000001)
#define UART_CR_SIREN                           ((uint32_t)0x00000002)
#define UART_CR_SIRLP                           ((uint32_t)0x00000004)
#define UART_CR_LBE                             ((uint32_t)0x00000080)
#define UART_CR_TXE                             ((uint32_t)0x00000100)
#define UART_CR_RXE                             ((uint32_t)0x00000200)
#define UART_CR_DTR                             ((uint32_t)0x00000400)
#define UART_CR_RTS                             ((uint32_t)0x00000800)
#define UART_CR_OUT1                            ((uint32_t)0x00001000)
#define UART_CR_OUT2                            ((uint32_t)0x00002000)
#define UART_CR_RTSEN                           ((uint32_t)0x00004000)
#define UART_CR_CTSEN                           ((uint32_t)0x00008000)

/** @} */ /* End of group UART_CR */

/** @defgroup Periph_UART_IFLS  UART IFLS
  * @{
  */

/*-- UART_IFLS: UART IFLS Register ---------------------------------*/
/* Bit field positions: */
#define UART_IFLS_TXIFLSEL_Pos                  0
#define UART_IFLS_RXIFLSEL_Pos                  3

/* Bit field masks: */
#define UART_IFLS_TXIFLSEL_Msk                  ((uint32_t)0x00000007)
#define UART_IFLS_RXIFLSEL_Msk                  ((uint32_t)0x00000038)

/* IFLSEL Modes */
#define UART_IFLS_IFLSEL_1_DIV_8              0x00
#define UART_IFLS_IFLSEL_1_DIV_4              0x01
#define UART_IFLS_IFLSEL_1_DIV_2              0x02
#define UART_IFLS_IFLSEL_3_DIV_4              0x03
#define UART_IFLS_IFLSEL_7_DIV_8              0x04

/** @} */ /* End of group UART_IFLS */

/** @defgroup Periph_UART_IMSC  UART IMSC
  * @{
  */

/*-- UART_IMSC: UART Interrupt Mask Register -----------------------*/
/* Bit field positions: */
#define UART_IMSC_RIMIM_Pos                     0
#define UART_IMSC_CTSMIM_Pos                    1
#define UART_IMSC_DCDMIM_Pos                    2
#define UART_IMSC_DSRMIM_Pos                    3
#define UART_IMSC_RXIM_Pos                      4
#define UART_IMSC_TXIM_Pos                      5
#define UART_IMSC_RTIM_Pos                      6
#define UART_IMSC_FEIM_Pos                      7
#define UART_IMSC_PEIM_Pos                      8
#define UART_IMSC_BEIM_Pos                      9
#define UART_IMSC_OEIM_Pos                      10

/* Bit field masks: */
#define UART_IMSC_RIMIM                         ((uint32_t)0x00000001)
#define UART_IMSC_CTSMIM                        ((uint32_t)0x00000002)
#define UART_IMSC_DCDMIM                        ((uint32_t)0x00000004)
#define UART_IMSC_DSRMIM                        ((uint32_t)0x00000008)
#define UART_IMSC_RXIM                          ((uint32_t)0x00000010)
#define UART_IMSC_TXIM                          ((uint32_t)0x00000020)
#define UART_IMSC_RTIM                          ((uint32_t)0x00000040)
#define UART_IMSC_FEIM                          ((uint32_t)0x00000080)
#define UART_IMSC_PEIM                          ((uint32_t)0x00000100)
#define UART_IMSC_BEIM                          ((uint32_t)0x00000200)
#define UART_IMSC_OEIM                          ((uint32_t)0x00000400)

/** @} */ /* End of group UART_IMSC */

/** @defgroup Periph_UART_RIS UART RIS
  * @{
  */

/*-- UART_RIS: UART Interrupt Pending Register ---------------------*/
/* Bit field positions: */
#define UART_RIS_RIRMIS_Pos                     0
#define UART_RIS_CTSRMIS_Pos                    1
#define UART_RIS_DCDRMIS_Pos                    2
#define UART_RIS_DSRRMIS_Pos                    3
#define UART_RIS_RXRIS_Pos                      4
#define UART_RIS_TXRIS_Pos                      5
#define UART_RIS_RTRIS_Pos                      6
#define UART_RIS_FERIS_Pos                      7
#define UART_RIS_PERIS_Pos                      8
#define UART_RIS_BERIS_Pos                      9
#define UART_RIS_OERIS_Pos                      10

/* Bit field masks: */
#define UART_RIS_RIRMIS                         ((uint32_t)0x00000001)
#define UART_RIS_CTSRMIS                        ((uint32_t)0x00000002)
#define UART_RIS_DCDRMIS                        ((uint32_t)0x00000004)
#define UART_RIS_DSRRMIS                        ((uint32_t)0x00000008)
#define UART_RIS_RXRIS                          ((uint32_t)0x00000010)
#define UART_RIS_TXRIS                          ((uint32_t)0x00000020)
#define UART_RIS_RTRIS                          ((uint32_t)0x00000040)
#define UART_RIS_FERIS                          ((uint32_t)0x00000080)
#define UART_RIS_PERIS                          ((uint32_t)0x00000100)
#define UART_RIS_BERIS                          ((uint32_t)0x00000200)
#define UART_RIS_OERIS                          ((uint32_t)0x00000400)

/** @} */ /* End of group UART_RIS */

/** @defgroup Periph_UART_MIS UART MIS
  * @{
  */

/*-- UART_MIS: UART Masked Interrupt Pending Register --------------*/
/* Bit field positions: */
#define UART_MIS_RIMMIS_Pos                     0
#define UART_MIS_CTSMMIS_Pos                    1
#define UART_MIS_DCDMMIS_Pos                    2
#define UART_MIS_DSRMMIS_Pos                    3
#define UART_MIS_RXMIS_Pos                      4
#define UART_MIS_TXMIS_Pos                      5
#define UART_MIS_RTMIS_Pos                      6
#define UART_MIS_FEMIS_Pos                      7
#define UART_MIS_PEMIS_Pos                      8
#define UART_MIS_BEMIS_Pos                      9
#define UART_MIS_OEMIS_Pos                      10

/* Bit field masks: */
#define UART_MIS_RIMMIS                         ((uint32_t)0x00000001)
#define UART_MIS_CTSMMIS                        ((uint32_t)0x00000002)
#define UART_MIS_DCDMMIS                        ((uint32_t)0x00000004)
#define UART_MIS_DSRMMIS                        ((uint32_t)0x00000008)
#define UART_MIS_RXMIS                          ((uint32_t)0x00000010)
#define UART_MIS_TXMIS                          ((uint32_t)0x00000020)
#define UART_MIS_RTMIS                          ((uint32_t)0x00000040)
#define UART_MIS_FEMIS                          ((uint32_t)0x00000080)
#define UART_MIS_PEMIS                          ((uint32_t)0x00000100)
#define UART_MIS_BEMIS                          ((uint32_t)0x00000200)
#define UART_MIS_OEMIS                          ((uint32_t)0x00000400)

/** @} */ /* End of group UART_MIS */

/** @defgroup Periph_UART_ICR UART ICR
  * @{
  */

/*-- UART_ICR: UART Interrupt Clear Register -----------------------*/
/* Bit field positions: */
#define UART_ICR_RIMIC_Pos                      0
#define UART_ICR_CTSMIC_Pos                     1
#define UART_ICR_DCDMIC_Pos                     2
#define UART_ICR_DSRMIC_Pos                     3
#define UART_ICR_RXIC_Pos                       4
#define UART_ICR_TXIC_Pos                       5
#define UART_ICR_RTIC_Pos                       6
#define UART_ICR_FEIC_Pos                       7
#define UART_ICR_PEIC_Pos                       8
#define UART_ICR_BEIC_Pos                       9
#define UART_ICR_OEIC_Pos                       10

/* Bit field masks: */
#define UART_ICR_RIMIC                          ((uint32_t)0x00000001)
#define UART_ICR_CTSMIC                         ((uint32_t)0x00000002)
#define UART_ICR_DCDMIC                         ((uint32_t)0x00000004)
#define UART_ICR_DSRMIC                         ((uint32_t)0x00000008)
#define UART_ICR_RXIC                           ((uint32_t)0x00000010)
#define UART_ICR_TXIC                           ((uint32_t)0x00000020)
#define UART_ICR_RTIC                           ((uint32_t)0x00000040)
#define UART_ICR_FEIC                           ((uint32_t)0x00000080)
#define UART_ICR_PEIC                           ((uint32_t)0x00000100)
#define UART_ICR_BEIC                           ((uint32_t)0x00000200)
#define UART_ICR_OEIC                           ((uint32_t)0x00000400)

/** @} */ /* End of group UART_ICR */

/** @defgroup Periph_UART_DMACR UART DMACR
  * @{
  */

/*-- UART_DMACR: UART DMA Control Register -------------------------*/
/* Bit field positions: */
#define UART_DMACR_RXDMAE_Pos                   0
#define UART_DMACR_TXDMAE_Pos                   1
#define UART_DMACR_DMAONERR_Pos                 2

/* Bit field masks: */
#define UART_DMACR_RXDMAE                       ((uint32_t)0x00000001)
#define UART_DMACR_TXDMAE                       ((uint32_t)0x00000002)
#define UART_DMACR_DMAONERR                     ((uint32_t)0x00000004)

/** @} */ /* End of group UART_DMACR */

/** @} */ /* End of group MDR32Fx_Periph_UART_Defines */

/** @} */ /* End of group MDR32Fx_Periph_UART */

/** @defgroup MDR32Fx_Periph_SSP SSP
  * @{
  */

/** @defgroup MDR32Fx_Periph_SSP_Data_Structures Data Structures
  * @{
  */

/* MDR_SSP_TypeDef structure */
typedef struct
{
  __IO uint32_t CR0;
  __IO uint32_t CR1;
  __IO uint32_t DR;
  __IO uint32_t SR;
  __IO uint32_t CPSR;
  __IO uint32_t IMSC;
  __IO uint32_t RIS;
  __IO uint32_t MIS;
  __IO uint32_t ICR;
  __IO uint32_t DMACR;
}MDR_SSP_TypeDef;

/** @} */ /* End of group MDR32Fx_Periph_SSP_Data_Structures */

/** @defgroup MDR32Fx_Periph_SSP_Defines Defines
  * @{
  */

/** @defgroup Periph_SSP_CR0  SSP CR0
  * @{
  */

/*-- SSP_CR0: SSP Control0 Register --------------------------------*/
/* Bit field positions: */
#define SSP_CR0_DSS_Pos                         0
#define SSP_CR0_FRF_Pos                         4
#define SSP_CR0_SPO_Pos                         6
#define SSP_CR0_SPH_Pos                         7
#define SSP_CR0_SCR_Pos                         8

/* Bit field masks: */
#define SSP_CR0_DSS_Msk                         ((uint32_t)0x0000000F)
#define SSP_CR0_FRF_Msk                         ((uint32_t)0x00000030)
#define SSP_CR0_SPO                             ((uint32_t)0x00000040)
#define SSP_CR0_SPH                             ((uint32_t)0x00000080)
#define SSP_CR0_SCR_Msk                         ((uint32_t)0x0000FF00)

/* DSS Modes */
#define SSP_CR0_DSS_4_BITS                      0x03
#define SSP_CR0_DSS_5_BITS                      0x04
#define SSP_CR0_DSS_6_BITS                      0x05
#define SSP_CR0_DSS_7_BITS                      0x06
#define SSP_CR0_DSS_8_BITS                      0x07
#define SSP_CR0_DSS_9_BITS                      0x08
#define SSP_CR0_DSS_10_BITS                     0x09
#define SSP_CR0_DSS_11_BITS                     0x0A
#define SSP_CR0_DSS_12_BITS                     0x0B
#define SSP_CR0_DSS_13_BITS                     0x0C
#define SSP_CR0_DSS_14_BITS                     0x0D
#define SSP_CR0_DSS_15_BITS                     0x0E
#define SSP_CR0_DSS_16_BITS                     0x0F

/* FRF Modes */
#define SSP_CR0_FRF_SPI_MOT                     0x00
#define SSP_CR0_FRF_SSI_TI                      0x01
#define SSP_CR0_FRF_MW_NS                       0x02

/** @} */ /* End of group SSP_CR0 */

/** @defgroup Periph_SSP_CR1  SSP CR1
  * @{
  */

/*-- SSP_CR1: SSP Control1 Register --------------------------------*/
/* Bit field positions: */
#define SSP_CR1_LBM_Pos                         0
#define SSP_CR1_SSE_Pos                         1
#define SSP_CR1_MS_Pos                          2
#define SSP_CR1_SOD_Pos                         3

/* Bit field masks: */
#define SSP_CR1_LBM                             ((uint32_t)0x00000001)
#define SSP_CR1_SSE                             ((uint32_t)0x00000002)
#define SSP_CR1_MS                              ((uint32_t)0x00000004)
#define SSP_CR1_SOD                             ((uint32_t)0x00000008)

/** @} */ /* End of group SSP_CR1 */

/** @defgroup Periph_SSP_SR SSP SR
  * @{
  */

/*-- SSP_SR: SSP Status Register -----------------------------------*/
/* Bit field positions: */
#define SSP_SR_TFE_Pos                          0
#define SSP_SR_TNF_Pos                          1
#define SSP_SR_RNE_Pos                          2
#define SSP_SR_RFF_Pos                          3
#define SSP_SR_BSY_Pos                          4

/* Bit field masks: */
#define SSP_SR_TFE                              ((uint32_t)0x00000001)
#define SSP_SR_TNF                              ((uint32_t)0x00000002)
#define SSP_SR_RNE                              ((uint32_t)0x00000004)
#define SSP_SR_RFF                              ((uint32_t)0x00000008)
#define SSP_SR_BSY                              ((uint32_t)0x00000010)

/** @} */ /* End of group SSP_SR */

/** @defgroup Periph_SSP_CPSR SSP CPSR
  * @{
  */

/*-- SSP_CPSR: SSP Clock Prescale Register --------------------------------*/
/* Bit field positions: */
#define SSP_CPSR_CPSDVSR_Pos                    0

/* Bit field masks: */
#define SSP_CPSR_CPSDVSR_Msk                    ((uint32_t)0x0000000F)

/** @} */ /* End of group SSP_CPSR */

/** @defgroup Periph_SSP_IMSC SSP IMSC
  * @{
  */

/*-- SSP_IMSC: SSP Interrupt Mask Register -------------------------*/
/* Bit field positions: */
#define SSP_IMSC_RORIM_Pos                      0
#define SSP_IMSC_RTIM_Pos                       1
#define SSP_IMSC_RXIM_Pos                       2
#define SSP_IMSC_TXIM_Pos                       3

/* Bit field masks: */
#define SSP_IMSC_RORIM                          ((uint32_t)0x00000001)
#define SSP_IMSC_RTIM                           ((uint32_t)0x00000002)
#define SSP_IMSC_RXIM                           ((uint32_t)0x00000004)
#define SSP_IMSC_TXIM                           ((uint32_t)0x00000008)

/** @} */ /* End of group SSP_IMSC */

/** @defgroup Periph_SSP_RIS  SSP RIS
  * @{
  */

/*-- SSP_RIS: SSP Interrupt Pending Register -----------------------*/
/* Bit field positions: */
#define SSP_RIS_RORRIS_Pos                      0
#define SSP_RIS_RTRIS_Pos                       1
#define SSP_RIS_RXRIS_Pos                       2
#define SSP_RIS_TXRIS_Pos                       3

/* Bit field masks: */
#define SSP_RIS_RORRIS                          ((uint32_t)0x00000001)
#define SSP_RIS_RTRIS                           ((uint32_t)0x00000002)
#define SSP_RIS_RXRIS                           ((uint32_t)0x00000004)
#define SSP_RIS_TXRIS                           ((uint32_t)0x00000008)

/** @} */ /* End of group SSP_RIS */

/** @defgroup Periph_SSP_MIS  SSP MIS
  * @{
  */

/*-- SSP_MIS: SSP Masked Interrupt Pending Register ----------------*/
/* Bit field positions: */
#define SSP_MIS_RORMIS_Pos                      0
#define SSP_MIS_RTMIS_Pos                       1
#define SSP_MIS_RXMIS_Pos                       2
#define SSP_MIS_TXMIS_Pos                       3

/* Bit field masks: */
#define SSP_MIS_RORMIS                          ((uint32_t)0x00000001)
#define SSP_MIS_RTMIS                           ((uint32_t)0x00000002)
#define SSP_MIS_RXMIS                           ((uint32_t)0x00000004)
#define SSP_MIS_TXMIS                           ((uint32_t)0x00000008)

/** @} */ /* End of group SSP_MIS */

/** @defgroup Periph_SSP_ICR  SSP ICR
  * @{
  */

/*-- SSP_ICR: SSP Interrupt Clear Register -------------------------*/
/* Bit field positions: */
#define SSP_ICR_RORIC_Pos                       0
#define SSP_ICR_RTIC_Pos                        1

/* Bit field masks: */
#define SSP_ICR_RORIC                           ((uint32_t)0x00000001)
#define SSP_ICR_RTIC                            ((uint32_t)0x00000002)

/** @} */ /* End of group SSP_ICR */

/** @defgroup Periph_SSP_DMACR  SSP DMACR
  * @{
  */

/*-- SSP_DMACR: SSP DMA Control Register ---------------------------*/
/* Bit field positions: */
#define SSP_DMACR_RXDMAE_Pos                    0
#define SSP_DMACR_TXDMAE_Pos                    1

/* Bit field masks: */
#define SSP_DMACR_RXDMAE                        ((uint32_t)0x00000001)
#define SSP_DMACR_TXDMAE                        ((uint32_t)0x00000002)

/** @} */ /* End of group SSP_DMACR */

/** @} */ /* End of group MDR32Fx_Periph_SSP_Defines */

/** @} */ /* End of group MDR32Fx_Periph_SSP */

/** @defgroup MDR32Fx_Periph_I2C I2C
  * @{
  */

/** @defgroup MDR32Fx_Periph_I2C_Data_Structures Data Structures
  * @{
  */

/* MDR_I2C_TypeDef structure */
typedef struct
{
  __IO uint32_t PRL;
  __IO uint32_t PRH;
  __IO uint32_t CTR;
  __IO uint32_t RXD;
  __IO uint32_t STA;
  __IO uint32_t TXD;
  __IO uint32_t CMD;
}MDR_I2C_TypeDef;

/** @} */ /* End of group MDR32Fx_Periph_I2C_Data_Structures */

/** @defgroup MDR32Fx_Periph_I2C_Defines Defines
  * @{
  */

/** @defgroup Periph_I2C_CTR  I2C CTR
  * @{
  */

/*-- I2C_CTR: I2C Control Register ---------------------------------*/
/* Bit field positions: */
#define I2C_CTR_S_I2C_Pos                       5
#define I2C_CTR_EN_INT_Pos                      6
#define I2C_CTR_EN_I2C_Pos                      7

/* Bit field masks: */
#define I2C_CTR_S_I2C                           ((uint32_t)0x00000020)
#define I2C_CTR_EN_INT                          ((uint32_t)0x00000040)
#define I2C_CTR_EN_I2C                          ((uint32_t)0x00000080)

/** @} */ /* End of group I2C_CTR */

/** @defgroup Periph_I2C_STA  I2C STA
  * @{
  */

/*-- I2C_STA: I2C Status Register ----------------------------------*/
/* Bit field positions: */
#define I2C_STA_INT_Pos                         0
#define I2C_STA_TR_PROG_Pos                     1
#define I2C_STA_LOST_ARB_Pos                    5
#define I2C_STA_BUSY_Pos                        6
#define I2C_STA_RX_ACK_Pos                      7

/* Bit field masks: */
#define I2C_STA_INT                             ((uint32_t)0x00000001)
#define I2C_STA_TR_PROG                         ((uint32_t)0x00000002)
#define I2C_STA_LOST_ARB                        ((uint32_t)0x00000020)
#define I2C_STA_BUSY                            ((uint32_t)0x00000040)
#define I2C_STA_RX_ACK                          ((uint32_t)0x00000080)

/** @} */ /* End of group I2C_STA */

/** @defgroup Periph_I2C_CMD  I2C CMD
  * @{
  */

/*-- I2C_CMD: I2C Command Register ---------------------------------*/
/* Bit field positions: */
#define I2C_CMD_CLRINT_Pos                      0
#define I2C_CMD_ACK_Pos                         3
#define I2C_CMD_WR_Pos                          4
#define I2C_CMD_RD_Pos                          5
#define I2C_CMD_STOP_Pos                        6
#define I2C_CMD_START_Pos                       7

/* Bit field masks: */
#define I2C_CMD_CLRINT                          ((uint32_t)0x00000001)
#define I2C_CMD_ACK                             ((uint32_t)0x00000008)
#define I2C_CMD_WR                              ((uint32_t)0x00000010)
#define I2C_CMD_RD                              ((uint32_t)0x00000020)
#define I2C_CMD_STOP                            ((uint32_t)0x00000040)
#define I2C_CMD_START                           ((uint32_t)0x00000080)

/** @} */ /* End of group I2C_CMD */

/** @} */ /* End of group MDR32Fx_Periph_I2C_Defines */

/** @} */ /* End of group MDR32Fx_Periph_I2C */

/** @defgroup MDR32Fx_Periph_POWER POWER
  * @{
  */

/** @defgroup MDR32Fx_Periph_POWER_Data_Structures Data Structures
  * @{
  */

/* MDR_POWER_TypeDef structure */
typedef struct
{
  __IO uint32_t PVDCS;
}MDR_POWER_TypeDef;

/** @} */ /* End of group MDR32Fx_Periph_POWER_Data_Structures */

/** @defgroup MDR32Fx_Periph_POWER_Defines Defines
  * @{
  */

/** @defgroup Periph_POWER_PVDCS  POWER PVDCS
  * @{
  */

/*-- POWER_PVDCS: POWER Power Detector Control/Status Register -----*/
/* Bit field positions: */
#define POWER_PVDCS_PVDEN_Pos                   0
#define POWER_PVDCS_PBLS_Pos                    1
#define POWER_PVDCS_PLS_Pos                     3
#define POWER_PVDCS_PVBD_Pos                    6
#define POWER_PVDCS_PVD_Pos                     7
#define POWER_PVDCS_IEPVBD_Pos                  8
#define POWER_PVDCS_IEPVD_Pos                   9
#define POWER_PVDCS_INVB_Pos                    10
#define POWER_PVDCS_INV_Pos                     11

/* Bit field masks: */
#define POWER_PVDCS_PVDEN                       ((uint32_t)0x00000001)
#define POWER_PVDCS_PBLS_Msk                    ((uint32_t)0x00000006)
#define POWER_PVDCS_PLS_Msk                     ((uint32_t)0x00000038)
#define POWER_PVDCS_PVBD                        ((uint32_t)0x00000040)
#define POWER_PVDCS_PVD                         ((uint32_t)0x00000080)
#define POWER_PVDCS_IEPVBD                      ((uint32_t)0x00000100)
#define POWER_PVDCS_IEPVD                       ((uint32_t)0x00000200)
#define POWER_PVDCS_INVB                        ((uint32_t)0x00000400)
#define POWER_PVDCS_INV                         ((uint32_t)0x00000800)

/** @} */ /* End of group POWER_PVDCS */

/** @} */ /* End of group MDR32Fx_Periph_POWER_Defines */

/** @} */ /* End of group MDR32Fx_Periph_POWER */

/** @defgroup MDR32Fx_Periph_WWDG WWDG
  * @{
  */

/** @defgroup MDR32Fx_Periph_WWDG_Data_Structures Data Structures
  * @{
  */

/* MDR_WWDG_TypeDef structure */
typedef struct
{
  __IO uint32_t CR;
  __IO uint32_t CFR;
  __IO uint32_t SR;
}MDR_WWDG_TypeDef;

/** @} */ /* End of group MDR32Fx_Periph_WWDG_Data_Structures */

/** @defgroup MDR32Fx_Periph_WWDG_Defines Defines
  * @{
  */

/** @defgroup Periph_WWDG_CR  WWDG CR
  * @{
  */

/*-- WWDG_CR: WWDG Command Register --------------------------------*/
/* Bit field positions: */
#define WWDG_CR_T_Pos                           0
#define WWDG_CR_WDGA_Pos                        7

/* Bit field masks: */
#define WWDG_CR_T_Msk                           ((uint32_t)0x0000007F)
#define WWDG_CR_WDGA                            ((uint32_t)0x00000080)

/** @} */ /* End of group WWDG_CR */

/** @defgroup Periph_WWDG_CFR WWDG CFR
  * @{
  */

/*-- WWDG_CFR: WWDG Configuration Register -------------------------*/
/* Bit field positions: */
#define WWDG_CFR_W_Pos                          0
#define WWDG_CFR_WGTB_Pos                       7
#define WWDG_CFR_EWI_Pos                        9

/* Bit field masks: */
#define WWDG_CFR_W_Msk                          ((uint32_t)0x0000007F)
#define WWDG_CFR_WGTB_Msk                       ((uint32_t)0x00000180)
#define WWDG_CFR_EWI                            ((uint32_t)0x00000200)

/* WGTB Modes */
#define WWDG_CFR_WGTB_NO_DIV                    0x00
#define WWDG_CFR_WGTB_DIV_2                     0x01
#define WWDG_CFR_WGTB_DIV_4                     0x02
#define WWDG_CFR_WGTB_DIV_8                     0x03

/** @} */ /* End of group WWDG_CFR */

/** @} */ /* End of group MDR32Fx_Periph_WWDG_Defines */

/** @} */ /* End of group MDR32Fx_Periph_WWDG */

/** @defgroup MDR32Fx_Periph_IWDG IWDG
  * @{
  */

/** @defgroup MDR32Fx_Periph_IWDG_Data_Structures Data Structures
  * @{
  */

/* MDR_IWDG_TypeDef structure */
typedef struct
{
  __IO uint32_t KR;
  __IO uint32_t PR;
  __IO uint32_t RLR;
  __IO uint32_t SR;
}MDR_IWDG_TypeDef;

/** @} */ /* End of group MDR32Fx_Periph_IWDG_Data_Structures */

/** @defgroup MDR32Fx_Periph_IWDG_Defines Defines
  * @{
  */

/** @defgroup Periph_IWDG_SR  IWDG SR
  * @{
  */

/*-- IWDG_SR: IWDG Status Register ---------------------------------*/
/* Bit field positions: */
#define IWDG_SR_PVU_Pos                         0
#define IWDG_SR_RVU_Pos                         1

/* Bit field masks: */
#define IWDG_SR_PVU                             ((uint32_t)0x00000001)
#define IWDG_SR_RVU                             ((uint32_t)0x00000002)

/* PR Modes */
#define IWDG_PR_DIV_4                           0x00
#define IWDG_PR_DIV_8                           0x01
#define IWDG_PR_DIV_16                          0x02
#define IWDG_PR_DIV_32                          0x03
#define IWDG_PR_DIV_64                          0x04
#define IWDG_PR_DIV_128                         0x05
#define IWDG_PR_DIV_256                         0x06

/* KR Keys */
#define IWDG_KR_KEY_REG_EN                      0x00005555
#define IWDG_KR_KEY_REWRITE                     0x0000AAAA
#define IWDG_KR_KEY_WORK_EN                     0x0000CCCC

/** @} */ /* End of group IWDG_SR */

/** @} */ /* End of group MDR32Fx_Periph_IWDG_Defines */

/** @} */ /* End of group MDR32Fx_Periph_IWDG */

/** @defgroup MDR32Fx_Periph_TIMER TIMER
  * @{
  */

/** @defgroup MDR32Fx_Periph_TIMER_Data_Structures Data Structures
  * @{
  */

/* MDR_TIMER_TypeDef structure */
typedef struct
{
  __IO uint32_t CNT;
  __IO uint32_t PSG;
  __IO uint32_t ARR;
  __IO uint32_t CNTRL;
  __IO uint32_t CCR1;
  __IO uint32_t CCR2;
  __IO uint32_t CCR3;
  __IO uint32_t CCR4;
  __IO uint32_t CH1_CNTRL;
  __IO uint32_t CH2_CNTRL;
  __IO uint32_t CH3_CNTRL;
  __IO uint32_t CH4_CNTRL;
  __IO uint32_t CH1_CNTRL1;
  __IO uint32_t CH2_CNTRL1;
  __IO uint32_t CH3_CNTRL1;
  __IO uint32_t CH4_CNTRL1;
  __IO uint32_t CH1_DTG;
  __IO uint32_t CH2_DTG;
  __IO uint32_t CH3_DTG;
  __IO uint32_t CH4_DTG;
  __IO uint32_t BRKETR_CNTRL;
  __IO uint32_t STATUS;
  __IO uint32_t IE;
  __IO uint32_t DMA_RE;
  __IO uint32_t CH1_CNTRL2;
  __IO uint32_t CH2_CNTRL2;
  __IO uint32_t CH3_CNTRL2;
  __IO uint32_t CH4_CNTRL2;
  __IO uint32_t CCR11;
  __IO uint32_t CCR21;
  __IO uint32_t CCR31;
  __IO uint32_t CCR41;
}MDR_TIMER_TypeDef;

/** @} */ /* End of group MDR32Fx_Periph_TIMER_Data_Structures */

/** @defgroup MDR32Fx_Periph_TIMER_Defines Defines
  * @{
  */

/** @defgroup Periph_TIMER_CNTRL  TIMER CNTRL
  * @{
  */

/*-- TIMER_CNTRL: Timer Control Register ---------------------------*/
/* Bit field positions: */
#define TIMER_CNTRL_CNT_EN_Pos                  0
#define TIMER_CNTRL_ARRB_EN_Pos                 1
#define TIMER_CNTRL_WR_CMPL_Pos                 2
#define TIMER_CNTRL_DIR_Pos                     3
#define TIMER_CNTRL_FDTS_Pos                    4
#define TIMER_CNTRL_CNT_MODE_Pos                6
#define TIMER_CNTRL_EVENT_SEL_Pos               8

/* Bit field masks: */
#define TIMER_CNTRL_CNT_EN                      ((uint32_t)0x00000001)
#define TIMER_CNTRL_ARRB_EN                     ((uint32_t)0x00000002)
#define TIMER_CNTRL_WR_CMPL                     ((uint32_t)0x00000004)
#define TIMER_CNTRL_DIR                         ((uint32_t)0x00000008)
#define TIMER_CNTRL_FDTS_Msk                    ((uint32_t)0x00000030)
#define TIMER_CNTRL_CNT_MODE_Msk                ((uint32_t)0x000000C0)
#define TIMER_CNTRL_EVENT_SEL_Msk               ((uint32_t)0x00000F00)

/* FDTS Modes */
#define TIMER_CNTRL_FDTS_TIM_CLK                0x00
#define TIMER_CNTRL_FDTS_SECOND_TIM_CLK         0x01
#define TIMER_CNTRL_FDTS_THIRD_TIM_CLK          0x02
#define TIMER_CNTRL_FDTS_FOURTH_TIM_CLK         0x03

/* CNT Modes*/
#define TIMER_CNTRL_CNT_MODE_UP_DIR_0_PSG_0             0x00
#define TIMER_CNTRL_CNT_MODE_DOWN_DIR_1_PSG_0           0x00
#define TIMER_CNTRL_CNT_MODE_UP_DOWN_DIR_AUTO_PSG_0     0x01
#define TIMER_CNTRL_CNT_MODE_UP_DIR_0_EVENT_1           0x02
#define TIMER_CNTRL_CNT_MODE_DOWN_DIR_1_EVENT_1         0x02
#define TIMER_CNTRL_CNT_MODE_UP_DOWN_DIR_AUTO_EVENT_1   0x03

/* EVENT SEL Modes */
#define TIMER_CNTRL_EVENT_SEL_TIM_CLK           0x00
#define TIMER_CNTRL_EVENT_SEL_CNT_ARR_TIM1      0x01
#define TIMER_CNTRL_EVENT_SEL_CNT_ARR_TIM2      0x02
#define TIMER_CNTRL_EVENT_SEL_CNT_ARR_TIM3      0x03
#define TIMER_CNTRL_EVENT_SEL_CH1_MODE1         0x04
#define TIMER_CNTRL_EVENT_SEL_CH2_MODE1         0x05
#define TIMER_CNTRL_EVENT_SEL_CH3_MODE1         0x06
#define TIMER_CNTRL_EVENT_SEL_CH4_MODE1         0x07
#define TIMER_CNTRL_EVENT_SEL_ETR_MODE2         0x08

/** @} */ /* End of group TIMER_CNTRL */

/** @defgroup Periph_TIMER_CH_CNTRL TIMER CH CNTRL
  * @{
  */

/*-- TIMER_CH_CNTRL: Timer Channel Control Register ----------------*/
/* Bit field positions: */
#define TIMER_CH_CNTRL_CHFLTR_Pos               0
#define TIMER_CH_CNTRL_CHSEL_Pos                4
#define TIMER_CH_CNTRL_CHPSC_Pos                6
#define TIMER_CH_CNTRL_OCCE_Pos                 8
#define TIMER_CH_CNTRL_OCCM_Pos                 9
#define TIMER_CH_CNTRL_BRKEN_Pos                12
#define TIMER_CH_CNTRL_ETREN_Pos                13
#define TIMER_CH_CNTRL_WR_CMPL_Pos              14
#define TIMER_CH_CNTRL_CAP_NPWM_Pos             15

/* Bit field masks: */
#define TIMER_CH_CNTRL_CHFLTR_Msk               ((uint32_t)0x0000000F)
#define TIMER_CH_CNTRL_CHSEL_Msk                ((uint32_t)0x00000030)
#define TIMER_CH_CNTRL_CHPSC_Msk                ((uint32_t)0x000000C0)
#define TIMER_CH_CNTRL_OCCE                     ((uint32_t)0x00000100)
#define TIMER_CH_CNTRL_OCCM_Msk                 ((uint32_t)0x00000E00)
#define TIMER_CH_CNTRL_BRKEN                    ((uint32_t)0x00001000)
#define TIMER_CH_CNTRL_ETREN                    ((uint32_t)0x00002000)
#define TIMER_CH_CNTRL_WR_CMPL                  ((uint32_t)0x00004000)
#define TIMER_CH_CNTRL_CAP_NPWM                 ((uint32_t)0x00008000)

/* CHFLTR Modes */
#define TIMER_CH_CNTRL_CHFLTR_1_TRG_TIM_CLK             0x00
#define TIMER_CH_CNTRL_CHFLTR_2_TRG_TIM_CLK             0x01
#define TIMER_CH_CNTRL_CHFLTR_4_TRG_TIM_CLK             0x02
#define TIMER_CH_CNTRL_CHFLTR_8_TRG_TIM_CLK             0x03
#define TIMER_CH_CNTRL_CHFLTR_6_TRG_FDTS_DIV_2          0x04
#define TIMER_CH_CNTRL_CHFLTR_8_TRG_FDTS_DIV_2          0x05
#define TIMER_CH_CNTRL_CHFLTR_6_TRG_FDTS_DIV_4          0x06
#define TIMER_CH_CNTRL_CHFLTR_8_TRG_FDTS_DIV_4          0x07
#define TIMER_CH_CNTRL_CHFLTR_6_TRG_FDTS_DIV_8          0x08
#define TIMER_CH_CNTRL_CHFLTR_8_TRG_FDTS_DIV_8          0x09
#define TIMER_CH_CNTRL_CHFLTR_5_TRG_FDTS_DIV_16         0x0A
#define TIMER_CH_CNTRL_CHFLTR_6_TRG_FDTS_DIV_16         0x0B
#define TIMER_CH_CNTRL_CHFLTR_8_TRG_FDTS_DIV_16         0x0C
#define TIMER_CH_CNTRL_CHFLTR_5_TRG_FDTS_DIV_32         0x0D
#define TIMER_CH_CNTRL_CHFLTR_6_TRG_FDTS_DIV_32         0x0E
#define TIMER_CH_CNTRL_CHFLTR_8_TRG_FDTS_DIV_32         0x0F

/* CHSEL Modes */
#define TIMER_CH_CNTRL_CHSEL_POS_EDGE                   0x00
#define TIMER_CH_CNTRL_CHSEL_NEG_EDGE                   0x01
#define TIMER_CH_CNTRL_CHSEL_POS_EDGE_CH1_FROM_CH2      0x02
#define TIMER_CH_CNTRL_CHSEL_POS_EDGE_CH2_FROM_CH3      0x02
#define TIMER_CH_CNTRL_CHSEL_POS_EDGE_CH3_FROM_CH4      0x02
#define TIMER_CH_CNTRL_CHSEL_POS_EDGE_CH4_FROM_CH1      0x02
#define TIMER_CH_CNTRL_CHSEL_POS_EDGE_CH1_FROM_CH3      0x03
#define TIMER_CH_CNTRL_CHSEL_POS_EDGE_CH2_FROM_CH4      0x03
#define TIMER_CH_CNTRL_CHSEL_POS_EDGE_CH3_FROM_CH1      0x03
#define TIMER_CH_CNTRL_CHSEL_POS_EDGE_CH4_FROM_CH2      0x03

/* CHPSC Modes */
#define TIMER_CH_CNTRL_CHPSC_NO_DIV                     0x00
#define TIMER_CH_CNTRL_CHPSC_DIV_2                      0x01
#define TIMER_CH_CNTRL_CHPSC_DIV_4                      0x02
#define TIMER_CH_CNTRL_CHPSC_DIV_8                      0x03

/* OCCM Modes */
// CCR1 EN = X
#define TIMER_CH_CNTRL_OCCM_REF_0                       0x00
#define TIMER_CH_CNTRL_OCCM_REF_1                       0x05
// CCR1 EN = 0
#define TIMER_CH_CNTRL_OCCM_REF_1_CNT_CCR               0x01
#define TIMER_CH_CNTRL_OCCM_REF_0_CNT_CCR               0x02
#define TIMER_CH_CNTRL_OCCM_SW_REF_CNT_CCR              0x03
#define TIMER_CH_CNTRL_OCCM_REF_1_DIR_0_CNT_CCR         0x06
#define TIMER_CH_CNTRL_OCCM_REF_0_DIR_1_CNT_CCR         0x06
#define TIMER_CH_CNTRL_OCCM_REF_0_DIR_0_CNT_CCR         0x07
#define TIMER_CH_CNTRL_OCCM_REF_1_DIR_1_CNT_CCR         0x07
// CCR1 EN = 1
#define TIMER_CH_CNTRL_OCCM_REF_1_CNT_CCR_OR_CNT_CCR1   0x01
#define TIMER_CH_CNTRL_OCCM_REF_0_CNT_CCR_OR_CNT_CCR1   0x02
#define TIMER_CH_CNTRL_OCCM_SW_REF_CNT_CCR_OR_CNT_CCR1  0x03
#define TIMER_CH_CNTRL_OCCM_REF_1_DIR_0_CCR1_CNT_CCR    0x06
#define TIMER_CH_CNTRL_OCCM_REF_0_DIR_1_CCR_CNT_CCR1    0x06
#define TIMER_CH_CNTRL_OCCM_REF_0_DIR_0_CCR1_CNT_CCR    0x07
#define TIMER_CH_CNTRL_OCCM_REF_1_DIR_1_CCR_CNT_CCR1    0x07

/** @} */ /* End of group TIMER_CH_CNTRL */

/** @defgroup Periph_TIMER_CH_CNTRL1  TIMER CH CNTRL1
  * @{
  */

/*-- TIMER_CH_CNTRL1: Timer Channel Control1 Register --------------*/
/* Bit field positions: */
#define TIMER_CH_CNTRL1_SELOE_Pos               0
#define TIMER_CH_CNTRL1_SELO_Pos                2
#define TIMER_CH_CNTRL1_INV_Pos                 4
#define TIMER_CH_CNTRL1_NSELOE_Pos              8
#define TIMER_CH_CNTRL1_NSELO_Pos               10
#define TIMER_CH_CNTRL1_NINV_Pos                12

/* Bit field masks: */
#define TIMER_CH_CNTRL1_SELOE_Msk               ((uint32_t)0x00000003)
#define TIMER_CH_CNTRL1_SELO_Msk                ((uint32_t)0x0000000C)
#define TIMER_CH_CNTRL1_INV                     ((uint32_t)0x00000010)
#define TIMER_CH_CNTRL1_NSELOE_Msk              ((uint32_t)0x00000300)
#define TIMER_CH_CNTRL1_NSELO_Msk               ((uint32_t)0x00000C00)
#define TIMER_CH_CNTRL1_NINV                    ((uint32_t)0x00001000)

/* SELOE Modes */
#define TIMER_CH_CNTRL1_SELOE_OUT_DIS           0x00
#define TIMER_CH_CNTRL1_SELOE_OUT_EN            0x01
#define TIMER_CH_CNTRL1_SELOE_OUT_REF_Z_OUT     0x02
#define TIMER_CH_CNTRL1_SELOE_OUT_DTG_Z_OUT     0x03

/* SELO Modes */
#define TIMER_CH_CNTRL1_SELO_OUT_0              0x00
#define TIMER_CH_CNTRL1_SELO_OUT_1              0x01
#define TIMER_CH_CNTRL1_SELO_OUT_REF            0x02
#define TIMER_CH_CNTRL1_SELO_OUT_DTG            0x03

/** @} */ /* End of group TIMER_CH_CNTRL1 */

/** @defgroup Periph_TIMER_CH_DTG TIMER CH DTG
  * @{
  */

/*-- TIMER_CH_DTG: Timer Channel DTG Register ----------------------*/
/* Bit field positions: */
#define TIMER_CH_DTGX_Pos                       0
#define TIMER_CH_DTG_EDTS_Pos                   4
#define TIMER_CH_DTG_Pos                        8

/* Bit field masks: */
#define TIMER_CH_DTGX_Msk                       ((uint32_t)0x0000000F)
#define TIMER_CH_DTG_EDTS                       ((uint32_t)0x00000010)
#define TIMER_CH_DTG_Msk                        ((uint32_t)0x0000FF00)

/** @} */ /* End of group TIMER_CH_DTG */

/** @defgroup Periph_TIMER_BRKETR_CNTRL TIMER BRKETR CNTRL
  * @{
  */

/*-- TIMER_BRKETR_CNTRL: Timer BRK/ETR Control Register ------------*/
/* Bit field positions: */
#define TIMER_BRKETR_CNTRL_BRK_INV_Pos          0
#define TIMER_BRKETR_CNTRL_ETR_INV_Pos          1
#define TIMER_BRKETR_CNTRL_ETR_PSC_Pos          2
#define TIMER_BRKETR_CNTRL_ETR_FILTER_Pos       4

/* Bit field masks: */
#define TIMER_BRKETR_CNTRL_BRK_INV              ((uint32_t)0x00000001)
#define TIMER_BRKETR_CNTRL_ETR_INV              ((uint32_t)0x00000002)
#define TIMER_BRKETR_CNTRL_ETR_PSC_Msk          ((uint32_t)0x0000000C)
#define TIMER_BRKETR_CNTRL_ETR_FILTER_Msk       ((uint32_t)0x000000F0)

/* ETR PSC Modes */
#define TIMER_BRKETR_CNTRL_ETR_PSC_NO_DIV       0x00
#define TIMER_BRKETR_CNTRL_ETR_PSC_DIV_2        0x01
#define TIMER_BRKETR_CNTRL_ETR_PSC_DIV_4        0x02
#define TIMER_BRKETR_CNTRL_ETR_PSC_DIV_8        0x03

/* ETR FILTER Modes */
#define TIMER_BRKETR_CNTRL_ETR_FILTER_1_TRG_TIM_CLK             0x00
#define TIMER_BRKETR_CNTRL_ETR_FILTER_2_TRG_TIM_CLK             0x01
#define TIMER_BRKETR_CNTRL_ETR_FILTER_4_TRG_TIM_CLK             0x02
#define TIMER_BRKETR_CNTRL_ETR_FILTER_8_TRG_TIM_CLK             0x03
#define TIMER_BRKETR_CNTRL_ETR_FILTER_6_TRG_FDTS_DIV_2          0x04
#define TIMER_BRKETR_CNTRL_ETR_FILTER_8_TRG_FDTS_DIV_2          0x05
#define TIMER_BRKETR_CNTRL_ETR_FILTER_6_TRG_FDTS_DIV_4          0x06
#define TIMER_BRKETR_CNTRL_ETR_FILTER_8_TRG_FDTS_DIV_4          0x07
#define TIMER_BRKETR_CNTRL_ETR_FILTER_6_TRG_FDTS_DIV_8          0x08
#define TIMER_BRKETR_CNTRL_ETR_FILTER_8_TRG_FDTS_DIV_8          0x09
#define TIMER_BRKETR_CNTRL_ETR_FILTER_5_TRG_FDTS_DIV_16         0x0A
#define TIMER_BRKETR_CNTRL_ETR_FILTER_6_TRG_FDTS_DIV_16         0x0B
#define TIMER_BRKETR_CNTRL_ETR_FILTER_8_TRG_FDTS_DIV_16         0x0C
#define TIMER_BRKETR_CNTRL_ETR_FILTER_5_TRG_FDTS_DIV_32         0x0D
#define TIMER_BRKETR_CNTRL_ETR_FILTER_6_TRG_FDTS_DIV_32         0x0E
#define TIMER_BRKETR_CNTRL_ETR_FILTER_8_TRG_FDTS_DIV_32         0x0F

/** @} */ /* End of group TIMER_BRKETR_CNTRL */

/** @defgroup Periph_TIMER_STATUS TIMER STATUS
  * @{
  */

/*-- TIMER_STATUS: Timer Status Register ---------------------------*/
/* Bit field positions: */
#define TIMER_STATUS_CNT_ZERO_EVENT_Pos         0
#define TIMER_STATUS_CNT_ARR_EVENT_Pos          1
#define TIMER_STATUS_ETR_RE_EVENT_Pos           2
#define TIMER_STATUS_ETR_FE_EVENT_Pos           3
#define TIMER_STATUS_BRK_EVENT_Pos              4
#define TIMER_STATUS_CCR_CAP_EVENT_Pos          5
#define TIMER_STATUS_CCR_REF_EVENT_Pos          9
#define TIMER_STATUS_CCR1_CAP_EVENT_Pos         13

/* Bit field masks: */
#define TIMER_STATUS_CNT_ZERO_EVENT             ((uint32_t)0x00000001)
#define TIMER_STATUS_CNT_ARR_EVENT              ((uint32_t)0x00000002)
#define TIMER_STATUS_ETR_RE_EVENT               ((uint32_t)0x00000004)
#define TIMER_STATUS_ETR_FE_EVENT               ((uint32_t)0x00000008)
#define TIMER_STATUS_BRK_EVENT                  ((uint32_t)0x00000010)
#define TIMER_STATUS_CCR_CAP_EVENT_Msk          ((uint32_t)0x000001E0)
#define TIMER_STATUS_CCR_REF_EVENT_Msk          ((uint32_t)0x00001E00)
#define TIMER_STATUS_CCR1_CAP_EVENT_Msk         ((uint32_t)0x0001E000)

/** @} */ /* End of group TIMER_STATUS */

/** @defgroup Periph_TIMER_IE TIMER IE
  * @{
  */

/*-- TIMER_IE: Timer Interrupt Enable Register ---------------------*/
/* Bit field positions: */
#define TIMER_IE_CNT_ZERO_EVENT_IE_Pos          0
#define TIMER_IE_CNT_ARR_EVENT_IE_Pos           1
#define TIMER_IE_ETR_RE_EVENT_IE_Pos            2
#define TIMER_IE_ETR_FE_EVENT_IE_Pos            3
#define TIMER_IE_BRK_EVENT_IE_Pos               4
#define TIMER_IE_CCR_CAP_EVENT_IE_Pos           5
#define TIMER_IE_CCR_REF_EVENT_IE_Pos           9
#define TIMER_IE_CCR1_CAP_EVENT_IE_Pos          13

/* Bit field masks: */
#define TIMER_IE_CNT_ZERO_EVENT_IE              ((uint32_t)0x00000001)
#define TIMER_IE_CNT_ARR_EVENT_IE               ((uint32_t)0x00000002)
#define TIMER_IE_ETR_RE_EVENT_IE                ((uint32_t)0x00000004)
#define TIMER_IE_ETR_FE_EVENT_IE                ((uint32_t)0x00000008)
#define TIMER_IE_BRK_EVENT_IE                   ((uint32_t)0x00000010)
#define TIMER_IE_CCR_CAP_EVENT_IE_Msk           ((uint32_t)0x000001E0)
#define TIMER_IE_CCR_REF_EVENT_IE_Msk           ((uint32_t)0x00001E00)
#define TIMER_IE_CCR1_CAP_EVENT_IE_Msk          ((uint32_t)0x0001E000)

/** @} */ /* End of group TIMER_IE */

/** @defgroup Periph_TIMER_DMA_RE TIMER DMA RE
  * @{
  */

/*-- TIMER_DMA_RE: Timer DMA Request Enable Register ---------------*/
/* Bit field positions: */
#define TIMER_DMA_RE_CNT_ZERO_EVENT_RE_Pos      0
#define TIMER_DMA_RE_CNT_ARR_EVENT_RE_Pos       1
#define TIMER_DMA_RE_ETR_RE_EVENT_RE_Pos        2
#define TIMER_DMA_RE_ETR_FE_EVENT_RE_Pos        3
#define TIMER_DMA_RE_BRK_EVENT_RE_Pos           4
#define TIMER_DMA_RE_CCR_CAP_EVENT_RE_Pos       5
#define TIMER_DMA_RE_CCR_REF_EVENT_RE_Pos       9
#define TIMER_DMA_RE_CCR1_CAP_EVENT_RE_Pos      13

/* Bit field masks: */
#define TIMER_DMA_RE_CNT_ZERO_EVENT_RE          ((uint32_t)0x00000001)
#define TIMER_DMA_RE_CNT_ARR_EVENT_RE           ((uint32_t)0x00000002)
#define TIMER_DMA_RE_ETR_RE_EVENT_RE            ((uint32_t)0x00000004)
#define TIMER_DMA_RE_ETR_FE_EVENT_RE            ((uint32_t)0x00000008)
#define TIMER_DMA_RE_BRK_EVENT_RE               ((uint32_t)0x00000010)
#define TIMER_DMA_RE_CCR_CAP_EVENT_RE_Msk       ((uint32_t)0x000001E0)
#define TIMER_DMA_RE_CCR_REF_EVENT_RE_Msk       ((uint32_t)0x00001E00)
#define TIMER_DMA_RE_CCR1_CAP_EVENT_RE_Msk      ((uint32_t)0x0001E000)

/** @} */ /* End of group TIMER_DMA_RE */

/** @defgroup Periph_TIMER_CH_CNTRL2  TIMER CH CNTRL2
  * @{
  */

/*-- TIMER_CH_CNTRL2: Timer Channel Control2 Register --------------*/
/* Bit field positions: */
#define TIMER_CH_CNTRL2_CHSEL1_Pos              0
#define TIMER_CH_CNTRL2_CCR1_EN_Pos             2
#define TIMER_CH_CNTRL2_CCRRLD_Pos              3

/* Bit field masks: */
#define TIMER_CH_CNTRL2_CHSEL1_Msk              ((uint32_t)0x00000003)
#define TIMER_CH_CNTRL2_CCR1_EN                 ((uint32_t)0x00000004)
#define TIMER_CH_CNTRL2_CCRRLD                  ((uint32_t)0x00000008)

/* CHSEL1 Modes */
#define TIMER_CH_CNTRL2_CHSEL1_POS_EDGE                   0x00
#define TIMER_CH_CNTRL2_CHSEL1_NEG_EDGE                   0x01
#define TIMER_CH_CNTRL2_CHSEL1_NEG_EDGE_CH1_FROM_CH2      0x02
#define TIMER_CH_CNTRL2_CHSEL1_NEG_EDGE_CH2_FROM_CH3      0x02
#define TIMER_CH_CNTRL2_CHSEL1_NEG_EDGE_CH3_FROM_CH4      0x02
#define TIMER_CH_CNTRL2_CHSEL1_NEG_EDGE_CH4_FROM_CH1      0x02
#define TIMER_CH_CNTRL2_CHSEL1_NEG_EDGE_CH1_FROM_CH3      0x03
#define TIMER_CH_CNTRL2_CHSEL1_NEG_EDGE_CH2_FROM_CH4      0x03
#define TIMER_CH_CNTRL2_CHSEL1_NEG_EDGE_CH3_FROM_CH1      0x03
#define TIMER_CH_CNTRL2_CHSEL1_NEG_EDGE_CH4_FROM_CH2      0x03

/** @} */ /* End of group TIMER_CH_CNTRL2 */

/** @} */ /* End of group MDR32Fx_Periph_TIMER_Defines */

/** @} */ /* End of group MDR32Fx_Periph_TIMER */

/** @defgroup MDR32Fx_Periph_ADC ADC
  * @{
  */

/** @defgroup MDR32Fx_Periph_ADC_Data_Structures Data Structures
  * @{
  */

/* MDR_ADC_TypeDef structure */
typedef struct
{
  __IO uint32_t ADC1_CFG;
  __IO uint32_t ADC2_CFG;
  __IO uint32_t ADC1_H_LEVEL;
  __IO uint32_t ADC2_H_LEVEL;
  __IO uint32_t ADC1_L_LEVEL;
  __IO uint32_t ADC2_L_LEVEL;
  __IO uint32_t ADC1_RESULT;
  __IO uint32_t ADC2_RESULT;
  __IO uint32_t ADC1_STATUS;
  __IO uint32_t ADC2_STATUS;
  __IO uint32_t ADC1_CHSEL;
  __IO uint32_t ADC2_CHSEL;
}MDR_ADC_TypeDef;

/** @} */ /* End of group MDR32Fx_Periph_ADC_Data_Structures */

/** @defgroup MDR32Fx_Periph_ADC_Defines Defines
  * @{
  */

/** @defgroup Periph_ADC1_CFG ADC1 CFG
  * @{
  */

/*-- ADC1_CFG: ADC1 Configuration Register -------------------------*/
/* Bit field positions: */
#define ADC1_CFG_REG_ADON_Pos                   0
#define ADC1_CFG_REG_GO_Pos                     1
#define ADC1_CFG_REG_CLKS_Pos                   2
#define ADC1_CFG_REG_SAMPLE_Pos                 3
#define ADC1_CFG_REG_CHS_Pos                    4
#define ADC1_CFG_REG_CHCH_Pos                   9
#define ADC1_CFG_REG_RNGC_Pos                   10
#define ADC1_CFG_M_REF_Pos                      11
#define ADC1_CFG_REG_DIVCLK_Pos                 12
#define ADC1_CFG_SYNC_CONVER_Pos                16
#define ADC1_CFG_TS_EN_Pos                      17
#define ADC1_CFG_TS_BUF_EN_Pos                  18
#define ADC1_CFG_SEL_TS_Pos                     19
#define ADC1_CFG_SEL_VREF_Pos                   20
#define ADC1_CFG_TR_Pos                         21
#define ADC1_CFG_DELAY_GO_Pos                   25
#define ADC1_CFG_DELAY_ADC_Pos                  28

/* Bit field masks: */
#define ADC1_CFG_REG_ADON                       ((uint32_t)0x00000001)
#define ADC1_CFG_REG_GO                         ((uint32_t)0x00000002)
#define ADC1_CFG_REG_CLKS                       ((uint32_t)0x00000004)
#define ADC1_CFG_REG_SAMPLE                     ((uint32_t)0x00000008)
#define ADC1_CFG_REG_CHS_Msk                    ((uint32_t)0x000001F0)
#define ADC1_CFG_REG_CHCH                       ((uint32_t)0x00000200)
#define ADC1_CFG_REG_RNGC                       ((uint32_t)0x00000400)
#define ADC1_CFG_M_REF                          ((uint32_t)0x00000800)
#define ADC1_CFG_REG_DIVCLK_Msk                 ((uint32_t)0x0000F000)
#define ADC1_CFG_SYNC_CONVER                    ((uint32_t)0x00010000)
#define ADC1_CFG_TS_EN                          ((uint32_t)0x00020000)
#define ADC1_CFG_TS_BUF_EN                      ((uint32_t)0x00040000)
#define ADC1_CFG_SEL_TS                         ((uint32_t)0x00080000)
#define ADC1_CFG_SEL_VREF                       ((uint32_t)0x00100000)
#define ADC1_CFG_TR_Msk                         ((uint32_t)0x01E00000)
#define ADC1_CFG_DELAY_GO_Msk                   ((uint32_t)0x0E000000)
#define ADC1_CFG_DELAY_ADC_Msk                  ((uint32_t)0xF0000000)

/* Delay Go Modes */
#define ADC1_CFG_DELAY_GO_1_CPU_CLK             0x00
#define ADC1_CFG_DELAY_GO_2_CPU_CLK             0x01
#define ADC1_CFG_DELAY_GO_3_CPU_CLK             0x02
#define ADC1_CFG_DELAY_GO_4_CPU_CLK             0x03
#define ADC1_CFG_DELAY_GO_5_CPU_CLK             0x04
#define ADC1_CFG_DELAY_GO_6_CPU_CLK             0x05
#define ADC1_CFG_DELAY_GO_7_CPU_CLK             0x06
#define ADC1_CFG_DELAY_GO_8_CPU_CLK             0x07

/* Delay ADC Modes */
#define ADC1_CFG_DELAY_ADC_1_CPU_CLK            0x00
#define ADC1_CFG_DELAY_ADC_2_CPU_CLK            0x01
#define ADC1_CFG_DELAY_ADC_3_CPU_CLK            0x02
#define ADC1_CFG_DELAY_ADC_4_CPU_CLK            0x03
#define ADC1_CFG_DELAY_ADC_5_CPU_CLK            0x04
#define ADC1_CFG_DELAY_ADC_6_CPU_CLK            0x05
#define ADC1_CFG_DELAY_ADC_7_CPU_CLK            0x06
#define ADC1_CFG_DELAY_ADC_8_CPU_CLK            0x07
#define ADC1_CFG_DELAY_ADC_9_CPU_CLK            0x08
#define ADC1_CFG_DELAY_ADC_10_CPU_CLK           0x09
#define ADC1_CFG_DELAY_ADC_11_CPU_CLK           0x0A
#define ADC1_CFG_DELAY_ADC_12_CPU_CLK           0x0B
#define ADC1_CFG_DELAY_ADC_13_CPU_CLK           0x0C
#define ADC1_CFG_DELAY_ADC_14_CPU_CLK           0x0D
#define ADC1_CFG_DELAY_ADC_15_CPU_CLK           0x0E
#define ADC1_CFG_DELAY_ADC_16_CPU_CLK           0x0F

/** @} */ /* End of group ADC1_CFG */

/** @defgroup Periph_ADC2_CFG ADC2 CFG
  * @{
  */

/*-- ADC2_CFG: ADC2 Configuration Register -------------------------*/
/* Bit field positions: */
#define ADC2_CFG_REG_ADON_Pos                   0
#define ADC2_CFG_REG_GO_Pos                     1
#define ADC2_CFG_REG_CLKS_Pos                   2
#define ADC2_CFG_REG_SAMPLE_Pos                 3
#define ADC2_CFG_REG_CHS_Pos                    4
#define ADC2_CFG_REG_CHCH_Pos                   9
#define ADC2_CFG_REG_RNGC_Pos                   10
#define ADC2_CFG_M_REF_Pos                      11
#define ADC2_CFG_REG_DIVCLK_Pos                 12
#define ADC2_CFG_ADC1_OP_Pos                    17
#define ADC2_CFG_ADC2_OP_Pos                    18
#define ADC2_CFG_DELAY_GO_Pos                   25

/* Bit field masks: */
#define ADC2_CFG_REG_ADON                       ((uint32_t)0x00000001)
#define ADC2_CFG_REG_GO                         ((uint32_t)0x00000002)
#define ADC2_CFG_REG_CLKS                       ((uint32_t)0x00000004)
#define ADC2_CFG_REG_SAMPLE                     ((uint32_t)0x00000008)
#define ADC2_CFG_REG_CHS_Msk                    ((uint32_t)0x000001F0)
#define ADC2_CFG_REG_CHCH                       ((uint32_t)0x00000200)
#define ADC2_CFG_REG_RNGC                       ((uint32_t)0x00000400)
#define ADC2_CFG_M_REF                          ((uint32_t)0x00000800)
#define ADC2_CFG_REG_DIVCLK_Msk                 ((uint32_t)0x0000F000)
#define ADC2_CFG_ADC1_OP                        ((uint32_t)0x00020000)
#define ADC2_CFG_ADC2_OP                        ((uint32_t)0x00040000)
#define ADC2_CFG_DELAY_GO_Msk                   ((uint32_t)0x0E000000)

/* Delay Go Modes */
#define ADC2_CFG_DELAY_GO_0_CPU_CLK             0x00
#define ADC2_CFG_DELAY_GO_1_CPU_CLK             0x01
#define ADC2_CFG_DELAY_GO_2_CPU_CLK             0x02
#define ADC2_CFG_DELAY_GO_3_CPU_CLK             0x03
#define ADC2_CFG_DELAY_GO_4_CPU_CLK             0x04
#define ADC2_CFG_DELAY_GO_5_CPU_CLK             0x05
#define ADC2_CFG_DELAY_GO_6_CPU_CLK             0x06
#define ADC2_CFG_DELAY_GO_7_CPU_CLK             0x07

/** @} */ /* End of group ADC2_CFG */

/* CFG REG CHS Modes */
#define ADC_CFG_REG_CHS_VREF                    30
#define ADC_CFG_REG_CHS_TS                      31

/* CFG REG DIVCLK Modes*/
#define ADC_CFG_REG_DIVCLK_HCLK                 0x00
#define ADC_CFG_REG_DIVCLK_HCLK_DIV_2           0x01
#define ADC_CFG_REG_DIVCLK_HCLK_DIV_4           0x02
#define ADC_CFG_REG_DIVCLK_HCLK_DIV_8           0x03
#define ADC_CFG_REG_DIVCLK_HCLK_DIV_16          0x04
#define ADC_CFG_REG_DIVCLK_HCLK_DIV_32          0x05
#define ADC_CFG_REG_DIVCLK_HCLK_DIV_64          0x06
#define ADC_CFG_REG_DIVCLK_HCLK_DIV_128         0x07
#define ADC_CFG_REG_DIVCLK_HCLK_DIV_256         0x08
#define ADC_CFG_REG_DIVCLK_HCLK_DIV_512         0x09
#define ADC_CFG_REG_DIVCLK_HCLK_DIV_1024        0x0A
#define ADC_CFG_REG_DIVCLK_HCLK_DIV_2048        0x0B

/** @defgroup Periph_ADC1_RESULT  ADC1 RESULT
  * @{
  */

/*-- ADC1_RESULT: ADC1 Result Register -----------------------------*/
/*-- ADC2_RESULT: ADC2 Result Register -----------------------------*/
/* Bit field positions: */
#define ADC_RESULT_Pos                          0
#define ADC_RESULT_CHANNEL_Pos                  16

/* Bit field masks: */
#define ADC_RESULT_Msk                          ((uint32_t)0x00000FFF)
#define ADC_RESULT_CHANNEL_Msk                  ((uint32_t)0x001F0000)

/** @} */ /* End of group ADC1_RESULT */

/** @defgroup Periph_ADC1_STATUS  ADC1 STATUS
  * @{
  */

/*-- ADC1_STATUS: ADC1 Status Register -----------------------------*/
/*-- ADC2_STATUS: ADC2 Status Register -----------------------------*/
/* Bit field positions: */
#define ADC_STATUS_FLG_REG_OVERWRITE_Pos        0
#define ADC_STATUS_FLG_REG_AWOIFEN_Pos          1
#define ADC_STATUS_FLG_REG_EOCIF_Pos            2
#define ADC_STATUS_AWOIF_IE_Pos                 3
#define ADC_STATUS_ECOIF_IE_Pos                 4

/* Bit field masks: */
#define ADC_STATUS_FLG_REG_OVERWRITE            ((uint32_t)0x00000001)
#define ADC_STATUS_FLG_REG_AWOIFEN              ((uint32_t)0x00000002)
#define ADC_STATUS_FLG_REG_EOCIF                ((uint32_t)0x00000004)
#define ADC_STATUS_AWOIF_IE                     ((uint32_t)0x00000008)
#define ADC_STATUS_ECOIF_IE                     ((uint32_t)0x00000010)

/** @} */ /* End of group ADC1_STATUS */

/** @} */ /* End of group MDR32Fx_Periph_ADC_Defines */

/** @} */ /* End of group MDR32Fx_Periph_ADC */

/** @defgroup MDR32Fx_Periph_DAC DAC
  * @{
  */

/** @defgroup MDR32Fx_Periph_DAC_Data_Structures Data Structures
  * @{
  */

/* MDR_DAC_TypeDef structure */
typedef struct
{
  __IO uint32_t CFG;
  __IO uint32_t DAC1_DATA;
  __IO uint32_t DAC2_DATA;
}MDR_DAC_TypeDef;

/** @} */ /* End of group MDR32Fx_Periph_DAC_Data_Structures */

/** @defgroup MDR32Fx_Periph_DAC_Defines Defines
  * @{
  */

/** @defgroup Periph_DAC_CFG  DAC CFG
  * @{
  */

/*-- DAC_CFG: DAC Configuration Register ---------------------------*/
/* Bit field positions: */
#define DAC_CFG_M_REF0_Pos                      0
#define DAC_CFG_M_REF1_Pos                      1
#define DAC_CFG_ON_DAC0_Pos                     2
#define DAC_CFG_ON_DAC1_Pos                     3
#define DAC_CFG_SYNC_A_Pos                      4

/* Bit field masks: */
#define DAC_CFG_M_REF0                          ((uint32_t)0x00000001)
#define DAC_CFG_M_REF1                          ((uint32_t)0x00000002)
#define DAC_CFG_ON_DAC0                         ((uint32_t)0x00000004)
#define DAC_CFG_ON_DAC1                         ((uint32_t)0x00000008)
#define DAC_CFG_SYNC_A                          ((uint32_t)0x00000010)

/** @} */ /* End of group DAC_CFG */

/** @defgroup Periph_DAC1_DATA  DAC1 DATA
  * @{
  */

/*-- DAC1_DATA: DAC1 Data Register ---------------------------------*/
/* Bit field positions: */
#define DAC1_DATA_DAC0DATA_Pos                  0
#define DAC1_DATA_DAC1DATA_Pos                  16

/* Bit field masks: */
#define DAC1_DATA_DAC0DATA_Msk                  ((uint32_t)0x00000FFF)
#define DAC1_DATA_DAC1DATA_Msk                  ((uint32_t)0x0FFF0000)

/** @} */ /* End of group DAC1_DATA */

/** @defgroup Periph_DAC2_DATA  DAC2 DATA
  * @{
  */

/*-- DAC2_DATA: DAC2 Data Register ---------------------------------*/
/* Bit field positions: */
#define DAC2_DATA_DAC1DATA_Pos                  0
#define DAC2_DATA_DAC0DATA_Pos                  16

/* Bit field masks: */
#define DAC2_DATA_DAC1DATA_Msk                  ((uint32_t)0x00000FFF)
#define DAC2_DATA_DAC0DATA_Msk                  ((uint32_t)0x0FFF0000)

/** @} */ /* End of group DAC2_DATA */

/** @} */ /* End of group MDR32Fx_Periph_DAC_Defines */

/** @} */ /* End of group MDR32Fx_Periph_DAC */

/** @defgroup MDR32Fx_Periph_COMP COMP
  * @{
  */

/** @defgroup MDR32Fx_Periph_COMP_Data_Structures Data Structures
  * @{
  */

/* MDR_COMP_TypeDef structure */
typedef struct
{
  __IO uint32_t CFG;
  __IO uint32_t RESULT;
  __IO uint32_t RESULT_LATCH;
}MDR_COMP_TypeDef;

/** @} */ /* End of group MDR32Fx_Periph_COMP_Data_Structures */

/** @defgroup MDR32Fx_Periph_COMP_Defines Defines
  * @{
  */

/** @defgroup Periph_COMP_CFG COMP CFG
  * @{
  */

/*-- COMP_CFG: COMP Configuration Register -------------------------*/
/* Bit field positions: */
#define COMP_CFG_ON_Pos                         0
#define COMP_CFG_CVRR_Pos                       1
#define COMP_CFG_CVRSS_Pos                      2
#define COMP_CFG_CVREN_Pos                      3
#define COMP_CFG_CVR_Pos                        4
#define COMP_CFG_CREF_Pos                       8
#define COMP_CFG_CCH_Pos                        9
#define COMP_CFG_INV_Pos                        11
#define COMP_CFG_READY_Pos                      12
#define COMP_CFG_CMPIE_Pos                      13

/* Bit field masks: */
#define COMP_CFG_ON                             ((uint32_t)0x00000001)
#define COMP_CFG_CVRR                           ((uint32_t)0x00000002)
#define COMP_CFG_CVRSS                          ((uint32_t)0x00000004)
#define COMP_CFG_CVREN                          ((uint32_t)0x00000008)
#define COMP_CFG_CVR_Msk                        ((uint32_t)0x000000F0)
#define COMP_CFG_CREF                           ((uint32_t)0x00000100)
#define COMP_CFG_CCH_Msk                        ((uint32_t)0x00000600)
#define COMP_CFG_INV                            ((uint32_t)0x00000800)
#define COMP_CFG_READY                          ((uint32_t)0x00001000)
#define COMP_CFG_CMPIE                          ((uint32_t)0x00002000)

/* COMP CFG CCH Modes */
#define COMP_CFG_CCH_NEG_IN_2                   0x00
#define COMP_CFG_CCH_NEG_IN_1                   0x01
#define COMP_CFG_CCH_NEG_IN_3                   0x02
#define COMP_CFG_CCH_NEG_IVREF                  0x03

/** @} */ /* End of group COMP_CFG */

/** @defgroup Periph_COMP_RESULT  COMP RESULT
  * @{
  */

/*-- COMP_RESULT: COMP Result Register -----------------------------*/
/* Bit field positions: */
#define COMP_RESULT_RSLT_SY_Pos                 0
#define COMP_RESULT_RSLT_AS_Pos                 1
#define COMP_RESULT_RST_LCH_Pos                 2

/* Bit field masks: */
#define COMP_RESULT_RSLT_SY                     ((uint32_t)0x00000001)
#define COMP_RESULT_RSLT_AS                     ((uint32_t)0x00000002)
#define COMP_RESULT_RST_LCH                     ((uint32_t)0x00000004)

/** @} */ /* End of group COMP_RESULT */

/** @} */ /* End of group MDR32Fx_Periph_COMP_Defines */

/** @} */ /* End of group MDR32Fx_Periph_COMP */

/** @defgroup MDR32Fx_Periph_PORT PORT
  * @{
  */

/** @defgroup MDR32Fx_Periph_PORT_Data_Structures Data Structures
  * @{
  */

/* MDR_PORT_TypeDef structure */
typedef struct
{
  __IO uint32_t RXTX;
  __IO uint32_t OE;
  __IO uint32_t FUNC;
  __IO uint32_t ANALOG;
  __IO uint32_t PULL;
  __IO uint32_t PD;
  __IO uint32_t PWR;
  __IO uint32_t GFEN;
}MDR_PORT_TypeDef;

/** @} */ /* End of group MDR32Fx_Periph_PORT_Data_Structures */

/** @defgroup MDR32Fx_Periph_PORT_Defines Defines
  * @{
  */

/** @defgroup Periph_PORT_FUNC  PORT FUNC
  * @{
  */

/*-- PORT_FUNC: PORT Function Register -----------------------------*/
/* Bit field positions: */
#define PORT_FUNC_MODE0_Pos                     0
#define PORT_FUNC_MODE1_Pos                     2
#define PORT_FUNC_MODE2_Pos                     4
#define PORT_FUNC_MODE3_Pos                     6
#define PORT_FUNC_MODE4_Pos                     8
#define PORT_FUNC_MODE5_Pos                     10
#define PORT_FUNC_MODE6_Pos                     12
#define PORT_FUNC_MODE7_Pos                     14
#define PORT_FUNC_MODE8_Pos                     16
#define PORT_FUNC_MODE9_Pos                     18
#define PORT_FUNC_MODE10_Pos                    20
#define PORT_FUNC_MODE11_Pos                    22
#define PORT_FUNC_MODE12_Pos                    24
#define PORT_FUNC_MODE13_Pos                    26
#define PORT_FUNC_MODE14_Pos                    28
#define PORT_FUNC_MODE15_Pos                    30

/* Bit field masks: */
#define PORT_FUNC_MODE_Msk                      3U
#define PORT_FUNC_MODE0_Msk                     ((uint32_t)0x00000003)
#define PORT_FUNC_MODE1_Msk                     ((uint32_t)0x0000000C)
#define PORT_FUNC_MODE2_Msk                     ((uint32_t)0x00000030)
#define PORT_FUNC_MODE3_Msk                     ((uint32_t)0x000000C0)
#define PORT_FUNC_MODE4_Msk                     ((uint32_t)0x00000300)
#define PORT_FUNC_MODE5_Msk                     ((uint32_t)0x00000C00)
#define PORT_FUNC_MODE6_Msk                     ((uint32_t)0x00003000)
#define PORT_FUNC_MODE7_Msk                     ((uint32_t)0x0000C000)
#define PORT_FUNC_MODE8_Msk                     ((uint32_t)0x00030000)
#define PORT_FUNC_MODE9_Msk                     ((uint32_t)0x000C0000)
#define PORT_FUNC_MODE10_Msk                    ((uint32_t)0x00300000)
#define PORT_FUNC_MODE11_Msk                    ((uint32_t)0x00C00000)
#define PORT_FUNC_MODE12_Msk                    ((uint32_t)0x03000000)
#define PORT_FUNC_MODE13_Msk                    ((uint32_t)0x0C000000)
#define PORT_FUNC_MODE14_Msk                    ((uint32_t)0x30000000)
#define PORT_FUNC_MODE15_Msk                    ((uint32_t)0xC0000000)

/* PORT FUNC Modes */
#define PORT_FUNC_MODE_PORT   0U
#define PORT_FUNC_MODE_MAIN   1U
#define PORT_FUNC_MODE_ALT    2U
#define PORT_FUNC_MODE_OVER   3U

/** @} */ /* End of group PORT_FUNC */

/** @defgroup Periph_PORT_PULL  PORT PULL
  * @{
  */

/*-- PORT_PULL: PORT Pull Up/Down Register -------------------------*/
/* Bit field positions: */
#define PORT_PULL_DOWN_Pos                      0
#define PORT_PULL_UP_Pos                        16

/* Bit field masks: */
#define PORT_PULL_DOWN_Msk                      ((uint32_t)0x0000FFFF)
#define PORT_PULL_UP_Msk                        ((uint32_t)0xFFFF0000)

/** @} */ /* End of group PORT_PULL */

/** @defgroup Periph_PORT_PD  PORT PD
  * @{
  */

/*-- PORT_PD: PORT Driver Mode Register ----------------------------*/
/* Bit field positions: */
#define PORT_PD_Pos                             0
#define PORT_PD_SHM_Pos                         16

/* Bit field masks: */
#define PORT_PD_Msk                             ((uint32_t)0x0000FFFF)
#define PORT_PD_SHM_Msk                         ((uint32_t)0xFFFF0000)

/** @} */ /* End of group PORT_PD */

/** @defgroup Periph_PORT_PWR PORT PWR
  * @{
  */

/*-- PORT_PWR: PORT Power Register ---------------------------------*/
/* Bit field positions: */
#define PORT_PWR0_Pos                           0
#define PORT_PWR1_Pos                           2
#define PORT_PWR2_Pos                           4
#define PORT_PWR3_Pos                           6
#define PORT_PWR4_Pos                           8
#define PORT_PWR5_Pos                           10
#define PORT_PWR6_Pos                           12
#define PORT_PWR7_Pos                           14
#define PORT_PWR8_Pos                           16
#define PORT_PWR9_Pos                           18
#define PORT_PWR10_Pos                          20
#define PORT_PWR11_Pos                          22
#define PORT_PWR12_Pos                          24
#define PORT_PWR13_Pos                          26
#define PORT_PWR14_Pos                          28
#define PORT_PWR15_Pos                          30

/* Bit field masks: */
#define PORT_PWR_Msk                            3U
#define PORT_PWR0_Msk                           ((uint32_t)0x00000003)
#define PORT_PWR1_Msk                           ((uint32_t)0x0000000C)
#define PORT_PWR2_Msk                           ((uint32_t)0x00000030)
#define PORT_PWR3_Msk                           ((uint32_t)0x000000C0)
#define PORT_PWR4_Msk                           ((uint32_t)0x00000300)
#define PORT_PWR5_Msk                           ((uint32_t)0x00000C00)
#define PORT_PWR6_Msk                           ((uint32_t)0x00003000)
#define PORT_PWR7_Msk                           ((uint32_t)0x0000C000)
#define PORT_PWR8_Msk                           ((uint32_t)0x00030000)
#define PORT_PWR9_Msk                           ((uint32_t)0x000C0000)
#define PORT_PWR10_Msk                          ((uint32_t)0x00300000)
#define PORT_PWR11_Msk                          ((uint32_t)0x00C00000)
#define PORT_PWR12_Msk                          ((uint32_t)0x03000000)
#define PORT_PWR13_Msk                          ((uint32_t)0x0C000000)
#define PORT_PWR14_Msk                          ((uint32_t)0x30000000)
#define PORT_PWR15_Msk                          ((uint32_t)0xC0000000)

/* PORT PWR Modes */
#define PORT_PWR_OFF        0U
#define PORT_PWR_SLOW       1U
#define PORT_PWR_FAST       2U
#define PORT_PWR_MAX_FAST   3U

/** @} */ /* End of group PORT_PWR */

/** @} */ /* End of group MDR32Fx_Periph_PORT_Defines */

/** @} */ /* End of group MDR32Fx_Periph_PORT */

/** @defgroup MDR32Fx_Periph_BKP BKP
  * @{
  */

/** @defgroup MDR32Fx_Periph_BKP_Data_Structures Data Structures
  * @{
  */

/* MDR_BKP_TypeDef structure */
typedef struct
{
  __IO uint32_t REG_00;
  __IO uint32_t REG_01;
  __IO uint32_t REG_02;
  __IO uint32_t REG_03;
  __IO uint32_t REG_04;
  __IO uint32_t REG_05;
  __IO uint32_t REG_06;
  __IO uint32_t REG_07;
  __IO uint32_t REG_08;
  __IO uint32_t REG_09;
  __IO uint32_t REG_0A;
  __IO uint32_t REG_0B;
  __IO uint32_t REG_0C;
  __IO uint32_t REG_0D;
  __IO uint32_t REG_0E;
  __IO uint32_t REG_0F;
  __IO uint32_t RTC_CNT;
  __IO uint32_t RTC_DIV;
  __IO uint32_t RTC_PRL;
  __IO uint32_t RTC_ALRM;
  __IO uint32_t RTC_CS;
}MDR_BKP_TypeDef;

/** @} */ /* End of group MDR32Fx_Periph_BKP_Data_Structures */

/** @defgroup MDR32Fx_Periph_BKP_Defines Defines
  * @{
  */

/** @defgroup Periph_BKP_REG_0E BKP REG 0E
  * @{
  */

/*-- BKP_REG_0E: Backup Register 14 --------------------------------*/
/* Bit field positions: */
#define BKP_REG_0E_LOW_Pos                      0
#define BKP_REG_0E_SELECTRI_Pos                 3
#define BKP_REG_0E_JTAGA_Pos                    6
#define BKP_REG_0E_JTAGB_Pos                    7
#define BKP_REG_0E_TRIM_Pos                     8
#define BKP_REG_0E_FPOR_Pos                     11
#define BKP_REG_0E_BKP_REG_Pos                  12

/* Bit field masks: */
#define BKP_REG_0E_LOW_Msk                      ((uint32_t)0x00000007)
#define BKP_REG_0E_SELECTRI_Msk                 ((uint32_t)0x00000038)
#define BKP_REG_0E_JTAGA                        ((uint32_t)0x00000040)
#define BKP_REG_0E_JTAGB                        ((uint32_t)0x00000080)
#define BKP_REG_0E_TRIM_Msk                     ((uint32_t)0x00000700)
#define BKP_REG_0E_FPOR                         ((uint32_t)0x00000800)
#define BKP_REG_0E_BKP_REG_Msk                  ((uint32_t)0xFFFFF000)

/** @} */ /* End of group BKP_REG_0E */

/** @defgroup Periph_BKP_REG_0F BKP REG 0F
  * @{
  */

/*-- BKP_REG_0F: Backup Register 15 --------------------------------*/
/* Bit field positions: */
#define BKP_REG_0F_LSE_ON_Pos                   0
#define BKP_REG_0F_LSE_BYP_Pos                  1
#define BKP_REG_0F_RTC_SEL_Pos                  2
#define BKP_REG_0F_RTC_EN_Pos                   4
#define BKP_REG_0F_CAL_Pos                      5
#define BKP_REG_0F_LSE_RDY_Pos                  13
#define BKP_REG_0F_BKP_REG_Pos                  14
#define BKP_REG_0F_LSI_ON_Pos                   15
#define BKP_REG_0F_LSI_TRIM_Pos                 16
#define BKP_REG_0F_LSI_RDY_Pos                  21
#define BKP_REG_0F_HSI_ON_Pos                   22
#define BKP_REG_0F_HSI_RDY_Pos                  23
#define BKP_REG_0F_HSI_TRIM_Pos                 24
#define BKP_REG_0F_STANDBY_Pos                  30
#define BKP_REG_0F_RTC_RESET_Pos                31

/* Bit field masks: */
#define BKP_REG_0F_LSE_ON                       ((uint32_t)0x00000001)
#define BKP_REG_0F_LSE_BYP                      ((uint32_t)0x00000002)
#define BKP_REG_0F_RTC_SEL_Msk                  ((uint32_t)0x0000000C)
#define BKP_REG_0F_RTC_EN                       ((uint32_t)0x00000010)
#define BKP_REG_0F_CAL_Msk                      ((uint32_t)0x00001FE0)
#define BKP_REG_0F_LSE_RDY                      ((uint32_t)0x00002000)
#define BKP_REG_0F_BKP_REG                      ((uint32_t)0x00004000)
#define BKP_REG_0F_LSI_ON                       ((uint32_t)0x00008000)
#define BKP_REG_0F_LSI_TRIM_Msk                 ((uint32_t)0x001F0000)
#define BKP_REG_0F_LSI_RDY                      ((uint32_t)0x00200000)
#define BKP_REG_0F_HSI_ON                       ((uint32_t)0x00400000)
#define BKP_REG_0F_HSI_RDY                      ((uint32_t)0x00800000)
#define BKP_REG_0F_HSI_TRIM_Msk                 ((uint32_t)0x3F000000)
#define BKP_REG_0F_STANDBY                      ((uint32_t)0x40000000)
#define BKP_REG_0F_RTC_RESET                    ((uint32_t)0x80000000)

/** @} */ /* End of group BKP_REG_0F */

/** @defgroup Periph_BKP_RTC_CS BKP RTC CS
  * @{
  */

/*-- BKP_RTC_CS: Backup Realtime clock Register --------------------*/
/* Bit field positions: */
#define BKP_RTC_CS_OWF_Pos                      0
#define BKP_RTC_CS_SECF_Pos                     1
#define BKP_RTC_CS_ALRF_Pos                     2
#define BKP_RTC_CS_OWF_IE_Pos                   3
#define BKP_RTC_CS_SECF_IE_Pos                  4
#define BKP_RTC_CS_ALRF_IE_Pos                  5
#define BKP_RTC_CS_WEC_Pos                      6

/* Bit field masks: */
#define BKP_RTC_CS_OWF                          ((uint32_t)0x00000001)
#define BKP_RTC_CS_SECF                         ((uint32_t)0x00000002)
#define BKP_RTC_CS_ALRF                         ((uint32_t)0x00000004)
#define BKP_RTC_CS_OWF_IE                       ((uint32_t)0x00000008)
#define BKP_RTC_CS_SECF_IE                      ((uint32_t)0x00000010)
#define BKP_RTC_CS_ALRF_IE                      ((uint32_t)0x00000020)
#define BKP_RTC_CS_WEC                          ((uint32_t)0x00000040)

/** @} */ /* End of group BKP_RTC_CS */

/** @} */ /* End of group MDR32Fx_Periph_BKP_Defines */

/** @} */ /* End of group MDR32Fx_Periph_BKP */

/** @defgroup MDR32Fx_Periph_EBC EBC
  * @{
  */

/** @defgroup MDR32Fx_Periph_EBC_Data_Structures Data Structures
  * @{
  */

/* MDR_EBC_TypeDef structure */
typedef struct
{
       uint32_t RESERVED0[20];
  __IO uint32_t NAND_CYCLES;
  __IO uint32_t CONTROL;
#if defined (USE_MDR1986VE94)
  __IO uint32_t MEM_REGION[4];
#endif
}MDR_EBC_TypeDef;

/** @} */ /* End of group MDR32Fx_Periph_EBC_Data_Structures */

/** @defgroup MDR32Fx_Periph_EBC_Defines Defines
  * @{
  */

/** @defgroup Periph_EBC_NAND_CYCLES  EBC NAND CYCLES
  * @{
  */

/*-- EBC_NAND_CYCLES: EBC NAND Timing Register ---------------------*/
/* Bit field positions: */
#define EBC_NAND_CYCLES_TRC_Pos                 0
#define EBC_NAND_CYCLES_TWC_Pos                 4
#define EBC_NAND_CYCLES_TREA_Pos                8
#define EBC_NAND_CYCLES_TWP_Pos                 12
#define EBC_NAND_CYCLES_TWHR_Pos                16
#define EBC_NAND_CYCLES_TALEA_Pos               20
#define EBC_NAND_CYCLES_TRR_Pos                 24

/* Bit field masks: */
#define EBC_NAND_CYCLES_TRC_Msk                 ((uint32_t)0x0000000F)
#define EBC_NAND_CYCLES_TWC_Msk                 ((uint32_t)0x000000F0)
#define EBC_NAND_CYCLES_TREA_Msk                ((uint32_t)0x00000F00)
#define EBC_NAND_CYCLES_TWP_Msk                 ((uint32_t)0x0000F000)
#define EBC_NAND_CYCLES_TWHR_Msk                ((uint32_t)0x000F0000)
#define EBC_NAND_CYCLES_TALEA_Msk               ((uint32_t)0x00F00000)
#define EBC_NAND_CYCLES_TRR_Msk                 ((uint32_t)0x0F000000)

/** @} */ /* End of group EBC_NAND_CYCLES */

/** @defgroup Periph_EBC_CONTROL  EBC CONTROL
  * @{
  */

/*-- EBC_CONTROL: EBC Control Register -----------------------------*/
/* Bit field positions: */
#define EBC_CONTROL_ROM_Pos                     0
#define EBC_CONTROL_RAM_Pos                     1
#define EBC_CONTROL_NAND_Pos                    2
#define EBC_CONTROL_CPOL_Pos                    3
#define EBC_CONTROL_BUSY_Pos                    7
#define EBC_CONTROL_WAIT_STATE_Pos              12
#if defined (USE_MDR1986VE94)
  #define EBC_CONTROL_FS_RDY_Pos                16
  #define EBC_CONTROL_FF_RDY_Pos                17
#endif

/* Bit field masks: */
#define EBC_CONTROL_ROM                         ((uint32_t)0x00000001)
#define EBC_CONTROL_RAM                         ((uint32_t)0x00000002)
#define EBC_CONTROL_NAND                        ((uint32_t)0x00000004)
#define EBC_CONTROL_CPOL                        ((uint32_t)0x00000008)
#define EBC_CONTROL_BUSY                        ((uint32_t)0x00000080)
#define EBC_CONTROL_WAIT_STATE_Msk              ((uint32_t)0x0000F000)
#if defined (USE_MDR1986VE94)
  #define EBC_CONTROL_FS_RDY                    ((uint32_t)0x00010000)
  #define EBC_CONTROL_FF_RDY                    ((uint32_t)0x00020000)
#endif


/** @} */ /* End of group EBC_CONTROL */

#if defined (USE_MDR1986VE94)

/** @defgroup Periph_EBC_RAM_CYCLESx  EBC RAM CYCLESx
  * @{
  */

/*-- EBC_RAM_CYCLESx: Register customization options exchange with RAM -------*/
/* Bit field positions: */
#define EBC_RAM_CYCLES_ENABLE_TUNE_Pos    0
#define EBC_RAM_CYCLES_WS_ACTIVE_Pos      1
#define EBC_RAM_CYCLES_WS_SETUP_Pos       8
#define EBC_RAM_CYCLES_WS_HOLD_Pos        11
#define EBC_RAM_CYCLES_USE_READY_Pos      14

/* Bit field masks: */
#define EBC_RAM_CYCLES_ENABLE_TUNE        ((uint32_t)0x00000001)
#define EBC_RAM_CYCLES_WS_ACTIVE_Msk      ((uint32_t)0x000000FE)
#define EBC_RAM_CYCLES_WS_SETUP_Msk       ((uint32_t)0x00000700)
#define EBC_RAM_CYCLES_WS_HOLD_Msk        ((uint32_t)0x00003200)
#define EBC_RAM_CYCLES_USE_READY          ((uint32_t)0x00004000)

/** @} */ /* End of group EBC_RAM_CYCLESx */
#endif

/** @} */ /* End of group MDR32Fx_Periph_EBC_Defines */

/** @} */ /* End of group MDR32Fx_Periph_EBC */

/** @} */ /* End of group __MDR32Fx_Peripheral_Units */


/** @defgroup __Peripheral_Memory_Map Peripheral Memory Map
  * @{
  */

#define MDR_CAN1_BASE       (0x40000000)
#define MDR_CAN2_BASE       (0x40008000)
#define MDR_USB_BASE        (0x40010000)
#define MDR_EEPROM_BASE     (0x40018000)
#define MDR_RST_CLK_BASE    (0x40020000)
#define MDR_DMA_BASE        (0x40028000)
#define MDR_UART1_BASE      (0x40030000)
#define MDR_UART2_BASE      (0x40038000)
#define MDR_SSP1_BASE       (0x40040000)
#define MDR_I2C_BASE        (0x40050000)
#define MDR_POWER_BASE      (0x40058000)
#define MDR_WWDG_BASE       (0x40060000)
#define MDR_IWDG_BASE       (0x40068000)
#define MDR_TIMER1_BASE     (0x40070000)
#define MDR_TIMER2_BASE     (0x40078000)
#define MDR_TIMER3_BASE     (0x40080000)
#define MDR_ADC_BASE        (0x40088000)
#define MDR_DAC_BASE        (0x40090000)
#define MDR_COMP_BASE       (0x40098000)
#define MDR_SSP2_BASE       (0x400A0000)
#define MDR_PORTA_BASE      (0x400A8000)
#define MDR_PORTB_BASE      (0x400B0000)
#define MDR_PORTC_BASE      (0x400B8000)
#define MDR_PORTD_BASE      (0x400C0000)
#define MDR_PORTE_BASE      (0x400C8000)
#define MDR_BKP_BASE        (0x400D8000)
#define MDR_PORTF_BASE      (0x400E8000)
#define MDR_EBC_BASE        (0x400F0000)

/** @} */ /* End of group __Peripheral_Memory_Map */

/** @defgroup __Peripheral_declaration Peripheral declaration
  * @{
  */

#define MDR_CAN1            ((MDR_CAN_TypeDef     *) MDR_CAN1_BASE)
#define MDR_CAN2            ((MDR_CAN_TypeDef     *) MDR_CAN2_BASE)
#define MDR_USB             ((MDR_USB_TypeDef     *) MDR_USB_BASE)
#define MDR_EEPROM          ((MDR_EEPROM_TypeDef  *) MDR_EEPROM_BASE)
#define MDR_RST_CLK         ((MDR_RST_CLK_TypeDef *) MDR_RST_CLK_BASE)
#define MDR_DMA             ((MDR_DMA_TypeDef     *) MDR_DMA_BASE)
#define MDR_UART1           ((MDR_UART_TypeDef    *) MDR_UART1_BASE)
#define MDR_UART2           ((MDR_UART_TypeDef    *) MDR_UART2_BASE)
#define MDR_SSP1            ((MDR_SSP_TypeDef     *) MDR_SSP1_BASE)
#define MDR_I2C             ((MDR_I2C_TypeDef     *) MDR_I2C_BASE)
#define MDR_POWER           ((MDR_POWER_TypeDef   *) MDR_POWER_BASE)
#define MDR_WWDG            ((MDR_WWDG_TypeDef    *) MDR_WWDG_BASE)
#define MDR_IWDG            ((MDR_IWDG_TypeDef    *) MDR_IWDG_BASE)
#define MDR_TIMER1          ((MDR_TIMER_TypeDef   *) MDR_TIMER1_BASE)
#define MDR_TIMER2          ((MDR_TIMER_TypeDef   *) MDR_TIMER2_BASE)
#define MDR_TIMER3          ((MDR_TIMER_TypeDef   *) MDR_TIMER3_BASE)
#define MDR_ADC             ((MDR_ADC_TypeDef     *) MDR_ADC_BASE)
#define MDR_DAC             ((MDR_DAC_TypeDef     *) MDR_DAC_BASE)
#define MDR_COMP            ((MDR_COMP_TypeDef    *) MDR_COMP_BASE)
#define MDR_SSP2            ((MDR_SSP_TypeDef     *) MDR_SSP2_BASE)
#define MDR_PORTA           ((MDR_PORT_TypeDef    *) MDR_PORTA_BASE)
#define MDR_PORTB           ((MDR_PORT_TypeDef    *) MDR_PORTB_BASE)
#define MDR_PORTC           ((MDR_PORT_TypeDef    *) MDR_PORTC_BASE)
#define MDR_PORTD           ((MDR_PORT_TypeDef    *) MDR_PORTD_BASE)
#define MDR_PORTE           ((MDR_PORT_TypeDef    *) MDR_PORTE_BASE)
#define MDR_BKP             ((MDR_BKP_TypeDef     *) MDR_BKP_BASE)
#define MDR_PORTF           ((MDR_PORT_TypeDef    *) MDR_PORTF_BASE)
#define MDR_EBC             ((MDR_EBC_TypeDef     *) MDR_EBC_BASE)

/** @} */ /* End of group __Peripheral_declaration */

#ifdef __cplusplus
}
#endif

/** @} */ /* End of group __MDR32Fx_Peripheral */

#define BITBAND_SRAM_REF    (0x20000000)
#define BITBAND_SRAM_BASE   (0x22000000)
#define BITBAND_PER_REF     (0x40000000)
#define BITBAND_PER_BASE    (0x42000000)

#define BIT_RAM_P(pa,b) *((volatile uint32_t *)(BITBAND_SRAM_BASE+((uint32_t)(pa)-BITBAND_SRAM_REF)*32+((b)*4)))
#define BIT_PER(a,b)    *((volatile uint32_t *)(BITBAND_PER_BASE +((uint32_t)&(a)-BITBAND_PER_REF) *32+((b)*4)))

#define CLR_BIT_RAM_P(pa,b) (BIT_RAM_P(pa,b) = 0x00000000)
#define CLR_BIT_PER(a,b)    (BIT_PER(a,b)    = 0x00000000)

#define SET_BIT_RAM_P(pa,b) (BIT_RAM_P(pa,b) = 0x00000001)
#define SET_BIT_PER(a,b)    (BIT_PER(a,b)    = 0x00000001)

#define CHF_BIT_RAM_P(pa,b) (BIT_RAM_P(pa,b) == 0x00000000)
#define CHF_BIT_PER(a,b)    (BIT_PER(a,b)    == 0x00000000)

#define CHT_BIT_RAM_P(pa,b) (BIT_RAM_P(pa,b) == 0x00000001)
#define CHT_BIT_PER(a,b)    (BIT_PER(a,b)    == 0x00000001)

/** @} */ /* End of group MDR1986VE9x */

/** @} */ /* End of group __CMSIS */

#endif /* __MDR32FX_H */

/******************* (C) COPYRIGHT 2010 Phyton *********************************
*
* END OF FILE MDR32Fx.h */
