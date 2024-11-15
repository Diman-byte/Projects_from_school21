#include "../s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int status = 0;                      // Статус операции
  memset(result, 0, sizeof(*result));  // Обнуляем результат

  // Создаем структуры для хранения больших чисел
  s21_big_decimal bd1 = {{0}, 0, 0};
  s21_big_decimal bd2 = {{0}, 0, 0};
  s21_big_decimal res_bd = {{0}, 0, 0};

  // Преобразуем десятичные числа в большие десятичные числа
  bd1 = s21_from_decimal_to_big_decimal(value_1);
  bd2 = s21_from_decimal_to_big_decimal(value_2);

  // Выбираем максимальный масштаб
  set_max_scale_big_decimal(&bd1, &bd2);

  int sign_1 = bd1.sign;  // Знак первого числа
  int sign_2 = bd2.sign;  // Знак второго числа

  if (sign_1 == sign_2) {  // Если знаки чисел равны
    add_big_decimal(bd1, bd2, &res_bd);  // Складываем числа
    res_bd.sign = bd1.sign;  // Присваиваем результату знак первого числа
  } else {
    if (gr_bd_abs(bd1, bd2)) {  // Если первое число по модулю больше второго
      res_bd.sign = bd1.sign;  // Присваиваем результату знак первого числа
      bd1.sign = 0;
      bd2.sign = 0;
      sub_big_decimal(bd1, bd2, &res_bd);  // Вычитаем второе число из первого
    } else if (eq_bd_abs(bd1, bd2)) {  // Если числа по модулю равны
      bd1.scale = bd2.scale;  // Присваиваем результату масштаб первого числа
    } else {
      res_bd.sign = bd2.sign;  // Присваиваем результату знак второго числа
      bd1.sign = 0;
      bd2.sign = 0;
      sub_big_decimal(bd2, bd1, &res_bd);  // Вычитаем первое число из второго
    }
  }
  res_bd.scale = bd1.scale;  // Присваиваем результату масштаб первого числа
  status = from_big_decimal_to_decimal(
      result, res_bd);  // Преобразуем результат в десятичное число

  return status;  // Возвращаем статус операции
}
