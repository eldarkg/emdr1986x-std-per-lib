/**
  * FILE MDR32F9Qx_usb.c
  */

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_config.h"
#include "MDR32F9Qx_usb.h"
#include "MDR32F9Qx_rst_clk.h"


#define ASSERT_INFO_FILE_ID FILEID__MDR32F9X_USB_C

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @defgroup USB USB
  * @{
  */

/** @defgroup USB_Private_Defines USB Private Defines
  * @{
  */

#define BIT_SET_Msk                          0xFFFFUL

/** @} */ /* End of group USB_Private_Defines */

/** @defgroup USB_Private_Macros USB Private Macros
  * @{
  */

#define USB_SFR_SET(SFR, VAL)   do {                                  \
                                  uint32_t tmpreg  = (SFR);      \
                                  tmpreg |= ((VAL) & BIT_SET_Msk);    \
                                  tmpreg &= (~((VAL) >> 16));         \
                                  (SFR) = tmpreg;                \
                                } while (0)

/** @} */ /* End of group USB_Private_Macros */

/** @defgroup USB_Private_Functions USB Private Functions
  * @{
  */

/**
  * @brief  Initializes the USB peripheral Clock according to the
  *         specified parameters.
  * @param  USB_Clock_InitStruct: pointer to a USB_Clock_TypeDef structure
  *         that contains the configuration information for the USB Clock.
  *
  * @retval None
  */

void USB_BRGInit(const USB_Clock_TypeDef* USB_Clock_InitStruct)
{
  uint32_t tmpreg;

  /* Check the parameters */
  assert_param(IS_USB_CLOCK(USB_Clock_InitStruct->USB_PLLUSBMUL, USB_Clock_InitStruct->USB_USBC1_Source));

  /* USB_CLOCK Configuration */
  tmpreg  = MDR_RST_CLK->USB_CLOCK;
  tmpreg |= RST_CLK_USB_CLOCK_USB_CLK_EN;
  tmpreg |= USB_Clock_InitStruct->USB_USBC1_Source;
  tmpreg |= USB_PLL;

  MDR_RST_CLK->USB_CLOCK = tmpreg;

  /* PLL_CONTROL Configuration */
  tmpreg  = MDR_RST_CLK->PLL_CONTROL;
  tmpreg |= RST_CLK_PLL_CONTROL_PLL_USB_ON;
  tmpreg |= (USB_Clock_InitStruct->USB_PLLUSBMUL << RST_CLK_PLL_CONTROL_PLL_USB_MUL_Pos);

  MDR_RST_CLK->PLL_CONTROL = tmpreg;
  while ((MDR_RST_CLK->CLOCK_STATUS & RST_CLK_CLOCK_STATUS_PLL_USB_RDY) != SET);
}

/**
  * @brief  Reset routine the USB periphery.
  * @param  None
  * @retval None
  */

void USB_Reset(void)
{
  uint32_t count;

  USB_SetHSCR(USB_HSCR_RESET_CORE_Reset);  /* Set RESET_CORE bit */
  for (count = 0; count < 1000; count++);  /* Hold Reset */
  USB_SetHSCR(USB_HSCR_RESET_CORE_Work);
}

/**
  * @brief  Returns USB_HSCR register value
  *
  * @param  None
  *
  * @retval USB_HSCR register value
  */

uint32_t USB_GetHSCR(void)
{
  return MDR_USB->HSCR;
}

/**
  * @brief  Writes to USB_HSCR register
  *
  * @param  RegValue: new USB_HSCR register value
  *
  * @retval None
  */

void USB_SetHSCR(uint32_t RegValue)
{
  /* Check the parameters */
  assert_param(IS_USB_HSCR_VALUE(RegValue));

  USB_SFR_SET(MDR_USB->HSCR, RegValue);
}

/**
  * @brief  Returns the USB controller version information.
  *
  * @param  None
  *
  * @retval USB_Version_TypeDef structure containing version
  *         and revision.
  */

USB_Version_TypeDef USB_GetHSVR(void)
{
  uint32_t tmpreg;
  USB_Version_TypeDef s;

  tmpreg = MDR_USB->HSVR;

  s.USB_Version  = tmpreg & USB_HSVR_VERSION_Msk;
  s.USB_Revision = (tmpreg & USB_HSVR_REVISION_Msk) >> USB_HSVR_REVISION_Pos;

  return s;
}

