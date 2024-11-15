#include <check.h>
#include <string.h>

#include "../s21_test.h"
/*
START_TEST(test_memset_1) {
  char str1[] = "Never gonna give you up";
  char str2[] = "Never gonna give you up";
  int ch = ' ';
  size_t len = strlen(str1);
  ck_assert_mem_eq(memset(str1, ch, len), s21_memset(str2, ch, len), len);
}
END_TEST

START_TEST(test_memset_2) {
  char str1[] = "Never gonna give you up";
  char str2[] = "Never gonna give you up";
  int ch = ' ';
  size_t len = 5;
  ck_assert_mem_eq(memset(str1, ch, len), s21_memset(str2, ch, len), len);
}
END_TEST

START_TEST(test_memset_3) {
  char str1[] = "Never gonna give you up";
  char str2[] = "Never gonna give you up";
  int ch = ' ';
  size_t len = 0;
  ck_assert_mem_eq(memset(str1, ch, len), s21_memset(str2, ch, len), len);
}
END_TEST

START_TEST(test_memset_4) {
  char str1[] = "";
  char str2[] = "";
  int ch = '\0';
  size_t len = 0;
  ck_assert_mem_eq(memset(str1, ch, len), s21_memset(str2, ch, len), len);
}
END_TEST

START_TEST(test_memset_5) {
  char str1[] = "Never";
  char str2[] = "Never";
  int ch = '\0';
  size_t len = 4;
  ck_assert_mem_eq(memset(str1, ch, len), s21_memset(str2, ch, len), len);
}
END_TEST

START_TEST(test_memset_6) {
  char str1[] = "Never gonna give you up";
  char str2[] = "Never gonna give you up";
  int ch = 80;
  size_t len = 7;
  ck_assert_mem_eq(memset(str1, ch, len), s21_memset(str2, ch, len), len);
}
END_TEST
*/

START_TEST(test_memset_1) {
  char str1[] = "Hello";
  char str2[] = "Hello";
  s21_size_t len = strlen(str1);
  int ch = ' ';
  ck_assert_mem_eq(memset(str1, ch, len), s21_memset(str2, ch, len), len);
}
END_TEST

START_TEST(test_memset_2) {
  char str1[] = "Hello";
  char str2[] = "Hello";
  s21_size_t len = strlen(str1);
  int ch = 0;
  ck_assert_mem_eq(memset(str1, ch, len), s21_memset(str2, ch, len), len);
}
END_TEST

START_TEST(test_memset_3) {
  char str1[] = "Hello";
  char str2[] = "Hello";
  s21_size_t len = strlen(str1);
  int ch = 'c';
  ck_assert_mem_eq(memset(str1, ch, len), s21_memset(str2, ch, len), len);
}
END_TEST

START_TEST(test_memset_4) {
  char str1[] = "Hello";
  char str2[] = "Hello";
  s21_size_t len = 2;
  int ch = 'c';
  ck_assert_mem_eq(memset(str1 + 1, ch, len), s21_memset(str2 + 1, ch, len),
                   len);
}
END_TEST

START_TEST(test_memset_5) {
  char str1[] = "";
  char str2[] = "";
  s21_size_t len = strlen(str1);
  int ch = 'c';
  ck_assert_mem_eq(memset(str1, ch, len), s21_memset(str2, ch, len), len);
}
END_TEST

START_TEST(test_memset_6) {
  char str1[] = "Never gonna give you up";
  char str2[] = "Never gonna give you up";
  s21_size_t len = strlen(str1) / 2;
  int ch = '1';
  ck_assert_mem_eq(memset(str1, ch, len), s21_memset(str2, ch, len), len * 2);
}
END_TEST

START_TEST(test_memset_7) {
  char str1[] = "Never gonna give you up";
  char str2[] = "Never gonna give you up";
  s21_size_t len = strlen(str1);
  int ch = 2;
  ck_assert_mem_eq(memset(str1, ch, 5), s21_memset(str2, ch, 5), len);
}
END_TEST

Suite *test_memset() {
  Suite *suite = suite_create("memset");
  TCase *tcase = tcase_create("memset_tcase");

  tcase_add_test(tcase, test_memset_1);
  tcase_add_test(tcase, test_memset_2);
  tcase_add_test(tcase, test_memset_3);
  tcase_add_test(tcase, test_memset_4);
  tcase_add_test(tcase, test_memset_5);
  tcase_add_test(tcase, test_memset_6);
  tcase_add_test(tcase, test_memset_7);

  suite_add_tcase(suite, tcase);
  return suite;
}
