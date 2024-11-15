//
// Created by lifefire1 on 02.02.24.
//

#include "../s21_decimal.h"

void set_decimal_scale(s21_decimal *value, int scale) {
  int diff = scale - get_scale(*value);

  if (diff > 0) {
    for (int i = 0; i < diff; ++i) {
      *value = decimal_mul_10(value);
    }
  }
}