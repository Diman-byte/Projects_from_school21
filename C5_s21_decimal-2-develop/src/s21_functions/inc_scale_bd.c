//
// Created by lifefire1 on 03.02.24.
//

#include "../s21_decimal.h"

void mul_10_bd(s21_big_decimal *value) {
  s21_big_decimal first_var = {{0, 0, 0, 0, 0, 0}, 0, 0};
  s21_big_decimal second_var = {{0, 0, 0, 0, 0, 0}, 0, 0};

  left_shift_count_times_big_decimal(*value, 3, &first_var);
  left_shift_count_times_big_decimal(*value, 1, &second_var);

  add_big_decimal(first_var, second_var, value);
}

void inc_scal_bd(s21_big_decimal *value) {
  mul_10_bd(value);
  value->scale = value->scale + 1;
}