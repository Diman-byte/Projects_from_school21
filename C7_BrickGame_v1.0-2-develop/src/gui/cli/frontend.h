/**
 * @file frontend.h
 * @brief Файл содержит функции отрисовки игры
 */

#ifndef FRONTEND_H
#define FRONTEND_H

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../../brick_game/tetris/backend.h"

/**
 * @brief Один блок на два столбца
 */
#define COLSPERCELL 2

/**
 * @brief Макрос на отрисовку заполненного блока
 */
#define ADDBLOCK(w, x)                          \
  waddch((w), ' ' | A_REVERSE | COLOR_PAIR(x)); \
  waddch((w), ' ' | A_REVERSE | COLOR_PAIR(x))

// waddch — это функция библиотеки ncurses, которая используется для добавления
// одиночного символа (с указанными атрибутами) в определенное окно (типа
// WINDOW). Эта функция является аналогом addch, но работает с конкретными
// окнами.

/**
 * @brief Макрос на отрисовку пусного блока
 */
#define ADDEMPTY(w) \
  waddch((w), ' '); \
  waddch((w), ' ')

/**
 * @brief Макрос на нициализацию ncurses
 */
#define CURSINIT()        \
  {                       \
    initscr();            \
    cbreak();             \
    noecho();             \
    keypad(stdscr, TRUE); \
    timeout(0);           \
    curs_set(0);          \
    initColors();         \
  }

// "cbreak": программа получает вводимые символы сразу, без ожидания нажатия
// клавиши Enter.
// - noecho() Отключает автоматическое отображение вводимых пользователем
// символов на экране.
// - keypad По умолчанию обработку таких клавиш, как клавиши управления курсором
// и функциональные клавиши берёт на себя терминал. Чтобы установить режим
// обработки командных клавиш нужно вызвать функцию keypad с TRUE в качестве
// второго параметра.
// - timeout Значение 0 указывает на отсутствие ожидания ввода —
// если пользователь не нажимает клавишу, программа продолжает выполнение сразу
// же
// - curs_set(0) - скрывает курсор

/**
 * @brief Макрос на нициализацию окон.
 * Выставление размеров и начала координат в окне
 */
#define WINDOWINIT(x, y, z)                                   \
  {                                                           \
    int row = 0, col = 0;                                     \
    getmaxyx(stdscr, row, col);                               \
    x = newwin(ROWS + 2, 2 * COLUMNS + 2, row / 10, col / 3); \
    y = newwin(4, 11, row / 7, col / 1.4);                    \
    z = newwin(5, 20, 14, col / 1.4);                         \
  }

/**
 * @brief Макрос на вызов функций отрисовки и таймер
 */
#define PRINT(wB, wN, wS, game) \
  {                             \
    printField(board, game);    \
    printNext(next, game);      \
    printStat(score, game);     \
    doupdate();                 \
    sleepMilli(10);             \
  }

/**
 * @brief Функция отрисовки игрового поля.
 * @param w Окно отрисовки
 * @param game Структура игры, из которой брать поле
 */
void printField(WINDOW *w, Tgame *game);

/**
 * @brief Функция отрисовки следующего тетрамино
 * @param w Окно отрисовки
 * @param game Структура игры, из которой брать структуру следующего тетрамино
 */
void printNext(WINDOW *w, Tgame *game);

/**
 * @brief Функция отрисовки игровой статистики
 * @param w Окно отрисовки
 * @param game Структура игры, из которой брать игровую статистику
 */
void printStat(WINDOW *w, Tgame *game);

/**
 * @brief Функция задачи цветов каждому типу тетрамино
 */
void initColors();

/**
 * @brief Функция отрисовки начала игры
 */
void start();

/**
 * @brief Функция отрисовки паузы в игре
 */
void pause();

/**
 * @brief Функция отрисовки конца игры, вопроса о начале новой игры
 * @param game Структура игры
 * @return Актуальный статус игры
 */
Gstatus again(Tgame *game);

/**
 * @brief Задержка времени(таймер)
 * @param milliseconds Количество миллисекунд
 */
void sleepMilli(int milliseconds);

#endif