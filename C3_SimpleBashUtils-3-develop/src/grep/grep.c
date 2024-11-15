#include "grep.h"

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc == 1 || argc == 2) {
    printf("Enter template or filename\n");
    return 0;
  }

  if (argv[1][0] != '-') {
    grep_1(argv[1], argv[2]);
    return 0;
  }
  if (argv[1][0] == '-') {
    if (strcmp(argv[1], "-e") == 0) {
      grep_e(argv, argv, argc);
    }

    if (strcmp(argv[1], "-i") == 0) {
      grep_i(argv[2], argv[3]);
    }
    if (strcmp(argv[1], "-v") == 0) {
      grep_v(argv[2], argv[3]);
    }
    if (strcmp(argv[1], "-c") == 0) {
      grep_c(argv[2], argv[3]);
    }
    if (strcmp(argv[1], "-l") == 0) {
      grep_l(argv[2], argv, argc);
    }
    if (strcmp(argv[1], "-n") == 0) {
      grep_n(argv[2], argv[3]);
    }
  }

  return 0;
}

void grep_0(char *template, char *filename) {
  FILE *file = fopen(filename, "r");

  if (file == NULL) {
    printf("File not found\n");
  }

  char line[1024];

  while ((fgets(line, sizeof(line), file)) != NULL) {
    if (strstr(line, template) != NULL) {
      printf("%s", line);
    }
  }

  fclose(file);
}

void grep_1(char *template, char *filename) {
  FILE *file = fopen(filename, "r");

  if (file == NULL) {
    printf("File not found\n");
    return;
  }

  char line[1024];

  regex_t pat;  // структура для скомпилированной регулярки
  int status =
      regcomp(&pat, template, REG_EXTENDED);  // компилим регулярку и помещаем
                                              // выходные данные в структуру
  // возвращает 0 если успех

  if (status == 0) {
    while ((fgets(line, sizeof(line), file)) != NULL) {
      int status1 = regexec(&pat, line, 0, NULL, 0);
      if (status1 == 0) {  // если нашел совпадение
        int len = strlen(line);
        printf("%s", line);
        if (line[len - 1] != '\n') {
          printf("\n");
        }
      }
    }
  }

  regfree(&pat);  // освобождаем память выделенную для хранения
                  // откомпилированного рег выр

  fclose(file);
}

void grep_e(char *template[], char *filename[], int argc) {
  FILE *file = fopen(filename[argc - 1], "r");

  if (file == NULL) {
    printf("File not found\n");
    return;
  }

  char line[1024];
  char line2[1024];

  line2[0] = '\0';

  int count_pat = 0;
  for (int i = 2; i < argc - 1; i = i + 2) {
    count_pat++;
  }

  regex_t *patterns;  // я не знаю сколько будет патернов поэтому делаю массив
                      // структур

  patterns = malloc(count_pat * sizeof(regex_t));

  for (int j = 0, i = 2; j < count_pat; j++, i = i + 2) {
    regcomp(&patterns[j], template[i], REG_EXTENDED);
  }

  int lenght;

  while ((fgets(line, sizeof(line), file)) != NULL) {
    int status[count_pat];
    int flag = 0;

    for (int j = 0; j < count_pat; j++) {
      status[j] = regexec(&patterns[j], line, 0, NULL, 0);

      if (j == 0) {
        if (status[j] == 0) {
          printf("%s", line);
          strcpy(line2, line);
          lenght = strlen(line2);
        }
      } else {
        if (status[j] == 0) {
          for (int i = 0; i < j; i++) {
            if (status[i] == 0) {
              flag = 1;  // если прежде уже находили соответствие, не нужно
            }            // выводить эту строку еще раз
          }
          if (flag != 1) {
            printf("%s", line);
            strcpy(line2, line);
            lenght = strlen(line2);
          }
        }
      }
    }
  }
  if (line2[0] != '\0') {
    if (line2[lenght - 1] != '\n') {
      printf("\n");
    }
  }

  for (int j = 0; j < count_pat; j++) {
    regfree(&patterns[j]);
  }

  free(patterns);

  fclose(file);
}

