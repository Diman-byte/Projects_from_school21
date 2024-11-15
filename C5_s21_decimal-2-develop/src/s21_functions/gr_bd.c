//
// Created by lifefire1 on 03.02.24.
//

#include "../s21_decimal.h"

int gr_bd(s21_big_decimal bd1, s21_big_decimal bd2) {
  set_max_scale_big_decimal(&bd1, &bd2);

  if (bd1.sign != bd2.sign) {
    return bd1.sign < bd2.sign;  // Если знаки разные, вернуть 1, если у bd2
                                 // знак отрицательный, иначе 0
  }

  for (int i = 5; i >= 0; i--) {
    if (bd1.bits[i] != bd2.bits[i]) {
      return (bd1.sign == 1) ? (bd1.bits[i] < bd2.bits[i])
                             : (bd1.bits[i] > bd2.bits[i]);
      // Если знак положительный, вернуть 1, если bd1 < bd2, иначе 0
      // Если знак отрицательный, вернуть 1, если bd1 > bd2, иначе 0
    }
  }

  return 0;  // Если все биты равны
}