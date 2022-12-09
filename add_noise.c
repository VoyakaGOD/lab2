// #include <math.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

void add_noise (double *radioactivity, int N)
{
    srand (time (NULL));

    for (int i = 0; i < N; i++)
    {
        double random_value = (double)rand()/RAND_MAX*2.0-1.0;
        radioactivity[i] = radioactivity[i] + random_value * 0.05;
    }
}
