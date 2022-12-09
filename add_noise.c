void add_noise (double *radioactivity, int N)
{
    double random_value;

    srand (time (NULL));
    random_value = (double)rand()/RAND_MAX*2.0-1.0;

    for (int i = 0; i < N; i++)
    {
        radioactivity[i] = radioactivity[i] + random_value () * 0.05;
    }
}