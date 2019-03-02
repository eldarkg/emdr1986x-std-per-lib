/**
  ******************************************************************************
  * @file    mdr32f8_can.c
  * @author  Milandr Application Team
  * @version V1.0.0
  * @date    03/09/2015
  * @brief   This file contains all the CAN firmware functions.
  ******************************************************************************
  * <br><br>
  *
  *
  * <h2><center>&copy; COPYRIGHT 2015 Milandr</center></h2>
  ******************************************************************************
  * FILE mdr32f8_can.c
  */

/* Includes ------------------------------------------------------------------*/
#include "mdr32f8_can.h"
#include "MDR1986VE8T.h"	


#define ASSERT_INFO_FILE_ID FILEID__MDR32F9X_CAN_C

/** @addtogroup __MDR32F8_StdPeriph_Driver
  * @{
  */

/** @defgroup CAN
  * @{
  */

/** @defgroup CAN_Private_Constants
  * @{
  */

/* CANx_BUF_xx_DLC Register masks to determine packet format */
#define CAN_BUF_DLC_STD   ((uint32_t)0x00000A00)    /* Standard format */
#define CAN_BUF_DLC_EXT   ((uint32_t)0x00001A00)    /* Extended format */

/** @} */ /* End of group CAN_Private_Constants */

/** @defgroup CAN_Private_Variables CAN Private Variables
  * @{
  */

/** @} */ /* End of group CAN_Private_Variables */

/** @defgroup CAN_Private_FunctionPrototypes CAN Private Function Prototypes
  * @{
  */
static uint32_t CAN_ReadBufferSFR(__IO uint32_t* SFR);

/** @} */ /* End of group CAN_Private_FunctionPrototypes */

/** @defgroup CAN_Private_Functions CAN Private Functions
  * @{
  */

/**
  * @brief  Deinitializes the CANx peripheral registers to their default reset values.
  * @param  CANx: Select the CAN peripheral.
  *         This parameter can be one of the following values: CAN1, CAN2.
  * @retval None
  */
void CAN_DeInit(MDR_CAN_TypeDef* CANx)
{
  uint32_t i;

  /* Check the parameters */
  assert_param(IS_CAN_ALL_PERIPH(CANx));

  CANx->CONTROL = 0;
  CANx->STATUS = 0;
  CANx->BITTMNG = 0;
  CANx->INT_EN = 0;
  CANx->OVER = 0;
  CANx->INT_RX = 0;
  CANx->INT_TX = 0;

  for (i = 0; i < 32; i++)
  {
    CANx->BUF_CON[i] = 0;
  }
}

/**
  * @brief  Initializes the CANx peripheral according to the specified
  *         parameters in the CAN_InitStruct.
  * @param  CANx: Select the CAN peripheral.
  *         This parameter can be one of the following values:
  *         CAN1, CAN2.
  * @param  CAN_InitStruct: pointer to a CAN_InitTypeDef structure
  *         that contains the configuration information for the specified CAN peripheral.
  * @retval None
  *
  * @note   This function may be called only if appropriate CANx controller is in the
  *         disabled state.
  */
void CAN_Init(MDR_CAN_TypeDef* CANx, const CAN_InitTypeDef* CAN_InitStruct)
{
  uint32_t tmpreg_CONTROL = 0;
  uint32_t tmpreg_BITTMNG;
  uint32_t i;

  /* Check the parameters */
  assert_param(IS_CAN_ALL_PERIPH(CANx));
  assert_param(IS_FUNCTIONAL_STATE(CAN_InitStruct->CAN_ROP));
  assert_param(IS_FUNCTIONAL_STATE(CAN_InitStruct->CAN_SAP));
  assert_param(IS_FUNCTIONAL_STATE(CAN_InitStruct->CAN_STM));
  assert_param(IS_FUNCTIONAL_STATE(CAN_InitStruct->CAN_ROM));
  assert_param(IS_CAN_PSEG_VALUE(CAN_InitStruct->CAN_PSEG));
  assert_param(IS_CAN_SEG1_VALUE(CAN_InitStruct->CAN_SEG1));
  assert_param(IS_CAN_SEG2_VALUE(CAN_InitStruct->CAN_SEG2));
  assert_param(IS_CAN_SJW_VALUE(CAN_InitStruct->CAN_SJW));
  assert_param(IS_CAN_SAMPLING_MODE(CAN_InitStruct->CAN_SB));

  /* Configure CONTROL register*/
  if (CAN_InitStruct->CAN_ROP != DISABLE)
  {
    tmpreg_CONTROL |= CAN_CONTROL_ROP;
  }
  if (CAN_InitStruct->CAN_SAP != DISABLE)
  {
    tmpreg_CONTROL |= CAN_CONTROL_SAP;
  }
  if (CAN_InitStruct->CAN_STM != DISABLE)
  {
    tmpreg_CONTROL |= CAN_CONTROL_STM;
  }
  if (CAN_InitStruct->CAN_ROM != DISABLE)
  {
    tmpreg_CONTROL |= CAN_CONTROL_ROM;
  }
  CANx->CONTROL = tmpreg_CONTROL;

  /* Configure BITTMNG register*/
  tmpreg_BITTMNG = CAN_InitStruct->CAN_PSEG + CAN_InitStruct->CAN_SEG1 +
                   CAN_InitStruct->CAN_SEG2 + CAN_InitStruct->CAN_SJW +
                   (uint32_t)(CAN_InitStruct->CAN_BRP);
  tmpreg_BITTMNG |= CAN_InitStruct->CAN_SB;
  CANx->BITTMNG = tmpreg_BITTMNG;

  /* Initialize Filters */
  for (i = 0; i < 32; i++)
  {
    CANx->FILTER[i].FILTER = 0;
    CANx->FILTER[i].MASK = 0;
  }

  /* Configure OVER register*/
  CANx->OVER = (uint32_t)(CAN_InitStruct->CAN_OVER_ERROR_MAX);
}

