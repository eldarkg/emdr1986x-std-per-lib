/**
  * FILE MDR32F9Qx_eth.c
  */

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_config.h"
#include "MDR32F9Qx_dma.h"
#include "MDR32F9Qx_eth.h"
#include "MDR32F9Qx_rst_clk.h"

#include <math.h>
#include <stdio.h>

#define ASSERT_INFO_FILE_ID FILEID__MDR32F9X_ETH_C


/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @defgroup ETHERNET ETHERNET
 *  @warning This module can be used only for microcontrollers MDR1986VE1T and MDR1986VE3.
  * @{
  */

#if defined (USE_MDR1986VE1T) || defined (USE_MDR1986VE3)

/** @defgroup ETH_Exported_Variables ETH Exported Variables
 *  @{
 */
extern DMA_CtrlDataTypeDef DMA_ControlTable[DMA_Channels_Number * (1 + DMA_AlternateData)];
/** @} */ /* End of group ETH_Exported_Variables */

/** @defgroup ETH_Private_Defines ETH Private Defines
  * @{
  */

#if defined (USE_MDR1986VE3)
	#define IS_ETH_ALL_PERIPH(PERIPH)				((PERIPH == MDR_ETHERNET1) ||\
																					 (PERIPH == MDR_ETHERNET2))
#elif defined (USE_MDR1986VE1T)
	#define IS_ETH_ALL_PERIPH(PERIPH)				(PERIPH == MDR_ETHERNET1)
#endif
#define IS_ETH_PHY_ADDRESS(ADDRESS)				(((ADDRESS << ETH_PHY_CONTROL_PHYADD_Pos) & (~ETH_PHY_CONTROL_PHYADD_Msk)) == 0)
#define IS_ETH_COL_WND(WND)						(WND <= 0xFF)
#define IS_ETH_RETRY_COUNTER(COUNTER)			(COUNTER <= 0x0F)
#define IS_ETH_DELIMITER(DELIMITER)				((DELIMITER >= 0x5EA) && (DELIMITER <= 0x1A16))

#define ETH_BUFFER_SIZE							((uint32_t)0x2000)

/** @} */ /* End of group ETH_Private_Defines */

/** @defgroup ETH_Private_Macros ETH Private Macros
  * @{
  */
/** @} */ /* End of group ETH_Private_Macros */

/** @defgroup ETH_Private_Variables ETH Private Variables
  * @{
  */

/** @} */ /* End of group ETH_Private_Variables */

/** @defgroup ETH_Private_FunctionPrototypes ETH Private FunctionPrototypes
  * @{
  */
/** @} */ /* End of group ETH_Private_FunctionPrototypes */

/** @defgroup ETH_Private_Functions ETH Private Functions
  * @{
  */

/**
  * @brief	Reset the ETHERNET clock registers to their default reset values.
  * @param	None
  * @retval	None
  */
void ETH_ClockDeInit(void)
{
	uint32_t tmpreg_ETH_CLOCK;

	/* Read old value */
	tmpreg_ETH_CLOCK = MDR_RST_CLK->ETH_CLOCK;

	/* Reset all settings for Ethernet and PHY */
	tmpreg_ETH_CLOCK &= ~(RST_CLK_ETH_CLOCK_PHY_CLK_SEL_Msk |
						  RST_CLK_ETH_CLOCK_ETH2_CLK_EN |
						  RST_CLK_ETH_CLOCK_PHY_CLK_EN |
						  RST_CLK_ETH_CLOCK_ETH_CLK_EN |
						  RST_CLK_ETH_CLOCK_ETH_BRG_Msk |
						  RST_CLK_ETH_CLOCK_PHY_BRG_Msk);
	/* Save new value */
	MDR_RST_CLK->ETH_CLOCK = tmpreg_ETH_CLOCK;
}

/**
  * @brief	Config the PHY clock register.
  * @param	clock_source: defines the frequency source for the PHY.
  * 		This parameter can be one of the following values:
  * 			@arg ETH_PHY_CLOCK_SOURCE_HSI
  * 			@arg ETH_PHY_CLOCK_SOURCE_HSE
  * 			@arg ETH_PHY_CLOCK_SOURCE_PLLCPU_0
  * 			@arg ETH_PHY_CLOCK_SOURCE_HSE2
  * @param	PHY_HCLKdiv: specifies the HCLK division factor.
  * 		This parameter can be one of the following values:
  * 			@arg ETH_PHY_HCLKdiv1
  * 			@arg ETH_PHY_HCLKdiv2
  * 			@arg ETH_PHY_HCLKdiv4
  * 			@arg ETH_PHY_HCLKdiv8
  * 			@arg ETH_PHY_HCLKdiv16
  * 			@arg ETH_PHY_HCLKdiv32
  * 			@arg ETH_PHY_HCLKdiv64
  * 			@arg ETH_PHY_HCLKdiv128
  * @retval	None
  */
void ETH_PHY_ClockConfig(uint32_t clock_source, uint32_t PHY_HCLKdiv)
{
	uint32_t tmpreg_ETH_CLOCK;

	/* Check the parameters */
	assert_param(IS_ETH_CLOCK_SOURCE(clock_source));
	assert_param(IS_ETH_PHY_HCLKdiv(PHY_HCLKdiv));

	tmpreg_ETH_CLOCK = MDR_RST_CLK->ETH_CLOCK;
	tmpreg_ETH_CLOCK &= ~ (RST_CLK_ETH_CLOCK_PHY_BRG_Msk | RST_CLK_ETH_CLOCK_PHY_CLK_SEL_Msk);

	/* Select clock source for PHY module and set PHY DIV */
	tmpreg_ETH_CLOCK |= clock_source | PHY_HCLKdiv;
	/* Enable PHY CLK */
	tmpreg_ETH_CLOCK |= RST_CLK_ETH_CLOCK_PHY_CLK_EN;

	MDR_RST_CLK->ETH_CLOCK = tmpreg_ETH_CLOCK;
}

/**
  * @brief	Initializes the ETHERNET peripheral Clock according to the
  *         specified parameters.
  * @param	ETH_HCLKdiv: specifies the HCLK division factor.
  * 		This parameter can be one of the following values:
  * 			@arg ETH_HCLKdiv1
  * 			@arg ETH_HCLKdiv2
  * 			@arg ETH_HCLKdiv4
  * 			@arg ETH_HCLKdiv8
  * 			@arg ETH_HCLKdiv16
  * 			@arg ETH_HCLKdiv32
  * 			@arg ETH_HCLKdiv64
  * 			@arg ETH_HCLKdiv128
  * @retval	None
  */
void ETH_BRGInit(uint32_t ETH_HCLKdiv)
{
	uint32_t tmpreg_ETH_CLOCK;

	/* Check the parameters */
	assert_param(IS_ETH_CLOCK_BRG(ETH_HCLKdiv));

	tmpreg_ETH_CLOCK = MDR_RST_CLK->ETH_CLOCK;
	tmpreg_ETH_CLOCK &= ~(RST_CLK_ETH_CLOCK_ETH_BRG_Msk);
	tmpreg_ETH_CLOCK |= ETH_HCLKdiv;

	MDR_RST_CLK->ETH_CLOCK = tmpreg_ETH_CLOCK;
}

/**
  * @brief	Enables or disables the specified ETHERNET clock.
  * @param	ETHx: Slect the number of ETHERNET interface.
  * 		This parameter can be one of the following values:
  * 			@arg ETH_CLK1
  * 			@arg ETH_CLK2
  * @param	NewState: new state of the ETHERNET interface clock.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void ETH_ClockCMD(uint32_t ETHx, FunctionalState NewState)
{
	/* Check the parameters */
	assert_param(IS_ETH_CLK(ETHx));
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(NewState == ENABLE){
		MDR_RST_CLK->ETH_CLOCK |= ETHx;
	}
	else{
		MDR_RST_CLK->ETH_CLOCK &= ~ETHx;
	}
}

/**
  * @brief	Reset the ETHERNETx peripheral registers to their default reset values.
  * @param	ETHERNETx: Slect the ETHERNET peripheral.
  *         This parameter can be one of the following values:
  *         MDR_ETHERNET1, MDR_ETHERNET2.
  * @retval	None
  */
