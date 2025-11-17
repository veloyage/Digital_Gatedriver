/*
 * main.h
 *
 *  Created on: 15.12.2023
 *      Author: ziemannt
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "ch.h"
#include "hal.h"

#include "shell.h"
#include "chprintf.h"

#include "usbcfg.h"

#include "AD8460.h"

#include <stdlib.h>
#include <string.h>
#include <math.h>

// ########################
// ##  Global Variables  ##
// ########################

const float delta = 1e-9;

//## New tester: add flag here
volatile bool clear_to_run_flag;
extern volatile bool DD_test_running_flag;

// #########################
// ## Serial Driver Stuff ##
// #########################

BaseSequentialStream * chp_USB = (BaseSequentialStream *) &SDU1;
BaseSequentialStream * chp_OPTICAL = (BaseSequentialStream *) &SD2;
BaseSequentialStream * chp_shell;

const ShellConfig shell_cfg1, shell_cfg2;


/*
 * pulling the DP pin low to generate disconnect
 */
//#define usb_lld_disconnect_bus(usbp) (palSetPadMode(GPIOA, GPIOA_USB_DP, PAL_MODE_OUTPUT_PUSHPULL))
//#define usb_lld_connect_bus(usbp)    (palSetPadMode(GPIOA, GPIOA_USB_DP, PAL_MODE_INPUT))

// ###########################
// ## Function Declarations ##
// ###########################

void stop_test(void);

// #################################
// ##     Extern declarations     ##
// #################################

// test thread pointer
extern thread_reference_t DD_test_thread_p;

extern void cmd_DD_test(BaseSequentialStream *chp, int argc, char *argv[]);
extern void cmd_DD_write_SPI(BaseSequentialStream *chp, int argc, char *argv[]);
extern void cmd_DD_read_SPI(BaseSequentialStream *chp, int argc, char *argv[]);
extern void cmd_DD_set_HV(BaseSequentialStream *chp, int argc, char *argv[]);
//extern void cmd_DD_test_PWM(BaseSequentialStream *chp, int argc, char *argv[]);

extern void DD_init(void);


#endif /* MAIN_H_ */
