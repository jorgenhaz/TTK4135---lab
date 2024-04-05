function [c , ceq] = elevationConstraint(x)
alpha = 0.2;
beta = 20;
lambda_t = (2*pi)/3;
N = 40;
mx = 6;
c = zeros(N,1);
for i = 1:N
    c(i) = alpha * exp(-beta*(x(mx*(i-1) + 1)-lambda_t)^2)-x(mx*(i-1)+5);
end 
ceq = [];
end