clc
close all;

% Initialization and model definition
init06; % Change this to the init file corresponding to your helicopter


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

%Defined sizes
mx = size(A_d,2);
mu = size(B_d,2);
N = 40;
M = N;
n = N*mx+M*mu;
z = NaN(n,1);
z0 = zeros(n,1);

% Initial values
x1_0 = pi;                              % Lambda
x2_0 = 0;                               % r
x3_0 = 0;                               % p
x4_0 = 0;                               % p_dot
x5_0 = 0;                               % e
x6_0 = 0;                               % e_dot
x0 = [x1_0 x2_0 x3_0 x4_0 x5_0 x6_0]';  % Initial values

% Bounds
pc_bound = 60*pi/360;
ul 	    = -pc_bound;                    % Lower bound on control
uu 	    = pc_bound;                     % Upper bound on control

xl      = -Inf*ones(mx,1);              % Lower bound on states (no bound)
xu      = Inf*ones(mx,1);               % Upper bound on states (no bound)
xl(3)   = ul;                           % Lower bound on state x3
xu(3)   = uu;                           % Upper b ound on state x3

% Generate constraints on measurements and inputs
[vlb,vub]       = gen_constraints(N,M,xl,xu,ul,uu); % hint: gen_constraints
vlb(N*mx+M*mu)  = 0;                    % We want the last input to be zero
vub(N*mx+M*mu)  = 0;                    % We want the last input to be zero

% Generate system matrixes for linear model
Aeq = gen_aeq(A_d,B_d,N,mx,mu);          % Generate A, hint: gen_aeq
beq = [A_d*x0;zeros((N-1)*mx,1)];        % Generate b

%% Tuning 
% LQR

Q_lqr = diag([1 1 1 1 1 1]);
R_lqr = diag([0.1 0.1]);

K_lqr = dlqr(A_d,B_d,Q_lqr,R_lqr);

%Creating function (see preparation for explanation)
q_1 = 8;
q_2 = 8;

R = [q_1 0;
    0 q_2];

Q = diag([1 0 0 0 0 0]);

title_string = sprintf("q_{1} = %0.2f, q_{2} = %0.2f",q_1,q_2);
plot_file_name = "LAB4_simulation_11.png";

%% Optimization
G = gen_q(Q,R,N,M);

func = @(z) z'*G*z;

%Nonlinear constraint
nonlcon = @elevationConstraint;
options = optimoptions('fmincon','Display','off','Algorithm','sqp');
tic
[Z,~] = fmincon(func,z0,[],[],Aeq,beq,vlb,vub,nonlcon,options);

% Extract control inputs and states
u_pc  = [Z(N*mx+1:mu:n);Z(n-1)];    % Pitch-referenc
u_ec  = [Z(N*mx+2:mu:n);Z(n)];      % Elevation reference
x1 = [x0(1);Z(1:mx:N*mx)];          % State lambda from solution
x2 = [x0(2);Z(2:mx:N*mx)];          % State r from solution
x3 = [x0(3);Z(3:mx:N*mx)];          % State p from solution
x4 = [x0(4);Z(4:mx:N*mx)];          % State p_dot from solution
x5 = [x0(5);Z(5:mx:N*mx)];          % State e from solution
x6 = [x0(6);Z(6:mx:N*mx)];          % State e_dot from solution

num_variables = 5/delta_t;
zero_padding = zeros(num_variables,1);
unit_padding  = ones(num_variables,1);

%Optimal u and states
u_pc  = [zero_padding; u_pc; zero_padding];
u_ec  = [zero_padding; u_ec; zero_padding];
u = [u_pc, u_ec];
x1  = [pi*unit_padding; x1; zero_padding];
x2  = [zero_padding; x2; zero_padding];
x3  = [zero_padding; x3; zero_padding];
x4  = [zero_padding; x4; zero_padding];
x5  = [zero_padding; x5; zero_padding];
x6  = [zero_padding; x6; zero_padding];

x_optimum = [x1 x2 x3 x4 x5 x6];

%% Plotting
t = 0:delta_t:delta_t*(length(u)-1);
u_ts = timeseries(u,t);
x_optimum_ts = timeseries(x_optimum,t);

fig2 = figure(2);
sgtitle(title_string)
subplot(421)
stairs(t,u_pc),grid
ylabel('u_{pc}')
subplot(422)
stairs(t,u_ec),grid
ylabel('u_{ec}')
subplot(423)
plot(t,x1,'m',t,x1,'mo'),grid
ylabel('lambda')
subplot(424)
plot(t,x2,'m',t,x2','mo'),grid
ylabel('r')
subplot(425)
plot(t,x3,'m',t,x3,'mo'),grid
ylabel('p')
subplot(426)
plot(t,x4,'m',t,x4','mo'),grid
xlabel('tid (s)'),ylabel('pdot')
subplot(427)
plot(t,x5,'m',t,x5','mo'),grid
ylabel('e')
subplot(428)
plot(t,x6,'m',t,x6','mo'),grid
xlabel('tid (s)'),ylabel('edot')
saveas(fig2,plot_file_name)


