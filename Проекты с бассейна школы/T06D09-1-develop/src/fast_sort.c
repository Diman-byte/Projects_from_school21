#include <stdio.h>
#define NMAX 10

int input(int *a);
void output(int *a);
void quickSort(int *a, int size);

int main() {
    int data[NMAX];
    int size = NMAX;
    if (input(data) == -1) {
        printf("n/a");
        return 0;
    }
    quickSort(data, size);
    output(data);
    quickSort(data, size);
    output(data);

    return 0;
}

int input(int *a) {
    int n = NMAX;
    for (int *p = a; p - a < n; p++) {
        int check2 = scanf("%d", p);
        if (check2 != 1) {
            return -1;
        }
    }
    return 0;
}

void output(int *a) {
    int n = NMAX;
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void quickSort(int *a, int size) {
    int i = 0;
    int j = size - 1;
    int mid = a[size / 2];
    do {
        while (a[i] < mid) {
            i++;
        }
        while (a[j] > mid) {
            j--;
        }
        if (i <= j) {
            int temp = a[i];
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
