
#define  S_FUNCTION_NAME  C_NN_LQR_demo_first           /*定义S-Function函数名，函数名要与.C文件保存的文件名一致*/
#define  S_FUNCTION_LEVEL 2
#define  w0   0.1

#include "simstruc.h"
#include <math.h>
#include <stdio.h>

  /*定义系统的全局变量*/
  real_T            w[5];
  real_T            w_1[5];  
  real_T            w_2[5];  
  

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
    ssSetInputPortWidth(S, 0, 5);                 /* 定义S-Function输入变量维数*/
    ssSetInputPortDirectFeedThrough(S, 0, 1);

    if (!ssSetNumOutputPorts(S,1)) return;
    ssSetOutputPortWidth(S, 0, 3);               /* 定义S-Function输入出变量维数*/
 
    ssSetNumSampleTimes(S, 1);
    ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE);
    
    /*对系统的全局变量赋初值*/    
    
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
    real_T            u_NN;
    real_T            u_LQR;
    real_T		      x[4];
    real_T		      h[5]={0,0,0,0,0}; /////////
    real_T            dw[5];
    real_T		      x_norm[4];
    real_T		      d[5];
    real_T		      K[4]={3.1623, 5.0469,-30.3064,-4.9203}; 
	real_T		      bi[5]={1.9,1.9,1.9,1.9,1.9};   /*{1.5,1.5,1.5,1.5,1.5};*/
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

   /* 获取算法的输入 */  
    for(i=0;i<4;i++)
    {  
      x[i]=*in[i];
  
    }   
    
     //h(j)=exp(-norm(x-c(:,j))^2/(2*b(j)*b(j)));
    
     for(j=0;j<5;j++)
     {
        for(i=0;i<4;i++)
        {
       
            x_norm[i]=x[i]-Ci[i][j];
            d[j]=x_norm[i]*x_norm[i];
            h[j]+=d[j];
            
        }
      
    h[j]=-h[j]/(2*bi[j]*bi[j]);    
    h[j]=exp(h[j]);    
    
    }
    
    
    /* 
     
     计算当前神经网络控制器的输出和神经网络权值调整
     *
     
     */
    u_LQR=K[0]*x[0];
    for(i=0;i<4;i++)
    {  
      u_LQR=u_LQR+K[i]*x[i];
     
    }   
    
    u_law=u_NN+u_LQR;
    
    for(i=0;i<5;i++)
    {  
       dw[i]=-xite*(u_NN-u_law)*h[i];
       w[i]=w_1[i]+ dw[i]+alfa*(w_1[i]-w_2[i]);
    }  
    
    w_1[0]=w[0];
    w_1[1]=w[1];
    w_1[2]=w[2];
    w_1[3]=w[3];
    w_1[4]=w[4];
    w_2[0]=w_1[0];
    w_2[1]=w_1[1];
    w_2[2]=w_1[2];
    w_2[3]=w_1[3];
    w_2[4]=w_1[4];
   //  u_law=u_NN+u_LQR;
//     dw=-xite*(u_NN-u_law)*h;
//     w=w_1+ dw+alfa*(w_1-w_2);
   
    
    /* 输出控制律限幅度 */ 
    if(u_law>10)
      u_law=10;
    if(u_law<-10)
      u_law=-10;
    
    
   /* 算法输出 */      
   out[0]=u_law;
   out[1]=u_NN;
   out[2]=u_LQR;
   
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

