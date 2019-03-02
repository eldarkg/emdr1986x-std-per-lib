
#include "spec.h"

#define JTAG_DELAY_EBC 1000
#define JTAG_DELAY_RAM 1000000

#define JTAG_DELAY  JTAG_DELAY_RAM

void POR_disable(void)
{
	int i = 0;
	for (i=0;i<JTAG_DELAY;i++) {}; // Pause to take control in alarm case
	
	BKP->KEY          = _KEY_; // Key to access batary domain control 
			
	BKP->REG_60_TMR0 |= 1<<28; // POR is disable
	BKP->REG_60_TMR1 |= 1<<28; // POR is disable
	BKP->REG_60_TMR2 |= 1<<28; // POR is disable
		
	CLK_CNTR->KEY     = _KEY_; // Key to access clock control 
	FT_CNTR->KEY      = _KEY_; // Key to access fault control  
		
  FT_CNTR->RESET_EVENT0 = 0x0; // hide all errors
  FT_CNTR->RESET_EVENT1 = 0x0; // hide all errors
  FT_CNTR->RESET_EVENT2 = 0x0; // hide all errors
  FT_CNTR->RESET_EVENT3 = 0x0; // hide all errors
  FT_CNTR->RESET_EVENT4 = 0x0; // hide all errors
}

void KEY_reg_accs(void)
{
	PORTA->KEY		=_KEY_;
	PORTB->KEY		=_KEY_;
	PORTC->KEY		=_KEY_;
	PORTD->KEY		=_KEY_;
	PORTE->KEY		=_KEY_;
}