void ETH_PHY_Reset(MDR_ETHERNET_TypeDef * ETHERNETx)
{
	/* Check the parameters */
	assert_param(IS_ETH_ALL_PERIPH(ETHERNETx));
	/* Reset PHY */
	ETHERNETx->PHY_Control &= ~ETH_PHY_CONTROL_nRST;

	/* Wait until the PHY unit did not come out in the state after a hard reset. */
	while(ETH_GetPHYStatus(ETHERNETx, ETH_PHY_FLAG_READY) != SET);
}

/**
  * @brief	Enables or disables the PHY.
  * @param	ETHERNETx: Slect the ETHERNET peripheral.
  *         This parameter can be one of the following values:
  *         MDR_ETHERNET1, MDR_ETHERNET2 for MDR1986VE3 and
  *         MDR_ETHERNET1 for MDR1986VE1T.
  * @param	NewState: new state of the PHY.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval	None
  */
void ETH_PHYCmd(MDR_ETHERNET_TypeDef * ETHERNETx, FunctionalState NewState)
{
	/* Check the parameters */
	assert_param(IS_ETH_ALL_PERIPH(ETHERNETx));
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(NewState == ENABLE){
		ETHERNETx->PHY_Control |= ETH_PHY_CONTROL_nRST;
	}
	else{
		ETHERNETx->PHY_Control &= ~ETH_PHY_CONTROL_nRST;
	}

}

/**
  * @brief	Deinitializes the ETHERNET peripheral registers to their default reset values.
  * @param	ETHERNETx: Slect the ETHERNET peripheral.
  *         This parameter can be one of the following values:
  *         MDR_ETHERNET1, MDR_ETHERNET2 for MDR1986VE3 and
  *         MDR_ETHERNET1 for MDR1986VE1T.
  * @retval	None
  */
void ETH_DeInit(MDR_ETHERNET_TypeDef * ETHERNETx )
{
	/* Check the parameters */
	assert_param(IS_ETH_ALL_PERIPH(ETHERNETx));

	/* PHY reset */
	ETH_PHY_Reset(ETHERNETx);

	ETHERNETx->ETH_Dilimiter 	= 0x1000;
	ETHERNETx->ETH_MAC_T 		= 0x78AB;
	ETHERNETx->ETH_MAC_M 		= 0x3456;
	ETHERNETx->ETH_MAC_H 		= 0x0012;
	ETHERNETx->ETH_HASH0 		= 0x0000;
	ETHERNETx->ETH_HASH1 		= 0x0000;
	ETHERNETx->ETH_HASH2 		= 0x0000;
	ETHERNETx->ETH_HASH3 		= 0x8000;
	ETHERNETx->ETH_IPG 			= 0x0060;
	ETHERNETx->ETH_PSC 			= 0x0031;
	ETHERNETx->ETH_BAG 			= 0x0064;
	ETHERNETx->ETH_JitterWnd 	= 0x0004;
	ETHERNETx->ETH_R_CFG 		= 0x0507;
	ETHERNETx->ETH_X_CFG 		= 0x01FA;
	ETHERNETx->ETH_G_CFGl 		= 0x4080;
	ETHERNETx->ETH_G_CFGh		= 0x3000;
	ETHERNETx->ETH_IMR 			= 0x0000;
	ETHERNETx->ETH_IFR 			= 0x0000;
	ETHERNETx->ETH_R_Head 		= 0x0000;
	ETHERNETx->ETH_X_Tail 		= 0x1000;  
  	ETHERNETx->ETH_STAT = 0;
}

/**
  * @brief	Fills each ETH_InitStruct member with its default value.
  * @param	ETH_InitStruct: pointer to a ETH_InitTypeDef structure which will be initialized.
  * @retval	None
  */
void ETH_StructInit(ETH_InitTypeDef * ETH_InitStruct)
{

	/* Set PHY address */
	ETH_InitStruct->ETH_PHY_Address = 0x1C;
	/* PHY Auto-negotiation enabled */
	ETH_InitStruct->ETH_PHY_Mode = ETH_PHY_MODE_AutoNegotiation;
	/* Set the working interface */
	ETH_InitStruct->ETH_PHY_Interface = ETH_PHY_INTERFACE_ETHERNET_802_3;

	/* General config*/
	ETH_InitStruct->ETH_Dilimiter = 0x0800;
	/* Set the DBG Mode */
	ETH_InitStruct->ETH_DBG_Mode = ETH_DBG_MODE_FREE_RUN;
	/* Enable automatically change the transmitter FIFO pointers in DBG Mode. */
	ETH_InitStruct->ETH_DBG_XF = ENABLE;
	/* Enable automatically change the receiver FIFO pointers in DBG Mode. */
	ETH_InitStruct->ETH_DBG_RF = ENABLE;
	/* Loopback disabled. */
	ETH_InitStruct->ETH_Loopback_Mode = DISABLE;
	/* Disable the receiver. */
	ETH_InitStruct->ETH_Receiver_RST = RESET;
	/* Disable the transmitter. */
	ETH_InitStruct->ETH_Transmitter_RST = RESET;
	/* Enables reset STATUS register when read in. */
	ETH_InitStruct->ETH_Register_CLR = ENABLE;
	/* Set the Buffer FIFO mode */
	ETH_InitStruct->ETH_Buffer_Mode = ETH_BUFFER_MODE_LINEAR;
	/* Disable mode additions to the size of short packets slotTime field "Extension". */
	ETH_InitStruct->ETH_Extension_Mode = DISABLE;
	/* Disable the half duplex mode/ */
	ETH_InitStruct->ETH_HalfDuplex_Mode = DISABLE;
	/* Disable the deterministic mode delivery time. */
	ETH_InitStruct->ETH_DTRM = DISABLE;
	/* Disable the automatic packet processing PAUSE. */
	ETH_InitStruct->ETH_Pause = DISABLE;
	/* Set the size of window collisions */
	ETH_InitStruct->ETH_ColWnd = 0x80;

	/* Transmitter config */
	/* Disable the transmitter. */
	ETH_InitStruct->ETH_Transmitter_State = DISABLE;
	/* Set the sequence of bytes in the word transmitter. */
	ETH_InitStruct->ETH_Transmitter_BE = ETH_TRANSMITTER_BE_LITTLE_ENDIAN;
	/* Set the order of the bits in the transmission of data bytes. */
	ETH_InitStruct->ETH_Transmitter_Bits_Order = ETH_TRANSMITTER_BITS_ORDER_LSB;
	/* Setting the operating mode output EVNT [1]. */
	ETH_InitStruct->ETH_Transmitter_Event_Mode = ETH_TRANSMITTER_EVENT_MODE_XFIFO_ALMOST_EMPTY;
	/* Enable addition to the minimum packet length PAD-s. */
	ETH_InitStruct->ETH_Automatic_Pad_Strip = ENABLE;
	/* Enable supplement packet preamble. */
	ETH_InitStruct->ETH_Automatic_Preamble = ENABLE;
	/* Enable supplement package will automatically calculate the CRC. */
	ETH_InitStruct->ETH_Automatic_CRC_Strip = ENABLE;
	/* Enable exposure mode pauses between sending packets. */
	ETH_InitStruct->ETH_Automatic_IPG = ENABLE;
	/* Set the maximum number of attempts to send a packet. */
	ETH_InitStruct->ETH_Retry_Counter = 0x0A;

	/* Receiver config  */
	/* Disable the receiver. */
	ETH_InitStruct->ETH_Receiver_State = DISABLE;
	/* Set the sequence of bytes in a word. */
	ETH_InitStruct->ETH_Receiver_BE = ETH_RECEIVER_BE_LITTLE_ENDIAN;
	/* Set the sequence of bits at the reception of data bytes. */
	ETH_InitStruct->ETH_Receiver_Bits_Order = ETH_RECEIVER_BITS_ORDER_LSB;
	/* Setting the operating mode output EVNT [0]. */
	ETH_InitStruct->ETH_Receiver_Event_Mode = ETH_RECEIVER_EVENT_MODE_PACET_RECEIVED;
	/* Disable receive all packets. */
	ETH_InitStruct->ETH_Receive_All_Packets = DISABLE;
	/* Disable receiving packets of length less than the minimum. */
	ETH_InitStruct->ETH_Short_Frames_Reception = DISABLE;
	/* Disable receiving packets of length greater than the maximum. */
	ETH_InitStruct->ETH_Long_Frames_Reception = DISABLE;
	/* Enable receiving packets with broadcast MAC-address. */
	ETH_InitStruct->ETH_Broadcast_Frames_Reception = ENABLE;
	/* Disable receiving packets with errors. */
	ETH_InitStruct->ETH_Error_CRC_Frames_Reception = DISABLE;
	/* Disable receive control packets. */
	ETH_InitStruct->ETH_Control_Frames_Reception = DISABLE;
	/* Enable receiving packets with MAC-address specified in the register MAC_Address. */
	ETH_InitStruct->ETH_Unicast_Frames_Reception = ENABLE;
	/* Enable receiving packets with a multicast MAC-address-filtered HAS-table. */
	ETH_InitStruct->ETH_Source_Addr_HASH_Filter = ENABLE;

	/* Set the MAC address. */
	ETH_InitStruct->ETH_MAC_Address[0] = 0x78AB;
	ETH_InitStruct->ETH_MAC_Address[1] = 0x3456;
	ETH_InitStruct->ETH_MAC_Address[2] = 0x0012;

	/* Set the hash table */
	ETH_InitStruct->ETH_Hash_Table_Low	= 0x00000000;
	ETH_InitStruct->ETH_Hash_Table_High = 0x08000000;

	/* Set the pacet interval fo half duplex mode. */
	ETH_InitStruct->ETH_IPG = 0x0060;
	/* Set the prescaler increment values for BAG and JitterWnd. */
	ETH_InitStruct->ETH_PSC = 0x0031;
	/* Set period the following of packages.*/
	ETH_InitStruct->ETH_BAG = 0x0064;
	/* Set jitter of packets transmitted. */
	ETH_InitStruct->ETH_JitterWnd = 0x0004;
}

