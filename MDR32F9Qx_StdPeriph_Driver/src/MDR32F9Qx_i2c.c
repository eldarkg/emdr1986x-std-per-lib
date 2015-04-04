/**
  ******************************************************************************
  * @file    MDR32F9Qx_i2c.c
  * @author  Phyton Application Team
  * @version V1.3.0
  * @date    22/02/2011
  * @brief   This file provides all the I2C firmware functions.
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
  * <h2><center>&copy; COPYRIGHT 2010 Phyton</center></h2>
  ******************************************************************************
  * FILE MDR32F9Qx_i2c.c
  */

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_i2c.h"
#include "MDR32F9Qx_config.h"

#define ASSERT_INFO_FILE_ID FILEID__MDR32F9X_I2C_C

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @defgroup I2C I2C
  * @warning  This module can be used only for microcontroller series MDR1986VE9x.
  * @{
  */

#if defined (USE_MDR1986VE9x)

/** @defgroup I2C_Private_Functions I2C Private Functions
  * @{
  */

/**
  * @brief  Resets the I2C peripheral registers to their default reset values.
  * @param  None.
  * @retval None.
  */
void I2C_DeInit(void)
{
  MDR_I2C_TypeDef *I2Cx;

  I2Cx = MDR_I2C;

  I2Cx->CTR = 0;
  I2Cx->STA = 0;
  I2Cx->CMD = I2C_CMD_CLRINT;
  I2Cx->PRL = 0;
  I2Cx->PRH = 0;
}

/**
  * @brief  Initializes the I2C peripheral according to the specified
  *         parameters in the I2C_InitStruct.
  * @param  I2C_InitStruct: pointer to a I2C_InitTypeDef structure that
  *         contains the configuration information for the specified I2C peripheral.
  * @retval None.
  */
void I2C_Init(const I2C_InitTypeDef* I2C_InitStruct)
{
  MDR_I2C_TypeDef *I2Cx;
  uint32_t tmpreg_CTR;
  uint32_t tmpreg_PR;

  /* Check the parameters */
  assert_param(IS_I2C_SPEED(I2C_InitStruct->I2C_Speed));
  assert_param(IS_I2C_CLKDIV(I2C_InitStruct->I2C_ClkDiv));

  I2Cx = MDR_I2C;

  /* Form new values */
  tmpreg_CTR = I2Cx->CTR;

  if ((I2C_InitStruct->I2C_Speed & I2C_SPEED_Msk) != I2C_SPEED_UP_TO_400KHz)
  {
    tmpreg_CTR |= I2C_CTR_S_I2C;
  }
  else
  {
    tmpreg_CTR &= ~I2C_CTR_S_I2C;
  }

  /* Configure I2C registers with new values */
  I2Cx->CTR = tmpreg_CTR;

  tmpreg_PR = I2C_InitStruct->I2C_ClkDiv;
  I2Cx->PRL = tmpreg_PR;
  I2Cx->PRH = tmpreg_PR >> 8;
}

/**
  * @brief  Fills each I2C_InitStruct member with its default value.
  * @param  I2C_InitStruct: pointer to a I2C_InitTypeDef structure which will
  *         be initialized.
  * @retval None.
  */
void I2C_StructInit(I2C_InitTypeDef* I2C_InitStruct)
{
  /* Reset I2C initialization structure parameters values */
  I2C_InitStruct->I2C_Speed  = I2C_SPEED_UP_TO_400KHz;
  I2C_InitStruct->I2C_ClkDiv = 1;
}

/**
  * @brief  Enables or disables the I2C peripheral.
  * @param  NewState: new state of the I2C peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void I2C_Cmd(FunctionalState NewState)
{
  MDR_I2C_TypeDef *I2Cx;
  uint32_t tmpreg_CTR;

  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  I2Cx = MDR_I2C;

  tmpreg_CTR = I2Cx->CTR;

  /* Form new value */
  if (NewState != DISABLE)
  {
    /* Enable I2C by setting the EN_I2C bit in the CTR register */
    tmpreg_CTR |= I2C_CTR_EN_I2C;
  }
  else
  {
    /* Disable I2C by resetting the EN_I2C bit in the CTR register */
    tmpreg_CTR &= ~I2C_CTR_EN_I2C;
  }

  /* Configure CTR register with new value */
  I2Cx->CTR = tmpreg_CTR;
}

