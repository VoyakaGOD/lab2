#include <stdlib.h>
#include <stdio.h>


double dev_exp(double *radioctivity, double *time, int M, double decay_rate)
{
    double sigma = 0;
    double true_time = 0;
    double *diff_rad = (double*)calloc(M, sizeof(double));

    for (int i = 0; i < M; i++)
    {
        true_time = 1 - time[i]/decay_rate;
        diff_rad[i] = fabs(radioctivity[i] - true_time);
    }

    double average_diff = 0;
    double sum_for_average = 0;

    for (int i = 0; i < M; i++)
    {
        sum_for_average += diff_rad[i];
    }

    average_diff = sum_for_average / M;

    double S = 0;

    for (int i = 0; i < M; i++)
    {
        S += (average_diff - diff_rad[i]) * (average_diff - diff_rad[i]);
    }

    sigma = sqrt(S/M);

    free(diff_rad);
    return sigma;
}