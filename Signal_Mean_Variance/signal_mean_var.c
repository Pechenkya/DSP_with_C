#include <stdio.h>
#include <math.h>

#define SIG_LENGTH 320
extern double InputSignal_f32_1kHz_15kHz[SIG_LENGTH];

double sig_mean(double* sig_arr, int sig_len) {
    double _sum = 0;
    for(int i = 0; i < sig_len; ++i) {
        _sum += sig_arr[i];
    }
    double _mean = _sum / (double)sig_len;

    return _mean;
}

double sig_variance(double* sig_arr, double mean, int sig_len) {
    double _sqr_diff_sum = 0;

    for(int i = 0; i < sig_len; ++i) {
        _sqr_diff_sum += pow(sig_arr[i] - mean, 2);
    }

    double _var = _sqr_diff_sum / (double)(sig_len - 1);

    return _var;
}

double sig_std_deviation(double variance) {
    double _std_dev = sqrt(variance);

    return _std_dev;
}

int main(void) {
    double mean = sig_mean(InputSignal_f32_1kHz_15kHz, SIG_LENGTH);

    printf("Mean: %f\n", mean);

    double var = sig_variance(InputSignal_f32_1kHz_15kHz, mean, SIG_LENGTH);

    printf("Variance: %f\n", var);

    double std_dev = sig_std_deviation(var);

    printf("Std deviation: %f\n", std_dev);

    return 0;
}