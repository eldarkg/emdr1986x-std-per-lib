/**
  * FILE MDR32F9Qx_port.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MDR32F9Qx_PORT_H
#define __MDR32F9Qx_PORT_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_config.h"
#include "MDR32F9Qx_lib.h"


/** @addtogroup __MDR32F9Qx_StdPeriph_Driver MDR32F9Qx Standard Peripherial Driver
  * @{
  */

/** @addtogroup PORT
  * @{
  */

/** @defgroup PORT_Exported_Types PORT Exported Types
  * @{
  */

#if defined (USE_MDR1986VE9x) || defined (USE_MDR1986VE1T) || defined (USE_MDR1901VC1T)
#define IS_PORT_ALL_PERIPH(PERIPH) (((PERIPH) == MDR_PORTA) || \
                                    ((PERIPH) == MDR_PORTB) || \
                                    ((PERIPH) == MDR_PORTC) || \
                                    ((PERIPH) == MDR_PORTD) || \
                                    ((PERIPH) == MDR_PORTE) || \
                                    ((PERIPH) == MDR_PORTF))
#endif
#if defined (USE_MDR1986VE3)
#define IS_PORT_ALL_PERIPH(PERIPH) (((PERIPH) == MDR_PORTA) || \
                                    ((PERIPH) == MDR_PORTB) || \
                                    ((PERIPH) == MDR_PORTC) || \
                                    ((PERIPH) == MDR_PORTD) || \
                                    ((PERIPH) == MDR_PORTE) || \
                                    ((PERIPH) == MDR_PORTF) || \
                                    ((PERIPH) == MDR_PORTG) || \
                                    ((PERIPH) == MDR_PORTH) || \
                                    ((PERIPH) == MDR_PORTI))
#endif

/**
  * @brief  Configuration OE enumeration
  */

typedef enum
{
  PORT_OE_IN            = 0x0,
  PORT_OE_OUT           = 0x1
}PORT_OE_TypeDef;

#define IS_PORT_OE(OE) (((OE) == PORT_OE_IN) || ((OE) == PORT_OE_OUT))


/**
  * @brief  Configuration Mode enumeration
  */

typedef enum
{
  PORT_MODE_ANALOG      = 0x0,
  PORT_MODE_DIGITAL     = 0x1
}PORT_MODE_TypeDef;

#define IS_PORT_MODE(MODE) (((MODE) == PORT_MODE_ANALOG) || ((MODE) == PORT_MODE_DIGITAL))


/**
  * @brief  Configuration PULL_UP enumeration
  */

typedef enum
{
  PORT_PULL_UP_OFF      = 0x0,
  PORT_PULL_UP_ON       = 0x1
}PORT_PULL_UP_TypeDef;

#define IS_PORT_PULL_UP(PULL_UP) (((PULL_UP) == PORT_PULL_UP_OFF) || ((PULL_UP) == PORT_PULL_UP_ON))


/**
  * @brief  Configuration PULL_DOWN enumeration
  */

typedef enum
{
  PORT_PULL_DOWN_OFF    = 0x0,
  PORT_PULL_DOWN_ON     = 0x1
}PORT_PULL_DOWN_TypeDef;

#define IS_PORT_PULL_DOWN(PULL_DOWN) (((PULL_DOWN) == PORT_PULL_DOWN_ON) || \
                                      ((PULL_DOWN) == PORT_PULL_DOWN_OFF))

/**
  * @brief  Configuration PD_SHM enumeration
  */

typedef enum
{
  PORT_PD_SHM_OFF       = 0x0,
  PORT_PD_SHM_ON        = 0x1
}PORT_PD_SHM_TypeDef;

#define IS_PORT_PD_SHM(PORT_PD_SHM) (((PORT_PD_SHM) == PORT_PD_SHM_OFF) || \
                                     ((PORT_PD_SHM) == PORT_PD_SHM_ON))


/**
  * @brief  Configuration PD_PD enumeration
  */

typedef enum
{
  PORT_PD_DRIVER        = 0x0,
  PORT_PD_OPEN          = 0x1
}PORT_PD_TypeDef;

#define IS_PORT_PD(PORT_PD) (((PORT_PD) == PORT_PD_DRIVER) || ((PORT_PD) == PORT_PD_OPEN))

/**
  * @brief  Configuration GFEN enumeration
  */

typedef enum
{
  PORT_GFEN_OFF         = 0x0,
  PORT_GFEN_ON          = 0x1
}PORT_GFEN_TypeDef;

