/**
  * FILE MDR32F9Qx_usb_device.c
  */

/* Includes ------------------------------------------------------------------*/
/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_config.h"
#include "MDR32F9Qx_rst_clk.h"
#include "MDR32F9Qx_usb_handlers.h"

#define ASSERT_INFO_FILE_ID FILEID__MDR32F9X_USB_DEVICE_C

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @addtogroup USB_DEVICE_AND_CDC USB DEVICE AND CDC
  * @{
  */

/** @defgroup USB_Device_Framework_Private_Types USB Device Framework Private Types
  * @{
  */

/** @} */ /* End of group USB_Device_Framework_Private_Types */

/** @defgroup USB_EndPoint USB EndPoint
  * @{
  */

/** @defgroup USB_EndPoint_Private_Types USB EndPoint Private Types
  * @{
  */

/**
  * @brief EndPoint States
  */

typedef enum
{
  USB_EP_NAK,
  USB_EP_IDLE,
  USB_EP_IN,
  USB_EP_OUT,
  USB_EP_SETUP,
  USB_EP_STALL
}USB_EPState_TypeDef;

/**
  * @brief EndPoint State Machine Context type
  */

typedef struct
{
  USB_EPState_TypeDef EP_State;
  USB_StallType EP_Halt;
  struct
  {
    struct
    {
      /* IN-OUT transactions buffer */
      uint8_t *pBuffer;
      uint32_t length, offset;
      uint32_t bytesToAck;        /* number of bytes sent to host in
                                     IN transaction but not acknowledged yet */
    }IO_Buffer;
    /* SETUP-transaction */
    USB_SetupPacket_TypeDef *pSetupPacket;
  }Buffer;
  FlagStatus EP_WasScdone;
  FlagStatus EP_WaitOut, EP_WaitSetup;
  USB_EP_IO_Handler InHandler;
  USB_EP_IO_Handler OutHandler;
  USB_EP_Setup_Handler SetupHandler;
  USB_EP_Error_Handler ErrorHandler;
}USB_EPContext_TypeDef;

/**
  * @brief DATA bit change control
  */

typedef enum
{
  USB_DATA_BIT_KEEP,
  USB_DATA_BIT_TOGGLE,
  USB_DATA_BIT_DATA1,
}USB_EPData_Bit_TypeDef;

/** @} */ /* End of group USB_EndPoint_Private_Types */

/** @defgroup USB_EndPoint_Private_Values USB EndPoint Private Values
  * @{
  */

/**
  * @brief EndPoint State Machine Context
  */

USB_EPContext_TypeDef USB_EPContext[Num_USB_EndPoints];

/** @} */ /* End of group USB_EndPoint_Private_Values */

/** @defgroup USB_EndPoint_Private_Constants USB EndPoint Private Constants
  * @{
  */

/** @} */ /* End of group USB_EndPoint_Private_Constants */

/** @defgroup USB_EndPoint_Private_Macros USB EndPoint Private Macros
  * @{
  */

#define TX_FIFO_FORCE_EMPTY(EndPoint)        USB_SetSEPxTXFDC(EndPoint, 1)
#define RX_FIFO_FORCE_EMPTY(EndPoint)        USB_SetSEPxRXFC(EndPoint, 1)
#define EPx_RX_FIFO_DATA(EndPoint)           USB_GetSEPxRXFD(EndPoint)

/** @} */ /* End of group USB_EndPoint_Private_Macros */

/** @defgroup USB_EndPoint_Private_FunctionPrototypes USB EndPoint Private Function Prototypes
  * @{
  */

static void USB_EP_sendInDataPortion(USB_EP_TypeDef EPx, USB_EPData_Bit_TypeDef DataBitChange);
static void USB_EP_SetReady(USB_EP_TypeDef EPx, uint32_t val);

/** @} */ /* End of group USB_EndPoint_Private_FunctionPrototypes */

/** @defgroup USB_EndPoint_Private_Functions USB EndPoint Private Functions
  * @{
  */

/**
  * @brief  Initial EndPoint setup
  *
  * @param  EPx: USB EndPoint number.
  *         This parameter can be one of the following values:
  *         USB_EP0, USB_EP1, USB_EP2, USB_EP3.
  * @param  USB_EP_Ctrl: Value, controlling EPISOEN, EPDATASEQ bits
  *         of corresponding USB_SEPx.CTRL register.
  * @param  onError: User's handler to be called on any error with data transmitting
  *                   via this End Point (may be 0).
  *
  * @retval USB_Result status (USB_SUCCESS or USB_ERROR).
  */

USB_Result USB_EP_Init(USB_EP_TypeDef EPx, uint32_t USB_EP_Ctrl, USB_EP_Error_Handler onError)
{
  USB_EPContext_TypeDef *ep = USB_EPContext + EPx;

  /* EndPoint context preparation */
  ep->Buffer.IO_Buffer.pBuffer    = 0;
  ep->Buffer.IO_Buffer.length     = 0;
  ep->Buffer.IO_Buffer.bytesToAck = 0;
  ep->Buffer.IO_Buffer.offset     = 0;
  ep->Buffer.pSetupPacket         = 0;
  ep->InHandler                   = 0;
  ep->OutHandler                  = 0;
  ep->SetupHandler                = 0;
  ep->ErrorHandler                = onError;
  ep->EP_Halt                     = USB_STALL_PROTO;
  ep->EP_State                    = USB_EP_NAK;
  ep->EP_WasScdone                = RESET;

  USB_SetSEPxCTRL(EPx, USB_EP_Ctrl);

  return USB_SUCCESS;
}

/**
  * @brief  Resets the EndPoint to NAK state
  *
  * @param  EPx: USB EndPoint number.
  *         This parameter can be one of the following values:
  *         USB_EP0, USB_EP1, USB_EP2, USB_EP3.
  *
  * @retval USB_Result.
  */

USB_Result USB_EP_Reset(USB_EP_TypeDef EPx)
{
  USB_EPContext_TypeDef *ep = USB_EPContext + EPx;

  ep->EP_State = USB_EP_NAK;
  ep->EP_WasScdone = RESET;

  USB_SetSEPxCTRL(EPx, USB_SEPx_CTRL_EPISOEN_Reset  |                           /* Reset Isohronic */
                       USB_SEPx_CTRL_EPRDY_NotReady |                           /* Reset READY */
                       USB_SEPx_CTRL_EPEN_Enable);                              /* Set ENABLE */

  return USB_SUCCESS;
}

/**
  * @brief  Switches the EndPoint to IDLE (wait for transaction) or NAK state
  *
  * @param  EPx: USB EndPoint number.
  *         This parameter can be one of the following values:
  *         USB_EP0, USB_EP1, USB_EP2, USB_EP3.
  *
  * @retval USB_Result.
  *
  * @note   IDLE state and EPRDY bit are set if OUT/SETUP transaction is expected.
  *         Otherwise, this function switches to NAK state.
  */

USB_Result USB_EP_Idle(USB_EP_TypeDef EPx)
{
  USB_EPContext_TypeDef *ep = USB_EPContext + EPx;
  uint32_t val = USB_SEPx_CTRL_EPSSTALL_NotReply;                               /* Reset STALL reply */

  if (ep->EP_WaitOut || ep->EP_WaitSetup)
  {
    ep->EP_State = USB_EP_IDLE;
    val |= USB_SEPx_CTRL_EPRDY_Ready;                                           /* Set READY */
  }
  else
  {
    ep->EP_State = USB_EP_NAK;
  }
  ep->EP_Halt = USB_STALL_PROTO;

  USB_EP_SetReady(EPx, val);

  return USB_SUCCESS;
}

/**
  * @brief  Switches the EndPoint to STALL state (protocol stall
  *         or halt) or NAK state, if STALL is prohibited.
  *
  * @param  EPx: USB EndPoint number.
  *         This parameter can be one of the following values:
  *         USB_EP0, USB_EP1, USB_EP2, USB_EP3.
  *
  * @param  bHalt: Specifies whether the STALL state is a HALT
  *         This parameter can be: USB_STALL_PROTO or USB_STALL_HALT.
  *
  * @retval USB_Result.
  *
  * @note   If protocol stall is ordered, but the EndPoint doesn't accept
  *         SETUP transactions, EndPoint is switched to NAK state.
  */

USB_Result USB_EP_Stall(USB_EP_TypeDef EPx, USB_StallType bHalt)
{
  USB_EPContext_TypeDef *ep = USB_EPContext + EPx;
  uint32_t val = 0;

  if (bHalt == USB_STALL_HALT && EPx == USB_EP0)
  {
    /* No functional stall for Default Control Pipe */
    return USB_ERROR;
  }

  if (bHalt == USB_STALL_HALT || ep->EP_WaitSetup)
  {
    ep->EP_Halt  = bHalt;
    ep->EP_State = USB_EP_STALL;
    val = USB_SEPx_CTRL_EPSSTALL_Reply |                                          /* Set STALL reply */
          USB_SEPx_CTRL_EPRDY_Ready;                                              /* Set READY */
  }

  USB_EP_SetReady(EPx, val);

  return USB_SUCCESS;
}

/**
  * @brief  Indicates that there is data to be sent to the host by this
  *         EndPoint with one or several IN-transactions.
  *
  * @param  EPx: USB EndPoint number.
  *         This parameter can be one of the following values:
  *         USB_EP0, USB_EP1, USB_EP2, USB_EP3.
  *
  * @param  Buffer: Pointer to the user's buffer with data to be sent.
  *
  * @param  Length: Length of data.
  *
  * @param  onInDone: User's handler to be called when data transfer is
  *                   successfully complete (may be 0).
  *
  * @retval USB_Result.
  */

USB_Result USB_EP_doDataIn(USB_EP_TypeDef EPx, uint8_t* Buffer, uint32_t Length, USB_EP_IO_Handler onInDone)
{
  USB_EPContext_TypeDef *ep = USB_EPContext + EPx;
  /* Setup IN Data stage starts with DATA1 */
  USB_EPData_Bit_TypeDef StartInStage = (ep->EP_WaitSetup ? USB_DATA_BIT_DATA1 : USB_DATA_BIT_TOGGLE);

  /* Set EndPoint context */
  ep->Buffer.IO_Buffer.pBuffer    = Buffer;
  ep->Buffer.IO_Buffer.length     = Length;
  ep->Buffer.IO_Buffer.bytesToAck = MAX_PACKET_SIZE;
  ep->Buffer.IO_Buffer.offset     = 0;
  ep->InHandler                   = onInDone;

  /* Send first data portion */
  USB_EP_sendInDataPortion(EPx, StartInStage);

  ep->EP_State                    = USB_EP_IN;
  
  return USB_SUCCESS;
}

/**
  * @brief  Indicates that we are willing to receive Length or more bytes of data
  *         from the host to this EndPoint with OUT transaction(s).
  *
  * @param  EPx: USB EndPoint number.
  *         This parameter can be one of the following values:
  *         USB_EP0, USB_EP1, USB_EP2, USB_EP3.
  *
  * @param  Buffer: Pointer to the user's buffer to place received data to.
  *                 The total buffer size should be equal or greater then
  *                 ((Length / MAX_PACKET_LENGTH) + 1) * MAX_PACKET_LENGTH)
  *
  * @param  Length: The minimal data length to receive before the transfer is
  *                 treated as complete.
  *
  * @param  onOutDone: User's handler to be called after Length or more bytes of
  *                    data is successfully received (may be 0).
  *
  * @retval USB_Result.
  */

USB_Result USB_EP_doDataOut(USB_EP_TypeDef EPx, uint8_t* Buffer, uint32_t Length, USB_EP_IO_Handler onOutDone)
{
  USB_EPContext_TypeDef *ep = USB_EPContext + EPx;

  /* Set EndPoint context */
  ep->Buffer.IO_Buffer.pBuffer    = Buffer;
  ep->Buffer.IO_Buffer.length     = Length;
  ep->Buffer.IO_Buffer.bytesToAck = 0;
  ep->Buffer.IO_Buffer.offset     = 0;
  ep->OutHandler                  = onOutDone;
  ep->EP_WaitOut                  = SET;

  /* Start awaiting for OUT transaction */
  USB_EP_Idle(EPx);

  return USB_SUCCESS;
}

/**
  * @brief  Indicates that we are willing to receive (repeatedly) Setup Control
  *         Transactions with this EndPoint.
  *
  * @param  EPx: USB EndPoint number.
  *         This parameter can be one of the following values:
  *         USB_EP0, USB_EP1, USB_EP2, USB_EP3.
  *
  * @param  USB_SetupPacket: Pointer to the user's buffer to place
  *         received setup packet.
  *
  * @param  onSetupPacket: User's handler to be called when setup packet
  *         is received.
  *
  * @retval USB_Result.
  */

USB_Result USB_EP_setSetupHandler(USB_EP_TypeDef EPx, USB_SetupPacket_TypeDef* USB_SetupPacket, USB_EP_Setup_Handler onSetupPacket)
{
  USB_EPContext_TypeDef *ep = USB_EPContext + EPx;

  /* Set EndPoint context */
  ep->Buffer.pSetupPacket         = USB_SetupPacket;
  ep->Buffer.IO_Buffer.length     = 0;
  ep->Buffer.IO_Buffer.bytesToAck = 0;
  ep->Buffer.IO_Buffer.offset     = 0;
  ep->SetupHandler                = onSetupPacket;
  ep->EP_WaitSetup                = onSetupPacket ? SET : RESET;

  /* Start awaiting for SETUP transaction */
  USB_EP_Idle(EPx);

  return USB_SUCCESS;
}

/**
  * @brief  EndPoint state machine implementation.
  *
  * @param  EPx: USB EndPoint number.
  *         This parameter can be one of the following values:
  *         USB_EP0, USB_EP1, USB_EP2, USB_EP3.
  *
  * @param  USB_IT: SLAVE controller interrupt flags (USB_SIS register value).
  *
  * @retval USB_Result.
  *
  * @note   This function should be called at appropriate rate to handle possible
  *         EndPoint events.
  */

USB_Result USB_EP_dispatchEvent(USB_EP_TypeDef EPx, uint32_t USB_IT)
{
  FlagStatus nextIteration = RESET;
  USB_Result result = USB_SUCCESS;
  uint32_t tmpSTS, tmpTS, tmpCTRL;
  uint32_t i, count;
  USB_EPContext_TypeDef *ep;

  tmpSTS = USB_GetSEPxSTS(EPx);
  tmpTS  = (USB_GetSEPxTS(EPx) & USB_SEPx_TS_SCTTYPE_Msk);
  tmpCTRL = USB_GetSEPxCTRL(EPx);

  ep = USB_EPContext + EPx;

  /* Remember SCDONE event in the EndPoint context */
  if (USB_IT & USB_SIS_SCTDONE)
  {
    ep->EP_WasScdone = SET;
  }

  do
  {
    switch (ep->EP_State)
    {
      /* USB_EP_NAK */
      case USB_EP_NAK:
      {
        /* Fast return if EndPoint in the NAK state */
        return USB_SUCCESS;
      }

      /* USB_EP_IDLE */
      case USB_EP_IDLE:
      {
        if (!(tmpCTRL & USB_SEP_CTRL_EPRDY) && ep->EP_WasScdone)
        {
          /* EPRDY dropped - event for this End Point */
          if ((tmpTS == USB_SEPx_TS_SCTTYPE_Outdata) && ep->EP_WaitOut)
          {
            /* OUT transaction started: switch into the OUT state and continue processing there */
            ep->EP_State = USB_EP_OUT;
            ep->EP_WaitOut = RESET;
            nextIteration = SET;
          }
          else if ((tmpTS == USB_SEPx_TS_SCTTYPE_Setup) && ep->EP_WaitSetup)
          {
            /* SETUP transaction started: switch into the SETUP state and continue processing there */
            ep->EP_State = USB_EP_SETUP;
            nextIteration = SET;
          }
          else
          {
            /* Unexpected transaction: switch into STALL/NAK state and return error */
            result = USB_ERROR;
            USB_EP_Stall(EPx, USB_STALL_PROTO);
          }
        }
        break;
      }

      /* USB_EP_IN */
      case USB_EP_IN:
      {
        /* Analyze event type */
        if ((!(tmpCTRL & USB_SEP_CTRL_EPRDY)) && ep->EP_WasScdone &&
            (tmpTS == USB_SEPx_TS_SCTTYPE_In) && (tmpSTS & USB_SEP_STS_SCACKRXED))
        {
          /* 1. ACK event */
          ep->Buffer.IO_Buffer.offset += ep->Buffer.IO_Buffer.bytesToAck;
          if (ep->Buffer.IO_Buffer.offset >= ep->Buffer.IO_Buffer.length)
          {
            /* If offset >= length (transfer is over), indicate it with NAK state
             * and call handler (if present) */
            ep->EP_State = USB_EP_NAK;
            if (ep->InHandler != 0)
            {
              result = ep->InHandler(EPx, ep->Buffer.IO_Buffer.pBuffer, ep->Buffer.IO_Buffer.length);
            }

            if (result == USB_SUCCESS)
            {
              /* If no other transaction is ordered by user or no data stage of SETUP
               * packet (state isn't changed), go to NAK/IDLE state */
              if (ep->EP_State == USB_EP_NAK)
              {
                USB_EP_Idle(EPx);
              }
            }
            else
            {
              /* If user's handler indicated error, go to STALL/NAK state */
              USB_EP_Stall(EPx, USB_STALL_PROTO);
            }
          }
          else
          {
            /* If there is any data to send remaining, send next portion */
            USB_EP_sendInDataPortion(EPx, USB_DATA_BIT_TOGGLE);
          }
        }
        else if (tmpSTS & (USB_SEP_STS_SCRXOF
                         | USB_SEP_STS_SCCRCERR
                         | USB_SEP_STS_SCBSERR
                         | USB_SEP_STS_SCRXTO))
        {
          /* 2. Error events - call error handler (if present). Switch temporarily to NAK
           * to check if user orders another transaction */
          ep->EP_State = USB_EP_NAK;
          if (ep->ErrorHandler != 0)
          {
            result = ep->ErrorHandler(EPx, tmpSTS, tmpTS, tmpCTRL);
          }
          if (result == USB_SUCCESS)
          {
            if (ep->EP_State == USB_EP_NAK)
            {
              /* If there is no user's handler or USB_SUCCESS returned and no other transaction
               * is started, retry with current data portion */
              ep->EP_State = USB_EP_IN;
              USB_EP_sendInDataPortion(EPx, USB_DATA_BIT_KEEP);
            }
          }
          else
          {
            /* If user's handler indicated error, go to STALL/NAK state */
            USB_EP_Stall(EPx, USB_STALL_PROTO);
          }
        }
        break;
      }

      /* USB_EP_OUT */
      case USB_EP_OUT:
      {
        /* Check for event */
        if (!(tmpCTRL & USB_SEP_CTRL_EPRDY) && ep->EP_WasScdone)
        {
          nextIteration = RESET;

          /* Read data packet */
          count = USB_GetSEPxRXFDC(EPx);
          for (i = 0; i < count; i++)
          {
            ep->Buffer.IO_Buffer.pBuffer[ep->Buffer.IO_Buffer.offset + i] = EPx_RX_FIFO_DATA(EPx);
          }
          RX_FIFO_FORCE_EMPTY(EPx);
          ep->Buffer.IO_Buffer.offset += count;

          /* If offset >= length (transfer is over), indicate it with NAK state
           * and call handler (if present) */
          if (ep->Buffer.IO_Buffer.offset >= ep->Buffer.IO_Buffer.length)
          {
            ep->EP_State = USB_EP_NAK;
            if (ep->OutHandler != 0)
            {
              result = ep->OutHandler(EPx, ep->Buffer.IO_Buffer.pBuffer, ep->Buffer.IO_Buffer.offset);
            }

            if (result == USB_SUCCESS)
            {
              /* If no other transaction is ordered by user or no data stage of SETUP
               * packet (state isn't changed), go to NAK/IDLE state */
              if (ep->EP_State == USB_EP_NAK)
              {
                USB_EP_Idle(EPx);
              }
            }
            else
            {
              /* If user's handler indicated error, go to STALL/NAK state */
              USB_EP_Stall(EPx, USB_STALL_PROTO);
            }
          }
          else
          {
            /* If offset < length, wait for another portion */
            USB_EP_SetReady(EPx, USB_SEPx_CTRL_EPRDY_Ready);
          }
        }
        break;
      }

      /* USB_EP_SETUP */
      case USB_EP_SETUP:
      {
        /* Check for event */
        if (ep->EP_WasScdone)
        {
          assert_param(ep->SetupHandler);

          /* Read setup packet and check for correct size (8 bytes) */
          count = USB_GetSEPxRXFDC(EPx);
          if (count == 8)
          {
            for (i = 0; i < count; i++)
            {
              ((uint8_t*)ep->Buffer.pSetupPacket)[i] = EPx_RX_FIFO_DATA(EPx);
            }
            RX_FIFO_FORCE_EMPTY(EPx);

            /* Call the handler */
            result = ep->SetupHandler(EPx, ep->Buffer.pSetupPacket);

            if (result == USB_SUCCESS)
            {
              /* If no other transaction is ordered by user or no data stage of SETUP
               * packet (state isn't changed), go to NAK/IDLE state */
              if (ep->EP_State == USB_EP_SETUP)
              {
                USB_EP_Idle(EPx);
              }
            }
            else
            {
              /* If user's handler indicated error, go to STALL/NAK state */
              USB_EP_Stall(EPx, USB_STALL_PROTO);
            }
          }
          else /* Incorrect packet size */
          {
            RX_FIFO_FORCE_EMPTY(EPx);
            result = USB_ERROR;
            /* Switch into STALL state */
            USB_EP_Stall(EPx, USB_STALL_PROTO);
          }
        }
        nextIteration = RESET;
        break;
      }

      /* USB_EP_STALL */
      case USB_EP_STALL:
      {
        if (!(tmpCTRL & USB_SEP_CTRL_EPRDY))
        {
          /* EPRDY dropped - event for this End Point */
          if (ep->EP_Halt == USB_STALL_HALT)
          {
            USB_EP_Stall(EPx, USB_STALL_HALT);
          }
          else
          {
            USB_EP_Idle(EPx);
          }
        }
        break;
      }
    }
  } while (nextIteration);

  return result;
}

/**
  * @brief  Prepares EndPoint for IN transaction accepting (service function).
  *
  * @param  EPx: USB EndPoint number.
  *         This parameter can be one of the following values:
  *         USB_EP0, USB_EP1, USB_EP2, USB_EP3.
  *
  * @param  DataBitChange: DATA bit handling.
  *         This parameter can be one of the following values:
  *           @arg USB_DATA_BIT_KEEP: Don't change DATA bit.
  *           @arg USB_DATA_BIT_TOGGLE: Toggle DATA0/DATA1.
  *           @arg USB_DATA_BIT_DATA1: Set DATA1.
  *
  * @retval USB_Result.
  */

static void USB_EP_sendInDataPortion(USB_EP_TypeDef EPx, USB_EPData_Bit_TypeDef DataBitChange)
{
  USB_EPContext_TypeDef *ep = USB_EPContext + EPx;
  uint32_t i, total;

  assert_param(ep->EP_State == USB_EP_IN);

  /* Clean TX FIFO buffer */
  TX_FIFO_FORCE_EMPTY(EPx);

  /* Adjust DATA bit */
  switch (DataBitChange)
  {
    case USB_DATA_BIT_KEEP:
      break;
    case USB_DATA_BIT_TOGGLE:
      USB_SEPxToggleEPDATASEQ(EPx);
      break;
    case USB_DATA_BIT_DATA1:
      USB_SetSEPxCTRL(EPx, USB_SEPx_CTRL_EPDATASEQ_Data1);
      break;
  }

  /* Copy data portion into TX FIFO buffer */
  total = (ep->Buffer.IO_Buffer.offset + ep->Buffer.IO_Buffer.bytesToAck < ep->Buffer.IO_Buffer.length ?
            ep->Buffer.IO_Buffer.offset + ep->Buffer.IO_Buffer.bytesToAck : ep->Buffer.IO_Buffer.length);
  for (i = ep->Buffer.IO_Buffer.offset; i < total; i++)
  {
    USB_SetSEPxTXFD(EPx, ep->Buffer.IO_Buffer.pBuffer[i]);
  };

  /* Set EPRDY bit */
  USB_EP_SetReady(EPx, USB_SEPx_CTRL_EPRDY_Ready);
}


/**
  * @brief  Sets EPRDY and STALL bits (service function).
  *
  * @param  EPx: USB EndPoint number.
  *         This parameter can be one of the following values:
  *         USB_EP0, USB_EP1, USB_EP2, USB_EP3.
  *
  * @param  val: Value for SEPxCTRL register.
  *
  * @retval USB_Result.
  *
  * @note   Before setting EPRDY, the function clears pending
  *         bits (especially SCTDONE), to indicate that previous
  *         transaction is complete.
  */

static void USB_EP_SetReady(USB_EP_TypeDef EPx, uint32_t val)
{
  USB_EPContext_TypeDef *ep = USB_EPContext + EPx;

  /* Clear pending bits */
  USB_SetSIS(USB_SIS_Msk);

  ep->EP_WasScdone = RESET;

  /* Set CTRL bits */
  USB_SetSEPxCTRL(EPx, val);
}

/** @} */ /* End of group USB_EndPoint_Private_Functions */

/** @} */ /* End of group USB_EndPoint */

/** @defgroup USB_Device USB Device
  * @{
  */

/** @defgroup USB_Device_Private_Types USB Device Private Types
  * @{
  */

/** @} */ /* End of group USB_Device_Private_Types */

/** @defgroup USB_Device_Private_Constants USB Device Private Constants
  * @{
  */

/** @} */ /* End of group USB_Device_Private_Constants */

/** @defgroup USB_Device_Private_Variables USB Device Private Variables
  * @{
  */

USB_SetupPacket_TypeDef USB_CurrentSetupPacket;
USB_DeviceContext_TypeDef USB_DeviceContext;
static uint8_t SetupPacketData[2];

/** @} */ /* End of group USB_Device_Private_Variables */

/** @defgroup USB_Device_Private_Macros USB Device Private Macros
  * @{
  */

/** @} */ /* End of group USB_Device_Private_Macros */

/** @defgroup USB_Device_Private_FunctionPrototypes USB Device Private Function Prototypes
  * @{
  */

static USB_Result USB_Device_setAddressWork(USB_EP_TypeDef EPx, uint8_t* Buffer, uint32_t Length);

/** @} */ /* End of group USB_Device_Private_FunctionPrototypes */

/** @defgroup USB_Device_Private_Functions USB Device Private Functions
  * @{
  */

/**
  * @brief  Initializes the USB peripheral according to the specified
  *         parameters in the USB_Clock_InitStruct.
  * @param  USB_Clock_InitStruct: pointer to a USB_Clock_TypeDef structure
  *         that contains the configuration information for the USB Clock.
  *
  * @param  USB_DeviceBUSParam: pointer to a USB_DeviceBUSParam_TypeDef structure
  *         that contains the configuration information for the USB BUS
  *
  * @retval USB_Result.
  */

USB_Result USB_DeviceInit(const USB_Clock_TypeDef* USB_Clock_InitStruct, USB_DeviceBUSParam_TypeDef* USB_DeviceBUSParam)
{
  /* Check the parameters */
  assert_param(IS_USB_PULL(USB_DeviceBUSParam->PULL));
  assert_param(IS_USB_SPEED(USB_DeviceBUSParam->SPEED));
  assert_param(IS_USB_MODE(USB_DeviceBUSParam->MODE));

  /* Set USB clocks perform controller reset */
  USB_BRGInit(USB_Clock_InitStruct);
  USB_Reset();
  /* Set pulls and Device mode */
  USB_SetHSCR(USB_HSCR_HOST_MODE_Device);
  USB_SetHSCR(USB_DeviceBUSParam->PULL);
  /* Set speed, polarity and enable end points */
  USB_SetSC(USB_DeviceBUSParam->SPEED | USB_DeviceBUSParam->MODE | USB_SC_SCGEN_Set);
  /* Setup EP0 */
  USB_EP_Init(USB_EP0, USB_SEPx_CTRL_EPEN_Enable | USB_SEPx_CTRL_EPDATASEQ_Data1, 0);
  USB_EP_setSetupHandler(USB_EP0, &USB_CurrentSetupPacket, USB_DEVICE_HANDLE_SETUP);

  USB_DeviceContext.USB_DeviceState = USB_DEV_STATE_UNKNOWN;
  USB_DeviceContext.Address = 0;

  return USB_SUCCESS;
}

/**
  * @brief  Enables the USB peripheral.
  *
  * @param  None
  *
  * @retval USB_Result.
  */

USB_Result USB_DevicePowerOn(void)
{
  USB_SetHSCR(USB_HSCR_EN_RX_Set | USB_HSCR_EN_TX_Set);
  USB_DeviceContext.USB_DeviceState = USB_DEV_STATE_POWERED;

  return USB_SUCCESS;
}

/**
  * @brief  Disables the USB peripheral.
  *
  * @param  None
  *
  * @retval USB_Result.
  */

USB_Result USB_DevicePowerOff(void)
{
  USB_SetHSCR(USB_HSCR_EN_RX_Reset);
  USB_DeviceContext.USB_DeviceState = USB_DEV_STATE_UNKNOWN;

  return USB_SUCCESS;
}

#ifdef USB_REMOTE_WAKEUP_SUPPORTED
/**
  * @brief  Initiates host remote wakeup
  *
  * @param  None
  *
  * @retval USB_Result.
  */

USB_Result USB_DeviceRemoteWakeUp(void)
{
  return USB_SUCCESS;
}
#endif /* USB_REMOTE_WAKEUP_SUPPORTED */

/** @defgroup USB_Device_Private_Handlers USB Device Handlers implementation
  * @{
  */

/**
  * @brief  Reset bus handler
  *
  * @param  None
  *
  * @retval USB_Result.
  */

USB_Result USB_DeviceReset(void)
{
  USB_DeviceContext.USB_DeviceState = USB_DEV_STATE_DEFAULT;
  return USB_SUCCESS;
}

/**
  * @brief  Performs all necessary actions on entering to SUSPENDED state
  *
  * @param  None
  *
  * @retval USB_Result.
  */

USB_Result USB_DeviceSuspend(void)
{
  return USB_SUCCESS;
}

/**
  * @brief  Performs all necessary actions on exit from SUSPENDED state
  *
  * @param  None
  *
  * @retval USB_Result.
  */

USB_Result USB_DeviceResume(void)
{
  return USB_SUCCESS;
}

/**
  * @brief  Control Setup Packet processing dispatcher (set as EP0 setup
  *         packet handler).
  *
  * @param  EPx: USB Control EndPoint (EP0) number.
  *
  * @param  USB_SetupPacket: Pointer to a USB_SetupPacket_TypeDef structure
  *         that contains received setup packet contents (on success)
  *
  * @retval USB_Result.
  *
  * @note   This function interface reflects EndPoint setup packet handler
  *         requirements. Request setup packet data is placed into
  *         USB_CurrentSetupPacket variable to be accessible from the
  *         specific request type handlers.
  */

USB_Result USB_DeviceSetupPacket(USB_EP_TypeDef EPx, const USB_SetupPacket_TypeDef* USB_SetupPacket)
{
  USB_RequestType_TypeDef requestType;
  USB_RequestTypeDT_TypeDef requestDirection;

  USB_Result result = USB_SUCCESS;
  uint16_t wValue, wIndex, wLength;

  /* Check the parameters */
  assert_param(IS_USB_ENDPOINT(EPx));

  /* Determine request type */
  requestType = (USB_RequestType_TypeDef)(USB_SetupPacket->mRequestTypeData & USB_REQUEST_TYPE_Msk);
  requestDirection = (USB_RequestTypeDT_TypeDef)(USB_SetupPacket->mRequestTypeData & USB_REQUEST_DT_Msk);

  /* Process request */
  switch (requestType)
  {
    /* Standard request */
    case USB_TYPE_STANDARD: {
      USB_RequestRecipient_TypeDef recipient;
      USB_EP_IO_Handler statusAckHandler = 0;

      wValue = USB_SetupPacket->wValue;
      wIndex = USB_SetupPacket->wIndex;
      wLength = USB_SetupPacket->wLength;

      /* Recipient check */
      recipient = (USB_RequestRecipient_TypeDef)(USB_SetupPacket->mRequestTypeData & USB_RECIPIENT_TYPE_Msk);
      if (!IS_VALID_USB_RECIPIENT(recipient)) {
        result = USB_ERR_INV_REQ;
        break;
      }
      /* Specific requests */
      switch (USB_SetupPacket->bRequest)
      {
        /* GET_STATUS */
        case USB_GET_STATUS:
          if (requestDirection != USB_DEVICE_TO_HOST ||
             (USB_DeviceContext.USB_DeviceState == USB_DEV_STATE_ADDRESS && (recipient == USB_RECIPIENT_INTERFACE ||
              (recipient == USB_RECIPIENT_ENDPOINT && wIndex >= Num_USB_EndPoints))))
          {
            result = USB_ERROR;
          }
          else
          {
            /* Give user a chance to set flags in the device context */
            result = USB_DEVICE_HANDLE_GET_STATUS(recipient, wIndex);
            if (result == USB_SUCCESS)
            {
              switch (recipient)
              {
                /* Device - return Self Powered and Remote Wakeup status */
                case USB_RECIPIENT_DEVICE:
                  SetupPacketData[0] = 0
#ifdef USB_SELF_POWERED_SUPPORTED
                    | USB_DeviceContext.USB_DeviceStatus.SelfPowered
#endif /* USB_SELF_POWERED_SUPPORTED */
#ifdef USB_REMOTE_WAKEUP_SUPPORTED
                    | (USB_DeviceContext.USB_DeviceStatus.RemoteWakeupEnabled << 1)
#endif /* USB_REMOTE_WAKEUP_SUPPORTED */
                    ;
                  break;
                /* Interface - return 0 */
                case USB_RECIPIENT_INTERFACE:
                  SetupPacketData[0] = 0;
                  break;
                /* Endpoint - return Halt status */
                case USB_RECIPIENT_ENDPOINT:
                  SetupPacketData[0] = USB_EPContext[wIndex].EP_Halt;
                  break;
                default:
                  break;
              }
              SetupPacketData[1] = 0;
              result = USB_EP_doDataIn(EPx, SetupPacketData, 2, USB_DeviceDoStatusOutAck);
            }
          }
          break;
        /* CLEAR_FEATURE */
        case USB_CLEAR_FEATURE:
          if (USB_DeviceContext.USB_DeviceState == USB_DEV_STATE_ADDRESS && (recipient == USB_RECIPIENT_INTERFACE ||
              (recipient == USB_RECIPIENT_ENDPOINT && wIndex >= Num_USB_EndPoints)))
          {
            result = USB_ERROR;
          }
          else
          {
            result = USB_DEVICE_HANDLE_CLEAR_FEATURE(recipient, wValue, wIndex);
          }
          break;
        /* SET_FEATURE */
        case USB_SET_FEATURE:
          if (USB_DeviceContext.USB_DeviceState == USB_DEV_STATE_ADDRESS && (recipient == USB_RECIPIENT_INTERFACE ||
              (recipient == USB_RECIPIENT_ENDPOINT && wIndex >= Num_USB_EndPoints)))
          {
            result = USB_ERROR;
          }
          else
          {
            result = USB_DEVICE_HANDLE_SET_FEATURE(recipient, wValue, wIndex);
          }
          break;
        /* SET_ADDRESS */
        case USB_SET_ADDRESS:
          result = USB_DEVICE_HANDLE_SET_ADDRESS(wValue);
          /* Set special Status Stage handler that will actually change the address */
          USB_DeviceContext.Address = wValue;
          statusAckHandler = USB_Device_setAddressWork;
          break;
        /* GET_DESCRIPTOR */
        case USB_GET_DESCRIPTOR:
          result = USB_DEVICE_HANDLE_GET_DESCRIPTOR(wValue, wIndex, wLength);
          break;
        /* SET_DESCRIPTOR */
        case USB_SET_DESCRIPTOR:
          result = USB_DEVICE_HANDLE_SET_DESCRIPTOR(wValue, wIndex, wLength);
          break;
        /* GET_CONFIGURATION */
        case USB_GET_CONFIGURATION:
          if (USB_DeviceContext.USB_DeviceState == USB_DEV_STATE_ADDRESS)
          {
            SetupPacketData[0] = 0;
          }
          else
          {
            SetupPacketData[0] = (uint8_t)USB_DEVICE_HANDLE_GET_CONFIGURATION;
          }
          result = USB_EP_doDataIn(EPx, SetupPacketData, 1, USB_DeviceDoStatusOutAck);
          break;
        /* SET_CONFIGURATION */
        case USB_SET_CONFIGURATION:
          if (wValue == 0)
          {
            USB_DeviceContext.USB_DeviceState = USB_DEV_STATE_ADDRESS;
          }
          else
          {
            result = USB_DEVICE_HANDLE_SET_CONFIGURATION(wValue);
            if (result == USB_SUCCESS)
            {
              USB_DeviceContext.USB_DeviceState = USB_DEV_STATE_CONFIGURED;
            }
          }
          break;
        /* GET_INTERFACE */
        case USB_GET_INTERFACE:
          if (USB_DeviceContext.USB_DeviceState == USB_DEV_STATE_ADDRESS)
          {
            result = USB_ERROR;
          }
          else
          {
            SetupPacketData[0] = (uint8_t)USB_DEVICE_HANDLE_GET_INTERFACE(wIndex);
            result = USB_EP_doDataIn(EPx, SetupPacketData, 1, USB_DeviceDoStatusOutAck);
          }
          break;
        /* SET_INTERFACE */
        case USB_SET_INTERFACE:
          if (USB_DeviceContext.USB_DeviceState == USB_DEV_STATE_ADDRESS)
          {
            result = USB_ERROR;
          }
          else
          {
            result = USB_DEVICE_HANDLE_SET_INTERFACE(wValue, wIndex);
          }
          break;
        /* SYNCH_FRAME */
        case USB_SYNCH_FRAME:
          if (USB_DeviceContext.USB_DeviceState == USB_DEV_STATE_ADDRESS)
          {
            result = USB_ERROR;
          }
          else
          {
            result = USB_DEVICE_HANDLE_SYNC_FRAME(wIndex, SetupPacketData);
            if (result == USB_SUCCESS)
            {
              result = USB_EP_doDataIn(EPx, SetupPacketData, 2, USB_DeviceDoStatusOutAck);
            }
          }
          break;
        default:
          result = USB_ERR_INV_REQ;
      }
      /* If there were no DATA stage, initiate Status Stage (IN ACK) */
      if (result == USB_SUCCESS && wLength == 0)
      {
        result = (USB_SetupPacket->mRequestTypeData & 0x80) == USB_DEVICE_TO_HOST ?
                        USB_EP_doDataOut(EPx, 0, 0, statusAckHandler) :
                        USB_EP_doDataIn(EPx, 0, 0, statusAckHandler);
      }
      break;
    }
    /* Class-specific request */
    case USB_TYPE_CLASS:
      result = USB_DEVICE_HANDLE_CLASS_REQUEST;
      break;
    /* Vendor-specific request */
    case USB_TYPE_VENDOR:
      result = USB_DEVICE_HANDLE_VENDOR_REQUEST;
      break;
    default:
      result = USB_ERR_INV_REQ;
  }
  return result;
}

/** @} */ /* End of group USB_Device_Private_Handlers */

/** @defgroup USB_Device_deviceSetupPacket_Handlers USB Device Standard Request specific handlers
  * @{
  */

/**
  * @brief  Called on CLEAR_FEATURE request (9.4.1).
  *
  * @param  Recipient: Recipient type (from setup packet header).
  *         This parameter can be one of the following values:
  *         USB_RECIPIENT_DEVICE, USB_RECIPIENT_INTERFACE,
  *         USB_RECIPIENT_ENDPOINT, USB_RECIPIENT_OTHER.
  *
  * @param  wVALUE: Feature selector.
  *
  * @param  wINDEX: Interface or EndPoint number, if Recipient has
  *         appropriate value.
  *
  * @retval USB_Result.
  *
  * @note   This handler is called in correct state only. This implementation
  *         process ENDPOINT_HALT (calling USB_EP_Ready) and DEVICE_REMOTE_WAKEUP
  *         (clearing RemoteWakeupEnabled context flag) standard features only.
  */

USB_Result USB_DeviceClearFeature(USB_RequestRecipient_TypeDef Recipient, uint16_t wVALUE, uint16_t wINDEX)
{
  if ((Recipient == USB_RECIPIENT_ENDPOINT) && (wVALUE == USB_ENDPOINT_HALT))
  {
    return USB_EP_Idle((USB_EP_TypeDef)wINDEX);
  }
  else
  {
    return USB_ERROR;
  }
}

/**
  * @brief  Called on SET_FEATURE request (9.4.9).
  *
  * @param  Recipient: Recipient type (from setup packet header).
  *         This parameter can be one of the following values:
  *         USB_RECIPIENT_DEVICE, USB_RECIPIENT_INTERFACE,
  *         USB_RECIPIENT_ENDPOINT, USB_RECIPIENT_OTHER.
  *
  * @param  wVALUE: Feature selector.
  *
  * @param  wINDEX: Interface or EndPoint number, if Recipient has
  *         appropriate value.
  *
  * @retval USB_Result.
  *
  * @note   This handler is called in correct state only. This implementation
  *         process ENDPOINT_HALT (calling USB_EP_Stall) and DEVICE_REMOTE_WAKEUP
  *         (setting RemoteWakeupEnabled context flag) standard features only.
  */

USB_Result USB_DeviceSetFeature(USB_RequestRecipient_TypeDef Recipient, uint16_t wVALUE, uint16_t wINDEX)
{
  if ((Recipient == USB_RECIPIENT_ENDPOINT) && (wVALUE == USB_ENDPOINT_HALT))
  {
    return USB_EP_Stall((USB_EP_TypeDef)wINDEX, USB_STALL_HALT);
  }
  else
  {
    return USB_ERROR;
  }
}

/** @} */ /* End of group USB_Device_deviceSetupPacket_Handlers */

/** @defgroup USB_Device_Status_Stage_Handlers USB Device Service Functions
  * @{
  */

/**
  * @brief Implements Status stage of Setup transaction with OUT data stage
  *        or without data stage. To be used as EndPoint transaction handler.
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

USB_Result USB_DeviceDoStatusInAck(USB_EP_TypeDef EPx, uint8_t* Buffer, uint32_t Length)
{
  (void)EPx;
  (void)Buffer;
  (void)Length;

  return USB_SUCCESS;
}

/**
  * @brief Implements Status stage of Setup transaction with IN data stage.
  *        To be used as EndPoint transaction handler.
  *
  * @param  EPx: USB EndPoint number.
  *         This parameter can be one of the following values:
  *         USB_EP0, USB_EP1, USB_EP2, USB_EP3.
  *
  * @param  Buffer: Pointer to the user's buffer for next portion of data
  *
  * @param  Length: Length of data portion
  *
  * @retval USB_Result.
  *
  * @note   This function interface reflects EndPoint data transmitting handler
  *         requirements.
  */

USB_Result USB_DeviceDoStatusOutAck(USB_EP_TypeDef EPx, uint8_t* Buffer, uint32_t Length)
{
  (void)Buffer;
  (void)Length;

  return USB_EP_doDataOut(EPx, 0, 0, 0);
}

/**
  * @brief Implements Status stage of Setup SET_ADDRESS transaction.
  *        Actually changes the device address. To be used as EndPoint
  *        transaction handler.
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

static USB_Result USB_Device_setAddressWork(USB_EP_TypeDef EPx, uint8_t* Buffer, uint32_t Length)
{
  (void)EPx;
  (void)Buffer;
  (void)Length;

  /* Set address */
  USB_SetSA(USB_DeviceContext.Address);
  /* Adjust device state */
  USB_DeviceContext.USB_DeviceState = (USB_DeviceContext.Address ? USB_DEV_STATE_ADDRESS : USB_DEV_STATE_DEFAULT);

  return USB_SUCCESS;
}

