/**
  * FILE MDR32F9Qx_eth.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef MDR32F9QX_ETH_H_
#define MDR32F9QX_ETH_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_config.h"
#include "MDR32F9Qx_lib.h"

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @addtogroup ETHERNET
  * @{
  */

/** @defgroup ETH_Exported_Types ETH Exported Types
  * @{
  */

/**
  * @brief	ETH Init Structure definition
  * @note	The user should not configure all the ETH_InitTypeDef structure's fields.
  *   		By calling the ETH_StructInit function the structure’s fields are set to their default values.
  *   		Only the parameters that will be set to a non-default value should be configured.
  */
typedef struct {

	/**
	  *  @brief PHY
	  */

	uint32_t 			ETH_PHY_Address;					/*!< Addres PHY.
																 This parameter can be a value from 0 to 0x1F. */
	uint32_t			ETH_PHY_Mode;						/*!< Selects the PHY MODE.
													 	 	 	 This parameter can be a value of @ref ETH_PHY_MODE. */
	uint32_t			ETH_PHY_Interface;					/*!< Selects the PHY interface.
													 	 	 	 This parameter can be a value of @ref ETH_PHY_INTERFACE. */

	/**
	  * @brief MAC General Config
	  */

	uint32_t			ETH_Dilimiter;						/*!< Defines the boundaries of the transmitter and receiver buffers.
													 	 	 	 This parameter can be a value from 0 to 0x1FFF. */
	uint32_t			ETH_DBG_Mode;						/*!< Select the mode of operation in debug mode.
													 	 	 	 This parameter can be a value of @ref ETH_DBG_MODE. */
	FunctionalState 	ETH_DBG_XF;							/*!< Enable or disable automatic change of the transmitter FIFO pointers.
	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 This parameter can be: ENABLE or DISABLE. */
	FunctionalState		ETH_DBG_RF;							/*!< Enable or disable automatic change of the receiver FIFO pointers.
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 This parameter can be: ENABLE or DISABLE. */
	FunctionalState		ETH_Loopback_Mode;					/*!< Selects or not the internal MAC Loopback mode.
													 	 	 	 This parameter can be: ENABLE or DISABLE. */
	BitStatus			ETH_Receiver_RST;					/*!< Receiver reset bit.
	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 This parameter can be: SET or RESET. */
	BitStatus			ETH_Transmitter_RST;				/*!< Transmitter reset bit.
	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 This parameter can be: SET or RESET. */
	FunctionalState		ETH_Register_CLR;					/*!< Permission or prohibition of discharge status registers his reading.
																 This parameter can be: ENABLE or DISABLE. */
	uint32_t			ETH_Buffer_Mode;					/*!< Set the operating mode buffers.
													 	 	 	 This parameter can be a value of@ref ETH_BUFFER_MODE */
	FunctionalState		ETH_Extension_Mode;					/*!< Enable or disable mode additions to the size of short packets slotTime field "Extension".
													 	 	 	 This parameter can be: ENABLE or DISABLE. */
	FunctionalState		ETH_HalfDuplex_Mode;				/*!< Enable or disable half-duplex operation.
													 	 	 	 This parameter can be: ENABLE or DISABLE. */
	FunctionalState		ETH_DTRM;							/*!< Enable or disable mode deterministic delivery time.
													 	 	 	 This parameter can be: ENABLE or DISABLE. */
	FunctionalState		ETH_Pause;							/*!< Enable or disable the automatic packet processing PAUSE.
													 	 	 	 This parameter can be: ENABLE or DISABLE. */
	uint32_t			ETH_ColWnd;							/*!< Set the size of the "window collisions".
													 	 	 	 This parameter can be a value from 0 to 0xFF. */
	/**
	 * @brief	MAC Transmitter Config
	 */

	FunctionalState		ETH_Transmitter_State;				/*!< The state of the transmitter.
																 This parameter can be: ENABLE or DISABLE. */
	uint32_t			ETH_Transmitter_BE;					/*!< Set the sequence of bytes in the word transmitter.
																 This parameter can be a value of @ref ETH_TRANSMITTER_BE. */
	uint32_t 			ETH_Transmitter_Bits_Order;			/*!< The order of the bits in the transmission of data bytes.
																 This parameter can be a value of @ref ETH_TRANSMITTER_BITS_ORDER. */
	uint32_t			ETH_Transmitter_Event_Mode;			/*!< Defines mode of operation withdrawal EVNT[1].
															 	 This parameter can be a value of @ref ETH_TRANSMITTER_EVENT_MODE. */
	FunctionalState     ETH_Automatic_Pad_Strip;    		/*!< Enable or disable addition to the minimum packet length PAD-s.
																 This parameter can be: ENABLE or DISABLE. */
	FunctionalState		ETH_Automatic_Preamble;				/*!< Enable or disable supplement packet preamble.
																 This parameter can be: ENABLE or DISABLE. */
	FunctionalState		ETH_Automatic_CRC_Strip;			/*!< Enable or disable supplement package automatically calculated CRC.
																 This parameter can be: ENABLE or DISABLE. */
	FunctionalState		ETH_Automatic_IPG;					/*!< Enable or disable curing system pauses between sending packets.
															     This parameter can be: ENABLE or DISABLE. */
	uint32_t			ETH_Retry_Counter;					/*!< Maximum number of attempts to send a packet.
																 This parameter can be a value from 0 to 0xF. */
	/**
	 * @brief	MAC Receiver Config
	 */

	FunctionalState		ETH_Receiver_State;					/*!< The state of the receiver.
																 This parameter can be: ENABLE or DISABLE. */
	uint32_t			ETH_Receiver_BE;					/*!< Set the sequence of bytes in the word receiver.
	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	 This parameter can be a value of @ref ETH_RECEIVER_BE. */
	uint32_t			ETH_Receiver_Bits_Order;			/*!< Set the sequence of bits at the reception of data bytes.
																 This parameter can be a value of @ref ETH_RECEIVER_BITS_ORDER. */
	uint32_t			ETH_Receiver_Event_Mode;			/*!< Defines mode of operation withdrawal EVNT[0].
																 This parameter can be a value of @ref ETH_RECEIVER_EVENT_MODE. */
	FunctionalState		ETH_Receive_All_Packets;			/*!< Selects or not all frames reception by the MAC (No filtering).
															     This parameter can be: ENABLE or DISABLE. */
	FunctionalState		ETH_Short_Frames_Reception;			/*!< Enable or disable the reception of packets of less than the minimum.
																 This parameter can be: ENABLE or DISABLE. */
	FunctionalState		ETH_Long_Frames_Reception;			/*!< Enable or disable the reception of packets longer than the maximum.
															     This parameter can be: ENABLE or DISABLE. */
	FunctionalState		ETH_Broadcast_Frames_Reception;		/*!< Enable or disable Receiving packet broadcast MAC-address.
																 This parameter can be: ENABLE or DISABLE. */
	FunctionalState		ETH_Error_CRC_Frames_Reception;		/*!< Enable or disable receiving packets with errors.
																 This parameter can be: ENABLE or DISABLE. */
	FunctionalState		ETH_Control_Frames_Reception;		/*!< Enable or disable receiving control packets.
																 This parameter can be: ENABLE or DISABLE. */
	FunctionalState		ETH_Unicast_Frames_Reception;		/*!< Enable or disable receiving packets with MAC-address specified in the register MAC_Address.
																 This parameter can be: ENABLE or DISABLE. */
	FunctionalState		ETH_Source_Addr_HASH_Filter;		/*!< Enable or disable receiving packets with a multicast MAC-address-filtered HAS-table.
																 This parameter can be: ENABLE or DISABLE. */
	/**
	 * @brief MAC Address
	 */

	uint16_t 			ETH_MAC_Address[3];					/*!< Individual MAC address */
	/**
	 * @brief Hash Table
	 */

	uint32_t            ETH_Hash_Table_High;             	/*!< This field holds the higher 32 bits of Hash table.  */
	uint32_t            ETH_Hash_Table_Low;              	/*!< This field holds the lower 32 bits of Hash table.  */
	/**
	 * @brief Time settings
	 */

	uint32_t 			ETH_IPG;							/*!< The value of inter-packet interval for full duplex
																 This parameter can be a value from 0 to 0xFFFF. */
	uint32_t 			ETH_PSC;							/*!< Prescaler value increment values for BAG and JitterWnd.
																 This parameter can be a value from 0 to 0xFFFF. */
	uint32_t 			ETH_BAG;							/*!< The period value of the packets.
																 This parameter can be a value from 0 to 0xFFFF. */
	uint32_t 			ETH_JitterWnd;						/*!< Jitter value of packets transmitted.
																 This parameter can be a value from 0 to 0xFFFF. */
} ETH_InitTypeDef;


