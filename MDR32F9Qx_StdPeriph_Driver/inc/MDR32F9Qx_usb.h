/**
  * FILE MDR32F9Qx_usb.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MDR32F9Qx_USB_H
#define __MDR32F9Qx_USB_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_config.h"
#include "MDR32F9Qx_lib.h"

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @addtogroup USB USB
  * @{
  */

/** @defgroup USB_Exported_Types USB Exported Types
  * @{
  */

/**
  * @brief EndPoints enumeration
  */

typedef enum
{
  USB_EP0  = 0,
  USB_EP1  = 1,
  USB_EP2  = 2,
  USB_EP3  = 3,
  Num_USB_EndPoints
}USB_EP_TypeDef;

#define IS_USB_ENDPOINT(ENDPOINT)       ((ENDPOINT) < Num_USB_EndPoints)

/**
  * @brief USB Clock Init Structure definition
  */

typedef struct
{
  uint32_t USB_USBC1_Source;       /*!< Specifies the source for USB_C1, if USB_C2 source is set to USB_C1.
                                        This parameter is one of @ref USB_USBC1_Source values. */
  uint32_t USB_PLLUSBMUL;          /*!< Specifies the source for USB_C1, if USB_C2 source is set to USB_PLL.
                                        This parameter is one of @ref USB_PLLUSB_Source values. */
}USB_Clock_TypeDef;

typedef struct
{
  uint8_t USB_Version;             /*!< USB Version. */
  uint8_t USB_Revision;            /*!< USB Revision. */
}USB_Version_TypeDef;

/** @} */ /* End of group USB_Exported_Types */

/** @defgroup USB_USBC2_Source USB USBC2 Source
  * @{
  */

#define USB_PLL                         ((uint32_t)0x00000004)

/** @} */ /* End of group USB_USBC2_Source */

/** @defgroup USB_USBC1_Source USB USBC1 Source
  * @{
  */

#define USB_C1HSIdiv1                  ((uint32_t)0x00000000)
#define USB_C1HSIdiv2                  ((uint32_t)0x00000001)
#define USB_C1HSEdiv1                  ((uint32_t)0x00000002)
#define USB_C1HSEdiv2                  ((uint32_t)0x00000003)

#define IS_USBC1_CLOCK_BRG(CLOCK)      (((CLOCK) >= 0) && ((CLOCK) <= 3))

/** @} */ /* End of group USB_USBC1_Source */

/** @defgroup USB_PLLUSB_Source USB PLLUSB Source
  * @{
  */

#define USB_PLLUSBMUL1                 ((uint32_t)0x00000000)
#define USB_PLLUSBMUL2                 ((uint32_t)0x00000001)
#define USB_PLLUSBMUL3                 ((uint32_t)0x00000002)
#define USB_PLLUSBMUL4                 ((uint32_t)0x00000003)
#define USB_PLLUSBMUL5                 ((uint32_t)0x00000004)
#define USB_PLLUSBMUL6                 ((uint32_t)0x00000005)
#define USB_PLLUSBMUL7                 ((uint32_t)0x00000006)
#define USB_PLLUSBMUL8                 ((uint32_t)0x00000007)
#define USB_PLLUSBMUL9                 ((uint32_t)0x00000008)
#define USB_PLLUSBMUL10                ((uint32_t)0x00000009)
#define USB_PLLUSBMUL11                ((uint32_t)0x0000000A)
#define USB_PLLUSBMUL12                ((uint32_t)0x0000000B)
#define USB_PLLUSBMUL13                ((uint32_t)0x0000000C)
#define USB_PLLUSBMUL14                ((uint32_t)0x0000000D)
#define USB_PLLUSBMUL15                ((uint32_t)0x0000000E)
#define USB_PLLUSBMUL16                ((uint32_t)0x0000000F)

#define IS_PLLUSBMUL(MUL)              (((MUL) >= 0) && ((MUL) < 16))

#define USB_CLOCK_48MHz                ((uint32_t)48000000)
#define IS_USB_CLOCK(MUL,USBC1)        (((USBC1 == USB_C1HSIdiv1) && (((MUL + 1)* HSI_Value) == USB_CLOCK_48MHz))       || \
                                        ((USBC1 == USB_C1HSIdiv2) && (((MUL + 1)* (HSI_Value / 2)) == USB_CLOCK_48MHz)) || \
                                        ((USBC1 == USB_C1HSEdiv1) && (((MUL + 1)* HSE_Value) == USB_CLOCK_48MHz))       || \
                                        ((USBC1 == USB_C1HSEdiv2) && (((MUL + 1)* (HSE_Value / 2)) == USB_CLOCK_48MHz)))

/** @} */ /* End of group USB_PLLUSB_Source */

/** @defgroup USB_HOST_REGS_Values USB_HOST Register Values
  * @{
  */

/** @defgroup USB_HSCR_Values USB_HSCR Values
  * @{
  */

#define USB_HSCR_HOST_MODE_Host              (uint32_t)(1 << USB_HSCR_HOST_MODE_Pos)
#define USB_HSCR_HOST_MODE_Device            (uint32_t)(1 << (USB_HSCR_HOST_MODE_Pos + 16))

