// #include <math.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

int experiment (double *radioactivity, double *time, double start_time, double end_time, double step) 
{
    int N = 1;
    double beta = 0;
    printf ("\nEnter beta-constant: ");
    scanf ("%lf", &beta);
    time[0] = start_time;
    radioactivity[0] = pow (exp(1), -time[0] / beta);

    for (int i = 1; i <= 100 && time[i - 1] <= end_time; i++)
    {
        time[i] = time[i-1] + step;
        radioactivity[i] = pow (exp(1), -time[i] / beta);
        N++;
    }

    return N;
}