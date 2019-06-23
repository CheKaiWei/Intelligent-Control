/*
 * File: cSPACE_28335demo.h
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

#ifndef RTW_HEADER_cSPACE_28335demo_h_
#define RTW_HEADER_cSPACE_28335demo_h_
#include <string.h>
#include <stddef.h>
#include <math.h>
#ifndef cSPACE_28335demo_COMMON_INCLUDES_
# define cSPACE_28335demo_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "DSP2833x_Device.h"
#include "DSP2833x_Gpio.h"
#include "DSP28xx_SciUtil.h"
#endif                                 /* cSPACE_28335demo_COMMON_INCLUDES_ */

#include "cSPACE_28335demo_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->blkStateChange = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

extern void enable_interrupts(void);
extern void init_SCI(void);
extern void init_SCI_GPIO(void);

/* user code (top of header file) */
/* System '<Root>' */
#define WMDAC16

/* Block signals (auto storage) */
typedef struct {
  real_T Gain2;                        /* '<S7>/Gain2' */
  real_T Diff;                         /* '<S11>/Diff' */
  real_T Gain3;                        /* '<S2>/Gain3' */
  real_T Diff_e;                       /* '<S10>/Diff' */
  real_T DataTypeConversion;           /* '<S1>/Data Type Conversion' */
  real_T DataTypeConversion2;          /* '<S1>/Data Type Conversion2' */
  real_T Gain2_p;                      /* '<S1>/Gain2' */
  real_T Gain3_p;                      /* '<S1>/Gain3' */
  real_T Gain4;                        /* '<S1>/Gain4' */
  real_T CSFunction_NNLQR[7];          /* '<S1>/C-S-Function_NN-LQR' */
  uint16_T eQEP1_o1;                   /* '<S2>/eQEP1' */
  uint16_T eQEP1_o2;                   /* '<S2>/eQEP1' */
  uint16_T TmpSignalConversionAtSCITransmi[10];
  boolean_T Compare;                   /* '<S3>/Compare' */
} BlockIO_cSPACE_28335demo;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S11>/UD' */
  real_T UD_DSTATE_m;                  /* '<S10>/UD' */
  uint16_T Output_DSTATE;              /* '<S4>/Output' */
} D_Work_cSPACE_28335demo;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T WM_DAC16_1;                   /* '<Root>/WM_DAC16_1' */
  real32_T WM_DAC16_2;                 /* '<Root>/WM_DAC16_2' */
  real32_T WM_DAC16_3;                 /* '<Root>/WM_DAC16_3' */
  real32_T WM_DAC16_4;                 /* '<Root>/WM_DAC16_4' */
} ExternalOutputs_cSPACE_28335demo;