#define USB_HSCR_RESET_CORE_Reset            (uint32_t)(1 << USB_HSCR_RESET_CORE_Pos)
#define USB_HSCR_RESET_CORE_Work             (uint32_t)(1 << (USB_HSCR_RESET_CORE_Pos + 16))

#define USB_HSCR_EN_TX_Set                   (uint32_t)(1 << USB_HSCR_EN_TX_Pos)
#define USB_HSCR_EN_TX_Reset                 (uint32_t)(1 << (USB_HSCR_EN_TX_Pos + 16))

#define USB_HSCR_EN_RX_Set                   (uint32_t)(1 << USB_HSCR_EN_RX_Pos)
#define USB_HSCR_EN_RX_Reset                 (uint32_t)(1 << (USB_HSCR_EN_RX_Pos + 16))

#define USB_HSCR_DP_PULLUP_Set               (uint32_t)(1 << USB_HSCR_DP_PULLUP_Pos)
#define USB_HSCR_DP_PULLUP_Reset             (uint32_t)(1 << (USB_HSCR_DP_PULLUP_Pos + 16))

#define USB_HSCR_DP_PULLDOWN_Set             (uint32_t)(1 << USB_HSCR_DP_PULLDOWN_Pos)
#define USB_HSCR_DP_PULLDOWN_Reset           (uint32_t)(1 << (USB_HSCR_DP_PULLDOWN_Pos + 16))

#define USB_HSCR_DM_PULLUP_Set               (uint32_t)(1 << USB_HSCR_DM_PULLUP_Pos)
#define USB_HSCR_DM_PULLUP_Reset             (uint32_t)(1 << (USB_HSCR_DM_PULLUP_Pos + 16))

#define USB_HSCR_DM_PULLDOWN_Set             (uint32_t)(1 << USB_HSCR_DM_PULLDOWN_Pos)
#define USB_HSCR_DM_PULLDOWN_Reset           (uint32_t)(1 << (USB_HSCR_DM_PULLDOWN_Pos + 16))

#define USB_HSCR_SET_MASK                    (USB_HSCR_HOST_MODE_Host   | \
                                              USB_HSCR_RESET_CORE_Reset | \
                                              USB_HSCR_EN_TX_Set        | \
                                              USB_HSCR_EN_RX_Set        | \
                                              USB_HSCR_DP_PULLUP_Set    | \
                                              USB_HSCR_DP_PULLDOWN_Set  | \
                                              USB_HSCR_DM_PULLUP_Set    | \
                                              USB_HSCR_DM_PULLDOWN_Set)

#define USB_HSCR_RESET_MASK                  (USB_HSCR_SET_MASK << 16)

#define IS_USB_HSCR_VALUE(VALUE)             ((((VALUE) & (~(USB_HSCR_SET_MASK | USB_HSCR_RESET_MASK))) == 0) && \
                                              ((((VALUE) & ((uint32_t)(VALUE)) >> 16)) == 0))
/** @} */ /* End of group USB_HSCR_Values */

/** @defgroup USB_HTXC_Values USB_HTXC Values
  * @{
  */

#define USB_HTXC_TREQ_Set                    (uint32_t)(1 << USB_HTXC_TREQ_Pos)
#define USB_HTXC_TREQ_Reset                  (uint32_t)(1 << (USB_HTXC_TREQ_Pos + 16))

#define USB_HTXC_SOFS_Set                    (uint32_t)(1 << USB_HTXC_SOFS_Pos)
#define USB_HTXC_SOFS_Reset                  (uint32_t)(1 << (USB_HTXC_SOFS_Pos + 16))

#define USB_HTXC_PREEN_Set                   (uint32_t)(1 << USB_HTXC_PREEN_Pos)
#define USB_HTXC_PREEN_Reset                 (uint32_t)(1 << (USB_HTXC_PREEN_Pos + 16))

#define USB_HTXC_ISOEN_Set                   (uint32_t)(1 << USB_HTXC_ISOEN_Pos)
#define USB_HTXC_ISOEN_Reset                 (uint32_t)(1 << (USB_HTXC_ISOEN_Pos + 16))

#define USB_HTXC_SET_MASK                    (USB_HTXC_TREQ_Set  | \
                                              USB_HTXC_SOFS_Set  | \
                                              USB_HTXC_PREEN_Set | \
                                              USB_HTXC_ISOEN_Set)

#define USB_HTXC_RESET_MASK                  (USB_HTXC_SET_MASK << 16)

#define IS_USB_HTXC_VALUE(VALUE)             ((((VALUE) & (~(USB_HTXC_SET_MASK | USB_HTXC_RESET_MASK))) == 0) && \
                                              ((((VALUE) & ((uint32_t)(VALUE)) >> 16)) == 0))

/** @} */ /* End of group USB_HTXC_Values */

/** @defgroup USB_HTXT_Values USB_HTXT Values
  * @{
  */

#define USB_HTXT_TTYPE_Setup                 (uint32_t)(0x00000000)
#define USB_HTXT_TTYPE_In                    (uint32_t)(0x00000001)
#define USB_HTXT_TTYPE_Outdata0              (uint32_t)(0x00000002)
#define USB_HTXT_TTYPE_Outdata1              (uint32_t)(0x00000003)

