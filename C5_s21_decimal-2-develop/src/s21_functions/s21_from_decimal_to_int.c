//
// Created by lifefire1 on 03.01.24.
//
#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int status =
      S21_OK;  // Предположим, что S21_OK определено где-то в вашем коде
  int scale = get_scale(
      src);  // Используем функцию s21_get_scale из вашего заголовочного файла

  if (scale <= 28 && scale >= 0) {
    while (scale != 0) {
      decrement_scale(&src);
      scale--;
    }
    int src_sign = s21_get_sign(src);
    if ((src.bits[1] == 0 && src.bits[2] == 0) &&
        ((src.bits[0] <= 2147483647 && !src_sign) ||
         (src.bits[0] <= 2147483648 && src_sign))) {
      *dst = (int)src.bits[0];
      *dst /= (int)pow(
          10,
          get_scale(src));  // Используем s21_get_scale для получения масштаба
      if (s21_get_sign(src)) {
        *dst *= -1;
      }
      status = 0;
    }
  } else {
    *dst = 0;
    status = 1;
  }
  return status;
}

// int main(){
//     s21_decimal dec = {{0xFFFFFFFF, 0x000003E7, 0x00000000, 0x00030000}};
//     int res = 0;
//     s21_from_decimal_to_int(dec, &res);
//     printf("%d\n", res);
//     return 0;
// }