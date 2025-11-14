/*
    ChibiOS - Copyright (C) 2006..2020 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/*
 * This file has been automatically generated using ChibiStudio board
 * generator plugin. Do not edit manually.
 */

#ifndef BOARD_H
#define BOARD_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*
 * Setup for STMicroelectronics STM32 Nucleo64-G474RE board.
 */

/*
 * Board identifier.
 */
#define BOARD_ZE_DIGITAL_DRIVER
#define BOARD_NAME                  "Ziemann Engineering Digital Driver 1.0"

/*
 * Board oscillators-related settings.
 */
#if !defined(STM32_LSECLK)
#define STM32_LSECLK                32768U
#endif

#define STM32_LSEDRV                (3U << 3U)

#if !defined(STM32_HSECLK)
#define STM32_HSECLK                24000000U
#endif

/*
 * Board voltages.
 * Required for performance limits calculation.
 */
#define STM32_VDD                   330U

/*
 * MCU type as defined in the ST header.
 */
#define STM32G474xx

/*
 * IO pins assignments.
 */
#define GPIOA_AIN1                  0U
#define GPIOA_AIN2                  1U
#define GPIOA_TX                    2U
#define GPIOA_RX                    3U
#define GPIOA_PIN4                  4U
#define GPIOA_PIN5                  5U
#define GPIOA_PIN6                  6U
#define GPIOA_PIN7                  7U
#define GPIOA_PIN8                  8U
#define GPIOA_PIN9                  9U
#define GPIOA_PIN10                 10U
#define GPIOA_USB_DM                11U
#define GPIOA_USB_DP                12U
#define GPIOA_SWDIO                 13U
#define GPIOA_SWCLK                 14U
#define GPIOA_PIN15                 15U

#define GPIOB_DB0                   0U
#define GPIOB_DB1                   1U
#define GPIOB_DB2                   2U
#define GPIOB_DB3                   3U
#define GPIOB_DB4                   4U
#define GPIOB_DB5                   5U
#define GPIOB_DB6                   6U
#define GPIOB_DB7                   7U
#define GPIOB_DB8                   8U
#define GPIOB_DB9                   9U
#define GPIOB_DB10                  10U
#define GPIOB_DB11                  11U
#define GPIOB_DB12                  12U
#define GPIOB_DB13                  13U
#define GPIOB_PIN14                 14U
#define GPIOB_PIN15                 15U

#define GPIOC_PIN0                  0U
#define GPIOC_PIN1                  1U
#define GPIOC_PIN2                  2U
#define GPIOC_PIN3                  3U
#define GPIOC_PIN4                  4U
#define GPIOC_PIN5                  5U
#define GPIOC_SYNC                  6U
#define GPIOC_RESET_8460            7U
#define GPIOC_SDN_RESET             8U
#define GPIOC_SDN_IO                9U
#define GPIOC_SPI_CLK               10U
#define GPIOC_SPI_MISO              11U
#define GPIOC_SPI_MOSI              12U
#define GPIOC_BUTTON                13U
#define GPIOC_PIN13                 13U
#define GPIOC_OSC32_IN              14U
#define GPIOC_OSC32_OUT             15U

#define GPIOD_SPI_CS                0U
#define GPIOD_PIN1                  1U
#define GPIOD_PIN2                  2U
#define GPIOD_PIN3                  3U
#define GPIOD_PIN4                  4U
#define GPIOD_PIN5                  5U
#define GPIOD_PIN6                  6U
#define GPIOD_PIN7                  7U
#define GPIOD_PIN8                  8U
#define GPIOD_PIN9                  9U
#define GPIOD_PIN10                 10U
#define GPIOD_PIN11                 11U
#define GPIOD_PIN12                 12U
#define GPIOD_PIN13                 13U
#define GPIOD_PIN14                 14U
#define GPIOD_PIN15                 15U

#define GPIOE_PIN0                  0U
#define GPIOE_PIN1                  1U
#define GPIOE_PIN2                  2U
#define GPIOE_PIN3                  3U
#define GPIOE_PIN4                  4U
#define GPIOE_PIN5                  5U
#define GPIOE_PIN6                  6U
#define GPIOE_PIN7                  7U
#define GPIOE_PIN8                  8U
#define GPIOE_PIN9                  9U
#define GPIOE_PIN10                 10U
#define GPIOE_PIN11                 11U
#define GPIOE_LED_YELLOW            12U
#define GPIOE_LED_BLUE              13U
#define GPIOE_LED_GREEN             14U
#define GPIOE_LED_RED               15U

#define GPIOF_OSC_IN                0U
#define GPIOF_OSC_OUT               1U
#define GPIOF_PIN2                  2U
#define GPIOF_PIN3                  3U
#define GPIOF_PIN4                  4U
#define GPIOF_PIN5                  5U
#define GPIOF_PIN6                  6U
#define GPIOF_PIN7                  7U
#define GPIOF_PIN8                  8U
#define GPIOF_PIN9                  9U
#define GPIOF_PIN10                 10U
#define GPIOF_PIN11                 11U
#define GPIOF_PIN12                 12U
#define GPIOF_PIN13                 13U
#define GPIOF_PIN14                 14U
#define GPIOF_PIN15                 15U

#define GPIOG_PIN0                  0U
#define GPIOG_PIN1                  1U
#define GPIOG_PIN2                  2U
#define GPIOG_PIN3                  3U
#define GPIOG_PIN4                  4U
#define GPIOG_PIN5                  5U
#define GPIOG_PIN6                  6U
#define GPIOG_PIN7                  7U
#define GPIOG_PIN8                  8U
#define GPIOG_PIN9                  9U
#define GPIOG_PIN10                 10U
#define GPIOG_PIN11                 11U
#define GPIOG_PIN12                 12U
#define GPIOG_PIN13                 13U
#define GPIOG_PIN14                 14U
#define GPIOG_PIN15                 15U

/*
 * IO lines assignments.
 */
#define LINE_AIN1                   PAL_LINE(GPIOA, 0U)
#define LINE_AIN2                   PAL_LINE(GPIOA, 1U)
#define LINE_TX                     PAL_LINE(GPIOA, 2U)
#define LINE_RX                     PAL_LINE(GPIOA, 3U)
#define LINE_USB_DM                 PAL_LINE(GPIOA, 11U)
#define LINE_USB_DP                 PAL_LINE(GPIOA, 12U)
#define LINE_SWDIO                  PAL_LINE(GPIOA, 13U)
#define LINE_SWCLK                  PAL_LINE(GPIOA, 14U)
#define LINE_DB0                    PAL_LINE(GPIOB, 0U)
#define LINE_DB1                    PAL_LINE(GPIOB, 1U)
#define LINE_DB2                    PAL_LINE(GPIOB, 2U)
#define LINE_DB3                    PAL_LINE(GPIOB, 3U)
#define LINE_DB4                    PAL_LINE(GPIOB, 4U)
#define LINE_DB5                    PAL_LINE(GPIOB, 5U)
#define LINE_DB6                    PAL_LINE(GPIOB, 6U)
#define LINE_DB7                    PAL_LINE(GPIOB, 7U)
#define LINE_DB8                    PAL_LINE(GPIOB, 8U)
#define LINE_DB9                    PAL_LINE(GPIOB, 9U)
#define LINE_DB10                   PAL_LINE(GPIOB, 10U)
#define LINE_DB11                   PAL_LINE(GPIOB, 11U)
#define LINE_DB12                   PAL_LINE(GPIOB, 12U)
#define LINE_DB13                   PAL_LINE(GPIOB, 13U)
#define LINE_SYNC                   PAL_LINE(GPIOC, 6U)
#define LINE_RESET_8460             PAL_LINE(GPIOC, 7U)
#define LINE_SDN_RESET              PAL_LINE(GPIOC, 8U)
#define LINE_SDN_IO                 PAL_LINE(GPIOC, 9U)
#define LINE_SPI_CLK                PAL_LINE(GPIOC, 10U)
#define LINE_SPI_MISO               PAL_LINE(GPIOC, 11U)
#define LINE_SPI_MOSI               PAL_LINE(GPIOC, 12U)
#define LINE_BUTTON                 PAL_LINE(GPIOC, 13U)
#define LINE_USER_BUTTON            PAL_LINE(GPIOC, 13U)
#define LINE_OSC32_IN               PAL_LINE(GPIOC, 14U)
#define LINE_OSC32_OUT              PAL_LINE(GPIOC, 15U)
#define LINE_SPI_CS                 PAL_LINE(GPIOD, 0U)
#define LINE_LED_YELLOW             PAL_LINE(GPIOE, 12U)
#define LINE_LED_BLUE               PAL_LINE(GPIOE, 13U)
#define LINE_LED_GREEN              PAL_LINE(GPIOE, 14U)
#define LINE_LED_RED                PAL_LINE(GPIOE, 15U)
#define LINE_OSC_IN                 PAL_LINE(GPIOF, 0U)
#define LINE_OSC_OUT                PAL_LINE(GPIOF, 1U)

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 * Please refer to the STM32 Reference Manual for details.
 */
