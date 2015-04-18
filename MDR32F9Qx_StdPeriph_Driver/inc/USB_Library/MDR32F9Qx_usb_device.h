/**
  ******************************************************************************
  * @file    USB_Library\MDR32F9Qx_usb_device.h
  * @author  Phyton Application Team
  * @version V1.4.0
  * @date    21/02/2011
  * @brief   This file contains all the interface types and function prototypes
  *          of the EndPoint and Device drivers as of USB Specification Rev.2.0
  *          Chapter 9
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
  * <h2><center>&copy; COPYRIGHT 2011 Phyton</center></h2>
  ******************************************************************************
  * FILE MDR32F9Qx_usb_device.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MDR32F9Qx_USB_DEVICE_H
#define __MDR32F9Qx_USB_DEVICE_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_config.h"

#ifdef MDR1986VE9x
/* Includes ------------------------------------------------------------------*/
	#include "MDR32Fx.h"
#endif

#ifdef MDR1986VE3
	#include "MDR1986VE3.h"
#endif

#include "MDR32F9Qx_lib.h"
#include "MDR32F9Qx_usb.h"
#include "MDR32F9Qx_config.h"

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @addtogroup USB_DEVICE_AND_CDC USB DEVICE AND CDC
  * @{
  */

/** @defgroup USB_Device_Framework_Exported_Types USB Device Framework Exported Types
  * @{
  */

/**
  * @brief Request Type Data Transfer Direction enumeration
  */

typedef enum
{
  USB_HOST_TO_DEVICE  = 0x0,
  USB_DEVICE_TO_HOST  = 0x80
}USB_RequestTypeDT_TypeDef;

/**
  * @brief Request Type enumeration
  */

typedef enum
{
  USB_TYPE_STANDARD  = 0x0,
  USB_TYPE_CLASS     = 0x20,
  USB_TYPE_VENDOR    = 0x40
}USB_RequestType_TypeDef;

#define USB_REQUEST_DT_Msk                    0x80
#define USB_REQUEST_TYPE_Msk                  0x60

/**
  * @brief Standard Setup Request Type enumeration
  */

typedef enum
{
  USB_GET_STATUS = 0,
  USB_CLEAR_FEATURE,
  USB_Reserved0,
  USB_SET_FEATURE,
  USB_Reserved1,
  USB_SET_ADDRESS,
  USB_GET_DESCRIPTOR,
  USB_SET_DESCRIPTOR,
  USB_GET_CONFIGURATION,
  USB_SET_CONFIGURATION,
  USB_GET_INTERFACE,
  USB_SET_INTERFACE,
  USB_SYNCH_FRAME
} USB_Standard_Setup_TypeDef;

/**
  * @brief Standard Descriptor Type enumeration
  */

typedef enum
{
  USB_DEVICE = 1,
  USB_CONFIGURATION,
  USB_STRING,
  USB_INTERFACE,
  USB_ENDPOINT,
  USB_DEVICE_QUALIFIER,
  USB_OTHER_SPEED_CONFIGURATION,
  USB_INTERFACE_POWER
} USB_Standard_Descriptor_TypeDef;

/**
  * @brief Standard Feature Selector Type enumeration
  */

typedef enum
{
  USB_ENDPOINT_HALT = 0,
  USB_DEVICE_REMOTE_WAKEUP,
  USB_TEST_MODE
} USB_Standard_Festure_Selector_TypeDef;

/**
  * @brief Request Recipient enumeration
  */

typedef enum
{
  USB_RECIPIENT_DEVICE    = 0x0,
  USB_RECIPIENT_INTERFACE = 0x1,
  USB_RECIPIENT_ENDPOINT  = 0x2,
  USB_RECIPIENT_OTHER     = 0x3
}USB_RequestRecipient_TypeDef;

#define USB_RECIPIENT_TYPE_Msk                0x1F
#define IS_VALID_USB_RECIPIENT(RECIPIENT)     ((RECIPIENT) <= USB_RECIPIENT_OTHER)

/**
  * @brief Setup Packet Structure (9.3) definition
  */

typedef struct
{
  uint8_t  mRequestTypeData;             /*!< Characteristics of request:
                                              D7:    Data transfer direction (USB_RequestTypeDT_TypeDef),
                                              D6..5: Type (USB_RequestType_TypeDef),
                                              D4..0: Recipient (USB_RequestRecipient_TypeDef). */
  uint8_t  bRequest;                     /*!< Specific request. */
  uint16_t wValue;                       /*!< Request value 1st word (wValue). */
  uint16_t wIndex;                       /*!< Request value 2nd word (wIndex). */
  uint16_t wLength;                      /*!< Data stage bytes number. */
}USB_SetupPacket_TypeDef;

/** @} */ /* End of group USB_Device_Framework_Exported_Types */

/** @defgroup USB_EndPoint USB EndPoint
  * @{
  */

/** @defgroup USB_EndPoint_Exported_Types USB EndPoint Exported Types
  * @{
  */

/**
  * @brief Function Return Code enumeration
  */

typedef enum
{
  USB_SUCCESS     = 0x0,             /*!< Success. */
  USB_ERROR       = 0x1,             /*!< General USB driver failure. */
  USB_ERR_INV_REQ = 0x2,             /*!< Incorrect data in USB device request. */
  USB_ERR_BUSY    = 0x200,           /*!< Action cannot be proceeded at this time. */
}USB_Result;

/**
  * @brief Stall Type enumeration
  */

typedef enum {USB_STALL_PROTO = 0x0, USB_STALL_HALT = 0x1} USB_StallType;

/** @defgroup USB_EndPoint_Transaction_Handlers USB EndPoint End of Transaction Handlers
  * @{
  */

typedef USB_Result (*USB_EP_IO_Handler)(USB_EP_TypeDef EPx, uint8_t* Buffer, uint32_t Length);
typedef USB_Result (*USB_EP_Setup_Handler)(USB_EP_TypeDef EPx, const USB_SetupPacket_TypeDef* USB_SetupPacket);
typedef USB_Result (*USB_EP_Error_Handler)(USB_EP_TypeDef EPx, uint32_t STS, uint32_t TS, uint32_t CTRL);

/** @} */ /* End of group USB_EndPoint_Transaction_Handlers */

/** @} */ /* End of group USB_EndPoint_Exported_Types */

/** @defgroup USB_EndPoint_Exported_Constants USB EndPoint Exported Constants
  * @{
  */

#define MAX_PACKET_SIZE                      32

/** @} */ /* End of group USB_EndPoint_Exported_Constants */

/** @defgroup USB_EndPoint_Exported_Macros USB EndPoint Exported Macros
  * @{
  */

/** @} */ /* End of group USB_EndPoint_Exported_Macros */

/** @defgroup USB_EndPoint_Exported_Functions USB EndPoint Exported Functions
  * @{
  */

USB_Result USB_EP_Init(USB_EP_TypeDef EPx, uint32_t USB_EP_Ctrl, USB_EP_Error_Handler onError);
USB_Result USB_EP_Reset(USB_EP_TypeDef EPx);
USB_Result USB_EP_Idle(USB_EP_TypeDef EPx);
USB_Result USB_EP_Stall(USB_EP_TypeDef EPx, USB_StallType bHalt);

USB_Result USB_EP_doDataIn(USB_EP_TypeDef EPx, uint8_t* Buffer, uint32_t Length, USB_EP_IO_Handler onInDone);
USB_Result USB_EP_doDataOut(USB_EP_TypeDef EPx, uint8_t* Buffer, uint32_t Length, USB_EP_IO_Handler onOutDone);

USB_Result USB_EP_setSetupHandler(USB_EP_TypeDef EPx, USB_SetupPacket_TypeDef* USB_SetupPacket, USB_EP_Setup_Handler onSetupPacket);

USB_Result USB_EP_dispatchEvent(USB_EP_TypeDef EPx, uint32_t USB_IT);

/** @} */ /* End of group USB_EndPoint_Exported_Functions */

/** @} */ /* End of group USB_EndPoint */

/** @defgroup USB_Device USB Device
  * @{
  */

/** @defgroup USB_Device_Exported_Types USB Device Exported Types
  * @{
  */

/**
  * @brief Device State (9.1) enumeration
  */

typedef enum
{
  USB_DEV_STATE_UNKNOWN = 0,
  USB_DEV_STATE_ATTACHED,
  USB_DEV_STATE_POWERED,
  USB_DEV_STATE_DEFAULT,
  USB_DEV_STATE_ADDRESS,
  USB_DEV_STATE_CONFIGURED,
  Num_USB_DEV_STATE
}USB_DeviceState_TypeDef;

/**
  * @brief Device Self Powered State enumeration
  */

typedef enum
{
  USB_DEV_SELF_POWERED_OFF = 0,
  USB_DEV_SELF_POWERED_ON  = 1
} USB_DeviceSelfPoweredState_TypeDef;

/**
  * @brief Device Remote Wakeup Ability enumeration
  */

typedef enum
{
  USB_DEV_REMOTE_WAKEUP_DISABLED = 0,
  USB_DEV_REMOTE_WAKEUP_ENABLED = 1
}USB_DeviceRemoteWakeup_TypeDef;

/**
  * @brief Device Status Structure definition
  */

typedef struct
{
#ifdef USB_SELF_POWERED_SUPPORTED
  USB_DeviceSelfPoweredState_TypeDef SelfPowered;
#endif /* USB_SELF_POWERED_SUPPORTED */
#ifdef USB_REMOTE_WAKEUP_SUPPORTED
  USB_DeviceRemoteWakeup_TypeDef     RemoteWakeupEnabled;
#endif /* USB_REMOTE_WAKEUP_SUPPORTED */
#if !defined (USB_SELF_POWERED_SUPPORTED) && !defined (USB_REMOTE_WAKEUP_SUPPORTED)
  uint32_t                           Reserved;
#endif
}Usb_DeviceStatus_TypeDef;

/**
  * @brief Device State Machine Context Structure definition
  */

typedef struct {
  USB_DeviceState_TypeDef  USB_DeviceState;
  Usb_DeviceStatus_TypeDef USB_DeviceStatus;
  uint32_t Address;
}USB_DeviceContext_TypeDef;

/**
  * @brief USB BUS parameters Structure definition
  */

typedef struct {
  uint32_t PULL;                           /*!< This member configures the D+ è D- line pulling
                                                This member can be combination of the following values:
                                                USB_HSCR_DM_PULLDOWN_Set: D- line pull down
                                                USB_HSCR_DM_PULLUP_Set:   D- line pull up
                                                USB_HSCR_DP_PULLDOWN_Set: D+ line pull down
                                                USB_HSCR_DP_PULLUP_Set:   D+ line pull up */
  uint32_t SPEED;                          /*!< This member configures the USB speed
                                                This member can be one of the following values:
                                                USB_SC_SCFSR_12Mb:  12 Mbit/sec
                                                USB_SC_SCFSR_1_5Mb: 1.5 Mbit/sec */
  uint32_t MODE;                           /*!< This member configures the USB polarity
                                                This member can be one of the following values:
                                                USB_SC_SCFSP_Full: FULL_SPEED
                                                USB_SC_SCFSP_Low:  LOW_SPEED */
}USB_DeviceBUSParam_TypeDef;

#define IS_USB_PULL(PULL)                    (((PULL) == USB_HSCR_DM_PULLDOWN_Set) || \
                                              ((PULL) == USB_HSCR_DM_PULLUP_Set)   || \
                                              ((PULL) == USB_HSCR_DP_PULLDOWN_Set) || \
                                              ((PULL) == USB_HSCR_DP_PULLUP_Set))