#define IS_USB_HTXT_VALUE(VALUE)             (((VALUE) == USB_HTXT_TTYPE_Setup)    || \
                                              ((VALUE) == USB_HTXT_TTYPE_In)       || \
                                              ((VALUE) == USB_HTXT_TTYPE_Outdata0) || \
                                              ((VALUE) == USB_HTXT_TTYPE_Outdata1))

/** @} */ /* End of group USB_HTXT_Values */

/** @defgroup USB_HTXLC_Values USB_HTXLC Values
  * @{
  */

#define USB_HTXLC_TXLC_DM_Set                (uint32_t)(1 << USB_HTXLC_Pos)
#define USB_HTXLC_TXLC_DM_Reset              (uint32_t)(1 << (USB_HTXLC_Pos + 16))

#define USB_HTXLC_TXLC_DP_Set                (uint32_t)(1 << (USB_HTXLC_Pos + 1))
#define USB_HTXLC_TXLC_DP_Reset              (uint32_t)(1 << (USB_HTXLC_Pos + 16 + 1))

#define USB_HTXLC_DC_Direct                  (uint32_t)(1 << USB_HTXLC_DC_Pos)
#define USB_HTXLC_DC_Normal                  (uint32_t)(1 << (USB_HTXLC_DC_Pos + 16))

#define USB_HTXLC_FSPL_Full                  (uint32_t)(1 << USB_HTXLC_FSPL_Pos)
#define USB_HTXLC_FSPL_Low                   (uint32_t)(1 << (USB_HTXLC_FSPL_Pos + 16))

#define USB_HTXLC_FSLR_12Mb                  (uint32_t)(1 << USB_HTXLC_FSLR_Pos)
#define USB_HTXLC_FSPL_1_5Mb                 (uint32_t)(1 << (USB_HTXLC_FSLR_Pos + 16))

#define USB_HTXLC_SET_MASK                   (USB_HTXLC_TXLC_DM_Set  | \
                                              USB_HTXLC_TXLC_DP_Set  | \
                                              USB_HTXLC_DC_Direct | \
                                              USB_HTXLC_FSPL_Full | \
                                              USB_HTXLC_FSLR_12Mb)

#define USB_HTXLC_RESET_MASK                 (USB_HTXLC_SET_MASK << 16)

#define IS_USB_HTXLC_VALUE(VALUE)            ((((VALUE) & (~(USB_HTXLC_SET_MASK | USB_HTXLC_RESET_MASK))) == 0) && \
                                              ((((VALUE) & ((uint32_t)(VALUE)) >> 16)) == 0))

/** @} */ /* End of group USB_HTXLC_Values */

/** @defgroup USB_HTXSE_Values USB_HTXSE Values
  * @{
  */

#define USB_HTXSE_SOFEN_Auto                 (uint32_t)(0x00000001)
#define USB_HTXSE_SOFEN_NonAuto              (uint32_t)(0x00000001 << 16)

#define IS_USB_HTXSE_VALUE(VALUE)            ((((VALUE) & (~(USB_HTXSE_SOFEN_Auto | USB_HTXSE_SOFEN_NonAuto))) == 0) && \
                                              ((((VALUE) & ((uint32_t)(VALUE)) >> 16)) == 0))

/** @} */ /* End of group USB_HTXSE_Values */

/** @defgroup USB_HIS_Values USB_HIS Values
  * @{
  */

#define USB_HIS_TDONE_Set                    USB_HIS_TDONE

#define USB_HIS_RESUME_Set                   USB_HIS_RESUME

#define USB_HIS_CONEV_Set                    USB_HIS_CONEV

#define USB_HIS_SOFS_Set                     USB_HIS_SOFS

#define IS_USB_HIS_VALUE(VALUE)              (((VALUE) == USB_HIS_TDONE_Set)  || \
                                              ((VALUE) == USB_HIS_RESUME_Set) || \
                                              ((VALUE) == USB_HIS_CONEV_Set)  || \
                                              ((VALUE) == USB_HIS_SOFS_Set))

/** @} */ /* End of group USB_HIS_Values */

/** @defgroup USB_HIM_Values USB_HIM Values
  * @{
  */

#define USB_HIM_TDONEIE_Set                  (uint32_t)(1 << USB_HIM_TDONEIE_Pos)
#define USB_HIM_TDONEIE_Reset                (uint32_t)(1 << (USB_HIM_TDONEIE_Pos + 16))

#define USB_HIM_RESUMEIE_Set                 (uint32_t)(1 << USB_HIM_RESUMEIE_Pos)
#define USB_HIM_RESUMEIE_Reset               (uint32_t)(1 << (USB_HIM_RESUMEIE_Pos + 16))

#define USB_HIM_CONEVIE_Set                  (uint32_t)(1 << USB_HIM_CONEVIE_Pos)
#define USB_HIM_CONEVIE_Reset                (uint32_t)(1 << (USB_HIM_CONEVIE_Pos + 16))

#define USB_HIM_SOFIE_Set                    (uint32_t)(1 << USB_HIM_SOFIE_Pos)
#define USB_HIM_SOFIE_Reset                  (uint32_t)(1 << (USB_HIM_SOFIE_Pos + 16))

