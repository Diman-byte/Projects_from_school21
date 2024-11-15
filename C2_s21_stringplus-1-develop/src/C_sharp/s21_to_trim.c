#include "../s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  void *head_result = malloc(sizeof(char) * (s21_strlen(src) + 1));
  char *result = head_result;
  size_t i = 0;
  // initialising
  while (i < s21_strlen(src)) {
    *result = '\0';
    result++;
    i++;
  }
  i = 0;
  result = head_result;
  // processing the beginning of the line
  while (*src && trim_chars[i]) {
    if (*src == trim_chars[i]) {
      src++;
      i = 0;
    } else
      i++;
  }
  // processing others of the line
  while (*src) {
    *result = *src;
    result++;
    src++;
  }
  // processing the ending of the line
  i = 0;
  if (head_result != result) result--;
  while (trim_chars[i] && *result) {
    if (*result == trim_chars[i]) {
      result--;
      i = 0;
    } else
      i++;
  }
  // endline ptr and exit
  if (head_result != result) result++;
  *result = '\0';
  return head_result;
}
