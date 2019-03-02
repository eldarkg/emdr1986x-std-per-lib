/**
  ******************************************************************************
  * @file    mdr32f8_uart.c
  * @author  Milandr
  * @version V1.0.0
  * @date    20/07/2015
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of the Universal asynchronous receiver
  *          transmitter (UART):           
  *           + Initialization and Configuration
  *           + Data transfers
  *
  *
  * <h2><center>&copy; COPYRIGHT 2015 Milandr</center></h2>
  ******************************************************************************
  * FILE mdr32f8_uart.c
  */
	
	/* Includes ------------------------------------------------------------------*/
#include "mdr32f8_uart.h"
#include "mdr32f8_clkctrl.h"
#include "MDR1986VE8T.h"

#define ASSERT_INFO_FILE_ID FILEID__MDR32F8_UART

/** @addtogroup __MDR32F8_StdPeriph_Driver
  * @{
  */

/** @defgroup UART
  * @{
  */

/** @defgroup UART_Private_Defines
  * @{
  */
	
#define CR_EN_Set                 ((uint16_t)0x0001)  /*!< UART Enable Mask */
#define CR_EN_Reset               ((uint16_t)0xFFFE)  /*!< UART Disable Mask */
#define CR_FC_Mask                ((uint16_t)0xFF80)  /*!< UART CR Flow control Bits Mask */
#define FBRD_Fract_Mask           ((uint16_t)0x003F)  /*!< Fractional divider Mask */

/**
  * @}
  */ 

/** @defgroup UART_Private_Functions
  * @{
  */

/**
  * @brief  Resets the UARTx peripheral registers to their default reset values.
  * @param  UARTx: Select the UART peripheral.
  *         This parameter can be one of the following values: UART0.
  * @retval None
  */
void UART_DeInit(MDR_UART_TypeDef* UARTx)
{
  /* Clear UART CR */
  UARTx->CR = 0;
  UARTx->LCR_H = 0;
  UARTx->RSR_ECR = 0;
  UARTx->FR = UART_FLAG_TXFE | UART_FLAG_RXFE;
  UARTx->ILPR = 0;
  UARTx->IBRD = 0;
  UARTx->FBRD = 0;
  UARTx->IMSC = 0;
  UARTx->DMACR = 0;
  /* Set UART CR[RXE] and UART CR[TXE] bits */
  UARTx->CR = UART_HardwareFlowControl_RXE | UART_HardwareFlowControl_TXE;
}	

/**
  * @brief  Initializes the UARTx peripheral according to the specified
  *         parameters in the UART_InitStruct.
  * @param  UARTx: Select the UART peripheral.
  *         This parameter can be one of the following values:
  *         UART0.
  * @param  UART_InitStruct: pointer to a UART_InitTypeDef structure
  *         that contains the configuration information for the specified UART peripheral.
  * @retval The Baud Rate status (BaudRateValid or BaudRateInvalid).
  */
BaudRateStatus UART_Init ( MDR_UART_TypeDef* UARTx,
						   UART_InitTypeDef* UART_InitStruct, uint32_t UART_freq)
{
	uint32_t tmpreg, cpuclock;
	uint32_t realspeed, speederror;
	uint32_t divider;
	uint32_t integerdivider;
	uint32_t fractionaldivider;

	/* Configure the UART Baud Rate */
	cpuclock = UART_freq;
	/* Determine the integer part */
	divider = cpuclock / (UART_InitStruct->UART_BaudRate >> 2);	
	integerdivider = divider >> 6;
	/* Determine the fractional part */
	fractionaldivider = (divider & FBRD_Fract_Mask);
	/* Determine the speed error */
	realspeed = (cpuclock * 4) / ((integerdivider * 64) + fractionaldivider);
	speederror = ((realspeed - UART_InitStruct->UART_BaudRate) * 128)
			/ UART_InitStruct->UART_BaudRate;
	if (speederror > 2) {
		return BaudRateInvalid;
	}
	/* Write UART Baud Rate */
	UARTx->IBRD = integerdivider;
	UARTx->FBRD = fractionaldivider;
	/* UART LCR_H configuration */
	/* Set the WLEN bits according to UART_WordLength value */
	/* Set STP2 bit according to UART_StopBits value */
	/* Set PEN, EPS and SPS bits according to UART_Parity value */
	/* Set FEN bit according to UART_FIFOMode value */
	tmpreg = UARTx->LCR_H;
	tmpreg |= UART_InitStruct->UART_WordLength | UART_InitStruct->UART_StopBits
			| UART_InitStruct->UART_Parity | UART_InitStruct->UART_FIFOMode;
	UARTx->LCR_H = tmpreg;

	/* UART CR configuration */
	tmpreg = UARTx->CR;
	/* Clear UART CR Flow control bits */
	tmpreg &= ~CR_FC_Mask;
	/* Set UART CR Flow control bits */
	tmpreg |= UART_InitStruct->UART_HardwareFlowControl;
	/* Write to UART CR */
	UARTx->CR = tmpreg;

	return BaudRateValid;
}

