//
// Created by lifefire1 on 01.02.24.
//
#include "../s21_decimal.h"

s21_big_decimal s21_from_decimal_to_big_decimal(s21_decimal src) {
  // Создаем новую структуру для большого десятичного числа
  s21_big_decimal bigDecimal;

  // Копируем первые два слова (32 бита) из исходного числа в большое десятичное
  // число
  for (int i = 0; i < 3; ++i) {
    bigDecimal.bits[i] = src.bits[i];
  }

  // Заполняем оставшиеся слова (96 бит) нулями
  for (int i = 3; i < 6; ++i) {
    bigDecimal.bits[i] = 0;
  }

  // Устанавливаем знак и масштаб для большого десятичного числа
  bigDecimal.sign = s21_get_sign(src);
  bigDecimal.scale = get_scale(src);

  return bigDecimal;  // Возвращаем созданное большое десятичное число
}
