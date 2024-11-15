//
// Created by lifefire1 on 02.02.24.
//

#include "../s21_decimal.h"

int big_decimal_geq(s21_big_decimal number1, s21_big_decimal number2) {
  // 0 <
  // 1 >
  // 2 ==
  int is_gr = 0;
  int is_eq = 0;
  int answer = 0;
  int stop_flag = 0;
  for (int i = 5; i > -1 && !stop_flag; --i) {
    if (number1.bits[i] > number2.bits[i]) {
      is_gr = 1;
    } else if (number1.bits[i] < number2.bits[i]) {
      is_gr = 0;
      stop_flag = 1;
    }
  }

  if (!is_gr) {
    for (int i = 5; i > -1; --i) {
      if (number1.bits[i] == number2.bits[i]) {
        is_eq++;
      }
    }
  }

  if (is_eq == 6) {
    answer = 2;
  }
  if (is_gr) {
    answer = 1;
  }
  return answer;
}

// int main(){
//     s21_big_decimal decimal = {{0b1111010,0,0,0,0,0},3,0};
//     s21_big_decimal decimal1 = {{0b1111010,0,0,0,0,0},2,0};
//     int res = big_decimal_geq(decimal,decimal1);
//     printf("%d\n", res);
//     return 0;
// }