#define PIN_MODE_INPUT(n)           (0U << ((n) * 2U))
#define PIN_MODE_OUTPUT(n)          (1U << ((n) * 2U))
#define PIN_MODE_ALTERNATE(n)       (2U << ((n) * 2U))
#define PIN_MODE_ANALOG(n)          (3U << ((n) * 2U))
#define PIN_ODR_LOW(n)              (0U << (n))
#define PIN_ODR_HIGH(n)             (1U << (n))
#define PIN_OTYPE_PUSHPULL(n)       (0U << (n))
#define PIN_OTYPE_OPENDRAIN(n)      (1U << (n))
#define PIN_OSPEED_VERYLOW(n)       (0U << ((n) * 2U))
#define PIN_OSPEED_LOW(n)           (1U << ((n) * 2U))
#define PIN_OSPEED_MEDIUM(n)        (2U << ((n) * 2U))
#define PIN_OSPEED_HIGH(n)          (3U << ((n) * 2U))
#define PIN_PUPDR_FLOATING(n)       (0U << ((n) * 2U))
#define PIN_PUPDR_PULLUP(n)         (1U << ((n) * 2U))
#define PIN_PUPDR_PULLDOWN(n)       (2U << ((n) * 2U))
#define PIN_AFIO_AF(n, v)           ((v) << (((n) % 8U) * 4U))
#define PIN_LOCKR_DISABLED(n)       (0U << (n))
#define PIN_LOCKR_ENABLED(n)        (1U << (n))

/*
 * GPIOA setup:
 *
 * PA0  - AIN1                      (analog).
 * PA1  - AIN2                      (analog).
 * PA2  - TX                 (alternate 7).
 * PA3  - RX                 (alternate 7).
 * PA4  - PIN4                      (analog).
 * PA5  - PIN5                      (analog).
 * PA6  - PIN6                      (analog).
 * PA7  - PIN7                      (analog).
 * PA8  - PIN8                      (analog).
 * PA9  - PIN9                      (analog).
 * PA10 - PIN10                     (analog).
 * PA11 - USB_DM                    (analog).
 * PA12 - USB_DP                    (analog).
 * PA13 - SWDIO                     (alternate 0).
 * PA14 - SWCLK                     (alternate 0).
 * PA15 - PIN15                     (analog).
 */
#define VAL_GPIOA_MODER             (PIN_MODE_ANALOG(GPIOA_AIN1) |          \
                                     PIN_MODE_ANALOG(GPIOA_AIN2) |          \
                                     PIN_MODE_ALTERNATE(GPIOA_TX) |  \
                                     PIN_MODE_ALTERNATE(GPIOA_RX) |  \
                                     PIN_MODE_ANALOG(GPIOA_PIN4) |          \
                                     PIN_MODE_ANALOG(GPIOA_PIN5) |          \
                                     PIN_MODE_ANALOG(GPIOA_PIN6) |          \
                                     PIN_MODE_ANALOG(GPIOA_PIN7) |          \
                                     PIN_MODE_ANALOG(GPIOA_PIN8) |          \
                                     PIN_MODE_ANALOG(GPIOA_PIN9) |          \
                                     PIN_MODE_ANALOG(GPIOA_PIN10) |         \
                                     PIN_MODE_ANALOG(GPIOA_USB_DM) |        \
                                     PIN_MODE_ANALOG(GPIOA_USB_DP) |        \
                                     PIN_MODE_ALTERNATE(GPIOA_SWDIO) |      \
                                     PIN_MODE_ALTERNATE(GPIOA_SWCLK) |      \
                                     PIN_MODE_ANALOG(GPIOA_PIN15))
#define VAL_GPIOA_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOA_AIN1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA_AIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA_TX) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOA_RX) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOA_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOA_USB_DM) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOA_USB_DP) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SWDIO) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SWCLK) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOA_PIN15))
#define VAL_GPIOA_OSPEEDR           (PIN_OSPEED_VERYLOW(GPIOA_AIN1) |       \
                                     PIN_OSPEED_VERYLOW(GPIOA_AIN2) |       \
                                     PIN_OSPEED_HIGH(GPIOA_TX) |  \
                                     PIN_OSPEED_HIGH(GPIOA_RX) |  \
                                     PIN_OSPEED_VERYLOW(GPIOA_PIN4) |       \
                                     PIN_OSPEED_HIGH(GPIOA_PIN5) |          \
                                     PIN_OSPEED_VERYLOW(GPIOA_PIN6) |       \
                                     PIN_OSPEED_VERYLOW(GPIOA_PIN7) |       \
                                     PIN_OSPEED_VERYLOW(GPIOA_PIN8) |       \
                                     PIN_OSPEED_VERYLOW(GPIOA_PIN9) |       \
                                     PIN_OSPEED_VERYLOW(GPIOA_PIN10) |      \
                                     PIN_OSPEED_VERYLOW(GPIOA_USB_DM) |     \
                                     PIN_OSPEED_VERYLOW(GPIOA_USB_DP) |     \
                                     PIN_OSPEED_HIGH(GPIOA_SWDIO) |         \
                                     PIN_OSPEED_HIGH(GPIOA_SWCLK) |         \
                                     PIN_OSPEED_VERYLOW(GPIOA_PIN15))
#define VAL_GPIOA_PUPDR             (PIN_PUPDR_FLOATING(GPIOA_AIN1) |       \
                                     PIN_PUPDR_FLOATING(GPIOA_AIN2) |       \
                                     PIN_PUPDR_FLOATING(GPIOA_TX) |  \
                                     PIN_PUPDR_FLOATING(GPIOA_RX) |  \
                                     PIN_PUPDR_FLOATING(GPIOA_PIN4) |       \
                                     PIN_PUPDR_FLOATING(GPIOA_PIN5) |       \
                                     PIN_PUPDR_FLOATING(GPIOA_PIN6) |       \
                                     PIN_PUPDR_FLOATING(GPIOA_PIN7) |       \
                                     PIN_PUPDR_FLOATING(GPIOA_PIN8) |       \
                                     PIN_PUPDR_FLOATING(GPIOA_PIN9) |       \
                                     PIN_PUPDR_FLOATING(GPIOA_PIN10) |      \
                                     PIN_PUPDR_FLOATING(GPIOA_USB_DM) |     \
                                     PIN_PUPDR_FLOATING(GPIOA_USB_DP) |     \
                                     PIN_PUPDR_PULLUP(GPIOA_SWDIO) |        \
                                     PIN_PUPDR_PULLDOWN(GPIOA_SWCLK) |      \
                                     PIN_PUPDR_FLOATING(GPIOA_PIN15))
