#include <check.h>
#include <string.h>

#include "../s21_test.h"

START_TEST(test1_strlen) {
  const char *src = "world!";
  ck_assert_int_eq(strlen(src), s21_strlen(src));
}

START_TEST(test2_strlen) {
  const char *src = "world\0";
  ck_assert_int_eq(strlen(src), s21_strlen(src));
}

START_TEST(test3_strlen) {
  const char *src = " ";
  ck_assert_int_eq(strlen(src), s21_strlen(src));
}

START_TEST(test4_strlen) {
  const char *src = "$";
  ck_assert_int_eq(strlen(src), s21_strlen(src));
}

START_TEST(test5_strlen) {
  const char *src = "\0";
  ck_assert_int_eq(strlen(src), s21_strlen(src));
}

Suite *test_strlen() {
  Suite *suite = suite_create("strlen");
  TCase *tcase = tcase_create("strlen_tcase");

  tcase_add_test(tcase, test1_strlen);
  tcase_add_test(tcase, test2_strlen);
  tcase_add_test(tcase, test3_strlen);
  tcase_add_test(tcase, test4_strlen);
  tcase_add_test(tcase, test5_strlen);

  suite_add_tcase(suite, tcase);
  return suite;
}
