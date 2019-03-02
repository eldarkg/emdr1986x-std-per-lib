/**
  ******************************************************************************
  * @file    mdr32f8_can.h
  * @author  Milandr Application Team
  * @version V1.0.0
  * @date    03/09/2015
  * @brief   This file contains all the functions prototypes for the CAN
  *          firmware library.
  ******************************************************************************
  * <br><br>
  *
  *
  * <h2><center>&copy; COPYRIGHT 2015 Milandr</center></h2>
  ******************************************************************************
  * FILE mdr32f8_can.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MDR32F9Qx_CAN_H
#define __MDR32F9Qx_CAN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"	
#include "mdr32f8_config.h"
#include "MDR1986VE8T.h"	

/** @addtogroup __MDR32F8_StdPeriph_Driver
  * @{
  */

/** @addtogroup CAN
  * @{
  */

/** @defgroup CAN_Exported_Types
  * @{
  */

/**
  * @brief  CAN init structure definition
  */

typedef struct
{
  uint8_t  CAN_ROP;                        /*!< Enables or disables own packets reception.
                                                This parameter can be a value of FunctionalState */
  uint8_t  CAN_SAP;                        /*!< Enables or disables sending ACK on own packets.
                                                This parameter can be a value of FunctionalState */
  uint8_t  CAN_STM;                        /*!< Enables or disables Self Test mode.
                                                This parameter can be a value of FunctionalState */
  uint8_t  CAN_ROM;                        /*!< Enables or disables Read Only mode.
                                                This parameter can be a value of FunctionalState */
  uint32_t CAN_PSEG;                       /*!< Specifies the Propagation time.
                                                This parameter is one of @ref CAN_Propagation_time values. */
  uint32_t CAN_SEG1;                       /*!< Specifies the Phase Segment 1 time.
                                                This parameter is one of @ref CAN_Phase_Segment1_time values. */
  uint32_t CAN_SEG2;                       /*!< Specifies the Phase Segment 2 time.
                                                This parameter is one of @ref CAN_Phase_Segment2_time values. */
  uint32_t CAN_SJW;                        /*!< Specifies the Synchronizations jump width time.
                                                This parameter is one of @ref CAN_Synch_jump_width_time values. */
  uint32_t CAN_SB;                         /*!< Specifies the Sampling mode.
                                                This parameter is one of @ref CAN_Sampling_mode */
  uint16_t CAN_BRP;                        /*!< Specifies the System Clock Prescaler. Used to calculate Time Quanta
                                                by the following algorithm:
                                                CLK = PCLK/(BRP + 1)
                                                TQ(microsec) = (BRP + 1)/CLK(MHz) */
  uint8_t CAN_OVER_ERROR_MAX;              /*!< Specifies the upper limit for TEC / REC error counters before
                                                ERROR_OVER flag is set. */
}CAN_InitTypeDef;


/**
  * @brief  CAN Buffer Data container definition
  */

typedef uint32_t CAN_DataTypeDef[2];


/**
  * @brief  CAN Transmitted message structure definition
  */

typedef struct
{
  uint32_t ID;                             /*!< Specifies the full (Standard or Extended) identifier.
                                                To set Standard ID, the macro CAN_STDID_TO_EXTID should
                                                be used. To get Standard ID use CAN_EXTID_TO_STDID macro.
                                                @ref CAN_ID_conversion
                                                This parameter can be a value between 0 to 0x1FFFFFFF. */
  uint8_t PRIOR_0;                         /*!< Specifies sending priority.
                                                This parameter can be a value of FunctionalState. */
  uint8_t IDE;                             /*!< Specifies the type of identifier for the message that will be transmitted.
                                                This parameter can be a value of @ref CAN_identifier_type */
  uint8_t DLC;                             /*!< Specifies the length of the frame that will be transmitted.
                                                This parameter can be a value between 0 to 8 */
  CAN_DataTypeDef Data;                    /*!< Contains the data to be transmitted. */
}CAN_TxMsgTypeDef;

/**
  * @brief  CAN Remote Transfer Request structure definition
  */

