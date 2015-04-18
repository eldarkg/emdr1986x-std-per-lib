/**
  ******************************************************************************
  * @file    MDR32F9Qx_i2c.h
  * @author  Phyton Application Team
  * @version V1.4.0
  * @date    16/02/2011
  * @brief   This file contains all the functions prototypes for the I2C
  *          firmware library.
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
  * FILE MDR32F9Qx_i2c.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MDR32F9QX_I2C_H
#define __MDR32F9QX_I2C_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_config.h"
#include "MDR32F9Qx_lib.h"

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @addtogroup I2C
  * @{
  */

/** @defgroup I2C_Exported_Types I2C Exported Types
  * @{
  */

/**
  * @brief  I2C Init structure definition
  */

typedef struct
{
  uint32_t I2C_ClkDiv;      /*!< Specifies the I2C peripheral clock devider value.
                               This parameter can be a value of @ref I2C_CLKDIV. */
  uint32_t I2C_Speed;       /*!< Specifies I2C speed limit.
                               This parameter can be a value of @ref I2C_SPEED. */
}I2C_InitTypeDef;

/** @} */ /* End of group I2C_Exported_Types */

/** @defgroup I2C_Exported_Constants I2C Exported Constants
  * @{
  */

/** @defgroup I2C_CLKDIV I2C clock devider
  * @{
  */

#define IS_I2C_CLKDIV(CLKDIV) ((CLKDIV >> 16) == 0)

/** @} */ /* End of group I2C_CLKDIV */

/** @defgroup I2C_SPEED I2C speed definition
  * @{
  */

#define I2C_SPEED_UP_TO_400KHz      (((uint32_t)0x0) << 5)             /*!< I2C speed is up to 400 KHz. */
#define I2C_SPEED_UP_TO_1MHz        (((uint32_t)0x1) << 5)             /*!< I2C speed is up to 1 MHz. */

#define I2C_SPEED_Msk               (((uint32_t)0x1) << 5)

#define IS_I2C_SPEED(SPEED) (((SPEED) == I2C_SPEED_UP_TO_400KHz) || ((SPEED) == I2C_SPEED_UP_TO_1MHz))

/** @} */ /* End of group I2C_SPEED */

/** @defgroup I2C_TRANSFER_DIRECTION I2C transfer direction
  * @{
  */

#define I2C_Direction_Transmitter   ((uint32_t)0x0)
#define I2C_Direction_Receiver      ((uint32_t)0x1)

#define I2C_Direction_Msk           ((uint32_t)0x1)

#define IS_I2C_DIRECTION(DIRECTION) (((DIRECTION) == I2C_Direction_Transmitter) || \
                                     ((DIRECTION) == I2C_Direction_Receiver))

/** @} */ /* End of group I2C_TRANSFER_DIRECTION */

/** @defgroup I2C_M2S_ACKNOWLAGE I2C Master to Slave acknowlage
  * @{
  */

#define I2C_Send_to_Slave_ACK       (((uint32_t)0x0) << I2C_CMD_ACK_Pos)
#define I2C_Send_to_Slave_NACK      (((uint32_t)0x1) << I2C_CMD_ACK_Pos)

#define IS_I2C_SEND_ACKNOWLAGE(ACKNOWLAGE) (((ACKNOWLAGE) == I2C_Send_to_Slave_ACK) || \
                                            ((ACKNOWLAGE) == I2C_Send_to_Slave_NACK))

/** @} */ /* End of group I2C_M2S_ACKNOWLAGE */

/** @defgroup I2C_FLAGS I2C status flags definition
  * @{
  */

/**
  * @brief  Flags based on I2C_CMD register
  *
  * This flags are the copies of corresponding I2C_CMD register bits.
  *
  */

#define I2C_FLAG_CMD_NACK           (I2C_CMD_ACK   <<  0)              /*!< Master will be send NACK after reading
                                                                            from Slave. */
#define I2C_FLAG_CMD_WR             (I2C_CMD_WR    <<  0)              /*!< The Master to Slave transfer in progress. */
#define I2C_FLAG_CMD_RD             (I2C_CMD_RD    <<  0)              /*!< The Slave to Master transfer in progress. */
#define I2C_FLAG_STOP               (I2C_CMD_STOP  <<  0)              /*!< The STOP condition transfer is selected. */
#define I2C_FLAG_START              (I2C_CMD_START <<  0)              /*!< The START condition transfer is selected. */

/**
  * @brief  Flags based on I2C_STA register
  *
  * This flags are the copies of corresponding I2C_STA register bits.
  *
  */

