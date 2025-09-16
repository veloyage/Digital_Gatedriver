/*
 * cgd.c
 *
 * This file contains code specific to the C_GD and C_GG test setups
 * Including the test thread, auxiliary functions and shell commands.
 *
 *  Created on: 11.09.2023
 *      Author: ziemannt
 */

#include "digital_driver.h"


// ########################
// ##     Functions      ##
// ########################

// calculate timer parameters
void calculate_parameters(double* t_ramp, uint8_t* bits, uint16_t* ARR, double* f_timer)
{
  double fbits;
  *ARR = MINIMUM_ARR;                       // ARR minimum value
  *f_timer = TIMER_CLOCK / *ARR;            // calc maximum SYNC frequency from timer 8
  fbits = log2(*t_ramp * *f_timer);         // calc float number of bits possible for this ramp with maximum timer frequency
  *bits = round(fbits);                     // get next round number
  if (*bits > BIT_DEPTH)                    // limit to available bit depth
    *bits = BIT_DEPTH;
  else if (*bits < 1)                       // 1 bit -> max speed turn on/off
    *bits = 1;
  fbits = fbits - *bits;                    // use "bit error" to see how far off we are
  if (fbits < 0)                            // can't go negative bits / can't increase timer frequency
    fbits = 0;
  *ARR = round(MINIMUM_ARR * exp2(fbits));  // if necessary, increase ARR to slow down the timer
  *f_timer = TIMER_CLOCK / *ARR;            // calc actual SYNC frequency
  *t_ramp = exp2(*bits) / *f_timer;         // calculate actual ramp time

}

static void delay_cycles(uint32_t cycles)
{
  while (cycles > 0)
  {
    __NOP();
    cycles --;
  }
}

// start timer
void DD_timer_DMA_start(uint16_t ARR, uint16_t transfers)
{
  // configure clock line
  palSetLineMode(AD8460.config->sync, PAL_MODE_ALTERNATE(4));

  // use DMA triggered by SYNC timer to copy 16 bit values from buffer to ODR register
  // data is latched by AD8460 on rising edge, updates need to happen on falling edge -> with PWM1 mode (falling edge on CC match), use CC event to trigger DMA

  // set up DMA2_CH1 (not used by anything else)
  RCC->AHB1ENR |= RCC_AHB1ENR_DMA2EN;                          // enable DMA
  DMA2_Channel1->CNDTR = transfers;                            // number of transfers
  DMA2_Channel1->CPAR = (uint32_t)&(GPIOB->ODR);               // write to register TODO: get from object
  DMA2_Channel1->CMAR = (uint32_t)&DD_data_buffer[1];          // read from address, second element because the first is preloaded
  // set both mem and peripheral size to 16 bit, increment mem address, direction to peripheral, set very high priority // enable transfer complete interrupt
  DMA2_Channel1->CCR |= (DMA_CCR_MSIZE_0 | DMA_CCR_PSIZE_0 | DMA_CCR_MINC | DMA_CCR_DIR | DMA_CCR_PL_0 | DMA_CCR_PL_1); // | DMA_CCR_TCIE);

  // enable DMAMUX
  RCC->AHB1ENR |= RCC_AHB1ENR_DMAMUX1EN;
  // set up DMAMUX, DMA2_CH1 is linked to DMAMUX1_CH8, TIM8_CH1 is on MUX 49
  DMAMUX1_Channel8->CCR |= (STM32_DMAMUX1_TIM8_CH1); //  && DMAMUX_CxCR_DMAREQ_ID_Msk);

  // enable DMA channel
  DMA2_Channel1->CCR |= DMA_CCR_EN;


  // interrupt config
  //nvicEnableVector(STM32_DMA1_CH1_NUMBER, 4);


  // timer 8 generates the SYNC clock signal
  RCC->APB2ENR |= RCC_APB2ENR_TIM8EN;                                           // enable clock to the timer system
  TIM8->ARR = ARR-1;                                                            // configure overflow to set frequency (frequency = 160MHz/(ARR+1))
  TIM8->CCR1 = ARR/2;                                                           // configure compare to set pulse width 50%
  TIM8->DIER |= (TIM_DIER_CC1DE);                                               // enable CC match DMA request
  TIM8->CCER |= (TIM_CCER_CC1E);                                                // enable compare channels
  TIM8->CCMR1 |= STM32_TIM_CCMR1_OC1M(6);                                       // switch to PWM1 (positive) mode
  TIM8->BDTR |= TIM_BDTR_MOE;                                                   // set main output enable bit
  TIM8->CR1 |= TIM_CR1_CEN;                                                     // enable timer
}

