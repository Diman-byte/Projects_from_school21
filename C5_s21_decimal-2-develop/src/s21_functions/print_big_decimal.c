//
// Created by lifefire1 on 02.02.24.
//
#include "../s21_decimal.h"

void print_big_decimal(s21_big_decimal decimal) {
  for (int i = 192; i > -1; --i) {
    printf("%d", get_bit_big_decimal(i, &decimal));
  }
  printf("\n");
}