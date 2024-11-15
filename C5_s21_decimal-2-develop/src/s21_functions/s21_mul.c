#include "../s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int result_scale = get_scale(value_1) + get_scale(value_2);
  set_scale(&value_1, 0);
  set_scale(&value_2, 0);
  int sign_flag = 0;
  int status = 0;
  for (int i = 0; i < 4; ++i) {
    result->bits[i] = 0;
  }
  int sign1 = s21_get_sign(value_1);
  int sign2 = s21_get_sign(value_2);
  if (sign1 != sign2) {
    sign_flag = 1;
  }
  s21_set_sign(0, &value_1);
  s21_set_sign(0, &value_2);
  s21_big_decimal tmp1 = s21_from_decimal_to_big_decimal(value_1);
  s21_big_decimal tmp2 = s21_from_decimal_to_big_decimal(value_2);
  s21_big_decimal res_tmp = s21_from_decimal_to_big_decimal(*result);
  mul_bd(tmp1, tmp2, &res_tmp);
  res_tmp.scale = result_scale;
  res_tmp.sign = sign_flag;
  status = from_big_decimal_to_decimal(result, res_tmp);
  s21_set_sign(sign_flag, result);
  return status;
}