/**
  * @brief	Initializes the ETHERNETx peripheral according to the specified
  *   		parameters in the ETH_InitStruct.
  * @param	ETHERNETx: Slect the ETHERNET peripheral.
  *         This parameter can be one of the following values:
  *         MMDR_ETHERNET1, MDR_ETHERNET2 for MDR1986VE3 and
  *         MDR_ETHERNET1 for MDR1986VE1T.
  * @param	ETH_InitStruct: pointer to a ETH_InitTypeDef structure that contains
  *   		the configuration information for the specified ETHERNET peripheral.
  * @retval	None
  *
  */
void ETH_Init(MDR_ETHERNET_TypeDef * ETHERNETx, ETH_InitTypeDef * ETH_InitStruct)
{
	uint32_t tmpreg_PHY_Control;
	uint32_t tmpreg_X_CFG;
	uint32_t tmpreg_R_CFG;
	uint16_t tmpreg_G_CFGh;
	uint16_t tmpreg_G_CFGl;
	/* Check the parameters */
	assert_param(IS_ETH_ALL_PERIPH(ETHERNETx));

	assert_param(IS_ETH_DELIMITER(ETH_InitStruct->ETH_Dilimiter));
	assert_param(IS_ETH_PHY_ADDRESS(ETH_InitStruct->ETH_PHY_Address));
	assert_param(IS_ETH_PHY_MODE(ETH_InitStruct->ETH_PHY_Mode));
	assert_param(IS_ETH_DBG_MODE(ETH_InitStruct->ETH_DBG_Mode));
	assert_param(IS_FUNCTIONAL_STATE(ETH_InitStruct->ETH_DBG_XF));
	assert_param(IS_FUNCTIONAL_STATE(ETH_InitStruct->ETH_DBG_RF));
	assert_param(IS_FUNCTIONAL_STATE(ETH_InitStruct->ETH_Loopback_Mode));
	assert_param(IS_BIT_STATUS(ETH_InitStruct->ETH_Receiver_RST));
	assert_param(IS_BIT_STATUS(ETH_InitStruct->ETH_Transmitter_RST));
	assert_param(IS_FUNCTIONAL_STATE(ETH_InitStruct->ETH_Register_CLR));
	assert_param(IS_ETH_BUFFER_MODE(ETH_InitStruct->ETH_Buffer_Mode));
	assert_param(IS_FUNCTIONAL_STATE(ETH_InitStruct->ETH_Extension_Mode));
	assert_param(IS_FUNCTIONAL_STATE(ETH_InitStruct->ETH_HalfDuplex_Mode));
	assert_param(IS_FUNCTIONAL_STATE(ETH_InitStruct->ETH_DTRM));
	assert_param(IS_FUNCTIONAL_STATE(ETH_InitStruct->ETH_Pause));
	assert_param(IS_ETH_COL_WND(ETH_InitStruct->ETH_ColWnd));

	assert_param(IS_FUNCTIONAL_STATE(ETH_InitStruct->ETH_Transmitter_State));
	assert_param(IS_ETH_TRANSMITTER_BE(ETH_InitStruct->ETH_Transmitter_BE));
	assert_param(IS_ETH_TRANSMITTER_BITS_ORDER(ETH_InitStruct->ETH_Transmitter_Bits_Order));
	assert_param(IS_ETH_TRANSMITTER_EVENT_MODE(ETH_InitStruct->ETH_Transmitter_Event_Mode));
	assert_param(IS_FUNCTIONAL_STATE(ETH_InitStruct->ETH_Automatic_Pad_Strip));
	assert_param(IS_FUNCTIONAL_STATE(ETH_InitStruct->ETH_Automatic_Preamble));
	assert_param(IS_FUNCTIONAL_STATE(ETH_InitStruct->ETH_Automatic_CRC_Strip));
	assert_param(IS_FUNCTIONAL_STATE(ETH_InitStruct->ETH_Automatic_IPG));
	assert_param(IS_ETH_RETRY_COUNTER(ETH_InitStruct->ETH_Retry_Counter));

	assert_param(IS_ETH_RECEIVER_BE(ETH_InitStruct->ETH_Receiver_BE));
	assert_param(IS_ETH_RECEIVER_BITS_ORDER(ETH_InitStruct->ETH_Receiver_Bits_Order));
	assert_param(IS_ETH_RECEIVER_EVENT_MODE(ETH_InitStruct->ETH_Receiver_Event_Mode));
	assert_param(IS_FUNCTIONAL_STATE(ETH_InitStruct->ETH_Receive_All_Packets));
	assert_param(IS_FUNCTIONAL_STATE(ETH_InitStruct->ETH_Short_Frames_Reception));
	assert_param(IS_FUNCTIONAL_STATE(ETH_InitStruct->ETH_Long_Frames_Reception));
	assert_param(IS_FUNCTIONAL_STATE(ETH_InitStruct->ETH_Broadcast_Frames_Reception));
	assert_param(IS_FUNCTIONAL_STATE(ETH_InitStruct->ETH_Error_CRC_Frames_Reception));
	assert_param(IS_FUNCTIONAL_STATE(ETH_InitStruct->ETH_Control_Frames_Reception));
	assert_param(IS_FUNCTIONAL_STATE(ETH_InitStruct->ETH_Unicast_Frames_Reception));
	assert_param(IS_FUNCTIONAL_STATE(ETH_InitStruct->ETH_Source_Addr_HASH_Filter));

	/* Set the buffer size of transmitter and receiver */
	ETHERNETx->ETH_Dilimiter = ETH_InitStruct->ETH_Dilimiter;

	/* Config the PHY control register */
	tmpreg_PHY_Control = (ETH_InitStruct->ETH_PHY_Address << ETH_PHY_CONTROL_PHYADD_Pos) | (ETH_InitStruct->ETH_PHY_Mode) | (ETH_InitStruct->ETH_PHY_Interface);
	ETHERNETx->PHY_Control |= tmpreg_PHY_Control;

	/* Config the G_CFGh register */
	tmpreg_G_CFGh = ETH_InitStruct->ETH_DBG_Mode | (ETH_InitStruct->ETH_DBG_XF << ETH_G_CFGh_DBG_XF_EN_Pos) |
					(ETH_InitStruct->ETH_DBG_RF << ETH_G_CFGh_DBG_RF_EN_Pos) | (ETH_InitStruct->ETH_Loopback_Mode << ETH_G_CFGh_DLB_Pos ) |
					(ETH_InitStruct->ETH_Receiver_RST << ETH_G_CFGh_RRST_Pos) | (ETH_InitStruct->ETH_Transmitter_RST << ETH_G_CFGh_XRST_Pos);
	/* Write to ETH_G_CFGh */
	ETHERNETx->ETH_G_CFGh = tmpreg_G_CFGh;

	/* Config the G_CFGl register */
	tmpreg_G_CFGl = (ETH_InitStruct->ETH_Register_CLR 		<< ETH_G_CFGl_RCLR_EN_Pos)
				  |	(ETH_InitStruct->ETH_Buffer_Mode)
				  |	(ETH_InitStruct->ETH_Extension_Mode 	<< ETH_G_CFGl_EXT_EN_Pos)
				  |	(ETH_InitStruct->ETH_HalfDuplex_Mode 	<< ETH_G_CFGl_HD_EN_Pos)
				  |	(ETH_InitStruct->ETH_DTRM 				<< ETH_G_CFGl_DTRM_EN_Pos)
				  |	(ETH_InitStruct->ETH_Pause 				<< ETH_G_CFGl_PAUSE_EN_Pos)
				  |	(ETH_InitStruct->ETH_ColWnd);
	/* Write to G_CFGl */
	ETHERNETx->ETH_G_CFGl = tmpreg_G_CFGl;

	/* Config the X_CFG register */
	tmpreg_X_CFG = (ETH_InitStruct->ETH_Transmitter_State 	<< ETH_X_CFG_EN_Pos)
				 | (ETH_InitStruct->ETH_Transmitter_BE)
				 | (ETH_InitStruct->ETH_Transmitter_Bits_Order)
				 | (ETH_InitStruct->ETH_Transmitter_Event_Mode)
				 | (ETH_InitStruct->ETH_Automatic_Pad_Strip << ETH_X_CFG_PAD_EN_Pos)
				 | (ETH_InitStruct->ETH_Automatic_Preamble 	<< ETH_X_CFG_PRE_EN_Pos)
				 | (ETH_InitStruct->ETH_Automatic_CRC_Strip << ETH_X_CFG_CRC_EN_Pos)
				 | (ETH_InitStruct->ETH_Automatic_IPG 		<< ETH_X_CFG_IPG_EN_Pos)
				 | (ETH_InitStruct->ETH_Retry_Counter);
	/* Write to X_CFG */
	ETHERNETx->ETH_X_CFG = tmpreg_X_CFG;

	/* Config the R_CFG register */
	tmpreg_R_CFG = (ETH_InitStruct->ETH_Receiver_State << ETH_R_CFG_EN_Pos)
				 | (ETH_InitStruct->ETH_Receiver_BE)
				 | (ETH_InitStruct->ETH_Receiver_Bits_Order)
				 | (ETH_InitStruct->ETH_Receiver_Event_Mode);

	/* Configure the received packets */
	tmpreg_R_CFG |= (ETH_InitStruct->ETH_Short_Frames_Reception 	<< ETH_R_CFG_LF_EN_Pos)
				 |	(ETH_InitStruct->ETH_Long_Frames_Reception 		<< ETH_R_CFG_LF_EN_Pos)
				 |	(ETH_InitStruct->ETH_Broadcast_Frames_Reception << ETH_R_CFG_BCA_EN_Pos)
				 |	(ETH_InitStruct->ETH_Error_CRC_Frames_Reception << ETH_R_CFG_EF_EN_Pos)
				 |	(ETH_InitStruct->ETH_Control_Frames_Reception 	<< ETH_R_CFG_CF_EN_Pos)
				 |	(ETH_InitStruct->ETH_Unicast_Frames_Reception 	<< ETH_R_CFG_UCA_EN_Pos)
				 |	(ETH_InitStruct->ETH_Source_Addr_HASH_Filter 	<< ETH_R_CFG_MCA_EN_Pos)
				 |	(ETH_InitStruct->ETH_Receive_All_Packets 		<< ETH_R_CFG_AC_EN_Pos);

	/* Write to R_CFG */
	ETHERNETx->ETH_R_CFG = tmpreg_R_CFG;

	/* Write the MAC address */
	ETHERNETx->ETH_MAC_T = ETH_InitStruct->ETH_MAC_Address[0];
	ETHERNETx->ETH_MAC_M = ETH_InitStruct->ETH_MAC_Address[1];
	ETHERNETx->ETH_MAC_H = ETH_InitStruct->ETH_MAC_Address[2];

	/* Set the hash table */
	ETHERNETx->ETH_HASH0 = ETH_InitStruct->ETH_Hash_Table_Low & 0x0000FFFF;
	ETHERNETx->ETH_HASH1 = (ETH_InitStruct->ETH_Hash_Table_Low & 0xFFFF0000) >> 16;
	ETHERNETx->ETH_HASH2 = ETH_InitStruct->ETH_Hash_Table_High & 0x0000FFFF;
	ETHERNETx->ETH_HASH3 = (ETH_InitStruct->ETH_Hash_Table_High & 0xFFFF0000) >> 16;

	/* Set the pacet interval fo falf duplex mode. */
	ETHERNETx->ETH_IPG = ETH_InitStruct->ETH_IPG;
	/* Set the prescaler increment values for BAG and JitterWnd. */
	ETHERNETx->ETH_PSC = ETH_InitStruct->ETH_PSC;
	/* Set period the following of packages.*/
	ETHERNETx->ETH_BAG = ETH_InitStruct->ETH_BAG;
	/* Set jitter of packets transmitted. */
	ETHERNETx->ETH_JitterWnd = ETH_InitStruct->ETH_JitterWnd;
  
	if (ETH_InitStruct->ETH_Buffer_Mode == ETH_BUFFER_MODE_FIFO)
		ETH_DMAPrepare();  
}