typedef struct
{
  uint32_t ID;                             /*!< Specifies the full (Standard or Extended) identifier.
                                                To set Standard ID, the macro CAN_STDID_TO_EXTID should
                                                be used. To get Standard ID use CAN_EXTID_TO_STDID macro.
                                                @ref CAN_ID_conversion
                                                This parameter can be a value between 0 to 0x1FFFFFFF. */
  uint8_t PRIOR_0;                         /*!< Specifies sending priority.
                                                This parameter can be a value of FunctionalState. */
  uint8_t IDE;                             /*!< Specifies the type of identifier for the message that will be transmitted.
                                                This parameter can be a value of @ref CAN_identifier_type */
}CAN_RTRMessageTypeDef;

/**
  * @brief  CAN Remote Transfer Request Reply structure definition
  */

typedef struct
{
  uint32_t ID;                             /*!< Specifies the full (Standard or Extended) identifier.
                                                To set Standard ID, the macro CAN_STDID_TO_EXTID should
                                                be used. To get Standard ID use CAN_EXTID_TO_STDID macro.
                                                @ref CAN_ID_conversion
                                                This parameter can be a value between 0 to 0x1FFFFFFF. */
  uint8_t IDE;                             /*!< Specifies the type of identifier for the message that will be transmitted.
                                                This parameter can be a value of @ref CAN_identifier_type */
  uint8_t DLC;                             /*!< Specifies the length of the frame that will be transmitted.
                                                This parameter can be a value between 0 to 8 */
  CAN_DataTypeDef Data;                    /*!< Contains the data to be transmitted. */
}CAN_RTRReplyTypeDef;

/**
  * @brief  CAN Received message header structure definition
  */

typedef struct
{
  uint32_t ID;                             /*!< Specifies the full (Standard or Extended) identifier.
                                                To set Standard ID, the macro CAN_STDID_TO_EXTID should
                                                be used. To get Standard ID use CAN_EXTID_TO_STDID macro.
                                                @ref CAN_ID_conversion
                                                This parameter can be a value between 0 to 0x1FFFFFFF. */
  uint8_t OVER_EN;                         /*!< Specifies if the received message could be rewritten.
                                                This parameter can be a value of FunctionalState. */
  uint8_t IDE;                             /*!< Specifies the type of identifier for the message that will be received.
                                                This parameter can be a value of @ref CAN_identifier_type */
  uint8_t DLC;                             /*!< Specifies the length of the frame that will be transmitted.
                                                This parameter can be a value between 0 to 8 */
}CAN_RxMsgHeaderTypeDef;

/**
  * @brief  CAN Received message structure definition
  */

typedef struct
{
  CAN_RxMsgHeaderTypeDef Rx_Header;        /*!< Contains message header. */
  CAN_DataTypeDef Data;                    /*!< Contains received data. */
}CAN_RxMsgTypeDef;

/**
  * @brief  CAN filter init structure definition
  */

typedef struct
{
  uint32_t Filter_ID;                      /*!< Specifies standard identifier for the filter.
                                                This parameter can be a value between 0 to 0x1FFFFFFF. */
  uint32_t Mask_ID;                        /*!< Specifies standard identifier for the mask.
                                                This parameter can be a value between 0 to 0x1FFFFFFF. */
}CAN_FilterInitTypeDef;

/** @} */ /* End of group CAN_Exported_Types */


/** @defgroup CAN_Exported_Constants CAN Exported Constants
  * @{
  */

#define IS_CAN_ALL_PERIPH(PERIPH)          (((PERIPH) == MDR_CAN1) || \
                                            ((PERIPH) == MDR_CAN2))

/** @defgroup CAN_Propagation_time CAN Propagation time
  * @{
  */

#define CAN_PSEG_Mul_1TQ            (((uint32_t)0x0) << CAN_BITTMNG_PSEG_Pos) /*!< Propagation time = 1 x TQ */
#define CAN_PSEG_Mul_2TQ            (((uint32_t)0x1) << CAN_BITTMNG_PSEG_Pos) /*!< Propagation time = 2 x TQ */
#define CAN_PSEG_Mul_3TQ            (((uint32_t)0x2) << CAN_BITTMNG_PSEG_Pos) /*!< Propagation time = 3 x TQ */
#define CAN_PSEG_Mul_4TQ            (((uint32_t)0x3) << CAN_BITTMNG_PSEG_Pos) /*!< Propagation time = 4 x TQ */
#define CAN_PSEG_Mul_5TQ            (((uint32_t)0x4) << CAN_BITTMNG_PSEG_Pos) /*!< Propagation time = 5 x TQ */
#define CAN_PSEG_Mul_6TQ            (((uint32_t)0x5) << CAN_BITTMNG_PSEG_Pos) /*!< Propagation time = 6 x TQ */
#define CAN_PSEG_Mul_7TQ            (((uint32_t)0x6) << CAN_BITTMNG_PSEG_Pos) /*!< Propagation time = 7 x TQ */
#define CAN_PSEG_Mul_8TQ            (((uint32_t)0x7) << CAN_BITTMNG_PSEG_Pos) /*!< Propagation time = 8 x TQ */

