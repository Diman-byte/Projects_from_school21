#include "../s21_decimal.h"

int s21_set_bit(int bit, int bit_number, s21_decimal *decimal) {
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