/**
  * @brief	Enables ETH MAC reception/transmission.
  * @param	ETHERNETx: Slect the ETHERNET peripheral.
  *         This parameter can be one of the following values:
  *         MDR_ETHERNET1, MDR_ETHERNET2 for MDR1986VE3 and
  *         MDR_ETHERNET1 for MDR1986VE1T.
  * @retval	None
  */
void ETH_Start(MDR_ETHERNET_TypeDef * ETHERNETx)
{
	/* Check the parameters */
	assert_param(IS_ETH_ALL_PERIPH(ETHERNETx));

	ETHERNETx->PHY_Control |= ETH_PHY_CONTROL_nRST;

	ETHERNETx->ETH_G_CFGh &= ~(ETH_G_CFGh_RRST | ETH_G_CFGh_XRST);

	/* Enable transmitter */
	ETH_MACTransmissionCmd(ETHERNETx, ENABLE);
	/* Enable receiver */
	ETH_MACReceptionCmd(ETHERNETx, ENABLE);
}

/**
  * @brief	Enables or disables the MAC transmission.
  * @param	ETHERNETx: Slect the ETHERNET peripheral.
  *         This parameter can be one of the following values:
  *         MDR_ETHERNET1, MDR_ETHERNET2 for MDR1986VE3 and
  *         MDR_ETHERNET1 for MDR1986VE1T.
  * @param	NewState: new state of the MAC transmission.
  * 		This parameter can be: ENABLE or DISABLE.
  * @retval	None
  */
void ETH_MACTransmissionCmd( MDR_ETHERNET_TypeDef * ETHERNETx, FunctionalState NewState)
{
	/* Check the parameters */
	assert_param(IS_ETH_ALL_PERIPH(ETHERNETx));
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(NewState == ENABLE){
		ETHERNETx->ETH_X_CFG |= ETH_X_CFG_EN;
	}
	else{
		ETHERNETx->ETH_X_CFG &= ~ETH_X_CFG_EN;
	}

}

/**
  * @brief	Enables or disables the MAC reception.
  * @param	ETHERNETx: Slect the ETHERNET peripheral.
  *         This parameter can be one of the following values:
  *         MDR_ETHERNET1, MDR_ETHERNET2 for MDR1986VE3 and
  *         MDR_ETHERNET1 for MDR1986VE1T.
  * @param	NewState: new state of the MAC reception.
  * 		This parameter can be: ENABLE or DISABLE.
  * @retval	None
  */
