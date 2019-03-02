/**
  * FILE MDR1901VC1T.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MDR1901VC1T_H
#define __MDR1901VC1T_H

/** @addtogroup __CMSIS CMSIS
  * @{
  */

/** @addtogroup MDR1901VC1T MDR1901VC1T
  * @{
  */

/** @addtogroup __MDR1901VC1T_Peripheral MDR1901VC1TPeripheral
  * @{
  */

#ifdef __cplusplus
extern "C" {
#endif

#if defined ( __CC_ARM   )
	#pragma anon_unions
#endif

/* MDR1901VC1T Interrupt Number Definition */
typedef enum IQRn{
/*-- Cortex-CM3 Processor Exceptions Numbers ----------------------------------*/
	NonMaskableInt_IRQn                   = -14, /*!< 2 Non Maskable Interrupt */
	HardFault_IRQn                        = -13, /*!< 3 Hard Fault Interrupt */
	MemoryManagement_IRQn                 = -12, /*!< 4 Memory Management Interrupt */
	BusFault_IRQn                         = -11, /*!< 5 Bus Fault Interrupt */
	UsageFault_IRQn                       = -10, /*!< 6 Usage Fault Interrupt */
	SVCall_IRQn                           = -5, /*!< 11 SV Call Interrupt */
	PendSV_IRQn                           = -2, /*!< 14 Pend SV Interrupt */
	SysTick_IRQn                          = -1, /*!< 15 System Tick Timer Interrupt */
/*-- MDR1901VC1T specific Interrupt Numbers --------------------------------------*/
	SSP3_IRQn                             = 0, /*!< SSP3 Interrupt */
	SSP4_IRQn                             = 1, /*!< SSP4  Interrupt */
	USB_IRQn                              = 2, /*!< USB Host  Interrupt */
	MCBSP1_IRQn                           = 3, /*!< MCBSP1  Interrupt */
	MCBSP2_IRQn                           = 4, /*!< MCBSP2  Interrupt */
	DMA_IRQn                              = 5, /*!< DMA  Interrupt */
	UART1_IRQn                            = 6, /*!< UART1  Interrupt */
	UART2_IRQn                            = 7, /*!< UART2  Interrupt */
	SSP1_IRQn                             = 8, /*!< SSP1  Interrupt */
	MCBSP3_IRQn                           = 9, /*!< MCBSP3  Interrupt */
	I2C_IRQn                              = 10, /*!< I2C  Interrupt */
	POWER_IRQn                            = 11, /*!< POWER Detecor  Interrupt */
	WWDG_IRQn                             = 12, /*!< Window Watchdog  Interrupt */
	DMA_DSP_IRQn                          = 13, /*!< DMA DSP  Interrupt */
	TIMER1_IRQn                           = 14, /*!< Timer1  Interrupt */
	TIMER2_IRQn                           = 15, /*!< Timer2  Interrupt */
	TIMER3_IRQn                           = 16, /*!< Timer3  Interrupt */
	ADC_IRQn                              = 17, /*!< ADC  Interrupt */
	SDIO_IRQn                             = 18, /*!< SDIO  Interrupt */
	COMPARATOR_IRQn                       = 19, /*!< COMPARATOR  Interrupt */
	SSP2_IRQn                             = 20, /*!< SSP2  Interrupt */
	AUDIO_IP_IRQn                         = 21, /*!< Audio IP  Interrupt */
	DSP_CRPT_IRQn                         = 22, /*!< DSP CRPT  Interrupt */
	DSP_TIMER_IRQn                        = 23, /*!< DSP TIMER  Interrupt */
	DSP_CORE_IRQn                         = 24, /*!< DSP CORE  Interrupt */
	DSP_STATE_IRQn                        = 25, /*!< DSP STATE  Interrupt */
	UART3_IRQn                            = 26, /*!< UART3  Interrupt */
	BACKUP_IRQn                           = 27, /*!< BACKUP  Interrupt */
	EXT_INT1_IRQn                         = 28, /*!< EXT_INT1  Interrupt */
	EXT_INT2_IRQn                         = 29, /*!< EXT_INT2  Interrupt */
	EXT_INT3_IRQn                         = 30, /*!< EXT_INT3  Interrupt */
	EXT_INT4_IRQn                         = 31  /*!< EXT_INT4  Interrupt */
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
#include "system_MDR1901VC1T.h"

/** @defgroup _Exported_types _Exported_types
  * @{
  */

typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus;
#define IS_FLAG_STATUS(FLAG) (((FLAG) == RESET) || ((FLAG) == SET))
typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;
#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))
typedef enum {ERROR = 0, SUCCESS = !ERROR} ErrorStatus;
/** @} */ /* End of group __Exported_types */

/** @addtogroup MDR1901VC1T_Peripheral_Units MDR1901VC1TPeripheral Units
  * @{
  */

/** @defgroup MDR1901VC1T_Periph_SSP SSP
  * @{
  */


/* MDR_SSPx_TypeDef structure */
typedef struct {
	__IO uint32_t	CR0;                    /*!<SSP Control0 Register */
	__IO uint32_t	CR1;                    /*!<SSP Control1 Register */
	__IO uint32_t	DR;                     /*!<SSP Data Register */
	__IO uint32_t	SR;                     /*!<SSP Status Register */
	__IO uint32_t	CPSR;                   /*!<SSP Clock Prescaler Register */
	__IO uint32_t	IMSC;                   /*!<SSP Interrupt Mask Register */
	__IO uint32_t	RIS;                    /*!<SSP Interrupt Pending Register */
	__IO uint32_t	MIS;                    /*!<SSP Masked Interrupt Pending Register */
	__IO uint32_t	ICR;                    /*!<SSP Interrupt Clear Register */
	__IO uint32_t	DMACR;                  /*!<SSP DMA Control Register */
}MDR_SSP_TypeDef;

/** @defgroup Periph_SSP_CR0 SSP CR0
  * @{
  */

/*-- SSP_CR0:SSP CR0 Register -----*/

/* Bit field positions: */
#define SSP_CR0_DSS_Pos                                    0
#define SSP_CR0_FRF_Pos                                    4
#define SSP_CR0_SPO_Pos                                    6
#define SSP_CR0_SPH_Pos                                    7
#define SSP_CR0_SCR_Pos                                    8

/* Bit field masks: */
#define SSP_CR0_DSS_Msk                                    ((uint32_t)0x0000000F)
#define SSP_CR0_FRF_Msk                                    ((uint32_t)0x00000030)
#define SSP_CR0_SPO                                        ((uint32_t)0x00000040)
#define SSP_CR0_SPH                                        ((uint32_t)0x00000080)
#define SSP_CR0_SCR_Msk                                    ((uint32_t)0x0000FF00)

/** @} */ /* End of group SSP_CR0 */

/** @defgroup Periph_SSP_CR1 SSP CR1
  * @{
  */

/*-- SSP_CR1:SSP CR1 Register -----*/

/* Bit field positions: */
#define SSP_CR1_LBM_Pos                                    0
#define SSP_CR1_SSE_Pos                                    1
#define SSP_CR1_MS_Pos                                     2
#define SSP_CR1_SOD_Pos                                    3

/* Bit field masks: */
#define SSP_CR1_LBM                                        ((uint32_t)0x00000001)
#define SSP_CR1_SSE                                        ((uint32_t)0x00000002)
#define SSP_CR1_MS                                         ((uint32_t)0x00000004)
#define SSP_CR1_SOD                                        ((uint32_t)0x00000008)

/** @} */ /* End of group SSP_CR1 */

/** @defgroup Periph_SSP_DR SSP DR
  * @{
  */

/*-- SSP_DR:SSP DR Register -----*/

/* Bit field positions: */
#define SSP_DR_DATA_Pos                                    0

/* Bit field masks: */
#define SSP_DR_DATA_Msk                                    ((uint32_t)0x0000FFFF)

/** @} */ /* End of group SSP_DR */

/** @defgroup Periph_SSP_SR SSP SR
  * @{
  */

/*-- SSP_SR:SSP SR Register -----*/

/* Bit field positions: */
#define SSP_SR_TFE_Pos                                     0
#define SSP_SR_TNF_Pos                                     1
#define SSP_SR_RNE_Pos                                     2
#define SSP_SR_RFF_Pos                                     3
#define SSP_SR_BSY_Pos                                     4

/* Bit field masks: */
#define SSP_SR_TFE                                         ((uint32_t)0x00000001)
#define SSP_SR_TNF                                         ((uint32_t)0x00000002)
#define SSP_SR_RNE                                         ((uint32_t)0x00000004)
#define SSP_SR_RFF                                         ((uint32_t)0x00000008)
#define SSP_SR_BSY                                         ((uint32_t)0x00000010)

/** @} */ /* End of group SSP_SR */

/** @defgroup Periph_SSP_CPSR SSP CPSR
  * @{
  */

/*-- SSP_CPSR:SSP CPSR Register -----*/

/* Bit field positions: */
#define SSP_CPSR_CPSDVSR_Pos                               0

/* Bit field masks: */
#define SSP_CPSR_CPSDVSR_Msk                               ((uint32_t)0x000000FF)

/** @} */ /* End of group SSP_CPSR */

/** @defgroup Periph_SSP_IMSC SSP IMSC
  * @{
  */

/*-- SSP_IMSC:SSP IMSC Register -----*/

/* Bit field positions: */
#define SSP_IMSC_RORIM_Pos                                 0
#define SSP_IMSC_RTIM_Pos                                  1
#define SSP_IMSC_RXIM_Pos                                  2
#define SSP_IMSC_TXIM_Pos                                  3

/* Bit field masks: */
#define SSP_IMSC_RORIM                                     ((uint32_t)0x00000001)
#define SSP_IMSC_RTIM                                      ((uint32_t)0x00000002)
#define SSP_IMSC_RXIM                                      ((uint32_t)0x00000004)
#define SSP_IMSC_TXIM                                      ((uint32_t)0x00000008)

/** @} */ /* End of group SSP_IMSC */

/** @defgroup Periph_SSP_RIS SSP RIS
  * @{
  */

/*-- SSP_RIS:SSP RIS Register -----*/

/* Bit field positions: */
#define SSP_RIS_RORRIS_Pos                                 0
#define SSP_RIS_RTRIS_Pos                                  1
#define SSP_RIS_RXRIS_Pos                                  2
#define SSP_RIS_TXRIS_Pos                                  3

/* Bit field masks: */
#define SSP_RIS_RORRIS                                     ((uint32_t)0x00000001)
#define SSP_RIS_RTRIS                                      ((uint32_t)0x00000002)
#define SSP_RIS_RXRIS                                      ((uint32_t)0x00000004)
#define SSP_RIS_TXRIS                                      ((uint32_t)0x00000008)

/** @} */ /* End of group SSP_RIS */

/** @defgroup Periph_SSP_MIS SSP MIS
  * @{
  */

/*-- SSP_MIS:SSP MIS Register -----*/

/* Bit field positions: */
#define SSP_MIS_RORMIS_Pos                                 0
#define SSP_MIS_RTMIS_Pos                                  1
#define SSP_MIS_RXMIS_Pos                                  2
#define SSP_MIS_TXMIS_Pos                                  3

/* Bit field masks: */
#define SSP_MIS_RORMIS                                     ((uint32_t)0x00000001)
#define SSP_MIS_RTMIS                                      ((uint32_t)0x00000002)
#define SSP_MIS_RXMIS                                      ((uint32_t)0x00000004)
#define SSP_MIS_TXMIS                                      ((uint32_t)0x00000008)

/** @} */ /* End of group SSP_MIS */

/** @defgroup Periph_SSP_ICR SSP ICR
  * @{
  */

/*-- SSP_ICR:SSP ICR Register -----*/

/* Bit field positions: */
#define SSP_ICR_RORIC_Pos                                  0
#define SSP_ICR_RTIC_Pos                                   1

/* Bit field masks: */
#define SSP_ICR_RORIC                                      ((uint32_t)0x00000001)
#define SSP_ICR_RTIC                                       ((uint32_t)0x00000002)

/** @} */ /* End of group SSP_ICR */

/** @defgroup Periph_SSP_DMACR SSP DMACR
  * @{
  */

/*-- SSP_DMACR:SSP DMACR Register -----*/

/* Bit field positions: */
#define SSP_DMACR_RXDMAE_Pos                               0
#define SSP_DMACR_TXDMAE_Pos                               1

/* Bit field masks: */
#define SSP_DMACR_RXDMAE                                   ((uint32_t)0x00000001)
#define SSP_DMACR_TXDMAE                                   ((uint32_t)0x00000002)

/** @} */ /* End of group SSP_DMACR */

/** @} */ /* End of group SSP */

/** @defgroup MDR1901VC1T_Periph_USB USB
  * @{
  */

/* MDR_USB_SEP_Typedef structure */
typedef struct {
	__IO uint32_t CTRL;
	__IO uint32_t STS;
	__IO uint32_t TS;
	__IO uint32_t NTS;
}MDR_USB_SEP_TypeDef;

/* MDR_USB_SEP_FIFO_Typedef structure */
typedef struct {
	__IO uint32_t RXFD;
	__I  uint32_t RESERVED0;
	__IO uint32_t RXFDC_L;
	__IO uint32_t RXFDC_H;
	__IO uint32_t RXFC;
	__I  uint32_t RESERVED1[11];
	__IO uint32_t TXFD;
	__I  uint32_t RESERVED2[3];
	__IO uint32_t TXFDC;
	__I  uint32_t RESERVED3[10];
	__I  uint32_t RESERVED4;
}MDR_USB_SEP_FIFO_TypeDef;


/* MDR_USB_TypeDef structure */
typedef struct {
	__IO uint32_t	HTXC;                   /*!<USB HTXC Register */
	__IO uint32_t	HTXT;                   /*!<USB HTXT Register */
	__IO uint32_t	HTXLC;                  /*!<USB HTXLC Register */
	__IO uint32_t	HTXSE;                  /*!< */
	__IO uint32_t	HTXA;                   /*!< */
	__IO uint32_t	HTXE;                   /*!< */
	__IO uint32_t	HFN_L;                  /*!< */
	__IO uint32_t	HFN_H;                  /*!< */
	__IO uint32_t	HIS;                    /*!<USB_HIS Register */
	__IO uint32_t	HIM;                    /*!<USB_HIM Register */
	__IO uint32_t	HRXS;                   /*!<USB_HRXS Register */
	__IO uint32_t	HRXP;                   /*!< */
	__IO uint32_t	HRXA;                   /*!< */
	__IO uint32_t	HRXE;                   /*!< */
	__IO uint32_t	HRXCS;                  /*!< */
	__IO uint32_t	HSTM;                   /*!< */
	__I  uint32_t	RESERVED0[16];
	__IO uint32_t	HRXFD;                  /*!< */
	__I  uint32_t	RESERVED1;
	__IO uint32_t	HRXFDC_L;               /*!< */
	__IO uint32_t	HRXFDC_H;               /*!< */
	__IO uint32_t	HRXFC;                  /*!< */
	__I  uint32_t	RESERVED2[11];
	__IO uint32_t	HTXFD;                  /*!< */
	__I  uint32_t	RESERVED3[3];
	__IO uint32_t	HTXFC;                  /*!< */
	__I  uint32_t	RESERVED4[11];
	MDR_USB_SEP_TypeDef USB_SEP[4];
	__IO uint32_t	SC;                     /*!<USB_SC Register */
	__IO uint32_t	SLS;                    /*!< */
	__IO uint32_t	SIS;                    /*!<USB_SIS Register */
	__IO uint32_t	SIM;                    /*!<USB_SIM Register */
	__IO uint32_t	SA;                     /*!< */
	__IO uint32_t	SFN_L;                  /*!< */
	__IO uint32_t	SFN_H;                  /*!< */
	__I  uint32_t	RESERVED5[9];
	MDR_USB_SEP_FIFO_TypeDef USB_SEP_FIFO[4];
	__IO uint32_t	HSCR;                   /*!<USB_HSCR Register */
	__IO uint32_t	HSVR;                   /*!<USB_HSVR Register */
}MDR_USB_TypeDef;

/** @defgroup Periph_USB_HTXC USB HTXC
  * @{
  */

/*-- USB_HTXC:USB HTXC Register -----*/

/* Bit field positions: */
#define USB_HTXC_TREQ_Pos                                  0
#define USB_HTXC_SOFS_Pos                                  1
#define USB_HTXC_PREEN_Pos                                 2
#define USB_HTXC_ISOEN_Pos                                 3

/* Bit field masks: */
#define USB_HTXC_TREQ                                      ((uint32_t)0x00000001)
#define USB_HTXC_SOFS                                      ((uint32_t)0x00000002)
#define USB_HTXC_PREEN                                     ((uint32_t)0x00000004)
#define USB_HTXC_ISOEN                                     ((uint32_t)0x00000008)

/** @} */ /* End of group USB_HTXC */

/** @defgroup Periph_USB_HTXT USB HTXT
  * @{
  */

/*-- USB_HTXT:USB HTXT Register -----*/

/* Bit field positions: */
#define USB_HTXT_TTYPE_Pos                                 0

/* Bit field masks: */
#define USB_HTXT_TTYPE_Msk                                 ((uint32_t)0x00000003)

/** @} */ /* End of group USB_HTXT */

/** @defgroup Periph_USB_HTXLC USB HTXLC
  * @{
  */

/*-- USB_HTXLC:USB HTXLC Register -----*/

/* Bit field positions: */
#define USB_HTXLC_Pos                                      0
#define USB_HTXLC_DC_Pos                                   2
#define USB_HTXLC_FSPL_Pos                                 3
#define USB_HTXLC_FSLR_Pos                                 4

/* Bit field masks: */
#define USB_HTXLC_Msk                                	   ((uint32_t)0x00000003)
#define USB_HTXLC_DC                                       ((uint32_t)0x00000004)
#define USB_HTXLC_FSPL                                     ((uint32_t)0x00000008)
#define USB_HTXLC_FSLR                                     ((uint32_t)0x00000010)

/** @} */ /* End of group USB_HTXLC */

/** @defgroup Periph_USB_HTXSE USB HTXSE
  * @{
  */

/*-- USB_HTXSE:USB HTXSE Register -----*/

/* Bit field positions: */
#define USB_HTXSE_SOFEN_Pos                                0

/* Bit field masks: */
#define USB_HTXSE_SOFEN                                    ((uint32_t)0x00000001)

/** @} */ /* End of group USB_HTXSE */

/** @defgroup Periph_USB_HTXA USB HTXA
  * @{
  */

/*-- USB_HTXA:USB HTXA Register -----*/

/* Bit field positions: */
#define USB_HTXA_DEVADDR_Pos                               0

/* Bit field masks: */
#define USB_HTXA_DEVADDR_Msk                               ((uint32_t)0x0000007F)

/** @} */ /* End of group USB_HTXA */

/** @defgroup Periph_USB_HTXE USB HTXE
  * @{
  */

/*-- USB_HTXE:USB HTXE Register -----*/

/* Bit field positions: */
#define USB_HTXE_EPADDR_Pos                                0

/* Bit field masks: */
#define USB_HTXE_EPADDR_Msk                                ((uint32_t)0x0000000F)

/** @} */ /* End of group USB_HTXE */

/** @defgroup Periph_USB_HFN_L USB HFN_L
  * @{
  */

/*-- USB_HFN_L:USB HFN_L Register -----*/

/* Bit field positions: */
#define USB_HFN_L_FNUM_Pos                                 0

/* Bit field masks: */
#define USB_HFN_L_FNUM_Msk                                 ((uint32_t)0x000000FF)

/** @} */ /* End of group USB_HFN_L */

/** @defgroup Periph_USB_HFN_H USB HFN_H
  * @{
  */

/*-- USB_HFN_H:USB HFN_H Register -----*/

/* Bit field positions: */
#define USB_HFN_H_FNUM_Pos                                 0

/* Bit field masks: */
#define USB_HFN_H_FNUM_Msk                                 ((uint32_t)0x00000007)

/** @} */ /* End of group USB_HFN_H */

/** @defgroup Periph_USB_HIS USB HIS
  * @{
  */

/*-- USB_HIS:USB HIS Register -----*/

/* Bit field positions: */
#define USB_HIS_TDONE_Pos                                  0
#define USB_HIS_RESUME_Pos                                 1
#define USB_HIS_CONEV_Pos                                  2
#define USB_HIS_SOFS_Pos                                   3

/* Bit field masks: */
#define USB_HIS_TDONE                                      ((uint32_t)0x00000001)
#define USB_HIS_RESUME                                     ((uint32_t)0x00000002)
#define USB_HIS_CONEV                                      ((uint32_t)0x00000004)
#define USB_HIS_SOFS                                       ((uint32_t)0x00000008)

/** @} */ /* End of group USB_HIS */

/** @defgroup Periph_USB_HIM USB HIM
  * @{
  */

/*-- USB_HIM:USB HIM Register -----*/

/* Bit field positions: */
#define USB_HIM_TDONEIE_Pos                                0
#define USB_HIM_RESUMEIE_Pos                               1
#define USB_HIM_CONEVIE_Pos                                2
#define USB_HIM_SOFIE_Pos                                  3

/* Bit field masks: */
#define USB_HIM_TDONEIE                                    ((uint32_t)0x00000001)
#define USB_HIM_RESUMEIE                                   ((uint32_t)0x00000002)
#define USB_HIM_CONEVIE                                    ((uint32_t)0x00000004)
#define USB_HIM_SOFIE                                      ((uint32_t)0x00000008)

/** @} */ /* End of group USB_HIM */

/** @defgroup Periph_USB_HRXS USB HRXS
  * @{
  */

/*-- USB_HRXS:USB HRXS Register -----*/

/* Bit field positions: */
#define USB_HRXS_CRCERR_Pos                                0
#define USB_HRXS_BSERR_Pos                                 1
#define USB_HRXS_RXOF_Pos                                  2
#define USB_HRXS_RXTO_Pos                                  3
#define USB_HRXS_NAKRXED_Pos                               4
#define USB_HRXS_STALLRXED_Pos                             5
#define USB_HRXS_ACKRXED_Pos                               6
#define USB_HRXS_DATASEQ_Pos                               7

/* Bit field masks: */
#define USB_HRXS_CRCERR                                    ((uint32_t)0x00000001)
#define USB_HRXS_BSERR                                     ((uint32_t)0x00000002)
#define USB_HRXS_RXOF                                      ((uint32_t)0x00000004)
#define USB_HRXS_RXTO                                      ((uint32_t)0x00000008)
#define USB_HRXS_NAKRXED                                   ((uint32_t)0x00000010)
#define USB_HRXS_STALLRXED                                 ((uint32_t)0x00000020)
#define USB_HRXS_ACKRXED                                   ((uint32_t)0x00000040)
#define USB_HRXS_DATASEQ                                   ((uint32_t)0x00000080)

/** @} */ /* End of group USB_HRXS */

/** @defgroup Periph_USB_HRXP USB HRXP
  * @{
  */

/*-- USB_HRXP:USB HRXP Register -----*/

/* Bit field positions: */
#define USB_HRXP_RPID_Pos                                  0

/* Bit field masks: */
#define USB_HRXP_RPID_Msk                                  ((uint32_t)0x0000000F)

/** @} */ /* End of group USB_HRXP */

/** @defgroup Periph_USB_HRXA USB HRXA
  * @{
  */

/*-- USB_HRXA:USB HRXA Register -----*/

/* Bit field positions: */
#define USB_HRXA_RADDR_Pos                                 0

/* Bit field masks: */
#define USB_HRXA_RADDR_Msk                                 ((uint32_t)0x0000007F)

/** @} */ /* End of group USB_HRXA */

/** @defgroup Periph_USB_HRXE USB HRXE
  * @{
  */

/*-- USB_HRXE:USB HRXE Register -----*/

/* Bit field positions: */
#define USB_HRXE_RENDP_Pos                                 0

/* Bit field masks: */
#define USB_HRXE_RENDP_Msk                                 ((uint32_t)0x0000000F)

/** @} */ /* End of group USB_HRXE */

/** @defgroup Periph_USB_HRXCS USB HRXCS
  * @{
  */

/*-- USB_HRXCS:USB HRXCS Register -----*/

/* Bit field positions: */
#define USB_HRXCS_RXLS_Pos                                 0

/* Bit field masks: */
#define USB_HRXCS_RXLS_Msk                                 ((uint32_t)0x00000003)

/** @} */ /* End of group USB_HRXCS */

/** @defgroup Periph_USB_HSTM USB HSTM
  * @{
  */

/*-- USB_HSTM:USB HSTM Register -----*/

/* Bit field positions: */
#define USB_HSTM_HSTM_Pos                                  0

/* Bit field masks: */
#define USB_HSTM_HSTM_Msk                                  ((uint32_t)0x000000FF)

/** @} */ /* End of group USB_HSTM */

/** @defgroup Periph_USB_HRXFD USB HRXFD
  * @{
  */

/*-- USB_HRXFD:USB HRXFD Register -----*/

/* Bit field positions: */
#define USB_HRXFD_RXFIFODATA_Pos                           0

/* Bit field masks: */
#define USB_HRXFD_RXFIFODATA_Msk                           ((uint32_t)0x000000FF)

/** @} */ /* End of group USB_HRXFD */

/** @defgroup Periph_USB_HRXFDC_L USB HRXFDC_L
  * @{
  */

/*-- USB_HRXFDC_L:USB HRXFDC_L Register -----*/

/* Bit field positions: */
#define USB_HRXFDC_L_FIFODATACOUNT_Pos                     0

/* Bit field masks: */
#define USB_HRXFDC_L_FIFODATACOUNT_Msk                     ((uint32_t)0x000000FF)

/** @} */ /* End of group USB_HRXFDC_L */

/** @defgroup Periph_USB_HRXFDC_H USB HRXFDC_H
  * @{
  */

/*-- USB_HRXFDC_H:USB HRXFDC_H Register -----*/

/* Bit field positions: */
#define USB_HRXFDC_H_FIFODATACOUNT_Pos                     0

/* Bit field masks: */
#define USB_HRXFDC_H_FIFODATACOUNT_Msk                     ((uint32_t)0x000000FF)

/** @} */ /* End of group USB_HRXFDC_H */

/** @defgroup Periph_USB_HRXFC USB HRXFC
  * @{
  */

/*-- USB_HRXFC:USB HRXFC Register -----*/

/* Bit field positions: */
#define USB_HRXFC_FIFOFORCEEMPTY_Pos                       0

/* Bit field masks: */
#define USB_HRXFC_FIFOFORCEEMPTY                           ((uint32_t)0x00000001)

/** @} */ /* End of group USB_HRXFC */

/** @defgroup Periph_USB_HTXFD USB HTXFD
  * @{
  */

/*-- USB_HTXFD:USB HTXFD Register -----*/

/* Bit field positions: */
#define USB_HTXFD_TXFIFODATA_Pos                           0

/* Bit field masks: */
#define USB_HTXFD_TXFIFODATA_Msk                           ((uint32_t)0x000000FF)

/** @} */ /* End of group USB_HTXFD */

/** @defgroup Periph_USB_HTXFC USB HTXFC
  * @{
  */

/*-- USB_HTXFC:USB HTXFC Register -----*/

/* Bit field positions: */
#define USB_HTXFC_FIFOFORCEEMPTY_Pos                       0

/* Bit field masks: */
#define USB_HTXFC_FIFOFORCEEMPTY                           ((uint32_t)0x00000001)

/** @} */ /* End of group USB_HTXFC */

/** @defgroup Periph_USB_SEP_CTRL USB SEP_CTRL
  * @{
  */

/*-- USB_SEP_CTRL:USB SEP_CTRL Register -----*/

/* Bit field positions: */
#define USB_SEP_CTRL_EPEN_Pos                              0
#define USB_SEP_CTRL_EPRDY_Pos                             1
#define USB_SEP_CTRL_EPDATASEQ_Pos                         2
#define USB_SEP_CTRL_EPSSTALL_Pos                          3
#define USB_SEP_CTRL_EPISOEN_Pos                           4

/* Bit field masks: */
#define USB_SEP_CTRL_EPEN                                  ((uint32_t)0x00000001)
#define USB_SEP_CTRL_EPRDY                                 ((uint32_t)0x00000002)
#define USB_SEP_CTRL_EPDATASEQ                             ((uint32_t)0x00000004)
#define USB_SEP_CTRL_EPSSTALL                              ((uint32_t)0x00000008)
#define USB_SEP_CTRL_EPISOEN                               ((uint32_t)0x00000010)

/** @} */ /* End of group USB_SEP_CTRL */

/** @defgroup Periph_USB_SEP_STS USB SEP_STS
  * @{
  */

/*-- USB_SEP_STS:USB SEP_STS Register -----*/

/* Bit field positions: */
#define USB_SEP_STS_SCCRCERR_Pos                           0
#define USB_SEP_STS_SCBSERR_Pos                            1
#define USB_SEP_STS_SCRXOF_Pos                             2
#define USB_SEP_STS_SCRXTO_Pos                             3
#define USB_SEP_STS_SCNAKSENT_Pos                          4
#define USB_SEP_STS_SCSTALLSENT_Pos                        5
#define USB_SEP_STS_SCACKRXED_Pos                          6
#define USB_SEP_STS_SCDATASEQ_Pos                          7

/* Bit field masks: */
#define USB_SEP_STS_SCCRCERR                               ((uint32_t)0x00000001)
#define USB_SEP_STS_SCBSERR                                ((uint32_t)0x00000002)
#define USB_SEP_STS_SCRXOF                                 ((uint32_t)0x00000004)
#define USB_SEP_STS_SCRXTO                                 ((uint32_t)0x00000008)
#define USB_SEP_STS_SCNAKSENT                              ((uint32_t)0x00000010)
#define USB_SEP_STS_SCSTALLSENT                            ((uint32_t)0x00000020)
#define USB_SEP_STS_SCACKRXED                              ((uint32_t)0x00000040)
#define USB_SEP_STS_SCDATASEQ                              ((uint32_t)0x00000080)

/** @} */ /* End of group USB_SEP_STS */

/** @defgroup Periph_USB_SEP_TS USB SEP_TS
  * @{
  */

/*-- USB_SEP_TS:USB SEP_TS Register -----*/

/* Bit field positions: */
#define USB_SEP_TS_SCTTYPE_Pos                             0

/* Bit field masks: */
#define USB_SEP_TS_SCTTYPE_Msk                             ((uint32_t)0x00000003)

/** @} */ /* End of group USB_SEP_TS */

/** @defgroup Periph_USB_SEP_NTS USB SEP_NTS
  * @{
  */

/*-- USB_SEP_NTS:USB SEP_NTS Register -----*/

/* Bit field positions: */
#define USB_SEP_NTS_NTTYPE_Pos                             0

/* Bit field masks: */
#define USB_SEP_NTS_NTTYPE_Msk                             ((uint32_t)0x00000003)

/** @} */ /* End of group USB_SEP_NTS */

/** @defgroup Periph_USB_SC USB SC
  * @{
  */

/*-- USB_SC:USB SC Register -----*/

/* Bit field positions: */
#define USB_SCGEN_Pos                                   0
#define USB_SCTXLS_Pos                                  1
#define USB_SCDC_Pos                                    3
#define USB_SCFSP_Pos                                   4
#define USB_SCFSR_Pos                                   5

/* Bit field masks: */
#define USB_SCGEN                                       ((uint32_t)0x00000001)
#define USB_SCTXLS_Msk                                  ((uint32_t)0x00000006)
#define USB_SCDC                                        ((uint32_t)0x00000008)
#define USB_SCFSP                                       ((uint32_t)0x00000010)
#define USB_SCFSR                                       ((uint32_t)0x00000020)

/** @} */ /* End of group USB_SC */

/** @defgroup Periph_USB_SLS USB SLS
  * @{
  */

/*-- USB_SLS:USB SLS Register -----*/

/* Bit field positions: */
#define USB_SLS_SCRXLS_Pos                                 0

/* Bit field masks: */
#define USB_SLS_SCRXLS_Msk                                 ((uint32_t)0x00000003)

/** @} */ /* End of group USB_SLS */

/** @defgroup Periph_USB_SIS USB SIS
  * @{
  */

/*-- USB_SIS:USB SIS Register -----*/

/* Bit field positions: */
#define USB_SIS_SCTDONE_Pos                                0
#define USB_SIS_SCRESUME_Pos                               1
#define USB_SIS_SCRESETEV_Pos                              2
#define USB_SIS_SCSOFREC_Pos                               3
#define USB_SIS_SCNAKSENT_Pos                              4
#define USB_SIS_SCUSBON_Pos                                5

/* Bit field masks: */
#define USB_SIS_SCTDONE                                    ((uint32_t)0x00000001)
#define USB_SIS_SCRESUME                                   ((uint32_t)0x00000002)
#define USB_SIS_SCRESETEV                                  ((uint32_t)0x00000004)
#define USB_SIS_SCSOFREC                                   ((uint32_t)0x00000008)
#define USB_SIS_SCNAKSENT                                  ((uint32_t)0x00000010)
#define USB_SIS_SCUSBON                                    ((uint32_t)0x00000020)

/** @} */ /* End of group USB_SIS */

/** @defgroup Periph_USB_SIM USB SIM
  * @{
  */

/*-- USB_SIM:USB SIM Register -----*/

/* Bit field positions: */
#define USB_SIM_SCTDONEIE_Pos                              0
#define USB_SIM_SCRESUMEIE_Pos                             1
#define USB_SIM_SCRESETEVIE_Pos                            2
#define USB_SIM_SCSOFRECIE_Pos                             3
#define USB_SIM_SCNAKSENTIE_Pos                            4

/* Bit field masks: */
#define USB_SIM_SCTDONEIE                                  ((uint32_t)0x00000001)
#define USB_SIM_SCRESUMEIE                                 ((uint32_t)0x00000002)
#define USB_SIM_SCRESETEVIE                                ((uint32_t)0x00000004)
#define USB_SIM_SCSOFRECIE                                 ((uint32_t)0x00000008)
#define USB_SIM_SCNAKSENTIE                                ((uint32_t)0x00000010)

/** @} */ /* End of group USB_SIM */

/** @defgroup Periph_USB_SA USB SA
  * @{
  */

/*-- USB_SA:USB SA Register -----*/

/* Bit field positions: */
#define USB_SA_SCDEVADDR_Pos                               0

/* Bit field masks: */
#define USB_SA_SCDEVADDR_Msk                               ((uint32_t)0x0000007F)

/** @} */ /* End of group USB_SA */

/** @defgroup Periph_USB_SFN_L USB SFN_L
  * @{
  */

/*-- USB_SFN_L:USB SFN_L Register -----*/

/* Bit field positions: */
#define USB_SFN_L_FRAMENUM_Pos                             0

/* Bit field masks: */
#define USB_SFN_L_FRAMENUM_Msk                             ((uint32_t)0x000000FF)

/** @} */ /* End of group USB_SFN_L */

/** @defgroup Periph_USB_SFN_H USB SFN_H
  * @{
  */

/*-- USB_SFN_H:USB SFN_H Register -----*/

/* Bit field positions: */
#define USB_SFN_H_FRAMENUM_Pos                             0

/* Bit field masks: */
#define USB_SFN_H_FRAMENUM_Msk                             ((uint32_t)0x00000007)

/** @} */ /* End of group USB_SFN_H */

/** @defgroup Periph_USB_SEP_FIFO_RXFD USB SEP_FIFO_RXFD
  * @{
  */

/*-- USB_SEP_FIFO_RXFD:USB SEP_FIFO_RXFD Register -----*/

/* Bit field positions: */
#define USB_SEP_FIFO_RXFD_RXFIFODATA_Pos                   0

/* Bit field masks: */
#define USB_SEP_FIFO_RXFD_RXFIFODATA_Msk                   ((uint32_t)0x000000FF)

/** @} */ /* End of group USB_SEP_FIFO_RXFD */

/** @defgroup Periph_USB_SEP_FIFO_RXFDC_L USB SEP_FIFO_RXFDC_L
  * @{
  */

/*-- USB_SEP_FIFO_RXFDC_L:USB SEP_FIFO_RXFDC_L Register -----*/

/* Bit field positions: */
#define USB_SEP_FIFO_RXFDC_L_FIFODATACOUNT_Pos             0

/* Bit field masks: */
#define USB_SEP_FIFO_RXFDC_L_FIFODATACOUNT_Msk             ((uint32_t)0x000000FF)

/** @} */ /* End of group USB_SEP_FIFO_RXFDC_L */

/** @defgroup Periph_USB_SEP_FIFO_RXFDC_H USB SEP_FIFO_RXFDC_H
  * @{
  */

/*-- USB_SEP_FIFO_RXFDC_H:USB SEP_FIFO_RXFDC_H Register -----*/

/* Bit field positions: */
#define USB_SEP_FIFO_RXFDC_H_FIFODATACOUNT_Pos             0

/* Bit field masks: */
#define USB_SEP_FIFO_RXFDC_H_FIFODATACOUNT_Msk             ((uint32_t)0x000000FF)

/** @} */ /* End of group USB_SEP_FIFO_RXFDC_H */

/** @defgroup Periph_USB_SEP_FIFO_RXFC USB SEP_FIFO_RXFC
  * @{
  */

/*-- USB_SEP_FIFO_RXFC:USB SEP_FIFO_RXFC Register -----*/

/* Bit field positions: */
#define USB_SEP_FIFO_RXFC_FIFOFORCEEMPTY_Pos               0

/* Bit field masks: */
#define USB_SEP_FIFO_RXFC_FIFOFORCEEMPTY                   ((uint32_t)0x00000001)

/** @} */ /* End of group USB_SEP_FIFO_RXFC */

/** @defgroup Periph_USB_SEP_FIFO_TXFD USB SEP_FIFO_TXFD
  * @{
  */

/*-- USB_SEP_FIFO_TXFD:USB SEP_FIFO_TXFD Register -----*/

/* Bit field positions: */
#define USB_SEP_FIFO_TXFD_TXFIFODATA_Pos                   0

/* Bit field masks: */
#define USB_SEP_FIFO_TXFD_TXFIFODATA_Msk                   ((uint32_t)0x000000FF)

/** @} */ /* End of group USB_SEP_FIFO_TXFD */

/** @defgroup Periph_USB_SEP_FIFO_TXFDC USB SEP_FIFO_TXFDC
  * @{
  */

/*-- USB_SEP_FIFO_TXFDC:USB SEP_FIFO_TXFDC Register -----*/

/* Bit field positions: */
#define USB_SEP_FIFO_TXFDC_FIFOFORCEEMPTY_Pos              0

/* Bit field masks: */
#define USB_SEP_FIFO_TXFDC_FIFOFORCEEMPTY                  ((uint32_t)0x00000001)

/** @} */ /* End of group USB_SEP_FIFO_TXFDC */

/** @defgroup Periph_USB_HSCR USB HSCR
  * @{
  */

/*-- USB_HSCR:USB HSCR Register -----*/

/* Bit field positions: */
#define USB_HSCR_HOST_MODE_Pos                             0
#define USB_HSCR_RESET_CORE_Pos                            1
#define USB_HSCR_EN_TX_Pos                                 2
#define USB_HSCR_EN_RX_Pos                                 3
#define USB_HSCR_DP_PULLUP_Pos                             4
#define USB_HSCR_DP_PULLDOWN_Pos                           5
#define USB_HSCR_DM_PULLUP_Pos                             6
#define USB_HSCR_DM_PULLDOWN_Pos                           7

/* Bit field masks: */
#define USB_HSCR_HOST_MODE                                 ((uint32_t)0x00000001)
#define USB_HSCR_RESET_CORE                                ((uint32_t)0x00000002)
#define USB_HSCR_EN_TX                                     ((uint32_t)0x00000004)
#define USB_HSCR_EN_RX                                     ((uint32_t)0x00000008)
#define USB_HSCR_DP_PULLUP                                 ((uint32_t)0x00000010)
#define USB_HSCR_DP_PULLDOWN                               ((uint32_t)0x00000020)
#define USB_HSCR_DM_PULLUP                                 ((uint32_t)0x00000040)
#define USB_HSCR_DM_PULLDOWN                               ((uint32_t)0x00000080)

/** @} */ /* End of group USB_HSCR */

/** @defgroup Periph_USB_HSVR USB HSVR
  * @{
  */

/*-- USB_HSVR:USB HSVR Register -----*/

/* Bit field positions: */
#define USB_HSVR_VERSION_Pos                               0
#define USB_HSVR_REVISION_Pos                              4

/* Bit field masks: */
#define USB_HSVR_VERSION_Msk                               ((uint32_t)0x0000000F)
#define USB_HSVR_REVISION_Msk                              ((uint32_t)0x000000F0)

/** @} */ /* End of group USB_HSVR */

/** @} */ /* End of group USB */

/** @defgroup MDR1901VC1T_Periph_EEPROM EEPROM
  * @{
  */


/* MDR_EEPROM_TypeDef structure */
typedef struct {
	__IO uint32_t	CMD;                    /*!<EEPROM Command Register */
	__IO uint32_t	ADR;                    /*!<EEPROM Address Register */
	__IO uint32_t	DI;                     /*!<EEPROM Read Data Register */
	__IO uint32_t	DO;                     /*!<EEPROM Write Data Register */
	__IO uint32_t	KEY;                    /*!<EEPROM Key Register */
	__IO uint32_t	CTRL;                   /*!< */
}MDR_EEPROM_TypeDef;

/** @defgroup Periph_EEPROM_CMD EEPROM CMD
  * @{
  */

/*-- EEPROM_CMD:EEPROM CMD Register -----*/

/* Bit field positions: */
#define EEPROM_CMD_CON_Pos                                 0
#define EEPROM_CMD_WR_Pos                                  1
#define EEPROM_CMD_RD_Pos                                  2
#define EEPROM_CMD_DELAY_Pos                               3
#define EEPROM_CMD_XE_Pos                                  6
#define EEPROM_CMD_YE_Pos                                  7
#define EEPROM_CMD_SE_Pos                                  8
#define EEPROM_CMD_IFREN_Pos                               9
#define EEPROM_CMD_ERASE_Pos                               10
#define EEPROM_CMD_MAS1_Pos                                11
#define EEPROM_CMD_PROG_Pos                                12
#define EEPROM_CMD_NVSTR_Pos                               13

/* Bit field masks: */
#define EEPROM_CMD_CON                                     ((uint32_t)0x00000001)
#define EEPROM_CMD_WR                                      ((uint32_t)0x00000002)
#define EEPROM_CMD_RD                                      ((uint32_t)0x00000004)
#define EEPROM_CMD_DELAY_Msk                               ((uint32_t)0x00000038)
#define EEPROM_CMD_XE                                      ((uint32_t)0x00000040)
#define EEPROM_CMD_YE                                      ((uint32_t)0x00000080)
#define EEPROM_CMD_SE                                      ((uint32_t)0x00000100)
#define EEPROM_CMD_IFREN                                   ((uint32_t)0x00000200)
#define EEPROM_CMD_ERASE                                   ((uint32_t)0x00000400)
#define EEPROM_CMD_MAS1                                    ((uint32_t)0x00000800)
#define EEPROM_CMD_PROG                                    ((uint32_t)0x00001000)
#define EEPROM_CMD_NVSTR                                   ((uint32_t)0x00002000)

/** @} */ /* End of group EEPROM_CMD */

/** @defgroup Periph_EEPROM_ADR EEPROM ADR
  * @{
  */

/*-- EEPROM_ADR:EEPROM ADR Register -----*/

/* Bit field positions: */
#define EEPROM_ADR_ADR_Pos                                 0

/* Bit field masks: */
#define EEPROM_ADR_ADR_Msk                                 ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group EEPROM_ADR */

/** @defgroup Periph_EEPROM_DI EEPROM DI
  * @{
  */

/*-- EEPROM_DI:EEPROM DI Register -----*/

/* Bit field positions: */
#define EEPROM_DI_DATA_Pos                                 0

/* Bit field masks: */
#define EEPROM_DI_DATA_Msk                                 ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group EEPROM_DI */

/** @defgroup Periph_EEPROM_DO EEPROM DO
  * @{
  */

/*-- EEPROM_DO:EEPROM DO Register -----*/

/* Bit field positions: */
#define EEPROM_DO_DATA_Pos                                 0

/* Bit field masks: */
#define EEPROM_DO_DATA_Msk                                 ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group EEPROM_DO */

/** @defgroup Periph_EEPROM_KEY EEPROM KEY
  * @{
  */

/*-- EEPROM_KEY:EEPROM KEY Register -----*/

/* Bit field positions: */
#define EEPROM_KEY_KEY_Pos                                 0

/* Bit field masks: */
#define EEPROM_KEY_KEY_Msk                                 ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group EEPROM_KEY */

/** @defgroup Periph_EEPROM_CTRL EEPROM CTRL
  * @{
  */

/*-- EEPROM_CTRL:EEPROM CTRL Register -----*/

/* Bit field positions: */
#define EEPROM_CTRL_ICEN_Pos                               0
#define EEPROM_CTRL_DCEN_Pos                               1

/* Bit field masks: */
#define EEPROM_CTRL_ICEN                                   ((uint32_t)0x00000001)
#define EEPROM_CTRL_DCEN                                   ((uint32_t)0x00000002)

/** @} */ /* End of group EEPROM_CTRL */

/** @} */ /* End of group EEPROM */

/** @defgroup MDR1901VC1T_Periph_RST_CLK RST_CLK
  * @{
  */


/* MDR_RST_CLK_TypeDef structure */
typedef struct {
	__IO uint32_t	CLOCK_STATUS;           /*!<Clock Status Register */
	__IO uint32_t	PLL_CONTROL;            /*!<PLL Control Register */
	__IO uint32_t	HS_CONTROL;             /*!<HS Control Register */
	__IO uint32_t	CPU_CLOCK;              /*!<CPU Clock Register */
	__IO uint32_t	USB_CLOCK;              /*!<USB Clock Register */
	__IO uint32_t	ADC_MCO_CLOCK;          /*!<ADC Clock Register */
	__IO uint32_t	RTC_CLOCK;              /*!<RTC Clock Register */
	__IO uint32_t	PER_CLOCK;              /*!<Peripheral Clock Enable Register */
	__I  uint32_t	RESERVED0;
	__IO uint32_t	TIM_CLOCK;              /*!<Timer Clock Register */
	__IO uint32_t	UART_CLOCK;             /*!<UART Clock Register */
	__IO uint32_t	SSP_CLOCK;              /*!<SSP Clock Register */
	__IO uint32_t	DSP_CLOCK;              /*!<DSP Clock Register */
	__IO uint32_t	SPP2_CLOCK;             /*!<SSP2 Control Status Register */
	__IO uint32_t	DSP_CONTROL_STATUS;     /*!<DSP and SSP2 Clock Register */
}MDR_RST_CLK_TypeDef;

/** @defgroup Periph_RST_CLK_CLOCK_STATUS RST_CLK CLOCK_STATUS
  * @{
  */

/*-- RST_CLK_CLOCK_STATUS:RST_CLK CLOCK_STATUS Register -----*/

/* Bit field positions: */
#define RST_CLK_CLOCK_STATUS_PLL_USB_RDY_Pos               0
#define RST_CLK_CLOCK_STATUS_PLL_CPU_RDY_Pos               1
#define RST_CLK_CLOCK_STATUS_HSE_RDY_Pos                   2
#define RST_CLK_CLOCK_STATUS_PLL_DSP_RDY_Pos               3

/* Bit field masks: */
#define RST_CLK_CLOCK_STATUS_PLL_USB_RDY                   ((uint32_t)0x00000001)
#define RST_CLK_CLOCK_STATUS_PLL_CPU_RDY                   ((uint32_t)0x00000002)
#define RST_CLK_CLOCK_STATUS_HSE_RDY                       ((uint32_t)0x00000004)
#define RST_CLK_CLOCK_STATUS_PLL_DSP_RDY                   ((uint32_t)0x00000008)

/** @} */ /* End of group RST_CLK_CLOCK_STATUS */

/** @defgroup Periph_RST_CLK_PLL_CONTROL RST_CLK PLL_CONTROL
  * @{
  */

/*-- RST_CLK_PLL_CONTROL:RST_CLK PLL_CONTROL Register -----*/

/* Bit field positions: */
#define RST_CLK_PLL_CONTROL_PLL_USB_ON_Pos                 0
#define RST_CLK_PLL_CONTROL_PLL_USB_RLD_Pos                1
#define RST_CLK_PLL_CONTROL_PLL_CPU_ON_Pos                 2
#define RST_CLK_PLL_CONTROL_PLL_CPU_PLD_Pos                3
#define RST_CLK_PLL_CONTROL_PLL_USB_MUL_Pos                4
#define RST_CLK_PLL_CONTROL_PLL_CPU_MUL_Pos                8
#define RST_CLK_PLL_CONTROL_PLL_DSP_ON_Pos                 16
#define RST_CLK_PLL_CONTROL_PLL_DSP_PLD_Pos                17
#define RST_CLK_PLL_CONTROL_PLL_DSP_MUL_Pos                20

/* Bit field masks: */
#define RST_CLK_PLL_CONTROL_PLL_USB_ON                     ((uint32_t)0x00000001)
#define RST_CLK_PLL_CONTROL_PLL_USB_RLD                    ((uint32_t)0x00000002)
#define RST_CLK_PLL_CONTROL_PLL_CPU_ON                     ((uint32_t)0x00000004)
#define RST_CLK_PLL_CONTROL_PLL_CPU_PLD                    ((uint32_t)0x00000008)
#define RST_CLK_PLL_CONTROL_PLL_USB_MUL_Msk                ((uint32_t)0x000000F0)
#define RST_CLK_PLL_CONTROL_PLL_CPU_MUL_Msk                ((uint32_t)0x00000F00)
#define RST_CLK_PLL_CONTROL_PLL_DSP_ON                     ((uint32_t)0x00010000)
#define RST_CLK_PLL_CONTROL_PLL_DSP_PLD                    ((uint32_t)0x00020000)
#define RST_CLK_PLL_CONTROL_PLL_DSP_MUL_Msk                ((uint32_t)0x00F00000)

/** @} */ /* End of group RST_CLK_PLL_CONTROL */

/** @defgroup Periph_RST_CLK_HS_CONTROL RST_CLK HS_CONTROL
  * @{
  */

/*-- RST_CLK_HS_CONTROL:RST_CLK HS_CONTROL Register -----*/

/* Bit field positions: */
#define RST_CLK_HS_CONTROL_HSE_ON_Pos                      0
#define RST_CLK_HS_CONTROL_HSE_BYP_Pos                     1

/* Bit field masks: */
#define RST_CLK_HS_CONTROL_HSE_ON                          ((uint32_t)0x00000001)
#define RST_CLK_HS_CONTROL_HSE_BYP                         ((uint32_t)0x00000002)

/** @} */ /* End of group RST_CLK_HS_CONTROL */

/** @defgroup Periph_RST_CLK_CPU_CLOCK RST_CLK CPU_CLOCK
  * @{
  */

/*-- RST_CLK_CPU_CLOCK:RST_CLK CPU_CLOCK Register -----*/

/* Bit field positions: */
#define RST_CLK_CPU_CLOCK_CPU_C1_SEL_Pos                   0
#define RST_CLK_CPU_CLOCK_CPU_C2_SEL_Pos                   2
#define RST_CLK_CPU_CLOCK_CPU_C3_SEL_Pos                   4
#define RST_CLK_CPU_CLOCK_HCLK_SEL_Pos                     8

/* Bit field masks: */
#define RST_CLK_CPU_CLOCK_CPU_C1_SEL_Msk                   ((uint32_t)0x00000003)
#define RST_CLK_CPU_CLOCK_CPU_C2_SEL                       ((uint32_t)0x00000004)
#define RST_CLK_CPU_CLOCK_CPU_C3_SEL_Msk                   ((uint32_t)0x000000F0)
#define RST_CLK_CPU_CLOCK_HCLK_SEL_Msk                     ((uint32_t)0x00000300)

/** @} */ /* End of group RST_CLK_CPU_CLOCK */

/** @defgroup Periph_RST_CLK_USB_CLOCK RST_CLK USB_CLOCK
  * @{
  */

/*-- RST_CLK_USB_CLOCK:RST_CLK USB_CLOCK Register -----*/

/* Bit field positions: */
#define RST_CLK_USB_CLOCK_USB_C1_SEL_Pos                   0
#define RST_CLK_USB_CLOCK_USB_C2_SEL_Pos                   2
#define RST_CLK_USB_CLOCK_USB_C3_SEL_Pos                   4
#define RST_CLK_USB_CLOCK_USB_CLK_EN_Pos                   8

/* Bit field masks: */
#define RST_CLK_USB_CLOCK_USB_C1_SEL_Msk                   ((uint32_t)0x00000003)
#define RST_CLK_USB_CLOCK_USB_C2_SEL                       ((uint32_t)0x00000004)
#define RST_CLK_USB_CLOCK_USB_C3_SEL                       ((uint32_t)0x00000010)
#define RST_CLK_USB_CLOCK_USB_CLK_EN                       ((uint32_t)0x00000100)

/** @} */ /* End of group RST_CLK_USB_CLOCK */

/** @defgroup Periph_RST_CLK_ADC_MCO_CLOCK RST_CLK ADC_MCO_CLOCK
  * @{
  */

/*-- RST_CLK_ADC_MCO_CLOCK:RST_CLK ADC_MCO_CLOCK Register -----*/

/* Bit field positions: */
#define RST_CLK_ADC_MCO_CLOCK_ADC_C1_SEL_Pos               0
#define RST_CLK_ADC_MCO_CLOCK_ADC_C2_SEL_Pos               4
#define RST_CLK_ADC_MCO_CLOCK_ADC_C3_SEL_Pos               8
#define RST_CLK_ADC_MCO_CLOCK_MCO_EN_Pos                   12
#define RST_CLK_ADC_MCO_CLOCK_ADC_CLK_EN_Pos               13
#define RST_CLK_ADC_MCO_CLOCK_AUC_C1_SEL_Pos               16
#define RST_CLK_ADC_MCO_CLOCK_AUC_C2_SEL_Pos               20
#define RST_CLK_ADC_MCO_CLOCK_AUC_C3_SEL_Pos               24
#define RST_CLK_ADC_MCO_CLOCK_AUC_CLK_EN_Pos               31

/* Bit field masks: */
#define RST_CLK_ADC_MCO_CLOCK_ADC_C1_SEL_Msk               ((uint32_t)0x00000003)
#define RST_CLK_ADC_MCO_CLOCK_ADC_C2_SEL_Msk               ((uint32_t)0x00000030)
#define RST_CLK_ADC_MCO_CLOCK_ADC_C3_SEL_Msk               ((uint32_t)0x00000F00)
#define RST_CLK_ADC_MCO_CLOCK_MCO_EN                       ((uint32_t)0x00001000)
#define RST_CLK_ADC_MCO_CLOCK_ADC_CLK_EN                   ((uint32_t)0x00002000)
#define RST_CLK_ADC_MCO_CLOCK_AUC_C1_SEL_Msk               ((uint32_t)0x00030000)
#define RST_CLK_ADC_MCO_CLOCK_AUC_C2_SEL_Msk               ((uint32_t)0x00300000)
#define RST_CLK_ADC_MCO_CLOCK_AUC_C3_SEL_Msk               ((uint32_t)0x0F000000)
#define RST_CLK_ADC_MCO_CLOCK_AUC_CLK_EN                   ((uint32_t)0x80000000)

/** @} */ /* End of group RST_CLK_ADC_MCO_CLOCK */

/** @defgroup Periph_RST_CLK_RTC_CLOCK RST_CLK RTC_CLOCK
  * @{
  */

/*-- RST_CLK_RTC_CLOCK:RST_CLK RTC_CLOCK Register -----*/

/* Bit field positions: */
#define RST_CLK_RTC_CLOCK_HSE_SEL_Pos                      0
#define RST_CLK_RTC_CLOCK_HSI_SEL_Pos                      4
#define RST_CLK_RTC_CLOCK_HSE_RTC_EN_Pos                   8
#define RST_CLK_RTC_CLOCK_HSI_RTC_EN_Pos                   9

/* Bit field masks: */
#define RST_CLK_RTC_CLOCK_HSE_SEL_Msk                      ((uint32_t)0x0000000F)
#define RST_CLK_RTC_CLOCK_HSI_SEL_Msk                      ((uint32_t)0x000000F0)
#define RST_CLK_RTC_CLOCK_HSE_RTC_EN                       ((uint32_t)0x00000100)
#define RST_CLK_RTC_CLOCK_HSI_RTC_EN                       ((uint32_t)0x00000200)

/** @} */ /* End of group RST_CLK_RTC_CLOCK */

/** @defgroup Periph_RST_CLK_PER_CLOCK RST_CLK PER_CLOCK
  * @{
  */

/*-- RST_CLK_PER_CLOCK:RST_CLK PER_CLOCK Register -----*/

/* Bit field positions: */
#define RST_CLK_PER_CLOCK_PCLK_EN_Pos                      0

/* Bit field masks: */
#define RST_CLK_PER_CLOCK_PCLK_EN_Msk                      ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group RST_CLK_PER_CLOCK */

/** @defgroup Periph_RST_CLK_TIM_CLOCK RST_CLK TIM_CLOCK
  * @{
  */

/*-- RST_CLK_TIM_CLOCK:RST_CLK TIM_CLOCK Register -----*/

/* Bit field positions: */
#define RST_CLK_TIM_CLOCK_TIM1_BRG_Pos                     0
#define RST_CLK_TIM_CLOCK_TIM2_BRG_Pos                     8
#define RST_CLK_TIM_CLOCK_TIM3_BRG_Pos                     16
#define RST_CLK_TIM_CLOCK_TIM1_CLK_EN_Pos                  24
#define RST_CLK_TIM_CLOCK_TIM2_CLK_EN_Pos                  25
#define RST_CLK_TIM_CLOCK_TIM3_CLK_EN_Pos                  26

/* Bit field masks: */
#define RST_CLK_TIM_CLOCK_TIM1_BRG_Msk                     ((uint32_t)0x000000FF)
#define RST_CLK_TIM_CLOCK_TIM2_BRG_Msk                     ((uint32_t)0x0000FF00)
#define RST_CLK_TIM_CLOCK_TIM3_BRG_Msk                     ((uint32_t)0x00FF0000)
#define RST_CLK_TIM_CLOCK_TIM1_CLK_EN                      ((uint32_t)0x01000000)
#define RST_CLK_TIM_CLOCK_TIM2_CLK_EN                      ((uint32_t)0x02000000)
#define RST_CLK_TIM_CLOCK_TIM3_CLK_EN                      ((uint32_t)0x04000000)

/** @} */ /* End of group RST_CLK_TIM_CLOCK */

/** @defgroup Periph_RST_CLK_UART_CLOCK RST_CLK UART_CLOCK
  * @{
  */

/*-- RST_CLK_UART_CLOCK:RST_CLK UART_CLOCK Register -----*/

/* Bit field positions: */
#define RST_CLK_UART_CLOCK_UART1_BRG_Pos                   0
#define RST_CLK_UART_CLOCK_UART2_BRG_Pos                   8
#define RST_CLK_UART_CLOCK_UART3_BRG_Pos                   16
#define RST_CLK_UART_CLOCK_UART1_CLK_EN_Pos                24
#define RST_CLK_UART_CLOCK_UART2_CLK_EN_Pos                25
#define RST_CLK_UART_CLOCK_UART3_CLK_EN_Pos                26

/* Bit field masks: */
#define RST_CLK_UART_CLOCK_UART1_BRG_Msk                   ((uint32_t)0x000000FF)
#define RST_CLK_UART_CLOCK_UART2_BRG_Msk                   ((uint32_t)0x0000FF00)
#define RST_CLK_UART_CLOCK_UART3_BRG_Msk                   ((uint32_t)0x00FF0000)
#define RST_CLK_UART_CLOCK_UART1_CLK_EN                    ((uint32_t)0x01000000)
#define RST_CLK_UART_CLOCK_UART2_CLK_EN                    ((uint32_t)0x02000000)
#define RST_CLK_UART_CLOCK_UART3_CLK_EN                    ((uint32_t)0x04000000)

/** @} */ /* End of group RST_CLK_UART_CLOCK */

/** @defgroup Periph_RST_CLK_SSP_CLOCK RST_CLK SSP_CLOCK
  * @{
  */

/*-- RST_CLK_SSP_CLOCK:RST_CLK SSP_CLOCK Register -----*/

/* Bit field positions: */
#define RST_CLK_SSP_CLOCK_SSP1_BRG_Pos                     0
#define RST_CLK_SSP_CLOCK_SSP2_BRG_Pos                     8
#define RST_CLK_SSP_CLOCK_SSP3_BRG_Pos                     16
#define RST_CLK_SSP_CLOCK_SSP1_CLK_EN_Pos                  24
#define RST_CLK_SSP_CLOCK_SSP2_CLK_EN_Pos                  25
#define RST_CLK_SSP_CLOCK_SSP3_CLK_EN_Pos                  26

/* Bit field masks: */
#define RST_CLK_SSP_CLOCK_SSP1_BRG_Msk                     ((uint32_t)0x000000FF)
#define RST_CLK_SSP_CLOCK_SSP2_BRG_Msk                     ((uint32_t)0x0000FF00)
#define RST_CLK_SSP_CLOCK_SSP3_BRG_Msk                     ((uint32_t)0x00FF0000)
#define RST_CLK_SSP_CLOCK_SSP1_CLK_EN                      ((uint32_t)0x01000000)
#define RST_CLK_SSP_CLOCK_SSP2_CLK_EN                      ((uint32_t)0x02000000)
#define RST_CLK_SSP_CLOCK_SSP3_CLK_EN                      ((uint32_t)0x04000000)

/** @} */ /* End of group RST_CLK_SSP_CLOCK */

/** @defgroup Periph_RST_CLK_DSP_CLOCK RST_CLK DSP_CLOCK
  * @{
  */

/*-- RST_CLK_DSP_CLOCK:RST_CLK DSP_CLOCK Register -----*/

/* Bit field positions: */
#define RST_CLK_DSP_CLOCK_DSP_C1_SEL_Pos                   0
#define RST_CLK_DSP_CLOCK_DSP_C2_SEL_Pos                   2
#define RST_CLK_DSP_CLOCK_DSP_C3_SEL_Pos                   4
#define RST_CLK_DSP_CLOCK_DSP_CLK_EN_Pos                   8

/* Bit field masks: */
#define RST_CLK_DSP_CLOCK_DSP_C1_SEL_Msk                   ((uint32_t)0x00000003)
#define RST_CLK_DSP_CLOCK_DSP_C2_SEL                       ((uint32_t)0x00000004)
#define RST_CLK_DSP_CLOCK_DSP_C3_SEL                       ((uint32_t)0x00000010)
#define RST_CLK_DSP_CLOCK_DSP_CLK_EN                       ((uint32_t)0x00000100)

/** @} */ /* End of group RST_CLK_DSP_CLOCK */

/** @defgroup Periph_RST_CLK_SPP2_CLOCK RST_CLK SPP2_CLOCK
  * @{
  */

/*-- RST_CLK_SPP2_CLOCK:RST_CLK SPP2_CLOCK Register -----*/

/* Bit field positions: */
#define RST_CLK_SPP2_CLOCK_SSP4_BRG_Pos                    0
#define RST_CLK_SPP2_CLOCK_SSP4_CLK_EN_Pos                 24

/* Bit field masks: */
#define RST_CLK_SPP2_CLOCK_SSP4_BRG_Msk                    ((uint32_t)0x000000FF)
#define RST_CLK_SPP2_CLOCK_SSP4_CLK_EN                     ((uint32_t)0x01000000)

/** @} */ /* End of group RST_CLK_SPP2_CLOCK */

/** @defgroup Periph_RST_CLK_DSP_CONTROL_STATUS RST_CLK DSP_CONTROL_STATUS
  * @{
  */

/*-- RST_CLK_DSP_CONTROL_STATUS:RST_CLK DSP_CONTROL_STATUS Register -----*/

/* Bit field positions: */
#define RST_CLK_DSP_CONTROL_STATUS_RST_DSP_Pos             0
#define RST_CLK_DSP_CONTROL_STATUS_RST_DSP_CPU_Pos         1
#define RST_CLK_DSP_CONTROL_STATUS_RST_DSP_MEM_Pos         2
#define RST_CLK_DSP_CONTROL_STATUS_RST_DSP_PER_Pos         3
#define RST_CLK_DSP_CONTROL_STATUS_HOLD_Pos                4
#define RST_CLK_DSP_CONTROL_STATUS_BIO_Pos                 5
#define RST_CLK_DSP_CONTROL_STATUS_XF_Pos                  8
#define RST_CLK_DSP_CONTROL_STATUS_HOLDA_Pos               9
#define RST_CLK_DSP_CONTROL_STATUS_IDLE_Pos                10
#define RST_CLK_DSP_CONTROL_STATUS_BRTRD_Pos               14
#define RST_CLK_DSP_CONTROL_STATUS_RD_BUFF_EN_Pos          15

/* Bit field masks: */
#define RST_CLK_DSP_CONTROL_STATUS_RST_DSP                 ((uint32_t)0x00000001)
#define RST_CLK_DSP_CONTROL_STATUS_RST_DSP_CPU             ((uint32_t)0x00000002)
#define RST_CLK_DSP_CONTROL_STATUS_RST_DSP_MEM             ((uint32_t)0x00000004)
#define RST_CLK_DSP_CONTROL_STATUS_RST_DSP_PER             ((uint32_t)0x00000008)
#define RST_CLK_DSP_CONTROL_STATUS_HOLD                    ((uint32_t)0x00000010)
#define RST_CLK_DSP_CONTROL_STATUS_BIO                     ((uint32_t)0x00000020)
#define RST_CLK_DSP_CONTROL_STATUS_XF                      ((uint32_t)0x00000100)
#define RST_CLK_DSP_CONTROL_STATUS_HOLDA                   ((uint32_t)0x00000200)
#define RST_CLK_DSP_CONTROL_STATUS_IDLE_Msk                ((uint32_t)0x00000C00)
#define RST_CLK_DSP_CONTROL_STATUS_BRTRD                   ((uint32_t)0x00004000)
#define RST_CLK_DSP_CONTROL_STATUS_RD_BUFF_EN              ((uint32_t)0x00008000)

/** @} */ /* End of group RST_CLK_DSP_CONTROL_STATUS */

/** @} */ /* End of group RST_CLK */

/** @defgroup MDR1901VC1T_Periph_DMA DMA
  * @{
  */


/* MDR_DMA_TypeDef structure */
typedef struct {
	__IO uint32_t	STATUS;                 /*!<DMA Status Register */
	__IO uint32_t	CFG;                    /*!<DMA Configuration Register */
	__IO uint32_t	CTRL_BASE_PTR;          /*!< */
	__IO uint32_t	ALT_CTRL_BASE_PTR;      /*!< */
	__IO uint32_t	WAITONREQ_STATUS;       /*!< */
	__IO uint32_t	CHNL_SW_REQUEST;        /*!< */
	__IO uint32_t	CHNL_USEBURST_SET;      /*!< */
	__IO uint32_t	CHNL_USEBURST_CLR;      /*!< */
	__IO uint32_t	CHNL_REQ_MASK_SET;      /*!< */
	__IO uint32_t	CHNL_REQ_MASK_CLR;      /*!< */
	__IO uint32_t	CHNL_ENABLE_SET;        /*!< */
	__IO uint32_t	CHNL_ENABLE_CLR;        /*!< */
	__IO uint32_t	CHNL_PRI_ALT_SET;       /*!< */
	__IO uint32_t	CHNL_PRI_ALT_CLR;       /*!< */
	__IO uint32_t	CHNL_PRIORITY_SET;      /*!< */
	__IO uint32_t	CHNL_PRIORITY_CLR;      /*!< */
	__I  uint32_t	RESERVED0[3];
	__IO uint32_t	ERR_CLR;                /*!< */
}MDR_DMA_TypeDef;

/** @defgroup Periph_DMA_STATUS DMA STATUS
  * @{
  */

/*-- DMA_STATUS:DMA STATUS Register -----*/

/* Bit field positions: */
#define DMA_STATUS_MASTER_ENABLE_Pos                       0
#define DMA_STATUS_STATE_Pos                               4
#define DMA_STATUS_CHNLS_MINUS1_Pos                        16
#define DMA_STATUS_TEST_STATUS_Pos                         28

/* Bit field masks: */
#define DMA_STATUS_MASTER_ENABLE                           ((uint32_t)0x00000001)
#define DMA_STATUS_STATE_Msk                               ((uint32_t)0x000000F0)
#define DMA_STATUS_CHNLS_MINUS1_Msk                        ((uint32_t)0x001F0000)
#define DMA_STATUS_TEST_STATUS_Msk                         ((uint32_t)0xF0000000)

/** @} */ /* End of group DMA_STATUS */

/** @defgroup Periph_DMA_CFG DMA CFG
  * @{
  */

/*-- DMA_CFG:DMA CFG Register -----*/

/* Bit field positions: */
#define DMA_CFG_MASTER_ENABLE_Pos                          0
#define DMA_CFG_CHNL_PROT_CTRL_Pos                         5

/* Bit field masks: */
#define DMA_CFG_MASTER_ENABLE                              ((uint32_t)0x00000001)
#define DMA_CFG_CHNL_PROT_CTRL_Msk                         ((uint32_t)0x000000E0)

/** @} */ /* End of group DMA_CFG */

/** @defgroup Periph_DMA_CTRL_BASE_PTR DMA CTRL_BASE_PTR
  * @{
  */

/*-- DMA_CTRL_BASE_PTR:DMA CTRL_BASE_PTR Register -----*/

/* Bit field positions: */

/* Bit field masks: */

/** @} */ /* End of group DMA_CTRL_BASE_PTR */

/** @defgroup Periph_DMA_ALT_CTRL_BASE_PTR DMA ALT_CTRL_BASE_PTR
  * @{
  */

/*-- DMA_ALT_CTRL_BASE_PTR:DMA ALT_CTRL_BASE_PTR Register -----*/

/* Bit field positions: */

/* Bit field masks: */

/** @} */ /* End of group DMA_ALT_CTRL_BASE_PTR */

/** @defgroup Periph_DMA_WAITONREQ_STATUS DMA WAITONREQ_STATUS
  * @{
  */

/*-- DMA_WAITONREQ_STATUS:DMA WAITONREQ_STATUS Register -----*/

/* Bit field positions: */

/* Bit field masks: */

/** @} */ /* End of group DMA_WAITONREQ_STATUS */

/** @defgroup Periph_DMA_CHNL_SW_REQUEST DMA CHNL_SW_REQUEST
  * @{
  */

/*-- DMA_CHNL_SW_REQUEST:DMA CHNL_SW_REQUEST Register -----*/

/* Bit field positions: */

/* Bit field masks: */

/** @} */ /* End of group DMA_CHNL_SW_REQUEST */

/** @defgroup Periph_DMA_CHNL_USEBURST_SET DMA CHNL_USEBURST_SET
  * @{
  */

/*-- DMA_CHNL_USEBURST_SET:DMA CHNL_USEBURST_SET Register -----*/

/* Bit field positions: */

/* Bit field masks: */

/** @} */ /* End of group DMA_CHNL_USEBURST_SET */

/** @defgroup Periph_DMA_CHNL_USEBURST_CLR DMA CHNL_USEBURST_CLR
  * @{
  */

/*-- DMA_CHNL_USEBURST_CLR:DMA CHNL_USEBURST_CLR Register -----*/

/* Bit field positions: */

/* Bit field masks: */

/** @} */ /* End of group DMA_CHNL_USEBURST_CLR */

/** @defgroup Periph_DMA_CHNL_REQ_MASK_SET DMA CHNL_REQ_MASK_SET
  * @{
  */

/*-- DMA_CHNL_REQ_MASK_SET:DMA CHNL_REQ_MASK_SET Register -----*/

/* Bit field positions: */

/* Bit field masks: */

/** @} */ /* End of group DMA_CHNL_REQ_MASK_SET */

/** @defgroup Periph_DMA_CHNL_REQ_MASK_CLR DMA CHNL_REQ_MASK_CLR
  * @{
  */

/*-- DMA_CHNL_REQ_MASK_CLR:DMA CHNL_REQ_MASK_CLR Register -----*/

/* Bit field positions: */

/* Bit field masks: */

/** @} */ /* End of group DMA_CHNL_REQ_MASK_CLR */

/** @defgroup Periph_DMA_CHNL_ENABLE_SET DMA CHNL_ENABLE_SET
  * @{
  */

/*-- DMA_CHNL_ENABLE_SET:DMA CHNL_ENABLE_SET Register -----*/

/* Bit field positions: */

/* Bit field masks: */

/** @} */ /* End of group DMA_CHNL_ENABLE_SET */

/** @defgroup Periph_DMA_CHNL_ENABLE_CLR DMA CHNL_ENABLE_CLR
  * @{
  */

/*-- DMA_CHNL_ENABLE_CLR:DMA CHNL_ENABLE_CLR Register -----*/

/* Bit field positions: */

/* Bit field masks: */

/** @} */ /* End of group DMA_CHNL_ENABLE_CLR */

/** @defgroup Periph_DMA_CHNL_PRI_ALT_SET DMA CHNL_PRI_ALT_SET
  * @{
  */

/*-- DMA_CHNL_PRI_ALT_SET:DMA CHNL_PRI_ALT_SET Register -----*/

/* Bit field positions: */

/* Bit field masks: */

/** @} */ /* End of group DMA_CHNL_PRI_ALT_SET */

/** @defgroup Periph_DMA_CHNL_PRI_ALT_CLR DMA CHNL_PRI_ALT_CLR
  * @{
  */

/*-- DMA_CHNL_PRI_ALT_CLR:DMA CHNL_PRI_ALT_CLR Register -----*/

/* Bit field positions: */

/* Bit field masks: */

/** @} */ /* End of group DMA_CHNL_PRI_ALT_CLR */

/** @defgroup Periph_DMA_CHNL_PRIORITY_SET DMA CHNL_PRIORITY_SET
  * @{
  */

/*-- DMA_CHNL_PRIORITY_SET:DMA CHNL_PRIORITY_SET Register -----*/

/* Bit field positions: */

/* Bit field masks: */

/** @} */ /* End of group DMA_CHNL_PRIORITY_SET */

/** @defgroup Periph_DMA_CHNL_PRIORITY_CLR DMA CHNL_PRIORITY_CLR
  * @{
  */

/*-- DMA_CHNL_PRIORITY_CLR:DMA CHNL_PRIORITY_CLR Register -----*/

/* Bit field positions: */

/* Bit field masks: */

/** @} */ /* End of group DMA_CHNL_PRIORITY_CLR */

/** @defgroup Periph_DMA_ERR_CLR DMA ERR_CLR
  * @{
  */

/*-- DMA_ERR_CLR:DMA ERR_CLR Register -----*/

/* Bit field positions: */
#define DMA_ERR_CLR_ERR_CLR_Pos                            0

/* Bit field masks: */
#define DMA_ERR_CLR_ERR_CLR                                ((uint32_t)0x00000001)

/** @} */ /* End of group DMA_ERR_CLR */

/** @} */ /* End of group DMA */

/** @defgroup MDR1901VC1T_Periph_UART UART
  * @{
  */


/* MDR_UARTx_TypeDef structure */
typedef struct {
	__IO uint32_t	DR;                     /*!<UART Data Register */
	__IO uint32_t	RSR_ECR;                /*!<UART RSR Register */
	__I  uint32_t	RESERVED0[4];
	__IO uint32_t	FR;                     /*!<UART Flag Register */
	__I  uint32_t	RESERVED1;
	__IO uint32_t	ILPR;                   /*!< */
	__IO uint32_t	IBRD;                   /*!< */
	__IO uint32_t	FBRD;                   /*!< */
	__IO uint32_t	LCR_H;                  /*!<UART LCR_H Register */
	__IO uint32_t	CR;                     /*!<UART Command Register */
	__IO uint32_t	IFLS;                   /*!<UART IFLS Register */
	__IO uint32_t	IMSC;                   /*!<UART Interrupt Mask Register */
	__IO uint32_t	RIS;                    /*!<UART Interrupt Pending Register */
	__IO uint32_t	MIS;                    /*!<UART Masked Interrupt Pending Register */
	__IO uint32_t	ICR;                    /*!<UART Interrupt Clear Register */
	__IO uint32_t	DMACR;                  /*!<UART DMA Control Register */
}MDR_UART_TypeDef;

/** @defgroup Periph_UART_DR UART DR
  * @{
  */

/*-- UART_DR:UART DR Register -----*/

/* Bit field positions: */
#define UART_DR_DATA_Pos                                   0
#define UART_DR_FE_Pos                                     8
#define UART_DR_PE_Pos                                     9
#define UART_DR_BE_Pos                                     10
#define UART_DR_OE_Pos                                     11

/* Bit field masks: */
#define UART_DR_DATA_Msk                                   ((uint32_t)0x000000FF)
#define UART_DR_FE                                         ((uint32_t)0x00000100)
#define UART_DR_PE                                         ((uint32_t)0x00000200)
#define UART_DR_BE                                         ((uint32_t)0x00000400)
#define UART_DR_OE                                         ((uint32_t)0x00000800)

/** @} */ /* End of group UART_DR */

/** @defgroup Periph_UART_RSR_ECR UART RSR_ECR
  * @{
  */

/*-- UART_RSR_ECR:UART RSR_ECR Register -----*/

/* Bit field positions: */
#define UART_RSR_ECR_FE_Pos                                0
#define UART_RSR_ECR_PE_Pos                                1
#define UART_RSR_ECR_BE_Pos                                2
#define UART_RSR_ECR_OE_Pos                                3

/* Bit field masks: */
#define UART_RSR_ECR_FE                                    ((uint32_t)0x00000001)
#define UART_RSR_ECR_PE                                    ((uint32_t)0x00000002)
#define UART_RSR_ECR_BE                                    ((uint32_t)0x00000004)
#define UART_RSR_ECR_OE                                    ((uint32_t)0x00000008)

/** @} */ /* End of group UART_RSR_ECR */

/** @defgroup Periph_UART_FR UART FR
  * @{
  */

/*-- UART_FR:UART FR Register -----*/

/* Bit field positions: */
#define UART_FR_CTS_Pos                                    0
#define UART_FR_DSR_Pos                                    1
#define UART_FR_DCD_Pos                                    2
#define UART_FR_BUSY_Pos                                   3
#define UART_FR_RXFE_Pos                                   4
#define UART_FR_TXFF_Pos                                   5
#define UART_FR_RXFF_Pos                                   6
#define UART_FR_TXFE_Pos                                   7
#define UART_FR_RI_Pos                                     8

/* Bit field masks: */
#define UART_FR_CTS                                        ((uint32_t)0x00000001)
#define UART_FR_DSR                                        ((uint32_t)0x00000002)
#define UART_FR_DCD                                        ((uint32_t)0x00000004)
#define UART_FR_BUSY                                       ((uint32_t)0x00000008)
#define UART_FR_RXFE                                       ((uint32_t)0x00000010)
#define UART_FR_TXFF                                       ((uint32_t)0x00000020)
#define UART_FR_RXFF                                       ((uint32_t)0x00000040)
#define UART_FR_TXFE                                       ((uint32_t)0x00000080)
#define UART_FR_RI                                         ((uint32_t)0x00000100)

/** @} */ /* End of group UART_FR */

/** @defgroup Periph_UART_ILPR UART ILPR
  * @{
  */

/*-- UART_ILPR:UART ILPR Register -----*/

/* Bit field positions: */
#define UART_ILPR_ILPDVSR_Pos                              0

/* Bit field masks: */
#define UART_ILPR_ILPDVSR_Msk                              ((uint32_t)0x000000FF)

/** @} */ /* End of group UART_ILPR */

/** @defgroup Periph_UART_IBRD UART IBRD
  * @{
  */

/*-- UART_IBRD:UART IBRD Register -----*/

/* Bit field positions: */
#define UART_IBRD_BAUD_DIVINT_Pos                          0

/* Bit field masks: */
#define UART_IBRD_BAUD_DIVINT_Msk                          ((uint32_t)0x0000FFFF)

/** @} */ /* End of group UART_IBRD */

/** @defgroup Periph_UART_FBRD UART FBRD
  * @{
  */

/*-- UART_FBRD:UART FBRD Register -----*/

/* Bit field positions: */
#define UART_FBRD_BAUD_DIVFRAC_Pos                         0

/* Bit field masks: */
#define UART_FBRD_BAUD_DIVFRAC_Msk                         ((uint32_t)0x0000003F)

/** @} */ /* End of group UART_FBRD */

/** @defgroup Periph_UART_LCR_H UART LCR_H
  * @{
  */

/*-- UART_LCR_H:UART LCR_H Register -----*/

/* Bit field positions: */
#define UART_LCR_H_BRK_Pos                                 0
#define UART_LCR_H_PEN_Pos                                 1
#define UART_LCR_H_EPS_Pos                                 2
#define UART_LCR_H_STP2_Pos                                3
#define UART_LCR_H_FEN_Pos                                 4
#define UART_LCR_H_WLEN_Pos                                5
#define UART_LCR_H_SPS_Pos                                 7

/* Bit field masks: */
#define UART_LCR_H_BRK                                     ((uint32_t)0x00000001)
#define UART_LCR_H_PEN                                     ((uint32_t)0x00000002)
#define UART_LCR_H_EPS                                     ((uint32_t)0x00000004)
#define UART_LCR_H_STP2                                    ((uint32_t)0x00000008)
#define UART_LCR_H_FEN                                     ((uint32_t)0x00000010)
#define UART_LCR_H_WLEN_Msk                                ((uint32_t)0x00000060)
#define UART_LCR_H_SPS                                     ((uint32_t)0x00000080)

/** @} */ /* End of group UART_LCR_H */

/** @defgroup Periph_UART_CR UART CR
  * @{
  */

/*-- UART_CR:UART CR Register -----*/

/* Bit field positions: */
#define UART_CR_UARTEN_Pos                                 0
#define UART_CR_SIREN_Pos                                  1
#define UART_CR_SIRLP_Pos                                  2
#define UART_CR_LBE_Pos                                    7
#define UART_CR_TXE_Pos                                    8
#define UART_CR_RXE_Pos                                    9
#define UART_CR_DTR_Pos                                    10
#define UART_CR_RTS_Pos                                    11
#define UART_CR_OUT1_Pos                                   12
#define UART_CR_OUT2_Pos                                   13
#define UART_CR_RTSEN_Pos                                  14
#define UART_CR_CTSEN_Pos                                  15

/* Bit field masks: */
#define UART_CR_UARTEN                                     ((uint32_t)0x00000001)
#define UART_CR_SIREN                                      ((uint32_t)0x00000002)
#define UART_CR_SIRLP                                      ((uint32_t)0x00000004)
#define UART_CR_LBE                                        ((uint32_t)0x00000080)
#define UART_CR_TXE                                        ((uint32_t)0x00000100)
#define UART_CR_RXE                                        ((uint32_t)0x00000200)
#define UART_CR_DTR                                        ((uint32_t)0x00000400)
#define UART_CR_RTS                                        ((uint32_t)0x00000800)
#define UART_CR_OUT1                                       ((uint32_t)0x00001000)
#define UART_CR_OUT2                                       ((uint32_t)0x00002000)
#define UART_CR_RTSEN                                      ((uint32_t)0x00004000)
#define UART_CR_CTSEN                                      ((uint32_t)0x00008000)

/** @} */ /* End of group UART_CR */

/** @defgroup Periph_UART_IFLS UART IFLS
  * @{
  */

/*-- UART_IFLS:UART IFLS Register -----*/

/* Bit field positions: */
#define UART_IFLS_TXIFLSEL_Pos                             0
#define UART_IFLS_RXIFLSEL_Pos                             3

/* Bit field masks: */
#define UART_IFLS_TXIFLSEL_Msk                             ((uint32_t)0x00000007)
#define UART_IFLS_RXIFLSEL_Msk                             ((uint32_t)0x00000038)

/** @} */ /* End of group UART_IFLS */

/** @defgroup Periph_UART_IMSC UART IMSC
  * @{
  */

/*-- UART_IMSC:UART IMSC Register -----*/

/* Bit field positions: */
#define UART_IMSC_RIMIM_Pos                                0
#define UART_IMSC_CTSMIM_Pos                               1
#define UART_IMSC_DCDMIM_Pos                               2
#define UART_IMSC_DSRMIM_Pos                               3
#define UART_IMSC_RXIM_Pos                                 4
#define UART_IMSC_TXIM_Pos                                 5
#define UART_IMSC_RTIM_Pos                                 6
#define UART_IMSC_FEIM_Pos                                 7
#define UART_IMSC_PEIM_Pos                                 8
#define UART_IMSC_BEIM_Pos                                 9
#define UART_IMSC_OEIM_Pos                                 10

/* Bit field masks: */
#define UART_IMSC_RIMIM                                    ((uint32_t)0x00000001)
#define UART_IMSC_CTSMIM                                   ((uint32_t)0x00000002)
#define UART_IMSC_DCDMIM                                   ((uint32_t)0x00000004)
#define UART_IMSC_DSRMIM                                   ((uint32_t)0x00000008)
#define UART_IMSC_RXIM                                     ((uint32_t)0x00000010)
#define UART_IMSC_TXIM                                     ((uint32_t)0x00000020)
#define UART_IMSC_RTIM                                     ((uint32_t)0x00000040)
#define UART_IMSC_FEIM                                     ((uint32_t)0x00000080)
#define UART_IMSC_PEIM                                     ((uint32_t)0x00000100)
#define UART_IMSC_BEIM                                     ((uint32_t)0x00000200)
#define UART_IMSC_OEIM                                     ((uint32_t)0x00000400)

/** @} */ /* End of group UART_IMSC */

/** @defgroup Periph_UART_RIS UART RIS
  * @{
  */

/*-- UART_RIS:UART RIS Register -----*/

/* Bit field positions: */
#define UART_RIS_RIRMIS_Pos                                0
#define UART_RIS_CTSRMIS_Pos                               1
#define UART_RIS_DCDRMIS_Pos                               2
#define UART_RIS_DSRRMIS_Pos                               3
#define UART_RIS_RXRIS_Pos                                 4
#define UART_RIS_TXRIS_Pos                                 5
#define UART_RIS_RTRIS_Pos                                 6
#define UART_RIS_FERIS_Pos                                 7
#define UART_RIS_PERIS_Pos                                 8
#define UART_RIS_BERIS_Pos                                 9
#define UART_RIS_OERIS_Pos                                 10

/* Bit field masks: */
#define UART_RIS_RIRMIS                                    ((uint32_t)0x00000001)
#define UART_RIS_CTSRMIS                                   ((uint32_t)0x00000002)
#define UART_RIS_DCDRMIS                                   ((uint32_t)0x00000004)
#define UART_RIS_DSRRMIS                                   ((uint32_t)0x00000008)
#define UART_RIS_RXRIS                                     ((uint32_t)0x00000010)
#define UART_RIS_TXRIS                                     ((uint32_t)0x00000020)
#define UART_RIS_RTRIS                                     ((uint32_t)0x00000040)
#define UART_RIS_FERIS                                     ((uint32_t)0x00000080)
#define UART_RIS_PERIS                                     ((uint32_t)0x00000100)
#define UART_RIS_BERIS                                     ((uint32_t)0x00000200)
#define UART_RIS_OERIS                                     ((uint32_t)0x00000400)

/** @} */ /* End of group UART_RIS */

/** @defgroup Periph_UART_MIS UART MIS
  * @{
  */

/*-- UART_MIS:UART MIS Register -----*/

/* Bit field positions: */
#define UART_MIS_RIMMIS_Pos                                0
#define UART_MIS_CTSMMIS_Pos                               1
#define UART_MIS_DCDMMIS_Pos                               2
#define UART_MIS_DSRMMIS_Pos                               3
#define UART_MIS_RXMIS_Pos                                 4
#define UART_MIS_TXMIS_Pos                                 5
#define UART_MIS_RTMIS_Pos                                 6
#define UART_MIS_FEMIS_Pos                                 7
#define UART_MIS_PEMIS_Pos                                 8
#define UART_MIS_BEMIS_Pos                                 9
#define UART_MIS_OEMIS_Pos                                 10

/* Bit field masks: */
#define UART_MIS_RIMMIS                                    ((uint32_t)0x00000001)
#define UART_MIS_CTSMMIS                                   ((uint32_t)0x00000002)
#define UART_MIS_DCDMMIS                                   ((uint32_t)0x00000004)
#define UART_MIS_DSRMMIS                                   ((uint32_t)0x00000008)
#define UART_MIS_RXMIS                                     ((uint32_t)0x00000010)
#define UART_MIS_TXMIS                                     ((uint32_t)0x00000020)
#define UART_MIS_RTMIS                                     ((uint32_t)0x00000040)
#define UART_MIS_FEMIS                                     ((uint32_t)0x00000080)
#define UART_MIS_PEMIS                                     ((uint32_t)0x00000100)
#define UART_MIS_BEMIS                                     ((uint32_t)0x00000200)
#define UART_MIS_OEMIS                                     ((uint32_t)0x00000400)

/** @} */ /* End of group UART_MIS */

/** @defgroup Periph_UART_ICR UART ICR
  * @{
  */

/*-- UART_ICR:UART ICR Register -----*/

/* Bit field positions: */
#define UART_ICR_RIMIC_Pos                                 0
#define UART_ICR_CTSMIC_Pos                                1
#define UART_ICR_DCDMIC_Pos                                2
#define UART_ICR_DSRMIC_Pos                                3
#define UART_ICR_RXIC_Pos                                  4
#define UART_ICR_TXIC_Pos                                  5
#define UART_ICR_RTIC_Pos                                  6
#define UART_ICR_FEIC_Pos                                  7
#define UART_ICR_PEIC_Pos                                  8
#define UART_ICR_BEIC_Pos                                  9
#define UART_ICR_OEIC_Pos                                  10

/* Bit field masks: */
#define UART_ICR_RIMIC                                     ((uint32_t)0x00000001)
#define UART_ICR_CTSMIC                                    ((uint32_t)0x00000002)
#define UART_ICR_DCDMIC                                    ((uint32_t)0x00000004)
#define UART_ICR_DSRMIC                                    ((uint32_t)0x00000008)
#define UART_ICR_RXIC                                      ((uint32_t)0x00000010)
#define UART_ICR_TXIC                                      ((uint32_t)0x00000020)
#define UART_ICR_RTIC                                      ((uint32_t)0x00000040)
#define UART_ICR_FEIC                                      ((uint32_t)0x00000080)
#define UART_ICR_PEIC                                      ((uint32_t)0x00000100)
#define UART_ICR_BEIC                                      ((uint32_t)0x00000200)
#define UART_ICR_OEIC                                      ((uint32_t)0x00000400)

/** @} */ /* End of group UART_ICR */

/** @defgroup Periph_UART_DMACR UART DMACR
  * @{
  */

/*-- UART_DMACR:UART DMACR Register -----*/

/* Bit field positions: */
#define UART_DMACR_RXDMAE_Pos                              0
#define UART_DMACR_TXDMAE_Pos                              1
#define UART_DMACR_DMAONERR_Pos                            2

/* Bit field masks: */
#define UART_DMACR_RXDMAE                                  ((uint32_t)0x00000001)
#define UART_DMACR_TXDMAE                                  ((uint32_t)0x00000002)
#define UART_DMACR_DMAONERR                                ((uint32_t)0x00000004)

/** @} */ /* End of group UART_DMACR */

/** @} */ /* End of group UART */

/** @defgroup MDR1901VC1T_Periph_SDIO SDIO
  * @{
  */


/* MDR_SDIO_TypeDef structure */
typedef struct {
	__IO uint32_t	CR;                     /*!< */
	__IO uint32_t	SR;                     /*!< */
	__IO uint32_t	CMDDR;                  /*!< */
	__IO uint32_t	DATDR;                  /*!< */
	__IO uint32_t	CMDCRC;                 /*!< */
	__IO uint32_t	DAT0CRC;                /*!< */
	__IO uint32_t	DAT1CRC;                /*!< */
	__IO uint32_t	DAT2CRC;                /*!< */
	__IO uint32_t	DAT3CRC;                /*!< */
	__IO uint32_t	CMD_TRANSFER;           /*!< */
	__IO uint32_t	DAT_TRANSFER;           /*!< */
}MDR_SDIO_TypeDef;

/** @defgroup Periph_SDIO_CR SDIO CR
  * @{
  */

/*-- SDIO_CR:SDIO CR Register -----*/

/* Bit field positions: */
#define SDIO_CR_SDE_Pos                                    0
#define SDIO_CR_DIRCMD_Pos                                 1
#define SDIO_CR_DIRDATA_Pos                                2
#define SDIO_CR_WORK1_Pos                                  3
#define SDIO_CR_SBITCMD_Pos                                4
#define SDIO_CR_SBITDAT_Pos                                5
#define SDIO_CR_BR_Pos                                     6
#define SDIO_CR_CRC_EN_DATA_Pos                            9
#define SDIO_CR_CRC_EN_CMD_Pos                             10
#define SDIO_CR_TXEIE_DAT_Pos                              11
#define SDIO_CR_RXNEIE_DAT_Pos                             12
#define SDIO_CR_RXFIE_DAT_Pos                              13
#define SDIO_CR_TXEIE_CMD_Pos                              14
#define SDIO_CR_RXNEIE_CMD_Pos                             15
#define SDIO_CR_RXFEIE_CMD_Pos                             16
#define SDIO_CR_WIDTHDAT_Pos                               17
#define SDIO_CR_WRITECMD_Pos                               18
#define SDIO_CR_ENDBUSY_Pos                                19
#define SDIO_CR_WORK2_Pos                                  20
#define SDIO_CR_CLKOE_Pos                                  21

/* Bit field masks: */
#define SDIO_CR_SDE                                        ((uint32_t)0x00000001)
#define SDIO_CR_DIRCMD                                     ((uint32_t)0x00000002)
#define SDIO_CR_DIRDATA                                    ((uint32_t)0x00000004)
#define SDIO_CR_WORK1                                      ((uint32_t)0x00000008)
#define SDIO_CR_SBITCMD                                    ((uint32_t)0x00000010)
#define SDIO_CR_SBITDAT                                    ((uint32_t)0x00000020)
#define SDIO_CR_BR_Msk                                     ((uint32_t)0x000001C0)
#define SDIO_CR_CRC_EN_DATA                                ((uint32_t)0x00000200)
#define SDIO_CR_CRC_EN_CMD                                 ((uint32_t)0x00000400)
#define SDIO_CR_TXEIE_DAT                                  ((uint32_t)0x00000800)
#define SDIO_CR_RXNEIE_DAT                                 ((uint32_t)0x00001000)
#define SDIO_CR_RXFIE_DAT                                  ((uint32_t)0x00002000)
#define SDIO_CR_TXEIE_CMD                                  ((uint32_t)0x00004000)
#define SDIO_CR_RXNEIE_CMD                                 ((uint32_t)0x00008000)
#define SDIO_CR_RXFEIE_CMD                                 ((uint32_t)0x00010000)
#define SDIO_CR_WIDTHDAT                                   ((uint32_t)0x00020000)
#define SDIO_CR_WRITECMD                                   ((uint32_t)0x00040000)
#define SDIO_CR_ENDBUSY                                    ((uint32_t)0x00080000)
#define SDIO_CR_WORK2                                      ((uint32_t)0x00100000)
#define SDIO_CR_CLKOE                                      ((uint32_t)0x00200000)

/** @} */ /* End of group SDIO_CR */

/** @defgroup Periph_SDIO_SR SDIO SR
  * @{
  */

/*-- SDIO_SR:SDIO SR Register -----*/

/* Bit field positions: */
#define SDIO_SR_FIFOCMD_EMPTY_Pos                          0
#define SDIO_SR_FIFODAT_EMPTY_Pos                          1
#define SDIO_SR_FIFOCMD_FULL_Pos                           2
#define SDIO_SR_FIFODAT_FULL_Pos                           3

/* Bit field masks: */
#define SDIO_SR_FIFOCMD_EMPTY                              ((uint32_t)0x00000001)
#define SDIO_SR_FIFODAT_EMPTY                              ((uint32_t)0x00000002)
#define SDIO_SR_FIFOCMD_FULL                               ((uint32_t)0x00000004)
#define SDIO_SR_FIFODAT_FULL                               ((uint32_t)0x00000008)

/** @} */ /* End of group SDIO_SR */

/** @defgroup Periph_SDIO_CMDDR SDIO CMDDR
  * @{
  */

/*-- SDIO_CMDDR:SDIO CMDDR Register -----*/

/* Bit field positions: */

/* Bit field masks: */

/** @} */ /* End of group SDIO_CMDDR */

/** @defgroup Periph_SDIO_DATDR SDIO DATDR
  * @{
  */

/*-- SDIO_DATDR:SDIO DATDR Register -----*/

/* Bit field positions: */

/* Bit field masks: */

/** @} */ /* End of group SDIO_DATDR */

/** @defgroup Periph_SDIO_CMDCRC SDIO CMDCRC
  * @{
  */

/*-- SDIO_CMDCRC:SDIO CMDCRC Register -----*/

/* Bit field positions: */
#define SDIO_CMDCRC_CMDCRC_Pos                             0

/* Bit field masks: */
#define SDIO_CMDCRC_CMDCRC_Msk                             ((uint32_t)0x0000007F)

/** @} */ /* End of group SDIO_CMDCRC */

/** @defgroup Periph_SDIO_DAT0CRC SDIO DAT0CRC
  * @{
  */

/*-- SDIO_DAT0CRC:SDIO DAT0CRC Register -----*/

/* Bit field positions: */
#define SDIO_DAT0CRC_DAT0CRC_Pos                           0

/* Bit field masks: */
#define SDIO_DAT0CRC_DAT0CRC_Msk                           ((uint32_t)0x0000FFFF)

/** @} */ /* End of group SDIO_DAT0CRC */

/** @defgroup Periph_SDIO_DAT1CRC SDIO DAT1CRC
  * @{
  */

/*-- SDIO_DAT1CRC:SDIO DAT1CRC Register -----*/

/* Bit field positions: */
#define SDIO_DAT1CRC_DAT1CRC_Pos                           0

/* Bit field masks: */
#define SDIO_DAT1CRC_DAT1CRC_Msk                           ((uint32_t)0x0000FFFF)

/** @} */ /* End of group SDIO_DAT1CRC */

/** @defgroup Periph_SDIO_DAT2CRC SDIO DAT2CRC
  * @{
  */

/*-- SDIO_DAT2CRC:SDIO DAT2CRC Register -----*/

/* Bit field positions: */
#define SDIO_DAT2CRC_DAT2CRC_Pos                           0

/* Bit field masks: */
#define SDIO_DAT2CRC_DAT2CRC_Msk                           ((uint32_t)0x0000FFFF)

/** @} */ /* End of group SDIO_DAT2CRC */

/** @defgroup Periph_SDIO_DAT3CRC SDIO DAT3CRC
  * @{
  */

/*-- SDIO_DAT3CRC:SDIO DAT3CRC Register -----*/

/* Bit field positions: */
#define SDIO_DAT3CRC_DAT3CRC_Pos                           0

/* Bit field masks: */
#define SDIO_DAT3CRC_DAT3CRC_Msk                           ((uint32_t)0x0000FFFF)

/** @} */ /* End of group SDIO_DAT3CRC */

/** @defgroup Periph_SDIO_CMD_TRANSFER SDIO CMD_TRANSFER
  * @{
  */

/*-- SDIO_CMD_TRANSFER:SDIO CMD_TRANSFER Register -----*/

/* Bit field positions: */
#define SDIO_CMD_TRANSFER_CMD_TRANSFER_Pos                 0

/* Bit field masks: */
#define SDIO_CMD_TRANSFER_CMD_TRANSFER_Msk                 ((uint32_t)0x0000FFFF)

/** @} */ /* End of group SDIO_CMD_TRANSFER */

/** @defgroup Periph_SDIO_DAT_TRANSFER SDIO DAT_TRANSFER
  * @{
  */

/*-- SDIO_DAT_TRANSFER:SDIO DAT_TRANSFER Register -----*/

/* Bit field positions: */
#define SDIO_DAT_TRANSFER_DAT_TRANSFER_Pos                 0

/* Bit field masks: */
#define SDIO_DAT_TRANSFER_DAT_TRANSFER_Msk                 ((uint32_t)0x0000FFFF)

/** @} */ /* End of group SDIO_DAT_TRANSFER */

/** @} */ /* End of group SDIO */

/** @defgroup MDR1901VC1T_Periph_I2C I2C
  * @{
  */


/* MDR_I2Cx_TypeDef structure */
typedef struct {
	__IO uint32_t	PRL;                    /*!<I2C Prescaler (low byte) Register */
	__IO uint32_t	PRH;                    /*!<I2C Prescaler (high byte) Register */
	__IO uint32_t	CTR;                    /*!<I2C Control Register */
	__IO uint32_t	RXD;                    /*!<I2C Received Data Register */
	__IO uint32_t	STA;                    /*!<I2C Status Register */
	__IO uint32_t	TXD;                    /*!<I2C Transmitted Data Register */
	__IO uint32_t	CMD;                    /*!<I2C Command Register */
}MDR_I2C_TypeDef;

/** @defgroup Periph_I2C_PRL I2C PRL
  * @{
  */

/*-- I2C_PRL:I2C PRL Register -----*/

/* Bit field positions: */
#define I2C_PRL_PR_Pos                                     0

/* Bit field masks: */
#define I2C_PRL_PR_Msk                                     ((uint32_t)0x000000FF)

/** @} */ /* End of group I2C_PRL */

/** @defgroup Periph_I2C_PRH I2C PRH
  * @{
  */

/*-- I2C_PRH:I2C PRH Register -----*/

/* Bit field positions: */
#define I2C_PRH_PR_Pos                                     0

/* Bit field masks: */
#define I2C_PRH_PR_Msk                                     ((uint32_t)0x000000FF)

/** @} */ /* End of group I2C_PRH */

/** @defgroup Periph_I2C_CTR I2C CTR
  * @{
  */

/*-- I2C_CTR:I2C CTR Register -----*/

/* Bit field positions: */
#define I2C_CTR_S_I2C_Pos                                  5
#define I2C_CTR_EN_INT_Pos                                 6
#define I2C_CTR_EN_I2C_Pos                                 7

/* Bit field masks: */
#define I2C_CTR_S_I2C                                      ((uint32_t)0x00000020)
#define I2C_CTR_EN_INT                                     ((uint32_t)0x00000040)
#define I2C_CTR_EN_I2C                                     ((uint32_t)0x00000080)

/** @} */ /* End of group I2C_CTR */

/** @defgroup Periph_I2C_RXD I2C RXD
  * @{
  */

/*-- I2C_RXD:I2C RXD Register -----*/

/* Bit field positions: */
#define I2C_RXD_RXD_Pos                                    0

/* Bit field masks: */
#define I2C_RXD_RXD_Msk                                    ((uint32_t)0x000000FF)

/** @} */ /* End of group I2C_RXD */

/** @defgroup Periph_I2C_STA I2C STA
  * @{
  */

/*-- I2C_STA:I2C STA Register -----*/

/* Bit field positions: */
#define I2C_STA_INT_Pos                                    0
#define I2C_STA_TR_PROG_Pos                                1
#define I2C_STA_LOST_ARB_Pos                               5
#define I2C_STA_BUSY_Pos                                   6
#define I2C_STA_RX_ACK_Pos                                 7

/* Bit field masks: */
#define I2C_STA_INT                                        ((uint32_t)0x00000001)
#define I2C_STA_TR_PROG                                    ((uint32_t)0x00000002)
#define I2C_STA_LOST_ARB                                   ((uint32_t)0x00000020)
#define I2C_STA_BUSY                                       ((uint32_t)0x00000040)
#define I2C_STA_RX_ACK                                     ((uint32_t)0x00000080)

/** @} */ /* End of group I2C_STA */

/** @defgroup Periph_I2C_TXD I2C TXD
  * @{
  */

/*-- I2C_TXD:I2C TXD Register -----*/

/* Bit field positions: */
#define I2C_TXD_TXD_Pos                                    0

/* Bit field masks: */
#define I2C_TXD_TXD_Msk                                    ((uint32_t)0x000000FF)

/** @} */ /* End of group I2C_TXD */

/** @defgroup Periph_I2C_CMD I2C CMD
  * @{
  */

/*-- I2C_CMD:I2C CMD Register -----*/

/* Bit field positions: */
#define I2C_CMD_CLRINT_Pos                                 0
#define I2C_CMD_ACK_Pos                                    3
#define I2C_CMD_WR_Pos                                     4
#define I2C_CMD_RD_Pos                                     5
#define I2C_CMD_STOP_Pos                                   6
#define I2C_CMD_START_Pos                                  7

/* Bit field masks: */
#define I2C_CMD_CLRINT                                     ((uint32_t)0x00000001)
#define I2C_CMD_ACK                                        ((uint32_t)0x00000008)
#define I2C_CMD_WR                                         ((uint32_t)0x00000010)
#define I2C_CMD_RD                                         ((uint32_t)0x00000020)
#define I2C_CMD_STOP                                       ((uint32_t)0x00000040)
#define I2C_CMD_START                                      ((uint32_t)0x00000080)

/** @} */ /* End of group I2C_CMD */

/** @} */ /* End of group I2C */

/** @defgroup MDR1901VC1T_Periph_POWER POWER
  * @{
  */


/* MDR_POWER_TypeDef structure */
typedef struct {
	__IO uint32_t	PVDCS;                  /*!<POWER Power Detector Control/Status Register */
}MDR_POWER_TypeDef;

/** @defgroup Periph_POWER_PVDCS POWER PVDCS
  * @{
  */

/*-- POWER_PVDCS:POWER PVDCS Register -----*/

/* Bit field positions: */
#define POWER_PVDCS_PVDEN_Pos                              0
#define POWER_PVDCS_PBLS_Pos                               1
#define POWER_PVDCS_PLS_Pos                                3
#define POWER_PVDCS_PVBD_Pos                               6
#define POWER_PVDCS_PVD_Pos                                7
#define POWER_PVDCS_IEPVBD_Pos                             8
#define POWER_PVDCS_IEPVD_Pos                              9
#define POWER_PVDCS_INVB_Pos                               10
#define POWER_PVDCS_INV_Pos                                11

/* Bit field masks: */
#define POWER_PVDCS_PVDEN                                  ((uint32_t)0x00000001)
#define POWER_PVDCS_PBLS_Msk                               ((uint32_t)0x00000006)
#define POWER_PVDCS_PLS_Msk                                ((uint32_t)0x00000038)
#define POWER_PVDCS_PVBD                                   ((uint32_t)0x00000040)
#define POWER_PVDCS_PVD                                    ((uint32_t)0x00000080)
#define POWER_PVDCS_IEPVBD                                 ((uint32_t)0x00000100)
#define POWER_PVDCS_IEPVD                                  ((uint32_t)0x00000200)
#define POWER_PVDCS_INVB                                   ((uint32_t)0x00000400)
#define POWER_PVDCS_INV                                    ((uint32_t)0x00000800)

/** @} */ /* End of group POWER_PVDCS */

/** @} */ /* End of group POWER */

/** @defgroup MDR1901VC1T_Periph_WWDG WWDG
  * @{
  */


/* MDR_WWDG_TypeDef structure */
typedef struct {
	__IO uint32_t	CR;                     /*!<WWDG Command Register */
	__IO uint32_t	CFR;                    /*!<WWDG Configuration Register */
	__IO uint32_t	SR;                     /*!<WWDG Status Register */
}MDR_WWDG_TypeDef;

/** @defgroup Periph_WWDG_CR WWDG CR
  * @{
  */

/*-- WWDG_CR:WWDG CR Register -----*/

/* Bit field positions: */
#define WWDG_CR_T_Pos                                      0
#define WWDG_CR_WDGA_Pos                                   7

/* Bit field masks: */
#define WWDG_CR_T_Msk                                      ((uint32_t)0x0000007F)
#define WWDG_CR_WDGA                                       ((uint32_t)0x00000080)

/** @} */ /* End of group WWDG_CR */

/** @defgroup Periph_WWDG_CFR WWDG CFR
  * @{
  */

/*-- WWDG_CFR:WWDG CFR Register -----*/

/* Bit field positions: */
#define WWDG_CFR_W_Pos                                     0
#define WWDG_CFR_WGTB_Pos                                  7
#define WWDG_CFR_EWI_Pos                                   9

/* Bit field masks: */
#define WWDG_CFR_W_Msk                                     ((uint32_t)0x0000007F)
#define WWDG_CFR_WGTB_Msk                                  ((uint32_t)0x00000180)
#define WWDG_CFR_EWI                                       ((uint32_t)0x00000200)

/** @} */ /* End of group WWDG_CFR */

/** @defgroup Periph_WWDG_SR WWDG SR
  * @{
  */

/*-- WWDG_SR:WWDG SR Register -----*/

/* Bit field positions: */
#define WWDG_SR_EWIF_Pos                                   0

/* Bit field masks: */
#define WWDG_SR_EWIF                                       ((uint32_t)0x00000001)

/** @} */ /* End of group WWDG_SR */

/** @} */ /* End of group WWDG */

/** @defgroup MDR1901VC1T_Periph_IWDG IWDG
  * @{
  */


/* MDR_IWDG_TypeDef structure */
typedef struct {
	__IO uint32_t	KR;                     /*!<IWDG Key Register */
	__IO uint32_t	PR;                     /*!<IWDG Clock Prescaler Register */
	__IO uint32_t	RLR;                    /*!<IWDG Reload Register */
	__IO uint32_t	SR;                     /*!<IWDG Status Register */
}MDR_IWDG_TypeDef;

/** @defgroup Periph_IWDG_KR IWDG KR
  * @{
  */

/*-- IWDG_KR:IWDG KR Register -----*/

/* Bit field positions: */
#define IWDG_KR_KEY_Pos                                    0

/* Bit field masks: */
#define IWDG_KR_KEY_Msk                                    ((uint32_t)0x0000FFFF)

/** @} */ /* End of group IWDG_KR */

/** @defgroup Periph_IWDG_PR IWDG PR
  * @{
  */

/*-- IWDG_PR:IWDG PR Register -----*/

/* Bit field positions: */
#define IWDG_PR_PR_Pos                                     0

/* Bit field masks: */
#define IWDG_PR_PR_Msk                                     ((uint32_t)0x00000007)

/** @} */ /* End of group IWDG_PR */

/** @defgroup Periph_IWDG_RLR IWDG RLR
  * @{
  */

/*-- IWDG_RLR:IWDG RLR Register -----*/

/* Bit field positions: */
#define IWDG_RLR_RLR_Pos                                   0

/* Bit field masks: */
#define IWDG_RLR_RLR_Msk                                   ((uint32_t)0x00000FFF)

/** @} */ /* End of group IWDG_RLR */

/** @defgroup Periph_IWDG_SR IWDG SR
  * @{
  */

/*-- IWDG_SR:IWDG SR Register -----*/

/* Bit field positions: */
#define IWDG_SR_PVU_Pos                                    0
#define IWDG_SR_RVU_Pos                                    1

/* Bit field masks: */
#define IWDG_SR_PVU                                        ((uint32_t)0x00000001)
#define IWDG_SR_RVU                                        ((uint32_t)0x00000002)

/** @} */ /* End of group IWDG_SR */

/** @} */ /* End of group IWDG */

/** @defgroup MDR1901VC1T_Periph_TIMER TIMER
  * @{
  */


/* MDR_TIMERx_TypeDef structure */
typedef struct {
	__IO uint32_t	CNT;                    /*!<Timer Counter Register */
	__IO uint32_t	PSG;                    /*!<Timer Clock Prescaler Register */
	__IO uint32_t	ARR;                    /*!<Timer Auto-Reload Register */
	__IO uint32_t	CNTRL;                  /*!<Timer Control Register */
	__IO uint32_t	CCR1;                   /*!<Timer Capture/Compare Register 1 */
	__IO uint32_t	CCR2;                   /*!<Timer Capture/Compare Register 2 */
	__IO uint32_t	CCR3;                   /*!<Timer Capture/Compare Register 3 */
	__IO uint32_t	CCR4;                   /*!<Timer Capture/Compare Register 4 */
	__IO uint32_t	CH1_CNTRL;              /*!<Timer Channel Control Register 1 */
	__IO uint32_t	CH2_CNTRL;              /*!<Timer Channel Control Register 2 */
	__IO uint32_t	CH3_CNTRL;              /*!<Timer Channel Control Register 3 */
	__IO uint32_t	CH4_CNTRL;              /*!<Timer Channel Control Register 4 */
	__IO uint32_t	CH1_CNTRL1;             /*!<Timer Channel Control1 Register 1 */
	__IO uint32_t	CH2_CNTRL1;             /*!<Timer Channel Control1 Register 2 */
	__IO uint32_t	CH3_CNTRL1;             /*!<Timer Channel Control1 Register 3 */
	__IO uint32_t	CH4_CNTRL1;             /*!<Timer Channel Control1 Register 4 */
	__IO uint32_t	CH1_DTG;                /*!<Timer Channel DTG Register 1 */
	__IO uint32_t	CH2_DTG;                /*!<Timer Channel DTG Register 2 */
	__IO uint32_t	CH3_DTG;                /*!<Timer Channel DTG Register 3 */
	__IO uint32_t	CH4_DTG;                /*!<Timer Channel DTG Register 4 */
	__IO uint32_t	BRKETR_CNTRL;           /*!<Timer BRK/ETR Control Register */
	__IO uint32_t	STATUS;                 /*!<Timer Status Register */
	__IO uint32_t	IE;                     /*!<Timer Interrupt Enable Register */
	__IO uint32_t	DMA_RE;                 /*!<Timer DMA Request Enable Register */
	__IO uint32_t	CH1_CNTRL2;             /*!<Timer Channel Control2 Register 1 */
	__IO uint32_t	CH2_CNTRL2;             /*!<Timer Channel Control2 Register 2 */
	__IO uint32_t	CH3_CNTRL2;             /*!<Timer Channel Control2 Register 3 */
	__IO uint32_t	CH4_CNTRL2;             /*!<Timer Channel Control2 Register 4 */
	__IO uint32_t	CCR11;                  /*!<Timer Capture/Compare1 Register 1 */
	__IO uint32_t	CCR21;                  /*!<Timer Capture/Compare1 Register 2 */
	__IO uint32_t	CCR31;                  /*!<Timer Capture/Compare1 Register 3 */
	__IO uint32_t	CCR41;                  /*!<Timer Capture/Compare1 Register 4 */
}MDR_TIMER_TypeDef;

/** @defgroup Periph_TIMER_CNT TIMER CNT
  * @{
  */

/*-- TIMER_CNT:TIMER CNT Register -----*/

/* Bit field positions: */
#define TIMER_CNT_CNT_Pos                                  0

/* Bit field masks: */
#define TIMER_CNT_CNT_Msk                                  ((uint32_t)0x0000FFFF)

/** @} */ /* End of group TIMER_CNT */

/** @defgroup Periph_TIMER_PSG TIMER PSG
  * @{
  */

/*-- TIMER_PSG:TIMER PSG Register -----*/

/* Bit field positions: */
#define TIMER_PSG_PSG_Pos                                  0

/* Bit field masks: */
#define TIMER_PSG_PSG_Msk                                  ((uint32_t)0x0000FFFF)

/** @} */ /* End of group TIMER_PSG */

/** @defgroup Periph_TIMER_ARR TIMER ARR
  * @{
  */

/*-- TIMER_ARR:TIMER ARR Register -----*/

/* Bit field positions: */
#define TIMER_ARR_ARR_Pos                                  0

/* Bit field masks: */
#define TIMER_ARR_ARR_Msk                                  ((uint32_t)0x0000FFFF)

/** @} */ /* End of group TIMER_ARR */

/** @defgroup Periph_TIMER_CNTRL TIMER CNTRL
  * @{
  */

/*-- TIMER_CNTRL:TIMER CNTRL Register -----*/

/* Bit field positions: */
#define TIMER_CNTRL_CNT_EN_Pos                             0
#define TIMER_CNTRL_ARRB_EN_Pos                            1
#define TIMER_CNTRL_WR_CMPL_Pos                            2
#define TIMER_CNTRL_DIR_Pos                                3
#define TIMER_CNTRL_FDTS_Pos                               4
#define TIMER_CNTRL_CNT_MODE_Pos                           6
#define TIMER_CNTRL_EVENT_SEL_Pos                          8

/* Bit field masks: */
#define TIMER_CNTRL_CNT_EN                                 ((uint32_t)0x00000001)
#define TIMER_CNTRL_ARRB_EN                                ((uint32_t)0x00000002)
#define TIMER_CNTRL_WR_CMPL                                ((uint32_t)0x00000004)
#define TIMER_CNTRL_DIR                                    ((uint32_t)0x00000008)
#define TIMER_CNTRL_FDTS_Msk                               ((uint32_t)0x00000030)
#define TIMER_CNTRL_CNT_MODE_Msk                           ((uint32_t)0x000000C0)
#define TIMER_CNTRL_EVENT_SEL_Msk                          ((uint32_t)0x00000F00)

/** @} */ /* End of group TIMER_CNTRL */

/** @defgroup Periph_TIMER_CCR TIMER CCR
  * @{
  */

/*-- TIMER_CCR:TIMER CCR Register -----*/

/* Bit field positions: */
#define TIMER_CCR_CCR_Pos                                  0

/* Bit field masks: */
#define TIMER_CCR_CCR_Msk                                  ((uint32_t)0x0000FFFF)

/** @} */ /* End of group TIMER_CCR */

/** @defgroup Periph_TIMER_CH_CNTRL TIMER CH_CNTRL
  * @{
  */

/*-- TIMER_CH_CNTRL:TIMER CH_CNTRL Register -----*/

/* Bit field positions: */
#define TIMER_CH_CNTRL_CHFLTR_Pos                          0
#define TIMER_CH_CNTRL_CHSEL_Pos                           4
#define TIMER_CH_CNTRL_CHPSC_Pos                           6
#define TIMER_CH_CNTRL_OCCE_Pos                            8
#define TIMER_CH_CNTRL_OCCM_Pos                            9
#define TIMER_CH_CNTRL_BRKEN_Pos                           12
#define TIMER_CH_CNTRL_ETREN_Pos                           13
#define TIMER_CH_CNTRL_WR_CMPL_Pos                         14
#define TIMER_CH_CNTRL_CAP_NPWM_Pos                        15

/* Bit field masks: */
#define TIMER_CH_CNTRL_CHFLTR_Msk                          ((uint32_t)0x0000000F)
#define TIMER_CH_CNTRL_CHSEL_Msk                           ((uint32_t)0x00000030)
#define TIMER_CH_CNTRL_CHPSC_Msk                           ((uint32_t)0x000000C0)
#define TIMER_CH_CNTRL_OCCE                                ((uint32_t)0x00000100)
#define TIMER_CH_CNTRL_OCCM_Msk                            ((uint32_t)0x00000E00)
#define TIMER_CH_CNTRL_BRKEN                               ((uint32_t)0x00001000)
#define TIMER_CH_CNTRL_ETREN                               ((uint32_t)0x00002000)
#define TIMER_CH_CNTRL_WR_CMPL                             ((uint32_t)0x00004000)
#define TIMER_CH_CNTRL_CAP_NPWM                            ((uint32_t)0x00008000)

/** @} */ /* End of group TIMER_CH_CNTRL */

/** @defgroup Periph_TIMER_CH_CNTRL1 TIMER CH_CNTRL1
  * @{
  */

/*-- TIMER_CH_CNTRL1:TIMER CH_CNTRL1 Register -----*/

/* Bit field positions: */
#define TIMER_CH_CNTRL1_SELOE_Pos                          0
#define TIMER_CH_CNTRL1_SELO_Pos                           2
#define TIMER_CH_CNTRL1_INV_Pos                            4
#define TIMER_CH_CNTRL1_NSELOE_Pos                         8
#define TIMER_CH_CNTRL1_NSELO_Pos                          10
#define TIMER_CH_CNTRL1_NINV_Pos                           12

/* Bit field masks: */
#define TIMER_CH_CNTRL1_SELOE_Msk                          ((uint32_t)0x00000003)
#define TIMER_CH_CNTRL1_SELO_Msk                           ((uint32_t)0x0000000C)
#define TIMER_CH_CNTRL1_INV                                ((uint32_t)0x00000010)
#define TIMER_CH_CNTRL1_NSELOE_Msk                         ((uint32_t)0x00000300)
#define TIMER_CH_CNTRL1_NSELO_Msk                          ((uint32_t)0x00000C00)
#define TIMER_CH_CNTRL1_NINV                               ((uint32_t)0x00001000)

/** @} */ /* End of group TIMER_CH_CNTRL1 */

/** @defgroup Periph_TIMER_CH_DTG TIMER CH_DTG
  * @{
  */

/*-- TIMER_CH_DTG:TIMER CH_DTG Register -----*/

/* Bit field positions: */
#define TIMER_CH_DTGX_Pos                              0
#define TIMER_CH_DTG_EDTS_Pos                          4
#define TIMER_CH_DTG_Pos                               8

/* Bit field masks: */
#define TIMER_CH_DTGX_Msk                              ((uint32_t)0x0000000F)
#define TIMER_CH_DTG_EDTS                              ((uint32_t)0x00000010)
#define TIMER_CH_DTG_Msk                               ((uint32_t)0x0000FF00)

/** @} */ /* End of group TIMER_CH_DTG */

/** @defgroup Periph_TIMER_BRKETR_CNTRL TIMER BRKETR_CNTRL
  * @{
  */

/*-- TIMER_BRKETR_CNTRL:TIMER BRKETR_CNTRL Register -----*/

/* Bit field positions: */
#define TIMER_BRKETR_CNTRL_BRK_INV_Pos                     0
#define TIMER_BRKETR_CNTRL_ETR_INV_Pos                     1
#define TIMER_BRKETR_CNTRL_ETR_PSC_Pos                     2
#define TIMER_BRKETR_CNTRL_ETR_FILTER_Pos                  4

/* Bit field masks: */
#define TIMER_BRKETR_CNTRL_BRK_INV                         ((uint32_t)0x00000001)
#define TIMER_BRKETR_CNTRL_ETR_INV                         ((uint32_t)0x00000002)
#define TIMER_BRKETR_CNTRL_ETR_PSC_Msk                     ((uint32_t)0x0000000C)
#define TIMER_BRKETR_CNTRL_ETR_FILTER_Msk                  ((uint32_t)0x000000F0)

/** @} */ /* End of group TIMER_BRKETR_CNTRL */

/** @defgroup Periph_TIMER_STATUS TIMER STATUS
  * @{
  */

/*-- TIMER_STATUS:TIMER STATUS Register -----*/

/* Bit field positions: */
#define TIMER_STATUS_CNT_ZERO_EVENT_Pos                    0
#define TIMER_STATUS_CNT_ARR_EVENT_Pos                     1
#define TIMER_STATUS_ETR_RE_EVENT_Pos                      2
#define TIMER_STATUS_ETR_FE_EVENT_Pos                      3
#define TIMER_STATUS_BRK_EVENT_Pos                         4
#define TIMER_STATUS_CCR_CAP_EVENT_Pos                     5
#define TIMER_STATUS_CCR_REF_EVENT_Pos                     9
#define TIMER_STATUS_CCR1_CAP_EVENT_Pos                    13

/* Bit field masks: */
#define TIMER_STATUS_CNT_ZERO_EVENT                        ((uint32_t)0x00000001)
#define TIMER_STATUS_CNT_ARR_EVENT                         ((uint32_t)0x00000002)
#define TIMER_STATUS_ETR_RE_EVENT                          ((uint32_t)0x00000004)
#define TIMER_STATUS_ETR_FE_EVENT                          ((uint32_t)0x00000008)
#define TIMER_STATUS_BRK_EVENT                             ((uint32_t)0x00000010)
#define TIMER_STATUS_CCR_CAP_EVENT_Msk                     ((uint32_t)0x000001E0)
#define TIMER_STATUS_CCR_REF_EVENT_Msk                     ((uint32_t)0x00001E00)
#define TIMER_STATUS_CCR1_CAP_EVENT_Msk                    ((uint32_t)0x0001E000)

/** @} */ /* End of group TIMER_STATUS */

/** @defgroup Periph_TIMER_IE TIMER IE
  * @{
  */

/*-- TIMER_IE:TIMER IE Register -----*/

/* Bit field positions: */
#define TIMER_IE_CNT_ZERO_EVENT_IE_Pos                     0
#define TIMER_IE_CNT_ARR_EVENT_IE_Pos                      1
#define TIMER_IE_ETR_RE_EVENT_IE_Pos                       2
#define TIMER_IE_ETR_FE_EVENT_IE_Pos                       3
#define TIMER_IE_BRK_EVENT_IE_Pos                          4
#define TIMER_IE_CCR_CAP_EVENT_IE_Pos                      5
#define TIMER_IE_CCR_REF_EVENT_IE_Pos                      9
#define TIMER_IE_CCR1_CAP_EVENT_IE_Pos                     13

/* Bit field masks: */
#define TIMER_IE_CNT_ZERO_EVENT_IE                         ((uint32_t)0x00000001)
#define TIMER_IE_CNT_ARR_EVENT_IE                          ((uint32_t)0x00000002)
#define TIMER_IE_ETR_RE_EVENT_IE                           ((uint32_t)0x00000004)
#define TIMER_IE_ETR_FE_EVENT_IE                           ((uint32_t)0x00000008)
#define TIMER_IE_BRK_EVENT_IE                              ((uint32_t)0x00000010)
#define TIMER_IE_CCR_CAP_EVENT_IE_Msk                      ((uint32_t)0x000001E0)
#define TIMER_IE_CCR_REF_EVENT_IE_Msk                      ((uint32_t)0x00001E00)
#define TIMER_IE_CCR1_CAP_EVENT_IE_Msk                     ((uint32_t)0x0001E000)

/** @} */ /* End of group TIMER_IE */

/** @defgroup Periph_TIMER_DMA_RE TIMER DMA_RE
  * @{
  */

/*-- TIMER_DMA_RE:TIMER DMA_RE Register -----*/

/* Bit field positions: */
#define TIMER_DMA_RE_CNT_ZERO_EVENT_RE_Pos                 0
#define TIMER_DMA_RE_CNT_ARR_EVENT_RE_Pos                  1
#define TIMER_DMA_RE_ETR_RE_EVENT_RE_Pos                   2
#define TIMER_DMA_RE_ETR_FE_EVENT_RE_Pos                   3
#define TIMER_DMA_RE_BRK_EVENT_RE_Pos                      4
#define TIMER_DMA_RE_CCR_CAP_EVENT_RE_Pos                  5
#define TIMER_DMA_RE_CCR_REF_EVENT_RE_Pos                  9
#define TIMER_DMA_RE_CCR1_CAP_EVENT_RE_Pos                 13

/* Bit field masks: */
#define TIMER_DMA_RE_CNT_ZERO_EVENT_RE                     ((uint32_t)0x00000001)
#define TIMER_DMA_RE_CNT_ARR_EVENT_RE                      ((uint32_t)0x00000002)
#define TIMER_DMA_RE_ETR_RE_EVENT_RE                       ((uint32_t)0x00000004)
#define TIMER_DMA_RE_ETR_FE_EVENT_RE                       ((uint32_t)0x00000008)
#define TIMER_DMA_RE_BRK_EVENT_RE                          ((uint32_t)0x00000010)
#define TIMER_DMA_RE_CCR_CAP_EVENT_RE_Msk                  ((uint32_t)0x000001E0)
#define TIMER_DMA_RE_CCR_REF_EVENT_RE_Msk                  ((uint32_t)0x00001E00)
#define TIMER_DMA_RE_CCR1_CAP_EVENT_RE_Msk                 ((uint32_t)0x0001E000)

/** @} */ /* End of group TIMER_DMA_RE */

/** @defgroup Periph_TIMER_CH_CNTRL2 TIMER CH_CNTRL2
  * @{
  */

/*-- TIMER_CH_CNTRL2:TIMER CH_CNTRL2 Register -----*/

/* Bit field positions: */
#define TIMER_CH_CNTRL2_CHSEL1_Pos                         0
#define TIMER_CH_CNTRL2_CCR1_EN_Pos                        2
#define TIMER_CH_CNTRL2_CCRRLD_Pos                         3

/* Bit field masks: */
#define TIMER_CH_CNTRL2_CHSEL1_Msk                         ((uint32_t)0x00000003)
#define TIMER_CH_CNTRL2_CCR1_EN                            ((uint32_t)0x00000004)
#define TIMER_CH_CNTRL2_CCRRLD                             ((uint32_t)0x00000008)

/** @} */ /* End of group TIMER_CH_CNTRL2 */

/** @defgroup Periph_TIMER_CCR1 TIMER CCR1
  * @{
  */

/*-- TIMER_CCR1:TIMER CCR1 Register -----*/

/* Bit field positions: */
#define TIMER_CCR1_CCR_Pos                                 0

/* Bit field masks: */
#define TIMER_CCR1_CCR_Msk                                 ((uint32_t)0x0000FFFF)

/** @} */ /* End of group TIMER_CCR1 */

/** @} */ /* End of group TIMER */

/** @defgroup MDR1901VC1T_Periph_ADC ADC
  * @{
  */

/* MDR_ADC_TypeDef structure */
typedef struct {
	__IO uint32_t	ADC1_CFG;               /*!<ADC1 Configuration Register */
	__IO uint32_t	ADC2_CFG;               /*!<ADC2 Configuration Register */
	__IO uint32_t	ADC1_H_LEVEL;           /*!<ADC1 High Level Register */
	__IO uint32_t	ADC2_H_LEVEL;           /*!<ADC2 High Level Register */
	__IO uint32_t	ADC1_L_LEVEL;           /*!<ADC1 Low Level Register */
	__IO uint32_t	ADC2_L_LEVEL;           /*!<ADC2 Low Level Register */
	__IO uint32_t	ADC1_RESULT;            /*!<ADC1 Result Register */
	__IO uint32_t	ADC2_RESULT;            /*!<ADC2 Result Register */
	__IO uint32_t	ADC1_STATUS;            /*!<ADC1 Status Register */
	__IO uint32_t	ADC2_STATUS;            /*!<ADC2 Status Register */
	__IO uint32_t	ADC1_CHSEL;             /*!<ADC1 Channel Selector Register */
	__IO uint32_t	ADC2_CHSEL;             /*!<ADC2 Channel Selector Register */
}MDR_ADC_TypeDef;

/** @defgroup Periph_ADC1_CFG  ADC1_CFG
  * @{
  */

/*-- ADC1_CFG: ADC1_CFG Register -----*/

/* Bit field positions: */
#define ADC1_CFG_REG_ADON_Pos                              0
#define ADC1_CFG_REG_GO_Pos                                1
#define ADC1_CFG_REG_CLKS_Pos                              2
#define ADC1_CFG_REG_SAMPLE_Pos                            3
#define ADC1_CFG_REG_CHS_Pos                               4
#define ADC1_CFG_REG_CHCH_Pos                              9
#define ADC1_CFG_REG_RNGC_Pos                              10
#define ADC1_CFG_M_REF_Pos                                 11
#define ADC1_CFG_REG_DIVCLK_Pos                            12
#define ADC1_CFG_SYNC_CONVER_Pos                           16
#define ADC1_CFG_TS_EN_Pos                                 17
#define ADC1_CFG_TS_BUF_EN_Pos                             18
#define ADC1_CFG_SEL_TS_Pos                                19
#define ADC1_CFG_SEL_VREF_Pos                              20
#define ADC1_CFG_TR_Pos                                    21
#define ADC1_CFG_DELAY_GO_Pos                              25
#define ADC1_CFG_DELAY_ADC_Pos                             28

/* Bit field masks: */
#define ADC1_CFG_REG_ADON                                  ((uint32_t)0x00000001)
#define ADC1_CFG_REG_GO                                    ((uint32_t)0x00000002)
#define ADC1_CFG_REG_CLKS                                  ((uint32_t)0x00000004)
#define ADC1_CFG_REG_SAMPLE                                ((uint32_t)0x00000008)
#define ADC1_CFG_REG_CHS_Msk                               ((uint32_t)0x000001F0)
#define ADC1_CFG_REG_CHCH                                  ((uint32_t)0x00000200)
#define ADC1_CFG_REG_RNGC                                  ((uint32_t)0x00000400)
#define ADC1_CFG_M_REF                                     ((uint32_t)0x00000800)
#define ADC1_CFG_REG_DIVCLK_Msk                            ((uint32_t)0x0000F000)
#define ADC1_CFG_SYNC_CONVER                               ((uint32_t)0x00010000)
#define ADC1_CFG_TS_EN                                     ((uint32_t)0x00020000)
#define ADC1_CFG_TS_BUF_EN                                 ((uint32_t)0x00040000)
#define ADC1_CFG_SEL_TS                                    ((uint32_t)0x00080000)
#define ADC1_CFG_SEL_VREF                                  ((uint32_t)0x00100000)
#define ADC1_CFG_TR_Msk                                    ((uint32_t)0x01E00000)
#define ADC1_CFG_DELAY_GO_Msk                              ((uint32_t)0x0E000000)
#define ADC1_CFG_DELAY_ADC_Msk                             ((uint32_t)0xF0000000)

/** @} */ /* End of group ADC1_CFG */

/** @defgroup Periph_ADC2_CFG  ADC2_CFG
  * @{
  */

/*-- ADC2_CFG: ADC2_CFG Register -----*/

/* Bit field positions: */
#define ADC2_CFG_REG_ADON_Pos                              0
#define ADC2_CFG_REG_GO_Pos                                1
#define ADC2_CFG_REG_CLKS_Pos                              2
#define ADC2_CFG_REG_SAMPLE_Pos                            3
#define ADC2_CFG_REG_CHS_Pos                               4
#define ADC2_CFG_REG_CHCH_Pos                              9
#define ADC2_CFG_REG_RNGC_Pos                              10
#define ADC2_CFG_M_REF_Pos                                 11
#define ADC2_CFG_REG_DIVCLK_Pos                            12
#define ADC2_CFG_ADC1_OP_Pos                               17
#define ADC2_CFG_ADC2_OP_Pos                               18
#define ADC2_CFG_DELAY_GO_Pos                              25

/* Bit field masks: */
#define ADC2_CFG_REG_ADON                                  ((uint32_t)0x00000001)
#define ADC2_CFG_REG_GO                                    ((uint32_t)0x00000002)
#define ADC2_CFG_REG_CLKS                                  ((uint32_t)0x00000004)
#define ADC2_CFG_REG_SAMPLE                                ((uint32_t)0x00000008)
#define ADC2_CFG_REG_CHS_Msk                               ((uint32_t)0x000001F0)
#define ADC2_CFG_REG_CHCH                                  ((uint32_t)0x00000200)
#define ADC2_CFG_REG_RNGC                                  ((uint32_t)0x00000400)
#define ADC2_CFG_M_REF                                     ((uint32_t)0x00000800)
#define ADC2_CFG_REG_DIVCLK_Msk                            ((uint32_t)0x0000F000)
#define ADC2_CFG_ADC1_OP                                   ((uint32_t)0x00020000)
#define ADC2_CFG_ADC2_OP                                   ((uint32_t)0x00040000)
#define ADC2_CFG_DELAY_GO_Msk                              ((uint32_t)0x0E000000)

/** @} */ /* End of group ADC2_CFG */

/** @defgroup Periph_ADC1_H_LEVEL  ADC1_H_LEVEL
  * @{
  */

/*-- ADC1_H_LEVEL: ADC1_H_LEVEL Register -----*/

/* Bit field positions: */
#define ADC1_H_LEVEL_REG_H_LEVEL_Pos                       0

/* Bit field masks: */
#define ADC1_H_LEVEL_REG_H_LEVEL_Msk                       ((uint32_t)0x00000FFF)

/** @} */ /* End of group ADC1_H_LEVEL */

/** @defgroup Periph_ADC2_H_LEVEL  ADC2_H_LEVEL
  * @{
  */

/*-- ADC2_H_LEVEL: ADC2_H_LEVEL Register -----*/

/* Bit field positions: */
#define ADC2_H_LEVEL_REG_H_LEVEL_Pos                       0

/* Bit field masks: */
#define ADC2_H_LEVEL_REG_H_LEVEL_Msk                       ((uint32_t)0x00000FFF)

/** @} */ /* End of group ADC2_H_LEVEL */

/** @defgroup Periph_ADC1_L_LEVEL  ADC1_L_LEVEL
  * @{
  */

/*-- ADC1_L_LEVEL: ADC1_L_LEVEL Register -----*/

/* Bit field positions: */
#define ADC1_L_LEVEL_REG_L_LEVEL_Pos                       0

/* Bit field masks: */
#define ADC1_L_LEVEL_REG_L_LEVEL_Msk                       ((uint32_t)0x00000FFF)

/** @} */ /* End of group ADC1_L_LEVEL */

/** @defgroup Periph_ADC2_L_LEVEL  ADC2_L_LEVEL
  * @{
  */

/*-- ADC2_L_LEVEL: ADC2_L_LEVEL Register -----*/

/* Bit field positions: */
#define ADC2_L_LEVEL_REG_L_LEVEL_Pos                       0

/* Bit field masks: */
#define ADC2_L_LEVEL_REG_L_LEVEL_Msk                       ((uint32_t)0x00000FFF)

/** @} */ /* End of group ADC2_L_LEVEL */

/** @defgroup Periph_ADC1_RESULT  ADC1_RESULT
  * @{
  */

/*-- ADC1_RESULT: ADC1_RESULT Register -----*/

/* Bit field positions: */
#define ADC1_RESULT_RESULT_Pos                             0
#define ADC1_RESULT_CHANNEL_Pos                            16

/* Bit field masks: */
#define ADC1_RESULT_RESULT_Msk                             ((uint32_t)0x00000FFF)
#define ADC1_RESULT_CHANNEL_Msk                            ((uint32_t)0x0FFF0000)

/** @} */ /* End of group ADC1_RESULT */

/** @defgroup Periph_ADC2_RESULT  ADC2_RESULT
  * @{
  */

/*-- ADC2_RESULT: ADC2_RESULT Register -----*/

/* Bit field positions: */
#define ADC2_RESULT_RESULT_Pos                             0
#define ADC2_RESULT_CHANNEL_Pos                            16

/* Bit field masks: */
#define ADC2_RESULT_RESULT_Msk                             ((uint32_t)0x00000FFF)
#define ADC2_RESULT_CHANNEL_Msk                            ((uint32_t)0x0FFF0000)

/** @} */ /* End of group ADC2_RESULT */

/** @defgroup Periph_ADC1_STATUS  ADC1_STATUS
  * @{
  */

/*-- ADC1_STATUS: ADC1_STATUS Register -----*/

/* Bit field positions: */
#define ADC_STATUS_FLG_REG_OVERWRITE_Pos                   0
#define ADC_STATUS_FLG_REG_AWOIFEN_Pos                     1
#define ADC_STATUS_FLG_REG_EOCIF_Pos                       2
#define ADC_STATUS_AWOIF_IE_Pos                            3
#define ADC_STATUS_ECOIF_IE_Pos                            4

/* Bit field masks: */
#define ADC_STATUS_FLG_REG_OVERWRITE                       ((uint32_t)0x00000001)
#define ADC_STATUS_FLG_REG_AWOIFEN                         ((uint32_t)0x00000002)
#define ADC_STATUS_FLG_REG_EOCIF                           ((uint32_t)0x00000004)
#define ADC_STATUS_AWOIF_IE                                ((uint32_t)0x00000008)
#define ADC_STATUS_ECOIF_IE                                ((uint32_t)0x00000010)

/** @} */ /* End of group ADC1_STATUS */

/** @defgroup Periph_ADC1_CHSEL  ADC1_CHSEL
  * @{
  */

/*-- ADC1_CHSEL: ADC1_CHSEL Register -----*/

/* Bit field positions: */
#define ADC1_CHSEL_SL_CH_CH_REF0_Pos                       0
#define ADC1_CHSEL_SL_CH_CH_REF1_Pos                       1
#define ADC1_CHSEL_SL_CH_CH_REF2_Pos                       2
#define ADC1_CHSEL_SL_CH_CH_REF3_Pos                       3
#define ADC1_CHSEL_SL_CH_CH_REF4_Pos                       4
#define ADC1_CHSEL_SL_CH_CH_REF5_Pos                       5
#define ADC1_CHSEL_SL_CH_CH_REF6_Pos                       6
#define ADC1_CHSEL_SL_CH_CH_REF7_Pos                       7
#define ADC1_CHSEL_SL_CH_CH_REF8_Pos                       8
#define ADC1_CHSEL_SL_CH_CH_REF9_Pos                       9
#define ADC1_CHSEL_SL_CH_CH_REF10_Pos                      10
#define ADC1_CHSEL_SL_CH_CH_REF11_Pos                      11
#define ADC1_CHSEL_SL_CH_CH_REF12_Pos                      12
#define ADC1_CHSEL_SL_CH_CH_REF13_Pos                      13
#define ADC1_CHSEL_SL_CH_CH_REF14_Pos                      14
#define ADC1_CHSEL_SL_CH_CH_REF15_Pos                      15
#define ADC1_CHSEL_SL_CH_CH_REF16_Pos                      16
#define ADC1_CHSEL_SL_CH_CH_REF17_Pos                      17
#define ADC1_CHSEL_SL_CH_CH_REF18_Pos                      18
#define ADC1_CHSEL_SL_CH_CH_REF19_Pos                      19
#define ADC1_CHSEL_SL_CH_CH_REF20_Pos                      20
#define ADC1_CHSEL_SL_CH_CH_REF21_Pos                      21
#define ADC1_CHSEL_SL_CH_CH_REF22_Pos                      22
#define ADC1_CHSEL_SL_CH_CH_REF23_Pos                      23
#define ADC1_CHSEL_SL_CH_CH_REF24_Pos                      24
#define ADC1_CHSEL_SL_CH_CH_REF25_Pos                      25
#define ADC1_CHSEL_SL_CH_CH_REF26_Pos                      26
#define ADC1_CHSEL_SL_CH_CH_REF27_Pos                      27
#define ADC1_CHSEL_SL_CH_CH_REF28_Pos                      28
#define ADC1_CHSEL_SL_CH_CH_REF29_Pos                      29
#define ADC1_CHSEL_SL_CH_CH_REF30_Pos                      30
#define ADC1_CHSEL_SL_CH_CH_REF31_Pos                      31

/* Bit field masks: */
#define ADC1_CHSEL_SL_CH_CH_REF0                           ((uint32_t)0x00000001)
#define ADC1_CHSEL_SL_CH_CH_REF1                           ((uint32_t)0x00000002)
#define ADC1_CHSEL_SL_CH_CH_REF2                           ((uint32_t)0x00000004)
#define ADC1_CHSEL_SL_CH_CH_REF3                           ((uint32_t)0x00000008)
#define ADC1_CHSEL_SL_CH_CH_REF4                           ((uint32_t)0x00000010)
#define ADC1_CHSEL_SL_CH_CH_REF5                           ((uint32_t)0x00000020)
#define ADC1_CHSEL_SL_CH_CH_REF6                           ((uint32_t)0x00000040)
#define ADC1_CHSEL_SL_CH_CH_REF7                           ((uint32_t)0x00000080)
#define ADC1_CHSEL_SL_CH_CH_REF8                           ((uint32_t)0x00000100)
#define ADC1_CHSEL_SL_CH_CH_REF9                           ((uint32_t)0x00000200)
#define ADC1_CHSEL_SL_CH_CH_REF10                          ((uint32_t)0x00000400)
#define ADC1_CHSEL_SL_CH_CH_REF11                          ((uint32_t)0x00000800)
#define ADC1_CHSEL_SL_CH_CH_REF12                          ((uint32_t)0x00001000)
#define ADC1_CHSEL_SL_CH_CH_REF13                          ((uint32_t)0x00002000)
#define ADC1_CHSEL_SL_CH_CH_REF14                          ((uint32_t)0x00004000)
#define ADC1_CHSEL_SL_CH_CH_REF15                          ((uint32_t)0x00008000)
#define ADC1_CHSEL_SL_CH_CH_REF16                          ((uint32_t)0x00010000)
#define ADC1_CHSEL_SL_CH_CH_REF17                          ((uint32_t)0x00020000)
#define ADC1_CHSEL_SL_CH_CH_REF18                          ((uint32_t)0x00040000)
#define ADC1_CHSEL_SL_CH_CH_REF19                          ((uint32_t)0x00080000)
#define ADC1_CHSEL_SL_CH_CH_REF20                          ((uint32_t)0x00100000)
#define ADC1_CHSEL_SL_CH_CH_REF21                          ((uint32_t)0x00200000)
#define ADC1_CHSEL_SL_CH_CH_REF22                          ((uint32_t)0x00400000)
#define ADC1_CHSEL_SL_CH_CH_REF23                          ((uint32_t)0x00800000)
#define ADC1_CHSEL_SL_CH_CH_REF24                          ((uint32_t)0x01000000)
#define ADC1_CHSEL_SL_CH_CH_REF25                          ((uint32_t)0x02000000)
#define ADC1_CHSEL_SL_CH_CH_REF26                          ((uint32_t)0x04000000)
#define ADC1_CHSEL_SL_CH_CH_REF27                          ((uint32_t)0x08000000)
#define ADC1_CHSEL_SL_CH_CH_REF28                          ((uint32_t)0x10000000)
#define ADC1_CHSEL_SL_CH_CH_REF29                          ((uint32_t)0x20000000)
#define ADC1_CHSEL_SL_CH_CH_REF30                          ((uint32_t)0x40000000)
#define ADC1_CHSEL_SL_CH_CH_REF31                          ((uint32_t)0x80000000)

/** @} */ /* End of group ADC1_CHSEL */

/** @defgroup Periph_ADC2_CHSEL  ADC2_CHSEL
  * @{
  */

/*-- ADC2_CHSEL: ADC2_CHSEL Register -----*/

/* Bit field positions: */
#define ADC2_CHSEL_SL_CH_CH_REF0_Pos                       0
#define ADC2_CHSEL_SL_CH_CH_REF1_Pos                       1
#define ADC2_CHSEL_SL_CH_CH_REF2_Pos                       2
#define ADC2_CHSEL_SL_CH_CH_REF3_Pos                       3
#define ADC2_CHSEL_SL_CH_CH_REF4_Pos                       4
#define ADC2_CHSEL_SL_CH_CH_REF5_Pos                       5
#define ADC2_CHSEL_SL_CH_CH_REF6_Pos                       6
#define ADC2_CHSEL_SL_CH_CH_REF7_Pos                       7
#define ADC2_CHSEL_SL_CH_CH_REF8_Pos                       8
#define ADC2_CHSEL_SL_CH_CH_REF9_Pos                       9
#define ADC2_CHSEL_SL_CH_CH_REF10_Pos                      10
#define ADC2_CHSEL_SL_CH_CH_REF11_Pos                      11
#define ADC2_CHSEL_SL_CH_CH_REF12_Pos                      12
#define ADC2_CHSEL_SL_CH_CH_REF13_Pos                      13
#define ADC2_CHSEL_SL_CH_CH_REF14_Pos                      14
#define ADC2_CHSEL_SL_CH_CH_REF15_Pos                      15
#define ADC2_CHSEL_SL_CH_CH_REF16_Pos                      16
#define ADC2_CHSEL_SL_CH_CH_REF17_Pos                      17
#define ADC2_CHSEL_SL_CH_CH_REF18_Pos                      18
#define ADC2_CHSEL_SL_CH_CH_REF19_Pos                      19
#define ADC2_CHSEL_SL_CH_CH_REF20_Pos                      20
#define ADC2_CHSEL_SL_CH_CH_REF21_Pos                      21
#define ADC2_CHSEL_SL_CH_CH_REF22_Pos                      22
#define ADC2_CHSEL_SL_CH_CH_REF23_Pos                      23
#define ADC2_CHSEL_SL_CH_CH_REF24_Pos                      24
#define ADC2_CHSEL_SL_CH_CH_REF25_Pos                      25
#define ADC2_CHSEL_SL_CH_CH_REF26_Pos                      26
#define ADC2_CHSEL_SL_CH_CH_REF27_Pos                      27
#define ADC2_CHSEL_SL_CH_CH_REF28_Pos                      28
#define ADC2_CHSEL_SL_CH_CH_REF29_Pos                      29
#define ADC2_CHSEL_SL_CH_CH_REF30_Pos                      30
#define ADC2_CHSEL_SL_CH_CH_REF31_Pos                      31

/* Bit field masks: */
#define ADC2_CHSEL_SL_CH_CH_REF0                           ((uint32_t)0x00000001)
#define ADC2_CHSEL_SL_CH_CH_REF1                           ((uint32_t)0x00000002)
#define ADC2_CHSEL_SL_CH_CH_REF2                           ((uint32_t)0x00000004)
#define ADC2_CHSEL_SL_CH_CH_REF3                           ((uint32_t)0x00000008)
#define ADC2_CHSEL_SL_CH_CH_REF4                           ((uint32_t)0x00000010)
#define ADC2_CHSEL_SL_CH_CH_REF5                           ((uint32_t)0x00000020)
#define ADC2_CHSEL_SL_CH_CH_REF6                           ((uint32_t)0x00000040)
#define ADC2_CHSEL_SL_CH_CH_REF7                           ((uint32_t)0x00000080)
#define ADC2_CHSEL_SL_CH_CH_REF8                           ((uint32_t)0x00000100)
#define ADC2_CHSEL_SL_CH_CH_REF9                           ((uint32_t)0x00000200)
#define ADC2_CHSEL_SL_CH_CH_REF10                          ((uint32_t)0x00000400)
#define ADC2_CHSEL_SL_CH_CH_REF11                          ((uint32_t)0x00000800)
#define ADC2_CHSEL_SL_CH_CH_REF12                          ((uint32_t)0x00001000)
#define ADC2_CHSEL_SL_CH_CH_REF13                          ((uint32_t)0x00002000)
#define ADC2_CHSEL_SL_CH_CH_REF14                          ((uint32_t)0x00004000)
#define ADC2_CHSEL_SL_CH_CH_REF15                          ((uint32_t)0x00008000)
#define ADC2_CHSEL_SL_CH_CH_REF16                          ((uint32_t)0x00010000)
#define ADC2_CHSEL_SL_CH_CH_REF17                          ((uint32_t)0x00020000)
#define ADC2_CHSEL_SL_CH_CH_REF18                          ((uint32_t)0x00040000)
#define ADC2_CHSEL_SL_CH_CH_REF19                          ((uint32_t)0x00080000)
#define ADC2_CHSEL_SL_CH_CH_REF20                          ((uint32_t)0x00100000)
#define ADC2_CHSEL_SL_CH_CH_REF21                          ((uint32_t)0x00200000)
#define ADC2_CHSEL_SL_CH_CH_REF22                          ((uint32_t)0x00400000)
#define ADC2_CHSEL_SL_CH_CH_REF23                          ((uint32_t)0x00800000)
#define ADC2_CHSEL_SL_CH_CH_REF24                          ((uint32_t)0x01000000)
#define ADC2_CHSEL_SL_CH_CH_REF25                          ((uint32_t)0x02000000)
#define ADC2_CHSEL_SL_CH_CH_REF26                          ((uint32_t)0x04000000)
#define ADC2_CHSEL_SL_CH_CH_REF27                          ((uint32_t)0x08000000)
#define ADC2_CHSEL_SL_CH_CH_REF28                          ((uint32_t)0x10000000)
#define ADC2_CHSEL_SL_CH_CH_REF29                          ((uint32_t)0x20000000)
#define ADC2_CHSEL_SL_CH_CH_REF30                          ((uint32_t)0x40000000)
#define ADC2_CHSEL_SL_CH_CH_REF31                          ((uint32_t)0x80000000)

/** @} */ /* End of group ADC2_CHSEL */

/** @} */ /* End of group ADC */

/** @defgroup MDR1901VC1T_Periph_DAC DAC
  * @{
  */


/* MDR_DAC_TypeDef structure */
typedef struct {
	__IO uint32_t	CFG;                    /*!<DAC Configuration Register */
	__IO uint32_t	DAC1_DATA;              /*!<DAC1 Data Register */
	__IO uint32_t	DAC2_DATA;              /*!<DAC2 Data Register */
}MDR_DAC_TypeDef;

/** @defgroup Periph_DAC_CFG  DAC_CFG
  * @{
  */

/*-- DAC_CFG: DAC_CFG Register -----*/

/* Bit field positions: */
#define DAC_CFG_M_REF0_Pos                                 0
#define DAC_CFG_M_REF1_Pos                                 1
#define DAC_CFG_ON_DAC0_Pos                                2
#define DAC_CFG_ON_DAC1_Pos                                3
#define DAC_CFG_SYNC_A_Pos                                 4

/* Bit field masks: */
#define DAC_CFG_M_REF0                                     ((uint32_t)0x00000001)
#define DAC_CFG_M_REF1                                     ((uint32_t)0x00000002)
#define DAC_CFG_ON_DAC0                                    ((uint32_t)0x00000004)
#define DAC_CFG_ON_DAC1                                    ((uint32_t)0x00000008)
#define DAC_CFG_SYNC_A                                     ((uint32_t)0x00000010)

/** @} */ /* End of group DAC_CFG */

/** @defgroup Periph_DAC1_DATA  DAC1_DATA
  * @{
  */

/*-- DAC1_DATA: DAC1_DATA Register -----*/

/* Bit field positions: */
#define DAC1_DATA_DAC0DATA_Pos                             0
#define DAC1_DATA_DAC1DATA_Pos                             16

/* Bit field masks: */
#define DAC1_DATA_DAC0DATA_Msk                             ((uint32_t)0x00000FFF)
#define DAC1_DATA_DAC1DATA_Msk                             ((uint32_t)0x0FFF0000)

/** @} */ /* End of group DAC1_DATA */

/** @defgroup Periph_DAC2_DATA  DAC2_DATA
  * @{
  */

/*-- DAC2_DATA: DAC2_DATA Register -----*/

/* Bit field positions: */
#define DAC2_DATA_DAC1DATA_Pos                             0
#define DAC2_DATA_DAC0DATA_Pos                             16

/* Bit field masks: */
#define DAC2_DATA_DAC1DATA_Msk                             ((uint32_t)0x00000FFF)
#define DAC2_DATA_DAC0DATA_Msk                             ((uint32_t)0x0FFF0000)

/** @} */ /* End of group DAC2_DATA */

/** @} */ /* End of group DAC */

/** @defgroup MDR1901VC1T_Periph_COMP COMP
  * @{
  */


/* MDR_COMP_TypeDef structure */
typedef struct {
	__IO uint32_t	CFG;                    /*!<COMP Configuration Register */
	__IO uint32_t	RESULT;                 /*!<COMP Result Register */
	__IO uint32_t	RESULT_LATCH;           /*!<COMP Result Latch Register */
}MDR_COMP_TypeDef;

/** @defgroup Periph_COMP_CFG COMP CFG
  * @{
  */

/*-- COMP_CFG:COMP CFG Register -----*/

/* Bit field positions: */
#define COMP_CFG_ON_Pos                                    0
#define COMP_CFG_CVRR_Pos                                  1
#define COMP_CFG_CVRSS_Pos                                 2
#define COMP_CFG_CVREN_Pos                                 3
#define COMP_CFG_CVR_Pos                                   4
#define COMP_CFG_CREF_Pos                                  8
#define COMP_CFG_CCH_Pos                                   9
#define COMP_CFG_INV_Pos                                   11
#define COMP_CFG_READY_Pos                                 12
#define COMP_CFG_CMPIE_Pos                                 13

/* Bit field masks: */
#define COMP_CFG_ON                                        ((uint32_t)0x00000001)
#define COMP_CFG_CVRR                                      ((uint32_t)0x00000002)
#define COMP_CFG_CVRSS                                     ((uint32_t)0x00000004)
#define COMP_CFG_CVREN                                     ((uint32_t)0x00000008)
#define COMP_CFG_CVR_Msk                                   ((uint32_t)0x000000F0)
#define COMP_CFG_CREF                                      ((uint32_t)0x00000100)
#define COMP_CFG_CCH_Msk                                   ((uint32_t)0x00000600)
#define COMP_CFG_INV                                       ((uint32_t)0x00000800)
#define COMP_CFG_READY                                     ((uint32_t)0x00001000)
#define COMP_CFG_CMPIE                                     ((uint32_t)0x00002000)

/** @} */ /* End of group COMP_CFG */

/** @defgroup Periph_COMP_RESULT COMP RESULT
  * @{
  */

/*-- COMP_RESULT:COMP RESULT Register -----*/

/* Bit field positions: */
#define COMP_RESULT_RSLT_SY_Pos                            0
#define COMP_RESULT_RSLT_AS_Pos                            1
#define COMP_RESULT_RST_LCH_Pos                            2

/* Bit field masks: */
#define COMP_RESULT_RSLT_SY                                ((uint32_t)0x00000001)
#define COMP_RESULT_RSLT_AS                                ((uint32_t)0x00000002)
#define COMP_RESULT_RST_LCH                                ((uint32_t)0x00000004)

/** @} */ /* End of group COMP_RESULT */

/** @defgroup Periph_COMP_RESULT_LATCH COMP RESULT_LATCH
  * @{
  */

/*-- COMP_RESULT_LATCH:COMP RESULT_LATCH Register -----*/

/* Bit field positions: */
#define COMP_RESULT_LATCH_RST_LCH_Pos                      0

/* Bit field masks: */
#define COMP_RESULT_LATCH_RST_LCH                          ((uint32_t)0x00000001)

/** @} */ /* End of group COMP_RESULT_LATCH */

/** @} */ /* End of group COMP */

/** @defgroup MDR1901VC1T_Periph_PORT PORT
  * @{
  */


/* MDR_PORTx_TypeDef structure */
typedef struct {
	__IO uint32_t	RXTX;                   /*!<PORT Data Register */
	__IO uint32_t	OE;                     /*!<PORT Output Enable Register */
	__IO uint32_t	FUNC;                   /*!<PORT Function Register */
	__IO uint32_t	ANALOG;                 /*!<PORT Analog Function Register */
	__IO uint32_t	PULL;                   /*!<PORT Pull Up/Down Register */
	__IO uint32_t	PD;                     /*!<PORT Driver Mode Register */
	__IO uint32_t	PWR;                    /*!<PORT Power Register */
	__IO uint32_t	GFEN;                   /*!<PORT Filter Configuration Register */
}MDR_PORT_TypeDef;

/** @defgroup Periph_PORT_RXTX PORT RXTX
  * @{
  */

/*-- PORT_RXTX:PORT RXTX Register -----*/

/* Bit field positions: */
#define PORT_RXTX_RXTX_Pos                                 0

/* Bit field masks: */
#define PORT_RXTX_RXTX_Msk                                 ((uint32_t)0x0000FFFF)

/** @} */ /* End of group PORT_RXTX */

/** @defgroup Periph_PORT_OE PORT OE
  * @{
  */

/*-- PORT_OE:PORT OE Register -----*/

/* Bit field positions: */
#define PORT_OE_OE_Pos                                     0

/* Bit field masks: */
#define PORT_OE_OE_Msk                                     ((uint32_t)0x0000FFFF)

/** @} */ /* End of group PORT_OE */

/** @defgroup Periph_PORT_FUNC PORT FUNC
  * @{
  */

/*-- PORT_FUNC:PORT FUNC Register -----*/

/* Bit field positions: */
#define PORT_FUNC_MODE0_Pos                                0
#define PORT_FUNC_MODE1_Pos                                2
#define PORT_FUNC_MODE2_Pos                                4
#define PORT_FUNC_MODE3_Pos                                6
#define PORT_FUNC_MODE4_Pos                                8
#define PORT_FUNC_MODE5_Pos                                10
#define PORT_FUNC_MODE6_Pos                                12
#define PORT_FUNC_MODE7_Pos                                14
#define PORT_FUNC_MODE8_Pos                                16
#define PORT_FUNC_MODE9_Pos                                18
#define PORT_FUNC_MODE10_Pos                               20
#define PORT_FUNC_MODE11_Pos                               22
#define PORT_FUNC_MODE12_Pos                               24
#define PORT_FUNC_MODE13_Pos                               26
#define PORT_FUNC_MODE14_Pos                               28
#define PORT_FUNC_MODE15_Pos                               30

/* Bit field masks: */
#define PORT_FUNC_MODE0_Msk                                ((uint32_t)0x00000003)
#define PORT_FUNC_MODE1_Msk                                ((uint32_t)0x0000000C)
#define PORT_FUNC_MODE2_Msk                                ((uint32_t)0x00000030)
#define PORT_FUNC_MODE3_Msk                                ((uint32_t)0x000000C0)
#define PORT_FUNC_MODE4_Msk                                ((uint32_t)0x00000300)
#define PORT_FUNC_MODE5_Msk                                ((uint32_t)0x00000C00)
#define PORT_FUNC_MODE6_Msk                                ((uint32_t)0x00003000)
#define PORT_FUNC_MODE7_Msk                                ((uint32_t)0x0000C000)
#define PORT_FUNC_MODE8_Msk                                ((uint32_t)0x00030000)
#define PORT_FUNC_MODE9_Msk                                ((uint32_t)0x000C0000)
#define PORT_FUNC_MODE10_Msk                               ((uint32_t)0x00300000)
#define PORT_FUNC_MODE11_Msk                               ((uint32_t)0x00C00000)
#define PORT_FUNC_MODE12_Msk                               ((uint32_t)0x03000000)
#define PORT_FUNC_MODE13_Msk                               ((uint32_t)0x0C000000)
#define PORT_FUNC_MODE14_Msk                               ((uint32_t)0x30000000)
#define PORT_FUNC_MODE15_Msk                               ((uint32_t)0xC0000000)

/** @} */ /* End of group PORT_FUNC */

/** @defgroup Periph_PORT_ANALOG PORT ANALOG
  * @{
  */

/*-- PORT_ANALOG:PORT ANALOG Register -----*/

/* Bit field positions: */
#define PORT_ANALOG_ANALOG_EN_Pos                          0

/* Bit field masks: */
#define PORT_ANALOG_ANALOG_EN_Msk                          ((uint32_t)0x0000FFFF)

/** @} */ /* End of group PORT_ANALOG */

/** @defgroup Periph_PORT_PULL PORT PULL
  * @{
  */

/*-- PORT_PULL:PORT PULL Register -----*/

/* Bit field positions: */
#define PORT_PULL_PULL_DOWN_Pos                            0
#define PORT_PULL_PULL_UP_Pos                              16

/* Bit field masks: */
#define PORT_PULL_PULL_DOWN_Msk                            ((uint32_t)0x0000FFFF)
#define PORT_PULL_PULL_UP_Msk                              ((uint32_t)0xFFFF0000)

/** @} */ /* End of group PORT_PULL */

/** @defgroup Periph_PORT_PD PORT PD
  * @{
  */

/*-- PORT_PD:PORT PD Register -----*/

/* Bit field positions: */
#define PORT_PD_PD_Pos                                     0
#define PORT_PD_SHM_Pos                                    16

/* Bit field masks: */
#define PORT_PD_PD_Msk                                     ((uint32_t)0x0000FFFF)
#define PORT_PD_SHM_Msk                                    ((uint32_t)0xFFFF0000)

/** @} */ /* End of group PORT_PD */

/** @defgroup Periph_PORT_PWR PORT PWR
  * @{
  */

/*-- PORT_PWR:PORT PWR Register -----*/

/* Bit field positions: */
#define PORT_PWR_PWR0_Pos                                  0
#define PORT_PWR_PWR1_Pos                                  2
#define PORT_PWR_PWR2_Pos                                  4
#define PORT_PWR_PWR3_Pos                                  6
#define PORT_PWR_PWR4_Pos                                  8
#define PORT_PWR_PWR5_Pos                                  10
#define PORT_PWR_PWR6_Pos                                  12
#define PORT_PWR_PWR7_Pos                                  14
#define PORT_PWR_PWR8_Pos                                  16
#define PORT_PWR_PWR9_Pos                                  18
#define PORT_PWR_PWR10_Pos                                 20
#define PORT_PWR_PWR11_Pos                                 22
#define PORT_PWR_PWR12_Pos                                 24
#define PORT_PWR_PWR13_Pos                                 26
#define PORT_PWR_PWR14_Pos                                 28
#define PORT_PWR_PWR15_Pos                                 30

/* Bit field masks: */
#define PORT_PWR_PWR0_Msk                                  ((uint32_t)0x00000003)
#define PORT_PWR_PWR1_Msk                                  ((uint32_t)0x0000000C)
#define PORT_PWR_PWR2_Msk                                  ((uint32_t)0x00000030)
#define PORT_PWR_PWR3_Msk                                  ((uint32_t)0x000000C0)
#define PORT_PWR_PWR4_Msk                                  ((uint32_t)0x00000300)
#define PORT_PWR_PWR5_Msk                                  ((uint32_t)0x00000C00)
#define PORT_PWR_PWR6_Msk                                  ((uint32_t)0x00003000)
#define PORT_PWR_PWR7_Msk                                  ((uint32_t)0x0000C000)
#define PORT_PWR_PWR8_Msk                                  ((uint32_t)0x00030000)
#define PORT_PWR_PWR9_Msk                                  ((uint32_t)0x000C0000)
#define PORT_PWR_PWR10_Msk                                 ((uint32_t)0x00300000)
#define PORT_PWR_PWR11_Msk                                 ((uint32_t)0x00C00000)
#define PORT_PWR_PWR12_Msk                                 ((uint32_t)0x03000000)
#define PORT_PWR_PWR13_Msk                                 ((uint32_t)0x0C000000)
#define PORT_PWR_PWR14_Msk                                 ((uint32_t)0x30000000)
#define PORT_PWR_PWR15_Msk                                 ((uint32_t)0xC0000000)

/** @} */ /* End of group PORT_PWR */

/** @defgroup Periph_PORT_GFEN PORT GFEN
  * @{
  */

/*-- PORT_GFEN:PORT GFEN Register -----*/

/* Bit field positions: */
#define PORT_GFEN_GFEN_Pos                                 0

/* Bit field masks: */
#define PORT_GFEN_GFEN_Msk                                 ((uint32_t)0x0000FFFF)

/** @} */ /* End of group PORT_GFEN */

/** @} */ /* End of group PORT */

/** @defgroup MDR1901VC1T_Periph_BKP BKP
  * @{
  */


/* MDR_BKP_TypeDef structure */
typedef struct {
	__IO uint32_t	REG_00;                 /*!<Backup Register 0 */
	__IO uint32_t	REG_01;                 /*!<Backup Register 1 */
	__IO uint32_t	REG_02;                 /*!<Backup Register 2 */
	__IO uint32_t	REG_03;                 /*!<Backup Register 3 */
	__IO uint32_t	REG_04;                 /*!<Backup Register 4 */
	__IO uint32_t	REG_05;                 /*!<Backup Register 5 */
	__IO uint32_t	REG_06;                 /*!<Backup Register 6 */
	__IO uint32_t	REG_07;                 /*!<Backup Register 7 */
	__IO uint32_t	REG_08;                 /*!<Backup Register 8 */
	__IO uint32_t	REG_09;                 /*!<Backup Register 9 */
	__IO uint32_t	REG_0A;                 /*!<Backup Register 10 */
	__IO uint32_t	REG_0B;                 /*!<Backup Register 11 */
	__IO uint32_t	REG_0C;                 /*!<Backup Register 12 */
	__IO uint32_t	REG_0D;                 /*!<Backup Register 13 */
	__IO uint32_t	REG_0E;                 /*!<Backup Register 14 */
	__IO uint32_t	REG_0F;                 /*!<Backup Register 15 */
	__IO uint32_t	RTC_CNT;                /*!<Realtime Clock Counter Register */
	__IO uint32_t	RTC_DIV;                /*!<Realtime Prescaler Counter Register */
	__IO uint32_t	RTC_PRL;                /*!<Realtime Prescaler Auto-Reload Value Register */
	__IO uint32_t	RTC_ALRM;               /*!<Realtime Alarm Register */
	__IO uint32_t	RTC_CS;                 /*!<Backup Realtime clock Register */
}MDR_BKP_TypeDef;

/** @defgroup Periph_BKP_REG_00 BKP REG_00
  * @{
  */

/*-- BKP_REG_00:BKP REG_00 Register -----*/

/* Bit field positions: */
#define BKP_REG_00_BKP_REG_Pos                             0

/* Bit field masks: */
#define BKP_REG_00_BKP_REG_Msk                             ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group BKP_REG_00 */

/** @defgroup Periph_BKP_REG_01 BKP REG_01
  * @{
  */

/*-- BKP_REG_01:BKP REG_01 Register -----*/

/* Bit field positions: */
#define BKP_REG_01_BKP_REG_Pos                             0

/* Bit field masks: */
#define BKP_REG_01_BKP_REG_Msk                             ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group BKP_REG_01 */

/** @defgroup Periph_BKP_REG_02 BKP REG_02
  * @{
  */

/*-- BKP_REG_02:BKP REG_02 Register -----*/

/* Bit field positions: */
#define BKP_REG_02_BKP_REG_Pos                             0

/* Bit field masks: */
#define BKP_REG_02_BKP_REG_Msk                             ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group BKP_REG_02 */

/** @defgroup Periph_BKP_REG_03 BKP REG_03
  * @{
  */

/*-- BKP_REG_03:BKP REG_03 Register -----*/

/* Bit field positions: */
#define BKP_REG_03_BKP_REG_Pos                             0

/* Bit field masks: */
#define BKP_REG_03_BKP_REG_Msk                             ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group BKP_REG_03 */

/** @defgroup Periph_BKP_REG_04 BKP REG_04
  * @{
  */

/*-- BKP_REG_04:BKP REG_04 Register -----*/

/* Bit field positions: */
#define BKP_REG_04_BKP_REG_Pos                             0

/* Bit field masks: */
#define BKP_REG_04_BKP_REG_Msk                             ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group BKP_REG_04 */

/** @defgroup Periph_BKP_REG_05 BKP REG_05
  * @{
  */

/*-- BKP_REG_05:BKP REG_05 Register -----*/

/* Bit field positions: */
#define BKP_REG_05_BKP_REG_Pos                             0

/* Bit field masks: */
#define BKP_REG_05_BKP_REG_Msk                             ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group BKP_REG_05 */

/** @defgroup Periph_BKP_REG_06 BKP REG_06
  * @{
  */

/*-- BKP_REG_06:BKP REG_06 Register -----*/

/* Bit field positions: */
#define BKP_REG_06_BKP_REG_Pos                             0

/* Bit field masks: */
#define BKP_REG_06_BKP_REG_Msk                             ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group BKP_REG_06 */

/** @defgroup Periph_BKP_REG_07 BKP REG_07
  * @{
  */

/*-- BKP_REG_07:BKP REG_07 Register -----*/

/* Bit field positions: */
#define BKP_REG_07_BKP_REG_Pos                             0

/* Bit field masks: */
#define BKP_REG_07_BKP_REG_Msk                             ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group BKP_REG_07 */

/** @defgroup Periph_BKP_REG_08 BKP REG_08
  * @{
  */

/*-- BKP_REG_08:BKP REG_08 Register -----*/

/* Bit field positions: */
#define BKP_REG_08_BKP_REG_Pos                             0

/* Bit field masks: */
#define BKP_REG_08_BKP_REG_Msk                             ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group BKP_REG_08 */

/** @defgroup Periph_BKP_REG_09 BKP REG_09
  * @{
  */

/*-- BKP_REG_09:BKP REG_09 Register -----*/

/* Bit field positions: */
#define BKP_REG_09_BKP_REG_Pos                             0

/* Bit field masks: */
#define BKP_REG_09_BKP_REG_Msk                             ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group BKP_REG_09 */

/** @defgroup Periph_BKP_REG_0A BKP REG_0A
  * @{
  */

/*-- BKP_REG_0A:BKP REG_0A Register -----*/

/* Bit field positions: */
#define BKP_REG_0A_BKP_REG_Pos                             0

/* Bit field masks: */
#define BKP_REG_0A_BKP_REG_Msk                             ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group BKP_REG_0A */

/** @defgroup Periph_BKP_REG_0B BKP REG_0B
  * @{
  */

/*-- BKP_REG_0B:BKP REG_0B Register -----*/

/* Bit field positions: */
#define BKP_REG_0B_BKP_REG_Pos                             0

/* Bit field masks: */
#define BKP_REG_0B_BKP_REG_Msk                             ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group BKP_REG_0B */

/** @defgroup Periph_BKP_REG_0C BKP REG_0C
  * @{
  */

/*-- BKP_REG_0C:BKP REG_0C Register -----*/

/* Bit field positions: */
#define BKP_REG_0C_BKP_REG_Pos                             0

/* Bit field masks: */
#define BKP_REG_0C_BKP_REG_Msk                             ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group BKP_REG_0C */

/** @defgroup Periph_BKP_REG_0D BKP REG_0D
  * @{
  */

/*-- BKP_REG_0D:BKP REG_0D Register -----*/

/* Bit field positions: */
#define BKP_REG_0D_BKP_REG_Pos                             0

/* Bit field masks: */
#define BKP_REG_0D_BKP_REG_Msk                             ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group BKP_REG_0D */

/** @defgroup Periph_BKP_REG_0E BKP REG_0E
  * @{
  */

/*-- BKP_REG_0E:BKP REG_0E Register -----*/

/* Bit field positions: */
#define BKP_REG_0E_LOW_Pos                                 0
#define BKP_REG_0E_SELECTRI_Pos                            3
#define BKP_REG_0E_JTAGA_Pos                               6
#define BKP_REG_0E_JTAGB_Pos                               7
#define BKP_REG_0E_TRIM_Pos                                8
#define BKP_REG_0E_FPOR_Pos                                11
#define BKP_REG_0E_MODE_Pos                                12

/* Bit field masks: */
#define BKP_REG_0E_LOW_Msk                                 ((uint32_t)0x00000007)
#define BKP_REG_0E_SELECTRI_Msk                            ((uint32_t)0x00000038)
#define BKP_REG_0E_JTAGA                                   ((uint32_t)0x00000040)
#define BKP_REG_0E_JTAGB                                   ((uint32_t)0x00000080)
#define BKP_REG_0E_TRIM_Msk                                ((uint32_t)0x00000700)
#define BKP_REG_0E_FPOR                                    ((uint32_t)0x00000800)
#define BKP_REG_0E_MODE_Msk                                ((uint32_t)0x00007000)

/** @} */ /* End of group BKP_REG_0E */

/** @defgroup Periph_BKP_REG_0F BKP REG_0F
  * @{
  */

/*-- BKP_REG_0F:BKP REG_0F Register -----*/

/* Bit field positions: */
#define BKP_REG_0F_LSE_ON_Pos                              0
#define BKP_REG_0F_LSE_BYP_Pos                             1
#define BKP_REG_0F_RTC_SEL_Pos                             2
#define BKP_REG_0F_RTC_EN_Pos                              4
#define BKP_REG_0F_CAL_Pos                                 5
#define BKP_REG_0F_LSE_RDY_Pos                             13
#define BKP_REG_0F_LSI_ON_Pos                              15
#define BKP_REG_0F_LSI_TRIM_Pos                            16
#define BKP_REG_0F_LSI_RDY_Pos                             21
#define BKP_REG_0F_HSI_ON_Pos                              22
#define BKP_REG_0F_HSI_RDY_Pos                             23
#define BKP_REG_0F_HSI_TRIM_Pos                            24
#define BKP_REG_0F_STANDBY_Pos                             30
#define BKP_REG_0F_RTC_RESET_Pos                           31

/* Bit field masks: */
#define BKP_REG_0F_LSE_ON                                  ((uint32_t)0x00000001)
#define BKP_REG_0F_LSE_BYP                                 ((uint32_t)0x00000002)
#define BKP_REG_0F_RTC_SEL_Msk                             ((uint32_t)0x0000000C)
#define BKP_REG_0F_RTC_EN                                  ((uint32_t)0x00000010)
#define BKP_REG_0F_CAL_Msk                                 ((uint32_t)0x00001FE0)
#define BKP_REG_0F_LSE_RDY                                 ((uint32_t)0x00002000)
#define BKP_REG_0F_LSI_ON                                  ((uint32_t)0x00008000)
#define BKP_REG_0F_LSI_TRIM_Msk                            ((uint32_t)0x001F0000)
#define BKP_REG_0F_LSI_RDY                                 ((uint32_t)0x00200000)
#define BKP_REG_0F_HSI_ON                                  ((uint32_t)0x00400000)
#define BKP_REG_0F_HSI_RDY                                 ((uint32_t)0x00800000)
#define BKP_REG_0F_HSI_TRIM_Msk                            ((uint32_t)0x3F000000)
#define BKP_REG_0F_STANDBY                                 ((uint32_t)0x40000000)
#define BKP_REG_0F_RTC_RESET                               ((uint32_t)0x80000000)

/** @} */ /* End of group BKP_REG_0F */

/** @defgroup Periph_BKP_RTC_CNT BKP RTC_CNT
  * @{
  */

/*-- BKP_RTC_CNT:BKP RTC_CNT Register -----*/

/* Bit field positions: */
#define BKP_RTC_CNT_RTC_CNT_Pos                            0

/* Bit field masks: */
#define BKP_RTC_CNT_RTC_CNT_Msk                            ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group BKP_RTC_CNT */

/** @defgroup Periph_BKP_RTC_DIV BKP RTC_DIV
  * @{
  */

/*-- BKP_RTC_DIV:BKP RTC_DIV Register -----*/

/* Bit field positions: */
#define BKP_RTC_DIV_RTC_DIV_Pos                            0

/* Bit field masks: */
#define BKP_RTC_DIV_RTC_DIV_Msk                            ((uint32_t)0x000FFFFF)

/** @} */ /* End of group BKP_RTC_DIV */

/** @defgroup Periph_BKP_RTC_PRL BKP RTC_PRL
  * @{
  */

/*-- BKP_RTC_PRL:BKP RTC_PRL Register -----*/

/* Bit field positions: */
#define BKP_RTC_PRL_RTC_PRL_Pos                            0

/* Bit field masks: */
#define BKP_RTC_PRL_RTC_PRL_Msk                            ((uint32_t)0x000FFFFF)

/** @} */ /* End of group BKP_RTC_PRL */

/** @defgroup Periph_BKP_RTC_ALRM BKP RTC_ALRM
  * @{
  */

/*-- BKP_RTC_ALRM:BKP RTC_ALRM Register -----*/

/* Bit field positions: */
#define BKP_RTC_ALRM_RTC_ALRM_Pos                          0

/* Bit field masks: */
#define BKP_RTC_ALRM_RTC_ALRM_Msk                          ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group BKP_RTC_ALRM */

/** @defgroup Periph_BKP_RTC_CS BKP RTC_CS
  * @{
  */

/*-- BKP_RTC_CS:BKP RTC_CS Register -----*/

/* Bit field positions: */
#define BKP_RTC_CS_OWF_Pos                                 0
#define BKP_RTC_CS_SECF_Pos                                1
#define BKP_RTC_CS_ALRF_Pos                                2
#define BKP_RTC_CS_OWF_IE_Pos                              3
#define BKP_RTC_CS_SECF_IE_Pos                             4
#define BKP_RTC_CS_ALRF_IE_Pos                             5
#define BKP_RTC_CS_WEC_Pos                                 6

/* Bit field masks: */
#define BKP_RTC_CS_OWF                                     ((uint32_t)0x00000001)
#define BKP_RTC_CS_SECF                                    ((uint32_t)0x00000002)
#define BKP_RTC_CS_ALRF                                    ((uint32_t)0x00000004)
#define BKP_RTC_CS_OWF_IE                                  ((uint32_t)0x00000008)
#define BKP_RTC_CS_SECF_IE                                 ((uint32_t)0x00000010)
#define BKP_RTC_CS_ALRF_IE                                 ((uint32_t)0x00000020)
#define BKP_RTC_CS_WEC                                     ((uint32_t)0x00000040)

/** @} */ /* End of group BKP_RTC_CS */

/** @} */ /* End of group BKP */

/** @defgroup MDR1901VC1T_Periph_EBC EBC
  * @{
  */


/* MDR_EBC_TypeDef structure */
typedef struct {
	__I  uint32_t	RESERVED0[20];
	__IO uint32_t	NAND_CYCLES;            /*!<EBC NAND Timing Register */
	__IO uint32_t	CONTROL;                /*!<EBC Control Register */
}MDR_EBC_TypeDef;

/** @defgroup Periph_EBC_NAND_CYCLES EBC NAND_CYCLES
  * @{
  */

/*-- EBC_NAND_CYCLES:EBC NAND_CYCLES Register -----*/

/* Bit field positions: */
#define EBC_NAND_CYCLES_TRC_Pos                            0
#define EBC_NAND_CYCLES_TWC_Pos                            4
#define EBC_NAND_CYCLES_TREA_Pos                           8
#define EBC_NAND_CYCLES_TWP_Pos                            12
#define EBC_NAND_CYCLES_TWHR_Pos                           16
#define EBC_NAND_CYCLES_TALEA_Pos                          20
#define EBC_NAND_CYCLES_TRR_Pos                            24

/* Bit field masks: */
#define EBC_NAND_CYCLES_TRC_Msk                            ((uint32_t)0x0000000F)
#define EBC_NAND_CYCLES_TWC_Msk                            ((uint32_t)0x000000F0)
#define EBC_NAND_CYCLES_TREA_Msk                           ((uint32_t)0x00000F00)
#define EBC_NAND_CYCLES_TWP_Msk                            ((uint32_t)0x0000F000)
#define EBC_NAND_CYCLES_TWHR_Msk                           ((uint32_t)0x000F0000)
#define EBC_NAND_CYCLES_TALEA_Msk                          ((uint32_t)0x00F00000)
#define EBC_NAND_CYCLES_TRR_Msk                            ((uint32_t)0x0F000000)

/** @} */ /* End of group EBC_NAND_CYCLES */

/** @defgroup Periph_EBC_CONTROL EBC CONTROL
  * @{
  */

/*-- EBC_CONTROL:EBC CONTROL Register -----*/

/* Bit field positions: */
#define EBC_CONTROL_ROM_Pos                                0
#define EBC_CONTROL_RAM_Pos                                1
#define EBC_CONTROL_NAND_Pos                               2
#define EBC_CONTROL_CPOL_Pos                               3
#define EBC_CONTROL_BUSY_Pos                               7
#define EBC_CONTROL_WAIT_STATE_Pos                         12

/* Bit field masks: */
#define EBC_CONTROL_ROM                                    ((uint32_t)0x00000001)
#define EBC_CONTROL_RAM                                    ((uint32_t)0x00000002)
#define EBC_CONTROL_NAND                                   ((uint32_t)0x00000004)
#define EBC_CONTROL_CPOL                                   ((uint32_t)0x00000008)
#define EBC_CONTROL_BUSY                                   ((uint32_t)0x00000080)
#define EBC_CONTROL_WAIT_STATE_Msk                         ((uint32_t)0x0000F000)

/** @} */ /* End of group EBC_CONTROL */

/** @} */ /* End of group EBC */

/** @defgroup MDR1901VC1T_Periph_DSP_CORE DSP_CORE
  * @{
  */


/* MDR_DSP_CORE_TypeDef structure */
typedef struct {
	__I  uint32_t	RESERVED0[47];
	__IO uint32_t	CLKCMD;                 /*!< */
	__IO uint32_t	DIR;                    /*!< */
	__IO uint32_t	AIR;                    /*!< */
}MDR_DSP_CORE_TypeDef;

/** @defgroup Periph_DSP_CORE_CLKCMD DSP_CORE CLKCMD
  * @{
  */

/*-- DSP_CORE_CLKCMD:DSP_CORE CLKCMD Register -----*/

/* Bit field positions: */
#define DSP_CORE_CLKCMD_CRP_Pos                            3
#define DSP_CORE_CLKCMD_CDC_Pos                            4
#define DSP_CORE_CLKCMD_TMR_Pos                            5
#define DSP_CORE_CLKCMD_DMA_Pos                            6
#define DSP_CORE_CLKCMD_MC3_Pos                            7
#define DSP_CORE_CLKCMD_PC3_Pos                            8
#define DSP_CORE_CLKCMD_MC2_Pos                            9
#define DSP_CORE_CLKCMD_PC2_Pos                            10
#define DSP_CORE_CLKCMD_MC1_Pos                            11
#define DSP_CORE_CLKCMD_PC1_Pos                            12
#define DSP_CORE_CLKCMD_CDM_Pos                            13
#define DSP_CORE_CLKCMD_CPM_Pos                            14
#define DSP_CORE_CLKCMD_CPU_Pos                            15

/* Bit field masks: */
#define DSP_CORE_CLKCMD_CRP                                ((uint32_t)0x00000008)
#define DSP_CORE_CLKCMD_CDC                                ((uint32_t)0x00000010)
#define DSP_CORE_CLKCMD_TMR                                ((uint32_t)0x00000020)
#define DSP_CORE_CLKCMD_DMA                                ((uint32_t)0x00000040)
#define DSP_CORE_CLKCMD_MC3                                ((uint32_t)0x00000080)
#define DSP_CORE_CLKCMD_PC3                                ((uint32_t)0x00000100)
#define DSP_CORE_CLKCMD_MC2                                ((uint32_t)0x00000200)
#define DSP_CORE_CLKCMD_PC2                                ((uint32_t)0x00000400)
#define DSP_CORE_CLKCMD_MC1                                ((uint32_t)0x00000800)
#define DSP_CORE_CLKCMD_PC1                                ((uint32_t)0x00001000)
#define DSP_CORE_CLKCMD_CDM                                ((uint32_t)0x00002000)
#define DSP_CORE_CLKCMD_CPM                                ((uint32_t)0x00004000)
#define DSP_CORE_CLKCMD_CPU                                ((uint32_t)0x00008000)

/** @} */ /* End of group DSP_CORE_CLKCMD */

/** @defgroup Periph_DSP_CORE_DIR DSP_CORE DIR
  * @{
  */

/*-- DSP_CORE_DIR:DSP_CORE DIR Register -----*/

/* Bit field positions: */
#define DSP_CORE_DIR_DIRQ0_Pos                             0
#define DSP_CORE_DIR_DIRQ1_Pos                             1
#define DSP_CORE_DIR_DIRQ2_Pos                             2
#define DSP_CORE_DIR_DIRQ3_Pos                             3
#define DSP_CORE_DIR_TIR_Pos                               4
#define DSP_CORE_DIR_RIRQ1_Pos                             5
#define DSP_CORE_DIR_XIRQ1_Pos                             6
#define DSP_CORE_DIR_RIRQ2_Pos                             7
#define DSP_CORE_DIR_XIRQ2_Pos                             8
#define DSP_CORE_DIR_RIRQ3_Pos                             9
#define DSP_CORE_DIR_XIRQ3_Pos                             10
#define DSP_CORE_DIR_CDIRQ_Pos                             11
#define DSP_CORE_DIR_CRIRQ_Pos                             12
#define DSP_CORE_DIR_DMAIRQ_Pos                            13
#define DSP_CORE_DIR_SNR_Pos                               15

/* Bit field masks: */
#define DSP_CORE_DIR_DIRQ0                                 ((uint32_t)0x00000001)
#define DSP_CORE_DIR_DIRQ1                                 ((uint32_t)0x00000002)
#define DSP_CORE_DIR_DIRQ2                                 ((uint32_t)0x00000004)
#define DSP_CORE_DIR_DIRQ3                                 ((uint32_t)0x00000008)
#define DSP_CORE_DIR_TIR                                   ((uint32_t)0x00000010)
#define DSP_CORE_DIR_RIRQ1                                 ((uint32_t)0x00000020)
#define DSP_CORE_DIR_XIRQ1                                 ((uint32_t)0x00000040)
#define DSP_CORE_DIR_RIRQ2                                 ((uint32_t)0x00000080)
#define DSP_CORE_DIR_XIRQ2                                 ((uint32_t)0x00000100)
#define DSP_CORE_DIR_RIRQ3                                 ((uint32_t)0x00000200)
#define DSP_CORE_DIR_XIRQ3                                 ((uint32_t)0x00000400)
#define DSP_CORE_DIR_CDIRQ                                 ((uint32_t)0x00000800)
#define DSP_CORE_DIR_CRIRQ                                 ((uint32_t)0x00001000)
#define DSP_CORE_DIR_DMAIRQ                                ((uint32_t)0x00002000)
#define DSP_CORE_DIR_SNR                                   ((uint32_t)0x00008000)

/** @} */ /* End of group DSP_CORE_DIR */

/** @defgroup Periph_DSP_CORE_AIR DSP_CORE AIR
  * @{
  */

/*-- DSP_CORE_AIR:DSP_CORE AIR Register -----*/

/* Bit field positions: */
#define DSP_CORE_AIR_AIRQ0_Pos                             0
#define DSP_CORE_AIR_AIRQ1_Pos                             1
#define DSP_CORE_AIR_AIRQ2_Pos                             2
#define DSP_CORE_AIR_AIRQ3_Pos                             3
#define DSP_CORE_AIR_ANMI_Pos                              4
#define DSP_CORE_AIR_ADMARQ0_Pos                           6
#define DSP_CORE_AIR_ADMARQ1_Pos                           7
#define DSP_CORE_AIR_ADMARQ2_Pos                           8
#define DSP_CORE_AIR_ADMARQ3_Pos                           9
#define DSP_CORE_AIR_ADMADONE0_Pos                         10
#define DSP_CORE_AIR_ADMADONE1_Pos                         11
#define DSP_CORE_AIR_ADMADONE2_Pos                         12
#define DSP_CORE_AIR_ADMADONE3_Pos                         13
#define DSP_CORE_AIR_SID_Pos                               14
#define DSP_CORE_AIR_SNR_Pos                               15

/* Bit field masks: */
#define DSP_CORE_AIR_AIRQ0                                 ((uint32_t)0x00000001)
#define DSP_CORE_AIR_AIRQ1                                 ((uint32_t)0x00000002)
#define DSP_CORE_AIR_AIRQ2                                 ((uint32_t)0x00000004)
#define DSP_CORE_AIR_AIRQ3                                 ((uint32_t)0x00000008)
#define DSP_CORE_AIR_ANMI                                  ((uint32_t)0x00000010)
#define DSP_CORE_AIR_ADMARQ0                               ((uint32_t)0x00000040)
#define DSP_CORE_AIR_ADMARQ1                               ((uint32_t)0x00000080)
#define DSP_CORE_AIR_ADMARQ2                               ((uint32_t)0x00000100)
#define DSP_CORE_AIR_ADMARQ3                               ((uint32_t)0x00000200)
#define DSP_CORE_AIR_ADMADONE0                             ((uint32_t)0x00000400)
#define DSP_CORE_AIR_ADMADONE1                             ((uint32_t)0x00000800)
#define DSP_CORE_AIR_ADMADONE2                             ((uint32_t)0x00001000)
#define DSP_CORE_AIR_ADMADONE3                             ((uint32_t)0x00002000)
#define DSP_CORE_AIR_SID                                   ((uint32_t)0x00004000)
#define DSP_CORE_AIR_SNR                                   ((uint32_t)0x00008000)

/** @} */ /* End of group DSP_CORE_AIR */

/** @} */ /* End of group DSP_CORE */

/** @defgroup MDR1901VC1T_Periph_AUDIO_IP AUDIO_IP
  * @{
  */


/* MDR_AUDIO_IP_TypeDef structure */
typedef struct {
	__IO uint32_t	POWCTL;                 /*!<AUDIO control register */
	__IO uint32_t	ADCCTL;                 /*!<ADC control register */
	__IO uint32_t	DACCTL;                 /*!<DAC control register */
	__IO uint32_t	MASKCTL;                /*!<IRQ mask register */
	__IO uint32_t	IRQFLAG;                /*!<IRQ flag register */
	__IO uint32_t	ADCREG;                 /*!<ADC FIFO register */
	__IO uint32_t	DACREG;                 /*!<DAC FIFO register */
}MDR_AUDIO_IP_TypeDef;

/** @defgroup Periph_AUDIO_IP_POWCTL AUDIO_IP POWCTL
  * @{
  */

/*-- AUDIO_IP_POWCTL:AUDIO_IP POWCTL Register -----*/

/* Bit field positions: */
#define AUDIO_IP_POWCTL_ADCEN_Pos                          0
#define AUDIO_IP_POWCTL_DACEN_Pos                          1
#define AUDIO_IP_POWCTL_IIREN_Pos                          2
#define AUDIO_IP_POWCTL_ALB_Pos                            3
#define AUDIO_IP_POWCTL_DLB_Pos                            4

/* Bit field masks: */
#define AUDIO_IP_POWCTL_ADCEN                              ((uint32_t)0x00000001)
#define AUDIO_IP_POWCTL_DACEN                              ((uint32_t)0x00000002)
#define AUDIO_IP_POWCTL_IIREN                              ((uint32_t)0x00000004)
#define AUDIO_IP_POWCTL_ALB                                ((uint32_t)0x00000008)
#define AUDIO_IP_POWCTL_DLB                                ((uint32_t)0x00000010)

/** @} */ /* End of group AUDIO_IP_POWCTL */

/** @defgroup Periph_AUDIO_IP_ADCCTL AUDIO_IP ADCCTL
  * @{
  */

/*-- AUDIO_IP_ADCCTL:AUDIO_IP ADCCTL Register -----*/

/* Bit field positions: */
#define AUDIO_IP_ADCCTL_ADGAIN_Pos                         0
#define AUDIO_IP_ADCCTL_INBG_Pos                           6
#define AUDIO_IP_ADCCTL_AINSEL_Pos                         8
#define AUDIO_IP_ADCCTL_ICONT_Pos                          10

/* Bit field masks: */
#define AUDIO_IP_ADCCTL_ADGAIN_Msk                         ((uint32_t)0x0000003F)
#define AUDIO_IP_ADCCTL_INBG_Msk                           ((uint32_t)0x000000C0)
#define AUDIO_IP_ADCCTL_AINSEL_Msk                         ((uint32_t)0x00000300)
#define AUDIO_IP_ADCCTL_ICONT                              ((uint32_t)0x00000400)

/** @} */ /* End of group AUDIO_IP_ADCCTL */

/** @defgroup Periph_AUDIO_IP_DACCTL AUDIO_IP DACCTL
  * @{
  */

/*-- AUDIO_IP_DACCTL:AUDIO_IP DACCTL Register -----*/

/* Bit field positions: */
#define AUDIO_IP_DACCTL_DAGAIN_Pos                         0
#define AUDIO_IP_DACCTL_MUTE1_Pos                          6
#define AUDIO_IP_DACCTL_ODAMP_Pos                          7
#define AUDIO_IP_DACCTL_ODBIAS_Pos                         8
#define AUDIO_IP_DACCTL_ODDAC_Pos                          9
#define AUDIO_IP_DACCTL_OVECBA_Pos                         10
#define AUDIO_IP_DACCTL_OVECBS_Pos                         11
#define AUDIO_IP_DACCTL_SIDETONE_Pos                       12
#define AUDIO_IP_DACCTL_DACRES_Pos                         15

/* Bit field masks: */
#define AUDIO_IP_DACCTL_DAGAIN_Msk                         ((uint32_t)0x0000003F)
#define AUDIO_IP_DACCTL_MUTE1                              ((uint32_t)0x00000040)
#define AUDIO_IP_DACCTL_ODAMP                              ((uint32_t)0x00000080)
#define AUDIO_IP_DACCTL_ODBIAS                             ((uint32_t)0x00000100)
#define AUDIO_IP_DACCTL_ODDAC                              ((uint32_t)0x00000200)
#define AUDIO_IP_DACCTL_OVECBA                             ((uint32_t)0x00000400)
#define AUDIO_IP_DACCTL_OVECBS                             ((uint32_t)0x00000800)
#define AUDIO_IP_DACCTL_SIDETONE_Msk                       ((uint32_t)0x00007000)
#define AUDIO_IP_DACCTL_DACRES                             ((uint32_t)0x00008000)

/** @} */ /* End of group AUDIO_IP_DACCTL */

/** @defgroup Periph_AUDIO_IP_MASKCTL AUDIO_IP MASKCTL
  * @{
  */

/*-- AUDIO_IP_MASKCTL:AUDIO_IP MASKCTL Register -----*/

/* Bit field positions: */
#define AUDIO_IP_MASKCTL_DAOVFM_Pos                        0
#define AUDIO_IP_MASKCTL_ADCVFM_Pos                        1
#define AUDIO_IP_MASKCTL_ADCNSM_Pos                        2
#define AUDIO_IP_MASKCTL_DACNSM_Pos                        3
#define AUDIO_IP_MASKCTL_OVERCURM_Pos                      4

/* Bit field masks: */
#define AUDIO_IP_MASKCTL_DAOVFM                            ((uint32_t)0x00000001)
#define AUDIO_IP_MASKCTL_ADCVFM                            ((uint32_t)0x00000002)
#define AUDIO_IP_MASKCTL_ADCNSM                            ((uint32_t)0x00000004)
#define AUDIO_IP_MASKCTL_DACNSM                            ((uint32_t)0x00000008)
#define AUDIO_IP_MASKCTL_OVERCURM                          ((uint32_t)0x00000010)

/** @} */ /* End of group AUDIO_IP_MASKCTL */

/** @defgroup Periph_AUDIO_IP_IRQFLAG AUDIO_IP IRQFLAG
  * @{
  */

/*-- AUDIO_IP_IRQFLAG:AUDIO_IP IRQFLAG Register -----*/

/* Bit field positions: */
#define AUDIO_IP_IRQFLAG_DAOVF_Pos                         0
#define AUDIO_IP_IRQFLAG_ADCVF_Pos                         1
#define AUDIO_IP_IRQFLAG_ADCNS_Pos                         2
#define AUDIO_IP_IRQFLAG_DACNS_Pos                         3
#define AUDIO_IP_IRQFLAG_OVERVCUR_Pos                      4

/* Bit field masks: */
#define AUDIO_IP_IRQFLAG_DAOVF                             ((uint32_t)0x00000001)
#define AUDIO_IP_IRQFLAG_ADCVF                             ((uint32_t)0x00000002)
#define AUDIO_IP_IRQFLAG_ADCNS                             ((uint32_t)0x00000004)
#define AUDIO_IP_IRQFLAG_DACNS                             ((uint32_t)0x00000008)
#define AUDIO_IP_IRQFLAG_OVERVCUR                          ((uint32_t)0x00000010)

/** @} */ /* End of group AUDIO_IP_IRQFLAG */

/** @defgroup Periph_AUDIO_IP_ADCREG AUDIO_IP ADCREG
  * @{
  */

/*-- AUDIO_IP_ADCREG:AUDIO_IP ADCREG Register -----*/

/* Bit field positions: */
#define AUDIO_IP_ADCREG_ADCSMP_Pos                         0

/* Bit field masks: */
#define AUDIO_IP_ADCREG_ADCSMP_Msk                         ((uint32_t)0x0000FFFF)

/** @} */ /* End of group AUDIO_IP_ADCREG */

/** @defgroup Periph_AUDIO_IP_DACREG AUDIO_IP DACREG
  * @{
  */

/*-- AUDIO_IP_DACREG:AUDIO_IP DACREG Register -----*/

/* Bit field positions: */
#define AUDIO_IP_DACREG_DACSMP_Pos                         0

/* Bit field masks: */
#define AUDIO_IP_DACREG_DACSMP_Msk                         ((uint32_t)0x0000FFFF)

/** @} */ /* End of group AUDIO_IP_DACREG */

/** @} */ /* End of group AUDIO_IP */

/** @defgroup MDR1901VC1T_Periph_MCBSP MCBSP
  * @{
  */


/* MDR_MCBSPx_TypeDef structure */
typedef struct {
	__IO uint32_t	DRR;                    /*!< */
	__IO uint32_t	DXR;                    /*!< */
	__IO uint32_t	SPSA;                   /*!< */
	__IO uint32_t	SPCR;                   /*!< */
	__IO uint32_t	RCR;                    /*!< */
	__IO uint32_t	XCR;                    /*!< */
	__IO uint32_t	SRGR;                   /*!< */
	__IO uint32_t	MCR;                    /*!< */
	__IO uint32_t	XCER;                   /*!< */
	__IO uint32_t	RCER;                   /*!< */
	__IO uint32_t	PCR_SPSR;               /*!< */
}MDR_MCBSP_TypeDef;

/** @defgroup Periph_MCBSP_DRR MCBSP DRR
  * @{
  */

/*-- MCBSP_DRR:MCBSP DRR Register -----*/

/* Bit field positions: */
#define MCBSP_DRR_DATA_RX_Pos                              0

/* Bit field masks: */
#define MCBSP_DRR_DATA_RX_Msk                              ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group MCBSP_DRR */

/** @defgroup Periph_MCBSP_DXR MCBSP DXR
  * @{
  */

/*-- MCBSP_DXR:MCBSP DXR Register -----*/

/* Bit field positions: */
#define MCBSP_DXR_DATA_TX_Pos                              0

/* Bit field masks: */
#define MCBSP_DXR_DATA_TX_Msk                              ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group MCBSP_DXR */

/** @defgroup Periph_MCBSP_SPSA MCBSP SPSA
  * @{
  */

/*-- MCBSP_SPSA:MCBSP SPSA Register -----*/

/* Bit field positions: */

/* Bit field masks: */

/** @} */ /* End of group MCBSP_SPSA */

/** @defgroup Periph_MCBSP_SPCR MCBSP SPCR
  * @{
  */

/*-- MCBSP_SPCR:MCBSP SPCR Register -----*/

/* Bit field positions: */
#define MCBSP_SPCR_NCGRST_Pos                              0
#define MCBSP_SPCR_NFGRST_Pos                              1
#define MCBSP_SPCR_NRRST_Pos                               2
#define MCBSP_SPCR_NXRST_Pos                               3
#define MCBSP_SPCR_CLKSTP_Pos                              4
#define MCBSP_SPCR_ABIS_Pos                                6
#define MCBSP_SPCR_DLB_Pos                                 7
#define MCBSP_SPCR_RJUST_Pos                               8
#define MCBSP_SPCR_XJUST_Pos                               10
#define MCBSP_SPCR_JBOUND_Pos                              12
#define MCBSP_SPCR_LW_ACC_Pos                              14
#define MCBSP_SPCR_DXENA_Pos                               15
#define MCBSP_SPCR_REVNT0_Pos                              16
#define MCBSP_SPCR_REVNT1_Pos                              18
#define MCBSP_SPCR_RINTM_Pos                               20
#define MCBSP_SPCR_SOFT_Pos                                23
#define MCBSP_SPCR_XEVENT0_Pos                             24
#define MCBSP_SPCR_XEVNT1_Pos                              26
#define MCBSP_SPCR_XEVENT1_Pos                             27
#define MCBSP_SPCR_XINTM_Pos                               28
#define MCBSP_SPCR_FREE_Pos                                31

/* Bit field masks: */
#define MCBSP_SPCR_NCGRST                                  ((uint32_t)0x00000001)
#define MCBSP_SPCR_NFGRST                                  ((uint32_t)0x00000002)
#define MCBSP_SPCR_NRRST                                   ((uint32_t)0x00000004)
#define MCBSP_SPCR_NXRST                                   ((uint32_t)0x00000008)
#define MCBSP_SPCR_CLKSTP_Msk                              ((uint32_t)0x00000030)
#define MCBSP_SPCR_ABIS                                    ((uint32_t)0x00000040)
#define MCBSP_SPCR_DLB                                     ((uint32_t)0x00000080)
#define MCBSP_SPCR_RJUST_Msk                               ((uint32_t)0x00000300)
#define MCBSP_SPCR_XJUST_Msk                               ((uint32_t)0x00000C00)
#define MCBSP_SPCR_JBOUND_Msk                              ((uint32_t)0x00003000)
#define MCBSP_SPCR_LW_ACC                                  ((uint32_t)0x00004000)
#define MCBSP_SPCR_DXENA                                   ((uint32_t)0x00008000)
#define MCBSP_SPCR_REVNT0_Msk                              ((uint32_t)0x00030000)
#define MCBSP_SPCR_REVNT1_Msk                              ((uint32_t)0x000C0000)
#define MCBSP_SPCR_RINTM_Msk                               ((uint32_t)0x00700000)
#define MCBSP_SPCR_SOFT                                    ((uint32_t)0x00800000)
#define MCBSP_SPCR_XEVENT0_Msk                             ((uint32_t)0x03000000)
#define MCBSP_SPCR_XEVNT1                                  ((uint32_t)0x04000000)
#define MCBSP_SPCR_XEVENT1                                 ((uint32_t)0x08000000)
#define MCBSP_SPCR_XINTM_Msk                               ((uint32_t)0x70000000)
#define MCBSP_SPCR_FREE                                    ((uint32_t)0x80000000)

/** @} */ /* End of group MCBSP_SPCR */

/** @defgroup Periph_MCBSP_RCR MCBSP RCR
  * @{
  */

/*-- MCBSP_RCR:MCBSP RCR Register -----*/

/* Bit field positions: */
#define MCBSP_RCR_WLEN_P0_Pos                              0
#define MCBSP_RCR_DELAY_Pos                                5
#define MCBSP_RCR_MSB1ST_Pos                               7
#define MCBSP_RCR_FLEN_P0_Pos                              8
#define MCBSP_RCR_FIG_Pos                                  15
#define MCBSP_RCR_WLEN_P1_Pos                              16
#define MCBSP_RCR_CODEC_Pos                                21
#define MCBSP_RCR_FLEN_P1_Pos                              24
#define MCBSP_RCR_MPHASE_Pos                               31

/* Bit field masks: */
#define MCBSP_RCR_WLEN_P0_Msk                              ((uint32_t)0x0000001F)
#define MCBSP_RCR_DELAY_Msk                                ((uint32_t)0x00000060)
#define MCBSP_RCR_MSB1ST                                   ((uint32_t)0x00000080)
#define MCBSP_RCR_FLEN_P0_Msk                              ((uint32_t)0x00007F00)
#define MCBSP_RCR_FIG                                      ((uint32_t)0x00008000)
#define MCBSP_RCR_WLEN_P1_Msk                              ((uint32_t)0x001F0000)
#define MCBSP_RCR_CODEC_Msk                                ((uint32_t)0x00E00000)
#define MCBSP_RCR_FLEN_P1_Msk                              ((uint32_t)0x7F000000)
#define MCBSP_RCR_MPHASE                                   ((uint32_t)0x80000000)

/** @} */ /* End of group MCBSP_RCR */

/** @defgroup Periph_MCBSP_XCR MCBSP XCR
  * @{
  */

/*-- MCBSP_XCR:MCBSP XCR Register -----*/

/* Bit field positions: */
#define MCBSP_XCR_WLEN_P0_Pos                              0
#define MCBSP_XCR_DELAY_Pos                                5
#define MCBSP_XCR_MSB1ST_Pos                               7
#define MCBSP_XCR_FLEN_P0_Pos                              8
#define MCBSP_XCR_FIG_Pos                                  15
#define MCBSP_XCR_WLEN_P1_Pos                              16
#define MCBSP_XCR_CODEC_Pos                                21
#define MCBSP_XCR_FLEN_P1_Pos                              24
#define MCBSP_XCR_MPHASE_Pos                               31

/* Bit field masks: */
#define MCBSP_XCR_WLEN_P0_Msk                              ((uint32_t)0x0000001F)
#define MCBSP_XCR_DELAY_Msk                                ((uint32_t)0x00000060)
#define MCBSP_XCR_MSB1ST                                   ((uint32_t)0x00000080)
#define MCBSP_XCR_FLEN_P0_Msk                              ((uint32_t)0x00007F00)
#define MCBSP_XCR_FIG                                      ((uint32_t)0x00008000)
#define MCBSP_XCR_WLEN_P1_Msk                              ((uint32_t)0x001F0000)
#define MCBSP_XCR_CODEC_Msk                                ((uint32_t)0x00E00000)
#define MCBSP_XCR_FLEN_P1_Msk                              ((uint32_t)0x7F000000)
#define MCBSP_XCR_MPHASE                                   ((uint32_t)0x80000000)

/** @} */ /* End of group MCBSP_XCR */

/** @defgroup Periph_MCBSP_SRGR MCBSP SRGR
  * @{
  */

/*-- MCBSP_SRGR:MCBSP SRGR Register -----*/

/* Bit field positions: */
#define MCBSP_SRGR_CLKGDV_Pos                              0
#define MCBSP_SRGR_FWID_Pos                                8
#define MCBSP_SRGR_FPER_Pos                                16
#define MCBSP_SRGR_CLKSP_Pos                               28
#define MCBSP_SRGR_CLKSM_Pos                               29
#define MCBSP_SRGR_FSGM_Pos                                30
#define MCBSP_SRGR_GSYNC_Pos                               31

/* Bit field masks: */
#define MCBSP_SRGR_CLKGDV_Msk                              ((uint32_t)0x000000FF)
#define MCBSP_SRGR_FWID_Msk                                ((uint32_t)0x0000FF00)
#define MCBSP_SRGR_FPER_Msk                                ((uint32_t)0x0FFF0000)
#define MCBSP_SRGR_CLKSP                                   ((uint32_t)0x10000000)
#define MCBSP_SRGR_CLKSM                                   ((uint32_t)0x20000000)
#define MCBSP_SRGR_FSGM                                    ((uint32_t)0x40000000)
#define MCBSP_SRGR_GSYNC                                   ((uint32_t)0x80000000)

/** @} */ /* End of group MCBSP_SRGR */

/** @defgroup Periph_MCBSP_MCR MCBSP MCR
  * @{
  */

/*-- MCBSP_MCR:MCBSP MCR Register -----*/

/* Bit field positions: */
#define MCBSP_MCR_MCM_Pos                                  0
#define MCBSP_MCR_CUR_BLK_Pos                              5
#define MCBSP_MCR_BLK0_EN_Pos                              8
#define MCBSP_MCR_BLK1_EN_Pos                              9
#define MCBSP_MCR_BLK2_EN_Pos                              10
#define MCBSP_MCR_BLK3_EN_Pos                              11
#define MCBSP_MCR_BLK4_EN_Pos                              12
#define MCBSP_MCR_BLK5_EN_Pos                              13
#define MCBSP_MCR_BLK6_EN_Pos                              14
#define MCBSP_MCR_BLK7_EN_Pos                              15

/* Bit field masks: */
#define MCBSP_MCR_MCM_Msk                                  ((uint32_t)0x00000003)
#define MCBSP_MCR_CUR_BLK_Msk                              ((uint32_t)0x000000E0)
#define MCBSP_MCR_BLK0_EN                                  ((uint32_t)0x00000100)
#define MCBSP_MCR_BLK1_EN                                  ((uint32_t)0x00000200)
#define MCBSP_MCR_BLK2_EN                                  ((uint32_t)0x00000400)
#define MCBSP_MCR_BLK3_EN                                  ((uint32_t)0x00000800)
#define MCBSP_MCR_BLK4_EN                                  ((uint32_t)0x00001000)
#define MCBSP_MCR_BLK5_EN                                  ((uint32_t)0x00002000)
#define MCBSP_MCR_BLK6_EN                                  ((uint32_t)0x00004000)
#define MCBSP_MCR_BLK7_EN                                  ((uint32_t)0x00008000)

/** @} */ /* End of group MCBSP_MCR */

/** @defgroup Periph_MCBSP_XCER MCBSP XCER
  * @{
  */

/*-- MCBSP_XCER:MCBSP XCER Register -----*/

/* Bit field positions: */
#define MCBSP_XCER_CH0_EN_Pos                              0
#define MCBSP_XCER_CH1_EN_Pos                              1
#define MCBSP_XCER_CH2_EN_Pos                              2
#define MCBSP_XCER_CH3_EN_Pos                              3
#define MCBSP_XCER_CH4_EN_Pos                              4
#define MCBSP_XCER_CH5_EN_Pos                              5
#define MCBSP_XCER_CH6_EN_Pos                              6
#define MCBSP_XCER_CH7_EN_Pos                              7
#define MCBSP_XCER_CH8_EN_Pos                              8
#define MCBSP_XCER_CH9_EN_Pos                              9
#define MCBSP_XCER_CH10_EN_Pos                             10
#define MCBSP_XCER_CH11_EN_Pos                             11
#define MCBSP_XCER_CH12_EN_Pos                             12
#define MCBSP_XCER_CH13_EN_Pos                             13
#define MCBSP_XCER_CH14_EN_Pos                             14
#define MCBSP_XCER_CH15_EN_Pos                             15
#define MCBSP_XCER_CH16_EN_Pos                             16
#define MCBSP_XCER_CH17_EN_Pos                             17
#define MCBSP_XCER_CH18_EN_Pos                             18
#define MCBSP_XCER_CH19_EN_Pos                             19
#define MCBSP_XCER_CH20_EN_Pos                             20
#define MCBSP_XCER_CH21_EN_Pos                             21
#define MCBSP_XCER_CH22_EN_Pos                             22
#define MCBSP_XCER_CH23_EN_Pos                             23
#define MCBSP_XCER_CH24_EN_Pos                             24
#define MCBSP_XCER_CH25_EN_Pos                             25
#define MCBSP_XCER_CH26_EN_Pos                             26
#define MCBSP_XCER_CH27_EN_Pos                             27
#define MCBSP_XCER_CH28_EN_Pos                             28
#define MCBSP_XCER_CH29_EN_Pos                             29
#define MCBSP_XCER_CH30_EN_Pos                             30
#define MCBSP_XCER_CH31_EN_Pos                             31

/* Bit field masks: */
#define MCBSP_XCER_CH0_EN                                  ((uint32_t)0x00000001)
#define MCBSP_XCER_CH1_EN                                  ((uint32_t)0x00000002)
#define MCBSP_XCER_CH2_EN                                  ((uint32_t)0x00000004)
#define MCBSP_XCER_CH3_EN                                  ((uint32_t)0x00000008)
#define MCBSP_XCER_CH4_EN                                  ((uint32_t)0x00000010)
#define MCBSP_XCER_CH5_EN                                  ((uint32_t)0x00000020)
#define MCBSP_XCER_CH6_EN                                  ((uint32_t)0x00000040)
#define MCBSP_XCER_CH7_EN                                  ((uint32_t)0x00000080)
#define MCBSP_XCER_CH8_EN                                  ((uint32_t)0x00000100)
#define MCBSP_XCER_CH9_EN                                  ((uint32_t)0x00000200)
#define MCBSP_XCER_CH10_EN                                 ((uint32_t)0x00000400)
#define MCBSP_XCER_CH11_EN                                 ((uint32_t)0x00000800)
#define MCBSP_XCER_CH12_EN                                 ((uint32_t)0x00001000)
#define MCBSP_XCER_CH13_EN                                 ((uint32_t)0x00002000)
#define MCBSP_XCER_CH14_EN                                 ((uint32_t)0x00004000)
#define MCBSP_XCER_CH15_EN                                 ((uint32_t)0x00008000)
#define MCBSP_XCER_CH16_EN                                 ((uint32_t)0x00010000)
#define MCBSP_XCER_CH17_EN                                 ((uint32_t)0x00020000)
#define MCBSP_XCER_CH18_EN                                 ((uint32_t)0x00040000)
#define MCBSP_XCER_CH19_EN                                 ((uint32_t)0x00080000)
#define MCBSP_XCER_CH20_EN                                 ((uint32_t)0x00100000)
#define MCBSP_XCER_CH21_EN                                 ((uint32_t)0x00200000)
#define MCBSP_XCER_CH22_EN                                 ((uint32_t)0x00400000)
#define MCBSP_XCER_CH23_EN                                 ((uint32_t)0x00800000)
#define MCBSP_XCER_CH24_EN                                 ((uint32_t)0x01000000)
#define MCBSP_XCER_CH25_EN                                 ((uint32_t)0x02000000)
#define MCBSP_XCER_CH26_EN                                 ((uint32_t)0x04000000)
#define MCBSP_XCER_CH27_EN                                 ((uint32_t)0x08000000)
#define MCBSP_XCER_CH28_EN                                 ((uint32_t)0x10000000)
#define MCBSP_XCER_CH29_EN                                 ((uint32_t)0x20000000)
#define MCBSP_XCER_CH30_EN                                 ((uint32_t)0x40000000)
#define MCBSP_XCER_CH31_EN                                 ((uint32_t)0x80000000)

/** @} */ /* End of group MCBSP_XCER */

/** @defgroup Periph_MCBSP_RCER MCBSP RCER
  * @{
  */

/*-- MCBSP_RCER:MCBSP RCER Register -----*/

/* Bit field positions: */
#define MCBSP_RCER_CH0_EN_Pos                              0
#define MCBSP_RCER_CH1_EN_Pos                              1
#define MCBSP_RCER_CH2_EN_Pos                              2
#define MCBSP_RCER_CH3_EN_Pos                              3
#define MCBSP_RCER_CH4_EN_Pos                              4
#define MCBSP_RCER_CH5_EN_Pos                              5
#define MCBSP_RCER_CH6_EN_Pos                              6
#define MCBSP_RCER_CH7_EN_Pos                              7
#define MCBSP_RCER_CH8_EN_Pos                              8
#define MCBSP_RCER_CH9_EN_Pos                              9
#define MCBSP_RCER_CH10_EN_Pos                             10
#define MCBSP_RCER_CH11_EN_Pos                             11
#define MCBSP_RCER_CH12_EN_Pos                             12
#define MCBSP_RCER_CH13_EN_Pos                             13
#define MCBSP_RCER_CH14_EN_Pos                             14
#define MCBSP_RCER_CH15_EN_Pos                             15
#define MCBSP_RCER_CH16_EN_Pos                             16
#define MCBSP_RCER_CH17_EN_Pos                             17
#define MCBSP_RCER_CH18_EN_Pos                             18
#define MCBSP_RCER_CH19_EN_Pos                             19
#define MCBSP_RCER_CH20_EN_Pos                             20
#define MCBSP_RCER_CH21_EN_Pos                             21
#define MCBSP_RCER_CH22_EN_Pos                             22
#define MCBSP_RCER_CH23_EN_Pos                             23
#define MCBSP_RCER_CH24_EN_Pos                             24
#define MCBSP_RCER_CH25_EN_Pos                             25
#define MCBSP_RCER_CH26_EN_Pos                             26
#define MCBSP_RCER_CH27_EN_Pos                             27
#define MCBSP_RCER_CH28_EN_Pos                             28
#define MCBSP_RCER_CH29_EN_Pos                             29
#define MCBSP_RCER_CH30_EN_Pos                             30
#define MCBSP_RCER_CH31_EN_Pos                             31

/* Bit field masks: */
#define MCBSP_RCER_CH0_EN                                  ((uint32_t)0x00000001)
#define MCBSP_RCER_CH1_EN                                  ((uint32_t)0x00000002)
#define MCBSP_RCER_CH2_EN                                  ((uint32_t)0x00000004)
#define MCBSP_RCER_CH3_EN                                  ((uint32_t)0x00000008)
#define MCBSP_RCER_CH4_EN                                  ((uint32_t)0x00000010)
#define MCBSP_RCER_CH5_EN                                  ((uint32_t)0x00000020)
#define MCBSP_RCER_CH6_EN                                  ((uint32_t)0x00000040)
#define MCBSP_RCER_CH7_EN                                  ((uint32_t)0x00000080)
#define MCBSP_RCER_CH8_EN                                  ((uint32_t)0x00000100)
#define MCBSP_RCER_CH9_EN                                  ((uint32_t)0x00000200)
#define MCBSP_RCER_CH10_EN                                 ((uint32_t)0x00000400)
#define MCBSP_RCER_CH11_EN                                 ((uint32_t)0x00000800)
#define MCBSP_RCER_CH12_EN                                 ((uint32_t)0x00001000)
#define MCBSP_RCER_CH13_EN                                 ((uint32_t)0x00002000)
#define MCBSP_RCER_CH14_EN                                 ((uint32_t)0x00004000)
#define MCBSP_RCER_CH15_EN                                 ((uint32_t)0x00008000)
#define MCBSP_RCER_CH16_EN                                 ((uint32_t)0x00010000)
#define MCBSP_RCER_CH17_EN                                 ((uint32_t)0x00020000)
#define MCBSP_RCER_CH18_EN                                 ((uint32_t)0x00040000)
#define MCBSP_RCER_CH19_EN                                 ((uint32_t)0x00080000)
#define MCBSP_RCER_CH20_EN                                 ((uint32_t)0x00100000)
#define MCBSP_RCER_CH21_EN                                 ((uint32_t)0x00200000)
#define MCBSP_RCER_CH22_EN                                 ((uint32_t)0x00400000)
#define MCBSP_RCER_CH23_EN                                 ((uint32_t)0x00800000)
#define MCBSP_RCER_CH24_EN                                 ((uint32_t)0x01000000)
#define MCBSP_RCER_CH25_EN                                 ((uint32_t)0x02000000)
#define MCBSP_RCER_CH26_EN                                 ((uint32_t)0x04000000)
#define MCBSP_RCER_CH27_EN                                 ((uint32_t)0x08000000)
#define MCBSP_RCER_CH28_EN                                 ((uint32_t)0x10000000)
#define MCBSP_RCER_CH29_EN                                 ((uint32_t)0x20000000)
#define MCBSP_RCER_CH30_EN                                 ((uint32_t)0x40000000)
#define MCBSP_RCER_CH31_EN                                 ((uint32_t)0x80000000)

/** @} */ /* End of group MCBSP_RCER */

/** @defgroup Periph_MCBSP_PCR_SPSR MCBSP PCR_SPSR
  * @{
  */

/*-- MCBSP_PCR_SPSR:MCBSP PCR_SPSR Register -----*/

/* Bit field positions: */
#define MCBSP_PCR_SPSR_CLKRP_Pos                           0
#define MCBSP_PCR_SPSR_CLKXP_Pos                           1
#define MCBSP_PCR_SPSR_FSRP_Pos                            2
#define MCBSP_PCR_SPSR_FSXP_Pos                            3
#define MCBSP_PCR_SPSR_DR_ST_Pos                           4
#define MCBSP_PCR_SPSR_DX_ST_Pos                           5
#define MCBSP_PCR_SPSR_CLKS_ST_Pos                         6
#define MCBSP_PCR_SPSR_CLKRM_Pos                           8
#define MCBSP_PCR_SPSR_CLKXM_Pos                           9
#define MCBSP_PCR_SPSR_FSRM_Pos                            10
#define MCBSP_PCR_SPSR_FSXM_Pos                            11
#define MCBSP_PCR_SPSR_RIOEN_Pos                           12
#define MCBSP_PCR_SPSR_XIOEN_Pos                           13
#define MCBSP_PCR_SPSR_RRDY_Pos                            16
#define MCBSP_PCR_SPSR_FFULL_Pos                           17
#define MCBSP_PCR_SPSR_RSER_Pos                            18
#define MCBSP_PCR_SPSR_RLOST_Pos                           19
#define MCBSP_PCR_SPSR_RFIFO_E_Pos                         20
#define MCBSP_PCR_SPSR_RFIFO_H_Pos                         21
#define MCBSP_PCR_SPSR_RFIFO_F_Pos                         22
#define MCBSP_PCR_SPSR_XRDY_Pos                            24
#define MCBSP_PCR_SPSR_XEMPTY_Pos                          25
#define MCBSP_PCR_SPSR_XSERR_Pos                           26
#define MCBSP_PCR_SPSR_XLOST_Pos                           27
#define MCBSP_PCR_SPSR_XFIFO_E_Pos                         28
#define MCBSP_PCR_SPSR_ZFIFO_H_Pos                         29
#define MCBSP_PCR_SPSR_XFIFO_F_Pos                         30

/* Bit field masks: */
#define MCBSP_PCR_SPSR_CLKRP                               ((uint32_t)0x00000001)
#define MCBSP_PCR_SPSR_CLKXP                               ((uint32_t)0x00000002)
#define MCBSP_PCR_SPSR_FSRP                                ((uint32_t)0x00000004)
#define MCBSP_PCR_SPSR_FSXP                                ((uint32_t)0x00000008)
#define MCBSP_PCR_SPSR_DR_ST                               ((uint32_t)0x00000010)
#define MCBSP_PCR_SPSR_DX_ST                               ((uint32_t)0x00000020)
#define MCBSP_PCR_SPSR_CLKS_ST                             ((uint32_t)0x00000040)
#define MCBSP_PCR_SPSR_CLKRM                               ((uint32_t)0x00000100)
#define MCBSP_PCR_SPSR_CLKXM                               ((uint32_t)0x00000200)
#define MCBSP_PCR_SPSR_FSRM                                ((uint32_t)0x00000400)
#define MCBSP_PCR_SPSR_FSXM                                ((uint32_t)0x00000800)
#define MCBSP_PCR_SPSR_RIOEN                               ((uint32_t)0x00001000)
#define MCBSP_PCR_SPSR_XIOEN                               ((uint32_t)0x00002000)
#define MCBSP_PCR_SPSR_RRDY                                ((uint32_t)0x00010000)
#define MCBSP_PCR_SPSR_FFULL                               ((uint32_t)0x00020000)
#define MCBSP_PCR_SPSR_RSER                                ((uint32_t)0x00040000)
#define MCBSP_PCR_SPSR_RLOST                               ((uint32_t)0x00080000)
#define MCBSP_PCR_SPSR_RFIFO_E                             ((uint32_t)0x00100000)
#define MCBSP_PCR_SPSR_RFIFO_H                             ((uint32_t)0x00200000)
#define MCBSP_PCR_SPSR_RFIFO_F                             ((uint32_t)0x00400000)
#define MCBSP_PCR_SPSR_XRDY                                ((uint32_t)0x01000000)
#define MCBSP_PCR_SPSR_XEMPTY                              ((uint32_t)0x02000000)
#define MCBSP_PCR_SPSR_XSERR                               ((uint32_t)0x04000000)
#define MCBSP_PCR_SPSR_XLOST                               ((uint32_t)0x08000000)
#define MCBSP_PCR_SPSR_XFIFO_E                             ((uint32_t)0x10000000)
#define MCBSP_PCR_SPSR_ZFIFO_H                             ((uint32_t)0x20000000)
#define MCBSP_PCR_SPSR_XFIFO_F                             ((uint32_t)0x40000000)

/** @} */ /* End of group MCBSP_PCR_SPSR */

/** @} */ /* End of group MCBSP */

/** @defgroup MDR1901VC1T_Periph_DSP_TIMER DSP_TIMER
  * @{
  */


/* MDR_DSP_TIMER_TypeDef structure */
typedef struct {
	__IO uint32_t	PDR_TIM;                /*!< */
	__IO uint32_t	TCR;                    /*!< */
}MDR_DSP_TIMER_TypeDef;

/** @defgroup Periph_DSP_TIMER_PDR_TIM DSP_TIMER PDR_TIM
  * @{
  */

/*-- DSP_TIMER_PDR_TIM:DSP_TIMER PDR_TIM Register -----*/

/* Bit field positions: */
#define DSP_TIMER_PDR_TIM_CNT_Pos                          0
#define DSP_TIMER_PDR_TIM_PR_Pos                           16

/* Bit field masks: */
#define DSP_TIMER_PDR_TIM_CNT_Msk                          ((uint32_t)0x0000FFFF)
#define DSP_TIMER_PDR_TIM_PR_Msk                           ((uint32_t)0xFFFF0000)

/** @} */ /* End of group DSP_TIMER_PDR_TIM */

/** @defgroup Periph_DSP_TIMER_TCR DSP_TIMER TCR
  * @{
  */

/*-- DSP_TIMER_TCR:DSP_TIMER TCR Register -----*/

/* Bit field positions: */
#define DSP_TIMER_TCR_TDDR_Pos                             0
#define DSP_TIMER_TCR_TSS_Pos                              4
#define DSP_TIMER_TCR_TRB_Pos                              5
#define DSP_TIMER_TCR_PSC_Pos                              6
#define DSP_TIMER_TCR_FREE_Pos                             8
#define DSP_TIMER_TCR_SOFT_Pos                             9

/* Bit field masks: */
#define DSP_TIMER_TCR_TDDR_Msk                             ((uint32_t)0x0000000F)
#define DSP_TIMER_TCR_TSS                                  ((uint32_t)0x00000010)
#define DSP_TIMER_TCR_TRB                                  ((uint32_t)0x00000020)
#define DSP_TIMER_TCR_PSC_Msk                              ((uint32_t)0x000000C0)
#define DSP_TIMER_TCR_FREE                                 ((uint32_t)0x00000100)
#define DSP_TIMER_TCR_SOFT                                 ((uint32_t)0x00000200)

/** @} */ /* End of group DSP_TIMER_TCR */

/** @} */ /* End of group DSP_TIMER */

/** @defgroup MDR1901VC1T_Periph_DSP_DMA DSP_DMA
  * @{
  */


/* MDR_DSP_DMA_TypeDef structure */
typedef struct {
	__IO uint32_t	DMA_STATUS;             /*!< */
	__IO uint32_t	DMA_CONFIG;             /*!< */
	__IO uint32_t	CTRL_BASE_PTR;          /*!< */
	__IO uint32_t	ALT_CTRL_BASE_PTR;      /*!< */
	__IO uint32_t	DMA_WAITONREG_STATUS;   /*!< */
	__IO uint32_t	CHNL_SW_REQUEST;        /*!< */
	__IO uint32_t	CHNL_USEBURST_SET;      /*!< */
	__IO uint32_t	CHNL_USEBURST_CLR;      /*!< */
	__IO uint32_t	CHNL_REQ_MASK_SET;      /*!< */
	__IO uint32_t	CHNL_REQ_MASK_CLR;      /*!< */
	__IO uint32_t	CHNL_ENABLE_SET;        /*!< */
	__IO uint32_t	CHNL_ENABLE_CLR;        /*!< */
	__IO uint32_t	CHNL_PRI_ALT_SET;       /*!< */
	__IO uint32_t	CHNL_PRI_ALT_CLR;       /*!< */
	__IO uint32_t	CHNL_PRIORITY_SET;      /*!< */
	__IO uint32_t	CHNL_PRIORITY_CLR;      /*!< */
	__IO uint32_t	ERR_CLR;                /*!< */
}MDR_DSP_DMA_TypeDef;

/** @defgroup Periph_DSP_DMA_DMA_STATUS DSP_DMA DMA_STATUS
  * @{
  */

/*-- DSP_DMA_DMA_STATUS:DSP_DMA DMA_STATUS Register -----*/

/* Bit field positions: */

/* Bit field masks: */

/** @} */ /* End of group DSP_DMA_DMA_STATUS */

/** @defgroup Periph_DSP_DMA_DMA_CONFIG DSP_DMA DMA_CONFIG
  * @{
  */

/*-- DSP_DMA_DMA_CONFIG:DSP_DMA DMA_CONFIG Register -----*/

/* Bit field positions: */

/* Bit field masks: */

/** @} */ /* End of group DSP_DMA_DMA_CONFIG */

/** @defgroup Periph_DSP_DMA_CTRL_BASE_PTR DSP_DMA CTRL_BASE_PTR
  * @{
  */

/*-- DSP_DMA_CTRL_BASE_PTR:DSP_DMA CTRL_BASE_PTR Register -----*/

/* Bit field positions: */

/* Bit field masks: */

/** @} */ /* End of group DSP_DMA_CTRL_BASE_PTR */

/** @defgroup Periph_DSP_DMA_ALT_CTRL_BASE_PTR DSP_DMA ALT_CTRL_BASE_PTR
  * @{
  */

/*-- DSP_DMA_ALT_CTRL_BASE_PTR:DSP_DMA ALT_CTRL_BASE_PTR Register -----*/

/* Bit field positions: */

/* Bit field masks: */

/** @} */ /* End of group DSP_DMA_ALT_CTRL_BASE_PTR */

/** @defgroup Periph_DSP_DMA_DMA_WAITONREG_STATUS DSP_DMA DMA_WAITONREG_STATUS
  * @{
  */

/*-- DSP_DMA_DMA_WAITONREG_STATUS:DSP_DMA DMA_WAITONREG_STATUS Register -----*/

/* Bit field positions: */

/* Bit field masks: */

/** @} */ /* End of group DSP_DMA_DMA_WAITONREG_STATUS */

/** @defgroup Periph_DSP_DMA_CHNL_SW_REQUEST DSP_DMA CHNL_SW_REQUEST
  * @{
  */

/*-- DSP_DMA_CHNL_SW_REQUEST:DSP_DMA CHNL_SW_REQUEST Register -----*/

/* Bit field positions: */

/* Bit field masks: */

/** @} */ /* End of group DSP_DMA_CHNL_SW_REQUEST */

/** @defgroup Periph_DSP_DMA_CHNL_USEBURST_SET DSP_DMA CHNL_USEBURST_SET
  * @{
  */

/*-- DSP_DMA_CHNL_USEBURST_SET:DSP_DMA CHNL_USEBURST_SET Register -----*/

/* Bit field positions: */

/* Bit field masks: */

/** @} */ /* End of group DSP_DMA_CHNL_USEBURST_SET */

/** @defgroup Periph_DSP_DMA_CHNL_USEBURST_CLR DSP_DMA CHNL_USEBURST_CLR
  * @{
  */

/*-- DSP_DMA_CHNL_USEBURST_CLR:DSP_DMA CHNL_USEBURST_CLR Register -----*/

/* Bit field positions: */

/* Bit field masks: */

/** @} */ /* End of group DSP_DMA_CHNL_USEBURST_CLR */

/** @defgroup Periph_DSP_DMA_CHNL_REQ_MASK_SET DSP_DMA CHNL_REQ_MASK_SET
  * @{
  */

/*-- DSP_DMA_CHNL_REQ_MASK_SET:DSP_DMA CHNL_REQ_MASK_SET Register -----*/

/* Bit field positions: */

/* Bit field masks: */

/** @} */ /* End of group DSP_DMA_CHNL_REQ_MASK_SET */

/** @defgroup Periph_DSP_DMA_CHNL_REQ_MASK_CLR DSP_DMA CHNL_REQ_MASK_CLR
  * @{
  */

/*-- DSP_DMA_CHNL_REQ_MASK_CLR:DSP_DMA CHNL_REQ_MASK_CLR Register -----*/

/* Bit field positions: */

/* Bit field masks: */

/** @} */ /* End of group DSP_DMA_CHNL_REQ_MASK_CLR */

/** @defgroup Periph_DSP_DMA_CHNL_ENABLE_SET DSP_DMA CHNL_ENABLE_SET
  * @{
  */

/*-- DSP_DMA_CHNL_ENABLE_SET:DSP_DMA CHNL_ENABLE_SET Register -----*/

/* Bit field positions: */

/* Bit field masks: */

/** @} */ /* End of group DSP_DMA_CHNL_ENABLE_SET */

/** @defgroup Periph_DSP_DMA_CHNL_ENABLE_CLR DSP_DMA CHNL_ENABLE_CLR
  * @{
  */

/*-- DSP_DMA_CHNL_ENABLE_CLR:DSP_DMA CHNL_ENABLE_CLR Register -----*/

/* Bit field positions: */

/* Bit field masks: */

/** @} */ /* End of group DSP_DMA_CHNL_ENABLE_CLR */

/** @defgroup Periph_DSP_DMA_CHNL_PRI_ALT_SET DSP_DMA CHNL_PRI_ALT_SET
  * @{
  */

/*-- DSP_DMA_CHNL_PRI_ALT_SET:DSP_DMA CHNL_PRI_ALT_SET Register -----*/

/* Bit field positions: */

/* Bit field masks: */

/** @} */ /* End of group DSP_DMA_CHNL_PRI_ALT_SET */

/** @defgroup Periph_DSP_DMA_CHNL_PRI_ALT_CLR DSP_DMA CHNL_PRI_ALT_CLR
  * @{
  */

/*-- DSP_DMA_CHNL_PRI_ALT_CLR:DSP_DMA CHNL_PRI_ALT_CLR Register -----*/

/* Bit field positions: */

/* Bit field masks: */

/** @} */ /* End of group DSP_DMA_CHNL_PRI_ALT_CLR */

/** @defgroup Periph_DSP_DMA_CHNL_PRIORITY_SET DSP_DMA CHNL_PRIORITY_SET
  * @{
  */

/*-- DSP_DMA_CHNL_PRIORITY_SET:DSP_DMA CHNL_PRIORITY_SET Register -----*/

/* Bit field positions: */

/* Bit field masks: */

/** @} */ /* End of group DSP_DMA_CHNL_PRIORITY_SET */

/** @defgroup Periph_DSP_DMA_CHNL_PRIORITY_CLR DSP_DMA CHNL_PRIORITY_CLR
  * @{
  */

/*-- DSP_DMA_CHNL_PRIORITY_CLR:DSP_DMA CHNL_PRIORITY_CLR Register -----*/

/* Bit field positions: */

/* Bit field masks: */

/** @} */ /* End of group DSP_DMA_CHNL_PRIORITY_CLR */

/** @defgroup Periph_DSP_DMA_ERR_CLR DSP_DMA ERR_CLR
  * @{
  */

/*-- DSP_DMA_ERR_CLR:DSP_DMA ERR_CLR Register -----*/

/* Bit field positions: */
#define DSP_DMA_ERR_CLR_CHNL_PRIORITY_SET_Pos              0

/* Bit field masks: */
#define DSP_DMA_ERR_CLR_CHNL_PRIORITY_SET                  ((uint32_t)0x00000001)

/** @} */ /* End of group DSP_DMA_ERR_CLR */

/** @} */ /* End of group DSP_DMA */

/** @defgroup MDR1901VC1T_Periph_DSP_CRPT DSP_CRPT
  * @{
  */


/* MDR_DSP_CRPT_TypeDef structure */
typedef struct {
	__IO uint32_t	CWR;                    /*!< */
	__IO uint32_t	SR;                     /*!< */
	__IO uint32_t	DATA;                   /*!< */
	__IO uint32_t	KR;                     /*!< */
	__IO uint32_t	SYNR;                   /*!< */
	__IO uint32_t	CR;                     /*!< */
	__IO uint32_t	IMIT;                   /*!< */
	__IO uint32_t	ITER;                   /*!< */
}MDR_DSP_CRPT_TypeDef;

/** @defgroup Periph_DSP_CRPT_CWR DSP_CRPT CWR
  * @{
  */

/*-- DSP_CRPT_CWR:DSP_CRPT CWR Register -----*/

/* Bit field positions: */
#define DSP_CRPT_CWR_MODE_Pos                              0
#define DSP_CRPT_CWR_IM_Pos                                2
#define DSP_CRPT_CWR_START_Pos                             3
#define DSP_CRPT_CWR_DIR_Pos                               4
#define DSP_CRPT_CWR_IE_CRPT_Pos                           5
#define DSP_CRPT_CWR_RST_Pos                               6
#define DSP_CRPT_CWR_BIST_Pos                              7

/* Bit field masks: */
#define DSP_CRPT_CWR_MODE_Msk                              ((uint32_t)0x00000003)
#define DSP_CRPT_CWR_IM                                    ((uint32_t)0x00000004)
#define DSP_CRPT_CWR_START                                 ((uint32_t)0x00000008)
#define DSP_CRPT_CWR_DIR                                   ((uint32_t)0x00000010)
#define DSP_CRPT_CWR_IE_CRPT                               ((uint32_t)0x00000020)
#define DSP_CRPT_CWR_RST                                   ((uint32_t)0x00000040)
#define DSP_CRPT_CWR_BIST                                  ((uint32_t)0x00000080)

/** @} */ /* End of group DSP_CRPT_CWR */

/** @defgroup Periph_DSP_CRPT_SR DSP_CRPT SR
  * @{
  */

/*-- DSP_CRPT_SR:DSP_CRPT SR Register -----*/

/* Bit field positions: */
#define DSP_CRPT_SR_READY_Pos                              0
#define DSP_CRPT_SR_ERROR_Pos                              1
#define DSP_CRPT_SR_KF_Pos                                 2
#define DSP_CRPT_SR_DW_Pos                                 3
#define DSP_CRPT_SR_DR_Pos                                 4
#define DSP_CRPT_SR_SW_Pos                                 5
#define DSP_CRPT_SR_KW_Pos                                 6

/* Bit field masks: */
#define DSP_CRPT_SR_READY                                  ((uint32_t)0x00000001)
#define DSP_CRPT_SR_ERROR                                  ((uint32_t)0x00000002)
#define DSP_CRPT_SR_KF                                     ((uint32_t)0x00000004)
#define DSP_CRPT_SR_DW                                     ((uint32_t)0x00000008)
#define DSP_CRPT_SR_DR                                     ((uint32_t)0x00000010)
#define DSP_CRPT_SR_SW                                     ((uint32_t)0x00000020)
#define DSP_CRPT_SR_KW                                     ((uint32_t)0x00000040)

/** @} */ /* End of group DSP_CRPT_SR */

/** @defgroup Periph_DSP_CRPT_DATA DSP_CRPT DATA
  * @{
  */

/*-- DSP_CRPT_DATA:DSP_CRPT DATA Register -----*/

/* Bit field positions: */
#define DSP_CRPT_DATA_DATA_Pos                             0

/* Bit field masks: */
#define DSP_CRPT_DATA_DATA_Msk                             ((uint32_t)0x0000FFFF)

/** @} */ /* End of group DSP_CRPT_DATA */

/** @defgroup Periph_DSP_CRPT_KR DSP_CRPT KR
  * @{
  */

/*-- DSP_CRPT_KR:DSP_CRPT KR Register -----*/

/* Bit field positions: */
#define DSP_CRPT_KR_KEY_Pos                                0

/* Bit field masks: */
#define DSP_CRPT_KR_KEY_Msk                                ((uint32_t)0x0000FFFF)

/** @} */ /* End of group DSP_CRPT_KR */

/** @defgroup Periph_DSP_CRPT_SYNR DSP_CRPT SYNR
  * @{
  */

/*-- DSP_CRPT_SYNR:DSP_CRPT SYNR Register -----*/

/* Bit field positions: */
#define DSP_CRPT_SYNR_KEY_Pos                              0
#define DSP_CRPT_SYNR_SYNCH_Pos                            1

/* Bit field masks: */
#define DSP_CRPT_SYNR_KEY                                  ((uint32_t)0x00000001)
#define DSP_CRPT_SYNR_SYNCH_Msk                            ((uint32_t)0x0000FFFE)

/** @} */ /* End of group DSP_CRPT_SYNR */

/** @defgroup Periph_DSP_CRPT_CR DSP_CRPT CR
  * @{
  */

/*-- DSP_CRPT_CR:DSP_CRPT CR Register -----*/

/* Bit field positions: */
#define DSP_CRPT_CR_CONST_Pos                              0

/* Bit field masks: */
#define DSP_CRPT_CR_CONST_Msk                              ((uint32_t)0x0000FFFF)

/** @} */ /* End of group DSP_CRPT_CR */

/** @defgroup Periph_DSP_CRPT_IMIT DSP_CRPT IMIT
  * @{
  */

/*-- DSP_CRPT_IMIT:DSP_CRPT IMIT Register -----*/

/* Bit field positions: */
#define DSP_CRPT_IMIT_IMIT_Pos                             0

/* Bit field masks: */
#define DSP_CRPT_IMIT_IMIT_Msk                             ((uint32_t)0x0000FFFF)

/** @} */ /* End of group DSP_CRPT_IMIT */

/** @defgroup Periph_DSP_CRPT_ITER DSP_CRPT ITER
  * @{
  */

/*-- DSP_CRPT_ITER:DSP_CRPT ITER Register -----*/

/* Bit field positions: */
#define DSP_CRPT_ITER_ITER0_Pos                            0
#define DSP_CRPT_ITER_ITER1_Pos                            1
#define DSP_CRPT_ITER_ITER2_Pos                            2
#define DSP_CRPT_ITER_ITER3_Pos                            3
#define DSP_CRPT_ITER_ITER4_Pos                            4
#define DSP_CRPT_ITER_ITER5_Pos                            5
#define DSP_CRPT_ITER_EN_CRPT_Pos                          6

/* Bit field masks: */
#define DSP_CRPT_ITER_ITER0                                ((uint32_t)0x00000001)
#define DSP_CRPT_ITER_ITER1                                ((uint32_t)0x00000002)
#define DSP_CRPT_ITER_ITER2                                ((uint32_t)0x00000004)
#define DSP_CRPT_ITER_ITER3                                ((uint32_t)0x00000008)
#define DSP_CRPT_ITER_ITER4                                ((uint32_t)0x00000010)
#define DSP_CRPT_ITER_ITER5                                ((uint32_t)0x00000020)
#define DSP_CRPT_ITER_EN_CRPT                              ((uint32_t)0x00000040)

/** @} */ /* End of group DSP_CRPT_ITER */

/** @} */ /* End of group DSP_CRPT */

/** @} */ /* End of group MDR1901VC1T */

/** @defgroup __Peripheral_Memory_Map  Peripheral Memory Map
  * @{
  */

#define MDR_SSP3_BASE                  (0x40000000)
#define MDR_SSP4_BASE                  (0x40008000)
#define MDR_USB_BASE                   (0x40010000)
#define MDR_EEPROM_BASE                (0x40018000)
#define MDR_RST_CLK_BASE               (0x40020000)
#define MDR_DMA_BASE                   (0x40028000)
#define MDR_UART1_BASE                 (0x40030000)
#define MDR_UART2_BASE                 (0x40038000)
#define MDR_SSP1_BASE                  (0x40040000)
#define MDR_SDIO_BASE                  (0x40048000)
#define MDR_I2C_BASE                   (0x40050000)
#define MDR_POWER_BASE                 (0x40058000)
#define MDR_WWDG_BASE                  (0x40060000)
#define MDR_IWDG_BASE                  (0x40068000)
#define MDR_TIMER1_BASE                (0x40070000)
#define MDR_TIMER2_BASE                (0x40078000)
#define MDR_TIMER3_BASE                (0x40080000)
#define MDR_ADC_BASE                   (0x40088000)
#define MDR_DAC_BASE                   (0x40090000)
#define MDR_COMP_BASE                  (0x40098000)
#define MDR_SSP2_BASE                  (0x400A0000)
#define MDR_PORTA_BASE                 (0x400A8000)
#define MDR_PORTB_BASE                 (0x400B0000)
#define MDR_PORTC_BASE                 (0x400B8000)
#define MDR_PORTD_BASE                 (0x400C0000)
#define MDR_PORTE_BASE                 (0x400C8000)
#define MDR_UART3_BASE                 (0x400D0000)
#define MDR_BKP_BASE                   (0x400D8000)
#define MDR_PORTF_BASE                 (0x400E8000)
#define MDR_EBC_BASE                   (0x400F0000)
#define MDR_DSP_CORE_BASE              (0x30000000)
#define MDR_AUDIO_IP_BASE              (0x300000A0)
#define MDR_MCBSP1_BASE                (0x30000040)
#define MDR_MCBSP2_BASE                (0x30000050)
#define MDR_MCBSP3_BASE                (0x30000060)
#define MDR_DSP_TIMER_BASE             (0x30000070)
#define MDR_DSP_DMA_BASE               (0x300000C0)
#define MDR_DSP_CRPT_BASE              (0x30000080)

/** @} */ /* End of group __Peripheral_Memory_Map */

/** @defgroup __Peripheral_declaration Peripheral declaration __Peripheral_declaration Peripheral declaration
  * @{
  */

#define MDR_SSP3                       ((MDR_SSP_TypeDef 	*) MDR_SSP3_BASE)
#define MDR_SSP4                       ((MDR_SSP_TypeDef 	*) MDR_SSP4_BASE)
#define MDR_USB                        ((MDR_USB_TypeDef 	*) MDR_USB_BASE)
#define MDR_EEPROM                     ((MDR_EEPROM_TypeDef 	*) MDR_EEPROM_BASE)
#define MDR_RST_CLK                    ((MDR_RST_CLK_TypeDef 	*) MDR_RST_CLK_BASE)
#define MDR_DMA                        ((MDR_DMA_TypeDef 	*) MDR_DMA_BASE)
#define MDR_UART1                      ((MDR_UART_TypeDef 	*) MDR_UART1_BASE)
#define MDR_UART2                      ((MDR_UART_TypeDef 	*) MDR_UART2_BASE)
#define MDR_SSP1                       ((MDR_SSP_TypeDef 	*) MDR_SSP1_BASE)
#define MDR_SDIO                       ((MDR_SDIO_TypeDef 	*) MDR_SDIO_BASE)
#define MDR_I2C                        ((MDR_I2C_TypeDef 	*) MDR_I2C_BASE)
#define MDR_POWER                      ((MDR_POWER_TypeDef 	*) MDR_POWER_BASE)
#define MDR_WWDG                       ((MDR_WWDG_TypeDef 	*) MDR_WWDG_BASE)
#define MDR_IWDG                       ((MDR_IWDG_TypeDef 	*) MDR_IWDG_BASE)
#define MDR_TIMER1                     ((MDR_TIMER_TypeDef 	*) MDR_TIMER1_BASE)
#define MDR_TIMER2                     ((MDR_TIMER_TypeDef 	*) MDR_TIMER2_BASE)
#define MDR_TIMER3                     ((MDR_TIMER_TypeDef 	*) MDR_TIMER3_BASE)
#define MDR_ADC                        ((MDR_ADC_TypeDef 	*) MDR_ADC_BASE)
#define MDR_DAC                        ((MDR_DAC_TypeDef 	*) MDR_DAC_BASE)
#define MDR_COMP                       ((MDR_COMP_TypeDef 	*) MDR_COMP_BASE)
#define MDR_SSP2                       ((MDR_SSP_TypeDef 	*) MDR_SSP2_BASE)
#define MDR_PORTA                      ((MDR_PORT_TypeDef 	*) MDR_PORTA_BASE)
#define MDR_PORTB                      ((MDR_PORT_TypeDef 	*) MDR_PORTB_BASE)
#define MDR_PORTC                      ((MDR_PORT_TypeDef 	*) MDR_PORTC_BASE)
#define MDR_PORTD                      ((MDR_PORT_TypeDef 	*) MDR_PORTD_BASE)
#define MDR_PORTE                      ((MDR_PORT_TypeDef 	*) MDR_PORTE_BASE)
#define MDR_UART3                      ((MDR_UART_TypeDef 	*) MDR_UART3_BASE)
#define MDR_BKP                        ((MDR_BKP_TypeDef 	*) MDR_BKP_BASE)
#define MDR_PORTF                      ((MDR_PORT_TypeDef 	*) MDR_PORTF_BASE)
#define MDR_EBC                        ((MDR_EBC_TypeDef 	*) MDR_EBC_BASE)
#define MDR_DSP_CORE                   ((MDR_DSP_CORE_TypeDef 	*) MDR_DSP_CORE_BASE)
#define MDR_AUDIO_IP                   ((MDR_AUDIO_IP_TypeDef 	*) MDR_AUDIO_IP_BASE)
#define MDR_MCBSP1                     ((MDR_MCBSP_TypeDef 	*) MDR_MCBSP1_BASE)
#define MDR_MCBSP2                     ((MDR_MCBSP_TypeDef 	*) MDR_MCBSP2_BASE)
#define MDR_MCBSP3                     ((MDR_MCBSP_TypeDef 	*) MDR_MCBSP3_BASE)
#define MDR_DSP_TIMER                  ((MDR_DSP_TIMER_TypeDef 	*) MDR_DSP_TIMER_BASE)
#define MDR_DSP_DMA                    ((MDR_DSP_DMA_TypeDef 	*) MDR_DSP_DMA_BASE)
#define MDR_DSP_CRPT                   ((MDR_DSP_CRPT_TypeDef 	*) MDR_DSP_CRPT_BASE)

/** @} */ /* End of group __Peripheral_declaration */

#ifdef __cplusplus
}
#endif

/** @} */ /* End of group __MDR1901VC1T_Peripheral*/

/** @} */ /* End of group MDR1901VC1T*/

/** @} */ /* End of group __CMSIS */

#endif /* MDR_MDR1901VC1T */

/*
*
* END OF FILE __MDR1901VC1T_H*/