#define IS_CAN_PSEG_VALUE(VALUE)    (((VALUE) == CAN_PSEG_Mul_1TQ) || \
                                     ((VALUE) == CAN_PSEG_Mul_2TQ) || \
                                     ((VALUE) == CAN_PSEG_Mul_3TQ) || \
                                     ((VALUE) == CAN_PSEG_Mul_4TQ) || \
                                     ((VALUE) == CAN_PSEG_Mul_5TQ) || \
                                     ((VALUE) == CAN_PSEG_Mul_6TQ) || \
                                     ((VALUE) == CAN_PSEG_Mul_7TQ) || \
                                     ((VALUE) == CAN_PSEG_Mul_8TQ))

/** @} */ /* End of group CAN_Propagation_time */

/** @defgroup CAN_Phase_Segment1_time CAN Phase Segment 1 time
  * @{
  */

#define CAN_SEG1_Mul_1TQ            (((uint32_t)0x0) << CAN_BITTMNG_SEG1_Pos) /*!< Phase Segment 1 time = 1 x TQ */
#define CAN_SEG1_Mul_2TQ            (((uint32_t)0x1) << CAN_BITTMNG_SEG1_Pos) /*!< Phase Segment 1 time = 2 x TQ */
#define CAN_SEG1_Mul_3TQ            (((uint32_t)0x2) << CAN_BITTMNG_SEG1_Pos) /*!< Phase Segment 1 time = 3 x TQ */
#define CAN_SEG1_Mul_4TQ            (((uint32_t)0x3) << CAN_BITTMNG_SEG1_Pos) /*!< Phase Segment 1 time = 4 x TQ */
#define CAN_SEG1_Mul_5TQ            (((uint32_t)0x4) << CAN_BITTMNG_SEG1_Pos) /*!< Phase Segment 1 time = 5 x TQ */
#define CAN_SEG1_Mul_6TQ            (((uint32_t)0x5) << CAN_BITTMNG_SEG1_Pos) /*!< Phase Segment 1 time = 6 x TQ */
#define CAN_SEG1_Mul_7TQ            (((uint32_t)0x6) << CAN_BITTMNG_SEG1_Pos) /*!< Phase Segment 1 time = 7 x TQ */
#define CAN_SEG1_Mul_8TQ            (((uint32_t)0x7) << CAN_BITTMNG_SEG1_Pos) /*!< Phase Segment 1 time = 8 x TQ */

#define IS_CAN_SEG1_VALUE(VALUE)    (((VALUE) == CAN_SEG1_Mul_1TQ) || \
                                     ((VALUE) == CAN_SEG1_Mul_2TQ) || \
                                     ((VALUE) == CAN_SEG1_Mul_3TQ) || \
                                     ((VALUE) == CAN_SEG1_Mul_4TQ) || \
                                     ((VALUE) == CAN_SEG1_Mul_5TQ) || \
                                     ((VALUE) == CAN_SEG1_Mul_6TQ) || \
                                     ((VALUE) == CAN_SEG1_Mul_7TQ) || \
                                     ((VALUE) == CAN_SEG1_Mul_8TQ))

/** @} */ /* End of group CAN_Phase_Segment1_time */

/** @defgroup CAN_Phase_Segment2_time CAN Phase Segment 2 time
  * @{
  */

