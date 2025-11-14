/*
 * AD8460.h
 *
 *  Created on: 15.12.2023
 *      Author: ziemannt
 */

#ifndef AD8460_H_
#define AD8460_H_

#include "ch.h"
#include "hal.h"

#include "shell.h"
#include "chprintf.h"

#include <stdlib.h>
#include <string.h>
#include <math.h>

// ########################
// ##  AD 8460 IO lines  ##
// ########################
/* RESET: digital reset, active low (RESET_8460)
 * SHUTDOWN: amp shutdown in/out, active high (SDN_IO)
 * SHUTDOWN reset: reset the shutdown, active high (SDN_RESET)
 *
 * SPI: SDI/MOSI, SDO/MISO, SCLK/SCK, CS (active low)
 * DB0 to DB13: 14 bit data
 * SYNC: clock signal for data/DAC (SYNC)
 */


// ###########################
// ## defines & definitions ##
// ###########################

// for debug only
extern BaseSequentialStream * chp_shell;

// device constants

#define AD8460_CTRL_REG_00     0x00
#define AD8460_CTRL_REG_01     0x01
#define AD8460_CTRL_REG_02     0x02
#define AD8460_CTRL_REG_03     0x03
#define AD8460_CTRL_REG_04     0x04
// 5-7 reserved
#define AD8460_CTRL_REG_08     0x08
#define AD8460_CTRL_REG_09     0x09
#define AD8460_CTRL_REG_10     0x0A
#define AD8460_CTRL_REG_11     0x0B
#define AD8460_CTRL_REG_12     0x0C
#define AD8460_CTRL_REG_13     0x0D
#define AD8460_CTRL_REG_14     0x0E
#define AD8460_CTRL_REG_25     0x19
#define AD8460_CTRL_REG_26     0x1A

// APG data registers not implemented

#define AD8460_CTRL_REG_00_WAVEGEN_MODE    (1 << 0)     // default 0 -> AWG, 1 -> APG
#define AD8460_CTRL_REG_00_HV_SLEEP        (1 << 4)     // default 1 -> enabled, 0 -> sleeping
#define AD8460_CTRL_REG_00_HV_RESET        (1 << 7)     // default 0 -> shutown possible, 1 -> reset shutdown

#define AD8460_CTRL_REG_01_DAC_FORMAT      (1 << 1)     // default 0 -> binary, 1 -> 2's complement
#define AD8460_CTRL_REG_01_DAC_SLEEP       (1 << 3)     // default 1 -> DAC sleeping, 0 -> DAC enabled
#define AD8460_CTRL_REG_01_INH_DAC_SDN     (1 << 5)     // default 0 -> DAC shuts down with HV, 1 -> DAC stays on

#define AD8460_CTRL_REG_02_APG_DEPTH_MASK  0x0F         // default 0x3
#define AD8460_CTRL_REG_02_SYNC_EDGE       (1 << 4)     // default 0 -> rising edge, 1 -> falling edge
#define AD8460_CTRL_REG_02_APG_MODE_ENABLE (1 << 5)     // default 0 -> off, 1 -> on (if configured)

#define AD8460_CTRL_REG_03_SOFT_RESET      (1 << 0)     // default 0 -> inactive, 1 -> triggers digital reset

#define AD8460_CTRL_REG_04_QUIESCENT_MASK  0xFF         // default 0, bit 7 is sign, 0-6 value

#define AD8460_CTRL_REG_14_SHUTDOWN_FLAG   (1 << 7)     // default 0 -> enabled, 1 -> shut down

// protections and alarms: not implemented

#define AD8460_CTRL_REG_25_DIE_REF_MASK    0x0F         // default 0x4

#define AD8460_CTRL_REG_26_CHIP_ID_MASK    0xFF         // default 0x46

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @name    AD8460 data structures and types
 * @{
 */
/**
 * @brief   Structure representing a AD8460 driver.
 */
typedef struct AD8460_driver AD8460_driver;

/**
 * @brief   Driver state machine possible states.
 */
typedef enum {
  AD8460_ERROR = -1,
  AD8460_UNINIT = 0,               /**< Not initialized.                   */
  AD8460_STOP = 1,                 /**< Stopped.                           */
  AD8460_READY = 2,                /**< Ready.                             */
  AD8460_RUNNING = 3,              /**< Running.                           */
} ad8460_state_t;

/**
 * @brief   configuration structure.
 */
typedef struct
{

  /**
   * @brief SPI driver
   */
  SPIDriver                 *spip;
  /**
   * @brief SPI configuration
   */
  const SPIConfig           *spicfg;

  uint32_t timer_clock;               // tells the calculations about the clock of the timer

  stm32_gpio_t * data_port; // for ODR register, requires all data bits to be arranged from pins 0 to 13
  ioline_t sync;

  ioline_t RESET;
  ioline_t SDN_RESET;
  ioline_t SDN_IO;

  int8_t positive_range;

  int8_t negative_range;

} AD8460_config;

/**
 * @brief   AD8460 class
 */
typedef struct
{
  /* Driver state.*/
  ad8460_state_t           state;
  /* Current configuration data.*/
  const AD8460_config       *config;
  /* Accelerometer communication tx buffer pointer.*/
  uint8_t*                  commtxp;
  /* Accelerometer communication rx buffer pointer.*/
  uint8_t*                  commrxp;

}AD8460_t;


// ###########################
// ## function declarations ##
// ###########################

void AD8460_init(AD8460_t *devp, const AD8460_config *config, uint8_t* txbp, uint8_t* rxbp);
void AD8460_start(AD8460_t *devp);
void AD8460_stop(AD8460_t *devp);

// for debug
void AD8460_SPIWriteRegister(AD8460_t *devp, uint8_t reg, size_t n, uint8_t* b);
void AD8460_SPIReadRegister(AD8460_t *devp, uint8_t reg, size_t n, uint8_t* b);

#endif /* AD8460_H_ */
