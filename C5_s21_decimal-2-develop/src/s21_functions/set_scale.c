//
// Created by lifefire1 on 01.02.24.
//

#include "../s21_decimal.h"

int set_scale(s21_decimal *value, int scale) {
  int status = S21_OK;
  if (scale < 0) {
    status = S21_TO_SMALL_OR_NEG_INF;
  }
  int mask = 0b11111111 << 16;
  value->bits[3] &= ~mask;
  value->bits[3] |= (scale << 16);
  return status;
}