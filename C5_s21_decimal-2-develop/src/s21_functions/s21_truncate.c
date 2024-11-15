//
// Created by lifefire1 on 03.02.24.
//

#include "../s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int status = 0;
  if (get_scale(value) > 28 || get_scale(value) < 0) {
    //    status = 1;
    result->bits[0] = 0;
    result->bits[1] = 0;
    result->bits[2] = 0;
    result->bits[3] = 0;
    return 1;
  }
  s21_set_sign(s21_get_sign(value), result);
  int scale = get_scale(value);
  if (scale == 0) {
    result->bits[0] = value.bits[0];
    result->bits[1] = value.bits[1];
    result->bits[2] = value.bits[2];
    result->bits[3] = value.bits[3];
  } else {
    for (int i = 0; i < scale; ++i) {
      decrement_scale(&value);
    }
    set_scale(&value, 0);
    result->bits[0] = value.bits[0];
    result->bits[1] = value.bits[1];
    result->bits[2] = value.bits[2];
    result->bits[3] = value.bits[3];
  }
  return status;
}