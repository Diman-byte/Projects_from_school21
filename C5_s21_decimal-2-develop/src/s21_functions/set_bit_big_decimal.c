//
// Created by lifefire1 on 02.02.24.
//

#include "../s21_decimal.h"

int set_bit_big_decimal(int bit, int bit_number, s21_big_decimal *decimal) {
  int status = S21_OK;
  int real_number_bit = bit_number % 32;
  int bits_number = bit_number / 32;
  int mask = 1 << real_number_bit;

  if (bit == 1) {
    decimal->bits[bits_number] |= mask;
  } else {
    mask = ~mask;
    decimal->bits[bits_number] &= mask;
  }
  return status;
}
