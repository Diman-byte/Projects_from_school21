#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int result = 0;
  unsigned char *str11 = (unsigned char *)str1;
  unsigned char *str22 = (unsigned char *)str2;

  for (s21_size_t i = 0; i < n; i++) {
    if (str11[i] != str22[i]) {
      result = str11[i] - str22[i];
      break;
    }
  }

  return result;
}