/**
  * @brief  Returns USB_HTXC register value
  *
  * @param  None
  *
  * @retval USB_HTXC register value
  */

uint32_t USB_GetHTXC(void)
{
  return MDR_USB->HTXC;
}

/**
  * @brief  Writes to USB_HTXC register
  *
  * @param  RegValue: new USB_HTXC register value
  *
  * @retval None
  */

void     USB_SetHTXC(uint32_t RegValue)
{
  /* Check the parameters */
  assert_param(IS_USB_HTXC_VALUE(RegValue));

  USB_SFR_SET(MDR_USB->HTXC, RegValue);
}

/**
  * @brief  Returns USB_HTXT register value
  *
  * @param  None
  *
  * @retval USB_HTXT register value
  */

uint32_t USB_GetHTXT(void)
{
  return MDR_USB->HTXT;
}

/**
  * @brief  Writes to USB_HTXT register
  *
  * @param  RegValue: new USB_HTXT register value
  *
  * @retval None
  */

void     USB_SetHTXT(uint32_t RegValue)
{
  /* Check the parameters */
  assert_param(IS_USB_HTXT_VALUE(RegValue));

  MDR_USB->HTXT = RegValue;
}

/**
  * @brief  Returns USB_HTXLC register value
  *
  * @param  None
  *
  * @retval USB_HTXLC register value
  */

uint32_t USB_GetHTXLC(void)
{
  return MDR_USB->HTXLC;
}

/**
  * @brief  Writes to USB_HTXLC register
  *
  * @param  RegValue: new USB_HTXLC register value
  *
  * @retval None
  */

void     USB_SetHTXLC(uint32_t RegValue)
{
  /* Check the parameters */
  assert_param(IS_USB_HTXLC_VALUE(RegValue));

  USB_SFR_SET(MDR_USB->HTXLC, RegValue);
}

/**
  * @brief  Returns USB_HTXSE register value
  *
  * @param  None
  *
  * @retval USB_HTXSE register value
  */

uint32_t USB_GetHTXSE(void)
{
  return MDR_USB->HTXSE;
}

/**
  * @brief  Writes to USB_HTXSE register
  *
  * @param  RegValue: new USB_HTXSE register value
  *
  * @retval None
  */

void     USB_SetHTXSE(uint32_t RegValue)
{
  /* Check the parameters */
  assert_param(IS_USB_HTXSE_VALUE(RegValue));

  USB_SFR_SET(MDR_USB->HTXSE, RegValue);
}

/**
  * @brief  Returns USB_HTXA register value
  *
  * @param  None
  *
  * @retval USB_HTXA register value
  */

uint32_t USB_GetHTXA(void)
{
  return MDR_USB->HTXA;
}

/**
  * @brief  Writes to USB_HTXA register
  *
  * @param  RegValue: new USB_HTXA register value
  *
  * @retval None
  */

void     USB_SetHTXA(uint32_t RegValue)
{
  /* Check the parameters */
  assert_param(IS_USB_HTXA_VALUE(RegValue));

  MDR_USB->HTXA = RegValue;
}

/**
  * @brief  Returns USB_HTXE register value
  *
  * @param  None
  *
  * @retval USB_HTXE register value
  */

uint32_t USB_GetHTXE(void)
{
  return MDR_USB->HTXE;
}

/**
  * @brief  Writes to USB_HTXE register
  *
  * @param  RegValue: new USB_HTXE register value
  *
  * @retval None
  */

void     USB_SetHTXE(uint32_t RegValue)
{
  /* Check the parameters */
  assert_param(IS_USB_HTXE_VALUE(RegValue));

  MDR_USB->HTXE = RegValue;
}

/**
  * @brief  Returns USB_HFN register value
  *
  * @param  None
  *
  * @retval USB_HFN register value
  */

uint32_t USB_GetHFN(void)
{
  return MDR_USB->HFN_H;
}

/**
  * @brief  Returns USB_HIS register value
  *
  * @param  None
  *
  * @retval USB_HIS register value
  */

uint32_t USB_GetHIS(void)
{
  return MDR_USB->HIS;
}

