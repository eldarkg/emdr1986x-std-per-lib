/**
  * FILE MDR1986VE1T.h
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MDR1986VE1T_H
#define __MDR1986VE1T_H

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup __CMSIS CMSIS
  * @{
  */

/** @defgroup MDR1986VE1T MDR1986VE1T
  * @{
  */

/** @defgroup MDR1986VE1T_Peripheral MDR1986VE1T Peripheral
  * @{
  */

#if defined ( __CC_ARM   )
  #pragma anon_unions
#endif

/**
  * @brief MDR1986VE1T Interrupt Number Definition
  */

typedef enum IRQn
{
/*-----  Cortex-M1 Processor Exceptions Numbers --------------------------------------------------*/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                             */
  HardFault_IRQn              = -13,    /*!< 3 Cortex-M1 Hard Fault Interrupt                     */
  SVCall_IRQn                 = -5,     /*!< 11 Cortex-M1 SV Call Interrupt                       */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M1 Pend SV Interrupt                       */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M1 System Tick Interrupt                   */

/*----- 1986EV3 specific Interrupt Numbers -------------------------------------------------------*/
  MIL_STD_1553B2_IRQn         = 0,      /*!< MIL_STD_1553B2 Interrupt                             */
  MIL_STD_1553B1_IRQn         = 1,      /*!< MIL_STD_1553B1 Interrupt                             */
  USB_IRQn                    = 2,      /*!< USB Host Interrupt                                   */
  CAN1_IRQn                   = 3,      /*!< CAN1 Interrupt                                       */
  CAN2_IRQn                   = 4,      /*!< CAN2 Interrupt                                       */
  DMA_IRQn                    = 5,      /*!< DMA Interrupt                                        */
  UART1_IRQn                  = 6,      /*!< UART1 Interrupt                                      */
  UART2_IRQn                  = 7,      /*!< UART2 Interrupt                                      */
  SSP1_IRQn                   = 8,      /*!< SSP1 Interrupt                                       */
  BUSY_IRQn                   = 9,      /*!< BUSY Interrupt                                       */
  ARINC429R_IRQn              = 10,     /*!< ARINC429 Receiver Interrupt                          */
  POWER_IRQn                  = 11,     /*!< POWER Detecor Interrupt                              */
  WWDG_IRQn                   = 12,     /*!< Window Watchdog Interrupt                            */
  TIMER4_IRQn                 = 13,     /*!< Timer4 Interrupt                                     */
  TIMER1_IRQn                 = 14,     /*!< Timer1 Interrupt                                     */
  TIMER2_IRQn                 = 15,     /*!< Timer2 Interrupt                                     */
  TIMER3_IRQn                 = 16,     /*!< Timer3 Interrupt                                     */
  ADC_IRQn                    = 17,     /*!< ADC Interrupt                                        */
  ETHERNET_IRQn               = 18,     /*!< Ethernet Interrupt                                   */
  SSP3_IRQn                   = 19,     /*!< SSP3 Interrupt                                       */
  SSP2_IRQn                   = 20,     /*!< SSP2 Interrupt                                       */
  ARINC429T1_IRQn             = 21,     /*!< ARINC429 Transmitter 1 Interrupt                     */
  ARINC429T2_IRQn             = 22,     /*!< ARINC429 Transmitter 2 Interrupt                     */
  ARINC429T3_IRQn             = 23,     /*!< ARINC429 Transmitter 3 Interrupt                     */
  ARINC429T4_IRQn             = 24,     /*!< ARINC429 Transmitter 4 Interrupt                     */
  BKP_IRQn                    = 27,     /*!< BACKUP Interrupt                                     */
  EXT_INT1_IRQn               = 28,     /*!< EXT_INT1 Interrupt                                   */
  EXT_INT2_IRQn               = 29,     /*!< EXT_INT2 Interrupt                                   */
  EXT_INT3_IRQn               = 30,     /*!< EXT_INT3 Interrupt                                   */
  EXT_INT4_IRQn               = 31      /*!< EXT_INT4 Interrupt                                   */
}IRQn_Type;

/** @addtogroup __1T___Configuration_of_CMSIS Configuration of CMSIS
  * @{
  */
/* Configuration of the Cortex-M1 Processor and Core Peripherals */
#define __CM1_REV              0x0102   /*!< Cortex-M1 Core Revision                      */
#define __MPU_PRESENT             0     /*!< MPU present or not                           */
#define __NVIC_PRIO_BITS          2     /*!< Number of Bits used for Priority Levels      */
#define __Vendor_SysTickConfig    0     /*!< Set to 1 if different SysTick Config is used */

/** @} */ /* __Configuration_of_CMSIS */

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_config.h"
#include "core_cm1.h"
#include "system_MDR1986VE1T.h"

/** @defgroup __1T___Exported_types Exported types
  * @{
  */
typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus, BitStatus;

#define IS_BIT_STATUS(STATUS)   (((STATUS) == RESET) || ((STATUS) == SET))

typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;
#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

typedef enum {ERROR = 0, SUCCESS = !ERROR} ErrorStatus;

/** @} */ /* End of group __Exported_types */

/** @defgroup __1T___MDR1986VE1T_Periph_CAN CAN
  * @{
  */

/** @defgroup __1T___MDR1986VE1T_CAN_Data_Structures Data Structures
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

/** @} */ /* End of group __MDR1986VE1T_CAN_Data_Structures */

/** @defgroup __1T___MDR1986VE1T_Periph_CAN_Defines Defines
  * @{
  */

/** @defgroup __1T_Periph_CAN_CONTROL   CAN CONTROL
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

/** @defgroup __1T_Periph_CAN_STATUS    CAN STATUS
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

/** @defgroup __1T_Periph_CAN_BITTMNG   CAN BITTMNG
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

/** @defgroup __1T_Periph_CAN_INT_EN  CAN INT EN
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

/** @defgroup __1T_Periph_CAN_RXID  CAN RXID
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

/** @defgroup __1T_Periph_CAN_RXDLC CAN RXDLC
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

/** @defgroup __1T_Periph_CAN_RXDATAL CAN RXDATAL
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

/** @defgroup __1T_Periph_CAN_RXDATAH CAN RXDATAH
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

/** @defgroup __1T_Periph_CAN_BUF_CON CAN BUF CON
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

/** @} */ /* End of group __MDR1986VE1T_Periph_CAN_Defines Defines */

/** @} */ /* End of group __MDR1986VE1T_Periph_CAN CAN */

/** @defgroup __1T___MDR1986VE1T_Periph_USB USB
  * @{
  */

/** @defgroup __1T___MDR1986VE1T_Periph_USB_Data_Structures Data Structures
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

/** @} */ /* End of group __MDR1986VE1T_Periph_USB_Data_Structures */

/** @defgroup __1T___MDR1986VE1T_Periph_USB_Defines Defines
  * @{
  */

/** @defgroup __1T_Periph_USB_HTXC  USB HTXC
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

/** @defgroup __1T_Periph_USB_HTXLC USB HTXLC
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

/** @defgroup __1T_Periph_USB_HIS USB HIS
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

/** @defgroup __1T_Periph_USB_HIM USB HIM
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

/** @defgroup __1T_Periph_USB_HRXS  USB HRXS
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

/** @defgroup __1T_Periph_USB_SEP_CTRL  USB SEP CTRL
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

/** @defgroup __1T_Periph_USB_SEP_STS USB SEP STS
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

/** @defgroup __1T_Periph_USB_SC  USB SC
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

/** @defgroup __1T_Periph_USB_SIS USB SIS
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

/** @defgroup __1T_Periph_USB_SIM USB SIM
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

/** @defgroup __1T_Periph_USB_HSCR  USB HSCR
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

/** @defgroup __1T_Periph_USB_HSVR  USB HSVR
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

/** @} */ /* End of group __MDR1986VE1T_Periph_USB_Defines */

/** @} */ /* End of group __MDR1986VE1T_Periph_USB */


/** @defgroup __1T___1986VE1T_Periph_EEPROM EEPROM
  * @{
  */

/** @defgroup __1T___MDR1986VE1T_Periph_EEPROM_Data_Structures Data Structures
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

/** @} */ /* End of group __MDR1986VE1T_Periph_EEPROM_Data_Structures */

/** @defgroup __1T___MDR1986VE1T_Periph_EEPROM_Defines Defines
  * @{
  */

/** @defgroup __1T_Periph_EEPROM_CMD  EEPROM CMD
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

#define EEPROM_ADDRESS                          0x00000000

#define EEPROM_SECTOR_A_SHIFT                   0x00
#define EEPROM_SECTOR_B_SHIFT                   0x04
#define EEPROM_SECTOR_C_SHIFT                   0x08
#define EEPROM_SECTOR_D_SHIFT                   0x0C

#define EEPROM_WORD_SIZE                        4
#define EEPROM_PAGE_SIZE                        4096

/** @} */ /* End of group EEPROM_CMD */

/** @} */ /* End of group __MDR1986VE1T_Periph_EEPROM_Defines Defines */

/** @}*/ /* End of group 1986VE1T_Periph_EEPROM EEPROM */

/** @defgroup __1T___MDR1986VE1T_Periph_RST_CLK RST_CLK
  * @{
  */

/** @defgroup __1T_Periph_RST_CLK_Data_Structures Data Structures
  * @{
  */

/* Periph_RST_CLK_TypeDef RST_CLK_TypeDef */
typedef struct {
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
       uint32_t RESERVED;
  __IO uint32_t ETH_CLOCK;
} MDR_RST_CLK_TypeDef;

/** @} */ /* End of group Periph_RST_CLK_Data_Structures */

/** @defgroup __1T_Periph_RST_CLK_Defines Defines
  * @{
  */

/** @defgroup __1T_Periph_RST_CLK_CLOCK_STATUS  RST CLK CLOCK STATUS
  * @{
  */

/*-- RST_CLK_CLOCK_STATUS: Clock Status Register -------------------*/
/* Bit field positions: */
#define RST_CLK_CLOCK_STATUS_PLL_USB_RDY_Pos    0
#define RST_CLK_CLOCK_STATUS_PLL_CPU_RDY_Pos    1
#define RST_CLK_CLOCK_STATUS_HSE_RDY_Pos        2
#define RST_CLK_CLOCK_STATUS_HSE_RDY2_Pos       3

/* Bit field masks: */
#define RST_CLK_CLOCK_STATUS_PLL_USB_RDY        ((uint32_t)0x00000001)
#define RST_CLK_CLOCK_STATUS_PLL_CPU_RDY        ((uint32_t)0x00000002)
#define RST_CLK_CLOCK_STATUS_HSE_RDY            ((uint32_t)0x00000004)
#define RST_CLK_CLOCK_STATUS_HSE_RDY2           ((uint32_t)0x00000008)

#define RST_CLK_CLOCK_STATUS_HSE_ALL_RDY        (RST_CLK_CLOCK_STATUS_HSE_RDY | \
                                                 RST_CLK_CLOCK_STATUS_HSE_RDY2)

/** @} */ /* End of group RST_CLK_CLOCK_STATUS */


/** @defgroup __1T_Periph_RST_CLK_PLL_CONTROL   RST CLK PLL CONTROL
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


/** @defgroup __1T_Periph_RST_CLK_HS_CONTROL    RST CLK HS CONTROL
  * @{
  */

/*-- RST_CLK_HS_CONTROL: HS Control Register -----------------------*/
/* Bit field positions: */
#define RST_CLK_HS_CONTROL_HSE_ON_Pos           0
#define RST_CLK_HS_CONTROL_HSE_BYP_Pos          1
#define RST_CLK_HS_CONTROL_HSE_ON2_Pos          2
#define RST_CLK_HS_CONTROL_HSE_BYP2_Pos         3

/* Bit field masks: */
#define RST_CLK_HS_CONTROL_HSE_ON               ((uint32_t)0x00000001)
#define RST_CLK_HS_CONTROL_HSE_BYP              ((uint32_t)0x00000002)
#define RST_CLK_HS_CONTROL_HSE_ON2              ((uint32_t)0x00000004)
#define RST_CLK_HS_CONTROL_HSE_BYP2             ((uint32_t)0x00000008)

/** @} */ /* End of group RST_CLK_HS_CONTROL */

/** @defgroup __1T_Periph_RST_CLK_CPU_CLOCK RST CLK CPU CLOCK
  * @{
  */

/*-- RST_CLK_CPU_CLOCK: CPU Clock Register -----------------------*/
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

/** @} */ /* End of group Periph_RST_CLK_CPU_CLOCK */


/** @defgroup __1T_Periph_RST_CLK_USB_CLOCK RST CLK USB CLOCK
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


/** @defgroup __1T_Periph_RST_CLK_ADC_MCO_CLOCK RST CLK ADC MCO CLOCK
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


/** @defgroup __1T_Periph_RST_CLK_RTC_CLOCK RST CLK RTC CLOCK
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
#define RST_CLK_PER_CLOCK_PCLK_EN_MIL_STD_1553B1_Pos  9
#define RST_CLK_PER_CLOCK_PCLK_EN_MIL_STD_1553B2_Pos  10
#define RST_CLK_PER_CLOCK_PCLK_EN_POWER_Pos           11
#define RST_CLK_PER_CLOCK_PCLK_EN_WWDT_Pos            12
#define RST_CLK_PER_CLOCK_PCLK_EN_IWDT_Pos            13
#define RST_CLK_PER_CLOCK_PCLK_EN_TIMER1_Pos          14
#define RST_CLK_PER_CLOCK_PCLK_EN_TIMER2_Pos          15
#define RST_CLK_PER_CLOCK_PCLK_EN_TIMER3_Pos          16
#define RST_CLK_PER_CLOCK_PCLK_EN_ADC_Pos             17
#define RST_CLK_PER_CLOCK_PCLK_EN_DAC_Pos             18
#define RST_CLK_PER_CLOCK_PCLK_EN_TIMER4_Pos          19
#define RST_CLK_PER_CLOCK_PCLK_EN_SPI2_Pos            20
#define RST_CLK_PER_CLOCK_PCLK_EN_PORTA_Pos           21
#define RST_CLK_PER_CLOCK_PCLK_EN_PORTB_Pos           22
#define RST_CLK_PER_CLOCK_PCLK_EN_PORTC_Pos           23
#define RST_CLK_PER_CLOCK_PCLK_EN_PORTD_Pos           24
#define RST_CLK_PER_CLOCK_PCLK_EN_PORTE_Pos           25
#define RST_CLK_PER_CLOCK_PCLK_EN_ARINC429R_Pos       26
#define RST_CLK_PER_CLOCK_PCLK_EN_BKP_Pos             27
#define RST_CLK_PER_CLOCK_PCLK_EN_ARINC429T_Pos       28
#define RST_CLK_PER_CLOCK_PCLK_EN_PORTF_Pos           29
#define RST_CLK_PER_CLOCK_PCLK_EN_EXT_BUS_CNTRL_Pos   30
#define RST_CLK_PER_CLOCK_PCLK_EN_SPI3_Pos            31

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
#define RST_CLK_PER_CLOCK_PCLK_EN_MIL_STD_1553B1      ((uint32_t)0x00000200)
#define RST_CLK_PER_CLOCK_PCLK_EN_MIL_STD_1553B2      ((uint32_t)0x00000400)
#define RST_CLK_PER_CLOCK_PCLK_EN_POWER               ((uint32_t)0x00000800)
#define RST_CLK_PER_CLOCK_PCLK_EN_WWDT                ((uint32_t)0x00001000)
#define RST_CLK_PER_CLOCK_PCLK_EN_IWDT                ((uint32_t)0x00002000)
#define RST_CLK_PER_CLOCK_PCLK_EN_TIMER1              ((uint32_t)0x00004000)
#define RST_CLK_PER_CLOCK_PCLK_EN_TIMER2              ((uint32_t)0x00008000)
#define RST_CLK_PER_CLOCK_PCLK_EN_TIMER3              ((uint32_t)0x00010000)
#define RST_CLK_PER_CLOCK_PCLK_EN_ADC                 ((uint32_t)0x00020000)
#define RST_CLK_PER_CLOCK_PCLK_EN_DAC                 ((uint32_t)0x00040000)
#define RST_CLK_PER_CLOCK_PCLK_EN_TIMER4              ((uint32_t)0x00080000)
#define RST_CLK_PER_CLOCK_PCLK_EN_SPI2                ((uint32_t)0x00100000)
#define RST_CLK_PER_CLOCK_PCLK_EN_PORTA               ((uint32_t)0x00200000)
#define RST_CLK_PER_CLOCK_PCLK_EN_PORTB               ((uint32_t)0x00400000)
#define RST_CLK_PER_CLOCK_PCLK_EN_PORTC               ((uint32_t)0x00800000)
#define RST_CLK_PER_CLOCK_PCLK_EN_PORTD               ((uint32_t)0x01000000)
#define RST_CLK_PER_CLOCK_PCLK_EN_PORTE               ((uint32_t)0x02000000)
#define RST_CLK_PER_CLOCK_PCLK_EN_ARINC429R           ((uint32_t)0x04000000)
#define RST_CLK_PER_CLOCK_PCLK_EN_BKP                 ((uint32_t)0x08000000)
#define RST_CLK_PER_CLOCK_PCLK_EN_ARINC429T           ((uint32_t)0x10000000)
#define RST_CLK_PER_CLOCK_PCLK_EN_PORTF               ((uint32_t)0x20000000)
#define RST_CLK_PER_CLOCK_PCLK_EN_EXT_BUS_CNTRL       ((uint32_t)0x40000000)
#define RST_CLK_PER_CLOCK_PCLK_EN_SPI3                ((uint32_t)0x80000000)

/** @} */ /* End of group RST_CLK_PER_CLOCK */

