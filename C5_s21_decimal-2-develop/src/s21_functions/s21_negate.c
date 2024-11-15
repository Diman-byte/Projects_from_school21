//
// Created by lifefire1 on 07.01.24.
//
#include "../s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int status = S21_OK;
  s21_decimal_cpy(result, value);
  s21_set_sign(!s21_get_sign(value), result);
  return status;
}