/**
  * @brief  Writes to USB_HIS register
  *
  * @param  RegValue: new USB_HIS register value
  *
  * @retval None
  */

void     USB_SetHIS(uint32_t RegValue)
{
  /* Check the parameters */
  assert_param(IS_USB_HIS_VALUE(RegValue));

  USB_SFR_SET(MDR_USB->HIS, RegValue);
}

/**
  * @brief  Returns USB_HIM register value
  *
  * @param  None
  *
  * @retval USB_HIM register value
  */

uint32_t USB_GetHIM(void)
{
  return MDR_USB->HIM;
}

/**
  * @brief  Writes to USB_HIM register
  *
  * @param  RegValue: new USB_HIM register value
  *
  * @retval None
  */

void     USB_SetHIM(uint32_t RegValue)
{
  /* Check the parameters */
  assert_param(IS_USB_HIM_VALUE(RegValue));

  USB_SFR_SET(MDR_USB->HIM, RegValue);
}

/**
  * @brief  Returns USB_HRXS register value
  *
  * @param  None
  *
  * @retval USB_HRXS register value
  */

uint32_t USB_GetHRXS(void)
{
  return MDR_USB->HRXS;
}

/**
  * @brief  Returns USB_HRXP register value
  *
  * @param  None
  *
  * @retval USB_HRXP register value
  */

uint32_t USB_GetHRXP(void)
{
  return MDR_USB->HRXP;
}

/**
  * @brief  Returns USB_HRXA register value
  *
  * @param  None
  *
  * @retval USB_HRXA register value
  */

uint32_t USB_GetHRXA(void)
{
  return MDR_USB->HRXA;
}

/**
  * @brief  Returns USB_HRXE register value
  *
  * @param  None
  *
  * @retval USB_HRXE register value
  */

uint32_t USB_GetHRXE(void)
{
  return MDR_USB->HRXE;
}

/**
  * @brief  Returns USB_HRXCS register value
  *
  * @param  None
  *
  * @retval USB_HRXCS register value
  */

uint32_t USB_GetHRXCS(void)
{
  return MDR_USB->HRXCS;
}

/**
  * @brief  Returns USB_HSTM register value
  *
  * @param  None
  *
  * @retval USB_HSTM register value
  */

uint32_t USB_GetHSTM(void)
{
  return MDR_USB->HSTM;
}

/**
  * @brief  Returns USB_HRXFD register value
  *
  * @param  None
  *
  * @retval USB_HRXFD register value
  */

uint32_t USB_GetHRXFD(void)
{
  return MDR_USB->HRXFD;
}

/**
  * @brief  Returns USB_HRXFDC register value
  *
  * @param  None
  *
  * @retval USB_HRXFDC register value
  */

uint32_t USB_GetHRXFDC(void)
{
  return MDR_USB->HRXFDC_H;
}

/**
  * @brief  Returns USB_HRXFC register value
  *
  * @param  None
  *
  * @retval USB_HRXFC register value
  */

uint32_t USB_GetHRXFC(void)
{
  return MDR_USB->HRXFC;
}

/**
  * @brief  Writes to USB_HRXFC register
  *
  * @param  RegValue: new USB_HRXFC register value
  *
  * @retval None
  */

void     USB_SetHRXFC(uint32_t RegValue)
{
  /* Check the parameters */
  assert_param(IS_USB_HRXFC_VALUE(RegValue));

  MDR_USB->HRXFC = RegValue;
}

/**
  * @brief  Returns USB_HTXFD register value
  *
  * @param  None
  *
  * @retval USB_HTXFD register value
  */

uint32_t USB_GetHTXFD(void)
{
  return MDR_USB->HTXFD;
}

/**
  * @brief  Writes to USB_HTXFD register
  *
  * @param  RegValue: new USB_HTXFD register value
  *
  * @retval None
  */

void     USB_SetHTXFD(uint32_t RegValue)
{
  /* Check the parameters */
  assert_param(IS_USB_HTXFD_VALUE(RegValue));

  MDR_USB->HTXFD = RegValue;
}

/**
  * @brief  Returns USB_HTXFC register value
  *
  * @param  None
  *
  * @retval USB_HTXFC register value
  */

uint32_t USB_GetHTXFC(void)
{
  return MDR_USB->HTXFC;
}

