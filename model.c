#include "mega_include.h"

double model(double *radioactivity, double *time, int N, double point) 
{
    double sum = 0;
    for(int i = 0; i < N; i++)
    {
        double _exp = exp(-time[i] / point);
        sum += time[i] * _exp *(radioactivity[i] - _exp); 
    }
    return sum;
}