#define USB_HIM_SET_MASK                     (USB_HIM_TDONEIE_Set  | \
                                              USB_HIM_RESUMEIE_Set | \
                                              USB_HIM_CONEVIE_Set  | \
                                              USB_HIM_SOFIE_Set)

#define USB_HIM_RESET_MASK                   (USB_HIM_SET_MASK << 16)

#define IS_USB_HIM_VALUE(VALUE)              ((((VALUE) & (~(USB_HIM_SET_MASK | USB_HIM_RESET_MASK))) == 0) && \
                                              ((((VALUE) & ((uint32_t)(VALUE)) >> 16)) == 0))

/** @} */ /* End of group USB_HIM_Values */

/** @defgroup USB_HRXS_Values USB_HRXS Values
  * @{
  */

#define USB_HRXS_CRCERR_Set                  (uint32_t)(1 << USB_HRXS_CRCERR_Pos)
#define USB_HRXS_CRCERR_Reset                (uint32_t)(1 << (USB_HRXS_CRCERR_Pos + 16))

#define USB_HRXS_BSERR_Set                   (uint32_t)(1 << USB_HRXS_BSERR_Pos)
#define USB_HRXS_BSERR_Reset                 (uint32_t)(1 << (USB_HRXS_BSERR_Pos + 16))

#define USB_HRXS_RXOF_Set                    (uint32_t)(1 << USB_HRXS_RXOF_Pos)
#define USB_HRXS_RXOF_Reset                  (uint32_t)(1 << (USB_HRXS_RXOF_Pos + 16))

#define USB_HRXS_RXTO_Set                    (uint32_t)(1 << USB_HRXS_RXTO_Pos)
#define USB_HRXS_RXTO_Reset                  (uint32_t)(1 << (USB_HRXS_RXTO_Pos + 16))

#define USB_HRXS_NAKRXED_Set                 (uint32_t)(1 << USB_HRXS_NAKRXED_Pos)
#define USB_HRXS_NAKRXED_Reset               (uint32_t)(1 << (USB_HRXS_NAKRXED_Pos + 16))

#define USB_HRXS_STALLRXED_Set               (uint32_t)(1 << USB_HRXS_STALLRXED_Pos)
#define USB_HRXS_STALLRXED_Reset             (uint32_t)(1 << (USB_HRXS_STALLRXED_Pos + 16))

#define USB_HRXS_ACKRXED_Set                 (uint32_t)(1 << USB_HRXS_ACKRXED_Pos)
#define USB_HRXS_ACKRXED_Reset               (uint32_t)(1 << (USB_HRXS_ACKRXED_Pos + 16))

#define USB_HRXS_DATASEQ_Data1               (uint32_t)(1 << USB_HRXS_DATASEQ_Pos)
#define USB_HRXS_DATASEQ_Data0               (uint32_t)(1 << (USB_HRXS_DATASEQ_Pos + 16))

#define USB_HRXS_SET_MASK                    (USB_HRXS_CRCERR_Set    | \
                                              USB_HRXS_BSERR_Set     | \
                                              USB_HRXS_RXOF_Set      | \
                                              USB_HRXS_RXTO_Set      | \
                                              USB_HRXS_NAKRXED_Set   | \
                                              USB_HRXS_STALLRXED_Set | \
                                              USB_HRXS_ACKRXED_Set   | \
                                              USB_HRXS_DATASEQ_Data1)

#define USB_HRXS_RESET_MASK                  (USB_HRXS_SET_MASK << 16)

#define IS_USB_HRXS_VALUE(VALUE)             ((((VALUE) & (~(USB_HRXS_SET_MASK | USB_HRXS_RESET_MASK))) == 0) && \
                                              ((((VALUE) & ((uint32_t)(VALUE)) >> 16)) == 0))

/** @} */ /* End of group USB_HRXS_Values */

/** @defgroup USB_HRXCS_Values USB_HRXCS Values
  * @{
  */

#define USB_HRXCS_RXLS_Disconnect            (uint32_t)(0x00000000)
#define USB_HRXCS_RXLS_LowSpeed              (uint32_t)(0x00000001)
#define USB_HRXCS_RXLS_FullSpeed             (uint32_t)(0x00000002)

#define IS_USB_HRXCS_VALUE(VALUE)            (((VALUE) == USB_HRXCS_RXLS_Disconnect) || \
                                              ((VALUE) == USB_HRXCS_RXLS_LowSpeed)   || \
                                              ((VALUE) == USB_HRXCS_RXLS_FullSpeed))

/** @} */ /* End of group USB_HRXCS_Values */

