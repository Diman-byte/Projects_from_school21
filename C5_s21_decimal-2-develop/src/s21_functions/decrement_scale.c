//
// Created by lifefire1 on 02.02.24.
//

#include "../s21_decimal.h"

// void div10_dec(s21_decimal *value) {
//   s21_decimal tmp1, tmp2, tmp3;
//   s21_decimal tmp4 = {{6, 0, 0, 0}};
//   set_scale(&tmp4, get_scale(*value));
//   s21_right_shift_decimal(value, 1, &tmp1);
//   s21_right_shift_decimal(value, 2, &tmp2);
//   s21_add(tmp1, tmp2, &tmp1);
//   s21_right_shift_decimal(&tmp1, 4, &tmp2);
//   s21_add(tmp1, tmp2, &tmp1);
//   s21_right_shift_decimal(&tmp1, 8, &tmp2);
//   s21_add(tmp1, tmp2, &tmp1);
//   s21_right_shift_decimal(&tmp1, 16, &tmp2);
//   s21_add(tmp1, tmp2, &tmp1);
//   s21_right_shift_decimal(&tmp1, 32, &tmp2);
//   s21_add(tmp1, tmp2, &tmp1);
//   s21_right_shift_decimal(&tmp1, 64, &tmp2);
//   s21_add(tmp1, tmp2, &tmp1);
//   s21_right_shift_decimal(&tmp1, 3, &tmp1);
//   s21_left_shift_decimal(&tmp1, 3, &tmp2);
//   s21_left_shift_decimal(&tmp1, 1, &tmp3);
//   s21_add(tmp2, tmp3, &tmp2);
//   s21_sub(*value, tmp2, &tmp2);  // q = tmp1 r = tmp2
//   s21_add(tmp2, tmp4, &tmp2);
//   s21_right_shift_decimal(&tmp2, 4, &tmp2);
//   s21_add(tmp1, tmp2, value);
// }

void decrement_scale(s21_decimal *dec) {
  int flag = s21_get_sign(*dec);
  if (flag) {
    s21_set_sign(0, dec);
  }
  s21_big_decimal tmp = s21_from_decimal_to_big_decimal(*dec);
  decimal_div_10(&tmp);
  from_big_decimal_to_decimal(dec, tmp);
  set_scale(dec, get_scale(*dec) - 1);
  s21_set_sign(flag, dec);
}
