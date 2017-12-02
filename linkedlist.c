#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList {
    int value;
    struct linkedList* prev;
    struct linkedList* next;
} linkedList;

linkedList *getLinkedList() {
    linkedList root;
    root->value = 0;
    root->prev = NULL;
    root->next = NULL;
    return root;
}