/**
  * @brief  Enables or disables the I2C interrupts.
  * @param  NewState: new state of the I2C interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void I2C_ITConfig(FunctionalState NewState)
{
  MDR_I2C_TypeDef *I2Cx;
  uint32_t tmpreg_CTR;

  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  I2Cx = MDR_I2C;

  tmpreg_CTR = I2Cx->CTR;

  /* Form new value */
  if (NewState != DISABLE)
  {
    /* Enable the I2C interrupts by setting the EN_INT bit in the CTR register */
    tmpreg_CTR |= I2C_CTR_EN_INT;
  }
  else
  {
    /* Disable the I2C interrupts by resetting the EN_INT bit in the CTR register */
    tmpreg_CTR &= ~I2C_CTR_EN_INT;
  }

  /* Configure CTR register with new value */
  I2Cx->CTR = tmpreg_CTR;
}

/**
  * @brief  Checks whether the I2C interrupt has occurred or not.
  * @param  None.
  * @retval The current state of I2C_STA_INT (SET or RESET).
  */
ITStatus I2C_GetITStatus(void)
{
  MDR_I2C_TypeDef *I2Cx;
  ITStatus bitstatus;

  I2Cx = MDR_I2C;

  if ((I2Cx->STA & I2C_STA_INT) == I2C_STA_INT)
  {
    bitstatus = SET;
  }
  else
  {
    bitstatus = RESET;
  }

  return bitstatus;
}

/**
  * @brief  Clears the I2C_STA_INT interrupt pending bit.
  * @param  None.
  * @retval None.
  */
void I2C_ClearITPendingBit(void)
{
  MDR_I2C_TypeDef *I2Cx;

  I2Cx = MDR_I2C;

  I2Cx->CMD |= I2C_CMD_CLRINT;
}

/**
  * @brief  Transmits the address byte to select the Slave device.
  * @param  Address: specifies the Slave address which will be transmitted.
  *         The Address[0] bit value is ignored. So only Address[7..1] bits
  *         are the seven-bit Slave address.
  * @param  Direction: specifies whether the I2C device will be a
  *         Transmitter or a Receiver. This parameter can be one of the
  *         following values:
  *           @arg I2C_Direction_Transmitter: Transmitter mode;
  *           @arg I2C_Direction_Receiver:    Receiver mode.
  * @retval None.
  */
void I2C_Send7bitAddress(uint8_t Address, uint32_t Direction)
{
  MDR_I2C_TypeDef *I2Cx;

  assert_param(IS_I2C_DIRECTION(Direction));

  I2Cx = MDR_I2C;

  I2Cx->TXD = (Address & ~I2C_Direction_Msk) | Direction;
  I2Cx->CMD = I2C_CMD_START | I2C_CMD_WR;
}

/**
  * @brief  Sends a byte through the I2C peripheral.
  * @param  ByteToSend: Byte to be transmitted.
  * @retval None.
  */
void I2C_SendByte(uint8_t ByteToSend)
{
  MDR_I2C_TypeDef *I2Cx;

  I2Cx = MDR_I2C;

  I2Cx->TXD = ByteToSend;
  I2Cx->CMD = I2C_CMD_WR;
}

/**
  * @brief  Generates I2C communication STOP condition.
  * @param  None.
  * @retval None.
  */
void I2C_SendSTOP(void)
{
  MDR_I2C_TypeDef *I2Cx;

  I2Cx = MDR_I2C;

  I2Cx->CMD = I2C_CMD_STOP;
}

/**
  * @brief  Starts data receiving from Slave.
  * @param  Acknowlage: specifies the acknowlage state at end
  *         of data receiving. This parameter can be one of the
  *         following values:
  *           @arg I2C_Send_to_Slave_ACK:  Acknowlage (ACK);
  *           @arg I2C_Send_to_Slave_NACK: Not Acknowlage (NACK).
  * @retval None.
  */
void I2C_StartReceiveData(uint32_t Acknowlage)
{
  MDR_I2C_TypeDef *I2Cx;

  assert_param(IS_I2C_SEND_ACKNOWLAGE(Acknowlage));

  I2Cx = MDR_I2C;

  I2Cx->CMD = I2C_CMD_RD | Acknowlage;
}

/**
  * @brief  Returns received from Slave data byte.
  * @param  None.
  * @retval Received from data byte.
  */
