
#include "mdr32f8_lib.h"
#include "stdio.h"

 #define USE_ASSERT_INFO    0
/* #define USE_ASSERT_INFO    1 */
/* #define USE_ASSERT_INFO    2 */

/* Target system parameters */
/* RST_CLK generators frequencies in HZ */
#define HSI_Value       	((uint32_t)8000000)
#define HSE0_Value       	((uint32_t)10000000)
#define HSE1_Value      	((uint32_t)25000000)
#define LSI_Value       	((uint32_t)40000)
#define LSE_Value       	((uint32_t)32768)

/* DMA configuration parameters */
/* Number of DMA channels to use */
#define DMA_Channels_Number   32          /* This parameter is in range 1..32 */

/* Alternate Control Data Structure Usage */
/* This parameter can be a value of:
    0 = DMA_ALternateDataDisabled;
    1 = DMA_ALternateDataEnabled; */
/*#define DMA_AlternateData   0 */          /* DMA_AlternateDataDisabled */
#define DMA_AlternateData   1             /* DMA_AlternateDataEnabled */

#define USE_MDR1986VE9x

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
