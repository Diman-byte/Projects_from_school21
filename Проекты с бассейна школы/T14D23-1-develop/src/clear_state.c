#include <stdio.h>
#include <string.h>

int scan_dir(char *dir);
void read_bin(FILE *f);

struct Quest_1 read_record_from_file(FILE *pfile, int index);
int get_file_size_in_bytes(FILE *pfile);
int get_records_count_in_file(FILE *pfile);
void write_record_in_file(FILE *pfile, const struct Quest_1 *record_to_write, int index);

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

    FILE *f;
    f = fopen(dir, "r");

    if (f == NULL) {
        printf("n/a");
        return 0;
    }
    int cnt = get_records_count_in_file(f);
    if (cnt == 0) {
        fclose(f);
        printf("n/a");
        return 0;
    }

    struct Quest_1 buf1;
    struct Quest_1 buf2;
    int check1 =
        scanf("%d.%d.%d %d.%d.%d", &buf1.day, &buf1.month, &buf1.year, &buf2.day, &buf2.month, &buf2.year);
    if (check1 != 6) {
        fclose(f);
        printf("n/a");
        return 0;
    }

    FILE *f2;
    f2 = fopen("temp", "w");

    int count = 0;

    for (int i = 0; i < cnt; i++) {
        struct Quest_1 record = read_record_from_file(f, i);

        write_record_in_file(f2, &record, count);

        if (record.year >= buf1.year && record.year <= buf2.year) {
            if (record.month >= buf1.month && record.month <= buf2.month) {
                if (record.day >= buf1.day && record.day <= buf2.day) {
                    // continue;
                } else {
                    write_record_in_file(f2, &record, count);
                    count++;
                }
            } else {
                write_record_in_file(f2, &record, count);
                count++;
            }
        } else {
            write_record_in_file(f2, &record, count);
            count++;
        }
    }

    fclose(f);
    fclose(f2);

    remove(dir);
    rename("temp", dir);

    f2 = fopen(dir, "r");
    read_bin(f2);
    fclose(f2);

    return 0;
}

int scan_dir(char *dir) {
    scanf("%255s", dir);
    char direction[256] = "../";
    strcat(direction, dir);

    strcpy(dir, direction);

    return 0;
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

void read_bin(FILE *f) {
    int cnt = get_records_count_in_file(f);

    for (int i = 0; i < cnt; i++) {
        struct Quest_1 buf = read_record_from_file(f, i);
        printf("%d %d %d %d %d %d %d %d\n", buf.year, buf.month, buf.day, buf.hour, buf.minute, buf.secand,
               buf.status, buf.code);
    }
}