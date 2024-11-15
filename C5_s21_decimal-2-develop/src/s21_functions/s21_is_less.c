//
// Created by lifefire1 on 04.02.24.
//

#include "../s21_decimal.h"

int s21_is_zero(s21_decimal value) {
  for (int i = 0; i < 3; i++) {
    if (value.bits[i] != 0) {
      return 0;  // Не ноль
    }
  }
  return 1;  // Ноль
}

int s21_is_less(s21_decimal value1, s21_decimal value2) {
  int res = 0;
  int prov = 0;

  //Если оба числа 0
  if (s21_is_zero(value1) && s21_is_zero(value2)) {
    res = 0;
    prov = 1;
  }

  int sign1 = s21_get_sign(value1);
  int sign2 = s21_get_sign(value2);
  if (sign1 > sign2 && prov != 1) res = 1;
  if (sign1 < sign2 && prov != 1) {
    res = 0;
    prov = 1;
  }

  //Приведение к общему скейлу

  int scale1 = get_scale(value1);
  int scale2 = get_scale(value2);
  if (scale1 > scale2 && res != 1 && prov != 1)
    set_decimal_scale(&value2, scale1);
  if (scale1 < scale2 && res != 1 && prov != 1)
    set_decimal_scale(&value1, scale2);

  if (sign1 && sign2) {
    for (int i = 2; i >= 0 && prov == 0 && res != 1; i--) {
      if (value1.bits[i] > value2.bits[i]) res = 1;
      if (value1.bits[i] < value2.bits[i]) {
        res = 0;
        prov = 1;
      }
    }
  }

  if (!sign1 && !sign2) {
    for (int i = 2; i >= 0 && prov == 0 && res != 1; i--) {
      if (value1.bits[i] < value2.bits[i]) res = 1;
      if (value1.bits[i] > value2.bits[i]) {
        res = 0;
        prov = 1;
      }
    }
  }
  return res;
}