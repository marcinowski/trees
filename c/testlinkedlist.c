#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "types.h"


void testLength() {
    printf("testLength - running.\n");
    linkedList *list = getLinkedList();
    assert(listLength(list) == 0);
    addValueToList(list, 1);
    assert(listLength(list) == 1);
    addValueToList(list, 1);
    assert(listLength(list) == 2);
    printf("testLength - passed.\n");
}

void testAddValueToList() {
    printf("testAddValueToList - running.\n");
    linkedList *list = getLinkedList();
    addValueToList(list, 1);
    assert(listLength(list) == 1);
    assert(list->value == 1);
    assert(list->next == NULL);
    assert(list->prev == NULL);
    addValueToList(list, 2);
    assert(listLength(list) == 2);
    assert(list->next != NULL);
    assert(list->prev == NULL);
    printf("Expected list: [1, 2]\n");
    printList(list);
    printf("testAddValueToList - passed.\n");
}

void testJoinLists() {
    printf("testJoinLists - running.\n");
    linkedList *first = getLinkedList();
    addValueToList(first, 1);
    linkedList *last = getLinkedList();
    addValueToList(last, 2);
    linkedList *result = joinLists(first, last);
    printf("Expected list: [1, 2]\n");
    printList(result);
    assert(listLength(result) == 2);
    printf("testJoinLists - passed.\n");
}

void testJoinWithEmptyList() {
    printf("testJoinWithEmptyList - running.\n");
    linkedList *empty = getLinkedList();
    linkedList *populated = getLinkedList();
    addValueToList(populated, 1);
    linkedList *result = joinLists(empty, populated);
    printf("Expected list: [1]\n");
    printList(result);
    assert(listLength(result) == 1);
    printf("testJoinWithEmptyList - passed.\n");
}

void testAddToListLoop() {
    printf("testAddToListLoop - running.\n");
    linkedList *list = getLinkedList();
    int *p;
    int vars[5] = {1, 2, 3, 4, 5};
    p = vars;
    addToListLoop(list, 5, p);
    assert(listLength(list) == 5);
    printf("Expected list: [1, 2, 3, 4, 5]\n");
    printList(list);
    printf("testAddToListLoop - passed.\n");
}

void testCopyList() {
    printf("testCopyList - running.\n");
    linkedList *list = getLinkedList();
    int *p;
    int vars[5] = {1, 2, 3, 4, 5};
    p = vars;
    addToListLoop(list, 5, p);
    linkedList *copy = copyList(list);
    assert(list->value == 1);
    assert(copy->value == 1);
    assert(listLength(list) == 5);
    assert(listLength(copy) == 5);
    assert(&list != &copy);
    list = list->next;
    assert(list->value == 2);
    assert(copy->value == 1);
    assert(listLength(list) == 4);
    assert(listLength(copy) == 5);
    printf("Expected list: [1, 2, 3, 4, 5]\n");
    printList(copy);
    printf("testCopyList - passed.\n");
}

void testGetIndex() {
    printf("testGetIndex - running.\n");
    linkedList *list = getLinkedList();
    int *p;
    int vars[5] = {1, 2, 3, 4, 5};
    p = vars;
    addToListLoop(list, 5, p);
    assert(getIndex(list, 0) == 1);
    assert(getIndex(list, 4) == 5);
    assert(getIndex(list, 5) == -1);
    printf("testCopyList - passed.\n");
}

int main(int argc, char const *argv[]) {
    printf("Running tests..\n");
    testLength();
    testAddValueToList();
    testJoinLists();
    testJoinWithEmptyList();
    testCopyList();
    testAddToListLoop();
    testGetIndex();
    printf("All tests passed!\n");
}
