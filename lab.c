#include "mega_include.h"

extern double FROM;
extern double TO;

int main()
{
    FILE *file = fopen("data.txt", "r");
    double start_time = 0;
    double end_time = 0;
    double step = 0;
    double precision = 0;
    double const_betta = 0;
    double int1 = 0;
    double int2 = 0;
    fscanf(file, "%lf%lf%lf%lf%lf%lf%lf", &start_time, &end_time, &step, &precision, &const_betta, &int1, &int2);

    double *radioactivity = (double *)calloc((int)(2 * (end_time - start_time) / step), sizeof(double));
    double *time = (double *)calloc((int)(2 * (end_time - start_time) / step), sizeof(double));
    int N = experiment(radioactivity, time, start_time, end_time, step);
    add_noise(radioactivity, N);
    FROM = int1;
    TO = int2;
    double decay_time = nonlinear_equation(radioactivity, time, N, precision);
    double decate_rate = linear_equation(radioactivity, time, N);
    double time_differences = precision_analysis(radioactivity, time, N);

    printf("%lf, %lf, %lf\n", decay_time, decate_rate, time_differences);

    fclose(file);
}