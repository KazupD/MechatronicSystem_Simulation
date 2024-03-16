clear; clc;

Cm = 0.1;
J_shaft = 0.012;
Ja = 0.001;
La = 0.047;
Ra = 0.5;
b_shaft = 2.21;
b_spring = 3;
ba = 0.01;
g = 9.81;
k_spring = 2*10^4;
lower_limit = 0;
m = 2;
r_shaft = 0.1;
upper_limit = 5;
time_step = 0.002;

A = [-Ra/La,   0,       -Cm/La, 0,     0;
      0,     0,        1,    0,     0;
      Cm/J_shaft, -r_shaft^2*k_spring/J_shaft, -b_shaft/J_shaft,  r_shaft*k_spring/J_shaft, 0;
      0,     0,        0,    0,     1;
      0,     r_shaft*k_spring/m,    0,   -k_spring/m,   -b_spring/m]

B = [1/La; 0; 0; 0; 0];
C = [0, 0, 0, 1, 0];
D = [0];

sys = ss(A, B, C, D);

s1 = -0.5;
s2 = -1.08e+01
s3 = -1.01e+02
s4 = -4.21e+01 + 1.29e+02i
s5 = conj(s4)

phic=[s1 s2 s3 s4 s5];

K=acker(A,B,phic)

At = A-B*K

Kr = -inv(C*inv(At)*B)

sys_c = ss(At, B, C, D)

figure;
step(4*sys_c*Kr);

