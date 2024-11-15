#include "sort.h"

void quickSort(double *a, int size) {
    int i = 0;
    int j = size - 1;
    double mid = a[size / 2];
    do {
        while (a[i] < mid) {
            i++;
        }
        while (a[j] > mid) {
            j--;
        }
        if (i <= j) {
            double temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0) {
        quickSort(a, j + 1);
    }
    if (i < size) {
        quickSort(&a[i], size - i);
    }
}
