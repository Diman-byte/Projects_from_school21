//
// Created by lifefire1 on 06.01.24.
//

#include "../s21_decimal.h"

int s21_is_equal(s21_decimal value1, s21_decimal value2) {
  int isEqual = 0;
  if (s21_is_zero(value1) && s21_is_zero(value2)) {
    isEqual = 1;
  }

  int scale_1 = get_scale(value1);
  int scale_2 = get_scale(value2);
  if (scale_1 > scale_2 && isEqual != 1) {
    int diff = scale_1 - scale_2;
    s21_big_decimal tmp = s21_from_decimal_to_big_decimal(value2);
    for (int i = 0; i < diff; ++i) {
      mul_10_bd(&tmp);
    }
    from_big_decimal_to_decimal(&value2, tmp);
    set_scale(&value2, scale_1);
  }
  if (scale_1 < scale_2 && isEqual != 1) {
    int diff = scale_2 - scale_1;
    s21_big_decimal tmp = s21_from_decimal_to_big_decimal(value1);
    for (int i = 0; i < diff; ++i) {
      mul_10_bd(&tmp);
    }
    from_big_decimal_to_decimal(&value1, tmp);
    set_scale(&value1, scale_2);
  }
  if (value1.bits[3] == value2.bits[3] && value1.bits[2] == value2.bits[2] &&
      value1.bits[1] == value2.bits[1] && value1.bits[0] == value2.bits[0]) {
    isEqual = 1;
  }
  return isEqual;
}