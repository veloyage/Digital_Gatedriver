/*
 * AD8460.c
 *
 * Driver code for the AD8460
 *
 *  Created on: 15.12.2023
 *      Author: ziemannt
 */

#include <AD8460.h>

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


// ########################
// ##     Functions      ##
// ########################

/**
 * @brief   Reads a generic register value using SPI.
 * @pre     The SPI interface must be initialized and the driver started.
 *
 * @param[in] devp      pointer to @p AD8460_driver interface.
 * @param[in] reg       starting register address
 * @param[in] n         number of consecutive registers to read
 * @param[in] b         pointer to an output buffer.
 */
void AD8460_SPIReadRegister(AD8460_t *devp, uint8_t reg, size_t n,
                                   uint8_t* b)
{
  unsigned i;
  devp->commtxp[0] = reg | (1 << 7);
  cacheBufferFlush(&devp->commtxp[0], sizeof devp->commtxp);
  spiSelect(devp->config->spip);
  spiSend(devp->config->spip, 1, devp->commtxp);
  spiReceive(devp->config->spip, n, devp->commrxp);
  spiUnselect(devp->config->spip);
  cacheBufferInvalidate(&devp->commrxp[0], sizeof devp->commrxp);
  for(i = 0; i < n; i++, b++)
  {
    *b = devp->commrxp[i];
  }
}

/**
 * @brief   Writes a value into a generic register using SPI.
 * @pre     The SPI interface must be initialized and the driver started.
 *
 * @param[in] devp      pointer to @p AD8460_driver interface.
 * @param[in] reg       starting register address
 * @param[in] n         number of adjacent registers to write
 * @param[in] b         pointer to a buffer of values.
 */
void AD8460_SPIWriteRegister(AD8460_t *devp, uint8_t reg, size_t n,
                                    uint8_t* b)
{
  unsigned i;
  devp->commtxp[0] = reg;
  for(i = 0; i < n; i++, b++)
  {
    devp->commtxp[i + 1] = *b;
  }
  //cacheBufferFlush(&devp->commtxp[0], sizeof devp->commtxp);
  spiSelect(devp->config->spip);
  spiSend(devp->config->spip, n + 1, devp->commtxp);
  spiUnselect(devp->config->spip);
}

/**
 * @brief   Initializes the AD8460
 *
 * @init
 */
void AD8460_init(AD8460_t *devp, const AD8460_config *config, uint8_t* txbp, uint8_t* rxbp)
{
  uint8_t reg_val;

  devp->config = config;
  devp->commtxp = txbp;
  devp->commrxp = rxbp;

  // enable device
  //palSetLine(devp->config->RESET);

  // start SPI
  spiStart(devp->config->spip, devp->config->spicfg);
  chThdSleepMilliseconds(1);
  // check chip ID to make sure SPI is working and AD8460 is answering
  AD8460_SPIReadRegister(devp, AD8460_CTRL_REG_26, 1, &reg_val);
  if (reg_val == 0x46)
    devp->state = AD8460_STOP;
  else
    devp->state = AD8460_ERROR;
  // configure AD8460 for AWG: nothing to do, default mode
  // if APG had been set: reset CTRL_REG_00 WAVE_GEN_MODE and CTRL_REG_02 APG_MODE_ENABLE
}

/**
 * @brief   Activates AD8460 output
 *
 * @param[in] devp      pointer to the @p AD8460_driver object
 *
 * @api
 */
void AD8460_start(AD8460_t *devp)
{
  uint8_t reg_val[4];

  // enable DAC by clearing DAC sleep bit, we can simply 0 the whole register
  reg_val[0] = 0; // AD8460_CTRL_REG_01_DAC_SLEEP
  AD8460_SPIWriteRegister(devp, AD8460_CTRL_REG_01, 1, reg_val);

  // enable HV driver by pulling SDN_IO low. holding it low disables all protections. 
  palClearLine(devp->config->SDN_IO);
  devp->state = AD8460_READY;
  
  //chThdSleepMilliseconds(1);
  
  //AD8460_SPIReadRegister(devp, AD8460_CTRL_REG_00, 4, reg_val);
  //chprintf(chp_shell, "AD8460 control registers: 1=0x%02x, 2=0x%02x, 3=0x%02x, 4=0x%02x\r\n", reg_val[0], reg_val[1], reg_val[2], reg_val[3]);
  //AD8460_SPIReadRegister(devp, AD8460_CTRL_REG_14, 1, reg_val);
  //chprintf(chp_shell, "AD8460 status register (14): 0x%02x\r\n", reg_val[0]);
}

/**
 * @brief   Deactivates AD8460 output.
 *
 * @param[in] devp       pointer to the @p AD8460_driver object
 *
 * @api
 */
void AD8460_stop(AD8460_t *devp)
{
  uint8_t reg_val[1];

  // disable HV driver
  palSetLine(devp->config->SDN_IO);

  //disable DAC
  reg_val[0] = AD8460_CTRL_REG_01_DAC_SLEEP;
  AD8460_SPIWriteRegister(devp, AD8460_CTRL_REG_01, 1, reg_val);

  devp->state = AD8460_STOP;
}