#define CAN_SEG2_Mul_1TQ            (((uint32_t)0x0) << CAN_BITTMNG_SEG2_Pos) /*!< Phase Segment 2 time = 1 x TQ */
#define CAN_SEG2_Mul_2TQ            (((uint32_t)0x1) << CAN_BITTMNG_SEG2_Pos) /*!< Phase Segment 2 time = 2 x TQ */
#define CAN_SEG2_Mul_3TQ            (((uint32_t)0x2) << CAN_BITTMNG_SEG2_Pos) /*!< Phase Segment 2 time = 3 x TQ */
#define CAN_SEG2_Mul_4TQ            (((uint32_t)0x3) << CAN_BITTMNG_SEG2_Pos) /*!< Phase Segment 2 time = 4 x TQ */
#define CAN_SEG2_Mul_5TQ            (((uint32_t)0x4) << CAN_BITTMNG_SEG2_Pos) /*!< Phase Segment 2 time = 5 x TQ */
#define CAN_SEG2_Mul_6TQ            (((uint32_t)0x5) << CAN_BITTMNG_SEG2_Pos) /*!< Phase Segment 2 time = 6 x TQ */
#define CAN_SEG2_Mul_7TQ            (((uint32_t)0x6) << CAN_BITTMNG_SEG2_Pos) /*!< Phase Segment 2 time = 7 x TQ */
#define CAN_SEG2_Mul_8TQ            (((uint32_t)0x7) << CAN_BITTMNG_SEG2_Pos) /*!< Phase Segment 2 time = 8 x TQ */

#define IS_CAN_SEG2_VALUE(VALUE)    (((VALUE) == CAN_SEG2_Mul_1TQ) || \
                                     ((VALUE) == CAN_SEG2_Mul_2TQ) || \
                                     ((VALUE) == CAN_SEG2_Mul_3TQ) || \
                                     ((VALUE) == CAN_SEG2_Mul_4TQ) || \
                                     ((VALUE) == CAN_SEG2_Mul_5TQ) || \
                                     ((VALUE) == CAN_SEG2_Mul_6TQ) || \
                                     ((VALUE) == CAN_SEG2_Mul_7TQ) || \
                                     ((VALUE) == CAN_SEG2_Mul_8TQ))

/** @} */ /* End of group CAN_Phase_Segment2_time */

/** @defgroup CAN_Synch_jump_width_time CAN Synchronizations jump width time
  * @{
  */

#define CAN_SJW_Mul_1TQ            (((uint32_t)0x0) << CAN_BITTMNG_SJW_Pos) /*!< Synchronization jump width time = 1 x TQ */
#define CAN_SJW_Mul_2TQ            (((uint32_t)0x1) << CAN_BITTMNG_SJW_Pos) /*!< Synchronization jump width time = 2 x TQ */
#define CAN_SJW_Mul_3TQ            (((uint32_t)0x2) << CAN_BITTMNG_SJW_Pos) /*!< Synchronization jump width time = 3 x TQ */
#define CAN_SJW_Mul_4TQ            (((uint32_t)0x3) << CAN_BITTMNG_SJW_Pos) /*!< Synchronization jump width time = 4 x TQ */

#define IS_CAN_SJW_VALUE(VALUE)    (((VALUE) == CAN_SJW_Mul_1TQ) || \
                                    ((VALUE) == CAN_SJW_Mul_2TQ) || \
                                    ((VALUE) == CAN_SJW_Mul_3TQ) || \
                                    ((VALUE) == CAN_SJW_Mul_4TQ))

/** @} */ /* End of group CAN_Synch_jump_width_time */

/** @defgroup CAN_Sampling_mode CAN Sampling mode
  * @{
  */

#define CAN_SB_1_SAMPLE            (((uint32_t)0x0) << CAN_BITTMNG_SB_Pos) /*!< One sample is enough             */
#define CAN_SB_3_SAMPLE            (((uint32_t)0x1) << CAN_BITTMNG_SB_Pos) /*!< Three samples should be obtained */

#define IS_CAN_SAMPLING_MODE(MODE) (((MODE) == CAN_SB_1_SAMPLE) || \
                                    ((MODE) == CAN_SB_3_SAMPLE))

/** @} */ /* End of group CAN_Sampling_mode */

/** @defgroup CAN_Status_Flags CAN Status Flags
  * @{
  */

/* !< Flags */
#if 0
/* Note: this group is under #if 0 and is introduced for informational purpose
 * only. The flags are really defined in the header file corresponding to SFR
 * level in CAN_STATUS group */
