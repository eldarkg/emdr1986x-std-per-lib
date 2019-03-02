/**
  * FILE MDR32F9Qx_eeprom.c
  */

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_config.h"
#include "MDR32F9Qx_eeprom.h"


#define ASSERT_INFO_FILE_ID FILEID__MDR32F9X_EEPROM_C

/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @defgroup EEPROM EEPROM
  * @{
  */

/** @defgroup EEPROM_Private_Defines EEPROM Private Defines
  * @{
  */

#define EEPROM_REG_ACCESS_KEY           ((uint32_t)0x8AAA5551)

/** @} */ /* End of group EEPROM_Private_Defines */

/** @defgroup EEPROM_Private_Macros EEPROM Private Macros
  * @{
  */

#define IS_TWO_BYTE_ALLIGNED(ADDR)      ((ADDR & 1) == 0)
#define IS_FOUR_BYTE_ALLIGNED(ADDR)     ((ADDR & 3) == 0)

#define DELAY_LOOP_CYCLES               (8UL)

#ifndef FLASH_PROG_FREQ_MHZ
#  error "Please set a EEPROM programming the max MCU frequency. Define FLASH_PROG_FREQ_MHZ in MDR32F9Qx_config.h file"
#endif

#define GET_US_LOOPS(N)                 ((uint32_t)((double)(N) * FLASH_PROG_FREQ_MHZ / DELAY_LOOP_CYCLES + 1.0))

/** @} */ /* End of group EEPROM_Private_Macros */

/** @defgroup EEPROM_Private_Functions EEPROM Private Functions
  * @{
  */

__RAMFUNC static void ProgramDelay(uint32_t Loops) __RAMFUNCSECTION;

/**
  * @brief  Program delay.
  * @param  Loops: Number of the loops.
  * @retval None.
  */
__RAMFUNC static void ProgramDelay(uint32_t Loops)
{
  volatile uint32_t i = Loops;
  for (; i > 0; i--)
  {
  }
}


/**
  * @brief  Sets the code latency value.
  * @param  FLASH_Latency: specifies the FLASH Latency value.
  *          This parameter can be one of the following values:
  *            @arg EEPROM_Latency_0: EEPROM Zero Latency cycle
  *            @arg EEPROM_Latency_1: EEPROM One Latency cycle
  *            @arg EEPROM_Latency_2: EEPROM Two Latency cycles
  *            @arg EEPROM_Latency_3: EEPROM Three Latency cycles
  *            @arg EEPROM_Latency_4: EEPROM Four Latency cycles
  *            @arg EEPROM_Latency_5: EEPROM Five Latency cycles
  *            @arg EEPROM_Latency_6: EEPROM Six Latency cycles
  *            @arg EEPROM_Latency_7: EEPROM Seven Latency cycles
  * @retval None
  */
void EEPROM_SetLatency ( uint32_t EEPROM_Latency )
{
  /* Check the parameters */
  assert_param(IS_EEPROM_LATENCY(EEPROM_Latency));

  /* Set the new latency value */
  MDR_EEPROM->CMD = EEPROM_Latency;
}

/**
  * @brief  Reads the 8-bit EEPROM memory value.
  * @param  Address: The EEPROM memory byte address.
  * @param  BankSelector: Selects EEPROM Bank (Main Bank or Information Bank).
  *         This parameter can be one of the following values:
  *           @arg EEPROM_Main_Bank_Select:      The EEPROM Main Bank selector.
  *           @arg EEPROM_Info_Bank_Select:      The EEPROM Information Bank selector.
  * @retval The selected EEPROM memory value.
  */
__RAMFUNC  uint8_t EEPROM_ReadByte(uint32_t Address, uint32_t BankSelector)
{
  uint32_t Data;
  uint32_t Command;
  uint32_t Shift;

  assert_param(IS_EEPROM_BANK_SELECTOR(BankSelector));

  MDR_EEPROM->KEY = EEPROM_REG_ACCESS_KEY;
  Command = (MDR_EEPROM->CMD & EEPROM_CMD_DELAY_Msk) | EEPROM_CMD_CON;
  Command |= (BankSelector == EEPROM_Info_Bank_Select) ? EEPROM_CMD_IFREN : 0;
  MDR_EEPROM->CMD = Command;
  MDR_EEPROM->ADR = Address;
  MDR_EEPROM->CMD = Command | EEPROM_CMD_XE | EEPROM_CMD_YE | EEPROM_CMD_SE;
  MDR_EEPROM->DO;   /* Idle Reading for Delay */
  MDR_EEPROM->DO;   /* Idle Reading for Delay */
  MDR_EEPROM->DO;   /* Idle Reading for Delay */
  Data = MDR_EEPROM->DO;
  Command &= EEPROM_CMD_DELAY_Msk;
  MDR_EEPROM->CMD = Command;
  MDR_EEPROM->KEY = 0;

  Shift = (Address & 3) * 8;
  Data >>= Shift;
  return Data;
}

/**
  * @brief  Reads the 16-bit EEPROM memory value.
  * @param  Address: The EEPROM memory half word address (two byte aligned).
  * @param  BankSelector: Selects EEPROM Bank (Main Bank or Information Bank).
  *         This parameter can be one of the following values:
  *           @arg EEPROM_Main_Bank_Select:      The EEPROM Main Bank selector.
  *           @arg EEPROM_Info_Bank_Select:      The EEPROM Information Bank selector.
  * @retval The selected EEPROM memory value.
  */
__RAMFUNC uint16_t EEPROM_ReadHalfWord(uint32_t Address, uint32_t BankSelector)
{
  uint32_t Data;
  uint32_t Command;
  uint32_t Shift;

  assert_param(IS_EEPROM_BANK_SELECTOR(BankSelector));
  assert_param(IS_TWO_BYTE_ALLIGNED(Address));

  MDR_EEPROM->KEY = EEPROM_REG_ACCESS_KEY;
  Command = (MDR_EEPROM->CMD & EEPROM_CMD_DELAY_Msk) | EEPROM_CMD_CON;
  Command |= (BankSelector == EEPROM_Info_Bank_Select) ? EEPROM_CMD_IFREN : 0;
  MDR_EEPROM->CMD = Command;
  MDR_EEPROM->ADR = Address;
  MDR_EEPROM->CMD = Command | EEPROM_CMD_XE | EEPROM_CMD_YE | EEPROM_CMD_SE;
  MDR_EEPROM->DO;   /* Idle Reading for Delay */
  MDR_EEPROM->DO;   /* Idle Reading for Delay */
  MDR_EEPROM->DO;   /* Idle Reading for Delay */
  Data = MDR_EEPROM->DO;
  Command &= EEPROM_CMD_DELAY_Msk;
  MDR_EEPROM->CMD = Command;
  MDR_EEPROM->KEY = 0;

  Shift = (Address & 2) * 8;
  Data >>= Shift;
  return Data;
}

/**
  * @brief  Reads the 32-bit EEPROM memory value.
  * @param  Address: The EEPROM memory word address (four byte aligned).
  * @param  BankSelector: Selects EEPROM Bank (Main Bank or Information Bank).
  *         This parameter can be one of the following values:
  *           @arg EEPROM_Main_Bank_Select:      The EEPROM Main Bank selector.
  *           @arg EEPROM_Info_Bank_Select:      The EEPROM Information Bank selector.
  * @retval The selected EEPROM memory value.
  */
__RAMFUNC uint32_t EEPROM_ReadWord(uint32_t Address, uint32_t BankSelector)
{
  uint32_t Command;
  uint32_t Data;

  assert_param(IS_EEPROM_BANK_SELECTOR(BankSelector));
  assert_param(IS_FOUR_BYTE_ALLIGNED(Address));

  MDR_EEPROM->KEY = EEPROM_REG_ACCESS_KEY;
  Command = (MDR_EEPROM->CMD & EEPROM_CMD_DELAY_Msk) | EEPROM_CMD_CON;
  Command |= (BankSelector == EEPROM_Info_Bank_Select) ? EEPROM_CMD_IFREN : 0;
  MDR_EEPROM->CMD = Command;
  MDR_EEPROM->ADR = Address;
  MDR_EEPROM->CMD = Command | EEPROM_CMD_XE | EEPROM_CMD_YE | EEPROM_CMD_SE;
  MDR_EEPROM->DO;   /* Idle Reading for Delay */
  MDR_EEPROM->DO;   /* Idle Reading for Delay */
  MDR_EEPROM->DO;   /* Idle Reading for Delay */
  Data = MDR_EEPROM->DO;
  Command &= EEPROM_CMD_DELAY_Msk;
  MDR_EEPROM->CMD = Command;
  MDR_EEPROM->KEY = 0;
  return Data;
}

/**
  * @brief  Erases one page of the selected EEPROM memory bank.
  * @param  Address: Page Address in the EEPROM memory.
  * @param  BankSelector: Selects EEPROM Bank (Main Bank or Information Bank).
  *         This parameter can be one of the following values:
  *           @arg EEPROM_Main_Bank_Select:      The EEPROM Main Bank selector.
  *           @arg EEPROM_Info_Bank_Select:      The EEPROM Information Bank selector.
  * @retval None
  */
__RAMFUNC void EEPROM_ErasePage(uint32_t Address, uint32_t BankSelector)
{
  uint32_t Command;

  assert_param(IS_EEPROM_BANK_SELECTOR(BankSelector));

  MDR_EEPROM->KEY = EEPROM_REG_ACCESS_KEY;
  Command = (MDR_EEPROM->CMD & EEPROM_CMD_DELAY_Msk) | EEPROM_CMD_CON;
  Command |= (BankSelector == EEPROM_Info_Bank_Select) ? EEPROM_CMD_IFREN : 0;
  MDR_EEPROM->CMD = Command;

  MDR_EEPROM->ADR = Address;                  /* Page Address */
  MDR_EEPROM->DI = 0;
  Command |= EEPROM_CMD_XE | EEPROM_CMD_ERASE;
  MDR_EEPROM->CMD = Command;
  ProgramDelay(GET_US_LOOPS(10));              /* Wait for 10 us */
  Command |= EEPROM_CMD_NVSTR;
  MDR_EEPROM->CMD = Command;
  ProgramDelay(GET_US_LOOPS(40000));          /* Wait for 40 ms */
  Command &= ~EEPROM_CMD_ERASE;
  MDR_EEPROM->CMD = Command;
  ProgramDelay(GET_US_LOOPS(5));              /* Wait for 5 us */
  Command &= ~(EEPROM_CMD_XE | EEPROM_CMD_NVSTR);
  MDR_EEPROM->CMD = Command;
  ProgramDelay(GET_US_LOOPS(1));              /* Wait for 1 us */

  Command &= EEPROM_CMD_DELAY_Msk;
  MDR_EEPROM->CMD = Command;
  MDR_EEPROM->KEY = 0;
}

/**
  * @brief  Erases one block of the selected EEPROM memory bank.
  * @param  Address: Block Address in the EEPROM memory.
  * @param  BankSelector: Selects EEPROM Bank (Main Bank or Information Bank).
  *         This parameter can be one of the following values:
  *           @arg EEPROM_Main_Bank_Select:      The EEPROM Main Bank selector.
  *           @arg EEPROM_Info_Bank_Select:      The EEPROM Information Bank selector.
  * @retval None
  */
__RAMFUNC void EEPROM_EraseBlock(uint32_t Address, uint32_t BankSelector)
{
  uint32_t Command;

  assert_param(IS_EEPROM_BANK_SELECTOR(BankSelector));

  MDR_EEPROM->KEY = EEPROM_REG_ACCESS_KEY;
  Command = (MDR_EEPROM->CMD & EEPROM_CMD_DELAY_Msk) | EEPROM_CMD_CON;
  Command |= (BankSelector == EEPROM_Info_Bank_Select) ? EEPROM_CMD_IFREN : 0;

  MDR_EEPROM->CMD = Command;

  MDR_EEPROM->ADR = Address;
  MDR_EEPROM->DI = 0;
  Command |= EEPROM_CMD_XE | EEPROM_CMD_MAS1 | EEPROM_CMD_ERASE;
  MDR_EEPROM->CMD = Command;
  ProgramDelay(GET_US_LOOPS(10));                /* Wait for 10 us */
  Command |= EEPROM_CMD_NVSTR;
  MDR_EEPROM->CMD = Command;
  ProgramDelay(GET_US_LOOPS(40000));            /* Wait for 40 ms */
  Command &= ~EEPROM_CMD_ERASE;
  MDR_EEPROM->CMD = Command;
  ProgramDelay(GET_US_LOOPS(100));              /* Wait for 100 us */
  Command &= ~(EEPROM_CMD_XE | EEPROM_CMD_MAS1 | EEPROM_CMD_NVSTR);
  MDR_EEPROM->CMD = Command;
  ProgramDelay(GET_US_LOOPS(1));                /* Wait for 1 us */

  Command &= EEPROM_CMD_DELAY_Msk;
  MDR_EEPROM->CMD = Command;
  MDR_EEPROM->KEY = 0;
}

/**
  * @brief  Programs the 8-bit EEPROM memory value.
  * @param  Address: The EEPROM memory byte address.
  * @param  BankSelector: Selects EEPROM Bank (Main Bank or Information Bank).
  *         This parameter can be one of the following values:
  *           @arg EEPROM_Main_Bank_Select:      The EEPROM Main Bank selector.
  *           @arg EEPROM_Info_Bank_Select:      The EEPROM Information Bank selector.
  * @param  Data: The data value to be programmed.
  * @retval None
  */
__RAMFUNC void EEPROM_ProgramByte(uint32_t Address, uint32_t BankSelector, uint32_t Data)
{
  uint32_t Mask;
  uint32_t Tmp;
  uint32_t Shift;

  assert_param(IS_EEPROM_BANK_SELECTOR(BankSelector));

  Shift = (Address & 3) * 8;
  Data = Data << Shift;
  Mask = 0xFF << Shift;
  Tmp = EEPROM_ReadWord(Address, BankSelector);
  EEPROM_ProgramWord(Address, BankSelector, (Tmp & ~Mask) | (Data & Mask));
}

/**
  * @brief  Programs the 16-bit EEPROM memory value.
  * @param  Address: The EEPROM memory half word address (two byte aligned).
  * @param  BankSelector: Selects EEPROM Bank (Main Bank or Information Bank).
  *         This parameter can be one of the following values:
  *           @arg EEPROM_Main_Bank_Select:      The EEPROM Main Bank selector.
  *           @arg EEPROM_Info_Bank_Select:      The EEPROM Information Bank selector.
  * @param  Data: The data value to be programmed.
  * @retval None
  */
__RAMFUNC void EEPROM_ProgramHalfWord(uint32_t Address, uint32_t BankSelector, uint32_t Data)
{
  uint32_t Mask;
  uint32_t Tmp;
  uint32_t Shift;

  assert_param(IS_EEPROM_BANK_SELECTOR(BankSelector));
  assert_param(IS_TWO_BYTE_ALLIGNED(Address));

  Shift = (Address & 2) * 8;
  Data = Data << Shift;
  Mask = 0xFFFF << Shift;
  Tmp = EEPROM_ReadWord(Address, BankSelector);
  EEPROM_ProgramWord(Address, BankSelector, (Tmp & ~Mask) | (Data & Mask));
}

/**
  * @brief  Programs the 32-bit EEPROM memory value.
  * @param  Address: The EEPROM memory word address (four byte aligned).
  * @param  BankSelector: Selects EEPROM Bank (Main Bank or Information Bank).
  *         This parameter can be one of the following values:
  *           @arg EEPROM_Main_Bank_Select:      The EEPROM Main Bank selector.
  *           @arg EEPROM_Info_Bank_Select:      The EEPROM Information Bank selector.
  * @param  Data: The data value to be programmed.
  * @retval None
  */
__RAMFUNC void EEPROM_ProgramWord(uint32_t Address, uint32_t BankSelector, uint32_t Data)
{
  uint32_t Command;

  assert_param(IS_EEPROM_BANK_SELECTOR(BankSelector));
  assert_param(IS_FOUR_BYTE_ALLIGNED(Address));

  MDR_EEPROM->KEY = EEPROM_REG_ACCESS_KEY;
  BankSelector = (BankSelector == EEPROM_Info_Bank_Select) ? EEPROM_CMD_IFREN : 0;
  Command = MDR_EEPROM->CMD & EEPROM_CMD_DELAY_Msk;
  Command |= EEPROM_CMD_CON | BankSelector;
  MDR_EEPROM->CMD = Command;
  MDR_EEPROM->ADR = Address;
  MDR_EEPROM->DI  = Data;
  Command |= EEPROM_CMD_XE | EEPROM_CMD_PROG;
  MDR_EEPROM->CMD = Command;
  ProgramDelay(GET_US_LOOPS(5));                /* Wait for 5 us */
  Command |= EEPROM_CMD_NVSTR;
  MDR_EEPROM->CMD = Command;
  ProgramDelay(GET_US_LOOPS(10));               /* Wait for 10 us */
  Command |= EEPROM_CMD_YE;
  MDR_EEPROM->CMD = Command;
  ProgramDelay(GET_US_LOOPS(40));               /* Wait for 40 us */
  Command &= ~EEPROM_CMD_YE;
  MDR_EEPROM->CMD = Command;
  Command &= ~EEPROM_CMD_PROG;
  MDR_EEPROM->CMD = Command;
  ProgramDelay(GET_US_LOOPS(5));                /* Wait for 5 us */
  Command &= ~(EEPROM_CMD_XE | EEPROM_CMD_NVSTR);
  MDR_EEPROM->CMD = Command;
  ProgramDelay(GET_US_LOOPS(1));                /* Wait for 1 us */

  MDR_EEPROM->CMD = Command & EEPROM_CMD_DELAY_Msk;
  MDR_EEPROM->KEY = 0;
}

/** @} */ /* End of group EEPROM_Private_Functions */

/** @} */ /* End of group EEPROM */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

/*
*
* END OF FILE MDR32F9Qx_eeprom.c */
