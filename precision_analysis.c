#include "mega_include.h"

double precision_analysis (double *radioactivity, double *time, int N){
    int M = 10;
    while (M != N){
        double precision = 0.0001;
        double decay_time = nonlinear_equation(radioactivity, time, M, precision);
        while (fabs(decay_time / precision) < 10){
            precision /= 10;
            decay_time = nonlinear_equation(radioactivity, time, M, precision);
        }
        double decay_rate = linear_equation(radioactivity, time, M);
        double deviation1 = dev_exp(radioactivity, time, M, decay_time);
        double deviation2 = dev_linear(radioactivity, time, M, decay_rate);
        if (deviation2 / deviation1 > 2){
            return time[M];
        }
        M++;
    }
    return time[N - 1];
}