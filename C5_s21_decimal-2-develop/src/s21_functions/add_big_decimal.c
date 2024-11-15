//
// Created by lifefire1 on 02.02.24.
//
#include "../s21_decimal.h"

void add_big_decimal(s21_big_decimal value_1, s21_big_decimal value_2,
                     s21_big_decimal *result) {
  int carry = 0;

  if (value_1.sign == value_2.sign) {
    for (unsigned int i = 0; i < 192; i++) {
      int sum = get_bit_big_decimal(i, &value_1) +
                get_bit_big_decimal(i, &value_2) + carry;
      set_bit_big_decimal(sum % 2, i, result);
      carry = sum / 2;
    }
  }

  result->scale = value_1.scale;
}

// int main() {
////    s21_decimal value = {0b111110100, 0, 0, 0}; // Инициализируйте ваше
///число /    s21_decimal result; // Результат деления на 10
//    s21_big_decimal value = {{0b111110100, 0b10101010, 0b000001, 0,0,0},0,0 };
//    s21_big_decimal value1 = {{0b111110100, 0b10101010, 0b000001, 0,0,0},0,0
//    }; s21_big_decimal res = {{0,0,0,0,0,0},0,0}; print_big_decimal(value);
//    print_big_decimal(value1);
//    add_big_decimal(value,value1,&res);
//    print_big_decimal(res);
//
//
//    return 0;
//}