#include "../s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (src == S21_NULL) {
    return S21_NULL;
  }
  s21_size_t len_src = s21_strlen(src);
  s21_size_t len_str = s21_strlen(str);

  if (start_index > len_src) {
    return S21_NULL;
  }

  char *res = (char *)malloc((len_src + len_str + 1) * sizeof(char));
  // memory check
  if (res == S21_NULL) {
    return S21_NULL;
  }

  // write to start_index
  s21_size_t cnt = 0;
  for (s21_size_t i = 0; i < start_index; i++) {
    res[i] = src[i];
    cnt = i;
  }
  if (start_index != 0) {
    cnt++;
  }
  // write from str
  for (s21_size_t i = 0; i < len_str; i++) {
    res[cnt] = str[i];
    cnt++;
  }
  // write after start_index
  for (s21_size_t i = start_index; i < len_src; i++) {
    res[cnt] = src[i];
    cnt++;
  }
  res[cnt] = '\0';

  return res;
}
