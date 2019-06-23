/*
 * File: ert_main.c
 *
 * Code generated for Simulink model 'cSPACE_28335demo'.
 *
 * Model version                  : 1.373
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Sat Feb 16 06:26:32 2013
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "cSPACE_28335demo.h"
#include "rtwtypes.h"

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

  enableTimer0Interrupt();
  cSPACE_28335demo_step();

  /* Get model outputs here */
  disableTimer0Interrupt();
  OverrunFlag--;
}

int main(void)
{
  volatile boolean_T runModel = 1;
  float modelBaseRate = 0.005;
  float systemClock = 150;
  c2000_flash_init();
  init_board();

#ifdef MW_EXEC_PROFILER_ON

  config_profilerTimer();

#endif

  ;
  rtmSetErrorStatus(cSPACE_28335demo_M, 0);
  cSPACE_28335demo_initialize();
  configureTimer0(modelBaseRate, systemClock);
  runModel =
    (rtmGetErrorStatus(cSPACE_28335demo_M) == (NULL)) && !rtmGetStopRequested
    (cSPACE_28335demo_M);
  enableTimer0Interrupt();
  globalInterruptEnable();
  while (runModel) {
    runModel =
      (rtmGetErrorStatus(cSPACE_28335demo_M) == (NULL)) && !rtmGetStopRequested
      (cSPACE_28335demo_M);
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  cSPACE_28335demo_terminate();
  globalInterruptDisable();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
