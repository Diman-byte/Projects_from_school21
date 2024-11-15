#include <check.h>
#include <string.h>

#include "../s21_test.h"

START_TEST(test_strtok_1) {
  char str1[] = "Never gonna give you up!";
  char str2[] = "Never gonna give you up!";
  char del[] = "!";
  ck_assert_pstr_eq(strtok(str1, del), s21_strtok(str2, del));
}
END_TEST

START_TEST(test_strtok_2) {
  char str1[] = "";
  char str2[] = "";
  char del[] = "";
  ck_assert_pstr_eq(strtok(str1, del), s21_strtok(str2, del));
}
END_TEST

START_TEST(test_strtok_3) {
  char str1[] = "Never gonna give you up!";
  char str2[] = "Never gonna give you up!";
  char del[] = "\0";
  ck_assert_pstr_eq(strtok(str1, del), s21_strtok(str2, del));
}
END_TEST

START_TEST(test_strtok_4) {
  char str1[] = "Never gonna give you up!";
  char str2[] = "Never gonna give you up!";
  char del[] = "";
  ck_assert_pstr_eq(strtok(str1, del), s21_strtok(str2, del));
}
END_TEST

START_TEST(test_strtok_5) {
  char str1[] = "Never gonna give you up!";
  char str2[] = "Never gonna give you up!";
  char del[] = "Never gonna give you up!";
  ck_assert_pstr_eq(strtok(str1, del), s21_strtok(str2, del));
}
END_TEST

START_TEST(test_strtok_6) {
  char str1[] = "Never gonna give you up!";
  char str2[] = "Never gonna give you up!";
  char del[] = "We've known each other for so long";
  ck_assert_pstr_eq(strtok(str1, del), s21_strtok(str2, del));
}
END_TEST

START_TEST(test_strtok_7) {
  char str1[] = "ABABABABABBABABABBABABABABABBA";
  char str2[] = "ABABABABABBABABABBABABABABABBA";
  char del[] = "B";
  ck_assert_pstr_eq(strtok(str1, del), s21_strtok(str2, del));
}
END_TEST

START_TEST(test_strtok_8) {
  char str1[] = "\0ABABABABABBABABABBABABABABABBA";
  char str2[] = "\0ABABABABABBABABABBABABABABABBA";
  char del[] = "A";
  ck_assert_pstr_eq(strtok(str1, del), s21_strtok(str2, del));
}
END_TEST

START_TEST(test_strtok_9) {
  char str1[] = "\0Never gonna give you up!";
  char str2[] = "\0Never gonna give you up!";
  char del[] = "\0";
  ck_assert_pstr_eq(strtok(str1, del), s21_strtok(str2, del));
}
END_TEST

START_TEST(test_strtok_10) {
  char str1[] = "\0Never gonna give you up!";
  char str2[] = "\0Never gonna give you up!";
  char del[] = "";
  ck_assert_pstr_eq(strtok(str1, del), s21_strtok(str2, del));
}
END_TEST

START_TEST(test_strtok_11) {
  char str1[] = "Never gonna give you up! And other people";
  char str2[] = "Never gonna give you up! And other people";
  char str3[] = "\0We know the game";
  char str4[] = "\0We know the game";
  char del[] = "";

  ck_assert_pstr_eq(strtok(str1, del), s21_strtok(str2, del));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(NULL, del), s21_strtok(NULL, del));
  }
  ck_assert_pstr_eq(strtok(str3, del), s21_strtok(str4, del));
  ck_assert_pstr_eq(strtok(NULL, del), s21_strtok(NULL, del));
  ck_assert_pstr_eq(strtok(NULL, del), s21_strtok(NULL, del));
}
END_TEST

START_TEST(test_strtok_12) {
  char str1[] = "Never      gonna run around and desert you";
  char str2[] = "Never      gonna run around and desert you";
  char str3[] = "Never gonna say goodbye";
  char str4[] = "Never gonna say goodbye";
  char del[] = " g";

  ck_assert_pstr_eq(strtok(str1, del), s21_strtok(str2, del));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(NULL, del), s21_strtok(NULL, del));
  }
  ck_assert_pstr_eq(strtok(str3, del), s21_strtok(str4, del));
  ck_assert_pstr_eq(strtok(NULL, del), s21_strtok(NULL, del));
  ck_assert_pstr_eq(strtok(NULL, del), s21_strtok(NULL, del));
}
END_TEST

Suite *test_strtok() {
  Suite *suite = suite_create("strtok");
  TCase *tcase = tcase_create("test_strtok_tcase");

  tcase_add_test(tcase, test_strtok_1);
  tcase_add_test(tcase, test_strtok_2);
  tcase_add_test(tcase, test_strtok_3);
  tcase_add_test(tcase, test_strtok_4);
  tcase_add_test(tcase, test_strtok_5);
  tcase_add_test(tcase, test_strtok_6);
  tcase_add_test(tcase, test_strtok_7);
  tcase_add_test(tcase, test_strtok_8);
  tcase_add_test(tcase, test_strtok_9);
  tcase_add_test(tcase, test_strtok_10);
  tcase_add_test(tcase, test_strtok_11);
  tcase_add_test(tcase, test_strtok_12);

  suite_add_tcase(suite, tcase);
  return suite;
}
