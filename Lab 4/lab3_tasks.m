
template_problem_2
% Discrete time system model. x = [lambda r p p_dot]'
delta_t	= 0.25; % sampling time
Ac = [0 1 0 0;
      0 0 -K_2 0;
      0 0 0 1;
      0 0 -K_1*K_pp -K_1*K_pd];
Ad = delta_t*Ac+eye(4);

Bc = [0 0 0 -K_1*K_pd]';

Bd = delta_t*Bc;

Q = diag([1 1 1 1]);
R = 1;

[K,p,e] = dlqr(Ad,Bd,Q,R,[]);