#define VAL_GPIOA_ODR               (PIN_ODR_LOW(GPIOA_AIN1) |              \
                                     PIN_ODR_LOW(GPIOA_AIN2) |              \
                                     PIN_ODR_LOW(GPIOA_TX) |         \
                                     PIN_ODR_LOW(GPIOA_RX) |         \
                                     PIN_ODR_LOW(GPIOA_PIN4) |              \
                                     PIN_ODR_LOW(GPIOA_PIN5) |              \
                                     PIN_ODR_LOW(GPIOA_PIN6) |              \
                                     PIN_ODR_LOW(GPIOA_PIN7) |              \
                                     PIN_ODR_LOW(GPIOA_PIN8) |              \
                                     PIN_ODR_LOW(GPIOA_PIN9) |              \
                                     PIN_ODR_LOW(GPIOA_PIN10) |             \
                                     PIN_ODR_LOW(GPIOA_USB_DM) |            \
                                     PIN_ODR_LOW(GPIOA_USB_DP) |            \
                                     PIN_ODR_LOW(GPIOA_SWDIO) |             \
                                     PIN_ODR_LOW(GPIOA_SWCLK) |             \
                                     PIN_ODR_LOW(GPIOA_PIN15))
#define VAL_GPIOA_AFRL              (PIN_AFIO_AF(GPIOA_AIN1, 0U) |          \
                                     PIN_AFIO_AF(GPIOA_AIN2, 0U) |          \
                                     PIN_AFIO_AF(GPIOA_TX, 07U) |    \
                                     PIN_AFIO_AF(GPIOA_RX, 07U) |    \
                                     PIN_AFIO_AF(GPIOA_PIN4, 0U) |          \
                                     PIN_AFIO_AF(GPIOA_PIN5, 0U) |          \
                                     PIN_AFIO_AF(GPIOA_PIN6, 0U) |          \
                                     PIN_AFIO_AF(GPIOA_PIN7, 0U))
#define VAL_GPIOA_AFRH              (PIN_AFIO_AF(GPIOA_PIN8, 0U) |          \
                                     PIN_AFIO_AF(GPIOA_PIN9, 0U) |          \
                                     PIN_AFIO_AF(GPIOA_PIN10, 0U) |         \
                                     PIN_AFIO_AF(GPIOA_USB_DM, 0U) |        \
                                     PIN_AFIO_AF(GPIOA_USB_DP, 0U) |        \
                                     PIN_AFIO_AF(GPIOA_SWDIO, 0U) |         \
                                     PIN_AFIO_AF(GPIOA_SWCLK, 0U) |         \
                                     PIN_AFIO_AF(GPIOA_PIN15, 0U))

/*
 * GPIOB setup:
 *
 * PB0  - DB0                       (output pushpull maximum).
 * PB1  - DB1                       (output pushpull maximum).
 * PB2  - DB2                       (output pushpull maximum).
 * PB3  - DB3                       (output pushpull maximum).
 * PB4  - DB4                       (output pushpull maximum).
 * PB5  - DB5                       (output pushpull maximum).
 * PB6  - DB6                       (output pushpull maximum).
 * PB7  - DB7                       (output pushpull minimum).
 * PB8  - DB8                       (output pushpull maximum).
 * PB9  - DB9                       (output pushpull maximum).
 * PB10 - DB10                      (output pushpull maximum).
 * DB11 - DB11                      (output pushpull maximum).
 * PB12 - DB12                      (output pushpull maximum).
 * PB13 - DB13                      (output pushpull maximum).
 * PB14 - PIN14                     (analog).
 * PB15 - PIN15                     (analog).
 */
#define VAL_GPIOB_MODER             (PIN_MODE_OUTPUT(GPIOB_DB0) |           \
                                     PIN_MODE_OUTPUT(GPIOB_DB1) |           \
                                     PIN_MODE_OUTPUT(GPIOB_DB2) |           \
                                     PIN_MODE_OUTPUT(GPIOB_DB3) |           \
                                     PIN_MODE_OUTPUT(GPIOB_DB4) |           \
                                     PIN_MODE_OUTPUT(GPIOB_DB5) |           \
                                     PIN_MODE_OUTPUT(GPIOB_DB6) |           \
                                     PIN_MODE_OUTPUT(GPIOB_DB7) |           \
                                     PIN_MODE_OUTPUT(GPIOB_DB8) |           \
                                     PIN_MODE_OUTPUT(GPIOB_DB9) |           \
                                     PIN_MODE_OUTPUT(GPIOB_DB10) |          \
                                     PIN_MODE_OUTPUT(GPIOB_DB11) |          \
                                     PIN_MODE_OUTPUT(GPIOB_DB12) |          \
                                     PIN_MODE_OUTPUT(GPIOB_DB13) |          \
                                     PIN_MODE_ANALOG(GPIOB_PIN14) |         \
                                     PIN_MODE_ANALOG(GPIOB_PIN15))
#define VAL_GPIOB_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOB_DB0) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOB_DB1) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOB_DB2) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOB_DB3) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOB_DB4) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOB_DB5) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOB_DB6) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOB_DB7) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOB_DB8) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOB_DB9) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOB_DB10) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOB_DB11) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOB_DB12) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOB_DB13) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOB_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOB_PIN15))
#define VAL_GPIOB_OSPEEDR           (PIN_OSPEED_HIGH(GPIOB_DB0) |           \
                                     PIN_OSPEED_HIGH(GPIOB_DB1) |           \
                                     PIN_OSPEED_HIGH(GPIOB_DB2) |           \
                                     PIN_OSPEED_HIGH(GPIOB_DB3) |           \
                                     PIN_OSPEED_HIGH(GPIOB_DB4) |           \
                                     PIN_OSPEED_HIGH(GPIOB_DB5) |           \
                                     PIN_OSPEED_HIGH(GPIOB_DB6) |           \
                                     PIN_OSPEED_HIGH(GPIOB_DB7) |           \
                                     PIN_OSPEED_HIGH(GPIOB_DB8) |           \
                                     PIN_OSPEED_HIGH(GPIOB_DB9) |           \
                                     PIN_OSPEED_HIGH(GPIOB_DB10) |          \
                                     PIN_OSPEED_HIGH(GPIOB_DB11) |          \
                                     PIN_OSPEED_HIGH(GPIOB_DB12) |          \
                                     PIN_OSPEED_HIGH(GPIOB_DB13) |          \
                                     PIN_OSPEED_VERYLOW(GPIOB_PIN14) |      \
                                     PIN_OSPEED_VERYLOW(GPIOB_PIN15))
#define VAL_GPIOB_PUPDR             (PIN_PUPDR_FLOATING(GPIOB_DB0) |        \
                                     PIN_PUPDR_FLOATING(GPIOB_DB1) |        \
                                     PIN_PUPDR_FLOATING(GPIOB_DB2) |        \
                                     PIN_PUPDR_FLOATING(GPIOB_DB3) |        \
                                     PIN_PUPDR_FLOATING(GPIOB_DB4) |        \
                                     PIN_PUPDR_FLOATING(GPIOB_DB5) |        \
                                     PIN_PUPDR_FLOATING(GPIOB_DB6) |        \
                                     PIN_PUPDR_FLOATING(GPIOB_DB7) |        \
                                     PIN_PUPDR_FLOATING(GPIOB_DB8) |        \
                                     PIN_PUPDR_FLOATING(GPIOB_DB9) |        \
                                     PIN_PUPDR_FLOATING(GPIOB_DB10) |       \
                                     PIN_PUPDR_FLOATING(GPIOB_DB11) |       \
                                     PIN_PUPDR_FLOATING(GPIOB_DB12) |       \
                                     PIN_PUPDR_FLOATING(GPIOB_DB13) |       \
                                     PIN_PUPDR_FLOATING(GPIOB_PIN14) |      \
                                     PIN_PUPDR_FLOATING(GPIOB_PIN15))
