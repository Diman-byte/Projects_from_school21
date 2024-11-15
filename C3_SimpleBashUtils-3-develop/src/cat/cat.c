
#include "cat.h"

#include <string.h>

int main(int argc, char *argv[]) {
  if (argc == 1) {
    printf("Enter filename\n");
    return 0;
  }

  if (argv[1][0] != '-') {
    cat(argv);
    return 0;
  }

  // one flag
  if (argv[1][0] == '-' && argv[2][0] != '-') {
    if (strcmp(argv[1], "-b") == 0 || strcmp(argv[1], "-B") == 0 ||
        strcmp(argv[1], "--number-nonblank") == 0) {
      cat_b(argv);
    }

    if (strcmp(argv[1], "-e") == 0 || strcmp(argv[1], "-E") == 0) {
      cat_e_1(argv);
    }
    if (strcmp(argv[1], "-n") == 0 || strcmp(argv[1], "-N") == 0 ||
        strcmp(argv[1], "--number") == 0) {
      cat_n(argv);
    }
    if (strcmp(argv[1], "-s") == 0 || strcmp(argv[1], "-S") == 0 ||
        strcmp(argv[1], "--squeeze-blank") == 0) {
      cat_s(argv);
    }
    if (strcmp(argv[1], "-t") == 0 || strcmp(argv[1], "-T") == 0) {
      cat_t_1(argv);
    }
  }

  // two flags
  if (argv[1][0] == '-' && argv[2][0] == '-') {
    if (strcmp(argv[1], "-e") == 0 && strcmp(argv[2], "-v") == 0) {
      cat_e_2(argv);
    }

    if (strcmp(argv[1], "-t") == 0 && strcmp(argv[2], "-v") == 0) {
      cat_t_2(argv);
    }
  }

  return 0;
}

void cat(char *argv[]) {
  FILE *file = fopen(argv[1], "r");

  if (file == NULL) {
    printf("File not found\n");
  }
  char line[1024];

  while ((fgets(line, sizeof(line), file)) != NULL) {
    printf("%s", line);
  }

  fclose(file);
}

void cat_b(char *argv[]) {
  FILE *file = fopen(argv[2], "r");

  if (file == NULL) {
    printf("File not found\n");
  }
  char line[1024];

  int i = 1;

  while ((fgets(line, sizeof(line), file)) != NULL) {
    if (strcmp(line, "\n") == 0) {
      printf("\n");
    } else {
      printf("     %d\t%s", i, line);
      i++;
    }
  }

  fclose(file);
}

void cat_e_1(char *argv[]) {
  FILE *file = fopen(argv[2], "r");

  if (file == NULL) {
    printf("File not found\n");
  }
  char line[1024];

  while ((fgets(line, sizeof(line), file)) != NULL) {
    int size = strlen(line);

    if (line[size - 1] == '\n') {
      line[size - 1] = '$';

      printf("%s", line);
      printf("\n");
    } else {
      printf("%s", line);
    }
  }

  fclose(file);
}

void cat_e_2(char *argv[]) {
  FILE *file = fopen(argv[3], "r");

  if (file == NULL) {
    printf("File not found\n");
  }
  char line[1024];

  while ((fgets(line, sizeof(line), file)) != NULL) {
    int size = strlen(line);

    if (line[size - 1] == '\n') {
      line[size - 1] = '$';

      printf("%s", line);
      printf("\n");
    } else {
      printf("%s", line);
    }
  }

  fclose(file);
}

void cat_n(char *argv[]) {
  FILE *file = fopen(argv[2], "r");

  if (file == NULL) {
    printf("File not found\n");
  }
  char line[1024];

  int i = 1;

  while ((fgets(line, sizeof(line), file)) != NULL) {
    printf("     %d\t%s", i, line);
    i++;
  }

  fclose(file);
}

void cat_s(char *argv[]) {
  FILE *file = fopen(argv[2], "r");

  if (file == NULL) {
    printf("File not found\n");
  }
  char line[1024];

  int counter = 0;

  while ((fgets(line, sizeof(line), file)) != NULL) {
    if (strcmp(line, "\n") == 0) {
      counter++;
      if (counter <= 1) {
        printf("%s", line);
      }
    } else {
      counter = 0;
      printf("%s", line);
    }
  }

  fclose(file);
}

void cat_t_1(char *argv[]) {
  FILE *file = fopen(argv[2], "r");

  if (file == NULL) {
    printf("File not found\n");
  }
  char line[1024];

  while ((fgets(line, sizeof(line), file)) != NULL) {
    for (int i = 0; line[i] != '\0'; i++) {
      if (line[i] == '\t') {
        putchar('^');
        putchar('I');
      } else {
        putchar(line[i]);
      }
    }
  }

  fclose(file);
}

void cat_t_2(char *argv[]) {
  FILE *file = fopen(argv[3], "r");

  if (file == NULL) {
    printf("File not found\n");
  }
  char line[1024];

  while ((fgets(line, sizeof(line), file)) != NULL) {
    for (int i = 0; line[i] != '\0'; i++) {
      if (line[i] == '\t') {
        putchar('^');
        putchar('I');
      } else {
        putchar(line[i]);
      }
    }
  }

  fclose(file);
}
