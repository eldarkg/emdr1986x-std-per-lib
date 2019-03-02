#include "MDR1986VE8T.h"

#include "mdr32f8_config.h"
#include "mdr32f8_port.h"
#include "mdr32f8_clkctrl.h"
#include "mdr32f8_uart.h"
#include "mdr32f8_dma.h"

void INT_UART0_Handler(void);
void IRQ_PORTE_Handler(void);
void DMA_DONE0_Handler(void);
