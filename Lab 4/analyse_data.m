%% Preamble
close all
clc

%% Plotting
load LAB2\Measure\LAB2_test.mat

t_measurement = T_Tr_p_pr_e_er_LAB2u(1,:);
Travel = T_Tr_p_pr_e_er_LAB2u(2,:);
Travel_dot = T_Tr_p_pr_e_er_LAB2u(3,:);
Pitch = T_Tr_p_pr_e_er_LAB2u(4,:);
Pitch_dot = T_Tr_p_pr_e_er_LAB2u(5,:);
Elevation = T_Tr_p_pr_e_er_LAB2u(6,:);
Elevation_dot = T_Tr_p_pr_e_er_LAB2u(7,:);
u_open_loop = T_Tr_p_pr_e_er_LAB2u(8,:);

time_stop = 20; %In seconds
samples_simu = time_stop/delta_t; 
samples_real = time_stop/0.002; %Tror at samplingstiden i simulink er 0.002

result_plot_heli = figure(1);
hold on
%plot(t,Travel)
plot(t_measurement,deg2rad(Travel_dot))
%plot(t,Pitch)
%plot(t,Pitch_dot)
%plot(t,Elevation)
%plot(t,Elevation_dot)
plot(t_measurement,u_open_loop)
grid on

result_plot_simu_with_real = figure(2);
subplot(511)
stairs(t(1:samples_simu),u(1:samples_simu)),grid
ylabel('u')
subplot(512)
plot(t(1:samples_simu),x1(1:samples_simu),'m',t(1:samples_simu),x1(1:samples_simu),'mo'),grid
ylabel('lambda')
subplot(513)
plot(t_measurement(1:samples_real),Travel(1:samples_real),'m'),grid
ylabel('real lambda')
xlabel('tid (s)'),ylabel('pdot')