#include "../s21_decimal.h"

void s21_print_bits(s21_decimal decimal) {
  for (int i = 95; i > -1; --i) {
    printf("%d", s21_get_bit(i, &decimal));
  }
  printf("\n");
}
