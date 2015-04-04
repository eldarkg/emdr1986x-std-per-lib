/**
  ******************************************************************************
  * @file    USB_Library\MDR32F9Qx_usb_CDC.c
  * @author  Phyton Application Team
  * @version V1.3.0
  * @date    02/03/2011
  * @brief   This file contains the implementation of the Communication Device
  *          Class driver as of:
  *          [1] Communication Device Class driver as of USB Class Definitions
  *              for Communications Devices Rev.1.2 (Errata 1);
  *          [2] USB Communication Class Subclass Specification for PSTN
  *              Devices Rev.1.2.
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
  * FILE MDR32F9Qx_usb_device.c
  */

/* Includes ------------------------------------------------------------------*/
/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_config.h"
#include "MDR32F9Qx_usb_handlers.h"

#define ASSERT_INFO_FILE_ID FILEID__MDR32F9X_USB_CDC_C

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @addtogroup USB_DEVICE_AND_CDC USB DEVICE AND CDC
  * @{
  */

/** @defgroup USB_CDC USB Communication Device Class
  * @{
  */

/** @defgroup USB_CDC_Private_Types USB CDC Private Types
  * @{
  */

/**
  * @brief CDC internal context type
  */

typedef struct {
    uint8_t* CDC_ReceiveBuffer;
    uint32_t CDC_DataPortionLength;
    volatile USB_Result CDC_SendDataStatus,
                        CDC_ReceiveDataStatus;
}USB_CDCContext_TypeDef;


/** @} */ /* End of group USB_CDC_Private_Types */

/** @defgroup USB_CDC_Private_Constants USB CDC Private Constants
  * @{
  */

#ifdef USB_REMOTE_WAKEUP_SUPPORTED
#define USB_REMOTE_WAKEUP                    0x20
#else
#define USB_REMOTE_WAKEUP                    0
#endif /* USB_REMOTE_WAKEUP_SUPPORTED */
#ifdef USB_SELF_POWERED_SUPPORTED
#define USB_SELF_POWERED                     0x40
#else
#define USB_SELF_POWERED                     0
#endif /* USB_SELF_POWERED_SUPPORTED */
#define USB_POWER_ATTIBUTES                  0x80 | USB_REMOTE_WAKEUP | USB_SELF_POWERED

/** @} */ /* End of group USB_CDC_Private_Constants */

/** @defgroup USB_CDC_Private_Variables USB CDC Private Variables
  * @{
  */

/**
  * @brief CDC internal context
  */

static USB_CDCContext_TypeDef USB_CDCContext;

/**
  * @brief Standard Device Descriptor
  */


static uint8_t Usb_CDC_Device_Descriptor[0x12] =
{
    0x12,            /* bLength                  */
    0x01,            /* bDescriptorType (Device) */
    0x10, 0x01,      /* bcdUSB                   */
    0x02,            /* bDeviceClass (CDC)       */
    0x00,            /* bDeviceSubClass          */
    0x00,            /* bDeviceProtocol          */
    MAX_PACKET_SIZE, /* bMaxPacketSize0          */
    0x83, 0x04,      /* idVendor                 */
    0x25, 0xF1,      /* idProduct                */
    0x00, 0x00,      /* bcdDevice                */
    0x00,            /* iManufacturer            */
    0x00,            /* iProduct                 */
    0x00,            /* iSerialNumber            */
    0x01             /* bNumConfigurations       */
};

/**
  * @brief Standard Configuration Descriptor
  */

#define USB_CDC_CONFIG_DESCR_LENGTH   0x43

static uint8_t Usb_CDC_Configuration_Descriptor[0x43] =
{
    /* Configuration Descriptor */
    0x09,                /* bLength                         */
    0x02,                /* bDescriptorType (Configuration) */
    0x43, 0x00,          /* wTotalLength                    */
    0x02,                /* bNumInterfaces                  */
    0x01,                /* bConfigurationValue             */
    0x00,                /* iConfiguration                  */
    USB_POWER_ATTIBUTES, /* bmAttributes                    */
    0x32,                /* bMaxPower (100 mA)              */

    /* Interface Descriptor */
    0x09, /* bLength                                         */
    0x04, /* bDescriptorType (Interface)                     */
    0x00, /* bInterfaceNumber                                */
    0x00, /* bAlternateSetting                               */
    0x01, /* bNumEndpoints                                   */
    0x02, /* bInterfaceClass (Communication Interface Class) */
    0x02, /* bInterfaceSubClass (Abstract Control Model)     */
    0x01, /* bInterfaceProtocol (Common AT commands)         */
    0x00, /* iInterface                                      */
    /* Header Functional Descriptor */
    0x05,       /* bLength (Endpoint Descriptor size)        */
    0x24,       /* bDescriptorType (CS_INTERFACE)            */
    0x00,       /* bDescriptorSubtype (Header Func Desc)     */
    0x10, 0x01, /* bcdCDC (Release Number)                   */
    /* Call Managment Functional Descriptor */
    0x05,       /* bFunctionLength                           */
    0x24,       /* bDescriptorType (CS_INTERFACE)            */
    0x01,       /* bDescriptorSubtype (Call Management)      */
    0x00,       /* bmCapabilities:                           */
    0x01,       /* bDataInterface                            */
    /* ACM Functional Descriptor */
    0x04,       /* bFunctionLength                           */
    0x24,       /* bDescriptorType (CS_INTERFACE)            */
    0x02,       /* bDescriptorSubtype (Abstract Control Management)*/
    0x06,       /* bmCapabilities                            */
    /* Union Functional Descriptor */
    0x05,       /* bFunctionLength                           */
    0x24,       /* bDescriptorType (CS_INTERFACE)            */
    0x06,       /* bDescriptorSubtype (Union func desc)      */
    0x00,       /* bMasterInterface (Communication class interface) */
    0x01,       /* bSlaveInterface0 (Data Class Interface)   */
    /* Endpoint 2 Descriptor */
    0x07,       /* bLength (Endpoint Descriptor size)        */
    0x05,       /* bDescriptorType (Endpoint)                */
    0x82,       /* bEndpointAddress (IN | 2)                 */
    0x03,       /* bmAttributes (Interrupt)                  */
    MAX_PACKET_SIZE, 0x00, /* wMaxPacketSize                 */
    0x02,       /* bInterval                                 */
    /* Data class interface Descriptor */
    0x09,       /* bLength (Endpoint Descriptor size)        */
    0x04,       /* bDescriptorType (Interface)               */
    0x01,       /* bInterfaceNumber                          */
    0x00,       /* bAlternateSetting                         */
    0x02,       /* bNumEndpoints (Two endpoints used)        */
    0x0A,       /* bInterfaceClass (CDC)                     */
    0x00,       /* bInterfaceSubClass                        */
    0x00,       /* bInterfaceProtocol                        */
    0x00,       /* iInterface                                */
    /* Endpoint 1 Descriptor */
    0x07,       /* bLength (Endpoint Descriptor size)        */
    0x05,       /* bDescriptorType (Endpoint)                */
    0x81,       /* bEndpointAddress (IN | 1)                 */
    0x02,       /* bmAttributes (Bulk)                       */
    MAX_PACKET_SIZE, 0x00, /* wMaxPacketSize                 */
    0x00,       /* bInterval                                 */
    /* Endpoint 3 Descriptor */
    0x07,       /* bLength (Endpoint Descriptor size)        */
    0x05,       /* bDescriptorType (Endpoint)                */
    0x03,       /* bEndpointAddress (OUT | 3)                */
    0x02,       /* bmAttributes (Bulk)                       */
    MAX_PACKET_SIZE, 0x00, /* wMaxPacketSize                 */
    0x00,       /* bInterval                                 */
};

#if (defined(USB_CDC_LINE_CODING_SUPPORTED) || defined(USB_CDC_COMM_FEATURE_SUPPORTED))
/**
  * @brief Buffer for Line Coding and Communication Feature data stage
  */
static union
{
#ifdef USB_CDC_LINE_CODING_SUPPORTED
  USB_CDC_LineCoding_TypeDef LineCoding;
#endif /* USB_CDC_LINE_CODING_SUPPORTED */
#ifdef USB_CDC_COMM_FEATURE_SUPPORTED
  uint16_t CommFeature;
#endif /* USB_CDC_COMM_FEATURE_SUPPORTED */
} CDC_ClassPacketData;
#endif /* USB_CDC_LINE_CODING_SUPPORTED || USB_CDC_COMM_FEATURE_SUPPORTED */

#ifdef USB_CDC_STATE_REPORTING_SUPPORTED
/**
  * @brief Buffer Line State Report package
  */
static struct
{
  USB_SetupPacket_TypeDef SetupPacket;
  uint16_t LineState;
} CDC_StateReportPacket =
{
 {
   (USB_DEVICE_TO_HOST | USB_TYPE_CLASS | USB_RECIPIENT_INTERFACE), /* mRequestTypeData */
   USB_CDC_SERIAL_STATE,                                            /* bRequest */
   0,                                                               /* wValue */
   1,                                                               /* wIndex */
   2                                                                /* wLength */
 },
 0                                                                  /* LineState */
};
#endif /* USB_CDC_STATE_REPORTING_SUPPORTED */

/** @} */ /* End of group USB_CDC_Private_Variables */

/** @defgroup USB_CDC_Private_Macros USB CDC Private Macros
  * @{
  */

/** @} */ /* End of group USB_CDC_Private_Macros */

/** @defgroup USB_CDC_Private_FunctionPrototypes USB CDC Private Function Prototypes
  * @{
  */

static USB_Result USB_CDC_OnDataSent(USB_EP_TypeDef EPx, uint8_t* Buffer, uint32_t Length);
static USB_Result USB_CDC_OnDataReceive(USB_EP_TypeDef EPx, uint8_t* Buffer, uint32_t Length);
static USB_Result USB_CDC_DoDataOut(USB_EP_TypeDef EPx, uint8_t* Buffer, uint32_t Length);

/** @} */ /* End of group USB_CDC_Private_FunctionPrototypes */

/** @defgroup USB_CDC_Private_Functions USB CDC Private Functions
  * @{
  */


/**
  * @brief  Initializes CDC context.
  *
  * @param  ReceiveBuffer: Pointer to memory buffer to place incoming
  *         data to. The buffer length should be equal or greater
  *         then MAX_PACKET_LENGTH and DataPortionLength.
  *
  * @param  DataPortionLength: Amount of data received that triggers
  *         USB_CDC_HANDLE_DATA_RECEIVE handler to be called. If any
  *         data should be immediately handled, this parameter should
  *         be set to 1.
  *
  * @param  DataPortionLength: Amount of data received that triggers
  *         USB_CDC_HANDLE_DATA_RECEIVE handler to be called. If any
  *         data should be immediately handled, this parameter should
  *         be set to 1.
  *
  * @param  StartReceiving: Flag indicating whether the device will accept
  *         incoming data immediately after USB_CDC_Reset is called for the
  *         first time.
  *
  * @retval USB_Result.
  */

USB_Result USB_CDC_Init(uint8_t* ReceiveBuffer, uint32_t DataPortionLength, FlagStatus StartReceiving)
{
  USB_CDC_SetReceiveBuffer(ReceiveBuffer, DataPortionLength);
  USB_CDCContext.CDC_SendDataStatus = USB_SUCCESS;
  USB_CDCContext.CDC_ReceiveDataStatus = StartReceiving ? USB_SUCCESS : USB_ERR_BUSY;

  return USB_SUCCESS;
}


/**
  * @brief  Sets the (new) buffer for incoming data.
  *
  * @param  ReceiveBuffer: Pointer to memory buffer to place incoming
  *         data to. The buffer length should be equal or greater
  *         then MAX_PACKET_LENGTH and DataPortionLength.
  *
  * @param  DataPortionLength: Amount of data received that triggers
  *         USB_CDC_HANDLE_DATA_RECEIVE handler to be called. If any
  *         data should be immediately handled, this parameter should
  *         be set to 1.
  *
  * @retval USB_Result.
  */

USB_Result USB_CDC_SetReceiveBuffer(uint8_t* ReceiveBuffer, uint32_t DataPortionLength)
{
  /* Check the parameters */
  assert_param(ReceiveBuffer);

  USB_CDCContext.CDC_ReceiveBuffer = ReceiveBuffer;
  USB_CDCContext.CDC_DataPortionLength = DataPortionLength;

  return USB_SUCCESS;
}

/**
  * @brief  Starts (or restarts) incoming data receiving.
  *
  * @retval USB_Result.
  *
  */

USB_Result USB_CDC_ReceiveStart(void)
{
  USB_CDCContext.CDC_ReceiveDataStatus = USB_SUCCESS;
  return USB_EP_doDataOut(USB_CDC_EP_RECEIVE, USB_CDCContext.CDC_ReceiveBuffer,
            USB_CDCContext.CDC_DataPortionLength, USB_CDC_OnDataReceive);
}

/**
  * @brief  Stops (suspends) incoming data receiving.
  *
  * @retval USB_Result.
  *
  */

USB_Result USB_CDC_ReceiveStop(void)
{
  USB_CDCContext.CDC_ReceiveDataStatus = USB_ERR_BUSY;
  return USB_EP_Stall(USB_CDC_EP_RECEIVE, USB_STALL_PROTO);
}

/**
  * @brief  Initiates sending of data portion to the host
  *
  * @param  Buffer: Pointer to the user's buffer containing data
  *         to be sent
  *
  * @param  Length: Length of data
  *
  * @retval USB_Result.
  *
  * @note   The function returns immediately.
  */

USB_Result USB_CDC_SendData(uint8_t* Buffer, uint32_t Length)
{
  /* Check if previous data sending is complete */
  USB_Result result = USB_CDCContext.CDC_SendDataStatus;

  /* If data can be sent, set "busy" flag and initiate data portion transfer */
  if (result == USB_SUCCESS)
  {
    USB_CDCContext.CDC_SendDataStatus = USB_ERR_BUSY;
    result = USB_EP_doDataIn(USB_CDC_EP_SEND, Buffer, Length, USB_CDC_OnDataSent);
  }
  return result;
}

#ifdef USB_CDC_STATE_REPORTING_SUPPORTED
/**
  * @brief  Sends special Line State Report to host
  *
  * @param  LineState: Coded line state.
  *         This parameter can be any combination of the following values:
  *           @arg USB_CDC_bRxCarrier
  *           @arg USB_CDC_bTxCarrier
  *           @arg USB_CDC_bBreak
  *           @arg USB_CDC_bRingSignal
  *           @arg USB_CDC_bFraming
  *           @arg USB_CDC_bParity
  *           @arg USB_CDC_bOverRun
  *
  * @retval USB_Result.
  *
  * @note   The function returns immediately.
  */

USB_Result USB_CDC_ReportState(uint16_t LineState)
{
  CDC_StateReportPacket.LineState = LineState;
  return USB_EP_doDataIn(USB_CDC_EP_STATE, (uint8_t*)&CDC_StateReportPacket, sizeof(CDC_StateReportPacket), 0);
}
#endif /* USB_CDC_STATE_REPORTING_SUPPORTED */

/** @defgroup USB_CDC_Private_Overwritten_Device_Handlers USB CDC Overwritten Device Handlers implementation
  * @{
  */

/**
  * @brief  Initial CDC setup/reset
  *
  * @param  None
  *
  * @retval USB_Result.
  */

USB_Result USB_CDC_Reset(void)
{
  USB_Result result;

  /* Inherited handler call */
  result = USB_DeviceReset();

  if (result == USB_SUCCESS)
  {
    /* EP1, EP2 and EP3 initialization. Note: DATA1 bit would be toggled to DATA0 on the first
     * IN transaction */
    USB_EP_Init(USB_CDC_EP_SEND, USB_SEPx_CTRL_EPEN_Enable | USB_SEPx_CTRL_EPDATASEQ_Data1,
                USB_CDC_HANDLE_SEND_ERROR);
    USB_EP_Init(USB_CDC_EP_STATE, USB_SEPx_CTRL_EPEN_Enable | USB_SEPx_CTRL_EPDATASEQ_Data1,
                USB_CDC_HANDLE_LINE_STATE_REPORT_SEND_ERROR);
    USB_EP_Init(USB_CDC_EP_RECEIVE, USB_SEPx_CTRL_EPEN_Enable, 0);

    /* Start to listen for incoming data, if desired */
    if (USB_CDCContext.CDC_ReceiveDataStatus == USB_SUCCESS)
    {
      result = USB_EP_doDataOut(USB_CDC_EP_RECEIVE, USB_CDCContext.CDC_ReceiveBuffer,
                USB_CDCContext.CDC_DataPortionLength, USB_CDC_OnDataReceive);
    }
  }
  return result;
}

/**
  * @brief  GET_DESCRIPTOR standard request handler implementation for CDC.
  *
  * @param  wVALUE: Descriptor Type and Descriptor Index
  *
  * @param  wINDEX: Not used
  *
  * @param  wLENGTH: Amount of data host is willing to receive.
  *
  * @retval USB_Result.
  *
  * @note   This handler transmits to host an appropriate CDC descriptor data.
  */

USB_Result USB_CDC_GetDescriptor(uint16_t wVALUE, uint16_t wINDEX, uint16_t wLENGTH)
{
  uint8_t* pDescr = 0;
  uint32_t length;
  USB_Result result = USB_SUCCESS;

  /* Only 0 configuration is supported; for device request this field must be 0 */
  if ((wVALUE & 0xFF) != 0)
  {
    result = USB_ERROR;
  }
  else
  {
    switch (wVALUE >> 8)      /* Descriptor type */
    {
      case USB_DEVICE:
        pDescr = Usb_CDC_Device_Descriptor;
        length = 0x12;
        break;
      case USB_CONFIGURATION:
        pDescr = Usb_CDC_Configuration_Descriptor;
        length = 0x43;
        break;
      default:
        result = USB_ERROR;
    }
  }

  if (result == USB_SUCCESS)
  {
    if (length > wLENGTH)
    {
      length = wLENGTH;
    }
    result = USB_EP_doDataIn(USB_EP0, pDescr, length, USB_DeviceDoStatusOutAck);
  }
  return result;
}

/**
  * @brief  Class-type setup request handler for CDC.
  *
  * @param  None
  *
  * @retval USB_Result.
  */

USB_Result USB_CDC_ClassRequest(void)
{
  USB_Result result = USB_SUCCESS;

  uint16_t wValue = USB_CurrentSetupPacket.wValue,
           wIndex = USB_CurrentSetupPacket.wIndex,
           wLength = USB_CurrentSetupPacket.wLength;

  /* Specific requests */
  switch (USB_CurrentSetupPacket.bRequest)
  {
#ifdef USB_CDC_ENCAPSULATION_SUPPORTED
    /* SEND_ENCAPSULATED_COMMAND */
    case USB_CDC_SEND_ENCAPSULATED_COMMAND:
      result = USB_CDC_HANDLE_SEND_ENCAPSULATED_CMD(wIndex, wLength);
      break;
    /* GET_ENCAPSULATED_RESPONSE */
    case USB_CDC_GET_ENCAPSULATED_RESPONSE:
      result = USB_CDC_HANDLE_GET_ENCAPSULATED_RESP(wIndex, wLength);
      break;
#endif /* USB_CDC_ENCAPSULATION_SUPPORTED */

#ifdef USB_CDC_COMM_FEATURE_SUPPORTED
    /* SET_COMM_FEATURE */
    case USB_CDC_SET_COMM_FEATURE:
      if (wLength == 2)
      {
        result = USB_EP_doDataOut(USB_EP0, (uint8_t*)&CDC_ClassPacketData, wLength, USB_CDC_DoDataOut);
      }
      else
      {
        result = USB_ERR_INV_REQ;
      }
      break;
    /* GET_COMM_FEATURE */
    case USB_CDC_GET_COMM_FEATURE:
      if (wLength == 2)
      {
        result = USB_CDC_HANDLE_GET_COMM_FEATURE(wValue, wIndex, &CDC_ClassPacketData.CommFeature);
        if (result == USB_SUCCESS)
        {
          result = USB_EP_doDataIn(USB_EP0, (uint8_t*)&CDC_ClassPacketData, wLength, USB_DeviceDoStatusOutAck);
        }
      }
      else
      {
        result = USB_ERR_INV_REQ;
      }
      break;
    /* CLEAR_COMM_FEATURE */
    case USB_CDC_CLEAR_COMM_FEATURE:
      result = USB_CDC_HANDLE_CLEAR_COMM_FEATURE(wValue, wIndex);
      break;
#endif /* USB_CDC_COMM_FEATURE_SUPPORTED */

#ifdef USB_CDC_LINE_CODING_SUPPORTED
    /* SET_LINE_CODING */
    case USB_CDC_SET_LINE_CODING:
      if (wLength == 7)
      {
        result = USB_EP_doDataOut(USB_EP0, (uint8_t*)&CDC_ClassPacketData, wLength, USB_CDC_DoDataOut);
      }
      else
      {
        result = USB_ERR_INV_REQ;
      }
      break;
    /* GET_LINE_CODING */
    case USB_CDC_GET_LINE_CODING:
      if (wLength == 7)
      {
        result = USB_CDC_HANDLE_GET_LINE_CODING(wIndex, &CDC_ClassPacketData.LineCoding);
        if (result == USB_SUCCESS)
        {
          result = USB_EP_doDataIn(USB_EP0, (uint8_t*)&CDC_ClassPacketData, wLength, USB_DeviceDoStatusOutAck);
        }
      }
      else
      {
        result = USB_ERR_INV_REQ;
      }
      break;
#endif /* USB_CDC_LINE_CODING_SUPPORTED */

#ifdef USB_CDC_CONTROL_LINE_STATE_SUPPORTED
      /* SET_CONTROL_LINE_STATE */
      case USB_CDC_SET_CONTROL_LINE_STATE:
        result = USB_CDC_HANDLE_CONTROL_LINE_STATE(wValue, wIndex);
        break;
#endif /* USB_CDC_CONTROL_LINE_STATE_SUPPORTED */

#ifdef USB_CDC_LINE_BREAK_SUPPORTED
      /* SEND_BREAK */
      case USB_CDC_SEND_BREAK:
        result = USB_CDC_HANDLE_BREAK(wValue, wIndex);
        break;
#endif /* USB_CDC_LINE_BREAK_SUPPORTED */

      default:
        result = USB_ERROR;
  }
  /* If there were no DATA stage, initiate Status Stage (IN ACK) */
  if (result == USB_SUCCESS && wLength == 0)
  {
    result = (USB_CurrentSetupPacket.mRequestTypeData & 0x80) == USB_DEVICE_TO_HOST ?
                    USB_EP_doDataOut(USB_EP0, 0, 0, 0) :
                    USB_EP_doDataIn(USB_EP0, 0, 0, 0);
  }

  return result;
}

/** @} */ /* End of group USB_CDC_Private_Overwritten_Device_Handlers */

/**
  * @brief  Handler called when data is sent.
  *
  * @param  EPx: USB EndPoint number.
  *         This parameter can be one of the following values:
  *         USB_EP0, USB_EP1, USB_EP2, USB_EP3.
  *
  * @param  Buffer: Pointer to the user's buffer with portion of data
  *                 sent
  *
  * @param  Length: Length of data portion
  *
  * @retval USB_Result.
  *
  * @note   This function interface reflects EndPoint data transmitting handler
  *         requirements.
  */


static USB_Result USB_CDC_OnDataSent(USB_EP_TypeDef EPx, uint8_t* Buffer, uint32_t Length)
{
  /* Release "busy" flag and call user's handler */
  USB_CDCContext.CDC_SendDataStatus = USB_SUCCESS;
  return USB_CDC_HANDLE_DATA_SENT;
}


/**
  * @brief  Handler called when some data is received.
  *
  * @param  EPx: USB EndPoint number.
  *         This parameter can be one of the following values:
  *         USB_EP0, USB_EP1, USB_EP2, USB_EP3.
  *
  * @param  Buffer: Pointer to the user's buffer with received data
  *
  * @param  Length: Length of data
  *
  * @retval USB_Result.
  *
  * @note   This function interface reflects EndPoint data transmitting handler
  *         requirements.
  */

static USB_Result USB_CDC_OnDataReceive(USB_EP_TypeDef EPx, uint8_t* Buffer, uint32_t Length)
{
  /* Call user's handler */
  USB_Result result = USB_CDC_HANDLE_DATA_RECEIVE(Buffer, Length);

  /* If handler returns USB_SUCCESS, wait for another portion. Otherwise, stop to receive
   * incoming data */
  if (result != USB_SUCCESS)
  {
    USB_CDCContext.CDC_ReceiveDataStatus = USB_ERR_BUSY;
  }
  if (USB_CDCContext.CDC_ReceiveDataStatus == USB_SUCCESS)
  {
    return USB_EP_doDataOut(USB_CDC_EP_RECEIVE, USB_CDCContext.CDC_ReceiveBuffer,
              USB_CDCContext.CDC_DataPortionLength, USB_CDC_OnDataReceive);
  }
  else
  {
    return USB_SUCCESS;
  }
}


/**
  * @brief Implements Data stage of Setup transaction with OUT data stage
  *        for Class-Specific requests with data processing on CDC layer.
  *
  * @param  EPx: USB EndPoint number.
  *         This parameter can be one of the following values:
  *         USB_EP0, USB_EP1, USB_EP2, USB_EP3.
  *
  * @param  Buffer: Pointer to the user's buffer with portion of data
  *                 to be sent
  *
  * @param  Length: Length of data portion
  *
  * @retval USB_Result.
  *
  * @note   This function interface reflects EndPoint data transmitting handler
  *         requirements.
  */

static USB_Result USB_CDC_DoDataOut(USB_EP_TypeDef EPx, uint8_t* Buffer, uint32_t Length)
{
  USB_Result result;

  switch (USB_CurrentSetupPacket.bRequest)
  {
#ifdef USB_CDC_COMM_FEATURE_SUPPORTED
    /* USB_CDC_SET_COMM_FEATURE */
    case USB_CDC_SET_COMM_FEATURE:
      /* Call user's handler */
      result = USB_CDC_HANDLE_SET_COMM_FEATURE(USB_CurrentSetupPacket.wValue,
                                               USB_CurrentSetupPacket.wIndex,
                                               *((uint16_t*)Buffer));
      break;
#endif /* USB_CDC_COMM_FEATURE_SUPPORTED */
#ifdef USB_CDC_LINE_CODING_SUPPORTED
    /* USB_CDC_SET_LINE_CODING */
    case USB_CDC_SET_LINE_CODING:
      /* Call user's handler */
      result = USB_CDC_HANDLE_SET_LINE_CODING(USB_CurrentSetupPacket.wIndex,
                                              (const USB_CDC_LineCoding_TypeDef*)Buffer);
      break;
#endif /* USB_CDC_LINE_CODING_SUPPORTED */
    default:
      result = USB_ERR_INV_REQ;
  }
  /* Initiate Status Stage */
  return result == USB_SUCCESS ? USB_EP_doDataIn(EPx, 0, 0, 0) : result;
}

/** @defgroup USB_CDC_Private_Dummy_Functions USB CDC Handlers implementation
  * @{
  */

/**
  * @brief  The sample of handler called when data is received from host.
  *
  * @param  Buffer: Pointer to buffer containing data (same as ReceiveBuffer)
  *
  * @param  Length: Received data length
  *
  * @retval USB_Result. If USB_SUCCESS is returned, the device continues
  *         to receive incoming data, stops otherwise.
  *
  */

USB_Result USB_CDC_DummyDataReceive(uint8_t* Buffer, uint32_t Length)
{
  return USB_ERROR;
}

/**
  * @brief  The sample of handler called when data sending is complete
  *         (successfully or with error)
  *
  * @retval USB_Result.
  *
  */

USB_Result USB_CDC_DummyDataSent(void)
{
  return USB_ERROR;
}

#ifdef USB_CDC_ENCAPSULATION_SUPPORTED
/**
  * @brief  SEND_ENCAPSULATED_COMMAND class-specific packet handler sample ([1], 6.2.1).
  *
  * @param  wINDEX: Interface number
  *
  * @param  wLENGTH: Amount of data
  *
  * @retval USB_Result.
  *
  * @note   The handler is expected to either perform data transfer and status
  *         stages on its own (calling USB_EP_doDataOut), or return value
  *         that is not USB_SUCCESSS.
  */

USB_Result USB_CDC_DummySendEncapsulatedCMD(uint16_t wINDEX, uint16_t wLENGTH)
{
  return USB_ERROR;
}

/**
  * @brief  GET_ENCAPSULATED_RESPONSE class-specific packet handler sample ([1], 6.2.2).
  *
  * @param  wINDEX: Interface number
  *
  * @param  wLENGTH: Amount of data
  *
  * @retval USB_Result.
  *
  * @note   The handler is expected to either perform data transfer and status
  *         stages on its own (calling USB_EP_doDataIn), or return value
  *         that is not USB_SUCCESSS.
  */

USB_Result USB_CDC_DummyGetEncapsulatedResp(uint16_t wINDEX, uint16_t wLENGTH)
{
  return USB_ERROR;
}
#endif /* USB_CDC_ENCAPSULATION_SUPPORTED */

#ifdef USB_CDC_COMM_FEATURE_SUPPORTED
/**
  * @brief  GET_COMM_FEATURE Class-specific packet handler sample ([2], 6.3.2).
  *
  * @param  wVALUE: Feature selector
  *
  * @param  wINDEX: Interface number
  *
  * @param  DATA: Place for the value of current setting.
  *
  * @retval USB_Result.
  */

USB_Result USB_CDC_DummyGetCommFeature(uint16_t wVALUE, uint16_t wINDEX, uint16_t* DATA)
{
  return USB_ERROR;
}

/**
  * @brief  SET_COMM_FEATURE Class-specific packet handler sample ([2], 6.3.1).
  *
  * @param  wVALUE: Feature selector
  *
  * @param  wINDEX: Interface number
  *
  * @param  DATA: Value to be set.
  *
  * @retval USB_Result.
  */

USB_Result USB_CDC_DummySetCommFeature(uint16_t wVALUE, uint16_t wINDEX, uint16_t DATA)
{
  return USB_ERROR;
}

/**
  * @brief  CLEAR_COMM_FEATURE Class-specific packet handler sample ([2], 6.3.3).
  *
  * @param  wVALUE: Feature selector
  *
  * @param  wINDEX: Interface number
  *
  * @retval USB_Result.
  */

USB_Result USB_CDC_DummyClearCommFeature(uint16_t wVALUE, uint16_t wINDEX)
{
  return USB_ERROR;
}
#endif /* USB_CDC_COMM_FEATURE_SUPPORTED */

#ifdef USB_CDC_LINE_CODING_SUPPORTED
/**
  * @brief  GET_LINE_CODING Class-specific packet handler sample ([2], 6.3.11).
  *
  * @param  wINDEX: Interface number
  *
  * @param  DATA: Pointer to USB_CDC_LineCoding_TypeDef structure that
  *         should hold current Line Coding information.
  *
  * @retval USB_Result.
  */

USB_Result USB_CDC_DummyGetLineCoding(uint16_t wINDEX, USB_CDC_LineCoding_TypeDef* DATA)
{
  return USB_ERROR;
}

/**
  * @brief  SET_LINE_CODING Class-specific packet handler sample ([2], 6.3.10).
  *
  * @param  wINDEX: Interface number
  *
  * @param  DATA: Pointer to USB_CDC_LineCoding_TypeDef structure
  *         that contains the Line Coding information.
  *
  * @retval USB_Result.
  */

USB_Result USB_CDC_DummySetLineCoding(uint16_t wINDEX, const USB_CDC_LineCoding_TypeDef* DATA)
{
  return USB_ERROR;
}
#endif /* USB_CDC_LINE_CODING_SUPPORTED */

#ifdef USB_CDC_CONTROL_LINE_STATE_SUPPORTED
/**
  * @brief  SET_CONTROL_LINE_STATE Class-specific packet handler sample ([2], 6.3.12).
  *
  * @param  wVALUE: Control Signal.
  *         This parameter can be any combination of the following values:
  *           @arg USB_CDC_DTR_PRESENT
  *           @arg USB_CDC_RTS_ACTIVATE_CARRIER
  *
  * @param  wINDEX: Interface number
  *
  * @retval USB_Result.
  */

USB_Result USB_CDC_DummyControlLineState(uint16_t wVALUE, uint16_t wINDEX)
{
  return USB_ERROR;
}
#endif /* USB_CDC_CONTROL_LINE_STATE_SUPPORTED */

#ifdef USB_CDC_LINE_BREAK_SUPPORTED
/**
  * @brief  SEND_BREAK Class-specific packet handler sample ([2], 6.3.13).
  *
  * @param  wVALUE: Duration of Break.
  *
  * @param  wINDEX: Interface number
  *
  * @retval USB_Result.
  */

USB_Result USB_CDC_DummySendBreak(uint16_t wVALUE, uint16_t wINDEX)
{
  return USB_ERROR;
}
#endif /* USB_CDC_LINE_BREAK_SUPPORTED */

/** @} */ /* End of group USB_CDC_Private_Dummy_Functions */

/** @} */ /* End of group USB_CDC_Private_Functions */

/** @} */ /* End of group USB_CDC */

/** @} */ /* End of group USB_DEVICE_AND_CDC */

/** @} */ /* End of group MDR32F9Qx_StdPeriph_Driver */

/******************* (C) COPYRIGHT 2011 Phyton *********
*
* END OF FILE MDR32F9Qx_usb_CDC.c */

