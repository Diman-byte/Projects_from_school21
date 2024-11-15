#include <check.h>
#include <string.h>

#include "../s21_test.h"

START_TEST(str_err_test) { ck_assert_str_eq(s21_strerror(_i), strerror(_i)); }
END_TEST

Suite *test_strerror() {
  Suite *s = NULL;
  TCase *tc_err = NULL;

  s = suite_create("err_suite");
  tc_err = tcase_create("err_case");

  tcase_add_loop_test(tc_err, str_err_test, -1, 135);
  suite_add_tcase(s, tc_err);

  return s;
}
