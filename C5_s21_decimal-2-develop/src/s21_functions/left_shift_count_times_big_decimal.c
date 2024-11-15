//
// Created by lifefire1 on 02.02.24.
//

#include "../s21_decimal.h"

int get_bit(unsigned int value, int index) {
  index = 1 << index;
  if ((value & index) > 0)
    index = 1;
  else
    index = 0;
  return index;
}

void set_bit(unsigned int *value, int set_value, int index) {
  if (set_value) {
    index = 1 << index;
    *value = *value | index;
  } else {
    index = 1 << index;
    index = ~index;
    *value = *value & index;
  }
}

int shift_left_big_decimal(s21_big_decimal *value) {
  int error = 0;
  int last_bit = 0;
  int last_bit_prev = 0;
  for (int i = 0; i < 6; i++) {
    last_bit = get_bit(value->bits[i], 31);
    value->bits[i] = value->bits[i] << 1;
    set_bit(&value->bits[i], last_bit_prev, 0);
    last_bit_prev = last_bit;
  }
  error = last_bit_prev;
  return error;
}

void left_shift_count_times_big_decimal(s21_big_decimal value, int count,
                                        s21_big_decimal *result) {
  for (int i = 0; i < count; i++) {
    shift_left_big_decimal(&value);
  }
  *result = value;
}