/**
  * @brief  Writes to USB_HTXFC register
  *
  * @param  RegValue: new USB_HTXFC register value
  *
  * @retval None
  */

void     USB_SetHTXFC(uint32_t RegValue)
{
  /* Check the parameters */
  assert_param(IS_USB_HTXFC_VALUE(RegValue));

  MDR_USB->HTXFC = RegValue;
}

/**
  * @brief  Returns USB_SEPx.CTRL register value
  *
  * @param  EndPointNumber: Select the USB End point peripheral.
  *         This parameter can be one of the following values:
  *         USB_EP0, USB_EP1, USB_EP2, USB_EP3.
  *
  * @retval USB_SEPx.CTRL register value
  */

uint32_t USB_GetSEPxCTRL(USB_EP_TypeDef EndPointNumber)
{
  /* Check the parameters */
  assert_param(IS_USB_ENDPOINT(EndPointNumber));

  return MDR_USB->USB_SEP[EndPointNumber].CTRL;
}

/**
  * @brief  Writes to USB_SEPx.CTRL register
  *
  * @param  EndPointNumber: Select the USB End point peripheral.
  *         This parameter can be one of the following values:
  *         USB_EP0, USB_EP1, USB_EP2, USB_EP3.
  *
  * @param  RegValue: new USB_SEPx.CTRL register value
  *
  * @retval None
  */

void     USB_SetSEPxCTRL(USB_EP_TypeDef EndPointNumber, uint32_t RegValue)
{
  /* Check the parameters */
  assert_param(IS_USB_ENDPOINT(EndPointNumber));
  assert_param(IS_USB_SEPx_CTRL_VALUE(RegValue));

  USB_SFR_SET(MDR_USB->USB_SEP[EndPointNumber].CTRL, RegValue);
}

/**
  * @brief  Returns USB_SEPx.STS register value
  *
  * @param  EndPointNumber: Select the USB End point peripheral.
  *         This parameter can be one of the following values:
  *         USB_EP0, USB_EP1, USB_EP2, USB_EP3.
  *
  * @retval USB_SEPx.STS register value
  */

uint32_t USB_GetSEPxSTS(USB_EP_TypeDef EndPointNumber)
{
  /* Check the parameters */
  assert_param(IS_USB_ENDPOINT(EndPointNumber));

  return MDR_USB->USB_SEP[EndPointNumber].STS;
}

/**
  * @brief  Returns USB_SEPx.TS register value
  *
  * @param  EndPointNumber: Select the USB End point peripheral.
  *         This parameter can be one of the following values:
  *         USB_EP0, USB_EP1, USB_EP2, USB_EP3.
  *
  * @retval USB_SEPx.TS register value
  */

uint32_t USB_GetSEPxTS(USB_EP_TypeDef EndPointNumber)
{
  /* Check the parameters */
  assert_param(IS_USB_ENDPOINT(EndPointNumber));

  return MDR_USB->USB_SEP[EndPointNumber].TS;
}

/**
  * @brief  Returns USB_SEPx.NTS register value
  *
  * @param  EndPointNumber: Select the USB End point peripheral.
  *         This parameter can be one of the following values:
  *         USB_EP0, USB_EP1, USB_EP2, USB_EP3.
  *
  * @retval USB_SEPx.NTS register value
  */

uint32_t USB_GetSEPxNTS(USB_EP_TypeDef EndPointNumber)
{
  /* Check the parameters */
  assert_param(IS_USB_ENDPOINT(EndPointNumber));

  return MDR_USB->USB_SEP[EndPointNumber].NTS;
}

/**
  * @brief  Returns USB_SC register value
  *
  * @param  None
  *
  * @retval USB_SC register value
  */

uint32_t USB_GetSC(void)
{
  return MDR_USB->SC;
}

/**
  * @brief  Writes to USB_SC register
  *
  * @param  RegValue: new USB_SC register value
  *
  * @retval None
  */

void     USB_SetSC(uint32_t RegValue)
{
  /* Check the parameters */
  assert_param(IS_USB_SC_VALUE(RegValue));

  USB_SFR_SET(MDR_USB->SC, RegValue);
}

/**
  * @brief  Returns USB_SLS register value
  *
  * @param  None
  *
  * @retval USB_SLS register value
  */

