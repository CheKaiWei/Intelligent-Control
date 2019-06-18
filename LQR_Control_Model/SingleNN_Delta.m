function [sys,x0,str,ts]=M_NN_LQR_demo_second(t,x,u,flag)
switch flag,
case 0,
    [sys,x0,str,ts]=mdlInitializeSizes;
case 3,
    sys=mdlOutputs(t,x,u);
case {2, 4, 9 }
    sys = [];
otherwise
    error(['Unhandled flag = ',num2str(flag)]);
end


function [sys,x0,str,ts]=mdlInitializeSizes
sizes = simsizes;
sizes.NumContStates  = 0;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 5;
sizes.NumInputs      = 4;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 0;
sys=simsizes(sizes);
x0=[];
str=[];
ts=[];
function sys=mdlOutputs(t,x,u)
% 定义全局变量
persistent    w_1 w_2  w  u_1

% 给全局变量赋初值
if t==0  
  w=[3.1623    5.0469  -30.3064   -4.9203];
  w_1=w; 
  w_2=w; 
  u_1 = 0;
end

% 参数赋初值
xite=0.0001;
K=0.2;
alfa=0.05;
% 获取当前神经网络的输入 
x1=u(1);
x2=u(2);
x3=u(3);
x4=u(4);
x=[x1 x2 x3 x4]';

for i=1:4
    dw(i) = -xite*x(i)*x(i);
end

w = w_1 + dw + alfa*(w_1-w_2) 

u_law = u_1+K.*w*x;

if u_law>=10
 u_law=10;
end
if u_law<=-10
 u_law=-10;
end

  
u_1 = u_law;
w_2 = w_1;
w_1 = w;   
   
% 算法输出
sys(1)=u_law;
sys(2)=w(1);
sys(3)=w(2);
sys(4)=w(3);
sys(5)=w(4);