void ETH_MACReceptionCmd( MDR_ETHERNET_TypeDef * ETHERNETx, FunctionalState NewState)
{
	/* Check the parameters */
	assert_param(IS_ETH_ALL_PERIPH(ETHERNETx));
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(NewState == ENABLE){
		ETHERNETx->ETH_R_CFG |= ETH_R_CFG_EN;
	}
	else{
		ETHERNETx->ETH_R_CFG &= ~ETH_R_CFG_EN;
	}

}

/**
  * @brief	Get the ETHERNETx interrupt status register.
  * @param	ETHERNETx: Slect the ETHERNET peripheral.
  *         This parameter can be one of the following values:
  *         MDR_ETHERNET1, MDR_ETHERNET2 for MDR1986VE3 and
  *         MDR_ETHERNET1 for MDR1986VE1T.
  * @retval	Return the vaue of the IFR register.
  */
uint16_t ETH_GetMACITStatusRegister(MDR_ETHERNET_TypeDef * ETHERNETx)
{
	/* Check the parameters */
	assert_param(IS_ETH_ALL_PERIPH(ETHERNETx));

	return(ETHERNETx->ETH_IFR);
}

/**
  * @brief	Checks whether the specified ETHERNET MAC IT is occurred or not.
  * @param	ETHERNETx: Slect the ETHERNET peripheral.
  *         This parameter can be one of the following values:
  *         MDR_ETHERNET1, MDR_ETHERNET2 for MDR1986VE3 and
  *         MDR_ETHERNET1 for MDR1986VE1T.
  * @param	ETH_MAC_FLAG: specifies the flag to check.
  * 		This parameter can be one of the following values:
  *   			@arg	ETH_MAC_IT_MII_RDY
  *   			@arg	ETH_MAC_IT_MDIO_INT
  *   			@arg	ETH_MAC_IT_CRS_LOST
  *   			@arg	ETH_MAC_IT_LC
  *   			@arg	ETH_MAC_IT_UNDF
  *   			@arg	ETH_MAC_IT_XF_ERR
  *   			@arg	ETH_MAC_IT_XF_OK
  *   			@arg	ETH_MAC_IT_SF
  *   			@arg	ETH_MAC_IT_LF
  *   			@arg	ETH_MAC_IT_CF
  *   			@arg	ETH_MAC_IT_CRC_ERR
  *   			@arg	ETH_MAC_IT_SMB_ERR
  *   			@arg	ETH_MAC_IT_OVF
  *   			@arg	ETH_MAC_IT_MISSED_F
  *   			@arg	ETH_MAC_IT_RF_OK
  * @retval	The state of ETHERNET MAC IT (SET or RESET).
  */
FlagStatus ETH_GetMACITStatus(MDR_ETHERNET_TypeDef * ETHERNETx, uint32_t ETH_MAC_IT)
{
	 FlagStatus bitstatus;

	/* Check the parameters */
	assert_param(IS_ETH_ALL_PERIPH(ETHERNETx));
	assert_param(IS_ETH_MAC_IT(ETH_MAC_IT));

	if(ETHERNETx->ETH_IFR & ETH_MAC_IT){
		bitstatus = SET;
	}
	else{
		bitstatus = RESET;
	}
	return (bitstatus);
}

/**
  * @brief	Get the MAC STATUS register.
  * @param	ETHERNETx: Slect the ETHERNET peripheral.
  *         This parameter can be one of the following values:
  *         MDR_ETHERNET1, MDR_ETHERNET2 for MDR1986VE3 and
  *         MDR_ETHERNET1 for MDR1986VE1T.
  * @retval	Return the vaue of the STATUS register.
  */
uint32_t ETH_GetMACStatusRegister(MDR_ETHERNET_TypeDef * ETHERNETx)
{
	/* Check the parameters */
	assert_param(IS_ETH_ALL_PERIPH(ETHERNETx));

	return (ETHERNETx->ETH_STAT);
}

/**
  * @brief	Checks whether the specified ETHERNET MAC flag is set or not.
  * @param	ETHERNETx: Slect the ETHERNET peripheral.
  *         This parameter can be one of the following values:
  *         MDR_ETHERNET1, MDR_ETHERNET2 for MDR1986VE3 and
  *         MDR_ETHERNET1 for MDR1986VE1T.
  * @param	ETH_MAC_FLAG: specifies the flag to check.
  * 		This parameter can be one of the following values:
  * 			@arg	ETH_MAC_FLAG_R_EMPTY
  * 			@arg	ETH_MAC_FLAG_R_AEMPTY
  * 			@arg	ETH_MAC_FLAG_R_HAL
  * 			@arg	ETH_MAC_FLAG_R_AFULL
  * 			@arg	ETH_MAC_FLAG_R_FULL
  * 			@arg	ETH_MAC_FLAG_X_EMPTY
  * 			@arg	ETH_MAC_FLAG_X_AEMPTY
  * 			@arg	ETH_MAC_FLAG_X_HALF
  * 			@arg	ETH_MAC_FLAG_X_AFULL
  * 			@arg	ETH_MAC_FLAG_X_FULL
  * @retval	The new state of ETHERNET MAC flag (SET or RESET).
  */
FlagStatus ETH_GetFlagStatus(MDR_ETHERNET_TypeDef * ETHERNETx, uint16_t ETH_MAC_FLAG)
{
	 FlagStatus bitstatus;

	/* Check the parameters */
	assert_param(IS_ETH_ALL_PERIPH(ETHERNETx));
	assert_param(IS_ETH_MAC_FLAG(ETH_MAC_FLAG));

	if(ETHERNETx->ETH_STAT & ETH_MAC_FLAG){
		bitstatus = SET;
	}
	else{
		bitstatus = RESET;
	}
	return (bitstatus);
}

/**
  * @brief	Enables or disables the specified ETHERNET MAC interrupts.
  * @param	ETHERNETx: Slect the ETHERNET peripheral.
  *         This parameter can be one of the following values:
  *         MDR_ETHERNET1, MDR_ETHERNET2 for MDR1986VE3 and
  *         MDR_ETHERNET1 for MDR1986VE1T.
  * @param	ETH_MAC_IT: specifies the ETHERNET MAC interrupt sources to be
  *   		enabled or disabled.
  *   		This parameter can be any combination of the following values:
  *   			@arg	ETH_MAC_IT_MII_RDY
  *   			@arg	ETH_MAC_IT_MDIO_INT
  *   			@arg	ETH_MAC_IT_CRS_LOST
  *   			@arg	ETH_MAC_IT_LC
  *   			@arg	ETH_MAC_IT_UNDF
  *   			@arg	ETH_MAC_IT_XF_ERR
  *   			@arg	ETH_MAC_IT_XF_OK
  *   			@arg	ETH_MAC_IT_SF
  *   			@arg	ETH_MAC_IT_LF
  *   			@arg	ETH_MAC_IT_CF
  *   			@arg	ETH_MAC_IT_CRC_ERR
  *   			@arg	ETH_MAC_IT_SMB_ERR
  *   			@arg	ETH_MAC_IT_OVF
  *   			@arg	ETH_MAC_IT_MISSED_F
  *   			@arg	ETH_MAC_IT_RF_OK
  * @param	NewState: new state of the ETHERNET interface clock.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval	None
  */
void ETH_MACITConfig(MDR_ETHERNET_TypeDef * ETHERNETx, uint32_t ETH_MAC_IT, FunctionalState NewState)
{
	/* Check the parameters */
	assert_param(IS_ETH_ALL_PERIPH(ETHERNETx));
	assert_param(IS_ETH_MAC_IT(ETH_MAC_IT));
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(NewState == ENABLE){
		ETHERNETx->ETH_IMR |= ETH_MAC_IT;
	}
	else{
		ETHERNETx->ETH_IMR &= (~ETH_MAC_IT);
	}
}

