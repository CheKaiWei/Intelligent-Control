/*
 * File: cSPACE_28335demo.c
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

/* user code (top of source file) */
/* System '<Root>' */
#include "DSP2833x_Device.h"           //CXL                                                                                                                                                                                                           #include "DSP2833x_Examples.h"
#define CLR                            GpioDataRegs.GPBDAT.bit.GPIO38;//ASYNCHRONOUS CLEAR   CXL
#define LDAC                           GpioDataRegs.GPCDAT.bit.GPIO79//LOAD DAC                     CXL
#define SYNC                           GpioDataRegs.GPCDAT.bit.GPIO76//20100506                   CXL
#define SCLK                           GpioDataRegs.GPCDAT.bit.GPIO77
#define SDIN                           GpioDataRegs.GPCDAT.bit.GPIO78

void delay (int length);
void WriteToAD5754RViaSpi(long int *RegisterData);
void WM_DA_Convert(float WM_DAC0,float WM_DAC1,float WM_DAC2,float WM_DAC3);
void WM_DA_IO_Init(void);
float WM_Inter_DAC16_1;
float WM_Inter_DAC16_2;
float WM_Inter_DAC16_3;
float WM_Inter_DAC16_4;
long int control_word[4]= { 0x10001f, 0x0c0004, 0x19000d, 0x1d0000 };

long int trbuf= 0x10001f;
long int trbuf1= 0x0c0004;
long int trbuf2= 0x19000d;
long int trbuf3= 0x1d0000;
unsigned int WM_Loop_Ini;
unsigned int geng= 0;
int i= 0;

/* System '<Root>' */
/* Enable pull-up for GPIO31 (CANRXA)*/
/* Enable pull-up for GPIO30  (CANTXA)  原来的CANB改成CANA引脚， */
uint32_T eCANReceive_dataL;
uint32_T eCANReceive_dataH;
void init_eCAN_A ( uint16_T bitRatePrescaler, uint16_T timeSeg1, uint16_T
                  timeSeg2, uint16_T sbg, uint16_T sjw, uint16_T sam);
void config_eCAN_A_mbx (uint16_T mbxType, uint16_T mbxNo, uint32_T msgID,
  uint16_T msgType);
void enable_interruptsCANA0_RX();
interrupt void ECAN0INTA_isr(void);

/* System '<Root>' */
void init_SCIA(void);
void init_SCIA_GPIO(void);
void enable_interruptsSCIA_RX();
interrupt void SCIRXINTA_isr(void);
void isr_int9pie1_task_fcnSCIA(void);
int scia_rcv(unsigned int *rcvBuff, int buffLen, int loopMode, int typeLen) ;
unsigned int GUIwrite_int16[16];

/* Block signals (auto storage) */
BlockIO_cSPACE_28335demo cSPACE_28335demo_B;

/* Block states (auto storage) */
D_Work_cSPACE_28335demo cSPACE_28335demo_DWork;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_cSPACE_28335demo cSPACE_28335demo_Y;

/* Real-time model */
RT_MODEL_cSPACE_28335demo cSPACE_28335demo_M_;
RT_MODEL_cSPACE_28335demo *const cSPACE_28335demo_M = &cSPACE_28335demo_M_;

