#include <regex.h>
#include <stdlib.h>

void grep_0(char *template, char *filename);  // скорее всего не нужна
void grep_1(char *template, char *filename);
void grep_e(char *template[], char *filename[],
            int argc);  // когда несколько шаблонов
void grep_i(char *template, char *filename);
void grep_v(char *template, char *filename);
void grep_c(char *template, char *filename);
void grep_l(char *template, char *filename[], int argc);
void grep_n(char *template, char *filename);