/**
  * @brief	Configures the selected MAC address.
  * @param	ETHERNETx: Slect the ETHERNET peripheral.
  *         This parameter can be one of the following values:
  *         MDR_ETHERNET1, MDR_ETHERNET2 for MDR1986VE3 and
  *         MDR_ETHERNET1 for MDR1986VE1T.
  * @param  MacAddr: Pointer on MAC address buffer data (6 bytes) to configure.
  * @retval	None
  */
void ETH_MACAddressConfig(MDR_ETHERNET_TypeDef * ETHERNETx, uint16_t *MacAddr)
{
	/* Check the parameters */
	assert_param(IS_ETH_ALL_PERIPH(ETHERNETx));

	ETHERNETx->ETH_MAC_T = MacAddr[0];
	ETHERNETx->ETH_MAC_M = MacAddr[1];
	ETHERNETx->ETH_MAC_H = MacAddr[2];
}

/**
  * @brief	Get the selected MAC address.
  * @param	ETHERNETx: Slect the ETHERNET peripheral.
  *         This parameter can be one of the following values:
  *         MDR_ETHERNET1, MDR_ETHERNET2 for MDR1986VE3 and
  *         MDR_ETHERNET1 for MDR1986VE1T.
  * @param	MacAddr: Pointer on MAC address buffer data (6 bytes) to return.
  * @retval	None
  */
void ETH_GetMACAddress(MDR_ETHERNET_TypeDef * ETHERNETx, uint16_t *MacAddr)
{
	/* Check the parameters */
	assert_param(IS_ETH_ALL_PERIPH(ETHERNETx));

	MacAddr[0] = ETHERNETx->ETH_MAC_T;
	MacAddr[1] = ETHERNETx->ETH_MAC_M;
	MacAddr[2] = ETHERNETx->ETH_MAC_H;
}

/**
  * @brief	Checks whether the specified ETHERNET MAC flag is set or not.
  * @param	ETHERNETx: Slect the ETHERNET peripheral.
  *         This parameter can be one of the following values:
  *         MDR_ETHERNET1, MDR_ETHERNET2 for MDR1986VE3 and
  *         MDR_ETHERNET1 for MDR1986VE1T.
  * @param	ETH_PHY_FLAG: specifies the flag to check.
  * 		This parameter can be one of the following values:
  * 			@arg ETH_PHY_FLAG_MDINT
  *				@arg ETH_PHY_FLAG_MDO
  *				@arg ETH_PHY_FLAG_FX_VALID
  *				@arg ETH_PHY_FLAG_COL
  *				@arg ETH_PHY_FLAG_CRS
  *				@arg ETH_PHY_FLAG_READY
  *				@arg ETH_PHY_FLAG_FULL_DUPLEX
  *				@arg ETH_PHY_FLAG_CARRIER_SENSE
  *				@arg ETH_PHY_FLAG_LINK
  *				@arg ETH_PHY_FLAG_100MBIT
  * @retval	The new state of ETHERNET PHY flag (SET or RESET).
  */
FlagStatus ETH_GetPHYStatus(MDR_ETHERNET_TypeDef * ETHERNETx, uint16_t ETH_PHY_FLAG)
{
	FlagStatus bitstatus;

	/* Check the parameters */
	assert_param(IS_ETH_ALL_PERIPH(ETHERNETx));
	assert_param(IS_ETH_PHY_FLAG(ETH_PHY_FLAG));

	if(ETHERNETx->PHY_Status & ETH_PHY_FLAG){
		bitstatus = SET;
	}
	else{
		bitstatus = RESET;
	}
	return (bitstatus);
}

/**
  * @brief	Read a PHY register.
  * @param	ETHERNETx: Slect the ETHERNET peripheral.
  *         This parameter can be one of the following values:
  *         MDR_ETHERNET1, MDR_ETHERNET2 for MDR1986VE3 and
  *         MDR_ETHERNET1 for MDR1986VE1T.
  * @param	PHYAddress: PHY device address, is the index of one of supported 32 PHY devices.
  *   		This parameter can be one of the following values: 0,..,31
  * @param	PHYReg: PHY register address, is the index of one of the 32 PHY register.
  *   		This parameter can be one of the following values:
  *   			@arg	PHY_BCR
  *   			@arg	PHY_BSR
  *   			@arg	PHY_ID1
  *   			@arg	PHY_ID2
  *   			@arg	PHY_ATU
  *   			@arg	PHY_OPP_ATU
  *   			@arg	PHY_EATU
  *   			@arg	PHY_EMODE
  *   			@arg	PHY_IT_FLAGs
  *   			@arg	PHY_IT_MASKs
  *   			@arg	PHY_ECTR
  * @retval	ETH_ERROR: in case of timeout.
  *         MAC register value: Data read from the selected PHY register (correct read ).
  */
uint16_t ETH_ReadPHYRegister(MDR_ETHERNET_TypeDef * ETHERNETx, uint16_t PHYAddress, uint16_t PHYReg)
{
	uint32_t tmpreg = 0;
	__IO uint32_t timeout = 0;
	/* Check the parameters */
	assert_param(IS_ETH_ALL_PERIPH(ETHERNETx));
	assert_param(IS_ETH_PHY_ADDRESS(PHYAddress));
	assert_param(IS_ETH_PHYReg(PHYReg));

	/* Get the ETHERNET MACMIIAR value */
	tmpreg = ETHERNETx->ETH_MDIO_CTRL;
	/* Keep only the CSR Clock Range CR[2:0] bits value */
	tmpreg &= ETH_MDIO_CTRL_DIV_Msk;
	/* Prepare the MII address register value */
	tmpreg |= (uint32_t)(PHYAddress << 8) | (PHYReg << 0) | (1 << ETH_MDIO_CTRL_OP_Pos) | (1 << ETH_MDIO_CTRL_RDY_Pos) | (1 << ETH_MDIO_CTRL_PRE_EN_Pos) | (1<<5);
	/* Write the result value into the MDIO_CTRL register */
	ETHERNETx->ETH_MDIO_CTRL = tmpreg;
	do{
		timeout++;
		tmpreg = ETHERNETx->ETH_MDIO_CTRL;
	}while(((tmpreg & ETH_MDIO_CTRL_RDY) == 0 ) && (timeout < PHY_READ_TO));

	/* Return ERROR in case of timeout */
	if(timeout == PHY_READ_TO){
		return ((uint16_t)ETH_ERROR);
	}
	/* Return data register value */
	return ((uint16_t)ETHERNETx->ETH_MDIO_DATA);
}

/**
  * @brief	Write to a PHY register.
  * @param	ETHERNETx: Slect the ETHERNET peripheral.
  *         This parameter can be one of the following values:
  *         MDR_ETHERNET1, MDR_ETHERNET2 for MDR1986VE3 and
  *         MDR_ETHERNET1 for MDR1986VE1T.
  * @param	PHYAddress: PHY device address, is the index of one of supported 32 PHY devices.
  * 		This parameter can be one of the following values: 0,..,31.
  * @param	PHYReg: PHY register address, is the index of one of the 32 PHY register.
  *   		This parameter can be one of the following values:
  *   			@arg	PHY_BCR
  *   			@arg	PHY_BSR
  *   			@arg	PHY_ID1
  *   			@arg	PHY_ID2
  *   			@arg	PHY_ATU
  *   			@arg	PHY_OPP_ATU
  *   			@arg	PHY_EATU
  *   			@arg	PHY_EMODE
  *   			@arg	PHY_IT_FLAGs
  *   			@arg	PHY_IT_MASKs
  *   			@arg	PHY_ECTR
  * @param  PHYValue: the value to write.
  * @retval	ETH_ERROR: in case of timeout.
  *         ETH_SUCCESS: for correct write.
  */
