/**
  * FILE MDR32F9Qx_usb_device.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MDR32F9Qx_USB_CDC_H
#define __MDR32F9Qx_USB_CDC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_config.h"
#include "MDR32F9Qx_lib.h"
#include "MDR32F9Qx_usb_device.h"

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @addtogroup USB_DEVICE_AND_CDC USB DEVICE AND CDC
  * @{
  */

/** @defgroup USB_CDC USB Communication Device Class
  * @{
  */

/** @defgroup USB_CDC_Exported_Types USB CDC Exported Types
  * @{
  */

/**
  * @brief CDC Class-Specific Setup Request Type enumeration
  */

typedef enum
{
  USB_CDC_SEND_ENCAPSULATED_COMMAND = 0x00,
  USB_CDC_GET_ENCAPSULATED_RESPONSE,
  USB_CDC_SET_COMM_FEATURE,
  USB_CDC_GET_COMM_FEATURE,
  USB_CDC_CLEAR_COMM_FEATURE,
  USB_CDC_SET_AUX_LINE_STATE        = 0x10,
  USB_CDC_SET_HOOK_STATE,
  USB_CDC_PULSE_SETUP,
  USB_CDC_SEND_PULSE,
  USB_CDC_SET_PULSE_TIME,
  USB_CDC_RING_AUX_JACK,
  USB_CDC_SET_LINE_CODING           = 0x20,
  USB_CDC_GET_LINE_CODING,
  USB_CDC_SET_CONTROL_LINE_STATE,
  USB_CDC_SEND_BREAK,
  USB_CDC_SET_RINGER_PARAMS         = 0x30,
  USB_CDC_GET_RINGER_PARAMS,
  USB_CDC_SET_OPERATION_PARAMS,
  USB_CDC_GET_OPERATION_PARAMS,
  USB_CDC_SET_LINE_PARAMS,
  USB_CDC_GET_LINE_PARAMS,
  USB_CDC_DIAL_DIGITS
} USB_CDC_Class_Setup_TypeDef;


/**
  * @brief USB_CDC Serial State enumeration
  */

typedef enum
{
  USB_CDC_bRxCarrier  = 0x01,
  USB_CDC_bTxCarrier  = 0x02,
  USB_CDC_bBreak      = 0x04,
  USB_CDC_bRingSignal = 0x08,
  USB_CDC_bFraming    = 0x10,
  USB_CDC_bParity     = 0x20,
  USB_CDC_bOverRun    = 0x40
}USB_CDCSerialState_TypeDef;

/**
  * @brief USB_CDC Char Format enumeration
  */

typedef enum
{
  USB_CDC_STOP_BITS1   = 0x0,
  USB_CDC_STOP_BITS1_5 = 0x1,
  USB_CDC_STOP_BITS2   = 0x2,
}USB_CDC_CharFormat_TypeDef;

/**
  * @brief USB_CDC Parity Type enumeration
  */

typedef enum
{
  USB_CDC_PARITY_NONE  = 0x0,
  USB_CDC_PARITY_ODD   = 0x1,
  USB_CDC_PARITY_EVEN  = 0x2,
  USB_CDC_PARITY_MARK  = 0x3,
  USB_CDC_PARITY_SPACE = 0x4
}USB_CDC_ParityType_TypeDef;

/**
  * @brief USB_CDC Data Bits enumeration
  */

typedef enum
{
  USB_CDC_DATA_BITS5  = 0x5,
  USB_CDC_DATA_BITS6  = 0x6,
  USB_CDC_DATA_BITS7  = 0x7,
  USB_CDC_DATA_BITS8  = 0x8,
  USB_CDC_DATA_BITS16 = 0xA
}USB_CDC_DataBits_TypeDef;

/**
  * @brief USB_CDC Line Coding Structure definition
  */

typedef struct
{
  uint32_t dwDTERate;
  uint8_t  bCharFormat;
  uint8_t  bParityType;
  uint8_t  bDataBits;
}USB_CDC_LineCoding_TypeDef;

/**
  * @brief USB_CDC Control Line State enumeration
  */

typedef enum
{
  USB_CDC_DTR_PRESENT          = 0x1,
  USB_CDC_RTS_ACTIVATE_CARRIER = 0x2
}USB_CDC_ControlLineState_TypeDef;


/**
  * @brief USB_CDC Line State Report Notifications enumeration
  */

typedef enum
{
  USB_CDC_RING_DETECT             = 0x09,
  USB_CDC_SERIAL_STATE            = 0x20,
  USB_CDC_CALL_STATE_CHANGE       = 0x28,
  USB_CDC_LINE_STATE_CHANGE       = 0x29,
  USB_CDC_CONNECTION_SPEED_CHANGE = 0x2A
}USB_CDC_LineStateReport_TypeDef;

