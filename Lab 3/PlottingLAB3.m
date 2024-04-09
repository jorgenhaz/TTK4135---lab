%% Preamble
close all
clear
clc

%%  Gather data

test1 = load ("Measure\runde2_LAB3_Q1_R01.mat");
test2 = load ("Measure\runde2_LAB3_Q1_R10.mat");
test3 = load ("Measure\runde2_LAB3_Q10_R1.mat");
test4 = load ("Measure\runde2_LAB3_Q100_1_1_1_R01.mat");
test5 = load ("Measure\runde2_LAB3_Q100_1_30_1_R01.mat");
test_cells = {test5,test4,test1,test3,test2};

%% Value strings for plotting
ledgend_list = ["Q[100,1,30,1], R=1","Q[100,1,1,1], R=1",...
    "Q[1,1,1,1], R=1","Q[10,10,10,10], R=1","Q[1,1,1,1], R=10"];

values = ["t","$$\lambda$$","r","p","$$\dot{p}$$", "e", "$$\dot{e}$$",...
    "$$\lambda_{opt}$$","r_{opt}", "$$p_{opt}$$","$$\dot{p}_{opt}$$",...
    "$$u_{opt}$$","$$u_{k}$$"];

%% Plotting

max_samples = 15000; % 30 sec
t = test1.LAB3(1,1:max_samples);

fig1 = figure(1);
set(fig1, "Position", [50,-250,1500,1500]); % Adjust the position and size of figure. [x,y,sizex,sizey]

%Travel
subplot(3,2,1)
hold on
for i = 1:length(test_cells)
plot(t,deg2rad(test_cells{i}.LAB3(2,1:max_samples)))
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
plot(t,(test_cells{i}.LAB3(8,1:max_samples)))
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
plot(t,deg2rad(test_cells{i}.LAB3(4,1:max_samples)))
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
plot(t,(test_cells{i}.LAB3(10,1:max_samples)))
end
xlabel(values(1) + "[s]", "Interpreter", "latex")
ylabel(values(10) + "[rad]", "Interpreter", "latex")
grid on;
legend(ledgend_list)
hold off

% Input
subplot(3,2,5)
hold on
for i = 1:length(test_cells)
plot(t,(test_cells{i}.LAB3(13,1:max_samples)))
end
xlabel(values(1) + "[s]", "Interpreter", "latex")
ylabel(values(13) + "[rad]", "Interpreter", "latex")
grid on;
legend(ledgend_list)
hold off

% Input optimum
subplot(3,2,6)
hold on
for i = 1:length(test_cells)
plot(t,(test_cells{i}.LAB3(12,1:max_samples)))
end
xlabel(values(1) + "[s]", "Interpreter", "latex")
ylabel(values(12) + "[rad]", "Interpreter", "latex")
grid on;
legend(ledgend_list)
hold off

saveas(fig1, "LAB3_plots.png");










