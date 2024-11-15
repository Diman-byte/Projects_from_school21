//
// Created by lifefire1 on 03.02.24.
//

#include "../s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int status = 0;
  int sign = s21_get_sign(src);

  if (dst) {
    double var = 0.0;

    for (int i = 0; i < 96; ++i) {  // пройти по всем битам
      if (s21_get_bit(i, &src) != 0) {
        var += pow(2, i);
      }
    }

    int scale = get_scale(
        src);  // Используем функцию s21_get_scale из вашего заголовочного файла

    if (scale > 0) {
      for (int i = scale; i > 0; --i) {
        var /= 10.0;
      }
    }

    *dst = (float)var;

    if (sign) {
      *dst = -(*dst);
    }

    status = 0;
  } else {
    status = 1;
  }

  return status;
}
