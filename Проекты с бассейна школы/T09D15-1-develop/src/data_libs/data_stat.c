#include "data_stat.h"

double max(const double *data, int n) {
    double max = data[0];
    for (int i = 0; i < n; i++) {
        if (max < data[i]) {
            max = data[i];
        }
    }
    return max;
}

double min(const double *data, int n) {
    double min = data[0];
    for (int i = 0; i < n; i++) {
        if (min > data[i]) {
            min = data[i];
        }
    }
    return min;
}

double mean(const double *data, int n) {
    double res;
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    res = sum / n;
    return res;
}

double variance(const double *data, int n) {
    double res;
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (data[i] - mean(data, n)) * (data[i] - mean(data, n));
    }

    res = sum / n;
    return res;
}