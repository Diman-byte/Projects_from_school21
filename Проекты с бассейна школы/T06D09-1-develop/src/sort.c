#include <stdio.h>
#define NMAX 10

int input(int *a);
void output(int *a);
void bubblesort(int *a);

int main() {
    int data[NMAX];
    if (input(data) == -1) {
        printf("n/a");
        return 0;
    }

    bubblesort(data);
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

void bubblesort(int *a) {
    int n = NMAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
