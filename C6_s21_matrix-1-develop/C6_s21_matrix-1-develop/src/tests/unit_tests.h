
#ifndef UNIT_TESTS_H
#define UNIT_TESTS_H

#include <check.h>

#include "../s21_matrix.h"

#define OK 0
#define INCORRECT_MATRIX 1
#define CALCULATION_ERROR 2

void s21_suit_execution(Suite *suite, int *failed_count, char *suite_name);

#endif