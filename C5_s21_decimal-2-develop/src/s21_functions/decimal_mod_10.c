//
// Created by lifefire1 on 02.02.24.
//
#include "../s21_decimal.h"

s21_decimal tmp_mod10(s21_decimal value) {
  int sign = s21_get_sign(value);
  s21_set_sign(0, &value);
  s21_decimal result;
  s21_decimal_cpy(&result, value);
  set_scale(&result, get_scale(value) + 1);
  decrement_scale(&result);
  //    printf_decimal("func3 ", result);
  result = decimal_mul_10(&result);
  //    printf_decimal("func3 ", result);
  s21_sub(value, result, &result);
  s21_set_sign(sign, &value);
  return result;
}

s21_decimal decimal_mod_10(s21_decimal *number) {
  s21_decimal answer = {{0, 0, 0, 0}};
  s21_big_decimal tmp = s21_from_decimal_to_big_decimal(*number);
  bd_mod_10(&tmp);
  from_big_decimal_to_decimal(&answer, tmp);
  //  s21_sub(*number, answer, &answer);
  return answer;
}

// int main(){
//     s21_decimal dec = {0b1111011,0,0,0};
//     s21_print_bits(decimal_mod_10(&dec));
// }