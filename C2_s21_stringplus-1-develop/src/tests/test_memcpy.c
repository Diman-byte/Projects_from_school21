#include <check.h>
#include <string.h>

#include "../s21_test.h"
/*
START_TEST(test_memcpy_1) {
  char src[] = "Never gonna give you up";
  size_t len = strlen(src);
  char dest[len], s21_dest[len];
  ck_assert_mem_eq(memcpy(dest, src, len), s21_memcpy(s21_dest, src, len), len);
}
END_TEST

START_TEST(test_memcpy_2) {
  char src[] = " ";
  size_t len = strlen(src);
  char dest[len], s21_dest[len];
  ck_assert_mem_eq(memcpy(dest, src, len), s21_memcpy(s21_dest, src, len), len);
}
END_TEST

START_TEST(test_memcpy_3) {
  char src[] = "Hello\0";
  size_t len = strlen(src);
  char dest[len], s21_dest[len];
  ck_assert_mem_eq(memcpy(dest, src, len), s21_memcpy(s21_dest, src, len), len);
}
END_TEST

START_TEST(test_memcpy_4) {
  char src[1] = "H";
  size_t len = strlen(src);
  char dest[len], s21_dest[len];
  ck_assert_mem_eq(memcpy(dest, src, len), s21_memcpy(s21_dest, src, len), len);
}
END_TEST

START_TEST(test_memcpy_5) {
  char src[] = "\n";
  size_t len = strlen(src);
  char dest[len], s21_dest[len];
  ck_assert_mem_eq(memcpy(dest, src, len), s21_memcpy(s21_dest, src, len), len);
}
END_TEST

START_TEST(test_memcpy_6) {
  char src[] = "Never gonna give you up";
  size_t len = 0;
  char dest[] = "Never", s21_dest[] = "Never";
  ck_assert_mem_eq(memcpy(dest, src, len), s21_memcpy(s21_dest, src, len), len);
}
END_TEST

START_TEST(test_memcpy_7) {
  char src[] = "435785675";
  size_t len = strlen(src);
  char dest[len], s21_dest[len];
  ck_assert_mem_eq(memcpy(dest, src, len), s21_memcpy(s21_dest, src, len), len);
}
END_TEST

START_TEST(test_memcpy_8) {
  char src[] = "435785675";
  size_t len = 0;
  char dest[len], s21_dest[len];
  ck_assert_mem_eq(memcpy(dest, src, len), s21_memcpy(s21_dest, src, len), len);
}
END_TEST

START_TEST(test_memcpy_9) {
  char src[] = "    Hello";
  size_t len = strlen(src);
  char dest[len], s21_dest[len];
  ck_assert_mem_eq(memcpy(dest, src, len), s21_memcpy(s21_dest, src, len), len);
}
END_TEST

START_TEST(test_memcpy_10) {
  char src[] = "";
  size_t len = 9;
  char dest[len], s21_dest[len];

  ck_assert_mem_eq(memcpy(dest, src, len), s21_memcpy(s21_dest, src, len), len);
}
*/

START_TEST(test_memcpy_1) {
  const char src[] = "Hello";
  s21_size_t len = strlen(src);
  char s21_dest[len], dest[len];
  ck_assert_mem_eq(memcpy(dest, src, len), s21_memcpy(s21_dest, src, len), len);
}
END_TEST

START_TEST(test_memcpy_2) {
  const char src[] = "";
  s21_size_t len = 9;
  char s21_dest[len], dest[len];
  ck_assert_mem_eq(memcpy(dest, src, len), s21_memcpy(s21_dest, src, len), len);
}
END_TEST

START_TEST(test_memcpy_3) {
  const char src[] = "Hello";
  s21_size_t len = 9;
  char s21_dest[len], dest[len];
  ck_assert_mem_eq(memcpy(dest, src, len), s21_memcpy(s21_dest, src, len), len);
}
END_TEST

START_TEST(test_memcpy_4) {
  const char src[] = " ";
  s21_size_t len = strlen(src);
  char s21_dest[len], dest[len];
  ck_assert_mem_eq(memcpy(dest, src, len), s21_memcpy(s21_dest, src, len), len);
}
END_TEST

START_TEST(test_memcpy_5) {
  int src[] = {1, 2, 3, 4, 5};
  s21_size_t len = 5;
  int s21_dest[len], dest[len];
  ck_assert_mem_eq(memcpy(dest, src, len), s21_memcpy(s21_dest, src, len), len);
}
END_TEST

START_TEST(test_memcpy_6) {
  const char src[] = "Hello\0";
  s21_size_t len = strlen(src);
  char s21_dest[len], dest[len];
  ck_assert_mem_eq(memcpy(dest, src, len), s21_memcpy(s21_dest, src, len), len);
}
END_TEST

START_TEST(test_memcpy_7) {
  char src[1] = "H";
  s21_size_t len = strlen(src);
  char s21_dest[len], dest[len];
  ck_assert_mem_eq(memcpy(dest, src, len), s21_memcpy(s21_dest, src, len), len);
}
END_TEST

START_TEST(test_memcpy_8) {
  const char src[] = "\n";
  s21_size_t len = strlen(src);
  char s21_dest[len], dest[len];
  ck_assert_mem_eq(memcpy(dest, src, len), s21_memcpy(s21_dest, src, len), len);
}
END_TEST

START_TEST(test_memcpy_9) {
  const char src[] = "Never gonna give you up";
  s21_size_t len = 0;
  char s21_dest[len], dest[len];
  ck_assert_mem_eq(memcpy(dest, src, len), s21_memcpy(s21_dest, src, len), len);
}
END_TEST

START_TEST(test_memcpy_10) {
  const char src[] = "Never gonna give you up";
  s21_size_t len = 0;
  char s21_dest[] = "Never", dest[] = "Never";
  ck_assert_mem_eq(memcpy(dest, src, len), s21_memcpy(s21_dest, src, len), len);
}
END_TEST

START_TEST(test_memcpy_11) {
  const char src[] = "Never gonna give you up";
  s21_size_t len = 0;
  char *s21_dest = S21_NULL, *dest = S21_NULL;
  ck_assert(memcpy(dest, src, len) == S21_NULL &&
            s21_memcpy(s21_dest, src, len) == S21_NULL);
}
END_TEST

Suite *test_memcpy() {
  Suite *suite = suite_create("memcpy");
  TCase *tcase = tcase_create("memcpy_tcase");

  tcase_add_test(tcase, test_memcpy_1);
  tcase_add_test(tcase, test_memcpy_2);
  tcase_add_test(tcase, test_memcpy_3);
  tcase_add_test(tcase, test_memcpy_4);
  tcase_add_test(tcase, test_memcpy_5);
  tcase_add_test(tcase, test_memcpy_6);
  tcase_add_test(tcase, test_memcpy_7);
  tcase_add_test(tcase, test_memcpy_8);
  tcase_add_test(tcase, test_memcpy_9);
  tcase_add_test(tcase, test_memcpy_10);
  tcase_add_test(tcase, test_memcpy_11);

  suite_add_tcase(suite, tcase);
  return suite;
}