/** @defgroup Periph_RST_CLK_PER_CLOCK  RST CLK PER CLOCK
  * @{
  */


/** @defgroup __1T_Periph_RST_CLK_CAN_CLOCK RST CLK CAN CLOCK
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


/** @defgroup __1T_Periph_RST_CLK_TIM_CLOCK RST CLK TIM CLOCK
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

/** @defgroup __1T_Periph_RST_CLK_UART_CLOCK    RST CLK UART CLOCK
  * @{
  */

/*-- RST_CLK_UART_CLOCK: UART Clock Register -----------------------*/
/* Bit field positions: */
#define RST_CLK_UART_CLOCK_UART1_BRG_Pos        0
#define RST_CLK_UART_CLOCK_UART2_BRG_Pos        8
#define RST_CLK_UART_CLOCK_TIM4_BRG_Pos         16
#define RST_CLK_UART_CLOCK_UART1_CLK_EN_Pos     24
#define RST_CLK_UART_CLOCK_UART2_CLK_EN_Pos     25
#define RST_CLK_UART_CLOCK_TIM4_CLK_EN_Pos      26

/* Bit field masks: */
#define RST_CLK_UART_CLOCK_UART1_BRG_Msk        ((uint32_t)0x000000FF)
#define RST_CLK_UART_CLOCK_UART2_BRG_Msk        ((uint32_t)0x0000FF00)
#define RST_CLK_UART_CLOCK_TIM4_BRG_Msk         ((uint32_t)0x00FF0000)
#define RST_CLK_UART_CLOCK_UART1_CLK_EN         ((uint32_t)0x01000000)
#define RST_CLK_UART_CLOCK_UART2_CLK_EN         ((uint32_t)0x02000000)
#define RST_CLK_UART_CLOCK_TIM4_CLK_EN          ((uint32_t)0x04000000)

/* UART BRG Modes */
#define RST_CLK_UART_CLOCK_UART_BRG_HCLK            0x00
#define RST_CLK_UART_CLOCK_UART_BRG_HCLK_DIV_2      0x01
#define RST_CLK_UART_CLOCK_UART_BRG_HCLK_DIV_4      0x02
#define RST_CLK_UART_CLOCK_UART_BRG_HCLK_DIV_8      0x03
#define RST_CLK_UART_CLOCK_UART_BRG_HCLK_DIV_16     0x04
#define RST_CLK_UART_CLOCK_UART_BRG_HCLK_DIV_32     0x05
#define RST_CLK_UART_CLOCK_UART_BRG_HCLK_DIV_64     0x06
#define RST_CLK_UART_CLOCK_UART_BRG_HCLK_DIV_128    0x07

/* TIM4 BRG Modes */
#define RST_CLK_UART_CLOCK_TIM4_BRG_HCLK          0x00
#define RST_CLK_UART_CLOCK_TIM4_BRG_HCLK_DIV_2    0x01
#define RST_CLK_UART_CLOCK_TIM4_BRG_HCLK_DIV_4    0x02
#define RST_CLK_UART_CLOCK_TIM4_BRG_HCLK_DIV_8    0x03
#define RST_CLK_UART_CLOCK_TIM4_BRG_HCLK_DIV_16   0x04
#define RST_CLK_UART_CLOCK_TIM4_BRG_HCLK_DIV_32   0x05
#define RST_CLK_UART_CLOCK_TIM4_BRG_HCLK_DIV_64   0x06
#define RST_CLK_UART_CLOCK_TIM4_BRG_HCLK_DIV_128  0x07

/** @} */ /* End of group RST_CLK_UART_CLOCK */


/** @defgroup __1T_Periph_RST_CLK_SSP_CLOCK RST CLK SSP CLOCK
  * @{
  */

/*-- RST_CLK_SSP_CLOCK: SSP Clock Register -----------------------*/
/* Bit field positions: */
#define RST_CLK_SSP_CLOCK_SSP1_BRG_Pos          0
#define RST_CLK_SSP_CLOCK_SSP2_BRG_Pos          8
#define RST_CLK_SSP_CLOCK_SSP3_BRG_Pos          16
#define RST_CLK_SSP_CLOCK_SSP1_CLK_EN_Pos       24
#define RST_CLK_SSP_CLOCK_SSP2_CLK_EN_Pos       25
#define RST_CLK_SSP_CLOCK_SSP3_CLK_EN_Pos       26

/* Bit field masks: */
#define RST_CLK_SSP_CLOCK_SSP1_BRG_Msk          ((uint32_t)0x000000FF)
#define RST_CLK_SSP_CLOCK_SSP2_BRG_Msk          ((uint32_t)0x0000FF00)
#define RST_CLK_SSP_CLOCK_SSP3_BRG_Msk          ((uint32_t)0x00FF0000)
#define RST_CLK_SSP_CLOCK_SSP1_CLK_EN           ((uint32_t)0x01000000)
#define RST_CLK_SSP_CLOCK_SSP2_CLK_EN           ((uint32_t)0x02000000)
#define RST_CLK_SSP_CLOCK_SSP3_CLK_EN           ((uint32_t)0x04000000)

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


/** @defgroup __1T_Periph_RST_CLK_ETH_CLOCK RST CLK ETR CLOCK
  * @{
  */

/*-- RST_CLK_ETH_CLOCK: ETH Clock Register -----------------------*/
/* Bit field positions: */
#define RST_CLK_ETH_CLOCK_ETH_BRG_Pos           0
#define RST_CLK_ETH_CLOCK_MAN_BRG_Pos           8
#define RST_CLK_ETH_CLOCK_PHY_BRG_Pos           16
#define RST_CLK_ETH_CLOCK_ETH_CLK_EN_Pos        24
#define RST_CLK_ETH_CLOCK_MAN_CLK_EN_Pos        25
#define RST_CLK_ETH_CLOCK_SLEEP_Pos             26
#define RST_CLK_ETH_CLOCK_PHY_CLK_EN_Pos        27
#define RST_CLK_ETH_CLOCK_PHY_CLK_SEL_Pos       28
#define RST_CLK_ETH_CLOCK_ETH2_CLK_EN_Pos       30

/* Bit field masks: */
#define RST_CLK_ETH_CLOCK_ETH_BRG_Msk           ((uint32_t)0x000000FF)
#define RST_CLK_ETH_CLOCK_MAN_BRG_Msk           ((uint32_t)0x0000FF00)
#define RST_CLK_ETH_CLOCK_PHY_BRG_Msk           ((uint32_t)0x00FF0000)
#define RST_CLK_ETH_CLOCK_ETH_CLK_EN            ((uint32_t)0x01000000)
#define RST_CLK_ETH_CLOCK_MAN_CLK_EN            ((uint32_t)0x02000000)
#define RST_CLK_ETH_CLOCK_SLEEP                 ((uint32_t)0x04000000)
#define RST_CLK_ETH_CLOCK_PHY_CLK_EN            ((uint32_t)0x08000000)
#define RST_CLK_ETH_CLOCK_PHY_CLK_SEL_Msk       ((uint32_t)0x30000000)
#define RST_CLK_ETH_CLOCK_ETH2_CLK_EN           ((uint32_t)0x40000000)

/* PHY_BRG Modes */
#define RST_CLK_ETH_CLOCK_PHY_BRG_PHY1_CLK          0x00
#define RST_CLK_ETH_CLOCK_PHY_BRG_PHY1_CLK_DIV_2    0x01
#define RST_CLK_ETH_CLOCK_PHY_BRG_PHY1_CLK_DIV_4    0x02
#define RST_CLK_ETH_CLOCK_PHY_BRG_PHY1_CLK_DIV_8    0x03
#define RST_CLK_ETH_CLOCK_PHY_BRG_PHY1_CLK_DIV_16   0x04
#define RST_CLK_ETH_CLOCK_PHY_BRG_PHY1_CLK_DIV_32   0x05
#define RST_CLK_ETH_CLOCK_PHY_BRG_PHY1_CLK_DIV_64   0x06
#define RST_CLK_ETH_CLOCK_PHY_BRG_PHY1_CLK_DIV_128  0x07

/* PHY CLK SEL Modes */
#define RST_CLK_ETH_CLOCK_PHY_CLK_SEL_HSI           0x00
#define RST_CLK_ETH_CLOCK_PHY_CLK_SEL_HSE           0x01
#define RST_CLK_ETH_CLOCK_PHY_CLK_SEL_PLL_CPU       0x02
#define RST_CLK_ETH_CLOCK_PHY_CLK_SEL_HSE2          0x03

/** @} */ /* End of group RST_CLK_ETH_CLOCK */

/** @} */ /* End of group Periph_RST_CLK_Defines */

/** @} */ /* End of group Periph_RST_CLK */


/** @defgroup __1T___MDR1986VE1T_Periph_DMA DMA
  * @{
  */

/** @defgroup __1T___MDR1986VE1T_Periph_DMA_Data_Structures Data Structures
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

/** @} */ /* End of group __MDR1986VE1T_Periph_DMA_Data_Structures */

/** @defgroup __1T___MDR1986VE1T_Periph_DMA_Defines Defines
  * @{
  */

/** @defgroup __1T_Periph_DMA_STATUS  DMA STATUS
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

/** @defgroup __1T_Periph_DMA_CFG DMA CFG
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

/** @} */ /* End of group __MDR1986VE1T_Periph_DMA_Defines */

/** @} */ /* End of group __MDR1986VE1T_Periph_DMA */


/** @defgroup __1T___MDR1986VE1T_Periph_UART UART
  * @{
  */

/** @defgroup __1T_Periph_UART_Data_Structures Data Structures
  * @{
  */

/** @defgroup __1T_Periph_UART_TypeDef UART_TypeDef
  * @{
  */

typedef struct {
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
  __IO uint32_t UARTTCR;
} MDR_UART_TypeDef;

/** @} */ /* End of group Periph_UART_TypeDef */

/** @} */ /* End of group Periph_UART_Data_Structures */

/** @defgroup __1T_Periph_UART_Defines Defines
  * @{
  */

/** @defgroup __1T_Periph_UART_DR UART DR
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

/** @defgroup __1T_Periph_UART_RSR_ECR  UART RSR ECR
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

/** @defgroup __1T_Periph_UART_FR UART FR
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

/** @defgroup __1T_Periph_UART_LCR_H  UART LCR H
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

/** @defgroup __1T_Periph_UART_CR UART CR
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

/** @defgroup __1T_Periph_UART_IFLS UART IFLS
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

/** @defgroup __1T_Periph_UART_IMSC UART IMSC
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


/** @defgroup __1T_Periph_UART_RIS  UART RIS
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

/** @defgroup __1T_Periph_UART_MIS  UART MIS
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

/** @defgroup __1T_Periph_UART_ICR  UART ICR
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

/** @defgroup __1T_Periph_UART_DMACR  UART DMACR
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

/** @defgroup __1T_Periph_UART_RTTCR  UART RTTCR
  * @{
  */

/*-- UART_RTTCR: UART Test Control Register -------------------------*/
/* Bit field positions: */
#define UART_UARTTCR_ITEN_Pos                   0
#define UART_UARTTCR_TESTFIFO_Pos               1
#define UART_UARTTCR_SIRTEST_Pos                2

/* Bit field masks: */
#define UART_UARTTCR_ITEN                       ((uint32_t)0x00000001)
#define UART_UARTTCR_TESTFIFO                   ((uint32_t)0x00000002)
#define UART_UARTTCR_SIRTEST                    ((uint32_t)0x00000004)

/** @} */ /* End of group UART_RTTCR */

/** @} */ /* End of group Periph_UART_Defines */

/** @} */ /* End of group Periph_UART */


/** @defgroup __1T___MDR1986VE1T_Periph_SPI SPI
  * @{
  */

/** @defgroup __1T_Periph_SPI_Data_Structures Data Structures
  * @{
  */

/** @defgroup __1T_Periph_SPI_TypeDef SPI_TypeDef
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


/** @} */ /* End of group Periph_SPI_TypeDef */

/** @} */ /* End of group Periph_SPI_Data_Structures */

/** @defgroup __1T_Periph_SPI_Defines Defines
  * @{
  */

/** @defgroup __1T_Periph_SSP_CR0   SSP CR0
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


/** @} */ /* End of group Periph_SPI_Defines */

/** @defgroup __1T_Periph_SPI_Defines Defines
  * @{
  */

/** @defgroup __1T_Periph_SSP_CR1 SSP CR1
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

/** @defgroup __1T_Periph_SSP_SR  SSP SR
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


/*-- SSP_CPSR: SSP Clock Prescale Register --------------------------------*/
/* Bit field positions: */
#define SSP_CPSR_CPSDVSR_Pos                    0

/* Bit field masks: */
#define SSP_CPSR_CPSDVSR_Msk                    ((uint32_t)0x0000000F)

/** @} */ /* End of group SSP_CPSR */

/** @defgroup __1T_Periph_SSP_IMSC  SSP IMSC
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

/** @defgroup __1T_Periph_SSP_RIS SSP RIS
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

/** @defgroup __1T_Periph_SSP_MIS SSP MIS
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

/** @defgroup __1T_SPI_SSPx SPI SSPx
 *  @{
 */

/*-- SPI_SSPx: SPI_SSPx Register ----------------*/
/* Bit field positions: */
#define SPI_SSPx_ICR_RORIC_Pos                 0
#define SPI_SSPx_ICR_RTIC_Pos                  1

/* Bit field masks: */
#define SPI_SSPx_ICR_RORIC                      ((uint32_t)0x00000001)
#define SPI_SSPx_ICR_RTIC                       ((uint32_t)0x00000002)

/** @} */ /* End of group SPI_SSPx */

/** @defgroup __1T_Periph_SSP_ICR SSP ICR
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

/** @defgroup __1T_Periph_SSP_DMACR SSP DMACR
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

/** @} */ /* End of group Periph_SPI_Defines */

/** @} */ /* End of group Periph_SPI */

/** @defgroup __1T___MDR1986VE1T_Periph_MIL_STD_1553 MIL_STD_1553
  * @{
  */

/** @defgroup __1T_Periph_MIL_STD_1553_Data_Structures Data Structures
  * @{
  */

