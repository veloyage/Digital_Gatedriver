/*
 * cgg2.h
 *
 *  Created on: 11.09.2023
 *      Author: ziemannt
 */

#ifndef CGG_H_
#define CGG_H_

#include "ch.h"
#include "hal.h"

#include "shell.h"
#include "chprintf.h"

#include "AD8460.h"

#include <stdlib.h>
#include <string.h>
#include <math.h>

// ## Function declarations ##
void DD_init(void);

void cmd_DD_test(BaseSequentialStream *chp, int argc, char *argv[]);
//void cmd_DD_read_SPI(BaseSequentialStream *chp, int argc, char *argv[]);
//void cmd_DD_write_SPI(BaseSequentialStream *chp, int argc, char *argv[]);
//void cmd_DD_set_HV(BaseSequentialStream *chp, int argc, char *argv[]);
//void cmd_DD_test_PWM(BaseSequentialStream *chp, int argc, char *argv[]);

// ## Variable definitions ##
// timing
#define TIMER_CLOCK 200000000              // tells the calculations about the clock of the timer
#define MINIMUM_ARR 8                      // DMA takes 8 cycles, so minimum 8 cycles timer period.
//(this is the effective reload value, the register value is -1)
#define BIT_DEPTH 14
static float osc_pretrigger_time = 10e-6;       // defines the time the oscilloscope is triggered in advance of testing

/**
 * @brief  Mode type for the digital driver.
 */
typedef enum {
  NO_MODE          = 0,
  R                = 1,
  F                = 2,
  RF               = 3,
  FR               = 4,
} DD_mode_t;

//static struct DD_timing
//{
//  uint32_t trigger_on;
//  uint32_t trigger_off;
//
//
//}DD_timing;

// test data structures
typedef struct
{
  float ramp_time;
  float hold_time;
  float first_voltage;
  float second_voltage;
  DD_mode_t mode;
  uint16_t ARR;
  uint8_t bits;
}DD_test_data_t;

// data buffer, maximum size determined by 2 ramps (up and down) with 14 bit resolution, using 16 bit uints
CC_ALIGN_DATA(32) static uint16_t DD_data_buffer[32768];

// AD8460 driver object
AD8460_t AD8460;

#define MAX_SEQUENTIAL_TESTS 10
static mailbox_t DD_test_mailbox;
static DD_test_data_t DD_test_data[MAX_SEQUENTIAL_TESTS];
static DD_test_data_t* DD_test_data_pointers[MAX_SEQUENTIAL_TESTS];
static DD_test_data_t DD_running_test;
static memory_pool_t DD_test_data_pool;

// test thread pointer declaration
thread_reference_t DD_test_thread_p = NULL;

volatile bool DD_test_running_flag;

// ## Extern declarations ##
extern float delta;
extern ShellConfig shell_cfg1;
extern ShellConfig shell_cfg2;
extern BaseSequentialStream * chp_USB;
extern BaseSequentialStream * chp_OPTICAL;
extern BaseSequentialStream * chp_shell;

extern volatile bool clear_to_run_flag;

// external function
extern void stop_test(void);

#endif /* DD_H_ */