// stop timer
void DD_timer_DMA_stop(void)
{
  TIM8->CR1 = 0;            // deactivate timer
  DMA2_Channel1->CCR = 0;   // reset DMA

  // configure clock line
  palSetLineMode(AD8460.config->sync, PAL_MODE_OUTPUT_PUSHPULL);
}

// ########################
// ##     Commands       ##
// ########################

void cmd_DD_test(BaseSequentialStream *chp, int argc, char *argv[])
{
  char input_buffer[10];
  msg_t MB_status;
  DD_test_data_t* new_test_data_p;

  double f_timer;
  uint16_t ARR;
  uint8_t bits;

  double first_voltage = 0, second_voltage = 0, ramp_time = -2, hold_time = -1;
  DD_mode_t mode = NO_MODE;

  if(!(argc == 2 || argc == 3))
  {
    chprintf(chp, "Usage:DD_test M Xs Zs\r\n");
    chprintf(chp, "Where M is the mode, R (rising), F (falling), RF (rise, then fall) or FR (fall, then rise).\r\n");
    chprintf(chp, "X is the desired duration of each ramp.\r\n");
    chprintf(chp, "Z is the optional hold time.\r\n");
    chprintf(chp, "You may enter times and voltages as floats, times also in us.\r\n");
    return;
  }

  // process first argument
  if (!strcasecmp(argv[0], "RISING") || !strcasecmp(argv[0], "R"))
    mode = R;
  else if (!strcasecmp(argv[0], "FALLING") || !strcasecmp(argv[0], "F"))
    mode = F;
  else if (!strcasecmp(argv[0], "BOTH") || !strcasecmp(argv[0], "RF"))
    mode = RF;
  else if (!strcasecmp(argv[0], "FR"))
    mode = FR;
  else
  {
    chprintf(chp, "Error: Mode is not valid.\r\n");
    return;
  }

  // process second argument
  if(argv[1][strlen(argv[1])-1] == 's')
  {
    ramp_time = strtof(argv[1], NULL);
    if (argv[1][strlen(argv[1])-2] == 'u')
      ramp_time = ramp_time * 1e-6;
  }
  else
  {
    chprintf(chp, "Error: Ramp duration is not valid.\r\n");
    return;
  }

  // check if parameters are valid (larger than zero)
  if (ramp_time <= 0)
  {
    chprintf(chp, "Error: Ramp time has to be larger than zero.\r\n");
    return;
  }


  if (argc == 3) // hold time has been set
  {
    // process third argument
      if(argv[2][strlen(argv[2])-1] == 's')
      {
        hold_time = strtof(argv[2], NULL);
        if (argv[2][strlen(argv[2])-2] == 'u')
          hold_time = hold_time * 1e-6;
      }
      else
      {
        chprintf(chp, "Error: Hold time is not valid.\r\n");
        return;
      }

      if (hold_time < 4.9e-6 || hold_time > 4000)
      {
        chprintf(chp, "Error: Hold time has to be between 5us and 4000s.\r\n");
        return;
      }
  }

// voltages for reduced voltage range, not fully implemented
//  if (argc == 4) //
//  {
//    // process third argument
//    if (argv[2][strlen(argv[2])-1] == 'V')
//      first_voltage = strtof(argv[2], NULL);
//    else
//    {
//      chprintf(chp, "Error: First voltage is not valid.\r\n");
//      return;
//    }
//
//    // process fourth argument
//    if (argv[3][strlen(argv[3])-1] == 'V')
//      second_voltage = strtof(argv[3], NULL);
//    else
//    {
//      chprintf(chp, "Error: Second voltage is not valid.\r\n");
//      return;
//    }
//  }




//  // check if voltage is possible
//  if (first_voltage > 30 || second_voltage > 30 || first_voltage < -30 || second_voltage < -30)
//  {
//    chprintf(chp, "Error: Voltages need to be between +30 V and -30 V.\r\n");
//    return;
//  }

  clear_to_run_flag = TRUE;

  calculate_parameters(&ramp_time, &bits, &ARR, &f_timer);


  // until now everything is okay, so we ask the user to start
  if (mode == R)
    chprintf(chp, "A %.3f us rising ramp has been configured, %d bit @ %.3f MHz.\r\n", ramp_time*1e6, bits, f_timer/1e6);
  else if (mode == F)
    chprintf(chp, "A %.3f us falling ramp has been configured, %d bit @ %.3f MHz.\r\n", ramp_time*1e6, bits, f_timer/1e6);
    //chprintf(chp, "A single ramp from %.3f V to %.3f V in %.3f us has been configured, %d bit @ %.3f MHz.\r\n", first_voltage, second_voltage, time*1e6, bits, f_timer/1e6);
  else if (mode == RF)
    chprintf(chp, "%.3f us rising and then falling ramps have been configured, %d bit @ %.3f MHz.\r\n", ramp_time*1e6, bits, f_timer/1e6);
    //chprintf(chp, "A double ramp from %.3f V to %.3f V in %.3f us and back has been configured, %d bit @ %.3f MHz.\r\n", first_voltage, second_voltage, time*1e6, bits, f_timer/1e6);
  else if (mode == FR)
    chprintf(chp, "%.3f us falling and then rising ramps have been configured, %d bit @ %.3f MHz.\r\n", ramp_time*1e6, bits, f_timer/1e6);
  else
  {
    chprintf(chp, "Error: Mode is not valid.\r\n");
    return;
  }
  if (hold_time > -0.1)
    chprintf(chp, "Hold time between ramps is %.3f us.\r\n", hold_time*1e6);
  chprintf(chp, "To start the measurement enter 'start'. To abort, enter anything else; to stop the process after starting, enter 'stop'.\r\n");

  ShellConfig current_shell_cfg = {chp, NULL};
  shellGetLine(&current_shell_cfg, input_buffer, 10, NULL);

  if(strcasecmp(input_buffer, "start"))
  {
    chprintf(chp, "Invalid input, aborting.\r\n");
    return;
  }

  new_test_data_p = chPoolAlloc(&DD_test_data_pool);

  if (new_test_data_p == NULL)
  {
    chprintf(chp, "Error: Maximum number of sequential tests exceeded.\r\n");
    chprintf(chp, "New test was not created.\r\n");
    return;
  }

  // user has started, we now copy the set and computed data
  new_test_data_p->first_voltage = first_voltage;
  new_test_data_p->second_voltage = second_voltage;
  new_test_data_p->ramp_time = ramp_time;
  new_test_data_p->hold_time = hold_time;
  new_test_data_p->mode = mode;
  new_test_data_p->bits = bits;
  new_test_data_p->ARR = ARR;

  MB_status = chMBPostTimeout(&DD_test_mailbox, (msg_t)new_test_data_p, TIME_IMMEDIATE);      // put address of new test data into the mailbox

  if (MB_status != MSG_OK)
  {
    chprintf(chp, "Error: Maximum number of sequential tests exceeded.\r\n");
    chprintf(chp, "New test was not created.\r\n");
  }

  chThdSleep(TIME_S2I(1));    // send command and shell thread to sleep for a second or two, looks nicer in the console																												   
}

