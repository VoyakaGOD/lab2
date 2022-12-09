#include "mega_include.h"

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


    //int N = experiment(double *radioactivity, double *time, start_time, end_time, step);

    fclose(file);
}