/**
  * @brief  Fills each CAN_InitStruct member with its default value.
  * @param  CAN_InitStruct: pointer to a CAN_InitTypeDef structure
  *         that is to be initialized.
  * @retval None
  */
void CAN_StructInit(CAN_InitTypeDef* CAN_InitStruct)
{
  /* Reset CAN init structure parameters values */
  /* Own packet reception: disabled */
  CAN_InitStruct->CAN_ROP = DISABLE;
  /* Sending ACK on own packets: disabled */
  CAN_InitStruct->CAN_SAP = DISABLE;
  /* Self Test mode: disabled */
  CAN_InitStruct->CAN_STM = DISABLE;
  /* Read Only mode: disabled */
  CAN_InitStruct->CAN_ROM = DISABLE;
  /* CAN_PSEG member */
  CAN_InitStruct->CAN_PSEG = CAN_PSEG_Mul_1TQ;
  /* CAN_SEG1 member */
  CAN_InitStruct->CAN_SEG1 = CAN_SEG1_Mul_2TQ;
  /* CAN_SEG2 member */
  CAN_InitStruct->CAN_SEG2 = CAN_SEG2_Mul_6TQ;
  /* CAN_SEG2 member */
  CAN_InitStruct->CAN_SJW = CAN_SJW_Mul_1TQ;
  /* Sampling mode member */
  CAN_InitStruct->CAN_SB = CAN_SB_1_SAMPLE;
  /* CAN_BRP member */
  CAN_InitStruct->CAN_BRP = 0;
  /* CAN_OVER_ERROR_MAX member */
  CAN_InitStruct->CAN_OVER_ERROR_MAX = 255;
}

/**
  * @brief  Initializes the CANx Buffer filter and mask according to the specified
  *         parameters in the CAN_FilterInitStruct.
  * @param  CANx: Select the CAN peripheral.
  *         This parameter can be one of the following values: CAN1, CAN2.
  * @param  BufferNumber: the number of the buffer that is used for reception.
  * @param  CAN_FilterInitStruct: pointer to a CAN_FilterInitTypeDef
  *         structure that contains the configuration information.
  * @retval None.
  */
void CAN_FilterInit(MDR_CAN_TypeDef* CANx, uint32_t BufferNumber, CAN_FilterInitTypeDef* CAN_FilterInitStruct)
{
  /* Check the parameters */
  assert_param(IS_CAN_ALL_PERIPH(CANx));
  assert_param(IS_CAN_BUFFER(BufferNumber));
  assert_param(IS_CAN_ID(CAN_FilterInitStruct->Filter_ID));
  assert_param(IS_CAN_ID(CAN_FilterInitStruct->Mask_ID));

  CANx->FILTER[BufferNumber].FILTER  = CAN_FilterInitStruct->Filter_ID;
  CANx->FILTER[BufferNumber].MASK    = CAN_FilterInitStruct->Mask_ID;
}

