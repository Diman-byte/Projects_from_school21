#include "../s21_decimal.h"

int s21_get_bit(int number, s21_decimal *decimal) {
  int real_number_bit = number % 32;
  int bits_number = number / 32;
  int mask = 1u << real_number_bit;
  int bit = decimal->bits[bits_number] & mask;
  return bit != 0 ? 1 : 0;
}
