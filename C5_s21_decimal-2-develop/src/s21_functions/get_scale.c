//
// Created by lifefire1 on 01.02.24.
//
#include "../s21_decimal.h"

int get_scale(s21_decimal value) {
  int mask = 0b11111111;  // Маска для последних 8 бит
  mask = mask << 16;      // Сдвигаем маску на 16 бит
  int scale = (value.bits[3] & mask) >>
              16;  // Применяем маску и сдвигаем результат обратно на 16 бит
  if (scale > 28) {
    return -1;
  }
  return scale;
}