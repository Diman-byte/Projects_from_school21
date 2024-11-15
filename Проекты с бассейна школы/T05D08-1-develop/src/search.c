#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);
int search(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == -1) {
        printf("n/a");
        return 0;
    }

    printf("%d", search(data, n));

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

int search(int *a, int n) {
    int res;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0 && a[i] >= mean(a, n) && (a[i] <= mean(a, n) + 3 * sqrt(variance(a, n))) &&
            a[i] != 0) {
            res = a[i];
            return res;
        }
    }
    return 0;
}

/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/