/**
 * @brief Bit-field structure of the state of the packet reception
 */
typedef struct{
	uint32_t Length			:16;		/*!< The number of bytes in the packet including header and CRC. */
	uint32_t PF_ERR			:1;			/*!< A sign package PAUSE. */
	uint32_t CF_ERR			:1;			/*!< A sign Management Pack (filtering by MAC and special tags in the field length - 13.14 - octets). */
	uint32_t LF_ERR			:1;			/*!< A sign excess packet length 1518 octets. */
	uint32_t SF_ERR			:1;			/*!< A sign of lack of packet length 64 octets. */
	uint32_t LEN_ERR		:1;			/*!< A sign mismatch between the actual length and the length specified in the length field - 13.14 octets. */
	uint32_t DN_ERR			:1;			/*!< A sign bit of the packet is not a multiple of 8. */
	uint32_t CRC_ERR		:1;			/*!< A sign mismatch packet CRC. */
	uint32_t SMB_ERR		:1;			/*!< A sign of the presence in the packet error nibbles. */
	uint32_t MCA			:1;			/*!< A sign group package (MAC matches HASH). */
	uint32_t BCA			:1;			/*!< A sign of the broadcast packet (MAC = FF:FF:FF:FF:FF:FF). */
	uint32_t UCA			:1;			/*!< A sign individual package (MAC corresponds to the set). */
}ETH_StatusPacketReceptionBitFileds;

