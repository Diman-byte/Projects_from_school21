#include <stdio.h>
#include <stdlib.h>
#define NMAX 10

void input(int *buffer, int *length);
void output(int *buffer, int length);
void quickSort(int *a, int size);

int main() {
    int length;
    int *data = NULL;
    int check1 = scanf("%d", &length);
    if (length <= 0 || check1 != 1 || length > NMAX) {
        printf("n/a");
        return 0;
    }
    data = (int *)malloc(length * sizeof(int));
    input(data, &length);
    if (length == -1) {
        printf("n/a");
        free(data);
        return 0;
    }
    quickSort(data, length);
    output(data, length);
    free(data);
    return 0;
}

void input(int *buffer, int *length) {
    for (int *p = buffer; p - buffer < *length; p++) {
        int check2 = scanf("%d", p);
        if (check2 != 1) {
            *length = -1;
        }
    }
}

void output(int *buffer, int length) {
    for (int i = 0; i < length; i++) {
        if (i == length - 1) {
            printf("%d", buffer[i]);
        } else {
            printf("%d ", buffer[i]);
        }
    }
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