#define IS_USB_HTXA_VALUE(VALUE)             ((VALUE)  < 0x00000080)
#define IS_USB_HTXE_VALUE(VALUE)             ((VALUE)  < 0x00000010)
#define IS_USB_HFN_VALUE(VALUE)              ((VALUE)  < 0x00000800)
#define IS_USB_HRXP_VALUE(VALUE)             ((VALUE)  < 0x00000010)
#define IS_USB_HRXA_VALUE(VALUE)             ((VALUE)  < 0x00000080)
#define IS_USB_HRXE_VALUE(VALUE)             ((VALUE)  < 0x00000010)
#define IS_USB_HSTM_VALUE(VALUE)             ((VALUE)  < 0x00000100)
#define IS_USB_HRXFD_VALUE(VALUE)            ((VALUE)  < 0x00000100)
#define IS_USB_HRXFDC_VALUE(VALUE)           ((VALUE)  < 0x00010000)
#define IS_USB_HRXFC_VALUE(VALUE)            ((VALUE) == 0x00000001)
#define IS_USB_HTXFD_VALUE(VALUE)            ((VALUE)  < 0x00000100)
#define IS_USB_HTXFC_VALUE(VALUE)            ((VALUE) == 0x00000001)

/** @} */ /* End of group USB_HOST_REGS_Values */

/** @defgroup USB_DEVICE_REGS_Values USB_DEVICE Register Values
  * @{
  */

/** @defgroup USB_SEPx_CTRL_Values USB_SEPx_CTRL Values
  * @{
  */

#define USB_SEPx_CTRL_EPEN_Enable            (uint32_t)(1 << USB_SEP_CTRL_EPEN_Pos)
#define USB_SEPx_CTRL_EPEN_Disable           (uint32_t)(1 << (USB_SEP_CTRL_EPEN_Pos + 16))

#define USB_SEPx_CTRL_EPRDY_Ready            (uint32_t)(1 << USB_SEP_CTRL_EPRDY_Pos)
#define USB_SEPx_CTRL_EPRDY_NotReady         (uint32_t)(1 << (USB_SEP_CTRL_EPRDY_Pos + 16))

#define USB_SEPx_CTRL_EPDATASEQ_Data1        (uint32_t)(1 << USB_SEP_CTRL_EPDATASEQ_Pos)
#define USB_SEPx_CTRL_EPDATASEQ_Data0        (uint32_t)(1 << (USB_SEP_CTRL_EPDATASEQ_Pos + 16))

#define USB_SEPx_CTRL_EPSSTALL_Reply         (uint32_t)(1 << USB_SEP_CTRL_EPSSTALL_Pos)
#define USB_SEPx_CTRL_EPSSTALL_NotReply      (uint32_t)(1 << (USB_SEP_CTRL_EPSSTALL_Pos + 16))

#define USB_SEPx_CTRL_EPISOEN_Set            (uint32_t)(1 << USB_SEP_CTRL_EPISOEN_Pos)
#define USB_SEPx_CTRL_EPISOEN_Reset          (uint32_t)(1 << (USB_SEP_CTRL_EPISOEN_Pos + 16))

#define USB_SEPx_CTRL_SET_MASK               (USB_SEPx_CTRL_EPEN_Enable     | \
                                              USB_SEPx_CTRL_EPRDY_Ready     | \
                                              USB_SEPx_CTRL_EPDATASEQ_Data1 | \
                                              USB_SEPx_CTRL_EPSSTALL_Reply  | \
                                              USB_SEPx_CTRL_EPISOEN_Set)

#define USB_SEPx_CTRL_RESET_MASK             (USB_SEPx_CTRL_SET_MASK << 16)

#define IS_USB_SEPx_CTRL_VALUE(VALUE)        ((((VALUE) & (~(USB_SEPx_CTRL_SET_MASK | USB_SEPx_CTRL_RESET_MASK))) == 0) && \
                                              ((((VALUE) & ((uint32_t)(VALUE)) >> 16)) == 0))

/** @} */ /* End of group USB_SEPx_CTRL_Values */

/** @defgroup USB_SEPx_STS_Values USB_SEPx_STS Values
  * @{
  */

#define USB_SEPx_STS_SCCRCERR_Set            (uint32_t)(1 << USB_SEP_STS_SCCRCERR_Pos)
#define USB_SEPx_STS_SCCRCERR_Reset          (uint32_t)(1 << (USB_SEP_STS_SCCRCERR_Pos + 16))

#define USB_SEPx_STS_SCBSERR_Set             (uint32_t)(1 << USB_SEP_STS_SCBSERR_Pos)
#define USB_SEPx_STS_SCBSERR_Reset           (uint32_t)(1 << (USB_SEP_STS_SCBSERR_Pos + 16))

#define USB_SEPx_STS_SCRXOF_Set              (uint32_t)(1 << USB_SEP_STS_SCRXOF_Pos)
#define USB_SEPx_STS_SCRXOF_Reset            (uint32_t)(1 << (USB_SEP_STS_SCRXOF_Pos + 16))

#define USB_SEPx_STS_SCRXTO_Set              (uint32_t)(1 << USB_SEP_STS_SCRXTO_Pos)
#define USB_SEPx_STS_SCRXTO_Reset            (uint32_t)(1 << (USB_SEP_STS_SCRXTO_Pos + 16))

#define USB_SEPx_STS_SCNAKSENT_Set            (uint32_t)(1 << USB_SEP_STS_SCNAKSENT_Pos)
#define USB_SEPx_STS_SCNAKSENT_Reset         (uint32_t)(1 << (USB_SEP_STS_SCNAKSENT_Pos + 16))

