//
// Created by lifefire1 on 03.02.24.
//

#include "../s21_decimal.h"

void set_max_scale_big_decimal(s21_big_decimal *number1,
                               s21_big_decimal *number2) {
  // Получаем масштабы чисел
  int scale1 = number1->scale;
  int scale2 = number2->scale;

  // Вычисляем разницу в масштабах
  int difference = abs(scale1 - scale2);

  // Определяем число с меньшим масштабом
  s21_big_decimal *min_bd = (scale1 > scale2) ? number2 : number1;

  // Увеличиваем масштаб числа с меньшим масштабом на разницу в масштабах
  for (int i = 0; i < difference; ++i) {
    inc_scal_bd(min_bd);
  }
}
