#include <check.h>
#include <float.h>
#include <stdio.h>

#include "../s21_decimal.h"

START_TEST(test) {
  float input_array[] = {-12784.01, 0.00125, -0.001, 30, 0.000001, 123456.1};

  FILE *fp = fopen("s21_tests/s21_from_float.txt", "r");
  if (fp) {
    char str_original[1024];
    char str_s21[1024];

    for (int i = 0; i < 6; i++) {
      fgets(str_original, sizeof(str_original), fp);
      if (i != 5) {
        str_original[strlen(str_original) - 1] = '\0';
      }
      s21_decimal output = {0};
      s21_from_float_to_decimal(input_array[i], &output);
      s21_dec_to_string(output, str_s21);

      ck_assert_str_eq(str_s21, str_original);
    }
    fclose(fp);
  }
}
END_TEST

Suite *suite_from_float_to_decimal(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_from_float_to_decimal");
  tc = tcase_create("s21_from_float_to_decimal");

  if (s != NULL && tc != NULL) {
    tcase_add_test(tc, test);
    // tcase_add_test(tc, error_test);
    suite_add_tcase(s, tc);
  }

  return (s);
}

static int run_test_suite(Suite *test_suite) {
  int number_failed = 0;
  SRunner *sr = NULL;

  sr = srunner_create(test_suite);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed);
}

int main(void) {
  int number_failed = 0;
  number_failed += run_test_suite(suite_from_float_to_decimal());
  return (number_failed ? EXIT_FAILURE : EXIT_SUCCESS);
}