#define USB_SEPx_STS_SCSTALLSENT_Set         (uint32_t)(1 << USB_SEP_STS_SCSTALLSENT_Pos)
#define USB_SEPx_STS_SCSTALLSENT_Reset       (uint32_t)(1 << (USB_SEP_STS_SCSTALLSENT_Pos + 16))

#define USB_SEPx_STS_SCACKRXED_Set           (uint32_t)(1 << USB_SEP_STS_SCACKRXED_Pos)
#define USB_SEPx_STS_SCACKRXED_Reset         (uint32_t)(1 << (USB_SEP_STS_SCACKRXED_Pos + 16))

#define USB_SEPx_STS_SCDATASEQ_Data1         (uint32_t)(1 << USB_SEP_STS_SCDATASEQ_Pos)
#define USB_SEPx_STS_SCDATASEQ_Data0         (uint32_t)(1 << (USB_SEP_STS_SCDATASEQ_Pos + 16))

#define USB_SEPx_STS_SET_MASK                (USB_SEPx_STS_SCCRCERR_Set    | \
                                              USB_SEPx_STS_SCBSERR_Set     | \
                                              USB_SEPx_STS_SCRXOF_Set      | \
                                              USB_SEPx_STS_SCRXTO_Set      | \
                                              USB_SEPx_STS_SCSTALLSENT_Set | \
                                              USB_SEPx_STS_SCNAKSENT_Set   | \
                                              USB_SEPx_STS_SCACKRXED_Set   | \
                                              USB_SEPx_STS_SCDATASEQ_Data1)

#define USB_SEPx_STS_RESET_MASK              (USB_SEPx_STS_SET_MASK << 16)

#define IS_USB_SEPx_STS_VALUE(VALUE)         ((((VALUE) & (~(USB_SEPx_STS_SET_MASK | USB_SEPx_STS_RESET_MASK))) == 0) && \
                                              ((((VALUE) & ((uint32_t)(VALUE)) >> 16)) == 0))

/** @} */ /* End of group USB_SEPx_STS_Values */

/** @defgroup USB_SEPx_TS_Values USB_SEPx_TS Values
  * @{
  */

#define USB_SEPx_TS_SCTTYPE_Setup            (uint32_t)(0x00000000)
#define USB_SEPx_TS_SCTTYPE_In               (uint32_t)(0x00000001)
#define USB_SEPx_TS_SCTTYPE_Outdata          (uint32_t)(0x00000002)

#define USB_SEPx_TS_SCTTYPE_Msk              (uint32_t)(0x00000003)

#define IS_USB_SEPx_TS_VALUE(VALUE)          (((VALUE) == USB_SEPx_TS_SCTTYPE_Setup)   || \
                                              ((VALUE) == USB_SEPx_TS_SCTTYPE_In)      || \
                                              ((VALUE) == USB_SEPx_TS_SCTTYPE_Outdata))

/** @} */ /* End of group USB_SEPx_TS_Values */

/** @defgroup USB_SEPx_NTS_Values USB_SEPx_NTS Values
  * @{
  */

#define USB_SEPx_NTS_NTTTYPE_Setup           (uint32_t)(0x00000000)
#define USB_SEPx_NTS_NTTTYPE_In              (uint32_t)(0x00000001)
#define USB_SEPx_NTS_NTTTYPE_Outdata         (uint32_t)(0x00000002)

#define USB_SEPx_NTS_NTTTYPE_Msk             (uint32_t)(0x00000003)

#define IS_USB_SEPx_NTS_VALUE(VALUE)         (((VALUE) == USB_SEPx_NTS_NTTTYPE_Setup)   || \
                                              ((VALUE) == USB_SEPx_NTS_NTTTYPE_In)      || \
                                              ((VALUE) == USB_SEPx_NTS_NTTTYPE_Outdata))

/** @} */ /* End of group USB_SEPx_NTS_Values */

/** @defgroup USB_SC_Values USB_SC Values
  * @{
  */

#define USB_SC_SCGEN_Set                     (uint32_t)(1 << USB_SCGEN_Pos)
#define USB_SC_SCGEN_Reset                   (uint32_t)(1 << (USB_SCGEN_Pos + 16))

#define USB_SC_SCTXLS_DM_Set                 (uint32_t)(1 << USB_SCTXLS_Pos)
#define USB_SC_SCTXLS_DM_Reset               (uint32_t)(1 << (USB_SCTXLS_Pos + 16))

#define USB_SC_SCTXLS_DP_Set                 (uint32_t)(1 << (USB_SCTXLS_Pos + 1))
#define USB_SC_SCTXLS_DP_Reset               (uint32_t)(1 << (USB_SCTXLS_Pos + 16 + 1))

#define USB_SC_SCDC_Direct                   (uint32_t)(1 << USB_SCDC_Pos)
#define USB_SC_SCDC_Normal                   (uint32_t)(1 << (USB_SCDC_Pos + 16))

#define USB_SC_SCFSP_Full                    (uint32_t)(1 << USB_SCFSP_Pos)
#define USB_SC_SCFSP_Low                     (uint32_t)(1 << (USB_SCFSP_Pos + 16))

