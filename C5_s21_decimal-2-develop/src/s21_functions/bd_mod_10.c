//
// Created by lifefire1 on 03.02.24.
//

#include "../s21_decimal.h"

void bd_mod_10(s21_big_decimal *bd) {
  int sign = bd->sign;
  bd->sign = 0;
  s21_big_decimal tmp = *bd;

  for (unsigned i = 0; i < bd->scale + 1; ++i) {
    decimal_div_10(&tmp);
    tmp.scale = bd->scale + 1;
  }
  for (unsigned i = 0; i < bd->scale + 1; ++i) {
    inc_scal_bd(&tmp);
  }

  sub_big_decimal(*bd, tmp, bd);
  bd->sign = sign;
}

// int main(){
//     s21_big_decimal tmp = {{0b11101010,0,0,0,0,0},0,0};
//     print_big_decimal(tmp);
//     bd_mod_10(&tmp);
//     print_big_decimal(tmp);
// }