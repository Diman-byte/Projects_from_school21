#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];

    if (input(data, &n) == -1) {
        printf("n/a\n");
        return 0;
    }

    squaring(data, n);
    output(data, n);

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
    for (int *p = a; p - a < n; p++) {
        printf("%d ", *p);
    }
}

void squaring(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        *p *= *p;
    }
}
