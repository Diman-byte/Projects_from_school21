#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define W 80
#define H 25
#define ALIVE 'o'
#define DEAD ' '

void init(int field[H][W]);
void print(int field[H][W]);
int neighbours(int field[H][W], int x, int y);
void next_field(int field[H][W], int new_field[H][W]);
int count_alive(int field[H][W]);
void copy_field(int field[H][W], int new_field[H][W]);
int scanf_file(int field[H][W]);

int main() {
    initscr();

    int field[H][W], new_field[H][W];

    if (scanf_file(field) == 2) {
        init(field);
    }

    noecho();
    curs_set(0);

    if (!freopen("/dev/tty", "r", stdin)) {
        return 0;
    }

    nodelay(stdscr, TRUE);
    int speed = 15000;

    int flag1 = 1;
    int flag2 = 1;

    while (flag2) {
        int check = getch();
        if (check == 'q' || check == 'Q') {
            break;
        }
        if (check == ' ') {
            flag1 = 1;
        }

        while (flag1) {
            int ch = getch();

            if (ch == 'q' || ch == 'Q') {
                flag2 = 0;
                break;
            }
            if (ch == 's' || ch == 'S') {
                speed += 100;
            }
            if (ch == 'f' || ch == 'F') {
                if (speed > 100) {
                    speed -= 100;
                }
            }
            if (ch == ' ') {
                flag1 = 0;
                break;
            }

            int alive = count_alive(field);
            if (alive == 0) {
                print(field);
                printw("----------GAME OVER----------");
                break;
            }
            print(field);
            refresh();
            usleep(speed);
            next_field(field, new_field);
            copy_field(field, new_field);
        }
    }
    endwin();
    return 0;
}

void init(int field[H][W]) {
    srand(time(0));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            field[i][j] = rand() % 2;
        }
    }
}

void print(int field[H][W]) {
    clear();
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            printw("%c", field[i][j] == 1 ? ALIVE : DEAD);
        }
        printw("\n");
    }
    printw("\n----------MENU----------\n");
    printw("Q/q - quit the game\nS/s - Make speed slower\nF/f - make speed faster\nSpace - pause the game");
}

int count_alive(int field[H][W]) {
    int count = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (field[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}

int neighbours(int field[H][W], int x, int y) {
    int nb_count = 0;
    const int mv[3] = {-1, 0, 1};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int n_x = (x + mv[i] + H) % H;
            int n_y = (y + mv[j] + W) % W;
            if (n_x >= 0 && n_y >= 0 && n_x < H && n_y < W) {
                if (n_x != x || n_y != y) {
                    if (field[n_x][n_y] == 1) {
                        nb_count++;
                    }
                }
            }
        }
    }
    return nb_count;
}

void next_field(int field[H][W], int new_field[H][W]) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int nb_count = neighbours(field, i, j);
            if ((nb_count == 2 || nb_count == 3) && field[i][j] == 1) {
                new_field[i][j] = 1;
            } else if (nb_count == 3 && field[i][j] == 0) {
                new_field[i][j] = 1;
            } else {
                new_field[i][j] = 0;
            }
        }
    }
}

void copy_field(int field[H][W], int new_field[H][W]) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            field[i][j] = new_field[i][j];
        }
    }
}

int scanf_file(int field[H][W]) {
    int number;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            scanf("%d", &number);
            if (i == 0 && j == 0 && number == 2) {
                return 2;
            }
            field[i][j] = number;
        }
    }
    return 0;
}
