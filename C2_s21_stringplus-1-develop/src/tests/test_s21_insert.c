#include "../s21_test.h"

START_TEST(test1_s21_insert) {
  const char* src1 = "Hello World!";
  const char* str1 = "wonderfull ";
  size_t index1 = 6;

  const char* src2 = "ABC";
  const char* str2 = "123";
  size_t index2 = 0;

  const char* src3 = "School";
  const char* str3 = " 21";
  size_t index3 = 6;

  const char* src4 = "Hello";
  const char* str4 = "";
  size_t index4 = 3;

  const char* src5 = "";
  const char* str5 = "World!";
  size_t index5 = 0;

  const char* src6 = "";
  const char* str6 = "";
  size_t index6 = 0;

  char* res1 = s21_insert(src1, str1, index1);
  char* res2 = s21_insert(src2, str2, index2);
  char* res3 = s21_insert(src3, str3, index3);
  char* res4 = s21_insert(src4, str4, index4);
  char* res5 = s21_insert(src5, str5, index5);
  char* res6 = s21_insert(src6, str6, index6);

  ck_assert_str_eq("Hello wonderfull World!", res1);
  ck_assert_str_eq("123ABC", res2);
  ck_assert_str_eq("School 21", res3);
  ck_assert_str_eq("Hello", res4);
  ck_assert_str_eq("World!", res5);
  ck_assert_str_eq("", res6);

  free(res1);
  free(res2);
  free(res3);
  free(res4);
  free(res5);
  free(res6);
}
END_TEST

START_TEST(s21_insert_test_normal) {
  const char srcString[128] = "Hello world";
  const char String[128] = "isn't it lovely";
  char* res = s21_insert(srcString, String, 11);
  ck_assert(!strncmp(res, "Hello worldisn't it lovely",
                     strlen("Hello worldisn't it lovely")));
  free(res);
}
END_TEST

START_TEST(s21_insert_test_strnull) {
  const char* srcString = NULL;
  const char* String = "hello world";
  char* res = s21_insert(srcString, String, 5);
  ck_assert_ptr_null(res);
  free(res);
}
END_TEST

START_TEST(s21_insert_test_bothnull) {
  const char* srcString = NULL;
  const char* String = NULL;
  char* res = s21_insert(srcString, String, 5);
  ck_assert_ptr_null(res);
  free(res);
}
END_TEST

START_TEST(s21_insert_test_indoutofrange) {
  const char *srcString, *String;
  srcString = "hello world";
  String = "fafa gogo";
  char* res = s21_insert(srcString, String, 55);
  ck_assert_ptr_null(res);
  free(res);
}
END_TEST

/*
Suite* test_insert() {
  Suite* suite = suite_create("s21_insert");
  TCase* tcase = tcase_create("s21_insert_tcase");

  tcase_add_test(tcase, test1_s21_insert);

  suite_add_tcase(suite, tcase);
  return suite;
}
*/
Suite* test_insert() {
  Suite* s;
  TCase *tc_insert_norm, *tc_insert_strnull, *tc_insert_bothnull,
      *tc_insert_indoutofrange, *tcase;

  s = suite_create("Suite_s21_insert");
  tcase = tcase_create("s21_insert_tcase");
  tc_insert_norm = tcase_create("insert normal");
  tc_insert_strnull = tcase_create("insert str null");
  tc_insert_bothnull = tcase_create("insert both null");
  tc_insert_indoutofrange = tcase_create("insert index out of range");

  tcase_add_test(tcase, test1_s21_insert);
  tcase_add_test(tc_insert_norm, s21_insert_test_normal);
  tcase_add_test(tc_insert_strnull, s21_insert_test_strnull);
  tcase_add_test(tc_insert_bothnull, s21_insert_test_bothnull);
  tcase_add_test(tc_insert_indoutofrange, s21_insert_test_indoutofrange);

  suite_add_tcase(s, tcase);
  suite_add_tcase(s, tc_insert_norm);
  suite_add_tcase(s, tc_insert_strnull);
  suite_add_tcase(s, tc_insert_bothnull);
  suite_add_tcase(s, tc_insert_indoutofrange);

  return s;
}
