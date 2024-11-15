#include "../s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int sign = s21_get_sign(value_2);
  s21_set_sign(!sign, &value_2);
  int status = s21_add(value_1, value_2, result);
  return status;
}