/* MDR_MIL_STD_1553_TypeDef structure */
typedef struct {
  uint32_t RESERVED0[1024];
  __IO uint32_t CONTROL;
  __IO uint32_t STATUS;
  __IO uint32_t ERROR;
  __IO uint32_t CommandWord1;
  __IO uint32_t CommandWord2;
  __IO uint32_t ModeData;
  __IO uint32_t StatusWord1;
  __IO uint32_t StatusWord2;
  __IO uint32_t INTEN;
  __IO uint32_t MSG;
} MDR_MIL_STD_1553_TypeDef;

/** @} */ /* End of group Periph_MIL_STD_1553_Data_Structures */

/** @defgroup __1T_Periph_MIL_STD_1553_Defines Defines
  * @{
  */
/** @defgroup __1T_Periph_MIL_STD_1553_CONTROL  MIL STD 1553 CONTROL
  * @{
  */

/*-- MIL_STD_1553_CONTROL: MIL_STD_1553 Control Register -----*/
/* Bit field positions: */
#define MIL_STD_1553_CONTROL_MR_Pos            0
#define MIL_STD_1553_CONTROL_BCSTART_Pos       1
#define MIL_STD_1553_CONTROL_BCMODE_Pos        2
#define MIL_STD_1553_CONTROL_RTMODE_Pos        3
#define MIL_STD_1553_CONTROL_TRA_Pos           4
#define MIL_STD_1553_CONTROL_TRB_Pos           5
#define MIL_STD_1553_CONTROL_RTA_Pos           6
#define MIL_STD_1553_CONTROL_DIV_Pos           11
#define MIL_STD_1553_CONTROL_RERR_Pos          18
#define MIL_STD_1553_CONTROL_INVTR_Pos         19
#define MIL_STD_1553_CONTROL_ENFILTER_Pos      20
#define MIL_STD_1553_CONTROL_AUTOTUNE_Pos      21

/* Bit field masks: */
#define MIL_STD_1553_CONTROL_MR                 ((uint32_t)0x00000001)
#define MIL_STD_1553_CONTROL_BCSTART            ((uint32_t)0x00000002)
#define MIL_STD_1553_CONTROL_BCMODE             ((uint32_t)0x00000004)
#define MIL_STD_1553_CONTROL_RTMODE             ((uint32_t)0x00000008)
#define MIL_STD_1553_CONTROL_TRA                ((uint32_t)0x00000010)
#define MIL_STD_1553_CONTROL_TRB                ((uint32_t)0x00000020)
#define MIL_STD_1553_CONTROL_RTA_Msk            ((uint32_t)0x000007C0)
#define MIL_STD_1553_CONTROL_DIV_Msk            ((uint32_t)0x0003F800)
#define MIL_STD_1553_CONTROL_RERR               ((uint32_t)0x00040000)
#define MIL_STD_1553_CONTROL_INVTR              ((uint32_t)0x00080000)
#define MIL_STD_1553_CONTROL_ENFILTER           ((uint32_t)0x00100000)
#define MIL_STD_1553_CONTROL_AUTOTUNE           ((uint32_t)0x00200000)

/** @} */ /* End of group MIL_STD_1553_CONTROL */


/** @defgroup __1T_Periph_MIL_STD_1553_STATUS   MIL STD 1553 STATUS
  * @{
  */

/*-- MIL_STD_1553_STATUS: MIL_STD_1553 Status Register -----*/
/* Bit field positions: */
#define MIL_STD_1553_STATUS_IDLE_Pos                 0
#define MIL_STD_1553_STATUS_RFLAGN_Pos               1
#define MIL_STD_1553_STATUS_VALMESS_Pos              2
#define MIL_STD_1553_STATUS_ERR_Pos                  3
#define MIL_STD_1553_STATUS_RCVA_Pos                 4
#define MIL_STD_1553_STATUS_RCVB_Pos                 5

/* Bit field masks: */
#define MIL_STD_1553_STATUS_IDLE                     ((uint32_t)0x00000001)
#define MIL_STD_1553_STATUS_RFLAGN                   ((uint32_t)0x00000002)
#define MIL_STD_1553_STATUS_VALMESS                  ((uint32_t)0x00000004)
#define MIL_STD_1553_STATUS_ERR                      ((uint32_t)0x00000008)
#define MIL_STD_1553_STATUS_RCVA                     ((uint32_t)0x00000010)
#define MIL_STD_1553_STATUS_RCVB                     ((uint32_t)0x00000020)

/** @} */ /* End of group MIL_STD_1553_STATUS */

/** @defgroup __1T_Periph_MIL_STD_1553_ERROR    MIL STD 1553 ERROR
  * @{
  */

/*-- MIL_STD_1553_ERROR: MIL_STD_1553 ERROR Register -----*/
/* Bit field positions: */
#define MIL_STD_1553_ERROR_NORCV_Pos           0
#define MIL_STD_1553_ERROR_MANERR_Pos          1
#define MIL_STD_1553_ERROR_SYNCERR_Pos         2
#define MIL_STD_1553_ERROR_SEQERR_Pos          3
#define MIL_STD_1553_ERROR_GAPERR_Pos          4
#define MIL_STD_1553_ERROR_CONERR_Pos          5
#define MIL_STD_1553_ERROR_PROERR_Pos          6

/* Bit field masks: */
#define MIL_STD_1553_ERROR_NORCV                ((uint32_t)0x00000001)
#define MIL_STD_1553_ERROR_MANERR               ((uint32_t)0x00000002)
#define MIL_STD_1553_ERROR_SYNCERR              ((uint32_t)0x00000004)
#define MIL_STD_1553_ERROR_SEQERR               ((uint32_t)0x00000008)
#define MIL_STD_1553_ERROR_GAPERR               ((uint32_t)0x00000010)
#define MIL_STD_1553_ERROR_CONERR               ((uint32_t)0x00000020)
#define MIL_STD_1553_ERROR_PROERR               ((uint32_t)0x00000040)

/** @} */ /* End of group MIL_STD_1553_ERROR */

/** @defgroup __1T_Periph_MIL_STD_1553_ITEEN    MIL STD 1553 ITEEN
  * @{
  */

/*-- MIL_STD_1553_ITEEN: MIL_STD_1553 ITEEN Register -----*/
/* Bit field positions: */
#define MIL_STD_1553_INTEN_IDLEIE_Pos          0
#define MIL_STD_1553_INTEN_RFLAGNIE_Pos        1
#define MIL_STD_1553_INTEN_VALMESSIE_Pos       2
#define MIL_STD_1553_INTEN_ERRIE_Pos           3

/* Bit field masks: */
#define MIL_STD_1553_INTEN_IDLEIE               ((uint32_t)0x00000001)
#define MIL_STD_1553_INTEN_RFLAGNIE             ((uint32_t)0x00000002)
#define MIL_STD_1553_INTEN_VALMESSIE            ((uint32_t)0x00000004)
#define MIL_STD_1553_INTEN_ERRIE                ((uint32_t)0x00000008)

/** @} */ /* End of group MIL_STD_1553_ITEEN */

/** @} */ /* End of group Periph_MIL_STD_1553_Defines */

/** @} */ /* End of group Periph_MIL_STD_1553 */


/** @defgroup __1T___MDR1986VE1T_Periph_POWER POWER
 * @{
 */

/** @defgroup __1T___MDR1986VE1T_Periph_POWER_Data_Structures Data Structures
  * @{
  */

/* MDR_POWER_TypeDef structure */
typedef struct
{
  __IO uint32_t PVDCS;
}MDR_POWER_TypeDef;

/** @} */ /* End of group __MDR1986VE1T_Periph_POWER_Data_Structures */

/** @defgroup __1T___MDR1986VE1T_Periph_POWER_Defines Defines
  * @{
  */

/** @defgroup __1T_Periph_POWER_PVDCS   POWER PVDCS
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

/** @} */ /* End of group __MDR1986VE1T_Periph_POWER_Defines */

/** @} */ /* End of group __MDR1986VE1T_Periph_POWER */

/** @defgroup __1T___MDR1986VE1T_Periph_WWDG WWDG
  * @{
  */

/** @defgroup __1T___MDR1986VE1T_Periph_WWDG_Data_Structures Data Structures
  * @{
  */

/* MDR_WWDG_TypeDef structure */
typedef struct
{
  __IO uint32_t CR;
  __IO uint32_t CFR;
  __IO uint32_t SR;
}MDR_WWDG_TypeDef;

/** @} */ /* End of group __MDR1986VE1T_Periph_WWDG_Data_Structures */

/** @defgroup __1T___MDR1986VE1T_Periph_WWDG_Defines Defines
  * @{
  */

/** @defgroup __1T_Periph_WWDG_CR   WWDG CR
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

/** @defgroup __1T_Periph_WWDG_CFR  WWDG CFR
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

/** @} */ /* End of group __MDR1986VE1T_Periph_WWDG_Defines */

/** @} */ /* End of group __MDR1986VE1T_Periph_WWDG */

/** @defgroup __1T___MDR1986VE1T_Periph_IWDG IWDG
  * @{
  */

/** @defgroup __1T___MDR1986VE1T_Periph_IWDG_Data_Structures Data Structures
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

/** @} */ /* End of group __MDR1986VE1T_Periph_IWDG_Data_Structures */

/** @defgroup __1T___MDR1986VE1T_Periph_IWDG_Defines Defines
  * @{
  */

/** @defgroup __1T_Periph_IWDG_SR IWDG SR
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

/** @} */ /* End of group __MDR1986VE1T_Periph_IWDG_Defines */

/** @} */ /* End of group __MDR1986VE1T_Periph_IWDG */


/** @defgroup __1T___MDR1986VE1T_Periph_TIMER TIMER
  * @{
  */

/** @defgroup __1T_Periph_TIMER_Data_Structures Data Structures
  * @{
  */

/** @defgroup __1T_Periph_TIMER_TypeDef TIMER_TypeDef
  * @{
  */

typedef struct {
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
  __IO uint32_t DMA_REChx[4];
} MDR_TIMER_TypeDef;


/** @} */ /* End of group Periph_TIMER_TypeDef */

/** @} */ /* End of group Periph_TIMER_Data_Structures */

/** @defgroup __1T_Periph_TIMER_Defines Defines
  * @{
  */

/** @defgroup __1T_Periph_TIMER_CNTRL TIMER CNTRL
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

/* EVENT SEL Modes */
#define TIMER_CNTRL_EVENT_SEL_TIM_CLK           0x00
#define TIMER_CNTRL_EVENT_SEL_CNT_ARR_TIM1      0x01
#define TIMER_CNTRL_EVENT_SEL_CNT_ARR_TIM2      0x02
#define TIMER_CNTRL_EVENT_SEL_CNT_ARR_TIM3      0x03
#define TIMER_CNTRL_EVENT_SEL_CH1               0x04
#define TIMER_CNTRL_EVENT_SEL_CH2               0x05
#define TIMER_CNTRL_EVENT_SEL_CH3               0x06
#define TIMER_CNTRL_EVENT_SEL_CH4               0x07
#define TIMER_CNTRL_EVENT_SEL_ETR_POS_EDGE      0x08
#define TIMER_CNTRL_EVENT_SEL_ETR_NEG_EDGE      0x09
#define TIMER_CNTRL_EVENT_SEL_CNT_ARR_TIM4      0x0A

/** @} */ /* End of group TIMER_CNTRL */

/** @defgroup __1T_Periph_TIMER_CH_CNTRL  TIMER CH CNTRL
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

/** @defgroup __1T_Periph_TIMER_CH_CNTRL1 TIMER CH CNTRL1
  * @{
  */

/*-- TIMER_CH_CNTRL1: Timer Channel 1 Control Register ----------------*/
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

/** @} */ /* End of group Periph_TIMER_CH_CNTRL1 */

/** @defgroup __1T_Periph_TIMER_CH_DTG  TIMER CH DTG
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

/** @defgroup __1T_Periph_TIMER_BRKETR_CNTRL  TIMER BRKETR CNTRL
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

/** @defgroup __1T_Periph_TIMER_STATUS  TIMER STATUS
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

/** @defgroup __1T_Periph_TIMER_IE  TIMER IE
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

/** @defgroup __1T_Periph_TIMER_DMA_RE  TIMER DMA RE
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

/** @defgroup __1T_Periph_TIMER_CH_CNTRL2 TIMER CH CNTRL2
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

/** @} */ /* End of group Periph_TIMER_Defines */

/** @} */ /* End of group Periph_TIMER */

/** @defgroup __1T___MDR1986VE1T_Periph_ADC ADC
  * @{
  */

/** @defgroup __1T_Periph_ADC_Data_Structures Data Structures
  * @{
  */

/** @defgroup __1T_Periph_ADC_TypeDef ADC_TypeDef
  * @{
  */

typedef struct {
  __IO uint32_t ADC1_CFG;       // 0x00
  __IO uint32_t ADC2_CFG;       // 0x04
  __IO uint32_t ADC1_H_LEVEL;   // 0x08
  __IO uint32_t RESERVED0;      // 0x0c
  __IO uint32_t ADC1_L_LEVEL;   // 0x10
  __IO uint32_t RESERVED1;      // 0x14
  __IO uint32_t ADC1_RESULT;    // 0x18
  __IO uint32_t RESERVED2;      // 0x1C
  __IO uint32_t ADC1_STATUS;    // 0x20
  __IO uint32_t RESERVED3;      // 0x24
  __IO uint32_t ADC1_CHSEL;     // 0x28
  __IO uint32_t RESERVED4;      // 0x2C
  __IO uint32_t ADC1_TRIM;      // 0x30
} MDR_ADC_TypeDef;

/** @} */ /* End of group Periph_ADC_TypeDef */

/** @} */ /* End of group Periph_ADC_Data_Structures */

/** @defgroup __1T_Periph_ADC_Defines Defines
  * @{
  */

/** @defgroup __1T_Periph_ADC1_CFG  ADC1 CFG
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
#define ADC1_CFG_RESERVED_Pos                   21
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
#define ADC1_CFG_RESERVED_Msk                   ((uint32_t)0x01E00000)
#define ADC1_CFG_DELAY_GO_Msk                   ((uint32_t)0x0E000000)
#define ADC1_CFG_DELAY_ADC_Msk                  ((uint32_t)0xF0000000)

/* CFG REG CHS Modes */
#define ADC1_CFG_REG_CHS_VREF                   30
#define ADC1_CFG_REG_CHS_TS                     31

/* CFG REG DIVCLK Modes*/
#define ADC1_CFG_REG_DIVCLK_HCLK                0x00
#define ADC1_CFG_REG_DIVCLK_HCLK_DIV_2          0x01
#define ADC1_CFG_REG_DIVCLK_HCLK_DIV_4          0x02
#define ADC1_CFG_REG_DIVCLK_HCLK_DIV_8          0x03
#define ADC1_CFG_REG_DIVCLK_HCLK_DIV_16         0x04
#define ADC1_CFG_REG_DIVCLK_HCLK_DIV_32         0x05
#define ADC1_CFG_REG_DIVCLK_HCLK_DIV_64         0x06
#define ADC1_CFG_REG_DIVCLK_HCLK_DIV_128        0x07
#define ADC1_CFG_REG_DIVCLK_HCLK_DIV_256        0x08
#define ADC1_CFG_REG_DIVCLK_HCLK_DIV_512        0x09
#define ADC1_CFG_REG_DIVCLK_HCLK_DIV_1024       0x0A
#define ADC1_CFG_REG_DIVCLK_HCLK_DIV_2048       0x0B
#define ADC1_CFG_REG_DIVCLK_HCLK_DIV_4096       0x0C
#define ADC1_CFG_REG_DIVCLK_HCLK_DIV_8192       0x0D
#define ADC1_CFG_REG_DIVCLK_HCLK_DIV_16384      0x0E
#define ADC1_CFG_REG_DIVCLK_HCLK_DIV_32768      0x0F

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