#define I2C_FLAG_IRQ                (I2C_STA_INT      <<  8)           /*!< The I2C interrupt pending flag is set. */
#define I2C_FLAG_TRANS              (I2C_STA_TR_PROG  <<  8)           /*!< Transfer in progress. */
#define I2C_FLAG_LOST_ARB           (I2C_STA_LOST_ARB <<  8)           /*!< Arbitration is lost at last byte transfer. */
#define I2C_FLAG_BUS_BUSY           (I2C_STA_BUSY     <<  8)           /*!< Some device holds the I2C bus. */
#define I2C_FLAG_SLAVE_NACK         (I2C_STA_RX_ACK   <<  8)           /*!< Not Acknowledge (NACK) received from Slave. */

/**
  * @brief  Software flags
  *
  * This flags are calculated by I2C driver.
  *
  */

#define I2C_FLAG_CMD_ACK            (I2C_FLAG_CMD_NACK      << 16)     /*!< Master will be send ACK after reading from Slave
                                                                            (inversion of the I2C_FLAG_CMD_NACK flag). */
#define I2C_FLAG_CMD_nWR            (I2C_FLAG_CMD_WR        << 16)     /*!< No the Master to Slave transfer
                                                                            (inversion of the I2C_FLAG_CMD_WR flag). */
#define I2C_FLAG_CMD_nRD            (I2C_FLAG_CMD_RD        << 16)     /*!< No the Slave to Master transfer
                                                                            (inversion of the I2C_FLAG_CMD_RD). */
#define I2C_FLAG_nSTOP              (I2C_FLAG_STOP          << 16)     /*!< STOP condition is resetted
                                                                            (inversion of the I2C_FLAG_STOP flag). */
#define I2C_FLAG_nSTART             (I2C_FLAG_START         << 16)     /*!< START condition is resetted
                                                                            (inversion of the I2C_FLAG_START flag). */
#define I2C_FLAG_nIRQ               (I2C_FLAG_IRQ           << 16)     /*!< The I2C interrupt pending flag is cleared
                                                                            (inversion of the I2C_FLAG_IRQ flag). */
#define I2C_FLAG_nTRANS             (I2C_FLAG_TRANS         << 16)     /*!< No transfer
                                                                            (inversion of the I2C_FLAG_TRANS flag). */
#define I2C_FLAG_ARB_OK             (I2C_FLAG_LOST_ARB      << 16)     /*!< Arbitration is OK
                                                                            (inversion of the I2C_FLAG_LOST_ARB flag). */
#define I2C_FLAG_BUS_FREE           (I2C_FLAG_BUS_BUSY      << 16)     /*!< I2C bus is free (SDA = SCL = 1)
                                                                            (inversion of the I2C_FLAG_BUS_BUSY flag). */
#define I2C_FLAG_SLAVE_ACK          (I2C_FLAG_SLAVE_NACK    << 16)     /*!< Acknowledge (ACK) received from Slave
                                                                            (inversion of the I2C_FLAG_SLAVE_NACK flag). */

#define IS_I2C_FLAG(FLAG) (((FLAG) == I2C_FLAG_CMD_NACK  ) || \
                           ((FLAG) == I2C_FLAG_CMD_WR    ) || \
                           ((FLAG) == I2C_FLAG_CMD_RD    ) || \
                           ((FLAG) == I2C_FLAG_STOP      ) || \
                           ((FLAG) == I2C_FLAG_START     ) || \
                           ((FLAG) == I2C_FLAG_IRQ       ) || \
                           ((FLAG) == I2C_FLAG_TRANS     ) || \
                           ((FLAG) == I2C_FLAG_LOST_ARB  ) || \
                           ((FLAG) == I2C_FLAG_BUS_BUSY  ) || \
                           ((FLAG) == I2C_FLAG_SLAVE_NACK) || \
                           ((FLAG) == I2C_FLAG_CMD_nWR   ) || \
                           ((FLAG) == I2C_FLAG_CMD_nRD   ) || \
                           ((FLAG) == I2C_FLAG_CMD_ACK   ) || \
                           ((FLAG) == I2C_FLAG_nSTOP     ) || \
                           ((FLAG) == I2C_FLAG_nSTART    ) || \
                           ((FLAG) == I2C_FLAG_nIRQ      ) || \
                           ((FLAG) == I2C_FLAG_nTRANS    ) || \
                           ((FLAG) == I2C_FLAG_ARB_OK    ) || \
                           ((FLAG) == I2C_FLAG_BUS_FREE  ) || \
                           ((FLAG) == I2C_FLAG_SLAVE_ACK ))

