#include <stdio.h>
#define NMAX 10

void input(int *buffer, int *length, int *c);
void output(int *buffer, int length);
void engine(int *buffer, int length, int c);

int main() {
    int n, c, data[NMAX];

    input(data, &n, &c);
    if (n == -1) {
        printf("n/a");
        return 0;
    }

    engine(data, n, c);

    output(data, n);

    return 0;
}

void input(int *buffer, int *length, int *c) {
    int check1 = scanf("%d", length);
    if (*length <= 0) {
        *length = -1;
    }
    if (check1 != 1) {
        *length = -1;
    }
    if (*length > NMAX) {
        *length = -1;
    }
    for (int *p = buffer; p - buffer < *length; p++) {
        int check2 = scanf("%d", p);
        if (check2 != 1) {
            *length = -1;
        }
    }
    if (*length >= 0) {
        int check2 = scanf("%d", c);
        if (check2 != 1) {
            *length = -1;
        }
    }
}

void output(int *buffer, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", buffer[i]);
    }
    printf("\n");
}

void engine(int *buffer, int length, int c) {
    if (c > 0) {
        for (int i = 0; i < c; i++) {
            int temp = buffer[0];
            for (int j = 0; j < length; j++) {
                buffer[j] = buffer[j + 1];
            }
            buffer[length - 1] = temp;
        }
    } else {
        c = -c;
        for (int i = 0; i < c; i++) {
            int temp = buffer[length - 1];
            for (int j = length - 1; j >= 0; j--) {
                buffer[j] = buffer[j - 1];
            }
            buffer[0] = temp;
        }
    }
}
