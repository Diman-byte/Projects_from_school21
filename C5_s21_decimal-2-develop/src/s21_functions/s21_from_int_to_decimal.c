//
// Created by lifefire1 on 03.02.24.
//

#include "../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int status = 0;
  // Очищаем dst перед установкой нового значения
  memset(dst, 0, sizeof(s21_decimal));

  if (src >= 0) {
    dst->bits[0] = src;
  } else {
    dst->bits[0] = -src;
    s21_set_sign(1, dst);
  }

  return status;
}