#define VAL_GPIOB_ODR               (PIN_ODR_LOW(GPIOB_DB0) |               \
                                     PIN_ODR_LOW(GPIOB_DB1) |               \
                                     PIN_ODR_LOW(GPIOB_DB2) |               \
                                     PIN_ODR_LOW(GPIOB_DB3) |               \
                                     PIN_ODR_LOW(GPIOB_DB4) |               \
                                     PIN_ODR_LOW(GPIOB_DB5) |               \
                                     PIN_ODR_LOW(GPIOB_DB6) |               \
                                     PIN_ODR_LOW(GPIOB_DB7) |               \
                                     PIN_ODR_LOW(GPIOB_DB8) |               \
                                     PIN_ODR_LOW(GPIOB_DB9) |               \
                                     PIN_ODR_LOW(GPIOB_DB10) |              \
                                     PIN_ODR_LOW(GPIOB_DB11) |              \
                                     PIN_ODR_LOW(GPIOB_DB12) |              \
                                     PIN_ODR_LOW(GPIOB_DB13) |              \
                                     PIN_ODR_LOW(GPIOB_PIN14) |             \
                                     PIN_ODR_LOW(GPIOB_PIN15))
#define VAL_GPIOB_AFRL              (PIN_AFIO_AF(GPIOB_DB0, 0U) |           \
                                     PIN_AFIO_AF(GPIOB_DB1, 0U) |           \
                                     PIN_AFIO_AF(GPIOB_DB2, 0U) |           \
                                     PIN_AFIO_AF(GPIOB_DB3, 0U) |           \
                                     PIN_AFIO_AF(GPIOB_DB4, 0U) |           \
                                     PIN_AFIO_AF(GPIOB_DB5, 0U) |           \
                                     PIN_AFIO_AF(GPIOB_DB6, 0U) |           \
                                     PIN_AFIO_AF(GPIOB_DB7, 0U))
#define VAL_GPIOB_AFRH              (PIN_AFIO_AF(GPIOB_DB8, 0U) |           \
                                     PIN_AFIO_AF(GPIOB_DB9, 0U) |           \
                                     PIN_AFIO_AF(GPIOB_DB10, 0U) |          \
                                     PIN_AFIO_AF(GPIOB_DB11, 0U) |          \
                                     PIN_AFIO_AF(GPIOB_DB12, 0U) |          \
                                     PIN_AFIO_AF(GPIOB_DB13, 0U) |          \
                                     PIN_AFIO_AF(GPIOB_PIN14, 0U) |         \
                                     PIN_AFIO_AF(GPIOB_PIN15, 0U))

/*
 * GPIOC setup:
 *
 * PC0  - PIN0                      (analog).
 * PC1  - PIN1                      (analog).
 * PC2  - PIN2                      (analog).
 * PC3  - PIN3                      (analog).
 * PC4  - PIN4                      (analog).
 * PC5  - PIN5                      (analog).
 * PC6  - SYNC                      (alternate 4).
 * PC7  - RESET_8460                (output pushpull minimum) // startup high: digital on
 * PC8  - SDN_RESET                 (output pushpull minimum)
 * PC9  - SDN_IO                    (output pushpull minimum) // startup high: HV off
 * PC10 - SPI_CLK                   (alternate 6).
 * PC11 - SPI_MISO                  (alternate 6).
 * PC12 - SPI_MOSI                  (alternate 6).
 * PC13 - PIN13                     (analog).
 * PC14 - OSC32_IN                  (analog).
 * PC15 - OSC32_OUT                 (analog).
 */
#define VAL_GPIOC_MODER             (PIN_MODE_ANALOG(GPIOC_PIN0) |          \
                                     PIN_MODE_ANALOG(GPIOC_PIN1) |          \
                                     PIN_MODE_ANALOG(GPIOC_PIN2) |          \
                                     PIN_MODE_ANALOG(GPIOC_PIN3) |          \
                                     PIN_MODE_ANALOG(GPIOC_PIN4) |          \
                                     PIN_MODE_ANALOG(GPIOC_PIN5) |          \
                                     PIN_MODE_OUTPUT(GPIOC_SYNC) |       \
                                     PIN_MODE_OUTPUT(GPIOC_RESET_8460) |    \
                                     PIN_MODE_OUTPUT(GPIOC_SDN_RESET) |     \
                                     PIN_MODE_OUTPUT(GPIOC_SDN_IO) |        \
                                     PIN_MODE_ALTERNATE(GPIOC_SPI_CLK) |    \
                                     PIN_MODE_ALTERNATE(GPIOC_SPI_MISO) |   \
                                     PIN_MODE_ALTERNATE(GPIOC_SPI_MOSI) |   \
                                     PIN_MODE_ANALOG(GPIOC_PIN13) |         \
                                     PIN_MODE_ANALOG(GPIOC_OSC32_IN) |      \
                                     PIN_MODE_ANALOG(GPIOC_OSC32_OUT))
#define VAL_GPIOC_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOC_PIN0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC_SYNC) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC_RESET_8460) | \
                                     PIN_OTYPE_PUSHPULL(GPIOC_SDN_RESET) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOC_SDN_IO) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOC_SPI_CLK) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOC_SPI_MISO) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOC_SPI_MOSI) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN13) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOC_OSC32_IN) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOC_OSC32_OUT))
#define VAL_GPIOC_OSPEEDR           (PIN_OSPEED_VERYLOW(GPIOC_PIN0) |       \
                                     PIN_OSPEED_VERYLOW(GPIOC_PIN1) |       \
                                     PIN_OSPEED_VERYLOW(GPIOC_PIN2) |       \
                                     PIN_OSPEED_VERYLOW(GPIOC_PIN3) |       \
                                     PIN_OSPEED_VERYLOW(GPIOC_PIN4) |       \
                                     PIN_OSPEED_VERYLOW(GPIOC_PIN5) |       \
                                     PIN_OSPEED_HIGH(GPIOC_SYNC) |          \
                                     PIN_OSPEED_VERYLOW(GPIOC_RESET_8460) | \
                                     PIN_OSPEED_VERYLOW(GPIOC_SDN_RESET) |  \
                                     PIN_OSPEED_VERYLOW(GPIOC_SDN_IO) |     \
                                     PIN_OSPEED_VERYLOW(GPIOC_SPI_CLK) |    \
                                     PIN_OSPEED_VERYLOW(GPIOC_SPI_MISO) |   \
                                     PIN_OSPEED_VERYLOW(GPIOC_SPI_MOSI) |   \
                                     PIN_OSPEED_VERYLOW(GPIOC_PIN13) |     \
                                     PIN_OSPEED_VERYLOW(GPIOC_OSC32_IN) |   \
                                     PIN_OSPEED_VERYLOW(GPIOC_OSC32_OUT))
#define VAL_GPIOC_PUPDR             (PIN_PUPDR_FLOATING(GPIOC_PIN0) |       \
                                     PIN_PUPDR_FLOATING(GPIOC_PIN1) |       \
                                     PIN_PUPDR_FLOATING(GPIOC_PIN2) |       \
                                     PIN_PUPDR_FLOATING(GPIOC_PIN3) |       \
                                     PIN_PUPDR_FLOATING(GPIOC_PIN4) |       \
                                     PIN_PUPDR_FLOATING(GPIOC_PIN5) |       \
                                     PIN_PUPDR_FLOATING(GPIOC_SYNC) |       \
                                     PIN_PUPDR_FLOATING(GPIOC_RESET_8460) | \
                                     PIN_PUPDR_FLOATING(GPIOC_SDN_RESET) |  \
                                     PIN_PUPDR_FLOATING(GPIOC_SDN_IO) |     \
                                     PIN_PUPDR_FLOATING(GPIOC_SPI_CLK) |    \
                                     PIN_PUPDR_FLOATING(GPIOC_SPI_MISO) |   \
                                     PIN_PUPDR_FLOATING(GPIOC_SPI_MOSI) |   \
                                     PIN_PUPDR_FLOATING(GPIOC_PIN13) |     \
                                     PIN_PUPDR_FLOATING(GPIOC_OSC32_IN) |   \
                                     PIN_PUPDR_FLOATING(GPIOC_OSC32_OUT))
