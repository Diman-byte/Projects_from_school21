//
// Created by lifefire1 on 03.02.24.
//

#include "../s21_decimal.h"

int gr_bd_abs(const s21_big_decimal bd1, const s21_big_decimal bd2) {
  s21_big_decimal abs_bd1 = bd1;
  s21_big_decimal abs_bd2 = bd2;

  abs_bd1.sign = 0;
  abs_bd2.sign = 0;

  return gr_bd(abs_bd1, abs_bd2);
}