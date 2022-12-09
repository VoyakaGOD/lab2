#include "mega_include.h"

double nonlinear_equation(double *radioactivity, double *time, int N, double precision, double from, double to)
{
    double point = (from + to)/2;

    if(to - from < precision)
        return point;
    
    double point_value = model(radioactivity, time, N, point);
    double from_value = model(radioactivity, time, N, from);
    if(from_value * point_value < 0)
        return nonlinear_equation(radioactivity, time, N, precision, from, point);
    else
        return nonlinear_equation(radioactivity, time, N, precision, point, to);
}