/** @} */ /* End of group USB_Device_Status stage _Handlers */

/**
  * @brief  USB interrupt dispatcher, called from interrupt handler
  *
  * @param  None
  *
  * @retval USB_Result.
  *
  * @note   Handles common events (such as Reset) and calls USB_EP_setSetupHandler
  *         for each EndPoint in use.
  */

USB_Result USB_DeviceDispatchEvent(void)
{
  uint32_t i;
  uint32_t USB_IT;
  USB_Result result = USB_SUCCESS;
  static volatile uint32_t bHandling = RESET;

  /* Disable USB interrupts */
#ifdef USB_INT_HANDLE_REQUIRED
  NVIC_DisableIRQ(USB_IRQn);
#endif /* USB_INT_HANDLE_REQUIRED */

  if (!bHandling) {
    bHandling = SET;

    /* Get masked interrupt flags */
    USB_IT = USB_GetSIS();
    /* Handle reset */
    if (USB_IT & USB_SIS_SCRESETEV)
    {
      result = USB_DeviceReset();
      USB_DeviceContext.Address = 0;
      USB_SetSA(USB_DeviceContext.Address);

    }

    /* Invoke End Point dispatchers */
    for (i = USB_EP0; i < Num_USB_EndPoints; i++)
    {
      USB_EP_dispatchEvent((USB_EP_TypeDef)i, USB_IT);
    }

    /* Clear pending bits, except for SCTDONE */
    USB_SetSIS(USB_IT & (~USB_SIS_SCTDONE_Set) & (~USB_SIS_SCUSBON_Set));

    bHandling = RESET;

    /* Enable USB interrupts (only after the actual work is done) */
#ifdef USB_INT_HANDLE_REQUIRED
    NVIC_EnableIRQ(USB_IRQn);
#endif /* USB_INT_HANDLE_REQUIRED */
  }
  return result;
}

