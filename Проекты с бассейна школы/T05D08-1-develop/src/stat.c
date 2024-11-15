#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == -1) {
        printf("n/a\n");
        return 0;
    }

    output(data, n);
    output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));

    return 0;
}

int input(int *a, int *n) {
    int check1 = scanf("%d", n);
    if (*n <= 0) {
        return -1;
    }
    if (check1 != 1) {
        return -1;
    }

    if (*n > NMAX) {
        return -1;
    }

    for (int *p = a; p - a < *n; p++) {
        int check2 = scanf("%d", p);
        if (check2 != 1) {
            return -1;
        }
    }
    return 0;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int max(int *a, int n) {
    int max = a[0];
    for (int i = 0; i < n; i++) {
        if (max < a[i]) {
            max = a[i];
        }
    }
    return max;
}

int min(int *a, int n) {
    int min = a[0];
    for (int i = 0; i < n; i++) {
        if (min > a[i]) {
            min = a[i];
        }
    }
    return min;
}

double mean(int *a, int n) {
    double res;
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    res = sum / n;
    return res;
}

double variance(int *a, int n) {
    double res;
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (a[i] - mean(a, n)) * (a[i] - mean(a, n));
    }

    res = sum / n;
    return res;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6lf %.6lf\n", max_v, min_v, mean_v, variance_v);
}