/**
 * @brief The state of the packet reception	Unioun definition
 */
typedef union {
	uint32_t Status;								/*!< Specifies the fully status Word. */
	ETH_StatusPacketReceptionBitFileds Fields;		/*!< Specifies the particular field of the status word.*/
}ETH_StatusPacketReceptionTypeDef;

/** @} */ /* End of group ETH_Exported_Types */

/** @defgroup ETH_Exported_Macros ETH Exported Macros
  * @{
  */

/** @defgroup ETH_MODE ETH_MODE
  * @{
  */

#define ETH_PHY_MODE_10BaseT_Half_Duplex					(uint32_t)(0x0 << ETH_PHY_CONTROL_MODE_Pos)
#define ETH_PHY_MODE_10BaseT_Full_Duplex					(uint32_t)(0x1 << ETH_PHY_CONTROL_MODE_Pos)
#define ETH_PHY_MODE_100BaseT_Half_Duplex					(uint32_t)(0x2 << ETH_PHY_CONTROL_MODE_Pos)
#define ETH_PHY_MODE_100BaseT_Full_Duplex					(uint32_t)(0x3 << ETH_PHY_CONTROL_MODE_Pos)
#define ETH_PHY_MODE_100BaseT_Half_Duplex_With_Auto_Tuning	(uint32_t)(0x4 << ETH_PHY_CONTROL_MODE_Pos)
#define ETH_PHY_MODE_Repeater								(uint32_t)(0x5 << ETH_PHY_CONTROL_MODE_Pos)
#define ETH_PHY_MODE_Low_Consumption						(uint32_t)(0x6 << ETH_PHY_CONTROL_MODE_Pos)
#define ETH_PHY_MODE_AutoNegotiation						(uint32_t)(0x7 << ETH_PHY_CONTROL_MODE_Pos)

#define ETH_PHY_MODE_MASK									(uint32_t)(0x7 << ETH_PHY_CONTROL_MODE_Pos)

#define IS_ETH_PHY_MODE(MODE)								(((MODE) & (~ETH_PHY_MODE_MASK)) == 0)

/** @} */ /* End of group ETH_MODE */

/** @defgroup ETH_PHY_INTERFACE ETH_PHY INTERFACE
  * @{
  */
#define ETH_PHY_INTERFACE_FIBER_OPTIC						(uint32_t)(0x01 << ETH_PHY_CONTROL_FX_EN_Pos)
#define ETH_PHY_INTERFACE_ETHERNET_802_3					(uint32_t)(0x00 << ETH_PHY_CONTROL_FX_EN_Pos)

#define IS_ETH_PHY_INTERFACE(INTERFACE)						(((INTERFACE) == ETH_PHY_INTERFACE_FIBER_OPTIC) ||\
															 ((INTERFACE) == ETH_PHY_INTERFACE_ETHERNET_802_3))

/** @} */ /* End of group ETH_PHY_INTERFACE */

/** @defgroup ETH_DBG_MODE ETH_DBG_MODE
  * @{
  */

#define ETH_DBG_MODE_FREE_RUN			(uint32_t)(0x0 << ETH_G_CFGh_DBG_MODE_Pos)
#define ETH_DBG_MODE_HALT				(uint32_t)(0x2 << ETH_G_CFGh_DBG_MODE_Pos)
#define ETH_DBG_MODE_STOP				(uint32_t)(0x3 << ETH_G_CFGh_DBG_MODE_Pos)

