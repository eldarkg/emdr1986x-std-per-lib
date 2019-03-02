/**
  ******************************************************************************
  * @file    mdr32f8_port.c
  * @author  Milandr
  * @version V1.0.0
  * @date    20/07/2015
  * @brief   This file provides all the PORT firmware functions.
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
  * <h2><center>&copy; COPYRIGHT 2015 Milandr</center></h2>
  ******************************************************************************
  * FILE mdr32f8_port.c
  */

/* Includes ------------------------------------------------------------------*/
#include "mdr32f8_port.h"
#include "MDR1986VE8T.h"

#define ASSERT_INFO_FILE_ID FILEID__MDR32F8_PORT

/** @addtogroup __MDR32F8_StdPeriph_Driver MDR32F8 Standard Peripherial Driver
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

void PORT_DeInit(PortControl* PORTx)
{
  /* Check the parameters */
  assert_param(IS_PORT_ALL_PERIPH(PORTx));
	
	PORTx->CRXTX 			= 0xFFFFFFFF;
	PORTx->COE 				= 0xFFFFFFFF;
	PORTx->CFUNC[0] 	= 0xFFFFFFFF;
	PORTx->CFUNC[1] 	= 0xFFFFFFFF;
	PORTx->CFUNC[2] 	= 0xFFFFFFFF;
	PORTx->CFUNC[3] 	= 0xFFFFFFFF;
	PORTx->CANALOG 		= 0xFFFFFFFF;
	PORTx->CPULLUP 		= 0xFFFFFFFF;
	PORTx->CPULLDOWN 	= 0xFFFFFFFF;
	PORTx->CPD 				= 0xFFFFFFFF;
	PORTx->CPWR[0] 		= 0xFFFFFFFF;
	PORTx->CPWR[1] 		= 0xFFFFFFFF;
	PORTx->CCL 				= 0xFFFFFFFF;
	PORTx->CIE 				= 0xFFFFFFFF;
	PORTx->CIT 				= 0xFFFFFFFF;
	PORTx->CIR 				= 0xFFFFFFFF;	
}

/**
  * @brief  Initializes the PORTx peripheral according to the specified
  *         parameters in the PORT_InitStruct.
  * @param  PORTx: where x can be (A..F) to select the PORT peripheral.
  * @param  PORT_InitStruct: pointer to a PORT_InitTypeDef structure that
  *         contains the configuration information for the specified PORT peripheral.
  * @retval None
  */

