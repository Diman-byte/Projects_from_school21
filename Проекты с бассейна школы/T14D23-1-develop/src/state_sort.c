#include <stdio.h>
#include <string.h>

int menu();
void read_bin(FILE *f);
void sort_bin(FILE *f);
int scan_dir(char *dir);

struct Quest_1 read_record_from_file(FILE *pfile, int index);
int get_file_size_in_bytes(FILE *pfile);
int get_records_count_in_file(FILE *pfile);
void write_record_in_file(FILE *pfile, const struct Quest_1 *record_to_write, int index);
void swap_records_in_file(FILE *pfile, int record_index1, int record_index2);

struct Quest_1 {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int secand;
    int status;
    int code;
};

int main() {
    char dir[256];
    scan_dir(dir);

    int res = menu();

    switch (res) {
        case -1:
            printf("n/a");
            break;

        case -2:
            printf("n/a");
            break;

        case 0: {
            FILE *f;
            f = fopen(dir, "r");

            if (f == NULL) {
                printf("n/a");
                return 0;
            }

            read_bin(f);
            fclose(f);
            break;
        }

        case 1: {
            FILE *f;
            f = fopen(dir, "r+");

            if (f == NULL) {
                printf("n/a");
                return 0;
            }

            int i = get_records_count_in_file(f);
            if (i == 0) {
                fclose(f);
                printf("n/a");
                return 0;
            }

            sort_bin(f);
            read_bin(f);
            fclose(f);

            break;
        }
        case 2: {
            FILE *f;
            f = fopen(dir, "r+");
            if (f == NULL) {
                printf("n/a");
                return 0;
            }

            struct Quest_1 tmp;
            int i = get_records_count_in_file(f);

            scanf("%d %d %d %d %d %d %d %d", &tmp.year, &tmp.month, &tmp.day, &tmp.hour, &tmp.minute,
                  &tmp.secand, &tmp.status, &tmp.code);
            write_record_in_file(f, &tmp, i);

            int j = get_records_count_in_file(f);
            if (j == 0) {
                fclose(f);
                printf("n/a");
                return 0;
            }

            sort_bin(f);
            read_bin(f);

            fclose(f);
            break;
        }

        default:
            break;
    }

    return 0;
}

int menu() {
    int res;
    int check1 = scanf("%d", &res);

    if (check1 != 1 || res < 0 || res > 2) {
        return -1;
    }

    char ch = getchar();
    if ((ch != '\n' && ch != ' ') || (ch == '.')) {
        rewind(stdin);
        return -2;
    }

    return res;
}

void read_bin(FILE *f) {
    int cnt = get_records_count_in_file(f);

    for (int i = 0; i < cnt; i++) {
        struct Quest_1 buf = read_record_from_file(f, i);
        printf("%d %d %d %d %d %d %d %d\n", buf.year, buf.month, buf.day, buf.hour, buf.minute, buf.secand,
               buf.status, buf.code);
    }
}

void sort_bin(FILE *f) {
    int cnt = get_records_count_in_file(f);

    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < cnt - i; j++) {
            struct Quest_1 record_1 = read_record_from_file(f, j);
            struct Quest_1 record_2 = read_record_from_file(f, j + 1);

            if (record_1.year > record_2.year) {
                swap_records_in_file(f, j, j + 1);
            }
            if (record_1.year == record_2.year) {
                if (record_1.month > record_2.month) {
                    swap_records_in_file(f, j, j + 1);
                }
            }
            if (record_1.year == record_2.year && record_1.month == record_2.month) {
                if (record_1.day > record_2.day) {
                    swap_records_in_file(f, j, j + 1);
                }
            }
            if (record_1.year == record_2.year && record_1.month == record_2.month &&
                record_1.day == record_2.day) {
                if (record_1.hour > record_2.hour) {
                    swap_records_in_file(f, j, j + 1);
                }
            }
            if (record_1.year == record_2.year && record_1.month == record_2.month &&
                record_1.day == record_2.day && record_1.hour == record_2.hour) {
                if (record_1.minute > record_2.minute) {
                    swap_records_in_file(f, j, j + 1);
                }
            }
            if (record_1.year == record_2.year && record_1.month == record_2.month &&
                record_1.day == record_2.day && record_1.hour == record_2.hour &&
                record_1.minute == record_2.minute) {
                if (record_1.secand > record_2.secand) {
                    swap_records_in_file(f, j, j + 1);
                }
            }
        }
    }
}

struct Quest_1 read_record_from_file(FILE *pfile, int index) {
    int offset = index * sizeof(struct Quest_1);
    fseek(pfile, offset, SEEK_SET);
    struct Quest_1 record;
    fread(&record, sizeof(struct Quest_1), 1, pfile);
    rewind(pfile);
    return record;
}

int get_file_size_in_bytes(FILE *pfile) {
    int size = 0;
    fseek(pfile, 0, SEEK_END);
    size = ftell(pfile);
    rewind(pfile);
    return size;
}

int get_records_count_in_file(FILE *pfile) { return get_file_size_in_bytes(pfile) / sizeof(struct Quest_1); }

void write_record_in_file(FILE *pfile, const struct Quest_1 *record_to_write, int index) {
    int offset = index * sizeof(struct Quest_1);
    fseek(pfile, offset, SEEK_SET);
    fwrite(record_to_write, sizeof(struct Quest_1), 1, pfile);
    fflush(pfile);
    rewind(pfile);
}

void swap_records_in_file(FILE *pfile, int record_index1, int record_index2) {
    struct Quest_1 record1 = read_record_from_file(pfile, record_index1);
    struct Quest_1 record2 = read_record_from_file(pfile, record_index2);

    write_record_in_file(pfile, &record1, record_index2);
    write_record_in_file(pfile, &record2, record_index1);
}

int scan_dir(char *dir) {
    scanf("%255s", dir);
    char direction[256] = "../";
    strcat(direction, dir);

    strcpy(dir, direction);

    return 0;
}