// I WANT TO PLAY WITH YOU
//         YOUR FRIEND, AI

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 25
#define PUDDLE_X_L 1 // смещение ракетки по Х
#define PUDDLE_X_R 78
#define WIN 21
#define SC_POS_X_P1 WIDTH / 2 - 5
#define SC_POS_X_P2 WIDTH / 2 + 5
#define SC_POS_Y 3
#define START_Y HEIGHT / 2
#define START_X WIDTH / 2

void draw(int puddle_middle_l, int puddle_middle_r, int ball_x, int ball_y,
          int score_count_1, int score_count_2);

int main(void) {
  int ball_x, ball_y; // координаты мячика
  int puddle_middle_r, puddle_middle_l; // середина правой и левой ракеток
  int score_count_1 = 0, score_count_2 = 0; // очки игроков
  ball_x = START_X; // вынести в отдельную ф=ю старта !!
  ball_y = START_Y;
  puddle_middle_r = puddle_middle_l = START_Y;
  int ball_vector_x = -1, ball_vector_y = 1; // направление движения

  while (1) {
    draw(puddle_middle_l, puddle_middle_r, ball_x, ball_y, score_count_1,
         score_count_2);
    if (ball_y == 1 || ball_y == HEIGHT - 2) //если мячик касается грани Y  то
      ball_vector_y = -ball_vector_y;
    if ((ball_y == puddle_middle_l || ball_y == (puddle_middle_l + 1) ||
         ball_y == (puddle_middle_l - 1)) &&
        ball_x == PUDDLE_X_L + 1) // если мяч касается ракетки левой то меняем
                                  // направление движения
      ball_vector_x = -ball_vector_x;
    if ((ball_y == puddle_middle_r || ball_y == (puddle_middle_r + 1) ||
         ball_y == (puddle_middle_r - 1)) &&
        ball_x == PUDDLE_X_R - 1) // если мяч касается ракетки правой, то меняем
                                  // направление движения
      ball_vector_x = -ball_vector_x;

    ball_x += ball_vector_x;
    ball_y += ball_vector_y;
    if (ball_x < PUDDLE_X_L) {
      score_count_2++;
      ball_x = START_X;
      ball_y = START_Y;
      if (score_count_2 == WIN) {
        printf("Победил игрок 2");
        return 0;
      }
    }
    if (ball_x > PUDDLE_X_R) {
      score_count_1++;
      ball_x = START_X;
      ball_y = START_Y;
      if (score_count_1 == WIN) {
        printf("Победил игрок 1");
        return 0;
      }
    }
    char key; // считываем нажатую клавишу
    key = getchar();
    if (key == ' ') {
      continue;
    }
    if (key == 'a') {
      if (puddle_middle_l > 2)
        puddle_middle_l--;
    } else if (key == 'z') {
      if (puddle_middle_l < HEIGHT - 3)
        puddle_middle_l++;
    } else if (key == 'k') {
      if (puddle_middle_r > 2)
        puddle_middle_r--;
    } else if (key == 'm') {
      if (puddle_middle_r < HEIGHT - 3)
        puddle_middle_r++;
    }
    printf("\33[0d\33[2J");
  }
}

void draw(int puddle_middle_l, int puddle_middle_r, int ball_x, int ball_y,
          int score_count_1, int score_count_2) {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      if ((y == 0) || (y == HEIGHT - 1)) {
        printf("-");
      } else if ((x == 0 || x == WIDTH - 1)) {
        printf("|");
      } else if ((x == PUDDLE_X_L &&
                  (y == puddle_middle_l || y == puddle_middle_l + 1 ||
                   y == puddle_middle_l - 1)) ||
                 (x == PUDDLE_X_R &&
                  (y == puddle_middle_r || y == puddle_middle_r + 1 ||
                   y == puddle_middle_r - 1)))
        printf("|"); // проверка и отрисовка ракеток
      else if (x == ball_x && y == ball_y)
        printf("o"); // проверка и отрисовка шарика
      else if (x == 40)
        printf("|");
      else if (x == SC_POS_X_P1 && y == SC_POS_Y) {
        printf("%d", score_count_1); // проверка очков первого и отрисока
        if (score_count_1 >= 10)
          x++;
      } else if (x == SC_POS_X_P2 && y == SC_POS_Y) {
        printf("%d", score_count_2); // проверка второго и отрисовка
        if (score_count_2 >= 10)
          x++;
      }

      else
        printf(" ");
    }
    printf("\n");
  }
}