/** @defgroup __1T_Periph_ADC2_CFG  ADC2 CFG
  * @{
  */

/*-- ADC2_CFG: ADC2 Configuration Register -------------------------*/
/* Bit field positions: */
#define ADC2_CFG_ADC1_OP_Pos                    17

/* Bit field masks: */
#define ADC2_CFG_ADC1_OP                        ((uint32_t)0x00020000)

/** @} */ /* End of group ADC2_CFG */


/** @defgroup __1T_Periph_ADC1_RESULT ADC1 RESULT
  * @{
  */

/*-- ADC1_RESULT: ADC1 Result Register -------------------------*/
#define ADC_RESULT_Pos                          0
#define ADC_RESULT_Msk                          ((uint32_t)0x00000FFF)

#define ADC_RESULT_CHANNEL_Pos                  16
#define ADC_RESULT_CHANNEL_Msk                  ((uint32_t)0x001F0000)

/** @} */ /* End of group ADC1_RESULT */


/** @defgroup __1T_Periph_ADC_STASUS  ADC STASUS
  * @{
  */

/*-- ADC_STASUS: ADC STASUS Register -----*/
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

/** @} */ /* End of group ADC_STASUS */

/** @defgroup __1T_Periph_ADC_TRIM  ADC TRIM
  * @{
  */

/*-- ADC_TRIM: ADC TRIM Register -----*/
/* Bit field positions: */
#define ADC1_TRIM_TS_TRIM_Pos                   1
#define ADC1_TRIM_SEL_VREF_BUF_Pos              6

/* Bit field masks: */
#define ADC1_TRIM_TS_TRIM_Msk                   ((uint32_t)0x0000003E)
#define ADC1_TRIM_SEL_VREF_BUF                  ((uint32_t)0x00000040)

/** @} */ /* End of group ADC_TRIM */

/** @} */ /* End of group Periph_ADC_Defines */

/** @} */ /* End of group Periph_ADC */

/** @defgroup __1T___MDR1986VE1T_Periph_DAC DAC
  * @{
  */

/** @defgroup __1T_Periph_DAC_Data_Structures Data Structures
  * @{
  */

/** @defgroup __1T_Periph_DAC_TypeDef DAC_TypeDef
  * @{
  */

typedef struct {
  __IO uint32_t CFG;
  __IO uint32_t DAC1_DATA;
  __IO uint32_t DAC2_DATA;
} MDR_DAC_TypeDef;

/** @} */ /* End of group Periph_DAC_TypeDef */

/** @} */ /* End of group Periph_DAC_Data_Structures */

/** @defgroup __1T_Periph_DAC_Defines Defines
  * @{
  */

/** @defgroup __1T_Periph_DAC_CFG DAC CFG
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


/** @} */ /* End of group Periph_DAC_Defines */

/** @defgroup __1T_Periph_DAC_Defines Defines
  * @{
  */

/** @defgroup __1T_Periph_DAC1_DATA DAC1 DATA
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



/** @} */ /* End of group Periph_DAC_Defines */

/** @defgroup __1T_Periph_DAC_Defines Defines
  * @{
  */

/** @defgroup __1T_Periph_DAC2_DATA DAC2 DATA
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



/** @} */ /* End of group Periph_DAC_Defines */

/** @} */ /* End of group Periph_DAC */

/** @defgroup __1T___MDR1986VE1T_Periph_PORT PORT
  * @{
  */

/** @defgroup __1T_Periph_PORT_Data_Structures Data Structures
  * @{
  */

/** @defgroup __1T_Periph_PORT_TypeDef PORT_TypeDef
  * @{
  */

typedef struct {
  __IO uint32_t RXTX;
  __IO uint32_t OE;
  __IO uint32_t FUNC;
  __IO uint32_t ANALOG;
  __IO uint32_t PULL;
  __IO uint32_t PD;
  __IO uint32_t PWR;
  __IO uint32_t GFEN;
  __IO uint32_t SETTX;
  __IO uint32_t CLRTX;
  __IO uint32_t RDTX;
} MDR_PORT_TypeDef;


/** @} */ /* End of group Periph_PORT_TypeDef */

/** @} */ /* End of group Periph_PORT_Data_Structures */

/** @defgroup __1T_Periph_PORT_Defines Defines
  * @{
  */

/** @defgroup __1T_Periph_PORT_FUNC PORT FUNC
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

/** @defgroup __1T_Periph_PORT_PULL PORT PULL
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

/** @defgroup __1T_Periph_PORT_PD PORT PD
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

/** @defgroup __1T_Periph_PORT_PWR  PORT PWR
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

/** @} */ /* End of group Periph_PORT_Defines */

/** @} */ /* End of group Periph_PORT */

/** @defgroup __1T___MDR1986VE1T_Periph_ARINC429R ARINC429R
  * @{
  */

/** @defgroup __1T___MDR1986VE1T_Periph_ARINC429R_Data_Structures Data Structures
  * @{
  */

/* MDR_ARINC429R_TypeDef structure */
typedef struct
{
  __IO uint32_t CONTROL1;
  __IO uint32_t CONTROL2;
  __IO uint32_t CONTROL3;
  __IO uint32_t STATUS1;
  __IO uint32_t STATUS2;
  __IO uint32_t CONTROL4;
  __IO uint32_t CONTROL5;
  __IO uint32_t CHANNEL;
  __IO uint32_t LABEL;
  __IO uint32_t DATA_R;
     uint32_t RESERVED1[2];
  __IO uint32_t DATA_R_Direct[8];
     uint32_t RESERVED2[6];
  __IO uint32_t INTMASK;
     uint32_t RESERVED3;
  __IO uint32_t CONTROL8;
  __IO uint32_t CONTROL9;
}MDR_ARINC429R_TypeDef;

/** @} */ /* End of group Periph_ARINC429R_Data_Structures */

/** @defgroup __1T___MDR1986VE1T_Periph_ARINC429R_Defines Defines
  * @{
  */

/** @defgroup __1T_Periph_ARINC429R_CONTROL1  ARINC429R CONTROL1
  * @{
  */

/*-- ARINC429R_CONTROL1: ARINC429R CONTROL1 Register -----*/
/* Bit field positions: */
#define ARINC429R_CONTROL1_CH_EN1_Pos          0
#define ARINC429R_CONTROL1_CH_EN2_Pos          1
#define ARINC429R_CONTROL1_CH_EN3_Pos          2
#define ARINC429R_CONTROL1_CH_EN4_Pos          3
#define ARINC429R_CONTROL1_CH_EN5_Pos          4
#define ARINC429R_CONTROL1_CH_EN6_Pos          5
#define ARINC429R_CONTROL1_CH_EN7_Pos          6
#define ARINC429R_CONTROL1_CH_EN8_Pos          7
#define ARINC429R_CONTROL1_CLK1_Pos            14
#define ARINC429R_CONTROL1_CLK2_Pos            15
#define ARINC429R_CONTROL1_CLK3_Pos            16
#define ARINC429R_CONTROL1_CLK4_Pos            17
#define ARINC429R_CONTROL1_CLK5_Pos            18
#define ARINC429R_CONTROL1_CLK6_Pos            19
#define ARINC429R_CONTROL1_CLK7_Pos            20
#define ARINC429R_CONTROL1_CLK8_Pos            21
#define ARINC429R_CONTROL1_DIV_Pos             28

/* Bit field masks: */
#define ARINC429R_CONTROL1_CH_EN1               ((uint32_t)0x00000001)
#define ARINC429R_CONTROL1_CH_EN2               ((uint32_t)0x00000002)
#define ARINC429R_CONTROL1_CH_EN3               ((uint32_t)0x00000004)
#define ARINC429R_CONTROL1_CH_EN4               ((uint32_t)0x00000008)
#define ARINC429R_CONTROL1_CH_EN5               ((uint32_t)0x00000010)
#define ARINC429R_CONTROL1_CH_EN6               ((uint32_t)0x00000020)
#define ARINC429R_CONTROL1_CH_EN7               ((uint32_t)0x00000040)
#define ARINC429R_CONTROL1_CH_EN8               ((uint32_t)0x00000080)
#define ARINC429R_CONTROL1_CLK1                 ((uint32_t)0x00004000)
#define ARINC429R_CONTROL1_CLK2                 ((uint32_t)0x00008000)
#define ARINC429R_CONTROL1_CLK3                 ((uint32_t)0x00010000)
#define ARINC429R_CONTROL1_CLK4                 ((uint32_t)0x00020000)
#define ARINC429R_CONTROL1_CLK5                 ((uint32_t)0x00040000)
#define ARINC429R_CONTROL1_CLK6                 ((uint32_t)0x00080000)
#define ARINC429R_CONTROL1_CLK7                 ((uint32_t)0x00100000)
#define ARINC429R_CONTROL1_DIV_Msk              ((uint32_t)0xF0000000)

/** @} */ /* End of group ARINC429R_CONTROL1 */

/** @defgroup __1T_Periph_ARICN429R_CONTROL2  ARICN429R CONTROL2
  * @{
  */

/*-- ARICN429R_CONTROL2: ARICN429R CONTROL2 Register -----*/
/* Bit field positions: */
#define ARINC429R_CONTROL2_DIV_6_4_Pos         0
#define ARINC429R_CONTROL2_LB_EN1_Pos          3
#define ARINC429R_CONTROL2_LB_EN2_Pos          4
#define ARINC429R_CONTROL2_LB_EN3_Pos          5
#define ARINC429R_CONTROL2_LB_EN4_Pos          6
#define ARINC429R_CONTROL2_LB_EN5_Pos          7
#define ARINC429R_CONTROL2_LB_EN6_Pos          8
#define ARINC429R_CONTROL2_LB_EN7_Pos          9
#define ARINC429R_CONTROL2_LB_EN8_Pos          10
#define ARINC429R_CONTROL2_SD_EN1_Pos          17
#define ARINC429R_CONTROL2_SD_EN2_Pos          18
#define ARINC429R_CONTROL2_SD_EN3_Pos          19
#define ARINC429R_CONTROL2_SD_EN4_Pos          20
#define ARINC429R_CONTROL2_SD_EN5_Pos          21
#define ARINC429R_CONTROL2_SD_EN6_Pos          22
#define ARINC429R_CONTROL2_SD_EN7_Pos          23
#define ARINC429R_CONTROL2_SD_EN8_Pos          24
#define ARINC429R_CONTROL2_DA_Pos              31

/* Bit field masks: */
#define ARINC429R_CONTROL2_DIV_6_4_Msk          ((uint32_t)0x00000007)
#define ARINC429R_CONTROL2_LB_EN1               ((uint32_t)0x00000008)
#define ARINC429R_CONTROL2_LB_EN2               ((uint32_t)0x00000010)
#define ARINC429R_CONTROL2_LB_EN3               ((uint32_t)0x00000020)
#define ARINC429R_CONTROL2_LB_EN4               ((uint32_t)0x00000040)
#define ARINC429R_CONTROL2_LB_EN5               ((uint32_t)0x00000080)
#define ARINC429R_CONTROL2_LB_EN6               ((uint32_t)0x00000100)
#define ARINC429R_CONTROL2_LB_EN7               ((uint32_t)0x00000200)
#define ARINC429R_CONTROL2_LB_EN8               ((uint32_t)0x00000400)
#define ARINC429R_CONTROL2_SD_EN1               ((uint32_t)0x00020000)
#define ARINC429R_CONTROL2_SD_EN2               ((uint32_t)0x00040000)
#define ARINC429R_CONTROL2_SD_EN3               ((uint32_t)0x00080000)
#define ARINC429R_CONTROL2_SD_EN4               ((uint32_t)0x00100000)
#define ARINC429R_CONTROL2_SD_EN5               ((uint32_t)0x00200000)
#define ARINC429R_CONTROL2_SD_EN6               ((uint32_t)0x00400000)
#define ARINC429R_CONTROL2_SD_EN7               ((uint32_t)0x00800000)
#define ARINC429R_CONTROL2_SD_EN8               ((uint32_t)0x01000000)
#define ARINC429R_CONTROL2_DA                   ((uint32_t)0x80000000)

/** @} */ /* End of group ARICN429R_CONTROL2 */

/** @defgroup __1T_Periph_ARINC429R_CONTROL3  ARINC429R CONTROL3
  * @{
  */

/*-- ARINC429R_CONTROL3: ARINC429R CONTROL3 Register -----*/
/* Bit field positions: */
#define ARINC429R_CONTROL3_SDI1_1_Pos          0
#define ARINC429R_CONTROL3_SDI1_2_Pos          1
#define ARINC429R_CONTROL3_SDI1_3_Pos          2
#define ARINC429R_CONTROL3_SDI1_4_Pos          3
#define ARINC429R_CONTROL3_SDI1_5_Pos          4
#define ARINC429R_CONTROL3_SDI1_6_Pos          5
#define ARINC429R_CONTROL3_SDI1_7_Pos          6
#define ARINC429R_CONTROL3_SDI1_8_Pos          7
#define ARINC429R_CONTROL3_SDI2_1_Pos          14
#define ARINC429R_CONTROL3_SDI2_2_Pos          15
#define ARINC429R_CONTROL3_SDI2_3_Pos          16
#define ARINC429R_CONTROL3_SDI2_4_Pos          17
#define ARINC429R_CONTROL3_SDI2_5_Pos          18
#define ARINC429R_CONTROL3_SDI2_6_Pos          19
#define ARINC429R_CONTROL3_SDI2_7_Pos          20
#define ARINC429R_CONTROL3_SDI2_8_Pos          21
#define ARINC429R_CONTROL3_INTEDR_Pos          28
#define ARINC429R_CONTROL3_INTEER_Pos          29
#define ARINC429R_CONTROL3_INTEFF_Pos          30
#define ARINC429R_CONTROL3_INTEHF_Pos          31

/* Bit field masks: */
#define ARINC429R_CONTROL3_SDI1_1               ((uint32_t)0x00000001)
#define ARINC429R_CONTROL3_SDI1_2               ((uint32_t)0x00000002)
#define ARINC429R_CONTROL3_SDI1_3               ((uint32_t)0x00000004)
#define ARINC429R_CONTROL3_SDI1_4               ((uint32_t)0x00000008)
#define ARINC429R_CONTROL3_SDI1_5               ((uint32_t)0x00000010)
#define ARINC429R_CONTROL3_SDI1_6               ((uint32_t)0x00000020)
#define ARINC429R_CONTROL3_SDI1_7               ((uint32_t)0x00000040)
#define ARINC429R_CONTROL3_SDI1_8               ((uint32_t)0x00000080)
#define ARINC429R_CONTROL3_SDI2_1               ((uint32_t)0x00004000)
#define ARINC429R_CONTROL3_SDI2_2               ((uint32_t)0x00008000)
#define ARINC429R_CONTROL3_SDI2_3               ((uint32_t)0x00010000)
#define ARINC429R_CONTROL3_SDI2_4               ((uint32_t)0x00020000)
#define ARINC429R_CONTROL3_SDI2_5               ((uint32_t)0x00040000)
#define ARINC429R_CONTROL3_SDI2_6               ((uint32_t)0x00080000)
#define ARINC429R_CONTROL3_SDI2_7               ((uint32_t)0x00100000)
#define ARINC429R_CONTROL3_SDI2_8               ((uint32_t)0x00200000)
#define ARINC429R_CONTROL3_INTEDR               ((uint32_t)0x10000000)
#define ARINC429R_CONTROL3_INTEER               ((uint32_t)0x20000000)
#define ARINC429R_CONTROL3_INTEFF               ((uint32_t)0x40000000)
#define ARINC429R_CONTROL3_INTEHF               ((uint32_t)0x80000000)

/** @} */ /* End of group ARINC429R_CONTROL3 */

/** @defgroup __1T_Periph_ARINC429R_CONTROL4  ARINC429R CONTROL4
  * @{
  */

