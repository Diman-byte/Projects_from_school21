#include "../s21_decimal.h"

int s21_left_shift_decimal(s21_decimal *src, int shift, s21_decimal *dst) {
  int error = 0;
  while (shift != 0) {
    int last_bit = 0;
    int last_bit_prev = 0;
    for (int i = 0; i < 3; i++) {
      last_bit = s21_get_bit((i + 1) * 32 - 1, src);
      src->bits[i] = src->bits[i] << 1;
      s21_set_bit(last_bit_prev, i * 32, src);
      last_bit_prev = last_bit;
    }
    shift--;
  }
  s21_decimal_cpy(dst, *src);
  // error = last_bit_prev;
  return error;
}

// int main(){
//     s21_decimal dec = {0xffffffff,0xffffffff,0,0};
//     s21_decimal res = {0,0,0,0};
//     s21_print_bits(dec);
//     s21_right_shift_decimal(&dec,32,&res);
//     s21_print_bits(res);
//     return 0;
// }