//
// Created by lifefire1 on 03.02.24.
//

#include "../s21_decimal.h"

// kill me pls

int from_big_decimal_to_decimal(s21_decimal *dst, s21_big_decimal src) {
  int status = 0;
  while (((src.bits[3] || src.bits[4] || src.bits[5]) || src.scale > 28) &&
         status == 0) {
    if (src.scale > 0) {
      decrement_scale_bd(&src);
    } else {
      if (src.sign) {
        status = 2;
      } else {
        status = 1;
      }
    }
  }

  if (status == 0) {
    dst->bits[0] = src.bits[0];
    dst->bits[1] = src.bits[1];
    dst->bits[2] = src.bits[2];
    s21_set_sign(src.sign, dst);
    set_scale(dst, src.scale);
  }
  return status;
}