#define IS_USB_SPEED(SPEED)                  (((SPEED) == USB_SC_SCFSR_12Mb) || \
                                              ((SPEED) == USB_SC_SCFSR_1_5Mb))

#define IS_USB_MODE(MODE)                    (((MODE) == USB_SC_SCFSP_Full) || \
                                              ((MODE) == USB_SC_SCFSP_Low))

/** @} */ /* End of group USB_Device_Exported_Types */

/** @defgroup USB_Device_Exported_Constants USB Device Exported Constants
  * @{
  */

/** @} */ /* End of group USB_Device_Exported_Constants */

/** @defgroup USB_Device_Exported_Variables USB Device Exported Variables
  * @{
  */

/**
  * @brief Last processed Controlling Setup Packet (or currently in processing)
  */

extern USB_SetupPacket_TypeDef USB_CurrentSetupPacket;

/**
  * @brief Device State Machine Context
  */

extern USB_DeviceContext_TypeDef USB_DeviceContext;

/** @} */ /* End of group USB_Device_Exported_Variables */

/** @defgroup USB_Device_Exported_Macros USB Device Exported Macros
  * @{
  */

/** @} */ /* End of group USB_Device_Exported_Macros */

/** @defgroup USB_Device_Exported_Functions USB Device Exported Functions
  * @{
  */

