%% Preamble
close all
clear
clc

%%  Gather data

test1 = load ("Measure\LAB3_Q1_1_1_1_R1.mat");
test2 = load ("Measure\LAB3_Q3_1_1_1_R1.mat");
test3 = load ("Measure\LAB3_Q3_1_1_1_R05.mat");
test4 = load ("Measure\LAB3_Q3_1_1_1_R5.mat");
test5 = load ("Measure\LAB3_Q3_1_2_1_R1.mat");
test6 = load ("Measure\LAB3_Q3_1_05_1_R1_2.mat");
test7 = load ("Measure\LAB3_Q5_1_1_1_R1.mat");
test8 = load ("Measure\LAB3_Q07_1_1_1_R1.mat");
test_cells = {test1,test2,test3,test4,test5,test6,test7,test8};

ledgend_list = ["Q[1,1,1,1], R=1","Q[3,1,1,1], R=1","Q[3,1,1,1], R=0.5","Q[3,1,2,1], R=1",...
    "Q[3,1,1,1], R=5","Q[3,1,2,1], R=1","Q[3,1,0.5,1], R=1","Q[5,1,1,1], R=1","Q[0.75,1,1,1], R=1"];

values = ["t","$$\lambda$$","r","p","$$\dot{p}$$", "e", "$$\dot{e}$$",...
    "$$\lambda_{opt}$$","r_{opt}", "$$p_{opt}$$","$$\dot{p}_{opt}$$",...
    "$$u_{opt}$$","$$u_{k}$$"];

max_samples = 8000;
t = test1.LAB3(1,1:max_samples);

fig1 = figure(1);

%Travel
subplot(3,2,1)
hold on
for i = 1:length(test_cells)
plot(t,deg2rad(test_cells{i}.LAB3(2,1:max_samples)))
end
ylabel(values(2), "Interpreter", "latex")
xlabel(values(1))
grid on;
legend(ledgend_list)
hold off

%Travel optimum
subplot(3,2,2)
hold on
for i = 1:length(test_cells)
plot(t,(test_cells{i}.LAB3(8,1:max_samples)))
end
xlabel(values(1), "Interpreter", "latex")
ylabel(values(8), "Interpreter", "latex")
grid on;
legend(ledgend_list)
hold off

%pitch 
subplot(3,2,3)
hold on
for i = 1:length(test_cells)
plot(t,deg2rad(test_cells{i}.LAB3(4,1:max_samples)))
end
xlabel(values(1), "Interpreter", "latex")
ylabel(values(4), "Interpreter", "latex")
grid on;
legend(ledgend_list)
hold off

% Pitch optimum
subplot(3,2,4)
hold on
for i = 1:length(test_cells)
plot(t,(test_cells{i}.LAB3(10,1:max_samples)))
end
xlabel(values(1), "Interpreter", "latex")
ylabel(values(10), "Interpreter", "latex")
grid on;
legend(ledgend_list)
hold off

% input
subplot(3,2,5)
hold on
for i = 1:length(test_cells)
plot(t,(test_cells{i}.LAB3(13,1:max_samples)))
end
xlabel(values(1), "Interpreter", "latex")
ylabel(values(13), "Interpreter", "latex")
grid on;
legend(ledgend_list)
hold off

% input optimum
subplot(3,2,6)
hold on
for i = 1:length(test_cells)
plot(t,(test_cells{i}.LAB3(12,1:max_samples)))
end
xlabel(values(1), "Interpreter", "latex")
ylabel(values(12), "Interpreter", "latex")
grid on;
legend(ledgend_list)
hold off










