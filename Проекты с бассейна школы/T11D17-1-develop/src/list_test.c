#include "list.h"

#include <stdio.h>

#ifdef LIST_TEST
void test_add_door();
void test_remove_door();

#endif

int main() {
    test_add_door();
    test_remove_door();

    return 0;
}

void test_add_door() {
    struct door door_1, door_2, door_3;
    door_1.id = 25;
    door_2.id = 35;
    door_3.id = 45;
    door_3.status = 1;

    struct node *node_1 = init(&door_1);
    struct node *node_2 = add_door(node_1, &door_2);
    struct node *node_3 = add_door(node_2, &door_3);

    printf("TESTS add_door\n");
    printf("%d\t%d\n", node_2->d.id, node_2->d.status);
    if (node_2->d.id == 35) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    printf("%d\t%d\n", node_3->d.id, node_3->d.status);
    if (node_3->d.id == 45) {
        printf("SUCCESS\n\n");
    } else {
        printf("FAIL\n\n");
    }
    // destroy(node_1);
}

void test_remove_door() {
    struct door door_1, door_2;
    door_1.id = 25;
    door_2.id = 35;

    struct node *node_1 = init(&door_1);
    struct node *node_2 = add_door(node_1, &door_2);

    printf("TESTS remove_door\n");

    printf("%d\t%d\n", node_2->d.id, node_2->d.status);

    remove_door(node_2, node_1);

    printf("NULL\t NULL\n");

    find_door(25, node_1);
    if (node_1->next == NULL) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}