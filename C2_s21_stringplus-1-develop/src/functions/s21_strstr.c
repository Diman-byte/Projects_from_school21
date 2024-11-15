#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *result = S21_NULL;
  s21_size_t check_for_matches = 0;
  s21_size_t check_for_no_matches = 0;

  if (*haystack == '\0') {
    return S21_NULL;
  }

  result = (char *)haystack;

  if (*needle == '\0') {
    return result;
  }

  s21_size_t length = s21_strlen(needle);

  while (*haystack) {
    if (*haystack == *needle) {
      if (check_for_matches == 0) {
        result = (char *)haystack;
      }
      check_for_matches++;
      haystack++;
      needle++;
    } else {
      for (; check_for_matches != 0; check_for_matches--) {
        needle--;
        check_for_no_matches++;
      }
      if (check_for_no_matches > 0) {
        check_for_no_matches = 0;
      } else {
        haystack++;
      }
      result = S21_NULL;
    }

    if (length == check_for_matches) {
      break;
    }

    if (*haystack == '\0') {
      result = S21_NULL;
    }
  }

  return result;
}