#define IS_ETH_DBG_MODE(MODE)			((MODE == ETH_DBG_MODE_FREE_RUN) |\
										 (MODE == ETH_DBG_MODE_HALT) |\
										 (MODE == ETH_DBG_MODE_STOP))

/** @} */ /* End of group ETH_DBG_MOD */

/** @defgroup ETH_BUFFER_MODE ETH_BUFFER_MODE
  * @{
  */

#define ETH_BUFFER_MODE_LINEAR						(uint32_t) (0x0 << ETH_G_CFGl_BUFF_MODE_Pos)
#define ETH_BUFFER_MODE_AUTOMATIC_CHANGE_POINTERS	(uint32_t) (0x1 << ETH_G_CFGl_BUFF_MODE_Pos)
#define ETH_BUFFER_MODE_FIFO						(uint32_t) (0x2 << ETH_G_CFGl_BUFF_MODE_Pos)

#define IS_ETH_BUFFER_MODE(MODE)					((MODE == ETH_BUFFER_MODE_LINEAR) |\
													 (MODE == ETH_BUFFER_MODE_AUTOMATIC_CHANGE_POINTERS) |\
													 (MODE == ETH_BUFFER_MODE_FIFO))

/** @} */ /* End of group ETH_BUFFER_MODE */

/** @defgroup ETH_TRANSMITTER_BITS_ORDER ETH_TRANSMITTER_BITS_ORDER
  * @{
  */

#define ETH_TRANSMITTER_BITS_ORDER_LSB	(uint32_t)(0 << ETH_X_CFG_MSB1st_Pos)
#define ETH_TRANSMITTER_BITS_ORDER_MSB	(uint32_t)(1 << ETH_X_CFG_MSB1st_Pos)

#define IS_ETH_TRANSMITTER_BITS_ORDER(ORDER)		((ORDER == ETH_TRANSMITTER_BITS_ORDER_LSB ) || \
													 (ORDER == ETH_TRANSMITTER_BITS_ORDER_MSB))

/** @} */ /* End of group ETH_TRANSMITTER_BITS_ORDER */

/** @defgroup ETH_TRANSMITTER_BE ETH_TRANSMITTER_BE
  * @{
  */
#define ETH_TRANSMITTER_BE_LITTLE_ENDIAN		(uint32_t)(0x0 << ETH_X_CFG_BE_Pos)
#define ETH_TRANSMITTER_BE_BIG_ENDIAN			(uint32_t)(0x1 << ETH_X_CFG_BE_Pos)

#define IS_ETH_TRANSMITTER_BE(BE)			((BE == ETH_TRANSMITTER_BE_LITTLE_ENDIAN) |\
											 (BE == ETH_TRANSMITTER_BE_BIG_ENDIAN))


/** @} */ /* End of group ETH_TRANSMITER_BE */

/** @defgroup ETH_TRANSMITTER_EVENT_MODE ETH_TRANSMITTER_EVENT_MODE
  * @{
  */

#define ETH_TRANSMITTER_EVENT_MODE_XFIFO_EMPTY			(uint32_t)(0x0 << ETH_X_CFG_EVNT_MODE_Pos)
#define ETH_TRANSMITTER_EVENT_MODE_XFIFO_ALMOST_EMPTY	(uint32_t)(0x1 << ETH_X_CFG_EVNT_MODE_Pos)
#define ETH_TRANSMITTER_EVENT_MODE_XFIFO_HALF_FULL		(uint32_t)(0x2 << ETH_X_CFG_EVNT_MODE_Pos)
#define ETH_TRANSMITTER_EVENT_MODE_XFIFO_ALMOST_FULL	(uint32_t)(0x3 << ETH_X_CFG_EVNT_MODE_Pos)
#define ETH_TRANSMITTER_EVENT_MODE_XFIFO_FULL			(uint32_t)(0x4 << ETH_X_CFG_EVNT_MODE_Pos)
#define ETH_TRANSMITTER_EVENT_MODE_PAKET_SENT			(uint32_t)(0x5 << ETH_X_CFG_EVNT_MODE_Pos)
#define ETH_TRANSMITTER_EVENT_MODE_READ_WORD			(uint32_t)(0x6 << ETH_X_CFG_EVNT_MODE_Pos)
#define ETH_TRANSMITTER_EVENT_MODE_START_TRANSMIT		(uint32_t)(0x7 << ETH_X_CFG_EVNT_MODE_Pos)