void PORT_Init(PortControl* PORTx, const PORT_InitTypeDef* PORT_InitStruct)
{
  uint32_t portpin, pos, mask_s, mask_l, mask_FUNC, mask_FUNK_count, mask_l_count;
	
	uint32_t pp;
				
	uint32_t tmpreg_SOE;
	uint32_t tmpreg_SFUNC[4];
	uint32_t tmpreg_SANALOG;
	uint32_t tmpreg_SPULLUP;
	uint32_t tmpreg_SPULLDOWN;
	uint32_t tmpreg_SPD;
	uint32_t tmpreg_SPWR[2];
	uint32_t tmpreg_SCL;
	uint32_t tmpreg_SIE;
	uint32_t tmpreg_SIT;
	uint32_t tmpreg_SIR;
	
	uint32_t tmpreg_COE;
  uint32_t tmpreg_CFUNC[4];
  uint32_t tmpreg_CANALOG;
  uint32_t tmpreg_CPULLUP;
  uint32_t tmpreg_CPULLDOWN;
	uint32_t tmpreg_CPD;
	uint32_t tmpreg_CPWR[2];
  uint32_t tmpreg_CCL;
  uint32_t tmpreg_CIE;
  uint32_t tmpreg_CIT;
  uint32_t tmpreg_CIR;
		
	/* Check the parameters */
  assert_param(IS_PORT_ALL_PERIPH(PORTx));
  assert_param(IS_PORT_PIN(PORT_InitStruct->PORT_Pin));
	
  assert_param(IS_PORT_SOE(PORT_InitStruct->PORT_SOE));	
  assert_param(IS_PORT_SFUNC(PORT_InitStruct->PORT_SFUNC));	
  assert_param(IS_PORT_SANALOG(PORT_InitStruct->PORT_SANALOG));	
  assert_param(IS_PORT_SPULLUP(PORT_InitStruct->PORT_SPULLUP));	
  assert_param(IS_PORT_SPULLDOWN(PORT_InitStruct->PORT_SPULLDOWN));	
  assert_param(IS_PORT_SPD(PORT_InitStruct->PORT_SPD));
  assert_param(IS_PORT_SPWR(PORT_InitStruct->PORT_SPWR));	
  assert_param(IS_PORT_SCL(PORT_InitStruct->PORT_SCL));	
  assert_param(IS_PORT_SIE(PORT_InitStruct->PORT_SIE));	
  assert_param(IS_PORT_SIT(PORT_InitStruct->PORT_SIT));	
  assert_param(IS_PORT_SIR(PORT_InitStruct->PORT_SIR));	
	
	assert_param(IS_PORT_COE(PORT_InitStruct->PORT_COE));	
  assert_param(IS_PORT_CFUNC(PORT_InitStruct->PORT_CFUNC));	
  assert_param(IS_PORT_CANALOG(PORT_InitStruct->PORT_CANALOG));	
  assert_param(IS_PORT_CPULLUP(PORT_InitStruct->PORT_CPULLUP));	
  assert_param(IS_PORT_CPULLDOWN(PORT_InitStruct->PORT_CPULLDOWN));	
  assert_param(IS_PORT_CPD(PORT_InitStruct->PORT_CPD));
  assert_param(IS_PORT_CPWR(PORT_InitStruct->PORT_CPWR));	
  assert_param(IS_PORT_CCL(PORT_InitStruct->PORT_CCL));	
  assert_param(IS_PORT_CIE(PORT_InitStruct->PORT_CIE));	
  assert_param(IS_PORT_CIT(PORT_InitStruct->PORT_CIT));	
  assert_param(IS_PORT_CIR(PORT_InitStruct->PORT_CIR));	
		
  /* Get current PORT register values */
	tmpreg_SOE 				= PORTx->SOE;
  tmpreg_SFUNC[0] 	= PORTx->SFUNC[0];
	tmpreg_SFUNC[1] 	= PORTx->SFUNC[1];
	tmpreg_SFUNC[2] 	= PORTx->SFUNC[2];
	tmpreg_SFUNC[3] 	= PORTx->SFUNC[3];
  tmpreg_SANALOG 		= PORTx->SANALOG;
  tmpreg_SPULLUP 		= PORTx->SPULLUP;
  tmpreg_SPULLDOWN 	= PORTx->SPULLDOWN;
  tmpreg_SPD 				= PORTx->SPD;
  tmpreg_SPWR[0] 		= PORTx->SPWR[0];
	tmpreg_SPWR[1] 		= PORTx->SPWR[1];
  tmpreg_SCL 				= PORTx->SCL;
  tmpreg_SIE 				= PORTx->SIE;
  tmpreg_SIT 				= PORTx->SIT;
  tmpreg_SIR 				= PORTx->SIR;
		
  /* Form new values */
  pos = 0;
  mask_s = 0x0001;
  mask_l = 0x00000003;
	mask_FUNC = 0x0000000F;
	
	pp = PORT_InitStruct->PORT_Pin;
	
  for (portpin = PORT_InitStruct->PORT_Pin; portpin; portpin >>= 1)
  {
    if (portpin & 0x1)
    {					
			if (((PORT_InitStruct->PORT_Pin)&mask_s)<=0x0080U)//0-7
			{
			tmpreg_SFUNC[0]  	= (tmpreg_SFUNC[0]	& 	 ~(mask_FUNC<<(pos*4)))		| (PORT_InitStruct->PORT_SFUNC	<<			pos*4);
			tmpreg_CFUNC[0]  	= (tmpreg_CFUNC[0]	& 	 ~(mask_FUNC<<(pos*4)))		| (PORT_InitStruct->PORT_CFUNC	<<			pos*4);
			}
			else if (((PORT_InitStruct->PORT_Pin)&mask_s)>0x0080U && ((PORT_InitStruct->PORT_Pin)&mask_s)<=0x8000U)//8-15
			{
			tmpreg_SFUNC[1]  	= (tmpreg_SFUNC[1]	& ~(mask_FUNC<<(pos*4-32))) 	| (PORT_InitStruct->PORT_SFUNC	<<	(pos*4-32));
			tmpreg_CFUNC[1]  	= (tmpreg_CFUNC[1]	& ~(mask_FUNC<<(pos*4-32))) 	| (PORT_InitStruct->PORT_CFUNC	<<	(pos*4-32));
			}
			else if (((PORT_InitStruct->PORT_Pin)&mask_s)>0x8000U && ((PORT_InitStruct->PORT_Pin)&mask_s)<=0x800000U)//16-23
			{
			tmpreg_SFUNC[2]  	= (tmpreg_SFUNC[2]	& ~(mask_FUNC<<(pos*4-64))) 	| (PORT_InitStruct->PORT_SFUNC	<<	(pos*4-64));
			tmpreg_CFUNC[2]  	= (tmpreg_CFUNC[2]	& ~(mask_FUNC<<(pos*4-64))) 	| (PORT_InitStruct->PORT_CFUNC	<<	(pos*4-64));
			}
			else if (((PORT_InitStruct->PORT_Pin)&mask_s)>0x800000U && ((PORT_InitStruct->PORT_Pin)&mask_s)<=0x80000000U)//24-31
			{
			tmpreg_SFUNC[3]  	= (tmpreg_SFUNC[3]	& ~(mask_FUNC<<(pos*4-96))) 	| (PORT_InitStruct->PORT_SFUNC	<<	(pos*4-96));
			tmpreg_CFUNC[3]  	= (tmpreg_CFUNC[3]	& ~(mask_FUNC<<(pos*4-96))) 	| (PORT_InitStruct->PORT_CFUNC	<<	(pos*4-96));
			}
			
			tmpreg_SOE    		= (tmpreg_SOE				& ~mask_s)	| (PORT_InitStruct->PORT_SOE					<<	pos);
			tmpreg_COE    		= (tmpreg_COE				& ~mask_s)	| (PORT_InitStruct->PORT_COE					<<	pos);
			
			tmpreg_SANALOG    = (tmpreg_SANALOG		& ~mask_s) 	| (PORT_InitStruct->PORT_SANALOG			<<	pos);
			tmpreg_CANALOG    = (tmpreg_CANALOG		& ~mask_s) 	| (PORT_InitStruct->PORT_CANALOG			<<	pos);
			
			tmpreg_SPULLUP    = (tmpreg_SPULLUP		& ~mask_s) 	| (PORT_InitStruct->PORT_SPULLUP			<<	pos);
			tmpreg_CPULLUP    = (tmpreg_CPULLUP		& ~mask_s) 	| (PORT_InitStruct->PORT_CPULLUP			<<	pos);
			
			tmpreg_SPULLDOWN  = (tmpreg_SPULLDOWN	& ~mask_s)	| (PORT_InitStruct->PORT_SPULLDOWN		<<	pos);
			tmpreg_CPULLDOWN  = (tmpreg_CPULLDOWN	& ~mask_s)	| (PORT_InitStruct->PORT_CPULLDOWN		<<	pos);
			
			tmpreg_SPD    		= (tmpreg_SPD				& ~mask_s) 	| (PORT_InitStruct->PORT_SPD					<<	pos);
			tmpreg_CPD    		= (tmpreg_CPD				& ~mask_s) 	| (PORT_InitStruct->PORT_CPD					<<	pos);
						
			tmpreg_SCL    		= (tmpreg_SCL				& ~mask_s) 	| (PORT_InitStruct->PORT_SCL					<<	pos);
			tmpreg_CCL    		= (tmpreg_CCL				& ~mask_s) 	| (PORT_InitStruct->PORT_CCL					<<	pos);
			
			tmpreg_SIE    		= (tmpreg_SIE				& ~mask_s) 	| (PORT_InitStruct->PORT_SIE					<<	pos);
			tmpreg_CIE    		= (tmpreg_CIE				& ~mask_s) 	| (PORT_InitStruct->PORT_CIE					<<	pos);
			
			tmpreg_SIT    		= (tmpreg_SIT				& ~mask_s) 	| (PORT_InitStruct->PORT_SIT					<<	pos);
			tmpreg_CIT    		= (tmpreg_CIT				& ~mask_s) 	| (PORT_InitStruct->PORT_CIT					<<	pos);
			
			tmpreg_SIR    		= (tmpreg_SIR				& ~mask_s) 	| (PORT_InitStruct->PORT_SIR					<<	pos);
			tmpreg_CIR    		= (tmpreg_CIR				& ~mask_s) 	| (PORT_InitStruct->PORT_CIR					<<	pos);			
			
			if (((PORT_InitStruct->PORT_Pin)&mask_s)<=0x8000U)
			{
			tmpreg_SPWR[0]    = (tmpreg_SPWR[0]		& 	 ~(mask_l<<(pos*2))) | (PORT_InitStruct->PORT_SPWR			<<			pos*2);
			tmpreg_CPWR[0]    = (tmpreg_CPWR[0]		& 	 ~(mask_l<<(pos*2))) | (PORT_InitStruct->PORT_CPWR			<<			pos*2);
			}
			else if (((PORT_InitStruct->PORT_Pin)&mask_s)>0x8000U && ((PORT_InitStruct->PORT_Pin)&mask_s)<=0x80000000U)
			{
			tmpreg_SPWR[1]    = (tmpreg_SPWR[1]		& ~(mask_l<<(pos*2-32))) | (PORT_InitStruct->PORT_SPWR			<<	(pos*2-32));
			tmpreg_CPWR[1]    = (tmpreg_CPWR[1]		& ~(mask_l<<(pos*2-32))) | (PORT_InitStruct->PORT_CPWR			<<	(pos*2-32));
			}
			
    }//if
		mask_s<<=1;
    pos++;
		
  }//for
	
  /* Configure PORT registers with new values */	
	
	PORTx->COE			= tmpreg_COE;
	PORTx->CFUNC[0]	= tmpreg_CFUNC[0];
	PORTx->CFUNC[1]	= tmpreg_CFUNC[1];
	PORTx->CFUNC[2]	= tmpreg_CFUNC[2];
	PORTx->CFUNC[3]	= tmpreg_CFUNC[3];
	PORTx->CANALOG	= tmpreg_CANALOG;
	PORTx->CPULLUP	= tmpreg_CPULLUP;
	PORTx->CPULLDOWN= tmpreg_CPULLDOWN;
	PORTx->CPD			= tmpreg_CPD;
	PORTx->CPWR[0]	= tmpreg_CPWR[0];
	PORTx->CPWR[1]	= tmpreg_CPWR[1];
	PORTx->CCL			= tmpreg_CCL;
	PORTx->CIE			= tmpreg_CIE;
	PORTx->CIT			= tmpreg_CIT;
	PORTx->CIR			= tmpreg_CIR;
	
	PORTx->SOE			= tmpreg_SOE;
  PORTx->SFUNC[0]	= tmpreg_SFUNC[0];
	PORTx->SFUNC[1]	= tmpreg_SFUNC[1];
	PORTx->SFUNC[2]	= tmpreg_SFUNC[2];
	PORTx->SFUNC[3]	= tmpreg_SFUNC[3];
  PORTx->SANALOG	= tmpreg_SANALOG;
  PORTx->SPULLUP	= tmpreg_SPULLUP;
  PORTx->SPULLDOWN= tmpreg_SPULLDOWN;
  PORTx->SPD			= tmpreg_SPD;
  PORTx->SPWR[0]	= tmpreg_SPWR[0];
	PORTx->SPWR[1]	= tmpreg_SPWR[1];
  PORTx->SCL			= tmpreg_SCL;
  PORTx->SIE			= tmpreg_SIE;
  PORTx->SIT			= tmpreg_SIT;
  PORTx->SIR			= tmpreg_SIR;
	
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
  PORT_InitStruct->PORT_Pin        = 0;
  PORT_InitStruct->PORT_SOE        = 0;
	PORT_InitStruct->PORT_SFUNC      = 0;
	PORT_InitStruct->PORT_SANALOG    = 0;
  PORT_InitStruct->PORT_SPULLUP    = 0;
  PORT_InitStruct->PORT_SPULLDOWN  = 0;
  PORT_InitStruct->PORT_SPD     	 = 0;
  PORT_InitStruct->PORT_SPWR       = 0;
  PORT_InitStruct->PORT_SCL        = 0;
  PORT_InitStruct->PORT_SIE      	 = 0;
  PORT_InitStruct->PORT_SIT        = 0;
	PORT_InitStruct->PORT_SIR        = 0;
}

