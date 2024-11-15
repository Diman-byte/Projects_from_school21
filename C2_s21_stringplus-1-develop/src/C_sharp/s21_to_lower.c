#include "../s21_string.h"

void *s21_to_lower(const char *str) {
  if (str == S21_NULL) {
    return S21_NULL;
  }
  int len = s21_strlen(str);

  char *res = (char *)malloc(sizeof(char) * (len + 1));
  if (res == S21_NULL) {
    return S21_NULL;
  }
  int i = 0;
  while (str[i] != '\0') {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      res[i] = str[i] + ('a' - 'A');
    } else {
      res[i] = str[i];
    }
    i++;
  }
  res[i] = '\0';

  return res;
}