#define ETH_TRANSMITTER_EVENT_MODE_MASK					(uint32_t)(0x7 << ETH_X_CFG_EVNT_MODE_Pos)

#define IS_ETH_TRANSMITTER_EVENT_MODE(MODE)				((MODE & (~ETH_TRANSMITTER_EVENT_MODE_MASK)) == 0)

/** @} */ /* End of group ETH_TRANSMITTER_EVENT_MODE */

/** @defgroup ETH_RECEVIER_BE ETH_RECEVIER_BE
  * @{
  */

#define ETH_RECEIVER_BE_LITTLE_ENDIAN		(uint32_t)(0x0 << ETH_R_CFG_BE_Pos)
#define ETH_RECEIVER_BE_BIG_ENDIAN			(uint32_t)(0x1 << ETH_R_CFG_BE_Pos)

#define IS_ETH_RECEIVER_BE(BE)				((BE == ETH_RECEIVER_BE_LITTLE_ENDIAN) |\
											 (BE == ETH_RECEIVER_BE_BIG_ENDIAN))

/** @} */ /* End of group ETH_RECEVIER_BE */

/** @defgroup ETH_RECIIVER_BITS_ORDER ETH_RECIIVER_BITS_ORDER
  * @{
  */

#define ETH_RECEIVER_BITS_ORDER_LSB	(uint32_t)(0 << ETH_R_CFG_MSB1st_Pos)
#define ETH_RECEIVER_BITS_ORDER_MSB	(uint32_t)(0 << ETH_R_CFG_MSB1st_Pos)

#define IS_ETH_RECEIVER_BITS_ORDER(ORDER)		((ORDER == ETH_RECEIVER_BITS_ORDER_LSB ) || \
												 (ORDER == ETH_RECEIVER_BITS_ORDER_MSB))

/** @} */ /* End of group ETH_RECIIVER_BITS_ORDER */

/** @defgroup ETH_RECEIVER_EVENT_MODE ETH_RECEIVER_EVENT_MODE
  * @{
  */

#define ETH_RECEIVER_EVENT_MODE_RFIFO_NOT_EMPTY				(uint32_t)(0x0 << ETH_R_CFG_EVNT_MODE_Pos)
#define ETH_RECEIVER_EVENT_MODE_RFIFO_NOT_ALMOST_EMPTY		(uint32_t)(0x1 << ETH_R_CFG_EVNT_MODE_Pos)
#define ETH_RECEIVER_EVENT_MODE_RFIFO_HALF_EMPTY			(uint32_t)(0x2 << ETH_R_CFG_EVNT_MODE_Pos)
#define ETH_RECEIVER_EVENT_MODE_RFIFO_NOT_ALMOST_FULL		(uint32_t)(0x3 << ETH_R_CFG_EVNT_MODE_Pos)
#define ETH_RECEIVER_EVENT_MODE_RFIFO_NOT_FULL				(uint32_t)(0x4 << ETH_R_CFG_EVNT_MODE_Pos)
#define ETH_RECEIVER_EVENT_MODE_PACET_RECEIVED				(uint32_t)(0x5 << ETH_R_CFG_EVNT_MODE_Pos)
#define ETH_RECEIVER_EVENT_MODE_WORD_RECEIVED				(uint32_t)(0x6 << ETH_R_CFG_EVNT_MODE_Pos)
#define ETH_RECEIVER_EVENT_MODE_PACET_DROPED				(uint32_t)(0x7 << ETH_R_CFG_EVNT_MODE_Pos)

#define ETH_RECEIVER_EVENT_MODE_MASK						(uint32_t)(0x7 << ETH_R_CFG_EVNT_MODE_Pos)

#define IS_ETH_RECEIVER_EVENT_MODE(MODE)					((MODE & (~ETH_RECEIVER_EVENT_MODE_MASK)) == 0)

/** @} */ /* End of group ETH_RECEIVER_EVENT_MODE */

/** @defgroup ETHERNET_Interrupt_defintions ETHERNET Interrupt defintions
  * @{
  */

