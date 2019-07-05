

#define    S_FUNCTION_NAME   C_NN_LQR_demo_second           /*定义S-Function函数名，函数名要与.C文件保存的文件名一致*/
#define    S_FUNCTION_LEVEL 2
/*#define    k0   3.1623    
#define    k1   5.0469 
#define    k2   -30.3064 
#define    k3   -4.9203*/
//15 12 -25 -3
#define    k0   15    
#define    k1   12 
#define    k2   -25 
#define    k3   -3


#include "simstruc.h"
#include <math.h>
#include <stdio.h>

  /*定义系统的全局变量*/ 
  real_T          w[4];
  real_T          w_1[4];  
  real_T          w_2[4];  

/* Function: mdlInitializeSizes 
 * Abstract:定义S-Function模块的基本特性.*/

static void mdlInitializeSizes(SimStruct *S)
{
    ssSetNumSFcnParams(S, 0);
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) 
    {
     return; 
    }

    if (!ssSetNumInputPorts(S, 1)) return;
    ssSetInputPortWidth(S, 0, 9);                 /* 定义S-Function输入变量维数*/
    ssSetInputPortDirectFeedThrough(S, 0, 1);

    if (!ssSetNumOutputPorts(S,1)) return;
    ssSetOutputPortWidth(S, 0, 7);               /* 定义S-Function输入出变量维数*/
 
    ssSetNumSampleTimes(S, 1);
    ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE);
    
    /*对系统的全局变量赋初值*/       

     w[0]=k0;
     w[1]=k1;
     w[2]=k2;
    w[3]=k3;
    w_1[0]=k0;
    w_1[1]=k1;
    w_1[2]=k2;
    w_1[3]=k3;
    w_2[0]=k0;
    w_2[1]=k1;
    w_2[2]=k2;
    w_2[3]=k3;
    
   }
    
/* Function: mdlInitializeSampleTimes 
 /* 定义系统的采样时间.*/

static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetOffsetTime(S, 0, 0.0);
}

/* Function: mdlOutputs 
/* 计算S-Function的输出（编写系统的控制器算法）*/

static void mdlOutputs(SimStruct *S, int_T tid)
{
     /* 定义变量 */  
	InputRealPtrsType in = ssGetInputPortRealSignalPtrs(S,0); 
	real_T            *out    = ssGetOutputPortRealSignal(S,0);
    real_T            u_law;
    real_T		      x[4];
    real_T		      a0;
    real_T		      a1;
    real_T		      a2;
    real_T		      a3;
    real_T            dw[4];
	real_T            xite;
	real_T            alfa;
    real_T            sum_u;
    int               j,flag; 

   /* 获取当前神经网络的输入 */  
    for(j=0;j<4;j++)
    {  
      x[j]=*in[j];
    }
    x[0]=-x[0];
    x[1]=-x[1];
    xite=*in[7];
    alfa=*in[8];
    flag=*in[5];
   
   
     
     
//      计算当前神经网络控制器的输出和神经网络权值调整
    if(flag==1){
     //output   
     u_law=w[0]*x[0]+w[1]*x[1]+w[2]*x[2]+w[3]*x[3];
     //Weight adjust
     a0=x[0]*(u_law-w[1]*x[1]-w[2]*x[2]-w[3]*x[3])/(w[0]*w[0]);
     a1=x[1]*(u_law-w[0]*x[0]-w[2]*x[2]-w[3]*x[3])/(w[1]*w[1]);
     a2=x[2]*(u_law-w[1]*x[1]-w[0]*x[0]-w[3]*x[3])/(w[2]*w[2]);
     a3=x[3]*(u_law-w[1]*x[1]-w[2]*x[2]-w[0]*x[0])/(w[3]*w[3]);
     dw[0]=xite*a0;
     dw[1]=xite*a1;
     dw[2]=xite*a2;
     dw[3]=xite*a3;
     w[0]=w_1[0]+dw[0]+alfa*(w_1[0]-w_2[0]);
     w[1]=w_1[1]+dw[1]+alfa*(w_1[1]-w_2[1]);
     w[2]=w_1[2]+dw[2]+alfa*(w_1[2]-w_2[2]);
     w[3]=w_1[3]+dw[3]+alfa*(w_1[3]-w_2[3]);
     w_1[0]=w[0];
     w_1[1]=w[1];
     w_1[2]=w[2];
     w_1[3]=w[3];
     w_2[0]=w_1[0];
     w_2[1]=w_1[1];
     w_2[2]=w_1[2];
     w_2[3]=w_1[3];
  
 
   /* 输出控制律限幅度 */ 
    if(u_law>10)
      u_law=10;
    if(u_law<-10)
      u_law=-10;
    }
    
    else u_law=0;//当Writer 15==0时不进行权值的调整
    
  /* 算法输出 */  
   out[0]=u_law;
   out[1]=0;//no u_lqr
   out[2]=0;//no u_nn
   out[3]=w[0];
   out[4]=w[1];
   out[5]=w[2];
   out[6]=w[3];
   
}


/* Function: mdlTerminate 
 * Abstract:实现仿真任务必须的结束.*/

static void mdlTerminate(SimStruct *S)
{
}

#ifdef  MATLAB_MEX_FILE    
#include "simulink.c"      
#else
#include "cg_sfun.h"      
#endif

