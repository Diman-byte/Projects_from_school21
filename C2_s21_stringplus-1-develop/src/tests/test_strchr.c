#include <check.h>
#include <string.h>

#include "../s21_test.h"

START_TEST(strchr_1) {
  char s[] = "Text for test strchr";
  int ch = 'e';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(strchr_2) {
  char s[] = "Text for test strchr";
  int ch = '\0';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(strchr_3) {
  char s[] = "Text for test strchr";
  int ch = 's';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(strchr_4) {
  char s[] = "Text for test strchr";
  int ch = 33;
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(strchr_5) {
  char s[] = "Text for test strchr";
  int ch = 'T';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(strchr_6) {
  char s[] = "Text for test strchr";
  int ch = 'r';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(strchr_7) {
  char s[] = "Text for test strchr";
  int ch = '0';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(strchr_8) {
  char s[] = "Never gonna give you up";
  int ch = 'X';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(strchr_9) {
  char s[] = "Never gonna give you up";
  int ch = '\n';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

Suite *test_strchr() {
  Suite *suite = suite_create("strchr");
  TCase *tcase = tcase_create("strchr_tcase");

  tcase_add_test(tcase, strchr_1);
  tcase_add_test(tcase, strchr_2);
  tcase_add_test(tcase, strchr_3);
  tcase_add_test(tcase, strchr_4);
  tcase_add_test(tcase, strchr_5);
  tcase_add_test(tcase, strchr_6);
  tcase_add_test(tcase, strchr_7);
  tcase_add_test(tcase, strchr_8);
  tcase_add_test(tcase, strchr_9);

  suite_add_tcase(suite, tcase);
  return suite;
}