/**
  * @brief  Enables or disables the specified UART peripheral.
  * @param  UARTx: Select the UART peripheral.
  *         This parameter can be one of the following values:
  *         UART0.
  * @param  NewState: new state of the UARTx peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void UART_Cmd(MDR_UART_TypeDef* UARTx, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  if (NewState != DISABLE)
  {
    /* Enable the selected UART by setting the UARTEN bit in the CR register */
    UARTx->CR |= CR_EN_Set;
  }
  else
  {
    /* Disable the selected UART by clearing the UARTEN bit in the CR register */
    UARTx->CR &= CR_EN_Reset;
  }
}
/**
  * @brief  Checks whether the specified UART flag is set or not.
  * @param  UARTx: Select the UART or the UART peripheral.
  *         This parameter can be one of the following values:
  *         UART0.
  * @param  UART_FLAG: specifies the flag to check.
  *         This parameter can be one of the following values:
  *           @arg UART_FLAG_RI  : nUARTRI line inverted value
  *           @arg UART_FLAG_TXFE: Transmit buffer is empty flag
  *           @arg UART_FLAG_RXFF: Receive buffer is full flag
  *           @arg UART_FLAG_TXFF: Transmit buffer is full flag
  *           @arg UART_FLAG_RXFE: Receive buffer is empty flag
  *           @arg UART_FLAG_BUSY: Transmit Busy flag
  *           @arg UART_FLAG_DCD:  nUARTDCD line inverted value
  *           @arg UART_FLAG_DSR:  nUARTDSR line inverted value
  *           @arg UART_FLAG_CTS:  nUARTCTS line inverted value
  * @retval The new state of UART_FLAG (SET or RESET).
  */
