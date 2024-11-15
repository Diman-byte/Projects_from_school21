#ifndef SRC_S21_TEST_H
#define SRC_S21_TEST_H

#include <check.h>
#include <math.h>
#include <string.h>

#include "s21_string.h"

Suite *test_memchr();
Suite *test_memcmp();
Suite *test_memcpy();
Suite *test_memset();
Suite *test_strncat();
Suite *test_strchr();
Suite *test_strncmp();
Suite *test_strncpy();
Suite *test_strcspn();
Suite *test_strerror();
Suite *test_strlen();
Suite *test_strpbrk();
Suite *test_strrchr();
Suite *test_strstr();
Suite *test_strtok();

Suite *test_sprintf();

Suite *test_sscanf();

Suite *test_insert();
Suite *test_to_upper();
Suite *test_to_lower();
Suite *test_trim();

#endif
