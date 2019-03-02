/**
  * FILE MDR32F9Qx_usb_handlers.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MDR32F9Qx_USB_HANDLERS_H
#define __MDR32F9Qx_USB_HANDLERS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_usb_default_handlers.h"

/** @addtogroup __MDR32F9Qx_StdPeriph_Examples MDR32F9Qx StdPeriph Examples
  * @{
  */

/** @addtogroup __MDR32F9Q1_EVAL MDR32F9Q1 Evaluation Board
  * @{
  */

/** @addtogroup  USB_Virtual_COM_Port_Echo_91 USB Virtual COM Port Echo
  * @{
  */

/* Configuration file MDR32F9Qx_config.h should be included before */
#ifndef __MDR32F9Qx_CONFIG_H
#error "Configuration file MDR32F9Qx_config.h should be included before"
#endif



/** @defgroup USB_Virtual_COM_Port_Echo_Handlers USB Virtual COM Port Echo Handlers
  * @{
  */

#undef USB_CDC_HANDLE_DATA_RECEIVE
#define USB_CDC_HANDLE_DATA_RECEIVE(BUFFER, LENGTH)   USB_CDC_RecieveData(BUFFER, LENGTH)

#ifdef USB_VCOM_SYNC
#undef USB_CDC_HANDLE_DATA_SENT
#define USB_CDC_HANDLE_DATA_SENT                                USB_CDC_DataSent();
#endif /* USB_VCOM_SYNC */

#ifdef USB_CDC_LINE_CODING_SUPPORTED
#undef USB_CDC_HANDLE_GET_LINE_CODING
#define USB_CDC_HANDLE_GET_LINE_CODING(wINDEX, DATA)  USB_CDC_GetLineCoding(wINDEX, DATA)
#undef USB_CDC_HANDLE_SET_LINE_CODING
#define USB_CDC_HANDLE_SET_LINE_CODING(wINDEX, DATA)  USB_CDC_SetLineCoding(wINDEX, DATA)
#endif /* USB_CDC_LINE_CODING_SUPPORTED */

#ifdef USB_CDC_CONTROL_LINE_STATE_SUPPORTED
#undef USB_CDC_HANDLE_CONTROL_LINE_STATE
#define USB_CDC_HANDLE_CONTROL_LINE_STATE(wVALUE, wINDEX)       USB_SUCCESS
#endif /* USB_CDC_CONTROL_LINE_STATE_SUPPORTED */


#ifdef USB_DEBUG_PROTO
#undef USB_DEVICE_HANDLE_SETUP
#define USB_DEVICE_HANDLE_SETUP   USB_DeviceSetupPacket_Debug
#endif /* USB_DEBUG_PROTO */

/** @} */ /* End of group USB_Virtual_COM_Port_Echo_Handlers */


/** @defgroup USB_Virtual_COM_Port_Echo_Handler_Functions USB Virtual COM Port Echo Handler Functions
  * @{
  */

USB_Result USB_CDC_RecieveData(uint8_t* Buffer, uint32_t Length);

#ifdef USB_CDC_LINE_CODING_SUPPORTED
USB_Result USB_CDC_GetLineCoding(uint16_t wINDEX, USB_CDC_LineCoding_TypeDef* DATA);
USB_Result USB_CDC_SetLineCoding(uint16_t wINDEX, const USB_CDC_LineCoding_TypeDef* DATA);
#endif /* USB_CDC_LINE_CODING_SUPPORTED */

#ifdef USB_VCOM_SYNC
USB_Result USB_CDC_DataSent(void);
#endif /* USB_VCOM_SYNC */

#ifdef USB_DEBUG_PROTO
USB_Result USB_DeviceSetupPacket_Debug(USB_EP_TypeDef EPx, const USB_SetupPacket_TypeDef* USB_SetupPacket);
#endif /* USB_DEBUG_PROTO */

/** @} */ /* End of group USB_Virtual_COM_Port_Echo_Handler_Functions */

/** @} */ /* End of group USB_Virtual_COM_Port_Echo_91 */

/** @} */ /* End of group __MDR32F9Q1_EVAL */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Examples */

#ifdef __cplusplus
} // extern "C" block end
#endif

#endif /* __MDR32F9Qx_USB_HANDLERS_H */

/*
*
* END OF FILE MDR32F9Qx_usb_handlers.h */