FlagStatus UART_GetFlagStatus(MDR_UART_TypeDef* UARTx, uint32_t UART_FLAG)
{
  FlagStatus bitstatus;

  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
  assert_param(IS_UART_FLAG(UART_FLAG));

  if (UARTx->FR & UART_FLAG)
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
  * @brief  Transmits single data through the UARTx peripheral.
  * @param  UARTx: Select the UART peripheral.
  *         This parameter can be one of the following values:
  *         UART0.
  * @param  Data: the data to transmit.
  * @retval None
  */
void UART_SendData(MDR_UART_TypeDef* UARTx, uint16_t Data)
{
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
  assert_param(IS_UART_DATA(Data));

  /* Transmit Data */
  UARTx->DR = (Data & (uint16_t)0x0FF);
}
/**
  * @brief  Returns the most recent received data by the UARTx peripheral.
  * @param  UARTx: Select the UART peripheral.
  *         This parameter can be one of the following values:
  *         UART0.
  * @retval The received data (7:0) and error flags (15:8).
  */
uint16_t UART_ReceiveData(MDR_UART_TypeDef* UARTx)
{
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
  /* Receive Data */
  return (uint16_t)(UARTx->DR);
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
void UART_CLK_en(uint32_t UART_CLKSRC, uint32_t UART_CLK_DIV)
{
  uint32_t tmpreg;
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
	assert_param(IS_UART_CLKSRC(UART_CLKSRC));

  tmpreg = CLK_CNTR->UART0_CLK;

  tmpreg |=  UART_CLK_EN;
  tmpreg &= ~UART_DIV_Msk;
  tmpreg |=  UART_CLK_DIV;
	tmpreg &= ~UART_CLKSRC_msk;
	tmpreg |=  UART_CLKSRC<<UART_CLKSRC_offs;

  CLK_CNTR->UART0_CLK = tmpreg;
}

/**
  * @brief  Checks whether the specified UART interrupt (masked) has occurred or not.
  * @param  UARTx: Select the UART peripheral.
  *         This parameter can be one of the following values:
  *         UART0.
  * @param  UART_IT: specifies the UART interrupt source to check.
  *         This parameter can be one of the following values:
  *           @arg UART_IT_OE:  Buffer overflow interrupt (UARTOEINTR).
  *           @arg UART_IT_BE:  Line break interrupt (UARTBEINTR).
  *           @arg UART_IT_PE:  Parity error interrupt (UARTPEINTR).
  *           @arg UART_IT_FE:  Frame structure error interrupt (UARTFEINTR).
  *           @arg UART_IT_RT:  Data input timeout interrupt (UARTRTINTR).
  *           @arg UART_IT_TX:  Transmitter interrupt (UARTTXINTR).
  *           @arg UART_IT_RX:  Receiver interrupt (UARTRXINTR).
  *           @arg UART_IT_DSR: Line nUARTDSR change interrupt (UARTDSRINTR).
  *           @arg UART_IT_DCD: Line nUARTDCD change interrupt (UARTDCDINTR).
  *           @arg UART_IT_CTS: Line nUARTCTS change interrupt (UARTCTSINTR).
  *           @arg UART_IT_RI:  Line nUARTRI change interrupt (UARTRIINTR).
  * @retval The new state of UART_IT (SET or RESET).
  */
	
ITStatus UART_GetITStatusMasked(MDR_UART_TypeDef* UARTx, uint32_t UART_IT)
{
  ITStatus bitstatus;

  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
  assert_param(IS_UART_CONFIG_IT(UART_IT));

  if (UARTx->MIS & UART_IT)
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
  * @brief  Clears the UARTx’s interrupt pending bits.
  * @param  UARTx: Select the UART or the UART peripheral.
  *         This parameter can be one of the following values:
  *         UART0.
  * @param  UART_IT: specifies the interrupt pending bit to clear.
  *         This parameter can be one of the following values:
  *           @arg UART_IT_OE:  Buffer overflow interrupt (UARTOEINTR).
  *           @arg UART_IT_BE:  Line break interrupt (UARTBEINTR).
  *           @arg UART_IT_PE:  Parity error interrupt (UARTPEINTR).
  *           @arg UART_IT_FE:  Frame structure error interrupt (UARTFEINTR).
  *           @arg UART_IT_RT:  Data input timeout interrupt (UARTRTINTR).
  *           @arg UART_IT_TX:  Transmitter interrupt (UARTTXINTR).
  *           @arg UART_IT_RX:  Receiver interrupt (UARTRXINTR).
  *           @arg UART_IT_DSR: Line nUARTDSR change interrupt (UARTDSRINTR).
  *           @arg UART_IT_DCD: Line nUARTDCD change interrupt (UARTDCDINTR).
  *           @arg UART_IT_CTS: Line nUARTCTS change interrupt (UARTCTSINTR).
  *           @arg UART_IT_RI:  Line nUARTRI change interrupt (UARTRIINTR).
  * @retval None
  */
void UART_ClearITPendingBit(MDR_UART_TypeDef* UARTx, uint32_t UART_IT)
{
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
  assert_param(IS_UART_CONFIG_IT(UART_IT));

  UARTx->ICR |= UART_IT;
}

/**
  * @brief  Enables or disables the specified UART interrupts.
  * @param  UARTx: Select the UART peripheral.
  *         This parameter can be one of the following values:
  *         UART0.
  * @param  UART_IT: specifies the UART interrupt sources to be enabled or disabled.
  *         This parameter can be one of the following values:
  *           @arg UART_IT_OE:  Buffer overflow interrupt (UARTOEINTR).
  *           @arg UART_IT_BE:  Line break interrupt (UARTBEINTR).
  *           @arg UART_IT_PE:  Parity error interrupt (UARTPEINTR).
  *           @arg UART_IT_FE:  Frame structure error interrupt (UARTFEINTR).
  *           @arg UART_IT_RT:  Data input timeout interrupt (UARTRTINTR).
  *           @arg UART_IT_TX:  Transmitter interrupt (UARTTXINTR).
  *           @arg UART_IT_RX:  Receiver interrupt (UARTRXINTR).
  *           @arg UART_IT_DSR: Line nUARTDSR change interrupt (UARTDSRINTR).
  *           @arg UART_IT_DCD: Line nUARTDCD change interrupt (UARTDCDINTR).
  *           @arg UART_IT_CTS: Line nUARTCTS change interrupt (UARTCTSINTR).
  *           @arg UART_IT_RI:  Line nUARTRI change interrupt (UARTRIINTR).
  * @param  NewState: new state of the specified UARTx interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void UART_ITConfig(MDR_UART_TypeDef* UARTx, uint32_t UART_IT, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
  assert_param(IS_UART_CONFIG_IT(UART_IT));
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  if (NewState != DISABLE)
  {
    UARTx->IMSC |= UART_IT;
  }
  else
  {
    UARTx->IMSC &= ~UART_IT;
  }
}

/**
  * @}
  */ 

/**
  * @}
  */  /* End of group __MDR32F8_StdPeriph_Driver */