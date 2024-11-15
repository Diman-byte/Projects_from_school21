/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10

void input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
    int n, data[NMAX];

    int number, numbers[NMAX];

    input(data, &n);
    if (n == -1) {
        printf("n/a");
        return 0;
    }
    number = sum_numbers(data, n);
    printf("%d\n", number);
    int ind = find_numbers(data, n, number, numbers);

    output(numbers, ind);

    return 0;
}

void input(int *buffer, int *length) {
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
    if (sum_numbers(buffer, *length) == 0) {
        *length = -1;
    }
}

void output(int *buffer, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", buffer[i]);
    }
    printf("\n");
}
/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum = sum + buffer[i];
        }
    }
    return sum;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int length, int number, int *numbers) {
    int ind = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0) {
            if (number % buffer[i] == 0) {
                numbers[ind] = buffer[i];
                ind++;
            }
        }
    }
    return ind;
}
