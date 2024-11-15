#include <dirent.h>
#include <stdio.h>
#include <string.h>

int menu();
int scan_file(char *name_file, FILE *rd);
int put_file(char *name_file);
int cesar();

int main() {
    char name_file[256];
    int flag = 1;
    int flag1 = 100;
    int flag2 = 150;
    FILE *rd = NULL;

    while (flag) {
        int n = menu();
        switch (n) {
            case 97:
                printf("n/a\n");
                // flag = 0;
                break;

            case 99:
                flag = 0;
                break;

            case 98:
                printf("n/a\n");
                break;

            case 96:
                printf("n/a\n");
                rewind(stdin);
                break;

            case -1:
                printf("n/a\n");
                break;

            case 1: {
                flag1 = scan_file(name_file, rd);
                if (flag1 == -1) {
                    fclose(rd);
                    break;
                }
                break;
            }

            case 2: {
                flag2 = put_file(name_file);
                if (flag2 == -1 || flag2 == -2) {
                    printf("n/a\n");
                    break;
                }

                break;
            }
            case 3: {
                int q3 = cesar();
                if (q3 == -1 || q3 == -2) {
                    printf("n/a\n");
                    break;
                }
                break;
            }

            default:
                break;
        }
    }

    fclose(rd);

    return 0;
}

int menu() {
    int res;
    int check1 = scanf("%d", &res);

    if (check1 != 1) {
        return 96;
    }
    if ((int)res != res) {
        return 98;
    }
    if (res == 0 || res < -1 || res > 4) {
        rewind(stdin);
        return 97;
    }

    char ch = getchar();
    if ((ch != '\n' && ch != ' ') || (ch == '.')) {
        rewind(stdin);
        return -1;
    }

    if (res == -1) {
        return 99;
    }

    return res;
}

int scan_file(char *name_file, FILE *rd) {
    scanf("%255s", name_file);

    if ((rd = fopen(name_file, "r")) == NULL) {
        printf("n/a\n");
        return -1;
    }

    if (getc(rd) == EOF) {
        printf("n/a\n");
        fseek(rd, 0, SEEK_SET);
        fclose(rd);
        return -1;
    }

    else {
        fseek(rd, 0, SEEK_SET);
        char line[256];
        while (fgets(line, sizeof(line), rd) != NULL) {
            printf("%s", line);
        }

        printf("\n");
        fclose(rd);
        return 1;
    }
    return 0;
}

int put_file(char *name_file) {
    FILE *file1 = fopen(name_file, "r");

    fflush(stdin);
    char line[255];
    fgets(line, sizeof(line), stdin);
    if (file1 == NULL) {
        return -1;
    } else {
        FILE *file = fopen(name_file, "a");
        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }
        fprintf(file, "%s\n", line);
        fclose(file);

        file = fopen(name_file, "r");

        if (file != NULL) {
            char line2[255];
            while (fgets(line2, sizeof(line2), file) != NULL) {
                printf("%s", line2);
            }
            // printf("\n");
            fclose(file);
        } else {
            fclose(file1);
            return -2;
        }
    }
    fclose(file1);

    return 0;
}

int cesar() {
    char direction[256];
    int shift;
    scanf("%255s", direction);
    if (scanf("%d", &shift) != 1) {
        return -1;
    }

    DIR *dir;
    struct dirent *entry;
    dir = opendir(direction);
    if (dir == NULL) {
        return -2;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strstr(entry->d_name, ".c") != NULL) {
            char filepath[1000];
            char namefile[256];
            strcpy(namefile, entry->d_name);
            sprintf(filepath, "%s/%s", direction, namefile);

            FILE *file1 = fopen(filepath, "r");
            FILE *file2 = fopen("temp_file", "w");
            int c;
            while ((c = getc(file1)) != EOF) {
                if (c >= 'A' && c <= 'Z') {
                    c = 'A' + (c - 'A' + shift) % 26;
                    fputc(c, file2);
                } else if (c >= 'a' && c <= 'z') {
                    c = 'a' + (c - 'a' + shift) % 26;
                    fputc(c, file2);
                } else {
                    fputc(c, file2);
                }
            }

            fclose(file1);
            fclose(file2);
            remove(filepath);
            rename("temp_file", namefile);
            rename(namefile, filepath);
        }
    }
    closedir(dir);

    dir = opendir(direction);
    while ((entry = readdir(dir)) != NULL) {
        if (strstr(entry->d_name, ".h") != NULL) {
            char filepath[1000];
            char namefile[256];
            strcpy(namefile, entry->d_name);
            sprintf(filepath, "%s/%s", direction, namefile);
            FILE *file3 = fopen(filepath, "w");
            fclose(file3);
        }
    }
    closedir(dir);

    return 0;
}