/*-- ARINC429R_CONTROL4: ARINC429R CONTROL4 Register -----*/
/* Bit field positions: */
#define ARINC429R_CONTROL4_DIV_CH1_Pos               0
#define ARINC429R_CONTROL4_DIV_CH2_Pos               8
#define ARINC429R_CONTROL4_DIV_CH3_Pos               16
#define ARINC429R_CONTROL4_DIV_CH4_Pos               24

/* Bit field masks: */
#define ARINC429R_CONTROL4_DIV_CH1_Msk               ((uint32_t)0x000000FF)
#define ARINC429R_CONTROL4_DIV_CH2_Msk               ((uint32_t)0x0000FF00)
#define ARINC429R_CONTROL4_DIV_CH3_Msk               ((uint32_t)0x00FF0000)
#define ARINC429R_CONTROL4_DIV_CH4_Msk               ((uint32_t)0xFF000000)

/** @} */ /* End of group ARINC429R_CONTROL4 */

/** @defgroup __1T_Periph_ARINC492_CONTROL5 ARINC492 CONTROL5
  * @{
  */

/*-- ARINC492R_CONTROL5: ARINC492R CONTROL5 Register -----*/
/* Bit field positions: */
#define ARINC429R_CONTROL5_DIV_CH5_Pos               0
#define ARINC429R_CONTROL5_DIV_CH6_Pos               8
#define ARINC429R_CONTROL5_DIV_CH7_Pos               16
#define ARINC429R_CONTROL5_DIV_CH8_Pos               24

/* Bit field masks: */
#define ARINC429R_CONTROL5_DIV_CH5_Msk               ((uint32_t)0x000000FF)
#define ARINC429R_CONTROL5_DIV_CH6_Msk               ((uint32_t)0x0000FF00)
#define ARINC429R_CONTROL5_DIV_CH7_Msk               ((uint32_t)0x00FF0000)
#define ARINC429R_CONTROL5_DIV_CH8_Msk               ((uint32_t)0xFF000000)

/** @} */ /* End of group ARINC492R_CONTROL5 */

/** @defgroup __1T_Periph_ARINC492R_CONTROL8  ARINC492R CONTROL8
  * @{
  */

/*-- ARINC492R_CONTROL8: ARINC492R CONTROL8 Register -----*/
/* Bit field positions: */
#define ARINC429R_CONTROL8_ENPAR1_Pos               0
#define ARINC429R_CONTROL8_ENPAR2_Pos               1
#define ARINC429R_CONTROL8_ENPAR3_Pos               2
#define ARINC429R_CONTROL8_ENPAR4_Pos               3
#define ARINC429R_CONTROL8_ENPAR5_Pos               4
#define ARINC429R_CONTROL8_ENPAR6_Pos               5
#define ARINC429R_CONTROL8_ENPAR7_Pos               6
#define ARINC429R_CONTROL8_ENPAR8_Pos               7
#define ARINC429R_CONTROL8_ODD1_Pos                 14
#define ARINC429R_CONTROL8_ODD2_Pos                 15
#define ARINC429R_CONTROL8_ODD3_Pos                 16
#define ARINC429R_CONTROL8_ODD4_Pos                 17
#define ARINC429R_CONTROL8_ODD5_Pos                 18
#define ARINC429R_CONTROL8_ODD6_Pos                 19
#define ARINC429R_CONTROL8_ODD7_Pos                 20
#define ARINC429R_CONTROL8_ODD8_Pos                 21
#define ARINC429R_CONTROL8_DA0_Pos                  28
#define ARINC429R_CONTROL8_DA1_Pos                  29

/* Bit field masks: */
#define ARINC429R_CONTROL8_ENPAR1                   ((uint32_t)0x00000001)
#define ARINC429R_CONTROL8_ENPAR2                   ((uint32_t)0x00000002)
#define ARINC429R_CONTROL8_ENPAR3                   ((uint32_t)0x00000004)
#define ARINC429R_CONTROL8_ENPAR4                   ((uint32_t)0x00000008)
#define ARINC429R_CONTROL8_ENPAR5                   ((uint32_t)0x00000010)
#define ARINC429R_CONTROL8_ENPAR6                   ((uint32_t)0x00000020)
#define ARINC429R_CONTROL8_ENPAR7                   ((uint32_t)0x00000040)
#define ARINC429R_CONTROL8_ENPAR8                   ((uint32_t)0x00000080)
#define ARINC429R_CONTROL8_ODD1                     ((uint32_t)0x00004000)
#define ARINC429R_CONTROL8_ODD2                     ((uint32_t)0x00008000)
#define ARINC429R_CONTROL8_ODD3                     ((uint32_t)0x00010000)
#define ARINC429R_CONTROL8_ODD4                     ((uint32_t)0x00020000)
#define ARINC429R_CONTROL8_ODD5                     ((uint32_t)0x00040000)
#define ARINC429R_CONTROL8_ODD6                     ((uint32_t)0x00080000)
#define ARINC429R_CONTROL8_ODD7                     ((uint32_t)0x00100000)
#define ARINC429R_CONTROL8_ODD8                     ((uint32_t)0x00200000)
#define ARINC429R_CONTROL8_DA0                      ((uint32_t)0x10000000)
#define ARINC429R_CONTROL8_DA1                      ((uint32_t)0x20000000)

/** @} */ /* End of group ARINC492R_CONTROL8 */

/** @defgroup __1T_Periph_ARINC492R_CONTROL9  ARINC492R CONTROL9
  * @{
  */

/*-- ARINC492R_CONTROL9: ARINC492R CONTROL9 Register -----*/
/* Bit field positions: */
#define ARINC429R_CONTROL9_ENSYNC1_Pos              0
#define ARINC429R_CONTROL9_ENSYNC2_Pos              1
#define ARINC429R_CONTROL9_ENSYNC3_Pos              2
#define ARINC429R_CONTROL9_ENSYNC4_Pos              3
#define ARINC429R_CONTROL9_ENSYNC5_Pos              4
#define ARINC429R_CONTROL9_ENSYNC6_Pos              5
#define ARINC429R_CONTROL9_ENSYNC7_Pos              6
#define ARINC429R_CONTROL9_ENSYNC8_Pos              7

/* Bit field masks: */
#define ARINC429R_CONTROL9_ENSYNC1                  ((uint32_t)0x00000001)
#define ARINC429R_CONTROL9_ENSYNC2                  ((uint32_t)0x00000002)
#define ARINC429R_CONTROL9_ENSYNC3                  ((uint32_t)0x00000004)
#define ARINC429R_CONTROL9_ENSYNC4                  ((uint32_t)0x00000008)
#define ARINC429R_CONTROL9_ENSYNC5                  ((uint32_t)0x00000010)
#define ARINC429R_CONTROL9_ENSYNC6                  ((uint32_t)0x00000020)
#define ARINC429R_CONTROL9_ENSYNC7                  ((uint32_t)0x00000040)
#define ARINC429R_CONTROL9_ENSYNC8                  ((uint32_t)0x00000080)

/** @} */ /* End of group ARINC492R_CONTROL9 */

/** @defgroup __1T_Periph_ARINC429R_INTMASK ARINC429R INTMASK
  * @{
  */

/*-- ARINC429R_INTMASK: ARINC429R INTMASK register -----*/
/* Bit field positions: */
#define ARINC429R_INTMASK_IEDR1_Pos                 0
#define ARINC429R_INTMASK_IEER1_Pos                 1
#define ARINC429R_INTMASK_IEFF1_Pos                 2
#define ARINC429R_INTMASK_IEHF1_Pos                 3
#define ARINC429R_INTMASK_IEDR2_Pos                 4
#define ARINC429R_INTMASK_IEER2_Pos                 5
#define ARINC429R_INTMASK_IEFF2_Pos                 6
#define ARINC429R_INTMASK_IEHF2_Pos                 7
#define ARINC429R_INTMASK_IEDR3_Pos                 8
#define ARINC429R_INTMASK_IEER3_Pos                 9
#define ARINC429R_INTMASK_IEFF3_Pos                 10
#define ARINC429R_INTMASK_IEHF3_Pos                 11
#define ARINC429R_INTMASK_IEDR4_Pos                 12
#define ARINC429R_INTMASK_IEER4_Pos                 13
#define ARINC429R_INTMASK_IEFF4_Pos                 14
#define ARINC429R_INTMASK_IEHF4_Pos                 15
#define ARINC429R_INTMASK_IEDR5_Pos                 16
#define ARINC429R_INTMASK_IEER5_Pos                 17
#define ARINC429R_INTMASK_IEFF5_Pos                 18
#define ARINC429R_INTMASK_IEHF5_Pos                 19
#define ARINC429R_INTMASK_IEDR6_Pos                 20
#define ARINC429R_INTMASK_IEER6_Pos                 21
#define ARINC429R_INTMASK_IEFF6_Pos                 22
#define ARINC429R_INTMASK_IEHF6_Pos                 23
#define ARINC429R_INTMASK_IEDR7_Pos                 24
#define ARINC429R_INTMASK_IEER7_Pos                 25
#define ARINC429R_INTMASK_IEFF7_Pos                 26
#define ARINC429R_INTMASK_IEHF7_Pos                 27
#define ARINC429R_INTMASK_IEDR8_Pos                 28
#define ARINC429R_INTMASK_IEER8_Pos                 29
#define ARINC429R_INTMASK_IEFF8_Pos                 30
#define ARINC429R_INTMASK_IEHF8_Pos                 31

/* Bit field masks: */
#define ARINC429R_INTMASK_IEDR1                     ((uint32_t)0x00000001)
#define ARINC429R_INTMASK_IEER1                     ((uint32_t)0x00000002)
#define ARINC429R_INTMASK_IEFF1                     ((uint32_t)0x00000004)
#define ARINC429R_INTMASK_IEHF1                     ((uint32_t)0x00000008)
#define ARINC429R_INTMASK_IEDR2                     ((uint32_t)0x00000010)
#define ARINC429R_INTMASK_IEER2                     ((uint32_t)0x00000020)
#define ARINC429R_INTMASK_IEFF2                     ((uint32_t)0x00000040)
#define ARINC429R_INTMASK_IEHF2                     ((uint32_t)0x00000080)
#define ARINC429R_INTMASK_IEDR3                     ((uint32_t)0x00000100)
#define ARINC429R_INTMASK_IEER3                     ((uint32_t)0x00000200)
#define ARINC429R_INTMASK_IEFF3                     ((uint32_t)0x00000400)
#define ARINC429R_INTMASK_IEHF3                     ((uint32_t)0x00000800)
#define ARINC429R_INTMASK_IEDR4                     ((uint32_t)0x00001000)
#define ARINC429R_INTMASK_IEER4                     ((uint32_t)0x00002000)
#define ARINC429R_INTMASK_IEFF4                     ((uint32_t)0x00004000)
#define ARINC429R_INTMASK_IEHF4                     ((uint32_t)0x00008000)
#define ARINC429R_INTMASK_IEDR5                     ((uint32_t)0x00010000)
#define ARINC429R_INTMASK_IEER5                     ((uint32_t)0x00020000)
#define ARINC429R_INTMASK_IEFF5                     ((uint32_t)0x00040000)
#define ARINC429R_INTMASK_IEHF5                     ((uint32_t)0x00080000)
#define ARINC429R_INTMASK_IEDR6                     ((uint32_t)0x00100000)
#define ARINC429R_INTMASK_IEER6                     ((uint32_t)0x00200000)
#define ARINC429R_INTMASK_IEFF6                     ((uint32_t)0x00400000)
#define ARINC429R_INTMASK_IEHF6                     ((uint32_t)0x00800000)
#define ARINC429R_INTMASK_IEDR7                     ((uint32_t)0x01000000)
#define ARINC429R_INTMASK_IEER7                     ((uint32_t)0x02000000)
#define ARINC429R_INTMASK_IEFF7                     ((uint32_t)0x04000000)
#define ARINC429R_INTMASK_IEHF7                     ((uint32_t)0x08000000)
#define ARINC429R_INTMASK_IEDR8                     ((uint32_t)0x10000000)
#define ARINC429R_INTMASK_IEER8                     ((uint32_t)0x20000000)
#define ARINC429R_INTMASK_IEFF8                     ((uint32_t)0x40000000)
#define ARINC429R_INTMASK_IEHF8                     ((uint32_t)0x80000000)

/** @} */ /* End of group ARINC429R_INTMASK */

/** @defgroup __1T_Periph_ARINC429R_STATUS1 ARINC429R STATUS1
  * @{
  */

/*-- ARINC429R_STATUS1: ARINC429R STATUS1 Register -----*/
/* Bit field positions: */
#define ARINC429R_STATUS1_DR1_Pos              0
#define ARINC429R_STATUS1_DR2_Pos              1
#define ARINC429R_STATUS1_DR3_Pos              2
#define ARINC429R_STATUS1_DR4_Pos              3
#define ARINC429R_STATUS1_DR5_Pos              4
#define ARINC429R_STATUS1_DR6_Pos              5
#define ARINC429R_STATUS1_DR7_Pos              6
#define ARINC429R_STATUS1_DR8_Pos              7
#define ARINC429R_STATUS1_ERR1_Pos             14
#define ARINC429R_STATUS1_ERR2_Pos             15
#define ARINC429R_STATUS1_ERR3_Pos             16
#define ARINC429R_STATUS1_ERR4_Pos             17
#define ARINC429R_STATUS1_ERR5_Pos             18
#define ARINC429R_STATUS1_ERR6_Pos             19
#define ARINC429R_STATUS1_ERR7_Pos             20
#define ARINC429R_STATUS1_ERR8_Pos             21

/* Bit field masks: */
#define ARINC429R_STATUS1_DR1                   ((uint32_t)0x00000001)
#define ARINC429R_STATUS1_DR2                   ((uint32_t)0x00000002)
#define ARINC429R_STATUS1_DR3                   ((uint32_t)0x00000004)
#define ARINC429R_STATUS1_DR4                   ((uint32_t)0x00000008)
#define ARINC429R_STATUS1_DR5                   ((uint32_t)0x00000010)
#define ARINC429R_STATUS1_DR6                   ((uint32_t)0x00000020)
#define ARINC429R_STATUS1_DR7                   ((uint32_t)0x00000040)
#define ARINC429R_STATUS1_DR8                   ((uint32_t)0x00000080)
#define ARINC429R_STATUS1_ERR1                  ((uint32_t)0x00004000)
#define ARINC429R_STATUS1_ERR2                  ((uint32_t)0x00008000)
#define ARINC429R_STATUS1_ERR3                  ((uint32_t)0x00010000)
#define ARINC429R_STATUS1_ERR4                  ((uint32_t)0x00020000)
#define ARINC429R_STATUS1_ERR5                  ((uint32_t)0x00040000)
#define ARINC429R_STATUS1_ERR6                  ((uint32_t)0x00080000)
#define ARINC429R_STATUS1_ERR7                  ((uint32_t)0x00100000)
#define ARINC429R_STATUS1_ERR8                  ((uint32_t)0x00200000)

/** @} */ /* End of group ARINC429R_STATUS1 */

/** @defgroup __1T_Periph_ARINC429R_STATUS2 ARINC429R STATUS2
  * @{
  */

/*-- ARINC429R_STATUS2: ARINC429R STATUS2 Register -----*/
/* Bit field positions: */
#define ARINC429R_STATUS2_FF1_Pos              0
#define ARINC429R_STATUS2_FF2_Pos              1
#define ARINC429R_STATUS2_FF3_Pos              2
#define ARINC429R_STATUS2_FF4_Pos              3
#define ARINC429R_STATUS2_FF5_Pos              4
#define ARINC429R_STATUS2_FF6_Pos              5
#define ARINC429R_STATUS2_FF7_Pos              6
#define ARINC429R_STATUS2_FF8_Pos              7
#define ARINC429R_STATUS2_HF1_Pos              14
#define ARINC429R_STATUS2_HF2_Pos              15
#define ARINC429R_STATUS2_HF3_Pos              16
#define ARINC429R_STATUS2_HF4_Pos              17
#define ARINC429R_STATUS2_HF5_Pos              18
#define ARINC429R_STATUS2_HF6_Pos              19
#define ARINC429R_STATUS2_HF7_Pos              20
#define ARINC429R_STATUS2_HF8_Pos              21

