#include <stdio.h>

void maxmin(int prob1, int prob2, int prob3, int *max, int *min);

/* Find a max & min probabilities */
int main(void) {
    int x, y, z;
    char ch;

    int check = scanf("%d %d %d", &x, &y, &z);

    if (check != 3) {
        printf("n/a");
        return 0;
    }

    ch = getchar();

    if (ch != ' ' && ch != '\n') {
        printf("n/a");
        return 0;
    } else {
        int max, min;

        maxmin(x, y, z, &max, &min);

        printf("%d %d", max, min);

        return 0;
    }
}

/* This function should be kept !!! (Your AI) */
/* But errors & bugs should be fixed         */
void maxmin(int prob1, int prob2, int prob3, int *max, int *min) {
    *max = *min = prob1;
    if (prob2 > *max) *max = prob2;
    if (prob2 < *min) *min = prob2;

    if (prob3 > *max) *max = prob3;
    if (prob3 < *min) *min = prob3;
}
