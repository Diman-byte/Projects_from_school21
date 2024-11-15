#include <check.h>
#include <string.h>

#include "../s21_test.h"

START_TEST(test1_strstr) {
  const char *qwe = "Always Day One dgdsfsgfdevok";
  const char *ewq = "dgdsfsgfdevok";

  while (*ewq) {
    ck_assert_ptr_eq(strstr(qwe, ewq), s21_strstr(qwe, ewq));
    ewq++;
  }
}

START_TEST(test2_strstr) {
  char *qwe = "hello world";
  char *ewq = "world";

  ck_assert_ptr_eq(strstr(qwe, ewq), s21_strstr(qwe, ewq));
}

START_TEST(test3_strstr) {
  char *qwe = "hello world";
  char *ewq = "goodbye";

  ck_assert_ptr_eq(strstr(qwe, ewq), s21_strstr(qwe, ewq));
}

START_TEST(test4_strstr) {
  char *qwe = "hello world";
  char *ewq = "";

  ck_assert_ptr_eq(strstr(qwe, ewq), s21_strstr(qwe, ewq));
}

START_TEST(test5_strstr) {
  char *qwe = "    hello    world  ";
  char *ewq = "hello    world";

  ck_assert_ptr_eq(strstr(qwe, ewq), s21_strstr(qwe, ewq));
}

START_TEST(test6_strstr) {
  char *qwe = "hello world hello world";
  char *ewq = "world";

  ck_assert_ptr_eq(strstr(qwe, ewq), s21_strstr(qwe, ewq));
}

Suite *test_strstr() {
  Suite *suite = suite_create("strstr");
  TCase *tcase = tcase_create("strstr_tcase");

  tcase_add_test(tcase, test1_strstr);
  tcase_add_test(tcase, test2_strstr);
  tcase_add_test(tcase, test3_strstr);
  tcase_add_test(tcase, test4_strstr);
  tcase_add_test(tcase, test5_strstr);
  tcase_add_test(tcase, test6_strstr);

  suite_add_tcase(suite, tcase);
  return suite;
}