#define I2C_FLAGS_Msk               (I2C_FLAG_CMD_NACK   | \
                                     I2C_FLAG_CMD_WR     | \
                                     I2C_FLAG_CMD_RD     | \
                                     I2C_FLAG_STOP       | \
                                     I2C_FLAG_START      | \
                                     I2C_FLAG_IRQ        | \
                                     I2C_FLAG_TRANS      | \
                                     I2C_FLAG_LOST_ARB   | \
                                     I2C_FLAG_BUS_BUSY   | \
                                     I2C_FLAG_SLAVE_NACK | \
                                     I2C_FLAG_CMD_nWR    | \
                                     I2C_FLAG_CMD_nRD    | \
                                     I2C_FLAG_CMD_ACK    | \
                                     I2C_FLAG_nSTOP      | \
                                     I2C_FLAG_nSTART     | \
                                     I2C_FLAG_nIRQ       | \
                                     I2C_FLAG_nTRANS     | \
                                     I2C_FLAG_ARB_OK     | \
                                     I2C_FLAG_BUS_FREE   | \
                                     I2C_FLAG_SLAVE_ACK  )

#define IS_I2C_FLAGS(FLAGS) (((FLAGS) & I2C_FLAGS_Msk) == (FLAGS))

/** @} */ /* End of group I2C_FLAGS */

/** @defgroup I2C_EVENTS I2C Events definition
  * @{
  */

/**
  * @brief  Communication start condition
  *
  * Before sending the START condition and Slave address the Master has to wait for the
  * I2C_EVENT_BUS_FREE event. It means that the I2C bus has not been held by other master
  * (the bus is free, no other devices are communicating).
  *
  */

#define I2C_EVENT_BUS_FREE                          (I2C_FLAG_BUS_FREE | I2C_FLAG_nSTOP)

/**
  * @brief  Communication start
  *
  * At communication start Master sends:
  *   1) the START condition;
  *   2) Slave address (full address in 7-bit address mode or header in 10-bit address mode);
  *   3) the bit that specify direction of the data comunication (Master to Slave - Transmitter;
  *      Slave to Master - Receiver).
  * The I2C_Send7bitAddress() function executes all of these start communication stages.
  * The following events are set when communication starts:
  *
  *  - I2C_EVENT_BUS_HELD - if this Master holds I2C bus;
  *
  *  - I2C_EVENT_TRANSFER_IN_PROGRESS - if this Master sends the START condition or Slave address;
  *
  */

#define I2C_EVENT_BUS_HELD                          (I2C_FLAG_BUS_BUSY | I2C_FLAG_ARB_OK)
#define I2C_EVENT_TRANSFER_IN_PROGRESS              (I2C_EVENT_BUS_HELD | I2C_FLAG_TRANS)

/**
  * @brief  Address Acknowledge
  *
  * Then the Master has to wait an address acknowledge from Slave.
  *
  * The event I2C_EVENT_TRANSFER_ENABLED if Master transfers the START condition and 7-bit
  * Slave address completely.
  *
  * The I2C_EVENT_ACK_FOUND event will be set if Slave sends the Acknowledge to the bus.
  * - In case of 7-bit addressing mode Master can start data exchange wih Slave
  *   (I2C_SendByte() or I2C_StartReceiveData() functions).
  * - In case of 10-bit addressing mode Master sends second byte of the Slave address
  *   (I2C_SendByte() function) as Data byte.
  *
  * The I2C_EVENT_NACK_FOUND event will be set if Slave sends the Not Acknowledge to the bus.
  * Then Master has to send STOP condition to the bus (I2C_SendSTOP() function).
  *
  * The I2C_EVENT_LOST_ARB_FOUND event will be set if Master loses Arbitration.
  * Then Master has to restart communication when the I2C_EVENT_BUS_FREE event is set.
  *
  */

#define I2C_EVENT_TRANSFER_ENABLED                  (I2C_EVENT_BUS_HELD | I2C_FLAG_nTRANS | I2C_FLAG_CMD_nWR | I2C_FLAG_CMD_nRD)
#define I2C_EVENT_ACK_FOUND                         (I2C_EVENT_TRANSFER_ENABLED | I2C_FLAG_SLAVE_ACK)
#define I2C_EVENT_NACK_FOUND                        (I2C_EVENT_TRANSFER_ENABLED | I2C_FLAG_SLAVE_NACK)
#define I2C_EVENT_LOST_ARB_FOUND                    (I2C_FLAG_LOST_ARB)

