/**
  * FILE MDR1986BE4.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MDR1986BE4_H
#define __MDR1986BE4_H

/** @addtogroup __CMSIS CMSIS
  * @{
  */

/** @addtogroup MDR1986BE4 MDR1986BE4
  * @{
  */

/** @addtogroup __MDR1986BE4_Peripheral MDR1986BE4Peripheral
  * @{
  */

#ifdef __cplusplus
extern "C" {
#endif

#if defined ( __CC_ARM   )
	#pragma anon_unions
#endif

/* MDR1986BE4 Interrupt Number Definition */
typedef enum IQRn{
/*-- Cortex-CM0 Processor Exceptions Numbers ----------------------------------*/
	NonMaskableInt_IRQn                   = -14, /*!< 2 Non Maskable Interrupt */
	HardFault_IRQn                        = -13, /*!< 3 Hard Fault Interrupt */
	SVCall_IRQn                           = -5, /*!< 10 SV Call Interrupt */
	PendSV_IRQn                           = -2, /*!< 14 Pend SV Interrupt */
	SysTick_IRQn                          = -1, /*!< 15 System Tick Timer Interrupt */
/*-- MDR1986BE4 specific Interrupt Numbers --------------------------------------*/
	DMA_IRQn                              = 0, /*!< DMA Interrupt */
	UART1_IRQn                            = 1, /*!< UART1  Interrupt */
	UART2_IRQn                            = 2, /*!< UART2  Interrupt */
	SSP1_IRQn                             = 3, /*!< SSP1  Interrupt */
	POWER_IRQn                            = 4, /*!< POWER Interrupt */
	WWDG_IRQn                             = 5, /*!< WWDG Interrupt */
	TIMER1_IRQn                           = 6, /*!< Timer1  Interrupt */
	TIMER2_IRQn                           = 7, /*!< Timer2  Interrupt */
	ADC_IRQn                              = 8, /*!< ADC  Interrupt */
	COMPARATOR_IRQn                       = 9, /*!< COMPARATOR  Interrupt */
	BACKUP_IRQn                           = 10, /*!< BACKUP  Interrupt */
	EXT_INT0_IRQn                         = 11, /*!< EXT_INT0  Interrupt */
	EXT_INT1_IRQn                         = 12, /*!< EXT_INT1  Interrupt */
	EXT_INT2_IRQn                         = 13, /*!< EXT_INT2  Interrupt */
	ADCIU_CH1_IRQn                        = 14, /*!< ADCIU_CH1 Interrupt */
	ADCIU_CH2_IRQn                        = 15, /*!< ADCIU_CH2 Interrupt */
	ADCIU_CH3_IRQn                        = 16, /*!< ADCIU_CH3 Interrupt */
	ADCIU_CH4_IRQn                        = 17, /*!< ADCIU_CH4 Interrupt */
	ADCIU_CH5_IRQn                        = 18, /*!< ADCIU_CH5 Interrupt */
	ADCIU_CH6_IRQn                        = 19, /*!< ADCIU_CH6 Interrupt */
	ADCIU_CH7_IRQn                        = 20, /*!< ADCIU_CH7 Interrupt */
	ADCIU_CH8_IRQn                        = 21, /*!< ADCIU_CH8 Interrupt */
	ADCIU_IRQn                            = 22  /*!< ADCIU Interrupt */
}IRQn_Type;

/** @addtogroup ___Configuration_of_CMSIS Configuration of CMSIS
  * @{
  */
/* Configuration of the Cortex-M0 Processor and Core Peripherals */
#define __M0_REV                       r2p0	/*!< Cortex-M0 Core Revision */
#define __MPU_PRESENT                  0	/*!< MPU present or not */
#define __NVIC_PRIO_BITS               2	/*!< Number of Bits used for Priority Levels */
#define __Vendor_SysTickConfig         0	/*!< Set to 1 if different SysTick Config is used */

/** @} */ /* __Configuration_of_CMSIS */

/* Includes ------------------------------------------------------------------*/
#include "core_cm0.h"
#include "system_MDR1986BE4.h"

/** @defgroup _Exported_types _Exported_types
  * @{
  */

typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus;
#define IS_FLAG_STATUS(FLAG) (((FLAG) == RESET) || ((FLAG) == SET))
typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;
#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))
typedef enum {ERROR = 0, SUCCESS = !ERROR} ErrorStatus;
/** @} */ /* End of group __Exported_types */

/** @addtogroup MDR1986BE4_Peripheral_Units MDR1986BE4Peripheral Units
  * @{
  */

/** @defgroup MDR1986BE4_Periph_SSP SSP
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

/** @defgroup MDR1986BE4_Periph_UART UART
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

/** @defgroup MDR1986BE4_Periph_EEPROM EEPROM
  * @{
  */


/* MDR_EEPROM_TypeDef structure */
typedef struct {
	__IO uint32_t	CMD;                    /*!<EEPROM Command Register */
	__IO uint32_t	ADR;                    /*!<EEPROM Address Register */
	__IO uint32_t	DI;                     /*!<EEPROM Read Data Register */
	__IO uint32_t	DO;                     /*!<EEPROM Write Data Register */
	__IO uint32_t	KEY;                    /*!<EEPROM Key Register */
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

/** @} */ /* End of group EEPROM */

/** @defgroup MDR1986BE4_Periph_RST_CLK RST_CLK
  * @{
  */


/* MDR_RST_CLK_TypeDef structure */
typedef struct {
	__IO uint32_t	CLOCK_STATUS;           /*!<Clock Status Register */
	__IO uint32_t	PLL_CONTROL;            /*!<PLL Control Register */
	__IO uint32_t	HS_CONTROL;             /*!<HS Control Register */
	__IO uint32_t	CPU_CLOCK;              /*!<CPU Clock Register */
	__IO uint32_t	PER1_CLOCK;             /*!<PER1 Clock Register */
	__IO uint32_t	ADC_MCO_CLOCK;          /*!<ADC Clock Register */
	__IO uint32_t	RTC_CLOCK;              /*!<RTC Clock Register */
	__IO uint32_t	PER2_CLOCK;             /*!<Peripheral Clock Enable Register */
	__I  uint32_t	RESERVED0;
	__IO uint32_t	TIM_CLOCK;              /*!<Timer Clock Register */
	__IO uint32_t	UART_CLOCK;             /*!<UART Clock Register */
	__IO uint32_t	SSP_CLOCK;              /*!<SSP Clock Register */
}MDR_RST_CLK_TypeDef;

/** @defgroup Periph_RST_CLK_CLOCK_STATUS RST_CLK CLOCK_STATUS
  * @{
  */

/*-- RST_CLK_CLOCK_STATUS:RST_CLK CLOCK_STATUS Register -----*/

/* Bit field positions: */
#define RST_CLK_CLOCK_STATUS_PLL_CPU_RDY_Pos               1
#define RST_CLK_CLOCK_STATUS_HSE_RDY_Pos                   2

/* Bit field masks: */
#define RST_CLK_CLOCK_STATUS_PLL_CPU_RDY                   ((uint32_t)0x00000002)
#define RST_CLK_CLOCK_STATUS_HSE_RDY                       ((uint32_t)0x00000004)

/** @} */ /* End of group RST_CLK_CLOCK_STATUS */

/** @defgroup Periph_RST_CLK_PLL_CONTROL RST_CLK PLL_CONTROL
  * @{
  */

/*-- RST_CLK_PLL_CONTROL:RST_CLK PLL_CONTROL Register -----*/

/* Bit field positions: */
#define RST_CLK_PLL_CONTROL_PLL_CPU_ON_Pos                 2
#define RST_CLK_PLL_CONTROL_PLL_CPU_PLD_Pos                3
#define RST_CLK_PLL_CONTROL_PLL_CPU_MUL_Pos                8

/* Bit field masks: */
#define RST_CLK_PLL_CONTROL_PLL_CPU_ON                     ((uint32_t)0x00000004)
#define RST_CLK_PLL_CONTROL_PLL_CPU_PLD                    ((uint32_t)0x00000008)
#define RST_CLK_PLL_CONTROL_PLL_CPU_MUL_Msk                ((uint32_t)0x00000F00)

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

/** @defgroup Periph_RST_CLK_PER1_CLOCK RST_CLK PER1_CLOCK
  * @{
  */

/*-- RST_CLK_PER1_CLOCK:RST_CLK PER1_CLOCK Register -----*/

/* Bit field positions: */
#define RST_CLK_PER1_CLOCK_C1_SEL_Pos                      0
#define RST_CLK_PER1_CLOCK_C2_SEL_Pos                      2
#define RST_CLK_PER1_CLOCK_DEBUG_EN_Pos                    4
#define RST_CLK_PER1_CLOCK_DMA_EN_Pos                      5

/* Bit field masks: */
#define RST_CLK_PER1_CLOCK_C1_SEL_Msk                      ((uint32_t)0x00000003)
#define RST_CLK_PER1_CLOCK_C2_SEL_Msk                      ((uint32_t)0x0000000C)
#define RST_CLK_PER1_CLOCK_DEBUG_EN                        ((uint32_t)0x00000010)
#define RST_CLK_PER1_CLOCK_DMA_EN                          ((uint32_t)0x00000020)

/** @} */ /* End of group RST_CLK_PER1_CLOCK */

/** @defgroup Periph_RST_CLK_ADC_MCO_CLOCK RST_CLK ADC_MCO_CLOCK
  * @{
  */

/*-- RST_CLK_ADC_MCO_CLOCK:RST_CLK ADC_MCO_CLOCK Register -----*/

/* Bit field positions: */
#define RST_CLK_ADC_MCO_CLOCK_ADC_C1_SEL_Pos               0
#define RST_CLK_ADC_MCO_CLOCK_ADCIU_C1_SEL_Pos             2
#define RST_CLK_ADC_MCO_CLOCK_ADCIU_C3_SEL_Pos             4
#define RST_CLK_ADC_MCO_CLOCK_ADC_C3_SEL_Pos               8
#define RST_CLK_ADC_MCO_CLOCK_ADCIU_CLK_EN_Pos             12
#define RST_CLK_ADC_MCO_CLOCK_ADC_CLK_EN_Pos               13

/* Bit field masks: */
#define RST_CLK_ADC_MCO_CLOCK_ADC_C1_SEL_Msk               ((uint32_t)0x00000003)
#define RST_CLK_ADC_MCO_CLOCK_ADCIU_C1_SEL_Msk             ((uint32_t)0x0000000C)
#define RST_CLK_ADC_MCO_CLOCK_ADCIU_C3_SEL_Msk             ((uint32_t)0x000000F0)
#define RST_CLK_ADC_MCO_CLOCK_ADC_C3_SEL_Msk               ((uint32_t)0x00000F00)
#define RST_CLK_ADC_MCO_CLOCK_ADCIU_CLK_EN                 ((uint32_t)0x00001000)
#define RST_CLK_ADC_MCO_CLOCK_ADC_CLK_EN                   ((uint32_t)0x00002000)

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

/** @defgroup Periph_RST_CLK_PER2_CLOCK RST_CLK PER2_CLOCK
  * @{
  */

/*-- RST_CLK_PER2_CLOCK:RST_CLK PER2_CLOCK Register -----*/

/* Bit field positions: */
#define RST_CLK_PER2_CLOCK_PCLK_EN_SPI_Pos                 0
#define RST_CLK_PER2_CLOCK_PCLK_EN_UART1_Pos               1
#define RST_CLK_PER2_CLOCK_PCLK_EN_UART2_Pos               2
#define RST_CLK_PER2_CLOCK_PCLK_EN_EEPROM_Pos              3
#define RST_CLK_PER2_CLOCK_PCLK_EN_RST_CLK_Pos             4
#define RST_CLK_PER2_CLOCK_PCLK_EN_DMA_Pos                 5
#define RST_CLK_PER2_CLOCK_PCLK_EN_COMP_Pos                6
#define RST_CLK_PER2_CLOCK_PCLK_EN_DAC_Pos                 7
#define RST_CLK_PER2_CLOCK_PCLK_EN_ADC_Pos                 8
#define RST_CLK_PER2_CLOCK_PCLK_EN_WWDT_Pos                9
#define RST_CLK_PER2_CLOCK_PCLK_EN_IWDT_Pos                10
#define RST_CLK_PER2_CLOCK_PCLK_EN_POWER_Pos               11
#define RST_CLK_PER2_CLOCK_PCLK_EN_BKP_Pos                 12
#define RST_CLK_PER2_CLOCK_PCLK_EN_ADCIU_Pos               13
#define RST_CLK_PER2_CLOCK_PCLK_EN_TIMRE1_Pos              14
#define RST_CLK_PER2_CLOCK_PCLK_EN_TIMER2_Pos              15
#define RST_CLK_PER2_CLOCK_PCLK_EN_PORTA_Pos               16
#define RST_CLK_PER2_CLOCK_PCLK_EN_PORTB_Pos               17
#define RST_CLK_PER2_CLOCK_PCLK_EN_PORTC_Pos               18
#define RST_CLK_PER2_CLOCK_PCLK_EN_CRC_Pos                 19

/* Bit field masks: */
#define RST_CLK_PER2_CLOCK_PCLK_EN_SPI                     ((uint32_t)0x00000001)
#define RST_CLK_PER2_CLOCK_PCLK_EN_UART1                   ((uint32_t)0x00000002)
#define RST_CLK_PER2_CLOCK_PCLK_EN_UART2                   ((uint32_t)0x00000004)
#define RST_CLK_PER2_CLOCK_PCLK_EN_EEPROM                  ((uint32_t)0x00000008)
#define RST_CLK_PER2_CLOCK_PCLK_EN_RST_CLK                 ((uint32_t)0x00000010)
#define RST_CLK_PER2_CLOCK_PCLK_EN_DMA                     ((uint32_t)0x00000020)
#define RST_CLK_PER2_CLOCK_PCLK_EN_COMP                    ((uint32_t)0x00000040)
#define RST_CLK_PER2_CLOCK_PCLK_EN_DAC                     ((uint32_t)0x00000080)
#define RST_CLK_PER2_CLOCK_PCLK_EN_ADC                     ((uint32_t)0x00000100)
#define RST_CLK_PER2_CLOCK_PCLK_EN_WWDT                    ((uint32_t)0x00000200)
#define RST_CLK_PER2_CLOCK_PCLK_EN_IWDT                    ((uint32_t)0x00000400)
#define RST_CLK_PER2_CLOCK_PCLK_EN_POWER                   ((uint32_t)0x00000800)
#define RST_CLK_PER2_CLOCK_PCLK_EN_BKP                     ((uint32_t)0x00001000)
#define RST_CLK_PER2_CLOCK_PCLK_EN_ADCIU                   ((uint32_t)0x00002000)
#define RST_CLK_PER2_CLOCK_PCLK_EN_TIMRE1                  ((uint32_t)0x00004000)
#define RST_CLK_PER2_CLOCK_PCLK_EN_TIMER2                  ((uint32_t)0x00008000)
#define RST_CLK_PER2_CLOCK_PCLK_EN_PORTA                   ((uint32_t)0x00010000)
#define RST_CLK_PER2_CLOCK_PCLK_EN_PORTB                   ((uint32_t)0x00020000)
#define RST_CLK_PER2_CLOCK_PCLK_EN_PORTC                   ((uint32_t)0x00040000)
#define RST_CLK_PER2_CLOCK_PCLK_EN_CRC                     ((uint32_t)0x00080000)

/** @} */ /* End of group RST_CLK_PER2_CLOCK */

/** @defgroup Periph_RST_CLK_TIM_CLOCK RST_CLK TIM_CLOCK
  * @{
  */

/*-- RST_CLK_TIM_CLOCK:RST_CLK TIM_CLOCK Register -----*/

/* Bit field positions: */
#define RST_CLK_TIM_CLOCK_TIM1_BRG_Pos                     0
#define RST_CLK_TIM_CLOCK_TIM2_BRG_Pos                     8
#define RST_CLK_TIM_CLOCK_TIM1_CLK_EN_Pos                  24
#define RST_CLK_TIM_CLOCK_TIM2_CLK_EN_Pos                  25

/* Bit field masks: */
#define RST_CLK_TIM_CLOCK_TIM1_BRG_Msk                     ((uint32_t)0x000000FF)
#define RST_CLK_TIM_CLOCK_TIM2_BRG_Msk                     ((uint32_t)0x0000FF00)
#define RST_CLK_TIM_CLOCK_TIM1_CLK_EN                      ((uint32_t)0x01000000)
#define RST_CLK_TIM_CLOCK_TIM2_CLK_EN                      ((uint32_t)0x02000000)

/** @} */ /* End of group RST_CLK_TIM_CLOCK */

/** @defgroup Periph_RST_CLK_UART_CLOCK RST_CLK UART_CLOCK
  * @{
  */

/*-- RST_CLK_UART_CLOCK:RST_CLK UART_CLOCK Register -----*/

/* Bit field positions: */
#define RST_CLK_UART_CLOCK_UART1_BRG_Pos                   0
#define RST_CLK_UART_CLOCK_UART2_BRG_Pos                   8
#define RST_CLK_UART_CLOCK_UART1_CLK_EN_Pos                24
#define RST_CLK_UART_CLOCK_UART2_CLK_EN_Pos                25

/* Bit field masks: */
#define RST_CLK_UART_CLOCK_UART1_BRG_Msk                   ((uint32_t)0x000000FF)
#define RST_CLK_UART_CLOCK_UART2_BRG_Msk                   ((uint32_t)0x0000FF00)
#define RST_CLK_UART_CLOCK_UART1_CLK_EN                    ((uint32_t)0x01000000)
#define RST_CLK_UART_CLOCK_UART2_CLK_EN                    ((uint32_t)0x02000000)

/** @} */ /* End of group RST_CLK_UART_CLOCK */

/** @defgroup Periph_RST_CLK_SSP_CLOCK RST_CLK SSP_CLOCK
  * @{
  */

/*-- RST_CLK_SSP_CLOCK:RST_CLK SSP_CLOCK Register -----*/

/* Bit field positions: */
#define RST_CLK_SSP_CLOCK_SSP1_BRG_Pos                     0
#define RST_CLK_SSP_CLOCK_SSP1_CLK_EN_Pos                  24

/* Bit field masks: */
#define RST_CLK_SSP_CLOCK_SSP1_BRG_Msk                     ((uint32_t)0x000000FF)
#define RST_CLK_SSP_CLOCK_SSP1_CLK_EN                      ((uint32_t)0x01000000)

/** @} */ /* End of group RST_CLK_SSP_CLOCK */

/** @} */ /* End of group RST_CLK */

/** @defgroup MDR1986BE4_Periph_DMA DMA
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

/** @defgroup MDR1986BE4_Periph_COMP COMP
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

/** @defgroup MDR1986BE4_Periph_DAC DAC
  * @{
  */


/* MDR_DAC_TypeDef structure */
typedef struct {
	__IO uint32_t	CFG;                    /*!<DAC Configuration Register */
	__IO uint32_t	DAC1_DATA;              /*!<DAC1 Data Register */
}MDR_DAC_TypeDef;

/** @defgroup Periph_DAC_CFG  DAC_CFG
  * @{
  */

/*-- DAC_CFG: DAC_CFG Register -----*/

/* Bit field positions: */
#define DAC_CFG_M_REF0_Pos                                 0
#define DAC_CFG_ON_DAC0_Pos                                2
#define DAC_CFG_SYNC_A_Pos                                 4

/* Bit field masks: */
#define DAC_CFG_M_REF0                                     ((uint32_t)0x00000001)
#define DAC_CFG_ON_DAC0                                    ((uint32_t)0x00000004)
#define DAC_CFG_SYNC_A                                     ((uint32_t)0x00000010)

/** @} */ /* End of group DAC_CFG */

/** @defgroup Periph_DAC1_DATA  DAC1_DATA
  * @{
  */

/*-- DAC1_DATA: DAC1_DATA Register -----*/

/* Bit field positions: */
#define DAC1_DATA_DAC0DATA_Pos                             0

/* Bit field masks: */
#define DAC1_DATA_DAC0DATA_Msk                             ((uint32_t)0x00000FFF)

/** @} */ /* End of group DAC1_DATA */

/** @} */ /* End of group DAC */

/** @defgroup MDR1986BE4_Periph_ADC ADC
  * @{
  */


/* MDR_ADC_TypeDef structure */
typedef struct {
	__IO uint32_t	ADC1_CFG;               /*!<ADC1 Configuration Register */
	__IO uint32_t	ADC2_CFG;               /*!<ADC2 Configuration Register */
	__IO uint32_t	ADC1_H_LEVEL;           /*!<ADC1 High Level Register */
	__I  uint32_t	RESERVED0;
	__IO uint32_t	ADC1_L_LEVEL;           /*!<ADC1 Low Level Register */
	__I  uint32_t	RESERVED1;
	__IO uint32_t	ADC1_RESULT;            /*!<ADC1 Result Register */
	__I  uint32_t	RESERVED2;
	__IO uint32_t	ADC1_STATUS;            /*!<ADC1 Status Register */
	__I  uint32_t	RESERVED3;
	__IO uint32_t	ADC1_CHSEL;             /*!<ADC1 Channel Selector Register */
	__I  uint32_t	RESERVED4;
	__IO uint32_t	ADC1_TRIM;              /*!< */
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
#define ADC2_CFG_ADC1_OP_Pos                               17

/* Bit field masks: */
#define ADC2_CFG_ADC1_OP                                   ((uint32_t)0x00020000)

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

/** @defgroup Periph_ADC1_L_LEVEL  ADC1_L_LEVEL
  * @{
  */

/*-- ADC1_L_LEVEL: ADC1_L_LEVEL Register -----*/

/* Bit field positions: */
#define ADC1_L_LEVEL_REG_L_LEVEL_Pos                       0

/* Bit field masks: */
#define ADC1_L_LEVEL_REG_L_LEVEL_Msk                       ((uint32_t)0x00000FFF)

/** @} */ /* End of group ADC1_L_LEVEL */

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

/** @defgroup Periph_ADC1_STATUS  ADC1_STATUS
  * @{
  */

/*-- ADC1_STATUS: ADC1_STATUS Register -----*/

/* Bit field positions: */
#define ADC1_STATUS_FLG_REG_OVERWRITE_Pos                  0
#define ADC1_STATUS_FLG_REG_AWOIFEN_Pos                    1
#define ADC1_STATUS_FLG_REG_EOCIF_Pos                      2
#define ADC1_STATUS_AWOIF_IE_Pos                           3
#define ADC1_STATUS_ECOIF_IE_Pos                           4

/* Bit field masks: */
#define ADC1_STATUS_FLG_REG_OVERWRITE                      ((uint32_t)0x00000001)
#define ADC1_STATUS_FLG_REG_AWOIFEN                        ((uint32_t)0x00000002)
#define ADC1_STATUS_FLG_REG_EOCIF                          ((uint32_t)0x00000004)
#define ADC1_STATUS_AWOIF_IE                               ((uint32_t)0x00000008)
#define ADC1_STATUS_ECOIF_IE                               ((uint32_t)0x00000010)

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

/** @defgroup Periph_ADC1_TRIM  ADC1_TRIM
  * @{
  */

/*-- ADC1_TRIM: ADC1_TRIM Register -----*/

/* Bit field positions: */
#define ADC1_TRIM_TS_TRIM_Pos                              1
#define ADC1_TRIM_SEL_VREF_BUF_Pos                         6

/* Bit field masks: */
#define ADC1_TRIM_TS_TRIM_Msk                              ((uint32_t)0x0000003E)
#define ADC1_TRIM_SEL_VREF_BUF                             ((uint32_t)0x00000040)

/** @} */ /* End of group ADC1_TRIM */

/** @} */ /* End of group ADC */

/** @defgroup MDR1986BE4_Periph_WWDG WWDG
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

/** @defgroup MDR1986BE4_Periph_IWDG IWDG
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

/** @defgroup MDR1986BE4_Periph_POWER POWER
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
#define POWER_PVDCS_PVDBEN_Pos                             12

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
#define POWER_PVDCS_PVDBEN                                 ((uint32_t)0x00001000)

/** @} */ /* End of group POWER_PVDCS */

/** @} */ /* End of group POWER */

/** @defgroup MDR1986BE4_Periph_BKP BKP
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
#define BKP_REG_0E_TRIM20_Pos                              8
#define BKP_REG_0E_FPOR_Pos                                11
#define BKP_REG_0E_TRIM43_Pos                              12
#define BKP_REG_0E_COVDET_Pos                              14
#define BKP_REG_0E_ILIMEN_Pos                              15

/* Bit field masks: */
#define BKP_REG_0E_LOW_Msk                                 ((uint32_t)0x00000007)
#define BKP_REG_0E_SELECTRI_Msk                            ((uint32_t)0x00000038)
#define BKP_REG_0E_JTAGA                                   ((uint32_t)0x00000040)
#define BKP_REG_0E_JTAGB                                   ((uint32_t)0x00000080)
#define BKP_REG_0E_TRIM20_Msk                              ((uint32_t)0x00000700)
#define BKP_REG_0E_FPOR                                    ((uint32_t)0x00000800)
#define BKP_REG_0E_TRIM43_Msk                              ((uint32_t)0x00003000)
#define BKP_REG_0E_COVDET                                  ((uint32_t)0x00004000)
#define BKP_REG_0E_ILIMEN                                  ((uint32_t)0x00008000)

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

/** @defgroup MDR1986BE4_Periph_ADCIU ADCIU
  * @{
  */


/* MDR_ADCIU_TypeDef structure */
typedef struct {
	__IO uint32_t	CTRL1;                  /*!< */
	__IO uint32_t	ANGAIN;                 /*!< */
	__IO uint32_t	DIGGAIN;                /*!< */
	__IO uint32_t	DMAEN;                  /*!< */
	__IO uint32_t	CTRL2;                  /*!< */
	__IO uint32_t	INTEN;                  /*!< */
	__IO uint32_t	STAT;                   /*!< */
	__IO uint32_t	F_DAT[8];               /*!< */
	__IO uint32_t	TST;                    /*!< */
}MDR_ADCIU_TypeDef;

/** @defgroup Periph_ADCIU_CTRL1 ADCIU CTRL1
  * @{
  */

/*-- ADCIU_CTRL1:ADCIU CTRL1 Register -----*/

/* Bit field positions: */
#define ADCIU_CTRL1_ADC1EN_Pos                             0
#define ADCIU_CTRL1_ADC2EN_Pos                             1
#define ADCIU_CTRL1_ADC3EN_Pos                             2
#define ADCIU_CTRL1_ADC4EN_Pos                             3
#define ADCIU_CTRL1_ADC5EN_Pos                             4
#define ADCIU_CTRL1_ADC6EN_Pos                             5
#define ADCIU_CTRL1_ADC7EN_Pos                             6
#define ADCIU_CTRL1_ADC8EN_Pos                             7
#define ADCIU_CTRL1_REF_EX_Pos                             8
#define ADCIU_CTRL1_CHP1EN_Pos                             9
#define ADCIU_CTRL1_CHP2EN_Pos                             10
#define ADCIU_CTRL1_CHP3EN_Pos                             11
#define ADCIU_CTRL1_CHP4EN_Pos                             12
#define ADCIU_CTRL1_CHP5EN_Pos                             13
#define ADCIU_CTRL1_CHP6EN_Pos                             14
#define ADCIU_CTRL1_CHP7EN_Pos                             15
#define ADCIU_CTRL1_CHP8EN_Pos                             16

/* Bit field masks: */
#define ADCIU_CTRL1_ADC1EN                                 ((uint32_t)0x00000001)
#define ADCIU_CTRL1_ADC2EN                                 ((uint32_t)0x00000002)
#define ADCIU_CTRL1_ADC3EN                                 ((uint32_t)0x00000004)
#define ADCIU_CTRL1_ADC4EN                                 ((uint32_t)0x00000008)
#define ADCIU_CTRL1_ADC5EN                                 ((uint32_t)0x00000010)
#define ADCIU_CTRL1_ADC6EN                                 ((uint32_t)0x00000020)
#define ADCIU_CTRL1_ADC7EN                                 ((uint32_t)0x00000040)
#define ADCIU_CTRL1_ADC8EN                                 ((uint32_t)0x00000080)
#define ADCIU_CTRL1_REF_EX                                 ((uint32_t)0x00000100)
#define ADCIU_CTRL1_CHP1EN                                 ((uint32_t)0x00000200)
#define ADCIU_CTRL1_CHP2EN                                 ((uint32_t)0x00000400)
#define ADCIU_CTRL1_CHP3EN                                 ((uint32_t)0x00000800)
#define ADCIU_CTRL1_CHP4EN                                 ((uint32_t)0x00001000)
#define ADCIU_CTRL1_CHP5EN                                 ((uint32_t)0x00002000)
#define ADCIU_CTRL1_CHP6EN                                 ((uint32_t)0x00004000)
#define ADCIU_CTRL1_CHP7EN                                 ((uint32_t)0x00008000)
#define ADCIU_CTRL1_CHP8EN                                 ((uint32_t)0x00010000)

/** @} */ /* End of group ADCIU_CTRL1 */

/** @defgroup Periph_ADCIU_ANGAIN ADCIU ANGAIN
  * @{
  */

/*-- ADCIU_ANGAIN:ADCIU ANGAIN Register -----*/

/* Bit field positions: */
#define ADCIU_ANGAIN_ADC1PGA_Pos                           0
#define ADCIU_ANGAIN_ADC2PGA_Pos                           2
#define ADCIU_ANGAIN_ADC3PGA_Pos                           4
#define ADCIU_ANGAIN_ADC4PGA_Pos                           6
#define ADCIU_ANGAIN_ADC5PGA_Pos                           8
#define ADCIU_ANGAIN_ADC6PGA_Pos                           10
#define ADCIU_ANGAIN_ADC7PGA_Pos                           12
#define ADCIU_ANGAIN_ADC8PGA_Pos                           14

/* Bit field masks: */
#define ADCIU_ANGAIN_ADC1PGA_Msk                           ((uint32_t)0x00000003)
#define ADCIU_ANGAIN_ADC2PGA_Msk                           ((uint32_t)0x0000000C)
#define ADCIU_ANGAIN_ADC3PGA_Msk                           ((uint32_t)0x00000030)
#define ADCIU_ANGAIN_ADC4PGA_Msk                           ((uint32_t)0x000000C0)
#define ADCIU_ANGAIN_ADC5PGA_Msk                           ((uint32_t)0x00000300)
#define ADCIU_ANGAIN_ADC6PGA_Msk                           ((uint32_t)0x00000C00)
#define ADCIU_ANGAIN_ADC7PGA_Msk                           ((uint32_t)0x00003000)
#define ADCIU_ANGAIN_ADC8PGA_Msk                           ((uint32_t)0x0000C000)

/** @} */ /* End of group ADCIU_ANGAIN */

/** @defgroup Periph_ADCIU_DIGGAN ADCIU DIGGAIN
  * @{
  */

/*-- ADCIU_DIGGAN:ADCIU DIGGAIN Register -----*/

/* Bit field positions: */
#define ADCIU_DIGGAN_ADCPGA_Pos                            0

/* Bit field masks: */
#define ADCIU_DIGGAN_ADCPGA_Msk                            ((uint32_t)0x0000003F)

/** @} */ /* End of group ADCIU_DIGGAN */

/** @defgroup Periph_ADCIU_DMAEN ADCIU DMAEN
  * @{
  */

/*-- ADCIU_DMAEN:ADCIU DMAEN Register -----*/

/* Bit field positions: */
#define ADCIU_DMAEN_DMA_EN1_Pos                            0
#define ADCIU_DMAEN_DMA_EN2_Pos                            1
#define ADCIU_DMAEN_DMA_EN3_Pos                            2
#define ADCIU_DMAEN_DMA_EN4_Pos                            3
#define ADCIU_DMAEN_DMA_EN5_Pos                            4
#define ADCIU_DMAEN_DMA_EN6_Pos                            5
#define ADCIU_DMAEN_DMA_EN7_Pos                            6
#define ADCIU_DMAEN_DMA_EN8_Pos                            7

/* Bit field masks: */
#define ADCIU_DMAEN_DMA_EN1                                ((uint32_t)0x00000001)
#define ADCIU_DMAEN_DMA_EN2                                ((uint32_t)0x00000002)
#define ADCIU_DMAEN_DMA_EN3                                ((uint32_t)0x00000004)
#define ADCIU_DMAEN_DMA_EN4                                ((uint32_t)0x00000008)
#define ADCIU_DMAEN_DMA_EN5                                ((uint32_t)0x00000010)
#define ADCIU_DMAEN_DMA_EN6                                ((uint32_t)0x00000020)
#define ADCIU_DMAEN_DMA_EN7                                ((uint32_t)0x00000040)
#define ADCIU_DMAEN_DMA_EN8                                ((uint32_t)0x00000080)

/** @} */ /* End of group ADCIU_DMAEN */

/** @defgroup Periph_ADCIU_CTRL2 ADCIU CTRL2
  * @{
  */

/*-- ADCIU_CTRL2:ADCIU CTRL2 Register -----*/

/* Bit field positions: */
#define ADCIU_CTRL2_SFF_Pos                                0
#define ADCIU_CTRL2_SFC_Pos                                7
#define ADCIU_CTRL2_RESET_Pos                              10
#define ADCIU_CTRL2_BF_BP_Pos                              11
#define ADCIU_CTRL2_CHOP_FREQ_Pos                          12

/* Bit field masks: */
#define ADCIU_CTRL2_SFF_Msk                                ((uint32_t)0x0000007F)
#define ADCIU_CTRL2_SFC_Msk                                ((uint32_t)0x00000380)
#define ADCIU_CTRL2_RESET                                  ((uint32_t)0x00000400)
#define ADCIU_CTRL2_BF_BP                                  ((uint32_t)0x00000800)
#define ADCIU_CTRL2_CHOP_FREQ_Msk                          ((uint32_t)0x00003000)

/** @} */ /* End of group ADCIU_CTRL2 */

/** @defgroup Periph_ADCIU_INTEN ADCIU INTEN
  * @{
  */

/*-- ADCIU_INTEN:ADCIU INTEN Register -----*/

/* Bit field positions: */
#define ADCIU_INTEN_NS1M_Pos                               0
#define ADCIU_INTEN_NS2M_Pos                               1
#define ADCIU_INTEN_NS3M_Pos                               2
#define ADCIU_INTEN_NS4M_Pos                               3
#define ADCIU_INTEN_NS5M_Pos                               4
#define ADCIU_INTEN_NS6M_Pos                               5
#define ADCIU_INTEN_NS7M_Pos                               6
#define ADCIU_INTEN_NS8M_Pos                               7
#define ADCIU_INTEN_OV1M_Pos                               8
#define ADCIU_INTEN_OV2M_Pos                               9
#define ADCIU_INTEN_OV3M_Pos                               10
#define ADCIU_INTEN_OV4M_Pos                               11
#define ADCIU_INTEN_OV5M_Pos                               12
#define ADCIU_INTEN_OV6M_Pos                               13
#define ADCIU_INTEN_OV7M_Pos                               14
#define ADCIU_INTEN_OV8M_Pos                               15

/* Bit field masks: */
#define ADCIU_INTEN_NSM1                                   ((uint32_t)0x00000001)
#define ADCIU_INTEN_NS2M                                   ((uint32_t)0x00000002)
#define ADCIU_INTEN_NS3M                                   ((uint32_t)0x00000004)
#define ADCIU_INTEN_NS4M                                   ((uint32_t)0x00000008)
#define ADCIU_INTEN_NS5M                                   ((uint32_t)0x00000010)
#define ADCIU_INTEN_NS6M                                   ((uint32_t)0x00000020)
#define ADCIU_INTEN_NS7M                                   ((uint32_t)0x00000040)
#define ADCIU_INTEN_NS8M                                   ((uint32_t)0x00000080)
#define ADCIU_INTEN_OV1M                                   ((uint32_t)0x00000100)
#define ADCIU_INTEN_OV2M                                   ((uint32_t)0x00000200)
#define ADCIU_INTEN_OV3M                                   ((uint32_t)0x00000400)
#define ADCIU_INTEN_OV4M                                   ((uint32_t)0x00000800)
#define ADCIU_INTEN_OV5M                                   ((uint32_t)0x00001000)
#define ADCIU_INTEN_OV6M                                   ((uint32_t)0x00002000)
#define ADCIU_INTEN_OV7M                                   ((uint32_t)0x00004000)
#define ADCIU_INTEN_OV8M                                   ((uint32_t)0x00008000)

/** @} */ /* End of group ADCIU_INTEN */

/** @defgroup Periph_ADCIU_STAT ADCIU STAT
  * @{
  */

/*-- ADCIU_STAT:ADCIU STAT Register -----*/

/* Bit field positions: */
#define ADCIU_STAT_NS1_Pos                                 0
#define ADCIU_STAT_NS2_Pos                                 1
#define ADCIU_STAT_NS3_Pos                                 2
#define ADCIU_STAT_NS4_Pos                                 3
#define ADCIU_STAT_NS5_Pos                                 4
#define ADCIU_STAT_NS6_Pos                                 5
#define ADCIU_STAT_NS7_Pos                                 6
#define ADCIU_STAT_NS8_Pos                                 7
#define ADCIU_STAT_OV1_Pos                                 8
#define ADCIU_STAT_OV2_Pos                                 9
#define ADCIU_STAT_OV3_Pos                                 10
#define ADCIU_STAT_OV4_Pos                                 11
#define ADCIU_STAT_OV5_Pos                                 12
#define ADCIU_STAT_OV6_Pos                                 13
#define ADCIU_STAT_OV7_Pos                                 14
#define ADCIU_STAT_OV8_Pos                                 15

/* Bit field masks: */
#define ADCIU_STAT_NS1                                     ((uint32_t)0x00000001)
#define ADCIU_STAT_NS2                                     ((uint32_t)0x00000002)
#define ADCIU_STAT_NS3                                     ((uint32_t)0x00000004)
#define ADCIU_STAT_NS4                                     ((uint32_t)0x00000008)
#define ADCIU_STAT_NS5                                     ((uint32_t)0x00000010)
#define ADCIU_STAT_NS6                                     ((uint32_t)0x00000020)
#define ADCIU_STAT_NS7                                     ((uint32_t)0x00000040)
#define ADCIU_STAT_NS8                                     ((uint32_t)0x00000080)
#define ADCIU_STAT_OV1                                     ((uint32_t)0x00000100)
#define ADCIU_STAT_OV2                                     ((uint32_t)0x00000200)
#define ADCIU_STAT_OV3                                     ((uint32_t)0x00000400)
#define ADCIU_STAT_OV4                                     ((uint32_t)0x00000800)
#define ADCIU_STAT_OV5                                     ((uint32_t)0x00001000)
#define ADCIU_STAT_OV6                                     ((uint32_t)0x00002000)
#define ADCIU_STAT_OV7                                     ((uint32_t)0x00004000)
#define ADCIU_STAT_OV8                                     ((uint32_t)0x00008000)

/** @} */ /* End of group ADCIU_STAT */

/** @defgroup Periph_ADCIU_F_DAT ADCIU F_DAT
  * @{
  */

/*-- ADCIU_F_DAT:ADCIU F_DAT Register -----*/

/* Bit field positions: */
#define ADCIU_F_DAT_SMPLE_Pos                              0

/* Bit field masks: */
#define ADCIU_F_DAT_SMPLE_Msk                              ((uint32_t)0x00FFFFFF)

/** @} */ /* End of group ADCIU_F_DAT */

/** @} */ /* End of group ADCIU */

/** @defgroup MDR1986BE4_Periph_TIMER TIMER
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
#define TIMER_CH_DTG_DTGX_Pos                              0
#define TIMER_CH_DTG_EDTS_Pos                              4
#define TIMER_CH_DTG_DTG_Pos                               8

/* Bit field masks: */
#define TIMER_CH_DTG_DTGX_Msk                              ((uint32_t)0x0000000F)
#define TIMER_CH_DTG_EDTS                                  ((uint32_t)0x00000010)
#define TIMER_CH_DTG_DTG_Msk                               ((uint32_t)0x0000FF00)

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

/** @defgroup MDR1986BE4_Periph_PORT PORT
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

/** @defgroup MDR1986BE4_Periph_CRC CRC
  * @{
  */


/* MDR_CRC_TypeDef structure */
typedef struct {
	__IO uint32_t	CTRL;                   /*!< */
	__IO uint32_t	STAT;                   /*!< */
	__IO uint32_t	DATAI;                  /*!< */
	__IO uint32_t	VAL;                    /*!< */
	__IO uint32_t	POL;                    /*!< */
}MDR_CRC_TypeDef;

/** @defgroup Periph_CRC_CTRL CRC CTRL
  * @{
  */

/*-- CRC_CTRL:CRC CTRL Register -----*/

/* Bit field positions: */
#define CRC_CTRL_CRCEN_Pos                                 0
#define CRC_CTRL_DATAINV_Pos                               1
#define CRC_CTRL_DMAEN_Pos                                 2
#define CRC_CTRL_DLSIZE_Pos                                3
#define CRC_CTRL_DCSIZE_Pos                                5

/* Bit field masks: */
#define CRC_CTRL_CRCEN                                     ((uint32_t)0x00000001)
#define CRC_CTRL_DATAINV                                   ((uint32_t)0x00000002)
#define CRC_CTRL_DMAEN                                     ((uint32_t)0x00000004)
#define CRC_CTRL_DLSIZE_Msk                                ((uint32_t)0x00000018)
#define CRC_CTRL_DCSIZE_Msk                                ((uint32_t)0x00000060)

/** @} */ /* End of group CRC_CTRL */

/** @defgroup Periph_CRC_STAT CRC STAT
  * @{
  */

/*-- CRC_STAT:CRC STAT Register -----*/

/* Bit field positions: */
#define CRC_STAT_CONVCOMP_Pos                              0
#define CRC_STAT_FIFOFULL_Pos                              1
#define CRC_STAT_FIFOEMPTY_Pos                             2
#define CRC_STAT_FIFOOVER_Pos                              3

/* Bit field masks: */
#define CRC_STAT_CONVCOMP                                  ((uint32_t)0x00000001)
#define CRC_STAT_FIFOFULL                                  ((uint32_t)0x00000002)
#define CRC_STAT_FIFOEMPTY                                 ((uint32_t)0x00000004)
#define CRC_STAT_FIFOOVER                                  ((uint32_t)0x00000008)

/** @} */ /* End of group CRC_STAT */

/** @defgroup Periph_CRC_DATAI CRC DATAI
  * @{
  */

/*-- CRC_DATAI:CRC DATAI Register -----*/

/* Bit field positions: */
#define CRC_DATAI_DATA_IN_Pos                              0

/* Bit field masks: */
#define CRC_DATAI_DATA_IN_Msk                              ((uint32_t)0xFFFFFFFF)

/** @} */ /* End of group CRC_DATAI */

/** @defgroup Periph_CRC_VAL CRC VAL
  * @{
  */

/*-- CRC_VAL:CRC VAL Register -----*/

/* Bit field positions: */
#define CRC_VAL_CRCOUT_Pos                                 0

/* Bit field masks: */
#define CRC_VAL_CRCOUT_Msk                                 ((uint32_t)0x0000FFFF)

/** @} */ /* End of group CRC_VAL */

/** @defgroup Periph_CRC_POL CRC POL
  * @{
  */

/*-- CRC_POL:CRC POL Register -----*/

/* Bit field positions: */
#define CRC_POL_CRC_POL_Pos                                0

/* Bit field masks: */
#define CRC_POL_CRC_POL_Msk                                ((uint32_t)0x0001FFFF)

/** @} */ /* End of group CRC_POL */

/** @} */ /* End of group CRC */

/** @} */ /* End of group MDR1986BE4 */

/** @defgroup __Peripheral_Memory_Map  Peripheral Memory Map
  * @{
  */

#define MDR_SSP1_BASE                  (0x40000000)
#define MDR_UART1_BASE                 (0x40008000)
#define MDR_UART2_BASE                 (0x40010000)
#define MDR_EEPROM_BASE                (0x40018000)
#define MDR_RST_CLK_BASE               (0x40020000)
#define MDR_DMA_BASE                   (0x40028000)
#define MDR_COMP_BASE                  (0x40030000)
#define MDR_DAC_BASE                   (0x40038000)
#define MDR_ADC_BASE                   (0x40040000)
#define MDR_WWDG_BASE                  (0x40048000)
#define MDR_IWDG_BASE                  (0x40050000)
#define MDR_POWER_BASE                 (0x40058000)
#define MDR_BKP_BASE                   (0x40060000)
#define MDR_ADCIU_BASE                 (0x40068000)
#define MDR_TIMER1_BASE                (0x40070000)
#define MDR_TIMER2_BASE                (0x40078000)
#define MDR_PORTA_BASE                 (0x40080000)
#define MDR_PORTB_BASE                 (0x40088000)
#define MDR_PORTC_BASE                 (0x40090000)
#define MDR_CRC_BASE                   (0x40098000)

/** @} */ /* End of group __Peripheral_Memory_Map */

/** @defgroup __Peripheral_declaration Peripheral declaration __Peripheral_declaration Peripheral declaration
  * @{
  */

#define MDR_SSP1                       ((MDR_SSP_TypeDef 	*) MDR_SSP1_BASE)
#define MDR_UART1                      ((MDR_UART_TypeDef 	*) MDR_UART1_BASE)
#define MDR_UART2                      ((MDR_UART_TypeDef 	*) MDR_UART2_BASE)
#define MDR_EEPROM                     ((MDR_EEPROM_TypeDef 	*) MDR_EEPROM_BASE)
#define MDR_RST_CLK                    ((MDR_RST_CLK_TypeDef 	*) MDR_RST_CLK_BASE)
#define MDR_DMA                        ((MDR_DMA_TypeDef 	*) MDR_DMA_BASE)
#define MDR_COMP                       ((MDR_COMP_TypeDef 	*) MDR_COMP_BASE)
#define MDR_DAC                        ((MDR_DAC_TypeDef 	*) MDR_DAC_BASE)
#define MDR_ADC                        ((MDR_ADC_TypeDef 	*) MDR_ADC_BASE)
#define MDR_WWDG                       ((MDR_WWDG_TypeDef 	*) MDR_WWDG_BASE)
#define MDR_IWDG                       ((MDR_IWDG_TypeDef 	*) MDR_IWDG_BASE)
#define MDR_POWER                      ((MDR_POWER_TypeDef 	*) MDR_POWER_BASE)
#define MDR_BKP                        ((MDR_BKP_TypeDef 	*) MDR_BKP_BASE)
#define MDR_ADCIU                      ((MDR_ADCIU_TypeDef 	*) MDR_ADCIU_BASE)
#define MDR_TIMER1                     ((MDR_TIMER_TypeDef 	*) MDR_TIMER1_BASE)
#define MDR_TIMER2                     ((MDR_TIMER_TypeDef 	*) MDR_TIMER2_BASE)
#define MDR_PORTA                      ((MDR_PORT_TypeDef 	*) MDR_PORTA_BASE)
#define MDR_PORTB                      ((MDR_PORT_TypeDef 	*) MDR_PORTB_BASE)
#define MDR_PORTC                      ((MDR_PORT_TypeDef 	*) MDR_PORTC_BASE)
#define MDR_CRC                        ((MDR_CRC_TypeDef 	*) MDR_CRC_BASE)

/** @} */ /* End of group __Peripheral_declaration */

#ifdef __cplusplus
}
#endif

/** @} */ /* End of group __MDR1986BE4_Peripheral*/

/** @} */ /* End of group MDR1986BE4*/

/** @} */ /* End of group __CMSIS */

#endif /* MDR_MDR1986BE4 */

/*
*
* END OF FILE __MDR1986BE4_H*/
