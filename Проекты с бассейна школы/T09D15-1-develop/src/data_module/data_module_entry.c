#include "../data_libs/data_io.h"
#include "data_process.h"

#define NMAX 1000

int main() {
    int n;

    int check1 = scanf("%d", &n);
    if (check1 != 1) {
        printf("n/a");
        return 0;
    }

    if (n > NMAX) {
        printf("n/a");
        return 0;
    }

    if (n <= 0) {
        printf("n/a");
        return 0;
    }

    double data[n];
    // Don`t forget to allocate memory !

    int check2 = input(data, n);
    if (check2 == -1) {
        printf("n/a");
        return 0;
    }

    if (normalization(data, n))
        output(data, n);
    else
        printf("ERROR");

    return 0;
}