#ifdef USB_INT_HANDLE_REQUIRED
/**
  * @brief  Default implementation of USB interrupt handler
  *
  * @param  None
  *
  * @retval None
  *
  * @note   To be overwritten, USB_INT_HANDLE_REQUIRED definition should be
  *         undefined.
  *
  */

void USB_IRQHandler(void)
{
  USB_DeviceDispatchEvent();
}
#endif /* USB_INT_HANDLE_REQUIRED */


/** @defgroup USB_Device_Private_Dummy_Functions USB Device Private Handler Samples
  * @{
  */

/**
  * @brief  GET_STATUS standard request handler sample (9.4.5).
  *
  * @param  Recipient: Recipient type (from setup packet header).
  *         This parameter can be one of the following values:
  *         USB_RECIPIENT_DEVICE, USB_RECIPIENT_INTERFACE,
  *         USB_RECIPIENT_ENDPOINT, USB_RECIPIENT_OTHER.
  *
  * @param  wINDEX: Interface or EndPoint number, if Recipient has
  *         appropriate value.
  *
  * @retval USB_Result.
  *
  * @note   Intended to update USB_DeviceStatus field of the device context
  *         before the status to be sent to host. Data stage begins if USB_SUCCESS
  *         is returned.
  */

USB_Result USB_DeviceDummyGetStatus(USB_RequestRecipient_TypeDef Recipient, uint16_t wINDEX)
{
  (void)Recipient;
  (void)wINDEX;

  return USB_SUCCESS;
}