#define USB_SC_SCFSR_12Mb                    (uint32_t)(1 << USB_SCFSR_Pos)
#define USB_SC_SCFSR_1_5Mb                   (uint32_t)(1 << (USB_SCFSR_Pos + 16))

#define USB_SC_SET_MASK                      (USB_SC_SCGEN_Set     | \
                                              USB_SC_SCTXLS_DM_Set | \
                                              USB_SC_SCTXLS_DP_Set | \
                                              USB_SC_SCDC_Direct   | \
                                              USB_SC_SCFSP_Full    | \
                                              USB_SC_SCFSR_12Mb)

#define USB_SC_RESET_MASK                    (USB_SC_SET_MASK << 16)

#define IS_USB_SC_VALUE(VALUE)               ((((VALUE) & (~(USB_SC_SET_MASK | USB_SC_RESET_MASK))) == 0) && \
                                              ((((VALUE) & ((uint32_t)(VALUE)) >> 16)) == 0))

/** @} */ /* End of group USB_SC_Values */

/** @defgroup USB_SLS_Values USB_SLS Values
  * @{
  */

#define USB_SLS_SCRXLS_Reset                 (uint32_t)(0x00000000)
#define USB_SLS_SCRXLS_LowSpeed              (uint32_t)(0x00000001)
#define USB_SLS_SCRXLS_FullSpeed             (uint32_t)(0x00000002)

#define IS_USB_SLS_VALUE(VALUE)              (((VALUE) == USB_SLS_SCRXLS_Reset)     || \
                                              ((VALUE) == USB_SLS_SCRXLS_LowSpeed)  || \
                                              ((VALUE) == USB_SLS_SCRXLS_FullSpeed))

/** @} */ /* End of group USB_SLS_Values */

/** @defgroup USB_SIS_Values USB_SIS Values
  * @{
  */

#define USB_SIS_SCTDONE_Set                  USB_SIS_SCTDONE
#define USB_SIS_SCRESUME_Set                 USB_SIS_SCRESUME
#define USB_SIS_SCRESETEV_Set                USB_SIS_SCRESETEV
#define USB_SIS_SCSOFREC_Set                 USB_SIS_SCSOFREC
#define USB_SIS_SCNAKSENT_Set                USB_SIS_SCNAKSENT
#define USB_SIS_SCUSBON_Set                  USB_SIS_SCUSBON

#define USB_SIS_Msk                          (USB_SIS_SCTDONE_Set   | \
                                              USB_SIS_SCRESUME_Set  | \
                                              USB_SIS_SCRESETEV_Set | \
                                              USB_SIS_SCSOFREC_Set  | \
                                              USB_SIS_SCNAKSENT_Set)

#define IS_USB_SIS_VALUE(VALUE)              (!((VALUE) & ~USB_SIS_Msk))

/** @} */ /* End of group USB_SIS_Values */

/** @defgroup USB_SIM_Values USB_SIM Values
  * @{
  */

#define USB_SIM_SCTDONEIE_Set                (uint32_t)(1 << USB_SIM_SCTDONEIE_Pos)
#define USB_SIM_SCTDONEIE_Reset              (uint32_t)(1 << (USB_SIM_SCTDONEIE_Pos + 16))

#define USB_SIM_SCRESUMEIE_Set               (uint32_t)(1 << USB_SIM_SCRESUMEIE_Pos)
#define USB_SIM_SCRESUMEIE_Reset             (uint32_t)(1 << (USB_SIM_SCRESUMEIE_Pos + 16))

#define USB_SIM_SCRESETEVIE_Set              (uint32_t)(1 << USB_SIM_SCRESETEVIE_Pos)
#define USB_SIM_SCRESETEVIE_Reset            (uint32_t)(1 << (USB_SIM_SCRESETEVIE_Pos + 16))

#define USB_SIM_SCSOFRECIE_Set               (uint32_t)(1 << USB_SIM_SCSOFRECIE_Pos)
#define USB_SIM_SCSOFRECIE_Reset             (uint32_t)(1 << (USB_SIM_SCSOFRECIE_Pos + 16))

#define USB_SIM_SCNAKSENTIE_Set              (uint32_t)(1 << USB_SIM_SCNAKSENTIE_Pos)
#define USB_SIM_SCNAKSENTIE_Reset            (uint32_t)(1 << (USB_SIM_SCNAKSENTIE_Pos + 16))

#define USB_SIM_SET_MASK                     (USB_SIM_SCTDONEIE_Set   | \
                                              USB_SIM_SCRESUMEIE_Set  | \
                                              USB_SIM_SCRESETEVIE_Set | \
                                              USB_SIM_SCSOFRECIE_Set  | \
                                              USB_SIM_SCNAKSENTIE_Set)

#define USB_SIM_RESET_MASK                   (USB_SIM_SET_MASK << 16)

#define IS_USB_SIM_VALUE(VALUE)              ((((VALUE) & (~(USB_SIM_SET_MASK | USB_SIM_RESET_MASK))) == 0) && \
                                              ((((VALUE) & ((uint32_t)(VALUE)) >> 16)) == 0))

/** @} */ /* End of group USB_SIM_Values */

