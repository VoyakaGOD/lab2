#include "mega_include.h"

double FROM = 0;
double TO = 0;

static double ___nonlinear_equation(double *radioactivity, double *time, int N, double precision, double from, double to);

double nonlinear_equation(double *radioactivity, double *time, int N, double precision)
{
    return ___nonlinear_equation(radioactivity, time, N, precision, FROM, TO);
}

static double ___nonlinear_equation(double *radioactivity, double *time, int N, double precision, double from, double to)
{
    double point = (from + to)/2;

    if(to - from < precision)
        return point;
    
    double point_value = model(radioactivity, time, N, point);
    double from_value = model(radioactivity, time, N, from);
    if(from_value * point_value < 0)
        return ___nonlinear_equation(radioactivity, time, N, precision, from, point);
    else
        return ___nonlinear_equation(radioactivity, time, N, precision, point, to);
}