uint32_t USB_GetSLS(void)
{
  return MDR_USB->SLS;
}

/**
  * @brief  Returns USB_SIS register value
  *
  * @param  None
  *
  * @retval USB_SIS register value
  */

uint32_t USB_GetSIS(void)
{
  return MDR_USB->SIS;
}

/**
  * @brief  Writes to USB_SIS register
  *
  * @param  RegValue: new USB_SIS register value
  *
  * @retval None
  */

void     USB_SetSIS(uint32_t RegValue)
{
  /* Check the parameters */
  assert_param(IS_USB_SIS_VALUE(RegValue));

  /* USB_SIS bits may be only cleared by writing 1 */
  MDR_USB->SIS = RegValue;
}

/**
  * @brief  Returns USB_SIM register value
  *
  * @param  None
  *
  * @retval USB_SIM register value
  */

uint32_t USB_GetSIM(void)
{
  return MDR_USB->SIM;
}

/**
  * @brief  Writes to USB_SIM register
  *
  * @param  RegValue: new USB_SIM register value
  *
  * @retval None
  */

void     USB_SetSIM(uint32_t RegValue)
{
  /* Check the parameters */
  assert_param(IS_USB_SIM_VALUE(RegValue));

  USB_SFR_SET(MDR_USB->SIM, RegValue);
}

/**
  * @brief  Returns USB_SA register value
  *
  * @param  None
  *
  * @retval USB_SA register value
  */

uint32_t USB_GetSA(void)
{
  return MDR_USB->SA;
}

/**
  * @brief  Writes to USB_SA register
  *
  * @param  RegValue: new USB_SA register value
  *
  * @retval None
  */

void     USB_SetSA(uint32_t RegValue)
{
  /* Check the parameters */
  assert_param(IS_USB_SA_VALUE(RegValue));

  MDR_USB->SA = RegValue;
}

/**
  * @brief  Returns USB_SFN register value
  *
  * @param  None
  *
  * @retval USB_SFN register value
  */

uint32_t USB_GetSFN(void)
{
  return MDR_USB->SFN_H;
}

/**
  * @brief  Returns USB_SEPx.RXFD register value
  *
  * @param  EndPointNumber: Select the USB End point peripheral.
  *         This parameter can be one of the following values:
  *         USB_EP0, USB_EP1, USB_EP2, USB_EP3.
  *
  * @retval USB_SEPx.RXFD register value
  */

uint32_t USB_GetSEPxRXFD(USB_EP_TypeDef EndPointNumber)
{
  /* Check the parameters */
  assert_param(IS_USB_ENDPOINT(EndPointNumber));

  return MDR_USB->USB_SEP_FIFO[EndPointNumber].RXFD;
}

/**
  * @brief  Returns USB_SEPx.RXFDC register value
  *
  * @param  EndPointNumber: Select the USB End point peripheral.
  *         This parameter can be one of the following values:
  *         USB_EP0, USB_EP1, USB_EP2, USB_EP3.
  *
  * @retval USB_SEPx.RXFDC register value
  */

uint32_t USB_GetSEPxRXFDC(USB_EP_TypeDef EndPointNumber)
{
  /* Check the parameters */
  assert_param(IS_USB_ENDPOINT(EndPointNumber));

  return MDR_USB->USB_SEP_FIFO[EndPointNumber].RXFDC_H;
}

/**
  * @brief  Returns USB_SEPx.RXFC register value
  *
  * @param  EndPointNumber: Select the USB End point peripheral.
  *         This parameter can be one of the following values:
  *         USB_EP0, USB_EP1, USB_EP2, USB_EP3.
  *
  * @retval USB_SEPx.RXFC register value
  */

uint32_t USB_GetSEPxRXFC(USB_EP_TypeDef EndPointNumber)
{
  /* Check the parameters */
  assert_param(IS_USB_ENDPOINT(EndPointNumber));

  return MDR_USB->USB_SEP_FIFO[EndPointNumber].RXFC;
}

/**
  * @brief  Writes to USB_SEPx.RXFC register
  *
  * @param  EndPointNumber: Select the USB End point peripheral.
  *         This parameter can be one of the following values:
  *         USB_EP0, USB_EP1, USB_EP2, USB_EP3.
  *
  * @param  RegValue: new USB_SEPx.RXFC register value
  *
  * @retval None
  */