void PORT_ClearStructInit(PORT_InitTypeDef* PORT_InitStruct)
{
	/* Reset PORT initialization structure parameters values */
  PORT_InitStruct->PORT_COE        = 0;
	PORT_InitStruct->PORT_CFUNC      = 0;
	PORT_InitStruct->PORT_CANALOG    = 0;
  PORT_InitStruct->PORT_CPULLUP    = 0;
  PORT_InitStruct->PORT_CPULLDOWN  = 0;
  PORT_InitStruct->PORT_CPD     	 = 0;
  PORT_InitStruct->PORT_CPWR       = 0;
  PORT_InitStruct->PORT_CCL        = 0;
  PORT_InitStruct->PORT_CIE      	 = 0;
  PORT_InitStruct->PORT_CIT        = 0;
	PORT_InitStruct->PORT_CIR        = 0;
}

/**
  * @brief  Reads the specified input port pin.
  * @param  PORTx: where x can be (A..F) to select the PORT peripheral.
  * @param  PORT_Pin: specifies the port bit to read.
  *         This parameter can be PORT_Pin_x where x can be (0..31).
  * @retval The input port pin value.
  */
uint8_t PORT_ReadInputDataBit(PortControl* PORTx, uint32_t PORT_Pin)
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
  * @retval PORT input data port value.
  */
