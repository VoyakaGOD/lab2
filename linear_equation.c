double linear_equation (double *radioactivity, double *time, int N){
    double sigma_ch = 0;
    double sigma_zn = 0;

    for (int i = 0; i < N; i++){
        sigma_ch += time[i] * time[i];
        sigma_zn += time[i] * (1 - radioactivity[i]);
    }

    double decay_rate = sigma_ch / sigma_zn;
    return decay_rate;
}