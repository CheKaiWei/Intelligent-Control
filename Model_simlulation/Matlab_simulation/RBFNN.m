function [sys,x0,str,ts]=M_NN_LQR_demo_first(t,x,u,flag)
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
sizes.NumInputs      = 5;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 0;
sys=simsizes(sizes);
x0=[];
str=[];
ts=[];
function sys=mdlOutputs(t,x,u)
% 定义全局变量
persistent w w_2 w_1 

% 给全局变量赋初值
if t==0  
  w=rands(5,1); 
  w_1=w;
  w_2=w_1;
end

 % 参数赋初值 
  b=1*ones(5,1);  %   b=1.9*ones(5,1);
  ci=0.5*[-5 -2 0 2 5];
  c=[ci;ci;ci;ci];
%   xite=0.50; 
%   alfa=0.05;
  xite=0.010; 
  alfa=0.1;

K=[3.1623    5.0469  -30.3064   -4.9203];

M=u(5);

% 获取当前RBF神经网络的输入 
x1=u(1);
x2=u(2);
x3=u(3);
x4=u(4);
x=[x1 x2 x3 x4]';

% 计算当前RBF神经网络隐含层的输出
h=zeros(5,1); 
for j=1:1:5
    h(j)=exp(-norm(x-c(:,j))^2/(2*b(j)*b(j)));
end

%%
% 计算当前RBF神经网络控制器的输出
u_NN=w'*h;    
u_LQR=K*x;
u_law=u_NN+u_LQR;

%%
% update weight

d_w=-xite*(u_NN-u_law)*h;
w=w_1+d_w+alfa*(w_1-w_2);
w_2=w_1;
w_1=w;

 
%%   
  % 输出控制律限幅度  
  if u_law>=10
     u_law=10;
  end
  if u_law<=-10
     u_law=-10;
  end 

% 算法输出
sys(1)=u_law;
sys(2)=u_NN;
sys(3)=u_LQR;
sys(4)=u_LQR;
sys(5)=u_LQR;