/**
  * @brief  Enables or disables the specified CAN interrupts.
  * @param  CANx: Select the CAN peripheral.
  *         This parameter can be one of the following values:
  *         CAN1, CAN2.
  * @param  CAN_IT: specifies the CAN interrupt sources to be enabled or disabled.
  *         This parameter can be: CAN_IT_GLBINTEN, CAN_IT_RXINTEN, CAN_IT_TXINTEN,
  *         CAN_IT_ERRINTEN or CAN_IT_ERROVERINTEN.
  * @param  NewState: new state of the CAN interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void CAN_ITConfig(MDR_CAN_TypeDef* CANx, uint32_t CAN_IT, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_CAN_ALL_PERIPH(CANx));
  assert_param(IS_CAN_ITConfig(CAN_IT));
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  if (NewState != DISABLE)
  {
    CANx->INT_EN |= CAN_IT;
  }
  else
  {
    CANx->INT_EN &= ~CAN_IT;
  }
}

/**
  * @brief  Searches for disabled (i.e., not currently used for reception
  *         or transmission) buffer.
  * @param  CANx: Select the CAN peripheral.
  *         This parameter can be one of the following values:
  *         CAN1, CAN2.
  * @retval Number of the first found (with lesser number) disabled buffer
  *         or CAN_BUFFER_NUMBER if there is no such a buffer.
  */
uint32_t CAN_GetDisabledBuffer(MDR_CAN_TypeDef* CANx)
{
  uint32_t buffer_number;

  /* Check the parameters */
  assert_param(IS_CAN_ALL_PERIPH(CANx));

  for (buffer_number = 0;
	  ((buffer_number < CAN_BUFFER_NUMBER) &&  ((CANx->BUF_CON[buffer_number] & CAN_STATUS_EN) != 0));
       buffer_number++)
  {
  }

  return buffer_number;
}

/**
  * @brief  Searches for an empty transfer buffer.
  * @param  CANx: Select the CAN peripheral.
  *         This parameter can be one of the following values:
  *         CAN1, CAN2.
  * @retval Number of the first found (with lesser number) empty buffer
  *         or CAN_BUFFER_NUMBER if there is no such a buffer.
  */
uint32_t CAN_GetEmptyTransferBuffer(MDR_CAN_TypeDef* CANx)
{
  uint32_t buffer_number;

  /* Check the parameters */
  assert_param(IS_CAN_ALL_PERIPH(CANx));

  for (buffer_number = 0; (buffer_number < CAN_BUFFER_NUMBER) &&
        ((CANx->BUF_CON[buffer_number] & (CAN_STATUS_EN | CAN_STATUS_TX_REQ | CAN_STATUS_RX_TXn)) != CAN_STATUS_EN);
        buffer_number++)
  {
  }
  return buffer_number;
}

/**
  * @brief  Initiates the transmission of a message.
  * @param  CANx: Select the CAN peripheral.
  *         This parameter can be one of the following values:
  *         CAN1, CAN2.
  * @param  BufferNumber: the number of the buffer that is used for transmission.
  * @param  TxMessage: pointer to a CAN_TxMsgTypeDef structure.
  * @retval None
  */
void CAN_Transmit(MDR_CAN_TypeDef* CANx, uint32_t BufferNumber, CAN_TxMsgTypeDef* TxMessage)
{
  uint32_t tmpreg;

  /* Check the parameters */
  assert_param(IS_CAN_ALL_PERIPH(CANx));
  assert_param(IS_CAN_BUFFER(BufferNumber));
  assert_param(IS_CAN_IDTYPE(TxMessage->IDE));
  assert_param(IS_CAN_DLC(TxMessage->DLC));
  assert_param(IS_FUNCTIONAL_STATE(TxMessage->PRIOR_0));
  assert_param(IS_CAN_ID(TxMessage->ID));

  /* Configure CAN_BUF_ID and CAN_BUF_DLC registers */
  /* Packet format */
  if (TxMessage->IDE == CAN_ID_STD)
  {
    /* Standard */
    tmpreg = CAN_BUF_DLC_STD + TxMessage->DLC;
  }
  else
  {
    /* Extended */
    tmpreg = CAN_BUF_DLC_EXT + TxMessage->DLC;
  }
  CANx->BUF[BufferNumber].DLC = tmpreg;
  CANx->BUF[BufferNumber].ID  = TxMessage->ID;

  /* Buffer data unit */
  CANx->BUF[BufferNumber].DATAL = TxMessage->Data[0];
  CANx->BUF[BufferNumber].DATAH = TxMessage->Data[1];

  /* Configure CAN_BUF_CON register */
  tmpreg = 0;
  /* Transmission priority */
  if (TxMessage->PRIOR_0 != DISABLE)
  {
    tmpreg |= CAN_BUF_CON_PRIOR_0;
  }
  /* Set transmission request bit */
  tmpreg |= CAN_BUF_CON_TX_REQ;
  /* Enable buffer */
  tmpreg |= CAN_BUF_CON_EN;

  CANx->BUF_CON[BufferNumber] = tmpreg;
}

