//
// Created by lifefire1 on 03.02.24.
//

#include "../s21_decimal.h"

void decrement_scale_bd(s21_big_decimal *bd) {
  s21_big_decimal proverka = {{bd->bits[0], bd->bits[1], bd->bits[2],
                               bd->bits[3], bd->bits[4], bd->bits[5]},
                              bd->scale,
                              bd->sign};
  bd_mod_10(&proverka);
  s21_big_decimal tmp = {{5, 0, 0, 0, 0, 0}, bd->scale, 0};
  if (bd->scale == 1 && proverka.bits[0] % 10 == 5 &&
      (proverka.bits[0] / 10) % 2 == 1) {
    add_big_decimal(*bd, tmp, bd);
  }
  decimal_div_10(bd);
  bd->scale -= 1;
  tmp.scale -= 1;
  tmp.bits[0] = tmp.bits[0] - 4;
  if ((!bd->bits[5] && !bd->bits[4] && !bd->bits[3]) &&
      proverka.bits[0] % (int)pow(10, proverka.scale) >
          5 * (int)pow(10, proverka.scale - 1)) {
    add_big_decimal(*bd, tmp, bd);
  }
}