#define IS_PORT_GFEN(PORT_GFEN) (((PORT_GFEN) == PORT_GFEN_OFF) || ((PORT_GFEN) == PORT_GFEN_ON))


/**
  * @brief  Configuration Function enumeration
  */

typedef enum
{
  PORT_FUNC_PORT        = 0x0,
  PORT_FUNC_MAIN        = 0x1,
  PORT_FUNC_ALTER       = 0x2,
  PORT_FUNC_OVERRID     = 0x3
}PORT_FUNC_TypeDef;

#define IS_PORT_FUNC(FUNC) (((FUNC) == PORT_FUNC_PORT)  || ((FUNC) == PORT_FUNC_MAIN) || \
                            ((FUNC) == PORT_FUNC_ALTER) || ((FUNC) == PORT_FUNC_OVERRID))

/**
  * @brief  Configuration Speed enumeration
  */

typedef enum
{
  PORT_OUTPUT_OFF       = 0x0,
  PORT_SPEED_SLOW       = 0x1,
  PORT_SPEED_FAST       = 0x2,
  PORT_SPEED_MAXFAST    = 0x3
}PORT_SPEED_TypeDef;

#define IS_PORT_SPEED(SPEED) (((SPEED) == PORT_OUTPUT_OFF) || ((SPEED) == PORT_SPEED_SLOW) || \
                              ((SPEED) == PORT_SPEED_FAST) || ((SPEED) == PORT_SPEED_MAXFAST))


/**
  * @brief  PORT Init structure definition
  */

typedef struct
{
  uint16_t PORT_Pin;                     /*!< Specifies PORT pins to be configured.
                                              This parameter is a mask of @ref PORT_pins_define values. */
  PORT_OE_TypeDef PORT_OE;               /*!< Specifies in/out mode for the selected pins.
                                              This parameter is one of @ref PORT_OE_TypeDef values. */
  PORT_PULL_UP_TypeDef PORT_PULL_UP;     /*!< Specifies pull up state for the selected pins.
                                              This parameter is one of @ref PORT_PULL_UP_TypeDef values. */
  PORT_PULL_DOWN_TypeDef PORT_PULL_DOWN; /*!< Specifies pull down state for the selected pins.
                                              This parameter is one of @ref PORT_PULL_DOWN_TypeDef values. */
  PORT_PD_SHM_TypeDef PORT_PD_SHM;       /*!< Specifies SHM state for the selected pins.
                                              This parameter is one of @ref PORT_PD_SHM_TypeDef values. */
  PORT_PD_TypeDef PORT_PD;               /*!< Specifies PD state for the selected pins.
                                              This parameter is one of @ref PORT_PD_TypeDef values. */
  PORT_GFEN_TypeDef PORT_GFEN;           /*!< Specifies GFEN state for the selected pins.
                                              This parameter is one of @ref PORT_GFEN_TypeDef values. */
  PORT_FUNC_TypeDef PORT_FUNC;           /*!< Specifies operating function for the selected pins.
                                              This parameter is one of @ref PORT_FUNC_TypeDef values. */
  PORT_SPEED_TypeDef PORT_SPEED;         /*!< Specifies the speed for the selected pins.
                                              This parameter is one of @ref PORT_SPEED_TypeDef values. */
  PORT_MODE_TypeDef PORT_MODE;           /*!< Specifies the operating mode for the selected pins.
                                              This parameter is one of @ref PORT_MODE_TypeDef values. */
}PORT_InitTypeDef;


/**
  * @brief  Bit_SET and Bit_RESET enumeration
  */

typedef enum
{
  Bit_RESET = 0,
  Bit_SET
}BitAction;

#define IS_PORT_BIT_ACTION(ACTION) (((ACTION) == Bit_RESET) || ((ACTION) == Bit_SET))

/** @} */ /* End of group PORT_Exported_Types */

/** @defgroup PORT_Exported_Constants PORT Exported Constants
  * @{
  */

/** @defgroup PORT_JTAG_define PORT JTAG define
  * @{
  */

#if defined (USE_JTAG_A)
#define PORT_JTAG                   MDR_PORTB    /*!< Port containing JTAG interface */
#define PORT_JTAG_Msk               0x001FU      /*!< JTAG pins */

#elif defined (USE_JTAG_B)
#define PORT_JTAG                   MDR_PORTD    /*!< Port containing JTAG interface */
#define PORT_JTAG_Msk               0x001FU      /*!< JTAG pins */

#endif

#if defined (PORT_JTAG)
#define JTAG_PINS(PORT)             (((PORT) == PORT_JTAG) ? PORT_JTAG_Msk : 0)

#else
#define JTAG_PINS(PORT)             0

