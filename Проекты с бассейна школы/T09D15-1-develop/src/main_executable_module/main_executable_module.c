
#ifdef DYNYMIC_LIBRARY

#endif
#include "../data_libs/data_io.h"
#include "../data_libs/data_stat.h"
#include "../data_module/data_process.h"
#include "../yet_another_decision_module/decision.h"
#include "sort.h"

#define NMAX 1000

int main() {
    int n;

    int check1 = scanf("%d", &n);
    if (check1 != 1 || n > NMAX || n <= 0) {
        printf("n/a");
        return 0;
    }

    double data[n];

    printf("LOAD DATA...\n");
    int check2 = input(data, n);
    if (check2 == -1) {
        printf("n/a");
        return 0;
    }

    printf("RAW DATA:\n\t");
    output(data, n);

    printf("\nNORMALIZED DATA:\n\t");
    if (normalization(data, n))
        output(data, n);
    else
        printf("ERROR");

    printf("\nSORTED NORMALIZED DATA:\n\t");
    quickSort(data, n);
    output(data, n);

    printf("\nFINAL DECISION:\n\t");
    if (make_decision(data, n))
        printf("YES");
    else
        printf("NO");

    return 0;
}
