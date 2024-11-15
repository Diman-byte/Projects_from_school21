//
// Created by lifefire1 on 03.02.24.
//

#include "../s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  int status = 0;
  int is_zero_flag = 0;
  s21_decimal round_helper = {{
      1,
      0,
      0,
      0,
  }};
  if (get_scale(value) > 29 || get_scale(value) < 0) {
    status = 1;
    result->bits[0] = 0;
    result->bits[1] = 0;
    result->bits[2] = 0;
    result->bits[3] = 0;
  }
  if (get_scale(value) == 0) {
    *result = value;
  }

  if (value.bits[0] == 0 && value.bits[1] == 0 && value.bits[2] == 0 &&
      status == 0 && get_scale(value) != 0) {
    is_zero_flag = 1;
    *result = value;
    set_scale(result, 0);
  }
  if (get_scale(value) != 0 && is_zero_flag == 0 && status == 0) {
    //        printf_decimal("func1 ", value);
    int scale = get_scale(value);
    for (int i = 0; i < scale - 1; ++i) {
      //            printf_decimal("func2 ", value);
      decrement_scale(&value);
    }
    if (tmp_mod10(value).bits[0] >= 5) {
      decrement_scale(&value);
      int sign = s21_get_sign(value);
      if (sign) {
        s21_sub(value, round_helper, result);
      } else {
        s21_add(value, round_helper, result);
      }
    } else {
      decrement_scale(&value);
      *result = value;
    }
  }
  return status;
}