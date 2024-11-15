#include <check.h>
#include <string.h>

#include "../s21_test.h"

START_TEST(test_memchr_1) {
  char str[] = "Never gonna give you up";
  int ch = ' ';
  size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(test_memchr_2) {
  char str[] = "Never gonna give you up";
  int ch = '5';
  size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(test_memchr_3) {
  char str[] = "Never gonna give you up";
  int ch = 'c';
  size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(test_memchr_4) {
  char str[] = "Never gonna give you up";
  int ch = 'N';
  size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(test_memchr_5) {
  char str[] = "Never gonna give you up";
  int ch = 'y';
  size_t len = 17;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(test_memchr_6) {
  char str[] = "Never gonna give you up";
  int ch = 'g';
  size_t len = -5;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(test_memchr_7) {
  char str[] = "435785675";
  int ch = '0';
  size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(test_memchr_8) {
  char str[] = "435785675";
  int ch = '4';
  size_t len = 0;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(test_memchr_9) {
  char str[] = "435785675";
  int ch = 'g';
  size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(test_memchr_10) {
  char str[] = "435785675";
  int ch = '\0';
  size_t len = 9;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}

START_TEST(test_memchr_11) {
  char str[] = "Hello";
  int ch = 'e';
  size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}

START_TEST(test_memchr_12) {
  char str[] = "Hello";
  int ch = 'a';
  size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}

START_TEST(test_memchr_13) {
  char str[] = "";
  int ch = 'a';
  size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}

START_TEST(test_memchr_14) {
  char str[] = "";
  int ch = '\0';
  size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}

Suite *test_memchr() {
  Suite *suite = suite_create("memchr");
  TCase *tcase = tcase_create("memchr_tcase");

  tcase_add_test(tcase, test_memchr_1);
  tcase_add_test(tcase, test_memchr_2);
  tcase_add_test(tcase, test_memchr_3);
  tcase_add_test(tcase, test_memchr_4);
  tcase_add_test(tcase, test_memchr_5);
  tcase_add_test(tcase, test_memchr_6);
  tcase_add_test(tcase, test_memchr_7);
  tcase_add_test(tcase, test_memchr_8);
  tcase_add_test(tcase, test_memchr_9);
  tcase_add_test(tcase, test_memchr_10);
  tcase_add_test(tcase, test_memchr_11);
  tcase_add_test(tcase, test_memchr_12);
  tcase_add_test(tcase, test_memchr_13);
  tcase_add_test(tcase, test_memchr_14);

  suite_add_tcase(suite, tcase);
  return suite;
}
