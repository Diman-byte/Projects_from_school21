#include <check.h>
#include <string.h>

#include "../s21_test.h"

START_TEST(memcmp_test_1) {
  char test_arr_1[] = "This tutorial should be exercised on the host system";
  char test_arr_2[] = "This tutorial should be exercised on the host system";

  int res_original = memcmp(test_arr_1, test_arr_2, strlen(test_arr_1));
  int res_s21 = s21_memcmp(test_arr_1, test_arr_2, strlen(test_arr_1));

  ck_assert_int_eq(res_original, res_s21);
}
END_TEST

START_TEST(memcmp_test_2) {
  char test_arr_1[] = "This tutorial should be exercised on the host system";
  char test_arr_2[] = "This tutorial should be exercised";

  int res_original = memcmp(test_arr_1, test_arr_2, strlen(test_arr_1));
  int res_s21 = s21_memcmp(test_arr_1, test_arr_2, strlen(test_arr_1));

  ck_assert_int_eq(res_original, res_s21);
}
END_TEST

START_TEST(memcmp_test_3) {
  int test_arr_1[] = {1, 2, 3, 4, 5};
  int test_arr_2[] = {1, 2, 3, 4, 5};

  int res_original = memcmp(test_arr_1, test_arr_2, 5);
  int res_s21 = s21_memcmp(test_arr_1, test_arr_2, 5);

  ck_assert_int_eq(res_original, res_s21);
}
END_TEST

START_TEST(memcmp_test_4) {
  int test_arr_1[] = {1, 2, 3, 4, 5};
  int test_arr_2[] = {1, 2, 8, 4, 5};

  int res_original = memcmp(test_arr_1, test_arr_2, 5);
  int res_s21 = s21_memcmp(test_arr_1, test_arr_2, 5);

  ck_assert_int_eq(res_original, res_s21);
}
END_TEST

START_TEST(memcmp_test_5) {
  int test_arr_1[] = {1, 2, 3, 4, 5};
  int test_arr_2[] = {1, 2, 3};

  int res_original = memcmp(test_arr_1, test_arr_2, 5);
  int res_s21 = s21_memcmp(test_arr_1, test_arr_2, 5);

  ck_assert_int_eq(res_original, res_s21);
}
END_TEST

Suite *test_memcmp() {
  Suite *memcmp_suite;

  TCase *tc_memcmp_case;

  memcmp_suite = suite_create("memcmp_test_suite");

  tc_memcmp_case = tcase_create("base_memcmp_case");

  tcase_add_test(tc_memcmp_case, memcmp_test_1);
  tcase_add_test(tc_memcmp_case, memcmp_test_2);
  tcase_add_test(tc_memcmp_case, memcmp_test_3);
  tcase_add_test(tc_memcmp_case, memcmp_test_4);
  tcase_add_test(tc_memcmp_case, memcmp_test_5);

  suite_add_tcase(memcmp_suite, tc_memcmp_case);

  return memcmp_suite;
}