/**
  * @brief  SET_ADDRESS standard request handler (preparation) sample (9.4.6).
  *
  * @param  wVALUE: New device address
  *
  * @retval USB_Result.
  *
  * @note   Intended to do perform actions while still in setup transaction
  *         (actual address change to be performed after status stage completes).
  *         If value returned is not USB_SUCCESS, transaction is aborted.
  */

USB_Result USB_DeviceDummySetAddress(uint16_t wVALUE)
{
  (void)wVALUE;

  return USB_SUCCESS;
}

/**
  * @brief  GET_DESCRIPTOR standard request handler sample (9.4.3).
  *
  * @param  wVALUE: Descriptor Type and Descriptor Index
  *
  * @param  wINDEX: Zero or Language ID (see 9.6.7)
  *
  * @param  wLENGTH: Amount of data host is willing to receive.
  *
  * @retval USB_Result.
  *
  * @note   This handler is called in correct state only. It's to be implemented
  *         in any device class. It is expected to either perform data transfer
  *         and status stages on its own (calling USB_EP_doDataIn), or return
  *         value that is not USB_SUCCESS.
  */

USB_Result USB_DeviceDummyGetDescriptor(uint16_t wVALUE, uint16_t wINDEX, uint16_t wLENGTH)
{
  (void)wVALUE;
  (void)wINDEX;
  (void)wLENGTH;

  return USB_ERROR;
}

