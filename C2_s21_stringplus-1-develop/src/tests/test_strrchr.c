#include <check.h>
#include <string.h>

#include "../s21_test.h"

START_TEST(strrchr_test_1) {
  char test_str[] = "The examples string for test";
  ck_assert_pstr_eq(strrchr(test_str, 's'), s21_strrchr(test_str, 's'));
}
END_TEST

START_TEST(strrchr_test_2) {
  char test_str[] = "The examples string for test";
  ck_assert_pstr_eq(strrchr(test_str, 'o'), s21_strrchr(test_str, 'o'));
}
END_TEST

START_TEST(strrchr_test_3) {
  char test_str[] = "The examples string for test";
  ck_assert_pstr_eq(strrchr(test_str, 'n'), s21_strrchr(test_str, 'n'));
}
END_TEST

START_TEST(strrchr_test_4) {
  char test_str[] = "";
  ck_assert_pstr_eq(strrchr(test_str, 'n'), s21_strrchr(test_str, 'n'));
}
END_TEST

START_TEST(strrchr_test_5) {
  char test_str[] = "aaaaaaaana";
  ck_assert_pstr_eq(strrchr(test_str, 'a'), s21_strrchr(test_str, 'a'));
}
END_TEST

START_TEST(strrchr_test_6) {
  char test_str[] = "1234567";
  ck_assert_pstr_eq(strrchr(test_str, '3'), s21_strrchr(test_str, '3'));
}
END_TEST

START_TEST(strrchr_test_7) {
  char test_str[] = "1234567";
  ck_assert_pstr_eq(strrchr(test_str, '-'), s21_strrchr(test_str, '-'));
}
END_TEST

Suite *test_strrchr() {
  Suite *stirng_test_suite;
  TCase *tc_strtchr;

  stirng_test_suite = suite_create("strrchr_func");

  tc_strtchr = tcase_create("base_strrchr_test");

  tcase_add_test(tc_strtchr, strrchr_test_1);
  tcase_add_test(tc_strtchr, strrchr_test_2);
  tcase_add_test(tc_strtchr, strrchr_test_3);
  tcase_add_test(tc_strtchr, strrchr_test_4);
  tcase_add_test(tc_strtchr, strrchr_test_5);
  tcase_add_test(tc_strtchr, strrchr_test_6);
  tcase_add_test(tc_strtchr, strrchr_test_7);

  suite_add_tcase(stirng_test_suite, tc_strtchr);

  return stirng_test_suite;
}
