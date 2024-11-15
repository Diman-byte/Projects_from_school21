#include "s21_string.h"

#include <stdio.h>

#define S0 "Hello"
#define S1 "\0"
#define S2 "123"

#ifdef STRLEN_TEST
void s21_strlen_test();
#define FUNC_TEST s21_strlen_test

#elif STRCMP_TEST
void s21_strcmp_test();
#define FUNC_TEST s21_strcmp_test

#elif STRCPY_TEST
void s21_strcpy_test();
#define FUNC_TEST s21_strcpy_test

#elif STRCAT_TEST
void s21_strcat_test();
#define FUNC_TEST s21_strcat_test

#elif STRCHR_TEST
void s21_strchr_test();
#define FUNC_TEST s21_strchr_test

#endif

int main() {
    FUNC_TEST();

    return 0;
}

void s21_strlen_test() {
    printf("%s\n", S0);
    printf("%zu\n", s21_strlen(S0));
    if (s21_strlen(S0) == 5) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    printf("%s\n", S1);
    printf("%zu\n", s21_strlen(S1));
    if (s21_strlen(S1) == 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    printf("%s\n", S2);
    printf("%zu\n", s21_strlen(S2));
    if (s21_strlen(S2) == 3) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}

void s21_strcmp_test() {
    char *s1[5] = {"a", "1", "abi", "abc0000", "a"};
    char *s2[5] = {"b", "9", "abz", "abc", "a"};
    int res[5] = {-1, -8, -17, 48, 0};

    for (int i = 0; i < 5; i++) {
        printf("%s\t", s1[i]);
        printf("%s\n", s2[i]);
        printf("%d\n", res[i]);
        if (res[i] == s21_strcmp(s1[i], s2[i])) {
            if (i < 4)
                printf("SUCCESS\n");
            else
                printf("SUCCESS");
        } else {
            if (i < 4)
                printf("FAIL\n");
            else
                printf("FAIL");
        }
        if (i < 4) {
            printf("\n");
        }
    }
}

void s21_strcpy_test() {
    char *s1[4] = {"Hello", "123", "\0", "hehe "};
    char s2[100];

    for (int i = 0; i < 4; i++) {
        s21_strcpy(s2, s1[i]);
        printf("%s\t", s1[i]);
        printf("%s\n", s2);
        if (s21_strlen(s1[i]) == s21_strlen(s2)) {
            if (i < 3)
                printf("SUCCESS\n");
            else
                printf("SUCCESS");
        } else if (i < 3)
            printf("FAIL\n");
        else
            printf("FAIL");

        if (i < 3) printf("\n");
    }
}

void s21_strcat_test() {
    char s1[4][100] = {"Hello", "123", "\0", "hehe "};
    char s2[4][100] = {" World", "456", "hey", "haha"};

    for (int i = 0; i < 4; i++) {
        printf("%s\t", s1[i]);
        printf("%s\n", s2[i]);
        int len_1 = s21_strlen(s1[i]);
        s21_strcat(s1[i], s2[i]);
        printf("%s\n", s1[i]);
        if (s21_strlen(s1[i]) == len_1 + s21_strlen(s2[i])) {
            if (i < 3)
                printf("SUCCESS\n");
            else
                printf("SUCCESS");
        } else {
            if (i < 3)
                printf("FAIL\n");
            else
                printf("FAIL");
        }
        if (i < 3) printf("\n");
    }
}

void s21_strchr_test() {
    char *s1[4] = {"Hello World", "123", "HAHA", "hehe\0a"};
    char s2[4] = {'W', '2', 'H', 'e'};
    const char index[4] = {6, 1, 0, 1};

    for (int i = 0; i < 4; i++) {
        printf("%s\t", s1[i]);
        printf("%c\n", s2[i]);
        char *ptr = s21_strchr(s1[i], s2[i]);
        printf("%s\n", ptr);
        if (ptr - s1[i] == index[i]) {
            if (i < 3)
                printf("SUCCESS\n");
            else
                printf("SUCCESS");
        } else {
            if (i < 3)
                printf("FAIL\n");
            else
                printf("FAIL");
        }
        if (i < 3) printf("\n");
    }
}
