//
// Created by lifefire1 on 03.02.24.
//

#include "../s21_decimal.h"

int eq_bd_abs(s21_big_decimal bd1, s21_big_decimal bd2) {
  int status = 1;
  int flag = 0;
  set_max_scale_big_decimal(&bd1, &bd2);

  for (int i = 0; i < 6 && !flag; ++i) {
    if (bd1.bits[i] != bd2.bits[i]) {
      flag = 1;  // Если хотя бы один элемент не совпадает, возвращаем 0
      status = 0;
    }
  }

  return status;  // Если все элементы совпадают, возвращаем 1
}
