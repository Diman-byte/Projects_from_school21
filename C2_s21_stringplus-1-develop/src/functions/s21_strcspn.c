#include "../s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t result = 0;
  int n = 0;
  int j = 0;

  while (*str1 && *str2) {
    if (*str1 == *str2) {
      break;
    } else {
      str2++;
      j++;
    }

    if (!*str2) {
      str1++;
      n++;

      for (; j != 0; j--) {
        str2--;
      }
    }
  }
  result = n;

  return result;
}