#define CAN_STATUS_RX_READY         (((uint32_t)0x1) <<  0) /*!< Flag indicating that there are messages received */
#define CAN_STATUS_TX_READY         (((uint32_t)0x1) <<  1) /*!< Flag indicating that there are buffers for transmitting */
#define CAN_STATUS_ERROR_OVER       (((uint32_t)0x1) <<  2) /*!< Flag indicating that TEC or REC exceeds ERROR_MAX value */
#define CAN_STATUS_BIT_ERR          (((uint32_t)0x1) <<  3) /*!< Transmitting frame bits error flag */
#define CAN_STATUS_BIT_STUFF_ERR    (((uint32_t)0x1) <<  4) /*!< Staff frame bits error flag */
#define CAN_STATUS_CRC_ERR          (((uint32_t)0x1) <<  5) /*!< Frame CRC error flag */
#define CAN_STATUS_FRAME_ERR        (((uint32_t)0x1) <<  6) /*!< Frame format error flag */
#define CAN_STATUS_ACK_ERR          (((uint32_t)0x1) <<  7) /*!< Reception acknowledge error flag */
#define CAN_STATUS_IDLOWER          (((uint32_t)0x1) <<  8) /*!< Arbitrage "loosing" flag */
#define CAN_STATUS_ERR_PASSIVE      (((uint32_t)0x1) <<  9) /*!< Flag indicating that CAN controller is in the ERROR PASSIVE state */
#define CAN_STATUS_ERR_BUSOFF       (((uint32_t)0x1) << 10) /*!< Flag indicating that CAN controller is in the BUS OFF state */
#define CAN_STATUS_RX_ERR_CNT8      (((uint32_t)0x1) << 11) /*!< REC (receiver error counter) flag. Set if REC > 255 */
#define CAN_STATUS_TX_ERR_CNT8      (((uint32_t)0x1) << 12) /*!< TEC (transmitter error counter) flag. Set if TEC > 255 */
#endif /* #if 0 */

#define IS_CAN_IT_ERROR_FLAG(FLAG)  (((FLAG) == CAN_STATUS_ERROR_OVER)    ||\
                                     ((FLAG) == CAN_STATUS_BIT_ERR)       ||\
                                     ((FLAG) == CAN_STATUS_BIT_STUFF_ERR) ||\
                                     ((FLAG) == CAN_STATUS_CRC_ERR)       ||\
                                     ((FLAG) == CAN_STATUS_FRAME_ERR)     ||\
                                     ((FLAG) == CAN_STATUS_ACK_ERR))

#define IS_CAN_IT_RXTX_FLAG(FLAG)   (((FLAG) == CAN_STATUS_RX_READY)  ||\
                                     ((FLAG) == CAN_STATUS_TX_READY))

/*!< CAN controller ERROR ACTIVE state mask */
#define CAN_STATUS_ERRACTIVE(STATUS)          !((STATUS) & (CAN_STATUS_ERR_PASSIVE | CAN_STATUS_ERR_BUSOFF))

/* Error counters */
#define CAN_STATUS_TXERRCNT(STATUS) ((uint32_t)((STATUS) & CAN_STATUS_TX_ERR_CNT_Msk) >> CAN_STATUS_TX_ERR_CNT_Pos)
#define CAN_STATUS_RXERRCNT(STATUS) ((uint32_t)((STATUS) & CAN_STATUS_RX_ERR_CNT_Msk) >> CAN_STATUS_RX_ERR_CNT_Pos)

/** @} */ /* End of group CAN_Status_Flags */

/** @defgroup CAN_identifier_type CAN Identifier Type
  * @{
  */

#define CAN_ID_STD                  ((uint8_t)0x0) /*!< Standard Id */
#define CAN_ID_EXT                  ((uint8_t)0x1) /*!< Extended Id */
#define IS_CAN_IDTYPE(IDTYPE) (((IDTYPE) == CAN_ID_STD) || ((IDTYPE) == CAN_ID_EXT))

/** @} */ /* End of group CAN_identifier_type */

/** @defgroup CAN_remote_transmission_request CAN Remote Transmission Request
  * @{
  */

#define CAN_RTR_DATA                ((uint8_t)0x0)                          /*!< Data frame */
#define CAN_RTR_REMOTE              (((uint32_t)0x1) << CAN_DLC_RTR_Pos)    /*!< Remote frame */
#define IS_CAN_RTR(RTR)             (((RTR) == CAN_RTR_DATA) || ((RTR) == CAN_RTR_REMOTE))

/** @} */ /* End of group CAN_remote_transmission_request */

/** @defgroup CAN_Message CAN Message-related macros
  * @{
  */

#define IS_CAN_ID(ID)               ((ID) <= ((uint32_t)0x1FFFFFFF))
#define IS_CAN_DLC(DLC)             ((DLC) <= ((uint8_t)0x08))
#define IS_CAN_BUFFER(NUMBER)       ((NUMBER) < ((uint32_t)0x00000020))
/** @} */ /* End of group CAN_Message */

