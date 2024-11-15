#include "../data_libs/data_io.h"
#include "decision.h"

#define NMAX 1000

int main() {
    int n;

    int check1 = scanf("%d", &n);
    if (check1 != 1 || n > NMAX || n <= 0) {
        printf("n/a");
        return 0;
    }

    double data[n];

    int check2 = input(data, n);
    if (check2 == -1) {
        printf("n/a");
        return 0;
    }

    if (make_decision(data, n))
        printf("YES");
    else
        printf("NO");

    return 0;
}