USB_Result USB_DeviceInit(const USB_Clock_TypeDef* USB_Clock_InitStruct, USB_DeviceBUSParam_TypeDef* USB_DeviceBUSParam);
USB_Result USB_DevicePowerOn(void);
USB_Result USB_DevicePowerOff(void);
#ifdef USB_REMOTE_WAKEUP_SUPPORTED
USB_Result USB_DeviceRemoteWakeUp(void);
#endif /* USB_REMOTE_WAKEUP_SUPPORTED */

USB_Result USB_DeviceReset(void);
USB_Result USB_DeviceSuspend(void);
USB_Result USB_DeviceResume(void);

USB_Result USB_DeviceSetupPacket(USB_EP_TypeDef EPx, const USB_SetupPacket_TypeDef* USB_SetupPacket);

USB_Result USB_DeviceClearFeature(USB_RequestRecipient_TypeDef Recipient, uint16_t wVALUE, uint16_t wINDEX);
USB_Result USB_DeviceSetFeature(USB_RequestRecipient_TypeDef Recipient, uint16_t wVALUE, uint16_t wINDEX);

USB_Result USB_DeviceDoStatusInAck(USB_EP_TypeDef EPx, uint8_t* Buffer, uint32_t Length);
USB_Result USB_DeviceDoStatusOutAck(USB_EP_TypeDef EPx, uint8_t* Buffer, uint32_t Length);

