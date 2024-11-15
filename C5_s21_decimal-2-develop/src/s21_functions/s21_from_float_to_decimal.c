//
// Created by lifefire1 on 03.02.24.
//

#include "../s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int res = 0;
  memset(dst, 0,
         sizeof(s21_decimal));  // Очищаем dst перед установкой нового значения

  if (src < 0) {
    src *= -1;
    s21_set_sign(1, dst);  // Устанавливаем отрицательный знак
  }

  // Проверяем, является ли src целым числом
  if (src == floorf(src)) {
    res = s21_from_int_to_decimal((int)src, dst);
  } else {
    unsigned int k = 0;
    int scale = 0;
    char str[100];
    int dot = 0;
    int r = 7;
    sprintf(str, "%.7f", src);  // Используем формат "%.7f" для управления
                                // количеством знаков после запятой
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
      if (str[i] == '.') dot = i;
      if (str[i] != '.' && r > 0) {
        k += (str[i] - '0') *
             pow(10, r);  // Используем символьное значение вместо ASCII кода
        r--;
      }
    }

    scale = 8 - dot;
    r = scale;

    for (int i = 0; i <= scale; i++) {
      if (k % 10 == 0) {
        r--;
        k /= 10;
      }
    }

    scale = r;
    set_scale(dst, scale);  // Устанавливаем масштаб
    dst->bits[0] = k;       // Устанавливаем значение
  }

  return res;
}