/**
  * @brief  Initiates the Remote Transfer Request.
  * @param  CANx: Select the CAN peripheral.
  *         This parameter can be one of the following values:
  *         CAN1, CAN2.
  * @param  BufferNumber: the number of the buffer that is used for transmission.
  * @param  RTRMessage: pointer to a CAN_RTRMessageTypeDef structure.
  * @retval None
  */
void CAN_SendRTR(MDR_CAN_TypeDef* CANx, uint32_t BufferNumber, CAN_RTRMessageTypeDef* RTRMessage)
{
  uint32_t tmpreg;

  /* Check the parameters */
  assert_param(IS_CAN_ALL_PERIPH(CANx));
  assert_param(IS_CAN_BUFFER(BufferNumber));
  assert_param(IS_CAN_IDTYPE(RTRMessage->IDE));
  assert_param(IS_FUNCTIONAL_STATE(RTRMessage->PRIOR_0));
  assert_param(IS_CAN_ID(RTRMessage->ID));

  /* Configure CAN_BUF_ID and CAN_BUF_DLC registers */
  /* Packet format */
  if (RTRMessage->IDE == CAN_ID_STD)
  {
    /* Standard */
    tmpreg = CAN_BUF_DLC_STD;
  }
  else
  {
    /* Extended */
    tmpreg = CAN_BUF_DLC_EXT;
  }
  CANx->BUF[BufferNumber].DLC = tmpreg + CAN_RTR_REMOTE;
  CANx->BUF[BufferNumber].ID  = RTRMessage->ID;

  /* Configure CAN_BUF_CON register */
  tmpreg = 0;
  /* Transmission priority */
  if (RTRMessage->PRIOR_0 != DISABLE)
  {
    tmpreg |= CAN_BUF_CON_PRIOR_0;
  }
  /* Set transmission request bit */
  tmpreg |= CAN_BUF_CON_TX_REQ;
  /* Enable buffer */
  tmpreg |= CAN_BUF_CON_EN;

  CANx->BUF_CON[BufferNumber] = tmpreg;
}

/**
  * @brief  Initiates the Remote Transfer Request reply.
  * @param  CANx: Select the CAN peripheral.
  *         This parameter can be one of the following values:
  *         CAN1, CAN2.
  * @param  BufferNumber: the number of the buffer that is used for transmission.
  * @param  RTRReplyMessage: pointer to a CAN_RTRReplyTypeDef structure.
  * @retval None
  */

void CAN_RTRReply(MDR_CAN_TypeDef* CANx, uint32_t BufferNumber, CAN_RTRReplyTypeDef* RTRReplyMessage)
{
  uint32_t tmpreg;

  /* Check the parameters */
  assert_param(IS_CAN_ALL_PERIPH(CANx));
  assert_param(IS_CAN_BUFFER(BufferNumber));
  assert_param(IS_CAN_IDTYPE(RTRReplyMessage->IDE));
  assert_param(IS_CAN_ID(RTRReplyMessage->ID));
  assert_param(IS_CAN_DLC(RTRReplyMessage->DLC));

  /* Configure CAN_BUF_ID and CAN_BUF_DLC registers */
  /* Configure CAN_BUF_ID and CAN_BUF_DLC registers */
  /* Packet format */
  if (RTRReplyMessage->IDE == CAN_ID_STD)
  {
    /* Standard */
    tmpreg = CAN_BUF_DLC_STD + RTRReplyMessage->DLC;
  }
  else
  {
    /* Extended */
    tmpreg = CAN_BUF_DLC_EXT + RTRReplyMessage->DLC;
  }
  CANx->BUF[BufferNumber].DLC = tmpreg;
  CANx->BUF[BufferNumber].ID  = RTRReplyMessage->ID;

  /* Buffer data unit */
  CANx->BUF[BufferNumber].DATAL = RTRReplyMessage->Data[0];
  CANx->BUF[BufferNumber].DATAH = RTRReplyMessage->Data[1];

  /* Configure CAN_BUF_CON register */
  /* Set RTR_EN bit */
  tmpreg = CAN_STATUS_RTR_EN;
  /* Enable buffer */
  tmpreg |= CAN_BUF_CON_EN;

  CANx->BUF_CON[BufferNumber] = tmpreg;
}

