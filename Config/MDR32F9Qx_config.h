/**
  ******************************************************************************
  * @file    MDR32F9Qx_Demo\Project\Demo\MDR32F9Qx_config.h
  * @author  Milandr Application Team
  * @version V1.2.0
  * @date    10/07/2010
  * @brief   Library configuration file.
  ******************************************************************************
  * <br><br>
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, MILANDR SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2014 Milandr</center></h2>
  */

/**
 * @mainpage MDR32F9Qx Standard Peripherals Library.
 * MDR32F9Qx Standard Peripherals Library is a package consisting of
 * all standard peripheral device drivers for 1986BE9x, K1986BE9x, MDR32F9Qx,
 * 1986VE1T, 1986VE3T, 1986VE7T microcontrollers.
 * This library is a firmware package which contains a collection of routines,
 * data structures and macros covering the features of Milandr MDR32F9Qx
 * peripherals. It includes a description of the device drivers plus a set of
 * examples for each peripheral. The firmware library allows any device to be
 * used in the user application without the need for in-depth study of each
 * peripherals specifications. Using the Standard Peripherals Library has two
 * advantages: it saves significant time that would otherwise be spent in
 * coding, while simultaneously reducing application development and
 * integration costs.
 *
 * The MDR32F9Qx Standard Peripherals Library is compatible with Milandr
 * 1986BE9x evaluation boards, Milandr evaluation board for MC 1986VE1T
 * (EVAL 22.0 B) and evaluation board for MC 1986VE3T.
 *
 * The MDR32F9Qx Standard Peripherals Library is full CMSIS compliant.
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MDR32F9Qx_CONFIG_H
#define __MDR32F9Qx_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

#if ((__CC_ARM == 0) || (__ARMCC_VERSION < 5000000))
	#include "MDR32F9Qx_board.h"
#endif
#include "MDR32F9Qx_lib.h"
#include <stdint.h>

#if defined (USE_MDR32F9Q1_Rev0) || defined (USE_MDR32F9Q1_Rev1) ||\
    defined (USE_MDR32F9Q2_Rev0) || defined (USE_MDR32F9Q2_Rev1) ||\
    defined (USE_MDR32F9Q3_Rev0) || defined (USE_MDR32F9Q3_Rev1) ||\
    defined (USE_MDR1986VE94)
	#define USE_MDR1986VE9x
#endif

#if defined (USE_MDR1986BE7T)
	#define USE_MDR1986VE1T
#endif

/* Select the header file for target microcontroller */
#if defined ( USE_MDR1986VE9x )
	#include "MDR32Fx.h"
#elif defined (USE_MDR1986VE1T)
	#include "MDR1986VE1T.h"
#elif defined ( USE_MDR1986VE3 )
	#include "MDR1986VE3.h"
#elif defined ( USE_MDR1901VC1T )
	#include "MDR1901VC1T.h"
#elif defined (USE_MDR1986BE4)
	#include "MDR1986BE4.h"
#endif

/* Uncomment the line(s) below to define used JTAG port(s). Leave all commented
 * if there is no JTAG ports */
#if (defined(USE_MDR1986VE9x) || defined (USE_MDR1901VC1T))
/* #define USE_JTAG_A */
#define USE_JTAG_B
/* #define USE_SWD_A */
/* #define USE_SWD_B */
#endif

/* Target system parameters */
/* RST_CLK generators frequencies in HZ */
#define HSI_Value       ((uint32_t)8000000)
#define HSE_Value       ((uint32_t)8000000)
#define HSE2_Value      ((uint32_t)25000000)
#define LSI_Value       ((uint32_t)40000)
#define LSE_Value       ((uint32_t)32768)

