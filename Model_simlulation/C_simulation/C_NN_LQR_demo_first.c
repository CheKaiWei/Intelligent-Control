
#define  S_FUNCTION_NAME  C_NN_LQR_demo_first           /*锟斤拷锟斤拷S-Function锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷要锟斤拷.C锟侥硷拷锟斤拷锟斤拷锟斤拷募锟斤拷锟揭伙拷锟�1�7*/
#define  S_FUNCTION_LEVEL 2
#define  w0   0.1

#include "simstruc.h"
#include <math.h>
#include <stdio.h>




  /*锟斤拷锟斤拷系统锟斤拷全锟街憋拷锟斤拷*/
  real_T            w[5];
  real_T            w_1[5];  
  real_T            w_2[5];  
  

/* Function: mdlInitializeSizes 
 * Abstract:锟斤拷锟斤拷S-Function模锟斤拷幕锟斤拷锟斤拷锟斤拷锟�1�7.*/

static void mdlInitializeSizes(SimStruct *S)
{
    ssSetNumSFcnParams(S, 0);
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) 
    {
     return; 
    }

    if (!ssSetNumInputPorts(S, 1)) return;
    ssSetInputPortWidth(S, 0, 5);                 /* 锟斤拷锟斤拷S-Function锟斤拷锟斤拷锟斤拷锟轿�锟斤縿1�7*/
    ssSetInputPortDirectFeedThrough(S, 0, 1);

    if (!ssSetNumOutputPorts(S,1)) return;
    ssSetOutputPortWidth(S, 0, 3);               /* 锟斤拷锟斤拷S-Function锟斤拷锟斤拷锟斤拷锟斤拷锟轿�锟斤縿1�7*/
 
    ssSetNumSampleTimes(S, 1);
    ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE);
    
    /*锟斤拷系统锟斤拷全锟街憋拷锟斤拷锟斤拷锟斤拷值*/    
    
    w[0]=w0;
    w[1]=w0;
    w[2]=w0;
    w[3]=w0;
    w[4]=w0;
    w_1[0]=w0;
    w_1[1]=w0;
    w_1[2]=w0;
    w_1[3]=w0;
    w_1[4]=w0;
    w_2[0]=w0;
    w_2[1]=w0;
    w_2[2]=w0;
    w_2[3]=w0;
    w_2[4]=w0;

 }


/* Function: mdlInitializeSampleTimes 
 /* 锟斤拷锟斤拷系统锟侥诧拷锟斤拷时锟斤拷.*/

static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetOffsetTime(S, 0, 0.0);
}


/* Function: mdlOutputs 
/* 锟斤拷锟斤拷S-Function锟斤拷锟斤拷锟斤拷锟斤拷锟叫聪低筹拷目锟斤拷锟斤拷锟斤拷惴�锟斤縿1�7*/

static void mdlOutputs(SimStruct *S, int_T tid)
{
     /* 锟斤拷锟斤拷锟斤拷锟�1�7 */  
	InputRealPtrsType in = ssGetInputPortRealSignalPtrs(S,0); 
	real_T            *out    = ssGetOutputPortRealSignal(S,0);
    real_T            u_law;
    real_T            u_NN;
    real_T            u_NN_mid[5];
    real_T            sum_mid;
    real_T            u_LQR;
    real_T            u_LQR_mid[4];
    real_T		       x[4];
    real_T		       h[5];
    real_T            dw[5];
    real_T		      x_norm[5];
    real_T		      x_norm_mid[4];
    real_T		      d[4][5];
    real_T		      K[4]={3.1623, 5.0469,-30.3064,-4.9203}; 
	  //real_T		      bi[5]={1.5,1.5,1.5,1.5,1.5};   /*{1.9,1.9,1.9,1.9,1.9};*/
	  real_T		      bi[5]={1,1,1,1,1};   /*{1.9,1.9,1.9,1.9,1.9};*/
	  real_T		      Ci[4][5]={{-2.5,-1,0,1,2.5},{-2.5,-1,0,1,2.5},{-2.5,-1,0,1,2.5},{-2.5,-1,0,1,2.5}};
//real_T		      Ci[4][5]={{-5,-2,0,2,5},{-5,-2,0,2,5},{-5,-2,0,2,5},{-5,-2,0,2,5}};    
// 	real_T            xite=0.50;
// 	real_T            alfa=0.05;
    real_T            xite=0.10;
    real_T            alfa=0.1;
    real_T            sum[5]={0,0,0,0,0};
    real_T            sum_u=0;
    real_T            flag=*in[4];
    int               i;
    int               j; 

    for(i=0;i<4;i++)
    {  
      x[i]=*in[i];
    }   
    
 
  
  for(j=0;j<5;j++){
    for(i=0;i<4;i++)
      x_norm_mid[i] = x[i] - Ci[i][j];
    x_norm[j] = x_norm_mid[1]*x_norm_mid[1]+x_norm_mid[2]*x_norm_mid[2]+x_norm_mid[3]*x_norm_mid[3]+x_norm_mid[4]*x_norm_mid[4];
    h[j] = exp(-(x_norm[j])/(2*bi[j]*bi[j]));
  }

  sum_mid = 0;
  for(i=0;i<5;i++){
    u_NN_mid[i] =  w[i]*h[i];
    sum_mid += u_NN_mid[i];
  }
  u_NN = sum_mid;

  sum_mid = 0;
  for(i=0;i<4;i++){
    u_LQR_mid[i] =  K[i]*x[i];
    sum_mid += u_LQR_mid[i];
  }
  u_LQR = sum_mid;

  u_law = u_NN + u_LQR;

  for(i=0;i<5;i++){
    dw[i] = -xite*(u_NN-u_law)*h[i];
    w[i] = w_1[i]+dw[i]+alfa*(w_1[i]-w_2[i]);
    w_2[i]= w_1[i];
    w_1[i] = w[i];
  }

  // u_law = u_NN;
//u_law = u_LQR;
    if(u_law>10)
      u_law=10;
    if(u_law<-10)
      u_law=-10;

   out[0]=u_law;
   out[1]=u_NN;
   out[2]=u_LQR;
   
}


/* Function: mdlTerminate 
 * Abstract:实锟街凤拷锟斤拷锟斤拷锟斤拷锟斤拷锟侥斤拷锟斤拷.*/

static void mdlTerminate(SimStruct *S)
{
}

#ifdef  MATLAB_MEX_FILE    
#include "simulink.c"      
#else
#include "cg_sfun.h"      
#endif

