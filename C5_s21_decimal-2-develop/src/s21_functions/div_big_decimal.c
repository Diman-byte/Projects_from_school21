//
// Created by lifefire1 on 02.02.24.
//

#include "../s21_decimal.h"

int div_big_decimal(s21_big_decimal number1, s21_big_decimal number2,
                    s21_big_decimal *res) {
  int error = 0;
  for (int i = 0; i < 192; i++) {
    // Создаем временные переменные для умножения и сдвига
    s21_big_decimal tmp1 = {{1, 0, 0, 0, 0, 0}, 0, 0};
    s21_big_decimal tmp = number2;

    // Сдвигаем второе число на i позиций влево
    left_shift_count_times_big_decimal(tmp, i, &tmp);

    // Проверяем, равно ли измененное число первого числа
    int comparison_result = big_decimal_geq(tmp, number1);
    if (comparison_result == 2) {
      // Если больше или равно, добавляем tmp1 к результату и завершаем цикл
      left_shift_count_times_big_decimal(tmp1, i, &tmp1);
      add_big_decimal(*res, tmp1, res);
      break;
    } else if (comparison_result == 1) {
      // Если меньше, уменьшаем i на 1 и выполняем дополнительные операции
      right_shift_count_times_big_decimal(tmp, 1, &tmp);
      left_shift_count_times_big_decimal(tmp1, i - 1, &tmp1);
      add_big_decimal(*res, tmp1, res);
      sub_big_decimal(number1, tmp, &number1);
      if (i) {
        i = 192;
      } else
        i = 0;
    }
  }
  return error;
}