uint8_t I2C_GetReceivedData(void)
{
  MDR_I2C_TypeDef *I2Cx;

  I2Cx = MDR_I2C;

  return I2Cx->RXD;
}

/**
  * @brief  Checks whether the last I2C Event is equal to the one passed
  *         as parameter.
  * @param  Event: specifies the event to be checked.
  *         This parameter can be one of the values discribed in
  *         @ref I2C_EVENTS or user specified combination of flags
  *         (@ref I2C_FLAGS).
  *
  * @note:  For detailed description of Events, please refer to section
  *         @ref I2C_EVENTS in MDR32F9Qx_i2c.h file.
  *
  * @retval An ErrorStatus enumuration value:
  *         - SUCCESS: Last event is equal to the Event;
  *         - ERROR: Last event is different from the Event.
  */
ErrorStatus I2C_CheckEvent(uint32_t Event)
{
  ErrorStatus errstatus;

  assert_param(IS_I2C_FLAGS(Event));

  if ((I2C_GetLastEvent() & Event) == Event)
  {
    errstatus = SUCCESS;
  }
  else
  {
    errstatus = ERROR;
  }

  return errstatus;
}

/**
  * @brief  Returns the last I2C Event.
  * @param  None.
  * @retval The last event
 *
  * @note:  For detailed description of Events, please refer to section
  *         @ref I2C_EVENTS in MDR32F9Qx_i2c.h file.
  */
uint32_t I2C_GetLastEvent(void)
{
  MDR_I2C_TypeDef *I2Cx;
  uint32_t event;

  I2Cx = MDR_I2C;

  event = I2Cx->CMD | (I2Cx->STA << 8);
  event |= ~event << 16;

  return event;
}

/**
  * @brief  Checks whether the specified I2C flag is set or not.
  * @param  Flag: specifies the flag to check.
  *         This parameter can be one of the values:
  *           @arg I2C_FLAG_CMD_NACK           Master will be send NACK after reading from Slave;
  *           @arg I2C_FLAG_CMD_ACK            Master will be send ACK after reading from Slave;
  *           @arg I2C_FLAG_CMD_WR             The Master to Slave transfer in progress;
  *           @arg I2C_FLAG_CMD_nWR            No the Master to Slave transfer;
  *           @arg I2C_FLAG_CMD_RD             The Slave to Master transfer in progress;
  *           @arg I2C_FLAG_CMD_nRD            No the Slave to Master transfer;
  *           @arg I2C_FLAG_STOP               STOP condition transfer is selected;
  *           @arg I2C_FLAG_nSTOP              STOP condition is resetted;
  *           @arg I2C_FLAG_START              START condition transfer is selected;
  *           @arg I2C_FLAG_nSTART             START condition is resetted;
  *           @arg I2C_FLAG_IRQ                The I2C interrupt pending flag is set;
  *           @arg I2C_FLAG_nIRQ               The I2C interrupt pending flag is cleared;
  *           @arg I2C_FLAG_TRANS              transfer in progress;
  *           @arg I2C_FLAG_nTRANS             No transfer;
  *           @arg I2C_FLAG_LOST_ARB           Arbitration is lost at last byte transfer;
  *           @arg I2C_FLAG_ARB_OK             Arbitration is Ok at last byte transfer;
  *           @arg I2C_FLAG_BUS_BUSY           Some device holds the I2C bus;
  *           @arg I2C_FLAG_BUS_FREE           I2C bus is free (SDA = SCL = 1);
  *           @arg I2C_FLAG_SLAVE_NACK         Not Acknowledge (NACK) received from Slave;
  *           @arg I2C_FLAG_SLAVE_ACK          Acknowledge (ACK) received from Slave.
  * @retval The new state of I2C_FLAG (SET or RESET).
  */
FlagStatus I2C_GetFlagStatus(uint32_t Flag)
{
  FlagStatus bitstatus;

  assert_param(IS_I2C_FLAG(Flag));

  if ((I2C_GetLastEvent() & Flag) != 0)
  {
    bitstatus = SET;
  }
  else
  {
    bitstatus = RESET;
  }

  return bitstatus;
}

/** @} */ /* End of group I2C_Private_Functions */

#endif /* #if defined (USE_MDR1986VE9x) */

/** @} */ /* End of group I2C */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

/******************* (C) COPYRIGHT 2010 Phyton *********************************
*
* END OF FILE MDR32F9Qx_i2c.c */

