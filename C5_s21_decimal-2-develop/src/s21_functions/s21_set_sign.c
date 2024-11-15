//
// Created by lifefire1 on 07.01.24.
//
#include "../s21_decimal.h"

int s21_set_sign(int sign, s21_decimal *decimal) {
  int status = S21_OK;
  s21_set_bit(sign, 127, decimal);
  return status;
}