/**
  * @brief  SET_DESCRIPTOR standard request handler sample (9.4.8).
  *
  * @param  wVALUE: Descriptor Type and Descriptor Index
  *
  * @param  wINDEX: Zero or Language ID (see 9.6.7)
  *
  * @param  wLENGTH: Amount of data to be sent by host.
  *
  * @retval USB_Result.
  *
  * @note   This handler is called in correct state only. It's to be implemented
  *         only if the device supports descriptor update by host. It is expected
  *         to either perform data transfer and status stages on its own (calling
  *         USB_EP_doDataOut), or return value that is not USB_SUCCESS.
  */

USB_Result USB_DeviceDummySetDescriptor(uint16_t wVALUE, uint16_t wINDEX, uint16_t wLENGTH)
{
  (void)wVALUE;
  (void)wINDEX;
  (void)wLENGTH;

  return USB_ERROR;
}

/**
  * @brief  GET_CONFIGURATION standard request handler sample (9.4.2).
  *
  * @param  None
  *
  * @retval Currently selected configuration number or 0 on error.
  *
  * @note   This handler is called in correct state only. It's to be implemented
  *         if the device supports more than one configuration.
  */

uint8_t USB_DeviceDummyGetConfiguration(void)
{
  return 1;
}

/**
  * @brief  SET_CONFIGURATION standard request handler sample (9.4.7).
  *
  * @param  wVALUE: Configuration number
  *
  * @retval USB_Result.
  *
  * @note   This handler is called in correct state only. It's to be implemented
  *         if the device supports more than one configuration.
  */