#define ETH_MAC_IT_MII_RDY				(uint32_t)(0x00008000)
#define ETH_MAC_IT_MDIO_INT				(uint32_t)(0x00004000)
#define ETH_MAC_IT_CRS_LOST				(uint32_t)(0x00001000)
#define ETH_MAC_IT_LC					(uint32_t)(0x00000800)
#define ETH_MAC_IT_UNDF					(uint32_t)(0x00000400)
#define ETH_MAC_IT_XF_ERR				(uint32_t)(0x00000200)
#define ETH_MAC_IT_XF_OK				(uint32_t)(0x00000100)
#define ETH_MAC_IT_SF					(uint32_t)(0x00000080)
#define ETH_MAC_IT_LF					(uint32_t)(0x00000040)
#define ETH_MAC_IT_CF					(uint32_t)(0x00000020)
#define ETH_MAC_IT_CRC_ERR				(uint32_t)(0x00000010)
#define ETH_MAC_IT_SMB_ERR				(uint32_t)(0x00000008)
#define ETH_MAC_IT_OVF					(uint32_t)(0x00000004)
#define ETH_MAC_IT_MISSED_F				(uint32_t)(0x00000002)
#define ETH_MAC_IT_RF_OK				(uint32_t)(0x00000001)

#define IS_ETH_MAC_IT(IT)				(( IT & 0xFFFF2000 ) == 0)

/** @} */ /* End of group ETHERNET_Interrupt_defintions */

/** @defgroup ETHERNET_Flags ETHERNET Flags
  * @{
  */

#define ETH_MAC_FLAG_R_EMPTY				((uint32_t)0x00000001)
#define ETH_MAC_FLAG_R_AEMPTY				((uint32_t)0x00000002)
#define ETH_MAC_FLAG_R_HALF					((uint32_t)0x00000004)
#define ETH_MAC_FLAG_R_AFULL				((uint32_t)0x00000008)
#define ETH_MAC_FLAG_R_FULL					((uint32_t)0x00000010)
#define ETH_MAC_FLAG_X_EMPTY				((uint32_t)0x00000100)
#define ETH_MAC_FLAG_X_AEMPTY				((uint32_t)0x00000200)
#define ETH_MAC_FLAG_X_HALF					((uint32_t)0x00000400)
#define ETH_MAC_FLAG_X_AFULL				((uint32_t)0x00000800)
#define ETH_MAC_FLAG_X_FULL					((uint32_t)0x00001000)

#define IS_ETH_MAC_FLAG(FLAG)				((( FLAG & 0xFFFFE0E0 ) == 0) |\
											 (!(FLAG == 0)))

/** @} */ /* End of group ETHERNET_Flags */

/** @defgroup ETHERNET_Clock_Source ETHERNET Clock Source
  * @{
  */

#define ETH_PHY_CLOCK_SOURCE_HSI			(uint32_t)(0x00000000)
#define ETH_PHY_CLOCK_SOURCE_HSE			(uint32_t)(0x10000000)
#define ETH_PHY_CLOCK_SOURCE_PLLCPU_0		(uint32_t)(0x20000000)
#define ETH_PHY_CLOCK_SOURCE_HSE2			(uint32_t)(0x30000000)

#define IS_ETH_CLOCK_SOURCE(CLOCK_SOURCE)		((CLOCK_SOURCE == ETH_PHY_CLOCK_SOURCE_HSI) |\
												 (CLOCK_SOURCE == ETH_PHY_CLOCK_SOURCE_HSE) |\
												 (CLOCK_SOURCE == ETH_PHY_CLOCK_SOURCE_PLLCPU_0) |\
												 (CLOCK_SOURCE == ETH_PHY_CLOCK_SOURCE_HSE2))

/** @} */ /* End of group ETHERNET_Clock_Source */

/** @defgroup ETHERNET_Clock_BRG ETHERNET Clock BRG
  * @{
  */

#define ETH_HCLKdiv1                       ((uint32_t)0x00000000)
#define ETH_HCLKdiv2                       ((uint32_t)0x00000001)
#define ETH_HCLKdiv4                       ((uint32_t)0x00000002)
#define ETH_HCLKdiv8                       ((uint32_t)0x00000003)
#define ETH_HCLKdiv16                      ((uint32_t)0x00000004)
#define ETH_HCLKdiv32                      ((uint32_t)0x00000005)
#define ETH_HCLKdiv64                      ((uint32_t)0x00000006)
#define ETH_HCLKdiv128                     ((uint32_t)0x00000007)

#define IS_ETH_CLOCK_BRG(BRG)              (((BRG) >= 0) && ((BRG) <= 7))

/** @} */ /* End of group ETHERNET_Clock_BRG */

/** @defgroup PHY_Clock_HCLKdiv PHY Clock HCLKdiv
  * @{
  */