/* Bit field masks: */
#define ARINC429R_STATUS2_FF1                   ((uint32_t)0x00000001)
#define ARINC429R_STATUS2_FF2                   ((uint32_t)0x00000002)
#define ARINC429R_STATUS2_FF3                   ((uint32_t)0x00000004)
#define ARINC429R_STATUS2_FF4                   ((uint32_t)0x00000008)
#define ARINC429R_STATUS2_FF5                   ((uint32_t)0x00000010)
#define ARINC429R_STATUS2_FF6                   ((uint32_t)0x00000020)
#define ARINC429R_STATUS2_FF7                   ((uint32_t)0x00000040)
#define ARINC429R_STATUS2_FF8                   ((uint32_t)0x00000080)
#define ARINC429R_STATUS2_HF1                   ((uint32_t)0x00004000)
#define ARINC429R_STATUS2_HF2                   ((uint32_t)0x00008000)
#define ARINC429R_STATUS2_HF3                   ((uint32_t)0x00010000)
#define ARINC429R_STATUS2_HF4                   ((uint32_t)0x00020000)
#define ARINC429R_STATUS2_HF5                   ((uint32_t)0x00040000)
#define ARINC429R_STATUS2_HF6                   ((uint32_t)0x00080000)
#define ARINC429R_STATUS2_HF7                   ((uint32_t)0x00100000)
#define ARINC429R_STATUS2_HF8                   ((uint32_t)0x00200000)

/** @} */ /* End of group ARINC429R_STATUS2 */

/** @} */ /* End of group __MDR1986VE1T_Periph_ARINC429R_Defines */

/** @} */ /* End of group __MDR1986VE1T_Periph_ARINC429R */

/** @defgroup __1T___MDR1986VE1T_Periph_ARINC429T ARINC429T
  * @{
  */

/** @defgroup __1T___MDR1986VE1T_Periph_ARINC429T_Data_Structures Data Structures
  * @{
  */

/* MDR_ARINC429T_TypeDef structure */
typedef struct
{
  __IO uint32_t CONTROL1;
  __IO uint32_t CONTROL2;
  __IO uint32_t STATUS;
  __IO uint32_t DATA1_T;
  __IO uint32_t DATA2_T;
  __IO uint32_t DATA3_T;
  __IO uint32_t DATA4_T;
  __IO uint32_t CONTROL3;
  __IO uint32_t CONTROL4;
}MDR_ARINC429T_TypeDef;

/** @} */ /* End of group Periph_ARINC429T_Data_Structures */

/** @defgroup __1T___MDR1986VE1T_Periph_ARINC429T_Defines Defines
  * @{
  */

/** @defgroup __1T_Periph_ARINC429T_CONTROL1  ARINC429T CONTROL1
  * @{
  */

/*-- ARINC429T_CONTROL1: ARINC429T CONTROL1 Register -----*/
/* Bit field positions: */
#define ARINC429T_CONTROL1_CH_EN1_Pos          0
#define ARINC429T_CONTROL1_CLK1_Pos            1
#define ARINC429T_CONTROL1_EN_PAR1_Pos         2
#define ARINC429T_CONTROL1_ODD1_Pos            3
#define ARINC429T_CONTROL1_CH_EN2_Pos          4
#define ARINC429T_CONTROL1_CLK2_Pos            5
#define ARINC429T_CONTROL1_EN_PAR2_Pos         6
#define ARINC429T_CONTROL1_ODD2_Pos            7
#define ARINC429T_CONTROL1_DIV_Pos             8
#define ARINC429T_CONTROL1_INTE_FFT1_Pos       15
#define ARINC429T_CONTROL1_INTE_TXR1_Pos       16
#define ARINC429T_CONTROL1_INTE_HFT1_Pos       17
#define ARINC429T_CONTROL1_INTE_FFT2_Pos       18
#define ARINC429T_CONTROL1_INTE_TXR2_Pos       19
#define ARINC429T_CONTROL1_INTE_HFT2_Pos       20

/* Bit field masks: */
#define ARINC429T_CONTROL1_CH_EN1               ((uint32_t)0x00000001)
#define ARINC429T_CONTROL1_CLK1                 ((uint32_t)0x00000002)
#define ARINC429T_CONTROL1_EN_PAR1              ((uint32_t)0x00000004)
#define ARINC429T_CONTROL1_ODD1                 ((uint32_t)0x00000008)
#define ARINC429T_CONTROL1_CH_EN2               ((uint32_t)0x00000010)
#define ARINC429T_CONTROL1_CLK2                 ((uint32_t)0x00000020)
#define ARINC429T_CONTROL1_EN_PAR2              ((uint32_t)0x00000040)
#define ARINC429T_CONTROL1_ODD2                 ((uint32_t)0x00000080)
#define ARINC429T_CONTROL1_DIV_MASK             ((uint32_t)0x00007F00)
#define ARINC429T_CONTROL1_INTE_FFT1            ((uint32_t)0x00008000)
#define ARINC429T_CONTROL1_INTE_TXR1            ((uint32_t)0x00010000)
#define ARINC429T_CONTROL1_INTE_HFT1            ((uint32_t)0x00020000)
#define ARINC429T_CONTROL1_INTE_FFT2            ((uint32_t)0x00040000)
#define ARINC429T_CONTROL1_INTE_TXR2            ((uint32_t)0x00080000)
#define ARINC429T_CONTROL1_INTE_HFT2            ((uint32_t)0x00100000)

/** @} */ /* End of group ARINC429T_CONTROL1 */

/** @defgroup __1T_Periph_ARINC429T_CONTROL2  ARINC429T CONTROL2
  * @{
  */

/*-- ARINC429T_CONTROL2: ARINC429T CONTROL2 Register -----*/
/* Bit field positions: */
#define ARINC429T_CONTROL2_CH_EN3_Pos          0
#define ARINC429T_CONTROL2_CLK3_Pos            1
#define ARINC429T_CONTROL2_EN_PAR3_Pos         2
#define ARINC429T_CONTROL2_ODD3_Pos            3
#define ARINC429T_CONTROL2_CH_EN4_Pos          4
#define ARINC429T_CONTROL2_CLK4_Pos            5
#define ARINC429T_CONTROL2_EN_PAR4_Pos         6
#define ARINC429T_CONTROL2_ODD4_Pos            7
#define ARINC429T_CONTROL2_INTE_FFT3_Pos       15
#define ARINC429T_CONTROL2_INTE_TXR3_Pos       16
#define ARINC429T_CONTROL2_INTE_HFT3_Pos       17
#define ARINC429T_CONTROL2_INTE_FFT4_Pos       18
#define ARINC429T_CONTROL2_INTE_TXR4_Pos       19
#define ARINC429T_CONTROL2_INTE_HFT4_Pos       20

/* Bit field masks: */
#define ARINC429T_CONTROL2_CH_EN3               ((uint32_t)0x00000001)
#define ARINC429T_CONTROL2_CLK3                 ((uint32_t)0x00000002)
#define ARINC429T_CONTROL2_EN_PAR3              ((uint32_t)0x00000004)
#define ARINC429T_CONTROL2_ODD3                 ((uint32_t)0x00000008)
#define ARINC429T_CONTROL2_CH_EN4               ((uint32_t)0x00000010)
#define ARINC429T_CONTROL2_CLK4                 ((uint32_t)0x00000020)
#define ARINC429T_CONTROL2_EN_PAR4              ((uint32_t)0x00000040)
#define ARINC429T_CONTROL2_ODD4                 ((uint32_t)0x00000080)
#define ARINC429T_CONTROL2_INTE_FFT3            ((uint32_t)0x00008000)
#define ARINC429T_CONTROL2_INTE_TXR3            ((uint32_t)0x00010000)
#define ARINC429T_CONTROL2_INTE_HFT3            ((uint32_t)0x00020000)
#define ARINC429T_CONTROL2_INTE_FFT4            ((uint32_t)0x00040000)
#define ARINC429T_CONTROL2_INTE_TXR4            ((uint32_t)0x00080000)
#define ARINC429T_CONTROL2_INTE_HFT4            ((uint32_t)0x00100000)

/** @} */ /* End of group ARINC429T_CONTROL2 */

/** @defgroup __1T_Periph_ARINC429T_CONTROL3  ARINC429T CONTROL3
  * @{
  */

/*-- ARINC429T_CONTROL3: ARINC429T CONTROL3 Register -----*/
/* Bit field positions: */
#define ARINC429T_CONTROL3_DIV_CH1_Pos               0
#define ARINC429T_CONTROL3_DIV_CH2_Pos               8
#define ARINC429T_CONTROL3_DIV_CH3_Pos               16
#define ARINC429T_CONTROL3_DIV_CH4_Pos               24

/* Bit field masks: */
#define ARINC429T_CONTROL3_DIV_CH1_Msk               ((uint32_t)0x000000FF)
#define ARINC429T_CONTROL3_DIV_CH2_Msk               ((uint32_t)0x0000FF00)
#define ARINC429T_CONTROL3_DIV_CH3_Msk               ((uint32_t)0x00FF0000)
#define ARINC429T_CONTROL3_DIV_CH4_Msk               ((uint32_t)0xFF000000)

/** @} */ /* End of group ARINC429T_CONTROL3 */

/** @defgroup __1T_Periph_ARINC429T_CONTROL4  ARINC429T CONTROL4
  * @{
  */

/*-- ARINC429T_CONTROL4: ARINC429T CONTROL4 Register -----*/
/* Bit field positions: */
#define ARINC429T_CONTROL4_ENSYNC1_Pos              0
#define ARINC429T_CONTROL4_ENSYNC2_Pos              1
#define ARINC429T_CONTROL4_ENSYNC3_Pos              2
#define ARINC429T_CONTROL4_ENSYNC4_Pos              3

/* Bit field masks: */
#define ARINC429T_CONTROL4_ENSYNC1                  ((uint32_t)0x00000001)
#define ARINC429T_CONTROL4_ENSYNC2                  ((uint32_t)0x00000002)
#define ARINC429T_CONTROL4_ENSYNC3                  ((uint32_t)0x00000004)
#define ARINC429T_CONTROL4_ENSYNC4                  ((uint32_t)0x00000008)

/** @} */ /* End of group ARINC429T_CONTROL4 */

/** @defgroup __1T_Periph_ARINC429T_STATUS  ARINC429T STATUS
  * @{
  */

/*-- ARINC429T_STATUS: ARINC429T STATUS Register -----*/
/* Bit field positions: */
#define ARINC429T_STATUS_TX_R1_Pos             0
#define ARINC429T_STATUS_FFT1_Pos              1
#define ARINC429T_STATUS_HFT1_Pos              2
#define ARINC429T_STATUS_TX_R2_Pos             3
#define ARINC429T_STATUS_FFT2_Pos              4
#define ARINC429T_STATUS_HFT2_Pos              5
#define ARINC429T_STATUS_TX_R3_Pos             8
#define ARINC429T_STATUS_FFT3_Pos              9
#define ARINC429T_STATUS_HFT3_Pos              10
#define ARINC429T_STATUS_TX_R4_Pos             11
#define ARINC429T_STATUS_FFT4_Pos              12
#define ARINC429T_STATUS_HFT4_Pos              13

/* Bit field masks: */
#define ARINC429T_STATUS_TX_R1                  ((uint32_t)0x00000001)
#define ARINC429T_STATUS_FFT1                   ((uint32_t)0x00000002)
#define ARINC429T_STATUS_HFT1                   ((uint32_t)0x00000004)
#define ARINC429T_STATUS_TX_R2                  ((uint32_t)0x00000008)
#define ARINC429T_STATUS_FFT2                   ((uint32_t)0x00000010)
#define ARINC429T_STATUS_HFT2                   ((uint32_t)0x00000020)
#define ARINC429T_STATUS_TX_R3                  ((uint32_t)0x00000100)
#define ARINC429T_STATUS_FFT3                   ((uint32_t)0x00000200)
#define ARINC429T_STATUS_HFT3                   ((uint32_t)0x00000400)
#define ARINC429T_STATUS_TX_R4                  ((uint32_t)0x00000800)
#define ARINC429T_STATUS_FFT4                   ((uint32_t)0x00001000)
#define ARINC429T_STATUS_HFT4                   ((uint32_t)0x00002000)

/** @} */ /* End of group ARINC429T_STATUS */

/** @} */ /* End of group __MDR1986VE1T_Periph_ARINC429T_Defines */

/** @} */ /* End of group __MDR1986VE1T_Periph_ARINC429T */

/** @defgroup __1T___MDR1986VE1T_Periph_BKP BKP
  * @{
  */

/** @defgroup __1T___MDR1986VE1T_Periph_BKP_Data_Structures Data Structures
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

/** @} */ /* End of group __MDR1986VE1T_Periph_BKP_Data_Structures */

/** @defgroup __1T___MDR1986VE1T_Periph_BKP_Defines Defines
  * @{
  */

/** @defgroup __1T_Periph_BKP_REG_0E  BKP REG 0E
  * @{
  */

/*-- BKP_REG_0E: Backup Register 14 --------------------------------*/
/* Bit field positions: */
#define BKP_REG_0E_LOW_Pos                      0
#define BKP_REG_0E_SELECTRI_Pos                 3
#define BKP_REG_0E_SANDALONE_Pos                6
#define BKP_REG_0E_TRIM_02_Pos                  8
#define BKP_REG_0E_FPOR_Pos                     11
#define BKP_REG_0E_TRIM_34_Pos                  12
#define BKP_REG_0E_ILIMEN_Pos                   15

/* Bit field masks: */
#define BKP_REG_0E_LOW_Msk                      ((uint32_t)0x00000007)
#define BKP_REG_0E_SELECTRI_Msk                 ((uint32_t)0x00000038)
#define BKP_REG_0E_SANDALONE                    ((uint32_t)0x00000040)
#define BKP_REG_0E_TRIM_Msk                     ((uint32_t)0x00003700)
#define BKP_REG_0E_FPOR                         ((uint32_t)0x00000800)
#define BKP_REG_0E_ILIMEN                       ((uint32_t)0x00008000)
#define BKP_REG_0E_BKP_REG_Msk                  ((uint32_t)0xFFFFF000)

/** @} */ /* End of group BKP_REG_0E */

/** @defgroup __1T_Periph_BKP_REG_0F    BKP REG 0F
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

/** @defgroup __1T_Periph_BKP_RTC_CS    BKP RTC CS
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

/** @} */ /* End of group __MDR1986VE1T_Periph_BKP_Defines */

/** @} */ /* End of group __MDR1986VE1T_Periph_BKP */

/** @defgroup __1T___MDR1986VE1T_Periph_EBC EBC
 *  @{
 */

/** @defgroup __1T___MDR1986VE1T_Periph_EBC_Data_structures Data Structures
 *  @{
 */

/* MDR_EBC_TypeDef structure */
typedef struct
{
       uint32_t RESERVED0[20];
  __IO uint32_t NAND_CYCLES;
  __IO uint32_t CONTROL;
  __IO uint32_t MEM_REGION[4];
}MDR_EBC_TypeDef;

/** @} */ /* End of groupe MDR1986VE1T_Periph_EBC_Data_structures Data Structures */

/** @defgroup __1T_MDR1986VE1T_Periph_EBC_Defines Defines
  * @{
  */

/** @defgroup __1T_Periph_EBC_NAND_CYCLES   EBC NAND CYCLES
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


/** @defgroup __1T_Periph_EBC_CONTROL   EBC CONTROL
  * @{
  */