//void cmd_DD_test_PWM(BaseSequentialStream *chp, int argc, char *argv[])
//{
//  if (!strcasecmp(argv[0], "on"))
//  {
//    DD_timer_DMA_start();
//    chprintf(chp, "Timer on.\r\n");
//  }
//  else
//    DD_timer_DMA_stop();
//}

//void cmd_DD_write_SPI(BaseSequentialStream *chp, int argc, char *argv[])
//{
//  uint8_t reg_val[1];
//  reg_val[0] = atoi(argv[1]); // AD8460_CTRL_REG_01_DAC_SLEEP
//  AD8460_SPIWriteRegister(&AD8460, atoi(argv[0]), 1, reg_val);
//  chprintf(chp, "Wrote %i to register %i.\r\n", atoi(argv[1]), atoi(argv[0]));
//}
//
//void cmd_DD_read_SPI(BaseSequentialStream *chp, int argc, char *argv[])
//{
//  uint8_t reg_val[1];
//  reg_val[0] = 0;
//  AD8460_SPIReadRegister(&AD8460, atoi(argv[0]), 1, reg_val);
//  chprintf(chp, "Read %i from register %i.\r\n", reg_val[0], atoi(argv[0]));
//}
//
//void cmd_DD_set_HV(BaseSequentialStream *chp, int argc, char *argv[])
//{
//  if(!strcasecmp(argv[0], "on"))
//  {
//    // enable HV driver by pulling SDN_IO low. holding it low disables all protections.
//    palSetLineMode(AD8460.config->SDN_IO, PAL_MODE_OUTPUT_PUSHPULL);
//    palClearLine(AD8460.config->SDN_IO);
//  }
//  else if(!strcasecmp(argv[0], "highZ"))
//    palSetLineMode(AD8460.config->SDN_IO, PAL_MODE_INPUT_ANALOG);
//  else
//    // disable HV driver
//    palSetLineMode(AD8460.config->SDN_IO, PAL_MODE_OUTPUT_PUSHPULL);
//  palSetLine(AD8460.config->SDN_IO);
//}



