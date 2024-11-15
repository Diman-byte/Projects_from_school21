//
// Created by lifefire1 on 06.01.24.
//

#include "../s21_decimal.h"

int s21_get_sign(s21_decimal decimal) { return s21_get_bit(127, &decimal); }