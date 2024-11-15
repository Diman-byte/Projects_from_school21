#include <stdio.h>

int divide(int a, int b);  // delenie
int res(int a, int b);     // ostatok
int max_prime(int n);      // poisk max delitelya

int main(void) {
    int a;
    char ch;
    int check = scanf("%d", &a);
    if (check != 1) {
        printf("n/a");
        return 0;
    }
    ch = getchar();
    if (ch != ' ' && ch != '\n') {
        printf("n/a");
        return 0;
    }
    if (a == 1) {
        printf("n/a");
        return 0;
    } else {
        printf("%d", max_prime(a));
        return 0;
    }
}

int divide(int a, int b) {
    int k = 0;
    while (a >= b) {
        a -= b;
        k++;
    }
    return k;
}

int res(int a, int b) {
    while (a >= b) {
        a -= b;
    }
    return a;
}

int max_prime(int n) {
    int d = 2;
    while (n > 1) {
        if (res(n, d) == 0) {
            n = divide(n, d);
        } else {
            d++;
        }
    }
    return d;
}