#endif

#define IS_NOT_JTAG_PIN(PORT, PIN)  (((PIN) & JTAG_PINS(PORT)) == 0x00)


/** @} */ /* End of group PORT_JTAG_define */

/** @defgroup PORT_pins_define PORT pins define
  * @{
  */

#define PORT_Pin_0                  0x0001U  /*!< Pin 0 selected */
#define PORT_Pin_1                  0x0002U  /*!< Pin 1 selected */
#define PORT_Pin_2                  0x0004U  /*!< Pin 2 selected */
#define PORT_Pin_3                  0x0008U  /*!< Pin 3 selected */
#define PORT_Pin_4                  0x0010U  /*!< Pin 4 selected */
#define PORT_Pin_5                  0x0020U  /*!< Pin 5 selected */
#define PORT_Pin_6                  0x0040U  /*!< Pin 6 selected */
#define PORT_Pin_7                  0x0080U  /*!< Pin 7 selected */
#define PORT_Pin_8                  0x0100U  /*!< Pin 8 selected */
#define PORT_Pin_9                  0x0200U  /*!< Pin 9 selected */
#define PORT_Pin_10                 0x0400U  /*!< Pin 10 selected */
#define PORT_Pin_11                 0x0800U  /*!< Pin 11 selected */
#define PORT_Pin_12                 0x1000U  /*!< Pin 12 selected */
#define PORT_Pin_13                 0x2000U  /*!< Pin 13 selected */
#define PORT_Pin_14                 0x4000U  /*!< Pin 14 selected */
#define PORT_Pin_15                 0x8000U  /*!< Pin 15 selected */
#define PORT_Pin_All                0xFFFFU  /*!< All pins selected */

#define IS_PORT_PIN(PIN)            ((((PIN) & (uint32_t)0xFFFF0000UL) == 0x00) && \
                                     ((PIN) != 0x00))

#define IS_GET_PORT_PIN(PIN)        (((PIN) == PORT_Pin_0 ) || \
                                     ((PIN) == PORT_Pin_1 ) || \
                                     ((PIN) == PORT_Pin_2 ) || \
                                     ((PIN) == PORT_Pin_3 ) || \
                                     ((PIN) == PORT_Pin_4 ) || \
                                     ((PIN) == PORT_Pin_5 ) || \
                                     ((PIN) == PORT_Pin_6 ) || \
                                     ((PIN) == PORT_Pin_7 ) || \
                                     ((PIN) == PORT_Pin_8 ) || \
                                     ((PIN) == PORT_Pin_9 ) || \
                                     ((PIN) == PORT_Pin_10) || \
                                     ((PIN) == PORT_Pin_11) || \
                                     ((PIN) == PORT_Pin_12) || \
                                     ((PIN) == PORT_Pin_13) || \
                                     ((PIN) == PORT_Pin_14) || \
                                     ((PIN) == PORT_Pin_15))

/** @} */ /* End of group PORT_pins_define */

/** @} */ /* End of group PORT_Exported_Constants */

/** @defgroup PORT_Exported_Macros PORT Exported Macros
  * @{
  */

/** @} */ /* End of group PORT_Exported_Macros */

/** @defgroup PORT_Exported_Functions PORT Exported Functions
  * @{
  */

void PORT_DeInit(MDR_PORT_TypeDef* PORTx);
void PORT_Init(MDR_PORT_TypeDef* PORTx, const PORT_InitTypeDef* PORT_InitStruct);
void PORT_StructInit(PORT_InitTypeDef* PORT_InitStruct);

uint8_t PORT_ReadInputDataBit(MDR_PORT_TypeDef* PORTx, uint32_t PORT_Pin);
uint32_t PORT_ReadInputData(MDR_PORT_TypeDef* PORTx);

void PORT_SetBits(MDR_PORT_TypeDef* PORTx, uint32_t PORT_Pin);
void PORT_ResetBits(MDR_PORT_TypeDef* PORTx, uint32_t PORT_Pin);
void PORT_WriteBit(MDR_PORT_TypeDef* PORTx, uint32_t PORT_Pin, BitAction BitVal);
void PORT_Write(MDR_PORT_TypeDef* PORTx, uint32_t PortVal);

/** @} */ /* End of group PORT_Exported_Functions */

/** @} */ /* End of group PORT */

/** @} */ /* End of group __MDR32F9Qx_StdPeriph_Driver */

#ifdef __cplusplus
} // extern "C" block end
#endif

#endif /* __MDR32F9Qx_PORT_H */

/*
*
* END OF FILE MDR32F9Qx_port.h */
