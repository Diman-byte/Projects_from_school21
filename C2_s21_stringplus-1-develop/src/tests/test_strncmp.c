#include <check.h>
#include <string.h>

#include "../s21_test.h"

START_TEST(test1_strncmp) {
  const char *qwe = "Teststring1";
  const char *ewq = "Teststring2";
  ck_assert_int_eq(strncmp(qwe, ewq, 10), s21_strncmp(qwe, ewq, 10));
}

START_TEST(test2_strncmp) {
  const char *qwe = "1234567";
  const char *ewq = "1234567";
  ck_assert_int_eq(strncmp(qwe, ewq, 7), s21_strncmp(qwe, ewq, 7));
}

START_TEST(test3_strncmp) {
  const char *qwe = "Hell0 man";
  const char *ewq = "Hell0 man";
  ck_assert_int_eq(strncmp(qwe, ewq, 9), s21_strncmp(qwe, ewq, 9));
}

START_TEST(test4_strncmp) {
  const char *qwe = "Hell0 man";
  const char *ewq = "Hell0 man";
  ck_assert_int_eq(strncmp(qwe, ewq, 4), s21_strncmp(qwe, ewq, 4));
}

START_TEST(test5_strncmp) {
  const char *qwe = "";
  const char *ewq = "";
  ck_assert_int_eq(strncmp(qwe, ewq, 1), s21_strncmp(qwe, ewq, 1));
}

START_TEST(test6_strncmp) {
  const char *qwe = "abcde";
  const char *ewq = "abc";
  ck_assert_int_eq(strncmp(qwe, ewq, 3), s21_strncmp(qwe, ewq, 3));
}

START_TEST(test7_strncmp) {
  const char *qwe = "abcde";
  const char *ewq = "abc";
  ck_assert_int_eq(strncmp(qwe, ewq, 4), s21_strncmp(qwe, ewq, 4));
}

Suite *test_strncmp() {
  Suite *suite = suite_create("strncmp");
  TCase *tcase = tcase_create("strncmp_tcase");

  tcase_add_test(tcase, test1_strncmp);
  tcase_add_test(tcase, test2_strncmp);
  tcase_add_test(tcase, test3_strncmp);
  tcase_add_test(tcase, test4_strncmp);
  tcase_add_test(tcase, test5_strncmp);
  tcase_add_test(tcase, test6_strncmp);
  tcase_add_test(tcase, test7_strncmp);

  suite_add_tcase(suite, tcase);
  return suite;
}