/**
  * @brief Communication events
  *
  * If communication is established (START condition is generated and Slave address
  * is acknowledged) then the Master has to check one of the following events for
  * communication procedures:
  *
  * 1) Master Receiver mode: The Master has to wait on the I2C_EVENT_TRANSFER_ENABLED event
  *    then to read the data received from the Slave (I2C_GetReceivedData() function).
  *
  * 2) Master Transmitter mode: The Master has to send data (I2C_SendByte() function)
  *    then to wait on I2C_EVENT_TRANSFER_ENABLED event. When the event is set Master
  *    can send next data byte or send the STOP condition (I2C_SendSTOP() function) to
  *    finish communication.
  *
  */

/**
  * @brief Finish communication
  *
  * To finish communication with Slave Master has to send the STOP condition
  * (I2C_SendSTOP() function). When the STOP condition is sent to the I2C bus the
  * I2C_EVENT_STOP_CONDITION_TRANSFER event is resetted.
  *
  */

#define I2C_EVENT_STOP_CONDITION_TRANSFER           (I2C_FLAG_STOP)

/** @} */ /* End of group I2C_EVENTS */

/** @} */ /* End of group I2C_Exported_Constants */

/** @defgroup I2C_Exported_Macros I2C Exported Macros
  * @{
  */

/** @} */ /* End of group I2C_Exported_Macros */

/** @defgroup I2C_Exported_Functions I2C Exported Functions
  * @{
  */

void I2C_DeInit(void);
void I2C_Init(const I2C_InitTypeDef* I2C_InitStruct);
void I2C_StructInit(I2C_InitTypeDef* I2C_InitStruct);

void I2C_Cmd(FunctionalState NewState);

void I2C_ITConfig(FunctionalState NewState);
ITStatus I2C_GetITStatus(void);
void I2C_ClearITPendingBit(void);

void I2C_Send7bitAddress(uint8_t Address, uint32_t Direction);
void I2C_SendByte(uint8_t ByteToSend);
void I2C_SendSTOP(void);

void I2C_StartReceiveData(uint32_t Acknowlage);
uint8_t I2C_GetReceivedData(void);

/**
 * @brief
 ****************************************************************************************
 *
 *                         I2C State Monitoring Functions
 *
 ****************************************************************************************
 * This I2C driver provides three different ways for I2C state monitoring
 *  depending on the application requirements and constraints:
 *
 * 1) Basic state monitoring:
 *    Using I2C_CheckEvent() function:
 *    It calculates the I2C status (using the I2C_CMD, I2C_STA registers content)
 *    and compares it to a given event (besides already defined events user can
 *    to define his own events).
 *    The function returns SUCCESS if the current status includes the given flags
 *    and returns ERROR if one or more flags are missed in the current status.
 *
 *    When to use:
 *    - This function is suitable for cases when it is needed to monitor only one
 *      event.
 *
 * 2) Advanced state monitoring:
 *    Using the function I2C_GetLastEvent():
 *    It calculates and returns the I2C status (using the I2C_CMD, I2C_STA registers
 *    content).
 *
 *    When to use:
 *    - This function is suitable for the same applications as above. The returned value
 *      could be compared to events already defined in the library (MDR32F9Qx_i2c.h)
 *      or to custom values defined by user.
 *    - This function is suitable when multiple events are monitored at the same time.
 *
 * 3) Flag-based state monitoring:
 *    The function I2C_GetFlagStatus() returns the status of one single flag.
 *
 *    When to use:
 *    - This function could be used for specific applications or in debug phase.
 *    - It is suitable when only one flag checking is needed (most I2C events
 *      are monitored through multiple flags).
 *
 */

/**
 *
 *  1) Basic state monitoring
 *******************************************************************************
 */
ErrorStatus I2C_CheckEvent(uint32_t Event);
/**
 *
 *  2) Advanced state monitoring
 *******************************************************************************
 */
uint32_t I2C_GetLastEvent(void);
/**
 *
 *  3) Flag-based state monitoring
 *******************************************************************************
 */
FlagStatus I2C_GetFlagStatus(uint32_t Flag);
/**
 *
 *******************************************************************************
 */

/** @} */ /* End of group I2C_Exported_Functions */

/** @} */ /* End of group I2C */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

#ifdef __cplusplus
} // extern "C" block end
#endif

#endif /* __MDR32F9QX_I2C_H */

/******************* (C) COPYRIGHT 2010 Phyton *********************************
*
* END OF FILE MDR32F9Qx_i2c.h */