/* RST_CLK frequencies startup timeouts settings */
#define HSEonTimeOut    ((uint16_t)0x0600)
#define HSE2onTimeOut	((uint16_t)0x8000)
#define LSEonTimeOut    ((uint16_t)0x0600)
#define HSIonTimeOut    ((uint16_t)0x0600)
#define LSIonTimeOut    ((uint16_t)0x0600)
#define PLLCPUonTimeOut ((uint16_t)0x0600)
#define PLLUSBonTimeOut ((uint16_t)0x0600)
#define PLLDSPonTimeOut ((uint16_t)0x0600)

/* EEPROM programming the max MCU frequency */
/* #define FLASH_PROG_FREQ_MHZ     (8.0) */

/* Use debug uart */
/* #define _USE_DEBUG_UART_ */

#if defined (_USE_DEBUG_UART_)

#define DEBUG_BAUD_RATE					115200

#if defined (USE_MDR1986VE3)
	#define DEBUG_UART					MDR_UART1
	#define DEBUG_UART_PORT				MDR_PORTD
	#define DEBUG_UART_TX_PIN			PORT_Pin_13
	#define DEBUG_UART_RX_PIN			PORT_Pin_14
	#define DEBUG_UART_PINS_FUNCTION	PORT_FUNC_MAIN
#elif defined (USE_MDR1986VE1T)
	#define DEBUG_UART 					MDR_UART1
	#define DEBUG_UART_PORT				MDR_PORTC
	#define DEBUG_UART_TX_PIN			PORT_Pin_3
	#define DEBUG_UART_RX_PIN			PORT_Pin_4
	#define DEBUG_UART_PINS_FUNCTION	PORT_FUNC_MAIN
#elif defined (USE_MDR1986VE9x)
	#define DEBUG_UART 					MDR_UART2
	#define DEBUG_UART_PORT				MDR_PORTF
	#define DEBUG_UART_TX_PIN			PORT_Pin_1
	#define DEBUG_UART_RX_PIN			PORT_Pin_0
	#define DEBUG_UART_PINS_FUNCTION	PORT_FUNC_OVERRID
#elif defined (USE_MDR1901VC1T)
	#define DEBUG_UART					MDR_UART3
	#define DEBUG_UART_PORT				MDR_PORTF
	#define DEBUG_UART_TX_PIN			PORT_Pin_1
	#define DEBUG_UART_RX_PIN			PORT_Pin_0
	#define DEBUG_UART_PINS_FUNCTION	PORT_FUNC_ALTER
#endif

/* #define PRINTF_FORMAT_FULL */
/* #define PRINTF_FORMAT_LARGE */

#endif /* #if defined (_USE_DEBUG_UART_) */

#if defined ( USE_MDR1986VE3 ) || defined ( USE_MDR1986VE1T )
	#define MIL_STD_1553_TERMINAL_ADDRESS	0x01
#endif /* #if defined ( USE_MDR1986VE3 ) || defined ( USE_MDR1986VE1T ) */

/* RTC configuration parameters */
#define RTC_CalibratorValue   	0
#define RTC_PRESCALER_VALUE		32768

/* DMA configuration parameters */
/* Number of DMA channels to use */
#define DMA_Channels_Number   32          /* This parameter is in range 1..32 */

/* Alternate Control Data Structure Usage */
/* This parameter can be a value of:
    0 = DMA_ALternateDataDisabled;
    1 = DMA_ALternateDataEnabled; */
/*#define DMA_AlternateData   0 */          /* DMA_AlternateDataDisabled */
#define DMA_AlternateData   1             /* DMA_AlternateDataEnabled */

/* USB configuration parameters ----------------------------------------------*/
/* Uncomment one of the lines below to select the Device Class. Leave all commented
 * if the desired device class is not currently supported by USB library */
#define USB_DEVICE_CLASS  USB_DEVICE_CLASS_CDC

/* USB Device management */
/* Uncomment the line below to enable appropriate functionality. */
/* #define USB_REMOTE_WAKEUP_SUPPORTED */
/* #define USB_SELF_POWERED_SUPPORTED */

