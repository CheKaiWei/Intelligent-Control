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
persistent  w_2  w_1  w  

% 给全局变量赋初值
if t==0  
  w=[3.1623    5.0469  -30.3064   -4.9203]';
  w_1=w; 
  w_2=w_1;
end

% 参数赋初值
xita=0.01;
alfa=0.1;

% 获取当前神经网络的输入 
x1=u(1);
x2=u(2);
x3=u(3);
x4=u(4);
x=[x1 x2 x3 x4]';
 

   %
   %
   %
   % 计算神经网络控制器的输出和神经网络权值调整
   %
   %
   
% E=-0.5u^2 
% s=w'*x;   
% u_law=s;
% dw=-xita*u_law*x;
% w=w_1+dw+alfa*(w_1-w_2);

% u_law=w'*x;
% s=sum(x);
% a1=(u_law-w(2)*x(2)-w(3)*x(3)-w(4)*x(4))/(w(1)*w(1));
% a2=(u_law-w(1)*x(1)-w(3)*x(3)-w(4)*x(4))/(w(2)*w(2));
% a3=(u_law-w(2)*x(2)-w(1)*x(1)-w(4)*x(4))/(w(3)*w(3));
% a4=(u_law-w(2)*x(2)-w(3)*x(3)-w(1)*x(1))/(w(4)*w(4));
% dw=-xita*s*(a1+a2+a3+a4);
% w=w_1+dw+alfa*(w_1-w_2);

u_law=w'*x;
a1=x(1)*(u_law-w(2)*x(2)-w(3)*x(3)-w(4)*x(4))/(w(1)*w(1));
a2=x(2)*(u_law-w(1)*x(1)-w(3)*x(3)-w(4)*x(4))/(w(2)*w(2));
a3=x(3)*(u_law-w(2)*x(2)-w(1)*x(1)-w(4)*x(4))/(w(3)*w(3));
a4=x(4)*(u_law-w(2)*x(2)-w(3)*x(3)-w(1)*x(1))/(w(4)*w(4));
dw=xita*[a1;a2;a3;a4];
w=w_1+dw+alfa*(w_1-w_2);
w_1 = w;
w_2 = w_1;


   % 输出控制律限幅度  
   if u_law>=10
     u_law=10;
   end
   if u_law<=-10
     u_law=-10;
   end 

% 算法输出
sys(1)=u_law;
sys(2)=w(1);
sys(3)=w(2);
sys(4)=w(3);
sys(5)=w(4);
