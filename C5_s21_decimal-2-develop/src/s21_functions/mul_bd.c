//
// Created by lifefire1 on 03.02.24.
//

#include "../s21_decimal.h"

void mul_bd(s21_big_decimal number1, s21_big_decimal number2,
            s21_big_decimal *result) {
  for (int i = 0; i < 192; ++i) {
    s21_big_decimal tmp = number2;
    int bit = get_bit_big_decimal(i, &number1);
    if (bit) {
      left_shift_count_times_big_decimal(tmp, i, &tmp);
      add_big_decimal(*result, tmp, result);
    }
  }
}