void grep_i(char *template, char *filename) {
  FILE *file = fopen(filename, "r");

  if (file == NULL) {
    printf("File not found\n");
    return;
  }

  char line[1024];
  char line2[1024];

  regex_t pat;
  int status =
      regcomp(&pat, template,
              REG_EXTENDED | REG_ICASE);  // REG_ICASE - игнорирует регистр

  if (status == 0) {
    int lenght;
    int status1 = 1;
    while ((fgets(line, sizeof(line), file)) != NULL) {
      status1 = regexec(&pat, line, 0, NULL, 0);
      if (status1 == 0) {
        printf("%s", line);
        strcpy(line2, line);
        lenght = strlen(line2);
      }
    }
    if (status1 == 0) {
      if (line2[lenght - 1] != '\n') {
        printf("\n");
      }
    }
  }

  regfree(&pat);

  fclose(file);
}

void grep_v(char *template, char *filename) {
  FILE *file = fopen(filename, "r");

  if (file == NULL) {
    printf("File not found\n");
    return;
  }

  char line[1024];
  char line2[1024];

  line2[0] = '\0';

  regex_t pat;
  int status = regcomp(&pat, template, REG_EXTENDED);

  if (status == 0) {
    int lenght;
    while ((fgets(line, sizeof(line), file)) != NULL) {
      int status1 = regexec(&pat, line, 0, NULL, 0);
      if (status1 != 0) {  // когда не соответствует - выводим
        printf("%s", line);
        strcpy(line2, line);
        lenght = strlen(line2);
      }
    }

    if (line2[0] != '\0') {
      if (line2[lenght - 1] != '\n') {
        printf("\n");
      }
    }
  }

  regfree(&pat);

  fclose(file);
}

void grep_c(char *template, char *filename) {
  FILE *file = fopen(filename, "r");

  if (file == NULL) {
    printf("File not found\n");
    return;
  }

  char line[1024];

  regex_t pat;
  int status = regcomp(&pat, template, REG_EXTENDED);

  if (status == 0) {
    int counter = 0;
    while ((fgets(line, sizeof(line), file)) != NULL) {
      int status1 = regexec(&pat, line, 0, NULL, 0);
      if (status1 == 0) {
        counter++;
      }
    }
    printf("%d\n", counter);
  }

  regfree(&pat);

  fclose(file);
}

void grep_l(char *template, char *filename[], int argc) {
  regex_t pat;
  int status = regcomp(&pat, template, REG_EXTENDED);

  char line[1024];

  int statuses[1024];

  for (int i = 3; i < argc; i++) {
    FILE *file = fopen(filename[i], "r");

    if (file == NULL) {
      printf("File not found\n");
      regfree(&pat);
      return;
    }

    int cnt_str = 0;

    if (status == 0) {
      while ((fgets(line, sizeof(line), file)) != NULL) {
        statuses[cnt_str] = regexec(&pat, line, 0, NULL, 0);
        cnt_str++;
      }
    }

    int flag = 0;
    for (int j = 0; j < cnt_str; j++) {
      if (statuses[j] == 0) {
        flag = 1;
      }
    }

    if (flag == 1) {
      printf("%s\n", filename[i]);
    }

    fclose(file);
  }

  regfree(&pat);
}

void grep_n(char *template, char *filename) {
  FILE *file = fopen(filename, "r");

  if (file == NULL) {
    printf("File not found\n");
    return;
  }

  char line[1024];
  char line2[1024];

  line2[0] = '\0';

  regex_t pat;
  int status = regcomp(&pat, template, REG_EXTENDED);

  if (status == 0) {
    int cnt = 1;
    int lenght;
    while ((fgets(line, sizeof(line), file)) != NULL) {
      int status1 = regexec(&pat, line, 0, NULL, 0);
      if (status1 == 0) {
        printf("%d:%s", cnt, line);
        strcpy(line2, line);
        lenght = strlen(line2);
      }
      cnt++;
    }
    if (line2[0] != '\0') {
      if (line2[lenght - 1] != '\n') {
        printf("\n");
      }
    }
  }

  regfree(&pat);

  fclose(file);
}