#define VAL_GPIOC_ODR               (PIN_ODR_LOW(GPIOC_PIN0) |              \
                                     PIN_ODR_LOW(GPIOC_PIN1) |              \
                                     PIN_ODR_LOW(GPIOC_PIN2) |              \
                                     PIN_ODR_LOW(GPIOC_PIN3) |              \
                                     PIN_ODR_LOW(GPIOC_PIN4) |              \
                                     PIN_ODR_LOW(GPIOC_PIN5) |              \
                                     PIN_ODR_LOW(GPIOC_SYNC) |              \
                                     PIN_ODR_HIGH(GPIOC_RESET_8460) |        \
                                     PIN_ODR_LOW(GPIOC_SDN_RESET) |         \
                                     PIN_ODR_HIGH(GPIOC_SDN_IO) |            \
                                     PIN_ODR_LOW(GPIOC_SPI_CLK) |           \
                                     PIN_ODR_LOW(GPIOC_SPI_MISO) |          \
                                     PIN_ODR_LOW(GPIOC_SPI_MOSI) |          \
                                     PIN_ODR_LOW(GPIOC_PIN13) |            \
                                     PIN_ODR_LOW(GPIOC_OSC32_IN) |          \
                                     PIN_ODR_LOW(GPIOC_OSC32_OUT))
#define VAL_GPIOC_AFRL              (PIN_AFIO_AF(GPIOC_PIN0, 0U) |          \
                                     PIN_AFIO_AF(GPIOC_PIN1, 0U) |          \
                                     PIN_AFIO_AF(GPIOC_PIN2, 0U) |          \
                                     PIN_AFIO_AF(GPIOC_PIN3, 0U) |          \
                                     PIN_AFIO_AF(GPIOC_PIN4, 0U) |          \
                                     PIN_AFIO_AF(GPIOC_PIN5, 0U) |          \
                                     PIN_AFIO_AF(GPIOC_SYNC, 4U) |          \
                                     PIN_AFIO_AF(GPIOC_RESET_8460, 0U))
#define VAL_GPIOC_AFRH              (PIN_AFIO_AF(GPIOC_SDN_RESET, 0U) |     \
                                     PIN_AFIO_AF(GPIOC_SDN_IO, 0U) |        \
                                     PIN_AFIO_AF(GPIOC_SPI_CLK, 6U) |       \
                                     PIN_AFIO_AF(GPIOC_SPI_MISO, 6U) |      \
                                     PIN_AFIO_AF(GPIOC_SPI_MOSI, 6U) |      \
                                     PIN_AFIO_AF(GPIOC_PIN13, 0U) |        \
                                     PIN_AFIO_AF(GPIOC_OSC32_IN, 0U) |      \
                                     PIN_AFIO_AF(GPIOC_OSC32_OUT, 0U))

/*
 * GPIOD setup:
 *
 * PD0  - SPI_CS                    (output pushpull low).
 * PD1  - PIN1                      (analog).
 * PD2  - PIN2                      (analog).
 * PD3  - PIN3                      (analog).
 * PD4  - PIN4                      (analog).
 * PD5  - PIN5                      (analog).
 * PD6  - PIN6                      (analog).
 * PD7  - PIN7                      (analog).
 * PD8  - PIN8                      (analog).
 * PD9  - PIN9                      (analog).
 * PD10 - PIN10                     (analog).
 * PD11 - PIN11                     (analog).
 * PD12 - PIN12                     (analog).
 * PD13 - PIN13                     (analog).
 * PD14 - PIN14                     (analog).
 * PD15 - PIN15                     (analog).
 */
#define VAL_GPIOD_MODER             (PIN_MODE_OUTPUT(GPIOD_SPI_CS) |        \
                                     PIN_MODE_ANALOG(GPIOD_PIN1) |          \
                                     PIN_MODE_ANALOG(GPIOD_PIN2) |          \
                                     PIN_MODE_ANALOG(GPIOD_PIN3) |          \
                                     PIN_MODE_ANALOG(GPIOD_PIN4) |          \
                                     PIN_MODE_ANALOG(GPIOD_PIN5) |          \
                                     PIN_MODE_ANALOG(GPIOD_PIN6) |          \
                                     PIN_MODE_ANALOG(GPIOD_PIN7) |          \
                                     PIN_MODE_ANALOG(GPIOD_PIN8) |          \
                                     PIN_MODE_ANALOG(GPIOD_PIN9) |          \
                                     PIN_MODE_ANALOG(GPIOD_PIN10) |         \
                                     PIN_MODE_ANALOG(GPIOD_PIN11) |         \
                                     PIN_MODE_ANALOG(GPIOD_PIN12) |         \
                                     PIN_MODE_ANALOG(GPIOD_PIN13) |         \
                                     PIN_MODE_ANALOG(GPIOD_PIN14) |         \
                                     PIN_MODE_ANALOG(GPIOD_PIN15))
#define VAL_GPIOD_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOD_SPI_CS) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN15))
#define VAL_GPIOD_OSPEEDR           (PIN_OSPEED_MEDIUM(GPIOD_SPI_CS) |         \
                                     PIN_OSPEED_VERYLOW(GPIOD_PIN1) |       \
                                     PIN_OSPEED_VERYLOW(GPIOD_PIN2) |       \
                                     PIN_OSPEED_VERYLOW(GPIOD_PIN3) |       \
                                     PIN_OSPEED_VERYLOW(GPIOD_PIN4) |       \
                                     PIN_OSPEED_VERYLOW(GPIOD_PIN5) |       \
                                     PIN_OSPEED_VERYLOW(GPIOD_PIN6) |       \
                                     PIN_OSPEED_VERYLOW(GPIOD_PIN7) |       \
                                     PIN_OSPEED_VERYLOW(GPIOD_PIN8) |       \
                                     PIN_OSPEED_VERYLOW(GPIOD_PIN9) |       \
                                     PIN_OSPEED_VERYLOW(GPIOD_PIN10) |      \
                                     PIN_OSPEED_VERYLOW(GPIOD_PIN11) |      \
                                     PIN_OSPEED_VERYLOW(GPIOD_PIN12) |      \
                                     PIN_OSPEED_VERYLOW(GPIOD_PIN13) |      \
                                     PIN_OSPEED_VERYLOW(GPIOD_PIN14) |      \
                                     PIN_OSPEED_VERYLOW(GPIOD_PIN15))
#define VAL_GPIOD_PUPDR             (PIN_PUPDR_FLOATING(GPIOD_SPI_CS) |     \
                                     PIN_PUPDR_FLOATING(GPIOD_PIN1) |       \
                                     PIN_PUPDR_FLOATING(GPIOD_PIN2) |       \
                                     PIN_PUPDR_FLOATING(GPIOD_PIN3) |       \
                                     PIN_PUPDR_FLOATING(GPIOD_PIN4) |       \
                                     PIN_PUPDR_FLOATING(GPIOD_PIN5) |       \
                                     PIN_PUPDR_FLOATING(GPIOD_PIN6) |       \
                                     PIN_PUPDR_FLOATING(GPIOD_PIN7) |       \
                                     PIN_PUPDR_FLOATING(GPIOD_PIN8) |       \
                                     PIN_PUPDR_FLOATING(GPIOD_PIN9) |       \
                                     PIN_PUPDR_FLOATING(GPIOD_PIN10) |      \
                                     PIN_PUPDR_FLOATING(GPIOD_PIN11) |      \
                                     PIN_PUPDR_FLOATING(GPIOD_PIN12) |      \
                                     PIN_PUPDR_FLOATING(GPIOD_PIN13) |      \
                                     PIN_PUPDR_FLOATING(GPIOD_PIN14) |      \
                                     PIN_PUPDR_FLOATING(GPIOD_PIN15))