/** @defgroup CAN_receive_request CAN Receive Request
  * @{
  */

#define CAN_DLC_DATA_LENGTH         ((uint32_t)0x0000000F)  /*!< Mask for message data length field */

/** @} */ /* End of group CAN_receive_request */

/** @defgroup CAN_Constants CAN Constants
  * @{
  */

#define CAN_BUFFER_NUMBER           ((uint32_t)32)          /*!< Total buffer number */

/** @} */ /* End of group CAN_Constants */

/** @defgroup CAN_Buffer_Control_Bit_Masks CAN Buffer Control Bit Masks
  * @{
  */

#define CAN_STATUS_EN              (((uint32_t)0x1) <<  0) /*!< Buffer enable state.
                                                                0 - off, 1 - on */
#define CAN_STATUS_RX_TXn          (((uint32_t)0x1) <<  1) /*!< Buffer operation mode.
                                                                0 - transmission, 1 - reception */
#define CAN_STATUS_OVER_EN         (((uint32_t)0x1) <<  2) /*!< Is received message overwriting allowed.
                                                                0 - not allowed, 1 - allowed */
#define CAN_STATUS_RTR_EN          (((uint32_t)0x1) <<  3) /*!< RTR answer mode
                                                                0 - don't answer, 1 - answer when RTR is received into buffer */
#define CAN_STATUS_PRIOR_0         (((uint32_t)0x1) <<  4) /*!< Sending priority
                                                                0 - without priority, 1 - with priority */
#define CAN_STATUS_TX_REQ          (((uint32_t)0x1) <<  5) /*!< Message sending request
                                                                0 - no request or already sent, 1 - request pending */
/* Flags */
#define CAN_STATUS_RX_FULL         (((uint32_t)0x1) <<  6) /*!< Reception readiness flag */
#define CAN_STATUS_OVER_WR         (((uint32_t)0x1) <<  7) /*!< Flag indicating that received message was overwritten */

/** @} */ /* End of group CAN_Buffer_Control_Bit_Masks */

/** @defgroup CAN_interrupts CAN Interrupts
  * @{
  */

#define CAN_IT_GLBINTEN            (((uint32_t)0x1) <<  0) /*!< General flag that enables CAN module interrupts */
#define CAN_IT_RXINTEN             (((uint32_t)0x1) <<  1) /*!< Flag that enables interrupt on message reception */
#define CAN_IT_TXINTEN             (((uint32_t)0x1) <<  2) /*!< Flag that enables interrupt if transmission becomes available */
#define CAN_IT_ERRINTEN            (((uint32_t)0x1) <<  3) /*!< Flag that enables interrupt on error */
#define CAN_IT_ERROVERINTEN        (((uint32_t)0x1) <<  4) /*!< Flag that enables interrupt on TEC or REC exceeds ERROR_MAX value */

#define CAN_IT_MASK		(CAN_IT_GLBINTEN | CAN_IT_RXINTEN | CAN_IT_TXINTEN |\
						 CAN_IT_ERRINTEN | CAN_IT_ERROVERINTEN)

#define IS_CAN_ITConfig(IT) 		((IT & (~CAN_IT_MASK)) == 0)

/** @} */ /* End of group CAN_interrupts */

/** @defgroup CAN_Buffer_Interrupts CAN Buffer Interrupts
  * @{
  */

