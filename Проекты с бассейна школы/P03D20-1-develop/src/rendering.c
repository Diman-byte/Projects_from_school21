#include "rendering.h"

#include <math.h>
#include <stdio.h>

// Определения символов для отрисовки графика
#define GRAPH_CHAR '*'  // Символ для линии графика
#define EMPTY_CHAR '.'  // Символ для пустых мест
#define WIDTH 80
#define HEIGHT 24

void renderGraph(double xMin, double xMax, double step) {
    char screen[HEIGHT][WIDTH];

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            screen[y][x] = ' ';
        }
    }

    for (int x = 0; x < WIDTH; x++) {
        screen[HEIGHT / 2][x] = '-';
    }

    for (int y = 0; y < HEIGHT; y++) {
        screen[y][WIDTH / 2] = '|';
    }

    for (double x = xMin; x <= xMax; x += step) {
        double y = sin(x);
        int screenX = (int)((x - xMin) / (xMax - xMin) * (WIDTH - 1));
        int screenY = (int)((1 - (y + 1) / 2) * (HEIGHT - 1));

        if (screenX >= 0 && screenX < WIDTH && screenY >= 0 && screenY < HEIGHT) {
            screen[screenY][screenX] = '*';
        }
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            putchar(screen[y][x]);
        }
        putchar('\n');
    }
}

int main() {
    double xMin = -10.0;
    double xMax = 10.0;
    double step = 0.1;

    renderGraph(xMin, xMax, step);

    return 0;
}