/** @} */ /* End of group USB_CDC_Exported_Types */

/** @defgroup USB_CDC_Exported_Constants USB CDC Exported Constants
  * @{
  */

/** @} */ /* End of group USB_CDC_Exported_Constants */

/** @defgroup USB_CDC_Exported_Variables USB CDC Exported Variables
  * @{
  */


/** @} */ /* End of group USB_CDC_Exported_Variables */

/** @defgroup USB_CDC_Exported_Macros USB CDC Exported Macros
  * @{
  */

/** @defgroup USB_CDC_End_Point_Aliases USB CDC End Point Aliases
  * @{
  */

#define USB_CDC_EP_SEND             USB_EP1
#define USB_CDC_EP_RECEIVE          USB_EP3
#define USB_CDC_EP_STATE            USB_EP2

/** @} */ /* End of group USB_CDC_End_Point_Aliases */

/** @} */ /* End of group USB_CDC_Exported_Macros */

/** @defgroup USB_CDC_Exported_Functions USB CDC Exported Functions
  * @{
  */

USB_Result USB_CDC_Init(uint8_t* ReceiveBuffer, uint32_t DataPortionLength, FlagStatus StartReceiving);

USB_Result USB_CDC_SetReceiveBuffer(uint8_t* ReceiveBuffer, uint32_t DataPortionLength);
USB_Result USB_CDC_ReceiveStart(void);
USB_Result USB_CDC_ReceiveStop(void);

USB_Result USB_CDC_SendData(uint8_t* Buffer, uint32_t Length);

#ifdef USB_CDC_STATE_REPORTING_SUPPORTED
USB_Result USB_CDC_ReportState(uint16_t LineState);
#endif

/** @defgroup USB_CDC_Exported_Overwritten_Device_Handlers USB CDC Overwritten Device Handlers
  * @{
  */

USB_Result USB_CDC_Reset(void);
USB_Result USB_CDC_GetDescriptor(uint16_t wVALUE, uint16_t wINDEX, uint16_t wLENGTH);
USB_Result USB_CDC_ClassRequest(void);

/** @} */ /* End of group USB_CDC_Exported_Overwritten_Device_Handlers */

/** @defgroup USB_CDC_Exported_Dummy_Functions USB CDC Handler Samples
  * @{
  */

USB_Result USB_CDC_DummyDataReceive(uint8_t* Buffer, uint32_t Length);
USB_Result USB_CDC_DummyDataSent(void);

#ifdef USB_CDC_ENCAPSULATION_SUPPORTED
USB_Result USB_CDC_DummySendEncapsulatedCMD(uint16_t wINDEX, uint16_t wLENGTH);
USB_Result USB_CDC_DummyGetEncapsulatedResp(uint16_t wINDEX, uint16_t wLENGTH);
#endif

#ifdef USB_CDC_COMM_FEATURE_SUPPORTED
USB_Result USB_CDC_DummyGetCommFeature(uint16_t wVALUE, uint16_t wINDEX, uint16_t* DATA);
USB_Result USB_CDC_DummySetCommFeature(uint16_t wVALUE, uint16_t wINDEX, uint16_t DATA);
USB_Result USB_CDC_DummyClearCommFeature(uint16_t wVALUE, uint16_t wINDEX);
#endif

#ifdef USB_CDC_LINE_CODING_SUPPORTED
USB_Result USB_CDC_DummyGetLineCoding(uint16_t wINDEX, USB_CDC_LineCoding_TypeDef* DATA);
USB_Result USB_CDC_DummySetLineCoding(uint16_t wINDEX, const USB_CDC_LineCoding_TypeDef* DATA);
#endif

#ifdef USB_CDC_CONTROL_LINE_STATE_SUPPORTED
USB_Result USB_CDC_DummyControlLineState(uint16_t wVALUE, uint16_t wINDEX);
#endif

#ifdef USB_CDC_LINE_BREAK_SUPPORTED
USB_Result USB_CDC_DummySendBreak(uint16_t wVALUE, uint16_t wINDEX);
#endif

/** @} */ /* End of group USB_CDC_Exported_Dummy_Functions */

/** @} */ /* End of group USB_CDC_Exported_Functions */

/** @} */ /* End of group USB_CDC */

/** @} */ /* End of group USB_DEVICE_AND_CDC */

/** @} */ /* End of group MDR32F9Qx_StdPeriph_Driver */

#ifdef __cplusplus
} // extern "C" block end
#endif

#endif /* __MDR32F9Qx_USB_CDC_H */

/*
*
* END OF FILE MDR32F9Qx_usb_CDC.h */
