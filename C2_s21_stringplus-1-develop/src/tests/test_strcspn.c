#include <check.h>
#include <string.h>

#include "../s21_test.h"

START_TEST(test1_strcspn) {
  const char *qwe = "Always Day One";
  const char *ewq = "absdfewjqie";

  while (*ewq) {
    ck_assert_int_eq(strcspn(qwe, ewq), s21_strcspn(qwe, ewq));
    ewq++;
  }
}

START_TEST(test2_strcspn) {
  const char *qwe = "Always Day One";
  const char *ewq = "absdfejqiew";

  while (*qwe) {
    ck_assert_int_eq(strcspn(qwe, ewq), s21_strcspn(qwe, ewq));
    qwe++;
  }
}

Suite *test_strcspn() {
  Suite *suite = suite_create("strcspn");
  TCase *tcase = tcase_create("strcspn_tcase");

  tcase_add_test(tcase, test1_strcspn);
  tcase_add_test(tcase, test2_strcspn);

  suite_add_tcase(suite, tcase);
  return suite;
}
