//
// Created by lifefire1 on 02.02.24.
//

#include "../s21_decimal.h"

#define BITS_COUNT 192

void sub_big_decimal(const s21_big_decimal value_1,
                     const s21_big_decimal value_2, s21_big_decimal *result) {
  s21_big_decimal temp_1 = value_1;
  s21_big_decimal temp_2 = value_2;

  int last_bit_set = 0;

  if (temp_1.sign == temp_2.sign) {
    for (int i = BITS_COUNT - 1; i >= 0; i--) {
      int bit_1 = get_bit_big_decimal(i, &temp_1);
      int bit_2 = get_bit_big_decimal(i, &temp_2);

      if (bit_1) last_bit_set = i;

      if (bit_1 == bit_2)
        set_bit_big_decimal(0, i, result);
      else if (bit_1 > bit_2)
        set_bit_big_decimal(1, i, result);
      else {
        while (get_bit_big_decimal(last_bit_set, result) == 0 &&
               last_bit_set < BITS_COUNT - 1)
          last_bit_set++;
        set_bit_big_decimal(0, last_bit_set, result);
        for (int p = last_bit_set - 1; p >= i; p--)
          set_bit_big_decimal(1, p, result);
        last_bit_set = i;
      }
    }
  }
  result->scale = value_1.scale;
}
