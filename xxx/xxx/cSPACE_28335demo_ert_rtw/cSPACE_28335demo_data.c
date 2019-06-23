/*
 * File: cSPACE_28335demo_data.c
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
#include "cSPACE_28335demo_private.h"

/* Block parameters (auto storage) */
Parameters_cSPACE_28335demo cSPACE_28335demo_P = {
  0.0,                                 /* Mask Parameter: Derivative2_ICPrevScaledInput
                                        * Referenced by: '<S11>/UD'
                                        */
  0.0,                                 /* Mask Parameter: Derivative1_ICPrevScaledInput
                                        * Referenced by: '<S10>/UD'
                                        */
  200U,                                /* Mask Parameter: CTC_const
                                        * Referenced by: '<S3>/Constant'
                                        */
  400U,                                /* Mask Parameter: Counter_uplimit
                                        * Referenced by: '<S14>/FixPt Switch'
                                        */
  200000.0,                            /* Expression: 200000
                                        * Referenced by: '<S7>/Constant6'
                                        */
  5.0E-6,                              /* Expression: 0.000005
                                        * Referenced by: '<S7>/Gain2'
                                        */
  200.0,                               /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S11>/TSamp'
                                        */
  32767.0,                             /* Expression: 32767
                                        * Referenced by: '<S12>/InitAng'
                                        */
  0.000628,                            /* Expression: 0.000628
                                        * Referenced by: '<S2>/Gain3'
                                        */
  200.0,                               /* Computed Parameter: TSamp_WtEt_a
                                        * Referenced by: '<S10>/TSamp'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S1>/Constant1'
                                        */
  1000.0,                              /* Expression: 1000
                                        * Referenced by: '<S1>/Gain1'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<S1>/Gain7'
                                        */
  0.036,                               /* Expression: 0.036
                                        * Referenced by: '<S2>/Gain4'
                                        */
  0.005,                               /* Expression: 0.005
                                        * Referenced by: '<S7>/Gain1'
                                        */
  0U,                                  /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S14>/Constant'
                                        */
  0U,                                  /* Computed Parameter: Output_InitialCondition
                                        * Referenced by: '<S4>/Output'
                                        */
  1U,                                  /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S13>/FixPt Constant'
                                        */
  25600,                               /* Computed Parameter: Pos_div1_Gain
                                        * Referenced by: '<S7>/Pos_div1'
                                        */
  26214,                               /* Computed Parameter: Gain2_Gain_c
                                        * Referenced by: '<S1>/Gain2'
                                        */
  26214,                               /* Computed Parameter: Gain3_Gain_g
                                        * Referenced by: '<S1>/Gain3'
                                        */
  26214,                               /* Computed Parameter: Gain4_Gain_o
                                        * Referenced by: '<S1>/Gain4'
                                        */
  170U,                                /* Computed Parameter: Constant5_Value
                                        * Referenced by: '<S16>/Constant5'
                                        */
  187U                                 /* Computed Parameter: Constant1_Value_j
                                        * Referenced by: '<S16>/Constant1'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