/* Uncomment the line below to let the library provide USB interrupt handler.
 * Leave this line commented if you are willing to implement the handler yourself. */
#define USB_INT_HANDLE_REQUIRED

/* USB CDC management */
/* Uncomment the lines below to enable appropriate functionality. */
/* #define USB_CDC_STATE_REPORTING_SUPPORTED 	*/
/* #define USB_CDC_ENCAPSULATION_SUPPORTED 	*/
/* #define USB_CDC_COMM_FEATURE_SUPPORTED 	*/
#define USB_CDC_LINE_CODING_SUPPORTED
/* #define USB_CDC_CONTROL_LINE_STATE_SUPPORTED */
/* #define USB_CDC_LINE_BREAK_SUPPORTED 	*/

/* VCOM Echo example flags */

/* Uncomment USB_VCOM_SYNC to enable "reliable delivery" mode: no new data
 * would be received (EP3 will reply NAK) until all previous data is sent
 * to host. */
//#define USB_VCOM_SYNC

/* Uncomment USB_DEBUG_PROTO to utilize the ring buffer for received setup
 * packets and send/receive byte counters (for debug purposes). */
//#define USB_DEBUG_PROTO

/* Known errors workaround control -------------------------------------------*/
/* MDR32F9Qx Series Errata Notice, Error 0002 */
#define WORKAROUND_MDR32F9QX_ERROR_0002

/* Parameter run-time check support ------------------------------------------*/

/* Select one of the following values of USE_ASSERT_INFO macro to control
   parameter checking in the Standard Peripheral Library drivers:
     0 - no parameter checks ("assert_param" macro is disabled);
     1 - check enabled, source file ID and line number are available;
     2 - check enabled, source file ID, line number and checking expression
         (as string) are available (increased code size).
*/
#define USE_ASSERT_INFO    0
/* #define USE_ASSERT_INFO    1 */
/* #define USE_ASSERT_INFO    2 */

/**
  * @brief  The assert_param macro is used for function's parameters check.
  * @param  expr: If expr is false, it calls assert_failed user's function
  *   which gets the source file ID (see MDR32F9Qx_lib.h), line number and
  *   expression text (if USE_ASSERT_INFO == 2) of the call that failed. That
  *   function should not return. If expr is true, nothing is done.
  * @retval None
  */
#if (USE_ASSERT_INFO == 0)
  #define assert_param(expr) ((void)0)
#elif (USE_ASSERT_INFO == 1)
  #define assert_param(expr) ((expr) ? (void)0 : assert_failed(ASSERT_INFO_FILE_ID, __LINE__))
  void assert_failed(uint32_t file_id, uint32_t line);
#elif (USE_ASSERT_INFO == 2)
  #define assert_param(expr) ((expr) ? (void)0 : assert_failed(ASSERT_INFO_FILE_ID, __LINE__, #expr))
  void assert_failed(uint32_t file_id, uint32_t line, const uint8_t* expr);
#else
  #error "Unsupported USE_ASSERT_INFO level"
#endif /* USE_ASSERT_INFO */

#if defined (__ICCARM__)
	#define __attribute__(name_section)
	#if defined (USE_MDR1986VE3) || defined (USE_MDR1986VE1T)
		#pragma section = "EXECUTABLE_MEMORY_SECTION"
		#define IAR_SECTION(section) @ section
	#elif defined (USE_MDR1986VE9x)
		#define IAR_SECTION(section)
	#endif
#endif
#if defined (__CMCARM__)
		#define __attribute__(name_section)
		#define IAR_SECTION(section)
#endif

#if defined (__CC_ARM)
	#define IAR_SECTION(section)
#endif

#ifdef __cplusplus
} // extern "C" block end
#endif

#endif /* __MDR32F9Qx_CONFIG_H */

/******************* (C) COPYRIGHT 2011 Milandr *********************************
*
* END OF FILE MDR32F9Qx_config.h */