uint32_t ETH_WritePHYRegister(MDR_ETHERNET_TypeDef * ETHERNETx, uint16_t PHYAddress, uint16_t PHYReg, uint16_t PHYValue)
{
	uint32_t tmpreg = 0;
	__IO uint32_t timeout = 0;
	/* Check the parameters */
	assert_param(IS_ETH_ALL_PERIPH(ETHERNETx));
	assert_param(IS_ETH_PHY_ADDRESS(PHYAddress));
	assert_param(IS_ETH_PHYReg(PHYReg));

	/* Get the ETHERNET MACMIIAR value */
	tmpreg = ETHERNETx->ETH_MDIO_CTRL;
	/* Keep only the CSR Clock Range CR[2:0] bits value */
	tmpreg &= ~ETH_MDIO_CTRL_DIV_Msk;
	
	tmpreg &= ~(1 << ETH_MDIO_CTRL_OP_Pos);
	/* Prepare the MII address register value */
	tmpreg |= (uint32_t)(PHYAddress << 8) | (PHYReg << 0) | (0 << ETH_MDIO_CTRL_OP_Pos) | (1 << ETH_MDIO_CTRL_RDY_Pos) | (1 << ETH_MDIO_CTRL_PRE_EN_Pos) | (1<<5);
	/* Give the value to the MII data register */
	ETHERNETx->ETH_MDIO_DATA = PHYValue;
	/* Write the result value into the MDIO_CTRL register */
	ETHERNETx->ETH_MDIO_CTRL = tmpreg;
	do{
		timeout++;
		tmpreg = ETHERNETx->ETH_MDIO_CTRL;
	}while(((tmpreg & ETH_MDIO_CTRL_RDY) == 0 ) && (timeout < PHY_READ_TO));

	/* Return ERROR in case of timeout */
	if(timeout == PHY_READ_TO){
		return ((uint16_t)ETH_ERROR);
	}
	/* Return SUCCESS */
	return ((uint16_t)ETH_SUCCESS);
}

/**
  * @brief	Read the input ethenet frame.
  * @param	ETHERNETx: Slect the ETHERNET peripheral.
  *         This parameter can be one of the following values:
  *         MDR_ETHERNET1, MDR_ETHERNET2 for MDR1986VE3 and
  *         MDR_ETHERNET1 for MDR1986VE1T.
  * @param	ptr_InputBuffer: pointer to buffer for reading input frame.
  * @retval	The status of the reading frame.
  */
uint32_t ETH_ReceivedFrame(MDR_ETHERNET_TypeDef * ETHERNETx, uint32_t * ptr_InputBuffer)
{
	ETH_StatusPacketReceptionTypeDef ETH_StatusPacketReceptionStruct;
	uint32_t PacketLength, i, Rhead, EthBaseBufferAddr, * ptr_InputFrame, tmp;
	uint16_t BufferMode;
	int32_t EthReceiverFreeBufferSize;
  uint32_t RHead;

	/* Check the parameters */
	assert_param(IS_ETH_ALL_PERIPH(ETHERNETx));

	/* Read the buffer mode */
	BufferMode = (ETHERNETx->ETH_G_CFGl & ETH_G_CFGl_BUFF_MODE_Msk);
	switch (BufferMode){
		/* The buffer mode is linear */
		case ETH_BUFFER_MODE_LINEAR:
			Rhead = ETHERNETx->ETH_R_Head;
			/* Set pointer to the status word reading message */
			ptr_InputFrame = (uint32_t *)((EthBaseBufferAddr = ((uint32_t)ETHERNETx) + 0x08000000) + Rhead);
			/* Read the status of the receiving a packet */
			ETH_StatusPacketReceptionStruct.Status = (uint32_t)*ptr_InputFrame++;
			PacketLength = (ETH_StatusPacketReceptionStruct.Fields.Length + 3)/4;
			/* Read the input frame */
			EthReceiverFreeBufferSize = (uint32_t) (ETHERNETx->ETH_Dilimiter - Rhead) - PacketLength*4;
			if(EthReceiverFreeBufferSize > 0){
				/* Read the input frame */
				for(i = 0; i < PacketLength; i++){
					ptr_InputBuffer[i] = *ptr_InputFrame++;
				}
			}
			else{
				/* Read the the first part of the packet */
				for(i = 0; i < (PacketLength*4 + EthReceiverFreeBufferSize)/4 - 1; i++){
					ptr_InputBuffer[i] = *ptr_InputFrame++;
				}
				/* Set pointer to second part of the packet */
				ptr_InputFrame = (uint32_t *)EthBaseBufferAddr;
				EthReceiverFreeBufferSize = 0 - EthReceiverFreeBufferSize;
				tmp = i;
				/* Read the the second part of the packet */
				for( i = 0; i < (EthReceiverFreeBufferSize/4) + 1; i++){
					ptr_InputBuffer[tmp + i] = *ptr_InputFrame++;
				}
			}
			/* Set the new value of the ETH_R_Head register */
      RHead = ((uint32_t)ptr_InputFrame)&0x1FFF;
      if (RHead < ETHERNETx->ETH_Dilimiter)
        ETHERNETx->ETH_R_Head = RHead;
      else
        ETHERNETx->ETH_R_Head = 0;
			break;
		/* The buffer mode is aoutomatic */
		case ETH_BUFFER_MODE_AUTOMATIC_CHANGE_POINTERS:
			/* Set the pointer to input frame */
			Rhead = ETHERNETx->ETH_R_Head;
			ptr_InputFrame = (uint32_t *)((EthBaseBufferAddr = ((uint32_t)ETHERNETx) + 0x08000000) + Rhead);
			/* Read the status of the receiving a packet */
			ETH_StatusPacketReceptionStruct.Status = (uint32_t)*ptr_InputFrame++;
			/* Set the Length of receiving paket */
			PacketLength = ((ETH_StatusPacketReceptionStruct.Fields.Length & 0x0003) != 0) + ETH_StatusPacketReceptionStruct.Fields.Length/4;
			/* Get the size of recever buffer */
			EthReceiverFreeBufferSize = (uint32_t) (ETHERNETx->ETH_Dilimiter - Rhead) - PacketLength*4;
			if(EthReceiverFreeBufferSize > 0){
				/* Read the input frame */
				for(i = 0; i < PacketLength; i++){
					ptr_InputBuffer[i] = *ptr_InputFrame++;
				}
			}
			else{
				/* Read the the first part of the packet */
				for(i = 0; i < (PacketLength*4 + EthReceiverFreeBufferSize)/4 - 1; i++){
					ptr_InputBuffer[i] = *ptr_InputFrame++;
				}
				/* Set pointer to second part of the packet */
				ptr_InputFrame = (uint32_t *)EthBaseBufferAddr;
				EthReceiverFreeBufferSize = 0 - EthReceiverFreeBufferSize;
				tmp = i;
				/* Read the the second part of the packet */
				for( i = 0; i < (EthReceiverFreeBufferSize/4) + 1; i++){
					ptr_InputBuffer[tmp + i] = *ptr_InputFrame++;
				}
			}
			break;
		/* The buffer mode is FIFO */
		case ETH_BUFFER_MODE_FIFO:
			/* Set the pointer to input frame */
			ptr_InputFrame = (uint32_t *) ((uint32_t)ETHERNETx + 0x08000000);
			/* Read the status of the receiving a packet */
			ETH_StatusPacketReceptionStruct.Status = (uint32_t)*ptr_InputFrame;
			/* Set the Length of receiving paket */
			PacketLength = ((ETH_StatusPacketReceptionStruct.Fields.Length & 0x0003) != 0) + ETH_StatusPacketReceptionStruct.Fields.Length/4;
			/* Read the input frame */
			ETH_DMAFrameRx((uint32_t * )&ptr_InputBuffer[0],  PacketLength, ptr_InputFrame);
			break;
	}
	/* Return status reading message */
	return (ETH_StatusPacketReceptionStruct.Status);
}

/**
  * @brief	Send the ethernet frame.
  * @param	ETHERNETx: Slect the ETHERNET peripheral.
  *         This parameter can be one of the following values:
  *         MDR_ETHERNET1, MDR_ETHERNET2 for MDR1986VE3 and
  *         MDR_ETHERNET1 for MDR1986VE1T.
  * @param	ptr_OututBuffer: pointer to the sending frame.
  * @param	BufLen: the size of the sending frmae.
  * @retval	None
  */
