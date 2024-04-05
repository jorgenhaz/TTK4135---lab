%%  Preamble
close all;
%clear 
clc

%% Define continuous system
%syms K_1 K_pp K_pd K_2

A = [0 1 0 0;
    0 0 -K_2 0;
    0 0 0 1;
    0 0 -K_1*K_pp -K_1*K_pd];

B = [0 0 0 K_1*K_pp]';

%% discrete system

dt = 0.25;   % samplingtime
N = 100;     % timesteps

% adjusting our model using forward euler
Ad = dt*A;
Bd = dt*B;