/**
  * @brief  Starts the waiting for the receiving of a message.
  * @param  CANx: Select the CAN peripheral.
  *         This parameter can be one of the following values:
  *         CAN1, CAN2.
  * @param  BufferNumber: the number of the buffer that is used for reception.
  * @param  OverWrite: Enables or disables overwrite mode.
  *         This parameter can be one of the following values:
  *         ENABLE, DISABLE.
  * @retval None
  */
void CAN_Receive(MDR_CAN_TypeDef* CANx, uint32_t BufferNumber, FunctionalState OverWrite)
{
  uint32_t tmpreg = 0;

  /* Check the parameters */
  assert_param(IS_CAN_ALL_PERIPH(CANx));
  assert_param(IS_CAN_BUFFER(BufferNumber));
  assert_param(IS_FUNCTIONAL_STATE(OverWrite));

  /* Configure CAN_BUF_CON register */
  /* Overwrite mode */
  if (OverWrite != DISABLE)
  {
    tmpreg = CAN_BUF_CON_OVER_EN;
  }
  /* Configure buffer for receiving and enable it */
  tmpreg |= CAN_BUF_CON_RX_TXN | CAN_BUF_CON_EN;

  CANx->BUF_CON[BufferNumber] = tmpreg;
}

/**
  * @brief  Reads the received data from buffer.
  * @param  CANx: Select the CAN peripheral.
  *         This parameter can be one of the following values:
  *         CAN1, CAN2.
  * @param  BufferNumber: the number of the buffer that is used for reception.
  * @param  RxBuffer: CAN_DataTypeDef array to place received data to.
  * @retval None
  */
void CAN_GetReceivedData(MDR_CAN_TypeDef* CANx, uint32_t BufferNumber, CAN_DataTypeDef RxBuffer)
{
  /* Check the parameters */
  assert_param(IS_CAN_ALL_PERIPH(CANx));
  assert_param(IS_CAN_BUFFER(BufferNumber));

  RxBuffer[0] = CAN_ReadBufferSFR(&(CANx->BUF[BufferNumber].DATAL));
  RxBuffer[1] = CAN_ReadBufferSFR(&(CANx->BUF[BufferNumber].DATAH));
}

/**
  * @brief  Reads received message (containing both header and data) from buffer.
  * @param  CANx: Select the CAN peripheral.
  *         This parameter can be one of the following values:
  *         CAN1, CAN2.
  * @param  BufferNumber: the number of the buffer that is used for reception.
  * @param  RxMessage: pointer to a CAN_RxMsgTypeDef.
  * @retval None
  */
void CAN_GetRawReceivedData(MDR_CAN_TypeDef* CANx, uint32_t BufferNumber, CAN_RxMsgTypeDef* RxMessage)
{
  uint32_t tmpreg;

  /* Check the parameters */
  assert_param(IS_CAN_ALL_PERIPH(CANx));
  assert_param(IS_CAN_BUFFER(BufferNumber));

  /* Get the DLC */
  tmpreg = CAN_ReadBufferSFR(&(CANx->BUF[BufferNumber].DLC));

  RxMessage->Rx_Header.DLC = (uint8_t)(tmpreg & CAN_DLC_DATA_LENGTH);
  /* Get the IDE */
  RxMessage->Rx_Header.IDE = CAN_ID_STD;
  if ((tmpreg & CAN_DLC_IDE) != 0)
  {
    RxMessage->Rx_Header.IDE = CAN_ID_EXT;
  }
  /* Get the OVER_EN */
  RxMessage->Rx_Header.OVER_EN = DISABLE;
  tmpreg = CAN_ReadBufferSFR(&(CANx->BUF_CON[BufferNumber]));
  if ((tmpreg & CAN_BUF_CON_OVER_EN) != 0)
  {
    RxMessage->Rx_Header.OVER_EN = ENABLE;
  }
  /* Get the Id */
  RxMessage->Rx_Header.ID = CAN_ReadBufferSFR(&(CANx->BUF[BufferNumber].ID));

  /* Get the data field */
  RxMessage->Data[0] = CAN_ReadBufferSFR(&(CANx->BUF[BufferNumber].DATAL));
  RxMessage->Data[1] = CAN_ReadBufferSFR(&(CANx->BUF[BufferNumber].DATAH));
}

/**
  * @brief  Releases the buffer.
  * @param  CANx: Select the CAN peripheral.
  *         This parameter can be one of the following values:
  *         CAN1, CAN2.
  * @param  BufferNumber: the number of the buffer to be released.
  * @retval None.
  */
