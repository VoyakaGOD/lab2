#ifndef MEGA_INCLUDE_HEADER
#define MEGA_INCLUDE_HEADER

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int experiment(double *radioactivity, double *time, double start_time, double end_time, double step);

void add_noise(double *radioactivity, int N);

double nonlinear_equation(double *radioactivity, double *time, int N, double precision, double from, double to);

double model(double *radioactivity, double *time, int N, double point);

double linear_equation(double *radioactivity, double *time, int N);

double precision_analysis(double *radioactivity, double *time, int N);

double dev_exp(double *radioactivity, double *time, int M, double decay_time);

double dev_linear(double *radioaktivity, double *time, int M, double decay_rate);

#endif //MEGA_INCLUDE_HEADER