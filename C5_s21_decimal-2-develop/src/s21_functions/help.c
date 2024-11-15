//
// Created by lifefire1 on 05.02.24.
//

#include "../s21_decimal.h"

void set_array_from_dec(s21_decimal dec, int *result) {
  int fract[96] = {-1};
  for (int i = 0; i < 96; i++) fract[i] = get_bit(dec.bits[i / 32], i % 32);
  int s[29] = {0};
  s[0] = 1;
  for (int i = 0; i < 96; i++) {
    if (fract[i]) {
      int vu = 0;
      for (int j = 0; j < 29; j++) {
        result[j] += s[j];
        result[j] += vu;
        if (result[j] > 9) {
          vu = 1;
          result[j] -= 10;
        } else {
          vu = 0;
        }
      }
    }
    int vu = 0;
    for (int j = 0; j < 29; j++) {
      s[j] *= 2;
      s[j] += vu;
      if (s[j] > 9) {
        vu = 1;
        s[j] -= 10;
      } else {
        vu = 0;
      }
    }
  }
}

void s21_dec_to_string(s21_decimal dec, char *str) {
  char *c = str;
  if (s21_get_sign(dec)) {
    *c = '-';
    c++;
  }
  int ex = (int)get_scale(dec);
  int array_of_int[29] = {0};
  set_array_from_dec(dec, array_of_int);
  int flag = 0;
  for (int j = 28; j >= 0; j--) {
    if (flag || array_of_int[j] || j == ex) {
      *c = (char)(array_of_int[j]) + 48;
      c++;
      flag = 1;
      if (j == ex && j) {
        *c = '.';
        c++;
      }
    }
  }
  if (*str == '-' && c == str + 1 && *c == '0') {
    *str = 0;
    c = str + 1;
  }
  *c = '\0';
}