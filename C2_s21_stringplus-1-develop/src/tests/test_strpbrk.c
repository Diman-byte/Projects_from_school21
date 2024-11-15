#include <check.h>
#include <string.h>

#include "../s21_test.h"

START_TEST(test1_strpbrk) {
  const char *qwe = "Always Day One";
  const char *ewq = "abskjmparevok";

  while (*ewq) {
    ck_assert_ptr_eq(strpbrk(qwe, ewq), s21_strpbrk(qwe, ewq));
    ewq++;
  }
}

START_TEST(test2_strpbrk) {
  const char *qwe = "Always Day One";
  const char *ewq = "";

  ck_assert_ptr_eq(strpbrk(qwe, ewq), s21_strpbrk(qwe, ewq));
}

Suite *test_strpbrk() {
  Suite *suite = suite_create("strpbrk");
  TCase *tcase = tcase_create("strpbrk_tcase");

  tcase_add_test(tcase, test1_strpbrk);
  tcase_add_test(tcase, test2_strpbrk);

  suite_add_tcase(suite, tcase);
  return suite;
}
