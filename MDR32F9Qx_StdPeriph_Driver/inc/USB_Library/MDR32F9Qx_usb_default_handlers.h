/**
  ******************************************************************************
  * @file    USB_Library\MDR32F9Qx_usb_default_handlers.h
  * @author  Phyton Application Team
  * @version V1.4.0
  * @date    18/03/2011
  * @brief   USB Library handlers definition file.
  ******************************************************************************
  * <br><br>
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, PHYTON SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2010 Phyton</center></h2>
  * FILE MDR32F9Qx_usb_default_handlers.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MDR32F9Qx_USB_DEFAULT_HANDLERS_H
#define __MDR32F9Qx_USB_DEFAULT_HANDLERS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_usb_CDC.h"

/* Configuration file MDR32F9Qx_config.h should be included before */
#ifndef __MDR32F9Qx_CONFIG_H
#error "Configuration file MDR32F9Qx_config.h should be included before"
#endif

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @addtogroup USB_DEVICE_AND_CDC USB DEVICE AND CDC
  * @{
  */

/** @defgroup USB_Configuring USB Configuring
  * @{
  */

/** @defgroup USB_Device_Configuring USB Device Configuring
  * @{
  */

/**
  * @brief Bus reset handler
  */

#define USB_DEVICE_HANDLE_RESET  USB_DeviceReset()

/**
  * @brief Device enter suspended mode handler
  */

#define USB_DEVICE_HANDLE_SUSPEND  USB_DeviceSuspend()

/**
  * @brief Device exit from suspended mode handler
  */

#define USB_DEVICE_HANDLE_RESUME  USB_DeviceResume()

/**
  * @brief Control Setup Packet general processing handle
  */

#define USB_DEVICE_HANDLE_SETUP   USB_DeviceSetupPacket

/**
  * @brief GET_STATUS standard request handler
  */

#define USB_DEVICE_HANDLE_GET_STATUS(Recipient, wINDEX)    USB_SUCCESS
/* To redefine handler for your own function choose the variant below using
 * USB_DeviceDummyGetStatus as an example and replacing it with your own function
#define USB_DEVICE_HANDLE_GET_STATUS(Recipient, wINDEX)    USB_DeviceDummyGetStatus(Recipient, wINDEX)
 */

/**
  * @brief CLEAR_FEATURE standard request handler
  */

#define USB_DEVICE_HANDLE_CLEAR_FEATURE(Recipient, wVALUE, wINDEX) \
        USB_DeviceClearFeature(Recipient, wVALUE, wINDEX)

/**
  * @brief SET_FEATURE standard request handler
  */

#define USB_DEVICE_HANDLE_SET_FEATURE(Recipient, wVALUE, wINDEX)  \
        USB_DeviceSetFeature(Recipient, wVALUE, wINDEX)

/**
  * @brief SET_ADDRESS standard request handler (preparation phase)
  */

#define USB_DEVICE_HANDLE_SET_ADDRESS(wVALUE)  USB_SUCCESS
/* To redefine handler for your own function choose the variant below using
 * USB_DeviceDummySetAddress as an example and replacing it with your own function
#define USB_DEVICE_HANDLE_SET_ADDRESS(wVALUE)  USB_DeviceDummySetAddress(wVALUE)
 */

/**
  * @brief GET_DESCRIPTOR standard request handler
  */

#define USB_DEVICE_HANDLE_GET_DESCRIPTOR(wVALUE, wINDEX, wLENGTH)  USB_ERROR
/* To redefine handler for your own function choose the variant below using
 * USB_DeviceDummyGetDescriptor as an example and replacing it with your own function
#define USB_DEVICE_HANDLE_GET_DESCRIPTOR(wVALUE, wINDEX, wLENGTH)  USB_DeviceDummyGetDescriptor(wVALUE, wINDEX, wLENGTH)
 */

/**
  * @brief SET_DESCRIPTOR standard request handler
  */

#define USB_DEVICE_HANDLE_SET_DESCRIPTOR(wVALUE, wINDEX, wLENGTH)  USB_ERROR
/* To redefine handler for your own function choose the variant below using
 * USB_DeviceDummySetDescriptor as an example and replacing it with your own function
#define USB_DEVICE_HANDLE_SET_DESCRIPTOR(wVALUE, wINDEX, wLENGTH)  USB_DeviceDummySetDescriptor(wVALUE, wINDEX, wLENGTH)
 */

/**
  * @brief GET_CONFIGURATION standard request handler
  */

#define USB_DEVICE_HANDLE_GET_CONFIGURATION  1
/* To redefine handler for your own function choose the variant below using
 * USB_DeviceDummyGetConfiguration as an example and replacing it with your own function
#define USB_DEVICE_HANDLE_GET_CONFIGURATION  USB_DeviceDummyGetConfiguration()
 */

/**
  * @brief SET_CONFIGURATION standard request handler
  */

#define USB_DEVICE_HANDLE_SET_CONFIGURATION(wVALUE)  \
        ((wVALUE) == 1 ? USB_SUCCESS : USB_ERROR)
/* To redefine handler for your own function choose the variant below using
 * USB_DeviceDummySetConfiguration as an example and replacing it with your own function
#define USB_DEVICE_HANDLE_SET_CONFIGURATION(wVALUE)  USB_DeviceDummySetConfiguration(wVALUE)
 */

/**
  * @brief GET_INTERFACE standard request handler
  */

#define USB_DEVICE_HANDLE_GET_INTERFACE(wINDEX)  0
/* To redefine handler for your own function choose the variant below using
 * USB_DeviceDummyGetInterface as an example and replacing it with your own function
#define USB_DEVICE_HANDLE_GET_INTERFACE(wINDEX)  USB_DeviceDummyGetInterface(wINDEX)
 */

/**
  * @brief SET_INTERFACE standard request handler
  */

#define USB_DEVICE_HANDLE_SET_INTERFACE(wVALUE, wINDEX) \
        ((wINDEX) == 0 && (wVALUE) == 0 ? USB_SUCCESS : USB_ERROR)
/* To redefine handler for your own function choose the variant below using
 * USB_DeviceDummySetInterface as an example and replacing it with your own function
#define USB_DEVICE_HANDLE_SET_INTERFACE(wVALUE, wINDEX)  USB_DeviceDummySetInterface(wVALUE, wINDEX)
 */

/**
  * @brief SYNC_FRAME standard request handler
  */

#define USB_DEVICE_HANDLE_SYNC_FRAME(wINDEX, DATA)  USB_ERROR
/* To redefine handler for your own function choose the variant below using
 * USB_DeviceDummySyncFrame as an example and replacing it with your own function
#define USB_DEVICE_HANDLE_SYNC_FRAME(wINDEX, DATA)  USB_DeviceDummySyncFrame(wINDEX, DATA)
 */

/**
  * @brief Class-type request handler
  */

#define USB_DEVICE_HANDLE_CLASS_REQUEST  USB_ERROR
/* To redefine handler for your own function choose the variant below using
 * USB_DeviceDummyClassRequest as an example and replacing it with your own function
#define USB_DEVICE_HANDLE_CLASS_REQUEST  USB_DeviceDummyClassRequest()
 */

/**
  * @brief Vendor-type request handler
  */

#define USB_DEVICE_HANDLE_VENDOR_REQUEST  USB_ERROR
/* To redefine handler for your own function choose the variant below using
 * USB_DeviceDummyVendorRequest as an example and replacing it with your own function
#define USB_DEVICE_HANDLE_VENDOR_REQUEST  USB_DeviceDummyVendorRequest()
 */

/** @} */ /* End of group USB_Device_Configuring */

/** @defgroup USB_CDC_Configuring USB CDC Configuring
  * @{
  */

#if (USB_DEVICE_CLASS == USB_DEVICE_CLASS_CDC)
/** @defgroup USB_CDC_Handlers USB CDC Handlers
  * @{
  */

/** @defgroup USB_CDC_Exported_Handlers USB CDC Handler Definitions and defaults
  * @{
  */

/**
  * @brief Data receive request handler
  */

#define USB_CDC_HANDLE_DATA_RECEIVE(BUFFER, LENGTH)             USB_ERROR
/* To redefine handler for your own function choose the variant below using
 * USB_CDC_DummyDataReceive as an example and replacing it with your own function
#define USB_CDC_HANDLE_DATA_RECEIVE(BUFFER, LENGTH)    USB_CDC_DummyDataReceive(BUFFER, LENGTH)
 */

/**
  * @brief Data sent completion handler
  */

#define USB_CDC_HANDLE_DATA_SENT                                USB_SUCCESS
/* To redefine handler for your own function choose the variant below using
 * USB_CDC_DummyDataSent as an example and replacing it with your own function
#define USB_CDC_HANDLE_DATA_SENT                  USB_CDC_DummyDataSent()
 */

/**
  * @brief Data send error handler
  */

#define USB_CDC_HANDLE_SEND_ERROR                               0
/* To redefine handler for your own function choose the variant below using
 * USB_DeviceDummyDataError as an example and replacing it with your own function
#define USB_CDC_HANDLE_SEND_ERROR                 USB_DeviceDummyDataError
 */


#ifdef USB_CDC_ENCAPSULATION_SUPPORTED
/**
  * @brief SEND_ENCAPSULATED_COMMAND Class-specific request handler
  */

#define USB_CDC_HANDLE_SEND_ENCAPSULATED_CMD(wINDEX, wLENGTH)   USB_ERROR
/* To redefine handler for your own function choose the variant below using
 * USB_CDC_DummySendEncapsulatedCMD as an example and replacing it with your own function
#define USB_CDC_HANDLE_SEND_ENCAPSULATED_CMD(wINDEX, wLENGTH)    USB_CDC_DummySendEncapsulatedCMD(wINDEX, wLENGTH)
 */

/**
  * @brief GET_ENCAPSULATED_RESPONSE Class-specific request handler
  */

#define USB_CDC_HANDLE_GET_ENCAPSULATED_RESP(wINDEX, wLENGTH)   USB_ERROR
/* To redefine handler for your own function choose the variant below using
 * USB_CDC_DummyGetEncapsulatedResp as an example and replacing it with your own function
#define USB_CDC_HANDLE_GET_ENCAPSULATED_RESP(wINDEX, wLENGTH)    USB_CDC_DummyGetEncapsulatedResp(wINDEX, wLENGTH)
 */

#endif /* USB_CDC_ENCAPSULATION_SUPPORTED */

#ifdef USB_CDC_COMM_FEATURE_SUPPORTED

/**
  * @brief GET_COMM_FEATURE Class-specific request handle
  */

#define USB_CDC_HANDLE_GET_COMM_FEATURE(wVALUE, wINDEX, DATA)   USB_ERROR
/* To redefine handler for your own function choose the variant below using
 * USB_CDC_DummyGetCommFeature as an example and replacing it with your own function
#define USB_CDC_HANDLE_GET_COMM_FEATURE(wVALUE, wINDEX, DATA)    USB_CDC_DummyGetCommFeature(wVALUE, wINDEX, DATA)
 */

/**
  * @brief  SET_COMM_FEATURE Class-specific request handle
  */

#define USB_CDC_HANDLE_SET_COMM_FEATURE(wVALUE, wINDEX, DATA)   USB_ERROR
/* To redefine handler for your own function choose the variant below using
 * USB_CDC_DummySetCommFeature as an example and replacing it with your own function
#define USB_CDC_HANDLE_SET_COMM_FEATURE(wVALUE, wINDEX, DATA)    USB_CDC_DummySetCommFeature(wVALUE, wINDEX, DATA)
 */

/**
  * @brief  CLEAR_COMM_FEATURE Class-specific request handle
  */

#define USB_CDC_HANDLE_CLEAR_COMM_FEATURE(wVALUE, wINDEX)       USB_ERROR
/* To redefine handler for your own function choose the variant below using
 * USB_CDC_DummyClearCommFeature as an example and replacing it with your own function
#define USB_CDC_HANDLE_CLEAR_COMM_FEATURE(wVALUE, wINDEX)    USB_CDC_DummyClearCommFeature(wVALUE, wINDEX)
 */

#endif /* USB_CDC_COMM_FEATURE_SUPPORTED */

#ifdef USB_CDC_LINE_CODING_SUPPORTED
/**
  * @brief  GET_LINE_CODING Class-specific request handle
  */

#define USB_CDC_HANDLE_GET_LINE_CODING(wINDEX, DATA)            USB_ERROR
/* To redefine handler for your own function choose the variant below using
 * USB_CDC_DummyGetLineCoding as an example and replacing it with your own function
#define USB_CDC_HANDLE_GET_LINE_CODING(wINDEX, DATA)    USB_CDC_DummyGetLineCoding(wINDEX, DATA)
 */

/**
  * @brief  SET_LINE_CODING Class-specific request handle
  */

#define USB_CDC_HANDLE_SET_LINE_CODING(wINDEX, DATA)            USB_ERROR
/* To redefine handler for your own function choose the variant below using
 * USB_CDC_DummySetLineCoding as an example and replacing it with your own function
#define USB_CDC_HANDLE_SET_LINE_CODING(wINDEX, DATA)    USB_CDC_DummySetLineCoding(wINDEX, DATA)
 */

#endif /* USB_CDC_LINE_CODING_SUPPORTED */

#ifdef USB_CDC_CONTROL_LINE_STATE_SUPPORTED
/**
  * @brief SET_CONTROL_LINE_STATE Class-specific request handle
  */

#define USB_CDC_HANDLE_CONTROL_LINE_STATE(wVALUE, wINDEX)       USB_ERROR
/* To redefine handler for your own function choose the variant below using
 * USB_CDC_DummyControlLineState as an example and replacing it with your own function
#define USB_CDC_HANDLE_SET_CONTROL_LINE_STATE(wVALUE, wINDEX)    USB_CDC_DummyControlLineState(wVALUE, wINDEX)
 */

#endif /* USB_CDC_CONTROL_LINE_STATE_SUPPORTED */

#ifdef USB_CDC_LINE_BREAK_SUPPORTED
/**
  * @brief  SEND_BREAK Class-specific request handle
  */

#define USB_CDC_HANDLE_BREAK(wVALUE, wINDEX)                    USB_ERROR
/* To redefine handler for your own function choose the variant below using
 * USB_CDC_DummySendBreak as an example and replacing it with your own function
#define USB_CDC_HANDLE_BREAK(wVALUE, wINDEX)    USB_CDC_DummySendBreak(wVALUE, wINDEX)
 */

#endif /* USB_CDC_LINE_BREAK_SUPPORTED */

/**
  * @brief Line state report send error handler
  */

#define USB_CDC_HANDLE_LINE_STATE_REPORT_SEND_ERROR             0
/* To redefine handler for your own function choose the variant below using
 * USB_DeviceDummyDataError as an example and replacing it with your own function
#define USB_CDC_HANDLE_LINE_STATE_REPORT_SEND_ERROR   USB_DeviceDummyDataError
 */

/** @} */ /* End of group USB_CDC_Exported_Handlers */

/** @} */ /* End of group USB_CDC_Handlers */

/** @defgroup USB_CDC_Used_Device_Handlers USB CDC Used Device Handlers
  * @{
  */

#undef  USB_DEVICE_HANDLE_RESET
#define USB_DEVICE_HANDLE_RESET                                   USB_CDC_Reset()

#undef  USB_DEVICE_HANDLE_CLASS_REQUEST
#define USB_DEVICE_HANDLE_CLASS_REQUEST                           USB_CDC_ClassRequest()

#undef  USB_DEVICE_HANDLE_GET_DESCRIPTOR
#define USB_DEVICE_HANDLE_GET_DESCRIPTOR(wVALUE, wINDEX, wLENGTH) \
                   USB_CDC_GetDescriptor(wVALUE, wINDEX, wLENGTH)

/** @} */ /* End of group USB_CDC_Used_Device_Handlers */

#endif /* USB_DEVICE_CLASS == USB_DEVICE_CLASS_CDC */

/** @} */ /* End of group USB_CDC_Configuring */

/** @} */ /* End of group USB_Configuring */

/** @} */ /* End of group USB_DEVICE_AND_CDC */

/** @} */ /* End of group MDR32F9Qx_StdPeriph_Driver */

#ifdef __cplusplus
} // extern "C" block end
#endif

#endif /* __MDR32F9Qx_USB_DEFAULT_HANDLERS_H */

/******************* (C) COPYRIGHT 2010 Phyton *********************************
*
* END OF FILE MDR32F9Qx_usb_default_handlers.h */
