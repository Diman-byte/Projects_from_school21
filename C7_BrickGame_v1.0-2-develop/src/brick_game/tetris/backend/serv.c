#include "../backend.h"

Tgame gameInit() {
  Tgame game = {0};
  game.falling = (Tblock *)malloc(sizeof(Tblock));
  game.next = (Tblock *)malloc(sizeof(Tblock));
  game.rows = ROWS;
  game.cols = COLUMNS;
  game.field = (int *)malloc(ROWS * COLUMNS * sizeof(int));
  for (int i = 0; i < ROWS * COLUMNS; i++) {
    game.field[i] = 0;
  }
  game.score = STARTSCORE;
  game.highScore = getHighScore();
  game.level = STARTLEVEL;
  game.speed = STARTSPEED;
  game.gravityTicks = STARTGRAVITY;
  srand(time(NULL));
  newFalling(&game);
  newFalling(&game);

  return game;
}

int getHighScore() {
  int x = 0;
  FILE *f = fopen(".saveScore.txt", "r");
  if (f != NULL) {
    fscanf(f, "%d", &x);
    fclose(f);
  }
  return x;
}

void gameDelete(Tgame *game) {
  free(game->field);
  free(game->falling);
  free(game->next);
}

bool gameOver(Tgame *game) {
  bool status = false;
  rmTetramino(game, game->falling);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < game->cols; j++) {
      if (ISFILLED(getBlock(game, i, j))) {
        status = true;
      }
    }
  }
  putTetramino(game, game->falling);

  return status;
}

void newGame(Tgame *game) {
  gameDelete(game);
  *game = gameInit();
}

void saveScore(const Tgame *game) {
  if (game->score == game->highScore) {
    FILE *f = fopen(".saveScore.txt", "wt");
    if (f) {
      fprintf(f, "%d", game->score);
      fclose(f);
    }
  }
}

Gstatus tick(Tgame *game, Tmove move) {
  Gstatus status = GO;
  if (move == TPAUSE) {
    status = PAUSE;
  }
  gravityBySpeed(game);
  moving(game, move);
  int clear = checkLines(game);
  upper(game, clear);
  if (gameOver(game) || move == TEND) {
    status = AGAIN;
  }

  return status;
}

int getGravity(int index) {
  const int speed[11] = {// 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10
                         0, 70, 60, 40, 35, 30, 25, 20, 15, 10, 7};

  return speed[index];
}

void gravityBySpeed(Tgame *game) {
  game->gravityTicks--;
  if (game->gravityTicks <= 0) {
    rmTetramino(game, game->falling);
    game->falling->loc.row++;
    if (checkMovesTetramino(
            game,
            game->falling)) {  //Проверка, достиг ли счетчик gravityTicks нуля
                               //или стал отрицательным. Если да, то нужно
                               //выполнить шаги для "сдвига" тетрамино вниз.
      game->gravityTicks = getGravity(game->level);
    } else {  // Если тетрамино не может быть перемещено вниз (столкновение с
              // другим блоком или дном игрового поля)
      game->falling->loc.row--;
      putTetramino(game, game->falling);

      newFalling(game);
    }
    putTetramino(game, game->falling);
  }
}

void upper(Tgame *game, int clearLines) {
  const int scoreTable[6] = {0, 100, 300, 700, 300, 1500};
  game->score += scoreTable[clearLines];
  if (game->score > game->highScore) {
    game->highScore = game->score;
  }
  saveScore(game);
  if (game->level < 10) {
    const int lvlTable[10] = {0,    600,  1200, 1800, 2400,
                              3000, 3600, 4200, 4800, 5400};
    if (game->score >= lvlTable[game->level]) {
      game->level++;
      game->speed++;
    }
  }
}

bool againGame(Tgame *game) {
  bool status = true;
  bool answer = false;
  while (status) {
    switch (getch()) {
      case 'y':
        newGame(game);
        answer = true;
        status = false;
        break;
      case 'n':
        gameDelete(game);
        status = false;
        break;
      default:
        break;
    }
  }

  return answer;
}