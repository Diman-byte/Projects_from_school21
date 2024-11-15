//
// Created by lifefire1 on 02.01.24.
//

#ifndef C5_S21_DECIMAL_1_S21_DECIMAL_H
#define C5_S21_DECIMAL_1_S21_DECIMAL_H
#define S21_OK 0
#define S21_TO_BIG_OR_INF 1
#define S21_TO_SMALL_OR_NEG_INF 2
#define S21_DIVIDE_BY_ZERO 3

#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[6];
  unsigned int scale;
  unsigned int sign;
} s21_big_decimal;

int gr_bd_abs(s21_big_decimal bd1, s21_big_decimal bd2);
int s21_get_bit(int number, s21_decimal *decimal);
int s21_set_bit(int bit, int bit_number, s21_decimal *decimal);
void s21_print_bits(s21_decimal decimal);
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_left_shift_decimal(s21_decimal *src, int shift, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_decimal_cpy(s21_decimal *dst, s21_decimal src);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_get_sign(s21_decimal decimal);
int s21_set_sign(int sign, s21_decimal *decimal);
s21_decimal decimal_mul_10(s21_decimal *value);
void decimal_div_10(s21_big_decimal *value);
int s21_right_shift_decimal(s21_decimal *src, int shift, s21_decimal *dst);
int get_bit_big_decimal(int number, s21_big_decimal *decimal);
void print_big_decimal(s21_big_decimal decimal);
void left_shift_count_times_big_decimal(s21_big_decimal value, int shift,
                                        s21_big_decimal *result);
void right_shift_count_times_big_decimal(s21_big_decimal value, int shift,
                                         s21_big_decimal *result);

void add_big_decimal(s21_big_decimal value_1, s21_big_decimal value_2,
                     s21_big_decimal *result);

void sub_big_decimal(s21_big_decimal value_1, s21_big_decimal value_2,
                     s21_big_decimal *result);
int set_bit_big_decimal(int bit, int bit_number, s21_big_decimal *decimal);
int get_scale(s21_decimal value);
int set_scale(s21_decimal *value, int scale);
s21_big_decimal s21_from_decimal_to_big_decimal(s21_decimal src);
void printf_decimal(char *title, s21_decimal value);
void div10_dec(s21_decimal *value);
int big_decimal_geq(s21_big_decimal number1, s21_big_decimal number2);
void mul_10_bd(s21_big_decimal *value);
void inc_scal_bd(s21_big_decimal *value);
void set_max_scale_big_decimal(s21_big_decimal *number1,
                               s21_big_decimal *number2);
int gr_bd(s21_big_decimal bd1, s21_big_decimal bd2);
void decrement_scale(s21_decimal *dec);
void bd_mod_10(s21_big_decimal *bd);
void decrement_scale_bd(s21_big_decimal *bd);
s21_decimal decimal_mod_10(s21_decimal *number);
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int from_big_decimal_to_decimal(s21_decimal *dst, s21_big_decimal src);
int eq_bd_abs(s21_big_decimal bd1, s21_big_decimal bd2);
void mul_bd(s21_big_decimal number1, s21_big_decimal number2,
            s21_big_decimal *result);
int div_big_decimal(s21_big_decimal number1, s21_big_decimal number2,
                    s21_big_decimal *res);
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int get_bit(unsigned int value, int index);
void set_bit(unsigned int *value, int set_value, int index);
int s21_is_less(s21_decimal value1, s21_decimal value2);
void set_decimal_scale(s21_decimal *value, int scale);
int s21_is_less_or_equal(s21_decimal value1, s21_decimal value2);
int s21_is_greater(s21_decimal value1, s21_decimal value2);
int s21_is_greater_or_equal(s21_decimal value1, s21_decimal value2);
int s21_is_not_equal(s21_decimal value1, s21_decimal value2);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
void set_array_from_dec(s21_decimal dec, int *result);
void s21_dec_to_string(s21_decimal dec, char *str);
s21_decimal tmp_mod10(s21_decimal value);
int s21_is_zero(s21_decimal value);
#endif  // C5_S21_DECIMAL_1_S21_DECIMAL_H