/*-- EBC_CONTROL: EBC Control Register -----------------------------*/
/* Bit field positions: */
#define EBC_CONTROL_ROM_Pos                     0
#define EBC_CONTROL_RAM_Pos                     1
#define EBC_CONTROL_NAND_Pos                    2
#define EBC_CONTROL_CPOL_Pos                    3
#define EBC_CONTROL_LOW8_Pos                    5
#define EBC_CONTROL_LOW16_Pos                   6
#define EBC_CONTROL_BUSY_Pos                    7
#define EBC_CONTROL_WAIT_STATE_Pos              12

/* Bit field masks: */
#define EBC_CONTROL_ROM                         ((uint32_t)0x00000001)
#define EBC_CONTROL_RAM                         ((uint32_t)0x00000002)
#define EBC_CONTROL_NAND                        ((uint32_t)0x00000004)
#define EBC_CONTROL_CPOL                        ((uint32_t)0x00000008)
#define EBC_CONTROL_LOW8                        ((uint32_t)0x00000020)
#define EBC_CONTROL_LOW16                       ((uint32_t)0x00000040)
#define EBC_CONTROL_BUSY                        ((uint32_t)0x00000080)
#define EBC_CONTROL_WAIT_STATE_Msk              ((uint32_t)0x0000F000)

/** @} */ /* End of group EBC_CONTROL */


/** @defgroup __1T_Periph_EBC_RAM_CYCLESx   EBC RAM CYCLESx
  * @{
  */

/*-- EBC_RAM_CYCLESx: Register customization options exchange with RAM -------*/
/* Bit field positions: */
#define EBC_RAM_CYCLES_ENABLE_TUNE_Pos          0
#define EBC_RAM_CYCLES_WS_ACTIVE_Pos            1
#define EBC_RAM_CYCLES_WS_SETUP_Pos             8
#define EBC_RAM_CYCLES_WS_HOLD_Pos              11
#define EBC_RAM_CYCLES_USE_READY_Pos            14

/* Bit field masks: */
#define EBC_RAM_CYCLES_ENABLE_TUNE              ((uint32_t)0x00000001)
#define EBC_RAM_CYCLES_WS_ACTIVE_Msk            ((uint32_t)0x000000FE)
#define EBC_RAM_CYCLES_WS_SETUP_Msk             ((uint32_t)0x00000700)
#define EBC_RAM_CYCLES_WS_HOLD_Msk              ((uint32_t)0x00003800)
#define EBC_RAM_CYCLES_USE_READY                ((uint32_t)0x00004000)

/** @} */ /* End of group EBC_RAM_CYCLESx */

/** @} */ /* End of groupe MDR1986VE1T_Periph_EBC_Defines Defines */

/** @} */ /* End of groupe __MDR1986VE1T_Periph_EBC EBC */

/** @defgroup __1T___MDR1986VE1T_Periph_ETHERNET ETHERNET
  * @{
  */

/** @defgroup __1T___MDR1986VE1T_Periph_Data_Structures Data Structures
  * @{
  */

typedef struct {
  __IO uint16_t ETH_Delimiter;      //0
  __IO uint16_t ETH_MAC_T;          //2
  __IO uint16_t ETH_MAC_M;          //4
  __IO uint16_t ETH_MAC_H;          //6
  __IO uint16_t ETH_HASH0;          //8
  __IO uint16_t ETH_HASH1;          //A
  __IO uint16_t ETH_HASH2;          //C
  __IO uint16_t ETH_HASH3;          //E
  __IO uint16_t ETH_IPG;            //10
  __IO uint16_t ETH_PSC;            //12
  __IO uint16_t ETH_BAG;            //14
  __IO uint16_t ETH_JitterWnd;      //16
  __IO uint16_t ETH_R_CFG;          //18
  __IO uint16_t ETH_X_CFG;          //1A
  __IO uint16_t ETH_G_CFGl;         //1C
  __IO uint16_t ETH_G_CFGh;         //1E
  __IO uint16_t ETH_IMR;            //20
  __IO uint16_t ETH_IFR;            //22
  __IO uint16_t ETH_MDIO_CTRL;      //24
  __IO uint16_t ETH_MDIO_DATA;      //26
  __IO uint16_t ETH_R_Head;         //28
  __IO uint16_t ETH_X_Tail;         //2A
  __IO uint16_t ETH_R_Tail;         //2C
  __IO uint16_t ETH_X_Head;         //2E
  __IO uint16_t ETH_STAT;           //30
  __IO uint16_t Reserved;           //32
  __IO uint16_t PHY_Control;        //34
  __IO uint16_t PHY_Status;         //36
} MDR_ETHERNET_TypeDef;

/** @} */ /* End of group __MDR1986VE1T_Periph_Data_Structures */

/** @defgroup __1T___MDR1986VE1T_Periph_ETHERNET_Defines Defines
  * @{
  */

/** @defgroup __1T_Periph_ETH_G_CFGl    ETH G CFGl
  * @{
  */

/*-- ETH_G_CFGl: ETH G_CFGl Register -----*/
/* Bit field positions: */
#define ETH_G_CFGl_ColWnd_Pos               0
#define ETH_G_CFGl_PAUSE_EN_Pos             8
#define ETH_G_CFGl_DTRM_EN_Pos              9
#define ETH_G_CFGl_HD_EN_Pos                10
#define ETH_G_CFGl_EXT_EN_Pos               11
#define ETH_G_CFGl_BUFF_MODE_Pos            12
#define ETH_G_CFGl_RCLR_EN_Pos              14

/* Bit field masks: */
#define ETH_G_CFGl_ColWnd_Msk               ((uint32_t)0x000000FF)
#define ETH_G_CFGl_PAUSE_EN                 ((uint32_t)0x00000100)
#define ETH_G_CFGl_DTRM_EN                  ((uint32_t)0x00000200)
#define ETH_G_CFGl_HD_EN                    ((uint32_t)0x00000400)
#define ETH_G_CFGl_EXT_EN                   ((uint32_t)0x00000800)
#define ETH_G_CFGl_BUFF_MODE_Msk            ((uint32_t)0x00003000)
#define ETH_G_CFGl_RCLR_EN                  ((uint32_t)0x00004000)

/* BUFF Modes */
#define ETH_G_CFGl_BUFF_MODE_LIN                    0x00
#define ETH_G_CFGl_BUFF_MODE_AUTO                   0x01
#define ETH_G_CFGl_BUFF_MODE_FIFO                   0x02

/** @} */ /* End of group ETH_G_CFGl */

/** @defgroup __1T_Periph_ETH_G_CFGh    ETH G CFGh
  * @{
  */

/*-- ETH_G_CFGh: ETH G_CFGh Register -----*/
/* Bit field positions: */
#define ETH_G_CFGh_XRST_Pos                 0
#define ETH_G_CFGh_RRST_Pos                 1
#define ETH_G_CFGh_DLB_Pos                  2
#define ETH_G_CFGh_DBG_RF_EN_Pos            12
#define ETH_G_CFGh_DBG_XF_EN_Pos            13
#define ETH_G_CFGh_DBG_MODE_Pos             14

/* Bit field masks: */
#define ETH_G_CFGh_XRST                     ((uint32_t)0x00000001)
#define ETH_G_CFGh_RRST                     ((uint32_t)0x00000002)
#define ETH_G_CFGh_DLB                      ((uint32_t)0x00000004)
#define ETH_G_CFGh_DBG_RF_EN                ((uint32_t)0x00001000)
#define ETH_G_CFGh_DBG_XF_EN                ((uint32_t)0x00002000)
#define ETH_G_CFGh_DBG_MODE_Msk             ((uint32_t)0x0000C000)

/** @} */ /* End of group ETH_G_CFGh */

/** @defgroup __1T_Periph_ETH_X_CFG ETH X CFG
  * @{
  */

/*-- ETH_X_CFG: ETH X_CFG Register -----*/
/* Bit field positions: */
#define ETH_X_CFG_RtryCnt_Pos               0
#define ETH_X_CFG_IPG_EN_Pos                4
#define ETH_X_CFG_CRC_EN_Pos                5
#define ETH_X_CFG_PRE_EN_Pos                6
#define ETH_X_CFG_PAD_EN_Pos                7
#define ETH_X_CFG_EVNT_MODE_Pos             8
#define ETH_X_CFG_MSB1st_Pos                12
#define ETH_X_CFG_BE_Pos                    13
#define ETH_X_CFG_EN_Pos                    15

/* Bit field masks: */
#define ETH_X_CFG_RtryCnt_Msk               ((uint32_t)0x0000000F)
#define ETH_X_CFG_IPG_EN                    ((uint32_t)0x00000010)
#define ETH_X_CFG_CRC_EN                    ((uint32_t)0x00000020)
#define ETH_X_CFG_PRE_EN                    ((uint32_t)0x00000040)
#define ETH_X_CFG_PAD_EN                    ((uint32_t)0x00000080)
#define ETH_X_CFG_EVNT_MODE_Msk             ((uint32_t)0x00000700)
#define ETH_X_CFG_MSB1st                    ((uint32_t)0x00001000)
#define ETH_X_CFG_BE                        ((uint32_t)0x00002000)
#define ETH_X_CFG_EN                        ((uint32_t)0x00008000)

/** @} */ /* End of group ETH_X_CFG */

/** @defgroup __1T_Periph_ETH_R_CFG ETH R CFG
  * @{
  */

/*-- ETH_R_CFG: ETH R_CFG Register -----*/
/* Bit field positions: */
#define ETH_R_CFG_MCA_EN_Pos          0
#define ETH_R_CFG_BCA_EN_Pos          1
#define ETH_R_CFG_UCA_EN_Pos          2
#define ETH_R_CFG_AC_EN_Pos           3
#define ETH_R_CFG_EF_EN_Pos           4
#define ETH_R_CFG_CF_EN_Pos           5
#define ETH_R_CFG_LF_EN_Pos           6
#define ETH_R_CFG_SF_EN_Pos           7
#define ETH_R_CFG_EVNT_MODE_Pos       8
#define ETH_R_CFG_MSB1st_Pos          12
#define ETH_R_CFG_BE_Pos              13
#define ETH_R_CFG_EN_Pos              15

/* Bit field masks: */
#define ETH_R_CFG_MCA_EN               ((uint32_t)0x00000001)
#define ETH_R_CFG_BCA_EN               ((uint32_t)0x00000002)
#define ETH_R_CFG_UCA_EN               ((uint32_t)0x00000004)
#define ETH_R_CFG_AC_EN                ((uint32_t)0x00000008)
#define ETH_R_CFG_EF_EN                ((uint32_t)0x00000010)
#define ETH_R_CFG_CF_EN                ((uint32_t)0x00000020)
#define ETH_R_CFG_LF_EN                ((uint32_t)0x00000040)
#define ETH_R_CFG_SF_EN                ((uint32_t)0x00000080)
#define ETH_R_CFG_EVNT_MODE_Msk        ((uint32_t)0x00000700)
#define ETH_R_CFG_MSB1st               ((uint32_t)0x00001000)
#define ETH_R_CFG_BE                   ((uint32_t)0x00002000)
#define ETH_R_CFG_EN                   ((uint32_t)0x00008000)

/** @} */ /* End of group ETH_R_CFG */

/** @defgroup __1T_Periph_ETH_IMR   ETH IMR
  * @{
  */

/*-- ETH_IMR: ETH IMR Register -----*/
/* Bit field positions: */
#define ETH_IMR_RF_OK_Pos             0
#define ETH_IMR_MISSED_F_Pos          1
#define ETH_IMR_OVF_Pos               2
#define ETH_IMR_SMB_ERR_Pos           3
#define ETH_IMR_CRC_ERR_Pos           4
#define ETH_IMR_CF_Pos                5
#define ETH_IMR_LF_Pos                6
#define ETH_IMR_SF_Pos                7
#define ETH_IMR_XF_OK_Pos             8
#define ETH_IMR_XF_ERR_Pos            9
#define ETH_IMR_UNDF_Pos              10
#define ETH_IMR_LC_Pos                11
#define ETH_IMR_CRS_LOST_Pos          12
#define ETH_IMR_MDIO_INT_Pos          14
#define ETH_IMR_MII_RDY_Pos           15

/* Bit field masks: */
#define ETH_IMR_RF_OK                  ((uint32_t)0x00000001)
#define ETH_IMR_MISSED_F               ((uint32_t)0x00000002)
#define ETH_IMR_OVF                    ((uint32_t)0x00000004)
#define ETH_IMR_SMB_ERR                ((uint32_t)0x00000008)
#define ETH_IMR_CRC_ERR                ((uint32_t)0x00000010)
#define ETH_IMR_CF                     ((uint32_t)0x00000020)
#define ETH_IMR_LF                     ((uint32_t)0x00000040)
#define ETH_IMR_SF                     ((uint32_t)0x00000080)
#define ETH_IMR_XF_OK                  ((uint32_t)0x00000100)
#define ETH_IMR_XF_ERR                 ((uint32_t)0x00000200)
#define ETH_IMR_UNDF                   ((uint32_t)0x00000400)
#define ETH_IMR_LC                     ((uint32_t)0x00000800)
#define ETH_IMR_CRS_LOST               ((uint32_t)0x00001000)
#define ETH_IMR_MDIO_INT               ((uint32_t)0x00004000)
#define ETH_IMR_MII_RDY                ((uint32_t)0x00008000)

/** @} */ /* End of group ETH_IMR */

/** @defgroup __1T_Periph_ETH_IFR   ETH IFR
  * @{
  */

/*-- ETH_IFR: ETH IFR Register -----*/
/* Bit field positions: */
#define ETH_IFR_RF_OK_Pos             0
#define ETH_IFR_MISSED_F_Pos          1
#define ETH_IFR_OVF_Pos               2
#define ETH_IFR_SMB_ERR_Pos           3
#define ETH_IFR_CRC_ERR_Pos           4
#define ETH_IFR_CF_Pos                5
#define ETH_IFR_LF_Pos                6
#define ETH_IFR_SF_Pos                7
#define ETH_IFR_XF_OK_Pos             8
#define ETH_IFR_XF_ERR_Pos            9
#define ETH_IFR_UNDF_Pos              10
#define ETH_IFR_LC_Pos                11
#define ETH_IFR_CRS_LOST_Pos          12
#define ETH_IFR_MDIO_INT_Pos          14
#define ETH_IFR_MII_RDY_Pos           15

/* Bit field masks: */
#define ETH_IFR_RF_OK                  ((uint32_t)0x00000001)
#define ETH_IFR_MISSED_F               ((uint32_t)0x00000002)
#define ETH_IFR_OVF                    ((uint32_t)0x00000004)
#define ETH_IFR_SMB_ERR                ((uint32_t)0x00000008)
#define ETH_IFR_CRC_ERR                ((uint32_t)0x00000010)
#define ETH_IFR_CF                     ((uint32_t)0x00000020)
#define ETH_IFR_LF                     ((uint32_t)0x00000040)
#define ETH_IFR_SF                     ((uint32_t)0x00000080)
#define ETH_IFR_XF_OK                  ((uint32_t)0x00000100)
#define ETH_IFR_XF_ERR                 ((uint32_t)0x00000200)
#define ETH_IFR_UNDF                   ((uint32_t)0x00000400)
#define ETH_IFR_LC                     ((uint32_t)0x00000800)
#define ETH_IFR_CRS_LOST               ((uint32_t)0x00001000)
#define ETH_IFR_MDIO_INT               ((uint32_t)0x00004000)
#define ETH_IFR_MII_RDY                ((uint32_t)0x00008000)

/** @} */ /* End of group ETH_IFR */

/** @defgroup __1T_Periph_ETH_STAT  ETH STAT
  * @{
  */

