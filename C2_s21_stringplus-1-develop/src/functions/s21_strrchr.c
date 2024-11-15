#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
  const char *res = S21_NULL;
  while (*str != '\0') {
    if (*str == c) res = str;
    str++;
  }
  if (c == '\0') return (char *)str;
  return (char *)res;
}
