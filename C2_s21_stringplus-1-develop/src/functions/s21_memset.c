#include "../s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *str1 = (unsigned char *)str;
  for (s21_size_t i = 0; i < n; i++) {
    str1[i] = (unsigned char)c;
  }
  return (void *)str1;
}
