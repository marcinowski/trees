#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "types.h"

void testAddValueToList() {
    linkedList *list = getLinkedList();
    addValueToList(list, 1);
    int l = listLength(list);
    assert(listLength(list) == 1);
    assert(list->value == 1);
    assert(list->next == NULL);
    assert(list->prev == NULL);
    addValueToList(list, 2);
    assert(listLength(list) == 2);
    assert(list->next != NULL);
    assert(list->prev == NULL);
}

void testJoinLists() {
    linkedList *first = getLinkedList();
    addValueToList(first, 1);
    linkedList *last = getLinkedList();
    addValueToList(last, 2);
    linkedList *result = joinLists(first, last);
    assert(listLength(result) == 2);
    assert(result->value == 1);
    assert(result->next->value == 2);
}

void testaddToListLoop() {
    linkedList *list = getLinkedList();
    int *p;
    int vars[5] = {1, 2, 3, 4, 5};
    p = vars;
    addToListLoop(list, 5, p);
    assert(listLength(list) == 5);
}

int main(int argc, char const *argv[]) {
    printf("Running tests ");
    printf(".");
    testAddValueToList();
    printf(".");
    testJoinLists();
    printf(".");
    testaddToListLoop();
    printf("\n");
    printf("All tests passed!\n");
}