#define VAL_GPIOD_ODR               (PIN_ODR_HIGH(GPIOD_SPI_CS) |            \
                                     PIN_ODR_LOW(GPIOD_PIN1) |              \
                                     PIN_ODR_LOW(GPIOD_PIN2) |              \
                                     PIN_ODR_LOW(GPIOD_PIN3) |              \
                                     PIN_ODR_LOW(GPIOD_PIN4) |              \
                                     PIN_ODR_LOW(GPIOD_PIN5) |              \
                                     PIN_ODR_LOW(GPIOD_PIN6) |              \
                                     PIN_ODR_LOW(GPIOD_PIN7) |              \
                                     PIN_ODR_LOW(GPIOD_PIN8) |              \
                                     PIN_ODR_LOW(GPIOD_PIN9) |              \
                                     PIN_ODR_LOW(GPIOD_PIN10) |             \
                                     PIN_ODR_LOW(GPIOD_PIN11) |             \
                                     PIN_ODR_LOW(GPIOD_PIN12) |             \
                                     PIN_ODR_LOW(GPIOD_PIN13) |             \
                                     PIN_ODR_LOW(GPIOD_PIN14) |             \
                                     PIN_ODR_LOW(GPIOD_PIN15))
#define VAL_GPIOD_AFRL              (PIN_AFIO_AF(GPIOD_SPI_CS, 0U) |        \
                                     PIN_AFIO_AF(GPIOD_PIN1, 0U) |          \
                                     PIN_AFIO_AF(GPIOD_PIN2, 0U) |          \
                                     PIN_AFIO_AF(GPIOD_PIN3, 0U) |          \
                                     PIN_AFIO_AF(GPIOD_PIN4, 0U) |          \
                                     PIN_AFIO_AF(GPIOD_PIN5, 0U) |          \
                                     PIN_AFIO_AF(GPIOD_PIN6, 0U) |          \
                                     PIN_AFIO_AF(GPIOD_PIN7, 0U))
#define VAL_GPIOD_AFRH              (PIN_AFIO_AF(GPIOD_PIN8, 0U) |          \
                                     PIN_AFIO_AF(GPIOD_PIN9, 0U) |          \
                                     PIN_AFIO_AF(GPIOD_PIN10, 0U) |         \
                                     PIN_AFIO_AF(GPIOD_PIN11, 0U) |         \
                                     PIN_AFIO_AF(GPIOD_PIN12, 0U) |         \
                                     PIN_AFIO_AF(GPIOD_PIN13, 0U) |         \
                                     PIN_AFIO_AF(GPIOD_PIN14, 0U) |         \
                                     PIN_AFIO_AF(GPIOD_PIN15, 0U))

/*
 * GPIOE setup:
 *
 * PE0  - PIN0                      (analog).
 * PE1  - PIN1                      (analog).
 * PE2  - PIN2                      (analog).
 * PE3  - PIN3                      (analog).
 * PE4  - PIN4                      (analog).
 * PE5  - PIN5                      (analog).
 * PE6  - PIN6                      (analog).
 * PE7  - PIN7                      (analog).
 * PE8  - PIN8                      (analog).
 * PE9  - PIN9                      (analog).
 * PE10 - PIN10                     (analog).
 * PE11 - PIN11                     (analog).
 * PE12 - LED_yellow                (output pushpull minimum).
 * PE13 - LED_blue                  (output pushpull minimum).
 * PE14 - LED_green                 (output pushpull minimum).
 * PE15 - LED_red                   (output pushpull minimum).
 */
#define VAL_GPIOE_MODER             (PIN_MODE_ANALOG(GPIOE_PIN0) |          \
                                     PIN_MODE_ANALOG(GPIOE_PIN1) |          \
                                     PIN_MODE_ANALOG(GPIOE_PIN2) |          \
                                     PIN_MODE_ANALOG(GPIOE_PIN3) |          \
                                     PIN_MODE_ANALOG(GPIOE_PIN4) |          \
                                     PIN_MODE_ANALOG(GPIOE_PIN5) |          \
                                     PIN_MODE_ANALOG(GPIOE_PIN6) |          \
                                     PIN_MODE_ANALOG(GPIOE_PIN7) |          \
                                     PIN_MODE_ANALOG(GPIOE_PIN8) |          \
                                     PIN_MODE_ANALOG(GPIOE_PIN9) |          \
                                     PIN_MODE_ANALOG(GPIOE_PIN10) |         \
                                     PIN_MODE_ANALOG(GPIOE_PIN11) |         \
                                     PIN_MODE_OUTPUT(GPIOE_LED_YELLOW) |    \
                                     PIN_MODE_OUTPUT(GPIOE_LED_BLUE) |      \
                                     PIN_MODE_OUTPUT(GPIOE_LED_GREEN) |     \
                                     PIN_MODE_OUTPUT(GPIOE_LED_RED))
#define VAL_GPIOE_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOE_PIN0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOE_LED_YELLOW) | \
                                     PIN_OTYPE_PUSHPULL(GPIOE_LED_BLUE) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOE_LED_GREEN) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOE_LED_RED))
#define VAL_GPIOE_OSPEEDR           (PIN_OSPEED_VERYLOW(GPIOE_PIN0) |       \
                                     PIN_OSPEED_VERYLOW(GPIOE_PIN1) |       \
                                     PIN_OSPEED_VERYLOW(GPIOE_PIN2) |       \
                                     PIN_OSPEED_VERYLOW(GPIOE_PIN3) |       \
                                     PIN_OSPEED_VERYLOW(GPIOE_PIN4) |       \
                                     PIN_OSPEED_VERYLOW(GPIOE_PIN5) |       \
                                     PIN_OSPEED_VERYLOW(GPIOE_PIN6) |       \
                                     PIN_OSPEED_VERYLOW(GPIOE_PIN7) |       \
                                     PIN_OSPEED_VERYLOW(GPIOE_PIN8) |       \
                                     PIN_OSPEED_VERYLOW(GPIOE_PIN9) |       \
                                     PIN_OSPEED_VERYLOW(GPIOE_PIN10) |      \
                                     PIN_OSPEED_VERYLOW(GPIOE_PIN11) |      \
                                     PIN_OSPEED_VERYLOW(GPIOE_LED_YELLOW) | \
                                     PIN_OSPEED_VERYLOW(GPIOE_LED_BLUE) |   \
                                     PIN_OSPEED_VERYLOW(GPIOE_LED_GREEN) |  \
                                     PIN_OSPEED_VERYLOW(GPIOE_LED_RED))
#define VAL_GPIOE_PUPDR             (PIN_PUPDR_FLOATING(GPIOE_PIN0) |       \
                                     PIN_PUPDR_FLOATING(GPIOE_PIN1) |       \
                                     PIN_PUPDR_FLOATING(GPIOE_PIN2) |       \
                                     PIN_PUPDR_FLOATING(GPIOE_PIN3) |       \
                                     PIN_PUPDR_FLOATING(GPIOE_PIN4) |       \
                                     PIN_PUPDR_FLOATING(GPIOE_PIN5) |       \
                                     PIN_PUPDR_FLOATING(GPIOE_PIN6) |       \
                                     PIN_PUPDR_FLOATING(GPIOE_PIN7) |       \
                                     PIN_PUPDR_FLOATING(GPIOE_PIN8) |       \
                                     PIN_PUPDR_FLOATING(GPIOE_PIN9) |       \
                                     PIN_PUPDR_FLOATING(GPIOE_PIN10) |      \
                                     PIN_PUPDR_FLOATING(GPIOE_PIN11) |      \
                                     PIN_PUPDR_FLOATING(GPIOE_LED_YELLOW) | \
                                     PIN_PUPDR_FLOATING(GPIOE_LED_BLUE) |   \
                                     PIN_PUPDR_FLOATING(GPIOE_LED_GREEN) |  \
                                     PIN_PUPDR_FLOATING(GPIOE_LED_RED))