USB_Result USB_DeviceDummySetConfiguration(uint16_t wVALUE)
{
  (void)wVALUE;

  return USB_ERROR;
}

/**
  * @brief  GET_INTERFACE standard request handler sample (9.4.4).
  *
  * @param  wINDEX: Interface number.
  *
  * @retval Currently selected alternate setting for the specified interface
  *         or 0 in case of error.
  *
  * @note   This handler is called in correct state only. It's to be implemented
  *         if the device supports interfaces with alternate settings.
  */

uint8_t USB_DeviceDummyGetInterface(uint16_t wINDEX)
{
  (void)wINDEX;

  return 0;
}

/**
  * @brief  SET_INTERFACE standard request handler sample (9.4.10).
  *
  * @param  wVALUE: Alternate setting to be set.
  *
  * @param  wINDEX: Interface number.
  *
  * @retval USB_Result.
  *
  * @note   This handler is called in correct state only. It's to be implemented
  *         if the device supports interfaces with alternate settings.
  */

USB_Result USB_DeviceDummySetInterface(uint16_t wVALUE, uint16_t wINDEX)
{
  (void)wVALUE;
  (void)wINDEX;

  return USB_SUCCESS;
}

/**
  * @brief  SYNC_FRAME standard request handler sample (9.4.11).
  *
  * @param  wINDEX: EndPoint number.
  *
  * @param  DATA: Pointer for frame number.
  *
  * @retval USB_Result.
  *
  * @note   This handler is called in correct state only. It's to be implemented
  *         if some of the device EndPoints support isochronous transfers. It is
  *         expected to place EndPoint synchronization frame number into DATA pointed
  *         location or return value that is not USB_SUCCESS.
  */

