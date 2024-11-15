#include <stdio.h>
#include <string.h>

int scan_dir(char *dir);

struct Quest_1 read_record_from_file(FILE *pfile, int index);
int get_file_size_in_bytes(FILE *pfile);
int get_records_count_in_file(FILE *pfile);

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

    struct Quest_1 buf;
    int check1 = scanf("%d.%d.%d", &buf.day, &buf.month, &buf.year);
    if (check1 != 3) {
        fclose(f);
        printf("n/a");
        return 0;
    }

    int count = 0;
    for (int i = 0; i < cnt; i++) {
        struct Quest_1 record = read_record_from_file(f, i);
        if (record.day == buf.day && record.month == buf.month && record.year == buf.year) {
            count++;
            printf("%d", record.code);
            break;
        }
    }
    if (count < 1) {
        printf("n/a");
        fclose(f);
        return 0;
    }

    fclose(f);

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