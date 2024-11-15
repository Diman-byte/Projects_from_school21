//
// Created by lifefire1 on 01.02.24.
//

#include "../s21_decimal.h"

void decimal_div_10(s21_big_decimal *value) {
  int sign = 0;
  if (value->sign) {
    sign = 1;
    value->sign = 0;
  }
  s21_big_decimal tmp1 = {{0, 0, 0, 0, 0, 0}, value->scale, 0},
                  tmp2 = {{0, 0, 0, 0, 0, 0}, value->scale, 0},
                  tmp3 = {{0, 0, 0, 0, 0, 0}, value->scale, 0};
  s21_big_decimal tmp4 = {{6, 0, 0, 0, 0, 0}, value->scale, 0};
  right_shift_count_times_big_decimal(*value, 1, &tmp1);
  //    printf_big_decimal("1) value",*value);
  //    printf_big_decimal("2) tmp1",tmp1);
  right_shift_count_times_big_decimal(*value, 2, &tmp2);
  //    printf_big_decimal("3) value",*value);
  //    printf_big_decimal("4) tmp2",tmp2);
  add_big_decimal(tmp1, tmp2, &tmp1);
  //    printf_big_decimal("5) tmp1",tmp1);
  //    printf_big_decimal("6) tmp2",tmp2);
  // q = (n >> 1) + (n >> 2);
  right_shift_count_times_big_decimal(tmp1, 4, &tmp2);
  //    printf_big_decimal("7) tmp1",tmp1);
  //    printf_big_decimal("8) tmp2",tmp2);
  add_big_decimal(tmp1, tmp2, &tmp1);
  //    printf_big_decimal("9) tmp1",tmp1);
  //    printf_big_decimal("10) tmp2",tmp2);
  //  q = q + (q >> 4);
  right_shift_count_times_big_decimal(tmp1, 8, &tmp2);
  //    printf_big_decimal("11) tmp1",tmp1);
  //    printf_big_decimal("12) tmp2",tmp2);
  add_big_decimal(tmp1, tmp2, &tmp1);
  //    printf_big_decimal("13) tmp1",tmp1);
  //    printf_big_decimal("14) tmp2",tmp2);
  right_shift_count_times_big_decimal(tmp1, 16, &tmp2);
  //    printf_big_decimal("15) tmp1",tmp1);
  //    printf_big_decimal("15) tmp2",tmp2);
  add_big_decimal(tmp1, tmp2, &tmp1);
  //    printf_big_decimal("17) tmp1",tmp1);
  //    printf_big_decimal("18) tmp2",tmp2);
  right_shift_count_times_big_decimal(tmp1, 32, &tmp2);
  //    printf_big_decimal("19) tmp1",tmp1);
  //    printf_big_decimal("20) tmp2",tmp2);
  add_big_decimal(tmp1, tmp2, &tmp1);
  //    printf_big_decimal("21) tmp1",tmp1);
  //    printf_big_decimal("22) tmp2",tmp2);
  right_shift_count_times_big_decimal(tmp1, 64, &tmp2);
  //    printf_big_decimal("23) tmp1",tmp1);
  //    printf_big_decimal("24) tmp2",tmp2);
  add_big_decimal(tmp1, tmp2, &tmp1);
  //    printf_big_decimal("25) tmp11",tmp1);
  //    printf_big_decimal("26) tmp2",tmp2);
  right_shift_count_times_big_decimal(tmp1, 128, &tmp2);
  //    printf_big_decimal("27) tmp1",tmp1);
  //    printf_big_decimal("28) tmp2",tmp2);
  add_big_decimal(tmp1, tmp2, &tmp1);
  //    printf_big_decimal("29) tmp1",tmp1);
  //    printf_big_decimal("30) tmp2",tmp2);
  // q = q + (q >> 16);
  right_shift_count_times_big_decimal(tmp1, 3, &tmp1);
  // q = q >> 3;
  left_shift_count_times_big_decimal(tmp1, 3, &tmp2);
  left_shift_count_times_big_decimal(tmp1, 1, &tmp3);
  add_big_decimal(tmp2, tmp3, &tmp2);
  // q * 10
  sub_big_decimal(*value, tmp2, &tmp2);
  // n - q * 10;
  add_big_decimal(tmp2, tmp4, &tmp2);
  // (r + 6)
  right_shift_count_times_big_decimal(tmp2, 4, &tmp2);
  //(r + 6) >> 4;
  add_big_decimal(tmp1, tmp2, value);
  // q + ((r + 6) >> 4)
  value->sign = sign;
}

// int main() {
//   s21_big_decimal decimal = {{0b110010, 0, 0, 0, 0, 0}, 2, 0};
//   decimal_div_10(&decimal);
//   printf_big_decimal("res ", decimal);
//   return 0;
// }