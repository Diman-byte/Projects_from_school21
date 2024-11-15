#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = S21_NULL;
  s21_size_t n = s21_strcspn(str1, str2);

  if (*str1 == '\0' || *str2 == '\0') {
    return S21_NULL;
  }

  s21_size_t length = s21_strlen(str1);

  if (n == length) {
    result = S21_NULL;
  } else {
    for (; n != 0; n--) {
      str1++;
    }
    result = (char *)str1;
  }

  return result;
}