#define VAL_GPIOE_ODR               (PIN_ODR_LOW(GPIOE_PIN0) |              \
                                     PIN_ODR_LOW(GPIOE_PIN1) |              \
                                     PIN_ODR_LOW(GPIOE_PIN2) |              \
                                     PIN_ODR_LOW(GPIOE_PIN3) |              \
                                     PIN_ODR_LOW(GPIOE_PIN4) |              \
                                     PIN_ODR_LOW(GPIOE_PIN5) |              \
                                     PIN_ODR_LOW(GPIOE_PIN6) |              \
                                     PIN_ODR_LOW(GPIOE_PIN7) |              \
                                     PIN_ODR_LOW(GPIOE_PIN8) |              \
                                     PIN_ODR_LOW(GPIOE_PIN9) |              \
                                     PIN_ODR_LOW(GPIOE_PIN10) |             \
                                     PIN_ODR_LOW(GPIOE_PIN11) |             \
                                     PIN_ODR_LOW(GPIOE_LED_YELLOW) |        \
                                     PIN_ODR_LOW(GPIOE_LED_BLUE) |          \
                                     PIN_ODR_LOW(GPIOE_LED_GREEN) |         \
                                     PIN_ODR_LOW(GPIOE_LED_RED))
#define VAL_GPIOE_AFRL              (PIN_AFIO_AF(GPIOE_PIN0, 0U) |          \
                                     PIN_AFIO_AF(GPIOE_PIN1, 0U) |          \
                                     PIN_AFIO_AF(GPIOE_PIN2, 0U) |          \
                                     PIN_AFIO_AF(GPIOE_PIN3, 0U) |          \
                                     PIN_AFIO_AF(GPIOE_PIN4, 0U) |          \
                                     PIN_AFIO_AF(GPIOE_PIN5, 0U) |          \
                                     PIN_AFIO_AF(GPIOE_PIN6, 0U) |          \
                                     PIN_AFIO_AF(GPIOE_PIN7, 0U))
#define VAL_GPIOE_AFRH              (PIN_AFIO_AF(GPIOE_PIN8, 0U) |          \
                                     PIN_AFIO_AF(GPIOE_PIN9, 0U) |          \
                                     PIN_AFIO_AF(GPIOE_PIN10, 0U) |         \
                                     PIN_AFIO_AF(GPIOE_PIN11, 0U) |         \
                                     PIN_AFIO_AF(GPIOE_LED_YELLOW, 0U) |    \
                                     PIN_AFIO_AF(GPIOE_LED_BLUE, 0U) |      \
                                     PIN_AFIO_AF(GPIOE_LED_GREEN, 0U) |     \
                                     PIN_AFIO_AF(GPIOE_LED_RED, 0U))

/*
 * GPIOF setup:
 *
 * PF0  - OSC_IN                    (analog).
 * PF1  - OSC_OUT                   (analog).
 * PF2  - PIN2                      (analog).
 * PF3  - PIN3                      (analog).
 * PF4  - PIN4                      (analog).
 * PF5  - PIN5                      (analog).
 * PF6  - PIN6                      (analog).
 * PF7  - PIN7                      (analog).
 * PF8  - PIN8                      (analog).
 * PF9  - PIN9                      (analog).
 * PF10 - PIN10                     (analog).
 * PF11 - PIN11                     (analog).
 * PF12 - PIN12                     (analog).
 * PF13 - PIN13                     (analog).
 * PF14 - PIN14                     (analog).
 * PF15 - PIN15                     (analog).
 */
#define VAL_GPIOF_MODER             (PIN_MODE_ANALOG(GPIOF_OSC_IN) |        \
                                     PIN_MODE_ANALOG(GPIOF_OSC_OUT) |       \
                                     PIN_MODE_ANALOG(GPIOF_PIN2) |          \
                                     PIN_MODE_ANALOG(GPIOF_PIN3) |          \
                                     PIN_MODE_ANALOG(GPIOF_PIN4) |          \
                                     PIN_MODE_ANALOG(GPIOF_PIN5) |          \
                                     PIN_MODE_ANALOG(GPIOF_PIN6) |          \
                                     PIN_MODE_ANALOG(GPIOF_PIN7) |          \
                                     PIN_MODE_ANALOG(GPIOF_PIN8) |          \
                                     PIN_MODE_ANALOG(GPIOF_PIN9) |          \
                                     PIN_MODE_ANALOG(GPIOF_PIN10) |         \
                                     PIN_MODE_ANALOG(GPIOF_PIN11) |         \
                                     PIN_MODE_ANALOG(GPIOF_PIN12) |         \
                                     PIN_MODE_ANALOG(GPIOF_PIN13) |         \
                                     PIN_MODE_ANALOG(GPIOF_PIN14) |         \
                                     PIN_MODE_ANALOG(GPIOF_PIN15))
#define VAL_GPIOF_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOF_OSC_IN) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOF_OSC_OUT) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN15))
#define VAL_GPIOF_OSPEEDR           (PIN_OSPEED_VERYLOW(GPIOF_OSC_IN) |     \
                                     PIN_OSPEED_VERYLOW(GPIOF_OSC_OUT) |    \
                                     PIN_OSPEED_VERYLOW(GPIOF_PIN2) |       \
                                     PIN_OSPEED_VERYLOW(GPIOF_PIN3) |       \
                                     PIN_OSPEED_VERYLOW(GPIOF_PIN4) |       \
                                     PIN_OSPEED_VERYLOW(GPIOF_PIN5) |       \
                                     PIN_OSPEED_VERYLOW(GPIOF_PIN6) |       \
                                     PIN_OSPEED_VERYLOW(GPIOF_PIN7) |       \
                                     PIN_OSPEED_VERYLOW(GPIOF_PIN8) |       \
                                     PIN_OSPEED_VERYLOW(GPIOF_PIN9) |       \
                                     PIN_OSPEED_VERYLOW(GPIOF_PIN10) |      \
                                     PIN_OSPEED_VERYLOW(GPIOF_PIN11) |      \
                                     PIN_OSPEED_VERYLOW(GPIOF_PIN12) |      \
                                     PIN_OSPEED_VERYLOW(GPIOF_PIN13) |      \
                                     PIN_OSPEED_VERYLOW(GPIOF_PIN14) |      \
                                     PIN_OSPEED_VERYLOW(GPIOF_PIN15))
#define VAL_GPIOF_PUPDR             (PIN_PUPDR_FLOATING(GPIOF_OSC_IN) |     \
                                     PIN_PUPDR_FLOATING(GPIOF_OSC_OUT) |    \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN2) |       \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN3) |       \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN4) |       \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN5) |       \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN6) |       \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN7) |       \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN8) |       \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN9) |       \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN10) |      \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN11) |      \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN12) |      \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN13) |      \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN14) |      \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN15))
