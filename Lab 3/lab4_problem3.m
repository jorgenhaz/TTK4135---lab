%Continous
A_c = [0 1 0 0 0 0;
    0 0 -K_2 0 0 0;
    0 0 0 1 0 0;
    0 0 -K_1*K_pp -K_1*K_pd 0 0;
    0 0 0 0 0 1;
    0 0 0 0 -K_3*K_ep -K_3*K_ed];

B_c = [0 0;
    0 0;
    0 0;
    K_1*K_pp 0;
    0 0;
    0 K_3*K_ep];

%Sampling time
delta_t	= 0.25;

%Discrete
A_d = delta_t*A_c+eye(size(A_c));
B_d = delta_t*B_c;

%Declaring variables
q_1, q_2 = 1;
alpha = 0.2;
beta = 20;
lambda_t = (2*pi)/3;




myFun = @(x) (x(1)-lambda_f)^2+q_1*p