uint32_t PORT_ReadInputData(PortControl* PORTx)
{
  /* Check the parameters */
  assert_param(IS_PORT_ALL_PERIPH(PORTx));

  return (PORTx->RXTX);
}

/**
  * @brief  Sets the selected data port bits.
  * @param  PORTx: where x can be (A..F) to select the PORT peripheral.
  * @param  PORT_Pin: specifies the port bits to be written.
  *         This parameter can be any combination of PORT_Pin_x where x can be (0..31).
  * @retval None
  */
void PORT_SetBits ( PortControl* PORTx, uint32_t PORT_Pin )
{
	/* Check the parameters */
	assert_param(IS_PORT_ALL_PERIPH(PORTx));
	assert_param(IS_PORT_PIN(PORT_Pin));
	//assert_param(IS_NOT_JTAG_PIN(PORTx, PORT_Pin));
	
	PORTx->SRXTX = PORT_Pin;
}

/**
  * @brief  Clears the selected data port bits.
  * @param  PORTx: where x can be (A..F) to select the PORT peripheral.
  * @param  PORT_Pin: specifies the port bits to be written.
  *         This parameter can be any combination of PORT_Pin_x where x can be (0..31).
  * @retval None
  */
void PORT_ResetBits ( PortControl* PORTx, uint32_t PORT_Pin )
{
	  /* Check the parameters */
  assert_param(IS_PORT_ALL_PERIPH(PORTx));
  assert_param(IS_PORT_PIN(PORT_Pin));
  //assert_param(IS_NOT_JTAG_PIN(PORTx, PORT_Pin));
	
	PORTx->CRXTX = PORT_Pin;
}