USB_Result USB_DeviceDummySyncFrame(uint16_t wINDEX, uint8_t* DATA)
{
  (void)wINDEX;
  (void)DATA;

  return USB_ERROR;
}

/**
  * @brief  Class-type setup request handler sample.
  *
  * @param  None
  *
  * @retval USB_Result.
  *
  * @note   This handler is called in correct state only. It's to be implemented
  *         the device supports any class-type requests. Request setup packet data
  *         is accessible by USB_CurrentSetupPacket variable. The overwritten method
  *         should implement both data (if present) and status transfer stages.
  */

USB_Result USB_DeviceDummyClassRequest(void)
{
  return USB_ERROR;
}

/**
  * @brief  Vendor-type setup request handler sample.
  *
  * @param  None
  *
  * @retval USB_Result.
  *
  * @note   This handler is called in correct state only. It's to be implemented
  *         the device supports any vendor-type requests. Request setup packet data
  *         is accessible by USB_CurrentSetupPacket variable. The overwritten method
  *         should implement both data (if present) and status transfer stages.
  */


USB_Result USB_DeviceDummyVendorRequest(void)
{
  return USB_ERROR;
}


/**
  * @brief  EndPoint error handler sample.
  *
  * @param  EPx: USB EndPoint number.
  *         This parameter can be one of the following values:
  *         USB_EP0, USB_EP1, USB_EP2, USB_EP3.
  *
  * @param  STS: USB_SEPx.STS register value.
  *
  * @param  TS: USB_SEPx.TS register value.
  *
  * @param  CTRL: USB_SEPx.CTRL register value.
  *
  * @retval USB_Result.
  *
  * @note   This function interface reflects EndPoint error handler
  *         requirements. When called on IN transaction error:
  *          - if it hasn't start another transaction and returns USB_SUCCESS,
  *            then retry of data transmission would occur;
  *          - if it returns error code, EndPoint would be switched to
  *            NAK/STALL state.
  */

USB_Result USB_DeviceDummyDataError(USB_EP_TypeDef EPx, uint32_t STS, uint32_t TS, uint32_t CTRL)
{
  (void)EPx;
  (void)STS;
  (void)TS;
  (void)CTRL;

  return USB_ERROR;
}

/** @} */ /* End of group USB_Device_Private_Dummy_Functions */


/** @} */ /* End of group USB_Device_Private_Functions */

/** @} */ /* End of group USB_Device */

/** @} */ /* End of group USB_DEVICE_AND_CDC */

/** @} */ /* End of group MDR32F9Qx_StdPeriph_Driver */

/*
*
* END OF FILE MDR32F9Qx_usb_device.c */