void CAN_BufferRelease(MDR_CAN_TypeDef* CANx, uint32_t BufferNumber)
{
  uint32_t tmpreg;

  /* Check the parameters */
  assert_param(IS_CAN_ALL_PERIPH(CANx));
  assert_param(IS_CAN_BUFFER(BufferNumber));

  tmpreg = CANx->BUF_CON[BufferNumber];
  tmpreg &= ~CAN_STATUS_EN;
  CANx->BUF_CON[BufferNumber] = tmpreg;
}

/**
  * @brief  Enables or disables the specified CAN peripheral.
  * @param  CANx: Select the CAN peripheral.
  *         This parameter can be one of the following values:
  *         CAN1, CAN2.
  * @param  NewState: new state of the CANx peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void CAN_Cmd(MDR_CAN_TypeDef* CANx, FunctionalState NewState)
{
  uint32_t tmpreg_CONTROL;

  /* Check the parameters */
  assert_param(IS_CAN_ALL_PERIPH(CANx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  tmpreg_CONTROL = CANx->CONTROL;

  /* Form new value */
  if (NewState != DISABLE)
  {
    /* Enable CANx by setting the CAN_EN bit in the CONTROL register */
    tmpreg_CONTROL |= CAN_CONTROL_CAN_EN;
  }
  else
  {
    /* Disable CANx by resetting the CAN_EN bit in the CONTROL register */
    tmpreg_CONTROL &= ~CAN_CONTROL_CAN_EN;
  }

  /* Configure CONTROL register with new value */
  CANx->CONTROL = tmpreg_CONTROL;
}

/**
  * @brief  Returns the CANx Status Register value.
  * @param  CANx: Select the CAN peripheral.
  *         This parameter can be one of the following values:
  *         CAN1, CAN2.
  * @retval The CANx_STATUS Register value.
  */
uint32_t CAN_GetStatus(MDR_CAN_TypeDef* CANx)
{
  /* Check the parameters */
  assert_param(IS_CAN_ALL_PERIPH(CANx));

  return CANx->STATUS;
}

/**
  * @brief  Returns the CANx_BUF_xx_CON Register value.
  * @param  CANx: Select the CAN peripheral.
  *         This parameter can be one of the following values:
  *         CAN1, CAN2.
  * @param  BufferNumber: The number of the buffer.
  * @retval The CANx_BUF_xx_CON Register value.
  */
uint32_t CAN_GetBufferStatus(MDR_CAN_TypeDef* CANx, uint32_t BufferNumber)
{
  /* Check the parameters */
  assert_param(IS_CAN_ALL_PERIPH(CANx));
  assert_param(IS_CAN_BUFFER(BufferNumber));

  return CANx->BUF_CON[BufferNumber];
}

/**
  * @brief  Checks whether the specified CAN interrupt enable or disable.
  * @param  CANx: Select the CAN peripheral.
  *         This parameter can be one of the following values:
  *         CAN1, CAN2.
  * @param  CAN_IT: specifies the CAN interrupt sources to be enabled or disabled.
  *         This parameter can be: CAN_IT_GLBINTEN, CAN_IT_RXINTEN, CAN_IT_TXINTEN,
  *         CAN_IT_ERRINTEN or CAN_IT_ERROVERINTEN.
  * @retval The state of CAN_IT (SET or RESET).
  */
ITStatus CAN_GetITState(MDR_CAN_TypeDef* CANx, uint32_t CAN_IT)
{
  ITStatus bitstatus;

  /* Check the parameters */
  assert_param(IS_CAN_ALL_PERIPH(CANx));
  assert_param(IS_CAN_ITConfig(CAN_IT));

  if ((CANx->INT_EN & CAN_IT) == 0)
  {
    bitstatus = RESET;
  }
  else
  {
    bitstatus = SET;
  }

  return bitstatus;
}

/**
  * @brief  Clears the CANx interrupt errors pending bits.
  * @param  CANx: Select the CAN peripheral.
  *         This parameter can be any combination of the following values:
  *         CAN1, CAN2.
  * @param  Status_Flag: specifies the interrupt pending bit to clear.
  *         This parameter can be one of the following values:
            CAN_STATUS_ERROR_OVER:    Flag indicating that TEC or REC exceeds ERROR_MAX value
            CAN_STATUS_BIT_ERR:       Transmitting frame bits error flag
            CAN_STATUS_BIT_STUFF_ERR: Staff frame bits error flag
            CAN_STATUS_CRC_ERR:       Frame CRC error flag
            CAN_STATUS_FRAME_ERR:     Frame format error flag
            CAN_STATUS_ACK_ERR:       Reception acknowledge error flag
  * @retval None.
  */
void CAN_ITClearErrorPendingBit(MDR_CAN_TypeDef* CANx, uint32_t Status_Flag)
{
  /* Check the parameters */
  assert_param(IS_CAN_ALL_PERIPH(CANx));
  assert_param(IS_CAN_IT_ERROR_FLAG(Status_Flag));

  CANx->STATUS &= ~Status_Flag;
}

/**
  * @brief  Enables or disables interrupts from the reception buffers.
  * @param  CANx: Select the CAN peripheral.
  *         This parameter can be one of the following values:
  *         CAN1, CAN2.
  * @param  Buffer_IT: specifies the reception buffers to enable or disable interrupts of.
  *         Each buffer is designated by bit number in the mask. See @CAN_Buffer_Interrupts
  *         group.
  * @param  NewState: new state of the reception buffer interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void CAN_RxITConfig(MDR_CAN_TypeDef* CANx, uint32_t Buffer_IT, FunctionalState NewState)
{
  uint32_t tmpreg;

  /* Check the parameters */
  assert_param(IS_CAN_ALL_PERIPH(CANx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  tmpreg = CANx->INT_RX;

  if (NewState != DISABLE)
  {
    tmpreg |= Buffer_IT;
  }
  else
  {
    tmpreg &= ~Buffer_IT;
  }

  CANx->INT_RX = tmpreg;
}

/**
  * @brief  Checks whether the specified reception buffer interrupt has occurred or not.
  * @param  CANx: Select the CAN peripheral.
  *         This parameter can be one of the following values:
  *         CAN1, CAN2.
  * @param  BufferNumber: The number of the buffer
  * @retval The new state of RX_FULL[BufferNumber] flag (SET or RESET).
  */
ITStatus CAN_GetRxITStatus(MDR_CAN_TypeDef* CANx, uint32_t BufferNumber)
{
  FlagStatus bitstatus;

  /* Check the parameters */
  assert_param(IS_CAN_ALL_PERIPH(CANx));
  assert_param(IS_CAN_BUFFER(BufferNumber));

  if ((CANx->RX & CANx->INT_RX & (((uint32_t)0x1) << BufferNumber)) == 0)
  {
    bitstatus = RESET;
  }
  else
  {
    bitstatus = SET;
  }

  return bitstatus;
}

/**
  * @brief  Returns the CANx_Rx Register value.
  * @param  CANx: Select the CAN peripheral.
  *         This parameter can be one of the following values:
  *         CAN1, CAN2.
  * @retval The CANx_Rx Register value.
  */
uint32_t CAN_GetRx(MDR_CAN_TypeDef* CANx)
{
  /* Check the parameters */
  assert_param(IS_CAN_ALL_PERIPH(CANx));

  return CANx->RX;
}

/**
  * @brief  Enables or disables interrupts from the transmission buffers.
  * @param  CANx: Select the CAN peripheral.
  *         This parameter can be one of the following values:
  *         CAN1, CAN2.
  * @param  Buffer_IT: specifies the transmission buffers to enable or disable interrupts of.
  *         Each buffer is designated by bit number in the mask. See @CAN_Buffer_Interrupts
  *         group.
  * @param  NewState: new state of the reception buffer interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void CAN_TxITConfig(MDR_CAN_TypeDef* CANx, uint32_t Buffer_IT, FunctionalState NewState)
{
  uint32_t tmpreg;

  /* Check the parameters */
  assert_param(IS_CAN_ALL_PERIPH(CANx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  tmpreg = CANx->INT_TX;

  if (NewState != DISABLE)
  {
    tmpreg |= Buffer_IT;
  }
  else
  {
    tmpreg &= ~Buffer_IT;
  }

  CANx->INT_TX = tmpreg;
}

/**
  * @brief  Checks whether the specified transmission buffer interrupt has occurred or not.
  * @param  CANx: Select the CAN peripheral.
  *         This parameter can be one of the following values:
  *         CAN1, CAN2.
  * @param  BufferNumber: The number of the buffer
  * @retval The new state of ~TX_REQ[BufferNumber] flag (SET or RESET).
  */
ITStatus CAN_GetTxITStatus(MDR_CAN_TypeDef* CANx, uint32_t BufferNumber)
{
  FlagStatus bitstatus;

  /* Check the parameters */
  assert_param(IS_CAN_ALL_PERIPH(CANx));
  assert_param(IS_CAN_BUFFER(BufferNumber));

  if ((CANx->TX & CANx->INT_TX & (((uint32_t)0x1) << BufferNumber)) == 0)
  {
    bitstatus = RESET;
  }
  else
  {
    bitstatus = SET;
  }

  return bitstatus;
}

/**
  * @brief  Clears the CANx transmission or reception buffer interrupt
  *         pending bits.
  * @param  CANx: Select the CAN peripheral.
  *         This parameter can be one of the following values:
  *         CAN1, CAN2.
  * @param  BufferNumber: The number of the buffer
  * @param  Status_Flag: specifies the interrupt pending bit to clear.
  *         This parameter can be of the following values:
            CAN_STATUS_RX_READY:    Flag indicating that there are messages received
            CAN_STATUS_TX_READY:    Flag indicating that there are buffers for transmitting
  * @retval None.
  */
void CAN_ITClearRxTxPendingBit(MDR_CAN_TypeDef* CANx, uint32_t BufferNumber, uint32_t Status_Flag)
{
  uint32_t tmpreg;

  /* Check the parameters */
  assert_param(IS_CAN_ALL_PERIPH(CANx));
  assert_param(IS_CAN_BUFFER(BufferNumber));
  assert_param(IS_CAN_IT_RXTX_FLAG(Status_Flag));

  tmpreg = CANx->BUF_CON[BufferNumber];

  if (Status_Flag == CAN_STATUS_RX_READY)
  {
    tmpreg &= ~CAN_STATUS_RX_FULL;
  }
  else if (Status_Flag == CAN_STATUS_TX_READY)
  {
    tmpreg |= CAN_STATUS_TX_REQ;
  }

  CANx->BUF_CON[BufferNumber] = tmpreg;
}

/**
  * @brief  Initializes the UARTx peripheral Clock according to the
  *         specified parameters.
  * @param  UARTx: Select the UART peripheral.
  *         This parameter can be one of the following values:
  *         UART0.
  * @param  UART_BRG: specifies the HCLK division factor.
  *         This parameter can be one of the following values:
  *           @arg UART_CLKdiv1
  *           @arg UART_CLKdiv2
  *           @arg UART_CLKdiv4
  *           @arg UART_CLKdiv8
  * @retval None
  */
void CAN_CLK_en(uint32_t CAN_CLK_DIV)
{
  uint32_t tmpreg;
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
	assert_param(IS_UART_CLKSRC(UART_CLKSRC));

  tmpreg = CLK_CNTR->CAN0_CLK;

  tmpreg |=  CAN_CLK_EN;
  tmpreg &= ~CAN_DIV_Msk;
  tmpreg |=  CAN_CLK_DIV;

  CLK_CNTR->CAN0_CLK = tmpreg;
}

/**
  * @brief  Service function for some SFRs reading
  *         supporting MDR32F9Qx Series Errata Notice,
  *         Error 0002 workaround.
  * @param  SFR: specifies SFR address
  * @retval SFR value
  * @note   If WORKAROUND_MDR32F9QX_ERROR_0002 is defined
  *         the function performs corrective actions (IMPORTANT:
  *         after SFR reading it enables IRQs in this mode),
  *         otherwise, just reads SFR.
  */
static __INLINE uint32_t CAN_ReadBufferSFR(__IO uint32_t* SFR)
{
#ifdef WORKAROUND_MDR32F9QX_ERROR_0002
  /*
   * MDR32F9Qx Series Errata Notice, Error 0002:
   * The registers CAN_BUFxx_ID, CAN_BUFxx_DLC, CAN_BUFxx_DATAL,
   * CAN_BUFxx_DATAH, CAN_BUFxx_MASK or CAN_BUFxx_FILTER value
   * may be incorrectly read as 0 if CAN controller accessed any
   * of that registers at the moment of reading.
   * In such case, another read should be performed in a time less
   * than minimum CAN package.
   */
  uint32_t tmpreg;

  __disable_irq();
  tmpreg = *SFR;
  if (tmpreg == 0)
  {
    tmpreg = *SFR;
  }
  __enable_irq();
  return tmpreg;
#else
  return *SFR;
#endif  /* WORKAROUND_MDR32F9QX_ERROR_0002 */
}

/** @} */ /* End of group CAN_Private_Functions */

/** @} */ /* End of group CAN */

/** @} */ /* End of group __MDR32F8_StdPeriph_Driver */

/******************* (C) COPYRIGHT 2015 Milandr *********************************
*
* END OF FILE mdr32f8_can.c */