void ETH_SendFrame(MDR_ETHERNET_TypeDef * ETHERNETx, uint32_t * ptr_OutputBuffer, uint32_t BufLen)
{
	uint32_t BufferMode, i, Xtail, tmp;
	uint32_t * ptr_OutputFrame;
	int32_t EthReceiverFreeBufferSize;

	/* Check the parameters */
	assert_param(IS_ETH_ALL_PERIPH(ETHERNETx));

	/* Read the buffer mode */
	BufferMode = (ETHERNETx->ETH_G_CFGl & ETH_G_CFGl_BUFF_MODE_Msk);
	/* Send packet */
	Xtail = ETHERNETx->ETH_X_Tail;

	switch (BufferMode){
		case ETH_BUFFER_MODE_LINEAR:
			/* Set pointer to output buffer */
			ptr_OutputFrame = (uint32_t *)((((uint32_t)ETHERNETx) + 0x08000000) + Xtail);
			/* Send frame */
			EthReceiverFreeBufferSize = (ETH_BUFFER_SIZE - Xtail) / 4;
			if(((BufLen +3)/4 + 1) < EthReceiverFreeBufferSize){
				for( i = 0; i < (BufLen + 3)/4 + 1; i++ ){
					*ptr_OutputFrame++ = ptr_OutputBuffer[i];
				}
			}
			else{
				for( i = 0; i < EthReceiverFreeBufferSize; i++ ){
					*ptr_OutputFrame++ = ptr_OutputBuffer[i];
				}
				tmp = i;
				ptr_OutputFrame = (uint32_t *)((((uint32_t)ETHERNETx) + 0x08000000) + ETHERNETx->ETH_Dilimiter);
				for(i = 0; i < (((BufLen + 3)/4 + 1) - EthReceiverFreeBufferSize); i++){
					*ptr_OutputFrame++ = ptr_OutputBuffer[i+tmp];
				}
			}
			ptr_OutputFrame++;
      Xtail = (uint32_t)ptr_OutputFrame&0x3FFC;
			if(Xtail >= ETH_BUFFER_SIZE)
				Xtail = ETHERNETx->ETH_Dilimiter;
			/* Write the new value of the ETH_X_Tail register */
			ETHERNETx->ETH_X_Tail = Xtail;
			break;
		case ETH_BUFFER_MODE_AUTOMATIC_CHANGE_POINTERS:
			/* Set pointer to output buffer */
			ptr_OutputFrame = (uint32_t *)((((uint32_t)ETHERNETx) + 0x08000000) + Xtail);
			/* Send frame */
			EthReceiverFreeBufferSize = (ETH_BUFFER_SIZE - Xtail) / 4;
			if(((BufLen +3)/4 + 2) < EthReceiverFreeBufferSize){
				for( i = 0; i < (BufLen + 3)/4 + 2; i++ ){
					*ptr_OutputFrame++ = ptr_OutputBuffer[i];
				}
			}
			else{
				for( i = 0; i < EthReceiverFreeBufferSize; i++ ){
					*ptr_OutputFrame++ = ptr_OutputBuffer[i];
				}
				tmp = i;
				ptr_OutputFrame = (uint32_t *)((((uint32_t)ETHERNETx) + 0x08000000) + ETHERNETx->ETH_Dilimiter);
				for(i = 0; i < (((BufLen + 3)/4 + 2) - EthReceiverFreeBufferSize); i++){
					*ptr_OutputFrame++ = ptr_OutputBuffer[i+tmp];
				}
			}
			break;
		case ETH_BUFFER_MODE_FIFO:
			/* Set the pointer to input frame */
			ptr_OutputFrame = (uint32_t *) ((uint32_t)ETHERNETx + 0x08000004);
			/* Send frame */
			ETH_DMAFrameTx(ptr_OutputFrame, ((BufLen+3)/4 + 2), ptr_OutputBuffer);
			break;
	}
}

/**
  * @brief	Init the DMA channel.
  * @param	None
  * @retval	None.
  */
void ETH_DMAPrepare(void)
{
	DMA_CtrlDataInitTypeDef DMA_PriCtrlStr;
	DMA_ChannelInitTypeDef DMA_InitStr;
	
	RST_CLK_PCLKcmd(RST_CLK_PCLK_DMA, ENABLE);
	DMA_DeInit();
	
	DMA_StructInit(&DMA_InitStr);

	/* Set Channel Structure */
	DMA_InitStr.DMA_PriCtrlData = &DMA_PriCtrlStr;
	DMA_InitStr.DMA_Priority = DMA_Priority_High;
	DMA_InitStr.DMA_UseBurst = DMA_BurstClear;
	DMA_InitStr.DMA_SelectDataStructure = DMA_CTRL_DATA_PRIMARY;
	/* Init DMA channel */
	DMA_Init(DMA_Channel_SW1, &DMA_InitStr);
    DMA_Init(DMA_Channel_SW2, &DMA_InitStr);
}

/**
  * @brief	Receives a frame on the ethernet DMA channel in FIFO mode.
  * @param	DstBuf: pouinter to destination array.
  * @param	BufferSize: size of the transmission.
  * @param	SrcBuf: pointer to source array.
  * @retval None
  */
void ETH_DMAFrameRx(uint32_t * DstBuf, uint32_t BufferSize, uint32_t *  SrcBuf)
{

	__IO uint32_t * ptrControltable;
	uint32_t tmpval;

	MDR_DMA->CHNL_PRIORITY_SET |= 1 << DMA_Channel_SW1;
	DMA_ControlTable[DMA_Channel_SW1].DMA_SourceEndAddr = (uint32_t)SrcBuf;
	DMA_ControlTable[DMA_Channel_SW1].DMA_DestEndAddr = ((uint32_t)DstBuf) + 4*(BufferSize-1);
	DMA_ControlTable[DMA_Channel_SW1].DMA_Control = DMA_DestIncWord
												  | DMA_SourceIncNo
												  | DMA_MemoryDataSize_Word
												  | DMA_Mode_AutoRequest
												  | DMA_Transfers_1024
												  | ((BufferSize - 1) << 4);

	/* Run channel */
	DMA_Cmd(DMA_Channel_SW1, ENABLE);
	DMA_Request(DMA_Channel_SW1);
	/* Get pointer to DMA control struct */
	ptrControltable = (uint32_t *)&DMA_ControlTable[DMA_Channel_SW1].DMA_Control;
	/* Wait while DMA running */
	while( 1 ){
		tmpval = (*ptrControltable)&0x7;
		if(tmpval == 0)
			break;
	}
	/* Disable DMA channel */
	DMA_Cmd(DMA_Channel_SW1, DISABLE);

}

/**
  * @brief	Send a frame on the ethernet DMA channel in FIFO mode.
  * @param	DstBuf: pouinter to destination array.
  * @param	BufferSize: size of the transmission.
  * @param	SrcBuf: pointer to source array.
  * @retval	None
  */
void ETH_DMAFrameTx(uint32_t * DstBuf, uint32_t BufferSize, uint32_t * SrcBuf)
{
	__IO uint32_t * ptrControltable;
	uint32_t tmpval;

	MDR_DMA->CHNL_PRIORITY_SET |= 1 << DMA_Channel_SW2;
	DMA_ControlTable[DMA_Channel_SW2].DMA_SourceEndAddr = (uint32_t)SrcBuf + 4*(BufferSize-1);
	DMA_ControlTable[DMA_Channel_SW2].DMA_DestEndAddr = (uint32_t)DstBuf;
	DMA_ControlTable[DMA_Channel_SW2].DMA_Control = DMA_DestIncNo
												  | DMA_SourceIncWord
												  | DMA_MemoryDataSize_Word
												  | DMA_Mode_AutoRequest

												  | DMA_Transfers_1024
												  | ((BufferSize - 1) << 4);
	/* Run channel */
	DMA_Cmd(DMA_Channel_SW2, ENABLE);
	DMA_Request(DMA_Channel_SW2);
	/* Get pointer to DMA control struct */
	ptrControltable = (uint32_t *)&DMA_ControlTable[DMA_Channel_SW2].DMA_Control;
	/* Wait while DMA running */
	while( 1 ){
		tmpval = (*ptrControltable)&0x7;
		if(tmpval == 0)
			break;
	}
	/* Disable DMA channel */
	DMA_Cmd(DMA_Channel_SW2, DISABLE);
}

/** @} */ /* End of group ETH_Private_Functions */

#endif /* #if defined (USE_MDR1986VE1T) || defined (USE_MDR1986VE3) */

/** @} */ /* End of group ETHERNET ETHERNET  */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

/*
*
* END OF FILE MDR32F9Qx_eth.c */