#define CAN_BUFFER_0               (((uint32_t)0x1) <<  0)
#define CAN_BUFFER_1               (((uint32_t)0x1) <<  1)
#define CAN_BUFFER_2               (((uint32_t)0x1) <<  2)
#define CAN_BUFFER_3               (((uint32_t)0x1) <<  3)
#define CAN_BUFFER_4               (((uint32_t)0x1) <<  4)
#define CAN_BUFFER_5               (((uint32_t)0x1) <<  5)
#define CAN_BUFFER_6               (((uint32_t)0x1) <<  6)
#define CAN_BUFFER_7               (((uint32_t)0x1) <<  7)
#define CAN_BUFFER_8               (((uint32_t)0x1) <<  8)
#define CAN_BUFFER_9               (((uint32_t)0x1) <<  9)
#define CAN_BUFFER_10              (((uint32_t)0x1) << 10)
#define CAN_BUFFER_11              (((uint32_t)0x1) << 11)
#define CAN_BUFFER_12              (((uint32_t)0x1) << 12)
#define CAN_BUFFER_13              (((uint32_t)0x1) << 13)
#define CAN_BUFFER_14              (((uint32_t)0x1) << 14)
#define CAN_BUFFER_15              (((uint32_t)0x1) << 15)
#define CAN_BUFFER_16              (((uint32_t)0x1) << 16)
#define CAN_BUFFER_17              (((uint32_t)0x1) << 17)
#define CAN_BUFFER_18              (((uint32_t)0x1) << 18)
#define CAN_BUFFER_19              (((uint32_t)0x1) << 19)
#define CAN_BUFFER_20              (((uint32_t)0x1) << 20)
#define CAN_BUFFER_21              (((uint32_t)0x1) << 21)
#define CAN_BUFFER_22              (((uint32_t)0x1) << 22)
#define CAN_BUFFER_23              (((uint32_t)0x1) << 23)
#define CAN_BUFFER_24              (((uint32_t)0x1) << 24)
#define CAN_BUFFER_25              (((uint32_t)0x1) << 25)
#define CAN_BUFFER_26              (((uint32_t)0x1) << 26)
#define CAN_BUFFER_27              (((uint32_t)0x1) << 27)
#define CAN_BUFFER_28              (((uint32_t)0x1) << 28)
#define CAN_BUFFER_29              (((uint32_t)0x1) << 29)
#define CAN_BUFFER_30              (((uint32_t)0x1) << 30)
#define CAN_BUFFER_31              (((uint32_t)0x1) << 31)

/** @} */ /* End of group CAN_Buffer_Interrupts */

/** @defgroup CAN_Clock_BRG
  * @{
  */

#define CAN_HCLKdiv1                        ((uint32_t)0x00000000)
#define CAN_HCLKdiv2                        ((uint32_t)0x00000001)
#define CAN_HCLKdiv4                        ((uint32_t)0x00000002)
#define CAN_HCLKdiv8                        ((uint32_t)0x00000003)
#define CAN_HCLKdiv16                       ((uint32_t)0x00000004)
#define CAN_HCLKdiv32                       ((uint32_t)0x00000005)
#define CAN_HCLKdiv64                       ((uint32_t)0x00000006)
#define CAN_HCLKdiv128                      ((uint32_t)0x00000007)

#define IS_CAN_CLOCK_BRG(BRG)               ((BRG) <= 7)

#define CAN_DIV_Msk        								 ((uint32_t)0x0000FFFF)
#define CAN_CLK_EN         								 (1<<16)
#define CAN_CLKSRC_msk                     ((uint32_t)0xF0000000) 
#define CAN_CLKSRC_offs                    28

#define CAN_CLKSRC_HSI                     ((uint32_t)0x00000000)
#define CAN_CLKSRC_HSE0                    ((uint32_t)0x00000001)
#define CAN_CLKSRC_HSE1                    ((uint32_t)0x00000002)
#define CAN_CLKSRC_LSI                     ((uint32_t)0x00000003)
#define CAN_CLKSRC_LSE                     ((uint32_t)0x00000004)
#define CAN_CLKSRC_PLL0                    ((uint32_t)0x00000005)
#define CAN_CLKSRC_PLL1                    ((uint32_t)0x00000006)
#define CAN_CLKSRC_PLL2                    ((uint32_t)0x00000007)
#define CAN_CLKSRC_MAX_CLK                 ((uint32_t)0x0000000C)

#define IS_CAN_CLKSRC(CLKSRC)  					(((CLKSRC) == CAN_CLKSRC_HSI)  || \
																					 ((CLKSRC) == CAN_CLKSRC_HSE0) || \
																					 ((CLKSRC) == CAN_CLKSRC_HSE1) || \
																					 ((CLKSRC) == CAN_CLKSRC_LSI)  || \
																					 ((CLKSRC) == CAN_CLKSRC_LSE)  || \
																					 ((CLKSRC) == CAN_CLKSRC_PLL0) || \
																					 ((CLKSRC) == CAN_CLKSRC_PLL1) || \
																					 ((CLKSRC) == CAN_CLKSRC_PLL2) || \
																					 ((CLKSRC) == CAN_CLKSRC_MAX_CLK))																				 

#define CAN_CLKdiv1                        ((uint32_t)0x00000000)
#define CAN_CLKdiv2                        ((uint32_t)0x00000001)
#define CAN_CLKdiv4                        ((uint32_t)0x00000002)
#define CAN_CLKdiv8                        ((uint32_t)0x00000003)

