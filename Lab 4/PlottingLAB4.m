%% Preamble
close all
clear
clc

%%  Gather data

test1 = load ("Measure\LAB4_Q1_R1.mat");
test2 = load ("Measure\LAB4_Q1_R10.mat");
test3 = load ("Measure\LAB4_Q1_R01.mat");
test4 = load ("Measure\LAB4_Q10_R1.mat");
test5 = load ("Measure\LAB4_Q50T_50E_R1.mat");
test6 = load ("Measure\LAB4_Q25T_25E_R1.mat");
test7 = load ("Measure\LAB4_Q_R_tuned.mat");
test8 = load ("Measure\LAB4_Q_R_tuned2.mat");
test9 = load ("Measure\LAB4_Q_R_tuned3.mat");
test10 = load ("Measure\LAB4_Q_R_tuned4.mat");

%test_cells = {test1, test2, test3, test4, test5, test6, test7, test8, test9, test10};
test_cells = {test7,test8,test9,test10};
%% Value strings for plotting
ledgend_list = ["Q=eye(6),R=eye(2)","Q=eye(6),R=10*eye(2)",...
    "Q=eye(6),R=0.1*eye(2)","Q=10*eye(6),R=eye(2)","Q=50T50E,R=1","Q=25T25E,R=1",...
    "QR tuned1", "QR tuned2", "QR tuned3", "QR tuned4"];

values = ["t","$$\lambda$$","r","p","$$\dot{p}$$", "e", "$$\dot{e}$$",...
    "$$\lambda_{opt}$$","r_{opt}", "$$p_{opt}$$","$$\dot{p}_{opt}$$",...
    "$$e_{opt}$$","$$\dot{e}_{opt}$$","$$u_{opt}$$","$$u_{k}$$"];

%% Plotting

max_samples = 15000; % 30 sec
t = test1.LAB4(1,1:max_samples);

fig1 = figure(1);
set(fig1, "Position", [50,-250,1500,1500]); % Adjust the position and size of figure. [x,y,sizex,sizey]

%Travel
subplot(3,2,1)
hold on
for i = 1:length(test_cells)
plot(t,deg2rad(test_cells{i}.LAB4(2,1:max_samples)))
end
ylabel(values(2) + "[rad]", "Interpreter", "latex")
xlabel(values(1) + "[s]", "Interpreter", "latex")
grid on;
legend(ledgend_list)
hold off

%Travel optimum
subplot(3,2,2)
hold on
for i = 1:length(test_cells)
plot(t,(test_cells{i}.LAB4(8,1:max_samples)))
end
xlabel(values(1) + "[s]", "Interpreter", "latex")
ylabel(values(8) + "[rad]", "Interpreter", "latex")
grid on;
legend(ledgend_list)
hold off

% Pitch 
subplot(3,2,3)
hold on
for i = 1:length(test_cells)
plot(t,deg2rad(test_cells{i}.LAB4(4,1:max_samples)))
end
xlabel(values(1) + "[s]", "Interpreter", "latex")
ylabel(values(4) + "[rad]", "Interpreter", "latex")
grid on;
legend(ledgend_list)
hold off

% Pitch optimum
subplot(3,2,4)
hold on
for i = 1:length(test_cells)
plot(t,(test_cells{i}.LAB4(10,1:max_samples)))
end
xlabel(values(1) + "[s]", "Interpreter", "latex")
ylabel(values(10) + "[rad]", "Interpreter", "latex")
grid on;
legend(ledgend_list)
hold off

% Elevation
subplot(3,2,5)
hold on
for i = 1:length(test_cells)
plot(t,deg2rad(test_cells{i}.LAB4(6,1:max_samples)))
end
xlabel(values(1) + "[s]", "Interpreter", "latex")
ylabel(values(6) + "[rad]", "Interpreter", "latex")
grid on;
legend(ledgend_list)
hold off

% Elevation optimum
subplot(3,2,6)
hold on
for i = 1:length(test_cells)
plot(t,(test_cells{i}.LAB4(12,1:max_samples)))
end
xlabel(values(1) + "[s]", "Interpreter", "latex")
ylabel(values(12) + "[rad]", "Interpreter", "latex")
grid on;
legend(ledgend_list)
hold off

saveas(fig1, "LAB4_plots.png");










