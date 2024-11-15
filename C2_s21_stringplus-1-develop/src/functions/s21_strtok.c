#include "../s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *pos;
  char *token = S21_NULL;
  if (str) {
    pos = str;
    while (*pos && s21_strchr(delim, *pos)) {
      *pos++ = '\0';
    }
  }
  if (pos && *pos) {
    str = pos;
    while (*pos && !s21_strchr(delim, *pos)) {
      ++pos;
    }
    while (*pos && s21_strchr(delim, *pos)) {
      *pos++ = '\0';
    }
    token = str;
  }
  return token;
}