/**
  * @brief  Sets or clears the selected data port bit.
  * @param  PORTx: where x can be (A..F) to select the PORT peripheral.
  * @param  PORT_Pin: specifies the port bit to be written.
  *         This parameter can be one of PORT_Pin_x where x can be (0..31).
  * @param  BitVal: specifies the value to be written to the selected bit.
  *         This parameter can be one of the BitAction enum values:
  *           @arg Bit_RESET: to clear the port pin
  *           @arg Bit_SET: to set the port pin
  * @retval None
  */
void PORT_WriteBit(PortControl* PORTx, uint32_t PORT_Pin, BitAction BitVal)
{
  uint32_t portdata;
  /* Check the parameters */
  assert_param(IS_PORT_ALL_PERIPH(PORTx));
  assert_param(IS_GET_PORT_PIN(PORT_Pin));
  assert_param(IS_PORT_BIT_ACTION(BitVal));
  //assert_param(IS_NOT_JTAG_PIN(PORTx, PORT_Pin));

  portdata = PORTx->RXTX;
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
  * @retval None
  */
void PORT_Write(PortControl* PORTx, uint32_t PortVal)
{
  /* Check the parameters */
  assert_param(IS_PORT_ALL_PERIPH(PORTx));
  assert_param(IS_NOT_JTAG_PIN(PORTx, PortVal));

  PORTx->RXTX = PortVal;
}

/** @} */ /* End of group PORT_Private_Functions */

/** @} */ /* End of group PORT */

/** @} */ /* End of group __MDR32F8_StdPeriph_Driver */

/******************* (C) COPYRIGHT 2015 Milandr *********************************
*
* END OF FILE mdr32f8_port.c */