/*-- ETH_STAT: ETH STAT Register -----*/
/* Bit field positions: */
#define ETH_STAT_R_EMPTY_Pos            0
#define ETH_STAT_R_AEMPTY_Pos           1
#define ETH_STAT_R_HALF_Pos             2
#define ETH_STAT_R_AFULL_Pos            3
#define ETH_STAT_R_FULL_Pos             4
#define ETH_STAT_R_COUNT_Pos            5
#define ETH_STAT_X_EMPTY_Pos            8
#define ETH_STAT_X_AEMPTY_Pos           9
#define ETH_STAT_X_HALF_Pos             10
#define ETH_STAT_X_AFULL_Pos            11
#define ETH_STAT_X_FULL_Pos             12

/* Bit field masks: */
#define ETH_STAT_R_EMPTY                ((uint32_t)0x00000001)
#define ETH_STAT_R_AEMPTY               ((uint32_t)0x00000002)
#define ETH_STAT_R_HALF                 ((uint32_t)0x00000004)
#define ETH_STAT_R_AFULL                ((uint32_t)0x00000008)
#define ETH_STAT_R_FULL                 ((uint32_t)0x00000010)
#define ETH_STAT_R_COUNT_Msk            ((uint32_t)0x000000E0)
#define ETH_STAT_X_EMPTY                ((uint32_t)0x00000100)
#define ETH_STAT_X_AEMPTY               ((uint32_t)0x00000200)
#define ETH_STAT_X_HALF                 ((uint32_t)0x00000400)
#define ETH_STAT_X_AFULL                ((uint32_t)0x00000800)
#define ETH_STAT_X_FULL                 ((uint32_t)0x00001000)

/** @} */ /* End of group ETH_STAT */

/** @defgroup __1T_Periph_ETH_MDIO_CTRL ETH MDIO CTRL
  * @{
  */

/*-- ETH_MDIO_CTRL: ETH MDIO_CTRL Register -----*/
/* Bit field positions: */
#define ETH_MDIO_CTRL_RG_A_Pos          0
#define ETH_MDIO_CTRL_DIV_Pos           5
#define ETH_MDIO_CTRL_PHY_A_Pos         8
#define ETH_MDIO_CTRL_OP_Pos            13
#define ETH_MDIO_CTRL_PRE_EN_Pos        14
#define ETH_MDIO_CTRL_RDY_Pos           15

/* Bit field masks: */
#define ETH_MDIO_CTRL_RG_A_Msk          ((uint32_t)0x0000001F)
#define ETH_MDIO_CTRL_DIV_Msk           ((uint32_t)0x000000E0)
#define ETH_MDIO_CTRL_PHY_A_Msk         ((uint32_t)0x00001F00)
#define ETH_MDIO_CTRL_OP                ((uint32_t)0x00002000)
#define ETH_MDIO_CTRL_PRE_EN            ((uint32_t)0x00004000)
#define ETH_MDIO_CTRL_RDY               ((uint32_t)0x00008000)

/** @} */ /* End of group ETH_MDIO_CTRL */

/** @defgroup __1T_Periph_ETH_PHY_CONTROL   ETH PHY CONTROL
  * @{
  */

/*-- ETH_PHY_CONTROL: ETH PHY_CONTROL Register -----*/
/* Bit field positions: */
#define ETH_PHY_CONTROL_nRST_Pos        0
#define ETH_PHY_CONTROL_MODE_Pos        1
#define ETH_PHY_CONTROL_FX_EN_Pos       7
#define ETH_PHY_CONTROL_MDI_Pos         8
#define ETH_PHY_CONTROL_MDIO_SEL_Pos    9
#define ETH_PHY_CONTROL_MDC_Pos         10
#define ETH_PHY_CONTROL_PHYADD_Pos      11

/* Bit field masks: */
#define ETH_PHY_CONTROL_nRST            ((uint32_t)0x00000001)
#define ETH_PHY_CONTROL_MODE_Msk        ((uint32_t)0x0000000E)
#define ETH_PHY_CONTROL_FX_EN           ((uint32_t)0x00000080)
#define ETH_PHY_CONTROL_MDI             ((uint32_t)0x00000100)
#define ETH_PHY_CONTROL_MDIO_SEL        ((uint32_t)0x00000200)
#define ETH_PHY_CONTROL_MDC             ((uint32_t)0x00000400)
#define ETH_PHY_CONTROL_PHYADD_Msk      ((uint32_t)0x0000F800)

/* PHY Modes */
#define ETH_PHY_CONTROL_MODE_10M_HD         0x00
#define ETH_PHY_CONTROL_MODE_10M_FD         0x01
#define ETH_PHY_CONTROL_MODE_100M_HD        0x02
#define ETH_PHY_CONTROL_MODE_100M_FD        0x03
#define ETH_PHY_CONTROL_MODE_100M_HD_AUTO   0x04
#define ETH_PHY_CONTROL_MODE_REPEAT         0x05
#define ETH_PHY_CONTROL_MODE_LOW_POWER      0x06
#define ETH_PHY_CONTROL_MODE_AUTO           0x07

/** @} */ /* End of group ETH_PHY_CONTROL */

/** @defgroup __1T_Periph_ETH_PHY_STATUS  ETH PHY STATUS
  * @{
  */

/*-- ETH_PHY_STATUS: ETH PHY_STATUS Register -----*/
/* Bit field positions: */
#define ETH_PHY_STATUS_LED0_Pos         0
#define ETH_PHY_STATUS_LED1_Pos         1
#define ETH_PHY_STATUS_LED2_Pos         2
#define ETH_PHY_STATUS_LED3_Pos         3
#define ETH_PHY_STATUS_READY_Pos        4
#define ETH_PHY_STATUS_CRS_Pos          5
#define ETH_PHY_STATUS_COL_Pos          6
#define ETH_PHY_STATUS_FX_VALID_Pos     8
#define ETH_PHY_STATUS_MDO_Pos          9
#define ETH_PHY_STATUS_MDINT_Pos        10

/* Bit field masks: */
#define ETH_PHY_STATUS_LED0             ((uint32_t)0x00000001)
#define ETH_PHY_STATUS_LED1             ((uint32_t)0x00000002)
#define ETH_PHY_STATUS_LED2             ((uint32_t)0x00000004)
#define ETH_PHY_STATUS_LED3             ((uint32_t)0x00000008)
#define ETH_PHY_STATUS_READY            ((uint32_t)0x00000010)
#define ETH_PHY_STATUS_CRS              ((uint32_t)0x00000020)
#define ETH_PHY_STATUS_COL_Msk          ((uint32_t)0x000000C0)
#define ETH_PHY_STATUS_FX_VALID         ((uint32_t)0x00000100)
#define ETH_PHY_STATUS_MDO              ((uint32_t)0x00000200)
#define ETH_PHY_STATUS_MDINT            ((uint32_t)0x00000400)

/** @} */ /* End of group ETH_PHY_STATUS */

/* PHY Read Write Timeouts */
#define PHY_READ_TO               ((uint32_t)0x0004FFFF)
#define PHY_WRITE_TO              ((uint32_t)0x0004FFFF)

/* PHY Register address */
#define PHY_BCR       0          /* Basic Control Register */
#define PHY_BSR       1          /* Basic Status Register */
#define PHY_ID1       2
#define PHY_ID2       3
#define PHY_ATU       4
#define PHY_OPP_ATU   5
#define PHY_EATU      6
#define PHY_EMODE     18
#define PHY_IT_FLAGs  29
#define PHY_IT_MASKs  30
#define PHY_ECTR      31

/*-- ETH_PHY_BCR: ETH PHY_BCR Register -----*/
/* Bit field positions: */
#define PHY_BCR_COL_TEST_Pos      7
#define PHY_BCR_DUPLEX_MODE_Pos   8
#define PHY_BCR_RST_AUTO_NEG_Pos  9
#define PHY_BCR_ISOLATE_Pos       10
#define PHY_BCR_POWER_DOWN_Pos    11
#define PHY_BCR_AUTO_NEG_EN_Pos   12
#define PHY_BCR_SPEED_SEL_Pos     13
#define PHY_BCR_LOOPBACK_Pos      14
#define PHY_BCR_RST_Pos           15

/* Bit field masks: */
#define PHY_BCR_COL_TEST          ((uint16_t) 0x0080)
#define PHY_BCR_DUPLEX_MODE       ((uint16_t) 0x0100)
#define PHY_BCR_RST_AUTO_NEG      ((uint16_t) 0x0200)
#define PHY_BCR_ISOLATE           ((uint16_t) 0x0400)
#define PHY_BCR_POWER_DOWN        ((uint16_t) 0x0800)
#define PHY_BCR_AUTO_NEG_EN       ((uint16_t) 0x1000)
#define PHY_BCR_SPEED_SEL         ((uint16_t) 0x2000)
#define PHY_BCR_LOOPBACK          ((uint16_t) 0x4000)
#define PHY_BCR_RST               ((uint16_t) 0x8000)

#define MDR_ETHERNET1_BUF_BASE    (0x38000000)
#define MDR_ETHERNET1_BUF_SIZE    8192

/** @} */ /* End of group __MDR1986VE1T_Periph_ETHERNET Defines */

/** @} */ /* End of group __MDR1986VE1T_Periph_ETHERNET */


//#include "MDR1986VE1T_sys_defs.h"

/** @defgroup __1T___Peripheral_Memory_Map Peripheral Memory Map
  * @{
  */

#define MDR_CAN1_BASE             (0x40000000)  // 0
#define MDR_CAN2_BASE             (0x40008000)  // 1
#define MDR_USB_BASE              (0x40010000)  // 2
#define MDR_EEPROM_BASE           (0x40018000)  // 3
#define MDR_RST_CLK_BASE          (0x40020000)  // 4
#define MDR_DMA_BASE              (0x40028000)  // 5
#define MDR_UART1_BASE            (0x40030000)  // 6
#define MDR_UART2_BASE            (0x40038000)  // 7
#define MDR_SSP1_BASE             (0x40040000)  // 8
#define MDR_MIL_STD_15531_BASE    (0x40048000)  // 9
#define MDR_MIL_STD_15532_BASE    (0x40050000)  // 10
#define MDR_POWER_BASE            (0x40058000)  // 11
#define MDR_WWDG_BASE             (0x40060000)  // 12
#define MDR_IWDG_BASE             (0x40068000)  // 13
#define MDR_TIMER1_BASE           (0x40070000)  // 14
#define MDR_TIMER2_BASE           (0x40078000)  // 15
#define MDR_TIMER3_BASE           (0x40080000)  // 16
#define MDR_ADC_BASE              (0x40088000)  // 17
#define MDR_DAC_BASE              (0x40090000)  // 18
#define MDR_TIMER4_BASE           (0x40098000)  // 19
#define MDR_SSP2_BASE             (0x400A0000)  // 20
#define MDR_PORTA_BASE            (0x400A8000)  // 21
#define MDR_PORTB_BASE            (0x400B0000)  // 22
#define MDR_PORTC_BASE            (0x400B8000)  // 23
#define MDR_PORTD_BASE            (0x400C0000)  // 24
#define MDR_PORTE_BASE            (0x400C8000)  // 25
#define MDR_ARINC429R_BASE        (0x400D0000)  // 26
#define MDR_BKP_BASE              (0x400D8000)  // 27
#define MDR_ARINC429T_BASE        (0x400E0000)  // 28
#define MDR_PORTF_BASE            (0x400E8000)  // 29
#define MDR_EBC_BASE              (0x400F0000)  // 30
#define MDR_SSP3_BASE             (0x400F8000)  // 31
#define MDR_ETHERNET1_BASE        (0x30000000)

/** @} */ /* End of group __Peripheral_Memory_Map */

/** @defgroup __1T___Peripheral_declaration Peripheral declaration
  * @{
  */

#define MDR_CAN1                  ((MDR_CAN_TypeDef           *)MDR_CAN1_BASE         )
#define MDR_CAN2                  ((MDR_CAN_TypeDef           *)MDR_CAN2_BASE         )
#define MDR_USB                   ((MDR_USB_TypeDef           *)MDR_USB_BASE          )
#define MDR_EEPROM                ((MDR_EEPROM_TypeDef        *)MDR_EEPROM_BASE       )
#define MDR_RST_CLK               ((MDR_RST_CLK_TypeDef       *)MDR_RST_CLK_BASE      )
#define MDR_DMA                   ((MDR_DMA_TypeDef           *)MDR_DMA_BASE          )
#define MDR_UART1                 ((MDR_UART_TypeDef          *)MDR_UART1_BASE        )
#define MDR_UART2                 ((MDR_UART_TypeDef          *)MDR_UART2_BASE        )
#define MDR_SSP1                  ((MDR_SSP_TypeDef           *)MDR_SSP1_BASE         )
#define MDR_MIL_STD_15531         ((MDR_MIL_STD_1553_TypeDef  *)MDR_MIL_STD_15531_BASE)
#define MDR_MIL_STD_15532         ((MDR_MIL_STD_1553_TypeDef  *)MDR_MIL_STD_15532_BASE)
#define MDR_POWER                 ((MDR_POWER_TypeDef         *)MDR_POWER_BASE        )
#define MDR_WWDG                  ((MDR_WWDG_TypeDef          *)MDR_WWDG_BASE         )
#define MDR_IWDG                  ((MDR_IWDG_TypeDef          *)MDR_IWDG_BASE         )
#define MDR_TIMER1                ((MDR_TIMER_TypeDef         *)MDR_TIMER1_BASE       )
#define MDR_TIMER2                ((MDR_TIMER_TypeDef         *)MDR_TIMER2_BASE       )
#define MDR_TIMER3                ((MDR_TIMER_TypeDef         *)MDR_TIMER3_BASE       )
#define MDR_ADC                   ((MDR_ADC_TypeDef           *)MDR_ADC_BASE          )
#define MDR_DAC                   ((MDR_DAC_TypeDef           *)MDR_DAC_BASE          )
#define MDR_TIMER4                ((MDR_TIMER_TypeDef         *)MDR_TIMER4_BASE       )
#define MDR_SSP2                  ((MDR_SSP_TypeDef           *)MDR_SSP2_BASE         )
#define MDR_PORTA                 ((MDR_PORT_TypeDef          *)MDR_PORTA_BASE        )
#define MDR_PORTB                 ((MDR_PORT_TypeDef          *)MDR_PORTB_BASE        )
#define MDR_PORTC                 ((MDR_PORT_TypeDef          *)MDR_PORTC_BASE        )
#define MDR_PORTD                 ((MDR_PORT_TypeDef          *)MDR_PORTD_BASE        )
#define MDR_PORTE                 ((MDR_PORT_TypeDef          *)MDR_PORTE_BASE        )
#define MDR_ARINC429R             ((MDR_ARINC429R_TypeDef     *)MDR_ARINC429R_BASE    )
#define MDR_BKP                   ((MDR_BKP_TypeDef           *)MDR_BKP_BASE          )
#define MDR_ARINC429T             ((MDR_ARINC429T_TypeDef     *)MDR_ARINC429T_BASE    )
#define MDR_PORTF                 ((MDR_PORT_TypeDef          *)MDR_PORTF_BASE        )
#define MDR_EBC                   ((MDR_EBC_TypeDef           *)MDR_EBC_BASE          )
#define MDR_SSP3                  ((MDR_SSP_TypeDef           *)MDR_SSP3_BASE         )
#define MDR_ETHERNET1             ((MDR_ETHERNET_TypeDef      *)MDR_ETHERNET1_BASE    )

/** @} */ /* End of group __Peripheral_declaration */

/** @} */ /* End of group MDR1986VE1T_Peripheral */

#define CLR_BIT(a,b) ((a) &= ~(1U << (b)))
#define SET_BIT(a,b) ((a) |= (1U << (b)))
#define INV_BIT(a,b) ((a) ^= (1U << (b)))

#define CHF_BIT(a,b) (((a) & (1U << (b))) == 0)
#define CHT_BIT(a,b) (((a) & (1U << (b))) != 0)

/** @} */ /* End of group MDR1986VE1T */

/** @} */ /* End of group __CMSIS */

#ifdef __cplusplus
}
#endif

#endif /* __MDR1986VE1T_H */

/*
*
* END OF FILE MDR1986VE1T.h */