/** @} */ /* End of group CAN_Clock_BRG */

/** @} */ /* End of group CAN_Exported_Constants */

/** @defgroup CAN_Exported_Macros CAN Exported Macros
  * @{
  */

/** @defgroup CAN_ID_conversion CAN Standard to/from Extended ID conversion
  * @{
  */

#define CAN_STDID_TO_EXTID(STDID)  ((STDID) << CAN_ID_SID_Pos)
#define CAN_EXTID_TO_STDID(EXTID)  ((EXTID) >> CAN_ID_SID_Pos)

/** @} */ /* End of group CAN_ID_conversion */



/** @} */ /* End of group CAN_Exported_Macros */

/** @defgroup CAN_Exported_Functions CAN Exported Functions
  * @{
  */

void CAN_DeInit(MDR_CAN_TypeDef* CANx);
void CAN_Init(MDR_CAN_TypeDef* CANx, const CAN_InitTypeDef* CAN_InitStruct);
void CAN_StructInit(CAN_InitTypeDef* CAN_InitStruct);
void CAN_FilterInit(MDR_CAN_TypeDef* CANx, uint32_t BufferNumber, CAN_FilterInitTypeDef* CAN_FilterInitStruct);
void CAN_ITConfig(MDR_CAN_TypeDef* CANx, uint32_t CAN_IT, FunctionalState NewState);
uint32_t CAN_GetDisabledBuffer(MDR_CAN_TypeDef* CANx);
uint32_t CAN_GetEmptyTransferBuffer(MDR_CAN_TypeDef* CANx);
void CAN_Transmit(MDR_CAN_TypeDef* CANx, uint32_t BufferNumber, CAN_TxMsgTypeDef* TxMessage);
void CAN_SendRTR(MDR_CAN_TypeDef* CANx, uint32_t BufferNumber, CAN_RTRMessageTypeDef* RTRMessage);
void CAN_RTRReply(MDR_CAN_TypeDef* CANx, uint32_t BufferNumber, CAN_RTRReplyTypeDef* RTRReplyMessage);
void CAN_Receive(MDR_CAN_TypeDef* CANx, uint32_t BufferNumber, FunctionalState OverWrite);
void CAN_GetReceivedData(MDR_CAN_TypeDef* CANx, uint32_t BufferNumber, CAN_DataTypeDef RxBuffer);
void CAN_GetRawReceivedData(MDR_CAN_TypeDef* CANx, uint32_t BufferNumber, CAN_RxMsgTypeDef* RxMessage);
void CAN_BufferRelease(MDR_CAN_TypeDef* CANx, uint32_t BufferNumber);
void CAN_Cmd(MDR_CAN_TypeDef* CANx, FunctionalState NewState);
uint32_t CAN_GetStatus(MDR_CAN_TypeDef* CANx);
uint32_t CAN_GetBufferStatus(MDR_CAN_TypeDef* CANx, uint32_t BufferNumber);
ITStatus CAN_GetITState(MDR_CAN_TypeDef* CANx, uint32_t CAN_IT);
void CAN_ITClearErrorPendingBit(MDR_CAN_TypeDef* CANx, uint32_t Status_Flag);
void CAN_RxITConfig(MDR_CAN_TypeDef* CANx, uint32_t Buffer_IT, FunctionalState NewState);
ITStatus CAN_GetRxITStatus(MDR_CAN_TypeDef* CANx, uint32_t BufferNumber);
uint32_t CAN_GetRx(MDR_CAN_TypeDef* CANx);
void CAN_TxITConfig(MDR_CAN_TypeDef* CANx, uint32_t Buffer_IT, FunctionalState NewState);
ITStatus CAN_GetTxITStatus(MDR_CAN_TypeDef* CANx, uint32_t BufferNumber);
void CAN_ITClearRxTxPendingBit(MDR_CAN_TypeDef* CANx, uint32_t BufferNumber, uint32_t Status_Flag);

void CAN_CLK_en(uint32_t CAN_CLK_DIV);


/** @} */ /* End of group CAN_Exported_Functions */

/** @} */ /* End of group CAN */

/** @} */ /* End of group MDR32F8_StdPeriph_Driver */

#ifdef __cplusplus
} // extern "C" block end
#endif

#endif /* __MDR32F8_CAN_H */

/******************* (C) COPYRIGHT 2015 Milandr *********
*
* END OF FILE mdr32f8_can.h */

