#include "../s21_string.h"
void *s21_memchr(const void *str, int c, s21_size_t n) {
  void *result = S21_NULL;
  char *str1 = (char *)str;
  s21_size_t i = 0;
  while (str1[i] != '\0' && i < n) {
    if (str1[i] == (unsigned char)c) {
      result = (void *)&str1[i];
      break;
    }
    i++;
  }
  return result;
}
