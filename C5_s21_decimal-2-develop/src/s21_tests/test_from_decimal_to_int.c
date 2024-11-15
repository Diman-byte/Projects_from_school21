#include <check.h>

#include "../s21_decimal.h"
#include "limits.h"

START_TEST(error_test) {
  // Проверка возврата ошибки для недопустимого значения
  s21_decimal a = {{10, 13, 827, 30 << 16}};
  int tmp;
  int ret = s21_from_decimal_to_int(a, &tmp);
  ck_assert_int_eq(ret, 1);
}

START_TEST(test_min_max_values) {
  // Проверка для максимального значения
  s21_decimal max_value = {{0xFFFFFFFF, 0x7FFFFFFF, 0xFFFFFFFF, 0x7FFF0000}};
  int tmp;
  int ret = s21_from_decimal_to_int(max_value, &tmp);
  ck_assert_int_eq(ret, 1);
  ck_assert_int_eq(tmp, 0);

  // Проверка для минимального значения
  s21_decimal min_value = {{0xFFFFFFFF, 0x80000000, 0xFFFFFFFF, 0x80000000}};
  ret = s21_from_decimal_to_int(min_value, &tmp);
  ck_assert_int_eq(ret, 0);
  ck_assert_int_eq(tmp, 0);
}

START_TEST(test) {
  s21_decimal max_value = {{0, 0, 0, 0}};
  int tmp;
  int ret = s21_from_decimal_to_int(max_value, &tmp);
  ck_assert_int_eq(ret, 0);
  ck_assert_int_eq(tmp, 0);
}

START_TEST(test_neg) {
  s21_decimal max_value = {{0, 0, 0, 0}};
  int tmp;
  s21_set_sign(1, &max_value);
  int ret = s21_from_decimal_to_int(max_value, &tmp);
  ck_assert_int_eq(ret, 0);
  ck_assert_int_eq(tmp, 0);
}

Suite *suite_from_decimal_to_int(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_from_decimal_to_int");
  tc = tcase_create("s21_from_decimal_to_int");

  if (s != NULL && tc != NULL) {
    //        tcase_add_test(tc, test);
    tcase_add_test(tc, error_test);
    tcase_add_test(tc, test);
    tcase_add_test(tc, test_neg);
    tcase_add_test(tc, test_min_max_values);  // Добавляем новый тест
    suite_add_tcase(s, tc);
  }

  return (s);
}

static int run_test_suite(Suite *test_suite) {
  int number_failed = 0;
  SRunner *sr = NULL;

  sr = srunner_create(test_suite);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed);
}

int main(void) {
  int number_failed = 0;
  number_failed += run_test_suite(suite_from_decimal_to_int());
  return (number_failed ? EXIT_FAILURE : EXIT_SUCCESS);
}