// ########################
// ##    Test Thread     ##
// ########################

static THD_WORKING_AREA(waThread_DD, 1024);
static THD_FUNCTION(Thread_DD, arg)
            {
  //uint8_t read_chars;
  //systime_t max_runtime;
  //char IO_buffer[20];
  msg_t struct_pointer;
  uint16_t remaining_tests;
  uint16_t transfers;
  int16_t increment;
  //uint8_t full_range;
  //double reduced_range;


  (void)arg;

  chRegSetThreadName("DD_test");

  while (TRUE)
  {
    DD_test_running_flag = 0;
    chMBFetchTimeout(&DD_test_mailbox, &struct_pointer, TIME_INFINITE);        // try to get a message containing a new test config, waits until one is available
    DD_test_running_flag = 1;

    DD_running_test = *(DD_test_data_t*)struct_pointer;

    chPoolFree(&DD_test_data_pool, (void*)struct_pointer);

    palSetLine(LINE_LED_RED);
    palClearLine(LINE_LED_GREEN);


    // fill data buffer
    transfers = exp2(DD_running_test.bits);

    // default: rising, increment is positive, start at 0
    increment = exp2(BIT_DEPTH - DD_running_test.bits);
    DD_data_buffer[0] = 0;

    // if falling (first), increment is negative, start at positive maximum
    if (DD_running_test.mode == F || DD_running_test.mode == FR)
    {
      increment = - increment;
      DD_data_buffer[0] = exp2(BIT_DEPTH) - 1;
    }

    int i;
    // first flank
    for (i = 1; i <= transfers; i++)
      DD_data_buffer[i] = DD_data_buffer[i-1] + increment;


    // ensure the last value is in range
    if (DD_data_buffer[i - 1] == (exp2(16) - 1))
      DD_data_buffer[i - 1] = 0;
    else if (DD_data_buffer[i - 1] == exp2(BIT_DEPTH))
      DD_data_buffer[i - 1] = exp2(BIT_DEPTH) - 1;

    // second flank, other direction
    if (DD_running_test.mode == RF || DD_running_test.mode == FR)
    {
      for (i = transfers + 1; i <= transfers * 2; i++)
        DD_data_buffer[i] = DD_data_buffer[i-1] - increment;

      // ensure the last value is in range
      if (DD_data_buffer[i - 1] == (exp2(16) - 1))
        DD_data_buffer[i - 1] = 0;
      else if (DD_data_buffer[i - 1] == exp2(BIT_DEPTH))
        DD_data_buffer[i - 1] = exp2(BIT_DEPTH) - 1;
    }

    // reduced range
    //full_range = AD8460.config->positive_range - AD8460.config->negative_range;
    //full_range_steps = full_range / exp2(DD_running_test.bits);
    //reduced_range = DD_running_test.second_voltage - DD_running_test.first_voltage;
    // ;

    chprintf(chp_shell, "Commencing test sequence.\r\n");


    // set ODR to initial value already, generate sync pulse
    GPIOB->ODR = DD_data_buffer[0];
    __NOP();
    __NOP();
    palSetLine(AD8460.config->sync);
    __NOP();
    __NOP();
    palClearLine(AD8460.config->sync);

    // enable driver / HV output
    AD8460_start(&AD8460);

    // wait for output to stabilize // TODO configurable?
    delay_cycles(500);

    // start DMA and SYNC timer
    DD_timer_DMA_start(DD_running_test.ARR, transfers);        // starting the timer starts the test sequence


    // wait for the DMA have 0 remaining transfers //TODO: do this with the transfer complete interrupt
    while (DMA2_Channel1->CNDTR != 0)
    {
      __NOP();
    }

    // second set of transfers
    if (DD_running_test.mode == RF || DD_running_test.mode == FR)
    {
//      if(DD_running_test.hold_time < 0.01) // hold time is small
//        delay_cycles((DD_running_test.hold_time*STM32_HCLK)/6); // add hold time using by wasting cycles, 6 cycles per loop
//      else
//        chThdSleepMicroseconds((uint32_t)(DD_running_test.hold_time * 1e6)); // add hold time using sleep with systick (10 kHz | 100 us) resolution

      // use a hardware timer to generate us delays
      if(DD_running_test.hold_time > 0) // hold time is set (otherwise -1)
        gptPolledDelay(&GPTD5, round(DD_running_test.hold_time * 1e6) - 3); // -3 to get accurate timings
      // disable DMA channel
      DMA2_Channel1->CCR &= ~DMA_CCR_EN;
      // give the DMA a second set of transfers to do
      DMA2_Channel1->CNDTR = transfers;
      // set to continue
      DMA2_Channel1->CMAR = (uint32_t)&DD_data_buffer[transfers + 1];          // read from address, first element of second flank
      // enable DMA channel
      DMA2_Channel1->CCR |= DMA_CCR_EN;
      // wait for the DMA have 0 remaining transfers //TODO: do this with the transfer complete interrupt
      while (DMA2_Channel1->CNDTR != 0)
      {
      }
    }


    // wait for output to stabilize
    delay_cycles(200);

    // stop timer and DMA
    DD_timer_DMA_stop();

/*     // set ODR to middle of range (0 V), generate sync pulse
    GPIOB->ODR = exp2(BIT_DEPTH-1);
    __NOP();
    __NOP();
    palSetLine(AD8460.config->sync);
    __NOP();
    __NOP();
    palClearLine(AD8460.config->sync); */

    // disable driver / HV output
    AD8460_stop(&AD8460);

    chprintf(chp_shell, "Test sequence completed.\r\n");

    chSysLock();
    remaining_tests = chMBGetUsedCountI(&DD_test_mailbox);
    chSysUnlock();

    if (remaining_tests > 0)                                    // if there are more tests waiting:
    {
      chThdSleep(TIME_S2I(1));                                  // another second settling time before the next test can start
    }
    else                                                        // no waiting, end test state
    {
      chprintf(chp_shell, "Testing finished.\r\n");

      palClearLine(LINE_LED_RED);                        // set LEDs to indicate "not energized"
      palSetLine(LINE_LED_GREEN);
    }
  }
            }

