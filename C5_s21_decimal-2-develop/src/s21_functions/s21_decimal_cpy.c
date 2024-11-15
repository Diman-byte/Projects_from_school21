//
// Created by lifefire1 on 05.01.24.
//

#include "../s21_decimal.h"

int s21_decimal_cpy(s21_decimal *dst, s21_decimal src) {
  dst->bits[0] = src.bits[0];
  dst->bits[1] = src.bits[1];
  dst->bits[2] = src.bits[2];
  dst->bits[3] = src.bits[3];
  return S21_OK;
}