#include <check.h>
#include <string.h>

#include "../s21_test.h"

START_TEST(test1_strncat) {
  char dest[20] = "Hello ";
  const char src[7] = "world!";
  size_t n = s21_strlen(src);
  ck_assert_str_eq(strncat(dest, src, n), s21_strncat(dest, src, n));
}

START_TEST(test2_strncat) {
  char dest[20] = "";
  const char src[7] = "world!";
  size_t n = s21_strlen(src);
  ck_assert_str_eq(strncat(dest, src, n), s21_strncat(dest, src, n));
}

START_TEST(test3_strncat) {
  char dest[20] = "\0";
  const char src[7] = "world!";
  size_t n = s21_strlen(src);
  ck_assert_str_eq(strncat(dest, src, n), s21_strncat(dest, src, n));
}

START_TEST(test4_strncat) {
  char dest[20] = "Hello, world!";
  const char src[5] = "\0!";
  size_t n = s21_strlen(src);
  ck_assert_str_eq(strncat(dest, src, n), s21_strncat(dest, src, n));
}
END_TEST

START_TEST(test5_strncat) {
  char dest[50] = "\0Hello, world!\0\0";
  const char *src = "My name is s21";
  size_t n = s21_strlen(src);
  ck_assert_str_eq(strncat(dest, src, n), s21_strncat(dest, src, n));
}
END_TEST

START_TEST(test6_strncat) {
  char dest[10] = "";
  const char *src = "";
  size_t n = s21_strlen(src);
  ck_assert_str_eq(strncat(dest, src, n), s21_strncat(dest, src, n));
}
END_TEST

START_TEST(test7_strncat) {
  char dest[10] = "Word 21";
  const char *src = "";
  size_t n = s21_strlen(src);
  ck_assert_str_eq(strncat(dest, src, n), s21_strncat(dest, src, n));
}
END_TEST

START_TEST(test8_strncat) {
  char dest[20] = "12345";
  const char *src = "12345";
  size_t n = s21_strlen(src);
  ck_assert_str_eq(strncat(dest, src, n), s21_strncat(dest, src, n));
}
END_TEST

START_TEST(test9_strncat) {
  char dest[80] = "Here w0 are123\0";
  const char *src = "Here w0 are123\0";
  size_t n = s21_strlen(src);
  ck_assert_str_eq(strncat(dest, src, n), s21_strncat(dest, src, n));
}
END_TEST

START_TEST(test10_strncat) {
  char dest[20] = "a\n\0";
  const char *src = "a\n\0";
  // size_t n = s21_strlen(src);
  ck_assert_str_eq(strncat(dest, src, 4), s21_strncat(dest, src, 4));
}
END_TEST

Suite *test_strncat() {
  Suite *suite = suite_create("strncat");
  TCase *tcase = tcase_create("strncat_tcase");

  tcase_add_test(tcase, test1_strncat);
  tcase_add_test(tcase, test2_strncat);
  tcase_add_test(tcase, test3_strncat);
  tcase_add_test(tcase, test4_strncat);
  tcase_add_test(tcase, test5_strncat);
  tcase_add_test(tcase, test6_strncat);
  tcase_add_test(tcase, test7_strncat);
  tcase_add_test(tcase, test8_strncat);
  tcase_add_test(tcase, test9_strncat);
  tcase_add_test(tcase, test10_strncat);

  suite_add_tcase(suite, tcase);
  return suite;
}