// init function
void DD_init(void)
{
  chPoolObjectInit(&DD_test_data_pool, sizeof(DD_test_data_t), NULL);

  chPoolLoadArray(&DD_test_data_pool, &DD_test_data, MAX_SEQUENTIAL_TESTS);

  chMBObjectInit(&DD_test_mailbox, (msg_t*)&DD_test_data_pointers, MAX_SEQUENTIAL_TESTS);

  //creates test thread
  chThdCreateStatic(waThread_DD, sizeof(waThread_DD), NORMALPRIO+20, Thread_DD, NULL);

  // set up hardware
  CC_ALIGN_DATA(32) static uint8_t txbuf[32];
  CC_ALIGN_DATA(32) static uint8_t rxbuf[32];

  SPIConfig SPIconf = // 1.25 MHz
  {
   .circular         = false,
   .slave            = false,
   .data_cb          = NULL,
   .error_cb         = NULL,
   .ssport           = GPIOD,
   .sspad            = GPIOD_SPI_CS,
   .cr1              = SPI_CR1_BR_2 | SPI_CR1_BR_1 | SPI_CR1_BR_0,
   .cr2              = SPI_CR2_DS_2 | SPI_CR2_DS_1 | SPI_CR2_DS_0
  };

  AD8460_config AD8460_conf =
  {
   &SPID3,
   &SPIconf,
   TIMER_CLOCK,
   GPIOB,
   LINE_SYNC,
   LINE_RESET_8460,
   LINE_SDN_RESET,
   LINE_SDN_IO,
   30,
   -30
  };

  static const GPTConfig gpt5cfg = {
      1000000,
      NULL,
      0,
      0
  };

  // timer for delays, run once to work around inaccurate timing with the first run
  gptStart(&GPTD5, &gpt5cfg);
  gptPolledDelay(&GPTD5, 5);


  // enable driver
  AD8460_init(&AD8460, &AD8460_conf, txbuf, rxbuf);
  if (AD8460.state == AD8460_ERROR)
  {
    chprintf(chp_shell, "Error initializing AD8460.\r\n");
    palSetLine(LINE_LED_YELLOW);
  }
}
