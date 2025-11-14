/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

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

#include "main.h"

// ########################
// ##       Shell        ##
// ########################

#define SHELL_WA_SIZE   THD_WORKING_AREA_SIZE(2048)

static void cmd_status(BaseSequentialStream *chp, int argc, char *argv[])
{
  (void)argv;
  if (argc > 0)
  {
    chprintf(chp, "Usage: status\r\n");
    return;
  }

}

// simple self test, turn on all LEDs and outputs
void cmd_selftest(BaseSequentialStream *chp, int argc, char *argv[])
{
  (void)argc;
  (void)argv;
  chprintf(chp, "Self test initiated:\r\n");

  palSetLine(LINE_LED_GREEN);
  palSetLine(LINE_LED_RED);
  palSetLine(LINE_LED_YELLOW);
  palSetLine(LINE_LED_BLUE);

  GPIOB->ODR = 16383;

  chThdSleepMilliseconds(1000);

  GPIOB->ODR = 12288;

  chThdSleepMilliseconds(1000);

  GPIOB->ODR = 8192;

  chThdSleepMilliseconds(1000);

  GPIOB->ODR = 4096;

  chThdSleepMilliseconds(1000);

  GPIOB->ODR = 0;

  palClearLine(LINE_LED_GREEN);
  palClearLine(LINE_LED_RED);
  palClearLine(LINE_LED_YELLOW);
  palClearLine(LINE_LED_BLUE);

}


// function to stop all tests
static void cmd_stop(BaseSequentialStream *chp, int argc, char *argv[])
{
  (void)argc;
  (void)argv;
  stop_test();
  //clear_to_run_flag = FALSE;
  chprintf(chp, "Aborting test due to user input.\r\n");
}

// function to reset the controller
static void cmd_reset(BaseSequentialStream *chp, int argc, char *argv[])
{
  (void)argc;
  (void)argv;
  chprintf(chp, "System will now reset.\r\n");
  chThdSleep(TIME_MS2I(10));        // wait for the message to be sent
  NVIC_SystemReset();           // reset MCU
}

// list of all console commands
static const ShellCommand commands[] =
{
 {"DD_test", cmd_DD_test},
 {"abort", cmd_stop},
 {"stop", cmd_stop},
 {"cancel", cmd_stop},
 {"status", cmd_status},
 {"selftest", cmd_selftest},
 {"reset", cmd_reset},
 {NULL, NULL}
};

const ShellConfig shell_cfg1 =
{
 (BaseSequentialStream *)&SDU1,
 commands
};

const ShellConfig shell_cfg2 =
{
 (BaseSequentialStream *)&SD2,
 commands
};

/*
 * Blinker thread.
 */
static THD_WORKING_AREA(waThread_LED, 128);
static THD_FUNCTION(Thread_LED, arg)
{

  (void)arg;

  chRegSetThreadName("LED");
  while (true)
  {
    palSetLine(LINE_LED_BLUE);
    chThdSleepMilliseconds(20);
    palClearLine(LINE_LED_BLUE);
    chThdSleepMilliseconds(980);
  }
}

// ########################
// ##     Functions      ##
// ########################

void stop_test()
{
  // reset DMA (flag reset register IFCR)
//  DMA1_Channel1->CCR = 0;
//  DMA1_Channel5->CCR = 0;
//  DMA1_Channel7->CCR = 0;
//
//  TIM2->DIER = 0;   // deactivate interrupts
//  TIM2->CR1 = 0;    // deactivate timer
//
//  TIM8->DIER = 0;   // deactivate interrupts
//  TIM8->CR1 = 0;    // deactivate timer
//
//  palClearPad(GPIOB, GPIOB_LED_RED);                // set LEDs to indicate "not energized"
//  palSetPad(GPIOB, GPIOB_LED_GREEN);

}

/*
 * Application entry point.
 */
int main(void)
{
   /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   * - Kernel initialization, the main() function becomes a thread and the
   *   RTOS is active.
   */
  halInit();
  chSysInit();

  // Activates the SIO driver using the default configuration.
  //sioStart(&SIOD2, NULL);
  sdStart(&SD2, NULL);

  // Initialize a serial-over-USB CDC driver
  sduObjectInit(&SDU1);
  sduStart(&SDU1, &serusbcfg);

  //Activate the USB driver
  usbDisconnectBus(serusbcfg.usbp);
  chThdSleepMilliseconds(500);
  usbStart(serusbcfg.usbp, &usbcfg);
  usbConnectBus(serusbcfg.usbp);

  /*
   * Shell manager initialization.
   */
  shellInit();

  /*
   * Creates the blinker thread.
   */
  chThdCreateStatic(waThread_LED, sizeof(waThread_LED), NORMALPRIO, Thread_LED, NULL);

  chThdSleepMilliseconds(500); // wait for USB

  // Start shell: if USB is connected, use that, otherwise use serial (via optical inputs)
  if (SDU1.config->usbp->state == USB_ACTIVE)
  {
    chprintf(chp_USB, "Ziemann Engineering CGG digital 1.0\r\n");
    // start USB shell thread
    thread_t *USBshelltp = chThdCreateFromHeap(NULL, SHELL_WA_SIZE, "shell_USB", NORMALPRIO + 1, shellThread, (void *)&shell_cfg1);
    USBshelltp->name = "shell_USB";
    chp_shell = chp_USB;

    // disable optical TX pin (otherwise the TX LED stays on)
    palSetLineMode(LINE_TX, PAL_MODE_INPUT_PULLDOWN);
  }
  else
  {
    chprintf(chp_OPTICAL, "Ziemann Engineering CGG digital 1.0\r\n");
    // start serial IO shell thread
    thread_t *SIOshelltp = chThdCreateFromHeap(NULL, SHELL_WA_SIZE, "shell_SIO", NORMALPRIO + 1, shellThread, (void *)&shell_cfg2);
    SIOshelltp->name = "shell_SIO"; // name is set to default during creation, set again
    chp_shell = chp_OPTICAL;
  }

  // creates thread, initializes AD8460
  DD_init();

  /*
   * Normal main() thread activity, does nothing
   */
  while (true)
  {
    chThdSleepMilliseconds(10000);
  }
}