#define ETH_PHY_HCLKdiv1                       ((uint32_t)0x00000000 << RST_CLK_ETH_CLOCK_PHY_BRG_Pos)
#define ETH_PHY_HCLKdiv2                       ((uint32_t)0x00000001 << RST_CLK_ETH_CLOCK_PHY_BRG_Pos)
#define ETH_PHY_HCLKdiv4                       ((uint32_t)0x00000002 << RST_CLK_ETH_CLOCK_PHY_BRG_Pos)
#define ETH_PHY_HCLKdiv8                       ((uint32_t)0x00000003 << RST_CLK_ETH_CLOCK_PHY_BRG_Pos)
#define ETH_PHY_HCLKdiv16                      ((uint32_t)0x00000004 << RST_CLK_ETH_CLOCK_PHY_BRG_Pos)
#define ETH_PHY_HCLKdiv32                      ((uint32_t)0x00000005 << RST_CLK_ETH_CLOCK_PHY_BRG_Pos)
#define ETH_PHY_HCLKdiv64                      ((uint32_t)0x00000006 << RST_CLK_ETH_CLOCK_PHY_BRG_Pos)
#define ETH_PHY_HCLKdiv128                     ((uint32_t)0x00000007 << RST_CLK_ETH_CLOCK_PHY_BRG_Pos)

#define IS_ETH_PHY_HCLKdiv(BRG)                (((~BRG) & 0x00070000) == 0)

/** @} */ /* End of group PHY_Clock_HCLKdiv */

/** @defgroup ETHERNET_Clock_Number ETHERNET Clock Number
  * @{
  */

#define ETH_CLK1							((uint32_t)0x01000000)
#define ETH_CLK2							((uint32_t)0x40000000)

#define IS_ETH_CLK(ETH_CLK)					((ETH_CLK == ETH_CLK1) ||\
											 (ETH_CLK == ETH_CLK2))
/** @} */ /* End of group ETHERNET_Clock_Number */

/* ETHERNET errors */
#define  ETH_ERROR              ((uint32_t)0)
#define  ETH_SUCCESS            ((uint32_t)1)

/**--------------------------------------------------------------------------**/
/**
  * @brief                     Description of common PHY registers
  */
/**--------------------------------------------------------------------------**/

/** @defgroup ETH_PHY_FLAGs ETH PHY FLAGs
  * @{
  */

#define ETH_PHY_FLAG_MDINT			((uint32_t)0x00000400)
#define ETH_PHY_FLAG_MDO			((uint32_t)0x00000200)
#define ETH_PHY_FLAG_FX_VALID		((uint32_t)0x00000100)
#define ETH_PHY_FLAG_COL			((uint32_t)0x000000C0)
#define ETH_PHY_FLAG_CRS			((uint32_t)0x00000020)
#define ETH_PHY_FLAG_READY			((uint32_t)0x00000010)
#define ETH_PHY_FLAG_FULL_DUPLEX	((uint32_t)0x00000008)
#define ETH_PHY_FLAG_CARRIER_SENSE	((uint32_t)0x00000004)
#define ETH_PHY_FLAG_LINK			((uint32_t)0x00000002)
#define ETH_PHY_FLAG_100MBIT		((uint32_t)0x00000001)

#define IS_ETH_PHY_FLAG(FLAG)		((FLAG == ETH_PHY_FLAG_MDINT) 		||\
									 (FLAG == ETH_PHY_FLAG_MDO) 		||\
									 (FLAG == ETH_PHY_FLAG_FX_VALID)	||\
									 (FLAG == ETH_PHY_FLAG_COL) 		||\
									 (FLAG == ETH_PHY_FLAG_CRS) 		||\
									 (FLAG == ETH_PHY_FLAG_READY) 		||\
									 (FLAG == ETH_PHY_FLAG_FULL_DUPLEX) ||\
									 (FLAG == ETH_PHY_FLAG_CARRIER_SENSE) ||\
									 (FLAG == ETH_PHY_FLAG_LINK) 		||\
									 (FLAG == ETH_PHY_FLAG_100MBIT))

/** @} */ /* End of group ETH_PHY_FLAGs */

/** @defgroup PHY_Read_Write_Timeouts PHY Read write Timeouts
  * @{
  */

#define PHY_READ_TO                     ((uint32_t)0x0004FFFF)
#define PHY_WRITE_TO                    ((uint32_t)0x0004FFFF)

/** @} */ /* End of group PHY_Read_Write_Timeouts */

/** @defgroup PHY_Register_address PHY Register address
  * @{
  */