/* Parameters (auto storage) */
struct Parameters_cSPACE_28335demo_ {
  real_T Derivative2_ICPrevScaledInput;/* Mask Parameter: Derivative2_ICPrevScaledInput
                                        * Referenced by: '<S11>/UD'
                                        */
  real_T Derivative1_ICPrevScaledInput;/* Mask Parameter: Derivative1_ICPrevScaledInput
                                        * Referenced by: '<S10>/UD'
                                        */
  uint16_T CTC_const;                  /* Mask Parameter: CTC_const
                                        * Referenced by: '<S3>/Constant'
                                        */
  uint16_T Counter_uplimit;            /* Mask Parameter: Counter_uplimit
                                        * Referenced by: '<S14>/FixPt Switch'
                                        */
  real_T Constant6_Value;              /* Expression: 200000
                                        * Referenced by: '<S7>/Constant6'
                                        */
  real_T Gain2_Gain;                   /* Expression: 0.000005
                                        * Referenced by: '<S7>/Gain2'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S11>/TSamp'
                                        */
  real_T InitAng_Value;                /* Expression: 32767
                                        * Referenced by: '<S12>/InitAng'
                                        */
  real_T Gain3_Gain;                   /* Expression: 0.000628
                                        * Referenced by: '<S2>/Gain3'
                                        */
  real_T TSamp_WtEt_a;                 /* Computed Parameter: TSamp_WtEt_a
                                        * Referenced by: '<S10>/TSamp'
                                        */
  real_T Constant1_Value;              /* Expression: 2
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1000
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T Gain7_Gain;                   /* Expression: 100
                                        * Referenced by: '<S1>/Gain7'
                                        */
  real_T Gain4_Gain;                   /* Expression: 0.036
                                        * Referenced by: '<S2>/Gain4'
                                        */
  real_T Gain1_Gain_a;                 /* Expression: 0.005
                                        * Referenced by: '<S7>/Gain1'
                                        */
  uint16_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S14>/Constant'
                                        */
  uint16_T Output_InitialCondition;    /* Computed Parameter: Output_InitialCondition
                                        * Referenced by: '<S4>/Output'
                                        */
  uint16_T FixPtConstant_Value;        /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S13>/FixPt Constant'
                                        */
  int16_T Pos_div1_Gain;               /* Computed Parameter: Pos_div1_Gain
                                        * Referenced by: '<S7>/Pos_div1'
                                        */
  int16_T Gain2_Gain_c;                /* Computed Parameter: Gain2_Gain_c
                                        * Referenced by: '<S1>/Gain2'
                                        */
  int16_T Gain3_Gain_g;                /* Computed Parameter: Gain3_Gain_g
                                        * Referenced by: '<S1>/Gain3'
                                        */
  int16_T Gain4_Gain_o;                /* Computed Parameter: Gain4_Gain_o
                                        * Referenced by: '<S1>/Gain4'
                                        */
  uint16_T Constant5_Value;            /* Computed Parameter: Constant5_Value
                                        * Referenced by: '<S16>/Constant5'
                                        */
  uint16_T Constant1_Value_j;          /* Computed Parameter: Constant1_Value_j
                                        * Referenced by: '<S16>/Constant1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_cSPACE_28335demo {
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[1];
    SimStruct childSFunctions[1];
    SimStruct *childSFunctionPtrs[1];
    struct _ssBlkInfo2 blkInfo2[1];
    struct _ssSFcnModelMethods2 methods2[1];
    struct _ssSFcnModelMethods3 methods3[1];
    struct _ssSFcnModelMethods4 methods4[1];
    struct _ssStatesInfo2 statesInfo2[1];
    ssPeriodicStatesInfo periodicStatesInfo[1];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[9];
      struct _ssPortOutputs outputPortInfo[1];
    } Sfcn0;
  } NonInlinedSFcns;

  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T blkStateChange;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[1];
    time_T offsetTimesArray[1];
    int_T sampleTimeTaskIDArray[1];
    int_T sampleHitArray[1];
    int_T perTaskSampleHitsArray[1];
    time_T tArray[1];
  } Timing;
};

/* Block parameters (auto storage) */
extern Parameters_cSPACE_28335demo cSPACE_28335demo_P;

/* Block signals (auto storage) */
extern BlockIO_cSPACE_28335demo cSPACE_28335demo_B;

/* Block states (auto storage) */
extern D_Work_cSPACE_28335demo cSPACE_28335demo_DWork;

/* External outputs (root outports fed by signals with auto storage) */
extern ExternalOutputs_cSPACE_28335demo cSPACE_28335demo_Y;

/* Model entry point functions */
extern void cSPACE_28335demo_initialize(void);
extern void cSPACE_28335demo_step(void);
extern void cSPACE_28335demo_terminate(void);

/* Real-time Model object */
extern RT_MODEL_cSPACE_28335demo *const cSPACE_28335demo_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'cSPACE_28335demo'
 * '<S1>'   : 'cSPACE_28335demo/ Controller'
 * '<S2>'   : 'cSPACE_28335demo/AngleQEP'
 * '<S3>'   : 'cSPACE_28335demo/CTC'
 * '<S4>'   : 'cSPACE_28335demo/Counter'
 * '<S5>'   : 'cSPACE_28335demo/Get_GUIdata'
 * '<S6>'   : 'cSPACE_28335demo/Get_MotorQEP2D'
 * '<S7>'   : 'cSPACE_28335demo/MotorQEP'
 * '<S8>'   : 'cSPACE_28335demo/Send_GUIdata'
 * '<S9>'   : 'cSPACE_28335demo/WM_DA0-3'
 * '<S10>'  : 'cSPACE_28335demo/ Controller/Derivative1'
 * '<S11>'  : 'cSPACE_28335demo/ Controller/Derivative2'
 * '<S12>'  : 'cSPACE_28335demo/AngleQEP/QEP_A'
 * '<S13>'  : 'cSPACE_28335demo/Counter/Increment Real World'
 * '<S14>'  : 'cSPACE_28335demo/Counter/Wrap To Zero'
 * '<S15>'  : 'cSPACE_28335demo/MotorQEP/WM-Write7'
 * '<S16>'  : 'cSPACE_28335demo/Send_GUIdata/GUI_SCIA'
 */

/* user code (bottom of header file) */
/* System '<Root>' */
extern float WM_Inter_DAC16_1;
extern float WM_Inter_DAC16_2;
extern float WM_Inter_DAC16_3;
extern float WM_Inter_DAC16_4;

#endif                                 /* RTW_HEADER_cSPACE_28335demo_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
