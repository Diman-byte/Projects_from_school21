//
// Created by lifefire1 on 01.02.24.
//
#include "../s21_decimal.h"

s21_decimal decimal_mul_10(s21_decimal *value) {
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal tmp = {{0, 0, 0, 0}};
  s21_decimal_cpy(&result, *value);
  s21_decimal_cpy(&tmp, *value);
  s21_left_shift_decimal(value, 3, &tmp);
  s21_left_shift_decimal(&result, 1, &result);
  s21_add(result, tmp, &result);
  return result;
}