USB_Result USB_DeviceDispatchEvent(void);

#ifdef USB_INT_HANDLE_REQUIRED
void USB_IRQHandler(void);
#endif /* USB_INT_HANDLE_REQUIRED */

/** @defgroup USB_Device_Exported_Dummy_Functions USB Device Handler Samples
  * @{
  */

USB_Result USB_DeviceDummyGetStatus(USB_RequestRecipient_TypeDef Recipient, uint16_t wINDEX);
USB_Result USB_DeviceDummySetAddress(uint16_t wVALUE);
USB_Result USB_DeviceDummyGetDescriptor(uint16_t wVALUE, uint16_t wINDEX, uint16_t wLENGTH);
USB_Result USB_DeviceDummySetDescriptor(uint16_t wVALUE, uint16_t wINDEX, uint16_t wLENGTH);
uint8_t    USB_DeviceDummyGetConfiguration(void);
USB_Result USB_DeviceDummySetConfiguration(uint16_t wVALUE);
uint8_t    USB_DeviceDummyGetInterface(uint16_t wINDEX);
USB_Result USB_DeviceDummySetInterface(uint16_t wVALUE, uint16_t wINDEX);
USB_Result USB_DeviceDummySyncFrame(uint16_t wINDEX, uint8_t* DATA);
USB_Result USB_DeviceDummyClassRequest(void);
USB_Result USB_DeviceDummyVendorRequest(void);
USB_Result USB_DeviceDummyDataError(USB_EP_TypeDef EPx, uint32_t STS, uint32_t TS, uint32_t CTRL);

/** @} */ /* End of group USB_Device_Exported_Dummy_Functions */

/** @} */ /* End of group USB_Device_Exported_Functions */

/** @} */ /* End of group USB_Device */

/** @} */ /* End of group USB_DEVICE_AND_CDC */

/** @} */ /* End of group MDR32F9Qx_StdPeriph_Driver */

#ifdef __cplusplus
} // extern "C" block end
#endif

#endif /* __MDR32F9Qx_USB_DEVICE_H */

/******************* (C) COPYRIGHT 2011 Phyton *********
*
* END OF FILE MDR32F9Qx_usb_device.h */
