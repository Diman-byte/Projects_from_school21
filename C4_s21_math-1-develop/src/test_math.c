#include <check.h>
#include <math.h>

#include "s21_math.h"

#define EPSILON 1e-6L

#define PART_OF_TEST(func)                                     \
  {                                                            \
    if (0 == 1) {                                              \
      printf("\n%f %f res: %Lf %f\n", i, j, s21_##func, func); \
    }                                                          \
    if (isnan(func)) {                                         \
      ck_assert(isnan(s21_##func));                            \
    } else if (isinf(func)) {                                  \
      ck_assert(s21_##func == func);                           \
    } else {                                                   \
      ck_assert(fabsl(s21_##func - func) < EPSILON);           \
    }                                                          \
  }

#define COMBINATION_BLOCK(func) \
  {                             \
    PART_OF_TEST(func)          \
    PART_OF_TEST(func)          \
    PART_OF_TEST(func)          \
    PART_OF_TEST(func)          \
  }

#define TESTS_BLOCK(func)   \
  {                         \
    j = NAN;                \
    COMBINATION_BLOCK(func) \
    j = -NAN;               \
    COMBINATION_BLOCK(func) \
    j = INF;                \
    COMBINATION_BLOCK(func) \
    j = -INF;               \
    COMBINATION_BLOCK(func) \
  }

#define INF_NAN_TESTS(func, mode)      \
  {                                    \
    double lim = 10;                   \
    double j = NAN;                    \
    double i;                          \
    double iLim = 10;                  \
    if (mode == 1) {                   \
      i = NAN;                         \
      PART_OF_TEST(func)               \
      i = -NAN;                        \
      PART_OF_TEST(func)               \
      i = INF;                         \
      PART_OF_TEST(func)               \
      i = -INF;                        \
      PART_OF_TEST(func)               \
      lim = -9.99;                     \
    } else {                           \
      i = NAN;                         \
      TESTS_BLOCK(func)                \
      i = -NAN;                        \
      TESTS_BLOCK(func)                \
      i = INF;                         \
      TESTS_BLOCK(func)                \
      i = -INF;                        \
      TESTS_BLOCK(func)                \
    }                                  \
    if (mode == 2) {                   \
      i = -1;                          \
      iLim = 1;                        \
    } else                             \
      i = -10;                         \
    for (j = -10; j < lim; j += 0.1) { \
      for (; i < iLim; i += 0.1) {     \
        PART_OF_TEST(func)             \
      }                                \
    }                                  \
  }

START_TEST(test_s21_abs) {
  for (int i = -10000; i < 10000; i += 1000) {
    ck_assert(s21_abs(i) == abs(i));
  }
}
END_TEST

START_TEST(test_s21_acos){INF_NAN_TESTS(acos(i), 2)} END_TEST

    START_TEST(test_s21_asin){INF_NAN_TESTS(asin(i), 2)} END_TEST

    START_TEST(test_s21_atan){INF_NAN_TESTS(atan(i), 1)} END_TEST

    START_TEST(test_s21_ceil){INF_NAN_TESTS(ceil(i), 1)} END_TEST

    START_TEST(test_s21_cos){INF_NAN_TESTS(cos(i), 1)} END_TEST

    START_TEST(test_s21_exp){INF_NAN_TESTS(exp(i), 1)} END_TEST

    START_TEST(test_s21_fabs){INF_NAN_TESTS(fabs(i), 1)} END_TEST

    START_TEST(test_s21_floor){INF_NAN_TESTS(floor(i), 1)} END_TEST

    START_TEST(test_s21_fmod){INF_NAN_TESTS(fmod(i, j), 0)} END_TEST

    START_TEST(test_s21_log){INF_NAN_TESTS(log(i), 2)} END_TEST

    START_TEST(test_s21_pow) {
  double i = NAN, j;
  TESTS_BLOCK(pow(i, j))
  i = -NAN;
  TESTS_BLOCK(pow(i, j))
  i = INF;
  TESTS_BLOCK(pow(i, j))
  i = -INF;
  TESTS_BLOCK(pow(i, j))
  for (i = -10; i < 10; i += 0.1) {
    for (j = -10; j < 10; j += 0.1) {
      if (i > -1e-10L && i < 0) i = 0;
      if (j > -1e-10L && j < 0) j = 0;
      if (isnan(pow(i, j))) {
        ck_assert(isnan(s21_pow(i, j)));
      } else if (isinf((double)pow(i, j))) {
        ck_assert(isinf(s21_pow(i, j)));
      } else {
        ck_assert(fabsl(s21_pow(i, j) - pow(i, j)) < 1e-4L);
      }
    }
  }
}
END_TEST

START_TEST(test_s21_sin){INF_NAN_TESTS(sin(i), 1)} END_TEST

    START_TEST(test_s21_sqrt){INF_NAN_TESTS(sqrt(i), 1)} END_TEST

    START_TEST(test_s21_tan){INF_NAN_TESTS(tan(i), 1)} END_TEST

    int main() {
  Suite *s = suite_create("s21_math Tests");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_abs);
  tcase_add_test(tc_core, test_s21_acos);
  tcase_add_test(tc_core, test_s21_asin);
  tcase_add_test(tc_core, test_s21_atan);
  tcase_add_test(tc_core, test_s21_ceil);
  tcase_add_test(tc_core, test_s21_cos);
  tcase_add_test(tc_core, test_s21_exp);
  tcase_add_test(tc_core, test_s21_fabs);
  tcase_add_test(tc_core, test_s21_floor);
  tcase_add_test(tc_core, test_s21_fmod);
  tcase_add_test(tc_core, test_s21_log);
  tcase_add_test(tc_core, test_s21_pow);
  tcase_add_test(tc_core, test_s21_sin);
  tcase_add_test(tc_core, test_s21_sqrt);
  tcase_add_test(tc_core, test_s21_tan);

  suite_add_tcase(s, tc_core);
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  int failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (failed == 0) ? 0 : 1;
}
