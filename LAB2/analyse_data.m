%% Preamble
close all
clc

%% Plotting
test1 = load("Measure\LAB2_test_q012.mat");
test2 = load("Measure\LAB2_test_q1_2.mat");
test3 = load("Measure\LAB2_test_q12.mat");
test4 = load("Measure\LAB2_test_q012_without_pc_bound.mat");

test_cells = {test1,test2,test3,test4};

legend_list = ["q = 0.12","q = 1.2",...
    "q = 12","q = 0.12 || no constraint on p_{c}"];

values = ["t","$$\lambda$$","r","p","$$\dot{p}$$", "e", "$$\dot{e}$$",...
    "$$\lambda_{opt}$$","r_{opt}", "$$p_{opt}$$","$$\dot{p}_{opt}$$",...
    "$$u_{opt}$$","$$u_{k}$$"];


max_samples = 15000; % 30 sec
t = test1.T_Tr_p_pr_e_er_LAB2u(1,1:max_samples);

%Plotting travel
fig = figure(1);
set(fig, "Position", [50,-250,1500,1500]); % Adjust the position and size of figure. [x,y,sizex,sizey]
hold on

for i = 1:length(test_cells)
    plot(t,test_cells{i}.T_Tr_p_pr_e_er_LAB2u(2,1:max_samples))
end

grid on
ylabel(values(2) + " degrees", "Interpreter", "latex")
xlabel(values(1) + "[s]", "Interpreter", "latex")
legend(legend_list)
xlim([0 , 15])
ylim([100 , 360])
title('Travel for different weights (q)')
hold off

%Plotting pitch
fig = figure(2);
set(fig, "Position", [50,-250,1500,1500]); % Adjust the position and size of figure. [x,y,sizex,sizey]
hold on

for i = 1:length(test_cells)
    plot(t,deg2rad(test_cells{i}.T_Tr_p_pr_e_er_LAB2u(4,1:max_samples)))
end

grid on
ylabel(values(3) + " radians", "Interpreter", "latex")
xlabel(values(1) + "[s]", "Interpreter", "latex")
legend(legend_list)
xlim([0 , 15])
ylim([-1 , 1])
title('Pitch for different weights (q)')
hold off

% t_measurement = T_Tr_p_pr_e_er_LAB2u(1,:);
% Travel = T_Tr_p_pr_e_er_LAB2u(2,:);
% Travel_dot = T_Tr_p_pr_e_er_LAB2u(3,:);
% Pitch = T_Tr_p_pr_e_er_LAB2u(4,:);
% Pitch_dot = T_Tr_p_pr_e_er_LAB2u(5,:);
% Elevation = T_Tr_p_pr_e_er_LAB2u(6,:);
% Elevation_dot = T_Tr_p_pr_e_er_LAB2u(7,:);
% u_open_loop = T_Tr_p_pr_e_er_LAB2u(8,:);