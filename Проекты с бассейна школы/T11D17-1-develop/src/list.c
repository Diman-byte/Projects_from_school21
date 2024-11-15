
#include "list.h"

#include <stdio.h>
#include <stdlib.h>

struct node* init(const struct door* door) {
    struct node* list = (struct node*)malloc(sizeof(struct node));
    list->d = *door;
    list->next = NULL;
    return list;
}

struct node* add_door(struct node* elem, const struct door* door) {
    struct node* new_elem = (struct node*)malloc(sizeof(struct node));
    new_elem->d = *door;
    new_elem->next = elem->next;
    elem->next = new_elem;
    return new_elem;
}

struct node* find_door(int door_id, struct node* root) {
    struct node* p = root;
    for (; p; p = p->next) {
        if (p->d.id == door_id) {
            return p;
        }
    }

    return p;
}

struct node* remove_door(struct node* elem, struct node* root) {
    struct node* p = root;
    if (root == elem) {
        p = root->next;
        free(root);
        root = p;
        return root;
    } else {
        for (; p->next != NULL; p = p->next) {
            if (p->next == elem) {
                struct node* buf = elem->next;
                free(p->next);
                p->next = buf;
                return root;
            }
        }
    }
    return root;
}

void destroy(struct node* root) {
    struct node* p = root;
    struct node* prev;
    for (; p; p = p->next) {
        prev = p;
        free(prev);
    }
}