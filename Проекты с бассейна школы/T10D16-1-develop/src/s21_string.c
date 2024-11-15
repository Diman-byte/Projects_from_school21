#include "s21_string.h"

size_t s21_strlen(const char *s) {
    size_t i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

int s21_strcmp(const char *s1, const char *s2) {
    int cmp = 0, i;
    for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        cmp = s1[i] - s2[i];
        if (cmp != 0) break;
    }
    if (cmp == 0) {
        cmp = s1[i] - s2[i];
    }
    return cmp;
}

char *s21_strcpy(char *cp, const char *src) {
    if (cp == NULL) {
        return NULL;
    }
    char *ptr = cp;
    while (*src != '\0') {
        *cp = *src;
        cp++;
        src++;
    }
    *cp = '\0';
    return ptr;
}

char *s21_strcat(char *des, const char *src) {
    s21_strcpy(des + s21_strlen(des), src);
    return des;
}

char *s21_strchr(const char *str, int c) {
    int i = 0;
    while (str[i] != '\0' && str[i] != c) i++;
    return c == str[i] ? (char *)str + i : NULL;
}
