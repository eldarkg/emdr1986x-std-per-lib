/**
  * FILE MDR32F9Qx_port.c
  */

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_port.h"

#define ASSERT_INFO_FILE_ID FILEID__MDR32F9X_PORT_C

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @defgroup PORT PORT
  * @{
  */

/** @defgroup PORT_Private_Functions PORT Private Functions
  * @{
  */

/**
  * @brief  Resets the PORTx peripheral registers to their default reset values.
  * @param  PORTx: where x can be (A..F) to select the PORT peripheral.
  * @retval None
  */
void PORT_DeInit(MDR_PORT_TypeDef* PORTx)
{
  /* Check the parameters */
  assert_param(IS_PORT_ALL_PERIPH(PORTx));

  PORTx->ANALOG = 0;
  PORTx->PULL = 0;
  PORTx->OE = 0;
  PORTx->RXTX = 0;
  PORTx->FUNC = 0;
  PORTx->PD = 0;
  PORTx->PWR = 0;
  PORTx->GFEN = 0;
}


/**
  * @brief  Initializes the PORTx peripheral according to the specified
  *         parameters in the PORT_InitStruct.
  * @param  PORTx: where x can be (A..F) to select the PORT peripheral.
  * @param  PORT_InitStruct: pointer to a PORT_InitTypeDef structure that
  *         contains the configuration information for the specified PORT peripheral.
  * @retval None
  */
void PORT_Init(MDR_PORT_TypeDef* PORTx, const PORT_InitTypeDef* PORT_InitStruct)
{
  uint32_t tmpreg_OE;
  uint32_t tmpreg_FUNC;
  uint32_t tmpreg_ANALOG;
  uint32_t tmpreg_PULL;
  uint32_t tmpreg_PD;
  uint32_t tmpreg_PWR;
  uint32_t tmpreg_GFEN;
  uint32_t portpin, pos, mask_s, mask_l, mask_d;

  /* Check the parameters */
  assert_param(IS_PORT_ALL_PERIPH(PORTx));
  assert_param(IS_PORT_PIN(PORT_InitStruct->PORT_Pin));
  assert_param(IS_PORT_OE(PORT_InitStruct->PORT_OE));
  assert_param(IS_PORT_PULL_UP(PORT_InitStruct->PORT_PULL_UP));
  assert_param(IS_PORT_PULL_DOWN(PORT_InitStruct->PORT_PULL_DOWN));
  assert_param(IS_PORT_PD_SHM(PORT_InitStruct->PORT_PD_SHM));
  assert_param(IS_PORT_PD(PORT_InitStruct->PORT_PD));
  assert_param(IS_PORT_GFEN(PORT_InitStruct->PORT_GFEN));
  assert_param(IS_PORT_FUNC(PORT_InitStruct->PORT_FUNC));
  assert_param(IS_PORT_SPEED(PORT_InitStruct->PORT_SPEED));
  assert_param(IS_PORT_MODE(PORT_InitStruct->PORT_MODE));

  /* Get current PORT register values */
  tmpreg_OE     = PORTx->OE;
  tmpreg_FUNC   = PORTx->FUNC;
  tmpreg_ANALOG = PORTx->ANALOG;
  tmpreg_PULL   = PORTx->PULL;
  tmpreg_PD     = PORTx->PD;
  tmpreg_PWR    = PORTx->PWR;
  tmpreg_GFEN   = PORTx->GFEN;

  /* Form new values */
  pos = 0;
  mask_s = 0x0001;
  mask_l = 0x00000003;
  mask_d = 0x00010001;
  for (portpin = PORT_InitStruct->PORT_Pin; portpin; portpin >>= 1)
  {
    if (portpin & 0x1)
    {
      tmpreg_OE     = (tmpreg_OE     & ~mask_s) | (PORT_InitStruct->PORT_OE        <<  pos);
      tmpreg_FUNC   = (tmpreg_FUNC   & ~mask_l) | (PORT_InitStruct->PORT_FUNC      << (pos*2));
      tmpreg_ANALOG = (tmpreg_ANALOG & ~mask_s) | (PORT_InitStruct->PORT_MODE      <<  pos);
      tmpreg_PULL   = (tmpreg_PULL   & ~mask_d) | (PORT_InitStruct->PORT_PULL_UP   << (pos + 16))
                                                | (PORT_InitStruct->PORT_PULL_DOWN <<  pos);
      tmpreg_PD     = (tmpreg_PD     & ~mask_d) | (PORT_InitStruct->PORT_PD_SHM    << (pos + 16))
                                                | (PORT_InitStruct->PORT_PD        <<  pos);
      tmpreg_PWR    = (tmpreg_PWR    & ~mask_l) | (PORT_InitStruct->PORT_SPEED     << (pos*2));
      tmpreg_GFEN   = (tmpreg_GFEN   & ~mask_s) | (PORT_InitStruct->PORT_GFEN      <<  pos);
    }
    mask_s <<= 1;
    mask_l <<= 2;
    mask_d <<= 1;
    pos++;
  }
#if defined  (USE_MDR1986VE9x) || defined (USE_MDR1901VC1T)
  /* Configure PORT registers with new values */
  PORTx->OE     = tmpreg_OE & (~JTAG_PINS(PORTx));
  PORTx->FUNC   = tmpreg_FUNC & (~JTAG_PINS(PORTx));
  PORTx->ANALOG = tmpreg_ANALOG & (~JTAG_PINS(PORTx));
  PORTx->PULL   = tmpreg_PULL & (~JTAG_PINS(PORTx));
  PORTx->PD     = tmpreg_PD & (~JTAG_PINS(PORTx));
  PORTx->PWR    = tmpreg_PWR & (~JTAG_PINS(PORTx));
  PORTx->GFEN   = tmpreg_GFEN & (~JTAG_PINS(PORTx));
#elif defined ( USE_MDR1986VE3 ) || defined (USE_MDR1986VE1T)
  /* Configure PORT registers with new values */
  PORTx->OE     = tmpreg_OE;
  PORTx->FUNC   = tmpreg_FUNC;
  PORTx->ANALOG = tmpreg_ANALOG;
  PORTx->PULL   = tmpreg_PULL;
  PORTx->PD     = tmpreg_PD;
  PORTx->PWR    = tmpreg_PWR;
  PORTx->GFEN   = tmpreg_GFEN;

#endif

}

/**
  * @brief  Fills each PORT_InitStruct member with its default value.
  * @param  PORT_InitStruct: pointer to a PORT_InitTypeDef structure which will
  *         be initialized.
  * @retval None
  */
void PORT_StructInit(PORT_InitTypeDef* PORT_InitStruct)
{
  /* Reset PORT initialization structure parameters values */
  PORT_InitStruct->PORT_Pin        = PORT_Pin_All;
  PORT_InitStruct->PORT_OE         = PORT_OE_IN;
  PORT_InitStruct->PORT_PULL_UP    = PORT_PULL_UP_OFF;
  PORT_InitStruct->PORT_PULL_DOWN  = PORT_PULL_DOWN_OFF;
  PORT_InitStruct->PORT_PD_SHM     = PORT_PD_SHM_OFF;
  PORT_InitStruct->PORT_PD         = PORT_PD_DRIVER;
  PORT_InitStruct->PORT_GFEN       = PORT_GFEN_OFF;
  PORT_InitStruct->PORT_FUNC       = PORT_FUNC_PORT;
  PORT_InitStruct->PORT_SPEED      = PORT_OUTPUT_OFF;
  PORT_InitStruct->PORT_MODE       = PORT_MODE_ANALOG;
}

/**
  * @brief  Reads the specified input port pin.
  * @param  PORTx: where x can be (A..F) to select the PORT peripheral.
  * @param  PORT_Pin: specifies the port bit to read.
  *         This parameter can be PORT_Pin_x where x can be (0..15).
  * @retval The input port pin value.
  */
uint8_t PORT_ReadInputDataBit(MDR_PORT_TypeDef* PORTx, uint32_t PORT_Pin)
{
  uint8_t bitstatus;

  /* Check the parameters */
  assert_param(IS_PORT_ALL_PERIPH(PORTx));
  assert_param(IS_GET_PORT_PIN(PORT_Pin));

  if ((PORTx->RXTX & PORT_Pin) != Bit_RESET)
  {
    bitstatus = (uint8_t)Bit_SET;
  }
  else
  {
    bitstatus = (uint8_t)Bit_RESET;
  }
  return bitstatus;
}

/**
  * @brief  Reads the specified PORT input data port.
  * @param  PORTx: where x can be (A..F) to select the PORT peripheral.
  * @retval PORT input data port value. Bits (16..31) are always 0.
  */
uint32_t PORT_ReadInputData(MDR_PORT_TypeDef* PORTx)
{
  /* Check the parameters */
  assert_param(IS_PORT_ALL_PERIPH(PORTx));

  return (PORTx->RXTX);
}

/**
  * @brief  Sets the selected data port bits.
  * @param  PORTx: where x can be (A..F) to select the PORT peripheral.
  * @param  PORT_Pin: specifies the port bits to be written.
  *         This parameter can be any combination of PORT_Pin_x where x can be (0..15).
  * @retval None
  */
void PORT_SetBits ( MDR_PORT_TypeDef* PORTx, uint32_t PORT_Pin )
{
	/* Check the parameters */
	assert_param(IS_PORT_ALL_PERIPH(PORTx));
	assert_param(IS_PORT_PIN(PORT_Pin));
	assert_param(IS_NOT_JTAG_PIN(PORTx, PORT_Pin));

#if defined  (USE_MDR1986VE9x) || defined (USE_MDR1901VC1T)
	PORTx->RXTX = PORT_Pin | (PORTx->RXTX & (~JTAG_PINS(PORTx)));
#endif

#if defined ( USE_MDR1986VE3 ) || defined (USE_MDR1986VE1T)
	PORTx->SETTX = PORT_Pin;
#endif
}

/**
  * @brief  Clears the selected data port bits.
  * @param  PORTx: where x can be (A..F) to select the PORT peripheral.
  * @param  PORT_Pin: specifies the port bits to be written.
  *         This parameter can be any combination of PORT_Pin_x where x can be (0..15).
  * @retval None
  */
void PORT_ResetBits(MDR_PORT_TypeDef* PORTx, uint32_t PORT_Pin)
{
  /* Check the parameters */
  assert_param(IS_PORT_ALL_PERIPH(PORTx));
  assert_param(IS_PORT_PIN(PORT_Pin));
  assert_param(IS_NOT_JTAG_PIN(PORTx, PORT_Pin));

#if defined  (USE_MDR1986VE9x) || defined (USE_MDR1901VC1T)
  PORTx->RXTX &= ~(PORT_Pin | JTAG_PINS(PORTx));
#endif

#if defined ( USE_MDR1986VE3 ) || defined (USE_MDR1986VE1T)
  PORTx->CLRTX = PORT_Pin;
#endif
}

/**
  * @brief  Sets or clears the selected data port bit.
  * @param  PORTx: where x can be (A..G) to select the PORT peripheral.
  * @param  PORT_Pin: specifies the port bit to be written.
  *         This parameter can be one of PORT_Pin_x where x can be (0..15).
  * @param  BitVal: specifies the value to be written to the selected bit.
  *         This parameter can be one of the BitAction enum values:
  *           @arg Bit_RESET: to clear the port pin
  *           @arg Bit_SET: to set the port pin
  * @retval None
  */
void PORT_WriteBit(MDR_PORT_TypeDef* PORTx, uint32_t PORT_Pin, BitAction BitVal)
{
  uint32_t portdata;
  /* Check the parameters */
  assert_param(IS_PORT_ALL_PERIPH(PORTx));
  assert_param(IS_GET_PORT_PIN(PORT_Pin));
  assert_param(IS_PORT_BIT_ACTION(BitVal));
  assert_param(IS_NOT_JTAG_PIN(PORTx, PORT_Pin));

  portdata = PORTx->RXTX & (~JTAG_PINS(PORTx));
  if (BitVal != Bit_RESET)
  {
    PORTx->RXTX = portdata | PORT_Pin;
  }
  else
  {
    PORTx->RXTX = portdata & (~PORT_Pin);
  }
}

/**
  * @brief  Writes data to the specified PORT data port.
  * @param  PORTx: where x can be (A..F) to select the PORT peripheral.
  * @param  PortVal: specifies the value to be written to the port output data register.
  *                  Bits (16..31) are ignored.
  * @retval None
  */
void PORT_Write(MDR_PORT_TypeDef* PORTx, uint32_t PortVal)
{
  /* Check the parameters */
  assert_param(IS_PORT_ALL_PERIPH(PORTx));
  assert_param(IS_NOT_JTAG_PIN(PORTx, PortVal));

  PORTx->RXTX = PortVal & (~JTAG_PINS(PORTx));
}

/** @} */ /* End of group PORT_Private_Functions */

/** @} */ /* End of group PORT */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

/*
*
* END OF FILE MDR32F9Qx_port.c */