#define PHY_BCR							0          /*!< Basic Control Register */
#define PHY_BSR							1          /*!< Basic Status Register */
#define PHY_ID1							2
#define PHY_ID2							3
#define PHY_ATU							4
#define PHY_OPP_ATU						5
#define PHY_EATU						6
#define PHY_EMODE						18
#define PHY_IT_FLAGs					29
#define PHY_IT_MASKs					30
#define PHY_ECTR						31

#define IS_ETH_PHYReg(PHYreg)					(((PHYreg >= 0 ) &&  (PHYreg <= 6)) ||\
												 (PHYreg == 18) || (PHYreg == 29)   ||\
												 (PHYreg == 30) || (PHYreg == 31))

/** @} */ /* End of group PHY_Register_address */

/** @} */ /* End of group ETH_Exported_Macros */

/** @defgroup ETH_Private_Function_Prototypes ETH Private Function Prototypes
 * 	@{
 */

void ETH_ClockDeInit(void);
void ETH_PHY_ClockConfig(uint32_t clock_source, uint32_t PHY_HCLKdiv);
void ETH_BRGInit(uint32_t ETH_HCLKdiv);
void ETH_ClockCMD(uint32_t ETHx, FunctionalState NewState);
void ETH_PHY_Reset(MDR_ETHERNET_TypeDef * ETHERNETx);
void ETH_PHYCmd(MDR_ETHERNET_TypeDef * ETHERNETx, FunctionalState NewState);
void ETH_DeInit(MDR_ETHERNET_TypeDef * ETHERNETx );
void ETH_StructInit(ETH_InitTypeDef * ETH_InitStruct);
void ETH_Init(MDR_ETHERNET_TypeDef * ETHERNETx, ETH_InitTypeDef * ETH_InitStruct);
void ETH_Start(MDR_ETHERNET_TypeDef * ETHERNETx);
void ETH_MACTransmissionCmd( MDR_ETHERNET_TypeDef * ETHERNETx, FunctionalState NewState);
void ETH_MACReceptionCmd( MDR_ETHERNET_TypeDef * ETHERNETx, FunctionalState NewState);
uint16_t ETH_GetMACITStatusRegister(MDR_ETHERNET_TypeDef * ETHERNETx);
FlagStatus ETH_GetMACITStatus(MDR_ETHERNET_TypeDef * ETHERNETx, uint32_t ETH_MAC_FLAG);
uint32_t ETH_GetMACStatusRegister(MDR_ETHERNET_TypeDef * ETHERNETx);
void ETH_MACITConfig(MDR_ETHERNET_TypeDef * ETHERNETx, uint32_t ETH_MAC_IT, FunctionalState NewState);
void ETH_MACAddressConfig(MDR_ETHERNET_TypeDef * ETHERNETx, uint16_t *MacAddr);
void ETH_GetMACAddress(MDR_ETHERNET_TypeDef * ETHERNETx, uint16_t *Addr);
FlagStatus ETH_GetPHYStatus(MDR_ETHERNET_TypeDef * ETHERNETx, uint16_t ETH_PHY_FLAG);
uint16_t ETH_ReadPHYRegister(MDR_ETHERNET_TypeDef * ETHERNETx, uint16_t PHYAddress, uint16_t PHYReg);
uint32_t ETH_WritePHYRegister(MDR_ETHERNET_TypeDef * ETHERNETx, uint16_t PHYAddress, uint16_t PHYReg, uint16_t PHYValue);
uint32_t ETH_ReceivedFrame(MDR_ETHERNET_TypeDef * ETHERNETx, uint32_t * ptr_InputBuffer);
void ETH_SendFrame(MDR_ETHERNET_TypeDef * ETHERNETx, uint32_t * ptr_OututBuffer, uint32_t BufLen);
void ETH_DMAPrepare(void);
void ETH_DMAFrameRx(uint32_t * DstBuf, uint32_t BufferSize, uint32_t * SrcBuf);
void ETH_DMAFrameTx(uint32_t * DstBuf, uint32_t BufferSize, uint32_t *  SrcBuf);

FlagStatus ETH_GetFlagStatus(MDR_ETHERNET_TypeDef * ETHERNETx, uint16_t ETH_MAC_FLAG);

/** @} */ /* End of group ETH_Private_Function_Prototypes */

/** @} */ /* End of group ETHERNET */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

#ifdef __cplusplus
} // extern "C" block end
#endif

#endif /* MDR32F9QX_ETH_H_ */

/*
*
* END OF FILE MDR32F9Qx_eth.h */
