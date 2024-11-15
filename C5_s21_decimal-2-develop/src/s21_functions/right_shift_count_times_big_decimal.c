//
// Created by lifefire1 on 02.02.24.
//

#include "../s21_decimal.h"

int shift_right_big_decimal(s21_big_decimal *value) {
  int error = 0;
  int first_bit = 0;
  int first_bit_prev = 0;
  for (int i = 5; i > -1; i--) {
    first_bit = get_bit(value->bits[i], 0);
    value->bits[i] = value->bits[i] >> 1;
    set_bit(&value->bits[i], first_bit_prev, 31);
    first_bit_prev = first_bit;
  }
  error = first_bit_prev;
  return error;
}

void right_shift_count_times_big_decimal(s21_big_decimal value, int shift,
                                         s21_big_decimal *result) {
  for (int i = 0; i < shift; ++i) {
    shift_right_big_decimal(&value);  // Выполняем сдвиг вправо shift раз
  }
  *result = value;  // Сохраняем результат в переменную result
}
