#include <stdio.h>

int fib(int a);

int main(void) {
  int a;
  char ch;
  int check = scanf("%d", &a);
  if (check != 1) {
    printf("n/a");
    return 0;
  }
  if (a == 0) {
    printf("n/a");
    return 0;
  }
  ch = getchar();
  if (ch != ' ' && ch != '\n') {
    printf("n/a");
    return 0;
  } else {
    printf("%d", fib(a));
    return 0;
  }
}

int fib(int a) {
  if (a == 1 || a == 2) {
    return 1;
  } else {
    return fib(a - 1) + fib(a - 2);
  }
}