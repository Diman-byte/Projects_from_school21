#include "../s21_test.h"

START_TEST(test1_s21_to_lower) {
  const char *str1 = "Hello, World!";
  const char *str2 = "123abc";
  const char *str3 = "";
  const char *str4 = "##12#&*^%^(_)*h*_!**J909";
  const char *str5 = "\nABc\n";
  const char *str6 = S21_NULL;

  char *res1 = s21_to_lower(str1);
  char *res2 = s21_to_lower(str2);
  char *res3 = s21_to_lower(str3);
  char *res4 = s21_to_lower(str4);
  char *res5 = s21_to_lower(str5);
  char *res6 = s21_to_lower(str6);

  ck_assert_str_eq("hello, world!", res1);
  ck_assert_str_eq("123abc", res2);
  ck_assert_str_eq("", res3);
  ck_assert_str_eq("##12#&*^%^(_)*h*_!**j909", res4);
  ck_assert_str_eq("\nabc\n", res5);
  ck_assert_pstr_eq(res6, S21_NULL);

  free(res1);
  free(res2);
  free(res3);
  free(res4);
  free(res5);
  if (res6 != S21_NULL) free(res6);
}
END_TEST

Suite *test_to_lower() {
  Suite *suite = suite_create("s21_to_lower");
  TCase *tcase = tcase_create("s21_to_lower_tcase");

  tcase_add_test(tcase, test1_s21_to_lower);

  suite_add_tcase(suite, tcase);
  return suite;
}