#define IS_USB_SA_VALUE(VALUE)               ((VALUE)  < 0x00000080)
#define IS_USB_SFN_VALUE(VALUE)              ((VALUE)  < 0x00000800)
#define IS_USB_SEPx_RXFD_VALUE(VALUE)        ((VALUE)  < 0x00000100)
#define IS_USB_SEPx_RXFDC_VALUE(VALUE)       ((VALUE)  < 0x00010000)
#define IS_USB_SEPx_RXFC_VALUE(VALUE)        ((VALUE) == 0x00000001)
#define IS_USB_SEPx_TXFD_VALUE(VALUE)        ((VALUE)  < 0x00000100)
#define IS_USB_SEPx_TXFDC_VALUE(VALUE)       ((VALUE) == 0x00000001)

/** @} */ /* End of group USB_DEVICE_REGS_Values */


/** @defgroup USB_Exported_Functions USB Exported Functions
  * @{
  */

void USB_BRGInit(const USB_Clock_TypeDef* USB_Clock_InitStruct);
void USB_Reset(void);

/**
  * @brief  Common register functions
  */

uint32_t USB_GetHSCR(void);
void     USB_SetHSCR(uint32_t RegValue);

USB_Version_TypeDef USB_GetHSVR(void);

/**
  * @brief  Host register functions
  */

uint32_t USB_GetHTXC(void);
void     USB_SetHTXC(uint32_t RegValue);
uint32_t USB_GetHTXT(void);
void     USB_SetHTXT(uint32_t RegValue);
uint32_t USB_GetHTXLC(void);
void     USB_SetHTXLC(uint32_t RegValue);
uint32_t USB_GetHTXSE(void);
void     USB_SetHTXSE(uint32_t RegValue);
uint32_t USB_GetHTXA(void);
void     USB_SetHTXA(uint32_t RegValue);
uint32_t USB_GetHTXE(void);
void     USB_SetHTXE(uint32_t RegValue);
uint32_t USB_GetHFN(void);
uint32_t USB_GetHIS(void);
void     USB_SetHIS(uint32_t RegValue);
uint32_t USB_GetHIM(void);
void     USB_SetHIM(uint32_t RegValue);
uint32_t USB_GetHRXS(void);
uint32_t USB_GetHRXP(void);
uint32_t USB_GetHRXA(void);
uint32_t USB_GetHRXE(void);
uint32_t USB_GetHRXCS(void);
uint32_t USB_GetHSTM(void);
uint32_t USB_GetHRXFD(void);
uint32_t USB_GetHRXFDC(void);
uint32_t USB_GetHRXFC(void);
void     USB_SetHRXFC(uint32_t RegValue);
uint32_t USB_GetHTXFD(void);
void     USB_SetHTXFD(uint32_t RegValue);
uint32_t USB_GetHTXFC(void);
void     USB_SetHTXFC(uint32_t RegValue);

/**
  * @brief  Slave register functions
  */

uint32_t USB_GetSEPxCTRL(USB_EP_TypeDef EndPointNumber);
void     USB_SetSEPxCTRL(USB_EP_TypeDef EndPointNumber, uint32_t RegValue);
uint32_t USB_GetSEPxSTS(USB_EP_TypeDef EndPointNumber);
uint32_t USB_GetSEPxTS(USB_EP_TypeDef EndPointNumber);
uint32_t USB_GetSEPxNTS(USB_EP_TypeDef EndPointNumber);
uint32_t USB_GetSC(void);
void     USB_SetSC(uint32_t RegValue);
uint32_t USB_GetSLS(void);
uint32_t USB_GetSIS(void);
void     USB_SetSIS(uint32_t RegValue);
uint32_t USB_GetSIM(void);
void     USB_SetSIM(uint32_t RegValue);
uint32_t USB_GetSA(void);
void     USB_SetSA(uint32_t RegValue);
uint32_t USB_GetSFN(void);
uint32_t USB_GetSEPxRXFD(USB_EP_TypeDef EndPointNumber);
uint32_t USB_GetSEPxRXFDC(USB_EP_TypeDef EndPointNumber);
uint32_t USB_GetSEPxRXFC(USB_EP_TypeDef EndPointNumber);
void     USB_SetSEPxRXFC(USB_EP_TypeDef EndPointNumber, uint32_t RegValue);
uint32_t USB_GetSEPxTXFD(USB_EP_TypeDef EndPointNumber);
void     USB_SetSEPxTXFD(USB_EP_TypeDef EndPointNumber, uint32_t RegValue);
uint32_t USB_GetSEPxTXFDC(USB_EP_TypeDef EndPointNumber);
void     USB_SetSEPxTXFDC(USB_EP_TypeDef EndPointNumber, uint32_t RegValue);
void     USB_SEPxToggleEPDATASEQ(USB_EP_TypeDef EndPointNumber);

/** @} */ /* End of group USB_Exported_Functions */

/** @} */ /* End of group USB */

/** @} */ /* End of group MDR32F9Qx_StdPeriph_Driver */

#ifdef __cplusplus
} // extern "C" block end
#endif

#endif /* __MDR32F9Qx_USB_H */

/*
*
* END OF FILE MDR32F9Qx_usb.h */
