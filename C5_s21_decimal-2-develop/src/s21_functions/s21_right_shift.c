//
// Created by lifefire1 on 01.02.24.
//

#include "../s21_decimal.h"

int s21_right_shift_decimal(s21_decimal *src, int shift, s21_decimal *dst) {
  int error = 0;
  while (shift != 0) {
    int last_bit = 0;
    int last_bit_prev = 0;
    for (int i = 2; i >= 0; i--) {
      last_bit = s21_get_bit(i * 32, src);
      src->bits[i] = src->bits[i] >> 1;
      s21_set_bit(last_bit_prev, (i + 1) * 32 - 1, src);
      last_bit_prev = last_bit;
    }
    shift--;
  }
  s21_decimal_cpy(dst, *src);
  // error = last_bit_prev;
  return error;
}
