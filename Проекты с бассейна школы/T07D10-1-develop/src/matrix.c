#include <stdio.h>
#include <stdlib.h>
#define NMAX 100

int menu();
void size(int *n, int *m, int flag);

int static_matrix_1(int a[][NMAX], int n, int m);
void print_static_matrix_1(int a[][NMAX], int n, int m);

int dynamic_matrix_2(int n, int m);
int dynamic_matrix_3(int n, int m);
int dynamic_matrix_4(int n, int m);
void print_dynamic_matrix(int **a, int n, int m);

void clear(int **a, int n);

int main() {
    int flag = menu();
    if (flag == -1) {
        printf("n/a");
        return 0;
    }
    int n, m;
    size(&n, &m, flag);
    if (n == -1) {
        printf("n/a");
        return 0;
    }
    int data1[n][m];

    switch (flag) {
        case 1:
            if (static_matrix_1(data1, n, m) == -1) {
                printf("n/a");
                return 0;
            }
            break;
        case 2:
            if (dynamic_matrix_2(n, m) == -1) {
                printf("n/a");
                return 0;
            }
            break;
        case 3:
            if (dynamic_matrix_3(n, m) == -1) {
                printf("n/a");
                return 0;
            }
            break;
        case 4:
            if (dynamic_matrix_4(n, m) == -1) {
                printf("n/a");
                return 0;
            }
            break;
    }
    return 0;
}

int menu() {
    printf("Select the type of matrix specification:\n");
    printf("1:  Static\n");
    printf("2:  Dynamic. Array of pointers to arrays\n");
    printf("3:  Dynamic. Array of pointers to segments of the second array\n");
    printf("4:  Dynamic. Array of pointers to array segments within one buffer\n");
    int flag;
    int check = scanf("%d", &flag);
    if (check != 1 || flag <= 0 || flag > 4) {
        return -1;
    }
    return flag;
}

void size(int *n, int *m, int flag) {
    int check = scanf("%d %d", n, m);
    if (flag == 1) {
        if (check != 2 || *n <= 0 || *m <= 0 || *n > 100 || *m > 100) {
            *n = -1;
        }
    } else {
        if (check != 2 || *n <= 0 || *m <= 0) {
            *n = -1;
        }
    }
}

int static_matrix_1(int a[][NMAX], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int number;
            int check1 = scanf("%d", &number);
            if (check1 != 1) {
                return -1;
            }
            a[i][j] = number;
        }
    }
    print_static_matrix_1(a, n, m);
    return 0;
}

void print_static_matrix_1(int a[][NMAX], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j == m - 1) {
                printf("%d", a[i][j]);
            } else {
                printf("%d ", a[i][j]);
            }
        }
        if (i != n - 1) {
            printf("\n");
        }
    }
}

int dynamic_matrix_2(int n, int m) {
    int **mas = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        mas[i] = (int *)malloc(m * sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int number;
            int check1 = scanf("%d", &number);
            if (check1 != 1) {
                clear(mas, n);
                return -1;
            }
            mas[i][j] = number;
        }
    }
    print_dynamic_matrix(mas, n, m);
    clear(mas, n);
    return 0;
}

int dynamic_matrix_3(int n, int m) {
    int **mas = (int **)malloc(n * sizeof(int *));
    int *val = (int *)malloc(n * m * sizeof(int));
    for (int i = 0; i < n; i++) {
        mas[i] = val + m * i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int number;
            int check1 = scanf("%d", &number);
            if (check1 != 1) {
                free(mas);
                free(val);
                return -1;
            }
            mas[i][j] = number;
        }
    }
    print_dynamic_matrix(mas, n, m);
    free(mas);
    free(val);
    return 0;
}

int dynamic_matrix_4(int n, int m) {
    int **mas = (int **)malloc(n * m * sizeof(int) + n * sizeof(int *));
    int *ptr = (int *)(mas + n);
    for (int i = 0; i < n; i++) {
        mas[i] = ptr + m * i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int number;
            int check1 = scanf("%d", &number);
            if (check1 != 1) {
                free(mas);
                return -1;
            }
            mas[i][j] = number;
        }
    }
    print_dynamic_matrix(mas, n, m);
    free(mas);
    return 0;
}

void clear(int **a, int n) {
    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
}

void print_dynamic_matrix(int **a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j == m - 1) {
                printf("%d", a[i][j]);
            } else {
                printf("%d ", a[i][j]);
            }
        }
        if (i != n - 1) {
            printf("\n");
        }
    }
}