/* Model step function */
void cSPACE_28335demo_step(void)
{
  /* local block i/o variables */
  uint32_T rtb_D18;
  int16_T rtb_GUIwrite_int1610;
  int16_T rtb_GUIwrite_int1611;
  int16_T rtb_GUIwrite_int1612;
  int16_T rtb_GUIwrite_int1613;
  int16_T rtb_GUIwrite_int1614;
  int16_T rtb_GUIwrite_int165;
  int16_T rtb_GUIwrite_int166;
  int16_T rtb_GUIwrite_int168;
  int16_T rtb_GUIwrite_int169;
  int16_T rtb_GUIwrite_int1615;
  int16_T rtb_GUIwrite_int162;
  real_T rtb_Gain1;
  real_T rtb_TSamp;
  real_T rtb_Gain4;
  real_T rtb_TSamp_g;
  real_T rtb_Gain1_h;
  uint16_T rtb_ShiftArithmetic3;
  uint16_T rtb_D19;
  uint16_T rtb_FixPtSwitch;
  uint16_T rtb_DataTypeConversion6;
  uint16_T rtb_DataTypeConversion7;
  uint16_T rtb_DataTypeConversion8;
  uint16_T rtb_DataTypeConversion9;

  /* user code (Output function Body) */

  /* System '<Root>' */
  /* System '<Root>' */

  /* S-Function (memorycopy): '<S6>/MotorQEP' */
  {
    uint32_T *memindsrc = (uint32_T *) (&eCANReceive_dataL);
    uint32_T *meminddst = (uint32_T *) (&rtb_D18);

    /* Custom Code Before Write*/
    *(uint32_T *) (meminddst) = *(uint32_T *) (memindsrc);

    /* Custom Code After Write*/
  }

  /* S-Function (memorycopy): '<S5>/GUIwrite_int16[7]' */
  {
    uint16_T *memindsrc = (uint16_T *) (&GUIwrite_int16[7]);
    int16_T *meminddst = (int16_T *) (&rtb_GUIwrite_int1615);

    /* Custom Code Before Write*/
    *(int16_T *) (meminddst) = *(uint16_T *) (memindsrc);

    /* Custom Code After Write*/
  }

  /* Sum: '<S7>/Sum1' incorporates:
   *  Constant: '<S7>/Constant6'
   *  Gain: '<S7>/Pos_div1'
   *  Sum: '<S7>/Sum3'
   */
  rtb_Gain1 = ((real_T)rtb_D18 - cSPACE_28335demo_P.Constant6_Value) - (real_T)
    ((int32_T)cSPACE_28335demo_P.Pos_div1_Gain * rtb_GUIwrite_int1615) *
    0.0078125;

  /* Gain: '<S7>/Gain2' */
  cSPACE_28335demo_B.Gain2 = cSPACE_28335demo_P.Gain2_Gain * rtb_Gain1;

  /* SampleTimeMath: '<S11>/TSamp'
   *
   * About '<S11>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp = cSPACE_28335demo_B.Gain2 * cSPACE_28335demo_P.TSamp_WtEt;

  /* Sum: '<S11>/Diff' incorporates:
   *  UnitDelay: '<S11>/UD'
   */
  cSPACE_28335demo_B.Diff = rtb_TSamp - cSPACE_28335demo_DWork.UD_DSTATE;

  /* S-Function (c280xqep): '<S2>/eQEP1' */
  {
    cSPACE_28335demo_B.eQEP1_o1 = EQep1Regs.QPOSCNT;/*eQEP Position Counter*/
    cSPACE_28335demo_B.eQEP1_o2 = EQep1Regs.QPOSILAT;/* The position-counter value is latched into this register on an IEL*/
  }

  /* Sum: '<S12>/Sum2' incorporates:
   *  Constant: '<S12>/InitAng'
   */
  rtb_Gain4 = (real_T)cSPACE_28335demo_B.eQEP1_o1 -
    cSPACE_28335demo_P.InitAng_Value;

  /* Gain: '<S2>/Gain3' */
  cSPACE_28335demo_B.Gain3 = cSPACE_28335demo_P.Gain3_Gain * rtb_Gain4;

  /* SampleTimeMath: '<S10>/TSamp'
   *
   * About '<S10>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_g = cSPACE_28335demo_B.Gain3 * cSPACE_28335demo_P.TSamp_WtEt_a;

  /* Sum: '<S10>/Diff' incorporates:
   *  UnitDelay: '<S10>/UD'
   */
  cSPACE_28335demo_B.Diff_e = rtb_TSamp_g - cSPACE_28335demo_DWork.UD_DSTATE_m;

  /* S-Function (memorycopy): '<S5>/GUIwrite_int16[3]' */
  {
    uint16_T *memindsrc = (uint16_T *) (&GUIwrite_int16[3]);
    int16_T *meminddst = (int16_T *) (&rtb_GUIwrite_int1615);

    /* Custom Code Before Write*/
    *(int16_T *) (meminddst) = *(uint16_T *) (memindsrc);

    /* Custom Code After Write*/
  }

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  cSPACE_28335demo_B.DataTypeConversion = rtb_GUIwrite_int1615;

  /* S-Function (memorycopy): '<S5>/GUIwrite_int16[15]' */
  {
    uint16_T *memindsrc = (uint16_T *) (&GUIwrite_int16[15]);
    int16_T *meminddst = (int16_T *) (&rtb_GUIwrite_int1615);

    /* Custom Code Before Write*/
    *(int16_T *) (meminddst) = *(uint16_T *) (memindsrc);

    /* Custom Code After Write*/
  }

  /* DataTypeConversion: '<S1>/Data Type Conversion2' */
  cSPACE_28335demo_B.DataTypeConversion2 = rtb_GUIwrite_int1615;

  /* S-Function (memorycopy): '<S5>/GUIwrite_int16[4]' */
  {
    uint16_T *memindsrc = (uint16_T *) (&GUIwrite_int16[4]);
    int16_T *meminddst = (int16_T *) (&rtb_GUIwrite_int162);

    /* Custom Code Before Write*/
    *(int16_T *) (meminddst) = *(uint16_T *) (memindsrc);

    /* Custom Code After Write*/
  }

  /* Gain: '<S1>/Gain2' */
  cSPACE_28335demo_B.Gain2_p = (real_T)cSPACE_28335demo_P.Gain2_Gain_c *
    3.814697265625E-6 * (real_T)rtb_GUIwrite_int162;

  /* S-Function (memorycopy): '<S5>/GUIwrite_int16[1]' */
  {
    uint16_T *memindsrc = (uint16_T *) (&GUIwrite_int16[1]);
    int16_T *meminddst = (int16_T *) (&rtb_GUIwrite_int162);

    /* Custom Code Before Write*/
    *(int16_T *) (meminddst) = *(uint16_T *) (memindsrc);

    /* Custom Code After Write*/
  }

  /* Gain: '<S1>/Gain3' */
  cSPACE_28335demo_B.Gain3_p = (real_T)cSPACE_28335demo_P.Gain3_Gain_g *
    3.814697265625E-6 * (real_T)rtb_GUIwrite_int162;

  /* S-Function (memorycopy): '<S5>/GUIwrite_int16[2]' */
  {
    uint16_T *memindsrc = (uint16_T *) (&GUIwrite_int16[2]);
    int16_T *meminddst = (int16_T *) (&rtb_GUIwrite_int162);

    /* Custom Code Before Write*/
    *(int16_T *) (meminddst) = *(uint16_T *) (memindsrc);

    /* Custom Code After Write*/
  }

  /* Gain: '<S1>/Gain4' */
  cSPACE_28335demo_B.Gain4 = (real_T)cSPACE_28335demo_P.Gain4_Gain_o *
    3.814697265625E-6 * (real_T)rtb_GUIwrite_int162;

  /* S-Function (C_NN_LQR_demo_second): '<S1>/C-S-Function_NN-LQR' */

  /* Level2 S-Function Block: '<S1>/C-S-Function_NN-LQR' (C_NN_LQR_demo_second) */
  {
    SimStruct *rts = cSPACE_28335demo_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  /* Outport: '<Root>/WM_DAC16_1' incorporates:
   *  Product: '<S1>/Product1'
   */
  cSPACE_28335demo_Y.WM_DAC16_1 = cSPACE_28335demo_B.CSFunction_NNLQR[0] *
    (real_T)rtb_GUIwrite_int1615;

  /* MultiPortSwitch: '<S1>/Multiport Switch' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  switch ((int16_T)cSPACE_28335demo_P.Constant1_Value) {
   case 1:
    rtb_Gain1_h = 0.0;
    break;

   case 2:
    rtb_Gain1_h = cSPACE_28335demo_B.Diff;
    break;

   case 3:
    rtb_Gain1_h = cSPACE_28335demo_B.Gain3;
    break;

   case 4:
    rtb_Gain1_h = cSPACE_28335demo_B.Diff_e;
    break;

   case 5:
    rtb_Gain1_h = cSPACE_28335demo_B.CSFunction_NNLQR[1];
    break;

   case 6:
    rtb_Gain1_h = cSPACE_28335demo_B.CSFunction_NNLQR[2];
    break;

   case 7:
    rtb_Gain1_h = cSPACE_28335demo_B.CSFunction_NNLQR[3];
    break;

   case 8:
    rtb_Gain1_h = cSPACE_28335demo_B.CSFunction_NNLQR[4];
    break;

   case 9:
    rtb_Gain1_h = cSPACE_28335demo_B.CSFunction_NNLQR[5];
    break;

   default:
    rtb_Gain1_h = cSPACE_28335demo_B.CSFunction_NNLQR[6];
    break;
  }

  /* End of MultiPortSwitch: '<S1>/Multiport Switch' */

  /* Gain: '<S1>/Gain1' */
  rtb_Gain1_h *= cSPACE_28335demo_P.Gain1_Gain;

  /* Gain: '<S2>/Gain4' */
  rtb_Gain4 *= cSPACE_28335demo_P.Gain4_Gain;

  /* Gain: '<S7>/Gain1' */
  rtb_Gain1 *= cSPACE_28335demo_P.Gain1_Gain_a;

  /* Outport: '<Root>/WM_DAC16_2' */
  cSPACE_28335demo_Y.WM_DAC16_2 = 0.0F;

  /* Outport: '<Root>/WM_DAC16_3' */
  cSPACE_28335demo_Y.WM_DAC16_3 = 0.0F;

  /* Outport: '<Root>/WM_DAC16_4' */
  cSPACE_28335demo_Y.WM_DAC16_4 = 0.0F;

  /* RelationalOperator: '<S3>/Compare' incorporates:
   *  Constant: '<S3>/Constant'
   *  UnitDelay: '<S4>/Output'
   */
  cSPACE_28335demo_B.Compare = (cSPACE_28335demo_DWork.Output_DSTATE <=
    cSPACE_28335demo_P.CTC_const);

  /* S-Function (c280xgpio_do): '<Root>/GPIO14' */
  {
    if (cSPACE_28335demo_B.Compare)
      GpioDataRegs.GPASET.bit.GPIO14 = 1;
    else
      GpioDataRegs.GPACLEAR.bit.GPIO14 = 1;
  }

  /* Sum: '<S13>/FixPt Sum1' incorporates:
   *  Constant: '<S13>/FixPt Constant'
   *  UnitDelay: '<S4>/Output'
   */
  rtb_ShiftArithmetic3 = cSPACE_28335demo_DWork.Output_DSTATE +
    cSPACE_28335demo_P.FixPtConstant_Value;

  /* Switch: '<S14>/FixPt Switch' incorporates:
   *  Constant: '<S14>/Constant'
   */
  if (rtb_ShiftArithmetic3 > cSPACE_28335demo_P.Counter_uplimit) {
    rtb_FixPtSwitch = cSPACE_28335demo_P.Constant_Value;
  } else {
    rtb_FixPtSwitch = rtb_ShiftArithmetic3;
  }

  /* End of Switch: '<S14>/FixPt Switch' */

  /* S-Function (memorycopy): '<S5>/GUIwrite_int16[10]' */
  {
    uint16_T *memindsrc = (uint16_T *) (&GUIwrite_int16[10]);
    int16_T *meminddst = (int16_T *) (&rtb_GUIwrite_int1610);

    /* Custom Code Before Write*/
    *(int16_T *) (meminddst) = *(uint16_T *) (memindsrc);

    /* Custom Code After Write*/
  }

  /* S-Function (memorycopy): '<S5>/GUIwrite_int16[11]' */
  {
    uint16_T *memindsrc = (uint16_T *) (&GUIwrite_int16[11]);
    int16_T *meminddst = (int16_T *) (&rtb_GUIwrite_int1611);

    /* Custom Code Before Write*/
    *(int16_T *) (meminddst) = *(uint16_T *) (memindsrc);

    /* Custom Code After Write*/
  }

  /* S-Function (memorycopy): '<S5>/GUIwrite_int16[12]' */
  {
    uint16_T *memindsrc = (uint16_T *) (&GUIwrite_int16[12]);
    int16_T *meminddst = (int16_T *) (&rtb_GUIwrite_int1612);

    /* Custom Code Before Write*/
    *(int16_T *) (meminddst) = *(uint16_T *) (memindsrc);

    /* Custom Code After Write*/
  }

  /* S-Function (memorycopy): '<S5>/GUIwrite_int16[13]' */
  {
    uint16_T *memindsrc = (uint16_T *) (&GUIwrite_int16[13]);
    int16_T *meminddst = (int16_T *) (&rtb_GUIwrite_int1613);

    /* Custom Code Before Write*/
    *(int16_T *) (meminddst) = *(uint16_T *) (memindsrc);

    /* Custom Code After Write*/
  }

  /* S-Function (memorycopy): '<S5>/GUIwrite_int16[14]' */
  {
    uint16_T *memindsrc = (uint16_T *) (&GUIwrite_int16[14]);
    int16_T *meminddst = (int16_T *) (&rtb_GUIwrite_int1614);

    /* Custom Code Before Write*/
    *(int16_T *) (meminddst) = *(uint16_T *) (memindsrc);

    /* Custom Code After Write*/
  }

  /* S-Function (memorycopy): '<S5>/GUIwrite_int16[5]' */
  {
    uint16_T *memindsrc = (uint16_T *) (&GUIwrite_int16[5]);
    int16_T *meminddst = (int16_T *) (&rtb_GUIwrite_int165);

    /* Custom Code Before Write*/
    *(int16_T *) (meminddst) = *(uint16_T *) (memindsrc);

    /* Custom Code After Write*/
  }

  /* S-Function (memorycopy): '<S5>/GUIwrite_int16[6]' */
  {
    uint16_T *memindsrc = (uint16_T *) (&GUIwrite_int16[6]);
    int16_T *meminddst = (int16_T *) (&rtb_GUIwrite_int166);

    /* Custom Code Before Write*/
    *(int16_T *) (meminddst) = *(uint16_T *) (memindsrc);

    /* Custom Code After Write*/
  }

  /* S-Function (memorycopy): '<S5>/GUIwrite_int16[8]' */
  {
    uint16_T *memindsrc = (uint16_T *) (&GUIwrite_int16[8]);
    int16_T *meminddst = (int16_T *) (&rtb_GUIwrite_int168);

    /* Custom Code Before Write*/
    *(int16_T *) (meminddst) = *(uint16_T *) (memindsrc);

    /* Custom Code After Write*/
  }

  /* S-Function (memorycopy): '<S5>/GUIwrite_int16[9]' */
  {
    uint16_T *memindsrc = (uint16_T *) (&GUIwrite_int16[9]);
    int16_T *meminddst = (int16_T *) (&rtb_GUIwrite_int169);

    /* Custom Code Before Write*/
    *(int16_T *) (meminddst) = *(uint16_T *) (memindsrc);

    /* Custom Code After Write*/
  }

  /* DataTypeConversion: '<S16>/DT14' */
  rtb_Gain1_h = floor(rtb_Gain1_h);
  if (rtIsNaN(rtb_Gain1_h) || rtIsInf(rtb_Gain1_h)) {
    rtb_Gain1_h = 0.0;
  } else {
    rtb_Gain1_h = fmod(rtb_Gain1_h, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S16>/D12' incorporates:
   *  DataTypeConversion: '<S16>/DT14'
   */
  rtb_D18 = (uint32_T)(rtb_Gain1_h < 0.0 ? -(int32_T)(uint32_T)-rtb_Gain1_h :
                       (int32_T)(uint32_T)rtb_Gain1_h);

  /* DataTypeConversion: '<S16>/D13' */
  rtb_ShiftArithmetic3 = (uint16_T)rtb_D18;

  /* DataTypeConversion: '<S16>/DT3' */
  rtb_Gain1_h = floor(rtb_Gain4);
  if (rtIsNaN(rtb_Gain1_h) || rtIsInf(rtb_Gain1_h)) {
    rtb_Gain1_h = 0.0;
  } else {
    rtb_Gain1_h = fmod(rtb_Gain1_h, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S16>/D1' incorporates:
   *  DataTypeConversion: '<S16>/DT3'
   */
  rtb_D18 = (uint32_T)(rtb_Gain1_h < 0.0 ? -(int32_T)(uint32_T)-rtb_Gain1_h :
                       (int32_T)(uint32_T)rtb_Gain1_h);

  /* DataTypeConversion: '<S16>/D2' */
  rtb_D19 = (uint16_T)rtb_D18;

  /* DataTypeConversion: '<S16>/Data Type Conversion6' incorporates:
   *  ArithShift: '<S16>/Shift Arithmetic1'
   */
  rtb_DataTypeConversion6 = rtb_D19 >> 8U;

  /* DataTypeConversion: '<S16>/Data Type Conversion7' */
  rtb_DataTypeConversion7 = rtb_D19 & 255U;

  /* DataTypeConversion: '<S16>/D17' */
  rtb_Gain1_h = floor(rtb_Gain1);
  if (rtIsNaN(rtb_Gain1_h) || rtIsInf(rtb_Gain1_h)) {
    rtb_Gain1_h = 0.0;
  } else {
    rtb_Gain1_h = fmod(rtb_Gain1_h, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S16>/D15' incorporates:
   *  DataTypeConversion: '<S16>/D17'
   */
  rtb_D18 = (uint32_T)(rtb_Gain1_h < 0.0 ? -(int32_T)(uint32_T)-rtb_Gain1_h :
                       (int32_T)(uint32_T)rtb_Gain1_h);

  /* DataTypeConversion: '<S16>/D16' */
  rtb_D19 = (uint16_T)rtb_D18;

  /* DataTypeConversion: '<S16>/Data Type Conversion8' incorporates:
   *  ArithShift: '<S16>/Shift Arithmetic2'
   */
  rtb_DataTypeConversion8 = rtb_D19 >> 8U;

  /* DataTypeConversion: '<S16>/Data Type Conversion9' */
  rtb_DataTypeConversion9 = rtb_D19 & 255U;

  /* DataTypeConversion: '<S16>/D20' incorporates:
   *  Gain: '<S1>/Gain7'
   */
  rtb_Gain1_h = floor(cSPACE_28335demo_P.Gain7_Gain *
                      cSPACE_28335demo_B.CSFunction_NNLQR[0]);
  if (rtIsNaN(rtb_Gain1_h) || rtIsInf(rtb_Gain1_h)) {
    rtb_Gain1_h = 0.0;
  } else {
    rtb_Gain1_h = fmod(rtb_Gain1_h, 4.294967296E+9);
  }

  /* DataTypeConversion: '<S16>/D18' incorporates:
   *  DataTypeConversion: '<S16>/D20'
   */
  rtb_D18 = (uint32_T)(rtb_Gain1_h < 0.0 ? -(int32_T)(uint32_T)-rtb_Gain1_h :
                       (int32_T)(uint32_T)rtb_Gain1_h);

  /* DataTypeConversion: '<S16>/D19' */
  rtb_D19 = (uint16_T)rtb_D18;

  /* SignalConversion: '<S16>/TmpSignal ConversionAtSCI TransmitInport1' incorporates:
   *  ArithShift: '<S16>/Shift Arithmetic'
   *  ArithShift: '<S16>/Shift Arithmetic3'
   *  Constant: '<S16>/Constant1'
   *  Constant: '<S16>/Constant5'
   *  DataTypeConversion: '<S16>/Data Type Conversion11'
   *  DataTypeConversion: '<S16>/Data Type Conversion5'
   */
  cSPACE_28335demo_B.TmpSignalConversionAtSCITransmi[0] =
    cSPACE_28335demo_P.Constant5_Value;
  cSPACE_28335demo_B.TmpSignalConversionAtSCITransmi[1] = rtb_ShiftArithmetic3 >>
    8U;
  cSPACE_28335demo_B.TmpSignalConversionAtSCITransmi[2] = rtb_ShiftArithmetic3 &
    255U;
  cSPACE_28335demo_B.TmpSignalConversionAtSCITransmi[3] =
    rtb_DataTypeConversion6;
  cSPACE_28335demo_B.TmpSignalConversionAtSCITransmi[4] =
    rtb_DataTypeConversion7;
  cSPACE_28335demo_B.TmpSignalConversionAtSCITransmi[5] =
    rtb_DataTypeConversion8;
  cSPACE_28335demo_B.TmpSignalConversionAtSCITransmi[6] =
    rtb_DataTypeConversion9;
  cSPACE_28335demo_B.TmpSignalConversionAtSCITransmi[7] = rtb_D19 >> 8U;
  cSPACE_28335demo_B.TmpSignalConversionAtSCITransmi[8] = rtb_D19 & 255U;
  cSPACE_28335demo_B.TmpSignalConversionAtSCITransmi[9] =
    cSPACE_28335demo_P.Constant1_Value_j;

  /* S-Function (c28xsci_tx): '<S16>/SCI Transmit' */
  {
    scia_xmit((char*)&cSPACE_28335demo_B.TmpSignalConversionAtSCITransmi[0], 10,
              1);
    SciaRegs.SCIFFTX.bit.TXFFINTCLR = 1;
    SciaRegs.SCIFFTX.bit.TXFFIENA = 1;
    SciaRegs.SCIFFTX.bit.TXFFIL = 16;
  }

  /* user code (Output function Trailer) */

  /* System '<Root>' */

  /*WM_DA_Convert(WM_Inter_DAC16_1,WM_Inter_DAC16_2,WM_Inter_DAC16_3,WM_Inter_DAC16_4);*/
  WM_DA_Convert(cSPACE_28335demo_Y.WM_DAC16_1,
                cSPACE_28335demo_Y.WM_DAC16_2,
                cSPACE_28335demo_Y.WM_DAC16_3,
                cSPACE_28335demo_Y.WM_DAC16_4);

  /* Update for UnitDelay: '<S11>/UD' */
  cSPACE_28335demo_DWork.UD_DSTATE = rtb_TSamp;

  /* Update for UnitDelay: '<S10>/UD' */
  cSPACE_28335demo_DWork.UD_DSTATE_m = rtb_TSamp_g;

  /* Update for UnitDelay: '<S4>/Output' */
  cSPACE_28335demo_DWork.Output_DSTATE = rtb_FixPtSwitch;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++cSPACE_28335demo_M->Timing.clockTick0)) {
    ++cSPACE_28335demo_M->Timing.clockTickH0;
  }

  cSPACE_28335demo_M->Timing.t[0] = cSPACE_28335demo_M->Timing.clockTick0 *
    cSPACE_28335demo_M->Timing.stepSize0 +
    cSPACE_28335demo_M->Timing.clockTickH0 *
    cSPACE_28335demo_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void cSPACE_28335demo_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)cSPACE_28335demo_M, 0,
                sizeof(RT_MODEL_cSPACE_28335demo));
  rtsiSetSolverName(&cSPACE_28335demo_M->solverInfo,"FixedStepDiscrete");
  cSPACE_28335demo_M->solverInfoPtr = (&cSPACE_28335demo_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = cSPACE_28335demo_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    cSPACE_28335demo_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    cSPACE_28335demo_M->Timing.sampleTimes =
      (&cSPACE_28335demo_M->Timing.sampleTimesArray[0]);
    cSPACE_28335demo_M->Timing.offsetTimes =
      (&cSPACE_28335demo_M->Timing.offsetTimesArray[0]);

    /* task periods */
    cSPACE_28335demo_M->Timing.sampleTimes[0] = (0.005);

    /* task offsets */
    cSPACE_28335demo_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(cSPACE_28335demo_M, &cSPACE_28335demo_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = cSPACE_28335demo_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    cSPACE_28335demo_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(cSPACE_28335demo_M, -1);
  cSPACE_28335demo_M->Timing.stepSize0 = 0.005;
  cSPACE_28335demo_M->solverInfoPtr = (&cSPACE_28335demo_M->solverInfo);
  cSPACE_28335demo_M->Timing.stepSize = (0.005);
  rtsiSetFixedStepSize(&cSPACE_28335demo_M->solverInfo, 0.005);
  rtsiSetSolverMode(&cSPACE_28335demo_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  (void) memset(((void *) &cSPACE_28335demo_B), 0,
                sizeof(BlockIO_cSPACE_28335demo));

  {
    int16_T i;
    for (i = 0; i < 7; i++) {
      cSPACE_28335demo_B.CSFunction_NNLQR[i] = 0.0;
    }

    cSPACE_28335demo_B.Gain2 = 0.0;
    cSPACE_28335demo_B.Diff = 0.0;
    cSPACE_28335demo_B.Gain3 = 0.0;
    cSPACE_28335demo_B.Diff_e = 0.0;
    cSPACE_28335demo_B.DataTypeConversion = 0.0;
    cSPACE_28335demo_B.DataTypeConversion2 = 0.0;
    cSPACE_28335demo_B.Gain2_p = 0.0;
    cSPACE_28335demo_B.Gain3_p = 0.0;
    cSPACE_28335demo_B.Gain4 = 0.0;
  }

  /* states (dwork) */
  (void) memset((void *)&cSPACE_28335demo_DWork, 0,
                sizeof(D_Work_cSPACE_28335demo));
  cSPACE_28335demo_DWork.UD_DSTATE = 0.0;
  cSPACE_28335demo_DWork.UD_DSTATE_m = 0.0;

  /* external outputs */
  cSPACE_28335demo_Y.WM_DAC16_1 = 0.0;
  cSPACE_28335demo_Y.WM_DAC16_2 = 0.0F;
  cSPACE_28335demo_Y.WM_DAC16_3 = 0.0F;
  cSPACE_28335demo_Y.WM_DAC16_4 = 0.0F;

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &cSPACE_28335demo_M->NonInlinedSFcns.sfcnInfo;
    cSPACE_28335demo_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(cSPACE_28335demo_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &cSPACE_28335demo_M->Sizes.numSampTimes);
    cSPACE_28335demo_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (cSPACE_28335demo_M)[0]);
    rtssSetTPtrPtr(sfcnInfo,cSPACE_28335demo_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(cSPACE_28335demo_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(cSPACE_28335demo_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (cSPACE_28335demo_M));
    rtssSetStepSizePtr(sfcnInfo, &cSPACE_28335demo_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(cSPACE_28335demo_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &cSPACE_28335demo_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &cSPACE_28335demo_M->zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &cSPACE_28335demo_M->blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &cSPACE_28335demo_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &cSPACE_28335demo_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &cSPACE_28335demo_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &cSPACE_28335demo_M->solverInfoPtr);
  }

  cSPACE_28335demo_M->Sizes.numSFcns = (1);

  /* register each child */
  {
    (void) memset((void *)&cSPACE_28335demo_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  1*sizeof(SimStruct));
    cSPACE_28335demo_M->childSfunctions =
      (&cSPACE_28335demo_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    cSPACE_28335demo_M->childSfunctions[0] =
      (&cSPACE_28335demo_M->NonInlinedSFcns.childSFunctions[0]);

    /* Level2 S-Function Block: cSPACE_28335demo/<S1>/C-S-Function_NN-LQR (C_NN_LQR_demo_second) */
    {
      SimStruct *rts = cSPACE_28335demo_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = cSPACE_28335demo_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = cSPACE_28335demo_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = cSPACE_28335demo_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &cSPACE_28335demo_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, cSPACE_28335demo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &cSPACE_28335demo_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &cSPACE_28335demo_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &cSPACE_28335demo_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &cSPACE_28335demo_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &cSPACE_28335demo_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &cSPACE_28335demo_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &cSPACE_28335demo_M->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] = &cSPACE_28335demo_B.Gain2;
          sfcnUPtrs[1] = &cSPACE_28335demo_B.Diff;
          sfcnUPtrs[2] = &cSPACE_28335demo_B.Gain3;
          sfcnUPtrs[3] = &cSPACE_28335demo_B.Diff_e;
          sfcnUPtrs[4] = &cSPACE_28335demo_B.DataTypeConversion;
          sfcnUPtrs[5] = &cSPACE_28335demo_B.DataTypeConversion2;
          sfcnUPtrs[6] = &cSPACE_28335demo_B.Gain2_p;
          sfcnUPtrs[7] = &cSPACE_28335demo_B.Gain3_p;
          sfcnUPtrs[8] = &cSPACE_28335demo_B.Gain4;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 9);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &cSPACE_28335demo_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 7);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            cSPACE_28335demo_B.CSFunction_NNLQR));
        }
      }

      /* path info */
      ssSetModelName(rts, "C-S-Function_NN-LQR");
      ssSetPath(rts, "cSPACE_28335demo/ Controller/C-S-Function_NN-LQR");
      ssSetRTModel(rts,cSPACE_28335demo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* registration */
      C_NN_LQR_demo_second(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.005);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }
  }

  /* Start for S-Function (c280xqep): '<S2>/eQEP1' */
  config_QEP_eQEP1(65535U, 27767U, 0, 0, 0, 0, 4264, 32768, 119, 0);

  /* Start for S-Function (c280xgpio_do): '<Root>/GPIO14' */
  EALLOW;
  GpioCtrlRegs.GPAMUX1.all &= 0xCFFFFFFF;
  GpioCtrlRegs.GPADIR.all |= 0x4000;
  EDIS;

  {
    /* user code (Initialize function Header) */

    /* System '<Root>' */
    extern uint32_T eCANReceive_dataL;
    extern uint32_T eCANReceive_dataH;

    /* System '<Root>' */
    extern unsigned int GUIwrite_int16[16];

    /* user code (Initialize function Body) */

    /* System '<Root>' */
    WM_Inter_DAC16_1= 0.0;
    WM_Inter_DAC16_2= 0.0;
    WM_Inter_DAC16_3= 0.0;
    WM_Inter_DAC16_4= 0.0;
    WM_DA_IO_Init();
    WM_DA_IO_Init();

    /* InitializeConditions for UnitDelay: '<S11>/UD' */
    cSPACE_28335demo_DWork.UD_DSTATE =
      cSPACE_28335demo_P.Derivative2_ICPrevScaledInput;

    /* InitializeConditions for UnitDelay: '<S10>/UD' */
    cSPACE_28335demo_DWork.UD_DSTATE_m =
      cSPACE_28335demo_P.Derivative1_ICPrevScaledInput;

    /* InitializeConditions for UnitDelay: '<S4>/Output' */
    cSPACE_28335demo_DWork.Output_DSTATE =
      cSPACE_28335demo_P.Output_InitialCondition;

    /* user code (Initialize function Trailer) */

    /* System '<Root>' */
    eCANReceive_dataL = (uint32_T)0.0;
    eCANReceive_dataH = (uint32_T)0.0;
    init_eCAN_A (5, 8, 6, 1, 2, 1);
    config_eCAN_A_mbx (0U, 1, 455, 0);
    enable_interruptsCANA0_RX() ;

    /* System '<Root>' */
    GUIwrite_int16[0] = 0;
    GUIwrite_int16[1] = 1;
    GUIwrite_int16[2] = 1000;
    GUIwrite_int16[3] = 0;
    GUIwrite_int16[4] = 0;
    GUIwrite_int16[5] = 0;
    GUIwrite_int16[6] = 0;
    GUIwrite_int16[7] = 0;
    GUIwrite_int16[8] = 0;
    GUIwrite_int16[9] = 0;
    GUIwrite_int16[10] = 0;
    GUIwrite_int16[11] = 0;
    GUIwrite_int16[12] = 0;
    GUIwrite_int16[13] = 0;
    GUIwrite_int16[14] = 0;
    GUIwrite_int16[15] = 0;
    init_SCIA();
    init_SCIA_GPIO();
    enable_interruptsSCIA_RX();
  }

  {
  }
}

/* Model terminate function */
void cSPACE_28335demo_terminate(void)
{
  /* Terminate for S-Function (C_NN_LQR_demo_second): '<S1>/C-S-Function_NN-LQR' */
  /* Level2 S-Function Block: '<S1>/C-S-Function_NN-LQR' (C_NN_LQR_demo_second) */
  {
    SimStruct *rts = cSPACE_28335demo_M->childSfunctions[0];
    sfcnTerminate(rts);
  }
}

/* user code (bottom of source file) */
/* System '<Root>' */
void WM_DA_Convert(float WM_DAC0,float WM_DAC1,float WM_DAC2,float WM_DAC3)
{
  unsigned int WM_Loop= 0;
  int WM_DAC_Data= 0;

  // LDAC=1;
  //GpioDataRegs.GPCSET.bit.GPIO79=1;
  // asm(" RPT #150 || NOP");
  /*WM_DAC0=WM_DAC0-WM_DAC0*0.0005-0.0126;
     WM_DAC1=WM_DAC1-WM_DAC1*0.0005-0.0126;
     WM_DAC2=WM_DAC2-WM_DAC2*0.0005-0.0126;
     WM_DAC3=WM_DAC3-WM_DAC3*0.0005-0.0126; */
  if (WM_DAC0<-10)
    WM_DAC0= -10;
  if (WM_DAC0>10)
    WM_DAC0= 10;
  if (WM_DAC1<-10)
    WM_DAC1= -10;
  if (WM_DAC1>10)
    WM_DAC1= 10;
  if (WM_DAC2<-10)
    WM_DAC2= -10;
  if (WM_DAC2>10)
    WM_DAC2= 10;
  if (WM_DAC3<-10)
    WM_DAC3= -10;
  if (WM_DAC3>10)
    WM_DAC3= 10;
  asm(" RPT #150 || NOP");
  for (WM_Loop=0;WM_Loop<4;WM_Loop++) {
    // SYNC=0;
    GpioDataRegs.GPCCLEAR.bit.GPIO76= 1;
    asm(" RPT #10 || NOP");
    switch (WM_Loop)
    {
     case 0:
      WM_DAC_Data= (int)(WM_DAC0*3276.8);
      geng= WM_DAC_Data;
      trbuf= 0x000000|geng;
      WriteToAD5754RViaSpi(&trbuf);
      break;

     case 1:
      WM_DAC_Data= (int)(WM_DAC1*3276.8);
      geng= WM_DAC_Data;
      trbuf1= 0x010000|geng;
      WriteToAD5754RViaSpi(&trbuf1);
      break;

     case 2:
      WM_DAC_Data= (int)(WM_DAC2*3276.8);
      geng= WM_DAC_Data;
      trbuf2= 0x020000|geng;
      WriteToAD5754RViaSpi(&trbuf2);
      break;

     case 3:
      WM_DAC_Data= (int)(WM_DAC3*3276.8);
      geng= WM_DAC_Data;
      trbuf3= 0x030000|geng;
      WriteToAD5754RViaSpi(&trbuf3);
      break;
    }
  }
}

void WM_DA_IO_Init()                   //20161123
{
  EALLOW;
  GpioCtrlRegs.GPCMUX1.bit.GPIO78= 0;  //SDIN
  GpioCtrlRegs.GPCMUX1.bit.GPIO79= 0;  //LDAC
  GpioCtrlRegs.GPCMUX1.bit.GPIO77= 0;  //SCLK
  GpioCtrlRegs.GPCMUX1.bit.GPIO76= 0;  //SYNC
  GpioCtrlRegs.GPBMUX1.bit.GPIO38= 0;  //CLR
  GpioCtrlRegs.GPCDIR.bit.GPIO78= 1;
  GpioCtrlRegs.GPCDIR.bit.GPIO79= 1;
  GpioCtrlRegs.GPCDIR.bit.GPIO77= 1;
  GpioCtrlRegs.GPCDIR.bit.GPIO76= 1;   //  SYNC
  GpioCtrlRegs.GPBDIR.bit.GPIO38= 1;   //CLR
  EDIS;
  GpioDataRegs.GPBSET.bit.GPIO38= 1;
  GpioDataRegs.GPCSET.bit.GPIO79= 1;
  delay(10);
  for (WM_Loop_Ini=0; WM_Loop_Ini<4; WM_Loop_Ini++) {
    WriteToAD5754RViaSpi(&control_word[WM_Loop_Ini]);
  }

  GpioDataRegs.GPCCLEAR.bit.GPIO79= 1;
}

void delay (int length)
{
  while (length >0)
    length--;
}

void WriteToAD5754RViaSpi(long int *RegisterData)
{
  long int ValueToWrite = *RegisterData;
  int j;

  // SPI start
  GpioDataRegs.GPCSET.bit.GPIO76= 1;
  delay(20);
  GpioDataRegs.GPCCLEAR.bit.GPIO76= 1; //bring CS low
  delay(2);

  //Write out the ControlWord
  for (j=0; j<24; j++) {
    GpioDataRegs.GPCSET.bit.GPIO77= 1;
    asm(" RPT #2 || NOP");
    if (0x800000 == (ValueToWrite & 0x800000)) {
      GpioDataRegs.GPCSET.bit.GPIO78= 1;//Send one to SDI pin
    } else {
      GpioDataRegs.GPCCLEAR.bit.GPIO78= 1;//Send zero to SDI pin
    }

    asm(" RPT #2 || NOP");
    GpioDataRegs.GPCCLEAR.bit.GPIO77= 1;
    asm(" RPT #2 || NOP");
    ValueToWrite <<= 1;                //Rotate data
    asm(" RPT #2 || NOP");
  }

  GpioDataRegs.GPCSET.bit.GPIO76= 1;
  asm(" RPT #10 || NOP");
}

/* System '<Root>' */
void init_eCAN_A ( uint16_T bitRatePrescaler, uint16_T timeSeg1, uint16_T
                  timeSeg2, uint16_T sbg, uint16_T sjw, uint16_T sam)
{
  struct ECAN_REGS ECanaShadow;

  /* Configure CAN pins using GPIO regs */
  EALLOW;
  GpioCtrlRegs.GPAPUD.bit.GPIO30 = 0;  /* Enable pull-up for GPIO30 (CANRXA)*/
  GpioCtrlRegs.GPAMUX2.bit.GPIO30 = 1; /* Configure GPIO30 for CANRXA operation*/
  GpioCtrlRegs.GPAPUD.bit.GPIO31 = 0;  /* Enable pull-up for GPIO31 (CANTXA)*/
  GpioCtrlRegs.GPAMUX2.bit.GPIO31 = 1; /* Configure GPIO31 for CANTXA operation*/
  EDIS;

  /* Configure the RX and TX pins for transmission */
  EALLOW;
  ECanaShadow.CANRIOC.all = ECanaRegs.CANRIOC.all;
  ECanaShadow.CANRIOC.bit.RXFUNC = 1;
  ECanaRegs.CANRIOC.all = ECanaShadow.CANRIOC.all;
  ECanaShadow.CANTIOC.all = ECanaRegs.CANTIOC.all;
  ECanaShadow.CANTIOC.bit.TXFUNC = 1;
  ECanaRegs.CANTIOC.all = ECanaShadow.CANTIOC.all;
  EDIS;

  /* Disable all Mailboxes */
  ECanaRegs.CANME.all = 0;
  EALLOW;
  ECanaRegs.CANMIM.all = 0xFFFFFFFF;
  ECanaShadow.CANMC.all = ECanaRegs.CANMC.all;
  ECanaShadow.CANMC.bit.CCR = 1;
  ECanaRegs.CANMC.all = ECanaShadow.CANMC.all;
  EDIS;
  do {
    ECanaShadow.CANES.all = ECanaRegs.CANES.all;
  } while (ECanaShadow.CANES.bit.CCE != 1 );/* Wait for CCE bit to be set..*/

  /* Configure the eCAN timing parameters */
  EALLOW;
  ECanaShadow.CANBTC.all = ECanaRegs.CANBTC.all;
  ECanaShadow.CANBTC.bit.BRPREG = bitRatePrescaler-1;
  ECanaShadow.CANBTC.bit.TSEG2REG = timeSeg2-1;
  ECanaShadow.CANBTC.bit.TSEG1REG = timeSeg1-1;
  ECanaShadow.CANBTC.bit.SAM = sam-1;
  ECanaShadow.CANBTC.bit.SJWREG = sjw-1;

  /*ECanaShadow.CANBTC.bit.ERM = sbg-1; */
  ECanaRegs.CANBTC.all = ECanaShadow.CANBTC.all;
  ECanaShadow.CANMC.all = ECanaRegs.CANMC.all;
  ECanaShadow.CANMC.bit.CCR = 0 ;      /* Set CCR = 0*/
  ECanaRegs.CANMC.all = ECanaShadow.CANMC.all;
  EDIS;
  do {
    ECanaShadow.CANES.all = ECanaRegs.CANES.all;
  } while (ECanaShadow.CANES.bit.CCE != 0 );/* Wait for CCE bit to be cleared..*/

  EALLOW;
  ECanaShadow.CANMC.all = ECanaRegs.CANMC.all;
  ECanaShadow.CANMC.bit.STM = 0;       /* Configure CAN for normal mode    */
  ECanaShadow.CANMC.bit.SCB = 1;       /* User has selected eCAN mode*/
  ECanaShadow.CANMC.bit.DBO = 1;       /* Set byte order: least significant first*/
  ECanaRegs.CANMC.all = ECanaShadow.CANMC.all;
  EDIS;

  /* Configure CAN interrupts */
  EALLOW;
  ECanaShadow.CANMIM.all = ECanaRegs.CANMIM.all;
  ECanaShadow.CANMIM.all = (uint32_T) 2;
  ECanaRegs.CANMIM = ECanaShadow.CANMIM;
  EDIS;
  EALLOW;
  ECanaShadow.CANMIL.all = ECanaRegs.CANMIL.all;
  ECanaShadow.CANMIL.all = (uint32_T) 0;
  ECanaRegs.CANMIL = ECanaShadow.CANMIL;
  EDIS;
  EALLOW;
  ECanaShadow.CANGIM.all = ECanaRegs.CANGIM.all;
  ECanaShadow.CANGIM.bit.GIL = 0;      /* GIL value determines ECana(0/1)INT*/
  ECanaShadow.CANGIM.bit.I0EN = 1;
  ECanaShadow.CANGIM.bit.I1EN = 0;
  ECanaRegs.CANGIM.all = ECanaShadow.CANGIM.all;
  EDIS;
}

void config_eCAN_A_mbx (uint16_T mbxType, uint16_T mbxNo, uint32_T msgID,
  uint16_T msgType)
{
  uint32_T maskRx = 0x1;
  uint32_T maskTx;
  struct ECAN_REGS ECanaShadow;
  volatile struct MBOX *mbx = &ECanaMboxes.MBOX0 + mbxNo;
  maskRx = maskRx<<mbxNo;
  maskTx = ~maskRx;
  mbx->MSGCTRL.bit.RTR = 0;
  ECanaShadow.CANME.all = ECanaRegs.CANME.all;
  ECanaRegs.CANME.all = 0x00000000;
  if (msgType==1)
    mbx->MSGID.all = msgID;            /* For Extended ID use bits  0:28 */
  else
    mbx->MSGID.bit.STDMSGID = msgID;   /* For Standard ID use bits 18:28 */
  mbx->MSGID.bit.AME = 0;
  mbx->MSGID.bit.AAM = 0;
  mbx->MSGID.bit.IDE = msgType;
  ECanaShadow.CANMD.all = ECanaRegs.CANMD.all;
  if (mbxType==0) {
    ECanaShadow.CANMD.all |= maskRx;
  } else {
    ECanaShadow.CANMD.all &= maskTx;
  }

  ECanaRegs.CANMD.all = ECanaShadow.CANMD.all;
  ECanaShadow.CANME.all |= maskRx;
  ECanaRegs.CANME.all = ECanaShadow.CANME.all;
}

void enable_interruptsCANA0_RX()
{
  EALLOW;
  PieVectTable.ECAN0INTA = &ECAN0INTA_isr;/* Hook interrupt to the ISR*/
  EDIS;
  PieCtrlRegs.PIEIER9.bit.INTx5 = 1;   /* Enable interrupt ECAN0INTA*/
  IER |= M_INT9;

  /* Enable global Interrupts and higher priority real-time debug events:*/
  EINT;                                /* Enable Global interrupt INTM*/
  ERTM;                                /* Enable Global realtime interrupt DBGM*/
}

interrupt void ECAN0INTA_isr(void)
{
  isr_int9pie5_task_fcn();
  switch (ECanaRegs.CANGIF0.bit.MIV0){
   case 1:
    ECanaRegs.CANRMP.bit.RMP1 = 1;
    break;
  }

  PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;/* Acknowledge to receive more interrupts*/
}

void isr_int9pie5_task_fcn(void)
{
  /* Call the system: <Root>/eCANA Receive */
  {
    /* S-Function (c28xisr_c2000): '<Root>/C28x Hardware Interrupt' */

    /* Output and update for function-call system: '<Root>/eCANA Receive' */

    /* S-Function (c280xcanrcv): '<S7>/eCAN Receive' */
    {
      struct ECAN_REGS ECanaShadow;
      if (ECanaRegs.CANRMP.bit.RMP1) {
        /* reenable the mailbox to receive the next message */
        EALLOW;
        ECanaShadow.CANRMP.all = 0x0;
        ECanaShadow.CANRMP.bit.RMP1 = 1;/* request clear RMP for this mailbox only*/
        ECanaRegs.CANRMP.all = ECanaShadow.CANRMP.all;/* 32-bit register access is reliable only                         */
        EDIS;
        eCANReceive_dataL = ECanaMboxes.MBOX1.MDL.all;
        eCANReceive_dataH = ECanaMboxes.MBOX1.MDH.all;

        /* -- Call CAN RX Fcn-Call_0 -- */

        /* Output and update for function-call system: '<S7>/Process CAN Msg' */

        /* Inport: '<S11>/Msg' */
        /* cSPACE_28335demo3_B.Msg[0] = cSPACE_28335demo3_B.eCANReceive_o2[0];
           cSPACE_28335demo3_B.Msg[1] = cSPACE_28335demo3_B.eCANReceive_o2[1];*/
      }
    }

    /* End of Outputs for S-Function (c280xcanrcv): '<S7>/eCAN Receive' */

    /* End of Outputs for S-Function (c28xisr_c2000): '<Root>/C28x Hardware Interrupt' */
  }
}

/* System '<Root>' */
void init_SCIA(void)
{                                      /* initialize SCI & FIFO registers */
  EALLOW;

  /*
   * Initialize SCI_A with following parameters:
   *    BaudRate              : 260417
   *    CharacterLengthBits   : 8
   *    EnableLoopBack        : 0
   *    NumberOfStopBits      : 1
   *    ParityMode            : None
   *    SuspensionMode        : Free_run
   *    CommMode              : Raw_data
   */
  SciaRegs.SCICCR.bit.STOPBITS = 0;    /*Number of stop bits. (0: One stop bit, 1: Two stop bits)*/
  SciaRegs.SCICCR.bit.PARITY = 0;      /*Parity mode (0: Odd parity, 1: Even parity)*/
  SciaRegs.SCICCR.bit.PARITYENA = 0;   /*Enable Pary Mode */
  SciaRegs.SCICCR.bit.LOOPBKENA = 0;   /*Loop Back enable*/
  SciaRegs.SCICCR.bit.ADDRIDLE_MODE = 0;/*ADDR/IDLE Mode control*/
  SciaRegs.SCICCR.bit.SCICHAR = 7;     /*Character length*/
  SciaRegs.SCICTL1.bit.RXERRINTENA = 0;/*Disable receive error interrupt*/
  SciaRegs.SCICTL1.bit.SWRESET = 1;    /*Software reset*/
  SciaRegs.SCICTL1.bit.TXENA = 1;      /* SCI transmitter enable*/
  SciaRegs.SCICTL1.bit.RXENA = 1;      /* SCI receiver enable*/
  SciaRegs.SCIHBAUD = 0U;
  SciaRegs.SCILBAUD = 17U;

  /*Free run, continue SCI operation regardless of suspend*/
  SciaRegs.SCIPRI.bit.FREE = 1;        /* Free emulation mode control*/
  SciaRegs.SCIPRI.bit.SOFT = 0;        /* Interrupt priority select*/
  SciaRegs.SCIFFCT.bit.ABDCLR = 0;
  SciaRegs.SCIFFCT.bit.CDC = 0;
  SciaRegs.SCIFFTX.bit.SCIRST = 1;     /* SCI reset rx/tx channels*/
  SciaRegs.SCIFFTX.bit.SCIFFENA = 1;   /* SCI FIFO enhancements are enabled.*/
  SciaRegs.SCIFFTX.bit.TXFIFOXRESET = 1;/* Re-enable transmit FIFO operation.*/
  SciaRegs.SCIFFRX.bit.RXFIFORESET = 1;/* Re-enable receive FIFO operation.*/
  SciaRegs.SCIFFRX.bit.RXFFIENA = 1;
  SciaRegs.SCIFFRX.bit.RXFFIL = 16;
  EDIS;
}

void init_SCIA_GPIO(void)
{
  EALLOW;
  GpioCtrlRegs.GPAPUD.bit.GPIO28 = 0;  /*Enable pull-up for GPIO28*/
  GpioCtrlRegs.GPAMUX2.bit.GPIO28 = 1; /*Configure GPIO28 as SCIRXDA*/
  GpioCtrlRegs.GPAPUD.bit.GPIO29 = 0;  /*Enable pull-up for GPIO29*/
  GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 1; /*Configure GPIO29 as SCITXDA*/
  EDIS;
}

void enable_interruptsSCIA_RX()
{
  EALLOW;
  PieVectTable.SCIRXINTA = &SCIRXINTA_isr;/* Hook interrupt to the ISR*/
  EDIS;
  PieCtrlRegs.PIEIER9.bit.INTx1 = 1;   /* Enable interrupt SCIRXINTA*/
  IER |= M_INT9;

  /* Enable global Interrupts and higher priority real-time debug events:*/
  EINT;                                /* Enable Global interrupt INTM*/
  ERTM;                                /* Enable Global realtime interrupt DBGM*/
}

interrupt void SCIRXINTA_isr(void)
{
  isr_int9pie1_task_fcnSCIA();
  EALLOW;
  SciaRegs.SCIFFRX.bit.RXFFINTCLR = 1;
  EDIS;
  PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;/* Acknowledge to receive more interrupts*/
}

void isr_int9pie1_task_fcnSCIA(void)
{
  /* Call the system: <Root>/FSub */
  {
    /* S-Function (c28xisr_c2000): '<Root>/Interrupt' */

    /* Output and update for function-call system: '<Root>/FSub' */

    /* S-Function (c28xsci_rx): '<S4>/SCI Receive' */
    unsigned int recbuff[32];

    /*{   */
    int i;
    int errFlg = NOERROR;
    for (i = 0; i < 32; i++)
      recbuff[i] = 0;

    /* Receiving data */
    errFlg = scia_rcv(recbuff, 32, LONGLOOP, 1);
    if (errFlg != NOERROR)
      goto RXERRA;

    /*memcpy( &SCIAReceive[0], recbuff, 32);*/
    /*memcpy( &cSPACE_28335demo_B.SCIReceive[0], recbuff, 32);*/
   RXERRA:
    asm(" NOP");

    /*}*/
    GUIwrite_int16[1]= recbuff[1]*256+recbuff[2];
    GUIwrite_int16[2]= recbuff[3]*256+recbuff[4];
    GUIwrite_int16[3]= recbuff[5]*256+recbuff[6];
    GUIwrite_int16[4]= recbuff[7]*256+recbuff[8];
    GUIwrite_int16[5]= recbuff[9]*256+recbuff[10];
    GUIwrite_int16[6]= recbuff[11]*256+recbuff[12];
    GUIwrite_int16[7]= recbuff[13]*256+recbuff[14];
    GUIwrite_int16[8]= recbuff[15]*256+recbuff[16];
    GUIwrite_int16[9]= recbuff[17]*256+recbuff[18];
    GUIwrite_int16[10]= recbuff[19]*256+recbuff[20];
    GUIwrite_int16[11]= recbuff[21]*256+recbuff[22];
    GUIwrite_int16[12]= recbuff[23]*256+recbuff[24];
    GUIwrite_int16[13]= recbuff[25]*256+recbuff[26];
    GUIwrite_int16[14]= recbuff[27]*256+recbuff[28];
    GUIwrite_int16[15]= recbuff[29]*256+recbuff[30];

    /* End of Outputs for S-Function (c28xisr_c2000): '<Root>/Interrupt' */
  }
}

int scia_rcv(unsigned int *rcvBuff, int buffLen, int loopMode, int typeLen)
{
  int i;
  int errorVal = NOERROR;
  unsigned int byte_cnt = 0;
  unsigned int cnt = 0;
  unsigned int maxcnt;
  if (loopMode == LONGLOOP) {
    maxcnt = RCVMAXCNTL;
  } else {
    maxcnt = RCVMAXCNTS;
  }

  for (i = 0; i<buffLen; i++) {
    cnt = 0;
    while (SciaRegs.SCIFFRX.bit.RXFFST == 0) {/* wait until data received */
      if (i == 0) {
        if (cnt++ > maxcnt)
          return TIMEOUT;
      } else {
        if (cnt++ > RCVMAXCNTL)
          return TIMEOUT;
      }
    }

    if (typeLen > 1) {
      if (byte_cnt == 0) {
        rcvBuff[i/2] = (SciaRegs.SCIRXBUF.all & 0x00FF);
        byte_cnt = 1;
      } else {
        rcvBuff[i/2] |= SciaRegs.SCIRXBUF.all << 8;
        byte_cnt = 0;
      }
    } else {
      rcvBuff[i] = SciaRegs.SCIRXBUF.all;
    }

    if (SciaRegs.SCIFFRX.bit.RXFFOVF == 1)/* detect FIFO overflow*/
    {
      SciaRegs.SCIFFRX.bit.RXFFOVRCLR = 1;

      /*SciaRegs.SCIFFRX.bit.RXFIFORESET = 0;    Reset the FIFO pointer to zero.
       * SciaRegs.SCIFFRX.bit.RXFIFORESET = 1;   Re-enable receive FIFO operation.
       */
    }

    if (SciaRegs.SCIRXST.bit.FE)
      errorVal = FRAMERR;
    if (SciaRegs.SCIRXST.bit.PE)
      errorVal = PRTYERR;
    if (SciaRegs.SCIRXST.bit.OE)
      errorVal = OVRNERR;
    if (SciaRegs.SCIRXST.bit.BRKDT)
      errorVal = BRKDTERR;
    if (SciaRegs.SCIRXST.bit.RXERROR == 1) {
      SciaRegs.SCICTL1.bit.SWRESET = 1;
      SciaRegs.SCICTL1.bit.SWRESET = 0;
      SciaRegs.SCICTL1.bit.SWRESET = 1;
    }
  }

  return errorVal;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