void     USB_SetSEPxRXFC(USB_EP_TypeDef EndPointNumber, uint32_t RegValue)
{
  /* Check the parameters */
  assert_param(IS_USB_ENDPOINT(EndPointNumber));
  assert_param(IS_USB_SEPx_RXFC_VALUE(RegValue));

  MDR_USB->USB_SEP_FIFO[EndPointNumber].RXFC = RegValue;
}

/**
  * @brief  Returns USB_SEPx.TXFD register value
  *
  * @param  EndPointNumber: Select the USB End point peripheral.
  *         This parameter can be one of the following values:
  *         USB_EP0, USB_EP1, USB_EP2, USB_EP3.
  *
  * @retval USB_SEPx.TXFD register value
  */

uint32_t USB_GetSEPxTXFD(USB_EP_TypeDef EndPointNumber)
{
  /* Check the parameters */
  assert_param(IS_USB_ENDPOINT(EndPointNumber));

  return MDR_USB->USB_SEP_FIFO[EndPointNumber].TXFD;
}

/**
  * @brief  Writes to USB_SEPx.TXFD register
  *
  * @param  EndPointNumber: Select the USB End point peripheral.
  *         This parameter can be one of the following values:
  *         USB_EP0, USB_EP1, USB_EP2, USB_EP3.
  *
  * @param  RegValue: new USB_SEPx.TXFD register value
  *
  * @retval None
  */

void     USB_SetSEPxTXFD(USB_EP_TypeDef EndPointNumber, uint32_t RegValue)
{
  /* Check the parameters */
  assert_param(IS_USB_ENDPOINT(EndPointNumber));
  assert_param(IS_USB_SEPx_TXFD_VALUE(RegValue));

  MDR_USB->USB_SEP_FIFO[EndPointNumber].TXFD = RegValue;
}

/**
  * @brief  Returns USB_SEPx.TXFDC register value
  *
  * @param  EndPointNumber: Select the USB End point peripheral.
  *         This parameter can be one of the following values:
  *         USB_EP0, USB_EP1, USB_EP2, USB_EP3.
  *
  * @retval USB_SEPx.TXFC register value
  */

uint32_t USB_GetSEPxTXFDC(USB_EP_TypeDef EndPointNumber)
{
  /* Check the parameters */
  assert_param(IS_USB_ENDPOINT(EndPointNumber));

  return MDR_USB->USB_SEP_FIFO[EndPointNumber].TXFDC;
}

/**
  * @brief  Writes to USB_SEPx.TXFDC register
  *
  * @param  EndPointNumber: Select the USB End point peripheral.
  *         This parameter can be one of the following values:
  *         USB_EP0, USB_EP1, USB_EP2, USB_EP3.
  *
  * @param  RegValue: new USB_SEPx.TXFDC register value
  *
  * @retval None
  */

void     USB_SetSEPxTXFDC(USB_EP_TypeDef EndPointNumber, uint32_t RegValue)
{
  /* Check the parameters */
  assert_param(IS_USB_ENDPOINT(EndPointNumber));
  assert_param(IS_USB_SEPx_TXFDC_VALUE(RegValue));

  MDR_USB->USB_SEP_FIFO[EndPointNumber].TXFDC = RegValue;
}

/**
  * @brief  Invert EPDATASEQ bit in USB_SEPx.CTRL register
  *
  * @param  EndPointNumber: Select the USB End point peripheral.
  *         This parameter can be one of the following values:
  *         USB_EP0, USB_EP1, USB_EP2, USB_EP3.
  *
  * @retval None
  */

void     USB_SEPxToggleEPDATASEQ(USB_EP_TypeDef EndPointNumber)
{
  uint32_t tmpreg;

  /* Check the parameters */
  assert_param(IS_USB_ENDPOINT(EndPointNumber));

  tmpreg = MDR_USB->USB_SEP[EndPointNumber].CTRL;
  tmpreg = tmpreg ^ USB_SEPx_CTRL_EPDATASEQ_Data1;
  MDR_USB->USB_SEP[EndPointNumber].CTRL = tmpreg;
}

/** @} */ /* End of group USB_Private_Functions */

/** @} */ /* End of group USB */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

/*
*
* END OF FILE MDR32F9Qx_usb.c */