#define VAL_GPIOF_ODR               (PIN_ODR_LOW(GPIOF_OSC_IN) |            \
                                     PIN_ODR_LOW(GPIOF_OSC_OUT) |           \
                                     PIN_ODR_LOW(GPIOF_PIN2) |              \
                                     PIN_ODR_LOW(GPIOF_PIN3) |              \
                                     PIN_ODR_LOW(GPIOF_PIN4) |              \
                                     PIN_ODR_LOW(GPIOF_PIN5) |              \
                                     PIN_ODR_LOW(GPIOF_PIN6) |              \
                                     PIN_ODR_LOW(GPIOF_PIN7) |              \
                                     PIN_ODR_LOW(GPIOF_PIN8) |              \
                                     PIN_ODR_LOW(GPIOF_PIN9) |              \
                                     PIN_ODR_LOW(GPIOF_PIN10) |             \
                                     PIN_ODR_LOW(GPIOF_PIN11) |             \
                                     PIN_ODR_LOW(GPIOF_PIN12) |             \
                                     PIN_ODR_LOW(GPIOF_PIN13) |             \
                                     PIN_ODR_LOW(GPIOF_PIN14) |             \
                                     PIN_ODR_LOW(GPIOF_PIN15))
#define VAL_GPIOF_AFRL              (PIN_AFIO_AF(GPIOF_OSC_IN, 0U) |        \
                                     PIN_AFIO_AF(GPIOF_OSC_OUT, 0U) |       \
                                     PIN_AFIO_AF(GPIOF_PIN2, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN3, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN4, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN5, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN6, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN7, 0U))
#define VAL_GPIOF_AFRH              (PIN_AFIO_AF(GPIOF_PIN8, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN9, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN10, 0U) |         \
                                     PIN_AFIO_AF(GPIOF_PIN11, 0U) |         \
                                     PIN_AFIO_AF(GPIOF_PIN12, 0U) |         \
                                     PIN_AFIO_AF(GPIOF_PIN13, 0U) |         \
                                     PIN_AFIO_AF(GPIOF_PIN14, 0U) |         \
                                     PIN_AFIO_AF(GPIOF_PIN15, 0U))

/*
 * GPIOG setup:
 *
 * PG0  - PIN0                      (analog).
 * PG1  - PIN1                      (analog).
 * PG2  - PIN2                      (analog).
 * PG3  - PIN3                      (analog).
 * PG4  - PIN4                      (analog).
 * PG5  - PIN5                      (analog).
 * PG6  - PIN6                      (analog).
 * PG7  - PIN7                      (analog).
 * PG8  - PIN8                      (analog).
 * PG9  - PIN9                      (analog).
 * PG10 - PIN10                     (analog).
 * PG11 - PIN11                     (analog).
 * PG12 - PIN12                     (analog).
 * PG13 - PIN13                     (analog).
 * PG14 - PIN14                     (analog).
 * PG15 - PIN15                     (analog).
 */
#define VAL_GPIOG_MODER             (PIN_MODE_ANALOG(GPIOG_PIN0) |          \
                                     PIN_MODE_ANALOG(GPIOG_PIN1) |          \
                                     PIN_MODE_ANALOG(GPIOG_PIN2) |          \
                                     PIN_MODE_ANALOG(GPIOG_PIN3) |          \
                                     PIN_MODE_ANALOG(GPIOG_PIN4) |          \
                                     PIN_MODE_ANALOG(GPIOG_PIN5) |          \
                                     PIN_MODE_ANALOG(GPIOG_PIN6) |          \
                                     PIN_MODE_ANALOG(GPIOG_PIN7) |          \
                                     PIN_MODE_ANALOG(GPIOG_PIN8) |          \
                                     PIN_MODE_ANALOG(GPIOG_PIN9) |          \
                                     PIN_MODE_ANALOG(GPIOG_PIN10) |         \
                                     PIN_MODE_ANALOG(GPIOG_PIN11) |         \
                                     PIN_MODE_ANALOG(GPIOG_PIN12) |         \
                                     PIN_MODE_ANALOG(GPIOG_PIN13) |         \
                                     PIN_MODE_ANALOG(GPIOG_PIN14) |         \
                                     PIN_MODE_ANALOG(GPIOG_PIN15))
#define VAL_GPIOG_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOG_PIN0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN15))
#define VAL_GPIOG_OSPEEDR           (PIN_OSPEED_VERYLOW(GPIOG_PIN0) |       \
                                     PIN_OSPEED_VERYLOW(GPIOG_PIN1) |       \
                                     PIN_OSPEED_VERYLOW(GPIOG_PIN2) |       \
                                     PIN_OSPEED_VERYLOW(GPIOG_PIN3) |       \
                                     PIN_OSPEED_VERYLOW(GPIOG_PIN4) |       \
                                     PIN_OSPEED_VERYLOW(GPIOG_PIN5) |       \
                                     PIN_OSPEED_VERYLOW(GPIOG_PIN6) |       \
                                     PIN_OSPEED_VERYLOW(GPIOG_PIN7) |       \
                                     PIN_OSPEED_VERYLOW(GPIOG_PIN8) |       \
                                     PIN_OSPEED_VERYLOW(GPIOG_PIN9) |       \
                                     PIN_OSPEED_VERYLOW(GPIOG_PIN10) |      \
                                     PIN_OSPEED_VERYLOW(GPIOG_PIN11) |      \
                                     PIN_OSPEED_VERYLOW(GPIOG_PIN12) |      \
                                     PIN_OSPEED_VERYLOW(GPIOG_PIN13) |      \
                                     PIN_OSPEED_VERYLOW(GPIOG_PIN14) |      \
                                     PIN_OSPEED_VERYLOW(GPIOG_PIN15))
#define VAL_GPIOG_PUPDR             (PIN_PUPDR_FLOATING(GPIOG_PIN0) |       \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN1) |       \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN2) |       \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN3) |       \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN4) |       \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN5) |       \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN6) |       \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN7) |       \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN8) |       \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN9) |       \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN10) |      \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN11) |      \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN12) |      \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN13) |      \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN14) |      \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN15))
#define VAL_GPIOG_ODR               (PIN_ODR_LOW(GPIOG_PIN0) |              \
                                     PIN_ODR_LOW(GPIOG_PIN1) |              \
                                     PIN_ODR_LOW(GPIOG_PIN2) |              \
                                     PIN_ODR_LOW(GPIOG_PIN3) |              \
                                     PIN_ODR_LOW(GPIOG_PIN4) |              \
                                     PIN_ODR_LOW(GPIOG_PIN5) |              \
                                     PIN_ODR_LOW(GPIOG_PIN6) |              \
                                     PIN_ODR_LOW(GPIOG_PIN7) |              \
                                     PIN_ODR_LOW(GPIOG_PIN8) |              \
                                     PIN_ODR_LOW(GPIOG_PIN9) |              \
                                     PIN_ODR_LOW(GPIOG_PIN10) |             \
                                     PIN_ODR_LOW(GPIOG_PIN11) |             \
                                     PIN_ODR_LOW(GPIOG_PIN12) |             \
                                     PIN_ODR_LOW(GPIOG_PIN13) |             \
                                     PIN_ODR_LOW(GPIOG_PIN14) |             \
                                     PIN_ODR_LOW(GPIOG_PIN15))
#define VAL_GPIOG_AFRL              (PIN_AFIO_AF(GPIOG_PIN0, 0U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN1, 0U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN2, 0U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN3, 0U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN4, 0U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN5, 0U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN6, 0U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN7, 0U))
#define VAL_GPIOG_AFRH              (PIN_AFIO_AF(GPIOG_PIN8, 0U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN9, 0U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN10, 0U) |         \
                                     PIN_AFIO_AF(GPIOG_PIN11, 0U) |         \
                                     PIN_AFIO_AF(GPIOG_PIN12, 0U) |         \
                                     PIN_AFIO_AF(GPIOG_PIN13, 0U) |         \
                                     PIN_AFIO_AF(GPIOG_PIN14, 0U) |         \
                                     PIN_AFIO_AF(GPIOG_PIN15, 0U))

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* BOARD_H */
