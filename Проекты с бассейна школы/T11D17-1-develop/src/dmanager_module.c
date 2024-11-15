#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door* doors);
void sort(struct door* doors, int size);
void swap(struct door* a, struct door* b);
void close(struct door* a);

int main() {
    struct door doors[DOORS_COUNT];

    initialize_doors(doors);

    // for(int i = 0; i < DOORS_COUNT; i++) {
    //     printf("%d status %d\n", doors[i].id, doors[i].status);
    // }

    sort(doors, DOORS_COUNT);
    close(doors);
    for (int i = 0; i < DOORS_COUNT; i++) {
        if (i == DOORS_COUNT - 1) {
            printf("%d, %d", doors[i].id, doors[i].status);
        } else {
            printf("%d, %d\n", doors[i].id, doors[i].status);
        }
    }

    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void sort(struct door* doors, int size) {
    int i = 0;
    int j = size - 1;
    int mid = doors[size / 2].id;

    do {
        while (doors[i].id < mid) {
            i++;
        }
        while (doors[j].id > mid) {
            j--;
        }

        if (i <= j) {
            swap(&doors[i], &doors[j]);
            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0) sort(doors, j + 1);

    if (i < size) sort(&doors[i], size - i);
}

void swap(struct door* a, struct door* b) {
    struct door temp = *a;
    *a = *b;
    *b = temp;
}

void close(struct door* a) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        a[i].status = 0;
    }
}
