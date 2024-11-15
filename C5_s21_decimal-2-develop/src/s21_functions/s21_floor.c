//
// Created by lifefire1 on 03.02.24.
//
#include "../s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  int status = 0;
  int zero_count = 0;
  int check = 0;

  *result = value;  // Копируем значение

  int scale = get_scale(*result);  // Получаем масштаб с помощью s21_get_scale

  if (scale > 29) {
    // Если масштаб больше 29, устанавливаем результат в ноль и возвращаем
    // статус 1
    for (int i = 0; i < 4; ++i) {
      result->bits[i] = 0;
    }
    status = 1;
  }
  int sign_res = s21_get_sign(*result);
  // Проверка, если значение равно нулю
  if (s21_is_zero(value) && status == 0) {
    check = 1;
    set_scale(result, 0);  // Устанавливаем масштаб результата в ноль
  }

  // Обработка случая, когда знак положителен и масштаб не равен нулю
  else if (!sign_res && scale != 0 && !check && !status) {
    for (int i = 0; i < scale; ++i) {
      decrement_scale(result);  // Уменьшаем масштаб результата
    }
  }

  // Обработка случая, когда знак отрицателен и масштаб не равен нулю
  else if (sign_res && scale != 0 && !check && !status) {
    s21_decimal round_helper = {{0, 0, 0, 0}};
    s21_decimal round_helper2 = {{1, 0, 0, 0}};
    int scale_neg_dec = scale;

    for (int i = 0; i < scale_neg_dec; ++i) {
      round_helper = *result;
      if (decimal_mod_10(&round_helper).bits[0] == 0) {
        zero_count++;
      }
      decrement_scale(result);  // Уменьшаем масштаб результата
    }

    // Если количество нулей не равно масштабу значения, уменьшаем результат на
    // 1
    if (zero_count != scale) {
      round_helper = *result;
      s21_sub(round_helper, round_helper2,
              result);  // Вычитаем единицу из результата
    }
  }

  return status;
}
