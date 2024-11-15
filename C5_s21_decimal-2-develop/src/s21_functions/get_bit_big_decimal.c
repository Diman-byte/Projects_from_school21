//
// Created by lifefire1 on 02.02.24.
//

#include "../s21_decimal.h"

int get_bit_big_decimal(int number, s21_big_decimal *decimal) {
  int real_number_bit = number % 32;
  int bits_number = number / 32;
  int mask = 1u << real_number_bit;
  int bit = decimal->bits[bits_number] & mask;
  return bit != 0 ? 1 : 0;
}