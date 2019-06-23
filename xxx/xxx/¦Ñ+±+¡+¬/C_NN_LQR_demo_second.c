

#define    S_FUNCTION_NAME   C_NN_LQR_demo_second           /*����S-Function��������������Ҫ��.C�ļ�������ļ���һ��*/
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

  /*����ϵͳ��ȫ�ֱ���*/ 
  real_T          w[4];
  real_T          w_1[4];  
  real_T          w_2[4];  

/* Function: mdlInitializeSizes 
 * Abstract:����S-Functionģ��Ļ�������.*/

static void mdlInitializeSizes(SimStruct *S)
{
    ssSetNumSFcnParams(S, 0);
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) 
    {
     return; 
    }

    if (!ssSetNumInputPorts(S, 1)) return;
    ssSetInputPortWidth(S, 0, 9);                 /* ����S-Function�������ά��*/
    ssSetInputPortDirectFeedThrough(S, 0, 1);

    if (!ssSetNumOutputPorts(S,1)) return;
    ssSetOutputPortWidth(S, 0, 7);               /* ����S-Function���������ά��*/
 
    ssSetNumSampleTimes(S, 1);
    ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE);
    
    /*��ϵͳ��ȫ�ֱ�������ֵ*/       

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
 /* ����ϵͳ�Ĳ���ʱ��.*/

static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetOffsetTime(S, 0, 0.0);
}

/* Function: mdlOutputs 
/* ����S-Function���������дϵͳ�Ŀ������㷨��*/

static void mdlOutputs(SimStruct *S, int_T tid)
{
     /* ������� */  
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

   /* ��ȡ��ǰ����������� */  
    for(j=0;j<4;j++)
    {  
      x[j]=*in[j];
    }
    x[0]=-x[0];
    x[1]=-x[1];
    xite=*in[7];
    alfa=*in[8];
    flag=*in[5];
   
   
     
     
//      ���㵱ǰ������������������������Ȩֵ����
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
  
 
   /* ����������޷��� */ 
    if(u_law>10)
      u_law=10;
    if(u_law<-10)
      u_law=-10;
    }
    
    else u_law=0;//��Writer 15==0ʱ������Ȩֵ�ĵ���
    
  /* �㷨��� */  
   out[0]=u_law;
   out[1]=0;//no u_lqr
   out[2]=0;//no u_nn
   out[3]=w[0];
   out[4]=w[1];
   out[5]=w[2];
   out[6]=w[3];
   
}


/* Function: mdlTerminate 
 * Abstract:ʵ�ַ����������Ľ���.*/

static void mdlTerminate(SimStruct *S)
{
}

#ifdef  MATLAB_MEX_FILE    
#include "simulink.c"      
#else
#include "cg_sfun.h"      
#endif

